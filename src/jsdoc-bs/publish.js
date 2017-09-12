"use strict";
var _ = require("lodash");

class Module {
  get type() {
    return "module";
  }
  constructor() {
    this.items = {};
  }
}

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
  return longname.split(".").map(titleCase);
};

var ensureModuleExists = function(modules, modulePath) {
  var m = modules;
  for (var i = 0; i < modulePath.length; i++) {
    if (!m.items[modulePath[i]]) {
      m.items[modulePath[i]] = new Module();
    }
    m = m.items[modulePath[i]];
  }
  return m;
};

var getItem = function(modules, path) {
  var m = modules;
  for (var i = 0; i < path.length; i++) {
    if (!(m.items && m.items[path[i]])) {
      return null;
    }
    m = m.items[path[i]];
  }
  return m;
};

var jsToBsType = (function() {
  var simpleTranslations = {
    boolean: "Js.boolean",
    Boolean: "Js.boolean",
    string: "string",
    number: "float",
    Number: "float",
    int: "int",
    HTMLCanvasElement: "Dom.element",
    HTMLImageElement: "Dom.element",
    HTMLVideoElement: "Dom.element",
    // CanvasRenderingContext2d: "Bs_webapi.Canvas.Canvas2d.t",
    WebGLRenderingContext: "ReasonJs.Gl.glT",
    WebGLBuffer: "ReasonJs.Gl.bufferT",
    Float32Array: "Js_typed_array.Float32Array.t",
    Uint8Array: "Js_typed_array.Uint8Array.t",
    Uint8ClampedArray: "Js_typed_array.Uint8ClampedArray.t",
    Uint16Array: "Js_typed_array.Uint16Array.t"
  };
  var regexpArrayOf = /^Array\.<(.*)>$/;
  return function(modules, jsTypeNames) {
    jsTypeNames = _.sortBy(jsTypeNames);
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
      _.isEqual(jsTypeNames, ["HTMLCanvasElement", "HTMLImageElement"])
    ) {
      return `Dom.element`;
    } else if (_.isEqual(jsTypeNames, ["string", "Array.<string>"])) {
      return jsToBsType(modules, ["Array.<string>"]);
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
  if (item.type === "classtype") {
    return `${descComment} type ${name} = T.${camelCase(
      path[path.length - 2]
    )};`;
  } else if (item.type === "opaquetype") {
    return `${descComment} type ${name};`;
  } else if (item.type === "makeobj") {
    var paramTypes = item.params.map(p => {
      var optional = p.optional ? "?" : "";
      return `${p.name}::${jsToBsType(modules, p.type.names)}${optional} => `;
    });
    return `${descComment} external ${name} : ${paramTypes.join(
      ""
    )} unit => ${item.returnType} = "" [@@bs.obj];`;
  } else if (item.type === "getter") {
    var getterName = unkeyword(camelCase(name));
    var r = `${descComment} external ${getterName} : t => ${item.bsType} = "${getterName ===
      name
      ? ""
      : name}" [@@bs.get];`;
    if (item.setter) {
      var setterName = `set${titleCase(name)}`;
      r += `
${descComment} external ${setterName} : t => ${item.bsType} => unit = "${name}" [@@bs.set];`;
    }
    return r;
  } else if (item.type === "constructor") {
    var paramTypes = item.params.map(p => {
      var typeString = p.bsType || jsToBsType(modules, p.type.names);
      var optional = p.optional ? "?" : "";
      return `${p.name}::${typeString}${optional}`;
    });
    var scopeAttr = _.isEqual(item.scope, [])
      ? ""
      : `[@@bs.scope (${item.scope.map(s => `"${s}"`).join(",")})]`;
    return `external ${name} : ${paramTypes
      .map(s => s + " => ")
      .join(
        ""
      )} unit => t = "${item.name}" [@@bs.new] ${scopeAttr} [@@bs.module ("pixi.js", "PIXI")];`;
  } else if (item.type === "method") {
    var paramTypes = item.params.map(p => {
      var typeString = p.bsType || jsToBsType(modules, p.type.names);
      var optional = p.optional ? "?" : "";
      return `${p.name}::${typeString}${optional} => `;
    });
    var returnType = item.returns && item.returns.length === 1
      ? jsToBsType(modules, item.returns[0].type.names)
      : "unit";
    return `${descComment} external ${name} : ${paramTypes.join(
      ""
    )} ${returnType} = "" [@@bs.send.pipe : t];`;
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
    .replace(/PIXI\.(Base|Canvas|WebGL)Prepare/, "PIXI.prepare.$1Prepare")
    // Sometimes `.memberof` has stuff like 'PIXI.DisplayObject#core', so
    // 'DisplayObject#core' -> 'DisplayObject'
    .replace(/#\w+\./, ".")
    .replace(/~/, ".")
    // e.g. 'PIXI.accessibility.AccessibilityManager.AccessibilityManager#debug'
    // ->   'PIXI.accessibility.AccessibilityManager#debug'
    .replace(/(\w+)\.(\1)(\W|$)/, "$1$3")
    // Strip 'PIXI.' namespace prefix
    .replace(/^PIXI\./, "");
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

var nestOptionsParams = params => {
  var nestedParams = [];

  _.forEach(params, p => {
    if (!/\./.test(p.name)) {
      nestedParams.push(_.clone(p));
    }
  });

  _.forEach(params, p => {
    if (/\./.test(p.name)) {
      var parts = p.name.split(".", 2);
      var parentParamName = parts[0];
      var childParamName = parts[1];
      var parentParam = _.find(nestedParams, other => {
        return other.name === parentParamName;
      });
      if (parentParam) {
        parentParam.params = parentParam.params || [];
        parentParam.params.push(_.merge({}, p, { name: childParamName }));
      }
    }
  });

  return nestedParams;
};

var liftNestedParamsToModule = (params, module, parentName) => {
  _.forEach(params, p => {
    if (
      _.isEqual(p.type.names, ["object"]) &&
      _.isArray(p.params) &&
      p.params.length >= 1
    ) {
      var optionsTypeName = `${parentName}${titleCase(p.name)}`;
      module.items[optionsTypeName] = { type: "opaquetype" };
      module.items[`mk${titleCase(optionsTypeName)}`] = {
        type: "makeobj",
        params: p.params,
        returnType: optionsTypeName,
        description: p.description
      };
      p.bsType = optionsTypeName;
    }
  });
};

var addConstructor = (module, datum) => {
  var params = nestOptionsParams(datum.params);

  // console.error(`constructor ${datum.name} has params:`);
  // ppJson(params);

  if (module.items["create"]) {
    console.error(`constructor for class ${datum.name} duplicated`);
  } else {
    liftNestedParamsToModule(params, module, "create");

    module.items["create"] = {
      type: "constructor",
      name: datum.name,
      scope: datum.longname.split(".").slice(0, -1),
      params
    };
  }
};

var addMethod = (module, datum) => {
  var params = nestOptionsParams(datum.params);
  liftNestedParamsToModule(params, module, datum.name);
  module.items[datum.name] = {
    type: "method",
    name: datum.name,
    description: datum.description,
    params,
    returns: datum.returns
  };
};

exports.publish = function(taffyData, opts) {
  var data = taffyData;
  var modules = new Module();
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
      // if (/FilterState$/.test(datum.longname)) {
      //   ppJson(datum);
      // }
      var isPrivateClass = datum.access === "private" || datum.ignore === true;
      var m = ensureModuleExists(
        modules,
        modulePathFromLongname(datum.longname)
      );
      // m.description = datum.classdesc;
      m.private = isPrivateClass;
      m.name = datum.name;
      m.items["t"] = {
        type: "classtype",
        description: datum.classdesc,
        name: datum.name
      };
      if (!isPrivateClass) {
        ensureClassExists(classes, camelCase(datum.name));
        if (datum.scope === "static") {
          addConstructor(m, datum);
        }
      }
    }
  });

  data().each(function(datum) {
    // if (/getRectangle$/.test(datum.longname)) {
    //   ppJson(datum);
    // }
    if (
      datum.kind === "function" &&
      datum.scope === "instance" &&
      datum.access !== "private" &&
      !datum.deprecated &&
      datum.params
    ) {
      var m = ensureModuleExists(
        modules,
        modulePathFromLongname(datum.memberof)
      );
      addMethod(m, datum);
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
      var memberName = m.items[datum.name] ||
        m.items[`set${titleCase(datum.name)}`]
        ? `${datum.name}Prop`
        : datum.name;
      m.items[memberName] = {
        type: "getter",
        propname: datum.name,
        description: datum.description,
        bsType: jsToBsType(modules, datum.type.names),
        setter: !datum.readonly
      };
    }
  });

  console.log(emit(modules, classes));
};
