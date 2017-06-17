module Utils = {
  external isWebGLSupported : unit => bool =
    "" [@@bs.scope "utils"] [@@bs.module "pixi.js"];
  external sayHello : string => unit =
    "" [@@bs.scope "utils"] [@@bs.module "pixi.js"];
};
