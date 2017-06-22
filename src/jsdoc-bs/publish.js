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
  return longname.split(".");
};

var mkModule = function() {
  return { type: "module", items: {} };
};

var ensureModuleExists = function(modules, modulePath) {
  var m = modules;
  var i = 0;
  while (i < modulePath.length) {
    if (!m["items"][modulePath[i]]) {
      m["items"][modulePath[i]] = mkModule();
    }
    m = m["items"][modulePath[i]];
    i++;
  }
  return m;
};

var jsToBsType = (function() {
  var simpleTranslations = {
    boolean: "Js.boolean",
    string: "string",
    number: "int",
    Number: "int",
    HTMLCanvasElement: "Dom.element",
    WebGLRenderingContext: "ReasonJs.Gl.glT",
    WebGLBuffer: "ReasonJs.Gl.bufferT"
  };
  var regexpArrayOf = /^Array\.<(.*)>$/;
  return function(jsTypeNames) {
    if (jsTypeNames.length === 1) {
      var jsTypeName = jsTypeNames[0];
      if (simpleTranslations[jsTypeName]) {
        return simpleTranslations[jsTypeName];
      } else if (regexpArrayOf.test(jsTypeName)) {
        return jsTypeName.replace(regexpArrayOf, function(match, g1) {
          return `array ${jsToBsType([g1])}`;
        });
      }
    } else if (_.isEqual(jsTypeNames, ['HTMLImageElement'|'HTMLCanvasElement'])) {
      return `Dom.element`;
    }
    return `unit /* unknown js type: ${jsTypeNames.join('|')} */`;
  };
})();

var unkeyword = function(name) {
  return name.replace(/^(type)$/, "$1_");
};

var pprint = function(item, path) {
  var name = path[path.length - 1];
  var descComment = item.description
    ? `/*
${item.description}
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
    var module = item;
    var pprintedItem = [];
    for (var modname in module["items"]) {
      pprintedItem.push(pprint(module["items"][modname], path.concat(modname)));
    }
    var ppModuleName = titleCase(name);
    return `module ${ppModuleName} = {
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
    .replace(/(\w+)\.(\1)(\W|$)/, "$1$3");
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
    ["longname", "memberof"].forEach(function(prop) {
      if (datum[prop]) {
        datum[prop] = cleanupLongname(datum[prop]);
      }
    });
  });

  data().each(function(datum) {
    if (datum.kind === "class") {
      var m = ensureModuleExists(
        modules,
        modulePathFromLongname(datum.longname)
      );
      m.items["t"] = { type: "type", description: datum.description };
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
      if (/debug/.test(datum.longname)) {
        ppJson(datum);
      }
      var m = ensureModuleExists(
        modules,
        modulePathFromLongname(datum.memberof)
      );
      m.items[datum.name] = {
        type: "getter",
        description: datum.description,
        bsType: jsToBsType(datum.type.names),
        setter: !datum.readonly
      };
    }
  });

  // ppJson(modules);
  // console.log(pprint(modules['items']['PIXI'], ['Pixi']));
  var submodules = modules["items"]["PIXI"]["items"];
  for (var name in submodules) {
    console.log(pprint(submodules[name], [name]));
  }
};
