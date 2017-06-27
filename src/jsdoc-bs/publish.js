var _ = require("lodash");

var ppJson = function(x) {
  console.error(JSON.stringify(x, null, 2));
};

var titleCase = function(s) {
  // anything -> Anything
  return s.replace(/^./, function(c) {
    return c.toUpperCase();
  });
};

var camelCase = function(s) {
  return (
    s
      // ALL_CAPS -> all_caps
      .replace(/^[A-Z_]+$/, function(m) {
        return m.toLowerCase();
      })
      // FXAAFilter -> fxaaFilter
      .replace(/^([A-Z]+)([A-Z])/, (m, m1, m2) => {
        return `${m1.toLowerCase()}${m2}`;
      })
      // FooBar -> fooBar
      .replace(/^./, function(c) {
        return c.toLowerCase();
      })
  );
};

var modulePathFromLongname = function(longname) {
  // var cleanLongname = cleanupLongname(longname);
  // var components = cleanLongname.split(".");
  // return _.map(components, titleCase);
  // return cleanupLongname(longname).split(".");
  return longname.split(".");
};

var mkModule = function() {
  return { type: "module", items: {} };
};

var ensureModuleExists = function(modules, modulePath) {
  var m = modules;
  for (var i = 0; i < modulePath.length; i++) {
    if (!m["items"][modulePath[i]]) {
      m["items"][modulePath[i]] = mkModule();
    }
    m = m["items"][modulePath[i]];
  }
  return m;
};

var getItem = function(modules, path) {
  var m = modules;
  for (var i = 0; i < path.length; i++) {
    if (!(m["items"] && m["items"][path[i]])) {
      return null;
    }
    m = m["items"][path[i]];
  }
  return m;
};

var jsToBsType = (function() {
  var simpleTranslations = {
    boolean: "Js.boolean",
    string: "string",
    number: "float",
    Number: "float",
    HTMLCanvasElement: "Dom.element",
    // CanvasRenderingContext2d: "Bs_webapi.Canvas.Canvas2d.t",
    WebGLRenderingContext: "ReasonJs.Gl.glT",
    WebGLBuffer: "ReasonJs.Gl.bufferT"
  };
  var regexpArrayOf = /^Array\.<(.*)>$/;
  return function(modules, jsTypeNames) {
    if (jsTypeNames.length === 1) {
      var jsTypeName = jsTypeNames[0];
      if (simpleTranslations[jsTypeName]) {
        return simpleTranslations[jsTypeName];
      } else if (regexpArrayOf.test(jsTypeName)) {
        return jsTypeName.replace(regexpArrayOf, function(match, g1) {
          return `array ${jsToBsType(modules, [g1])}`;
        });
      } else {
        var cleanLongname = cleanupLongname(jsTypeName);
        var classModulePath = modulePathFromLongname(cleanLongname);
        var classModule = getItem(modules, classModulePath);
        if (classModule && classModule.items["t"]) {
          return `T.${camelCase(classModulePath[classModulePath.length - 1])}`;
        }
      }
    } else if (
      _.isEqual(jsTypeNames, ["HTMLImageElement" | "HTMLCanvasElement"])
    ) {
      return `Dom.element`;
    }
    return `unit /* unknown js type: ${jsTypeNames.join("|")} */`;
  };
})();

var unkeyword = function(name) {
  return name.replace(/^(type)$/, "$1_");
};

var formatDescription = function(desc) {
  return desc.replace(/<p>([^<]*)<\/p>/gm, "$1\n").trim();
};

var emitModuleType = (classes, name) => {
  name = name || "TYPES";
  var emittedClassTypes = classes.map(c => `type ${c};`).join("\n");
  return `module type ${name} = {
${emittedClassTypes}
};`;
};

var emitTypes = classes => {
  return classes.map(c => `type ${c};`).join("\n");
};

var emitIncludeImpl = classes => {
  var emittedClassBindings = classes
    .map(c => `type nonrec ${c} = ${c};`)
    .join("\n");
  return `include Impl {
${emittedClassBindings}
};`;
};

var emitModule = function(modules, item, path, arg) {
  var name = path[path.length - 1];
  var descComment = item.description
    ? `/*
${formatDescription(item.description)}
*/
`
    : "";
  if (item["type"] === "type") {
    return `${descComment} type ${name} = T.${camelCase(
      path[path.length - 2]
    )};`;
  } else if (item.type === "getter") {
    var getterName = unkeyword(camelCase(name));
    var r = `${descComment} external ${getterName} : t => ${item.bsType} = "${getterName ===
      name
      ? ""
      : name}" [@@bs.get];`;
    if (item.setter) {
      var setterName = unkeyword(titleCase(name));
      r += `
${descComment} external set${titleCase(
        name
      )} : t => ${item.bsType} => unit = "${name}" [@@bs.set];`;
    }
    return r;
  } else if (item.type === "constructor") {
    var paramTypes = item.params.map(p => {
      // TODO: support optionals
      return `${p.name}::${jsToBsType(modules, p.type.names)}`;
    });
    var scope = path.slice(1, -2);
    var scopeAttr = _.isEqual(scope, [])
      ? ""
      : `[@@bs.scope (${scope.map(s => `"${s}"`).join(",")})]`;
    return `external ${name} : ${paramTypes
      .map(s => s + " => ")
      .join(
        ""
      )} unit => t = "${item.name}" [@@bs.new] ${scopeAttr} [@@bs.module ("pixi.js", "PIXI")];`;
  } else if (item.type === "module") {
    if (item.private) {
      return "";
    }
    var module = item;
    var emitItems = [];
    for (var modname in module["items"]) {
      emitItems.push(
        emitModule(modules, module["items"][modname], path.concat(modname))
      );
    }
    if (arg) {
      return `${descComment} module ${name} (${arg}) => {
${emitItems.join("\n")}
};`;
    } else {
      return `${descComment} module ${name} = {
${emitItems.join("\n")}
};`;
    }
  }
};

var emit = (modules, classes) => {
  return (
    emitModuleType(classes, "TYPES") +
    emitModule(modules, modules, ["Impl"], "T: TYPES") +
    emitTypes(classes) +
    emitIncludeImpl(classes)
  );
};

function cleanupLongname(longname) {
  var replaced = longname
    // Some specific renaming
    .replace(
      "PIXI.NineSlicePlane#PIXI.mesh.NineSlicePlane",
      "PIXI.mesh.NineSlicePlane"
    )
    .replace(/PIXI.(DisplayObject|Container)#core/, "PIXI")
    .replace(
      "PIXI.interaction.InteractionTrackingData#InteractionTrackingData",
      "PIXI.interaction.InteractionTrackingData"
    )
    .replace("PIXI.CountLimiter", "PIXI.prepare.CountLimiter")
    // Sometimes `.memberof` has stuff like 'PIXI.DisplayObject#core', so
    // 'DisplayObject#core' -> 'DisplayObject'
    .replace(/#\w+\./, ".")
    .replace(/~/, ".")
    // e.g. 'PIXI.accessibility.AccessibilityManager.AccessibilityManager#debug'
    // ->   'PIXI.accessibility.AccessibilityManager#debug'
    .replace(/(\w+)\.(\1)(\W|$)/, "$1$3")
    // Strip 'PIXI.' namespace prefix
    .replace(/^PIXI\./, "")
    // Capitalize module names
    .split(".")
    .map(titleCase)
    .join(".");
  // if (longname !== replaced) {
  //   console.error(`replacing (${longname}) with (${replaced})`);
  // }
  return replaced;
}

var ensureClassExists = (classes, c) => {
  if (!_.includes(classes, c)) {
    classes.push(c);
  } else {
    throw `class (${c}) already exists`;
  }
  return c;
};

var addConstructor = (module, datum) => {
  var params = [];
  _.forEach(datum.params, p => {
    if (!/\./.test(p.name)) {
      if (p.type.names.length === 1 && p.type.names[0] === "object") {
        params.push(_.merge({}, p, { params: [] }));
      } else {
        params.push(p);
      }
    }
  });
  _.forEach(datum.params, p => {
    if (/\./.test(p.name)) {
      var parts = p.name.split(".", 2);
      var parentParamName = parts[0];
      var childParamName = parts[1];
      var parentParam = _.find(params, other => {
        return other.name === parentParamName;
      });
      if (parentParam) {
        parentParam.params.push(_.merge({}, p, { name: childParamName }));
      }
    }
  });

  console.error(`constructor ${datum.name} has params:`);
  ppJson(params);

  if (module.items["create"]) {
    console.error(`constructor for class ${datum.name} duplicated`);
  } else {
    module.items["create"] = {
      name: datum.name,
      type: "constructor",
      params
    };
  }
};

exports.publish = function(taffyData, opts) {
  var data = taffyData;
  var modules = mkModule();
  var classes = [];

  data({ undocumented: true }).remove();

  data().each(function(datum) {
    // if (/autoStart$/.test(datum.longname)) {
    //   ppJson(datum);
    // }
    ["longname", "memberof"].forEach(function(prop) {
      if (datum[prop]) {
        datum[prop] = cleanupLongname(datum[prop]);
      }
    });
  });

  data().each(function(datum) {
    if (datum.kind === "class" && !datum.deprecated) {
      // if (/Application$/.test(datum.longname)) {
      //   ppJson(datum);
      // }
      var isPrivateClass = datum.access === "private";
      var m = ensureModuleExists(
        modules,
        modulePathFromLongname(datum.longname)
      );
      m.description = datum.classdesc;
      m.private = isPrivateClass;
      m.name = datum.name;
      m.items["t"] = {
        type: "type",
        description: datum.classdesc,
        name: datum.name
      };
      if (!isPrivateClass) {
        ensureClassExists(classes, camelCase(datum.name));
        addConstructor(m, datum);
      }
    }
  });

  data().each(function(datum) {
    if (
      datum.kind === "member" &&
      datum.scope === "instance" &&
      datum.access !== "private" &&
      datum.type &&
      !datum.deprecated &&
      (!datum.params || datum.params.length === 0)
    ) {
      // if (/autoStart$/.test(datum.longname)) {
      //   ppJson(datum);
      // }
      var m = ensureModuleExists(
        modules,
        modulePathFromLongname(datum.memberof)
      );
      m.items[datum.name] = {
        type: "getter",
        description: datum.description,
        bsType: jsToBsType(modules, datum.type.names),
        setter: !datum.readonly
      };
    }
  });

  console.log(emit(modules, classes));
};
