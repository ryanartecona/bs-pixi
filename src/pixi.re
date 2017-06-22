module Utils = {
  external isWebGLSupported : unit => bool =
    "" [@@bs.scope "utils"] [@@bs.module ("pixi.js", "PIXI")];
  external sayHello : string => unit =
    "" [@@bs.scope "utils"] [@@bs.module ("pixi.js", "PIXI")];
};

/*
 module SystemRendererClass = {
   class type _t = {
     pub autoResize: Js.boolean
   };
 };

 module ApplicationClass = {
   class type _t = {
     pub renderer: [ | `webgl unit | `canvas unit];
     pub stage: unit;
     pub ticker: unit;
     pub view: Dom.element;
     pub render: unit => unit;
     pub start: unit => unit;
     pub stop: unit => unit;
     pub destroy: bool => unit
   };
   type t = Js.t _t;
   external create : unit => t =
     "Application" [@@bs.new] [@@bs.module "pixi.js"];
 };
 */
module SystemRenderer = {
  type t;
  external autoResize : t => Js.boolean = "" [@@bs.get];
  external setAutoResize : t => Js.boolean => unit = "autoResize" [@@bs.set];
  external transparent : t => Js.boolean = "" [@@bs.get];
  external setTransparent : t => Js.boolean => unit = "transparent" [@@bs.set];
};

module Application = {
  type t;
  type opts;
  external mkOpts :
    width::int? =>
    height::int? =>
    view::Dom.element? =>
    transparent::Js.boolean? =>
    antialias::Js.boolean? =>
    preserveDrawingBuffer::Js.boolean? =>
    resolution::int? =>
    forceCanvas::Js.boolean? =>
    backgroundColor::int? =>
    clearBeforeRender::Js.boolean? =>
    roundPixels::Js.boolean? =>
    forceFXAA::Js.boolean? =>
    legacy::Js.boolean? =>
    sharedTicker::Js.boolean? =>
    sharedLoader::Js.boolean? =>
    unit =>
    opts =
    "" [@@bs.obj];
  external create : opts::opts? => unit => t =
    "Application" [@@bs.new] [@@bs.module ("pixi.js", "PIXI")];
  /* let create ::width=800 ::height=600 ::opts=? () :t => */
  /*   _create width height (); */
  external renderer : t => SystemRenderer.t = "" [@@bs.get];
  external setRenderer : t => SystemRenderer.t => unit = "" [@@bs.set];
  external view : t => Dom.element = "" [@@bs.get];
  external destroy : Js.boolean => unit = "" [@@bs.send.pipe : t];
  external render : unit => unit = "" [@@bs.send.pipe : t];
  external start : unit => unit = "" [@@bs.send.pipe : t];
  external stop : unit => unit = "" [@@bs.send.pipe : t];
};
