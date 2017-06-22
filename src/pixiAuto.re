module Accessibility = {
  module AccessibilityManager = {
    type t;
    /*
     <p>Setting this to true will visually show the divs.</p>
     */
    external debug : t => Js.boolean = "" [@@bs.get];
    /*
     <p>Setting this to true will visually show the divs.</p>
     */
    external setDebug : t => Js.boolean => unit = "debug" [@@bs.set];
    /*
     <p>The renderer this accessibility manager works for.</p>
     */
    external renderer : t => unit /* unknown js type: PIXI.SystemRenderer */ = "" [@@bs.get];
    /*
     <p>The renderer this accessibility manager works for.</p>
     */
    external setRenderer : t => unit /* unknown js type: PIXI.SystemRenderer */ => unit =
      "renderer" [@@bs.set];
  };
};

module Application = {
  type t;
  /*
   <p>The default options, so we mixin functionality later.</p>
   */
  external _options : t => unit /* unknown js type: object */ = "" [@@bs.get];
  /*
   <p>The default options, so we mixin functionality later.</p>
   */
  external set_options : t => unit /* unknown js type: object */ => unit = "_options" [@@bs.set];
  /*
   <p>WebGL renderer if available, otherwise CanvasRenderer</p>
   */
  external renderer : t => unit /* unknown js type: PIXI.WebGLRenderer|PIXI.CanvasRenderer */ =
    "" [@@bs.get];
  /*
   <p>WebGL renderer if available, otherwise CanvasRenderer</p>
   */
  external setRenderer :
    t => unit /* unknown js type: PIXI.WebGLRenderer|PIXI.CanvasRenderer */ => unit =
    "renderer" [@@bs.set];
  /*
   <p>The root display container that's rendered.</p>
   */
  external stage : t => unit /* unknown js type: PIXI.Container */ = "" [@@bs.get];
  /*
   <p>The root display container that's rendered.</p>
   */
  external setStage : t => unit /* unknown js type: PIXI.Container */ => unit = "stage" [@@bs.set];
  /*
   <p>Ticker for doing render updates.</p>
   */
  external ticker : t => unit /* unknown js type: PIXI.ticker.Ticker */ = "" [@@bs.get];
  /*
   <p>Ticker for doing render updates.</p>
   */
  external setTicker : t => unit /* unknown js type: PIXI.ticker.Ticker */ => unit =
    "ticker" [@@bs.set];
  /*
   <p>Reference to the renderer's canvas element.</p>
   */
  external view : t => Dom.element = "" [@@bs.get];
  /*
   <p>Reference to the renderer's screen rectangle. Its safe to use as filterArea or hitArea for whole screen</p>
   */
  external screen : t => unit /* unknown js type: PIXI.Rectangle */ = "" [@@bs.get];
  /*
   <p>Loader instance to help with asset loading.</p>
   */
  external loader : t => unit /* unknown js type: PIXI.loaders.Loader */ = "" [@@bs.get];
  /*
   <p>Loader instance to help with asset loading.</p>
   */
  external setLoader : t => unit /* unknown js type: PIXI.loaders.Loader */ => unit =
    "loader" [@@bs.set];
};

module Shader = {
  type t;
};

module Bounds = {
  type t;
  external minX : t => int = "" [@@bs.get];
  external setMinX : t => int => unit = "minX" [@@bs.set];
  external minY : t => int = "" [@@bs.get];
  external setMinY : t => int => unit = "minY" [@@bs.set];
  external maxX : t => int = "" [@@bs.get];
  external setMaxX : t => int => unit = "maxX" [@@bs.set];
  external maxY : t => int = "" [@@bs.get];
  external setMaxY : t => int => unit = "maxY" [@@bs.set];
};

module Container = {
  type t;
  /*
   <p>The array of children of this container.</p>
   */
  external children : t => array unit /* unknown js type: PIXI.DisplayObject */ = "" [@@bs.get];
  /*
   <p>The width of the Container, setting this will actually modify the scale to achieve the value set</p>
   */
  external width : t => int = "" [@@bs.get];
  /*
   <p>The width of the Container, setting this will actually modify the scale to achieve the value set</p>
   */
  external setWidth : t => int => unit = "width" [@@bs.set];
  /*
   <p>The height of the Container, setting this will actually modify the scale to achieve the value set</p>
   */
  external height : t => int = "" [@@bs.get];
  /*
   <p>The height of the Container, setting this will actually modify the scale to achieve the value set</p>
   */
  external setHeight : t => int => unit = "height" [@@bs.set];
  /*
   <p>Determines if the children to the displayObject can be clicked/touched
   Setting this to false allows pixi to bypass a recursive <code>hitTest</code> function</p>
   */
  external interactiveChildren : t => Js.boolean = "" [@@bs.get];
  /*
   <p>Determines if the children to the displayObject can be clicked/touched
   Setting this to false allows pixi to bypass a recursive <code>hitTest</code> function</p>
   */
  external setInteractiveChildren : t => Js.boolean => unit = "interactiveChildren" [@@bs.set];
  /*
   <p>World transform and local transform of this object.
   This will become read-only later, please do not assign anything there unless you know what are you doing</p>
   */
  external transform : t => unit /* unknown js type: PIXI.TransformBase */ = "" [@@bs.get];
  /*
   <p>World transform and local transform of this object.
   This will become read-only later, please do not assign anything there unless you know what are you doing</p>
   */
  external setTransform : t => unit /* unknown js type: PIXI.TransformBase */ => unit =
    "transform" [@@bs.set];
  /*
   <p>The opacity of the object.</p>
   */
  external alpha : t => int = "" [@@bs.get];
  /*
   <p>The opacity of the object.</p>
   */
  external setAlpha : t => int => unit = "alpha" [@@bs.set];
  /*
   <p>The visibility of the object. If false the object will not be drawn, and
   the updateTransform function will not be called.</p>
   <p>Only affects recursive calls from parent. You can ask for bounds or call updateTransform manually</p>
   */
  external visible : t => Js.boolean = "" [@@bs.get];
  /*
   <p>The visibility of the object. If false the object will not be drawn, and
   the updateTransform function will not be called.</p>
   <p>Only affects recursive calls from parent. You can ask for bounds or call updateTransform manually</p>
   */
  external setVisible : t => Js.boolean => unit = "visible" [@@bs.set];
  /*
   <p>Can this object be rendered, if false the object will not be drawn but the updateTransform
   methods will still be called.</p>
   <p>Only affects recursive calls from parent. You can ask for bounds manually</p>
   */
  external renderable : t => Js.boolean = "" [@@bs.get];
  /*
   <p>Can this object be rendered, if false the object will not be drawn but the updateTransform
   methods will still be called.</p>
   <p>Only affects recursive calls from parent. You can ask for bounds manually</p>
   */
  external setRenderable : t => Js.boolean => unit = "renderable" [@@bs.set];
  /*
   <p>The display object container that contains this display object.</p>
   */
  external parent : t => unit /* unknown js type: PIXI.Container */ = "" [@@bs.get];
  /*
   <p>The multiplied alpha of the displayObject</p>
   */
  external worldAlpha : t => int = "" [@@bs.get];
  /*
   <p>The area the filter is applied to. This is used as more of an optimisation
   rather than figuring out the dimensions of the displayObject each frame you can set this rectangle</p>
   <p>Also works as an interaction mask</p>
   */
  external filterArea : t => unit /* unknown js type: PIXI.Rectangle */ = "" [@@bs.get];
  /*
   <p>The area the filter is applied to. This is used as more of an optimisation
   rather than figuring out the dimensions of the displayObject each frame you can set this rectangle</p>
   <p>Also works as an interaction mask</p>
   */
  external setFilterArea : t => unit /* unknown js type: PIXI.Rectangle */ => unit =
    "filterArea" [@@bs.set];
  /*
   <p>The position of the displayObject on the x axis relative to the local coordinates of the parent.
   An alias to position.x</p>
   */
  external x : t => int = "" [@@bs.get];
  /*
   <p>The position of the displayObject on the x axis relative to the local coordinates of the parent.
   An alias to position.x</p>
   */
  external setX : t => int => unit = "x" [@@bs.set];
  /*
   <p>The position of the displayObject on the y axis relative to the local coordinates of the parent.
   An alias to position.y</p>
   */
  external y : t => int = "" [@@bs.get];
  /*
   <p>The position of the displayObject on the y axis relative to the local coordinates of the parent.
   An alias to position.y</p>
   */
  external setY : t => int => unit = "y" [@@bs.set];
  /*
   <p>Current transform of the object based on world (parent) factors</p>
   */
  external worldTransform : t => unit /* unknown js type: PIXI.Matrix */ = "" [@@bs.get];
  /*
   <p>Current transform of the object based on local factors: position, scale, other stuff</p>
   */
  external localTransform : t => unit /* unknown js type: PIXI.Matrix */ = "" [@@bs.get];
  /*
   <p>The coordinate of the object relative to the local coordinates of the parent.
   Assignment by value since pixi-v4.</p>
   */
  external position : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
    "" [@@bs.get];
  /*
   <p>The coordinate of the object relative to the local coordinates of the parent.
   Assignment by value since pixi-v4.</p>
   */
  external setPosition : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
    "position" [@@bs.set];
  /*
   <p>The scale factor of the object.
   Assignment by value since pixi-v4.</p>
   */
  external scale : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
    "" [@@bs.get];
  /*
   <p>The scale factor of the object.
   Assignment by value since pixi-v4.</p>
   */
  external setScale : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
    "scale" [@@bs.set];
  /*
   <p>The pivot point of the displayObject that it rotates around
   Assignment by value since pixi-v4.</p>
   */
  external pivot : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
    "" [@@bs.get];
  /*
   <p>The pivot point of the displayObject that it rotates around
   Assignment by value since pixi-v4.</p>
   */
  external setPivot : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
    "pivot" [@@bs.set];
  /*
   <p>The skew factor for the object in radians.
   Assignment by value since pixi-v4.</p>
   */
  external skew : t => unit /* unknown js type: PIXI.ObservablePoint */ = "" [@@bs.get];
  /*
   <p>The skew factor for the object in radians.
   Assignment by value since pixi-v4.</p>
   */
  external setSkew : t => unit /* unknown js type: PIXI.ObservablePoint */ => unit =
    "skew" [@@bs.set];
  /*
   <p>The rotation of the object in radians.</p>
   */
  external rotation : t => int = "" [@@bs.get];
  /*
   <p>The rotation of the object in radians.</p>
   */
  external setRotation : t => int => unit = "rotation" [@@bs.set];
  /*
   <p>Indicates if the object is globally visible.</p>
   */
  external worldVisible : t => Js.boolean = "" [@@bs.get];
  /*
   <p>Sets a mask for the displayObject. A mask is an object that limits the visibility of an
   object to the shape of the mask applied to it. In PIXI a regular mask must be a
   PIXI.Graphics or a PIXI.Sprite object. This allows for much faster masking in canvas as it
   utilises shape clipping. To remove a mask, set this property to null.</p>
   */
  external mask : t => unit /* unknown js type: PIXI.Graphics|PIXI.Sprite */ = "" [@@bs.get];
  /*
   <p>Sets a mask for the displayObject. A mask is an object that limits the visibility of an
   object to the shape of the mask applied to it. In PIXI a regular mask must be a
   PIXI.Graphics or a PIXI.Sprite object. This allows for much faster masking in canvas as it
   utilises shape clipping. To remove a mask, set this property to null.</p>
   */
  external setMask : t => unit /* unknown js type: PIXI.Graphics|PIXI.Sprite */ => unit =
    "mask" [@@bs.set];
  /*
   <p>Sets the filters for the displayObject.</p>
   <ul>
   <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
   To remove filters simply set this property to 'null'</li>
   </ul>
   */
  external filters : t => array unit /* unknown js type: PIXI.Filter */ = "" [@@bs.get];
  /*
   <p>Sets the filters for the displayObject.</p>
   <ul>
   <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
   To remove filters simply set this property to 'null'</li>
   </ul>
   */
  external setFilters : t => array unit /* unknown js type: PIXI.Filter */ => unit =
    "filters" [@@bs.set];
  /*
   <p>Set this to true if you want this display object to be cached as a bitmap.
   This basically takes a snap shot of the display object as it is at that moment. It can
   provide a performance benefit for complex static displayObjects.
   To remove simply set this property to 'false'</p>
   <p>IMPORTANT GOTCHA - make sure that all your textures are preloaded BEFORE setting this property to true
   as it will take a snapshot of what is currently there. If the textures have not loaded then they will not appear.</p>
   */
  external cacheAsBitmap : t => Js.boolean = "" [@@bs.get];
  /*
   <p>Set this to true if you want this display object to be cached as a bitmap.
   This basically takes a snap shot of the display object as it is at that moment. It can
   provide a performance benefit for complex static displayObjects.
   To remove simply set this property to 'false'</p>
   <p>IMPORTANT GOTCHA - make sure that all your textures are preloaded BEFORE setting this property to true
   as it will take a snapshot of what is currently there. If the textures have not loaded then they will not appear.</p>
   */
  external setCacheAsBitmap : t => Js.boolean => unit = "cacheAsBitmap" [@@bs.set];
  /*
   <p>Enable interaction events for the DisplayObject. Touch, pointer and mouse
   events will not be emitted unless <code>interactive</code> is set to <code>true</code>.</p>
   */
  external interactive : t => Js.boolean = "" [@@bs.get];
  /*
   <p>Enable interaction events for the DisplayObject. Touch, pointer and mouse
   events will not be emitted unless <code>interactive</code> is set to <code>true</code>.</p>
   */
  external setInteractive : t => Js.boolean => unit = "interactive" [@@bs.set];
  /*
   <p>Interaction shape. Children will be hit first, then this shape will be checked.
   Setting this will cause this shape to be checked in hit tests rather than the displayObject's bounds.</p>
   */
  external hitArea :
    t => unit /* unknown js type: PIXI.Rectangle|PIXI.Circle|PIXI.Ellipse|PIXI.Polygon|PIXI.RoundedRectangle */ =
    "" [@@bs.get];
  /*
   <p>Interaction shape. Children will be hit first, then this shape will be checked.
   Setting this will cause this shape to be checked in hit tests rather than the displayObject's bounds.</p>
   */
  external setHitArea :
    t =>
    unit /* unknown js type: PIXI.Rectangle|PIXI.Circle|PIXI.Ellipse|PIXI.Polygon|PIXI.RoundedRectangle */ =>
    unit =
    "hitArea" [@@bs.set];
  /*
   <p>If enabled, the mouse cursor use the pointer behavior when hovered over the displayObject if it is interactive
   Setting this changes the 'cursor' property to <code>'pointer'</code>.</p>
   */
  external buttonMode : t => Js.boolean = "" [@@bs.get];
  /*
   <p>If enabled, the mouse cursor use the pointer behavior when hovered over the displayObject if it is interactive
   Setting this changes the 'cursor' property to <code>'pointer'</code>.</p>
   */
  external setButtonMode : t => Js.boolean => unit = "buttonMode" [@@bs.set];
  /*
   <p>This defines what cursor mode is used when the mouse cursor
   is hovered over the displayObject.</p>
   */
  external cursor : t => string = "" [@@bs.get];
  /*
   <p>This defines what cursor mode is used when the mouse cursor
   is hovered over the displayObject.</p>
   */
  external setCursor : t => string => unit = "cursor" [@@bs.set];
};

module DisplayObject = {
  type t;
  /*
   <p>World transform and local transform of this object.
   This will become read-only later, please do not assign anything there unless you know what are you doing</p>
   */
  external transform : t => unit /* unknown js type: PIXI.TransformBase */ = "" [@@bs.get];
  /*
   <p>World transform and local transform of this object.
   This will become read-only later, please do not assign anything there unless you know what are you doing</p>
   */
  external setTransform : t => unit /* unknown js type: PIXI.TransformBase */ => unit =
    "transform" [@@bs.set];
  /*
   <p>The opacity of the object.</p>
   */
  external alpha : t => int = "" [@@bs.get];
  /*
   <p>The opacity of the object.</p>
   */
  external setAlpha : t => int => unit = "alpha" [@@bs.set];
  /*
   <p>The visibility of the object. If false the object will not be drawn, and
   the updateTransform function will not be called.</p>
   <p>Only affects recursive calls from parent. You can ask for bounds or call updateTransform manually</p>
   */
  external visible : t => Js.boolean = "" [@@bs.get];
  /*
   <p>The visibility of the object. If false the object will not be drawn, and
   the updateTransform function will not be called.</p>
   <p>Only affects recursive calls from parent. You can ask for bounds or call updateTransform manually</p>
   */
  external setVisible : t => Js.boolean => unit = "visible" [@@bs.set];
  /*
   <p>Can this object be rendered, if false the object will not be drawn but the updateTransform
   methods will still be called.</p>
   <p>Only affects recursive calls from parent. You can ask for bounds manually</p>
   */
  external renderable : t => Js.boolean = "" [@@bs.get];
  /*
   <p>Can this object be rendered, if false the object will not be drawn but the updateTransform
   methods will still be called.</p>
   <p>Only affects recursive calls from parent. You can ask for bounds manually</p>
   */
  external setRenderable : t => Js.boolean => unit = "renderable" [@@bs.set];
  /*
   <p>The display object container that contains this display object.</p>
   */
  external parent : t => unit /* unknown js type: PIXI.Container */ = "" [@@bs.get];
  /*
   <p>The multiplied alpha of the displayObject</p>
   */
  external worldAlpha : t => int = "" [@@bs.get];
  /*
   <p>The area the filter is applied to. This is used as more of an optimisation
   rather than figuring out the dimensions of the displayObject each frame you can set this rectangle</p>
   <p>Also works as an interaction mask</p>
   */
  external filterArea : t => unit /* unknown js type: PIXI.Rectangle */ = "" [@@bs.get];
  /*
   <p>The area the filter is applied to. This is used as more of an optimisation
   rather than figuring out the dimensions of the displayObject each frame you can set this rectangle</p>
   <p>Also works as an interaction mask</p>
   */
  external setFilterArea : t => unit /* unknown js type: PIXI.Rectangle */ => unit =
    "filterArea" [@@bs.set];
  /*
   <p>The position of the displayObject on the x axis relative to the local coordinates of the parent.
   An alias to position.x</p>
   */
  external x : t => int = "" [@@bs.get];
  /*
   <p>The position of the displayObject on the x axis relative to the local coordinates of the parent.
   An alias to position.x</p>
   */
  external setX : t => int => unit = "x" [@@bs.set];
  /*
   <p>The position of the displayObject on the y axis relative to the local coordinates of the parent.
   An alias to position.y</p>
   */
  external y : t => int = "" [@@bs.get];
  /*
   <p>The position of the displayObject on the y axis relative to the local coordinates of the parent.
   An alias to position.y</p>
   */
  external setY : t => int => unit = "y" [@@bs.set];
  /*
   <p>Current transform of the object based on world (parent) factors</p>
   */
  external worldTransform : t => unit /* unknown js type: PIXI.Matrix */ = "" [@@bs.get];
  /*
   <p>Current transform of the object based on local factors: position, scale, other stuff</p>
   */
  external localTransform : t => unit /* unknown js type: PIXI.Matrix */ = "" [@@bs.get];
  /*
   <p>The coordinate of the object relative to the local coordinates of the parent.
   Assignment by value since pixi-v4.</p>
   */
  external position : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
    "" [@@bs.get];
  /*
   <p>The coordinate of the object relative to the local coordinates of the parent.
   Assignment by value since pixi-v4.</p>
   */
  external setPosition : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
    "position" [@@bs.set];
  /*
   <p>The scale factor of the object.
   Assignment by value since pixi-v4.</p>
   */
  external scale : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
    "" [@@bs.get];
  /*
   <p>The scale factor of the object.
   Assignment by value since pixi-v4.</p>
   */
  external setScale : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
    "scale" [@@bs.set];
  /*
   <p>The pivot point of the displayObject that it rotates around
   Assignment by value since pixi-v4.</p>
   */
  external pivot : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
    "" [@@bs.get];
  /*
   <p>The pivot point of the displayObject that it rotates around
   Assignment by value since pixi-v4.</p>
   */
  external setPivot : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
    "pivot" [@@bs.set];
  /*
   <p>The skew factor for the object in radians.
   Assignment by value since pixi-v4.</p>
   */
  external skew : t => unit /* unknown js type: PIXI.ObservablePoint */ = "" [@@bs.get];
  /*
   <p>The skew factor for the object in radians.
   Assignment by value since pixi-v4.</p>
   */
  external setSkew : t => unit /* unknown js type: PIXI.ObservablePoint */ => unit =
    "skew" [@@bs.set];
  /*
   <p>The rotation of the object in radians.</p>
   */
  external rotation : t => int = "" [@@bs.get];
  /*
   <p>The rotation of the object in radians.</p>
   */
  external setRotation : t => int => unit = "rotation" [@@bs.set];
  /*
   <p>Indicates if the object is globally visible.</p>
   */
  external worldVisible : t => Js.boolean = "" [@@bs.get];
  /*
   <p>Sets a mask for the displayObject. A mask is an object that limits the visibility of an
   object to the shape of the mask applied to it. In PIXI a regular mask must be a
   PIXI.Graphics or a PIXI.Sprite object. This allows for much faster masking in canvas as it
   utilises shape clipping. To remove a mask, set this property to null.</p>
   */
  external mask : t => unit /* unknown js type: PIXI.Graphics|PIXI.Sprite */ = "" [@@bs.get];
  /*
   <p>Sets a mask for the displayObject. A mask is an object that limits the visibility of an
   object to the shape of the mask applied to it. In PIXI a regular mask must be a
   PIXI.Graphics or a PIXI.Sprite object. This allows for much faster masking in canvas as it
   utilises shape clipping. To remove a mask, set this property to null.</p>
   */
  external setMask : t => unit /* unknown js type: PIXI.Graphics|PIXI.Sprite */ => unit =
    "mask" [@@bs.set];
  /*
   <p>Sets the filters for the displayObject.</p>
   <ul>
   <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
   To remove filters simply set this property to 'null'</li>
   </ul>
   */
  external filters : t => array unit /* unknown js type: PIXI.Filter */ = "" [@@bs.get];
  /*
   <p>Sets the filters for the displayObject.</p>
   <ul>
   <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
   To remove filters simply set this property to 'null'</li>
   </ul>
   */
  external setFilters : t => array unit /* unknown js type: PIXI.Filter */ => unit =
    "filters" [@@bs.set];
  /*
   <p>Set this to true if you want this display object to be cached as a bitmap.
   This basically takes a snap shot of the display object as it is at that moment. It can
   provide a performance benefit for complex static displayObjects.
   To remove simply set this property to 'false'</p>
   <p>IMPORTANT GOTCHA - make sure that all your textures are preloaded BEFORE setting this property to true
   as it will take a snapshot of what is currently there. If the textures have not loaded then they will not appear.</p>
   */
  external cacheAsBitmap : t => Js.boolean = "" [@@bs.get];
  /*
   <p>Set this to true if you want this display object to be cached as a bitmap.
   This basically takes a snap shot of the display object as it is at that moment. It can
   provide a performance benefit for complex static displayObjects.
   To remove simply set this property to 'false'</p>
   <p>IMPORTANT GOTCHA - make sure that all your textures are preloaded BEFORE setting this property to true
   as it will take a snapshot of what is currently there. If the textures have not loaded then they will not appear.</p>
   */
  external setCacheAsBitmap : t => Js.boolean => unit = "cacheAsBitmap" [@@bs.set];
  /*
   <p>The instance name of the object.</p>
   */
  external name : t => string = "" [@@bs.get];
  /*
   <p>The instance name of the object.</p>
   */
  external setName : t => string => unit = "name" [@@bs.set];
  /*
   <p>Enable interaction events for the DisplayObject. Touch, pointer and mouse
   events will not be emitted unless <code>interactive</code> is set to <code>true</code>.</p>
   */
  external interactive : t => Js.boolean = "" [@@bs.get];
  /*
   <p>Enable interaction events for the DisplayObject. Touch, pointer and mouse
   events will not be emitted unless <code>interactive</code> is set to <code>true</code>.</p>
   */
  external setInteractive : t => Js.boolean => unit = "interactive" [@@bs.set];
  /*
   <p>Interaction shape. Children will be hit first, then this shape will be checked.
   Setting this will cause this shape to be checked in hit tests rather than the displayObject's bounds.</p>
   */
  external hitArea :
    t => unit /* unknown js type: PIXI.Rectangle|PIXI.Circle|PIXI.Ellipse|PIXI.Polygon|PIXI.RoundedRectangle */ =
    "" [@@bs.get];
  /*
   <p>Interaction shape. Children will be hit first, then this shape will be checked.
   Setting this will cause this shape to be checked in hit tests rather than the displayObject's bounds.</p>
   */
  external setHitArea :
    t =>
    unit /* unknown js type: PIXI.Rectangle|PIXI.Circle|PIXI.Ellipse|PIXI.Polygon|PIXI.RoundedRectangle */ =>
    unit =
    "hitArea" [@@bs.set];
  /*
   <p>If enabled, the mouse cursor use the pointer behavior when hovered over the displayObject if it is interactive
   Setting this changes the 'cursor' property to <code>'pointer'</code>.</p>
   */
  external buttonMode : t => Js.boolean = "" [@@bs.get];
  /*
   <p>If enabled, the mouse cursor use the pointer behavior when hovered over the displayObject if it is interactive
   Setting this changes the 'cursor' property to <code>'pointer'</code>.</p>
   */
  external setButtonMode : t => Js.boolean => unit = "buttonMode" [@@bs.set];
  /*
   <p>This defines what cursor mode is used when the mouse cursor
   is hovered over the displayObject.</p>
   */
  external cursor : t => string = "" [@@bs.get];
  /*
   <p>This defines what cursor mode is used when the mouse cursor
   is hovered over the displayObject.</p>
   */
  external setCursor : t => string => unit = "cursor" [@@bs.set];
};

module Transform = {
  type t;
  /*
   <p>The coordinate of the object relative to the local coordinates of the parent.</p>
   */
  external position : t => unit /* unknown js type: PIXI.Point */ = "" [@@bs.get];
  /*
   <p>The coordinate of the object relative to the local coordinates of the parent.</p>
   */
  external setPosition : t => unit /* unknown js type: PIXI.Point */ => unit =
    "position" [@@bs.set];
  /*
   <p>The scale factor of the object.</p>
   */
  external scale : t => unit /* unknown js type: PIXI.Point */ = "" [@@bs.get];
  /*
   <p>The scale factor of the object.</p>
   */
  external setScale : t => unit /* unknown js type: PIXI.Point */ => unit = "scale" [@@bs.set];
  /*
   <p>The skew amount, on the x and y axis.</p>
   */
  external skew : t => unit /* unknown js type: PIXI.ObservablePoint */ = "" [@@bs.get];
  /*
   <p>The skew amount, on the x and y axis.</p>
   */
  external setSkew : t => unit /* unknown js type: PIXI.ObservablePoint */ => unit =
    "skew" [@@bs.set];
  /*
   <p>The pivot point of the displayObject that it rotates around</p>
   */
  external pivot : t => unit /* unknown js type: PIXI.Point */ = "" [@@bs.get];
  /*
   <p>The pivot point of the displayObject that it rotates around</p>
   */
  external setPivot : t => unit /* unknown js type: PIXI.Point */ => unit = "pivot" [@@bs.set];
  /*
   <p>The rotation of the object in radians.</p>
   */
  external rotation : t => int = "" [@@bs.get];
  /*
   <p>The rotation of the object in radians.</p>
   */
  external setRotation : t => int => unit = "rotation" [@@bs.set];
  /*
   <p>The global matrix transform. It can be swapped temporarily by some functions like getLocalBounds()</p>
   */
  external worldTransform : t => unit /* unknown js type: PIXI.Matrix */ = "" [@@bs.get];
  /*
   <p>The global matrix transform. It can be swapped temporarily by some functions like getLocalBounds()</p>
   */
  external setWorldTransform : t => unit /* unknown js type: PIXI.Matrix */ => unit =
    "worldTransform" [@@bs.set];
  /*
   <p>The local matrix transform</p>
   */
  external localTransform : t => unit /* unknown js type: PIXI.Matrix */ = "" [@@bs.get];
  /*
   <p>The local matrix transform</p>
   */
  external setLocalTransform : t => unit /* unknown js type: PIXI.Matrix */ => unit =
    "localTransform" [@@bs.set];
};

module TransformBase = {
  type t;
  /*
   <p>The global matrix transform. It can be swapped temporarily by some functions like getLocalBounds()</p>
   */
  external worldTransform : t => unit /* unknown js type: PIXI.Matrix */ = "" [@@bs.get];
  /*
   <p>The global matrix transform. It can be swapped temporarily by some functions like getLocalBounds()</p>
   */
  external setWorldTransform : t => unit /* unknown js type: PIXI.Matrix */ => unit =
    "worldTransform" [@@bs.set];
  /*
   <p>The local matrix transform</p>
   */
  external localTransform : t => unit /* unknown js type: PIXI.Matrix */ = "" [@@bs.get];
  /*
   <p>The local matrix transform</p>
   */
  external setLocalTransform : t => unit /* unknown js type: PIXI.Matrix */ => unit =
    "localTransform" [@@bs.set];
};

module TransformStatic = {
  type t;
  /*
   <p>The coordinate of the object relative to the local coordinates of the parent.</p>
   */
  external position : t => unit /* unknown js type: PIXI.ObservablePoint */ = "" [@@bs.get];
  /*
   <p>The coordinate of the object relative to the local coordinates of the parent.</p>
   */
  external setPosition : t => unit /* unknown js type: PIXI.ObservablePoint */ => unit =
    "position" [@@bs.set];
  /*
   <p>The scale factor of the object.</p>
   */
  external scale : t => unit /* unknown js type: PIXI.ObservablePoint */ = "" [@@bs.get];
  /*
   <p>The scale factor of the object.</p>
   */
  external setScale : t => unit /* unknown js type: PIXI.ObservablePoint */ => unit =
    "scale" [@@bs.set];
  /*
   <p>The pivot point of the displayObject that it rotates around</p>
   */
  external pivot : t => unit /* unknown js type: PIXI.ObservablePoint */ = "" [@@bs.get];
  /*
   <p>The pivot point of the displayObject that it rotates around</p>
   */
  external setPivot : t => unit /* unknown js type: PIXI.ObservablePoint */ => unit =
    "pivot" [@@bs.set];
  /*
   <p>The skew amount, on the x and y axis.</p>
   */
  external skew : t => unit /* unknown js type: PIXI.ObservablePoint */ = "" [@@bs.get];
  /*
   <p>The skew amount, on the x and y axis.</p>
   */
  external setSkew : t => unit /* unknown js type: PIXI.ObservablePoint */ => unit =
    "skew" [@@bs.set];
  /*
   <p>The rotation of the object in radians.</p>
   */
  external rotation : t => int = "" [@@bs.get];
  /*
   <p>The rotation of the object in radians.</p>
   */
  external setRotation : t => int => unit = "rotation" [@@bs.set];
  /*
   <p>The global matrix transform. It can be swapped temporarily by some functions like getLocalBounds()</p>
   */
  external worldTransform : t => unit /* unknown js type: PIXI.Matrix */ = "" [@@bs.get];
  /*
   <p>The global matrix transform. It can be swapped temporarily by some functions like getLocalBounds()</p>
   */
  external setWorldTransform : t => unit /* unknown js type: PIXI.Matrix */ => unit =
    "worldTransform" [@@bs.set];
  /*
   <p>The local matrix transform</p>
   */
  external localTransform : t => unit /* unknown js type: PIXI.Matrix */ = "" [@@bs.get];
  /*
   <p>The local matrix transform</p>
   */
  external setLocalTransform : t => unit /* unknown js type: PIXI.Matrix */ => unit =
    "localTransform" [@@bs.set];
};

module Graphics = {
  type t;
  /*
   <p>The alpha value used when filling the Graphics object.</p>
   */
  external fillAlpha : t => int = "" [@@bs.get];
  /*
   <p>The alpha value used when filling the Graphics object.</p>
   */
  external setFillAlpha : t => int => unit = "fillAlpha" [@@bs.set];
  /*
   <p>The width (thickness) of any lines drawn.</p>
   */
  external lineWidth : t => int = "" [@@bs.get];
  /*
   <p>The width (thickness) of any lines drawn.</p>
   */
  external setLineWidth : t => int => unit = "lineWidth" [@@bs.set];
  /*
   <p>If true the lines will be draw using LINES instead of TRIANGLE_STRIP</p>
   */
  external nativeLines : t => Js.boolean = "" [@@bs.get];
  /*
   <p>If true the lines will be draw using LINES instead of TRIANGLE_STRIP</p>
   */
  external setNativeLines : t => Js.boolean => unit = "nativeLines" [@@bs.set];
  /*
   <p>The color of any lines drawn.</p>
   */
  external lineColor : t => string = "" [@@bs.get];
  /*
   <p>The color of any lines drawn.</p>
   */
  external setLineColor : t => string => unit = "lineColor" [@@bs.set];
  /*
   <p>The tint applied to the graphic shape. This is a hex value. Apply a value of 0xFFFFFF to
   reset the tint.</p>
   */
  external tint : t => int = "" [@@bs.get];
  /*
   <p>The tint applied to the graphic shape. This is a hex value. Apply a value of 0xFFFFFF to
   reset the tint.</p>
   */
  external setTint : t => int => unit = "tint" [@@bs.set];
  /*
   <p>The blend mode to be applied to the graphic shape. Apply a value of
   <code>PIXI.BLEND_MODES.NORMAL</code> to reset the blend mode.</p>
   */
  external blendMode : t => int = "" [@@bs.get];
  /*
   <p>The blend mode to be applied to the graphic shape. Apply a value of
   <code>PIXI.BLEND_MODES.NORMAL</code> to reset the blend mode.</p>
   */
  external setBlendMode : t => int => unit = "blendMode" [@@bs.set];
  /*
   <p>Whether this shape is being used as a mask.</p>
   */
  external isMask : t => Js.boolean = "" [@@bs.get];
  /*
   <p>Whether this shape is being used as a mask.</p>
   */
  external setIsMask : t => Js.boolean => unit = "isMask" [@@bs.set];
  /*
   <p>The bounds' padding used for bounds calculation.</p>
   */
  external boundsPadding : t => int = "" [@@bs.get];
  /*
   <p>The bounds' padding used for bounds calculation.</p>
   */
  external setBoundsPadding : t => int => unit = "boundsPadding" [@@bs.set];
  /*
   <p>Used to detect if we need to do a fast rect check using the id compare method</p>
   */
  external fastRectDirty : t => int = "" [@@bs.get];
  /*
   <p>Used to detect if we need to do a fast rect check using the id compare method</p>
   */
  external setFastRectDirty : t => int => unit = "fastRectDirty" [@@bs.set];
  /*
   <p>Used to detect if we clear the graphics webGL data</p>
   */
  external clearDirty : t => int = "" [@@bs.get];
  /*
   <p>Used to detect if we clear the graphics webGL data</p>
   */
  external setClearDirty : t => int => unit = "clearDirty" [@@bs.set];
  /*
   <p>Used to detect if we we need to recalculate local bounds</p>
   */
  external boundsDirty : t => int = "" [@@bs.get];
  /*
   <p>Used to detect if we we need to recalculate local bounds</p>
   */
  external setBoundsDirty : t => int => unit = "boundsDirty" [@@bs.set];
  /*
   <p>When cacheAsBitmap is set to true the graphics object will be rendered as if it was a sprite.
   This is useful if your graphics element does not change often, as it will speed up the rendering
   of the object in exchange for taking up texture memory. It is also useful if you need the graphics
   object to be anti-aliased, because it will be rendered using canvas. This is not recommended if
   you are constantly redrawing the graphics element.</p>
   */
  external cacheAsBitmap : t => Js.boolean = "" [@@bs.get];
  /*
   <p>When cacheAsBitmap is set to true the graphics object will be rendered as if it was a sprite.
   This is useful if your graphics element does not change often, as it will speed up the rendering
   of the object in exchange for taking up texture memory. It is also useful if you need the graphics
   object to be anti-aliased, because it will be rendered using canvas. This is not recommended if
   you are constantly redrawing the graphics element.</p>
   */
  external setCacheAsBitmap : t => Js.boolean => unit = "cacheAsBitmap" [@@bs.set];
  /*
   <p>The array of children of this container.</p>
   */
  external children : t => array unit /* unknown js type: PIXI.DisplayObject */ = "" [@@bs.get];
  /*
   <p>The width of the Container, setting this will actually modify the scale to achieve the value set</p>
   */
  external width : t => int = "" [@@bs.get];
  /*
   <p>The width of the Container, setting this will actually modify the scale to achieve the value set</p>
   */
  external setWidth : t => int => unit = "width" [@@bs.set];
  /*
   <p>The height of the Container, setting this will actually modify the scale to achieve the value set</p>
   */
  external height : t => int = "" [@@bs.get];
  /*
   <p>The height of the Container, setting this will actually modify the scale to achieve the value set</p>
   */
  external setHeight : t => int => unit = "height" [@@bs.set];
  /*
   <p>Determines if the children to the displayObject can be clicked/touched
   Setting this to false allows pixi to bypass a recursive <code>hitTest</code> function</p>
   */
  external interactiveChildren : t => Js.boolean = "" [@@bs.get];
  /*
   <p>Determines if the children to the displayObject can be clicked/touched
   Setting this to false allows pixi to bypass a recursive <code>hitTest</code> function</p>
   */
  external setInteractiveChildren : t => Js.boolean => unit = "interactiveChildren" [@@bs.set];
  /*
   <p>World transform and local transform of this object.
   This will become read-only later, please do not assign anything there unless you know what are you doing</p>
   */
  external transform : t => unit /* unknown js type: PIXI.TransformBase */ = "" [@@bs.get];
  /*
   <p>World transform and local transform of this object.
   This will become read-only later, please do not assign anything there unless you know what are you doing</p>
   */
  external setTransform : t => unit /* unknown js type: PIXI.TransformBase */ => unit =
    "transform" [@@bs.set];
  /*
   <p>The opacity of the object.</p>
   */
  external alpha : t => int = "" [@@bs.get];
  /*
   <p>The opacity of the object.</p>
   */
  external setAlpha : t => int => unit = "alpha" [@@bs.set];
  /*
   <p>The visibility of the object. If false the object will not be drawn, and
   the updateTransform function will not be called.</p>
   <p>Only affects recursive calls from parent. You can ask for bounds or call updateTransform manually</p>
   */
  external visible : t => Js.boolean = "" [@@bs.get];
  /*
   <p>The visibility of the object. If false the object will not be drawn, and
   the updateTransform function will not be called.</p>
   <p>Only affects recursive calls from parent. You can ask for bounds or call updateTransform manually</p>
   */
  external setVisible : t => Js.boolean => unit = "visible" [@@bs.set];
  /*
   <p>Can this object be rendered, if false the object will not be drawn but the updateTransform
   methods will still be called.</p>
   <p>Only affects recursive calls from parent. You can ask for bounds manually</p>
   */
  external renderable : t => Js.boolean = "" [@@bs.get];
  /*
   <p>Can this object be rendered, if false the object will not be drawn but the updateTransform
   methods will still be called.</p>
   <p>Only affects recursive calls from parent. You can ask for bounds manually</p>
   */
  external setRenderable : t => Js.boolean => unit = "renderable" [@@bs.set];
  /*
   <p>The display object container that contains this display object.</p>
   */
  external parent : t => unit /* unknown js type: PIXI.Container */ = "" [@@bs.get];
  /*
   <p>The multiplied alpha of the displayObject</p>
   */
  external worldAlpha : t => int = "" [@@bs.get];
  /*
   <p>The area the filter is applied to. This is used as more of an optimisation
   rather than figuring out the dimensions of the displayObject each frame you can set this rectangle</p>
   <p>Also works as an interaction mask</p>
   */
  external filterArea : t => unit /* unknown js type: PIXI.Rectangle */ = "" [@@bs.get];
  /*
   <p>The area the filter is applied to. This is used as more of an optimisation
   rather than figuring out the dimensions of the displayObject each frame you can set this rectangle</p>
   <p>Also works as an interaction mask</p>
   */
  external setFilterArea : t => unit /* unknown js type: PIXI.Rectangle */ => unit =
    "filterArea" [@@bs.set];
  /*
   <p>The position of the displayObject on the x axis relative to the local coordinates of the parent.
   An alias to position.x</p>
   */
  external x : t => int = "" [@@bs.get];
  /*
   <p>The position of the displayObject on the x axis relative to the local coordinates of the parent.
   An alias to position.x</p>
   */
  external setX : t => int => unit = "x" [@@bs.set];
  /*
   <p>The position of the displayObject on the y axis relative to the local coordinates of the parent.
   An alias to position.y</p>
   */
  external y : t => int = "" [@@bs.get];
  /*
   <p>The position of the displayObject on the y axis relative to the local coordinates of the parent.
   An alias to position.y</p>
   */
  external setY : t => int => unit = "y" [@@bs.set];
  /*
   <p>Current transform of the object based on world (parent) factors</p>
   */
  external worldTransform : t => unit /* unknown js type: PIXI.Matrix */ = "" [@@bs.get];
  /*
   <p>Current transform of the object based on local factors: position, scale, other stuff</p>
   */
  external localTransform : t => unit /* unknown js type: PIXI.Matrix */ = "" [@@bs.get];
  /*
   <p>The coordinate of the object relative to the local coordinates of the parent.
   Assignment by value since pixi-v4.</p>
   */
  external position : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
    "" [@@bs.get];
  /*
   <p>The coordinate of the object relative to the local coordinates of the parent.
   Assignment by value since pixi-v4.</p>
   */
  external setPosition : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
    "position" [@@bs.set];
  /*
   <p>The scale factor of the object.
   Assignment by value since pixi-v4.</p>
   */
  external scale : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
    "" [@@bs.get];
  /*
   <p>The scale factor of the object.
   Assignment by value since pixi-v4.</p>
   */
  external setScale : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
    "scale" [@@bs.set];
  /*
   <p>The pivot point of the displayObject that it rotates around
   Assignment by value since pixi-v4.</p>
   */
  external pivot : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
    "" [@@bs.get];
  /*
   <p>The pivot point of the displayObject that it rotates around
   Assignment by value since pixi-v4.</p>
   */
  external setPivot : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
    "pivot" [@@bs.set];
  /*
   <p>The skew factor for the object in radians.
   Assignment by value since pixi-v4.</p>
   */
  external skew : t => unit /* unknown js type: PIXI.ObservablePoint */ = "" [@@bs.get];
  /*
   <p>The skew factor for the object in radians.
   Assignment by value since pixi-v4.</p>
   */
  external setSkew : t => unit /* unknown js type: PIXI.ObservablePoint */ => unit =
    "skew" [@@bs.set];
  /*
   <p>The rotation of the object in radians.</p>
   */
  external rotation : t => int = "" [@@bs.get];
  /*
   <p>The rotation of the object in radians.</p>
   */
  external setRotation : t => int => unit = "rotation" [@@bs.set];
  /*
   <p>Indicates if the object is globally visible.</p>
   */
  external worldVisible : t => Js.boolean = "" [@@bs.get];
  /*
   <p>Sets a mask for the displayObject. A mask is an object that limits the visibility of an
   object to the shape of the mask applied to it. In PIXI a regular mask must be a
   PIXI.Graphics or a PIXI.Sprite object. This allows for much faster masking in canvas as it
   utilises shape clipping. To remove a mask, set this property to null.</p>
   */
  external mask : t => unit /* unknown js type: PIXI.Graphics|PIXI.Sprite */ = "" [@@bs.get];
  /*
   <p>Sets a mask for the displayObject. A mask is an object that limits the visibility of an
   object to the shape of the mask applied to it. In PIXI a regular mask must be a
   PIXI.Graphics or a PIXI.Sprite object. This allows for much faster masking in canvas as it
   utilises shape clipping. To remove a mask, set this property to null.</p>
   */
  external setMask : t => unit /* unknown js type: PIXI.Graphics|PIXI.Sprite */ => unit =
    "mask" [@@bs.set];
  /*
   <p>Sets the filters for the displayObject.</p>
   <ul>
   <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
   To remove filters simply set this property to 'null'</li>
   </ul>
   */
  external filters : t => array unit /* unknown js type: PIXI.Filter */ = "" [@@bs.get];
  /*
   <p>Sets the filters for the displayObject.</p>
   <ul>
   <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
   To remove filters simply set this property to 'null'</li>
   </ul>
   */
  external setFilters : t => array unit /* unknown js type: PIXI.Filter */ => unit =
    "filters" [@@bs.set];
  /*
   <p>Enable interaction events for the DisplayObject. Touch, pointer and mouse
   events will not be emitted unless <code>interactive</code> is set to <code>true</code>.</p>
   */
  external interactive : t => Js.boolean = "" [@@bs.get];
  /*
   <p>Enable interaction events for the DisplayObject. Touch, pointer and mouse
   events will not be emitted unless <code>interactive</code> is set to <code>true</code>.</p>
   */
  external setInteractive : t => Js.boolean => unit = "interactive" [@@bs.set];
  /*
   <p>Interaction shape. Children will be hit first, then this shape will be checked.
   Setting this will cause this shape to be checked in hit tests rather than the displayObject's bounds.</p>
   */
  external hitArea :
    t => unit /* unknown js type: PIXI.Rectangle|PIXI.Circle|PIXI.Ellipse|PIXI.Polygon|PIXI.RoundedRectangle */ =
    "" [@@bs.get];
  /*
   <p>Interaction shape. Children will be hit first, then this shape will be checked.
   Setting this will cause this shape to be checked in hit tests rather than the displayObject's bounds.</p>
   */
  external setHitArea :
    t =>
    unit /* unknown js type: PIXI.Rectangle|PIXI.Circle|PIXI.Ellipse|PIXI.Polygon|PIXI.RoundedRectangle */ =>
    unit =
    "hitArea" [@@bs.set];
  /*
   <p>If enabled, the mouse cursor use the pointer behavior when hovered over the displayObject if it is interactive
   Setting this changes the 'cursor' property to <code>'pointer'</code>.</p>
   */
  external buttonMode : t => Js.boolean = "" [@@bs.get];
  /*
   <p>If enabled, the mouse cursor use the pointer behavior when hovered over the displayObject if it is interactive
   Setting this changes the 'cursor' property to <code>'pointer'</code>.</p>
   */
  external setButtonMode : t => Js.boolean => unit = "buttonMode" [@@bs.set];
  /*
   <p>This defines what cursor mode is used when the mouse cursor
   is hovered over the displayObject.</p>
   */
  external cursor : t => string = "" [@@bs.get];
  /*
   <p>This defines what cursor mode is used when the mouse cursor
   is hovered over the displayObject.</p>
   */
  external setCursor : t => string => unit = "cursor" [@@bs.set];
};

module GraphicsData = {
  type t;
};

module CanvasGraphicsRenderer = {
  type t;
};

module GraphicsRenderer = {
  type t;
  /*
   <p>The renderer this manager works for.</p>
   */
  external renderer : t => unit /* unknown js type: PIXI.WebGLRenderer */ = "" [@@bs.get];
  /*
   <p>The renderer this manager works for.</p>
   */
  external setRenderer : t => unit /* unknown js type: PIXI.WebGLRenderer */ => unit =
    "renderer" [@@bs.set];
};

module WebGLGraphicsData = {
  type t;
  /*
   <p>The current WebGL drawing context</p>
   */
  external gl : t => ReasonJs.Gl.glT = "" [@@bs.get];
  /*
   <p>The current WebGL drawing context</p>
   */
  external setGl : t => ReasonJs.Gl.glT => unit = "gl" [@@bs.set];
  /*
   <p>An array of color components (r,g,b)</p>
   */
  external color : t => array int = "" [@@bs.get];
  /*
   <p>An array of color components (r,g,b)</p>
   */
  external setColor : t => array int => unit = "color" [@@bs.set];
  /*
   <p>An array of points to draw</p>
   */
  external points : t => array unit /* unknown js type: PIXI.Point */ = "" [@@bs.get];
  /*
   <p>An array of points to draw</p>
   */
  external setPoints : t => array unit /* unknown js type: PIXI.Point */ => unit =
    "points" [@@bs.set];
  /*
   <p>The indices of the vertices</p>
   */
  external indices : t => array int = "" [@@bs.get];
  /*
   <p>The indices of the vertices</p>
   */
  external setIndices : t => array int => unit = "indices" [@@bs.set];
  /*
   <p>The main buffer</p>
   */
  external buffer : t => ReasonJs.Gl.bufferT = "" [@@bs.get];
  /*
   <p>The main buffer</p>
   */
  external setBuffer : t => ReasonJs.Gl.bufferT => unit = "buffer" [@@bs.set];
  /*
   <p>The index buffer</p>
   */
  external indexBuffer : t => ReasonJs.Gl.bufferT = "" [@@bs.get];
  /*
   <p>The index buffer</p>
   */
  external setIndexBuffer : t => ReasonJs.Gl.bufferT => unit = "indexBuffer" [@@bs.set];
  /*
   <p>Whether this graphics is dirty or not</p>
   */
  external dirty : t => Js.boolean = "" [@@bs.get];
  /*
   <p>Whether this graphics is dirty or not</p>
   */
  external setDirty : t => Js.boolean => unit = "dirty" [@@bs.set];
  /*
   <p>Whether this graphics is nativeLines or not</p>
   */
  external nativeLines : t => Js.boolean = "" [@@bs.get];
  /*
   <p>Whether this graphics is nativeLines or not</p>
   */
  external setNativeLines : t => Js.boolean => unit = "nativeLines" [@@bs.set];
  external shader : t => unit /* unknown js type: PIXI.Shader */ = "" [@@bs.get];
  external setShader : t => unit /* unknown js type: PIXI.Shader */ => unit = "shader" [@@bs.set];
};

module PrimitiveShader = {
  type t;
};

module GroupD8 = {
  /*
   <p>Implements Dihedral Group D_8, see [group D4]{@link http://mathworld.wolfram.com/DihedralGroupD4.html},
   D8 is the same but with diagonals. Used for texture rotations.</p>
   <p>Vector xX(i), xY(i) is U-axis of sprite with rotation i
   Vector yY(i), yY(i) is V-axis of sprite with rotation i
   Rotations: 0 grad (0), 90 grad (2), 180 grad (4), 270 grad (6)
   Mirrors: vertical (8), main diagonal (10), horizontal (12), reverse diagonal (14)
   This is the small part of gameofbombs.com portal system. It works.</p>
   */
  type t;
};

module Matrix = {
  type t;
  external a : t => int = "" [@@bs.get];
  external setA : t => int => unit = "a" [@@bs.set];
  external b : t => int = "" [@@bs.get];
  external setB : t => int => unit = "b" [@@bs.set];
  external c : t => int = "" [@@bs.get];
  external setC : t => int => unit = "c" [@@bs.set];
  external d : t => int = "" [@@bs.get];
  external setD : t => int => unit = "d" [@@bs.set];
  external tx : t => int = "" [@@bs.get];
  external setTx : t => int => unit = "tx" [@@bs.set];
  external ty : t => int = "" [@@bs.get];
  external setTy : t => int => unit = "ty" [@@bs.set];
};

module ObservablePoint = {
  type t;
  /*
   <p>The position of the displayObject on the x axis relative to the local coordinates of the parent.</p>
   */
  external x : t => int = "" [@@bs.get];
  /*
   <p>The position of the displayObject on the x axis relative to the local coordinates of the parent.</p>
   */
  external setX : t => int => unit = "x" [@@bs.set];
  /*
   <p>The position of the displayObject on the x axis relative to the local coordinates of the parent.</p>
   */
  external y : t => int = "" [@@bs.get];
  /*
   <p>The position of the displayObject on the x axis relative to the local coordinates of the parent.</p>
   */
  external setY : t => int => unit = "y" [@@bs.set];
};

module Point = {
  type t;
  external x : t => int = "" [@@bs.get];
  external setX : t => int => unit = "x" [@@bs.set];
  external y : t => int = "" [@@bs.get];
  external setY : t => int => unit = "y" [@@bs.set];
};

module Circle = {
  type t;
  external x : t => int = "" [@@bs.get];
  external setX : t => int => unit = "x" [@@bs.set];
  external y : t => int = "" [@@bs.get];
  external setY : t => int => unit = "y" [@@bs.set];
  external radius : t => int = "" [@@bs.get];
  external setRadius : t => int => unit = "radius" [@@bs.set];
  /*
   <p>The type of the object, mainly used to avoid <code>instanceof</code> checks</p>
   */
  external type_ : t => int = "type" [@@bs.get];
};

module Ellipse = {
  type t;
  external x : t => int = "" [@@bs.get];
  external setX : t => int => unit = "x" [@@bs.set];
  external y : t => int = "" [@@bs.get];
  external setY : t => int => unit = "y" [@@bs.set];
  external width : t => int = "" [@@bs.get];
  external setWidth : t => int => unit = "width" [@@bs.set];
  external height : t => int = "" [@@bs.get];
  external setHeight : t => int => unit = "height" [@@bs.set];
  /*
   <p>The type of the object, mainly used to avoid <code>instanceof</code> checks</p>
   */
  external type_ : t => int = "type" [@@bs.get];
};

module Polygon = {
  type t;
  /*
   <p>An array of the points of this polygon</p>
   */
  external points : t => array int = "" [@@bs.get];
  /*
   <p>An array of the points of this polygon</p>
   */
  external setPoints : t => array int => unit = "points" [@@bs.set];
  /*
   <p>The type of the object, mainly used to avoid <code>instanceof</code> checks</p>
   */
  external type_ : t => int = "type" [@@bs.get];
};

module Rectangle = {
  type t;
  external x : t => int = "" [@@bs.get];
  external setX : t => int => unit = "x" [@@bs.set];
  external y : t => int = "" [@@bs.get];
  external setY : t => int => unit = "y" [@@bs.set];
  external width : t => int = "" [@@bs.get];
  external setWidth : t => int => unit = "width" [@@bs.set];
  external height : t => int = "" [@@bs.get];
  external setHeight : t => int => unit = "height" [@@bs.set];
  /*
   <p>The type of the object, mainly used to avoid <code>instanceof</code> checks</p>
   */
  external type_ : t => int = "type" [@@bs.get];
  /*
   <p>returns the left edge of the rectangle</p>
   */
  external left : t => int = "" [@@bs.get];
  /*
   <p>returns the left edge of the rectangle</p>
   */
  external setLeft : t => int => unit = "left" [@@bs.set];
  /*
   <p>returns the right edge of the rectangle</p>
   */
  external right : t => int = "" [@@bs.get];
  /*
   <p>returns the right edge of the rectangle</p>
   */
  external setRight : t => int => unit = "right" [@@bs.set];
  /*
   <p>returns the top edge of the rectangle</p>
   */
  external top : t => int = "" [@@bs.get];
  /*
   <p>returns the top edge of the rectangle</p>
   */
  external setTop : t => int => unit = "top" [@@bs.set];
  /*
   <p>returns the bottom edge of the rectangle</p>
   */
  external bottom : t => int = "" [@@bs.get];
  /*
   <p>returns the bottom edge of the rectangle</p>
   */
  external setBottom : t => int => unit = "bottom" [@@bs.set];
};

module RoundedRectangle = {
  type t;
  external x : t => int = "" [@@bs.get];
  external setX : t => int => unit = "x" [@@bs.set];
  external y : t => int = "" [@@bs.get];
  external setY : t => int => unit = "y" [@@bs.set];
  external width : t => int = "" [@@bs.get];
  external setWidth : t => int => unit = "width" [@@bs.set];
  external height : t => int = "" [@@bs.get];
  external setHeight : t => int => unit = "height" [@@bs.set];
  external radius : t => int = "" [@@bs.get];
  external setRadius : t => int => unit = "radius" [@@bs.set];
  /*
   <p>The type of the object, mainly used to avoid <code>instanceof</code> checks</p>
   */
  external type_ : t => int = "type" [@@bs.get];
};

module SystemRenderer = {
  type t;
  /*
   <p>The supplied constructor options.</p>
   */
  external options : t => unit /* unknown js type: Object */ = "" [@@bs.get];
  /*
   <p>The type of the renderer.</p>
   */
  external type_ : t => int = "type" [@@bs.get];
  /*
   <p>The type of the renderer.</p>
   */
  external setType : t => int => unit = "type" [@@bs.set];
  /*
   <p>Measurements of the screen. (0, 0, screenWidth, screenHeight)</p>
   <p>Its safe to use as filterArea or hitArea for whole stage</p>
   */
  external screen : t => unit /* unknown js type: PIXI.Rectangle */ = "" [@@bs.get];
  /*
   <p>Measurements of the screen. (0, 0, screenWidth, screenHeight)</p>
   <p>Its safe to use as filterArea or hitArea for whole stage</p>
   */
  external setScreen : t => unit /* unknown js type: PIXI.Rectangle */ => unit =
    "screen" [@@bs.set];
  /*
   <p>The canvas element that everything is drawn to</p>
   */
  external view : t => Dom.element = "" [@@bs.get];
  /*
   <p>The canvas element that everything is drawn to</p>
   */
  external setView : t => Dom.element => unit = "view" [@@bs.set];
  /*
   <p>The resolution / device pixel ratio of the renderer</p>
   */
  external resolution : t => int = "" [@@bs.get];
  /*
   <p>The resolution / device pixel ratio of the renderer</p>
   */
  external setResolution : t => int => unit = "resolution" [@@bs.set];
  /*
   <p>Whether the render view is transparent</p>
   */
  external transparent : t => Js.boolean = "" [@@bs.get];
  /*
   <p>Whether the render view is transparent</p>
   */
  external setTransparent : t => Js.boolean => unit = "transparent" [@@bs.set];
  /*
   <p>Whether css dimensions of canvas view should be resized to screen dimensions automatically</p>
   */
  external autoResize : t => Js.boolean = "" [@@bs.get];
  /*
   <p>Whether css dimensions of canvas view should be resized to screen dimensions automatically</p>
   */
  external setAutoResize : t => Js.boolean => unit = "autoResize" [@@bs.set];
  /*
   <p>Tracks the blend modes useful for this renderer.</p>
   */
  external blendModes : t => unit /* unknown js type: object.<string, mixed> */ = "" [@@bs.get];
  /*
   <p>Tracks the blend modes useful for this renderer.</p>
   */
  external setBlendModes : t => unit /* unknown js type: object.<string, mixed> */ => unit =
    "blendModes" [@@bs.set];
  /*
   <p>The value of the preserveDrawingBuffer flag affects whether or not the contents of
   the stencil buffer is retained after rendering.</p>
   */
  external preserveDrawingBuffer : t => Js.boolean = "" [@@bs.get];
  /*
   <p>The value of the preserveDrawingBuffer flag affects whether or not the contents of
   the stencil buffer is retained after rendering.</p>
   */
  external setPreserveDrawingBuffer : t => Js.boolean => unit = "preserveDrawingBuffer" [@@bs.set];
  /*
   <p>This sets if the CanvasRenderer will clear the canvas or not before the new render pass.
   If the scene is NOT transparent Pixi will use a canvas sized fillRect operation every
   frame to set the canvas background color. If the scene is transparent Pixi will use clearRect
   to clear the canvas every frame. Disable this by setting this to false. For example if
   your game has a canvas filling background image you often don't need this set.</p>
   */
  external clearBeforeRender : t => Js.boolean = "" [@@bs.get];
  /*
   <p>This sets if the CanvasRenderer will clear the canvas or not before the new render pass.
   If the scene is NOT transparent Pixi will use a canvas sized fillRect operation every
   frame to set the canvas background color. If the scene is transparent Pixi will use clearRect
   to clear the canvas every frame. Disable this by setting this to false. For example if
   your game has a canvas filling background image you often don't need this set.</p>
   */
  external setClearBeforeRender : t => Js.boolean => unit = "clearBeforeRender" [@@bs.set];
  /*
   <p>If true Pixi will Math.floor() x/y values when rendering, stopping pixel interpolation.
   Handy for crisp pixel art and speed on legacy devices.</p>
   */
  external roundPixels : t => Js.boolean = "" [@@bs.get];
  /*
   <p>If true Pixi will Math.floor() x/y values when rendering, stopping pixel interpolation.
   Handy for crisp pixel art and speed on legacy devices.</p>
   */
  external setRoundPixels : t => Js.boolean => unit = "roundPixels" [@@bs.set];
  /*
   <p>Same as view.width, actual number of pixels in the canvas by horizontal</p>
   */
  external width : t => int = "" [@@bs.get];
  /*
   <p>Same as view.height, actual number of pixels in the canvas by vertical</p>
   */
  external height : t => int = "" [@@bs.get];
  /*
   <p>The background color to fill if not transparent</p>
   */
  external backgroundColor : t => int = "" [@@bs.get];
  /*
   <p>The background color to fill if not transparent</p>
   */
  external setBackgroundColor : t => int => unit = "backgroundColor" [@@bs.set];
};

module CanvasRenderer = {
  type t;
  /*
   <p>The root canvas 2d context that everything is drawn with.</p>
   */
  external rootContext : t => unit /* unknown js type: CanvasRenderingContext2D */ = "" [@@bs.get];
  /*
   <p>The root canvas 2d context that everything is drawn with.</p>
   */
  external setRootContext : t => unit /* unknown js type: CanvasRenderingContext2D */ => unit =
    "rootContext" [@@bs.set];
  /*
   <p>The currently active canvas 2d context (could change with renderTextures)</p>
   */
  external context : t => unit /* unknown js type: CanvasRenderingContext2D */ = "" [@@bs.get];
  /*
   <p>The currently active canvas 2d context (could change with renderTextures)</p>
   */
  external setContext : t => unit /* unknown js type: CanvasRenderingContext2D */ => unit =
    "context" [@@bs.set];
  /*
   <p>Boolean flag controlling canvas refresh.</p>
   */
  external refresh : t => Js.boolean = "" [@@bs.get];
  /*
   <p>Boolean flag controlling canvas refresh.</p>
   */
  external setRefresh : t => Js.boolean => unit = "refresh" [@@bs.set];
  /*
   <p>Instance of a CanvasMaskManager, handles masking when using the canvas renderer.</p>
   */
  external maskManager : t => unit /* unknown js type: PIXI.CanvasMaskManager */ = "" [@@bs.get];
  /*
   <p>Instance of a CanvasMaskManager, handles masking when using the canvas renderer.</p>
   */
  external setMaskManager : t => unit /* unknown js type: PIXI.CanvasMaskManager */ => unit =
    "maskManager" [@@bs.set];
  /*
   <p>The canvas property used to set the canvas smoothing property.</p>
   */
  external smoothProperty : t => string = "" [@@bs.get];
  /*
   <p>The canvas property used to set the canvas smoothing property.</p>
   */
  external setSmoothProperty : t => string => unit = "smoothProperty" [@@bs.set];
  /*
   <p>Collection of installed plugins. These are included by default in PIXI, but can be excluded
   by creating a custom build. Consult the README for more information about creating custom
   builds and excluding plugins.</p>
   */
  external plugins : t => unit /* unknown js type: object */ = "" [@@bs.get];
  /*
   <p>Collection of methods for extracting data (image, pixels, etc.) from a display object or render texture</p>
   */
  external extract : t => unit /* unknown js type: PIXI.extract.CanvasExtract */ = "" [@@bs.get];
  /*
   <p>Collection of methods for extracting data (image, pixels, etc.) from a display object or render texture</p>
   */
  external setExtract : t => unit /* unknown js type: PIXI.extract.CanvasExtract */ => unit =
    "extract" [@@bs.set];
  /*
   <p>The supplied constructor options.</p>
   */
  external options : t => unit /* unknown js type: Object */ = "" [@@bs.get];
  /*
   <p>The type of the renderer.</p>
   */
  external type_ : t => int = "type" [@@bs.get];
  /*
   <p>The type of the renderer.</p>
   */
  external setType : t => int => unit = "type" [@@bs.set];
  /*
   <p>Measurements of the screen. (0, 0, screenWidth, screenHeight)</p>
   <p>Its safe to use as filterArea or hitArea for whole stage</p>
   */
  external screen : t => unit /* unknown js type: PIXI.Rectangle */ = "" [@@bs.get];
  /*
   <p>Measurements of the screen. (0, 0, screenWidth, screenHeight)</p>
   <p>Its safe to use as filterArea or hitArea for whole stage</p>
   */
  external setScreen : t => unit /* unknown js type: PIXI.Rectangle */ => unit =
    "screen" [@@bs.set];
  /*
   <p>The canvas element that everything is drawn to</p>
   */
  external view : t => Dom.element = "" [@@bs.get];
  /*
   <p>The canvas element that everything is drawn to</p>
   */
  external setView : t => Dom.element => unit = "view" [@@bs.set];
  /*
   <p>The resolution / device pixel ratio of the renderer</p>
   */
  external resolution : t => int = "" [@@bs.get];
  /*
   <p>The resolution / device pixel ratio of the renderer</p>
   */
  external setResolution : t => int => unit = "resolution" [@@bs.set];
  /*
   <p>Whether the render view is transparent</p>
   */
  external transparent : t => Js.boolean = "" [@@bs.get];
  /*
   <p>Whether the render view is transparent</p>
   */
  external setTransparent : t => Js.boolean => unit = "transparent" [@@bs.set];
  /*
   <p>Whether css dimensions of canvas view should be resized to screen dimensions automatically</p>
   */
  external autoResize : t => Js.boolean = "" [@@bs.get];
  /*
   <p>Whether css dimensions of canvas view should be resized to screen dimensions automatically</p>
   */
  external setAutoResize : t => Js.boolean => unit = "autoResize" [@@bs.set];
  /*
   <p>Tracks the blend modes useful for this renderer.</p>
   */
  external blendModes : t => unit /* unknown js type: object.<string, mixed> */ = "" [@@bs.get];
  /*
   <p>Tracks the blend modes useful for this renderer.</p>
   */
  external setBlendModes : t => unit /* unknown js type: object.<string, mixed> */ => unit =
    "blendModes" [@@bs.set];
  /*
   <p>The value of the preserveDrawingBuffer flag affects whether or not the contents of
   the stencil buffer is retained after rendering.</p>
   */
  external preserveDrawingBuffer : t => Js.boolean = "" [@@bs.get];
  /*
   <p>The value of the preserveDrawingBuffer flag affects whether or not the contents of
   the stencil buffer is retained after rendering.</p>
   */
  external setPreserveDrawingBuffer : t => Js.boolean => unit = "preserveDrawingBuffer" [@@bs.set];
  /*
   <p>This sets if the CanvasRenderer will clear the canvas or not before the new render pass.
   If the scene is NOT transparent Pixi will use a canvas sized fillRect operation every
   frame to set the canvas background color. If the scene is transparent Pixi will use clearRect
   to clear the canvas every frame. Disable this by setting this to false. For example if
   your game has a canvas filling background image you often don't need this set.</p>
   */
  external clearBeforeRender : t => Js.boolean = "" [@@bs.get];
  /*
   <p>This sets if the CanvasRenderer will clear the canvas or not before the new render pass.
   If the scene is NOT transparent Pixi will use a canvas sized fillRect operation every
   frame to set the canvas background color. If the scene is transparent Pixi will use clearRect
   to clear the canvas every frame. Disable this by setting this to false. For example if
   your game has a canvas filling background image you often don't need this set.</p>
   */
  external setClearBeforeRender : t => Js.boolean => unit = "clearBeforeRender" [@@bs.set];
  /*
   <p>If true Pixi will Math.floor() x/y values when rendering, stopping pixel interpolation.
   Handy for crisp pixel art and speed on legacy devices.</p>
   */
  external roundPixels : t => Js.boolean = "" [@@bs.get];
  /*
   <p>If true Pixi will Math.floor() x/y values when rendering, stopping pixel interpolation.
   Handy for crisp pixel art and speed on legacy devices.</p>
   */
  external setRoundPixels : t => Js.boolean => unit = "roundPixels" [@@bs.set];
  /*
   <p>Same as view.width, actual number of pixels in the canvas by horizontal</p>
   */
  external width : t => int = "" [@@bs.get];
  /*
   <p>Same as view.height, actual number of pixels in the canvas by vertical</p>
   */
  external height : t => int = "" [@@bs.get];
  /*
   <p>The background color to fill if not transparent</p>
   */
  external backgroundColor : t => int = "" [@@bs.get];
  /*
   <p>The background color to fill if not transparent</p>
   */
  external setBackgroundColor : t => int => unit = "backgroundColor" [@@bs.set];
};

module CanvasMaskManager = {
  type t;
};

module CanvasRenderTarget = {
  type t;
  /*
   <p>The Canvas object that belongs to this CanvasRenderTarget.</p>
   */
  external canvas : t => Dom.element = "" [@@bs.get];
  /*
   <p>The Canvas object that belongs to this CanvasRenderTarget.</p>
   */
  external setCanvas : t => Dom.element => unit = "canvas" [@@bs.set];
  /*
   <p>A CanvasRenderingContext2D object representing a two-dimensional rendering context.</p>
   */
  external context : t => unit /* unknown js type: CanvasRenderingContext2D */ = "" [@@bs.get];
  /*
   <p>A CanvasRenderingContext2D object representing a two-dimensional rendering context.</p>
   */
  external setContext : t => unit /* unknown js type: CanvasRenderingContext2D */ => unit =
    "context" [@@bs.set];
  /*
   <p>The width of the canvas buffer in pixels.</p>
   */
  external width : t => int = "" [@@bs.get];
  /*
   <p>The width of the canvas buffer in pixels.</p>
   */
  external setWidth : t => int => unit = "width" [@@bs.set];
  /*
   <p>The height of the canvas buffer in pixels.</p>
   */
  external height : t => int = "" [@@bs.get];
  /*
   <p>The height of the canvas buffer in pixels.</p>
   */
  external setHeight : t => int => unit = "height" [@@bs.set];
};

module TextureGarbageCollector = {
  type t;
};

module TextureManager = {
  type t;
  /*
   <p>A reference to the current renderer</p>
   */
  external renderer : t => unit /* unknown js type: PIXI.WebGLRenderer */ = "" [@@bs.get];
  /*
   <p>A reference to the current renderer</p>
   */
  external setRenderer : t => unit /* unknown js type: PIXI.WebGLRenderer */ => unit =
    "renderer" [@@bs.set];
  /*
   <p>The current WebGL rendering context</p>
   */
  external gl : t => ReasonJs.Gl.glT = "" [@@bs.get];
  /*
   <p>The current WebGL rendering context</p>
   */
  external setGl : t => ReasonJs.Gl.glT => unit = "gl" [@@bs.set];
};

module WebGLRenderer = {
  type t;
  /*
   <p>The type of this renderer as a standardised const</p>
   */
  external type_ : t => int = "type" [@@bs.get];
  /*
   <p>The type of this renderer as a standardised const</p>
   */
  external setType : t => int => unit = "type" [@@bs.set];
  /*
   <p>Manages the masks using the stencil buffer.</p>
   */
  external maskManager : t => unit /* unknown js type: PIXI.MaskManager */ = "" [@@bs.get];
  /*
   <p>Manages the masks using the stencil buffer.</p>
   */
  external setMaskManager : t => unit /* unknown js type: PIXI.MaskManager */ => unit =
    "maskManager" [@@bs.set];
  /*
   <p>Manages the stencil buffer.</p>
   */
  external stencilManager : t => unit /* unknown js type: PIXI.StencilManager */ = "" [@@bs.get];
  /*
   <p>Manages the stencil buffer.</p>
   */
  external setStencilManager : t => unit /* unknown js type: PIXI.StencilManager */ => unit =
    "stencilManager" [@@bs.set];
  /*
   <p>An empty renderer.</p>
   */
  external emptyRenderer : t => unit /* unknown js type: PIXI.ObjectRenderer */ = "" [@@bs.get];
  /*
   <p>An empty renderer.</p>
   */
  external setEmptyRenderer : t => unit /* unknown js type: PIXI.ObjectRenderer */ => unit =
    "emptyRenderer" [@@bs.set];
  /*
   <p>The currently active ObjectRenderer.</p>
   */
  external currentRenderer : t => unit /* unknown js type: PIXI.ObjectRenderer */ = "" [@@bs.get];
  /*
   <p>The currently active ObjectRenderer.</p>
   */
  external setCurrentRenderer : t => unit /* unknown js type: PIXI.ObjectRenderer */ => unit =
    "currentRenderer" [@@bs.set];
  /*
   <p>The currently active ObjectRenderer.</p>
   */
  external state : t => unit /* unknown js type: PIXI.WebGLState */ = "" [@@bs.get];
  /*
   <p>The currently active ObjectRenderer.</p>
   */
  external setState : t => unit /* unknown js type: PIXI.WebGLState */ => unit =
    "state" [@@bs.set];
  /*
   <p>Holds the current state of textures bound to the GPU.</p>
   */
  external boundTextures : t => unit /* unknown js type: Array */ = "" [@@bs.get];
  /*
   <p>Holds the current state of textures bound to the GPU.</p>
   */
  external setBoundTextures : t => unit /* unknown js type: Array */ => unit =
    "boundTextures" [@@bs.set];
  /*
   <p>Holds the current shader</p>
   */
  external _activeShader : t => unit /* unknown js type: PIXI.Shader */ = "" [@@bs.get];
  /*
   <p>Holds the current shader</p>
   */
  external set_activeShader : t => unit /* unknown js type: PIXI.Shader */ => unit =
    "_activeShader" [@@bs.set];
  /*
   <p>Holds the current render target</p>
   */
  external _activeRenderTarget : t => unit /* unknown js type: PIXI.RenderTarget */ =
    "" [@@bs.get];
  /*
   <p>Holds the current render target</p>
   */
  external set_activeRenderTarget : t => unit /* unknown js type: PIXI.RenderTarget */ => unit =
    "_activeRenderTarget" [@@bs.set];
  /*
   <p>Manages the filters.</p>
   */
  external filterManager : t => unit /* unknown js type: PIXI.FilterManager */ = "" [@@bs.get];
  /*
   <p>Manages the filters.</p>
   */
  external setFilterManager : t => unit /* unknown js type: PIXI.FilterManager */ => unit =
    "filterManager" [@@bs.set];
  /*
   <p>Collection of installed plugins. These are included by default in PIXI, but can be excluded
   by creating a custom build. Consult the README for more information about creating custom
   builds and excluding plugins.</p>
   */
  external plugins : t => unit /* unknown js type: object */ = "" [@@bs.get];
  /*
   <p>Collection of methods for extracting data (image, pixels, etc.) from a display object or render texture</p>
   */
  external extract : t => unit /* unknown js type: PIXI.extract.WebGLExtract */ = "" [@@bs.get];
  /*
   <p>Collection of methods for extracting data (image, pixels, etc.) from a display object or render texture</p>
   */
  external setExtract : t => unit /* unknown js type: PIXI.extract.WebGLExtract */ => unit =
    "extract" [@@bs.set];
  /*
   <p>The supplied constructor options.</p>
   */
  external options : t => unit /* unknown js type: Object */ = "" [@@bs.get];
  /*
   <p>Measurements of the screen. (0, 0, screenWidth, screenHeight)</p>
   <p>Its safe to use as filterArea or hitArea for whole stage</p>
   */
  external screen : t => unit /* unknown js type: PIXI.Rectangle */ = "" [@@bs.get];
  /*
   <p>Measurements of the screen. (0, 0, screenWidth, screenHeight)</p>
   <p>Its safe to use as filterArea or hitArea for whole stage</p>
   */
  external setScreen : t => unit /* unknown js type: PIXI.Rectangle */ => unit =
    "screen" [@@bs.set];
  /*
   <p>The canvas element that everything is drawn to</p>
   */
  external view : t => Dom.element = "" [@@bs.get];
  /*
   <p>The canvas element that everything is drawn to</p>
   */
  external setView : t => Dom.element => unit = "view" [@@bs.set];
  /*
   <p>The resolution / device pixel ratio of the renderer</p>
   */
  external resolution : t => int = "" [@@bs.get];
  /*
   <p>The resolution / device pixel ratio of the renderer</p>
   */
  external setResolution : t => int => unit = "resolution" [@@bs.set];
  /*
   <p>Whether the render view is transparent</p>
   */
  external transparent : t => Js.boolean = "" [@@bs.get];
  /*
   <p>Whether the render view is transparent</p>
   */
  external setTransparent : t => Js.boolean => unit = "transparent" [@@bs.set];
  /*
   <p>Whether css dimensions of canvas view should be resized to screen dimensions automatically</p>
   */
  external autoResize : t => Js.boolean = "" [@@bs.get];
  /*
   <p>Whether css dimensions of canvas view should be resized to screen dimensions automatically</p>
   */
  external setAutoResize : t => Js.boolean => unit = "autoResize" [@@bs.set];
  /*
   <p>Tracks the blend modes useful for this renderer.</p>
   */
  external blendModes : t => unit /* unknown js type: object.<string, mixed> */ = "" [@@bs.get];
  /*
   <p>Tracks the blend modes useful for this renderer.</p>
   */
  external setBlendModes : t => unit /* unknown js type: object.<string, mixed> */ => unit =
    "blendModes" [@@bs.set];
  /*
   <p>The value of the preserveDrawingBuffer flag affects whether or not the contents of
   the stencil buffer is retained after rendering.</p>
   */
  external preserveDrawingBuffer : t => Js.boolean = "" [@@bs.get];
  /*
   <p>The value of the preserveDrawingBuffer flag affects whether or not the contents of
   the stencil buffer is retained after rendering.</p>
   */
  external setPreserveDrawingBuffer : t => Js.boolean => unit = "preserveDrawingBuffer" [@@bs.set];
  /*
   <p>This sets if the CanvasRenderer will clear the canvas or not before the new render pass.
   If the scene is NOT transparent Pixi will use a canvas sized fillRect operation every
   frame to set the canvas background color. If the scene is transparent Pixi will use clearRect
   to clear the canvas every frame. Disable this by setting this to false. For example if
   your game has a canvas filling background image you often don't need this set.</p>
   */
  external clearBeforeRender : t => Js.boolean = "" [@@bs.get];
  /*
   <p>This sets if the CanvasRenderer will clear the canvas or not before the new render pass.
   If the scene is NOT transparent Pixi will use a canvas sized fillRect operation every
   frame to set the canvas background color. If the scene is transparent Pixi will use clearRect
   to clear the canvas every frame. Disable this by setting this to false. For example if
   your game has a canvas filling background image you often don't need this set.</p>
   */
  external setClearBeforeRender : t => Js.boolean => unit = "clearBeforeRender" [@@bs.set];
  /*
   <p>If true Pixi will Math.floor() x/y values when rendering, stopping pixel interpolation.
   Handy for crisp pixel art and speed on legacy devices.</p>
   */
  external roundPixels : t => Js.boolean = "" [@@bs.get];
  /*
   <p>If true Pixi will Math.floor() x/y values when rendering, stopping pixel interpolation.
   Handy for crisp pixel art and speed on legacy devices.</p>
   */
  external setRoundPixels : t => Js.boolean => unit = "roundPixels" [@@bs.set];
  /*
   <p>Same as view.width, actual number of pixels in the canvas by horizontal</p>
   */
  external width : t => int = "" [@@bs.get];
  /*
   <p>Same as view.height, actual number of pixels in the canvas by vertical</p>
   */
  external height : t => int = "" [@@bs.get];
  /*
   <p>The background color to fill if not transparent</p>
   */
  external backgroundColor : t => int = "" [@@bs.get];
  /*
   <p>The background color to fill if not transparent</p>
   */
  external setBackgroundColor : t => int => unit = "backgroundColor" [@@bs.set];
};

module WebGLState = {
  type t;
  /*
   <p>The current active state</p>
   */
  external activeState : t => unit /* unknown js type: Uint8Array */ = "" [@@bs.get];
  /*
   <p>The current active state</p>
   */
  external setActiveState : t => unit /* unknown js type: Uint8Array */ => unit =
    "activeState" [@@bs.set];
  /*
   <p>The default state</p>
   */
  external defaultState : t => unit /* unknown js type: Uint8Array */ = "" [@@bs.get];
  /*
   <p>The default state</p>
   */
  external setDefaultState : t => unit /* unknown js type: Uint8Array */ => unit =
    "defaultState" [@@bs.set];
  /*
   <p>The current WebGL rendering context</p>
   */
  external gl : t => ReasonJs.Gl.glT = "" [@@bs.get];
  /*
   <p>The current WebGL rendering context</p>
   */
  external setGl : t => ReasonJs.Gl.glT => unit = "gl" [@@bs.set];
};

module Filter = {
  type t;
  /*
   <p>The vertex shader.</p>
   */
  external vertexSrc : t => string = "" [@@bs.get];
  /*
   <p>The vertex shader.</p>
   */
  external setVertexSrc : t => string => unit = "vertexSrc" [@@bs.set];
  /*
   <p>The fragment shader.</p>
   */
  external fragmentSrc : t => string = "" [@@bs.get];
  /*
   <p>The fragment shader.</p>
   */
  external setFragmentSrc : t => string => unit = "fragmentSrc" [@@bs.set];
  /*
   <p>An object containing the current values of custom uniforms.</p>
   */
  external uniforms : t => unit /* unknown js type: object */ = "" [@@bs.get];
  /*
   <p>An object containing the current values of custom uniforms.</p>
   */
  external setUniforms : t => unit /* unknown js type: object */ => unit = "uniforms" [@@bs.set];
  /*
   <p>The padding of the filter. Some filters require extra space to breath such as a blur.
   Increasing this will add extra width and height to the bounds of the object that the
   filter is applied to.</p>
   */
  external padding : t => int = "" [@@bs.get];
  /*
   <p>The padding of the filter. Some filters require extra space to breath such as a blur.
   Increasing this will add extra width and height to the bounds of the object that the
   filter is applied to.</p>
   */
  external setPadding : t => int => unit = "padding" [@@bs.set];
  /*
   <p>The resolution of the filter. Setting this to be lower will lower the quality but
   increase the performance of the filter.</p>
   */
  external resolution : t => int = "" [@@bs.get];
  /*
   <p>The resolution of the filter. Setting this to be lower will lower the quality but
   increase the performance of the filter.</p>
   */
  external setResolution : t => int => unit = "resolution" [@@bs.set];
  /*
   <p>If enabled is true the filter is applied, if false it will not.</p>
   */
  external enabled : t => Js.boolean = "" [@@bs.get];
  /*
   <p>If enabled is true the filter is applied, if false it will not.</p>
   */
  external setEnabled : t => Js.boolean => unit = "enabled" [@@bs.set];
  /*
   <p>If enabled, pixi will fit the filter area into boundaries for better performance.
   Switch it off if it does not work for specific shader.</p>
   */
  external autoFit : t => Js.boolean = "" [@@bs.get];
  /*
   <p>If enabled, pixi will fit the filter area into boundaries for better performance.
   Switch it off if it does not work for specific shader.</p>
   */
  external setAutoFit : t => Js.boolean => unit = "autoFit" [@@bs.set];
};

module SpriteMaskFilter = {
  type t;
  /*
   <p>The vertex shader.</p>
   */
  external vertexSrc : t => string = "" [@@bs.get];
  /*
   <p>The vertex shader.</p>
   */
  external setVertexSrc : t => string => unit = "vertexSrc" [@@bs.set];
  /*
   <p>The fragment shader.</p>
   */
  external fragmentSrc : t => string = "" [@@bs.get];
  /*
   <p>The fragment shader.</p>
   */
  external setFragmentSrc : t => string => unit = "fragmentSrc" [@@bs.set];
  /*
   <p>An object containing the current values of custom uniforms.</p>
   */
  external uniforms : t => unit /* unknown js type: object */ = "" [@@bs.get];
  /*
   <p>An object containing the current values of custom uniforms.</p>
   */
  external setUniforms : t => unit /* unknown js type: object */ => unit = "uniforms" [@@bs.set];
  /*
   <p>The padding of the filter. Some filters require extra space to breath such as a blur.
   Increasing this will add extra width and height to the bounds of the object that the
   filter is applied to.</p>
   */
  external padding : t => int = "" [@@bs.get];
  /*
   <p>The padding of the filter. Some filters require extra space to breath such as a blur.
   Increasing this will add extra width and height to the bounds of the object that the
   filter is applied to.</p>
   */
  external setPadding : t => int => unit = "padding" [@@bs.set];
  /*
   <p>The resolution of the filter. Setting this to be lower will lower the quality but
   increase the performance of the filter.</p>
   */
  external resolution : t => int = "" [@@bs.get];
  /*
   <p>The resolution of the filter. Setting this to be lower will lower the quality but
   increase the performance of the filter.</p>
   */
  external setResolution : t => int => unit = "resolution" [@@bs.set];
  /*
   <p>If enabled is true the filter is applied, if false it will not.</p>
   */
  external enabled : t => Js.boolean = "" [@@bs.get];
  /*
   <p>If enabled is true the filter is applied, if false it will not.</p>
   */
  external setEnabled : t => Js.boolean => unit = "enabled" [@@bs.set];
  /*
   <p>If enabled, pixi will fit the filter area into boundaries for better performance.
   Switch it off if it does not work for specific shader.</p>
   */
  external autoFit : t => Js.boolean = "" [@@bs.get];
  /*
   <p>If enabled, pixi will fit the filter area into boundaries for better performance.
   Switch it off if it does not work for specific shader.</p>
   */
  external setAutoFit : t => Js.boolean => unit = "autoFit" [@@bs.set];
};

module BlendModeManager = {
  type t;
  external currentBlendMode : t => int = "" [@@bs.get];
  external setCurrentBlendMode : t => int => unit = "currentBlendMode" [@@bs.set];
  /*
   <p>The renderer this manager works for.</p>
   */
  external renderer : t => unit /* unknown js type: PIXI.WebGLRenderer */ = "" [@@bs.get];
  /*
   <p>The renderer this manager works for.</p>
   */
  external setRenderer : t => unit /* unknown js type: PIXI.WebGLRenderer */ => unit =
    "renderer" [@@bs.set];
};

module FilterManager = {
  type t;
  /*
   <p>The renderer this manager works for.</p>
   */
  external renderer : t => unit /* unknown js type: PIXI.WebGLRenderer */ = "" [@@bs.get];
  /*
   <p>The renderer this manager works for.</p>
   */
  external setRenderer : t => unit /* unknown js type: PIXI.WebGLRenderer */ => unit =
    "renderer" [@@bs.set];
};

module MaskManager = {
  type t;
  /*
   <p>The renderer this manager works for.</p>
   */
  external renderer : t => unit /* unknown js type: PIXI.WebGLRenderer */ = "" [@@bs.get];
  /*
   <p>The renderer this manager works for.</p>
   */
  external setRenderer : t => unit /* unknown js type: PIXI.WebGLRenderer */ => unit =
    "renderer" [@@bs.set];
};

module StencilManager = {
  type t;
  /*
   <p>The renderer this manager works for.</p>
   */
  external renderer : t => unit /* unknown js type: PIXI.WebGLRenderer */ = "" [@@bs.get];
  /*
   <p>The renderer this manager works for.</p>
   */
  external setRenderer : t => unit /* unknown js type: PIXI.WebGLRenderer */ => unit =
    "renderer" [@@bs.set];
};

module WebGLManager = {
  type t;
  /*
   <p>The renderer this manager works for.</p>
   */
  external renderer : t => unit /* unknown js type: PIXI.WebGLRenderer */ = "" [@@bs.get];
  /*
   <p>The renderer this manager works for.</p>
   */
  external setRenderer : t => unit /* unknown js type: PIXI.WebGLRenderer */ => unit =
    "renderer" [@@bs.set];
};

module ObjectRenderer = {
  type t;
  /*
   <p>The renderer this manager works for.</p>
   */
  external renderer : t => unit /* unknown js type: PIXI.WebGLRenderer */ = "" [@@bs.get];
  /*
   <p>The renderer this manager works for.</p>
   */
  external setRenderer : t => unit /* unknown js type: PIXI.WebGLRenderer */ => unit =
    "renderer" [@@bs.set];
};

module Quad = {
  type t;
  /*
   <p>the current WebGL drawing context</p>
   */
  external gl : t => ReasonJs.Gl.glT = "" [@@bs.get];
  /*
   <p>the current WebGL drawing context</p>
   */
  external setGl : t => ReasonJs.Gl.glT => unit = "gl" [@@bs.set];
  /*
   <p>An array of vertices</p>
   */
  external vertices : t => unit /* unknown js type: Float32Array */ = "" [@@bs.get];
  /*
   <p>An array of vertices</p>
   */
  external setVertices : t => unit /* unknown js type: Float32Array */ => unit =
    "vertices" [@@bs.set];
  /*
   <p>The Uvs of the quad</p>
   */
  external uvs : t => unit /* unknown js type: Float32Array */ = "" [@@bs.get];
  /*
   <p>The Uvs of the quad</p>
   */
  external setUvs : t => unit /* unknown js type: Float32Array */ => unit = "uvs" [@@bs.set];
  /*
   <p>An array containing the indices of the vertices</p>
   */
  external indices : t => unit /* unknown js type: Uint16Array */ = "" [@@bs.get];
  /*
   <p>An array containing the indices of the vertices</p>
   */
  external setIndices : t => unit /* unknown js type: Uint16Array */ => unit =
    "indices" [@@bs.set];
  /*
   <p>The vertex buffer</p>
   */
  external vertexBuffer : t => unit /* unknown js type: glCore.GLBuffer */ = "" [@@bs.get];
  /*
   <p>The vertex buffer</p>
   */
  external setVertexBuffer : t => unit /* unknown js type: glCore.GLBuffer */ => unit =
    "vertexBuffer" [@@bs.set];
  /*
   <p>The index buffer</p>
   */
  external indexBuffer : t => unit /* unknown js type: glCore.GLBuffer */ = "" [@@bs.get];
  /*
   <p>The index buffer</p>
   */
  external setIndexBuffer : t => unit /* unknown js type: glCore.GLBuffer */ => unit =
    "indexBuffer" [@@bs.set];
  /*
   <p>The vertex array object</p>
   */
  external vao : t => unit /* unknown js type: glCore.VertexArrayObject */ = "" [@@bs.get];
  /*
   <p>The vertex array object</p>
   */
  external setVao : t => unit /* unknown js type: glCore.VertexArrayObject */ => unit =
    "vao" [@@bs.set];
};

module RenderTarget = {
  type t;
  /*
   <p>The current WebGL drawing context.</p>
   */
  external gl : t => ReasonJs.Gl.glT = "" [@@bs.get];
  /*
   <p>The current WebGL drawing context.</p>
   */
  external setGl : t => ReasonJs.Gl.glT => unit = "gl" [@@bs.set];
  /*
   <p>A frame buffer</p>
   */
  external frameBuffer : t => unit /* unknown js type: PIXI.glCore.GLFramebuffer */ =
    "" [@@bs.get];
  /*
   <p>A frame buffer</p>
   */
  external setFrameBuffer : t => unit /* unknown js type: PIXI.glCore.GLFramebuffer */ => unit =
    "frameBuffer" [@@bs.set];
  /*
   <p>The texture</p>
   */
  external texture : t => unit /* unknown js type: PIXI.glCore.GLTexture */ = "" [@@bs.get];
  /*
   <p>The texture</p>
   */
  external setTexture : t => unit /* unknown js type: PIXI.glCore.GLTexture */ => unit =
    "texture" [@@bs.set];
  /*
   <p>The background colour of this render target, as an array of [r,g,b,a] values</p>
   */
  external clearColor : t => array int = "" [@@bs.get];
  /*
   <p>The background colour of this render target, as an array of [r,g,b,a] values</p>
   */
  external setClearColor : t => array int => unit = "clearColor" [@@bs.set];
  /*
   <p>The size of the object as a rectangle</p>
   */
  external size : t => unit /* unknown js type: PIXI.Rectangle */ = "" [@@bs.get];
  /*
   <p>The size of the object as a rectangle</p>
   */
  external setSize : t => unit /* unknown js type: PIXI.Rectangle */ => unit = "size" [@@bs.set];
  /*
   <p>The current resolution / device pixel ratio</p>
   */
  external resolution : t => int = "" [@@bs.get];
  /*
   <p>The current resolution / device pixel ratio</p>
   */
  external setResolution : t => int => unit = "resolution" [@@bs.set];
  /*
   <p>The projection matrix</p>
   */
  external projectionMatrix : t => unit /* unknown js type: PIXI.Matrix */ = "" [@@bs.get];
  /*
   <p>The projection matrix</p>
   */
  external setProjectionMatrix : t => unit /* unknown js type: PIXI.Matrix */ => unit =
    "projectionMatrix" [@@bs.set];
  /*
   <p>The object's transform</p>
   */
  external transform : t => unit /* unknown js type: PIXI.Matrix */ = "" [@@bs.get];
  /*
   <p>The object's transform</p>
   */
  external setTransform : t => unit /* unknown js type: PIXI.Matrix */ => unit =
    "transform" [@@bs.set];
  /*
   <p>The frame.</p>
   */
  external frame : t => unit /* unknown js type: PIXI.Rectangle */ = "" [@@bs.get];
  /*
   <p>The frame.</p>
   */
  external setFrame : t => unit /* unknown js type: PIXI.Rectangle */ => unit = "frame" [@@bs.set];
  /*
   <p>The stencil buffer stores masking data for the render target</p>
   */
  external defaultFrame : t => unit /* unknown js type: glCore.GLBuffer */ = "" [@@bs.get];
  /*
   <p>The stencil buffer stores masking data for the render target</p>
   */
  external setDefaultFrame : t => unit /* unknown js type: glCore.GLBuffer */ => unit =
    "defaultFrame" [@@bs.set];
  /*
   <p>The stencil buffer stores masking data for the render target</p>
   */
  external stencilBuffer : t => unit /* unknown js type: glCore.GLBuffer */ = "" [@@bs.get];
  /*
   <p>The stencil buffer stores masking data for the render target</p>
   */
  external setStencilBuffer : t => unit /* unknown js type: glCore.GLBuffer */ => unit =
    "stencilBuffer" [@@bs.set];
  /*
   <p>The data structure for the stencil masks</p>
   */
  external stencilMaskStack : t => array unit /* unknown js type: PIXI.Graphics */ = "" [@@bs.get];
  /*
   <p>The data structure for the stencil masks</p>
   */
  external setStencilMaskStack : t => array unit /* unknown js type: PIXI.Graphics */ => unit =
    "stencilMaskStack" [@@bs.set];
  /*
   <p>Stores filter data for the render target</p>
   */
  external filterData : t => array unit /* unknown js type: object */ = "" [@@bs.get];
  /*
   <p>Stores filter data for the render target</p>
   */
  external setFilterData : t => array unit /* unknown js type: object */ => unit =
    "filterData" [@@bs.set];
  /*
   <p>The scale mode.</p>
   */
  external scaleMode : t => int = "" [@@bs.get];
  /*
   <p>The scale mode.</p>
   */
  external setScaleMode : t => int => unit = "scaleMode" [@@bs.set];
  /*
   <p>Whether this object is the root element or not</p>
   */
  external root : t => Js.boolean = "" [@@bs.get];
  /*
   <p>Whether this object is the root element or not</p>
   */
  external setRoot : t => Js.boolean => unit = "root" [@@bs.set];
};

module Sprite = {
  type t;
  /*
   <p>The blend mode to be applied to the sprite. Apply a value of <code>PIXI.BLEND_MODES.NORMAL</code> to reset the blend mode.</p>
   */
  external blendMode : t => int = "" [@@bs.get];
  /*
   <p>The blend mode to be applied to the sprite. Apply a value of <code>PIXI.BLEND_MODES.NORMAL</code> to reset the blend mode.</p>
   */
  external setBlendMode : t => int => unit = "blendMode" [@@bs.set];
  /*
   <p>The shader that will be used to render the sprite. Set to null to remove a current shader.</p>
   */
  external shader : t => unit /* unknown js type: PIXI.Filter|PIXI.Shader */ = "" [@@bs.get];
  /*
   <p>The shader that will be used to render the sprite. Set to null to remove a current shader.</p>
   */
  external setShader : t => unit /* unknown js type: PIXI.Filter|PIXI.Shader */ => unit =
    "shader" [@@bs.set];
  /*
   <p>Plugin that is responsible for rendering this element.
   Allows to customize the rendering process without overriding '_renderWebGL' &amp; '_renderCanvas' methods.</p>
   */
  external pluginName : t => string = "" [@@bs.get];
  /*
   <p>Plugin that is responsible for rendering this element.
   Allows to customize the rendering process without overriding '_renderWebGL' &amp; '_renderCanvas' methods.</p>
   */
  external setPluginName : t => string => unit = "pluginName" [@@bs.set];
  /*
   <p>The width of the sprite, setting this will actually modify the scale to achieve the value set</p>
   */
  external width : t => int = "" [@@bs.get];
  /*
   <p>The width of the sprite, setting this will actually modify the scale to achieve the value set</p>
   */
  external setWidth : t => int => unit = "width" [@@bs.set];
  /*
   <p>The height of the sprite, setting this will actually modify the scale to achieve the value set</p>
   */
  external height : t => int = "" [@@bs.get];
  /*
   <p>The height of the sprite, setting this will actually modify the scale to achieve the value set</p>
   */
  external setHeight : t => int => unit = "height" [@@bs.set];
  /*
   <p>The anchor sets the origin point of the texture.
   The default is 0,0 this means the texture's origin is the top left
   Setting the anchor to 0.5,0.5 means the texture's origin is centered
   Setting the anchor to 1,1 would mean the texture's origin point will be the bottom right corner</p>
   */
  external anchor : t => unit /* unknown js type: PIXI.ObservablePoint */ = "" [@@bs.get];
  /*
   <p>The anchor sets the origin point of the texture.
   The default is 0,0 this means the texture's origin is the top left
   Setting the anchor to 0.5,0.5 means the texture's origin is centered
   Setting the anchor to 1,1 would mean the texture's origin point will be the bottom right corner</p>
   */
  external setAnchor : t => unit /* unknown js type: PIXI.ObservablePoint */ => unit =
    "anchor" [@@bs.set];
  /*
   <p>The tint applied to the sprite. This is a hex value.
   A value of 0xFFFFFF will remove any tint effect.</p>
   */
  external tint : t => int = "" [@@bs.get];
  /*
   <p>The tint applied to the sprite. This is a hex value.
   A value of 0xFFFFFF will remove any tint effect.</p>
   */
  external setTint : t => int => unit = "tint" [@@bs.set];
  /*
   <p>The texture that the sprite is using</p>
   */
  external texture : t => unit /* unknown js type: PIXI.Texture */ = "" [@@bs.get];
  /*
   <p>The texture that the sprite is using</p>
   */
  external setTexture : t => unit /* unknown js type: PIXI.Texture */ => unit =
    "texture" [@@bs.set];
  /*
   <p>The array of children of this container.</p>
   */
  external children : t => array unit /* unknown js type: PIXI.DisplayObject */ = "" [@@bs.get];
  /*
   <p>Determines if the children to the displayObject can be clicked/touched
   Setting this to false allows pixi to bypass a recursive <code>hitTest</code> function</p>
   */
  external interactiveChildren : t => Js.boolean = "" [@@bs.get];
  /*
   <p>Determines if the children to the displayObject can be clicked/touched
   Setting this to false allows pixi to bypass a recursive <code>hitTest</code> function</p>
   */
  external setInteractiveChildren : t => Js.boolean => unit = "interactiveChildren" [@@bs.set];
  /*
   <p>World transform and local transform of this object.
   This will become read-only later, please do not assign anything there unless you know what are you doing</p>
   */
  external transform : t => unit /* unknown js type: PIXI.TransformBase */ = "" [@@bs.get];
  /*
   <p>World transform and local transform of this object.
   This will become read-only later, please do not assign anything there unless you know what are you doing</p>
   */
  external setTransform : t => unit /* unknown js type: PIXI.TransformBase */ => unit =
    "transform" [@@bs.set];
  /*
   <p>The opacity of the object.</p>
   */
  external alpha : t => int = "" [@@bs.get];
  /*
   <p>The opacity of the object.</p>
   */
  external setAlpha : t => int => unit = "alpha" [@@bs.set];
  /*
   <p>The visibility of the object. If false the object will not be drawn, and
   the updateTransform function will not be called.</p>
   <p>Only affects recursive calls from parent. You can ask for bounds or call updateTransform manually</p>
   */
  external visible : t => Js.boolean = "" [@@bs.get];
  /*
   <p>The visibility of the object. If false the object will not be drawn, and
   the updateTransform function will not be called.</p>
   <p>Only affects recursive calls from parent. You can ask for bounds or call updateTransform manually</p>
   */
  external setVisible : t => Js.boolean => unit = "visible" [@@bs.set];
  /*
   <p>Can this object be rendered, if false the object will not be drawn but the updateTransform
   methods will still be called.</p>
   <p>Only affects recursive calls from parent. You can ask for bounds manually</p>
   */
  external renderable : t => Js.boolean = "" [@@bs.get];
  /*
   <p>Can this object be rendered, if false the object will not be drawn but the updateTransform
   methods will still be called.</p>
   <p>Only affects recursive calls from parent. You can ask for bounds manually</p>
   */
  external setRenderable : t => Js.boolean => unit = "renderable" [@@bs.set];
  /*
   <p>The display object container that contains this display object.</p>
   */
  external parent : t => unit /* unknown js type: PIXI.Container */ = "" [@@bs.get];
  /*
   <p>The multiplied alpha of the displayObject</p>
   */
  external worldAlpha : t => int = "" [@@bs.get];
  /*
   <p>The area the filter is applied to. This is used as more of an optimisation
   rather than figuring out the dimensions of the displayObject each frame you can set this rectangle</p>
   <p>Also works as an interaction mask</p>
   */
  external filterArea : t => unit /* unknown js type: PIXI.Rectangle */ = "" [@@bs.get];
  /*
   <p>The area the filter is applied to. This is used as more of an optimisation
   rather than figuring out the dimensions of the displayObject each frame you can set this rectangle</p>
   <p>Also works as an interaction mask</p>
   */
  external setFilterArea : t => unit /* unknown js type: PIXI.Rectangle */ => unit =
    "filterArea" [@@bs.set];
  /*
   <p>The position of the displayObject on the x axis relative to the local coordinates of the parent.
   An alias to position.x</p>
   */
  external x : t => int = "" [@@bs.get];
  /*
   <p>The position of the displayObject on the x axis relative to the local coordinates of the parent.
   An alias to position.x</p>
   */
  external setX : t => int => unit = "x" [@@bs.set];
  /*
   <p>The position of the displayObject on the y axis relative to the local coordinates of the parent.
   An alias to position.y</p>
   */
  external y : t => int = "" [@@bs.get];
  /*
   <p>The position of the displayObject on the y axis relative to the local coordinates of the parent.
   An alias to position.y</p>
   */
  external setY : t => int => unit = "y" [@@bs.set];
  /*
   <p>Current transform of the object based on world (parent) factors</p>
   */
  external worldTransform : t => unit /* unknown js type: PIXI.Matrix */ = "" [@@bs.get];
  /*
   <p>Current transform of the object based on local factors: position, scale, other stuff</p>
   */
  external localTransform : t => unit /* unknown js type: PIXI.Matrix */ = "" [@@bs.get];
  /*
   <p>The coordinate of the object relative to the local coordinates of the parent.
   Assignment by value since pixi-v4.</p>
   */
  external position : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
    "" [@@bs.get];
  /*
   <p>The coordinate of the object relative to the local coordinates of the parent.
   Assignment by value since pixi-v4.</p>
   */
  external setPosition : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
    "position" [@@bs.set];
  /*
   <p>The scale factor of the object.
   Assignment by value since pixi-v4.</p>
   */
  external scale : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
    "" [@@bs.get];
  /*
   <p>The scale factor of the object.
   Assignment by value since pixi-v4.</p>
   */
  external setScale : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
    "scale" [@@bs.set];
  /*
   <p>The pivot point of the displayObject that it rotates around
   Assignment by value since pixi-v4.</p>
   */
  external pivot : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
    "" [@@bs.get];
  /*
   <p>The pivot point of the displayObject that it rotates around
   Assignment by value since pixi-v4.</p>
   */
  external setPivot : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
    "pivot" [@@bs.set];
  /*
   <p>The skew factor for the object in radians.
   Assignment by value since pixi-v4.</p>
   */
  external skew : t => unit /* unknown js type: PIXI.ObservablePoint */ = "" [@@bs.get];
  /*
   <p>The skew factor for the object in radians.
   Assignment by value since pixi-v4.</p>
   */
  external setSkew : t => unit /* unknown js type: PIXI.ObservablePoint */ => unit =
    "skew" [@@bs.set];
  /*
   <p>The rotation of the object in radians.</p>
   */
  external rotation : t => int = "" [@@bs.get];
  /*
   <p>The rotation of the object in radians.</p>
   */
  external setRotation : t => int => unit = "rotation" [@@bs.set];
  /*
   <p>Indicates if the object is globally visible.</p>
   */
  external worldVisible : t => Js.boolean = "" [@@bs.get];
  /*
   <p>Sets a mask for the displayObject. A mask is an object that limits the visibility of an
   object to the shape of the mask applied to it. In PIXI a regular mask must be a
   PIXI.Graphics or a PIXI.Sprite object. This allows for much faster masking in canvas as it
   utilises shape clipping. To remove a mask, set this property to null.</p>
   */
  external mask : t => unit /* unknown js type: PIXI.Graphics|PIXI.Sprite */ = "" [@@bs.get];
  /*
   <p>Sets a mask for the displayObject. A mask is an object that limits the visibility of an
   object to the shape of the mask applied to it. In PIXI a regular mask must be a
   PIXI.Graphics or a PIXI.Sprite object. This allows for much faster masking in canvas as it
   utilises shape clipping. To remove a mask, set this property to null.</p>
   */
  external setMask : t => unit /* unknown js type: PIXI.Graphics|PIXI.Sprite */ => unit =
    "mask" [@@bs.set];
  /*
   <p>Sets the filters for the displayObject.</p>
   <ul>
   <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
   To remove filters simply set this property to 'null'</li>
   </ul>
   */
  external filters : t => array unit /* unknown js type: PIXI.Filter */ = "" [@@bs.get];
  /*
   <p>Sets the filters for the displayObject.</p>
   <ul>
   <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
   To remove filters simply set this property to 'null'</li>
   </ul>
   */
  external setFilters : t => array unit /* unknown js type: PIXI.Filter */ => unit =
    "filters" [@@bs.set];
  /*
   <p>Set this to true if you want this display object to be cached as a bitmap.
   This basically takes a snap shot of the display object as it is at that moment. It can
   provide a performance benefit for complex static displayObjects.
   To remove simply set this property to 'false'</p>
   <p>IMPORTANT GOTCHA - make sure that all your textures are preloaded BEFORE setting this property to true
   as it will take a snapshot of what is currently there. If the textures have not loaded then they will not appear.</p>
   */
  external cacheAsBitmap : t => Js.boolean = "" [@@bs.get];
  /*
   <p>Set this to true if you want this display object to be cached as a bitmap.
   This basically takes a snap shot of the display object as it is at that moment. It can
   provide a performance benefit for complex static displayObjects.
   To remove simply set this property to 'false'</p>
   <p>IMPORTANT GOTCHA - make sure that all your textures are preloaded BEFORE setting this property to true
   as it will take a snapshot of what is currently there. If the textures have not loaded then they will not appear.</p>
   */
  external setCacheAsBitmap : t => Js.boolean => unit = "cacheAsBitmap" [@@bs.set];
  /*
   <p>Enable interaction events for the DisplayObject. Touch, pointer and mouse
   events will not be emitted unless <code>interactive</code> is set to <code>true</code>.</p>
   */
  external interactive : t => Js.boolean = "" [@@bs.get];
  /*
   <p>Enable interaction events for the DisplayObject. Touch, pointer and mouse
   events will not be emitted unless <code>interactive</code> is set to <code>true</code>.</p>
   */
  external setInteractive : t => Js.boolean => unit = "interactive" [@@bs.set];
  /*
   <p>Interaction shape. Children will be hit first, then this shape will be checked.
   Setting this will cause this shape to be checked in hit tests rather than the displayObject's bounds.</p>
   */
  external hitArea :
    t => unit /* unknown js type: PIXI.Rectangle|PIXI.Circle|PIXI.Ellipse|PIXI.Polygon|PIXI.RoundedRectangle */ =
    "" [@@bs.get];
  /*
   <p>Interaction shape. Children will be hit first, then this shape will be checked.
   Setting this will cause this shape to be checked in hit tests rather than the displayObject's bounds.</p>
   */
  external setHitArea :
    t =>
    unit /* unknown js type: PIXI.Rectangle|PIXI.Circle|PIXI.Ellipse|PIXI.Polygon|PIXI.RoundedRectangle */ =>
    unit =
    "hitArea" [@@bs.set];
  /*
   <p>If enabled, the mouse cursor use the pointer behavior when hovered over the displayObject if it is interactive
   Setting this changes the 'cursor' property to <code>'pointer'</code>.</p>
   */
  external buttonMode : t => Js.boolean = "" [@@bs.get];
  /*
   <p>If enabled, the mouse cursor use the pointer behavior when hovered over the displayObject if it is interactive
   Setting this changes the 'cursor' property to <code>'pointer'</code>.</p>
   */
  external setButtonMode : t => Js.boolean => unit = "buttonMode" [@@bs.set];
  /*
   <p>This defines what cursor mode is used when the mouse cursor
   is hovered over the displayObject.</p>
   */
  external cursor : t => string = "" [@@bs.get];
  /*
   <p>This defines what cursor mode is used when the mouse cursor
   is hovered over the displayObject.</p>
   */
  external setCursor : t => string => unit = "cursor" [@@bs.set];
};

module CanvasSpriteRenderer = {
  type t;
};

module CanvasTinter = {
  /*
   <p>Utility methods for Sprite/Texture tinting.</p>
   */
  type t;
};

module Buffer = {
  type t;
  /*
   <p>View on the vertices as a Float32Array for positions</p>
   */
  external float32View : t => unit /* unknown js type: Float32Array */ = "" [@@bs.get];
  /*
   <p>View on the vertices as a Float32Array for positions</p>
   */
  external setFloat32View : t => unit /* unknown js type: Float32Array */ => unit =
    "float32View" [@@bs.set];
  /*
   <p>View on the vertices as a Uint32Array for uvs</p>
   */
  external uint32View : t => unit /* unknown js type: Float32Array */ = "" [@@bs.get];
  /*
   <p>View on the vertices as a Uint32Array for uvs</p>
   */
  external setUint32View : t => unit /* unknown js type: Float32Array */ => unit =
    "uint32View" [@@bs.set];
};

module SpriteRenderer = {
  type t;
  /*
   <p>Number of values sent in the vertex buffer.
   aVertexPosition(2), aTextureCoord(1), aColor(1), aTextureId(1) = 5</p>
   */
  external vertSize : t => int = "" [@@bs.get];
  /*
   <p>Number of values sent in the vertex buffer.
   aVertexPosition(2), aTextureCoord(1), aColor(1), aTextureId(1) = 5</p>
   */
  external setVertSize : t => int => unit = "vertSize" [@@bs.set];
  /*
   <p>The size of the vertex information in bytes.</p>
   */
  external vertByteSize : t => int = "" [@@bs.get];
  /*
   <p>The size of the vertex information in bytes.</p>
   */
  external setVertByteSize : t => int => unit = "vertByteSize" [@@bs.set];
  /*
   <p>The number of images in the SpriteRenderer before it flushes.</p>
   */
  external size : t => int = "" [@@bs.get];
  /*
   <p>The number of images in the SpriteRenderer before it flushes.</p>
   */
  external setSize : t => int => unit = "size" [@@bs.set];
  /*
   <p>Holds the indices of the geometry (quads) to draw</p>
   */
  external indices : t => unit /* unknown js type: Uint16Array */ = "" [@@bs.get];
  /*
   <p>Holds the indices of the geometry (quads) to draw</p>
   */
  external setIndices : t => unit /* unknown js type: Uint16Array */ => unit =
    "indices" [@@bs.set];
  /*
   <p>The default shaders that is used if a sprite doesn't have a more specific one.
   there is a shader for each number of textures that can be rendererd.
   These shaders will also be generated on the fly as required.</p>
   */
  external shader : t => array unit /* unknown js type: PIXI.Shader */ = "" [@@bs.get];
  /*
   <p>The default shaders that is used if a sprite doesn't have a more specific one.
   there is a shader for each number of textures that can be rendererd.
   These shaders will also be generated on the fly as required.</p>
   */
  external setShader : t => array unit /* unknown js type: PIXI.Shader */ => unit =
    "shader" [@@bs.set];
  /*
   <p>The renderer this manager works for.</p>
   */
  external renderer : t => unit /* unknown js type: PIXI.WebGLRenderer */ = "" [@@bs.get];
  /*
   <p>The renderer this manager works for.</p>
   */
  external setRenderer : t => unit /* unknown js type: PIXI.WebGLRenderer */ => unit =
    "renderer" [@@bs.set];
};

module Text = {
  type t;
  /*
   <p>The canvas element that everything is drawn to</p>
   */
  external canvas : t => Dom.element = "" [@@bs.get];
  /*
   <p>The canvas element that everything is drawn to</p>
   */
  external setCanvas : t => Dom.element => unit = "canvas" [@@bs.set];
  /*
   <p>The canvas 2d context that everything is drawn with</p>
   */
  external context : t => unit /* unknown js type: CanvasRenderingContext2D */ = "" [@@bs.get];
  /*
   <p>The canvas 2d context that everything is drawn with</p>
   */
  external setContext : t => unit /* unknown js type: CanvasRenderingContext2D */ => unit =
    "context" [@@bs.set];
  /*
   <p>The resolution / device pixel ratio of the canvas. This is set automatically by the renderer.</p>
   */
  external resolution : t => int = "" [@@bs.get];
  /*
   <p>The resolution / device pixel ratio of the canvas. This is set automatically by the renderer.</p>
   */
  external setResolution : t => int => unit = "resolution" [@@bs.set];
  /*
   <p>The width of the Text, setting this will actually modify the scale to achieve the value set</p>
   */
  external width : t => int = "" [@@bs.get];
  /*
   <p>The width of the Text, setting this will actually modify the scale to achieve the value set</p>
   */
  external setWidth : t => int => unit = "width" [@@bs.set];
  /*
   <p>The height of the Text, setting this will actually modify the scale to achieve the value set</p>
   */
  external height : t => int = "" [@@bs.get];
  /*
   <p>The height of the Text, setting this will actually modify the scale to achieve the value set</p>
   */
  external setHeight : t => int => unit = "height" [@@bs.set];
  /*
   <p>Set the style of the text. Set up an event listener to listen for changes on the style
   object and mark the text as dirty.</p>
   */
  external style : t => unit /* unknown js type: object|PIXI.TextStyle */ = "" [@@bs.get];
  /*
   <p>Set the style of the text. Set up an event listener to listen for changes on the style
   object and mark the text as dirty.</p>
   */
  external setStyle : t => unit /* unknown js type: object|PIXI.TextStyle */ => unit =
    "style" [@@bs.set];
  /*
   <p>Set the copy for the text object. To split a line you can use '\n'.</p>
   */
  external text : t => string = "" [@@bs.get];
  /*
   <p>Set the copy for the text object. To split a line you can use '\n'.</p>
   */
  external setText : t => string => unit = "text" [@@bs.set];
  /*
   <p>The blend mode to be applied to the sprite. Apply a value of <code>PIXI.BLEND_MODES.NORMAL</code> to reset the blend mode.</p>
   */
  external blendMode : t => int = "" [@@bs.get];
  /*
   <p>The blend mode to be applied to the sprite. Apply a value of <code>PIXI.BLEND_MODES.NORMAL</code> to reset the blend mode.</p>
   */
  external setBlendMode : t => int => unit = "blendMode" [@@bs.set];
  /*
   <p>The shader that will be used to render the sprite. Set to null to remove a current shader.</p>
   */
  external shader : t => unit /* unknown js type: PIXI.Filter|PIXI.Shader */ = "" [@@bs.get];
  /*
   <p>The shader that will be used to render the sprite. Set to null to remove a current shader.</p>
   */
  external setShader : t => unit /* unknown js type: PIXI.Filter|PIXI.Shader */ => unit =
    "shader" [@@bs.set];
  /*
   <p>Plugin that is responsible for rendering this element.
   Allows to customize the rendering process without overriding '_renderWebGL' &amp; '_renderCanvas' methods.</p>
   */
  external pluginName : t => string = "" [@@bs.get];
  /*
   <p>Plugin that is responsible for rendering this element.
   Allows to customize the rendering process without overriding '_renderWebGL' &amp; '_renderCanvas' methods.</p>
   */
  external setPluginName : t => string => unit = "pluginName" [@@bs.set];
  /*
   <p>The anchor sets the origin point of the texture.
   The default is 0,0 this means the texture's origin is the top left
   Setting the anchor to 0.5,0.5 means the texture's origin is centered
   Setting the anchor to 1,1 would mean the texture's origin point will be the bottom right corner</p>
   */
  external anchor : t => unit /* unknown js type: PIXI.ObservablePoint */ = "" [@@bs.get];
  /*
   <p>The anchor sets the origin point of the texture.
   The default is 0,0 this means the texture's origin is the top left
   Setting the anchor to 0.5,0.5 means the texture's origin is centered
   Setting the anchor to 1,1 would mean the texture's origin point will be the bottom right corner</p>
   */
  external setAnchor : t => unit /* unknown js type: PIXI.ObservablePoint */ => unit =
    "anchor" [@@bs.set];
  /*
   <p>The tint applied to the sprite. This is a hex value.
   A value of 0xFFFFFF will remove any tint effect.</p>
   */
  external tint : t => int = "" [@@bs.get];
  /*
   <p>The tint applied to the sprite. This is a hex value.
   A value of 0xFFFFFF will remove any tint effect.</p>
   */
  external setTint : t => int => unit = "tint" [@@bs.set];
  /*
   <p>The texture that the sprite is using</p>
   */
  external texture : t => unit /* unknown js type: PIXI.Texture */ = "" [@@bs.get];
  /*
   <p>The texture that the sprite is using</p>
   */
  external setTexture : t => unit /* unknown js type: PIXI.Texture */ => unit =
    "texture" [@@bs.set];
  /*
   <p>The array of children of this container.</p>
   */
  external children : t => array unit /* unknown js type: PIXI.DisplayObject */ = "" [@@bs.get];
  /*
   <p>Determines if the children to the displayObject can be clicked/touched
   Setting this to false allows pixi to bypass a recursive <code>hitTest</code> function</p>
   */
  external interactiveChildren : t => Js.boolean = "" [@@bs.get];
  /*
   <p>Determines if the children to the displayObject can be clicked/touched
   Setting this to false allows pixi to bypass a recursive <code>hitTest</code> function</p>
   */
  external setInteractiveChildren : t => Js.boolean => unit = "interactiveChildren" [@@bs.set];
  /*
   <p>World transform and local transform of this object.
   This will become read-only later, please do not assign anything there unless you know what are you doing</p>
   */
  external transform : t => unit /* unknown js type: PIXI.TransformBase */ = "" [@@bs.get];
  /*
   <p>World transform and local transform of this object.
   This will become read-only later, please do not assign anything there unless you know what are you doing</p>
   */
  external setTransform : t => unit /* unknown js type: PIXI.TransformBase */ => unit =
    "transform" [@@bs.set];
  /*
   <p>The opacity of the object.</p>
   */
  external alpha : t => int = "" [@@bs.get];
  /*
   <p>The opacity of the object.</p>
   */
  external setAlpha : t => int => unit = "alpha" [@@bs.set];
  /*
   <p>The visibility of the object. If false the object will not be drawn, and
   the updateTransform function will not be called.</p>
   <p>Only affects recursive calls from parent. You can ask for bounds or call updateTransform manually</p>
   */
  external visible : t => Js.boolean = "" [@@bs.get];
  /*
   <p>The visibility of the object. If false the object will not be drawn, and
   the updateTransform function will not be called.</p>
   <p>Only affects recursive calls from parent. You can ask for bounds or call updateTransform manually</p>
   */
  external setVisible : t => Js.boolean => unit = "visible" [@@bs.set];
  /*
   <p>Can this object be rendered, if false the object will not be drawn but the updateTransform
   methods will still be called.</p>
   <p>Only affects recursive calls from parent. You can ask for bounds manually</p>
   */
  external renderable : t => Js.boolean = "" [@@bs.get];
  /*
   <p>Can this object be rendered, if false the object will not be drawn but the updateTransform
   methods will still be called.</p>
   <p>Only affects recursive calls from parent. You can ask for bounds manually</p>
   */
  external setRenderable : t => Js.boolean => unit = "renderable" [@@bs.set];
  /*
   <p>The display object container that contains this display object.</p>
   */
  external parent : t => unit /* unknown js type: PIXI.Container */ = "" [@@bs.get];
  /*
   <p>The multiplied alpha of the displayObject</p>
   */
  external worldAlpha : t => int = "" [@@bs.get];
  /*
   <p>The area the filter is applied to. This is used as more of an optimisation
   rather than figuring out the dimensions of the displayObject each frame you can set this rectangle</p>
   <p>Also works as an interaction mask</p>
   */
  external filterArea : t => unit /* unknown js type: PIXI.Rectangle */ = "" [@@bs.get];
  /*
   <p>The area the filter is applied to. This is used as more of an optimisation
   rather than figuring out the dimensions of the displayObject each frame you can set this rectangle</p>
   <p>Also works as an interaction mask</p>
   */
  external setFilterArea : t => unit /* unknown js type: PIXI.Rectangle */ => unit =
    "filterArea" [@@bs.set];
  /*
   <p>The position of the displayObject on the x axis relative to the local coordinates of the parent.
   An alias to position.x</p>
   */
  external x : t => int = "" [@@bs.get];
  /*
   <p>The position of the displayObject on the x axis relative to the local coordinates of the parent.
   An alias to position.x</p>
   */
  external setX : t => int => unit = "x" [@@bs.set];
  /*
   <p>The position of the displayObject on the y axis relative to the local coordinates of the parent.
   An alias to position.y</p>
   */
  external y : t => int = "" [@@bs.get];
  /*
   <p>The position of the displayObject on the y axis relative to the local coordinates of the parent.
   An alias to position.y</p>
   */
  external setY : t => int => unit = "y" [@@bs.set];
  /*
   <p>Current transform of the object based on world (parent) factors</p>
   */
  external worldTransform : t => unit /* unknown js type: PIXI.Matrix */ = "" [@@bs.get];
  /*
   <p>Current transform of the object based on local factors: position, scale, other stuff</p>
   */
  external localTransform : t => unit /* unknown js type: PIXI.Matrix */ = "" [@@bs.get];
  /*
   <p>The coordinate of the object relative to the local coordinates of the parent.
   Assignment by value since pixi-v4.</p>
   */
  external position : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
    "" [@@bs.get];
  /*
   <p>The coordinate of the object relative to the local coordinates of the parent.
   Assignment by value since pixi-v4.</p>
   */
  external setPosition : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
    "position" [@@bs.set];
  /*
   <p>The scale factor of the object.
   Assignment by value since pixi-v4.</p>
   */
  external scale : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
    "" [@@bs.get];
  /*
   <p>The scale factor of the object.
   Assignment by value since pixi-v4.</p>
   */
  external setScale : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
    "scale" [@@bs.set];
  /*
   <p>The pivot point of the displayObject that it rotates around
   Assignment by value since pixi-v4.</p>
   */
  external pivot : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
    "" [@@bs.get];
  /*
   <p>The pivot point of the displayObject that it rotates around
   Assignment by value since pixi-v4.</p>
   */
  external setPivot : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
    "pivot" [@@bs.set];
  /*
   <p>The skew factor for the object in radians.
   Assignment by value since pixi-v4.</p>
   */
  external skew : t => unit /* unknown js type: PIXI.ObservablePoint */ = "" [@@bs.get];
  /*
   <p>The skew factor for the object in radians.
   Assignment by value since pixi-v4.</p>
   */
  external setSkew : t => unit /* unknown js type: PIXI.ObservablePoint */ => unit =
    "skew" [@@bs.set];
  /*
   <p>The rotation of the object in radians.</p>
   */
  external rotation : t => int = "" [@@bs.get];
  /*
   <p>The rotation of the object in radians.</p>
   */
  external setRotation : t => int => unit = "rotation" [@@bs.set];
  /*
   <p>Indicates if the object is globally visible.</p>
   */
  external worldVisible : t => Js.boolean = "" [@@bs.get];
  /*
   <p>Sets a mask for the displayObject. A mask is an object that limits the visibility of an
   object to the shape of the mask applied to it. In PIXI a regular mask must be a
   PIXI.Graphics or a PIXI.Sprite object. This allows for much faster masking in canvas as it
   utilises shape clipping. To remove a mask, set this property to null.</p>
   */
  external mask : t => unit /* unknown js type: PIXI.Graphics|PIXI.Sprite */ = "" [@@bs.get];
  /*
   <p>Sets a mask for the displayObject. A mask is an object that limits the visibility of an
   object to the shape of the mask applied to it. In PIXI a regular mask must be a
   PIXI.Graphics or a PIXI.Sprite object. This allows for much faster masking in canvas as it
   utilises shape clipping. To remove a mask, set this property to null.</p>
   */
  external setMask : t => unit /* unknown js type: PIXI.Graphics|PIXI.Sprite */ => unit =
    "mask" [@@bs.set];
  /*
   <p>Sets the filters for the displayObject.</p>
   <ul>
   <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
   To remove filters simply set this property to 'null'</li>
   </ul>
   */
  external filters : t => array unit /* unknown js type: PIXI.Filter */ = "" [@@bs.get];
  /*
   <p>Sets the filters for the displayObject.</p>
   <ul>
   <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
   To remove filters simply set this property to 'null'</li>
   </ul>
   */
  external setFilters : t => array unit /* unknown js type: PIXI.Filter */ => unit =
    "filters" [@@bs.set];
  /*
   <p>Set this to true if you want this display object to be cached as a bitmap.
   This basically takes a snap shot of the display object as it is at that moment. It can
   provide a performance benefit for complex static displayObjects.
   To remove simply set this property to 'false'</p>
   <p>IMPORTANT GOTCHA - make sure that all your textures are preloaded BEFORE setting this property to true
   as it will take a snapshot of what is currently there. If the textures have not loaded then they will not appear.</p>
   */
  external cacheAsBitmap : t => Js.boolean = "" [@@bs.get];
  /*
   <p>Set this to true if you want this display object to be cached as a bitmap.
   This basically takes a snap shot of the display object as it is at that moment. It can
   provide a performance benefit for complex static displayObjects.
   To remove simply set this property to 'false'</p>
   <p>IMPORTANT GOTCHA - make sure that all your textures are preloaded BEFORE setting this property to true
   as it will take a snapshot of what is currently there. If the textures have not loaded then they will not appear.</p>
   */
  external setCacheAsBitmap : t => Js.boolean => unit = "cacheAsBitmap" [@@bs.set];
  /*
   <p>Enable interaction events for the DisplayObject. Touch, pointer and mouse
   events will not be emitted unless <code>interactive</code> is set to <code>true</code>.</p>
   */
  external interactive : t => Js.boolean = "" [@@bs.get];
  /*
   <p>Enable interaction events for the DisplayObject. Touch, pointer and mouse
   events will not be emitted unless <code>interactive</code> is set to <code>true</code>.</p>
   */
  external setInteractive : t => Js.boolean => unit = "interactive" [@@bs.set];
  /*
   <p>Interaction shape. Children will be hit first, then this shape will be checked.
   Setting this will cause this shape to be checked in hit tests rather than the displayObject's bounds.</p>
   */
  external hitArea :
    t => unit /* unknown js type: PIXI.Rectangle|PIXI.Circle|PIXI.Ellipse|PIXI.Polygon|PIXI.RoundedRectangle */ =
    "" [@@bs.get];
  /*
   <p>Interaction shape. Children will be hit first, then this shape will be checked.
   Setting this will cause this shape to be checked in hit tests rather than the displayObject's bounds.</p>
   */
  external setHitArea :
    t =>
    unit /* unknown js type: PIXI.Rectangle|PIXI.Circle|PIXI.Ellipse|PIXI.Polygon|PIXI.RoundedRectangle */ =>
    unit =
    "hitArea" [@@bs.set];
  /*
   <p>If enabled, the mouse cursor use the pointer behavior when hovered over the displayObject if it is interactive
   Setting this changes the 'cursor' property to <code>'pointer'</code>.</p>
   */
  external buttonMode : t => Js.boolean = "" [@@bs.get];
  /*
   <p>If enabled, the mouse cursor use the pointer behavior when hovered over the displayObject if it is interactive
   Setting this changes the 'cursor' property to <code>'pointer'</code>.</p>
   */
  external setButtonMode : t => Js.boolean => unit = "buttonMode" [@@bs.set];
  /*
   <p>This defines what cursor mode is used when the mouse cursor
   is hovered over the displayObject.</p>
   */
  external cursor : t => string = "" [@@bs.get];
  /*
   <p>This defines what cursor mode is used when the mouse cursor
   is hovered over the displayObject.</p>
   */
  external setCursor : t => string => unit = "cursor" [@@bs.set];
};

module TextMetrics = {
  type t;
  module FontMetrics = {
    /*
     <p>Internal return object for {@link PIXI.TextMetrics.measureFont <code>TextMetrics.measureFont</code>}.</p>
     */
    type t;
  };
};

module TextStyle = {
  type t;
};

module BaseRenderTexture = {
  type t;
  /*
   <p>This will let the renderer know if the texture is valid. If it's not then it cannot be rendered.</p>
   */
  external valid : t => Js.boolean = "" [@@bs.get];
  /*
   <p>This will let the renderer know if the texture is valid. If it's not then it cannot be rendered.</p>
   */
  external setValid : t => Js.boolean => unit = "valid" [@@bs.set];
  /*
   <p>The resolution / device pixel ratio of the texture</p>
   */
  external resolution : t => int = "" [@@bs.get];
  /*
   <p>The resolution / device pixel ratio of the texture</p>
   */
  external setResolution : t => int => unit = "resolution" [@@bs.set];
  /*
   <p>The width of the base texture set when the image has loaded</p>
   */
  external width : t => int = "" [@@bs.get];
  /*
   <p>The height of the base texture set when the image has loaded</p>
   */
  external height : t => int = "" [@@bs.get];
  /*
   <p>Used to store the actual width of the source of this texture</p>
   */
  external realWidth : t => int = "" [@@bs.get];
  /*
   <p>Used to store the actual height of the source of this texture</p>
   */
  external realHeight : t => int = "" [@@bs.get];
  /*
   <p>The scale mode to apply when scaling this texture</p>
   */
  external scaleMode : t => int = "" [@@bs.get];
  /*
   <p>The scale mode to apply when scaling this texture</p>
   */
  external setScaleMode : t => int => unit = "scaleMode" [@@bs.set];
  /*
   <p>Set to true once the base texture has successfully loaded.</p>
   <p>This is never true if the underlying source fails to load or has no texture data.</p>
   */
  external hasLoaded : t => Js.boolean = "" [@@bs.get];
  /*
   <p>Set to true if the source is currently loading.</p>
   <p>If an Image source is loading the 'loaded' or 'error' event will be
   dispatched when the operation ends. An underyling source that is
   immediately-available bypasses loading entirely.</p>
   */
  external isLoading : t => Js.boolean = "" [@@bs.get];
  /*
   <p>The image source that is used to create the texture.</p>
   <p>TODO: Make this a setter that calls loadSource();</p>
   */
  external source : t => unit /* unknown js type: HTMLImageElement|HTMLCanvasElement */ =
    "" [@@bs.get];
  /*
   <p>The image source that is used to create the texture. This is used to
   store the original Svg source when it is replaced with a canvas element.</p>
   <p>TODO: Currently not in use but could be used when re-scaling svg.</p>
   */
  external origSource : t => unit /* unknown js type: Image */ = "" [@@bs.get];
  /*
   <p>Type of image defined in source, eg. <code>png</code> or <code>svg</code></p>
   */
  external imageType : t => string = "" [@@bs.get];
  /*
   <p>Scale for source image. Used with Svg images to scale them before rasterization.</p>
   */
  external sourceScale : t => int = "" [@@bs.get];
  /*
   <p>Controls if RGB channels should be pre-multiplied by Alpha  (WebGL only)
   All blend modes, and shaders written for default value. Change it on your own risk.</p>
   */
  external premultipliedAlpha : t => Js.boolean = "" [@@bs.get];
  /*
   <p>Controls if RGB channels should be pre-multiplied by Alpha  (WebGL only)
   All blend modes, and shaders written for default value. Change it on your own risk.</p>
   */
  external setPremultipliedAlpha : t => Js.boolean => unit = "premultipliedAlpha" [@@bs.set];
  /*
   <p>The image url of the texture</p>
   */
  external imageUrl : t => string = "" [@@bs.get];
  /*
   <p>The image url of the texture</p>
   */
  external setImageUrl : t => string => unit = "imageUrl" [@@bs.set];
  /*
   <p>Set this to true if a mipmap of this texture needs to be generated. This value needs
   to be set before the texture is used
   Also the texture must be a power of two size to work</p>
   */
  external mipmap : t => Js.boolean = "" [@@bs.get];
  /*
   <p>Set this to true if a mipmap of this texture needs to be generated. This value needs
   to be set before the texture is used
   Also the texture must be a power of two size to work</p>
   */
  external setMipmap : t => Js.boolean => unit = "mipmap" [@@bs.set];
  /*
   <p>WebGL Texture wrap mode</p>
   */
  external wrapMode : t => int = "" [@@bs.get];
  /*
   <p>WebGL Texture wrap mode</p>
   */
  external setWrapMode : t => int => unit = "wrapMode" [@@bs.set];
  /*
   <p>The ids under which this BaseTexture has been added to the base texture cache. This is
   automatically set as long as BaseTexture.addToCache is used, but may not be set if a
   BaseTexture is added directly to the BaseTextureCache array.</p>
   */
  external textureCacheIds : t => array string = "" [@@bs.get];
  /*
   <p>The ids under which this BaseTexture has been added to the base texture cache. This is
   automatically set as long as BaseTexture.addToCache is used, but may not be set if a
   BaseTexture is added directly to the BaseTextureCache array.</p>
   */
  external setTextureCacheIds : t => array string => unit = "textureCacheIds" [@@bs.set];
};

module BaseTexture = {
  type t;
  /*
   <p>The resolution / device pixel ratio of the texture</p>
   */
  external resolution : t => int = "" [@@bs.get];
  /*
   <p>The resolution / device pixel ratio of the texture</p>
   */
  external setResolution : t => int => unit = "resolution" [@@bs.set];
  /*
   <p>The width of the base texture set when the image has loaded</p>
   */
  external width : t => int = "" [@@bs.get];
  /*
   <p>The height of the base texture set when the image has loaded</p>
   */
  external height : t => int = "" [@@bs.get];
  /*
   <p>Used to store the actual width of the source of this texture</p>
   */
  external realWidth : t => int = "" [@@bs.get];
  /*
   <p>Used to store the actual height of the source of this texture</p>
   */
  external realHeight : t => int = "" [@@bs.get];
  /*
   <p>The scale mode to apply when scaling this texture</p>
   */
  external scaleMode : t => int = "" [@@bs.get];
  /*
   <p>The scale mode to apply when scaling this texture</p>
   */
  external setScaleMode : t => int => unit = "scaleMode" [@@bs.set];
  /*
   <p>Set to true once the base texture has successfully loaded.</p>
   <p>This is never true if the underlying source fails to load or has no texture data.</p>
   */
  external hasLoaded : t => Js.boolean = "" [@@bs.get];
  /*
   <p>Set to true if the source is currently loading.</p>
   <p>If an Image source is loading the 'loaded' or 'error' event will be
   dispatched when the operation ends. An underyling source that is
   immediately-available bypasses loading entirely.</p>
   */
  external isLoading : t => Js.boolean = "" [@@bs.get];
  /*
   <p>The image source that is used to create the texture.</p>
   <p>TODO: Make this a setter that calls loadSource();</p>
   */
  external source : t => unit /* unknown js type: HTMLImageElement|HTMLCanvasElement */ =
    "" [@@bs.get];
  /*
   <p>The image source that is used to create the texture. This is used to
   store the original Svg source when it is replaced with a canvas element.</p>
   <p>TODO: Currently not in use but could be used when re-scaling svg.</p>
   */
  external origSource : t => unit /* unknown js type: Image */ = "" [@@bs.get];
  /*
   <p>Type of image defined in source, eg. <code>png</code> or <code>svg</code></p>
   */
  external imageType : t => string = "" [@@bs.get];
  /*
   <p>Scale for source image. Used with Svg images to scale them before rasterization.</p>
   */
  external sourceScale : t => int = "" [@@bs.get];
  /*
   <p>Controls if RGB channels should be pre-multiplied by Alpha  (WebGL only)
   All blend modes, and shaders written for default value. Change it on your own risk.</p>
   */
  external premultipliedAlpha : t => Js.boolean = "" [@@bs.get];
  /*
   <p>Controls if RGB channels should be pre-multiplied by Alpha  (WebGL only)
   All blend modes, and shaders written for default value. Change it on your own risk.</p>
   */
  external setPremultipliedAlpha : t => Js.boolean => unit = "premultipliedAlpha" [@@bs.set];
  /*
   <p>The image url of the texture</p>
   */
  external imageUrl : t => string = "" [@@bs.get];
  /*
   <p>The image url of the texture</p>
   */
  external setImageUrl : t => string => unit = "imageUrl" [@@bs.set];
  /*
   <p>Set this to true if a mipmap of this texture needs to be generated. This value needs
   to be set before the texture is used
   Also the texture must be a power of two size to work</p>
   */
  external mipmap : t => Js.boolean = "" [@@bs.get];
  /*
   <p>Set this to true if a mipmap of this texture needs to be generated. This value needs
   to be set before the texture is used
   Also the texture must be a power of two size to work</p>
   */
  external setMipmap : t => Js.boolean => unit = "mipmap" [@@bs.set];
  /*
   <p>WebGL Texture wrap mode</p>
   */
  external wrapMode : t => int = "" [@@bs.get];
  /*
   <p>WebGL Texture wrap mode</p>
   */
  external setWrapMode : t => int => unit = "wrapMode" [@@bs.set];
  /*
   <p>The ids under which this BaseTexture has been added to the base texture cache. This is
   automatically set as long as BaseTexture.addToCache is used, but may not be set if a
   BaseTexture is added directly to the BaseTextureCache array.</p>
   */
  external textureCacheIds : t => array string = "" [@@bs.get];
  /*
   <p>The ids under which this BaseTexture has been added to the base texture cache. This is
   automatically set as long as BaseTexture.addToCache is used, but may not be set if a
   BaseTexture is added directly to the BaseTextureCache array.</p>
   */
  external setTextureCacheIds : t => array string => unit = "textureCacheIds" [@@bs.set];
};

module RenderTexture = {
  type t;
  /*
   <p>This will let the renderer know if the texture is valid. If it's not then it cannot be rendered.</p>
   */
  external valid : t => Js.boolean = "" [@@bs.get];
  /*
   <p>This will let the renderer know if the texture is valid. If it's not then it cannot be rendered.</p>
   */
  external setValid : t => Js.boolean => unit = "valid" [@@bs.set];
  /*
   <p>Does this Texture have any frame data assigned to it?</p>
   */
  external noFrame : t => Js.boolean = "" [@@bs.get];
  /*
   <p>Does this Texture have any frame data assigned to it?</p>
   */
  external setNoFrame : t => Js.boolean => unit = "noFrame" [@@bs.set];
  /*
   <p>The base texture that this texture uses.</p>
   */
  external baseTexture : t => unit /* unknown js type: PIXI.BaseTexture */ = "" [@@bs.get];
  /*
   <p>The base texture that this texture uses.</p>
   */
  external setBaseTexture : t => unit /* unknown js type: PIXI.BaseTexture */ => unit =
    "baseTexture" [@@bs.set];
  /*
   <p>This is the area of the BaseTexture image to actually copy to the Canvas / WebGL when rendering,
   irrespective of the actual frame size or placement (which can be influenced by trimmed texture atlases)</p>
   */
  external _frame : t => unit /* unknown js type: PIXI.Rectangle */ = "" [@@bs.get];
  /*
   <p>This is the area of the BaseTexture image to actually copy to the Canvas / WebGL when rendering,
   irrespective of the actual frame size or placement (which can be influenced by trimmed texture atlases)</p>
   */
  external set_frame : t => unit /* unknown js type: PIXI.Rectangle */ => unit =
    "_frame" [@@bs.set];
  /*
   <p>This is the trimmed area of original texture, before it was put in atlas</p>
   */
  external trim : t => unit /* unknown js type: PIXI.Rectangle */ = "" [@@bs.get];
  /*
   <p>This is the trimmed area of original texture, before it was put in atlas</p>
   */
  external setTrim : t => unit /* unknown js type: PIXI.Rectangle */ => unit = "trim" [@@bs.set];
  /*
   <p>This will let a renderer know that a texture has been updated (used mainly for webGL uv updates)</p>
   */
  external requiresUpdate : t => Js.boolean = "" [@@bs.get];
  /*
   <p>This will let a renderer know that a texture has been updated (used mainly for webGL uv updates)</p>
   */
  external setRequiresUpdate : t => Js.boolean => unit = "requiresUpdate" [@@bs.set];
  /*
   <p>This is the area of original texture, before it was put in atlas</p>
   */
  external orig : t => unit /* unknown js type: PIXI.Rectangle */ = "" [@@bs.get];
  /*
   <p>This is the area of original texture, before it was put in atlas</p>
   */
  external setOrig : t => unit /* unknown js type: PIXI.Rectangle */ => unit = "orig" [@@bs.set];
  /*
   <p>The ids under which this Texture has been added to the texture cache. This is
   automatically set as long as Texture.addToCache is used, but may not be set if a
   Texture is added directly to the TextureCache array.</p>
   */
  external textureCacheIds : t => array string = "" [@@bs.get];
  /*
   <p>The ids under which this Texture has been added to the texture cache. This is
   automatically set as long as Texture.addToCache is used, but may not be set if a
   Texture is added directly to the TextureCache array.</p>
   */
  external setTextureCacheIds : t => array string => unit = "textureCacheIds" [@@bs.set];
  /*
   <p>The frame specifies the region of the base texture that this texture uses.</p>
   */
  external frame : t => unit /* unknown js type: PIXI.Rectangle */ = "" [@@bs.get];
  /*
   <p>The frame specifies the region of the base texture that this texture uses.</p>
   */
  external setFrame : t => unit /* unknown js type: PIXI.Rectangle */ => unit = "frame" [@@bs.set];
  /*
   <p>Indicates whether the texture is rotated inside the atlas
   set to 2 to compensate for texture packer rotation
   set to 6 to compensate for spine packer rotation
   can be used to rotate or mirror sprites
   See {@link PIXI.GroupD8} for explanation</p>
   */
  external rotate : t => int = "" [@@bs.get];
  /*
   <p>Indicates whether the texture is rotated inside the atlas
   set to 2 to compensate for texture packer rotation
   set to 6 to compensate for spine packer rotation
   can be used to rotate or mirror sprites
   See {@link PIXI.GroupD8} for explanation</p>
   */
  external setRotate : t => int => unit = "rotate" [@@bs.set];
  /*
   <p>The width of the Texture in pixels.</p>
   */
  external width : t => int = "" [@@bs.get];
  /*
   <p>The width of the Texture in pixels.</p>
   */
  external setWidth : t => int => unit = "width" [@@bs.set];
  /*
   <p>The height of the Texture in pixels.</p>
   */
  external height : t => int = "" [@@bs.get];
  /*
   <p>The height of the Texture in pixels.</p>
   */
  external setHeight : t => int => unit = "height" [@@bs.set];
};

module Spritesheet = {
  type t;
  /*
   <p>Reference to ths source texture</p>
   */
  external baseTexture : t => unit /* unknown js type: PIXI.BaseTexture */ = "" [@@bs.get];
  /*
   <p>Reference to ths source texture</p>
   */
  external setBaseTexture : t => unit /* unknown js type: PIXI.BaseTexture */ => unit =
    "baseTexture" [@@bs.set];
  /*
   <p>Map of spritesheet textures.</p>
   */
  external textures : t => unit /* unknown js type: Object */ = "" [@@bs.get];
  /*
   <p>Map of spritesheet textures.</p>
   */
  external setTextures : t => unit /* unknown js type: Object */ => unit = "textures" [@@bs.set];
  /*
   <p>Reference to the original JSON data.</p>
   */
  external data : t => unit /* unknown js type: Object */ = "" [@@bs.get];
  /*
   <p>Reference to the original JSON data.</p>
   */
  external setData : t => unit /* unknown js type: Object */ => unit = "data" [@@bs.set];
  /*
   <p>The resolution of the spritesheet.</p>
   */
  external resolution : t => int = "" [@@bs.get];
  /*
   <p>The resolution of the spritesheet.</p>
   */
  external setResolution : t => int => unit = "resolution" [@@bs.set];
};

module Texture = {
  type t;
  /*
   <p>Does this Texture have any frame data assigned to it?</p>
   */
  external noFrame : t => Js.boolean = "" [@@bs.get];
  /*
   <p>Does this Texture have any frame data assigned to it?</p>
   */
  external setNoFrame : t => Js.boolean => unit = "noFrame" [@@bs.set];
  /*
   <p>The base texture that this texture uses.</p>
   */
  external baseTexture : t => unit /* unknown js type: PIXI.BaseTexture */ = "" [@@bs.get];
  /*
   <p>The base texture that this texture uses.</p>
   */
  external setBaseTexture : t => unit /* unknown js type: PIXI.BaseTexture */ => unit =
    "baseTexture" [@@bs.set];
  /*
   <p>This is the area of the BaseTexture image to actually copy to the Canvas / WebGL when rendering,
   irrespective of the actual frame size or placement (which can be influenced by trimmed texture atlases)</p>
   */
  external _frame : t => unit /* unknown js type: PIXI.Rectangle */ = "" [@@bs.get];
  /*
   <p>This is the area of the BaseTexture image to actually copy to the Canvas / WebGL when rendering,
   irrespective of the actual frame size or placement (which can be influenced by trimmed texture atlases)</p>
   */
  external set_frame : t => unit /* unknown js type: PIXI.Rectangle */ => unit =
    "_frame" [@@bs.set];
  /*
   <p>This is the trimmed area of original texture, before it was put in atlas</p>
   */
  external trim : t => unit /* unknown js type: PIXI.Rectangle */ = "" [@@bs.get];
  /*
   <p>This is the trimmed area of original texture, before it was put in atlas</p>
   */
  external setTrim : t => unit /* unknown js type: PIXI.Rectangle */ => unit = "trim" [@@bs.set];
  /*
   <p>This will let the renderer know if the texture is valid. If it's not then it cannot be rendered.</p>
   */
  external valid : t => Js.boolean = "" [@@bs.get];
  /*
   <p>This will let the renderer know if the texture is valid. If it's not then it cannot be rendered.</p>
   */
  external setValid : t => Js.boolean => unit = "valid" [@@bs.set];
  /*
   <p>This will let a renderer know that a texture has been updated (used mainly for webGL uv updates)</p>
   */
  external requiresUpdate : t => Js.boolean = "" [@@bs.get];
  /*
   <p>This will let a renderer know that a texture has been updated (used mainly for webGL uv updates)</p>
   */
  external setRequiresUpdate : t => Js.boolean => unit = "requiresUpdate" [@@bs.set];
  /*
   <p>This is the area of original texture, before it was put in atlas</p>
   */
  external orig : t => unit /* unknown js type: PIXI.Rectangle */ = "" [@@bs.get];
  /*
   <p>This is the area of original texture, before it was put in atlas</p>
   */
  external setOrig : t => unit /* unknown js type: PIXI.Rectangle */ => unit = "orig" [@@bs.set];
  /*
   <p>Extra field for extra plugins. May contain clamp settings and some matrices</p>
   */
  external transform : t => unit /* unknown js type: Object */ = "" [@@bs.get];
  /*
   <p>Extra field for extra plugins. May contain clamp settings and some matrices</p>
   */
  external setTransform : t => unit /* unknown js type: Object */ => unit = "transform" [@@bs.set];
  /*
   <p>The ids under which this Texture has been added to the texture cache. This is
   automatically set as long as Texture.addToCache is used, but may not be set if a
   Texture is added directly to the TextureCache array.</p>
   */
  external textureCacheIds : t => array string = "" [@@bs.get];
  /*
   <p>The ids under which this Texture has been added to the texture cache. This is
   automatically set as long as Texture.addToCache is used, but may not be set if a
   Texture is added directly to the TextureCache array.</p>
   */
  external setTextureCacheIds : t => array string => unit = "textureCacheIds" [@@bs.set];
  /*
   <p>The frame specifies the region of the base texture that this texture uses.</p>
   */
  external frame : t => unit /* unknown js type: PIXI.Rectangle */ = "" [@@bs.get];
  /*
   <p>The frame specifies the region of the base texture that this texture uses.</p>
   */
  external setFrame : t => unit /* unknown js type: PIXI.Rectangle */ => unit = "frame" [@@bs.set];
  /*
   <p>Indicates whether the texture is rotated inside the atlas
   set to 2 to compensate for texture packer rotation
   set to 6 to compensate for spine packer rotation
   can be used to rotate or mirror sprites
   See {@link PIXI.GroupD8} for explanation</p>
   */
  external rotate : t => int = "" [@@bs.get];
  /*
   <p>Indicates whether the texture is rotated inside the atlas
   set to 2 to compensate for texture packer rotation
   set to 6 to compensate for spine packer rotation
   can be used to rotate or mirror sprites
   See {@link PIXI.GroupD8} for explanation</p>
   */
  external setRotate : t => int => unit = "rotate" [@@bs.set];
  /*
   <p>The width of the Texture in pixels.</p>
   */
  external width : t => int = "" [@@bs.get];
  /*
   <p>The width of the Texture in pixels.</p>
   */
  external setWidth : t => int => unit = "width" [@@bs.set];
  /*
   <p>The height of the Texture in pixels.</p>
   */
  external height : t => int = "" [@@bs.get];
  /*
   <p>The height of the Texture in pixels.</p>
   */
  external setHeight : t => int => unit = "height" [@@bs.set];
};

module TextureUvs = {
  type t;
};

module VideoBaseTexture = {
  type t;
  /*
   <p>When set to true will automatically play videos used by this texture once
   they are loaded. If false, it will not modify the playing state.</p>
   */
  external autoPlay : t => Js.boolean = "" [@@bs.get];
  /*
   <p>When set to true will automatically play videos used by this texture once
   they are loaded. If false, it will not modify the playing state.</p>
   */
  external setAutoPlay : t => Js.boolean => unit = "autoPlay" [@@bs.set];
  /*
   <p>Should the base texture automatically update itself, set to true by default</p>
   */
  external autoUpdate : t => Js.boolean = "" [@@bs.get];
  /*
   <p>Should the base texture automatically update itself, set to true by default</p>
   */
  external setAutoUpdate : t => Js.boolean => unit = "autoUpdate" [@@bs.set];
  /*
   <p>The resolution / device pixel ratio of the texture</p>
   */
  external resolution : t => int = "" [@@bs.get];
  /*
   <p>The resolution / device pixel ratio of the texture</p>
   */
  external setResolution : t => int => unit = "resolution" [@@bs.set];
  /*
   <p>The width of the base texture set when the image has loaded</p>
   */
  external width : t => int = "" [@@bs.get];
  /*
   <p>The height of the base texture set when the image has loaded</p>
   */
  external height : t => int = "" [@@bs.get];
  /*
   <p>Used to store the actual width of the source of this texture</p>
   */
  external realWidth : t => int = "" [@@bs.get];
  /*
   <p>Used to store the actual height of the source of this texture</p>
   */
  external realHeight : t => int = "" [@@bs.get];
  /*
   <p>The scale mode to apply when scaling this texture</p>
   */
  external scaleMode : t => int = "" [@@bs.get];
  /*
   <p>The scale mode to apply when scaling this texture</p>
   */
  external setScaleMode : t => int => unit = "scaleMode" [@@bs.set];
  /*
   <p>Set to true once the base texture has successfully loaded.</p>
   <p>This is never true if the underlying source fails to load or has no texture data.</p>
   */
  external hasLoaded : t => Js.boolean = "" [@@bs.get];
  /*
   <p>Set to true if the source is currently loading.</p>
   <p>If an Image source is loading the 'loaded' or 'error' event will be
   dispatched when the operation ends. An underyling source that is
   immediately-available bypasses loading entirely.</p>
   */
  external isLoading : t => Js.boolean = "" [@@bs.get];
  /*
   <p>The image source that is used to create the texture.</p>
   <p>TODO: Make this a setter that calls loadSource();</p>
   */
  external source : t => unit /* unknown js type: HTMLImageElement|HTMLCanvasElement */ =
    "" [@@bs.get];
  /*
   <p>The image source that is used to create the texture. This is used to
   store the original Svg source when it is replaced with a canvas element.</p>
   <p>TODO: Currently not in use but could be used when re-scaling svg.</p>
   */
  external origSource : t => unit /* unknown js type: Image */ = "" [@@bs.get];
  /*
   <p>Type of image defined in source, eg. <code>png</code> or <code>svg</code></p>
   */
  external imageType : t => string = "" [@@bs.get];
  /*
   <p>Scale for source image. Used with Svg images to scale them before rasterization.</p>
   */
  external sourceScale : t => int = "" [@@bs.get];
  /*
   <p>Controls if RGB channels should be pre-multiplied by Alpha  (WebGL only)
   All blend modes, and shaders written for default value. Change it on your own risk.</p>
   */
  external premultipliedAlpha : t => Js.boolean = "" [@@bs.get];
  /*
   <p>Controls if RGB channels should be pre-multiplied by Alpha  (WebGL only)
   All blend modes, and shaders written for default value. Change it on your own risk.</p>
   */
  external setPremultipliedAlpha : t => Js.boolean => unit = "premultipliedAlpha" [@@bs.set];
  /*
   <p>The image url of the texture</p>
   */
  external imageUrl : t => string = "" [@@bs.get];
  /*
   <p>The image url of the texture</p>
   */
  external setImageUrl : t => string => unit = "imageUrl" [@@bs.set];
  /*
   <p>Set this to true if a mipmap of this texture needs to be generated. This value needs
   to be set before the texture is used
   Also the texture must be a power of two size to work</p>
   */
  external mipmap : t => Js.boolean = "" [@@bs.get];
  /*
   <p>Set this to true if a mipmap of this texture needs to be generated. This value needs
   to be set before the texture is used
   Also the texture must be a power of two size to work</p>
   */
  external setMipmap : t => Js.boolean => unit = "mipmap" [@@bs.set];
  /*
   <p>WebGL Texture wrap mode</p>
   */
  external wrapMode : t => int = "" [@@bs.get];
  /*
   <p>WebGL Texture wrap mode</p>
   */
  external setWrapMode : t => int => unit = "wrapMode" [@@bs.set];
  /*
   <p>The ids under which this BaseTexture has been added to the base texture cache. This is
   automatically set as long as BaseTexture.addToCache is used, but may not be set if a
   BaseTexture is added directly to the BaseTextureCache array.</p>
   */
  external textureCacheIds : t => array string = "" [@@bs.get];
  /*
   <p>The ids under which this BaseTexture has been added to the base texture cache. This is
   automatically set as long as BaseTexture.addToCache is used, but may not be set if a
   BaseTexture is added directly to the BaseTextureCache array.</p>
   */
  external setTextureCacheIds : t => array string => unit = "textureCacheIds" [@@bs.set];
};

module Ticker = {
  module Ticker = {
    type t;
    /*
     <p>Whether or not this ticker should invoke the method
     {@link PIXI.ticker.Ticker#start} automatically
     when a listener is added.</p>
     */
    external autoStart : t => Js.boolean = "" [@@bs.get];
    /*
     <p>Whether or not this ticker should invoke the method
     {@link PIXI.ticker.Ticker#start} automatically
     when a listener is added.</p>
     */
    external setAutoStart : t => Js.boolean => unit = "autoStart" [@@bs.set];
    /*
     <p>Scalar time value from last frame to this frame.
     This value is capped by setting {@link PIXI.ticker.Ticker#minFPS}
     and is scaled with {@link PIXI.ticker.Ticker#speed}.
     <strong>Note:</strong> The cap may be exceeded by scaling.</p>
     */
    external deltaTime : t => int = "" [@@bs.get];
    /*
     <p>Scalar time value from last frame to this frame.
     This value is capped by setting {@link PIXI.ticker.Ticker#minFPS}
     and is scaled with {@link PIXI.ticker.Ticker#speed}.
     <strong>Note:</strong> The cap may be exceeded by scaling.</p>
     */
    external setDeltaTime : t => int => unit = "deltaTime" [@@bs.set];
    /*
     <p>Time elapsed in milliseconds from last frame to this frame.
     Opposed to what the scalar {@link PIXI.ticker.Ticker#deltaTime}
     is based, this value is neither capped nor scaled.
     If the platform supports DOMHighResTimeStamp,
     this value will have a precision of 1 µs.
     Defaults to target frame time</p>
     */
    external elapsedMS : t => int = "" [@@bs.get];
    /*
     <p>Time elapsed in milliseconds from last frame to this frame.
     Opposed to what the scalar {@link PIXI.ticker.Ticker#deltaTime}
     is based, this value is neither capped nor scaled.
     If the platform supports DOMHighResTimeStamp,
     this value will have a precision of 1 µs.
     Defaults to target frame time</p>
     */
    external setElapsedMS : t => int => unit = "elapsedMS" [@@bs.set];
    /*
     <p>The last time {@link PIXI.ticker.Ticker#update} was invoked.
     This value is also reset internally outside of invoking
     update, but only when a new animation frame is requested.
     If the platform supports DOMHighResTimeStamp,
     this value will have a precision of 1 µs.</p>
     */
    external lastTime : t => int = "" [@@bs.get];
    /*
     <p>The last time {@link PIXI.ticker.Ticker#update} was invoked.
     This value is also reset internally outside of invoking
     update, but only when a new animation frame is requested.
     If the platform supports DOMHighResTimeStamp,
     this value will have a precision of 1 µs.</p>
     */
    external setLastTime : t => int => unit = "lastTime" [@@bs.set];
    /*
     <p>Factor of current {@link PIXI.ticker.Ticker#deltaTime}.</p>
     */
    external speed : t => int = "" [@@bs.get];
    /*
     <p>Factor of current {@link PIXI.ticker.Ticker#deltaTime}.</p>
     */
    external setSpeed : t => int => unit = "speed" [@@bs.set];
    /*
     <p>Whether or not this ticker has been started.
     <code>true</code> if {@link PIXI.ticker.Ticker#start} has been called.
     <code>false</code> if {@link PIXI.ticker.Ticker#stop} has been called.
     While <code>false</code>, this value may change to <code>true</code> in the
     event of {@link PIXI.ticker.Ticker#autoStart} being <code>true</code>
     and a listener is added.</p>
     */
    external started : t => Js.boolean = "" [@@bs.get];
    /*
     <p>Whether or not this ticker has been started.
     <code>true</code> if {@link PIXI.ticker.Ticker#start} has been called.
     <code>false</code> if {@link PIXI.ticker.Ticker#stop} has been called.
     While <code>false</code>, this value may change to <code>true</code> in the
     event of {@link PIXI.ticker.Ticker#autoStart} being <code>true</code>
     and a listener is added.</p>
     */
    external setStarted : t => Js.boolean => unit = "started" [@@bs.set];
    /*
     <p>The frames per second at which this ticker is running.
     The default is approximately 60 in most modern browsers.
     <strong>Note:</strong> This does not factor in the value of
     {@link PIXI.ticker.Ticker#speed}, which is specific
     to scaling {@link PIXI.ticker.Ticker#deltaTime}.</p>
     */
    external fps : t => int = "FPS" [@@bs.get];
    /*
     <p>Manages the maximum amount of milliseconds allowed to
     elapse between invoking {@link PIXI.ticker.Ticker#update}.
     This value is used to cap {@link PIXI.ticker.Ticker#deltaTime},
     but does not effect the measured value of {@link PIXI.ticker.Ticker#FPS}.
     When setting this property it is clamped to a value between
     <code>0</code> and <code>PIXI.settings.TARGET_FPMS * 1000</code>.</p>
     */
    external minFPS : t => int = "" [@@bs.get];
    /*
     <p>Manages the maximum amount of milliseconds allowed to
     elapse between invoking {@link PIXI.ticker.Ticker#update}.
     This value is used to cap {@link PIXI.ticker.Ticker#deltaTime},
     but does not effect the measured value of {@link PIXI.ticker.Ticker#FPS}.
     When setting this property it is clamped to a value between
     <code>0</code> and <code>PIXI.settings.TARGET_FPMS * 1000</code>.</p>
     */
    external setMinFPS : t => int => unit = "minFPS" [@@bs.set];
  };
  module TickerListener = {
    /*
     <p>Constructor</p>
     */
    type t;
    /*
     <p>The handler function to execute.</p>
     */
    external fn : t => unit /* unknown js type: function */ = "" [@@bs.get];
    /*
     <p>The handler function to execute.</p>
     */
    external setFn : t => unit /* unknown js type: function */ => unit = "fn" [@@bs.set];
    /*
     <p>The calling to execute.</p>
     */
    external context : t => unit /* unknown js type: function */ = "" [@@bs.get];
    /*
     <p>The calling to execute.</p>
     */
    external setContext : t => unit /* unknown js type: function */ => unit = "context" [@@bs.set];
    /*
     <p>The current priority.</p>
     */
    external priority : t => int = "" [@@bs.get];
    /*
     <p>The current priority.</p>
     */
    external setPriority : t => int => unit = "priority" [@@bs.set];
    /*
     <p>If this should only execute once.</p>
     */
    external once : t => Js.boolean = "" [@@bs.get];
    /*
     <p>If this should only execute once.</p>
     */
    external setOnce : t => Js.boolean => unit = "once" [@@bs.set];
    /*
     <p>The next item in chain.</p>
     */
    external next : t => unit /* unknown js type: TickerListener */ = "" [@@bs.get];
    /*
     <p>The next item in chain.</p>
     */
    external setNext : t => unit /* unknown js type: TickerListener */ => unit = "next" [@@bs.set];
    /*
     <p>The previous item in chain.</p>
     */
    external previous : t => unit /* unknown js type: TickerListener */ = "" [@@bs.get];
    /*
     <p>The previous item in chain.</p>
     */
    external setPrevious : t => unit /* unknown js type: TickerListener */ => unit =
      "previous" [@@bs.set];
  };
};

module Utils = {
  module EventEmitter = {
    type t;
  };
};

module SpriteBatch = {
  type t;
};

module AssetLoader = {
  type t;
};

module Stage = {
  type t;
};

module DisplayObjectContainer = {
  type t;
};

module Strip = {
  type t;
};

module Rope = {
  type t;
};

module ParticleContainer = {
  type t;
};

module MovieClip = {
  type t;
};

module TilingSprite = {
  type t;
};

module BitmapText = {
  type t;
};

module BlendModes = {
  type t;
};

module ScaleModes = {
  type t;
};

module BaseTextureCache = {
  type t;
};

module TextureCache = {
  type t;
};

module AbstractFilter = {
  type t;
};

module TransformManual = {
  type t;
};

module Extras = {
  module MovieClip = {
    type t;
  };
  module AnimatedSprite = {
    type t;
    /*
     <p>The speed that the AnimatedSprite will play at. Higher is faster, lower is slower</p>
     */
    external animationSpeed : t => int = "" [@@bs.get];
    /*
     <p>The speed that the AnimatedSprite will play at. Higher is faster, lower is slower</p>
     */
    external setAnimationSpeed : t => int => unit = "animationSpeed" [@@bs.set];
    /*
     <p>Whether or not the animate sprite repeats after playing.</p>
     */
    external loop : t => Js.boolean = "" [@@bs.get];
    /*
     <p>Whether or not the animate sprite repeats after playing.</p>
     */
    external setLoop : t => Js.boolean => unit = "loop" [@@bs.set];
    /*
     <p>Function to call when a AnimatedSprite finishes playing</p>
     */
    external onComplete : t => unit /* unknown js type: function */ = "" [@@bs.get];
    /*
     <p>Function to call when a AnimatedSprite finishes playing</p>
     */
    external setOnComplete : t => unit /* unknown js type: function */ => unit =
      "onComplete" [@@bs.set];
    /*
     <p>Function to call when a AnimatedSprite changes which texture is being rendered</p>
     */
    external onFrameChange : t => unit /* unknown js type: function */ = "" [@@bs.get];
    /*
     <p>Function to call when a AnimatedSprite changes which texture is being rendered</p>
     */
    external setOnFrameChange : t => unit /* unknown js type: function */ => unit =
      "onFrameChange" [@@bs.set];
    /*
     <p>Function to call when 'loop' is true, and an AnimatedSprite is played and loops around to start again</p>
     */
    external onLoop : t => unit /* unknown js type: function */ = "" [@@bs.get];
    /*
     <p>Function to call when 'loop' is true, and an AnimatedSprite is played and loops around to start again</p>
     */
    external setOnLoop : t => unit /* unknown js type: function */ => unit = "onLoop" [@@bs.set];
    /*
     <p>Indicates if the AnimatedSprite is currently playing</p>
     */
    external playing : t => Js.boolean = "" [@@bs.get];
    /*
     <p>totalFrames is the total number of frames in the AnimatedSprite. This is the same as number of textures
     assigned to the AnimatedSprite.</p>
     */
    external totalFrames : t => int = "" [@@bs.get];
    /*
     <p>The array of textures used for this AnimatedSprite</p>
     */
    external textures : t => array unit /* unknown js type: PIXI.Texture */ = "" [@@bs.get];
    /*
     <p>The array of textures used for this AnimatedSprite</p>
     */
    external setTextures : t => array unit /* unknown js type: PIXI.Texture */ => unit =
      "textures" [@@bs.set];
    /*
     <p>The AnimatedSprites current frame index</p>
     */
    external currentFrame : t => int = "" [@@bs.get];
    /*
     <p>The blend mode to be applied to the sprite. Apply a value of <code>PIXI.BLEND_MODES.NORMAL</code> to reset the blend mode.</p>
     */
    external blendMode : t => int = "" [@@bs.get];
    /*
     <p>The blend mode to be applied to the sprite. Apply a value of <code>PIXI.BLEND_MODES.NORMAL</code> to reset the blend mode.</p>
     */
    external setBlendMode : t => int => unit = "blendMode" [@@bs.set];
    /*
     <p>The shader that will be used to render the sprite. Set to null to remove a current shader.</p>
     */
    external shader : t => unit /* unknown js type: PIXI.Filter|PIXI.Shader */ = "" [@@bs.get];
    /*
     <p>The shader that will be used to render the sprite. Set to null to remove a current shader.</p>
     */
    external setShader : t => unit /* unknown js type: PIXI.Filter|PIXI.Shader */ => unit =
      "shader" [@@bs.set];
    /*
     <p>Plugin that is responsible for rendering this element.
     Allows to customize the rendering process without overriding '_renderWebGL' &amp; '_renderCanvas' methods.</p>
     */
    external pluginName : t => string = "" [@@bs.get];
    /*
     <p>Plugin that is responsible for rendering this element.
     Allows to customize the rendering process without overriding '_renderWebGL' &amp; '_renderCanvas' methods.</p>
     */
    external setPluginName : t => string => unit = "pluginName" [@@bs.set];
    /*
     <p>The width of the sprite, setting this will actually modify the scale to achieve the value set</p>
     */
    external width : t => int = "" [@@bs.get];
    /*
     <p>The width of the sprite, setting this will actually modify the scale to achieve the value set</p>
     */
    external setWidth : t => int => unit = "width" [@@bs.set];
    /*
     <p>The height of the sprite, setting this will actually modify the scale to achieve the value set</p>
     */
    external height : t => int = "" [@@bs.get];
    /*
     <p>The height of the sprite, setting this will actually modify the scale to achieve the value set</p>
     */
    external setHeight : t => int => unit = "height" [@@bs.set];
    /*
     <p>The anchor sets the origin point of the texture.
     The default is 0,0 this means the texture's origin is the top left
     Setting the anchor to 0.5,0.5 means the texture's origin is centered
     Setting the anchor to 1,1 would mean the texture's origin point will be the bottom right corner</p>
     */
    external anchor : t => unit /* unknown js type: PIXI.ObservablePoint */ = "" [@@bs.get];
    /*
     <p>The anchor sets the origin point of the texture.
     The default is 0,0 this means the texture's origin is the top left
     Setting the anchor to 0.5,0.5 means the texture's origin is centered
     Setting the anchor to 1,1 would mean the texture's origin point will be the bottom right corner</p>
     */
    external setAnchor : t => unit /* unknown js type: PIXI.ObservablePoint */ => unit =
      "anchor" [@@bs.set];
    /*
     <p>The tint applied to the sprite. This is a hex value.
     A value of 0xFFFFFF will remove any tint effect.</p>
     */
    external tint : t => int = "" [@@bs.get];
    /*
     <p>The tint applied to the sprite. This is a hex value.
     A value of 0xFFFFFF will remove any tint effect.</p>
     */
    external setTint : t => int => unit = "tint" [@@bs.set];
    /*
     <p>The texture that the sprite is using</p>
     */
    external texture : t => unit /* unknown js type: PIXI.Texture */ = "" [@@bs.get];
    /*
     <p>The texture that the sprite is using</p>
     */
    external setTexture : t => unit /* unknown js type: PIXI.Texture */ => unit =
      "texture" [@@bs.set];
    /*
     <p>The array of children of this container.</p>
     */
    external children : t => array unit /* unknown js type: PIXI.DisplayObject */ = "" [@@bs.get];
    /*
     <p>Determines if the children to the displayObject can be clicked/touched
     Setting this to false allows pixi to bypass a recursive <code>hitTest</code> function</p>
     */
    external interactiveChildren : t => Js.boolean = "" [@@bs.get];
    /*
     <p>Determines if the children to the displayObject can be clicked/touched
     Setting this to false allows pixi to bypass a recursive <code>hitTest</code> function</p>
     */
    external setInteractiveChildren : t => Js.boolean => unit = "interactiveChildren" [@@bs.set];
    /*
     <p>World transform and local transform of this object.
     This will become read-only later, please do not assign anything there unless you know what are you doing</p>
     */
    external transform : t => unit /* unknown js type: PIXI.TransformBase */ = "" [@@bs.get];
    /*
     <p>World transform and local transform of this object.
     This will become read-only later, please do not assign anything there unless you know what are you doing</p>
     */
    external setTransform : t => unit /* unknown js type: PIXI.TransformBase */ => unit =
      "transform" [@@bs.set];
    /*
     <p>The opacity of the object.</p>
     */
    external alpha : t => int = "" [@@bs.get];
    /*
     <p>The opacity of the object.</p>
     */
    external setAlpha : t => int => unit = "alpha" [@@bs.set];
    /*
     <p>The visibility of the object. If false the object will not be drawn, and
     the updateTransform function will not be called.</p>
     <p>Only affects recursive calls from parent. You can ask for bounds or call updateTransform manually</p>
     */
    external visible : t => Js.boolean = "" [@@bs.get];
    /*
     <p>The visibility of the object. If false the object will not be drawn, and
     the updateTransform function will not be called.</p>
     <p>Only affects recursive calls from parent. You can ask for bounds or call updateTransform manually</p>
     */
    external setVisible : t => Js.boolean => unit = "visible" [@@bs.set];
    /*
     <p>Can this object be rendered, if false the object will not be drawn but the updateTransform
     methods will still be called.</p>
     <p>Only affects recursive calls from parent. You can ask for bounds manually</p>
     */
    external renderable : t => Js.boolean = "" [@@bs.get];
    /*
     <p>Can this object be rendered, if false the object will not be drawn but the updateTransform
     methods will still be called.</p>
     <p>Only affects recursive calls from parent. You can ask for bounds manually</p>
     */
    external setRenderable : t => Js.boolean => unit = "renderable" [@@bs.set];
    /*
     <p>The display object container that contains this display object.</p>
     */
    external parent : t => unit /* unknown js type: PIXI.Container */ = "" [@@bs.get];
    /*
     <p>The multiplied alpha of the displayObject</p>
     */
    external worldAlpha : t => int = "" [@@bs.get];
    /*
     <p>The area the filter is applied to. This is used as more of an optimisation
     rather than figuring out the dimensions of the displayObject each frame you can set this rectangle</p>
     <p>Also works as an interaction mask</p>
     */
    external filterArea : t => unit /* unknown js type: PIXI.Rectangle */ = "" [@@bs.get];
    /*
     <p>The area the filter is applied to. This is used as more of an optimisation
     rather than figuring out the dimensions of the displayObject each frame you can set this rectangle</p>
     <p>Also works as an interaction mask</p>
     */
    external setFilterArea : t => unit /* unknown js type: PIXI.Rectangle */ => unit =
      "filterArea" [@@bs.set];
    /*
     <p>The position of the displayObject on the x axis relative to the local coordinates of the parent.
     An alias to position.x</p>
     */
    external x : t => int = "" [@@bs.get];
    /*
     <p>The position of the displayObject on the x axis relative to the local coordinates of the parent.
     An alias to position.x</p>
     */
    external setX : t => int => unit = "x" [@@bs.set];
    /*
     <p>The position of the displayObject on the y axis relative to the local coordinates of the parent.
     An alias to position.y</p>
     */
    external y : t => int = "" [@@bs.get];
    /*
     <p>The position of the displayObject on the y axis relative to the local coordinates of the parent.
     An alias to position.y</p>
     */
    external setY : t => int => unit = "y" [@@bs.set];
    /*
     <p>Current transform of the object based on world (parent) factors</p>
     */
    external worldTransform : t => unit /* unknown js type: PIXI.Matrix */ = "" [@@bs.get];
    /*
     <p>Current transform of the object based on local factors: position, scale, other stuff</p>
     */
    external localTransform : t => unit /* unknown js type: PIXI.Matrix */ = "" [@@bs.get];
    /*
     <p>The coordinate of the object relative to the local coordinates of the parent.
     Assignment by value since pixi-v4.</p>
     */
    external position : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
      "" [@@bs.get];
    /*
     <p>The coordinate of the object relative to the local coordinates of the parent.
     Assignment by value since pixi-v4.</p>
     */
    external setPosition : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
      "position" [@@bs.set];
    /*
     <p>The scale factor of the object.
     Assignment by value since pixi-v4.</p>
     */
    external scale : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
      "" [@@bs.get];
    /*
     <p>The scale factor of the object.
     Assignment by value since pixi-v4.</p>
     */
    external setScale : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
      "scale" [@@bs.set];
    /*
     <p>The pivot point of the displayObject that it rotates around
     Assignment by value since pixi-v4.</p>
     */
    external pivot : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
      "" [@@bs.get];
    /*
     <p>The pivot point of the displayObject that it rotates around
     Assignment by value since pixi-v4.</p>
     */
    external setPivot : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
      "pivot" [@@bs.set];
    /*
     <p>The skew factor for the object in radians.
     Assignment by value since pixi-v4.</p>
     */
    external skew : t => unit /* unknown js type: PIXI.ObservablePoint */ = "" [@@bs.get];
    /*
     <p>The skew factor for the object in radians.
     Assignment by value since pixi-v4.</p>
     */
    external setSkew : t => unit /* unknown js type: PIXI.ObservablePoint */ => unit =
      "skew" [@@bs.set];
    /*
     <p>The rotation of the object in radians.</p>
     */
    external rotation : t => int = "" [@@bs.get];
    /*
     <p>The rotation of the object in radians.</p>
     */
    external setRotation : t => int => unit = "rotation" [@@bs.set];
    /*
     <p>Indicates if the object is globally visible.</p>
     */
    external worldVisible : t => Js.boolean = "" [@@bs.get];
    /*
     <p>Sets a mask for the displayObject. A mask is an object that limits the visibility of an
     object to the shape of the mask applied to it. In PIXI a regular mask must be a
     PIXI.Graphics or a PIXI.Sprite object. This allows for much faster masking in canvas as it
     utilises shape clipping. To remove a mask, set this property to null.</p>
     */
    external mask : t => unit /* unknown js type: PIXI.Graphics|PIXI.Sprite */ = "" [@@bs.get];
    /*
     <p>Sets a mask for the displayObject. A mask is an object that limits the visibility of an
     object to the shape of the mask applied to it. In PIXI a regular mask must be a
     PIXI.Graphics or a PIXI.Sprite object. This allows for much faster masking in canvas as it
     utilises shape clipping. To remove a mask, set this property to null.</p>
     */
    external setMask : t => unit /* unknown js type: PIXI.Graphics|PIXI.Sprite */ => unit =
      "mask" [@@bs.set];
    /*
     <p>Sets the filters for the displayObject.</p>
     <ul>
     <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
     To remove filters simply set this property to 'null'</li>
     </ul>
     */
    external filters : t => array unit /* unknown js type: PIXI.Filter */ = "" [@@bs.get];
    /*
     <p>Sets the filters for the displayObject.</p>
     <ul>
     <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
     To remove filters simply set this property to 'null'</li>
     </ul>
     */
    external setFilters : t => array unit /* unknown js type: PIXI.Filter */ => unit =
      "filters" [@@bs.set];
    /*
     <p>Set this to true if you want this display object to be cached as a bitmap.
     This basically takes a snap shot of the display object as it is at that moment. It can
     provide a performance benefit for complex static displayObjects.
     To remove simply set this property to 'false'</p>
     <p>IMPORTANT GOTCHA - make sure that all your textures are preloaded BEFORE setting this property to true
     as it will take a snapshot of what is currently there. If the textures have not loaded then they will not appear.</p>
     */
    external cacheAsBitmap : t => Js.boolean = "" [@@bs.get];
    /*
     <p>Set this to true if you want this display object to be cached as a bitmap.
     This basically takes a snap shot of the display object as it is at that moment. It can
     provide a performance benefit for complex static displayObjects.
     To remove simply set this property to 'false'</p>
     <p>IMPORTANT GOTCHA - make sure that all your textures are preloaded BEFORE setting this property to true
     as it will take a snapshot of what is currently there. If the textures have not loaded then they will not appear.</p>
     */
    external setCacheAsBitmap : t => Js.boolean => unit = "cacheAsBitmap" [@@bs.set];
    /*
     <p>Enable interaction events for the DisplayObject. Touch, pointer and mouse
     events will not be emitted unless <code>interactive</code> is set to <code>true</code>.</p>
     */
    external interactive : t => Js.boolean = "" [@@bs.get];
    /*
     <p>Enable interaction events for the DisplayObject. Touch, pointer and mouse
     events will not be emitted unless <code>interactive</code> is set to <code>true</code>.</p>
     */
    external setInteractive : t => Js.boolean => unit = "interactive" [@@bs.set];
    /*
     <p>Interaction shape. Children will be hit first, then this shape will be checked.
     Setting this will cause this shape to be checked in hit tests rather than the displayObject's bounds.</p>
     */
    external hitArea :
      t => unit /* unknown js type: PIXI.Rectangle|PIXI.Circle|PIXI.Ellipse|PIXI.Polygon|PIXI.RoundedRectangle */ =
      "" [@@bs.get];
    /*
     <p>Interaction shape. Children will be hit first, then this shape will be checked.
     Setting this will cause this shape to be checked in hit tests rather than the displayObject's bounds.</p>
     */
    external setHitArea :
      t =>
      unit /* unknown js type: PIXI.Rectangle|PIXI.Circle|PIXI.Ellipse|PIXI.Polygon|PIXI.RoundedRectangle */ =>
      unit =
      "hitArea" [@@bs.set];
    /*
     <p>If enabled, the mouse cursor use the pointer behavior when hovered over the displayObject if it is interactive
     Setting this changes the 'cursor' property to <code>'pointer'</code>.</p>
     */
    external buttonMode : t => Js.boolean = "" [@@bs.get];
    /*
     <p>If enabled, the mouse cursor use the pointer behavior when hovered over the displayObject if it is interactive
     Setting this changes the 'cursor' property to <code>'pointer'</code>.</p>
     */
    external setButtonMode : t => Js.boolean => unit = "buttonMode" [@@bs.set];
    /*
     <p>This defines what cursor mode is used when the mouse cursor
     is hovered over the displayObject.</p>
     */
    external cursor : t => string = "" [@@bs.get];
    /*
     <p>This defines what cursor mode is used when the mouse cursor
     is hovered over the displayObject.</p>
     */
    external setCursor : t => string => unit = "cursor" [@@bs.set];
  };
  module BitmapText = {
    type t;
    /*
     <p>The dirty state of this object.</p>
     */
    external dirty : t => Js.boolean = "" [@@bs.get];
    /*
     <p>The dirty state of this object.</p>
     */
    external setDirty : t => Js.boolean => unit = "dirty" [@@bs.set];
    /*
     <p>The tint of the BitmapText object</p>
     */
    external tint : t => int = "" [@@bs.get];
    /*
     <p>The tint of the BitmapText object</p>
     */
    external setTint : t => int => unit = "tint" [@@bs.set];
    /*
     <p>The alignment of the BitmapText object</p>
     */
    external align : t => string = "" [@@bs.get];
    /*
     <p>The alignment of the BitmapText object</p>
     */
    external setAlign : t => string => unit = "align" [@@bs.set];
    /*
     <p>The anchor sets the origin point of the text.
     The default is 0,0 this means the text's origin is the top left
     Setting the anchor to 0.5,0.5 means the text's origin is centered
     Setting the anchor to 1,1 would mean the text's origin point will be the bottom right corner</p>
     */
    external anchor : t => unit /* unknown js type: PIXI.Point|number */ = "" [@@bs.get];
    /*
     <p>The anchor sets the origin point of the text.
     The default is 0,0 this means the text's origin is the top left
     Setting the anchor to 0.5,0.5 means the text's origin is centered
     Setting the anchor to 1,1 would mean the text's origin point will be the bottom right corner</p>
     */
    external setAnchor : t => unit /* unknown js type: PIXI.Point|number */ => unit =
      "anchor" [@@bs.set];
    /*
     <p>The font descriptor of the BitmapText object</p>
     */
    external font : t => unit /* unknown js type: string|object */ = "" [@@bs.get];
    /*
     <p>The font descriptor of the BitmapText object</p>
     */
    external setFont : t => unit /* unknown js type: string|object */ => unit = "font" [@@bs.set];
    /*
     <p>The text of the BitmapText object</p>
     */
    external text : t => string = "" [@@bs.get];
    /*
     <p>The text of the BitmapText object</p>
     */
    external setText : t => string => unit = "text" [@@bs.set];
    /*
     <p>The max width of this bitmap text in pixels. If the text provided is longer than the
     value provided, line breaks will be automatically inserted in the last whitespace.
     Disable by setting value to 0</p>
     */
    external maxWidth : t => int = "" [@@bs.get];
    /*
     <p>The max width of this bitmap text in pixels. If the text provided is longer than the
     value provided, line breaks will be automatically inserted in the last whitespace.
     Disable by setting value to 0</p>
     */
    external setMaxWidth : t => int => unit = "maxWidth" [@@bs.set];
    /*
     <p>The max line height. This is useful when trying to use the total height of the Text,
     ie: when trying to vertically align.</p>
     */
    external maxLineHeight : t => int = "" [@@bs.get];
    /*
     <p>The width of the overall text, different from fontSize,
     which is defined in the style object</p>
     */
    external textWidth : t => int = "" [@@bs.get];
    /*
     <p>The height of the overall text, different from fontSize,
     which is defined in the style object</p>
     */
    external textHeight : t => int = "" [@@bs.get];
    /*
     <p>The array of children of this container.</p>
     */
    external children : t => array unit /* unknown js type: PIXI.DisplayObject */ = "" [@@bs.get];
    /*
     <p>The width of the Container, setting this will actually modify the scale to achieve the value set</p>
     */
    external width : t => int = "" [@@bs.get];
    /*
     <p>The width of the Container, setting this will actually modify the scale to achieve the value set</p>
     */
    external setWidth : t => int => unit = "width" [@@bs.set];
    /*
     <p>The height of the Container, setting this will actually modify the scale to achieve the value set</p>
     */
    external height : t => int = "" [@@bs.get];
    /*
     <p>The height of the Container, setting this will actually modify the scale to achieve the value set</p>
     */
    external setHeight : t => int => unit = "height" [@@bs.set];
    /*
     <p>Determines if the children to the displayObject can be clicked/touched
     Setting this to false allows pixi to bypass a recursive <code>hitTest</code> function</p>
     */
    external interactiveChildren : t => Js.boolean = "" [@@bs.get];
    /*
     <p>Determines if the children to the displayObject can be clicked/touched
     Setting this to false allows pixi to bypass a recursive <code>hitTest</code> function</p>
     */
    external setInteractiveChildren : t => Js.boolean => unit = "interactiveChildren" [@@bs.set];
    /*
     <p>World transform and local transform of this object.
     This will become read-only later, please do not assign anything there unless you know what are you doing</p>
     */
    external transform : t => unit /* unknown js type: PIXI.TransformBase */ = "" [@@bs.get];
    /*
     <p>World transform and local transform of this object.
     This will become read-only later, please do not assign anything there unless you know what are you doing</p>
     */
    external setTransform : t => unit /* unknown js type: PIXI.TransformBase */ => unit =
      "transform" [@@bs.set];
    /*
     <p>The opacity of the object.</p>
     */
    external alpha : t => int = "" [@@bs.get];
    /*
     <p>The opacity of the object.</p>
     */
    external setAlpha : t => int => unit = "alpha" [@@bs.set];
    /*
     <p>The visibility of the object. If false the object will not be drawn, and
     the updateTransform function will not be called.</p>
     <p>Only affects recursive calls from parent. You can ask for bounds or call updateTransform manually</p>
     */
    external visible : t => Js.boolean = "" [@@bs.get];
    /*
     <p>The visibility of the object. If false the object will not be drawn, and
     the updateTransform function will not be called.</p>
     <p>Only affects recursive calls from parent. You can ask for bounds or call updateTransform manually</p>
     */
    external setVisible : t => Js.boolean => unit = "visible" [@@bs.set];
    /*
     <p>Can this object be rendered, if false the object will not be drawn but the updateTransform
     methods will still be called.</p>
     <p>Only affects recursive calls from parent. You can ask for bounds manually</p>
     */
    external renderable : t => Js.boolean = "" [@@bs.get];
    /*
     <p>Can this object be rendered, if false the object will not be drawn but the updateTransform
     methods will still be called.</p>
     <p>Only affects recursive calls from parent. You can ask for bounds manually</p>
     */
    external setRenderable : t => Js.boolean => unit = "renderable" [@@bs.set];
    /*
     <p>The display object container that contains this display object.</p>
     */
    external parent : t => unit /* unknown js type: PIXI.Container */ = "" [@@bs.get];
    /*
     <p>The multiplied alpha of the displayObject</p>
     */
    external worldAlpha : t => int = "" [@@bs.get];
    /*
     <p>The area the filter is applied to. This is used as more of an optimisation
     rather than figuring out the dimensions of the displayObject each frame you can set this rectangle</p>
     <p>Also works as an interaction mask</p>
     */
    external filterArea : t => unit /* unknown js type: PIXI.Rectangle */ = "" [@@bs.get];
    /*
     <p>The area the filter is applied to. This is used as more of an optimisation
     rather than figuring out the dimensions of the displayObject each frame you can set this rectangle</p>
     <p>Also works as an interaction mask</p>
     */
    external setFilterArea : t => unit /* unknown js type: PIXI.Rectangle */ => unit =
      "filterArea" [@@bs.set];
    /*
     <p>The position of the displayObject on the x axis relative to the local coordinates of the parent.
     An alias to position.x</p>
     */
    external x : t => int = "" [@@bs.get];
    /*
     <p>The position of the displayObject on the x axis relative to the local coordinates of the parent.
     An alias to position.x</p>
     */
    external setX : t => int => unit = "x" [@@bs.set];
    /*
     <p>The position of the displayObject on the y axis relative to the local coordinates of the parent.
     An alias to position.y</p>
     */
    external y : t => int = "" [@@bs.get];
    /*
     <p>The position of the displayObject on the y axis relative to the local coordinates of the parent.
     An alias to position.y</p>
     */
    external setY : t => int => unit = "y" [@@bs.set];
    /*
     <p>Current transform of the object based on world (parent) factors</p>
     */
    external worldTransform : t => unit /* unknown js type: PIXI.Matrix */ = "" [@@bs.get];
    /*
     <p>Current transform of the object based on local factors: position, scale, other stuff</p>
     */
    external localTransform : t => unit /* unknown js type: PIXI.Matrix */ = "" [@@bs.get];
    /*
     <p>The coordinate of the object relative to the local coordinates of the parent.
     Assignment by value since pixi-v4.</p>
     */
    external position : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
      "" [@@bs.get];
    /*
     <p>The coordinate of the object relative to the local coordinates of the parent.
     Assignment by value since pixi-v4.</p>
     */
    external setPosition : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
      "position" [@@bs.set];
    /*
     <p>The scale factor of the object.
     Assignment by value since pixi-v4.</p>
     */
    external scale : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
      "" [@@bs.get];
    /*
     <p>The scale factor of the object.
     Assignment by value since pixi-v4.</p>
     */
    external setScale : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
      "scale" [@@bs.set];
    /*
     <p>The pivot point of the displayObject that it rotates around
     Assignment by value since pixi-v4.</p>
     */
    external pivot : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
      "" [@@bs.get];
    /*
     <p>The pivot point of the displayObject that it rotates around
     Assignment by value since pixi-v4.</p>
     */
    external setPivot : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
      "pivot" [@@bs.set];
    /*
     <p>The skew factor for the object in radians.
     Assignment by value since pixi-v4.</p>
     */
    external skew : t => unit /* unknown js type: PIXI.ObservablePoint */ = "" [@@bs.get];
    /*
     <p>The skew factor for the object in radians.
     Assignment by value since pixi-v4.</p>
     */
    external setSkew : t => unit /* unknown js type: PIXI.ObservablePoint */ => unit =
      "skew" [@@bs.set];
    /*
     <p>The rotation of the object in radians.</p>
     */
    external rotation : t => int = "" [@@bs.get];
    /*
     <p>The rotation of the object in radians.</p>
     */
    external setRotation : t => int => unit = "rotation" [@@bs.set];
    /*
     <p>Indicates if the object is globally visible.</p>
     */
    external worldVisible : t => Js.boolean = "" [@@bs.get];
    /*
     <p>Sets a mask for the displayObject. A mask is an object that limits the visibility of an
     object to the shape of the mask applied to it. In PIXI a regular mask must be a
     PIXI.Graphics or a PIXI.Sprite object. This allows for much faster masking in canvas as it
     utilises shape clipping. To remove a mask, set this property to null.</p>
     */
    external mask : t => unit /* unknown js type: PIXI.Graphics|PIXI.Sprite */ = "" [@@bs.get];
    /*
     <p>Sets a mask for the displayObject. A mask is an object that limits the visibility of an
     object to the shape of the mask applied to it. In PIXI a regular mask must be a
     PIXI.Graphics or a PIXI.Sprite object. This allows for much faster masking in canvas as it
     utilises shape clipping. To remove a mask, set this property to null.</p>
     */
    external setMask : t => unit /* unknown js type: PIXI.Graphics|PIXI.Sprite */ => unit =
      "mask" [@@bs.set];
    /*
     <p>Sets the filters for the displayObject.</p>
     <ul>
     <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
     To remove filters simply set this property to 'null'</li>
     </ul>
     */
    external filters : t => array unit /* unknown js type: PIXI.Filter */ = "" [@@bs.get];
    /*
     <p>Sets the filters for the displayObject.</p>
     <ul>
     <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
     To remove filters simply set this property to 'null'</li>
     </ul>
     */
    external setFilters : t => array unit /* unknown js type: PIXI.Filter */ => unit =
      "filters" [@@bs.set];
    /*
     <p>Set this to true if you want this display object to be cached as a bitmap.
     This basically takes a snap shot of the display object as it is at that moment. It can
     provide a performance benefit for complex static displayObjects.
     To remove simply set this property to 'false'</p>
     <p>IMPORTANT GOTCHA - make sure that all your textures are preloaded BEFORE setting this property to true
     as it will take a snapshot of what is currently there. If the textures have not loaded then they will not appear.</p>
     */
    external cacheAsBitmap : t => Js.boolean = "" [@@bs.get];
    /*
     <p>Set this to true if you want this display object to be cached as a bitmap.
     This basically takes a snap shot of the display object as it is at that moment. It can
     provide a performance benefit for complex static displayObjects.
     To remove simply set this property to 'false'</p>
     <p>IMPORTANT GOTCHA - make sure that all your textures are preloaded BEFORE setting this property to true
     as it will take a snapshot of what is currently there. If the textures have not loaded then they will not appear.</p>
     */
    external setCacheAsBitmap : t => Js.boolean => unit = "cacheAsBitmap" [@@bs.set];
    /*
     <p>Enable interaction events for the DisplayObject. Touch, pointer and mouse
     events will not be emitted unless <code>interactive</code> is set to <code>true</code>.</p>
     */
    external interactive : t => Js.boolean = "" [@@bs.get];
    /*
     <p>Enable interaction events for the DisplayObject. Touch, pointer and mouse
     events will not be emitted unless <code>interactive</code> is set to <code>true</code>.</p>
     */
    external setInteractive : t => Js.boolean => unit = "interactive" [@@bs.set];
    /*
     <p>Interaction shape. Children will be hit first, then this shape will be checked.
     Setting this will cause this shape to be checked in hit tests rather than the displayObject's bounds.</p>
     */
    external hitArea :
      t => unit /* unknown js type: PIXI.Rectangle|PIXI.Circle|PIXI.Ellipse|PIXI.Polygon|PIXI.RoundedRectangle */ =
      "" [@@bs.get];
    /*
     <p>Interaction shape. Children will be hit first, then this shape will be checked.
     Setting this will cause this shape to be checked in hit tests rather than the displayObject's bounds.</p>
     */
    external setHitArea :
      t =>
      unit /* unknown js type: PIXI.Rectangle|PIXI.Circle|PIXI.Ellipse|PIXI.Polygon|PIXI.RoundedRectangle */ =>
      unit =
      "hitArea" [@@bs.set];
    /*
     <p>If enabled, the mouse cursor use the pointer behavior when hovered over the displayObject if it is interactive
     Setting this changes the 'cursor' property to <code>'pointer'</code>.</p>
     */
    external buttonMode : t => Js.boolean = "" [@@bs.get];
    /*
     <p>If enabled, the mouse cursor use the pointer behavior when hovered over the displayObject if it is interactive
     Setting this changes the 'cursor' property to <code>'pointer'</code>.</p>
     */
    external setButtonMode : t => Js.boolean => unit = "buttonMode" [@@bs.set];
    /*
     <p>This defines what cursor mode is used when the mouse cursor
     is hovered over the displayObject.</p>
     */
    external cursor : t => string = "" [@@bs.get];
    /*
     <p>This defines what cursor mode is used when the mouse cursor
     is hovered over the displayObject.</p>
     */
    external setCursor : t => string => unit = "cursor" [@@bs.set];
  };
  module TextureTransform = {
    type t;
    /*
     <p>Changes frame clamping
     Works with TilingSprite and Mesh
     Change to 1.5 if you texture has repeated right and bottom lines, that leads to smoother borders</p>
     */
    external clampOffset : t => int = "" [@@bs.get];
    /*
     <p>Changes frame clamping
     Works with TilingSprite and Mesh
     Change to 1.5 if you texture has repeated right and bottom lines, that leads to smoother borders</p>
     */
    external setClampOffset : t => int => unit = "clampOffset" [@@bs.set];
    /*
     <p>Changes frame clamping
     Works with TilingSprite and Mesh
     Change to -0.5 to add a pixel to the edge, recommended for transparent trimmed textures in atlas</p>
     */
    external clampMargin : t => int = "" [@@bs.get];
    /*
     <p>Changes frame clamping
     Works with TilingSprite and Mesh
     Change to -0.5 to add a pixel to the edge, recommended for transparent trimmed textures in atlas</p>
     */
    external setClampMargin : t => int => unit = "clampMargin" [@@bs.set];
    /*
     <p>texture property</p>
     */
    external texture : t => unit /* unknown js type: PIXI.Texture */ = "" [@@bs.get];
    /*
     <p>texture property</p>
     */
    external setTexture : t => unit /* unknown js type: PIXI.Texture */ => unit =
      "texture" [@@bs.set];
  };
  module TilingSprite = {
    type t;
    /*
     <p>Tile transform</p>
     */
    external tileTransform : t => unit /* unknown js type: PIXI.TransformStatic */ = "" [@@bs.get];
    /*
     <p>Tile transform</p>
     */
    external setTileTransform : t => unit /* unknown js type: PIXI.TransformStatic */ => unit =
      "tileTransform" [@@bs.set];
    /*
     <p>transform that is applied to UV to get the texture coords</p>
     */
    external uvTransform : t => unit /* unknown js type: PIXI.extras.TextureTransform */ =
      "" [@@bs.get];
    /*
     <p>transform that is applied to UV to get the texture coords</p>
     */
    external setUvTransform : t => unit /* unknown js type: PIXI.extras.TextureTransform */ => unit =
      "uvTransform" [@@bs.set];
    /*
     <p>Plugin that is responsible for rendering this element.
     Allows to customize the rendering process without overriding '_renderWebGL' method.</p>
     */
    external pluginName : t => string = "" [@@bs.get];
    /*
     <p>Plugin that is responsible for rendering this element.
     Allows to customize the rendering process without overriding '_renderWebGL' method.</p>
     */
    external setPluginName : t => string => unit = "pluginName" [@@bs.set];
    /*
     <p>Whether or not anchor affects uvs</p>
     */
    external uvRespectAnchor : t => Js.boolean = "" [@@bs.get];
    /*
     <p>Whether or not anchor affects uvs</p>
     */
    external setUvRespectAnchor : t => Js.boolean => unit = "uvRespectAnchor" [@@bs.set];
    /*
     <p>Changes frame clamping in corresponding textureTransform, shortcut
     Change to -0.5 to add a pixel to the edge, recommended for transparent trimmed textures in atlas</p>
     */
    external clampMargin : t => int = "" [@@bs.get];
    /*
     <p>Changes frame clamping in corresponding textureTransform, shortcut
     Change to -0.5 to add a pixel to the edge, recommended for transparent trimmed textures in atlas</p>
     */
    external setClampMargin : t => int => unit = "clampMargin" [@@bs.set];
    /*
     <p>The scaling of the image that is being tiled</p>
     */
    external tileScale : t => unit /* unknown js type: PIXI.ObservablePoint */ = "" [@@bs.get];
    /*
     <p>The scaling of the image that is being tiled</p>
     */
    external setTileScale : t => unit /* unknown js type: PIXI.ObservablePoint */ => unit =
      "tileScale" [@@bs.set];
    /*
     <p>The offset of the image that is being tiled</p>
     */
    external tilePosition : t => unit /* unknown js type: PIXI.ObservablePoint */ = "" [@@bs.get];
    /*
     <p>The offset of the image that is being tiled</p>
     */
    external setTilePosition : t => unit /* unknown js type: PIXI.ObservablePoint */ => unit =
      "tilePosition" [@@bs.set];
    /*
     <p>The width of the sprite, setting this will actually modify the scale to achieve the value set</p>
     */
    external width : t => int = "" [@@bs.get];
    /*
     <p>The width of the sprite, setting this will actually modify the scale to achieve the value set</p>
     */
    external setWidth : t => int => unit = "width" [@@bs.set];
    /*
     <p>The height of the TilingSprite, setting this will actually modify the scale to achieve the value set</p>
     */
    external height : t => int = "" [@@bs.get];
    /*
     <p>The height of the TilingSprite, setting this will actually modify the scale to achieve the value set</p>
     */
    external setHeight : t => int => unit = "height" [@@bs.set];
    /*
     <p>The blend mode to be applied to the sprite. Apply a value of <code>PIXI.BLEND_MODES.NORMAL</code> to reset the blend mode.</p>
     */
    external blendMode : t => int = "" [@@bs.get];
    /*
     <p>The blend mode to be applied to the sprite. Apply a value of <code>PIXI.BLEND_MODES.NORMAL</code> to reset the blend mode.</p>
     */
    external setBlendMode : t => int => unit = "blendMode" [@@bs.set];
    /*
     <p>The shader that will be used to render the sprite. Set to null to remove a current shader.</p>
     */
    external shader : t => unit /* unknown js type: PIXI.Filter|PIXI.Shader */ = "" [@@bs.get];
    /*
     <p>The shader that will be used to render the sprite. Set to null to remove a current shader.</p>
     */
    external setShader : t => unit /* unknown js type: PIXI.Filter|PIXI.Shader */ => unit =
      "shader" [@@bs.set];
    /*
     <p>The anchor sets the origin point of the texture.
     The default is 0,0 this means the texture's origin is the top left
     Setting the anchor to 0.5,0.5 means the texture's origin is centered
     Setting the anchor to 1,1 would mean the texture's origin point will be the bottom right corner</p>
     */
    external anchor : t => unit /* unknown js type: PIXI.ObservablePoint */ = "" [@@bs.get];
    /*
     <p>The anchor sets the origin point of the texture.
     The default is 0,0 this means the texture's origin is the top left
     Setting the anchor to 0.5,0.5 means the texture's origin is centered
     Setting the anchor to 1,1 would mean the texture's origin point will be the bottom right corner</p>
     */
    external setAnchor : t => unit /* unknown js type: PIXI.ObservablePoint */ => unit =
      "anchor" [@@bs.set];
    /*
     <p>The tint applied to the sprite. This is a hex value.
     A value of 0xFFFFFF will remove any tint effect.</p>
     */
    external tint : t => int = "" [@@bs.get];
    /*
     <p>The tint applied to the sprite. This is a hex value.
     A value of 0xFFFFFF will remove any tint effect.</p>
     */
    external setTint : t => int => unit = "tint" [@@bs.set];
    /*
     <p>The texture that the sprite is using</p>
     */
    external texture : t => unit /* unknown js type: PIXI.Texture */ = "" [@@bs.get];
    /*
     <p>The texture that the sprite is using</p>
     */
    external setTexture : t => unit /* unknown js type: PIXI.Texture */ => unit =
      "texture" [@@bs.set];
    /*
     <p>The array of children of this container.</p>
     */
    external children : t => array unit /* unknown js type: PIXI.DisplayObject */ = "" [@@bs.get];
    /*
     <p>Determines if the children to the displayObject can be clicked/touched
     Setting this to false allows pixi to bypass a recursive <code>hitTest</code> function</p>
     */
    external interactiveChildren : t => Js.boolean = "" [@@bs.get];
    /*
     <p>Determines if the children to the displayObject can be clicked/touched
     Setting this to false allows pixi to bypass a recursive <code>hitTest</code> function</p>
     */
    external setInteractiveChildren : t => Js.boolean => unit = "interactiveChildren" [@@bs.set];
    /*
     <p>World transform and local transform of this object.
     This will become read-only later, please do not assign anything there unless you know what are you doing</p>
     */
    external transform : t => unit /* unknown js type: PIXI.TransformBase */ = "" [@@bs.get];
    /*
     <p>World transform and local transform of this object.
     This will become read-only later, please do not assign anything there unless you know what are you doing</p>
     */
    external setTransform : t => unit /* unknown js type: PIXI.TransformBase */ => unit =
      "transform" [@@bs.set];
    /*
     <p>The opacity of the object.</p>
     */
    external alpha : t => int = "" [@@bs.get];
    /*
     <p>The opacity of the object.</p>
     */
    external setAlpha : t => int => unit = "alpha" [@@bs.set];
    /*
     <p>The visibility of the object. If false the object will not be drawn, and
     the updateTransform function will not be called.</p>
     <p>Only affects recursive calls from parent. You can ask for bounds or call updateTransform manually</p>
     */
    external visible : t => Js.boolean = "" [@@bs.get];
    /*
     <p>The visibility of the object. If false the object will not be drawn, and
     the updateTransform function will not be called.</p>
     <p>Only affects recursive calls from parent. You can ask for bounds or call updateTransform manually</p>
     */
    external setVisible : t => Js.boolean => unit = "visible" [@@bs.set];
    /*
     <p>Can this object be rendered, if false the object will not be drawn but the updateTransform
     methods will still be called.</p>
     <p>Only affects recursive calls from parent. You can ask for bounds manually</p>
     */
    external renderable : t => Js.boolean = "" [@@bs.get];
    /*
     <p>Can this object be rendered, if false the object will not be drawn but the updateTransform
     methods will still be called.</p>
     <p>Only affects recursive calls from parent. You can ask for bounds manually</p>
     */
    external setRenderable : t => Js.boolean => unit = "renderable" [@@bs.set];
    /*
     <p>The display object container that contains this display object.</p>
     */
    external parent : t => unit /* unknown js type: PIXI.Container */ = "" [@@bs.get];
    /*
     <p>The multiplied alpha of the displayObject</p>
     */
    external worldAlpha : t => int = "" [@@bs.get];
    /*
     <p>The area the filter is applied to. This is used as more of an optimisation
     rather than figuring out the dimensions of the displayObject each frame you can set this rectangle</p>
     <p>Also works as an interaction mask</p>
     */
    external filterArea : t => unit /* unknown js type: PIXI.Rectangle */ = "" [@@bs.get];
    /*
     <p>The area the filter is applied to. This is used as more of an optimisation
     rather than figuring out the dimensions of the displayObject each frame you can set this rectangle</p>
     <p>Also works as an interaction mask</p>
     */
    external setFilterArea : t => unit /* unknown js type: PIXI.Rectangle */ => unit =
      "filterArea" [@@bs.set];
    /*
     <p>The position of the displayObject on the x axis relative to the local coordinates of the parent.
     An alias to position.x</p>
     */
    external x : t => int = "" [@@bs.get];
    /*
     <p>The position of the displayObject on the x axis relative to the local coordinates of the parent.
     An alias to position.x</p>
     */
    external setX : t => int => unit = "x" [@@bs.set];
    /*
     <p>The position of the displayObject on the y axis relative to the local coordinates of the parent.
     An alias to position.y</p>
     */
    external y : t => int = "" [@@bs.get];
    /*
     <p>The position of the displayObject on the y axis relative to the local coordinates of the parent.
     An alias to position.y</p>
     */
    external setY : t => int => unit = "y" [@@bs.set];
    /*
     <p>Current transform of the object based on world (parent) factors</p>
     */
    external worldTransform : t => unit /* unknown js type: PIXI.Matrix */ = "" [@@bs.get];
    /*
     <p>Current transform of the object based on local factors: position, scale, other stuff</p>
     */
    external localTransform : t => unit /* unknown js type: PIXI.Matrix */ = "" [@@bs.get];
    /*
     <p>The coordinate of the object relative to the local coordinates of the parent.
     Assignment by value since pixi-v4.</p>
     */
    external position : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
      "" [@@bs.get];
    /*
     <p>The coordinate of the object relative to the local coordinates of the parent.
     Assignment by value since pixi-v4.</p>
     */
    external setPosition : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
      "position" [@@bs.set];
    /*
     <p>The scale factor of the object.
     Assignment by value since pixi-v4.</p>
     */
    external scale : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
      "" [@@bs.get];
    /*
     <p>The scale factor of the object.
     Assignment by value since pixi-v4.</p>
     */
    external setScale : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
      "scale" [@@bs.set];
    /*
     <p>The pivot point of the displayObject that it rotates around
     Assignment by value since pixi-v4.</p>
     */
    external pivot : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
      "" [@@bs.get];
    /*
     <p>The pivot point of the displayObject that it rotates around
     Assignment by value since pixi-v4.</p>
     */
    external setPivot : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
      "pivot" [@@bs.set];
    /*
     <p>The skew factor for the object in radians.
     Assignment by value since pixi-v4.</p>
     */
    external skew : t => unit /* unknown js type: PIXI.ObservablePoint */ = "" [@@bs.get];
    /*
     <p>The skew factor for the object in radians.
     Assignment by value since pixi-v4.</p>
     */
    external setSkew : t => unit /* unknown js type: PIXI.ObservablePoint */ => unit =
      "skew" [@@bs.set];
    /*
     <p>The rotation of the object in radians.</p>
     */
    external rotation : t => int = "" [@@bs.get];
    /*
     <p>The rotation of the object in radians.</p>
     */
    external setRotation : t => int => unit = "rotation" [@@bs.set];
    /*
     <p>Indicates if the object is globally visible.</p>
     */
    external worldVisible : t => Js.boolean = "" [@@bs.get];
    /*
     <p>Sets a mask for the displayObject. A mask is an object that limits the visibility of an
     object to the shape of the mask applied to it. In PIXI a regular mask must be a
     PIXI.Graphics or a PIXI.Sprite object. This allows for much faster masking in canvas as it
     utilises shape clipping. To remove a mask, set this property to null.</p>
     */
    external mask : t => unit /* unknown js type: PIXI.Graphics|PIXI.Sprite */ = "" [@@bs.get];
    /*
     <p>Sets a mask for the displayObject. A mask is an object that limits the visibility of an
     object to the shape of the mask applied to it. In PIXI a regular mask must be a
     PIXI.Graphics or a PIXI.Sprite object. This allows for much faster masking in canvas as it
     utilises shape clipping. To remove a mask, set this property to null.</p>
     */
    external setMask : t => unit /* unknown js type: PIXI.Graphics|PIXI.Sprite */ => unit =
      "mask" [@@bs.set];
    /*
     <p>Sets the filters for the displayObject.</p>
     <ul>
     <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
     To remove filters simply set this property to 'null'</li>
     </ul>
     */
    external filters : t => array unit /* unknown js type: PIXI.Filter */ = "" [@@bs.get];
    /*
     <p>Sets the filters for the displayObject.</p>
     <ul>
     <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
     To remove filters simply set this property to 'null'</li>
     </ul>
     */
    external setFilters : t => array unit /* unknown js type: PIXI.Filter */ => unit =
      "filters" [@@bs.set];
    /*
     <p>Set this to true if you want this display object to be cached as a bitmap.
     This basically takes a snap shot of the display object as it is at that moment. It can
     provide a performance benefit for complex static displayObjects.
     To remove simply set this property to 'false'</p>
     <p>IMPORTANT GOTCHA - make sure that all your textures are preloaded BEFORE setting this property to true
     as it will take a snapshot of what is currently there. If the textures have not loaded then they will not appear.</p>
     */
    external cacheAsBitmap : t => Js.boolean = "" [@@bs.get];
    /*
     <p>Set this to true if you want this display object to be cached as a bitmap.
     This basically takes a snap shot of the display object as it is at that moment. It can
     provide a performance benefit for complex static displayObjects.
     To remove simply set this property to 'false'</p>
     <p>IMPORTANT GOTCHA - make sure that all your textures are preloaded BEFORE setting this property to true
     as it will take a snapshot of what is currently there. If the textures have not loaded then they will not appear.</p>
     */
    external setCacheAsBitmap : t => Js.boolean => unit = "cacheAsBitmap" [@@bs.set];
    /*
     <p>Enable interaction events for the DisplayObject. Touch, pointer and mouse
     events will not be emitted unless <code>interactive</code> is set to <code>true</code>.</p>
     */
    external interactive : t => Js.boolean = "" [@@bs.get];
    /*
     <p>Enable interaction events for the DisplayObject. Touch, pointer and mouse
     events will not be emitted unless <code>interactive</code> is set to <code>true</code>.</p>
     */
    external setInteractive : t => Js.boolean => unit = "interactive" [@@bs.set];
    /*
     <p>Interaction shape. Children will be hit first, then this shape will be checked.
     Setting this will cause this shape to be checked in hit tests rather than the displayObject's bounds.</p>
     */
    external hitArea :
      t => unit /* unknown js type: PIXI.Rectangle|PIXI.Circle|PIXI.Ellipse|PIXI.Polygon|PIXI.RoundedRectangle */ =
      "" [@@bs.get];
    /*
     <p>Interaction shape. Children will be hit first, then this shape will be checked.
     Setting this will cause this shape to be checked in hit tests rather than the displayObject's bounds.</p>
     */
    external setHitArea :
      t =>
      unit /* unknown js type: PIXI.Rectangle|PIXI.Circle|PIXI.Ellipse|PIXI.Polygon|PIXI.RoundedRectangle */ =>
      unit =
      "hitArea" [@@bs.set];
    /*
     <p>If enabled, the mouse cursor use the pointer behavior when hovered over the displayObject if it is interactive
     Setting this changes the 'cursor' property to <code>'pointer'</code>.</p>
     */
    external buttonMode : t => Js.boolean = "" [@@bs.get];
    /*
     <p>If enabled, the mouse cursor use the pointer behavior when hovered over the displayObject if it is interactive
     Setting this changes the 'cursor' property to <code>'pointer'</code>.</p>
     */
    external setButtonMode : t => Js.boolean => unit = "buttonMode" [@@bs.set];
    /*
     <p>This defines what cursor mode is used when the mouse cursor
     is hovered over the displayObject.</p>
     */
    external cursor : t => string = "" [@@bs.get];
    /*
     <p>This defines what cursor mode is used when the mouse cursor
     is hovered over the displayObject.</p>
     */
    external setCursor : t => string => unit = "cursor" [@@bs.set];
  };
  module TilingSpriteRenderer = {
    /*
     <p>constructor for renderer</p>
     */
    type t;
    /*
     <p>The renderer this manager works for.</p>
     */
    external renderer : t => unit /* unknown js type: PIXI.WebGLRenderer */ = "" [@@bs.get];
    /*
     <p>The renderer this manager works for.</p>
     */
    external setRenderer : t => unit /* unknown js type: PIXI.WebGLRenderer */ => unit =
      "renderer" [@@bs.set];
  };
};

module Filters = {
  module AbstractFilter = {
    type t;
  };
  module SpriteMaskFilter = {
    type t;
  };
  module BlurFilter = {
    type t;
    /*
     <p>Sets the strength of both the blurX and blurY properties simultaneously</p>
     */
    external blur : t => int = "" [@@bs.get];
    /*
     <p>Sets the strength of both the blurX and blurY properties simultaneously</p>
     */
    external setBlur : t => int => unit = "blur" [@@bs.set];
    /*
     <p>Sets the number of passes for blur. More passes means higher quaility bluring.</p>
     */
    external quality : t => int = "" [@@bs.get];
    /*
     <p>Sets the number of passes for blur. More passes means higher quaility bluring.</p>
     */
    external setQuality : t => int => unit = "quality" [@@bs.set];
    /*
     <p>Sets the strength of the blurX property</p>
     */
    external blurX : t => int = "" [@@bs.get];
    /*
     <p>Sets the strength of the blurX property</p>
     */
    external setBlurX : t => int => unit = "blurX" [@@bs.set];
    /*
     <p>Sets the strength of the blurY property</p>
     */
    external blurY : t => int = "" [@@bs.get];
    /*
     <p>Sets the strength of the blurY property</p>
     */
    external setBlurY : t => int => unit = "blurY" [@@bs.set];
    /*
     <p>The vertex shader.</p>
     */
    external vertexSrc : t => string = "" [@@bs.get];
    /*
     <p>The vertex shader.</p>
     */
    external setVertexSrc : t => string => unit = "vertexSrc" [@@bs.set];
    /*
     <p>The fragment shader.</p>
     */
    external fragmentSrc : t => string = "" [@@bs.get];
    /*
     <p>The fragment shader.</p>
     */
    external setFragmentSrc : t => string => unit = "fragmentSrc" [@@bs.set];
    /*
     <p>An object containing the current values of custom uniforms.</p>
     */
    external uniforms : t => unit /* unknown js type: object */ = "" [@@bs.get];
    /*
     <p>An object containing the current values of custom uniforms.</p>
     */
    external setUniforms : t => unit /* unknown js type: object */ => unit = "uniforms" [@@bs.set];
    /*
     <p>The padding of the filter. Some filters require extra space to breath such as a blur.
     Increasing this will add extra width and height to the bounds of the object that the
     filter is applied to.</p>
     */
    external padding : t => int = "" [@@bs.get];
    /*
     <p>The padding of the filter. Some filters require extra space to breath such as a blur.
     Increasing this will add extra width and height to the bounds of the object that the
     filter is applied to.</p>
     */
    external setPadding : t => int => unit = "padding" [@@bs.set];
    /*
     <p>The resolution of the filter. Setting this to be lower will lower the quality but
     increase the performance of the filter.</p>
     */
    external resolution : t => int = "" [@@bs.get];
    /*
     <p>The resolution of the filter. Setting this to be lower will lower the quality but
     increase the performance of the filter.</p>
     */
    external setResolution : t => int => unit = "resolution" [@@bs.set];
    /*
     <p>If enabled is true the filter is applied, if false it will not.</p>
     */
    external enabled : t => Js.boolean = "" [@@bs.get];
    /*
     <p>If enabled is true the filter is applied, if false it will not.</p>
     */
    external setEnabled : t => Js.boolean => unit = "enabled" [@@bs.set];
    /*
     <p>If enabled, pixi will fit the filter area into boundaries for better performance.
     Switch it off if it does not work for specific shader.</p>
     */
    external autoFit : t => Js.boolean = "" [@@bs.get];
    /*
     <p>If enabled, pixi will fit the filter area into boundaries for better performance.
     Switch it off if it does not work for specific shader.</p>
     */
    external setAutoFit : t => Js.boolean => unit = "autoFit" [@@bs.set];
  };
  module BlurXFilter = {
    type t;
    /*
     <p>Sets the strength of both the blur.</p>
     */
    external blur : t => int = "" [@@bs.get];
    /*
     <p>Sets the strength of both the blur.</p>
     */
    external setBlur : t => int => unit = "blur" [@@bs.set];
    /*
     <p>Sets the quality of the blur by modifying the number of passes. More passes means higher
     quaility bluring but the lower the performance.</p>
     */
    external quality : t => int = "" [@@bs.get];
    /*
     <p>Sets the quality of the blur by modifying the number of passes. More passes means higher
     quaility bluring but the lower the performance.</p>
     */
    external setQuality : t => int => unit = "quality" [@@bs.set];
    /*
     <p>The vertex shader.</p>
     */
    external vertexSrc : t => string = "" [@@bs.get];
    /*
     <p>The vertex shader.</p>
     */
    external setVertexSrc : t => string => unit = "vertexSrc" [@@bs.set];
    /*
     <p>The fragment shader.</p>
     */
    external fragmentSrc : t => string = "" [@@bs.get];
    /*
     <p>The fragment shader.</p>
     */
    external setFragmentSrc : t => string => unit = "fragmentSrc" [@@bs.set];
    /*
     <p>An object containing the current values of custom uniforms.</p>
     */
    external uniforms : t => unit /* unknown js type: object */ = "" [@@bs.get];
    /*
     <p>An object containing the current values of custom uniforms.</p>
     */
    external setUniforms : t => unit /* unknown js type: object */ => unit = "uniforms" [@@bs.set];
    /*
     <p>The padding of the filter. Some filters require extra space to breath such as a blur.
     Increasing this will add extra width and height to the bounds of the object that the
     filter is applied to.</p>
     */
    external padding : t => int = "" [@@bs.get];
    /*
     <p>The padding of the filter. Some filters require extra space to breath such as a blur.
     Increasing this will add extra width and height to the bounds of the object that the
     filter is applied to.</p>
     */
    external setPadding : t => int => unit = "padding" [@@bs.set];
    /*
     <p>The resolution of the filter. Setting this to be lower will lower the quality but
     increase the performance of the filter.</p>
     */
    external resolution : t => int = "" [@@bs.get];
    /*
     <p>The resolution of the filter. Setting this to be lower will lower the quality but
     increase the performance of the filter.</p>
     */
    external setResolution : t => int => unit = "resolution" [@@bs.set];
    /*
     <p>If enabled is true the filter is applied, if false it will not.</p>
     */
    external enabled : t => Js.boolean = "" [@@bs.get];
    /*
     <p>If enabled is true the filter is applied, if false it will not.</p>
     */
    external setEnabled : t => Js.boolean => unit = "enabled" [@@bs.set];
    /*
     <p>If enabled, pixi will fit the filter area into boundaries for better performance.
     Switch it off if it does not work for specific shader.</p>
     */
    external autoFit : t => Js.boolean = "" [@@bs.get];
    /*
     <p>If enabled, pixi will fit the filter area into boundaries for better performance.
     Switch it off if it does not work for specific shader.</p>
     */
    external setAutoFit : t => Js.boolean => unit = "autoFit" [@@bs.set];
  };
  module BlurYFilter = {
    type t;
    /*
     <p>Sets the strength of both the blur.</p>
     */
    external blur : t => int = "" [@@bs.get];
    /*
     <p>Sets the strength of both the blur.</p>
     */
    external setBlur : t => int => unit = "blur" [@@bs.set];
    /*
     <p>Sets the quality of the blur by modifying the number of passes. More passes means higher
     quaility bluring but the lower the performance.</p>
     */
    external quality : t => int = "" [@@bs.get];
    /*
     <p>Sets the quality of the blur by modifying the number of passes. More passes means higher
     quaility bluring but the lower the performance.</p>
     */
    external setQuality : t => int => unit = "quality" [@@bs.set];
    /*
     <p>The vertex shader.</p>
     */
    external vertexSrc : t => string = "" [@@bs.get];
    /*
     <p>The vertex shader.</p>
     */
    external setVertexSrc : t => string => unit = "vertexSrc" [@@bs.set];
    /*
     <p>The fragment shader.</p>
     */
    external fragmentSrc : t => string = "" [@@bs.get];
    /*
     <p>The fragment shader.</p>
     */
    external setFragmentSrc : t => string => unit = "fragmentSrc" [@@bs.set];
    /*
     <p>An object containing the current values of custom uniforms.</p>
     */
    external uniforms : t => unit /* unknown js type: object */ = "" [@@bs.get];
    /*
     <p>An object containing the current values of custom uniforms.</p>
     */
    external setUniforms : t => unit /* unknown js type: object */ => unit = "uniforms" [@@bs.set];
    /*
     <p>The padding of the filter. Some filters require extra space to breath such as a blur.
     Increasing this will add extra width and height to the bounds of the object that the
     filter is applied to.</p>
     */
    external padding : t => int = "" [@@bs.get];
    /*
     <p>The padding of the filter. Some filters require extra space to breath such as a blur.
     Increasing this will add extra width and height to the bounds of the object that the
     filter is applied to.</p>
     */
    external setPadding : t => int => unit = "padding" [@@bs.set];
    /*
     <p>The resolution of the filter. Setting this to be lower will lower the quality but
     increase the performance of the filter.</p>
     */
    external resolution : t => int = "" [@@bs.get];
    /*
     <p>The resolution of the filter. Setting this to be lower will lower the quality but
     increase the performance of the filter.</p>
     */
    external setResolution : t => int => unit = "resolution" [@@bs.set];
    /*
     <p>If enabled is true the filter is applied, if false it will not.</p>
     */
    external enabled : t => Js.boolean = "" [@@bs.get];
    /*
     <p>If enabled is true the filter is applied, if false it will not.</p>
     */
    external setEnabled : t => Js.boolean => unit = "enabled" [@@bs.set];
    /*
     <p>If enabled, pixi will fit the filter area into boundaries for better performance.
     Switch it off if it does not work for specific shader.</p>
     */
    external autoFit : t => Js.boolean = "" [@@bs.get];
    /*
     <p>If enabled, pixi will fit the filter area into boundaries for better performance.
     Switch it off if it does not work for specific shader.</p>
     */
    external setAutoFit : t => Js.boolean => unit = "autoFit" [@@bs.set];
  };
  module ColorMatrixFilter = {
    type t;
    /*
     <p>The matrix of the color matrix filter</p>
     */
    external matrix : t => array int = "" [@@bs.get];
    /*
     <p>The matrix of the color matrix filter</p>
     */
    external setMatrix : t => array int => unit = "matrix" [@@bs.set];
    /*
     <p>The opacity value to use when mixing the original and resultant colors.</p>
     <p>When the value is 0, the original color is used without modification.
     When the value is 1, the result color is used.
     When in the range (0, 1) the color is interpolated between the original and result by this amount.</p>
     */
    external alpha : t => int = "" [@@bs.get];
    /*
     <p>The opacity value to use when mixing the original and resultant colors.</p>
     <p>When the value is 0, the original color is used without modification.
     When the value is 1, the result color is used.
     When in the range (0, 1) the color is interpolated between the original and result by this amount.</p>
     */
    external setAlpha : t => int => unit = "alpha" [@@bs.set];
    /*
     <p>The vertex shader.</p>
     */
    external vertexSrc : t => string = "" [@@bs.get];
    /*
     <p>The vertex shader.</p>
     */
    external setVertexSrc : t => string => unit = "vertexSrc" [@@bs.set];
    /*
     <p>The fragment shader.</p>
     */
    external fragmentSrc : t => string = "" [@@bs.get];
    /*
     <p>The fragment shader.</p>
     */
    external setFragmentSrc : t => string => unit = "fragmentSrc" [@@bs.set];
    /*
     <p>An object containing the current values of custom uniforms.</p>
     */
    external uniforms : t => unit /* unknown js type: object */ = "" [@@bs.get];
    /*
     <p>An object containing the current values of custom uniforms.</p>
     */
    external setUniforms : t => unit /* unknown js type: object */ => unit = "uniforms" [@@bs.set];
    /*
     <p>The padding of the filter. Some filters require extra space to breath such as a blur.
     Increasing this will add extra width and height to the bounds of the object that the
     filter is applied to.</p>
     */
    external padding : t => int = "" [@@bs.get];
    /*
     <p>The padding of the filter. Some filters require extra space to breath such as a blur.
     Increasing this will add extra width and height to the bounds of the object that the
     filter is applied to.</p>
     */
    external setPadding : t => int => unit = "padding" [@@bs.set];
    /*
     <p>The resolution of the filter. Setting this to be lower will lower the quality but
     increase the performance of the filter.</p>
     */
    external resolution : t => int = "" [@@bs.get];
    /*
     <p>The resolution of the filter. Setting this to be lower will lower the quality but
     increase the performance of the filter.</p>
     */
    external setResolution : t => int => unit = "resolution" [@@bs.set];
    /*
     <p>If enabled is true the filter is applied, if false it will not.</p>
     */
    external enabled : t => Js.boolean = "" [@@bs.get];
    /*
     <p>If enabled is true the filter is applied, if false it will not.</p>
     */
    external setEnabled : t => Js.boolean => unit = "enabled" [@@bs.set];
    /*
     <p>If enabled, pixi will fit the filter area into boundaries for better performance.
     Switch it off if it does not work for specific shader.</p>
     */
    external autoFit : t => Js.boolean = "" [@@bs.get];
    /*
     <p>If enabled, pixi will fit the filter area into boundaries for better performance.
     Switch it off if it does not work for specific shader.</p>
     */
    external setAutoFit : t => Js.boolean => unit = "autoFit" [@@bs.set];
  };
  module DisplacementFilter = {
    type t;
    /*
     <p>The texture used for the displacement map. Must be power of 2 sized texture.</p>
     */
    external map : t => unit /* unknown js type: PIXI.Texture */ = "" [@@bs.get];
    /*
     <p>The texture used for the displacement map. Must be power of 2 sized texture.</p>
     */
    external setMap : t => unit /* unknown js type: PIXI.Texture */ => unit = "map" [@@bs.set];
    /*
     <p>The vertex shader.</p>
     */
    external vertexSrc : t => string = "" [@@bs.get];
    /*
     <p>The vertex shader.</p>
     */
    external setVertexSrc : t => string => unit = "vertexSrc" [@@bs.set];
    /*
     <p>The fragment shader.</p>
     */
    external fragmentSrc : t => string = "" [@@bs.get];
    /*
     <p>The fragment shader.</p>
     */
    external setFragmentSrc : t => string => unit = "fragmentSrc" [@@bs.set];
    /*
     <p>An object containing the current values of custom uniforms.</p>
     */
    external uniforms : t => unit /* unknown js type: object */ = "" [@@bs.get];
    /*
     <p>An object containing the current values of custom uniforms.</p>
     */
    external setUniforms : t => unit /* unknown js type: object */ => unit = "uniforms" [@@bs.set];
    /*
     <p>The padding of the filter. Some filters require extra space to breath such as a blur.
     Increasing this will add extra width and height to the bounds of the object that the
     filter is applied to.</p>
     */
    external padding : t => int = "" [@@bs.get];
    /*
     <p>The padding of the filter. Some filters require extra space to breath such as a blur.
     Increasing this will add extra width and height to the bounds of the object that the
     filter is applied to.</p>
     */
    external setPadding : t => int => unit = "padding" [@@bs.set];
    /*
     <p>The resolution of the filter. Setting this to be lower will lower the quality but
     increase the performance of the filter.</p>
     */
    external resolution : t => int = "" [@@bs.get];
    /*
     <p>The resolution of the filter. Setting this to be lower will lower the quality but
     increase the performance of the filter.</p>
     */
    external setResolution : t => int => unit = "resolution" [@@bs.set];
    /*
     <p>If enabled is true the filter is applied, if false it will not.</p>
     */
    external enabled : t => Js.boolean = "" [@@bs.get];
    /*
     <p>If enabled is true the filter is applied, if false it will not.</p>
     */
    external setEnabled : t => Js.boolean => unit = "enabled" [@@bs.set];
    /*
     <p>If enabled, pixi will fit the filter area into boundaries for better performance.
     Switch it off if it does not work for specific shader.</p>
     */
    external autoFit : t => Js.boolean = "" [@@bs.get];
    /*
     <p>If enabled, pixi will fit the filter area into boundaries for better performance.
     Switch it off if it does not work for specific shader.</p>
     */
    external setAutoFit : t => Js.boolean => unit = "autoFit" [@@bs.set];
  };
  module FXAAFilter = {
    type t;
    /*
     <p>The vertex shader.</p>
     */
    external vertexSrc : t => string = "" [@@bs.get];
    /*
     <p>The vertex shader.</p>
     */
    external setVertexSrc : t => string => unit = "vertexSrc" [@@bs.set];
    /*
     <p>The fragment shader.</p>
     */
    external fragmentSrc : t => string = "" [@@bs.get];
    /*
     <p>The fragment shader.</p>
     */
    external setFragmentSrc : t => string => unit = "fragmentSrc" [@@bs.set];
    /*
     <p>An object containing the current values of custom uniforms.</p>
     */
    external uniforms : t => unit /* unknown js type: object */ = "" [@@bs.get];
    /*
     <p>An object containing the current values of custom uniforms.</p>
     */
    external setUniforms : t => unit /* unknown js type: object */ => unit = "uniforms" [@@bs.set];
    /*
     <p>The padding of the filter. Some filters require extra space to breath such as a blur.
     Increasing this will add extra width and height to the bounds of the object that the
     filter is applied to.</p>
     */
    external padding : t => int = "" [@@bs.get];
    /*
     <p>The padding of the filter. Some filters require extra space to breath such as a blur.
     Increasing this will add extra width and height to the bounds of the object that the
     filter is applied to.</p>
     */
    external setPadding : t => int => unit = "padding" [@@bs.set];
    /*
     <p>The resolution of the filter. Setting this to be lower will lower the quality but
     increase the performance of the filter.</p>
     */
    external resolution : t => int = "" [@@bs.get];
    /*
     <p>The resolution of the filter. Setting this to be lower will lower the quality but
     increase the performance of the filter.</p>
     */
    external setResolution : t => int => unit = "resolution" [@@bs.set];
    /*
     <p>If enabled is true the filter is applied, if false it will not.</p>
     */
    external enabled : t => Js.boolean = "" [@@bs.get];
    /*
     <p>If enabled is true the filter is applied, if false it will not.</p>
     */
    external setEnabled : t => Js.boolean => unit = "enabled" [@@bs.set];
    /*
     <p>If enabled, pixi will fit the filter area into boundaries for better performance.
     Switch it off if it does not work for specific shader.</p>
     */
    external autoFit : t => Js.boolean = "" [@@bs.get];
    /*
     <p>If enabled, pixi will fit the filter area into boundaries for better performance.
     Switch it off if it does not work for specific shader.</p>
     */
    external setAutoFit : t => Js.boolean => unit = "autoFit" [@@bs.set];
  };
  module NoiseFilter = {
    type t;
    /*
     <p>The amount of noise to apply, this value should be in the range (0, 1].</p>
     */
    external noise : t => int = "" [@@bs.get];
    /*
     <p>The amount of noise to apply, this value should be in the range (0, 1].</p>
     */
    external setNoise : t => int => unit = "noise" [@@bs.set];
    /*
     <p>A seed value to apply to the random noise generation. <code>Math.random()</code> is a good value to use.</p>
     */
    external seed : t => int = "" [@@bs.get];
    /*
     <p>A seed value to apply to the random noise generation. <code>Math.random()</code> is a good value to use.</p>
     */
    external setSeed : t => int => unit = "seed" [@@bs.set];
    /*
     <p>The vertex shader.</p>
     */
    external vertexSrc : t => string = "" [@@bs.get];
    /*
     <p>The vertex shader.</p>
     */
    external setVertexSrc : t => string => unit = "vertexSrc" [@@bs.set];
    /*
     <p>The fragment shader.</p>
     */
    external fragmentSrc : t => string = "" [@@bs.get];
    /*
     <p>The fragment shader.</p>
     */
    external setFragmentSrc : t => string => unit = "fragmentSrc" [@@bs.set];
    /*
     <p>An object containing the current values of custom uniforms.</p>
     */
    external uniforms : t => unit /* unknown js type: object */ = "" [@@bs.get];
    /*
     <p>An object containing the current values of custom uniforms.</p>
     */
    external setUniforms : t => unit /* unknown js type: object */ => unit = "uniforms" [@@bs.set];
    /*
     <p>The padding of the filter. Some filters require extra space to breath such as a blur.
     Increasing this will add extra width and height to the bounds of the object that the
     filter is applied to.</p>
     */
    external padding : t => int = "" [@@bs.get];
    /*
     <p>The padding of the filter. Some filters require extra space to breath such as a blur.
     Increasing this will add extra width and height to the bounds of the object that the
     filter is applied to.</p>
     */
    external setPadding : t => int => unit = "padding" [@@bs.set];
    /*
     <p>The resolution of the filter. Setting this to be lower will lower the quality but
     increase the performance of the filter.</p>
     */
    external resolution : t => int = "" [@@bs.get];
    /*
     <p>The resolution of the filter. Setting this to be lower will lower the quality but
     increase the performance of the filter.</p>
     */
    external setResolution : t => int => unit = "resolution" [@@bs.set];
    /*
     <p>If enabled is true the filter is applied, if false it will not.</p>
     */
    external enabled : t => Js.boolean = "" [@@bs.get];
    /*
     <p>If enabled is true the filter is applied, if false it will not.</p>
     */
    external setEnabled : t => Js.boolean => unit = "enabled" [@@bs.set];
    /*
     <p>If enabled, pixi will fit the filter area into boundaries for better performance.
     Switch it off if it does not work for specific shader.</p>
     */
    external autoFit : t => Js.boolean = "" [@@bs.get];
    /*
     <p>If enabled, pixi will fit the filter area into boundaries for better performance.
     Switch it off if it does not work for specific shader.</p>
     */
    external setAutoFit : t => Js.boolean => unit = "autoFit" [@@bs.set];
  };
  module VoidFilter = {
    type t;
    /*
     <p>The vertex shader.</p>
     */
    external vertexSrc : t => string = "" [@@bs.get];
    /*
     <p>The vertex shader.</p>
     */
    external setVertexSrc : t => string => unit = "vertexSrc" [@@bs.set];
    /*
     <p>The fragment shader.</p>
     */
    external fragmentSrc : t => string = "" [@@bs.get];
    /*
     <p>The fragment shader.</p>
     */
    external setFragmentSrc : t => string => unit = "fragmentSrc" [@@bs.set];
    /*
     <p>An object containing the current values of custom uniforms.</p>
     */
    external uniforms : t => unit /* unknown js type: object */ = "" [@@bs.get];
    /*
     <p>An object containing the current values of custom uniforms.</p>
     */
    external setUniforms : t => unit /* unknown js type: object */ => unit = "uniforms" [@@bs.set];
    /*
     <p>The padding of the filter. Some filters require extra space to breath such as a blur.
     Increasing this will add extra width and height to the bounds of the object that the
     filter is applied to.</p>
     */
    external padding : t => int = "" [@@bs.get];
    /*
     <p>The padding of the filter. Some filters require extra space to breath such as a blur.
     Increasing this will add extra width and height to the bounds of the object that the
     filter is applied to.</p>
     */
    external setPadding : t => int => unit = "padding" [@@bs.set];
    /*
     <p>The resolution of the filter. Setting this to be lower will lower the quality but
     increase the performance of the filter.</p>
     */
    external resolution : t => int = "" [@@bs.get];
    /*
     <p>The resolution of the filter. Setting this to be lower will lower the quality but
     increase the performance of the filter.</p>
     */
    external setResolution : t => int => unit = "resolution" [@@bs.set];
    /*
     <p>If enabled is true the filter is applied, if false it will not.</p>
     */
    external enabled : t => Js.boolean = "" [@@bs.get];
    /*
     <p>If enabled is true the filter is applied, if false it will not.</p>
     */
    external setEnabled : t => Js.boolean => unit = "enabled" [@@bs.set];
    /*
     <p>If enabled, pixi will fit the filter area into boundaries for better performance.
     Switch it off if it does not work for specific shader.</p>
     */
    external autoFit : t => Js.boolean = "" [@@bs.get];
    /*
     <p>If enabled, pixi will fit the filter area into boundaries for better performance.
     Switch it off if it does not work for specific shader.</p>
     */
    external setAutoFit : t => Js.boolean => unit = "autoFit" [@@bs.set];
  };
};

module Extract = {
  module CanvasExtract = {
    type t;
  };
  module WebGLExtract = {
    type t;
  };
};

module Interaction = {
  module InteractionData = {
    type t;
    /*
     <p>This point stores the global coords of where the touch/mouse event happened</p>
     */
    external global : t => unit /* unknown js type: PIXI.Point */ = "" [@@bs.get];
    /*
     <p>This point stores the global coords of where the touch/mouse event happened</p>
     */
    external setGlobal : t => unit /* unknown js type: PIXI.Point */ => unit = "global" [@@bs.set];
    /*
     <p>The target DisplayObject that was interacted with</p>
     */
    external target : t => unit /* unknown js type: PIXI.DisplayObject */ = "" [@@bs.get];
    /*
     <p>The target DisplayObject that was interacted with</p>
     */
    external setTarget : t => unit /* unknown js type: PIXI.DisplayObject */ => unit =
      "target" [@@bs.set];
    /*
     <p>When passed to an event handler, this will be the original DOM Event that was captured</p>
     */
    external originalEvent : t => unit /* unknown js type: MouseEvent|TouchEvent|PointerEvent */ =
      "" [@@bs.get];
    /*
     <p>When passed to an event handler, this will be the original DOM Event that was captured</p>
     */
    external setOriginalEvent :
      t => unit /* unknown js type: MouseEvent|TouchEvent|PointerEvent */ => unit =
      "originalEvent" [@@bs.set];
    /*
     <p>Unique identifier for this interaction</p>
     */
    external identifier : t => int = "" [@@bs.get];
    /*
     <p>Unique identifier for this interaction</p>
     */
    external setIdentifier : t => int => unit = "identifier" [@@bs.set];
    /*
     <p>Indicates whether or not the pointer device that created the event is the primary pointer.</p>
     */
    external isPrimary : t => unit /* unknown js type: Boolean */ = "" [@@bs.get];
    /*
     <p>Indicates whether or not the pointer device that created the event is the primary pointer.</p>
     */
    external setIsPrimary : t => unit /* unknown js type: Boolean */ => unit =
      "isPrimary" [@@bs.set];
    /*
     <p>Indicates which button was pressed on the mouse or pointer device to trigger the event.</p>
     */
    external button : t => int = "" [@@bs.get];
    /*
     <p>Indicates which button was pressed on the mouse or pointer device to trigger the event.</p>
     */
    external setButton : t => int => unit = "button" [@@bs.set];
    /*
     <p>Indicates which buttons are pressed on the mouse or pointer device when the event is triggered.</p>
     */
    external buttons : t => int = "" [@@bs.get];
    /*
     <p>Indicates which buttons are pressed on the mouse or pointer device when the event is triggered.</p>
     */
    external setButtons : t => int => unit = "buttons" [@@bs.set];
    /*
     <p>The width of the pointer's contact along the x-axis, measured in CSS pixels.
     radiusX of TouchEvents will be represented by this value.</p>
     */
    external width : t => int = "" [@@bs.get];
    /*
     <p>The width of the pointer's contact along the x-axis, measured in CSS pixels.
     radiusX of TouchEvents will be represented by this value.</p>
     */
    external setWidth : t => int => unit = "width" [@@bs.set];
    /*
     <p>The height of the pointer's contact along the y-axis, measured in CSS pixels.
     radiusY of TouchEvents will be represented by this value.</p>
     */
    external height : t => int = "" [@@bs.get];
    /*
     <p>The height of the pointer's contact along the y-axis, measured in CSS pixels.
     radiusY of TouchEvents will be represented by this value.</p>
     */
    external setHeight : t => int => unit = "height" [@@bs.set];
    /*
     <p>The angle, in degrees, between the pointer device and the screen.</p>
     */
    external tiltX : t => int = "" [@@bs.get];
    /*
     <p>The angle, in degrees, between the pointer device and the screen.</p>
     */
    external setTiltX : t => int => unit = "tiltX" [@@bs.set];
    /*
     <p>The angle, in degrees, between the pointer device and the screen.</p>
     */
    external tiltY : t => int = "" [@@bs.get];
    /*
     <p>The angle, in degrees, between the pointer device and the screen.</p>
     */
    external setTiltY : t => int => unit = "tiltY" [@@bs.set];
    /*
     <p>The type of pointer that triggered the event.</p>
     */
    external pointerType : t => string = "" [@@bs.get];
    /*
     <p>The type of pointer that triggered the event.</p>
     */
    external setPointerType : t => string => unit = "pointerType" [@@bs.set];
    /*
     <p>Pressure applied by the pointing device during the event. A Touch's force property
     will be represented by this value.</p>
     */
    external pressure : t => int = "" [@@bs.get];
    /*
     <p>Pressure applied by the pointing device during the event. A Touch's force property
     will be represented by this value.</p>
     */
    external setPressure : t => int => unit = "pressure" [@@bs.set];
    /*
     <p>From TouchEvents (not PointerEvents triggered by touches), the rotationAngle of the Touch.</p>
     */
    external rotationAngle : t => int = "" [@@bs.get];
    /*
     <p>From TouchEvents (not PointerEvents triggered by touches), the rotationAngle of the Touch.</p>
     */
    external setRotationAngle : t => int => unit = "rotationAngle" [@@bs.set];
    /*
     <p>Twist of a stylus pointer.</p>
     */
    external twist : t => int = "" [@@bs.get];
    /*
     <p>Twist of a stylus pointer.</p>
     */
    external setTwist : t => int => unit = "twist" [@@bs.set];
    /*
     <p>Barrel pressure on a stylus pointer.</p>
     */
    external tangentialPressure : t => int = "" [@@bs.get];
    /*
     <p>Barrel pressure on a stylus pointer.</p>
     */
    external setTangentialPressure : t => int => unit = "tangentialPressure" [@@bs.set];
    /*
     <p>The unique identifier of the pointer. It will be the same as <code>identifier</code>.</p>
     */
    external pointerId : t => int = "" [@@bs.get];
  };
  module InteractionEvent = {
    type t;
    /*
     <p>Whether this event will continue propagating in the tree</p>
     */
    external stopped : t => Js.boolean = "" [@@bs.get];
    /*
     <p>Whether this event will continue propagating in the tree</p>
     */
    external setStopped : t => Js.boolean => unit = "stopped" [@@bs.set];
    /*
     <p>The object which caused this event to be dispatched.
     For listener callback see {@link PIXI.interaction.InteractionEvent.currentTarget}.</p>
     */
    external target : t => unit /* unknown js type: PIXI.DisplayObject */ = "" [@@bs.get];
    /*
     <p>The object which caused this event to be dispatched.
     For listener callback see {@link PIXI.interaction.InteractionEvent.currentTarget}.</p>
     */
    external setTarget : t => unit /* unknown js type: PIXI.DisplayObject */ => unit =
      "target" [@@bs.set];
    /*
     <p>The object whose event listener’s callback is currently being invoked.</p>
     */
    external currentTarget : t => unit /* unknown js type: PIXI.DisplayObject */ = "" [@@bs.get];
    /*
     <p>The object whose event listener’s callback is currently being invoked.</p>
     */
    external setCurrentTarget : t => unit /* unknown js type: PIXI.DisplayObject */ => unit =
      "currentTarget" [@@bs.set];
    /*
     <p>Type of the event</p>
     */
    external type_ : t => string = "type" [@@bs.get];
    /*
     <p>Type of the event</p>
     */
    external setType : t => string => unit = "type" [@@bs.set];
    /*
     <p>InteractionData related to this event</p>
     */
    external data : t => unit /* unknown js type: PIXI.interaction.InteractionData */ =
      "" [@@bs.get];
    /*
     <p>InteractionData related to this event</p>
     */
    external setData : t => unit /* unknown js type: PIXI.interaction.InteractionData */ => unit =
      "data" [@@bs.set];
  };
  module InteractionManager = {
    type t;
    /*
     <p>The renderer this interaction manager works for.</p>
     */
    external renderer : t => unit /* unknown js type: PIXI.SystemRenderer */ = "" [@@bs.get];
    /*
     <p>The renderer this interaction manager works for.</p>
     */
    external setRenderer : t => unit /* unknown js type: PIXI.SystemRenderer */ => unit =
      "renderer" [@@bs.set];
    /*
     <p>Should default browser actions automatically be prevented.
     Does not apply to pointer events for backwards compatibility
     preventDefault on pointer events stops mouse events from firing
     Thus, for every pointer event, there will always be either a mouse of touch event alongside it.</p>
     */
    external autoPreventDefault : t => Js.boolean = "" [@@bs.get];
    /*
     <p>Should default browser actions automatically be prevented.
     Does not apply to pointer events for backwards compatibility
     preventDefault on pointer events stops mouse events from firing
     Thus, for every pointer event, there will always be either a mouse of touch event alongside it.</p>
     */
    external setAutoPreventDefault : t => Js.boolean => unit = "autoPreventDefault" [@@bs.set];
    /*
     <p>Frequency in milliseconds that the mousemove, moveover &amp; mouseout interaction events will be checked.</p>
     */
    external interactionFrequency : t => int = "" [@@bs.get];
    /*
     <p>Frequency in milliseconds that the mousemove, moveover &amp; mouseout interaction events will be checked.</p>
     */
    external setInteractionFrequency : t => int => unit = "interactionFrequency" [@@bs.set];
    /*
     <p>The mouse data</p>
     */
    external mouse : t => unit /* unknown js type: PIXI.interaction.InteractionData */ =
      "" [@@bs.get];
    /*
     <p>The mouse data</p>
     */
    external setMouse : t => unit /* unknown js type: PIXI.interaction.InteractionData */ => unit =
      "mouse" [@@bs.set];
    /*
     <p>An event data object to handle all the event tracking/dispatching</p>
     */
    external eventData : t => unit /* unknown js type: object */ = "" [@@bs.get];
    /*
     <p>An event data object to handle all the event tracking/dispatching</p>
     */
    external setEventData : t => unit /* unknown js type: object */ => unit =
      "eventData" [@@bs.set];
    /*
     <p>This property determines if mousemove and touchmove events are fired only when the cursor
     is over the object.
     Setting to true will make things work more in line with how the DOM verison works.
     Setting to false can make things easier for things like dragging
     It is currently set to false as this is how pixi used to work. This will be set to true in
     future versions of pixi.</p>
     */
    external moveWhenInside : t => Js.boolean = "" [@@bs.get];
    /*
     <p>This property determines if mousemove and touchmove events are fired only when the cursor
     is over the object.
     Setting to true will make things work more in line with how the DOM verison works.
     Setting to false can make things easier for things like dragging
     It is currently set to false as this is how pixi used to work. This will be set to true in
     future versions of pixi.</p>
     */
    external setMoveWhenInside : t => Js.boolean => unit = "moveWhenInside" [@@bs.set];
    /*
     <p>Does the device support touch events
     https://www.w3.org/TR/touch-events/</p>
     */
    external supportsTouchEvents : t => Js.boolean = "" [@@bs.get];
    /*
     <p>Does the device support pointer events
     https://www.w3.org/Submission/pointer-events/</p>
     */
    external supportsPointerEvents : t => Js.boolean = "" [@@bs.get];
    /*
     <p>Dictionary of how different cursor modes are handled. Strings are handled as CSS cursor
     values, objects are handled as dictionaries of CSS values for interactionDOMElement,
     and functions are called instead of changing the CSS.
     Default CSS cursor values are provided for 'default' and 'pointer' modes.</p>
     */
    external cursorStyles :
      t => unit /* unknown js type: Object.<string, (string|function()|Object.<string, string>)> */ =
      "" [@@bs.get];
    /*
     <p>Dictionary of how different cursor modes are handled. Strings are handled as CSS cursor
     values, objects are handled as dictionaries of CSS values for interactionDOMElement,
     and functions are called instead of changing the CSS.
     Default CSS cursor values are provided for 'default' and 'pointer' modes.</p>
     */
    external setCursorStyles :
      t =>
      unit /* unknown js type: Object.<string, (string|function()|Object.<string, string>)> */ =>
      unit =
      "cursorStyles" [@@bs.set];
    /*
     <p>The mode of the cursor that is being used.
     The value of this is a key from the cursorStyles dictionary.</p>
     */
    external currentCursorMode : t => string = "" [@@bs.get];
    /*
     <p>The mode of the cursor that is being used.
     The value of this is a key from the cursorStyles dictionary.</p>
     */
    external setCurrentCursorMode : t => string => unit = "currentCursorMode" [@@bs.set];
    /*
     <p>The current resolution / device pixel ratio.</p>
     */
    external resolution : t => int = "" [@@bs.get];
    /*
     <p>The current resolution / device pixel ratio.</p>
     */
    external setResolution : t => int => unit = "resolution" [@@bs.set];
  };
  module InteractionTrackingData = {
    type t;
    /*
     <p>Unique pointer id of the event</p>
     */
    external pointerId : t => int = "" [@@bs.get];
    /*
     <p>State of the tracking data, expressed as bit flags</p>
     */
    external flags : t => int = "" [@@bs.get];
    /*
     <p>State of the tracking data, expressed as bit flags</p>
     */
    external setFlags : t => int => unit = "flags" [@@bs.set];
    /*
     <p>Is the tracked event inactive (not over or down)?</p>
     */
    external none : t => int = "" [@@bs.get];
    /*
     <p>Is the tracked event inactive (not over or down)?</p>
     */
    external setNone : t => int => unit = "none" [@@bs.set];
    /*
     <p>Is the tracked event over the DisplayObject?</p>
     */
    external over : t => Js.boolean = "" [@@bs.get];
    /*
     <p>Is the tracked event over the DisplayObject?</p>
     */
    external setOver : t => Js.boolean => unit = "over" [@@bs.set];
    /*
     <p>Did the right mouse button come down in the DisplayObject?</p>
     */
    external rightDown : t => Js.boolean = "" [@@bs.get];
    /*
     <p>Did the right mouse button come down in the DisplayObject?</p>
     */
    external setRightDown : t => Js.boolean => unit = "rightDown" [@@bs.set];
    /*
     <p>Did the left mouse button come down in the DisplayObject?</p>
     */
    external leftDown : t => Js.boolean = "" [@@bs.get];
    /*
     <p>Did the left mouse button come down in the DisplayObject?</p>
     */
    external setLeftDown : t => Js.boolean => unit = "leftDown" [@@bs.set];
  };
};

module Loaders = {
  module Resource = {
    /*
     <p>Reference to <strong>resource-loader</strong>'s Resource class.
     See https://github.com/englercj/resource-loader</p>
     */
    type t;
  };
  module Loader = {
    type t;
  };
};

module Mesh = {
  module Mesh = {
    type t;
    /*
     <p>The Uvs of the Mesh</p>
     */
    external uvs : t => unit /* unknown js type: Float32Array */ = "" [@@bs.get];
    /*
     <p>The Uvs of the Mesh</p>
     */
    external setUvs : t => unit /* unknown js type: Float32Array */ => unit = "uvs" [@@bs.set];
    /*
     <p>An array of vertices</p>
     */
    external vertices : t => unit /* unknown js type: Float32Array */ = "" [@@bs.get];
    /*
     <p>An array of vertices</p>
     */
    external setVertices : t => unit /* unknown js type: Float32Array */ => unit =
      "vertices" [@@bs.set];
    /*
     <p>An array containing the indices of the vertices</p>
     */
    external indices : t => unit /* unknown js type: Uint16Array */ = "" [@@bs.get];
    /*
     <p>An array containing the indices of the vertices</p>
     */
    external setIndices : t => unit /* unknown js type: Uint16Array */ => unit =
      "indices" [@@bs.set];
    /*
     <p>Version of mesh uvs are dirty or not</p>
     */
    external dirty : t => int = "" [@@bs.get];
    /*
     <p>Version of mesh uvs are dirty or not</p>
     */
    external setDirty : t => int => unit = "dirty" [@@bs.set];
    /*
     <p>Version of mesh indices</p>
     */
    external indexDirty : t => int = "" [@@bs.get];
    /*
     <p>Version of mesh indices</p>
     */
    external setIndexDirty : t => int => unit = "indexDirty" [@@bs.set];
    /*
     <p>The blend mode to be applied to the sprite. Set to <code>PIXI.BLEND_MODES.NORMAL</code> to remove
     any blend mode.</p>
     */
    external blendMode : t => int = "" [@@bs.get];
    /*
     <p>The blend mode to be applied to the sprite. Set to <code>PIXI.BLEND_MODES.NORMAL</code> to remove
     any blend mode.</p>
     */
    external setBlendMode : t => int => unit = "blendMode" [@@bs.set];
    /*
     <p>Triangles in canvas mode are automatically antialiased, use this value to force triangles
     to overlap a bit with each other.</p>
     */
    external canvasPadding : t => int = "" [@@bs.get];
    /*
     <p>Triangles in canvas mode are automatically antialiased, use this value to force triangles
     to overlap a bit with each other.</p>
     */
    external setCanvasPadding : t => int => unit = "canvasPadding" [@@bs.set];
    /*
     <p>The way the Mesh should be drawn, can be any of the {@link PIXI.mesh.Mesh.DRAW_MODES} consts</p>
     */
    external drawMode : t => int = "" [@@bs.get];
    /*
     <p>The way the Mesh should be drawn, can be any of the {@link PIXI.mesh.Mesh.DRAW_MODES} consts</p>
     */
    external setDrawMode : t => int => unit = "drawMode" [@@bs.set];
    /*
     <p>The default shader that is used if a mesh doesn't have a more specific one.</p>
     */
    external shader : t => unit /* unknown js type: PIXI.Shader */ = "" [@@bs.get];
    /*
     <p>The default shader that is used if a mesh doesn't have a more specific one.</p>
     */
    external setShader : t => unit /* unknown js type: PIXI.Shader */ => unit =
      "shader" [@@bs.set];
    /*
     <p>The tint applied to the mesh. This is a [r,g,b] value. A value of [1,1,1] will remove any
     tint effect.</p>
     */
    external tintRgb : t => int = "" [@@bs.get];
    /*
     <p>The tint applied to the mesh. This is a [r,g,b] value. A value of [1,1,1] will remove any
     tint effect.</p>
     */
    external setTintRgb : t => int => unit = "tintRgb" [@@bs.set];
    /*
     <p>whether or not upload uvTransform to shader
     if its false, then uvs should be pre-multiplied
     if you change it for generated mesh, please call 'refresh(true)'</p>
     */
    external uploadUvTransform : t => Js.boolean = "" [@@bs.get];
    /*
     <p>whether or not upload uvTransform to shader
     if its false, then uvs should be pre-multiplied
     if you change it for generated mesh, please call 'refresh(true)'</p>
     */
    external setUploadUvTransform : t => Js.boolean => unit = "uploadUvTransform" [@@bs.set];
    /*
     <p>Plugin that is responsible for rendering this element.
     Allows to customize the rendering process without overriding '_renderWebGL' &amp; '_renderCanvas' methods.</p>
     */
    external pluginName : t => string = "" [@@bs.get];
    /*
     <p>Plugin that is responsible for rendering this element.
     Allows to customize the rendering process without overriding '_renderWebGL' &amp; '_renderCanvas' methods.</p>
     */
    external setPluginName : t => string => unit = "pluginName" [@@bs.set];
    /*
     <p>The texture that the mesh uses.</p>
     */
    external texture : t => unit /* unknown js type: PIXI.Texture */ = "" [@@bs.get];
    /*
     <p>The texture that the mesh uses.</p>
     */
    external setTexture : t => unit /* unknown js type: PIXI.Texture */ => unit =
      "texture" [@@bs.set];
    /*
     <p>The tint applied to the mesh. This is a hex value. A value of 0xFFFFFF will remove any tint effect.</p>
     */
    external tint : t => int = "" [@@bs.get];
    /*
     <p>The tint applied to the mesh. This is a hex value. A value of 0xFFFFFF will remove any tint effect.</p>
     */
    external setTint : t => int => unit = "tint" [@@bs.set];
    /*
     <p>The array of children of this container.</p>
     */
    external children : t => array unit /* unknown js type: PIXI.DisplayObject */ = "" [@@bs.get];
    /*
     <p>The width of the Container, setting this will actually modify the scale to achieve the value set</p>
     */
    external width : t => int = "" [@@bs.get];
    /*
     <p>The width of the Container, setting this will actually modify the scale to achieve the value set</p>
     */
    external setWidth : t => int => unit = "width" [@@bs.set];
    /*
     <p>The height of the Container, setting this will actually modify the scale to achieve the value set</p>
     */
    external height : t => int = "" [@@bs.get];
    /*
     <p>The height of the Container, setting this will actually modify the scale to achieve the value set</p>
     */
    external setHeight : t => int => unit = "height" [@@bs.set];
    /*
     <p>Determines if the children to the displayObject can be clicked/touched
     Setting this to false allows pixi to bypass a recursive <code>hitTest</code> function</p>
     */
    external interactiveChildren : t => Js.boolean = "" [@@bs.get];
    /*
     <p>Determines if the children to the displayObject can be clicked/touched
     Setting this to false allows pixi to bypass a recursive <code>hitTest</code> function</p>
     */
    external setInteractiveChildren : t => Js.boolean => unit = "interactiveChildren" [@@bs.set];
    /*
     <p>World transform and local transform of this object.
     This will become read-only later, please do not assign anything there unless you know what are you doing</p>
     */
    external transform : t => unit /* unknown js type: PIXI.TransformBase */ = "" [@@bs.get];
    /*
     <p>World transform and local transform of this object.
     This will become read-only later, please do not assign anything there unless you know what are you doing</p>
     */
    external setTransform : t => unit /* unknown js type: PIXI.TransformBase */ => unit =
      "transform" [@@bs.set];
    /*
     <p>The opacity of the object.</p>
     */
    external alpha : t => int = "" [@@bs.get];
    /*
     <p>The opacity of the object.</p>
     */
    external setAlpha : t => int => unit = "alpha" [@@bs.set];
    /*
     <p>The visibility of the object. If false the object will not be drawn, and
     the updateTransform function will not be called.</p>
     <p>Only affects recursive calls from parent. You can ask for bounds or call updateTransform manually</p>
     */
    external visible : t => Js.boolean = "" [@@bs.get];
    /*
     <p>The visibility of the object. If false the object will not be drawn, and
     the updateTransform function will not be called.</p>
     <p>Only affects recursive calls from parent. You can ask for bounds or call updateTransform manually</p>
     */
    external setVisible : t => Js.boolean => unit = "visible" [@@bs.set];
    /*
     <p>Can this object be rendered, if false the object will not be drawn but the updateTransform
     methods will still be called.</p>
     <p>Only affects recursive calls from parent. You can ask for bounds manually</p>
     */
    external renderable : t => Js.boolean = "" [@@bs.get];
    /*
     <p>Can this object be rendered, if false the object will not be drawn but the updateTransform
     methods will still be called.</p>
     <p>Only affects recursive calls from parent. You can ask for bounds manually</p>
     */
    external setRenderable : t => Js.boolean => unit = "renderable" [@@bs.set];
    /*
     <p>The display object container that contains this display object.</p>
     */
    external parent : t => unit /* unknown js type: PIXI.Container */ = "" [@@bs.get];
    /*
     <p>The multiplied alpha of the displayObject</p>
     */
    external worldAlpha : t => int = "" [@@bs.get];
    /*
     <p>The area the filter is applied to. This is used as more of an optimisation
     rather than figuring out the dimensions of the displayObject each frame you can set this rectangle</p>
     <p>Also works as an interaction mask</p>
     */
    external filterArea : t => unit /* unknown js type: PIXI.Rectangle */ = "" [@@bs.get];
    /*
     <p>The area the filter is applied to. This is used as more of an optimisation
     rather than figuring out the dimensions of the displayObject each frame you can set this rectangle</p>
     <p>Also works as an interaction mask</p>
     */
    external setFilterArea : t => unit /* unknown js type: PIXI.Rectangle */ => unit =
      "filterArea" [@@bs.set];
    /*
     <p>The position of the displayObject on the x axis relative to the local coordinates of the parent.
     An alias to position.x</p>
     */
    external x : t => int = "" [@@bs.get];
    /*
     <p>The position of the displayObject on the x axis relative to the local coordinates of the parent.
     An alias to position.x</p>
     */
    external setX : t => int => unit = "x" [@@bs.set];
    /*
     <p>The position of the displayObject on the y axis relative to the local coordinates of the parent.
     An alias to position.y</p>
     */
    external y : t => int = "" [@@bs.get];
    /*
     <p>The position of the displayObject on the y axis relative to the local coordinates of the parent.
     An alias to position.y</p>
     */
    external setY : t => int => unit = "y" [@@bs.set];
    /*
     <p>Current transform of the object based on world (parent) factors</p>
     */
    external worldTransform : t => unit /* unknown js type: PIXI.Matrix */ = "" [@@bs.get];
    /*
     <p>Current transform of the object based on local factors: position, scale, other stuff</p>
     */
    external localTransform : t => unit /* unknown js type: PIXI.Matrix */ = "" [@@bs.get];
    /*
     <p>The coordinate of the object relative to the local coordinates of the parent.
     Assignment by value since pixi-v4.</p>
     */
    external position : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
      "" [@@bs.get];
    /*
     <p>The coordinate of the object relative to the local coordinates of the parent.
     Assignment by value since pixi-v4.</p>
     */
    external setPosition : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
      "position" [@@bs.set];
    /*
     <p>The scale factor of the object.
     Assignment by value since pixi-v4.</p>
     */
    external scale : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
      "" [@@bs.get];
    /*
     <p>The scale factor of the object.
     Assignment by value since pixi-v4.</p>
     */
    external setScale : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
      "scale" [@@bs.set];
    /*
     <p>The pivot point of the displayObject that it rotates around
     Assignment by value since pixi-v4.</p>
     */
    external pivot : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
      "" [@@bs.get];
    /*
     <p>The pivot point of the displayObject that it rotates around
     Assignment by value since pixi-v4.</p>
     */
    external setPivot : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
      "pivot" [@@bs.set];
    /*
     <p>The skew factor for the object in radians.
     Assignment by value since pixi-v4.</p>
     */
    external skew : t => unit /* unknown js type: PIXI.ObservablePoint */ = "" [@@bs.get];
    /*
     <p>The skew factor for the object in radians.
     Assignment by value since pixi-v4.</p>
     */
    external setSkew : t => unit /* unknown js type: PIXI.ObservablePoint */ => unit =
      "skew" [@@bs.set];
    /*
     <p>The rotation of the object in radians.</p>
     */
    external rotation : t => int = "" [@@bs.get];
    /*
     <p>The rotation of the object in radians.</p>
     */
    external setRotation : t => int => unit = "rotation" [@@bs.set];
    /*
     <p>Indicates if the object is globally visible.</p>
     */
    external worldVisible : t => Js.boolean = "" [@@bs.get];
    /*
     <p>Sets a mask for the displayObject. A mask is an object that limits the visibility of an
     object to the shape of the mask applied to it. In PIXI a regular mask must be a
     PIXI.Graphics or a PIXI.Sprite object. This allows for much faster masking in canvas as it
     utilises shape clipping. To remove a mask, set this property to null.</p>
     */
    external mask : t => unit /* unknown js type: PIXI.Graphics|PIXI.Sprite */ = "" [@@bs.get];
    /*
     <p>Sets a mask for the displayObject. A mask is an object that limits the visibility of an
     object to the shape of the mask applied to it. In PIXI a regular mask must be a
     PIXI.Graphics or a PIXI.Sprite object. This allows for much faster masking in canvas as it
     utilises shape clipping. To remove a mask, set this property to null.</p>
     */
    external setMask : t => unit /* unknown js type: PIXI.Graphics|PIXI.Sprite */ => unit =
      "mask" [@@bs.set];
    /*
     <p>Sets the filters for the displayObject.</p>
     <ul>
     <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
     To remove filters simply set this property to 'null'</li>
     </ul>
     */
    external filters : t => array unit /* unknown js type: PIXI.Filter */ = "" [@@bs.get];
    /*
     <p>Sets the filters for the displayObject.</p>
     <ul>
     <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
     To remove filters simply set this property to 'null'</li>
     </ul>
     */
    external setFilters : t => array unit /* unknown js type: PIXI.Filter */ => unit =
      "filters" [@@bs.set];
    /*
     <p>Set this to true if you want this display object to be cached as a bitmap.
     This basically takes a snap shot of the display object as it is at that moment. It can
     provide a performance benefit for complex static displayObjects.
     To remove simply set this property to 'false'</p>
     <p>IMPORTANT GOTCHA - make sure that all your textures are preloaded BEFORE setting this property to true
     as it will take a snapshot of what is currently there. If the textures have not loaded then they will not appear.</p>
     */
    external cacheAsBitmap : t => Js.boolean = "" [@@bs.get];
    /*
     <p>Set this to true if you want this display object to be cached as a bitmap.
     This basically takes a snap shot of the display object as it is at that moment. It can
     provide a performance benefit for complex static displayObjects.
     To remove simply set this property to 'false'</p>
     <p>IMPORTANT GOTCHA - make sure that all your textures are preloaded BEFORE setting this property to true
     as it will take a snapshot of what is currently there. If the textures have not loaded then they will not appear.</p>
     */
    external setCacheAsBitmap : t => Js.boolean => unit = "cacheAsBitmap" [@@bs.set];
    /*
     <p>Enable interaction events for the DisplayObject. Touch, pointer and mouse
     events will not be emitted unless <code>interactive</code> is set to <code>true</code>.</p>
     */
    external interactive : t => Js.boolean = "" [@@bs.get];
    /*
     <p>Enable interaction events for the DisplayObject. Touch, pointer and mouse
     events will not be emitted unless <code>interactive</code> is set to <code>true</code>.</p>
     */
    external setInteractive : t => Js.boolean => unit = "interactive" [@@bs.set];
    /*
     <p>Interaction shape. Children will be hit first, then this shape will be checked.
     Setting this will cause this shape to be checked in hit tests rather than the displayObject's bounds.</p>
     */
    external hitArea :
      t => unit /* unknown js type: PIXI.Rectangle|PIXI.Circle|PIXI.Ellipse|PIXI.Polygon|PIXI.RoundedRectangle */ =
      "" [@@bs.get];
    /*
     <p>Interaction shape. Children will be hit first, then this shape will be checked.
     Setting this will cause this shape to be checked in hit tests rather than the displayObject's bounds.</p>
     */
    external setHitArea :
      t =>
      unit /* unknown js type: PIXI.Rectangle|PIXI.Circle|PIXI.Ellipse|PIXI.Polygon|PIXI.RoundedRectangle */ =>
      unit =
      "hitArea" [@@bs.set];
    /*
     <p>If enabled, the mouse cursor use the pointer behavior when hovered over the displayObject if it is interactive
     Setting this changes the 'cursor' property to <code>'pointer'</code>.</p>
     */
    external buttonMode : t => Js.boolean = "" [@@bs.get];
    /*
     <p>If enabled, the mouse cursor use the pointer behavior when hovered over the displayObject if it is interactive
     Setting this changes the 'cursor' property to <code>'pointer'</code>.</p>
     */
    external setButtonMode : t => Js.boolean => unit = "buttonMode" [@@bs.set];
    /*
     <p>This defines what cursor mode is used when the mouse cursor
     is hovered over the displayObject.</p>
     */
    external cursor : t => string = "" [@@bs.get];
    /*
     <p>This defines what cursor mode is used when the mouse cursor
     is hovered over the displayObject.</p>
     */
    external setCursor : t => string => unit = "cursor" [@@bs.set];
  };
  module NineSlicePlane = {
    type t;
    /*
     <p>The width of the NineSlicePlane, setting this will actually modify the vertices and UV's of this plane</p>
     */
    external _width : t => int = "" [@@bs.get];
    /*
     <p>The width of the NineSlicePlane, setting this will actually modify the vertices and UV's of this plane</p>
     */
    external set_width : t => int => unit = "_width" [@@bs.set];
    /*
     <p>The height of the NineSlicePlane, setting this will actually modify the vertices and UV's of this plane</p>
     */
    external _height : t => int = "" [@@bs.get];
    /*
     <p>The height of the NineSlicePlane, setting this will actually modify the vertices and UV's of this plane</p>
     */
    external set_height : t => int => unit = "_height" [@@bs.set];
    /*
     <p>The width of the left column</p>
     */
    external leftWidth : t => int = "" [@@bs.get];
    /*
     <p>The width of the left column</p>
     */
    external setLeftWidth : t => int => unit = "leftWidth" [@@bs.set];
    /*
     <p>The width of the right column</p>
     */
    external rightWidth : t => int = "" [@@bs.get];
    /*
     <p>The width of the right column</p>
     */
    external setRightWidth : t => int => unit = "rightWidth" [@@bs.set];
    /*
     <p>The height of the top row</p>
     */
    external topHeight : t => int = "" [@@bs.get];
    /*
     <p>The height of the top row</p>
     */
    external setTopHeight : t => int => unit = "topHeight" [@@bs.set];
    /*
     <p>The height of the bottom row</p>
     */
    external bottomHeight : t => int = "" [@@bs.get];
    /*
     <p>The height of the bottom row</p>
     */
    external setBottomHeight : t => int => unit = "bottomHeight" [@@bs.set];
    /*
     <p>The width of the NineSlicePlane, setting this will actually modify the vertices and UV's of this plane</p>
     */
    external width : t => int = "" [@@bs.get];
    /*
     <p>The width of the NineSlicePlane, setting this will actually modify the vertices and UV's of this plane</p>
     */
    external setWidth : t => int => unit = "width" [@@bs.set];
    /*
     <p>The height of the NineSlicePlane, setting this will actually modify the vertices and UV's of this plane</p>
     */
    external height : t => int = "" [@@bs.get];
    /*
     <p>The height of the NineSlicePlane, setting this will actually modify the vertices and UV's of this plane</p>
     */
    external setHeight : t => int => unit = "height" [@@bs.set];
    /*
     <p>The Uvs of the Mesh</p>
     */
    external uvs : t => unit /* unknown js type: Float32Array */ = "" [@@bs.get];
    /*
     <p>The Uvs of the Mesh</p>
     */
    external setUvs : t => unit /* unknown js type: Float32Array */ => unit = "uvs" [@@bs.set];
    /*
     <p>An array of vertices</p>
     */
    external vertices : t => unit /* unknown js type: Float32Array */ = "" [@@bs.get];
    /*
     <p>An array of vertices</p>
     */
    external setVertices : t => unit /* unknown js type: Float32Array */ => unit =
      "vertices" [@@bs.set];
    /*
     <p>Version of mesh uvs are dirty or not</p>
     */
    external dirty : t => int = "" [@@bs.get];
    /*
     <p>Version of mesh uvs are dirty or not</p>
     */
    external setDirty : t => int => unit = "dirty" [@@bs.set];
    /*
     <p>Version of mesh indices</p>
     */
    external indexDirty : t => int = "" [@@bs.get];
    /*
     <p>Version of mesh indices</p>
     */
    external setIndexDirty : t => int => unit = "indexDirty" [@@bs.set];
    /*
     <p>The blend mode to be applied to the sprite. Set to <code>PIXI.BLEND_MODES.NORMAL</code> to remove
     any blend mode.</p>
     */
    external blendMode : t => int = "" [@@bs.get];
    /*
     <p>The blend mode to be applied to the sprite. Set to <code>PIXI.BLEND_MODES.NORMAL</code> to remove
     any blend mode.</p>
     */
    external setBlendMode : t => int => unit = "blendMode" [@@bs.set];
    /*
     <p>Triangles in canvas mode are automatically antialiased, use this value to force triangles
     to overlap a bit with each other.</p>
     */
    external canvasPadding : t => int = "" [@@bs.get];
    /*
     <p>Triangles in canvas mode are automatically antialiased, use this value to force triangles
     to overlap a bit with each other.</p>
     */
    external setCanvasPadding : t => int => unit = "canvasPadding" [@@bs.set];
    /*
     <p>The way the Mesh should be drawn, can be any of the {@link PIXI.mesh.Mesh.DRAW_MODES} consts</p>
     */
    external drawMode : t => int = "" [@@bs.get];
    /*
     <p>The way the Mesh should be drawn, can be any of the {@link PIXI.mesh.Mesh.DRAW_MODES} consts</p>
     */
    external setDrawMode : t => int => unit = "drawMode" [@@bs.set];
    /*
     <p>The default shader that is used if a mesh doesn't have a more specific one.</p>
     */
    external shader : t => unit /* unknown js type: PIXI.Shader */ = "" [@@bs.get];
    /*
     <p>The default shader that is used if a mesh doesn't have a more specific one.</p>
     */
    external setShader : t => unit /* unknown js type: PIXI.Shader */ => unit =
      "shader" [@@bs.set];
    /*
     <p>The tint applied to the mesh. This is a [r,g,b] value. A value of [1,1,1] will remove any
     tint effect.</p>
     */
    external tintRgb : t => int = "" [@@bs.get];
    /*
     <p>The tint applied to the mesh. This is a [r,g,b] value. A value of [1,1,1] will remove any
     tint effect.</p>
     */
    external setTintRgb : t => int => unit = "tintRgb" [@@bs.set];
    /*
     <p>whether or not upload uvTransform to shader
     if its false, then uvs should be pre-multiplied
     if you change it for generated mesh, please call 'refresh(true)'</p>
     */
    external uploadUvTransform : t => Js.boolean = "" [@@bs.get];
    /*
     <p>whether or not upload uvTransform to shader
     if its false, then uvs should be pre-multiplied
     if you change it for generated mesh, please call 'refresh(true)'</p>
     */
    external setUploadUvTransform : t => Js.boolean => unit = "uploadUvTransform" [@@bs.set];
    /*
     <p>Plugin that is responsible for rendering this element.
     Allows to customize the rendering process without overriding '_renderWebGL' &amp; '_renderCanvas' methods.</p>
     */
    external pluginName : t => string = "" [@@bs.get];
    /*
     <p>Plugin that is responsible for rendering this element.
     Allows to customize the rendering process without overriding '_renderWebGL' &amp; '_renderCanvas' methods.</p>
     */
    external setPluginName : t => string => unit = "pluginName" [@@bs.set];
    /*
     <p>The texture that the mesh uses.</p>
     */
    external texture : t => unit /* unknown js type: PIXI.Texture */ = "" [@@bs.get];
    /*
     <p>The texture that the mesh uses.</p>
     */
    external setTexture : t => unit /* unknown js type: PIXI.Texture */ => unit =
      "texture" [@@bs.set];
    /*
     <p>The tint applied to the mesh. This is a hex value. A value of 0xFFFFFF will remove any tint effect.</p>
     */
    external tint : t => int = "" [@@bs.get];
    /*
     <p>The tint applied to the mesh. This is a hex value. A value of 0xFFFFFF will remove any tint effect.</p>
     */
    external setTint : t => int => unit = "tint" [@@bs.set];
    /*
     <p>The array of children of this container.</p>
     */
    external children : t => array unit /* unknown js type: PIXI.DisplayObject */ = "" [@@bs.get];
    /*
     <p>Determines if the children to the displayObject can be clicked/touched
     Setting this to false allows pixi to bypass a recursive <code>hitTest</code> function</p>
     */
    external interactiveChildren : t => Js.boolean = "" [@@bs.get];
    /*
     <p>Determines if the children to the displayObject can be clicked/touched
     Setting this to false allows pixi to bypass a recursive <code>hitTest</code> function</p>
     */
    external setInteractiveChildren : t => Js.boolean => unit = "interactiveChildren" [@@bs.set];
    /*
     <p>World transform and local transform of this object.
     This will become read-only later, please do not assign anything there unless you know what are you doing</p>
     */
    external transform : t => unit /* unknown js type: PIXI.TransformBase */ = "" [@@bs.get];
    /*
     <p>World transform and local transform of this object.
     This will become read-only later, please do not assign anything there unless you know what are you doing</p>
     */
    external setTransform : t => unit /* unknown js type: PIXI.TransformBase */ => unit =
      "transform" [@@bs.set];
    /*
     <p>The opacity of the object.</p>
     */
    external alpha : t => int = "" [@@bs.get];
    /*
     <p>The opacity of the object.</p>
     */
    external setAlpha : t => int => unit = "alpha" [@@bs.set];
    /*
     <p>The visibility of the object. If false the object will not be drawn, and
     the updateTransform function will not be called.</p>
     <p>Only affects recursive calls from parent. You can ask for bounds or call updateTransform manually</p>
     */
    external visible : t => Js.boolean = "" [@@bs.get];
    /*
     <p>The visibility of the object. If false the object will not be drawn, and
     the updateTransform function will not be called.</p>
     <p>Only affects recursive calls from parent. You can ask for bounds or call updateTransform manually</p>
     */
    external setVisible : t => Js.boolean => unit = "visible" [@@bs.set];
    /*
     <p>Can this object be rendered, if false the object will not be drawn but the updateTransform
     methods will still be called.</p>
     <p>Only affects recursive calls from parent. You can ask for bounds manually</p>
     */
    external renderable : t => Js.boolean = "" [@@bs.get];
    /*
     <p>Can this object be rendered, if false the object will not be drawn but the updateTransform
     methods will still be called.</p>
     <p>Only affects recursive calls from parent. You can ask for bounds manually</p>
     */
    external setRenderable : t => Js.boolean => unit = "renderable" [@@bs.set];
    /*
     <p>The display object container that contains this display object.</p>
     */
    external parent : t => unit /* unknown js type: PIXI.Container */ = "" [@@bs.get];
    /*
     <p>The multiplied alpha of the displayObject</p>
     */
    external worldAlpha : t => int = "" [@@bs.get];
    /*
     <p>The area the filter is applied to. This is used as more of an optimisation
     rather than figuring out the dimensions of the displayObject each frame you can set this rectangle</p>
     <p>Also works as an interaction mask</p>
     */
    external filterArea : t => unit /* unknown js type: PIXI.Rectangle */ = "" [@@bs.get];
    /*
     <p>The area the filter is applied to. This is used as more of an optimisation
     rather than figuring out the dimensions of the displayObject each frame you can set this rectangle</p>
     <p>Also works as an interaction mask</p>
     */
    external setFilterArea : t => unit /* unknown js type: PIXI.Rectangle */ => unit =
      "filterArea" [@@bs.set];
    /*
     <p>The position of the displayObject on the x axis relative to the local coordinates of the parent.
     An alias to position.x</p>
     */
    external x : t => int = "" [@@bs.get];
    /*
     <p>The position of the displayObject on the x axis relative to the local coordinates of the parent.
     An alias to position.x</p>
     */
    external setX : t => int => unit = "x" [@@bs.set];
    /*
     <p>The position of the displayObject on the y axis relative to the local coordinates of the parent.
     An alias to position.y</p>
     */
    external y : t => int = "" [@@bs.get];
    /*
     <p>The position of the displayObject on the y axis relative to the local coordinates of the parent.
     An alias to position.y</p>
     */
    external setY : t => int => unit = "y" [@@bs.set];
    /*
     <p>Current transform of the object based on world (parent) factors</p>
     */
    external worldTransform : t => unit /* unknown js type: PIXI.Matrix */ = "" [@@bs.get];
    /*
     <p>Current transform of the object based on local factors: position, scale, other stuff</p>
     */
    external localTransform : t => unit /* unknown js type: PIXI.Matrix */ = "" [@@bs.get];
    /*
     <p>The coordinate of the object relative to the local coordinates of the parent.
     Assignment by value since pixi-v4.</p>
     */
    external position : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
      "" [@@bs.get];
    /*
     <p>The coordinate of the object relative to the local coordinates of the parent.
     Assignment by value since pixi-v4.</p>
     */
    external setPosition : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
      "position" [@@bs.set];
    /*
     <p>The scale factor of the object.
     Assignment by value since pixi-v4.</p>
     */
    external scale : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
      "" [@@bs.get];
    /*
     <p>The scale factor of the object.
     Assignment by value since pixi-v4.</p>
     */
    external setScale : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
      "scale" [@@bs.set];
    /*
     <p>The pivot point of the displayObject that it rotates around
     Assignment by value since pixi-v4.</p>
     */
    external pivot : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
      "" [@@bs.get];
    /*
     <p>The pivot point of the displayObject that it rotates around
     Assignment by value since pixi-v4.</p>
     */
    external setPivot : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
      "pivot" [@@bs.set];
    /*
     <p>The skew factor for the object in radians.
     Assignment by value since pixi-v4.</p>
     */
    external skew : t => unit /* unknown js type: PIXI.ObservablePoint */ = "" [@@bs.get];
    /*
     <p>The skew factor for the object in radians.
     Assignment by value since pixi-v4.</p>
     */
    external setSkew : t => unit /* unknown js type: PIXI.ObservablePoint */ => unit =
      "skew" [@@bs.set];
    /*
     <p>The rotation of the object in radians.</p>
     */
    external rotation : t => int = "" [@@bs.get];
    /*
     <p>The rotation of the object in radians.</p>
     */
    external setRotation : t => int => unit = "rotation" [@@bs.set];
    /*
     <p>Indicates if the object is globally visible.</p>
     */
    external worldVisible : t => Js.boolean = "" [@@bs.get];
    /*
     <p>Sets a mask for the displayObject. A mask is an object that limits the visibility of an
     object to the shape of the mask applied to it. In PIXI a regular mask must be a
     PIXI.Graphics or a PIXI.Sprite object. This allows for much faster masking in canvas as it
     utilises shape clipping. To remove a mask, set this property to null.</p>
     */
    external mask : t => unit /* unknown js type: PIXI.Graphics|PIXI.Sprite */ = "" [@@bs.get];
    /*
     <p>Sets a mask for the displayObject. A mask is an object that limits the visibility of an
     object to the shape of the mask applied to it. In PIXI a regular mask must be a
     PIXI.Graphics or a PIXI.Sprite object. This allows for much faster masking in canvas as it
     utilises shape clipping. To remove a mask, set this property to null.</p>
     */
    external setMask : t => unit /* unknown js type: PIXI.Graphics|PIXI.Sprite */ => unit =
      "mask" [@@bs.set];
    /*
     <p>Sets the filters for the displayObject.</p>
     <ul>
     <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
     To remove filters simply set this property to 'null'</li>
     </ul>
     */
    external filters : t => array unit /* unknown js type: PIXI.Filter */ = "" [@@bs.get];
    /*
     <p>Sets the filters for the displayObject.</p>
     <ul>
     <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
     To remove filters simply set this property to 'null'</li>
     </ul>
     */
    external setFilters : t => array unit /* unknown js type: PIXI.Filter */ => unit =
      "filters" [@@bs.set];
    /*
     <p>Set this to true if you want this display object to be cached as a bitmap.
     This basically takes a snap shot of the display object as it is at that moment. It can
     provide a performance benefit for complex static displayObjects.
     To remove simply set this property to 'false'</p>
     <p>IMPORTANT GOTCHA - make sure that all your textures are preloaded BEFORE setting this property to true
     as it will take a snapshot of what is currently there. If the textures have not loaded then they will not appear.</p>
     */
    external cacheAsBitmap : t => Js.boolean = "" [@@bs.get];
    /*
     <p>Set this to true if you want this display object to be cached as a bitmap.
     This basically takes a snap shot of the display object as it is at that moment. It can
     provide a performance benefit for complex static displayObjects.
     To remove simply set this property to 'false'</p>
     <p>IMPORTANT GOTCHA - make sure that all your textures are preloaded BEFORE setting this property to true
     as it will take a snapshot of what is currently there. If the textures have not loaded then they will not appear.</p>
     */
    external setCacheAsBitmap : t => Js.boolean => unit = "cacheAsBitmap" [@@bs.set];
    /*
     <p>Enable interaction events for the DisplayObject. Touch, pointer and mouse
     events will not be emitted unless <code>interactive</code> is set to <code>true</code>.</p>
     */
    external interactive : t => Js.boolean = "" [@@bs.get];
    /*
     <p>Enable interaction events for the DisplayObject. Touch, pointer and mouse
     events will not be emitted unless <code>interactive</code> is set to <code>true</code>.</p>
     */
    external setInteractive : t => Js.boolean => unit = "interactive" [@@bs.set];
    /*
     <p>Interaction shape. Children will be hit first, then this shape will be checked.
     Setting this will cause this shape to be checked in hit tests rather than the displayObject's bounds.</p>
     */
    external hitArea :
      t => unit /* unknown js type: PIXI.Rectangle|PIXI.Circle|PIXI.Ellipse|PIXI.Polygon|PIXI.RoundedRectangle */ =
      "" [@@bs.get];
    /*
     <p>Interaction shape. Children will be hit first, then this shape will be checked.
     Setting this will cause this shape to be checked in hit tests rather than the displayObject's bounds.</p>
     */
    external setHitArea :
      t =>
      unit /* unknown js type: PIXI.Rectangle|PIXI.Circle|PIXI.Ellipse|PIXI.Polygon|PIXI.RoundedRectangle */ =>
      unit =
      "hitArea" [@@bs.set];
    /*
     <p>If enabled, the mouse cursor use the pointer behavior when hovered over the displayObject if it is interactive
     Setting this changes the 'cursor' property to <code>'pointer'</code>.</p>
     */
    external buttonMode : t => Js.boolean = "" [@@bs.get];
    /*
     <p>If enabled, the mouse cursor use the pointer behavior when hovered over the displayObject if it is interactive
     Setting this changes the 'cursor' property to <code>'pointer'</code>.</p>
     */
    external setButtonMode : t => Js.boolean => unit = "buttonMode" [@@bs.set];
    /*
     <p>This defines what cursor mode is used when the mouse cursor
     is hovered over the displayObject.</p>
     */
    external cursor : t => string = "" [@@bs.get];
    /*
     <p>This defines what cursor mode is used when the mouse cursor
     is hovered over the displayObject.</p>
     */
    external setCursor : t => string => unit = "cursor" [@@bs.set];
  };
  module Plane = {
    type t;
    /*
     <p>The Uvs of the Mesh</p>
     */
    external uvs : t => unit /* unknown js type: Float32Array */ = "" [@@bs.get];
    /*
     <p>The Uvs of the Mesh</p>
     */
    external setUvs : t => unit /* unknown js type: Float32Array */ => unit = "uvs" [@@bs.set];
    /*
     <p>An array of vertices</p>
     */
    external vertices : t => unit /* unknown js type: Float32Array */ = "" [@@bs.get];
    /*
     <p>An array of vertices</p>
     */
    external setVertices : t => unit /* unknown js type: Float32Array */ => unit =
      "vertices" [@@bs.set];
    /*
     <p>Version of mesh uvs are dirty or not</p>
     */
    external dirty : t => int = "" [@@bs.get];
    /*
     <p>Version of mesh uvs are dirty or not</p>
     */
    external setDirty : t => int => unit = "dirty" [@@bs.set];
    /*
     <p>Version of mesh indices</p>
     */
    external indexDirty : t => int = "" [@@bs.get];
    /*
     <p>Version of mesh indices</p>
     */
    external setIndexDirty : t => int => unit = "indexDirty" [@@bs.set];
    /*
     <p>The blend mode to be applied to the sprite. Set to <code>PIXI.BLEND_MODES.NORMAL</code> to remove
     any blend mode.</p>
     */
    external blendMode : t => int = "" [@@bs.get];
    /*
     <p>The blend mode to be applied to the sprite. Set to <code>PIXI.BLEND_MODES.NORMAL</code> to remove
     any blend mode.</p>
     */
    external setBlendMode : t => int => unit = "blendMode" [@@bs.set];
    /*
     <p>Triangles in canvas mode are automatically antialiased, use this value to force triangles
     to overlap a bit with each other.</p>
     */
    external canvasPadding : t => int = "" [@@bs.get];
    /*
     <p>Triangles in canvas mode are automatically antialiased, use this value to force triangles
     to overlap a bit with each other.</p>
     */
    external setCanvasPadding : t => int => unit = "canvasPadding" [@@bs.set];
    /*
     <p>The way the Mesh should be drawn, can be any of the {@link PIXI.mesh.Mesh.DRAW_MODES} consts</p>
     */
    external drawMode : t => int = "" [@@bs.get];
    /*
     <p>The way the Mesh should be drawn, can be any of the {@link PIXI.mesh.Mesh.DRAW_MODES} consts</p>
     */
    external setDrawMode : t => int => unit = "drawMode" [@@bs.set];
    /*
     <p>The default shader that is used if a mesh doesn't have a more specific one.</p>
     */
    external shader : t => unit /* unknown js type: PIXI.Shader */ = "" [@@bs.get];
    /*
     <p>The default shader that is used if a mesh doesn't have a more specific one.</p>
     */
    external setShader : t => unit /* unknown js type: PIXI.Shader */ => unit =
      "shader" [@@bs.set];
    /*
     <p>The tint applied to the mesh. This is a [r,g,b] value. A value of [1,1,1] will remove any
     tint effect.</p>
     */
    external tintRgb : t => int = "" [@@bs.get];
    /*
     <p>The tint applied to the mesh. This is a [r,g,b] value. A value of [1,1,1] will remove any
     tint effect.</p>
     */
    external setTintRgb : t => int => unit = "tintRgb" [@@bs.set];
    /*
     <p>whether or not upload uvTransform to shader
     if its false, then uvs should be pre-multiplied
     if you change it for generated mesh, please call 'refresh(true)'</p>
     */
    external uploadUvTransform : t => Js.boolean = "" [@@bs.get];
    /*
     <p>whether or not upload uvTransform to shader
     if its false, then uvs should be pre-multiplied
     if you change it for generated mesh, please call 'refresh(true)'</p>
     */
    external setUploadUvTransform : t => Js.boolean => unit = "uploadUvTransform" [@@bs.set];
    /*
     <p>Plugin that is responsible for rendering this element.
     Allows to customize the rendering process without overriding '_renderWebGL' &amp; '_renderCanvas' methods.</p>
     */
    external pluginName : t => string = "" [@@bs.get];
    /*
     <p>Plugin that is responsible for rendering this element.
     Allows to customize the rendering process without overriding '_renderWebGL' &amp; '_renderCanvas' methods.</p>
     */
    external setPluginName : t => string => unit = "pluginName" [@@bs.set];
    /*
     <p>The texture that the mesh uses.</p>
     */
    external texture : t => unit /* unknown js type: PIXI.Texture */ = "" [@@bs.get];
    /*
     <p>The texture that the mesh uses.</p>
     */
    external setTexture : t => unit /* unknown js type: PIXI.Texture */ => unit =
      "texture" [@@bs.set];
    /*
     <p>The tint applied to the mesh. This is a hex value. A value of 0xFFFFFF will remove any tint effect.</p>
     */
    external tint : t => int = "" [@@bs.get];
    /*
     <p>The tint applied to the mesh. This is a hex value. A value of 0xFFFFFF will remove any tint effect.</p>
     */
    external setTint : t => int => unit = "tint" [@@bs.set];
    /*
     <p>The array of children of this container.</p>
     */
    external children : t => array unit /* unknown js type: PIXI.DisplayObject */ = "" [@@bs.get];
    /*
     <p>The width of the Container, setting this will actually modify the scale to achieve the value set</p>
     */
    external width : t => int = "" [@@bs.get];
    /*
     <p>The width of the Container, setting this will actually modify the scale to achieve the value set</p>
     */
    external setWidth : t => int => unit = "width" [@@bs.set];
    /*
     <p>The height of the Container, setting this will actually modify the scale to achieve the value set</p>
     */
    external height : t => int = "" [@@bs.get];
    /*
     <p>The height of the Container, setting this will actually modify the scale to achieve the value set</p>
     */
    external setHeight : t => int => unit = "height" [@@bs.set];
    /*
     <p>Determines if the children to the displayObject can be clicked/touched
     Setting this to false allows pixi to bypass a recursive <code>hitTest</code> function</p>
     */
    external interactiveChildren : t => Js.boolean = "" [@@bs.get];
    /*
     <p>Determines if the children to the displayObject can be clicked/touched
     Setting this to false allows pixi to bypass a recursive <code>hitTest</code> function</p>
     */
    external setInteractiveChildren : t => Js.boolean => unit = "interactiveChildren" [@@bs.set];
    /*
     <p>World transform and local transform of this object.
     This will become read-only later, please do not assign anything there unless you know what are you doing</p>
     */
    external transform : t => unit /* unknown js type: PIXI.TransformBase */ = "" [@@bs.get];
    /*
     <p>World transform and local transform of this object.
     This will become read-only later, please do not assign anything there unless you know what are you doing</p>
     */
    external setTransform : t => unit /* unknown js type: PIXI.TransformBase */ => unit =
      "transform" [@@bs.set];
    /*
     <p>The opacity of the object.</p>
     */
    external alpha : t => int = "" [@@bs.get];
    /*
     <p>The opacity of the object.</p>
     */
    external setAlpha : t => int => unit = "alpha" [@@bs.set];
    /*
     <p>The visibility of the object. If false the object will not be drawn, and
     the updateTransform function will not be called.</p>
     <p>Only affects recursive calls from parent. You can ask for bounds or call updateTransform manually</p>
     */
    external visible : t => Js.boolean = "" [@@bs.get];
    /*
     <p>The visibility of the object. If false the object will not be drawn, and
     the updateTransform function will not be called.</p>
     <p>Only affects recursive calls from parent. You can ask for bounds or call updateTransform manually</p>
     */
    external setVisible : t => Js.boolean => unit = "visible" [@@bs.set];
    /*
     <p>Can this object be rendered, if false the object will not be drawn but the updateTransform
     methods will still be called.</p>
     <p>Only affects recursive calls from parent. You can ask for bounds manually</p>
     */
    external renderable : t => Js.boolean = "" [@@bs.get];
    /*
     <p>Can this object be rendered, if false the object will not be drawn but the updateTransform
     methods will still be called.</p>
     <p>Only affects recursive calls from parent. You can ask for bounds manually</p>
     */
    external setRenderable : t => Js.boolean => unit = "renderable" [@@bs.set];
    /*
     <p>The display object container that contains this display object.</p>
     */
    external parent : t => unit /* unknown js type: PIXI.Container */ = "" [@@bs.get];
    /*
     <p>The multiplied alpha of the displayObject</p>
     */
    external worldAlpha : t => int = "" [@@bs.get];
    /*
     <p>The area the filter is applied to. This is used as more of an optimisation
     rather than figuring out the dimensions of the displayObject each frame you can set this rectangle</p>
     <p>Also works as an interaction mask</p>
     */
    external filterArea : t => unit /* unknown js type: PIXI.Rectangle */ = "" [@@bs.get];
    /*
     <p>The area the filter is applied to. This is used as more of an optimisation
     rather than figuring out the dimensions of the displayObject each frame you can set this rectangle</p>
     <p>Also works as an interaction mask</p>
     */
    external setFilterArea : t => unit /* unknown js type: PIXI.Rectangle */ => unit =
      "filterArea" [@@bs.set];
    /*
     <p>The position of the displayObject on the x axis relative to the local coordinates of the parent.
     An alias to position.x</p>
     */
    external x : t => int = "" [@@bs.get];
    /*
     <p>The position of the displayObject on the x axis relative to the local coordinates of the parent.
     An alias to position.x</p>
     */
    external setX : t => int => unit = "x" [@@bs.set];
    /*
     <p>The position of the displayObject on the y axis relative to the local coordinates of the parent.
     An alias to position.y</p>
     */
    external y : t => int = "" [@@bs.get];
    /*
     <p>The position of the displayObject on the y axis relative to the local coordinates of the parent.
     An alias to position.y</p>
     */
    external setY : t => int => unit = "y" [@@bs.set];
    /*
     <p>Current transform of the object based on world (parent) factors</p>
     */
    external worldTransform : t => unit /* unknown js type: PIXI.Matrix */ = "" [@@bs.get];
    /*
     <p>Current transform of the object based on local factors: position, scale, other stuff</p>
     */
    external localTransform : t => unit /* unknown js type: PIXI.Matrix */ = "" [@@bs.get];
    /*
     <p>The coordinate of the object relative to the local coordinates of the parent.
     Assignment by value since pixi-v4.</p>
     */
    external position : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
      "" [@@bs.get];
    /*
     <p>The coordinate of the object relative to the local coordinates of the parent.
     Assignment by value since pixi-v4.</p>
     */
    external setPosition : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
      "position" [@@bs.set];
    /*
     <p>The scale factor of the object.
     Assignment by value since pixi-v4.</p>
     */
    external scale : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
      "" [@@bs.get];
    /*
     <p>The scale factor of the object.
     Assignment by value since pixi-v4.</p>
     */
    external setScale : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
      "scale" [@@bs.set];
    /*
     <p>The pivot point of the displayObject that it rotates around
     Assignment by value since pixi-v4.</p>
     */
    external pivot : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
      "" [@@bs.get];
    /*
     <p>The pivot point of the displayObject that it rotates around
     Assignment by value since pixi-v4.</p>
     */
    external setPivot : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
      "pivot" [@@bs.set];
    /*
     <p>The skew factor for the object in radians.
     Assignment by value since pixi-v4.</p>
     */
    external skew : t => unit /* unknown js type: PIXI.ObservablePoint */ = "" [@@bs.get];
    /*
     <p>The skew factor for the object in radians.
     Assignment by value since pixi-v4.</p>
     */
    external setSkew : t => unit /* unknown js type: PIXI.ObservablePoint */ => unit =
      "skew" [@@bs.set];
    /*
     <p>The rotation of the object in radians.</p>
     */
    external rotation : t => int = "" [@@bs.get];
    /*
     <p>The rotation of the object in radians.</p>
     */
    external setRotation : t => int => unit = "rotation" [@@bs.set];
    /*
     <p>Indicates if the object is globally visible.</p>
     */
    external worldVisible : t => Js.boolean = "" [@@bs.get];
    /*
     <p>Sets a mask for the displayObject. A mask is an object that limits the visibility of an
     object to the shape of the mask applied to it. In PIXI a regular mask must be a
     PIXI.Graphics or a PIXI.Sprite object. This allows for much faster masking in canvas as it
     utilises shape clipping. To remove a mask, set this property to null.</p>
     */
    external mask : t => unit /* unknown js type: PIXI.Graphics|PIXI.Sprite */ = "" [@@bs.get];
    /*
     <p>Sets a mask for the displayObject. A mask is an object that limits the visibility of an
     object to the shape of the mask applied to it. In PIXI a regular mask must be a
     PIXI.Graphics or a PIXI.Sprite object. This allows for much faster masking in canvas as it
     utilises shape clipping. To remove a mask, set this property to null.</p>
     */
    external setMask : t => unit /* unknown js type: PIXI.Graphics|PIXI.Sprite */ => unit =
      "mask" [@@bs.set];
    /*
     <p>Sets the filters for the displayObject.</p>
     <ul>
     <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
     To remove filters simply set this property to 'null'</li>
     </ul>
     */
    external filters : t => array unit /* unknown js type: PIXI.Filter */ = "" [@@bs.get];
    /*
     <p>Sets the filters for the displayObject.</p>
     <ul>
     <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
     To remove filters simply set this property to 'null'</li>
     </ul>
     */
    external setFilters : t => array unit /* unknown js type: PIXI.Filter */ => unit =
      "filters" [@@bs.set];
    /*
     <p>Set this to true if you want this display object to be cached as a bitmap.
     This basically takes a snap shot of the display object as it is at that moment. It can
     provide a performance benefit for complex static displayObjects.
     To remove simply set this property to 'false'</p>
     <p>IMPORTANT GOTCHA - make sure that all your textures are preloaded BEFORE setting this property to true
     as it will take a snapshot of what is currently there. If the textures have not loaded then they will not appear.</p>
     */
    external cacheAsBitmap : t => Js.boolean = "" [@@bs.get];
    /*
     <p>Set this to true if you want this display object to be cached as a bitmap.
     This basically takes a snap shot of the display object as it is at that moment. It can
     provide a performance benefit for complex static displayObjects.
     To remove simply set this property to 'false'</p>
     <p>IMPORTANT GOTCHA - make sure that all your textures are preloaded BEFORE setting this property to true
     as it will take a snapshot of what is currently there. If the textures have not loaded then they will not appear.</p>
     */
    external setCacheAsBitmap : t => Js.boolean => unit = "cacheAsBitmap" [@@bs.set];
    /*
     <p>Enable interaction events for the DisplayObject. Touch, pointer and mouse
     events will not be emitted unless <code>interactive</code> is set to <code>true</code>.</p>
     */
    external interactive : t => Js.boolean = "" [@@bs.get];
    /*
     <p>Enable interaction events for the DisplayObject. Touch, pointer and mouse
     events will not be emitted unless <code>interactive</code> is set to <code>true</code>.</p>
     */
    external setInteractive : t => Js.boolean => unit = "interactive" [@@bs.set];
    /*
     <p>Interaction shape. Children will be hit first, then this shape will be checked.
     Setting this will cause this shape to be checked in hit tests rather than the displayObject's bounds.</p>
     */
    external hitArea :
      t => unit /* unknown js type: PIXI.Rectangle|PIXI.Circle|PIXI.Ellipse|PIXI.Polygon|PIXI.RoundedRectangle */ =
      "" [@@bs.get];
    /*
     <p>Interaction shape. Children will be hit first, then this shape will be checked.
     Setting this will cause this shape to be checked in hit tests rather than the displayObject's bounds.</p>
     */
    external setHitArea :
      t =>
      unit /* unknown js type: PIXI.Rectangle|PIXI.Circle|PIXI.Ellipse|PIXI.Polygon|PIXI.RoundedRectangle */ =>
      unit =
      "hitArea" [@@bs.set];
    /*
     <p>If enabled, the mouse cursor use the pointer behavior when hovered over the displayObject if it is interactive
     Setting this changes the 'cursor' property to <code>'pointer'</code>.</p>
     */
    external buttonMode : t => Js.boolean = "" [@@bs.get];
    /*
     <p>If enabled, the mouse cursor use the pointer behavior when hovered over the displayObject if it is interactive
     Setting this changes the 'cursor' property to <code>'pointer'</code>.</p>
     */
    external setButtonMode : t => Js.boolean => unit = "buttonMode" [@@bs.set];
    /*
     <p>This defines what cursor mode is used when the mouse cursor
     is hovered over the displayObject.</p>
     */
    external cursor : t => string = "" [@@bs.get];
    /*
     <p>This defines what cursor mode is used when the mouse cursor
     is hovered over the displayObject.</p>
     */
    external setCursor : t => string => unit = "cursor" [@@bs.set];
  };
  module Rope = {
    type t;
    /*
     <p>An array of points that determine the rope</p>
     */
    external points : t => array unit /* unknown js type: PIXI.Point */ = "" [@@bs.get];
    /*
     <p>An array of points that determine the rope</p>
     */
    external setPoints : t => array unit /* unknown js type: PIXI.Point */ => unit =
      "points" [@@bs.set];
    /*
     <p>An array of vertices used to construct this rope.</p>
     */
    external vertices : t => unit /* unknown js type: Float32Array */ = "" [@@bs.get];
    /*
     <p>An array of vertices used to construct this rope.</p>
     */
    external setVertices : t => unit /* unknown js type: Float32Array */ => unit =
      "vertices" [@@bs.set];
    /*
     <p>The WebGL Uvs of the rope.</p>
     */
    external uvs : t => unit /* unknown js type: Float32Array */ = "" [@@bs.get];
    /*
     <p>The WebGL Uvs of the rope.</p>
     */
    external setUvs : t => unit /* unknown js type: Float32Array */ => unit = "uvs" [@@bs.set];
    /*
     <p>An array containing the color components</p>
     */
    external colors : t => unit /* unknown js type: Float32Array */ = "" [@@bs.get];
    /*
     <p>An array containing the color components</p>
     */
    external setColors : t => unit /* unknown js type: Float32Array */ => unit =
      "colors" [@@bs.set];
    /*
     <p>An array containing the indices of the vertices</p>
     */
    external indices : t => unit /* unknown js type: Uint16Array */ = "" [@@bs.get];
    /*
     <p>An array containing the indices of the vertices</p>
     */
    external setIndices : t => unit /* unknown js type: Uint16Array */ => unit =
      "indices" [@@bs.set];
    /*
     <p>refreshes vertices on every updateTransform</p>
     */
    external autoUpdate : t => Js.boolean = "" [@@bs.get];
    /*
     <p>refreshes vertices on every updateTransform</p>
     */
    external setAutoUpdate : t => Js.boolean => unit = "autoUpdate" [@@bs.set];
    /*
     <p>Version of mesh uvs are dirty or not</p>
     */
    external dirty : t => int = "" [@@bs.get];
    /*
     <p>Version of mesh uvs are dirty or not</p>
     */
    external setDirty : t => int => unit = "dirty" [@@bs.set];
    /*
     <p>Version of mesh indices</p>
     */
    external indexDirty : t => int = "" [@@bs.get];
    /*
     <p>Version of mesh indices</p>
     */
    external setIndexDirty : t => int => unit = "indexDirty" [@@bs.set];
    /*
     <p>The blend mode to be applied to the sprite. Set to <code>PIXI.BLEND_MODES.NORMAL</code> to remove
     any blend mode.</p>
     */
    external blendMode : t => int = "" [@@bs.get];
    /*
     <p>The blend mode to be applied to the sprite. Set to <code>PIXI.BLEND_MODES.NORMAL</code> to remove
     any blend mode.</p>
     */
    external setBlendMode : t => int => unit = "blendMode" [@@bs.set];
    /*
     <p>Triangles in canvas mode are automatically antialiased, use this value to force triangles
     to overlap a bit with each other.</p>
     */
    external canvasPadding : t => int = "" [@@bs.get];
    /*
     <p>Triangles in canvas mode are automatically antialiased, use this value to force triangles
     to overlap a bit with each other.</p>
     */
    external setCanvasPadding : t => int => unit = "canvasPadding" [@@bs.set];
    /*
     <p>The way the Mesh should be drawn, can be any of the {@link PIXI.mesh.Mesh.DRAW_MODES} consts</p>
     */
    external drawMode : t => int = "" [@@bs.get];
    /*
     <p>The way the Mesh should be drawn, can be any of the {@link PIXI.mesh.Mesh.DRAW_MODES} consts</p>
     */
    external setDrawMode : t => int => unit = "drawMode" [@@bs.set];
    /*
     <p>The default shader that is used if a mesh doesn't have a more specific one.</p>
     */
    external shader : t => unit /* unknown js type: PIXI.Shader */ = "" [@@bs.get];
    /*
     <p>The default shader that is used if a mesh doesn't have a more specific one.</p>
     */
    external setShader : t => unit /* unknown js type: PIXI.Shader */ => unit =
      "shader" [@@bs.set];
    /*
     <p>The tint applied to the mesh. This is a [r,g,b] value. A value of [1,1,1] will remove any
     tint effect.</p>
     */
    external tintRgb : t => int = "" [@@bs.get];
    /*
     <p>The tint applied to the mesh. This is a [r,g,b] value. A value of [1,1,1] will remove any
     tint effect.</p>
     */
    external setTintRgb : t => int => unit = "tintRgb" [@@bs.set];
    /*
     <p>whether or not upload uvTransform to shader
     if its false, then uvs should be pre-multiplied
     if you change it for generated mesh, please call 'refresh(true)'</p>
     */
    external uploadUvTransform : t => Js.boolean = "" [@@bs.get];
    /*
     <p>whether or not upload uvTransform to shader
     if its false, then uvs should be pre-multiplied
     if you change it for generated mesh, please call 'refresh(true)'</p>
     */
    external setUploadUvTransform : t => Js.boolean => unit = "uploadUvTransform" [@@bs.set];
    /*
     <p>Plugin that is responsible for rendering this element.
     Allows to customize the rendering process without overriding '_renderWebGL' &amp; '_renderCanvas' methods.</p>
     */
    external pluginName : t => string = "" [@@bs.get];
    /*
     <p>Plugin that is responsible for rendering this element.
     Allows to customize the rendering process without overriding '_renderWebGL' &amp; '_renderCanvas' methods.</p>
     */
    external setPluginName : t => string => unit = "pluginName" [@@bs.set];
    /*
     <p>The texture that the mesh uses.</p>
     */
    external texture : t => unit /* unknown js type: PIXI.Texture */ = "" [@@bs.get];
    /*
     <p>The texture that the mesh uses.</p>
     */
    external setTexture : t => unit /* unknown js type: PIXI.Texture */ => unit =
      "texture" [@@bs.set];
    /*
     <p>The tint applied to the mesh. This is a hex value. A value of 0xFFFFFF will remove any tint effect.</p>
     */
    external tint : t => int = "" [@@bs.get];
    /*
     <p>The tint applied to the mesh. This is a hex value. A value of 0xFFFFFF will remove any tint effect.</p>
     */
    external setTint : t => int => unit = "tint" [@@bs.set];
    /*
     <p>The array of children of this container.</p>
     */
    external children : t => array unit /* unknown js type: PIXI.DisplayObject */ = "" [@@bs.get];
    /*
     <p>The width of the Container, setting this will actually modify the scale to achieve the value set</p>
     */
    external width : t => int = "" [@@bs.get];
    /*
     <p>The width of the Container, setting this will actually modify the scale to achieve the value set</p>
     */
    external setWidth : t => int => unit = "width" [@@bs.set];
    /*
     <p>The height of the Container, setting this will actually modify the scale to achieve the value set</p>
     */
    external height : t => int = "" [@@bs.get];
    /*
     <p>The height of the Container, setting this will actually modify the scale to achieve the value set</p>
     */
    external setHeight : t => int => unit = "height" [@@bs.set];
    /*
     <p>Determines if the children to the displayObject can be clicked/touched
     Setting this to false allows pixi to bypass a recursive <code>hitTest</code> function</p>
     */
    external interactiveChildren : t => Js.boolean = "" [@@bs.get];
    /*
     <p>Determines if the children to the displayObject can be clicked/touched
     Setting this to false allows pixi to bypass a recursive <code>hitTest</code> function</p>
     */
    external setInteractiveChildren : t => Js.boolean => unit = "interactiveChildren" [@@bs.set];
    /*
     <p>World transform and local transform of this object.
     This will become read-only later, please do not assign anything there unless you know what are you doing</p>
     */
    external transform : t => unit /* unknown js type: PIXI.TransformBase */ = "" [@@bs.get];
    /*
     <p>World transform and local transform of this object.
     This will become read-only later, please do not assign anything there unless you know what are you doing</p>
     */
    external setTransform : t => unit /* unknown js type: PIXI.TransformBase */ => unit =
      "transform" [@@bs.set];
    /*
     <p>The opacity of the object.</p>
     */
    external alpha : t => int = "" [@@bs.get];
    /*
     <p>The opacity of the object.</p>
     */
    external setAlpha : t => int => unit = "alpha" [@@bs.set];
    /*
     <p>The visibility of the object. If false the object will not be drawn, and
     the updateTransform function will not be called.</p>
     <p>Only affects recursive calls from parent. You can ask for bounds or call updateTransform manually</p>
     */
    external visible : t => Js.boolean = "" [@@bs.get];
    /*
     <p>The visibility of the object. If false the object will not be drawn, and
     the updateTransform function will not be called.</p>
     <p>Only affects recursive calls from parent. You can ask for bounds or call updateTransform manually</p>
     */
    external setVisible : t => Js.boolean => unit = "visible" [@@bs.set];
    /*
     <p>Can this object be rendered, if false the object will not be drawn but the updateTransform
     methods will still be called.</p>
     <p>Only affects recursive calls from parent. You can ask for bounds manually</p>
     */
    external renderable : t => Js.boolean = "" [@@bs.get];
    /*
     <p>Can this object be rendered, if false the object will not be drawn but the updateTransform
     methods will still be called.</p>
     <p>Only affects recursive calls from parent. You can ask for bounds manually</p>
     */
    external setRenderable : t => Js.boolean => unit = "renderable" [@@bs.set];
    /*
     <p>The display object container that contains this display object.</p>
     */
    external parent : t => unit /* unknown js type: PIXI.Container */ = "" [@@bs.get];
    /*
     <p>The multiplied alpha of the displayObject</p>
     */
    external worldAlpha : t => int = "" [@@bs.get];
    /*
     <p>The area the filter is applied to. This is used as more of an optimisation
     rather than figuring out the dimensions of the displayObject each frame you can set this rectangle</p>
     <p>Also works as an interaction mask</p>
     */
    external filterArea : t => unit /* unknown js type: PIXI.Rectangle */ = "" [@@bs.get];
    /*
     <p>The area the filter is applied to. This is used as more of an optimisation
     rather than figuring out the dimensions of the displayObject each frame you can set this rectangle</p>
     <p>Also works as an interaction mask</p>
     */
    external setFilterArea : t => unit /* unknown js type: PIXI.Rectangle */ => unit =
      "filterArea" [@@bs.set];
    /*
     <p>The position of the displayObject on the x axis relative to the local coordinates of the parent.
     An alias to position.x</p>
     */
    external x : t => int = "" [@@bs.get];
    /*
     <p>The position of the displayObject on the x axis relative to the local coordinates of the parent.
     An alias to position.x</p>
     */
    external setX : t => int => unit = "x" [@@bs.set];
    /*
     <p>The position of the displayObject on the y axis relative to the local coordinates of the parent.
     An alias to position.y</p>
     */
    external y : t => int = "" [@@bs.get];
    /*
     <p>The position of the displayObject on the y axis relative to the local coordinates of the parent.
     An alias to position.y</p>
     */
    external setY : t => int => unit = "y" [@@bs.set];
    /*
     <p>Current transform of the object based on world (parent) factors</p>
     */
    external worldTransform : t => unit /* unknown js type: PIXI.Matrix */ = "" [@@bs.get];
    /*
     <p>Current transform of the object based on local factors: position, scale, other stuff</p>
     */
    external localTransform : t => unit /* unknown js type: PIXI.Matrix */ = "" [@@bs.get];
    /*
     <p>The coordinate of the object relative to the local coordinates of the parent.
     Assignment by value since pixi-v4.</p>
     */
    external position : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
      "" [@@bs.get];
    /*
     <p>The coordinate of the object relative to the local coordinates of the parent.
     Assignment by value since pixi-v4.</p>
     */
    external setPosition : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
      "position" [@@bs.set];
    /*
     <p>The scale factor of the object.
     Assignment by value since pixi-v4.</p>
     */
    external scale : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
      "" [@@bs.get];
    /*
     <p>The scale factor of the object.
     Assignment by value since pixi-v4.</p>
     */
    external setScale : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
      "scale" [@@bs.set];
    /*
     <p>The pivot point of the displayObject that it rotates around
     Assignment by value since pixi-v4.</p>
     */
    external pivot : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
      "" [@@bs.get];
    /*
     <p>The pivot point of the displayObject that it rotates around
     Assignment by value since pixi-v4.</p>
     */
    external setPivot : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
      "pivot" [@@bs.set];
    /*
     <p>The skew factor for the object in radians.
     Assignment by value since pixi-v4.</p>
     */
    external skew : t => unit /* unknown js type: PIXI.ObservablePoint */ = "" [@@bs.get];
    /*
     <p>The skew factor for the object in radians.
     Assignment by value since pixi-v4.</p>
     */
    external setSkew : t => unit /* unknown js type: PIXI.ObservablePoint */ => unit =
      "skew" [@@bs.set];
    /*
     <p>The rotation of the object in radians.</p>
     */
    external rotation : t => int = "" [@@bs.get];
    /*
     <p>The rotation of the object in radians.</p>
     */
    external setRotation : t => int => unit = "rotation" [@@bs.set];
    /*
     <p>Indicates if the object is globally visible.</p>
     */
    external worldVisible : t => Js.boolean = "" [@@bs.get];
    /*
     <p>Sets a mask for the displayObject. A mask is an object that limits the visibility of an
     object to the shape of the mask applied to it. In PIXI a regular mask must be a
     PIXI.Graphics or a PIXI.Sprite object. This allows for much faster masking in canvas as it
     utilises shape clipping. To remove a mask, set this property to null.</p>
     */
    external mask : t => unit /* unknown js type: PIXI.Graphics|PIXI.Sprite */ = "" [@@bs.get];
    /*
     <p>Sets a mask for the displayObject. A mask is an object that limits the visibility of an
     object to the shape of the mask applied to it. In PIXI a regular mask must be a
     PIXI.Graphics or a PIXI.Sprite object. This allows for much faster masking in canvas as it
     utilises shape clipping. To remove a mask, set this property to null.</p>
     */
    external setMask : t => unit /* unknown js type: PIXI.Graphics|PIXI.Sprite */ => unit =
      "mask" [@@bs.set];
    /*
     <p>Sets the filters for the displayObject.</p>
     <ul>
     <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
     To remove filters simply set this property to 'null'</li>
     </ul>
     */
    external filters : t => array unit /* unknown js type: PIXI.Filter */ = "" [@@bs.get];
    /*
     <p>Sets the filters for the displayObject.</p>
     <ul>
     <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
     To remove filters simply set this property to 'null'</li>
     </ul>
     */
    external setFilters : t => array unit /* unknown js type: PIXI.Filter */ => unit =
      "filters" [@@bs.set];
    /*
     <p>Set this to true if you want this display object to be cached as a bitmap.
     This basically takes a snap shot of the display object as it is at that moment. It can
     provide a performance benefit for complex static displayObjects.
     To remove simply set this property to 'false'</p>
     <p>IMPORTANT GOTCHA - make sure that all your textures are preloaded BEFORE setting this property to true
     as it will take a snapshot of what is currently there. If the textures have not loaded then they will not appear.</p>
     */
    external cacheAsBitmap : t => Js.boolean = "" [@@bs.get];
    /*
     <p>Set this to true if you want this display object to be cached as a bitmap.
     This basically takes a snap shot of the display object as it is at that moment. It can
     provide a performance benefit for complex static displayObjects.
     To remove simply set this property to 'false'</p>
     <p>IMPORTANT GOTCHA - make sure that all your textures are preloaded BEFORE setting this property to true
     as it will take a snapshot of what is currently there. If the textures have not loaded then they will not appear.</p>
     */
    external setCacheAsBitmap : t => Js.boolean => unit = "cacheAsBitmap" [@@bs.set];
    /*
     <p>Enable interaction events for the DisplayObject. Touch, pointer and mouse
     events will not be emitted unless <code>interactive</code> is set to <code>true</code>.</p>
     */
    external interactive : t => Js.boolean = "" [@@bs.get];
    /*
     <p>Enable interaction events for the DisplayObject. Touch, pointer and mouse
     events will not be emitted unless <code>interactive</code> is set to <code>true</code>.</p>
     */
    external setInteractive : t => Js.boolean => unit = "interactive" [@@bs.set];
    /*
     <p>Interaction shape. Children will be hit first, then this shape will be checked.
     Setting this will cause this shape to be checked in hit tests rather than the displayObject's bounds.</p>
     */
    external hitArea :
      t => unit /* unknown js type: PIXI.Rectangle|PIXI.Circle|PIXI.Ellipse|PIXI.Polygon|PIXI.RoundedRectangle */ =
      "" [@@bs.get];
    /*
     <p>Interaction shape. Children will be hit first, then this shape will be checked.
     Setting this will cause this shape to be checked in hit tests rather than the displayObject's bounds.</p>
     */
    external setHitArea :
      t =>
      unit /* unknown js type: PIXI.Rectangle|PIXI.Circle|PIXI.Ellipse|PIXI.Polygon|PIXI.RoundedRectangle */ =>
      unit =
      "hitArea" [@@bs.set];
    /*
     <p>If enabled, the mouse cursor use the pointer behavior when hovered over the displayObject if it is interactive
     Setting this changes the 'cursor' property to <code>'pointer'</code>.</p>
     */
    external buttonMode : t => Js.boolean = "" [@@bs.get];
    /*
     <p>If enabled, the mouse cursor use the pointer behavior when hovered over the displayObject if it is interactive
     Setting this changes the 'cursor' property to <code>'pointer'</code>.</p>
     */
    external setButtonMode : t => Js.boolean => unit = "buttonMode" [@@bs.set];
    /*
     <p>This defines what cursor mode is used when the mouse cursor
     is hovered over the displayObject.</p>
     */
    external cursor : t => string = "" [@@bs.get];
    /*
     <p>This defines what cursor mode is used when the mouse cursor
     is hovered over the displayObject.</p>
     */
    external setCursor : t => string => unit = "cursor" [@@bs.set];
  };
};

module MeshSpriteRenderer = {
  type t;
};

module MeshRenderer = {
  /*
   <p>constructor for renderer</p>
   */
  type t;
  /*
   <p>The renderer this manager works for.</p>
   */
  external renderer : t => unit /* unknown js type: PIXI.WebGLRenderer */ = "" [@@bs.get];
  /*
   <p>The renderer this manager works for.</p>
   */
  external setRenderer : t => unit /* unknown js type: PIXI.WebGLRenderer */ => unit =
    "renderer" [@@bs.set];
};

module Particles = {
  module ParticleContainer = {
    type t;
    external interactiveChildren : t => Js.boolean = "" [@@bs.get];
    external setInteractiveChildren : t => Js.boolean => unit = "interactiveChildren" [@@bs.set];
    /*
     <p>The blend mode to be applied to the sprite. Apply a value of <code>PIXI.BLEND_MODES.NORMAL</code>
     to reset the blend mode.</p>
     */
    external blendMode : t => int = "" [@@bs.get];
    /*
     <p>The blend mode to be applied to the sprite. Apply a value of <code>PIXI.BLEND_MODES.NORMAL</code>
     to reset the blend mode.</p>
     */
    external setBlendMode : t => int => unit = "blendMode" [@@bs.set];
    /*
     <p>Used for canvas renderering. If true then the elements will be positioned at the
     nearest pixel. This provides a nice speed boost.</p>
     */
    external roundPixels : t => Js.boolean = "" [@@bs.get];
    /*
     <p>Used for canvas renderering. If true then the elements will be positioned at the
     nearest pixel. This provides a nice speed boost.</p>
     */
    external setRoundPixels : t => Js.boolean => unit = "roundPixels" [@@bs.set];
    /*
     <p>The texture used to render the children.</p>
     */
    external baseTexture : t => unit /* unknown js type: BaseTexture */ = "" [@@bs.get];
    /*
     <p>The tint applied to the container. This is a hex value.
     A value of 0xFFFFFF will remove any tint effect.</p>
     <ul>
     <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.</li>
     </ul>
     */
    external tint : t => int = "" [@@bs.get];
    /*
     <p>The tint applied to the container. This is a hex value.
     A value of 0xFFFFFF will remove any tint effect.</p>
     <ul>
     <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.</li>
     </ul>
     */
    external setTint : t => int => unit = "tint" [@@bs.set];
    /*
     <p>The array of children of this container.</p>
     */
    external children : t => array unit /* unknown js type: PIXI.DisplayObject */ = "" [@@bs.get];
    /*
     <p>The width of the Container, setting this will actually modify the scale to achieve the value set</p>
     */
    external width : t => int = "" [@@bs.get];
    /*
     <p>The width of the Container, setting this will actually modify the scale to achieve the value set</p>
     */
    external setWidth : t => int => unit = "width" [@@bs.set];
    /*
     <p>The height of the Container, setting this will actually modify the scale to achieve the value set</p>
     */
    external height : t => int = "" [@@bs.get];
    /*
     <p>The height of the Container, setting this will actually modify the scale to achieve the value set</p>
     */
    external setHeight : t => int => unit = "height" [@@bs.set];
    /*
     <p>World transform and local transform of this object.
     This will become read-only later, please do not assign anything there unless you know what are you doing</p>
     */
    external transform : t => unit /* unknown js type: PIXI.TransformBase */ = "" [@@bs.get];
    /*
     <p>World transform and local transform of this object.
     This will become read-only later, please do not assign anything there unless you know what are you doing</p>
     */
    external setTransform : t => unit /* unknown js type: PIXI.TransformBase */ => unit =
      "transform" [@@bs.set];
    /*
     <p>The opacity of the object.</p>
     */
    external alpha : t => int = "" [@@bs.get];
    /*
     <p>The opacity of the object.</p>
     */
    external setAlpha : t => int => unit = "alpha" [@@bs.set];
    /*
     <p>The visibility of the object. If false the object will not be drawn, and
     the updateTransform function will not be called.</p>
     <p>Only affects recursive calls from parent. You can ask for bounds or call updateTransform manually</p>
     */
    external visible : t => Js.boolean = "" [@@bs.get];
    /*
     <p>The visibility of the object. If false the object will not be drawn, and
     the updateTransform function will not be called.</p>
     <p>Only affects recursive calls from parent. You can ask for bounds or call updateTransform manually</p>
     */
    external setVisible : t => Js.boolean => unit = "visible" [@@bs.set];
    /*
     <p>Can this object be rendered, if false the object will not be drawn but the updateTransform
     methods will still be called.</p>
     <p>Only affects recursive calls from parent. You can ask for bounds manually</p>
     */
    external renderable : t => Js.boolean = "" [@@bs.get];
    /*
     <p>Can this object be rendered, if false the object will not be drawn but the updateTransform
     methods will still be called.</p>
     <p>Only affects recursive calls from parent. You can ask for bounds manually</p>
     */
    external setRenderable : t => Js.boolean => unit = "renderable" [@@bs.set];
    /*
     <p>The display object container that contains this display object.</p>
     */
    external parent : t => unit /* unknown js type: PIXI.Container */ = "" [@@bs.get];
    /*
     <p>The multiplied alpha of the displayObject</p>
     */
    external worldAlpha : t => int = "" [@@bs.get];
    /*
     <p>The area the filter is applied to. This is used as more of an optimisation
     rather than figuring out the dimensions of the displayObject each frame you can set this rectangle</p>
     <p>Also works as an interaction mask</p>
     */
    external filterArea : t => unit /* unknown js type: PIXI.Rectangle */ = "" [@@bs.get];
    /*
     <p>The area the filter is applied to. This is used as more of an optimisation
     rather than figuring out the dimensions of the displayObject each frame you can set this rectangle</p>
     <p>Also works as an interaction mask</p>
     */
    external setFilterArea : t => unit /* unknown js type: PIXI.Rectangle */ => unit =
      "filterArea" [@@bs.set];
    /*
     <p>The position of the displayObject on the x axis relative to the local coordinates of the parent.
     An alias to position.x</p>
     */
    external x : t => int = "" [@@bs.get];
    /*
     <p>The position of the displayObject on the x axis relative to the local coordinates of the parent.
     An alias to position.x</p>
     */
    external setX : t => int => unit = "x" [@@bs.set];
    /*
     <p>The position of the displayObject on the y axis relative to the local coordinates of the parent.
     An alias to position.y</p>
     */
    external y : t => int = "" [@@bs.get];
    /*
     <p>The position of the displayObject on the y axis relative to the local coordinates of the parent.
     An alias to position.y</p>
     */
    external setY : t => int => unit = "y" [@@bs.set];
    /*
     <p>Current transform of the object based on world (parent) factors</p>
     */
    external worldTransform : t => unit /* unknown js type: PIXI.Matrix */ = "" [@@bs.get];
    /*
     <p>Current transform of the object based on local factors: position, scale, other stuff</p>
     */
    external localTransform : t => unit /* unknown js type: PIXI.Matrix */ = "" [@@bs.get];
    /*
     <p>The coordinate of the object relative to the local coordinates of the parent.
     Assignment by value since pixi-v4.</p>
     */
    external position : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
      "" [@@bs.get];
    /*
     <p>The coordinate of the object relative to the local coordinates of the parent.
     Assignment by value since pixi-v4.</p>
     */
    external setPosition : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
      "position" [@@bs.set];
    /*
     <p>The scale factor of the object.
     Assignment by value since pixi-v4.</p>
     */
    external scale : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
      "" [@@bs.get];
    /*
     <p>The scale factor of the object.
     Assignment by value since pixi-v4.</p>
     */
    external setScale : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
      "scale" [@@bs.set];
    /*
     <p>The pivot point of the displayObject that it rotates around
     Assignment by value since pixi-v4.</p>
     */
    external pivot : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
      "" [@@bs.get];
    /*
     <p>The pivot point of the displayObject that it rotates around
     Assignment by value since pixi-v4.</p>
     */
    external setPivot : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
      "pivot" [@@bs.set];
    /*
     <p>The skew factor for the object in radians.
     Assignment by value since pixi-v4.</p>
     */
    external skew : t => unit /* unknown js type: PIXI.ObservablePoint */ = "" [@@bs.get];
    /*
     <p>The skew factor for the object in radians.
     Assignment by value since pixi-v4.</p>
     */
    external setSkew : t => unit /* unknown js type: PIXI.ObservablePoint */ => unit =
      "skew" [@@bs.set];
    /*
     <p>The rotation of the object in radians.</p>
     */
    external rotation : t => int = "" [@@bs.get];
    /*
     <p>The rotation of the object in radians.</p>
     */
    external setRotation : t => int => unit = "rotation" [@@bs.set];
    /*
     <p>Indicates if the object is globally visible.</p>
     */
    external worldVisible : t => Js.boolean = "" [@@bs.get];
    /*
     <p>Sets a mask for the displayObject. A mask is an object that limits the visibility of an
     object to the shape of the mask applied to it. In PIXI a regular mask must be a
     PIXI.Graphics or a PIXI.Sprite object. This allows for much faster masking in canvas as it
     utilises shape clipping. To remove a mask, set this property to null.</p>
     */
    external mask : t => unit /* unknown js type: PIXI.Graphics|PIXI.Sprite */ = "" [@@bs.get];
    /*
     <p>Sets a mask for the displayObject. A mask is an object that limits the visibility of an
     object to the shape of the mask applied to it. In PIXI a regular mask must be a
     PIXI.Graphics or a PIXI.Sprite object. This allows for much faster masking in canvas as it
     utilises shape clipping. To remove a mask, set this property to null.</p>
     */
    external setMask : t => unit /* unknown js type: PIXI.Graphics|PIXI.Sprite */ => unit =
      "mask" [@@bs.set];
    /*
     <p>Sets the filters for the displayObject.</p>
     <ul>
     <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
     To remove filters simply set this property to 'null'</li>
     </ul>
     */
    external filters : t => array unit /* unknown js type: PIXI.Filter */ = "" [@@bs.get];
    /*
     <p>Sets the filters for the displayObject.</p>
     <ul>
     <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
     To remove filters simply set this property to 'null'</li>
     </ul>
     */
    external setFilters : t => array unit /* unknown js type: PIXI.Filter */ => unit =
      "filters" [@@bs.set];
    /*
     <p>Set this to true if you want this display object to be cached as a bitmap.
     This basically takes a snap shot of the display object as it is at that moment. It can
     provide a performance benefit for complex static displayObjects.
     To remove simply set this property to 'false'</p>
     <p>IMPORTANT GOTCHA - make sure that all your textures are preloaded BEFORE setting this property to true
     as it will take a snapshot of what is currently there. If the textures have not loaded then they will not appear.</p>
     */
    external cacheAsBitmap : t => Js.boolean = "" [@@bs.get];
    /*
     <p>Set this to true if you want this display object to be cached as a bitmap.
     This basically takes a snap shot of the display object as it is at that moment. It can
     provide a performance benefit for complex static displayObjects.
     To remove simply set this property to 'false'</p>
     <p>IMPORTANT GOTCHA - make sure that all your textures are preloaded BEFORE setting this property to true
     as it will take a snapshot of what is currently there. If the textures have not loaded then they will not appear.</p>
     */
    external setCacheAsBitmap : t => Js.boolean => unit = "cacheAsBitmap" [@@bs.set];
    /*
     <p>Enable interaction events for the DisplayObject. Touch, pointer and mouse
     events will not be emitted unless <code>interactive</code> is set to <code>true</code>.</p>
     */
    external interactive : t => Js.boolean = "" [@@bs.get];
    /*
     <p>Enable interaction events for the DisplayObject. Touch, pointer and mouse
     events will not be emitted unless <code>interactive</code> is set to <code>true</code>.</p>
     */
    external setInteractive : t => Js.boolean => unit = "interactive" [@@bs.set];
    /*
     <p>Interaction shape. Children will be hit first, then this shape will be checked.
     Setting this will cause this shape to be checked in hit tests rather than the displayObject's bounds.</p>
     */
    external hitArea :
      t => unit /* unknown js type: PIXI.Rectangle|PIXI.Circle|PIXI.Ellipse|PIXI.Polygon|PIXI.RoundedRectangle */ =
      "" [@@bs.get];
    /*
     <p>Interaction shape. Children will be hit first, then this shape will be checked.
     Setting this will cause this shape to be checked in hit tests rather than the displayObject's bounds.</p>
     */
    external setHitArea :
      t =>
      unit /* unknown js type: PIXI.Rectangle|PIXI.Circle|PIXI.Ellipse|PIXI.Polygon|PIXI.RoundedRectangle */ =>
      unit =
      "hitArea" [@@bs.set];
    /*
     <p>If enabled, the mouse cursor use the pointer behavior when hovered over the displayObject if it is interactive
     Setting this changes the 'cursor' property to <code>'pointer'</code>.</p>
     */
    external buttonMode : t => Js.boolean = "" [@@bs.get];
    /*
     <p>If enabled, the mouse cursor use the pointer behavior when hovered over the displayObject if it is interactive
     Setting this changes the 'cursor' property to <code>'pointer'</code>.</p>
     */
    external setButtonMode : t => Js.boolean => unit = "buttonMode" [@@bs.set];
    /*
     <p>This defines what cursor mode is used when the mouse cursor
     is hovered over the displayObject.</p>
     */
    external cursor : t => string = "" [@@bs.get];
    /*
     <p>This defines what cursor mode is used when the mouse cursor
     is hovered over the displayObject.</p>
     */
    external setCursor : t => string => unit = "cursor" [@@bs.set];
  };
};

module ParticleBuffer = {
  type t;
  /*
   <p>The current WebGL drawing context.</p>
   */
  external gl : t => ReasonJs.Gl.glT = "" [@@bs.get];
  /*
   <p>The current WebGL drawing context.</p>
   */
  external setGl : t => ReasonJs.Gl.glT => unit = "gl" [@@bs.set];
  /*
   <p>Size of a single vertex.</p>
   */
  external vertSize : t => int = "" [@@bs.get];
  /*
   <p>Size of a single vertex.</p>
   */
  external setVertSize : t => int => unit = "vertSize" [@@bs.set];
  /*
   <p>Size of a single vertex in bytes.</p>
   */
  external vertByteSize : t => int = "" [@@bs.get];
  /*
   <p>Size of a single vertex in bytes.</p>
   */
  external setVertByteSize : t => int => unit = "vertByteSize" [@@bs.set];
  /*
   <p>The number of particles the buffer can hold</p>
   */
  external size : t => int = "" [@@bs.get];
  /*
   <p>The number of particles the buffer can hold</p>
   */
  external setSize : t => int => unit = "size" [@@bs.set];
  /*
   <p>A list of the properties that are dynamic.</p>
   */
  external dynamicProperties : t => array unit /* unknown js type: object */ = "" [@@bs.get];
  /*
   <p>A list of the properties that are dynamic.</p>
   */
  external setDynamicProperties : t => array unit /* unknown js type: object */ => unit =
    "dynamicProperties" [@@bs.set];
  /*
   <p>A list of the properties that are static.</p>
   */
  external staticProperties : t => array unit /* unknown js type: object */ = "" [@@bs.get];
  /*
   <p>A list of the properties that are static.</p>
   */
  external setStaticProperties : t => array unit /* unknown js type: object */ => unit =
    "staticProperties" [@@bs.set];
  /*
   <p>Holds the indices of the geometry (quads) to draw</p>
   */
  external indices : t => unit /* unknown js type: Uint16Array */ = "" [@@bs.get];
  /*
   <p>Holds the indices of the geometry (quads) to draw</p>
   */
  external setIndices : t => unit /* unknown js type: Uint16Array */ => unit =
    "indices" [@@bs.set];
};

module ParticleRenderer = {
  type t;
  /*
   <p>The default shader that is used if a sprite doesn't have a more specific one.</p>
   */
  external shader : t => unit /* unknown js type: PIXI.Shader */ = "" [@@bs.get];
  /*
   <p>The default shader that is used if a sprite doesn't have a more specific one.</p>
   */
  external setShader : t => unit /* unknown js type: PIXI.Shader */ => unit = "shader" [@@bs.set];
};

module ParticleShader = {
  type t;
};

module Prepare = {
  module BasePrepare = {
    type t;
    /*
     <p>The limiter to be used to control how quickly items are prepared.</p>
     */
    external limiter :
      t => unit /* unknown js type: PIXI.prepare.CountLimiter|PIXI.prepare.TimeLimiter */ =
      "" [@@bs.get];
    /*
     <p>The limiter to be used to control how quickly items are prepared.</p>
     */
    external setLimiter :
      t => unit /* unknown js type: PIXI.prepare.CountLimiter|PIXI.prepare.TimeLimiter */ => unit =
      "limiter" [@@bs.set];
    /*
     <p>Reference to the renderer.</p>
     */
    external renderer : t => unit /* unknown js type: PIXI.SystemRenderer */ = "" [@@bs.get];
    /*
     <p>Reference to the renderer.</p>
     */
    external setRenderer : t => unit /* unknown js type: PIXI.SystemRenderer */ => unit =
      "renderer" [@@bs.set];
    /*
     <p>The only real difference between CanvasPrepare and WebGLPrepare is what they pass
     to upload hooks. That different parameter is stored here.</p>
     */
    external uploadHookHelper :
      t => unit /* unknown js type: PIXI.prepare.CanvasPrepare|PIXI.WebGLRenderer */ =
      "" [@@bs.get];
    /*
     <p>The only real difference between CanvasPrepare and WebGLPrepare is what they pass
     to upload hooks. That different parameter is stored here.</p>
     */
    external setUploadHookHelper :
      t => unit /* unknown js type: PIXI.prepare.CanvasPrepare|PIXI.WebGLRenderer */ => unit =
      "uploadHookHelper" [@@bs.set];
  };
  module CanvasPrepare = {
    type t;
  };
  module WebGLPrepare = {
    type t;
  };
};

module CountLimiter = {
  type t;
};

module TimeLimiter = {
  type t;
};
