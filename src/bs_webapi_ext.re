open ReasonJs.Dom;

module Document = {
  include Document;
  /* external body : Dom.element = "document.body" [@@bs.val]; */
  /* external body : Dom.document => Dom.element = "body" [@@bs.get]; */
  external body : Dom.document => Dom.element = "body" [@@bs.get];
  external createTextNode : string => Dom.text = "" [@@bs.send.pipe : t];
};
