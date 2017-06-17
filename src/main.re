let greeting = "hello from bucklescript!";

print_endline greeting;

open ReasonJs.Dom;

open Bs_webapi_ext;

document |> Document.body |>
Element.appendChild (document |> Document.createTextNode greeting);

Pixi.Utils.sayHello (
  if (Pixi.Utils.isWebGLSupported ()) {
    "WebGL"
  } else {
    "canvas"
  }
);
