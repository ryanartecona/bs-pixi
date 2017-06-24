var _ = require("lodash");

var ppJson = function(x) {
  console.error(JSON.stringify(x, null, 2));
};

var titleCase = function(s) {
  return s.replace(/^./, function(c) {
    return c.toUpperCase();
  });
};

var camelCase = function(s) {
  return s
    .replace(/^[A-Z]+$/, function(m) {
      return m.toLowerCase();
    })
    .replace(/^./, function(c) {
      return c.toLowerCase();
    });
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
        var classModule = getItem(
          modules,
          modulePathFromLongname(cleanLongname)
        );
        if (classModule && classModule.items["t"]) {
          return `${cleanLongname}.t`;
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

var pprint = function(item, path) {
  var name = path[path.length - 1];
  var descComment = item.description
    ? `/*
${formatDescription(item.description)}
*/
`
    : "";
  if (item["type"] === "type") {
    return `${descComment} type ${name};`;
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
  } else if (item.type === "module") {
    if (item.private) {
      return "";
    }
    var module = item;
    var pprintedItem = [];
    for (var modname in module["items"]) {
      pprintedItem.push(pprint(module["items"][modname], path.concat(modname)));
    }
    return `${descComment} module ${name} = {
${pprintedItem.join("\n")}
};`;
  }
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

exports.publish = function(taffyData, opts) {
  var data = taffyData;
  var modules = mkModule();

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
    if (datum.kind === "class" // && datum.access !== "private"
       ) {
      // if (/ParticleRenderer/.test(datum.longname)) {
      //   ppJson(datum);
      // }
      var m = ensureModuleExists(
        modules,
        modulePathFromLongname(datum.longname)
      );
      m.description = datum.classdesc;
      m.private = datum.access === "private";
      m.items["t"] = { type: "type", description: datum.classdesc };
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

  // ppJson(modules);
  var submodules = modules["items"]; //["PIXI"]["items"];
  for (var name in submodules) {
    console.log(pprint(submodules[name], [name]));
  }
};
