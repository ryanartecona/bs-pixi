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

let _ = {
  let app = Pixi.ApplicationClass.create ();
  document |> Document.body |> Element.appendChild app##view;
  let r = app##renderer;
  switch r {
  | `canvas _ => print_endline "canvas"
  | `webgl _ => print_endline "webgl"
  };
  let _ = app##destroy Js.true_;
  ()
};

/* let _ = { */
/*   open Pixi; */
/*   let app = */
/*     Application.create */
/*       opts::( */
/*         Application.mkOpts width::400 height::400 backgroundColor::0x335500 () */
/*       ) */
/*       (); */
/*   /\* let me debug in dev tools *\/ */
/*   let () = [%bs.raw "window.app = app"]; */
/*   document |> Document.body |> Element.appendChild (app |> Application.view); */
/*   app |> Application.renderer |> ( */
/*     fun r => SystemRenderer.setAutoResize r Js.true_ */
/*   ); */
/*   /\* app |> Application.stop (); *\/ */
/*   /\* app |> Application.destroy Js.true_; *\/ */
/*   () */
/* }; */
let _ = {
  open PixiAuto;
  /* test creating some shit */
  let transform = Transform.create ();
  let countLimiter = Prepare.CountLimiter.create 10. ();
  let baseTexture =
    BaseRenderTexture.create
      width::10. height::10. scaleMode::1. resolution::2. ();
  /* make an app */
  let app =
    Application.(
      create
        options::(
          mkCreateOptions
            width::600.
            height::300.
            backgroundColor::(float_of_int 0x003355)
            ()
        )
        ()
    );
  /* expose window.appAuto for debugging */
  let _ = [%bs.raw "function (app) { window.appAuto = app; }"] app;
  /* add app's canvas to the document */
  document |> Document.body |> Element.appendChild (app |> Application.view);
  /* draw a square */
  let rect = Graphics.create ();
  rect |> Graphics.beginFill color::(float_of_int 0x005588) |>
  Graphics.drawRect x::40. y::40. width::200. height::200. |> ignore;
  app |> Application.stage |> Container.addChild child::(Obj.magic rect) |> ignore;
  ()
};
