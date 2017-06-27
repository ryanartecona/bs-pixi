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

/* let _ = { */
/*   let app = Pixi.ApplicationClass.create (); */
/*   document |> Document.body |> Element.appendChild app##view; */
/*   let r = app##renderer; */
/*   switch r { */
/*   | `canvas _ => print_endline "canvas" */
/*   | `webgl _ => print_endline "webgl" */
/*   }; */
/*   let _ = app##(destroy true); */
/*   () */
/* }; */
let _ = {
  open Pixi;
  let app =
    Application.create
      opts::(Application.mkOpts width::400 backgroundColor::0x335500 ()) ();
  /* let me debug in dev tools */
  let () = [%bs.raw "window.app = app"];
  document |> Document.body |> Element.appendChild (app |> Application.view);
  app |> Application.renderer |> (
    fun r => SystemRenderer.setAutoResize r Js.true_
  );
  /* app |> Application.stop (); */
  /* app |> Application.destroy Js.true_; */
  ()
};

let _ = {
  open PixiAuto;
  let transform = Transform.create ();
  let countLimiter = Prepare.CountLimiter.create 10. ();
  let baseTexture = BaseRenderTexture.create 10. 10. 1. 2. ();
  ()
};
