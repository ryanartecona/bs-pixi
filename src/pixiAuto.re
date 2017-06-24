module Accessibility = {
  /*
   The Accessibility manager recreates the ability to tab and have content read by screen
   readers. This is very important as it can possibly help people with disabilities access pixi
   content.

   Much like interaction any DisplayObject can be made accessible. This manager will map the
   events as if the mouse was being used, minimizing the effort required to implement.

   An instance of this class is automatically created by default, and can be found at renderer.plugins.accessibility
   */
  module AccessibilityManager = {
    /*
     The Accessibility manager recreates the ability to tab and have content read by screen
     readers. This is very important as it can possibly help people with disabilities access pixi
     content.

     Much like interaction any DisplayObject can be made accessible. This manager will map the
     events as if the mouse was being used, minimizing the effort required to implement.

     An instance of this class is automatically created by default, and can be found at renderer.plugins.accessibility
     */
    type t;
    /*
     Setting this to true will visually show the divs.
     */
    external debug : t => Js.boolean = "" [@@bs.get];
    /*
     Setting this to true will visually show the divs.
     */
    external setDebug : t => Js.boolean => unit = "debug" [@@bs.set];
    /*
     The renderer this accessibility manager works for.
     */
    external renderer : t => SystemRenderer.t = "" [@@bs.get];
    /*
     The renderer this accessibility manager works for.
     */
    external setRenderer : t => SystemRenderer.t => unit = "renderer" [@@bs.set];
  };
};

/*
 Convenience class to create a new PIXI application.
 This class automatically creates the renderer, ticker
 and root container.
 */
module Application = {
  /*
   Convenience class to create a new PIXI application.
   This class automatically creates the renderer, ticker
   and root container.
   */
  type t;
  /*
   The default options, so we mixin functionality later.
   */
  external _options : t => unit /* unknown js type: object */ = "" [@@bs.get];
  /*
   The default options, so we mixin functionality later.
   */
  external set_options : t => unit /* unknown js type: object */ => unit = "_options" [@@bs.set];
  /*
   WebGL renderer if available, otherwise CanvasRenderer
   */
  external renderer : t => unit /* unknown js type: PIXI.WebGLRenderer|PIXI.CanvasRenderer */ =
    "" [@@bs.get];
  /*
   WebGL renderer if available, otherwise CanvasRenderer
   */
  external setRenderer :
    t => unit /* unknown js type: PIXI.WebGLRenderer|PIXI.CanvasRenderer */ => unit =
    "renderer" [@@bs.set];
  /*
   The root display container that's rendered.
   */
  external stage : t => Container.t = "" [@@bs.get];
  /*
   The root display container that's rendered.
   */
  external setStage : t => Container.t => unit = "stage" [@@bs.set];
  /*
   Ticker for doing render updates.
   */
  external ticker : t => Ticker.Ticker.t = "" [@@bs.get];
  /*
   Ticker for doing render updates.
   */
  external setTicker : t => Ticker.Ticker.t => unit = "ticker" [@@bs.set];
  /*
   Reference to the renderer's canvas element.
   */
  external view : t => Dom.element = "" [@@bs.get];
  /*
   Reference to the renderer's screen rectangle. Its safe to use as filterArea or hitArea for whole screen
   */
  external screen : t => Rectangle.t = "" [@@bs.get];
  /*
   Loader instance to help with asset loading.
   */
  external loader : t => Loaders.Loader.t = "" [@@bs.get];
  /*
   Loader instance to help with asset loading.
   */
  external setLoader : t => Loaders.Loader.t => unit = "loader" [@@bs.set];
};

/*
 Wrapper class, webGL Shader for Pixi.
 Adds precision string if vertexSrc or fragmentSrc have no mention of it.
 */
module Shader = {
  /*
   Wrapper class, webGL Shader for Pixi.
   Adds precision string if vertexSrc or fragmentSrc have no mention of it.
   */
  type t;
};

/*
 'Builder' pattern for bounds rectangles
 Axis-Aligned Bounding Box
 It is not a shape! Its mutable thing, no 'EMPTY' or that kind of problems
 */
module Bounds = {
  /*
   'Builder' pattern for bounds rectangles
   Axis-Aligned Bounding Box
   It is not a shape! Its mutable thing, no 'EMPTY' or that kind of problems
   */
  type t;
  external minX : t => float = "" [@@bs.get];
  external setMinX : t => float => unit = "minX" [@@bs.set];
  external minY : t => float = "" [@@bs.get];
  external setMinY : t => float => unit = "minY" [@@bs.set];
  external maxX : t => float = "" [@@bs.get];
  external setMaxX : t => float => unit = "maxX" [@@bs.set];
  external maxY : t => float = "" [@@bs.get];
  external setMaxY : t => float => unit = "maxY" [@@bs.set];
};

/*
 A Container represents a collection of display objects.
 It is the base class of all display objects that act as a container for other objects.

 <pre class="prettyprint source lang-js"><code>let container = new PIXI.Container();
 container.addChild(sprite);</code></pre>
 */
module Container = {
  /*
   A Container represents a collection of display objects.
   It is the base class of all display objects that act as a container for other objects.

   <pre class="prettyprint source lang-js"><code>let container = new PIXI.Container();
   container.addChild(sprite);</code></pre>
   */
  type t;
  /*
   The array of children of this container.
   */
  external children : t => array DisplayObject.t = "" [@@bs.get];
  /*
   The width of the Container, setting this will actually modify the scale to achieve the value set
   */
  external width : t => float = "" [@@bs.get];
  /*
   The width of the Container, setting this will actually modify the scale to achieve the value set
   */
  external setWidth : t => float => unit = "width" [@@bs.set];
  /*
   The height of the Container, setting this will actually modify the scale to achieve the value set
   */
  external height : t => float = "" [@@bs.get];
  /*
   The height of the Container, setting this will actually modify the scale to achieve the value set
   */
  external setHeight : t => float => unit = "height" [@@bs.set];
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
   World transform and local transform of this object.
   This will become read-only later, please do not assign anything there unless you know what are you doing
   */
  external transform : t => TransformBase.t = "" [@@bs.get];
  /*
   World transform and local transform of this object.
   This will become read-only later, please do not assign anything there unless you know what are you doing
   */
  external setTransform : t => TransformBase.t => unit = "transform" [@@bs.set];
  /*
   The opacity of the object.
   */
  external alpha : t => float = "" [@@bs.get];
  /*
   The opacity of the object.
   */
  external setAlpha : t => float => unit = "alpha" [@@bs.set];
  /*
   The visibility of the object. If false the object will not be drawn, and
   the updateTransform function will not be called.

   Only affects recursive calls from parent. You can ask for bounds or call updateTransform manually
   */
  external visible : t => Js.boolean = "" [@@bs.get];
  /*
   The visibility of the object. If false the object will not be drawn, and
   the updateTransform function will not be called.

   Only affects recursive calls from parent. You can ask for bounds or call updateTransform manually
   */
  external setVisible : t => Js.boolean => unit = "visible" [@@bs.set];
  /*
   Can this object be rendered, if false the object will not be drawn but the updateTransform
   methods will still be called.

   Only affects recursive calls from parent. You can ask for bounds manually
   */
  external renderable : t => Js.boolean = "" [@@bs.get];
  /*
   Can this object be rendered, if false the object will not be drawn but the updateTransform
   methods will still be called.

   Only affects recursive calls from parent. You can ask for bounds manually
   */
  external setRenderable : t => Js.boolean => unit = "renderable" [@@bs.set];
  /*
   The display object container that contains this display object.
   */
  external parent : t => Container.t = "" [@@bs.get];
  /*
   The multiplied alpha of the displayObject
   */
  external worldAlpha : t => float = "" [@@bs.get];
  /*
   The area the filter is applied to. This is used as more of an optimisation
   rather than figuring out the dimensions of the displayObject each frame you can set this rectangle

   Also works as an interaction mask
   */
  external filterArea : t => Rectangle.t = "" [@@bs.get];
  /*
   The area the filter is applied to. This is used as more of an optimisation
   rather than figuring out the dimensions of the displayObject each frame you can set this rectangle

   Also works as an interaction mask
   */
  external setFilterArea : t => Rectangle.t => unit = "filterArea" [@@bs.set];
  /*
   The position of the displayObject on the x axis relative to the local coordinates of the parent.
   An alias to position.x
   */
  external x : t => float = "" [@@bs.get];
  /*
   The position of the displayObject on the x axis relative to the local coordinates of the parent.
   An alias to position.x
   */
  external setX : t => float => unit = "x" [@@bs.set];
  /*
   The position of the displayObject on the y axis relative to the local coordinates of the parent.
   An alias to position.y
   */
  external y : t => float = "" [@@bs.get];
  /*
   The position of the displayObject on the y axis relative to the local coordinates of the parent.
   An alias to position.y
   */
  external setY : t => float => unit = "y" [@@bs.set];
  /*
   Current transform of the object based on world (parent) factors
   */
  external worldTransform : t => Matrix.t = "" [@@bs.get];
  /*
   Current transform of the object based on local factors: position, scale, other stuff
   */
  external localTransform : t => Matrix.t = "" [@@bs.get];
  /*
   The coordinate of the object relative to the local coordinates of the parent.
   Assignment by value since pixi-v4.
   */
  external position : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
    "" [@@bs.get];
  /*
   The coordinate of the object relative to the local coordinates of the parent.
   Assignment by value since pixi-v4.
   */
  external setPosition : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
    "position" [@@bs.set];
  /*
   The scale factor of the object.
   Assignment by value since pixi-v4.
   */
  external scale : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
    "" [@@bs.get];
  /*
   The scale factor of the object.
   Assignment by value since pixi-v4.
   */
  external setScale : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
    "scale" [@@bs.set];
  /*
   The pivot point of the displayObject that it rotates around
   Assignment by value since pixi-v4.
   */
  external pivot : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
    "" [@@bs.get];
  /*
   The pivot point of the displayObject that it rotates around
   Assignment by value since pixi-v4.
   */
  external setPivot : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
    "pivot" [@@bs.set];
  /*
   The skew factor for the object in radians.
   Assignment by value since pixi-v4.
   */
  external skew : t => ObservablePoint.t = "" [@@bs.get];
  /*
   The skew factor for the object in radians.
   Assignment by value since pixi-v4.
   */
  external setSkew : t => ObservablePoint.t => unit = "skew" [@@bs.set];
  /*
   The rotation of the object in radians.
   */
  external rotation : t => float = "" [@@bs.get];
  /*
   The rotation of the object in radians.
   */
  external setRotation : t => float => unit = "rotation" [@@bs.set];
  /*
   Indicates if the object is globally visible.
   */
  external worldVisible : t => Js.boolean = "" [@@bs.get];
  /*
   Sets a mask for the displayObject. A mask is an object that limits the visibility of an
   object to the shape of the mask applied to it. In PIXI a regular mask must be a
   PIXI.Graphics or a PIXI.Sprite object. This allows for much faster masking in canvas as it
   utilises shape clipping. To remove a mask, set this property to null.
   */
  external mask : t => unit /* unknown js type: PIXI.Graphics|PIXI.Sprite */ = "" [@@bs.get];
  /*
   Sets a mask for the displayObject. A mask is an object that limits the visibility of an
   object to the shape of the mask applied to it. In PIXI a regular mask must be a
   PIXI.Graphics or a PIXI.Sprite object. This allows for much faster masking in canvas as it
   utilises shape clipping. To remove a mask, set this property to null.
   */
  external setMask : t => unit /* unknown js type: PIXI.Graphics|PIXI.Sprite */ => unit =
    "mask" [@@bs.set];
  /*
   Sets the filters for the displayObject.

   <ul>
   <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
   To remove filters simply set this property to 'null'</li>
   </ul>
   */
  external filters : t => array Filter.t = "" [@@bs.get];
  /*
   Sets the filters for the displayObject.

   <ul>
   <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
   To remove filters simply set this property to 'null'</li>
   </ul>
   */
  external setFilters : t => array Filter.t => unit = "filters" [@@bs.set];
  /*
   Set this to true if you want this display object to be cached as a bitmap.
   This basically takes a snap shot of the display object as it is at that moment. It can
   provide a performance benefit for complex static displayObjects.
   To remove simply set this property to 'false'

   IMPORTANT GOTCHA - make sure that all your textures are preloaded BEFORE setting this property to true
   as it will take a snapshot of what is currently there. If the textures have not loaded then they will not appear.
   */
  external cacheAsBitmap : t => Js.boolean = "" [@@bs.get];
  /*
   Set this to true if you want this display object to be cached as a bitmap.
   This basically takes a snap shot of the display object as it is at that moment. It can
   provide a performance benefit for complex static displayObjects.
   To remove simply set this property to 'false'

   IMPORTANT GOTCHA - make sure that all your textures are preloaded BEFORE setting this property to true
   as it will take a snapshot of what is currently there. If the textures have not loaded then they will not appear.
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
   Interaction shape. Children will be hit first, then this shape will be checked.
   Setting this will cause this shape to be checked in hit tests rather than the displayObject's bounds.
   */
  external hitArea :
    t => unit /* unknown js type: PIXI.Rectangle|PIXI.Circle|PIXI.Ellipse|PIXI.Polygon|PIXI.RoundedRectangle */ =
    "" [@@bs.get];
  /*
   Interaction shape. Children will be hit first, then this shape will be checked.
   Setting this will cause this shape to be checked in hit tests rather than the displayObject's bounds.
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
   This defines what cursor mode is used when the mouse cursor
   is hovered over the displayObject.
   */
  external cursor : t => string = "" [@@bs.get];
  /*
   This defines what cursor mode is used when the mouse cursor
   is hovered over the displayObject.
   */
  external setCursor : t => string => unit = "cursor" [@@bs.set];
};

/*
 The base class for all objects that are rendered on the screen.
 This is an abstract class and should not be used on its own rather it should be extended.
 */
module DisplayObject = {
  /*
   The base class for all objects that are rendered on the screen.
   This is an abstract class and should not be used on its own rather it should be extended.
   */
  type t;
  /*
   World transform and local transform of this object.
   This will become read-only later, please do not assign anything there unless you know what are you doing
   */
  external transform : t => TransformBase.t = "" [@@bs.get];
  /*
   World transform and local transform of this object.
   This will become read-only later, please do not assign anything there unless you know what are you doing
   */
  external setTransform : t => TransformBase.t => unit = "transform" [@@bs.set];
  /*
   The opacity of the object.
   */
  external alpha : t => float = "" [@@bs.get];
  /*
   The opacity of the object.
   */
  external setAlpha : t => float => unit = "alpha" [@@bs.set];
  /*
   The visibility of the object. If false the object will not be drawn, and
   the updateTransform function will not be called.

   Only affects recursive calls from parent. You can ask for bounds or call updateTransform manually
   */
  external visible : t => Js.boolean = "" [@@bs.get];
  /*
   The visibility of the object. If false the object will not be drawn, and
   the updateTransform function will not be called.

   Only affects recursive calls from parent. You can ask for bounds or call updateTransform manually
   */
  external setVisible : t => Js.boolean => unit = "visible" [@@bs.set];
  /*
   Can this object be rendered, if false the object will not be drawn but the updateTransform
   methods will still be called.

   Only affects recursive calls from parent. You can ask for bounds manually
   */
  external renderable : t => Js.boolean = "" [@@bs.get];
  /*
   Can this object be rendered, if false the object will not be drawn but the updateTransform
   methods will still be called.

   Only affects recursive calls from parent. You can ask for bounds manually
   */
  external setRenderable : t => Js.boolean => unit = "renderable" [@@bs.set];
  /*
   The display object container that contains this display object.
   */
  external parent : t => Container.t = "" [@@bs.get];
  /*
   The multiplied alpha of the displayObject
   */
  external worldAlpha : t => float = "" [@@bs.get];
  /*
   The area the filter is applied to. This is used as more of an optimisation
   rather than figuring out the dimensions of the displayObject each frame you can set this rectangle

   Also works as an interaction mask
   */
  external filterArea : t => Rectangle.t = "" [@@bs.get];
  /*
   The area the filter is applied to. This is used as more of an optimisation
   rather than figuring out the dimensions of the displayObject each frame you can set this rectangle

   Also works as an interaction mask
   */
  external setFilterArea : t => Rectangle.t => unit = "filterArea" [@@bs.set];
  /*
   The position of the displayObject on the x axis relative to the local coordinates of the parent.
   An alias to position.x
   */
  external x : t => float = "" [@@bs.get];
  /*
   The position of the displayObject on the x axis relative to the local coordinates of the parent.
   An alias to position.x
   */
  external setX : t => float => unit = "x" [@@bs.set];
  /*
   The position of the displayObject on the y axis relative to the local coordinates of the parent.
   An alias to position.y
   */
  external y : t => float = "" [@@bs.get];
  /*
   The position of the displayObject on the y axis relative to the local coordinates of the parent.
   An alias to position.y
   */
  external setY : t => float => unit = "y" [@@bs.set];
  /*
   Current transform of the object based on world (parent) factors
   */
  external worldTransform : t => Matrix.t = "" [@@bs.get];
  /*
   Current transform of the object based on local factors: position, scale, other stuff
   */
  external localTransform : t => Matrix.t = "" [@@bs.get];
  /*
   The coordinate of the object relative to the local coordinates of the parent.
   Assignment by value since pixi-v4.
   */
  external position : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
    "" [@@bs.get];
  /*
   The coordinate of the object relative to the local coordinates of the parent.
   Assignment by value since pixi-v4.
   */
  external setPosition : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
    "position" [@@bs.set];
  /*
   The scale factor of the object.
   Assignment by value since pixi-v4.
   */
  external scale : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
    "" [@@bs.get];
  /*
   The scale factor of the object.
   Assignment by value since pixi-v4.
   */
  external setScale : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
    "scale" [@@bs.set];
  /*
   The pivot point of the displayObject that it rotates around
   Assignment by value since pixi-v4.
   */
  external pivot : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
    "" [@@bs.get];
  /*
   The pivot point of the displayObject that it rotates around
   Assignment by value since pixi-v4.
   */
  external setPivot : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
    "pivot" [@@bs.set];
  /*
   The skew factor for the object in radians.
   Assignment by value since pixi-v4.
   */
  external skew : t => ObservablePoint.t = "" [@@bs.get];
  /*
   The skew factor for the object in radians.
   Assignment by value since pixi-v4.
   */
  external setSkew : t => ObservablePoint.t => unit = "skew" [@@bs.set];
  /*
   The rotation of the object in radians.
   */
  external rotation : t => float = "" [@@bs.get];
  /*
   The rotation of the object in radians.
   */
  external setRotation : t => float => unit = "rotation" [@@bs.set];
  /*
   Indicates if the object is globally visible.
   */
  external worldVisible : t => Js.boolean = "" [@@bs.get];
  /*
   Sets a mask for the displayObject. A mask is an object that limits the visibility of an
   object to the shape of the mask applied to it. In PIXI a regular mask must be a
   PIXI.Graphics or a PIXI.Sprite object. This allows for much faster masking in canvas as it
   utilises shape clipping. To remove a mask, set this property to null.
   */
  external mask : t => unit /* unknown js type: PIXI.Graphics|PIXI.Sprite */ = "" [@@bs.get];
  /*
   Sets a mask for the displayObject. A mask is an object that limits the visibility of an
   object to the shape of the mask applied to it. In PIXI a regular mask must be a
   PIXI.Graphics or a PIXI.Sprite object. This allows for much faster masking in canvas as it
   utilises shape clipping. To remove a mask, set this property to null.
   */
  external setMask : t => unit /* unknown js type: PIXI.Graphics|PIXI.Sprite */ => unit =
    "mask" [@@bs.set];
  /*
   Sets the filters for the displayObject.

   <ul>
   <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
   To remove filters simply set this property to 'null'</li>
   </ul>
   */
  external filters : t => array Filter.t = "" [@@bs.get];
  /*
   Sets the filters for the displayObject.

   <ul>
   <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
   To remove filters simply set this property to 'null'</li>
   </ul>
   */
  external setFilters : t => array Filter.t => unit = "filters" [@@bs.set];
  /*
   Set this to true if you want this display object to be cached as a bitmap.
   This basically takes a snap shot of the display object as it is at that moment. It can
   provide a performance benefit for complex static displayObjects.
   To remove simply set this property to 'false'

   IMPORTANT GOTCHA - make sure that all your textures are preloaded BEFORE setting this property to true
   as it will take a snapshot of what is currently there. If the textures have not loaded then they will not appear.
   */
  external cacheAsBitmap : t => Js.boolean = "" [@@bs.get];
  /*
   Set this to true if you want this display object to be cached as a bitmap.
   This basically takes a snap shot of the display object as it is at that moment. It can
   provide a performance benefit for complex static displayObjects.
   To remove simply set this property to 'false'

   IMPORTANT GOTCHA - make sure that all your textures are preloaded BEFORE setting this property to true
   as it will take a snapshot of what is currently there. If the textures have not loaded then they will not appear.
   */
  external setCacheAsBitmap : t => Js.boolean => unit = "cacheAsBitmap" [@@bs.set];
  /*
   The instance name of the object.
   */
  external name : t => string = "" [@@bs.get];
  /*
   The instance name of the object.
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
   Interaction shape. Children will be hit first, then this shape will be checked.
   Setting this will cause this shape to be checked in hit tests rather than the displayObject's bounds.
   */
  external hitArea :
    t => unit /* unknown js type: PIXI.Rectangle|PIXI.Circle|PIXI.Ellipse|PIXI.Polygon|PIXI.RoundedRectangle */ =
    "" [@@bs.get];
  /*
   Interaction shape. Children will be hit first, then this shape will be checked.
   Setting this will cause this shape to be checked in hit tests rather than the displayObject's bounds.
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
   This defines what cursor mode is used when the mouse cursor
   is hovered over the displayObject.
   */
  external cursor : t => string = "" [@@bs.get];
  /*
   This defines what cursor mode is used when the mouse cursor
   is hovered over the displayObject.
   */
  external setCursor : t => string => unit = "cursor" [@@bs.set];
};

/*
 Generic class to deal with traditional 2D matrix transforms
 local transformation is calculated from position,scale,skew and rotation
 */
module Transform = {
  /*
   Generic class to deal with traditional 2D matrix transforms
   local transformation is calculated from position,scale,skew and rotation
   */
  type t;
  /*
   The coordinate of the object relative to the local coordinates of the parent.
   */
  external position : t => Point.t = "" [@@bs.get];
  /*
   The coordinate of the object relative to the local coordinates of the parent.
   */
  external setPosition : t => Point.t => unit = "position" [@@bs.set];
  /*
   The scale factor of the object.
   */
  external scale : t => Point.t = "" [@@bs.get];
  /*
   The scale factor of the object.
   */
  external setScale : t => Point.t => unit = "scale" [@@bs.set];
  /*
   The skew amount, on the x and y axis.
   */
  external skew : t => ObservablePoint.t = "" [@@bs.get];
  /*
   The skew amount, on the x and y axis.
   */
  external setSkew : t => ObservablePoint.t => unit = "skew" [@@bs.set];
  /*
   The pivot point of the displayObject that it rotates around
   */
  external pivot : t => Point.t = "" [@@bs.get];
  /*
   The pivot point of the displayObject that it rotates around
   */
  external setPivot : t => Point.t => unit = "pivot" [@@bs.set];
  /*
   The rotation of the object in radians.
   */
  external rotation : t => float = "" [@@bs.get];
  /*
   The rotation of the object in radians.
   */
  external setRotation : t => float => unit = "rotation" [@@bs.set];
  /*
   The global matrix transform. It can be swapped temporarily by some functions like getLocalBounds()
   */
  external worldTransform : t => Matrix.t = "" [@@bs.get];
  /*
   The global matrix transform. It can be swapped temporarily by some functions like getLocalBounds()
   */
  external setWorldTransform : t => Matrix.t => unit = "worldTransform" [@@bs.set];
  /*
   The local matrix transform
   */
  external localTransform : t => Matrix.t = "" [@@bs.get];
  /*
   The local matrix transform
   */
  external setLocalTransform : t => Matrix.t => unit = "localTransform" [@@bs.set];
};

/*
 Generic class to deal with traditional 2D matrix transforms
 */
module TransformBase = {
  /*
   Generic class to deal with traditional 2D matrix transforms
   */
  type t;
  /*
   The global matrix transform. It can be swapped temporarily by some functions like getLocalBounds()
   */
  external worldTransform : t => Matrix.t = "" [@@bs.get];
  /*
   The global matrix transform. It can be swapped temporarily by some functions like getLocalBounds()
   */
  external setWorldTransform : t => Matrix.t => unit = "worldTransform" [@@bs.set];
  /*
   The local matrix transform
   */
  external localTransform : t => Matrix.t = "" [@@bs.get];
  /*
   The local matrix transform
   */
  external setLocalTransform : t => Matrix.t => unit = "localTransform" [@@bs.set];
};

/*
 Transform that takes care about its versions
 */
module TransformStatic = {
  /*
   Transform that takes care about its versions
   */
  type t;
  /*
   The coordinate of the object relative to the local coordinates of the parent.
   */
  external position : t => ObservablePoint.t = "" [@@bs.get];
  /*
   The coordinate of the object relative to the local coordinates of the parent.
   */
  external setPosition : t => ObservablePoint.t => unit = "position" [@@bs.set];
  /*
   The scale factor of the object.
   */
  external scale : t => ObservablePoint.t = "" [@@bs.get];
  /*
   The scale factor of the object.
   */
  external setScale : t => ObservablePoint.t => unit = "scale" [@@bs.set];
  /*
   The pivot point of the displayObject that it rotates around
   */
  external pivot : t => ObservablePoint.t = "" [@@bs.get];
  /*
   The pivot point of the displayObject that it rotates around
   */
  external setPivot : t => ObservablePoint.t => unit = "pivot" [@@bs.set];
  /*
   The skew amount, on the x and y axis.
   */
  external skew : t => ObservablePoint.t = "" [@@bs.get];
  /*
   The skew amount, on the x and y axis.
   */
  external setSkew : t => ObservablePoint.t => unit = "skew" [@@bs.set];
  /*
   The rotation of the object in radians.
   */
  external rotation : t => float = "" [@@bs.get];
  /*
   The rotation of the object in radians.
   */
  external setRotation : t => float => unit = "rotation" [@@bs.set];
  /*
   The global matrix transform. It can be swapped temporarily by some functions like getLocalBounds()
   */
  external worldTransform : t => Matrix.t = "" [@@bs.get];
  /*
   The global matrix transform. It can be swapped temporarily by some functions like getLocalBounds()
   */
  external setWorldTransform : t => Matrix.t => unit = "worldTransform" [@@bs.set];
  /*
   The local matrix transform
   */
  external localTransform : t => Matrix.t = "" [@@bs.get];
  /*
   The local matrix transform
   */
  external setLocalTransform : t => Matrix.t => unit = "localTransform" [@@bs.set];
};

/*
 The Graphics class contains methods used to draw primitive shapes such as lines, circles and
 rectangles to the display, and to color and fill them.
 */
module Graphics = {
  /*
   The Graphics class contains methods used to draw primitive shapes such as lines, circles and
   rectangles to the display, and to color and fill them.
   */
  type t;
  /*
   The alpha value used when filling the Graphics object.
   */
  external fillAlpha : t => float = "" [@@bs.get];
  /*
   The alpha value used when filling the Graphics object.
   */
  external setFillAlpha : t => float => unit = "fillAlpha" [@@bs.set];
  /*
   The width (thickness) of any lines drawn.
   */
  external lineWidth : t => float = "" [@@bs.get];
  /*
   The width (thickness) of any lines drawn.
   */
  external setLineWidth : t => float => unit = "lineWidth" [@@bs.set];
  /*
   If true the lines will be draw using LINES instead of TRIANGLE_STRIP
   */
  external nativeLines : t => Js.boolean = "" [@@bs.get];
  /*
   If true the lines will be draw using LINES instead of TRIANGLE_STRIP
   */
  external setNativeLines : t => Js.boolean => unit = "nativeLines" [@@bs.set];
  /*
   The color of any lines drawn.
   */
  external lineColor : t => string = "" [@@bs.get];
  /*
   The color of any lines drawn.
   */
  external setLineColor : t => string => unit = "lineColor" [@@bs.set];
  /*
   The tint applied to the graphic shape. This is a hex value. Apply a value of 0xFFFFFF to
   reset the tint.
   */
  external tint : t => float = "" [@@bs.get];
  /*
   The tint applied to the graphic shape. This is a hex value. Apply a value of 0xFFFFFF to
   reset the tint.
   */
  external setTint : t => float => unit = "tint" [@@bs.set];
  /*
   <p>The blend mode to be applied to the graphic shape. Apply a value of
   <code>PIXI.BLEND_MODES.NORMAL</code> to reset the blend mode.</p>
   */
  external blendMode : t => float = "" [@@bs.get];
  /*
   <p>The blend mode to be applied to the graphic shape. Apply a value of
   <code>PIXI.BLEND_MODES.NORMAL</code> to reset the blend mode.</p>
   */
  external setBlendMode : t => float => unit = "blendMode" [@@bs.set];
  /*
   Whether this shape is being used as a mask.
   */
  external isMask : t => Js.boolean = "" [@@bs.get];
  /*
   Whether this shape is being used as a mask.
   */
  external setIsMask : t => Js.boolean => unit = "isMask" [@@bs.set];
  /*
   The bounds' padding used for bounds calculation.
   */
  external boundsPadding : t => float = "" [@@bs.get];
  /*
   The bounds' padding used for bounds calculation.
   */
  external setBoundsPadding : t => float => unit = "boundsPadding" [@@bs.set];
  /*
   Used to detect if we need to do a fast rect check using the id compare method
   */
  external fastRectDirty : t => float = "" [@@bs.get];
  /*
   Used to detect if we need to do a fast rect check using the id compare method
   */
  external setFastRectDirty : t => float => unit = "fastRectDirty" [@@bs.set];
  /*
   Used to detect if we clear the graphics webGL data
   */
  external clearDirty : t => float = "" [@@bs.get];
  /*
   Used to detect if we clear the graphics webGL data
   */
  external setClearDirty : t => float => unit = "clearDirty" [@@bs.set];
  /*
   Used to detect if we we need to recalculate local bounds
   */
  external boundsDirty : t => float = "" [@@bs.get];
  /*
   Used to detect if we we need to recalculate local bounds
   */
  external setBoundsDirty : t => float => unit = "boundsDirty" [@@bs.set];
  /*
   When cacheAsBitmap is set to true the graphics object will be rendered as if it was a sprite.
   This is useful if your graphics element does not change often, as it will speed up the rendering
   of the object in exchange for taking up texture memory. It is also useful if you need the graphics
   object to be anti-aliased, because it will be rendered using canvas. This is not recommended if
   you are constantly redrawing the graphics element.
   */
  external cacheAsBitmap : t => Js.boolean = "" [@@bs.get];
  /*
   When cacheAsBitmap is set to true the graphics object will be rendered as if it was a sprite.
   This is useful if your graphics element does not change often, as it will speed up the rendering
   of the object in exchange for taking up texture memory. It is also useful if you need the graphics
   object to be anti-aliased, because it will be rendered using canvas. This is not recommended if
   you are constantly redrawing the graphics element.
   */
  external setCacheAsBitmap : t => Js.boolean => unit = "cacheAsBitmap" [@@bs.set];
  /*
   The array of children of this container.
   */
  external children : t => array DisplayObject.t = "" [@@bs.get];
  /*
   The width of the Container, setting this will actually modify the scale to achieve the value set
   */
  external width : t => float = "" [@@bs.get];
  /*
   The width of the Container, setting this will actually modify the scale to achieve the value set
   */
  external setWidth : t => float => unit = "width" [@@bs.set];
  /*
   The height of the Container, setting this will actually modify the scale to achieve the value set
   */
  external height : t => float = "" [@@bs.get];
  /*
   The height of the Container, setting this will actually modify the scale to achieve the value set
   */
  external setHeight : t => float => unit = "height" [@@bs.set];
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
   World transform and local transform of this object.
   This will become read-only later, please do not assign anything there unless you know what are you doing
   */
  external transform : t => TransformBase.t = "" [@@bs.get];
  /*
   World transform and local transform of this object.
   This will become read-only later, please do not assign anything there unless you know what are you doing
   */
  external setTransform : t => TransformBase.t => unit = "transform" [@@bs.set];
  /*
   The opacity of the object.
   */
  external alpha : t => float = "" [@@bs.get];
  /*
   The opacity of the object.
   */
  external setAlpha : t => float => unit = "alpha" [@@bs.set];
  /*
   The visibility of the object. If false the object will not be drawn, and
   the updateTransform function will not be called.

   Only affects recursive calls from parent. You can ask for bounds or call updateTransform manually
   */
  external visible : t => Js.boolean = "" [@@bs.get];
  /*
   The visibility of the object. If false the object will not be drawn, and
   the updateTransform function will not be called.

   Only affects recursive calls from parent. You can ask for bounds or call updateTransform manually
   */
  external setVisible : t => Js.boolean => unit = "visible" [@@bs.set];
  /*
   Can this object be rendered, if false the object will not be drawn but the updateTransform
   methods will still be called.

   Only affects recursive calls from parent. You can ask for bounds manually
   */
  external renderable : t => Js.boolean = "" [@@bs.get];
  /*
   Can this object be rendered, if false the object will not be drawn but the updateTransform
   methods will still be called.

   Only affects recursive calls from parent. You can ask for bounds manually
   */
  external setRenderable : t => Js.boolean => unit = "renderable" [@@bs.set];
  /*
   The display object container that contains this display object.
   */
  external parent : t => Container.t = "" [@@bs.get];
  /*
   The multiplied alpha of the displayObject
   */
  external worldAlpha : t => float = "" [@@bs.get];
  /*
   The area the filter is applied to. This is used as more of an optimisation
   rather than figuring out the dimensions of the displayObject each frame you can set this rectangle

   Also works as an interaction mask
   */
  external filterArea : t => Rectangle.t = "" [@@bs.get];
  /*
   The area the filter is applied to. This is used as more of an optimisation
   rather than figuring out the dimensions of the displayObject each frame you can set this rectangle

   Also works as an interaction mask
   */
  external setFilterArea : t => Rectangle.t => unit = "filterArea" [@@bs.set];
  /*
   The position of the displayObject on the x axis relative to the local coordinates of the parent.
   An alias to position.x
   */
  external x : t => float = "" [@@bs.get];
  /*
   The position of the displayObject on the x axis relative to the local coordinates of the parent.
   An alias to position.x
   */
  external setX : t => float => unit = "x" [@@bs.set];
  /*
   The position of the displayObject on the y axis relative to the local coordinates of the parent.
   An alias to position.y
   */
  external y : t => float = "" [@@bs.get];
  /*
   The position of the displayObject on the y axis relative to the local coordinates of the parent.
   An alias to position.y
   */
  external setY : t => float => unit = "y" [@@bs.set];
  /*
   Current transform of the object based on world (parent) factors
   */
  external worldTransform : t => Matrix.t = "" [@@bs.get];
  /*
   Current transform of the object based on local factors: position, scale, other stuff
   */
  external localTransform : t => Matrix.t = "" [@@bs.get];
  /*
   The coordinate of the object relative to the local coordinates of the parent.
   Assignment by value since pixi-v4.
   */
  external position : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
    "" [@@bs.get];
  /*
   The coordinate of the object relative to the local coordinates of the parent.
   Assignment by value since pixi-v4.
   */
  external setPosition : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
    "position" [@@bs.set];
  /*
   The scale factor of the object.
   Assignment by value since pixi-v4.
   */
  external scale : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
    "" [@@bs.get];
  /*
   The scale factor of the object.
   Assignment by value since pixi-v4.
   */
  external setScale : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
    "scale" [@@bs.set];
  /*
   The pivot point of the displayObject that it rotates around
   Assignment by value since pixi-v4.
   */
  external pivot : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
    "" [@@bs.get];
  /*
   The pivot point of the displayObject that it rotates around
   Assignment by value since pixi-v4.
   */
  external setPivot : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
    "pivot" [@@bs.set];
  /*
   The skew factor for the object in radians.
   Assignment by value since pixi-v4.
   */
  external skew : t => ObservablePoint.t = "" [@@bs.get];
  /*
   The skew factor for the object in radians.
   Assignment by value since pixi-v4.
   */
  external setSkew : t => ObservablePoint.t => unit = "skew" [@@bs.set];
  /*
   The rotation of the object in radians.
   */
  external rotation : t => float = "" [@@bs.get];
  /*
   The rotation of the object in radians.
   */
  external setRotation : t => float => unit = "rotation" [@@bs.set];
  /*
   Indicates if the object is globally visible.
   */
  external worldVisible : t => Js.boolean = "" [@@bs.get];
  /*
   Sets a mask for the displayObject. A mask is an object that limits the visibility of an
   object to the shape of the mask applied to it. In PIXI a regular mask must be a
   PIXI.Graphics or a PIXI.Sprite object. This allows for much faster masking in canvas as it
   utilises shape clipping. To remove a mask, set this property to null.
   */
  external mask : t => unit /* unknown js type: PIXI.Graphics|PIXI.Sprite */ = "" [@@bs.get];
  /*
   Sets a mask for the displayObject. A mask is an object that limits the visibility of an
   object to the shape of the mask applied to it. In PIXI a regular mask must be a
   PIXI.Graphics or a PIXI.Sprite object. This allows for much faster masking in canvas as it
   utilises shape clipping. To remove a mask, set this property to null.
   */
  external setMask : t => unit /* unknown js type: PIXI.Graphics|PIXI.Sprite */ => unit =
    "mask" [@@bs.set];
  /*
   Sets the filters for the displayObject.

   <ul>
   <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
   To remove filters simply set this property to 'null'</li>
   </ul>
   */
  external filters : t => array Filter.t = "" [@@bs.get];
  /*
   Sets the filters for the displayObject.

   <ul>
   <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
   To remove filters simply set this property to 'null'</li>
   </ul>
   */
  external setFilters : t => array Filter.t => unit = "filters" [@@bs.set];
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
   Interaction shape. Children will be hit first, then this shape will be checked.
   Setting this will cause this shape to be checked in hit tests rather than the displayObject's bounds.
   */
  external hitArea :
    t => unit /* unknown js type: PIXI.Rectangle|PIXI.Circle|PIXI.Ellipse|PIXI.Polygon|PIXI.RoundedRectangle */ =
    "" [@@bs.get];
  /*
   Interaction shape. Children will be hit first, then this shape will be checked.
   Setting this will cause this shape to be checked in hit tests rather than the displayObject's bounds.
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
   This defines what cursor mode is used when the mouse cursor
   is hovered over the displayObject.
   */
  external cursor : t => string = "" [@@bs.get];
  /*
   This defines what cursor mode is used when the mouse cursor
   is hovered over the displayObject.
   */
  external setCursor : t => string => unit = "cursor" [@@bs.set];
};

/*
 A GraphicsData object.
 */
module GraphicsData = {
  /*
   A GraphicsData object.
   */
  type t;
};

/*
 Renders the graphics object.
 */
module GraphicsRenderer = {
  /*
   Renders the graphics object.
   */
  type t;
  /*
   The renderer this manager works for.
   */
  external renderer : t => WebGLRenderer.t = "" [@@bs.get];
  /*
   The renderer this manager works for.
   */
  external setRenderer : t => WebGLRenderer.t => unit = "renderer" [@@bs.set];
};

/*
 This shader is used to draw simple primitive shapes for {@link PIXI.Graphics}.
 */
module PrimitiveShader = {
  /*
   This shader is used to draw simple primitive shapes for {@link PIXI.Graphics}.
   */
  type t;
};

module GroupD8 = {
  type t;
};

/*
 The pixi Matrix class as an object, which makes it a lot faster,
 here is a representation of it :
 | a | b | tx|
 | c | d | ty|
 | 0 | 0 | 1 |
 */
module Matrix = {
  /*
   The pixi Matrix class as an object, which makes it a lot faster,
   here is a representation of it :
   | a | b | tx|
   | c | d | ty|
   | 0 | 0 | 1 |
   */
  type t;
  external a : t => float = "" [@@bs.get];
  external setA : t => float => unit = "a" [@@bs.set];
  external b : t => float = "" [@@bs.get];
  external setB : t => float => unit = "b" [@@bs.set];
  external c : t => float = "" [@@bs.get];
  external setC : t => float => unit = "c" [@@bs.set];
  external d : t => float = "" [@@bs.get];
  external setD : t => float => unit = "d" [@@bs.set];
  external tx : t => float = "" [@@bs.get];
  external setTx : t => float => unit = "tx" [@@bs.set];
  external ty : t => float = "" [@@bs.get];
  external setTy : t => float => unit = "ty" [@@bs.set];
};

/*
 The Point object represents a location in a two-dimensional coordinate system, where x represents
 the horizontal axis and y represents the vertical axis.
 An observable point is a point that triggers a callback when the point's position is changed.
 */
module ObservablePoint = {
  /*
   The Point object represents a location in a two-dimensional coordinate system, where x represents
   the horizontal axis and y represents the vertical axis.
   An observable point is a point that triggers a callback when the point's position is changed.
   */
  type t;
  /*
   The position of the displayObject on the x axis relative to the local coordinates of the parent.
   */
  external x : t => float = "" [@@bs.get];
  /*
   The position of the displayObject on the x axis relative to the local coordinates of the parent.
   */
  external setX : t => float => unit = "x" [@@bs.set];
  /*
   The position of the displayObject on the x axis relative to the local coordinates of the parent.
   */
  external y : t => float = "" [@@bs.get];
  /*
   The position of the displayObject on the x axis relative to the local coordinates of the parent.
   */
  external setY : t => float => unit = "y" [@@bs.set];
};

/*
 The Point object represents a location in a two-dimensional coordinate system, where x represents
 the horizontal axis and y represents the vertical axis.
 */
module Point = {
  /*
   The Point object represents a location in a two-dimensional coordinate system, where x represents
   the horizontal axis and y represents the vertical axis.
   */
  type t;
  external x : t => float = "" [@@bs.get];
  external setX : t => float => unit = "x" [@@bs.set];
  external y : t => float = "" [@@bs.get];
  external setY : t => float => unit = "y" [@@bs.set];
};

/*
 The Circle object can be used to specify a hit area for displayObjects
 */
module Circle = {
  /*
   The Circle object can be used to specify a hit area for displayObjects
   */
  type t;
  external x : t => float = "" [@@bs.get];
  external setX : t => float => unit = "x" [@@bs.set];
  external y : t => float = "" [@@bs.get];
  external setY : t => float => unit = "y" [@@bs.set];
  external radius : t => float = "" [@@bs.get];
  external setRadius : t => float => unit = "radius" [@@bs.set];
  /*
   <p>The type of the object, mainly used to avoid <code>instanceof</code> checks</p>
   */
  external type_ : t => float = "type" [@@bs.get];
};

/*
 The Ellipse object can be used to specify a hit area for displayObjects
 */
module Ellipse = {
  /*
   The Ellipse object can be used to specify a hit area for displayObjects
   */
  type t;
  external x : t => float = "" [@@bs.get];
  external setX : t => float => unit = "x" [@@bs.set];
  external y : t => float = "" [@@bs.get];
  external setY : t => float => unit = "y" [@@bs.set];
  external width : t => float = "" [@@bs.get];
  external setWidth : t => float => unit = "width" [@@bs.set];
  external height : t => float = "" [@@bs.get];
  external setHeight : t => float => unit = "height" [@@bs.set];
  /*
   <p>The type of the object, mainly used to avoid <code>instanceof</code> checks</p>
   */
  external type_ : t => float = "type" [@@bs.get];
};

module Polygon = {
  type t;
  /*
   An array of the points of this polygon
   */
  external points : t => array float = "" [@@bs.get];
  /*
   An array of the points of this polygon
   */
  external setPoints : t => array float => unit = "points" [@@bs.set];
  /*
   <p>The type of the object, mainly used to avoid <code>instanceof</code> checks</p>
   */
  external type_ : t => float = "type" [@@bs.get];
};

/*
 Rectangle object is an area defined by its position, as indicated by its top-left corner
 point (x, y) and by its width and its height.
 */
module Rectangle = {
  /*
   Rectangle object is an area defined by its position, as indicated by its top-left corner
   point (x, y) and by its width and its height.
   */
  type t;
  external x : t => float = "" [@@bs.get];
  external setX : t => float => unit = "x" [@@bs.set];
  external y : t => float = "" [@@bs.get];
  external setY : t => float => unit = "y" [@@bs.set];
  external width : t => float = "" [@@bs.get];
  external setWidth : t => float => unit = "width" [@@bs.set];
  external height : t => float = "" [@@bs.get];
  external setHeight : t => float => unit = "height" [@@bs.set];
  /*
   <p>The type of the object, mainly used to avoid <code>instanceof</code> checks</p>
   */
  external type_ : t => float = "type" [@@bs.get];
  /*
   returns the left edge of the rectangle
   */
  external left : t => float = "" [@@bs.get];
  /*
   returns the left edge of the rectangle
   */
  external setLeft : t => float => unit = "left" [@@bs.set];
  /*
   returns the right edge of the rectangle
   */
  external right : t => float = "" [@@bs.get];
  /*
   returns the right edge of the rectangle
   */
  external setRight : t => float => unit = "right" [@@bs.set];
  /*
   returns the top edge of the rectangle
   */
  external top : t => float = "" [@@bs.get];
  /*
   returns the top edge of the rectangle
   */
  external setTop : t => float => unit = "top" [@@bs.set];
  /*
   returns the bottom edge of the rectangle
   */
  external bottom : t => float = "" [@@bs.get];
  /*
   returns the bottom edge of the rectangle
   */
  external setBottom : t => float => unit = "bottom" [@@bs.set];
};

/*
 The Rounded Rectangle object is an area that has nice rounded corners, as indicated by its
 top-left corner point (x, y) and by its width and its height and its radius.
 */
module RoundedRectangle = {
  /*
   The Rounded Rectangle object is an area that has nice rounded corners, as indicated by its
   top-left corner point (x, y) and by its width and its height and its radius.
   */
  type t;
  external x : t => float = "" [@@bs.get];
  external setX : t => float => unit = "x" [@@bs.set];
  external y : t => float = "" [@@bs.get];
  external setY : t => float => unit = "y" [@@bs.set];
  external width : t => float = "" [@@bs.get];
  external setWidth : t => float => unit = "width" [@@bs.set];
  external height : t => float = "" [@@bs.get];
  external setHeight : t => float => unit = "height" [@@bs.set];
  external radius : t => float = "" [@@bs.get];
  external setRadius : t => float => unit = "radius" [@@bs.set];
  /*
   <p>The type of the object, mainly used to avoid <code>instanceof</code> checks</p>
   */
  external type_ : t => float = "type" [@@bs.get];
};

/*
 The SystemRenderer is the base for a Pixi Renderer. It is extended by the {@link PIXI.CanvasRenderer}
 and {@link PIXI.WebGLRenderer} which can be used for rendering a Pixi scene.
 */
module SystemRenderer = {
  /*
   The SystemRenderer is the base for a Pixi Renderer. It is extended by the {@link PIXI.CanvasRenderer}
   and {@link PIXI.WebGLRenderer} which can be used for rendering a Pixi scene.
   */
  type t;
  /*
   The supplied constructor options.
   */
  external options : t => unit /* unknown js type: Object */ = "" [@@bs.get];
  /*
   The type of the renderer.
   */
  external type_ : t => float = "type" [@@bs.get];
  /*
   The type of the renderer.
   */
  external setType : t => float => unit = "type" [@@bs.set];
  /*
   Measurements of the screen. (0, 0, screenWidth, screenHeight)

   Its safe to use as filterArea or hitArea for whole stage
   */
  external screen : t => Rectangle.t = "" [@@bs.get];
  /*
   Measurements of the screen. (0, 0, screenWidth, screenHeight)

   Its safe to use as filterArea or hitArea for whole stage
   */
  external setScreen : t => Rectangle.t => unit = "screen" [@@bs.set];
  /*
   The canvas element that everything is drawn to
   */
  external view : t => Dom.element = "" [@@bs.get];
  /*
   The canvas element that everything is drawn to
   */
  external setView : t => Dom.element => unit = "view" [@@bs.set];
  /*
   The resolution / device pixel ratio of the renderer
   */
  external resolution : t => float = "" [@@bs.get];
  /*
   The resolution / device pixel ratio of the renderer
   */
  external setResolution : t => float => unit = "resolution" [@@bs.set];
  /*
   Whether the render view is transparent
   */
  external transparent : t => Js.boolean = "" [@@bs.get];
  /*
   Whether the render view is transparent
   */
  external setTransparent : t => Js.boolean => unit = "transparent" [@@bs.set];
  /*
   Whether css dimensions of canvas view should be resized to screen dimensions automatically
   */
  external autoResize : t => Js.boolean = "" [@@bs.get];
  /*
   Whether css dimensions of canvas view should be resized to screen dimensions automatically
   */
  external setAutoResize : t => Js.boolean => unit = "autoResize" [@@bs.set];
  /*
   Tracks the blend modes useful for this renderer.
   */
  external blendModes : t => unit /* unknown js type: object.<string, mixed> */ = "" [@@bs.get];
  /*
   Tracks the blend modes useful for this renderer.
   */
  external setBlendModes : t => unit /* unknown js type: object.<string, mixed> */ => unit =
    "blendModes" [@@bs.set];
  /*
   The value of the preserveDrawingBuffer flag affects whether or not the contents of
   the stencil buffer is retained after rendering.
   */
  external preserveDrawingBuffer : t => Js.boolean = "" [@@bs.get];
  /*
   The value of the preserveDrawingBuffer flag affects whether or not the contents of
   the stencil buffer is retained after rendering.
   */
  external setPreserveDrawingBuffer : t => Js.boolean => unit = "preserveDrawingBuffer" [@@bs.set];
  /*
   This sets if the CanvasRenderer will clear the canvas or not before the new render pass.
   If the scene is NOT transparent Pixi will use a canvas sized fillRect operation every
   frame to set the canvas background color. If the scene is transparent Pixi will use clearRect
   to clear the canvas every frame. Disable this by setting this to false. For example if
   your game has a canvas filling background image you often don't need this set.
   */
  external clearBeforeRender : t => Js.boolean = "" [@@bs.get];
  /*
   This sets if the CanvasRenderer will clear the canvas or not before the new render pass.
   If the scene is NOT transparent Pixi will use a canvas sized fillRect operation every
   frame to set the canvas background color. If the scene is transparent Pixi will use clearRect
   to clear the canvas every frame. Disable this by setting this to false. For example if
   your game has a canvas filling background image you often don't need this set.
   */
  external setClearBeforeRender : t => Js.boolean => unit = "clearBeforeRender" [@@bs.set];
  /*
   If true Pixi will Math.floor() x/y values when rendering, stopping pixel interpolation.
   Handy for crisp pixel art and speed on legacy devices.
   */
  external roundPixels : t => Js.boolean = "" [@@bs.get];
  /*
   If true Pixi will Math.floor() x/y values when rendering, stopping pixel interpolation.
   Handy for crisp pixel art and speed on legacy devices.
   */
  external setRoundPixels : t => Js.boolean => unit = "roundPixels" [@@bs.set];
  /*
   Same as view.width, actual number of pixels in the canvas by horizontal
   */
  external width : t => float = "" [@@bs.get];
  /*
   Same as view.height, actual number of pixels in the canvas by vertical
   */
  external height : t => float = "" [@@bs.get];
  /*
   The background color to fill if not transparent
   */
  external backgroundColor : t => float = "" [@@bs.get];
  /*
   The background color to fill if not transparent
   */
  external setBackgroundColor : t => float => unit = "backgroundColor" [@@bs.set];
};

/*
 The CanvasRenderer draws the scene and all its content onto a 2d canvas. This renderer should
 be used for browsers that do not support WebGL. Don't forget to add the CanvasRenderer.view to
 your DOM or you will not see anything :)
 */
module CanvasRenderer = {
  /*
   The CanvasRenderer draws the scene and all its content onto a 2d canvas. This renderer should
   be used for browsers that do not support WebGL. Don't forget to add the CanvasRenderer.view to
   your DOM or you will not see anything :)
   */
  type t;
  /*
   The root canvas 2d context that everything is drawn with.
   */
  external rootContext : t => unit /* unknown js type: CanvasRenderingContext2D */ = "" [@@bs.get];
  /*
   The root canvas 2d context that everything is drawn with.
   */
  external setRootContext : t => unit /* unknown js type: CanvasRenderingContext2D */ => unit =
    "rootContext" [@@bs.set];
  /*
   The currently active canvas 2d context (could change with renderTextures)
   */
  external context : t => unit /* unknown js type: CanvasRenderingContext2D */ = "" [@@bs.get];
  /*
   The currently active canvas 2d context (could change with renderTextures)
   */
  external setContext : t => unit /* unknown js type: CanvasRenderingContext2D */ => unit =
    "context" [@@bs.set];
  /*
   Boolean flag controlling canvas refresh.
   */
  external refresh : t => Js.boolean = "" [@@bs.get];
  /*
   Boolean flag controlling canvas refresh.
   */
  external setRefresh : t => Js.boolean => unit = "refresh" [@@bs.set];
  /*
   Instance of a CanvasMaskManager, handles masking when using the canvas renderer.
   */
  external maskManager : t => CanvasMaskManager.t = "" [@@bs.get];
  /*
   Instance of a CanvasMaskManager, handles masking when using the canvas renderer.
   */
  external setMaskManager : t => CanvasMaskManager.t => unit = "maskManager" [@@bs.set];
  /*
   The canvas property used to set the canvas smoothing property.
   */
  external smoothProperty : t => string = "" [@@bs.get];
  /*
   The canvas property used to set the canvas smoothing property.
   */
  external setSmoothProperty : t => string => unit = "smoothProperty" [@@bs.set];
  /*
   Collection of installed plugins. These are included by default in PIXI, but can be excluded
   by creating a custom build. Consult the README for more information about creating custom
   builds and excluding plugins.
   */
  external plugins : t => unit /* unknown js type: object */ = "" [@@bs.get];
  /*
   Collection of methods for extracting data (image, pixels, etc.) from a display object or render texture
   */
  external extract : t => Extract.CanvasExtract.t = "" [@@bs.get];
  /*
   Collection of methods for extracting data (image, pixels, etc.) from a display object or render texture
   */
  external setExtract : t => Extract.CanvasExtract.t => unit = "extract" [@@bs.set];
  /*
   The supplied constructor options.
   */
  external options : t => unit /* unknown js type: Object */ = "" [@@bs.get];
  /*
   The type of the renderer.
   */
  external type_ : t => float = "type" [@@bs.get];
  /*
   The type of the renderer.
   */
  external setType : t => float => unit = "type" [@@bs.set];
  /*
   Measurements of the screen. (0, 0, screenWidth, screenHeight)

   Its safe to use as filterArea or hitArea for whole stage
   */
  external screen : t => Rectangle.t = "" [@@bs.get];
  /*
   Measurements of the screen. (0, 0, screenWidth, screenHeight)

   Its safe to use as filterArea or hitArea for whole stage
   */
  external setScreen : t => Rectangle.t => unit = "screen" [@@bs.set];
  /*
   The canvas element that everything is drawn to
   */
  external view : t => Dom.element = "" [@@bs.get];
  /*
   The canvas element that everything is drawn to
   */
  external setView : t => Dom.element => unit = "view" [@@bs.set];
  /*
   The resolution / device pixel ratio of the renderer
   */
  external resolution : t => float = "" [@@bs.get];
  /*
   The resolution / device pixel ratio of the renderer
   */
  external setResolution : t => float => unit = "resolution" [@@bs.set];
  /*
   Whether the render view is transparent
   */
  external transparent : t => Js.boolean = "" [@@bs.get];
  /*
   Whether the render view is transparent
   */
  external setTransparent : t => Js.boolean => unit = "transparent" [@@bs.set];
  /*
   Whether css dimensions of canvas view should be resized to screen dimensions automatically
   */
  external autoResize : t => Js.boolean = "" [@@bs.get];
  /*
   Whether css dimensions of canvas view should be resized to screen dimensions automatically
   */
  external setAutoResize : t => Js.boolean => unit = "autoResize" [@@bs.set];
  /*
   Tracks the blend modes useful for this renderer.
   */
  external blendModes : t => unit /* unknown js type: object.<string, mixed> */ = "" [@@bs.get];
  /*
   Tracks the blend modes useful for this renderer.
   */
  external setBlendModes : t => unit /* unknown js type: object.<string, mixed> */ => unit =
    "blendModes" [@@bs.set];
  /*
   The value of the preserveDrawingBuffer flag affects whether or not the contents of
   the stencil buffer is retained after rendering.
   */
  external preserveDrawingBuffer : t => Js.boolean = "" [@@bs.get];
  /*
   The value of the preserveDrawingBuffer flag affects whether or not the contents of
   the stencil buffer is retained after rendering.
   */
  external setPreserveDrawingBuffer : t => Js.boolean => unit = "preserveDrawingBuffer" [@@bs.set];
  /*
   This sets if the CanvasRenderer will clear the canvas or not before the new render pass.
   If the scene is NOT transparent Pixi will use a canvas sized fillRect operation every
   frame to set the canvas background color. If the scene is transparent Pixi will use clearRect
   to clear the canvas every frame. Disable this by setting this to false. For example if
   your game has a canvas filling background image you often don't need this set.
   */
  external clearBeforeRender : t => Js.boolean = "" [@@bs.get];
  /*
   This sets if the CanvasRenderer will clear the canvas or not before the new render pass.
   If the scene is NOT transparent Pixi will use a canvas sized fillRect operation every
   frame to set the canvas background color. If the scene is transparent Pixi will use clearRect
   to clear the canvas every frame. Disable this by setting this to false. For example if
   your game has a canvas filling background image you often don't need this set.
   */
  external setClearBeforeRender : t => Js.boolean => unit = "clearBeforeRender" [@@bs.set];
  /*
   If true Pixi will Math.floor() x/y values when rendering, stopping pixel interpolation.
   Handy for crisp pixel art and speed on legacy devices.
   */
  external roundPixels : t => Js.boolean = "" [@@bs.get];
  /*
   If true Pixi will Math.floor() x/y values when rendering, stopping pixel interpolation.
   Handy for crisp pixel art and speed on legacy devices.
   */
  external setRoundPixels : t => Js.boolean => unit = "roundPixels" [@@bs.set];
  /*
   Same as view.width, actual number of pixels in the canvas by horizontal
   */
  external width : t => float = "" [@@bs.get];
  /*
   Same as view.height, actual number of pixels in the canvas by vertical
   */
  external height : t => float = "" [@@bs.get];
  /*
   The background color to fill if not transparent
   */
  external backgroundColor : t => float = "" [@@bs.get];
  /*
   The background color to fill if not transparent
   */
  external setBackgroundColor : t => float => unit = "backgroundColor" [@@bs.set];
};

/*
 A set of functions used to handle masking.
 */
module CanvasMaskManager = {
  /*
   A set of functions used to handle masking.
   */
  type t;
};

/*
 Creates a Canvas element of the given size.
 */
module CanvasRenderTarget = {
  /*
   Creates a Canvas element of the given size.
   */
  type t;
  /*
   The Canvas object that belongs to this CanvasRenderTarget.
   */
  external canvas : t => Dom.element = "" [@@bs.get];
  /*
   The Canvas object that belongs to this CanvasRenderTarget.
   */
  external setCanvas : t => Dom.element => unit = "canvas" [@@bs.set];
  /*
   A CanvasRenderingContext2D object representing a two-dimensional rendering context.
   */
  external context : t => unit /* unknown js type: CanvasRenderingContext2D */ = "" [@@bs.get];
  /*
   A CanvasRenderingContext2D object representing a two-dimensional rendering context.
   */
  external setContext : t => unit /* unknown js type: CanvasRenderingContext2D */ => unit =
    "context" [@@bs.set];
  /*
   The width of the canvas buffer in pixels.
   */
  external width : t => float = "" [@@bs.get];
  /*
   The width of the canvas buffer in pixels.
   */
  external setWidth : t => float => unit = "width" [@@bs.set];
  /*
   The height of the canvas buffer in pixels.
   */
  external height : t => float = "" [@@bs.get];
  /*
   The height of the canvas buffer in pixels.
   */
  external setHeight : t => float => unit = "height" [@@bs.set];
};

/*
 TextureGarbageCollector. This class manages the GPU and ensures that it does not get clogged
 up with textures that are no longer being used.
 */
module TextureGarbageCollector = {
  /*
   TextureGarbageCollector. This class manages the GPU and ensures that it does not get clogged
   up with textures that are no longer being used.
   */
  type t;
};

/*
 Helper class to create a webGL Texture
 */
module TextureManager = {
  /*
   Helper class to create a webGL Texture
   */
  type t;
  /*
   A reference to the current renderer
   */
  external renderer : t => WebGLRenderer.t = "" [@@bs.get];
  /*
   A reference to the current renderer
   */
  external setRenderer : t => WebGLRenderer.t => unit = "renderer" [@@bs.set];
  /*
   The current WebGL rendering context
   */
  external gl : t => ReasonJs.Gl.glT = "" [@@bs.get];
  /*
   The current WebGL rendering context
   */
  external setGl : t => ReasonJs.Gl.glT => unit = "gl" [@@bs.set];
};

/*
 The WebGLRenderer draws the scene and all its content onto a webGL enabled canvas. This renderer
 should be used for browsers that support webGL. This Render works by automatically managing webGLBatchs.
 So no need for Sprite Batches or Sprite Clouds.
 Don't forget to add the view to your DOM or you will not see anything :)
 */
module WebGLRenderer = {
  /*
   The WebGLRenderer draws the scene and all its content onto a webGL enabled canvas. This renderer
   should be used for browsers that support webGL. This Render works by automatically managing webGLBatchs.
   So no need for Sprite Batches or Sprite Clouds.
   Don't forget to add the view to your DOM or you will not see anything :)
   */
  type t;
  /*
   The type of this renderer as a standardised const
   */
  external type_ : t => float = "type" [@@bs.get];
  /*
   The type of this renderer as a standardised const
   */
  external setType : t => float => unit = "type" [@@bs.set];
  /*
   Manages the masks using the stencil buffer.
   */
  external maskManager : t => MaskManager.t = "" [@@bs.get];
  /*
   Manages the masks using the stencil buffer.
   */
  external setMaskManager : t => MaskManager.t => unit = "maskManager" [@@bs.set];
  /*
   Manages the stencil buffer.
   */
  external stencilManager : t => StencilManager.t = "" [@@bs.get];
  /*
   Manages the stencil buffer.
   */
  external setStencilManager : t => StencilManager.t => unit = "stencilManager" [@@bs.set];
  /*
   An empty renderer.
   */
  external emptyRenderer : t => ObjectRenderer.t = "" [@@bs.get];
  /*
   An empty renderer.
   */
  external setEmptyRenderer : t => ObjectRenderer.t => unit = "emptyRenderer" [@@bs.set];
  /*
   The currently active ObjectRenderer.
   */
  external currentRenderer : t => ObjectRenderer.t = "" [@@bs.get];
  /*
   The currently active ObjectRenderer.
   */
  external setCurrentRenderer : t => ObjectRenderer.t => unit = "currentRenderer" [@@bs.set];
  /*
   The currently active ObjectRenderer.
   */
  external state : t => WebGLState.t = "" [@@bs.get];
  /*
   The currently active ObjectRenderer.
   */
  external setState : t => WebGLState.t => unit = "state" [@@bs.set];
  /*
   Holds the current state of textures bound to the GPU.
   */
  external boundTextures : t => unit /* unknown js type: Array */ = "" [@@bs.get];
  /*
   Holds the current state of textures bound to the GPU.
   */
  external setBoundTextures : t => unit /* unknown js type: Array */ => unit =
    "boundTextures" [@@bs.set];
  /*
   Holds the current shader
   */
  external _activeShader : t => Shader.t = "" [@@bs.get];
  /*
   Holds the current shader
   */
  external set_activeShader : t => Shader.t => unit = "_activeShader" [@@bs.set];
  /*
   Holds the current render target
   */
  external _activeRenderTarget : t => RenderTarget.t = "" [@@bs.get];
  /*
   Holds the current render target
   */
  external set_activeRenderTarget : t => RenderTarget.t => unit = "_activeRenderTarget" [@@bs.set];
  /*
   Manages the filters.
   */
  external filterManager : t => FilterManager.t = "" [@@bs.get];
  /*
   Manages the filters.
   */
  external setFilterManager : t => FilterManager.t => unit = "filterManager" [@@bs.set];
  /*
   Collection of installed plugins. These are included by default in PIXI, but can be excluded
   by creating a custom build. Consult the README for more information about creating custom
   builds and excluding plugins.
   */
  external plugins : t => unit /* unknown js type: object */ = "" [@@bs.get];
  /*
   Collection of methods for extracting data (image, pixels, etc.) from a display object or render texture
   */
  external extract : t => Extract.WebGLExtract.t = "" [@@bs.get];
  /*
   Collection of methods for extracting data (image, pixels, etc.) from a display object or render texture
   */
  external setExtract : t => Extract.WebGLExtract.t => unit = "extract" [@@bs.set];
  /*
   The supplied constructor options.
   */
  external options : t => unit /* unknown js type: Object */ = "" [@@bs.get];
  /*
   Measurements of the screen. (0, 0, screenWidth, screenHeight)

   Its safe to use as filterArea or hitArea for whole stage
   */
  external screen : t => Rectangle.t = "" [@@bs.get];
  /*
   Measurements of the screen. (0, 0, screenWidth, screenHeight)

   Its safe to use as filterArea or hitArea for whole stage
   */
  external setScreen : t => Rectangle.t => unit = "screen" [@@bs.set];
  /*
   The canvas element that everything is drawn to
   */
  external view : t => Dom.element = "" [@@bs.get];
  /*
   The canvas element that everything is drawn to
   */
  external setView : t => Dom.element => unit = "view" [@@bs.set];
  /*
   The resolution / device pixel ratio of the renderer
   */
  external resolution : t => float = "" [@@bs.get];
  /*
   The resolution / device pixel ratio of the renderer
   */
  external setResolution : t => float => unit = "resolution" [@@bs.set];
  /*
   Whether the render view is transparent
   */
  external transparent : t => Js.boolean = "" [@@bs.get];
  /*
   Whether the render view is transparent
   */
  external setTransparent : t => Js.boolean => unit = "transparent" [@@bs.set];
  /*
   Whether css dimensions of canvas view should be resized to screen dimensions automatically
   */
  external autoResize : t => Js.boolean = "" [@@bs.get];
  /*
   Whether css dimensions of canvas view should be resized to screen dimensions automatically
   */
  external setAutoResize : t => Js.boolean => unit = "autoResize" [@@bs.set];
  /*
   Tracks the blend modes useful for this renderer.
   */
  external blendModes : t => unit /* unknown js type: object.<string, mixed> */ = "" [@@bs.get];
  /*
   Tracks the blend modes useful for this renderer.
   */
  external setBlendModes : t => unit /* unknown js type: object.<string, mixed> */ => unit =
    "blendModes" [@@bs.set];
  /*
   The value of the preserveDrawingBuffer flag affects whether or not the contents of
   the stencil buffer is retained after rendering.
   */
  external preserveDrawingBuffer : t => Js.boolean = "" [@@bs.get];
  /*
   The value of the preserveDrawingBuffer flag affects whether or not the contents of
   the stencil buffer is retained after rendering.
   */
  external setPreserveDrawingBuffer : t => Js.boolean => unit = "preserveDrawingBuffer" [@@bs.set];
  /*
   This sets if the CanvasRenderer will clear the canvas or not before the new render pass.
   If the scene is NOT transparent Pixi will use a canvas sized fillRect operation every
   frame to set the canvas background color. If the scene is transparent Pixi will use clearRect
   to clear the canvas every frame. Disable this by setting this to false. For example if
   your game has a canvas filling background image you often don't need this set.
   */
  external clearBeforeRender : t => Js.boolean = "" [@@bs.get];
  /*
   This sets if the CanvasRenderer will clear the canvas or not before the new render pass.
   If the scene is NOT transparent Pixi will use a canvas sized fillRect operation every
   frame to set the canvas background color. If the scene is transparent Pixi will use clearRect
   to clear the canvas every frame. Disable this by setting this to false. For example if
   your game has a canvas filling background image you often don't need this set.
   */
  external setClearBeforeRender : t => Js.boolean => unit = "clearBeforeRender" [@@bs.set];
  /*
   If true Pixi will Math.floor() x/y values when rendering, stopping pixel interpolation.
   Handy for crisp pixel art and speed on legacy devices.
   */
  external roundPixels : t => Js.boolean = "" [@@bs.get];
  /*
   If true Pixi will Math.floor() x/y values when rendering, stopping pixel interpolation.
   Handy for crisp pixel art and speed on legacy devices.
   */
  external setRoundPixels : t => Js.boolean => unit = "roundPixels" [@@bs.set];
  /*
   Same as view.width, actual number of pixels in the canvas by horizontal
   */
  external width : t => float = "" [@@bs.get];
  /*
   Same as view.height, actual number of pixels in the canvas by vertical
   */
  external height : t => float = "" [@@bs.get];
  /*
   The background color to fill if not transparent
   */
  external backgroundColor : t => float = "" [@@bs.get];
  /*
   The background color to fill if not transparent
   */
  external setBackgroundColor : t => float => unit = "backgroundColor" [@@bs.set];
};

/*
 A WebGL state machines
 */
module WebGLState = {
  /*
   A WebGL state machines
   */
  type t;
  /*
   The current active state
   */
  external activeState : t => unit /* unknown js type: Uint8Array */ = "" [@@bs.get];
  /*
   The current active state
   */
  external setActiveState : t => unit /* unknown js type: Uint8Array */ => unit =
    "activeState" [@@bs.set];
  /*
   The default state
   */
  external defaultState : t => unit /* unknown js type: Uint8Array */ = "" [@@bs.get];
  /*
   The default state
   */
  external setDefaultState : t => unit /* unknown js type: Uint8Array */ => unit =
    "defaultState" [@@bs.set];
  /*
   The current WebGL rendering context
   */
  external gl : t => ReasonJs.Gl.glT = "" [@@bs.get];
  /*
   The current WebGL rendering context
   */
  external setGl : t => ReasonJs.Gl.glT => unit = "gl" [@@bs.set];
};

module Filter = {
  type t;
  /*
   The vertex shader.
   */
  external vertexSrc : t => string = "" [@@bs.get];
  /*
   The vertex shader.
   */
  external setVertexSrc : t => string => unit = "vertexSrc" [@@bs.set];
  /*
   The fragment shader.
   */
  external fragmentSrc : t => string = "" [@@bs.get];
  /*
   The fragment shader.
   */
  external setFragmentSrc : t => string => unit = "fragmentSrc" [@@bs.set];
  /*
   An object containing the current values of custom uniforms.
   */
  external uniforms : t => unit /* unknown js type: object */ = "" [@@bs.get];
  /*
   An object containing the current values of custom uniforms.
   */
  external setUniforms : t => unit /* unknown js type: object */ => unit = "uniforms" [@@bs.set];
  /*
   The padding of the filter. Some filters require extra space to breath such as a blur.
   Increasing this will add extra width and height to the bounds of the object that the
   filter is applied to.
   */
  external padding : t => float = "" [@@bs.get];
  /*
   The padding of the filter. Some filters require extra space to breath such as a blur.
   Increasing this will add extra width and height to the bounds of the object that the
   filter is applied to.
   */
  external setPadding : t => float => unit = "padding" [@@bs.set];
  /*
   The resolution of the filter. Setting this to be lower will lower the quality but
   increase the performance of the filter.
   */
  external resolution : t => float = "" [@@bs.get];
  /*
   The resolution of the filter. Setting this to be lower will lower the quality but
   increase the performance of the filter.
   */
  external setResolution : t => float => unit = "resolution" [@@bs.set];
  /*
   If enabled is true the filter is applied, if false it will not.
   */
  external enabled : t => Js.boolean = "" [@@bs.get];
  /*
   If enabled is true the filter is applied, if false it will not.
   */
  external setEnabled : t => Js.boolean => unit = "enabled" [@@bs.set];
  /*
   If enabled, pixi will fit the filter area into boundaries for better performance.
   Switch it off if it does not work for specific shader.
   */
  external autoFit : t => Js.boolean = "" [@@bs.get];
  /*
   If enabled, pixi will fit the filter area into boundaries for better performance.
   Switch it off if it does not work for specific shader.
   */
  external setAutoFit : t => Js.boolean => unit = "autoFit" [@@bs.set];
};

/*
 The SpriteMaskFilter class
 */
module SpriteMaskFilter = {
  /*
   The SpriteMaskFilter class
   */
  type t;
  /*
   The vertex shader.
   */
  external vertexSrc : t => string = "" [@@bs.get];
  /*
   The vertex shader.
   */
  external setVertexSrc : t => string => unit = "vertexSrc" [@@bs.set];
  /*
   The fragment shader.
   */
  external fragmentSrc : t => string = "" [@@bs.get];
  /*
   The fragment shader.
   */
  external setFragmentSrc : t => string => unit = "fragmentSrc" [@@bs.set];
  /*
   An object containing the current values of custom uniforms.
   */
  external uniforms : t => unit /* unknown js type: object */ = "" [@@bs.get];
  /*
   An object containing the current values of custom uniforms.
   */
  external setUniforms : t => unit /* unknown js type: object */ => unit = "uniforms" [@@bs.set];
  /*
   The padding of the filter. Some filters require extra space to breath such as a blur.
   Increasing this will add extra width and height to the bounds of the object that the
   filter is applied to.
   */
  external padding : t => float = "" [@@bs.get];
  /*
   The padding of the filter. Some filters require extra space to breath such as a blur.
   Increasing this will add extra width and height to the bounds of the object that the
   filter is applied to.
   */
  external setPadding : t => float => unit = "padding" [@@bs.set];
  /*
   The resolution of the filter. Setting this to be lower will lower the quality but
   increase the performance of the filter.
   */
  external resolution : t => float = "" [@@bs.get];
  /*
   The resolution of the filter. Setting this to be lower will lower the quality but
   increase the performance of the filter.
   */
  external setResolution : t => float => unit = "resolution" [@@bs.set];
  /*
   If enabled is true the filter is applied, if false it will not.
   */
  external enabled : t => Js.boolean = "" [@@bs.get];
  /*
   If enabled is true the filter is applied, if false it will not.
   */
  external setEnabled : t => Js.boolean => unit = "enabled" [@@bs.set];
  /*
   If enabled, pixi will fit the filter area into boundaries for better performance.
   Switch it off if it does not work for specific shader.
   */
  external autoFit : t => Js.boolean = "" [@@bs.get];
  /*
   If enabled, pixi will fit the filter area into boundaries for better performance.
   Switch it off if it does not work for specific shader.
   */
  external setAutoFit : t => Js.boolean => unit = "autoFit" [@@bs.set];
};

module BlendModeManager = {
  type t;
  external currentBlendMode : t => float = "" [@@bs.get];
  external setCurrentBlendMode : t => float => unit = "currentBlendMode" [@@bs.set];
  /*
   The renderer this manager works for.
   */
  external renderer : t => WebGLRenderer.t = "" [@@bs.get];
  /*
   The renderer this manager works for.
   */
  external setRenderer : t => WebGLRenderer.t => unit = "renderer" [@@bs.set];
};

module FilterState = {
  type t;
};

module FilterManager = {
  type t;
  /*
   The renderer this manager works for.
   */
  external renderer : t => WebGLRenderer.t = "" [@@bs.get];
  /*
   The renderer this manager works for.
   */
  external setRenderer : t => WebGLRenderer.t => unit = "renderer" [@@bs.set];
};

module MaskManager = {
  type t;
  /*
   The renderer this manager works for.
   */
  external renderer : t => WebGLRenderer.t = "" [@@bs.get];
  /*
   The renderer this manager works for.
   */
  external setRenderer : t => WebGLRenderer.t => unit = "renderer" [@@bs.set];
};

module StencilManager = {
  type t;
  /*
   The renderer this manager works for.
   */
  external renderer : t => WebGLRenderer.t = "" [@@bs.get];
  /*
   The renderer this manager works for.
   */
  external setRenderer : t => WebGLRenderer.t => unit = "renderer" [@@bs.set];
};

module WebGLManager = {
  type t;
  /*
   The renderer this manager works for.
   */
  external renderer : t => WebGLRenderer.t = "" [@@bs.get];
  /*
   The renderer this manager works for.
   */
  external setRenderer : t => WebGLRenderer.t => unit = "renderer" [@@bs.set];
};

/*
 Base for a common object renderer that can be used as a system renderer plugin.
 */
module ObjectRenderer = {
  /*
   Base for a common object renderer that can be used as a system renderer plugin.
   */
  type t;
  /*
   The renderer this manager works for.
   */
  external renderer : t => WebGLRenderer.t = "" [@@bs.get];
  /*
   The renderer this manager works for.
   */
  external setRenderer : t => WebGLRenderer.t => unit = "renderer" [@@bs.set];
};

/*
 Helper class to create a quad
 */
module Quad = {
  /*
   Helper class to create a quad
   */
  type t;
  /*
   the current WebGL drawing context
   */
  external gl : t => ReasonJs.Gl.glT = "" [@@bs.get];
  /*
   the current WebGL drawing context
   */
  external setGl : t => ReasonJs.Gl.glT => unit = "gl" [@@bs.set];
  /*
   An array of vertices
   */
  external vertices : t => unit /* unknown js type: Float32Array */ = "" [@@bs.get];
  /*
   An array of vertices
   */
  external setVertices : t => unit /* unknown js type: Float32Array */ => unit =
    "vertices" [@@bs.set];
  /*
   The Uvs of the quad
   */
  external uvs : t => unit /* unknown js type: Float32Array */ = "" [@@bs.get];
  /*
   The Uvs of the quad
   */
  external setUvs : t => unit /* unknown js type: Float32Array */ => unit = "uvs" [@@bs.set];
  /*
   An array containing the indices of the vertices
   */
  external indices : t => unit /* unknown js type: Uint16Array */ = "" [@@bs.get];
  /*
   An array containing the indices of the vertices
   */
  external setIndices : t => unit /* unknown js type: Uint16Array */ => unit =
    "indices" [@@bs.set];
  /*
   The vertex buffer
   */
  external vertexBuffer : t => unit /* unknown js type: glCore.GLBuffer */ = "" [@@bs.get];
  /*
   The vertex buffer
   */
  external setVertexBuffer : t => unit /* unknown js type: glCore.GLBuffer */ => unit =
    "vertexBuffer" [@@bs.set];
  /*
   The index buffer
   */
  external indexBuffer : t => unit /* unknown js type: glCore.GLBuffer */ = "" [@@bs.get];
  /*
   The index buffer
   */
  external setIndexBuffer : t => unit /* unknown js type: glCore.GLBuffer */ => unit =
    "indexBuffer" [@@bs.set];
  /*
   The vertex array object
   */
  external vao : t => unit /* unknown js type: glCore.VertexArrayObject */ = "" [@@bs.get];
  /*
   The vertex array object
   */
  external setVao : t => unit /* unknown js type: glCore.VertexArrayObject */ => unit =
    "vao" [@@bs.set];
};

module RenderTarget = {
  type t;
  /*
   The current WebGL drawing context.
   */
  external gl : t => ReasonJs.Gl.glT = "" [@@bs.get];
  /*
   The current WebGL drawing context.
   */
  external setGl : t => ReasonJs.Gl.glT => unit = "gl" [@@bs.set];
  /*
   A frame buffer
   */
  external frameBuffer : t => unit /* unknown js type: PIXI.glCore.GLFramebuffer */ =
    "" [@@bs.get];
  /*
   A frame buffer
   */
  external setFrameBuffer : t => unit /* unknown js type: PIXI.glCore.GLFramebuffer */ => unit =
    "frameBuffer" [@@bs.set];
  /*
   The texture
   */
  external texture : t => unit /* unknown js type: PIXI.glCore.GLTexture */ = "" [@@bs.get];
  /*
   The texture
   */
  external setTexture : t => unit /* unknown js type: PIXI.glCore.GLTexture */ => unit =
    "texture" [@@bs.set];
  /*
   The background colour of this render target, as an array of [r,g,b,a] values
   */
  external clearColor : t => array float = "" [@@bs.get];
  /*
   The background colour of this render target, as an array of [r,g,b,a] values
   */
  external setClearColor : t => array float => unit = "clearColor" [@@bs.set];
  /*
   The size of the object as a rectangle
   */
  external size : t => Rectangle.t = "" [@@bs.get];
  /*
   The size of the object as a rectangle
   */
  external setSize : t => Rectangle.t => unit = "size" [@@bs.set];
  /*
   The current resolution / device pixel ratio
   */
  external resolution : t => float = "" [@@bs.get];
  /*
   The current resolution / device pixel ratio
   */
  external setResolution : t => float => unit = "resolution" [@@bs.set];
  /*
   The projection matrix
   */
  external projectionMatrix : t => Matrix.t = "" [@@bs.get];
  /*
   The projection matrix
   */
  external setProjectionMatrix : t => Matrix.t => unit = "projectionMatrix" [@@bs.set];
  /*
   The object's transform
   */
  external transform : t => Matrix.t = "" [@@bs.get];
  /*
   The object's transform
   */
  external setTransform : t => Matrix.t => unit = "transform" [@@bs.set];
  /*
   The frame.
   */
  external frame : t => Rectangle.t = "" [@@bs.get];
  /*
   The frame.
   */
  external setFrame : t => Rectangle.t => unit = "frame" [@@bs.set];
  /*
   The stencil buffer stores masking data for the render target
   */
  external defaultFrame : t => unit /* unknown js type: glCore.GLBuffer */ = "" [@@bs.get];
  /*
   The stencil buffer stores masking data for the render target
   */
  external setDefaultFrame : t => unit /* unknown js type: glCore.GLBuffer */ => unit =
    "defaultFrame" [@@bs.set];
  /*
   The stencil buffer stores masking data for the render target
   */
  external stencilBuffer : t => unit /* unknown js type: glCore.GLBuffer */ = "" [@@bs.get];
  /*
   The stencil buffer stores masking data for the render target
   */
  external setStencilBuffer : t => unit /* unknown js type: glCore.GLBuffer */ => unit =
    "stencilBuffer" [@@bs.set];
  /*
   The data structure for the stencil masks
   */
  external stencilMaskStack : t => array Graphics.t = "" [@@bs.get];
  /*
   The data structure for the stencil masks
   */
  external setStencilMaskStack : t => array Graphics.t => unit = "stencilMaskStack" [@@bs.set];
  /*
   Stores filter data for the render target
   */
  external filterData : t => array unit /* unknown js type: object */ = "" [@@bs.get];
  /*
   Stores filter data for the render target
   */
  external setFilterData : t => array unit /* unknown js type: object */ => unit =
    "filterData" [@@bs.set];
  /*
   The scale mode.
   */
  external scaleMode : t => float = "" [@@bs.get];
  /*
   The scale mode.
   */
  external setScaleMode : t => float => unit = "scaleMode" [@@bs.set];
  /*
   Whether this object is the root element or not
   */
  external root : t => Js.boolean = "" [@@bs.get];
  /*
   Whether this object is the root element or not
   */
  external setRoot : t => Js.boolean => unit = "root" [@@bs.set];
};

/*
 The Sprite object is the base for all textured objects that are rendered to the screen

 A sprite can be created directly from an image like this:

 <pre class="prettyprint source lang-js"><code>let sprite = new PIXI.Sprite.fromImage('assets/image.png');</code></pre>
 */
module Sprite = {
  /*
   The Sprite object is the base for all textured objects that are rendered to the screen

   A sprite can be created directly from an image like this:

   <pre class="prettyprint source lang-js"><code>let sprite = new PIXI.Sprite.fromImage('assets/image.png');</code></pre>
   */
  type t;
  /*
   <p>The blend mode to be applied to the sprite. Apply a value of <code>PIXI.BLEND_MODES.NORMAL</code> to reset the blend mode.</p>
   */
  external blendMode : t => float = "" [@@bs.get];
  /*
   <p>The blend mode to be applied to the sprite. Apply a value of <code>PIXI.BLEND_MODES.NORMAL</code> to reset the blend mode.</p>
   */
  external setBlendMode : t => float => unit = "blendMode" [@@bs.set];
  /*
   The shader that will be used to render the sprite. Set to null to remove a current shader.
   */
  external shader : t => unit /* unknown js type: PIXI.Filter|PIXI.Shader */ = "" [@@bs.get];
  /*
   The shader that will be used to render the sprite. Set to null to remove a current shader.
   */
  external setShader : t => unit /* unknown js type: PIXI.Filter|PIXI.Shader */ => unit =
    "shader" [@@bs.set];
  /*
   Plugin that is responsible for rendering this element.
   Allows to customize the rendering process without overriding '_renderWebGL' &amp; '_renderCanvas' methods.
   */
  external pluginName : t => string = "" [@@bs.get];
  /*
   Plugin that is responsible for rendering this element.
   Allows to customize the rendering process without overriding '_renderWebGL' &amp; '_renderCanvas' methods.
   */
  external setPluginName : t => string => unit = "pluginName" [@@bs.set];
  /*
   The width of the sprite, setting this will actually modify the scale to achieve the value set
   */
  external width : t => float = "" [@@bs.get];
  /*
   The width of the sprite, setting this will actually modify the scale to achieve the value set
   */
  external setWidth : t => float => unit = "width" [@@bs.set];
  /*
   The height of the sprite, setting this will actually modify the scale to achieve the value set
   */
  external height : t => float = "" [@@bs.get];
  /*
   The height of the sprite, setting this will actually modify the scale to achieve the value set
   */
  external setHeight : t => float => unit = "height" [@@bs.set];
  /*
   The anchor sets the origin point of the texture.
   The default is 0,0 this means the texture's origin is the top left
   Setting the anchor to 0.5,0.5 means the texture's origin is centered
   Setting the anchor to 1,1 would mean the texture's origin point will be the bottom right corner
   */
  external anchor : t => ObservablePoint.t = "" [@@bs.get];
  /*
   The anchor sets the origin point of the texture.
   The default is 0,0 this means the texture's origin is the top left
   Setting the anchor to 0.5,0.5 means the texture's origin is centered
   Setting the anchor to 1,1 would mean the texture's origin point will be the bottom right corner
   */
  external setAnchor : t => ObservablePoint.t => unit = "anchor" [@@bs.set];
  /*
   The tint applied to the sprite. This is a hex value.
   A value of 0xFFFFFF will remove any tint effect.
   */
  external tint : t => float = "" [@@bs.get];
  /*
   The tint applied to the sprite. This is a hex value.
   A value of 0xFFFFFF will remove any tint effect.
   */
  external setTint : t => float => unit = "tint" [@@bs.set];
  /*
   The texture that the sprite is using
   */
  external texture : t => Texture.t = "" [@@bs.get];
  /*
   The texture that the sprite is using
   */
  external setTexture : t => Texture.t => unit = "texture" [@@bs.set];
  /*
   The array of children of this container.
   */
  external children : t => array DisplayObject.t = "" [@@bs.get];
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
   World transform and local transform of this object.
   This will become read-only later, please do not assign anything there unless you know what are you doing
   */
  external transform : t => TransformBase.t = "" [@@bs.get];
  /*
   World transform and local transform of this object.
   This will become read-only later, please do not assign anything there unless you know what are you doing
   */
  external setTransform : t => TransformBase.t => unit = "transform" [@@bs.set];
  /*
   The opacity of the object.
   */
  external alpha : t => float = "" [@@bs.get];
  /*
   The opacity of the object.
   */
  external setAlpha : t => float => unit = "alpha" [@@bs.set];
  /*
   The visibility of the object. If false the object will not be drawn, and
   the updateTransform function will not be called.

   Only affects recursive calls from parent. You can ask for bounds or call updateTransform manually
   */
  external visible : t => Js.boolean = "" [@@bs.get];
  /*
   The visibility of the object. If false the object will not be drawn, and
   the updateTransform function will not be called.

   Only affects recursive calls from parent. You can ask for bounds or call updateTransform manually
   */
  external setVisible : t => Js.boolean => unit = "visible" [@@bs.set];
  /*
   Can this object be rendered, if false the object will not be drawn but the updateTransform
   methods will still be called.

   Only affects recursive calls from parent. You can ask for bounds manually
   */
  external renderable : t => Js.boolean = "" [@@bs.get];
  /*
   Can this object be rendered, if false the object will not be drawn but the updateTransform
   methods will still be called.

   Only affects recursive calls from parent. You can ask for bounds manually
   */
  external setRenderable : t => Js.boolean => unit = "renderable" [@@bs.set];
  /*
   The display object container that contains this display object.
   */
  external parent : t => Container.t = "" [@@bs.get];
  /*
   The multiplied alpha of the displayObject
   */
  external worldAlpha : t => float = "" [@@bs.get];
  /*
   The area the filter is applied to. This is used as more of an optimisation
   rather than figuring out the dimensions of the displayObject each frame you can set this rectangle

   Also works as an interaction mask
   */
  external filterArea : t => Rectangle.t = "" [@@bs.get];
  /*
   The area the filter is applied to. This is used as more of an optimisation
   rather than figuring out the dimensions of the displayObject each frame you can set this rectangle

   Also works as an interaction mask
   */
  external setFilterArea : t => Rectangle.t => unit = "filterArea" [@@bs.set];
  /*
   The position of the displayObject on the x axis relative to the local coordinates of the parent.
   An alias to position.x
   */
  external x : t => float = "" [@@bs.get];
  /*
   The position of the displayObject on the x axis relative to the local coordinates of the parent.
   An alias to position.x
   */
  external setX : t => float => unit = "x" [@@bs.set];
  /*
   The position of the displayObject on the y axis relative to the local coordinates of the parent.
   An alias to position.y
   */
  external y : t => float = "" [@@bs.get];
  /*
   The position of the displayObject on the y axis relative to the local coordinates of the parent.
   An alias to position.y
   */
  external setY : t => float => unit = "y" [@@bs.set];
  /*
   Current transform of the object based on world (parent) factors
   */
  external worldTransform : t => Matrix.t = "" [@@bs.get];
  /*
   Current transform of the object based on local factors: position, scale, other stuff
   */
  external localTransform : t => Matrix.t = "" [@@bs.get];
  /*
   The coordinate of the object relative to the local coordinates of the parent.
   Assignment by value since pixi-v4.
   */
  external position : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
    "" [@@bs.get];
  /*
   The coordinate of the object relative to the local coordinates of the parent.
   Assignment by value since pixi-v4.
   */
  external setPosition : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
    "position" [@@bs.set];
  /*
   The scale factor of the object.
   Assignment by value since pixi-v4.
   */
  external scale : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
    "" [@@bs.get];
  /*
   The scale factor of the object.
   Assignment by value since pixi-v4.
   */
  external setScale : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
    "scale" [@@bs.set];
  /*
   The pivot point of the displayObject that it rotates around
   Assignment by value since pixi-v4.
   */
  external pivot : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
    "" [@@bs.get];
  /*
   The pivot point of the displayObject that it rotates around
   Assignment by value since pixi-v4.
   */
  external setPivot : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
    "pivot" [@@bs.set];
  /*
   The skew factor for the object in radians.
   Assignment by value since pixi-v4.
   */
  external skew : t => ObservablePoint.t = "" [@@bs.get];
  /*
   The skew factor for the object in radians.
   Assignment by value since pixi-v4.
   */
  external setSkew : t => ObservablePoint.t => unit = "skew" [@@bs.set];
  /*
   The rotation of the object in radians.
   */
  external rotation : t => float = "" [@@bs.get];
  /*
   The rotation of the object in radians.
   */
  external setRotation : t => float => unit = "rotation" [@@bs.set];
  /*
   Indicates if the object is globally visible.
   */
  external worldVisible : t => Js.boolean = "" [@@bs.get];
  /*
   Sets a mask for the displayObject. A mask is an object that limits the visibility of an
   object to the shape of the mask applied to it. In PIXI a regular mask must be a
   PIXI.Graphics or a PIXI.Sprite object. This allows for much faster masking in canvas as it
   utilises shape clipping. To remove a mask, set this property to null.
   */
  external mask : t => unit /* unknown js type: PIXI.Graphics|PIXI.Sprite */ = "" [@@bs.get];
  /*
   Sets a mask for the displayObject. A mask is an object that limits the visibility of an
   object to the shape of the mask applied to it. In PIXI a regular mask must be a
   PIXI.Graphics or a PIXI.Sprite object. This allows for much faster masking in canvas as it
   utilises shape clipping. To remove a mask, set this property to null.
   */
  external setMask : t => unit /* unknown js type: PIXI.Graphics|PIXI.Sprite */ => unit =
    "mask" [@@bs.set];
  /*
   Sets the filters for the displayObject.

   <ul>
   <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
   To remove filters simply set this property to 'null'</li>
   </ul>
   */
  external filters : t => array Filter.t = "" [@@bs.get];
  /*
   Sets the filters for the displayObject.

   <ul>
   <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
   To remove filters simply set this property to 'null'</li>
   </ul>
   */
  external setFilters : t => array Filter.t => unit = "filters" [@@bs.set];
  /*
   Set this to true if you want this display object to be cached as a bitmap.
   This basically takes a snap shot of the display object as it is at that moment. It can
   provide a performance benefit for complex static displayObjects.
   To remove simply set this property to 'false'

   IMPORTANT GOTCHA - make sure that all your textures are preloaded BEFORE setting this property to true
   as it will take a snapshot of what is currently there. If the textures have not loaded then they will not appear.
   */
  external cacheAsBitmap : t => Js.boolean = "" [@@bs.get];
  /*
   Set this to true if you want this display object to be cached as a bitmap.
   This basically takes a snap shot of the display object as it is at that moment. It can
   provide a performance benefit for complex static displayObjects.
   To remove simply set this property to 'false'

   IMPORTANT GOTCHA - make sure that all your textures are preloaded BEFORE setting this property to true
   as it will take a snapshot of what is currently there. If the textures have not loaded then they will not appear.
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
   Interaction shape. Children will be hit first, then this shape will be checked.
   Setting this will cause this shape to be checked in hit tests rather than the displayObject's bounds.
   */
  external hitArea :
    t => unit /* unknown js type: PIXI.Rectangle|PIXI.Circle|PIXI.Ellipse|PIXI.Polygon|PIXI.RoundedRectangle */ =
    "" [@@bs.get];
  /*
   Interaction shape. Children will be hit first, then this shape will be checked.
   Setting this will cause this shape to be checked in hit tests rather than the displayObject's bounds.
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
   This defines what cursor mode is used when the mouse cursor
   is hovered over the displayObject.
   */
  external cursor : t => string = "" [@@bs.get];
  /*
   This defines what cursor mode is used when the mouse cursor
   is hovered over the displayObject.
   */
  external setCursor : t => string => unit = "cursor" [@@bs.set];
};

module CanvasTinter = {
  type t;
};

module Buffer = {
  type t;
  /*
   View on the vertices as a Float32Array for positions
   */
  external float32View : t => unit /* unknown js type: Float32Array */ = "" [@@bs.get];
  /*
   View on the vertices as a Float32Array for positions
   */
  external setFloat32View : t => unit /* unknown js type: Float32Array */ => unit =
    "float32View" [@@bs.set];
  /*
   View on the vertices as a Uint32Array for uvs
   */
  external uint32View : t => unit /* unknown js type: Float32Array */ = "" [@@bs.get];
  /*
   View on the vertices as a Uint32Array for uvs
   */
  external setUint32View : t => unit /* unknown js type: Float32Array */ => unit =
    "uint32View" [@@bs.set];
};

/*
 A Text Object will create a line or multiple lines of text. To split a line you can use '\n' in your text string,
 or add a wordWrap property set to true and and wordWrapWidth property with a value in the style object.

 A Text can be created directly from a string and a style object

 <pre class="prettyprint source lang-js"><code>let text = new PIXI.Text('This is a pixi text',{fontFamily : 'Arial', fontSize: 24, fill : 0xff1010, align : 'center'});</code></pre>
 */
module Text = {
  /*
   A Text Object will create a line or multiple lines of text. To split a line you can use '\n' in your text string,
   or add a wordWrap property set to true and and wordWrapWidth property with a value in the style object.

   A Text can be created directly from a string and a style object

   <pre class="prettyprint source lang-js"><code>let text = new PIXI.Text('This is a pixi text',{fontFamily : 'Arial', fontSize: 24, fill : 0xff1010, align : 'center'});</code></pre>
   */
  type t;
  /*
   The canvas element that everything is drawn to
   */
  external canvas : t => Dom.element = "" [@@bs.get];
  /*
   The canvas element that everything is drawn to
   */
  external setCanvas : t => Dom.element => unit = "canvas" [@@bs.set];
  /*
   The canvas 2d context that everything is drawn with
   */
  external context : t => unit /* unknown js type: CanvasRenderingContext2D */ = "" [@@bs.get];
  /*
   The canvas 2d context that everything is drawn with
   */
  external setContext : t => unit /* unknown js type: CanvasRenderingContext2D */ => unit =
    "context" [@@bs.set];
  /*
   The resolution / device pixel ratio of the canvas. This is set automatically by the renderer.
   */
  external resolution : t => float = "" [@@bs.get];
  /*
   The resolution / device pixel ratio of the canvas. This is set automatically by the renderer.
   */
  external setResolution : t => float => unit = "resolution" [@@bs.set];
  /*
   The width of the Text, setting this will actually modify the scale to achieve the value set
   */
  external width : t => float = "" [@@bs.get];
  /*
   The width of the Text, setting this will actually modify the scale to achieve the value set
   */
  external setWidth : t => float => unit = "width" [@@bs.set];
  /*
   The height of the Text, setting this will actually modify the scale to achieve the value set
   */
  external height : t => float = "" [@@bs.get];
  /*
   The height of the Text, setting this will actually modify the scale to achieve the value set
   */
  external setHeight : t => float => unit = "height" [@@bs.set];
  /*
   Set the style of the text. Set up an event listener to listen for changes on the style
   object and mark the text as dirty.
   */
  external style : t => unit /* unknown js type: object|PIXI.TextStyle */ = "" [@@bs.get];
  /*
   Set the style of the text. Set up an event listener to listen for changes on the style
   object and mark the text as dirty.
   */
  external setStyle : t => unit /* unknown js type: object|PIXI.TextStyle */ => unit =
    "style" [@@bs.set];
  /*
   Set the copy for the text object. To split a line you can use '\n'.
   */
  external text : t => string = "" [@@bs.get];
  /*
   Set the copy for the text object. To split a line you can use '\n'.
   */
  external setText : t => string => unit = "text" [@@bs.set];
  /*
   <p>The blend mode to be applied to the sprite. Apply a value of <code>PIXI.BLEND_MODES.NORMAL</code> to reset the blend mode.</p>
   */
  external blendMode : t => float = "" [@@bs.get];
  /*
   <p>The blend mode to be applied to the sprite. Apply a value of <code>PIXI.BLEND_MODES.NORMAL</code> to reset the blend mode.</p>
   */
  external setBlendMode : t => float => unit = "blendMode" [@@bs.set];
  /*
   The shader that will be used to render the sprite. Set to null to remove a current shader.
   */
  external shader : t => unit /* unknown js type: PIXI.Filter|PIXI.Shader */ = "" [@@bs.get];
  /*
   The shader that will be used to render the sprite. Set to null to remove a current shader.
   */
  external setShader : t => unit /* unknown js type: PIXI.Filter|PIXI.Shader */ => unit =
    "shader" [@@bs.set];
  /*
   Plugin that is responsible for rendering this element.
   Allows to customize the rendering process without overriding '_renderWebGL' &amp; '_renderCanvas' methods.
   */
  external pluginName : t => string = "" [@@bs.get];
  /*
   Plugin that is responsible for rendering this element.
   Allows to customize the rendering process without overriding '_renderWebGL' &amp; '_renderCanvas' methods.
   */
  external setPluginName : t => string => unit = "pluginName" [@@bs.set];
  /*
   The anchor sets the origin point of the texture.
   The default is 0,0 this means the texture's origin is the top left
   Setting the anchor to 0.5,0.5 means the texture's origin is centered
   Setting the anchor to 1,1 would mean the texture's origin point will be the bottom right corner
   */
  external anchor : t => ObservablePoint.t = "" [@@bs.get];
  /*
   The anchor sets the origin point of the texture.
   The default is 0,0 this means the texture's origin is the top left
   Setting the anchor to 0.5,0.5 means the texture's origin is centered
   Setting the anchor to 1,1 would mean the texture's origin point will be the bottom right corner
   */
  external setAnchor : t => ObservablePoint.t => unit = "anchor" [@@bs.set];
  /*
   The tint applied to the sprite. This is a hex value.
   A value of 0xFFFFFF will remove any tint effect.
   */
  external tint : t => float = "" [@@bs.get];
  /*
   The tint applied to the sprite. This is a hex value.
   A value of 0xFFFFFF will remove any tint effect.
   */
  external setTint : t => float => unit = "tint" [@@bs.set];
  /*
   The texture that the sprite is using
   */
  external texture : t => Texture.t = "" [@@bs.get];
  /*
   The texture that the sprite is using
   */
  external setTexture : t => Texture.t => unit = "texture" [@@bs.set];
  /*
   The array of children of this container.
   */
  external children : t => array DisplayObject.t = "" [@@bs.get];
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
   World transform and local transform of this object.
   This will become read-only later, please do not assign anything there unless you know what are you doing
   */
  external transform : t => TransformBase.t = "" [@@bs.get];
  /*
   World transform and local transform of this object.
   This will become read-only later, please do not assign anything there unless you know what are you doing
   */
  external setTransform : t => TransformBase.t => unit = "transform" [@@bs.set];
  /*
   The opacity of the object.
   */
  external alpha : t => float = "" [@@bs.get];
  /*
   The opacity of the object.
   */
  external setAlpha : t => float => unit = "alpha" [@@bs.set];
  /*
   The visibility of the object. If false the object will not be drawn, and
   the updateTransform function will not be called.

   Only affects recursive calls from parent. You can ask for bounds or call updateTransform manually
   */
  external visible : t => Js.boolean = "" [@@bs.get];
  /*
   The visibility of the object. If false the object will not be drawn, and
   the updateTransform function will not be called.

   Only affects recursive calls from parent. You can ask for bounds or call updateTransform manually
   */
  external setVisible : t => Js.boolean => unit = "visible" [@@bs.set];
  /*
   Can this object be rendered, if false the object will not be drawn but the updateTransform
   methods will still be called.

   Only affects recursive calls from parent. You can ask for bounds manually
   */
  external renderable : t => Js.boolean = "" [@@bs.get];
  /*
   Can this object be rendered, if false the object will not be drawn but the updateTransform
   methods will still be called.

   Only affects recursive calls from parent. You can ask for bounds manually
   */
  external setRenderable : t => Js.boolean => unit = "renderable" [@@bs.set];
  /*
   The display object container that contains this display object.
   */
  external parent : t => Container.t = "" [@@bs.get];
  /*
   The multiplied alpha of the displayObject
   */
  external worldAlpha : t => float = "" [@@bs.get];
  /*
   The area the filter is applied to. This is used as more of an optimisation
   rather than figuring out the dimensions of the displayObject each frame you can set this rectangle

   Also works as an interaction mask
   */
  external filterArea : t => Rectangle.t = "" [@@bs.get];
  /*
   The area the filter is applied to. This is used as more of an optimisation
   rather than figuring out the dimensions of the displayObject each frame you can set this rectangle

   Also works as an interaction mask
   */
  external setFilterArea : t => Rectangle.t => unit = "filterArea" [@@bs.set];
  /*
   The position of the displayObject on the x axis relative to the local coordinates of the parent.
   An alias to position.x
   */
  external x : t => float = "" [@@bs.get];
  /*
   The position of the displayObject on the x axis relative to the local coordinates of the parent.
   An alias to position.x
   */
  external setX : t => float => unit = "x" [@@bs.set];
  /*
   The position of the displayObject on the y axis relative to the local coordinates of the parent.
   An alias to position.y
   */
  external y : t => float = "" [@@bs.get];
  /*
   The position of the displayObject on the y axis relative to the local coordinates of the parent.
   An alias to position.y
   */
  external setY : t => float => unit = "y" [@@bs.set];
  /*
   Current transform of the object based on world (parent) factors
   */
  external worldTransform : t => Matrix.t = "" [@@bs.get];
  /*
   Current transform of the object based on local factors: position, scale, other stuff
   */
  external localTransform : t => Matrix.t = "" [@@bs.get];
  /*
   The coordinate of the object relative to the local coordinates of the parent.
   Assignment by value since pixi-v4.
   */
  external position : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
    "" [@@bs.get];
  /*
   The coordinate of the object relative to the local coordinates of the parent.
   Assignment by value since pixi-v4.
   */
  external setPosition : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
    "position" [@@bs.set];
  /*
   The scale factor of the object.
   Assignment by value since pixi-v4.
   */
  external scale : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
    "" [@@bs.get];
  /*
   The scale factor of the object.
   Assignment by value since pixi-v4.
   */
  external setScale : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
    "scale" [@@bs.set];
  /*
   The pivot point of the displayObject that it rotates around
   Assignment by value since pixi-v4.
   */
  external pivot : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
    "" [@@bs.get];
  /*
   The pivot point of the displayObject that it rotates around
   Assignment by value since pixi-v4.
   */
  external setPivot : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
    "pivot" [@@bs.set];
  /*
   The skew factor for the object in radians.
   Assignment by value since pixi-v4.
   */
  external skew : t => ObservablePoint.t = "" [@@bs.get];
  /*
   The skew factor for the object in radians.
   Assignment by value since pixi-v4.
   */
  external setSkew : t => ObservablePoint.t => unit = "skew" [@@bs.set];
  /*
   The rotation of the object in radians.
   */
  external rotation : t => float = "" [@@bs.get];
  /*
   The rotation of the object in radians.
   */
  external setRotation : t => float => unit = "rotation" [@@bs.set];
  /*
   Indicates if the object is globally visible.
   */
  external worldVisible : t => Js.boolean = "" [@@bs.get];
  /*
   Sets a mask for the displayObject. A mask is an object that limits the visibility of an
   object to the shape of the mask applied to it. In PIXI a regular mask must be a
   PIXI.Graphics or a PIXI.Sprite object. This allows for much faster masking in canvas as it
   utilises shape clipping. To remove a mask, set this property to null.
   */
  external mask : t => unit /* unknown js type: PIXI.Graphics|PIXI.Sprite */ = "" [@@bs.get];
  /*
   Sets a mask for the displayObject. A mask is an object that limits the visibility of an
   object to the shape of the mask applied to it. In PIXI a regular mask must be a
   PIXI.Graphics or a PIXI.Sprite object. This allows for much faster masking in canvas as it
   utilises shape clipping. To remove a mask, set this property to null.
   */
  external setMask : t => unit /* unknown js type: PIXI.Graphics|PIXI.Sprite */ => unit =
    "mask" [@@bs.set];
  /*
   Sets the filters for the displayObject.

   <ul>
   <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
   To remove filters simply set this property to 'null'</li>
   </ul>
   */
  external filters : t => array Filter.t = "" [@@bs.get];
  /*
   Sets the filters for the displayObject.

   <ul>
   <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
   To remove filters simply set this property to 'null'</li>
   </ul>
   */
  external setFilters : t => array Filter.t => unit = "filters" [@@bs.set];
  /*
   Set this to true if you want this display object to be cached as a bitmap.
   This basically takes a snap shot of the display object as it is at that moment. It can
   provide a performance benefit for complex static displayObjects.
   To remove simply set this property to 'false'

   IMPORTANT GOTCHA - make sure that all your textures are preloaded BEFORE setting this property to true
   as it will take a snapshot of what is currently there. If the textures have not loaded then they will not appear.
   */
  external cacheAsBitmap : t => Js.boolean = "" [@@bs.get];
  /*
   Set this to true if you want this display object to be cached as a bitmap.
   This basically takes a snap shot of the display object as it is at that moment. It can
   provide a performance benefit for complex static displayObjects.
   To remove simply set this property to 'false'

   IMPORTANT GOTCHA - make sure that all your textures are preloaded BEFORE setting this property to true
   as it will take a snapshot of what is currently there. If the textures have not loaded then they will not appear.
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
   Interaction shape. Children will be hit first, then this shape will be checked.
   Setting this will cause this shape to be checked in hit tests rather than the displayObject's bounds.
   */
  external hitArea :
    t => unit /* unknown js type: PIXI.Rectangle|PIXI.Circle|PIXI.Ellipse|PIXI.Polygon|PIXI.RoundedRectangle */ =
    "" [@@bs.get];
  /*
   Interaction shape. Children will be hit first, then this shape will be checked.
   Setting this will cause this shape to be checked in hit tests rather than the displayObject's bounds.
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
   This defines what cursor mode is used when the mouse cursor
   is hovered over the displayObject.
   */
  external cursor : t => string = "" [@@bs.get];
  /*
   This defines what cursor mode is used when the mouse cursor
   is hovered over the displayObject.
   */
  external setCursor : t => string => unit = "cursor" [@@bs.set];
};

/*
 The TextMetrics object represents the measurement of a block of text with a specified style.
 */
module TextMetrics = {
  /*
   The TextMetrics object represents the measurement of a block of text with a specified style.
   */
  type t;
  module FontMetrics = {
    type t;
  };
};

/*
 A TextStyle Object decorates a Text Object. It can be shared between
 multiple Text objects. Changing the style will update all text objects using it.
 */
module TextStyle = {
  /*
   A TextStyle Object decorates a Text Object. It can be shared between
   multiple Text objects. Changing the style will update all text objects using it.
   */
  type t;
};

/*
 A BaseRenderTexture is a special texture that allows any Pixi display object to be rendered to it.

 <p><strong>Hint</strong>: All DisplayObjects (i.e. Sprites) that render to a BaseRenderTexture should be preloaded
 otherwise black rectangles will be drawn instead.</p>
 A BaseRenderTexture takes a snapshot of any Display Object given to its render method. The position
 and rotation of the given Display Objects is ignored. For example:

 <pre class="prettyprint source lang-js"><code>let renderer = PIXI.autoDetectRenderer(1024, 1024, { view: canvas, ratio: 1 });
 let baseRenderTexture = new PIXI.BaseRenderTexture(renderer, 800, 600);
 let sprite = PIXI.Sprite.fromImage(&quot;spinObj_01.png&quot;);

 sprite.position.x = 800/2;
 sprite.position.y = 600/2;
 sprite.anchor.x = 0.5;
 sprite.anchor.y = 0.5;

 baseRenderTexture.render(sprite);</code></pre>The Sprite in this case will be rendered using its local transform. To render this sprite at 0,0
 you can clear the transform

 <pre class="prettyprint source lang-js"><code>
 sprite.setTransform()

 let baseRenderTexture = new PIXI.BaseRenderTexture(100, 100);
 let renderTexture = new PIXI.RenderTexture(baseRenderTexture);

 renderer.render(sprite, renderTexture);  // Renders to center of RenderTexture</code></pre>
 */
module BaseRenderTexture = {
  /*
   A BaseRenderTexture is a special texture that allows any Pixi display object to be rendered to it.

   <p><strong>Hint</strong>: All DisplayObjects (i.e. Sprites) that render to a BaseRenderTexture should be preloaded
   otherwise black rectangles will be drawn instead.</p>
   A BaseRenderTexture takes a snapshot of any Display Object given to its render method. The position
   and rotation of the given Display Objects is ignored. For example:

   <pre class="prettyprint source lang-js"><code>let renderer = PIXI.autoDetectRenderer(1024, 1024, { view: canvas, ratio: 1 });
   let baseRenderTexture = new PIXI.BaseRenderTexture(renderer, 800, 600);
   let sprite = PIXI.Sprite.fromImage(&quot;spinObj_01.png&quot;);

   sprite.position.x = 800/2;
   sprite.position.y = 600/2;
   sprite.anchor.x = 0.5;
   sprite.anchor.y = 0.5;

   baseRenderTexture.render(sprite);</code></pre>The Sprite in this case will be rendered using its local transform. To render this sprite at 0,0
   you can clear the transform

   <pre class="prettyprint source lang-js"><code>
   sprite.setTransform()

   let baseRenderTexture = new PIXI.BaseRenderTexture(100, 100);
   let renderTexture = new PIXI.RenderTexture(baseRenderTexture);

   renderer.render(sprite, renderTexture);  // Renders to center of RenderTexture</code></pre>
   */
  type t;
  /*
   This will let the renderer know if the texture is valid. If it's not then it cannot be rendered.
   */
  external valid : t => Js.boolean = "" [@@bs.get];
  /*
   This will let the renderer know if the texture is valid. If it's not then it cannot be rendered.
   */
  external setValid : t => Js.boolean => unit = "valid" [@@bs.set];
  /*
   The resolution / device pixel ratio of the texture
   */
  external resolution : t => float = "" [@@bs.get];
  /*
   The resolution / device pixel ratio of the texture
   */
  external setResolution : t => float => unit = "resolution" [@@bs.set];
  /*
   The width of the base texture set when the image has loaded
   */
  external width : t => float = "" [@@bs.get];
  /*
   The height of the base texture set when the image has loaded
   */
  external height : t => float = "" [@@bs.get];
  /*
   Used to store the actual width of the source of this texture
   */
  external realWidth : t => float = "" [@@bs.get];
  /*
   Used to store the actual height of the source of this texture
   */
  external realHeight : t => float = "" [@@bs.get];
  /*
   The scale mode to apply when scaling this texture
   */
  external scaleMode : t => float = "" [@@bs.get];
  /*
   The scale mode to apply when scaling this texture
   */
  external setScaleMode : t => float => unit = "scaleMode" [@@bs.set];
  /*
   Set to true once the base texture has successfully loaded.

   This is never true if the underlying source fails to load or has no texture data.
   */
  external hasLoaded : t => Js.boolean = "" [@@bs.get];
  /*
   Set to true if the source is currently loading.

   If an Image source is loading the 'loaded' or 'error' event will be
   dispatched when the operation ends. An underyling source that is
   immediately-available bypasses loading entirely.
   */
  external isLoading : t => Js.boolean = "" [@@bs.get];
  /*
   The image source that is used to create the texture.

   TODO: Make this a setter that calls loadSource();
   */
  external source : t => unit /* unknown js type: HTMLImageElement|HTMLCanvasElement */ =
    "" [@@bs.get];
  /*
   The image source that is used to create the texture. This is used to
   store the original Svg source when it is replaced with a canvas element.

   TODO: Currently not in use but could be used when re-scaling svg.
   */
  external origSource : t => unit /* unknown js type: Image */ = "" [@@bs.get];
  /*
   <p>Type of image defined in source, eg. <code>png</code> or <code>svg</code></p>
   */
  external imageType : t => string = "" [@@bs.get];
  /*
   Scale for source image. Used with Svg images to scale them before rasterization.
   */
  external sourceScale : t => float = "" [@@bs.get];
  /*
   Controls if RGB channels should be pre-multiplied by Alpha  (WebGL only)
   All blend modes, and shaders written for default value. Change it on your own risk.
   */
  external premultipliedAlpha : t => Js.boolean = "" [@@bs.get];
  /*
   Controls if RGB channels should be pre-multiplied by Alpha  (WebGL only)
   All blend modes, and shaders written for default value. Change it on your own risk.
   */
  external setPremultipliedAlpha : t => Js.boolean => unit = "premultipliedAlpha" [@@bs.set];
  /*
   The image url of the texture
   */
  external imageUrl : t => string = "" [@@bs.get];
  /*
   The image url of the texture
   */
  external setImageUrl : t => string => unit = "imageUrl" [@@bs.set];
  /*
   Set this to true if a mipmap of this texture needs to be generated. This value needs
   to be set before the texture is used
   Also the texture must be a power of two size to work
   */
  external mipmap : t => Js.boolean = "" [@@bs.get];
  /*
   Set this to true if a mipmap of this texture needs to be generated. This value needs
   to be set before the texture is used
   Also the texture must be a power of two size to work
   */
  external setMipmap : t => Js.boolean => unit = "mipmap" [@@bs.set];
  /*
   WebGL Texture wrap mode
   */
  external wrapMode : t => float = "" [@@bs.get];
  /*
   WebGL Texture wrap mode
   */
  external setWrapMode : t => float => unit = "wrapMode" [@@bs.set];
  /*
   The ids under which this BaseTexture has been added to the base texture cache. This is
   automatically set as long as BaseTexture.addToCache is used, but may not be set if a
   BaseTexture is added directly to the BaseTextureCache array.
   */
  external textureCacheIds : t => array string = "" [@@bs.get];
  /*
   The ids under which this BaseTexture has been added to the base texture cache. This is
   automatically set as long as BaseTexture.addToCache is used, but may not be set if a
   BaseTexture is added directly to the BaseTextureCache array.
   */
  external setTextureCacheIds : t => array string => unit = "textureCacheIds" [@@bs.set];
};

/*
 A texture stores the information that represents an image. All textures have a base texture.
 */
module BaseTexture = {
  /*
   A texture stores the information that represents an image. All textures have a base texture.
   */
  type t;
  /*
   The resolution / device pixel ratio of the texture
   */
  external resolution : t => float = "" [@@bs.get];
  /*
   The resolution / device pixel ratio of the texture
   */
  external setResolution : t => float => unit = "resolution" [@@bs.set];
  /*
   The width of the base texture set when the image has loaded
   */
  external width : t => float = "" [@@bs.get];
  /*
   The height of the base texture set when the image has loaded
   */
  external height : t => float = "" [@@bs.get];
  /*
   Used to store the actual width of the source of this texture
   */
  external realWidth : t => float = "" [@@bs.get];
  /*
   Used to store the actual height of the source of this texture
   */
  external realHeight : t => float = "" [@@bs.get];
  /*
   The scale mode to apply when scaling this texture
   */
  external scaleMode : t => float = "" [@@bs.get];
  /*
   The scale mode to apply when scaling this texture
   */
  external setScaleMode : t => float => unit = "scaleMode" [@@bs.set];
  /*
   Set to true once the base texture has successfully loaded.

   This is never true if the underlying source fails to load or has no texture data.
   */
  external hasLoaded : t => Js.boolean = "" [@@bs.get];
  /*
   Set to true if the source is currently loading.

   If an Image source is loading the 'loaded' or 'error' event will be
   dispatched when the operation ends. An underyling source that is
   immediately-available bypasses loading entirely.
   */
  external isLoading : t => Js.boolean = "" [@@bs.get];
  /*
   The image source that is used to create the texture.

   TODO: Make this a setter that calls loadSource();
   */
  external source : t => unit /* unknown js type: HTMLImageElement|HTMLCanvasElement */ =
    "" [@@bs.get];
  /*
   The image source that is used to create the texture. This is used to
   store the original Svg source when it is replaced with a canvas element.

   TODO: Currently not in use but could be used when re-scaling svg.
   */
  external origSource : t => unit /* unknown js type: Image */ = "" [@@bs.get];
  /*
   <p>Type of image defined in source, eg. <code>png</code> or <code>svg</code></p>
   */
  external imageType : t => string = "" [@@bs.get];
  /*
   Scale for source image. Used with Svg images to scale them before rasterization.
   */
  external sourceScale : t => float = "" [@@bs.get];
  /*
   Controls if RGB channels should be pre-multiplied by Alpha  (WebGL only)
   All blend modes, and shaders written for default value. Change it on your own risk.
   */
  external premultipliedAlpha : t => Js.boolean = "" [@@bs.get];
  /*
   Controls if RGB channels should be pre-multiplied by Alpha  (WebGL only)
   All blend modes, and shaders written for default value. Change it on your own risk.
   */
  external setPremultipliedAlpha : t => Js.boolean => unit = "premultipliedAlpha" [@@bs.set];
  /*
   The image url of the texture
   */
  external imageUrl : t => string = "" [@@bs.get];
  /*
   The image url of the texture
   */
  external setImageUrl : t => string => unit = "imageUrl" [@@bs.set];
  /*
   Set this to true if a mipmap of this texture needs to be generated. This value needs
   to be set before the texture is used
   Also the texture must be a power of two size to work
   */
  external mipmap : t => Js.boolean = "" [@@bs.get];
  /*
   Set this to true if a mipmap of this texture needs to be generated. This value needs
   to be set before the texture is used
   Also the texture must be a power of two size to work
   */
  external setMipmap : t => Js.boolean => unit = "mipmap" [@@bs.set];
  /*
   WebGL Texture wrap mode
   */
  external wrapMode : t => float = "" [@@bs.get];
  /*
   WebGL Texture wrap mode
   */
  external setWrapMode : t => float => unit = "wrapMode" [@@bs.set];
  /*
   The ids under which this BaseTexture has been added to the base texture cache. This is
   automatically set as long as BaseTexture.addToCache is used, but may not be set if a
   BaseTexture is added directly to the BaseTextureCache array.
   */
  external textureCacheIds : t => array string = "" [@@bs.get];
  /*
   The ids under which this BaseTexture has been added to the base texture cache. This is
   automatically set as long as BaseTexture.addToCache is used, but may not be set if a
   BaseTexture is added directly to the BaseTextureCache array.
   */
  external setTextureCacheIds : t => array string => unit = "textureCacheIds" [@@bs.set];
};

/*
 A RenderTexture is a special texture that allows any Pixi display object to be rendered to it.

 <p><strong>Hint</strong>: All DisplayObjects (i.e. Sprites) that render to a RenderTexture should be preloaded
 otherwise black rectangles will be drawn instead.</p>
 A RenderTexture takes a snapshot of any Display Object given to its render method. For example:

 <pre class="prettyprint source lang-js"><code>let renderer = PIXI.autoDetectRenderer(1024, 1024, { view: canvas, ratio: 1 });
 let renderTexture = PIXI.RenderTexture.create(800, 600);
 let sprite = PIXI.Sprite.fromImage(&quot;spinObj_01.png&quot;);

 sprite.position.x = 800/2;
 sprite.position.y = 600/2;
 sprite.anchor.x = 0.5;
 sprite.anchor.y = 0.5;

 renderer.render(sprite, renderTexture);</code></pre>The Sprite in this case will be rendered using its local transform. To render this sprite at 0,0
 you can clear the transform

 <pre class="prettyprint source lang-js"><code>
 sprite.setTransform()

 let renderTexture = new PIXI.RenderTexture.create(100, 100);

 renderer.render(sprite, renderTexture);  // Renders to center of RenderTexture</code></pre>
 */
module RenderTexture = {
  /*
   A RenderTexture is a special texture that allows any Pixi display object to be rendered to it.

   <p><strong>Hint</strong>: All DisplayObjects (i.e. Sprites) that render to a RenderTexture should be preloaded
   otherwise black rectangles will be drawn instead.</p>
   A RenderTexture takes a snapshot of any Display Object given to its render method. For example:

   <pre class="prettyprint source lang-js"><code>let renderer = PIXI.autoDetectRenderer(1024, 1024, { view: canvas, ratio: 1 });
   let renderTexture = PIXI.RenderTexture.create(800, 600);
   let sprite = PIXI.Sprite.fromImage(&quot;spinObj_01.png&quot;);

   sprite.position.x = 800/2;
   sprite.position.y = 600/2;
   sprite.anchor.x = 0.5;
   sprite.anchor.y = 0.5;

   renderer.render(sprite, renderTexture);</code></pre>The Sprite in this case will be rendered using its local transform. To render this sprite at 0,0
   you can clear the transform

   <pre class="prettyprint source lang-js"><code>
   sprite.setTransform()

   let renderTexture = new PIXI.RenderTexture.create(100, 100);

   renderer.render(sprite, renderTexture);  // Renders to center of RenderTexture</code></pre>
   */
  type t;
  /*
   This will let the renderer know if the texture is valid. If it's not then it cannot be rendered.
   */
  external valid : t => Js.boolean = "" [@@bs.get];
  /*
   This will let the renderer know if the texture is valid. If it's not then it cannot be rendered.
   */
  external setValid : t => Js.boolean => unit = "valid" [@@bs.set];
  /*
   Does this Texture have any frame data assigned to it?
   */
  external noFrame : t => Js.boolean = "" [@@bs.get];
  /*
   Does this Texture have any frame data assigned to it?
   */
  external setNoFrame : t => Js.boolean => unit = "noFrame" [@@bs.set];
  /*
   The base texture that this texture uses.
   */
  external baseTexture : t => BaseTexture.t = "" [@@bs.get];
  /*
   The base texture that this texture uses.
   */
  external setBaseTexture : t => BaseTexture.t => unit = "baseTexture" [@@bs.set];
  /*
   This is the area of the BaseTexture image to actually copy to the Canvas / WebGL when rendering,
   irrespective of the actual frame size or placement (which can be influenced by trimmed texture atlases)
   */
  external _frame : t => Rectangle.t = "" [@@bs.get];
  /*
   This is the area of the BaseTexture image to actually copy to the Canvas / WebGL when rendering,
   irrespective of the actual frame size or placement (which can be influenced by trimmed texture atlases)
   */
  external set_frame : t => Rectangle.t => unit = "_frame" [@@bs.set];
  /*
   This is the trimmed area of original texture, before it was put in atlas
   */
  external trim : t => Rectangle.t = "" [@@bs.get];
  /*
   This is the trimmed area of original texture, before it was put in atlas
   */
  external setTrim : t => Rectangle.t => unit = "trim" [@@bs.set];
  /*
   This will let a renderer know that a texture has been updated (used mainly for webGL uv updates)
   */
  external requiresUpdate : t => Js.boolean = "" [@@bs.get];
  /*
   This will let a renderer know that a texture has been updated (used mainly for webGL uv updates)
   */
  external setRequiresUpdate : t => Js.boolean => unit = "requiresUpdate" [@@bs.set];
  /*
   This is the area of original texture, before it was put in atlas
   */
  external orig : t => Rectangle.t = "" [@@bs.get];
  /*
   This is the area of original texture, before it was put in atlas
   */
  external setOrig : t => Rectangle.t => unit = "orig" [@@bs.set];
  /*
   The ids under which this Texture has been added to the texture cache. This is
   automatically set as long as Texture.addToCache is used, but may not be set if a
   Texture is added directly to the TextureCache array.
   */
  external textureCacheIds : t => array string = "" [@@bs.get];
  /*
   The ids under which this Texture has been added to the texture cache. This is
   automatically set as long as Texture.addToCache is used, but may not be set if a
   Texture is added directly to the TextureCache array.
   */
  external setTextureCacheIds : t => array string => unit = "textureCacheIds" [@@bs.set];
  /*
   The frame specifies the region of the base texture that this texture uses.
   */
  external frame : t => Rectangle.t = "" [@@bs.get];
  /*
   The frame specifies the region of the base texture that this texture uses.
   */
  external setFrame : t => Rectangle.t => unit = "frame" [@@bs.set];
  /*
   Indicates whether the texture is rotated inside the atlas
   set to 2 to compensate for texture packer rotation
   set to 6 to compensate for spine packer rotation
   can be used to rotate or mirror sprites
   See {@link PIXI.GroupD8} for explanation
   */
  external rotate : t => float = "" [@@bs.get];
  /*
   Indicates whether the texture is rotated inside the atlas
   set to 2 to compensate for texture packer rotation
   set to 6 to compensate for spine packer rotation
   can be used to rotate or mirror sprites
   See {@link PIXI.GroupD8} for explanation
   */
  external setRotate : t => float => unit = "rotate" [@@bs.set];
  /*
   The width of the Texture in pixels.
   */
  external width : t => float = "" [@@bs.get];
  /*
   The width of the Texture in pixels.
   */
  external setWidth : t => float => unit = "width" [@@bs.set];
  /*
   The height of the Texture in pixels.
   */
  external height : t => float = "" [@@bs.get];
  /*
   The height of the Texture in pixels.
   */
  external setHeight : t => float => unit = "height" [@@bs.set];
};

/*
 Utility class for maintaining reference to a collection
 of Textures on a single Spritesheet.
 */
module Spritesheet = {
  /*
   Utility class for maintaining reference to a collection
   of Textures on a single Spritesheet.
   */
  type t;
  /*
   Reference to ths source texture
   */
  external baseTexture : t => BaseTexture.t = "" [@@bs.get];
  /*
   Reference to ths source texture
   */
  external setBaseTexture : t => BaseTexture.t => unit = "baseTexture" [@@bs.set];
  /*
   Map of spritesheet textures.
   */
  external textures : t => unit /* unknown js type: Object */ = "" [@@bs.get];
  /*
   Map of spritesheet textures.
   */
  external setTextures : t => unit /* unknown js type: Object */ => unit = "textures" [@@bs.set];
  /*
   Reference to the original JSON data.
   */
  external data : t => unit /* unknown js type: Object */ = "" [@@bs.get];
  /*
   Reference to the original JSON data.
   */
  external setData : t => unit /* unknown js type: Object */ => unit = "data" [@@bs.set];
  /*
   The resolution of the spritesheet.
   */
  external resolution : t => float = "" [@@bs.get];
  /*
   The resolution of the spritesheet.
   */
  external setResolution : t => float => unit = "resolution" [@@bs.set];
};

/*
 A texture stores the information that represents an image or part of an image. It cannot be added
 to the display list directly. Instead use it as the texture for a Sprite. If no frame is provided
 then the whole image is used.

 You can directly create a texture from an image and then reuse it multiple times like this :

 <pre class="prettyprint source lang-js"><code>let texture = PIXI.Texture.fromImage('assets/image.png');
 let sprite1 = new PIXI.Sprite(texture);
 let sprite2 = new PIXI.Sprite(texture);</code></pre>Textures made from SVGs, loaded or not, cannot be used before the file finishes processing.
 You can check for this by checking the sprite's _textureID property.

 <pre class="prettyprint source lang-js"><code>var texture = PIXI.Texture.fromImage('assets/image.svg');
 var sprite1 = new PIXI.Sprite(texture);
 //sprite1._textureID should not be undefined if the texture has finished processing the SVG file</code></pre>You can use a ticker or rAF to ensure your sprites load the finished textures after processing. See issue #3068.
 */
module Texture = {
  /*
   A texture stores the information that represents an image or part of an image. It cannot be added
   to the display list directly. Instead use it as the texture for a Sprite. If no frame is provided
   then the whole image is used.

   You can directly create a texture from an image and then reuse it multiple times like this :

   <pre class="prettyprint source lang-js"><code>let texture = PIXI.Texture.fromImage('assets/image.png');
   let sprite1 = new PIXI.Sprite(texture);
   let sprite2 = new PIXI.Sprite(texture);</code></pre>Textures made from SVGs, loaded or not, cannot be used before the file finishes processing.
   You can check for this by checking the sprite's _textureID property.

   <pre class="prettyprint source lang-js"><code>var texture = PIXI.Texture.fromImage('assets/image.svg');
   var sprite1 = new PIXI.Sprite(texture);
   //sprite1._textureID should not be undefined if the texture has finished processing the SVG file</code></pre>You can use a ticker or rAF to ensure your sprites load the finished textures after processing. See issue #3068.
   */
  type t;
  /*
   Does this Texture have any frame data assigned to it?
   */
  external noFrame : t => Js.boolean = "" [@@bs.get];
  /*
   Does this Texture have any frame data assigned to it?
   */
  external setNoFrame : t => Js.boolean => unit = "noFrame" [@@bs.set];
  /*
   The base texture that this texture uses.
   */
  external baseTexture : t => BaseTexture.t = "" [@@bs.get];
  /*
   The base texture that this texture uses.
   */
  external setBaseTexture : t => BaseTexture.t => unit = "baseTexture" [@@bs.set];
  /*
   This is the area of the BaseTexture image to actually copy to the Canvas / WebGL when rendering,
   irrespective of the actual frame size or placement (which can be influenced by trimmed texture atlases)
   */
  external _frame : t => Rectangle.t = "" [@@bs.get];
  /*
   This is the area of the BaseTexture image to actually copy to the Canvas / WebGL when rendering,
   irrespective of the actual frame size or placement (which can be influenced by trimmed texture atlases)
   */
  external set_frame : t => Rectangle.t => unit = "_frame" [@@bs.set];
  /*
   This is the trimmed area of original texture, before it was put in atlas
   */
  external trim : t => Rectangle.t = "" [@@bs.get];
  /*
   This is the trimmed area of original texture, before it was put in atlas
   */
  external setTrim : t => Rectangle.t => unit = "trim" [@@bs.set];
  /*
   This will let the renderer know if the texture is valid. If it's not then it cannot be rendered.
   */
  external valid : t => Js.boolean = "" [@@bs.get];
  /*
   This will let the renderer know if the texture is valid. If it's not then it cannot be rendered.
   */
  external setValid : t => Js.boolean => unit = "valid" [@@bs.set];
  /*
   This will let a renderer know that a texture has been updated (used mainly for webGL uv updates)
   */
  external requiresUpdate : t => Js.boolean = "" [@@bs.get];
  /*
   This will let a renderer know that a texture has been updated (used mainly for webGL uv updates)
   */
  external setRequiresUpdate : t => Js.boolean => unit = "requiresUpdate" [@@bs.set];
  /*
   This is the area of original texture, before it was put in atlas
   */
  external orig : t => Rectangle.t = "" [@@bs.get];
  /*
   This is the area of original texture, before it was put in atlas
   */
  external setOrig : t => Rectangle.t => unit = "orig" [@@bs.set];
  /*
   Extra field for extra plugins. May contain clamp settings and some matrices
   */
  external transform : t => unit /* unknown js type: Object */ = "" [@@bs.get];
  /*
   Extra field for extra plugins. May contain clamp settings and some matrices
   */
  external setTransform : t => unit /* unknown js type: Object */ => unit = "transform" [@@bs.set];
  /*
   The ids under which this Texture has been added to the texture cache. This is
   automatically set as long as Texture.addToCache is used, but may not be set if a
   Texture is added directly to the TextureCache array.
   */
  external textureCacheIds : t => array string = "" [@@bs.get];
  /*
   The ids under which this Texture has been added to the texture cache. This is
   automatically set as long as Texture.addToCache is used, but may not be set if a
   Texture is added directly to the TextureCache array.
   */
  external setTextureCacheIds : t => array string => unit = "textureCacheIds" [@@bs.set];
  /*
   The frame specifies the region of the base texture that this texture uses.
   */
  external frame : t => Rectangle.t = "" [@@bs.get];
  /*
   The frame specifies the region of the base texture that this texture uses.
   */
  external setFrame : t => Rectangle.t => unit = "frame" [@@bs.set];
  /*
   Indicates whether the texture is rotated inside the atlas
   set to 2 to compensate for texture packer rotation
   set to 6 to compensate for spine packer rotation
   can be used to rotate or mirror sprites
   See {@link PIXI.GroupD8} for explanation
   */
  external rotate : t => float = "" [@@bs.get];
  /*
   Indicates whether the texture is rotated inside the atlas
   set to 2 to compensate for texture packer rotation
   set to 6 to compensate for spine packer rotation
   can be used to rotate or mirror sprites
   See {@link PIXI.GroupD8} for explanation
   */
  external setRotate : t => float => unit = "rotate" [@@bs.set];
  /*
   The width of the Texture in pixels.
   */
  external width : t => float = "" [@@bs.get];
  /*
   The width of the Texture in pixels.
   */
  external setWidth : t => float => unit = "width" [@@bs.set];
  /*
   The height of the Texture in pixels.
   */
  external height : t => float = "" [@@bs.get];
  /*
   The height of the Texture in pixels.
   */
  external setHeight : t => float => unit = "height" [@@bs.set];
};

/*
 A texture of a [playing] Video.

 Video base textures mimic Pixi BaseTexture.from.... method in their creation process.

 This can be used in several ways, such as:

 <pre class="prettyprint source lang-js"><code>let texture = PIXI.VideoBaseTexture.fromUrl('http://mydomain.com/video.mp4');

 let texture = PIXI.VideoBaseTexture.fromUrl({ src: 'http://mydomain.com/video.mp4', mime: 'video/mp4' });

 let texture = PIXI.VideoBaseTexture.fromUrls(['/video.webm', '/video.mp4']);

 let texture = PIXI.VideoBaseTexture.fromUrls([
     { src: '/video.webm', mime: 'video/webm' },
     { src: '/video.mp4', mime: 'video/mp4' }
 ]);</code></pre><p>See the <a href="http://www.goodboydigital.com/pixijs/examples/deus/">&quot;deus&quot; demo</a>.</p>
 */
module VideoBaseTexture = {
  /*
   A texture of a [playing] Video.

   Video base textures mimic Pixi BaseTexture.from.... method in their creation process.

   This can be used in several ways, such as:

   <pre class="prettyprint source lang-js"><code>let texture = PIXI.VideoBaseTexture.fromUrl('http://mydomain.com/video.mp4');

   let texture = PIXI.VideoBaseTexture.fromUrl({ src: 'http://mydomain.com/video.mp4', mime: 'video/mp4' });

   let texture = PIXI.VideoBaseTexture.fromUrls(['/video.webm', '/video.mp4']);

   let texture = PIXI.VideoBaseTexture.fromUrls([
       { src: '/video.webm', mime: 'video/webm' },
       { src: '/video.mp4', mime: 'video/mp4' }
   ]);</code></pre><p>See the <a href="http://www.goodboydigital.com/pixijs/examples/deus/">&quot;deus&quot; demo</a>.</p>
   */
  type t;
  /*
   When set to true will automatically play videos used by this texture once
   they are loaded. If false, it will not modify the playing state.
   */
  external autoPlay : t => Js.boolean = "" [@@bs.get];
  /*
   When set to true will automatically play videos used by this texture once
   they are loaded. If false, it will not modify the playing state.
   */
  external setAutoPlay : t => Js.boolean => unit = "autoPlay" [@@bs.set];
  /*
   Should the base texture automatically update itself, set to true by default
   */
  external autoUpdate : t => Js.boolean = "" [@@bs.get];
  /*
   Should the base texture automatically update itself, set to true by default
   */
  external setAutoUpdate : t => Js.boolean => unit = "autoUpdate" [@@bs.set];
  /*
   The resolution / device pixel ratio of the texture
   */
  external resolution : t => float = "" [@@bs.get];
  /*
   The resolution / device pixel ratio of the texture
   */
  external setResolution : t => float => unit = "resolution" [@@bs.set];
  /*
   The width of the base texture set when the image has loaded
   */
  external width : t => float = "" [@@bs.get];
  /*
   The height of the base texture set when the image has loaded
   */
  external height : t => float = "" [@@bs.get];
  /*
   Used to store the actual width of the source of this texture
   */
  external realWidth : t => float = "" [@@bs.get];
  /*
   Used to store the actual height of the source of this texture
   */
  external realHeight : t => float = "" [@@bs.get];
  /*
   The scale mode to apply when scaling this texture
   */
  external scaleMode : t => float = "" [@@bs.get];
  /*
   The scale mode to apply when scaling this texture
   */
  external setScaleMode : t => float => unit = "scaleMode" [@@bs.set];
  /*
   Set to true once the base texture has successfully loaded.

   This is never true if the underlying source fails to load or has no texture data.
   */
  external hasLoaded : t => Js.boolean = "" [@@bs.get];
  /*
   Set to true if the source is currently loading.

   If an Image source is loading the 'loaded' or 'error' event will be
   dispatched when the operation ends. An underyling source that is
   immediately-available bypasses loading entirely.
   */
  external isLoading : t => Js.boolean = "" [@@bs.get];
  /*
   The image source that is used to create the texture.

   TODO: Make this a setter that calls loadSource();
   */
  external source : t => unit /* unknown js type: HTMLImageElement|HTMLCanvasElement */ =
    "" [@@bs.get];
  /*
   The image source that is used to create the texture. This is used to
   store the original Svg source when it is replaced with a canvas element.

   TODO: Currently not in use but could be used when re-scaling svg.
   */
  external origSource : t => unit /* unknown js type: Image */ = "" [@@bs.get];
  /*
   <p>Type of image defined in source, eg. <code>png</code> or <code>svg</code></p>
   */
  external imageType : t => string = "" [@@bs.get];
  /*
   Scale for source image. Used with Svg images to scale them before rasterization.
   */
  external sourceScale : t => float = "" [@@bs.get];
  /*
   Controls if RGB channels should be pre-multiplied by Alpha  (WebGL only)
   All blend modes, and shaders written for default value. Change it on your own risk.
   */
  external premultipliedAlpha : t => Js.boolean = "" [@@bs.get];
  /*
   Controls if RGB channels should be pre-multiplied by Alpha  (WebGL only)
   All blend modes, and shaders written for default value. Change it on your own risk.
   */
  external setPremultipliedAlpha : t => Js.boolean => unit = "premultipliedAlpha" [@@bs.set];
  /*
   The image url of the texture
   */
  external imageUrl : t => string = "" [@@bs.get];
  /*
   The image url of the texture
   */
  external setImageUrl : t => string => unit = "imageUrl" [@@bs.set];
  /*
   Set this to true if a mipmap of this texture needs to be generated. This value needs
   to be set before the texture is used
   Also the texture must be a power of two size to work
   */
  external mipmap : t => Js.boolean = "" [@@bs.get];
  /*
   Set this to true if a mipmap of this texture needs to be generated. This value needs
   to be set before the texture is used
   Also the texture must be a power of two size to work
   */
  external setMipmap : t => Js.boolean => unit = "mipmap" [@@bs.set];
  /*
   WebGL Texture wrap mode
   */
  external wrapMode : t => float = "" [@@bs.get];
  /*
   WebGL Texture wrap mode
   */
  external setWrapMode : t => float => unit = "wrapMode" [@@bs.set];
  /*
   The ids under which this BaseTexture has been added to the base texture cache. This is
   automatically set as long as BaseTexture.addToCache is used, but may not be set if a
   BaseTexture is added directly to the BaseTextureCache array.
   */
  external textureCacheIds : t => array string = "" [@@bs.get];
  /*
   The ids under which this BaseTexture has been added to the base texture cache. This is
   automatically set as long as BaseTexture.addToCache is used, but may not be set if a
   BaseTexture is added directly to the BaseTextureCache array.
   */
  external setTextureCacheIds : t => array string => unit = "textureCacheIds" [@@bs.set];
};

module Ticker = {
  /*
   A Ticker class that runs an update loop that other objects listen to.
   This class is composed around listeners
   meant for execution on the next requested animation frame.
   Animation frames are requested only when necessary,
   e.g. When the ticker is started and the emitter has listeners.
   */
  module Ticker = {
    /*
     A Ticker class that runs an update loop that other objects listen to.
     This class is composed around listeners
     meant for execution on the next requested animation frame.
     Animation frames are requested only when necessary,
     e.g. When the ticker is started and the emitter has listeners.
     */
    type t;
    /*
     Whether or not this ticker should invoke the method
     {@link PIXI.ticker.Ticker#start} automatically
     when a listener is added.
     */
    external autoStart : t => Js.boolean = "" [@@bs.get];
    /*
     Whether or not this ticker should invoke the method
     {@link PIXI.ticker.Ticker#start} automatically
     when a listener is added.
     */
    external setAutoStart : t => Js.boolean => unit = "autoStart" [@@bs.set];
    /*
     <p>Scalar time value from last frame to this frame.
     This value is capped by setting {@link PIXI.ticker.Ticker#minFPS}
     and is scaled with {@link PIXI.ticker.Ticker#speed}.
     <strong>Note:</strong> The cap may be exceeded by scaling.</p>
     */
    external deltaTime : t => float = "" [@@bs.get];
    /*
     <p>Scalar time value from last frame to this frame.
     This value is capped by setting {@link PIXI.ticker.Ticker#minFPS}
     and is scaled with {@link PIXI.ticker.Ticker#speed}.
     <strong>Note:</strong> The cap may be exceeded by scaling.</p>
     */
    external setDeltaTime : t => float => unit = "deltaTime" [@@bs.set];
    /*
     Time elapsed in milliseconds from last frame to this frame.
     Opposed to what the scalar {@link PIXI.ticker.Ticker#deltaTime}
     is based, this value is neither capped nor scaled.
     If the platform supports DOMHighResTimeStamp,
     this value will have a precision of 1 µs.
     Defaults to target frame time
     */
    external elapsedMS : t => float = "" [@@bs.get];
    /*
     Time elapsed in milliseconds from last frame to this frame.
     Opposed to what the scalar {@link PIXI.ticker.Ticker#deltaTime}
     is based, this value is neither capped nor scaled.
     If the platform supports DOMHighResTimeStamp,
     this value will have a precision of 1 µs.
     Defaults to target frame time
     */
    external setElapsedMS : t => float => unit = "elapsedMS" [@@bs.set];
    /*
     The last time {@link PIXI.ticker.Ticker#update} was invoked.
     This value is also reset internally outside of invoking
     update, but only when a new animation frame is requested.
     If the platform supports DOMHighResTimeStamp,
     this value will have a precision of 1 µs.
     */
    external lastTime : t => float = "" [@@bs.get];
    /*
     The last time {@link PIXI.ticker.Ticker#update} was invoked.
     This value is also reset internally outside of invoking
     update, but only when a new animation frame is requested.
     If the platform supports DOMHighResTimeStamp,
     this value will have a precision of 1 µs.
     */
    external setLastTime : t => float => unit = "lastTime" [@@bs.set];
    /*
     Factor of current {@link PIXI.ticker.Ticker#deltaTime}.
     */
    external speed : t => float = "" [@@bs.get];
    /*
     Factor of current {@link PIXI.ticker.Ticker#deltaTime}.
     */
    external setSpeed : t => float => unit = "speed" [@@bs.set];
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
    external fps : t => float = "FPS" [@@bs.get];
    /*
     <p>Manages the maximum amount of milliseconds allowed to
     elapse between invoking {@link PIXI.ticker.Ticker#update}.
     This value is used to cap {@link PIXI.ticker.Ticker#deltaTime},
     but does not effect the measured value of {@link PIXI.ticker.Ticker#FPS}.
     When setting this property it is clamped to a value between
     <code>0</code> and <code>PIXI.settings.TARGET_FPMS * 1000</code>.</p>
     */
    external minFPS : t => float = "" [@@bs.get];
    /*
     <p>Manages the maximum amount of milliseconds allowed to
     elapse between invoking {@link PIXI.ticker.Ticker#update}.
     This value is used to cap {@link PIXI.ticker.Ticker#deltaTime},
     but does not effect the measured value of {@link PIXI.ticker.Ticker#FPS}.
     When setting this property it is clamped to a value between
     <code>0</code> and <code>PIXI.settings.TARGET_FPMS * 1000</code>.</p>
     */
    external setMinFPS : t => float => unit = "minFPS" [@@bs.set];
  };
};

module Utils = {
  module EventEmitter = {
    type t;
  };
};

module Extras = {
  module MovieClip = {
    type t;
  };
  /*
   An AnimatedSprite is a simple way to display an animation depicted by a list of textures.

   <pre class="prettyprint source lang-js"><code>let alienImages = [&quot;image_sequence_01.png&quot;,&quot;image_sequence_02.png&quot;,&quot;image_sequence_03.png&quot;,&quot;image_sequence_04.png&quot;];
   let textureArray = [];

   for (let i=0; i &lt; 4; i++)
   {
        let texture = PIXI.Texture.fromImage(alienImages[i]);
        textureArray.push(texture);
   };

   let mc = new PIXI.AnimatedSprite(textureArray);</code></pre>
   */
  module AnimatedSprite = {
    /*
     An AnimatedSprite is a simple way to display an animation depicted by a list of textures.

     <pre class="prettyprint source lang-js"><code>let alienImages = [&quot;image_sequence_01.png&quot;,&quot;image_sequence_02.png&quot;,&quot;image_sequence_03.png&quot;,&quot;image_sequence_04.png&quot;];
     let textureArray = [];

     for (let i=0; i &lt; 4; i++)
     {
          let texture = PIXI.Texture.fromImage(alienImages[i]);
          textureArray.push(texture);
     };

     let mc = new PIXI.AnimatedSprite(textureArray);</code></pre>
     */
    type t;
    /*
     The speed that the AnimatedSprite will play at. Higher is faster, lower is slower
     */
    external animationSpeed : t => float = "" [@@bs.get];
    /*
     The speed that the AnimatedSprite will play at. Higher is faster, lower is slower
     */
    external setAnimationSpeed : t => float => unit = "animationSpeed" [@@bs.set];
    /*
     Whether or not the animate sprite repeats after playing.
     */
    external loop : t => Js.boolean = "" [@@bs.get];
    /*
     Whether or not the animate sprite repeats after playing.
     */
    external setLoop : t => Js.boolean => unit = "loop" [@@bs.set];
    /*
     Function to call when a AnimatedSprite finishes playing
     */
    external onComplete : t => unit /* unknown js type: function */ = "" [@@bs.get];
    /*
     Function to call when a AnimatedSprite finishes playing
     */
    external setOnComplete : t => unit /* unknown js type: function */ => unit =
      "onComplete" [@@bs.set];
    /*
     Function to call when a AnimatedSprite changes which texture is being rendered
     */
    external onFrameChange : t => unit /* unknown js type: function */ = "" [@@bs.get];
    /*
     Function to call when a AnimatedSprite changes which texture is being rendered
     */
    external setOnFrameChange : t => unit /* unknown js type: function */ => unit =
      "onFrameChange" [@@bs.set];
    /*
     Function to call when 'loop' is true, and an AnimatedSprite is played and loops around to start again
     */
    external onLoop : t => unit /* unknown js type: function */ = "" [@@bs.get];
    /*
     Function to call when 'loop' is true, and an AnimatedSprite is played and loops around to start again
     */
    external setOnLoop : t => unit /* unknown js type: function */ => unit = "onLoop" [@@bs.set];
    /*
     Indicates if the AnimatedSprite is currently playing
     */
    external playing : t => Js.boolean = "" [@@bs.get];
    /*
     totalFrames is the total number of frames in the AnimatedSprite. This is the same as number of textures
     assigned to the AnimatedSprite.
     */
    external totalFrames : t => float = "" [@@bs.get];
    /*
     The array of textures used for this AnimatedSprite
     */
    external textures : t => array Texture.t = "" [@@bs.get];
    /*
     The array of textures used for this AnimatedSprite
     */
    external setTextures : t => array Texture.t => unit = "textures" [@@bs.set];
    /*
     The AnimatedSprites current frame index
     */
    external currentFrame : t => float = "" [@@bs.get];
    /*
     <p>The blend mode to be applied to the sprite. Apply a value of <code>PIXI.BLEND_MODES.NORMAL</code> to reset the blend mode.</p>
     */
    external blendMode : t => float = "" [@@bs.get];
    /*
     <p>The blend mode to be applied to the sprite. Apply a value of <code>PIXI.BLEND_MODES.NORMAL</code> to reset the blend mode.</p>
     */
    external setBlendMode : t => float => unit = "blendMode" [@@bs.set];
    /*
     The shader that will be used to render the sprite. Set to null to remove a current shader.
     */
    external shader : t => unit /* unknown js type: PIXI.Filter|PIXI.Shader */ = "" [@@bs.get];
    /*
     The shader that will be used to render the sprite. Set to null to remove a current shader.
     */
    external setShader : t => unit /* unknown js type: PIXI.Filter|PIXI.Shader */ => unit =
      "shader" [@@bs.set];
    /*
     Plugin that is responsible for rendering this element.
     Allows to customize the rendering process without overriding '_renderWebGL' &amp; '_renderCanvas' methods.
     */
    external pluginName : t => string = "" [@@bs.get];
    /*
     Plugin that is responsible for rendering this element.
     Allows to customize the rendering process without overriding '_renderWebGL' &amp; '_renderCanvas' methods.
     */
    external setPluginName : t => string => unit = "pluginName" [@@bs.set];
    /*
     The width of the sprite, setting this will actually modify the scale to achieve the value set
     */
    external width : t => float = "" [@@bs.get];
    /*
     The width of the sprite, setting this will actually modify the scale to achieve the value set
     */
    external setWidth : t => float => unit = "width" [@@bs.set];
    /*
     The height of the sprite, setting this will actually modify the scale to achieve the value set
     */
    external height : t => float = "" [@@bs.get];
    /*
     The height of the sprite, setting this will actually modify the scale to achieve the value set
     */
    external setHeight : t => float => unit = "height" [@@bs.set];
    /*
     The anchor sets the origin point of the texture.
     The default is 0,0 this means the texture's origin is the top left
     Setting the anchor to 0.5,0.5 means the texture's origin is centered
     Setting the anchor to 1,1 would mean the texture's origin point will be the bottom right corner
     */
    external anchor : t => ObservablePoint.t = "" [@@bs.get];
    /*
     The anchor sets the origin point of the texture.
     The default is 0,0 this means the texture's origin is the top left
     Setting the anchor to 0.5,0.5 means the texture's origin is centered
     Setting the anchor to 1,1 would mean the texture's origin point will be the bottom right corner
     */
    external setAnchor : t => ObservablePoint.t => unit = "anchor" [@@bs.set];
    /*
     The tint applied to the sprite. This is a hex value.
     A value of 0xFFFFFF will remove any tint effect.
     */
    external tint : t => float = "" [@@bs.get];
    /*
     The tint applied to the sprite. This is a hex value.
     A value of 0xFFFFFF will remove any tint effect.
     */
    external setTint : t => float => unit = "tint" [@@bs.set];
    /*
     The texture that the sprite is using
     */
    external texture : t => Texture.t = "" [@@bs.get];
    /*
     The texture that the sprite is using
     */
    external setTexture : t => Texture.t => unit = "texture" [@@bs.set];
    /*
     The array of children of this container.
     */
    external children : t => array DisplayObject.t = "" [@@bs.get];
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
     World transform and local transform of this object.
     This will become read-only later, please do not assign anything there unless you know what are you doing
     */
    external transform : t => TransformBase.t = "" [@@bs.get];
    /*
     World transform and local transform of this object.
     This will become read-only later, please do not assign anything there unless you know what are you doing
     */
    external setTransform : t => TransformBase.t => unit = "transform" [@@bs.set];
    /*
     The opacity of the object.
     */
    external alpha : t => float = "" [@@bs.get];
    /*
     The opacity of the object.
     */
    external setAlpha : t => float => unit = "alpha" [@@bs.set];
    /*
     The visibility of the object. If false the object will not be drawn, and
     the updateTransform function will not be called.

     Only affects recursive calls from parent. You can ask for bounds or call updateTransform manually
     */
    external visible : t => Js.boolean = "" [@@bs.get];
    /*
     The visibility of the object. If false the object will not be drawn, and
     the updateTransform function will not be called.

     Only affects recursive calls from parent. You can ask for bounds or call updateTransform manually
     */
    external setVisible : t => Js.boolean => unit = "visible" [@@bs.set];
    /*
     Can this object be rendered, if false the object will not be drawn but the updateTransform
     methods will still be called.

     Only affects recursive calls from parent. You can ask for bounds manually
     */
    external renderable : t => Js.boolean = "" [@@bs.get];
    /*
     Can this object be rendered, if false the object will not be drawn but the updateTransform
     methods will still be called.

     Only affects recursive calls from parent. You can ask for bounds manually
     */
    external setRenderable : t => Js.boolean => unit = "renderable" [@@bs.set];
    /*
     The display object container that contains this display object.
     */
    external parent : t => Container.t = "" [@@bs.get];
    /*
     The multiplied alpha of the displayObject
     */
    external worldAlpha : t => float = "" [@@bs.get];
    /*
     The area the filter is applied to. This is used as more of an optimisation
     rather than figuring out the dimensions of the displayObject each frame you can set this rectangle

     Also works as an interaction mask
     */
    external filterArea : t => Rectangle.t = "" [@@bs.get];
    /*
     The area the filter is applied to. This is used as more of an optimisation
     rather than figuring out the dimensions of the displayObject each frame you can set this rectangle

     Also works as an interaction mask
     */
    external setFilterArea : t => Rectangle.t => unit = "filterArea" [@@bs.set];
    /*
     The position of the displayObject on the x axis relative to the local coordinates of the parent.
     An alias to position.x
     */
    external x : t => float = "" [@@bs.get];
    /*
     The position of the displayObject on the x axis relative to the local coordinates of the parent.
     An alias to position.x
     */
    external setX : t => float => unit = "x" [@@bs.set];
    /*
     The position of the displayObject on the y axis relative to the local coordinates of the parent.
     An alias to position.y
     */
    external y : t => float = "" [@@bs.get];
    /*
     The position of the displayObject on the y axis relative to the local coordinates of the parent.
     An alias to position.y
     */
    external setY : t => float => unit = "y" [@@bs.set];
    /*
     Current transform of the object based on world (parent) factors
     */
    external worldTransform : t => Matrix.t = "" [@@bs.get];
    /*
     Current transform of the object based on local factors: position, scale, other stuff
     */
    external localTransform : t => Matrix.t = "" [@@bs.get];
    /*
     The coordinate of the object relative to the local coordinates of the parent.
     Assignment by value since pixi-v4.
     */
    external position : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
      "" [@@bs.get];
    /*
     The coordinate of the object relative to the local coordinates of the parent.
     Assignment by value since pixi-v4.
     */
    external setPosition : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
      "position" [@@bs.set];
    /*
     The scale factor of the object.
     Assignment by value since pixi-v4.
     */
    external scale : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
      "" [@@bs.get];
    /*
     The scale factor of the object.
     Assignment by value since pixi-v4.
     */
    external setScale : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
      "scale" [@@bs.set];
    /*
     The pivot point of the displayObject that it rotates around
     Assignment by value since pixi-v4.
     */
    external pivot : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
      "" [@@bs.get];
    /*
     The pivot point of the displayObject that it rotates around
     Assignment by value since pixi-v4.
     */
    external setPivot : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
      "pivot" [@@bs.set];
    /*
     The skew factor for the object in radians.
     Assignment by value since pixi-v4.
     */
    external skew : t => ObservablePoint.t = "" [@@bs.get];
    /*
     The skew factor for the object in radians.
     Assignment by value since pixi-v4.
     */
    external setSkew : t => ObservablePoint.t => unit = "skew" [@@bs.set];
    /*
     The rotation of the object in radians.
     */
    external rotation : t => float = "" [@@bs.get];
    /*
     The rotation of the object in radians.
     */
    external setRotation : t => float => unit = "rotation" [@@bs.set];
    /*
     Indicates if the object is globally visible.
     */
    external worldVisible : t => Js.boolean = "" [@@bs.get];
    /*
     Sets a mask for the displayObject. A mask is an object that limits the visibility of an
     object to the shape of the mask applied to it. In PIXI a regular mask must be a
     PIXI.Graphics or a PIXI.Sprite object. This allows for much faster masking in canvas as it
     utilises shape clipping. To remove a mask, set this property to null.
     */
    external mask : t => unit /* unknown js type: PIXI.Graphics|PIXI.Sprite */ = "" [@@bs.get];
    /*
     Sets a mask for the displayObject. A mask is an object that limits the visibility of an
     object to the shape of the mask applied to it. In PIXI a regular mask must be a
     PIXI.Graphics or a PIXI.Sprite object. This allows for much faster masking in canvas as it
     utilises shape clipping. To remove a mask, set this property to null.
     */
    external setMask : t => unit /* unknown js type: PIXI.Graphics|PIXI.Sprite */ => unit =
      "mask" [@@bs.set];
    /*
     Sets the filters for the displayObject.

     <ul>
     <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
     To remove filters simply set this property to 'null'</li>
     </ul>
     */
    external filters : t => array Filter.t = "" [@@bs.get];
    /*
     Sets the filters for the displayObject.

     <ul>
     <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
     To remove filters simply set this property to 'null'</li>
     </ul>
     */
    external setFilters : t => array Filter.t => unit = "filters" [@@bs.set];
    /*
     Set this to true if you want this display object to be cached as a bitmap.
     This basically takes a snap shot of the display object as it is at that moment. It can
     provide a performance benefit for complex static displayObjects.
     To remove simply set this property to 'false'

     IMPORTANT GOTCHA - make sure that all your textures are preloaded BEFORE setting this property to true
     as it will take a snapshot of what is currently there. If the textures have not loaded then they will not appear.
     */
    external cacheAsBitmap : t => Js.boolean = "" [@@bs.get];
    /*
     Set this to true if you want this display object to be cached as a bitmap.
     This basically takes a snap shot of the display object as it is at that moment. It can
     provide a performance benefit for complex static displayObjects.
     To remove simply set this property to 'false'

     IMPORTANT GOTCHA - make sure that all your textures are preloaded BEFORE setting this property to true
     as it will take a snapshot of what is currently there. If the textures have not loaded then they will not appear.
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
     Interaction shape. Children will be hit first, then this shape will be checked.
     Setting this will cause this shape to be checked in hit tests rather than the displayObject's bounds.
     */
    external hitArea :
      t => unit /* unknown js type: PIXI.Rectangle|PIXI.Circle|PIXI.Ellipse|PIXI.Polygon|PIXI.RoundedRectangle */ =
      "" [@@bs.get];
    /*
     Interaction shape. Children will be hit first, then this shape will be checked.
     Setting this will cause this shape to be checked in hit tests rather than the displayObject's bounds.
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
     This defines what cursor mode is used when the mouse cursor
     is hovered over the displayObject.
     */
    external cursor : t => string = "" [@@bs.get];
    /*
     This defines what cursor mode is used when the mouse cursor
     is hovered over the displayObject.
     */
    external setCursor : t => string => unit = "cursor" [@@bs.set];
  };
  /*
   A BitmapText object will create a line or multiple lines of text using bitmap font. To
   split a line you can use '\n', '\r' or '\r\n' in your string. You can generate the fnt files using:

   A BitmapText can only be created when the font is loaded

   <pre class="prettyprint source lang-js"><code>// in this case the font is in a file called 'desyrel.fnt'
   let bitmapText = new PIXI.extras.BitmapText(&quot;text using a fancy font!&quot;, {font: &quot;35px Desyrel&quot;, align: &quot;right&quot;});</code></pre>http://www.angelcode.com/products/bmfont/ for windows or
   http://www.bmglyph.com/ for mac.
   */
  module BitmapText = {
    /*
     A BitmapText object will create a line or multiple lines of text using bitmap font. To
     split a line you can use '\n', '\r' or '\r\n' in your string. You can generate the fnt files using:

     A BitmapText can only be created when the font is loaded

     <pre class="prettyprint source lang-js"><code>// in this case the font is in a file called 'desyrel.fnt'
     let bitmapText = new PIXI.extras.BitmapText(&quot;text using a fancy font!&quot;, {font: &quot;35px Desyrel&quot;, align: &quot;right&quot;});</code></pre>http://www.angelcode.com/products/bmfont/ for windows or
     http://www.bmglyph.com/ for mac.
     */
    type t;
    /*
     The dirty state of this object.
     */
    external dirty : t => Js.boolean = "" [@@bs.get];
    /*
     The dirty state of this object.
     */
    external setDirty : t => Js.boolean => unit = "dirty" [@@bs.set];
    /*
     The tint of the BitmapText object
     */
    external tint : t => float = "" [@@bs.get];
    /*
     The tint of the BitmapText object
     */
    external setTint : t => float => unit = "tint" [@@bs.set];
    /*
     The alignment of the BitmapText object
     */
    external align : t => string = "" [@@bs.get];
    /*
     The alignment of the BitmapText object
     */
    external setAlign : t => string => unit = "align" [@@bs.set];
    /*
     The anchor sets the origin point of the text.
     The default is 0,0 this means the text's origin is the top left
     Setting the anchor to 0.5,0.5 means the text's origin is centered
     Setting the anchor to 1,1 would mean the text's origin point will be the bottom right corner
     */
    external anchor : t => unit /* unknown js type: PIXI.Point|number */ = "" [@@bs.get];
    /*
     The anchor sets the origin point of the text.
     The default is 0,0 this means the text's origin is the top left
     Setting the anchor to 0.5,0.5 means the text's origin is centered
     Setting the anchor to 1,1 would mean the text's origin point will be the bottom right corner
     */
    external setAnchor : t => unit /* unknown js type: PIXI.Point|number */ => unit =
      "anchor" [@@bs.set];
    /*
     The font descriptor of the BitmapText object
     */
    external font : t => unit /* unknown js type: string|object */ = "" [@@bs.get];
    /*
     The font descriptor of the BitmapText object
     */
    external setFont : t => unit /* unknown js type: string|object */ => unit = "font" [@@bs.set];
    /*
     The text of the BitmapText object
     */
    external text : t => string = "" [@@bs.get];
    /*
     The text of the BitmapText object
     */
    external setText : t => string => unit = "text" [@@bs.set];
    /*
     The max width of this bitmap text in pixels. If the text provided is longer than the
     value provided, line breaks will be automatically inserted in the last whitespace.
     Disable by setting value to 0
     */
    external maxWidth : t => float = "" [@@bs.get];
    /*
     The max width of this bitmap text in pixels. If the text provided is longer than the
     value provided, line breaks will be automatically inserted in the last whitespace.
     Disable by setting value to 0
     */
    external setMaxWidth : t => float => unit = "maxWidth" [@@bs.set];
    /*
     The max line height. This is useful when trying to use the total height of the Text,
     ie: when trying to vertically align.
     */
    external maxLineHeight : t => float = "" [@@bs.get];
    /*
     The width of the overall text, different from fontSize,
     which is defined in the style object
     */
    external textWidth : t => float = "" [@@bs.get];
    /*
     The height of the overall text, different from fontSize,
     which is defined in the style object
     */
    external textHeight : t => float = "" [@@bs.get];
    /*
     The array of children of this container.
     */
    external children : t => array DisplayObject.t = "" [@@bs.get];
    /*
     The width of the Container, setting this will actually modify the scale to achieve the value set
     */
    external width : t => float = "" [@@bs.get];
    /*
     The width of the Container, setting this will actually modify the scale to achieve the value set
     */
    external setWidth : t => float => unit = "width" [@@bs.set];
    /*
     The height of the Container, setting this will actually modify the scale to achieve the value set
     */
    external height : t => float = "" [@@bs.get];
    /*
     The height of the Container, setting this will actually modify the scale to achieve the value set
     */
    external setHeight : t => float => unit = "height" [@@bs.set];
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
     World transform and local transform of this object.
     This will become read-only later, please do not assign anything there unless you know what are you doing
     */
    external transform : t => TransformBase.t = "" [@@bs.get];
    /*
     World transform and local transform of this object.
     This will become read-only later, please do not assign anything there unless you know what are you doing
     */
    external setTransform : t => TransformBase.t => unit = "transform" [@@bs.set];
    /*
     The opacity of the object.
     */
    external alpha : t => float = "" [@@bs.get];
    /*
     The opacity of the object.
     */
    external setAlpha : t => float => unit = "alpha" [@@bs.set];
    /*
     The visibility of the object. If false the object will not be drawn, and
     the updateTransform function will not be called.

     Only affects recursive calls from parent. You can ask for bounds or call updateTransform manually
     */
    external visible : t => Js.boolean = "" [@@bs.get];
    /*
     The visibility of the object. If false the object will not be drawn, and
     the updateTransform function will not be called.

     Only affects recursive calls from parent. You can ask for bounds or call updateTransform manually
     */
    external setVisible : t => Js.boolean => unit = "visible" [@@bs.set];
    /*
     Can this object be rendered, if false the object will not be drawn but the updateTransform
     methods will still be called.

     Only affects recursive calls from parent. You can ask for bounds manually
     */
    external renderable : t => Js.boolean = "" [@@bs.get];
    /*
     Can this object be rendered, if false the object will not be drawn but the updateTransform
     methods will still be called.

     Only affects recursive calls from parent. You can ask for bounds manually
     */
    external setRenderable : t => Js.boolean => unit = "renderable" [@@bs.set];
    /*
     The display object container that contains this display object.
     */
    external parent : t => Container.t = "" [@@bs.get];
    /*
     The multiplied alpha of the displayObject
     */
    external worldAlpha : t => float = "" [@@bs.get];
    /*
     The area the filter is applied to. This is used as more of an optimisation
     rather than figuring out the dimensions of the displayObject each frame you can set this rectangle

     Also works as an interaction mask
     */
    external filterArea : t => Rectangle.t = "" [@@bs.get];
    /*
     The area the filter is applied to. This is used as more of an optimisation
     rather than figuring out the dimensions of the displayObject each frame you can set this rectangle

     Also works as an interaction mask
     */
    external setFilterArea : t => Rectangle.t => unit = "filterArea" [@@bs.set];
    /*
     The position of the displayObject on the x axis relative to the local coordinates of the parent.
     An alias to position.x
     */
    external x : t => float = "" [@@bs.get];
    /*
     The position of the displayObject on the x axis relative to the local coordinates of the parent.
     An alias to position.x
     */
    external setX : t => float => unit = "x" [@@bs.set];
    /*
     The position of the displayObject on the y axis relative to the local coordinates of the parent.
     An alias to position.y
     */
    external y : t => float = "" [@@bs.get];
    /*
     The position of the displayObject on the y axis relative to the local coordinates of the parent.
     An alias to position.y
     */
    external setY : t => float => unit = "y" [@@bs.set];
    /*
     Current transform of the object based on world (parent) factors
     */
    external worldTransform : t => Matrix.t = "" [@@bs.get];
    /*
     Current transform of the object based on local factors: position, scale, other stuff
     */
    external localTransform : t => Matrix.t = "" [@@bs.get];
    /*
     The coordinate of the object relative to the local coordinates of the parent.
     Assignment by value since pixi-v4.
     */
    external position : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
      "" [@@bs.get];
    /*
     The coordinate of the object relative to the local coordinates of the parent.
     Assignment by value since pixi-v4.
     */
    external setPosition : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
      "position" [@@bs.set];
    /*
     The scale factor of the object.
     Assignment by value since pixi-v4.
     */
    external scale : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
      "" [@@bs.get];
    /*
     The scale factor of the object.
     Assignment by value since pixi-v4.
     */
    external setScale : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
      "scale" [@@bs.set];
    /*
     The pivot point of the displayObject that it rotates around
     Assignment by value since pixi-v4.
     */
    external pivot : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
      "" [@@bs.get];
    /*
     The pivot point of the displayObject that it rotates around
     Assignment by value since pixi-v4.
     */
    external setPivot : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
      "pivot" [@@bs.set];
    /*
     The skew factor for the object in radians.
     Assignment by value since pixi-v4.
     */
    external skew : t => ObservablePoint.t = "" [@@bs.get];
    /*
     The skew factor for the object in radians.
     Assignment by value since pixi-v4.
     */
    external setSkew : t => ObservablePoint.t => unit = "skew" [@@bs.set];
    /*
     The rotation of the object in radians.
     */
    external rotation : t => float = "" [@@bs.get];
    /*
     The rotation of the object in radians.
     */
    external setRotation : t => float => unit = "rotation" [@@bs.set];
    /*
     Indicates if the object is globally visible.
     */
    external worldVisible : t => Js.boolean = "" [@@bs.get];
    /*
     Sets a mask for the displayObject. A mask is an object that limits the visibility of an
     object to the shape of the mask applied to it. In PIXI a regular mask must be a
     PIXI.Graphics or a PIXI.Sprite object. This allows for much faster masking in canvas as it
     utilises shape clipping. To remove a mask, set this property to null.
     */
    external mask : t => unit /* unknown js type: PIXI.Graphics|PIXI.Sprite */ = "" [@@bs.get];
    /*
     Sets a mask for the displayObject. A mask is an object that limits the visibility of an
     object to the shape of the mask applied to it. In PIXI a regular mask must be a
     PIXI.Graphics or a PIXI.Sprite object. This allows for much faster masking in canvas as it
     utilises shape clipping. To remove a mask, set this property to null.
     */
    external setMask : t => unit /* unknown js type: PIXI.Graphics|PIXI.Sprite */ => unit =
      "mask" [@@bs.set];
    /*
     Sets the filters for the displayObject.

     <ul>
     <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
     To remove filters simply set this property to 'null'</li>
     </ul>
     */
    external filters : t => array Filter.t = "" [@@bs.get];
    /*
     Sets the filters for the displayObject.

     <ul>
     <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
     To remove filters simply set this property to 'null'</li>
     </ul>
     */
    external setFilters : t => array Filter.t => unit = "filters" [@@bs.set];
    /*
     Set this to true if you want this display object to be cached as a bitmap.
     This basically takes a snap shot of the display object as it is at that moment. It can
     provide a performance benefit for complex static displayObjects.
     To remove simply set this property to 'false'

     IMPORTANT GOTCHA - make sure that all your textures are preloaded BEFORE setting this property to true
     as it will take a snapshot of what is currently there. If the textures have not loaded then they will not appear.
     */
    external cacheAsBitmap : t => Js.boolean = "" [@@bs.get];
    /*
     Set this to true if you want this display object to be cached as a bitmap.
     This basically takes a snap shot of the display object as it is at that moment. It can
     provide a performance benefit for complex static displayObjects.
     To remove simply set this property to 'false'

     IMPORTANT GOTCHA - make sure that all your textures are preloaded BEFORE setting this property to true
     as it will take a snapshot of what is currently there. If the textures have not loaded then they will not appear.
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
     Interaction shape. Children will be hit first, then this shape will be checked.
     Setting this will cause this shape to be checked in hit tests rather than the displayObject's bounds.
     */
    external hitArea :
      t => unit /* unknown js type: PIXI.Rectangle|PIXI.Circle|PIXI.Ellipse|PIXI.Polygon|PIXI.RoundedRectangle */ =
      "" [@@bs.get];
    /*
     Interaction shape. Children will be hit first, then this shape will be checked.
     Setting this will cause this shape to be checked in hit tests rather than the displayObject's bounds.
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
     This defines what cursor mode is used when the mouse cursor
     is hovered over the displayObject.
     */
    external cursor : t => string = "" [@@bs.get];
    /*
     This defines what cursor mode is used when the mouse cursor
     is hovered over the displayObject.
     */
    external setCursor : t => string => unit = "cursor" [@@bs.set];
  };
  /*
   class controls uv transform and frame clamp for texture
   */
  module TextureTransform = {
    /*
     class controls uv transform and frame clamp for texture
     */
    type t;
    /*
     Changes frame clamping
     Works with TilingSprite and Mesh
     Change to 1.5 if you texture has repeated right and bottom lines, that leads to smoother borders
     */
    external clampOffset : t => float = "" [@@bs.get];
    /*
     Changes frame clamping
     Works with TilingSprite and Mesh
     Change to 1.5 if you texture has repeated right and bottom lines, that leads to smoother borders
     */
    external setClampOffset : t => float => unit = "clampOffset" [@@bs.set];
    /*
     Changes frame clamping
     Works with TilingSprite and Mesh
     Change to -0.5 to add a pixel to the edge, recommended for transparent trimmed textures in atlas
     */
    external clampMargin : t => float = "" [@@bs.get];
    /*
     Changes frame clamping
     Works with TilingSprite and Mesh
     Change to -0.5 to add a pixel to the edge, recommended for transparent trimmed textures in atlas
     */
    external setClampMargin : t => float => unit = "clampMargin" [@@bs.set];
    /*
     texture property
     */
    external texture : t => Texture.t = "" [@@bs.get];
    /*
     texture property
     */
    external setTexture : t => Texture.t => unit = "texture" [@@bs.set];
  };
  /*
   A tiling sprite is a fast way of rendering a tiling image
   */
  module TilingSprite = {
    /*
     A tiling sprite is a fast way of rendering a tiling image
     */
    type t;
    /*
     Tile transform
     */
    external tileTransform : t => TransformStatic.t = "" [@@bs.get];
    /*
     Tile transform
     */
    external setTileTransform : t => TransformStatic.t => unit = "tileTransform" [@@bs.set];
    /*
     transform that is applied to UV to get the texture coords
     */
    external uvTransform : t => Extras.TextureTransform.t = "" [@@bs.get];
    /*
     transform that is applied to UV to get the texture coords
     */
    external setUvTransform : t => Extras.TextureTransform.t => unit = "uvTransform" [@@bs.set];
    /*
     Plugin that is responsible for rendering this element.
     Allows to customize the rendering process without overriding '_renderWebGL' method.
     */
    external pluginName : t => string = "" [@@bs.get];
    /*
     Plugin that is responsible for rendering this element.
     Allows to customize the rendering process without overriding '_renderWebGL' method.
     */
    external setPluginName : t => string => unit = "pluginName" [@@bs.set];
    /*
     Whether or not anchor affects uvs
     */
    external uvRespectAnchor : t => Js.boolean = "" [@@bs.get];
    /*
     Whether or not anchor affects uvs
     */
    external setUvRespectAnchor : t => Js.boolean => unit = "uvRespectAnchor" [@@bs.set];
    /*
     Changes frame clamping in corresponding textureTransform, shortcut
     Change to -0.5 to add a pixel to the edge, recommended for transparent trimmed textures in atlas
     */
    external clampMargin : t => float = "" [@@bs.get];
    /*
     Changes frame clamping in corresponding textureTransform, shortcut
     Change to -0.5 to add a pixel to the edge, recommended for transparent trimmed textures in atlas
     */
    external setClampMargin : t => float => unit = "clampMargin" [@@bs.set];
    /*
     The scaling of the image that is being tiled
     */
    external tileScale : t => ObservablePoint.t = "" [@@bs.get];
    /*
     The scaling of the image that is being tiled
     */
    external setTileScale : t => ObservablePoint.t => unit = "tileScale" [@@bs.set];
    /*
     The offset of the image that is being tiled
     */
    external tilePosition : t => ObservablePoint.t = "" [@@bs.get];
    /*
     The offset of the image that is being tiled
     */
    external setTilePosition : t => ObservablePoint.t => unit = "tilePosition" [@@bs.set];
    /*
     The width of the sprite, setting this will actually modify the scale to achieve the value set
     */
    external width : t => float = "" [@@bs.get];
    /*
     The width of the sprite, setting this will actually modify the scale to achieve the value set
     */
    external setWidth : t => float => unit = "width" [@@bs.set];
    /*
     The height of the TilingSprite, setting this will actually modify the scale to achieve the value set
     */
    external height : t => float = "" [@@bs.get];
    /*
     The height of the TilingSprite, setting this will actually modify the scale to achieve the value set
     */
    external setHeight : t => float => unit = "height" [@@bs.set];
    /*
     <p>The blend mode to be applied to the sprite. Apply a value of <code>PIXI.BLEND_MODES.NORMAL</code> to reset the blend mode.</p>
     */
    external blendMode : t => float = "" [@@bs.get];
    /*
     <p>The blend mode to be applied to the sprite. Apply a value of <code>PIXI.BLEND_MODES.NORMAL</code> to reset the blend mode.</p>
     */
    external setBlendMode : t => float => unit = "blendMode" [@@bs.set];
    /*
     The shader that will be used to render the sprite. Set to null to remove a current shader.
     */
    external shader : t => unit /* unknown js type: PIXI.Filter|PIXI.Shader */ = "" [@@bs.get];
    /*
     The shader that will be used to render the sprite. Set to null to remove a current shader.
     */
    external setShader : t => unit /* unknown js type: PIXI.Filter|PIXI.Shader */ => unit =
      "shader" [@@bs.set];
    /*
     The anchor sets the origin point of the texture.
     The default is 0,0 this means the texture's origin is the top left
     Setting the anchor to 0.5,0.5 means the texture's origin is centered
     Setting the anchor to 1,1 would mean the texture's origin point will be the bottom right corner
     */
    external anchor : t => ObservablePoint.t = "" [@@bs.get];
    /*
     The anchor sets the origin point of the texture.
     The default is 0,0 this means the texture's origin is the top left
     Setting the anchor to 0.5,0.5 means the texture's origin is centered
     Setting the anchor to 1,1 would mean the texture's origin point will be the bottom right corner
     */
    external setAnchor : t => ObservablePoint.t => unit = "anchor" [@@bs.set];
    /*
     The tint applied to the sprite. This is a hex value.
     A value of 0xFFFFFF will remove any tint effect.
     */
    external tint : t => float = "" [@@bs.get];
    /*
     The tint applied to the sprite. This is a hex value.
     A value of 0xFFFFFF will remove any tint effect.
     */
    external setTint : t => float => unit = "tint" [@@bs.set];
    /*
     The texture that the sprite is using
     */
    external texture : t => Texture.t = "" [@@bs.get];
    /*
     The texture that the sprite is using
     */
    external setTexture : t => Texture.t => unit = "texture" [@@bs.set];
    /*
     The array of children of this container.
     */
    external children : t => array DisplayObject.t = "" [@@bs.get];
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
     World transform and local transform of this object.
     This will become read-only later, please do not assign anything there unless you know what are you doing
     */
    external transform : t => TransformBase.t = "" [@@bs.get];
    /*
     World transform and local transform of this object.
     This will become read-only later, please do not assign anything there unless you know what are you doing
     */
    external setTransform : t => TransformBase.t => unit = "transform" [@@bs.set];
    /*
     The opacity of the object.
     */
    external alpha : t => float = "" [@@bs.get];
    /*
     The opacity of the object.
     */
    external setAlpha : t => float => unit = "alpha" [@@bs.set];
    /*
     The visibility of the object. If false the object will not be drawn, and
     the updateTransform function will not be called.

     Only affects recursive calls from parent. You can ask for bounds or call updateTransform manually
     */
    external visible : t => Js.boolean = "" [@@bs.get];
    /*
     The visibility of the object. If false the object will not be drawn, and
     the updateTransform function will not be called.

     Only affects recursive calls from parent. You can ask for bounds or call updateTransform manually
     */
    external setVisible : t => Js.boolean => unit = "visible" [@@bs.set];
    /*
     Can this object be rendered, if false the object will not be drawn but the updateTransform
     methods will still be called.

     Only affects recursive calls from parent. You can ask for bounds manually
     */
    external renderable : t => Js.boolean = "" [@@bs.get];
    /*
     Can this object be rendered, if false the object will not be drawn but the updateTransform
     methods will still be called.

     Only affects recursive calls from parent. You can ask for bounds manually
     */
    external setRenderable : t => Js.boolean => unit = "renderable" [@@bs.set];
    /*
     The display object container that contains this display object.
     */
    external parent : t => Container.t = "" [@@bs.get];
    /*
     The multiplied alpha of the displayObject
     */
    external worldAlpha : t => float = "" [@@bs.get];
    /*
     The area the filter is applied to. This is used as more of an optimisation
     rather than figuring out the dimensions of the displayObject each frame you can set this rectangle

     Also works as an interaction mask
     */
    external filterArea : t => Rectangle.t = "" [@@bs.get];
    /*
     The area the filter is applied to. This is used as more of an optimisation
     rather than figuring out the dimensions of the displayObject each frame you can set this rectangle

     Also works as an interaction mask
     */
    external setFilterArea : t => Rectangle.t => unit = "filterArea" [@@bs.set];
    /*
     The position of the displayObject on the x axis relative to the local coordinates of the parent.
     An alias to position.x
     */
    external x : t => float = "" [@@bs.get];
    /*
     The position of the displayObject on the x axis relative to the local coordinates of the parent.
     An alias to position.x
     */
    external setX : t => float => unit = "x" [@@bs.set];
    /*
     The position of the displayObject on the y axis relative to the local coordinates of the parent.
     An alias to position.y
     */
    external y : t => float = "" [@@bs.get];
    /*
     The position of the displayObject on the y axis relative to the local coordinates of the parent.
     An alias to position.y
     */
    external setY : t => float => unit = "y" [@@bs.set];
    /*
     Current transform of the object based on world (parent) factors
     */
    external worldTransform : t => Matrix.t = "" [@@bs.get];
    /*
     Current transform of the object based on local factors: position, scale, other stuff
     */
    external localTransform : t => Matrix.t = "" [@@bs.get];
    /*
     The coordinate of the object relative to the local coordinates of the parent.
     Assignment by value since pixi-v4.
     */
    external position : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
      "" [@@bs.get];
    /*
     The coordinate of the object relative to the local coordinates of the parent.
     Assignment by value since pixi-v4.
     */
    external setPosition : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
      "position" [@@bs.set];
    /*
     The scale factor of the object.
     Assignment by value since pixi-v4.
     */
    external scale : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
      "" [@@bs.get];
    /*
     The scale factor of the object.
     Assignment by value since pixi-v4.
     */
    external setScale : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
      "scale" [@@bs.set];
    /*
     The pivot point of the displayObject that it rotates around
     Assignment by value since pixi-v4.
     */
    external pivot : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
      "" [@@bs.get];
    /*
     The pivot point of the displayObject that it rotates around
     Assignment by value since pixi-v4.
     */
    external setPivot : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
      "pivot" [@@bs.set];
    /*
     The skew factor for the object in radians.
     Assignment by value since pixi-v4.
     */
    external skew : t => ObservablePoint.t = "" [@@bs.get];
    /*
     The skew factor for the object in radians.
     Assignment by value since pixi-v4.
     */
    external setSkew : t => ObservablePoint.t => unit = "skew" [@@bs.set];
    /*
     The rotation of the object in radians.
     */
    external rotation : t => float = "" [@@bs.get];
    /*
     The rotation of the object in radians.
     */
    external setRotation : t => float => unit = "rotation" [@@bs.set];
    /*
     Indicates if the object is globally visible.
     */
    external worldVisible : t => Js.boolean = "" [@@bs.get];
    /*
     Sets a mask for the displayObject. A mask is an object that limits the visibility of an
     object to the shape of the mask applied to it. In PIXI a regular mask must be a
     PIXI.Graphics or a PIXI.Sprite object. This allows for much faster masking in canvas as it
     utilises shape clipping. To remove a mask, set this property to null.
     */
    external mask : t => unit /* unknown js type: PIXI.Graphics|PIXI.Sprite */ = "" [@@bs.get];
    /*
     Sets a mask for the displayObject. A mask is an object that limits the visibility of an
     object to the shape of the mask applied to it. In PIXI a regular mask must be a
     PIXI.Graphics or a PIXI.Sprite object. This allows for much faster masking in canvas as it
     utilises shape clipping. To remove a mask, set this property to null.
     */
    external setMask : t => unit /* unknown js type: PIXI.Graphics|PIXI.Sprite */ => unit =
      "mask" [@@bs.set];
    /*
     Sets the filters for the displayObject.

     <ul>
     <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
     To remove filters simply set this property to 'null'</li>
     </ul>
     */
    external filters : t => array Filter.t = "" [@@bs.get];
    /*
     Sets the filters for the displayObject.

     <ul>
     <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
     To remove filters simply set this property to 'null'</li>
     </ul>
     */
    external setFilters : t => array Filter.t => unit = "filters" [@@bs.set];
    /*
     Set this to true if you want this display object to be cached as a bitmap.
     This basically takes a snap shot of the display object as it is at that moment. It can
     provide a performance benefit for complex static displayObjects.
     To remove simply set this property to 'false'

     IMPORTANT GOTCHA - make sure that all your textures are preloaded BEFORE setting this property to true
     as it will take a snapshot of what is currently there. If the textures have not loaded then they will not appear.
     */
    external cacheAsBitmap : t => Js.boolean = "" [@@bs.get];
    /*
     Set this to true if you want this display object to be cached as a bitmap.
     This basically takes a snap shot of the display object as it is at that moment. It can
     provide a performance benefit for complex static displayObjects.
     To remove simply set this property to 'false'

     IMPORTANT GOTCHA - make sure that all your textures are preloaded BEFORE setting this property to true
     as it will take a snapshot of what is currently there. If the textures have not loaded then they will not appear.
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
     Interaction shape. Children will be hit first, then this shape will be checked.
     Setting this will cause this shape to be checked in hit tests rather than the displayObject's bounds.
     */
    external hitArea :
      t => unit /* unknown js type: PIXI.Rectangle|PIXI.Circle|PIXI.Ellipse|PIXI.Polygon|PIXI.RoundedRectangle */ =
      "" [@@bs.get];
    /*
     Interaction shape. Children will be hit first, then this shape will be checked.
     Setting this will cause this shape to be checked in hit tests rather than the displayObject's bounds.
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
     This defines what cursor mode is used when the mouse cursor
     is hovered over the displayObject.
     */
    external cursor : t => string = "" [@@bs.get];
    /*
     This defines what cursor mode is used when the mouse cursor
     is hovered over the displayObject.
     */
    external setCursor : t => string => unit = "cursor" [@@bs.set];
  };
  /*
   WebGL renderer plugin for tiling sprites
   */
  module TilingSpriteRenderer = {
    /*
     WebGL renderer plugin for tiling sprites
     */
    type t;
    /*
     The renderer this manager works for.
     */
    external renderer : t => WebGLRenderer.t = "" [@@bs.get];
    /*
     The renderer this manager works for.
     */
    external setRenderer : t => WebGLRenderer.t => unit = "renderer" [@@bs.set];
  };
};

module Filters = {
  /*
   The BlurFilter applies a Gaussian blur to an object.
   The strength of the blur can be set for x- and y-axis separately.
   */
  module BlurFilter = {
    /*
     The BlurFilter applies a Gaussian blur to an object.
     The strength of the blur can be set for x- and y-axis separately.
     */
    type t;
    /*
     Sets the strength of both the blurX and blurY properties simultaneously
     */
    external blur : t => float = "" [@@bs.get];
    /*
     Sets the strength of both the blurX and blurY properties simultaneously
     */
    external setBlur : t => float => unit = "blur" [@@bs.set];
    /*
     Sets the number of passes for blur. More passes means higher quaility bluring.
     */
    external quality : t => float = "" [@@bs.get];
    /*
     Sets the number of passes for blur. More passes means higher quaility bluring.
     */
    external setQuality : t => float => unit = "quality" [@@bs.set];
    /*
     Sets the strength of the blurX property
     */
    external blurX : t => float = "" [@@bs.get];
    /*
     Sets the strength of the blurX property
     */
    external setBlurX : t => float => unit = "blurX" [@@bs.set];
    /*
     Sets the strength of the blurY property
     */
    external blurY : t => float = "" [@@bs.get];
    /*
     Sets the strength of the blurY property
     */
    external setBlurY : t => float => unit = "blurY" [@@bs.set];
    /*
     The vertex shader.
     */
    external vertexSrc : t => string = "" [@@bs.get];
    /*
     The vertex shader.
     */
    external setVertexSrc : t => string => unit = "vertexSrc" [@@bs.set];
    /*
     The fragment shader.
     */
    external fragmentSrc : t => string = "" [@@bs.get];
    /*
     The fragment shader.
     */
    external setFragmentSrc : t => string => unit = "fragmentSrc" [@@bs.set];
    /*
     An object containing the current values of custom uniforms.
     */
    external uniforms : t => unit /* unknown js type: object */ = "" [@@bs.get];
    /*
     An object containing the current values of custom uniforms.
     */
    external setUniforms : t => unit /* unknown js type: object */ => unit = "uniforms" [@@bs.set];
    /*
     The padding of the filter. Some filters require extra space to breath such as a blur.
     Increasing this will add extra width and height to the bounds of the object that the
     filter is applied to.
     */
    external padding : t => float = "" [@@bs.get];
    /*
     The padding of the filter. Some filters require extra space to breath such as a blur.
     Increasing this will add extra width and height to the bounds of the object that the
     filter is applied to.
     */
    external setPadding : t => float => unit = "padding" [@@bs.set];
    /*
     The resolution of the filter. Setting this to be lower will lower the quality but
     increase the performance of the filter.
     */
    external resolution : t => float = "" [@@bs.get];
    /*
     The resolution of the filter. Setting this to be lower will lower the quality but
     increase the performance of the filter.
     */
    external setResolution : t => float => unit = "resolution" [@@bs.set];
    /*
     If enabled is true the filter is applied, if false it will not.
     */
    external enabled : t => Js.boolean = "" [@@bs.get];
    /*
     If enabled is true the filter is applied, if false it will not.
     */
    external setEnabled : t => Js.boolean => unit = "enabled" [@@bs.set];
    /*
     If enabled, pixi will fit the filter area into boundaries for better performance.
     Switch it off if it does not work for specific shader.
     */
    external autoFit : t => Js.boolean = "" [@@bs.get];
    /*
     If enabled, pixi will fit the filter area into boundaries for better performance.
     Switch it off if it does not work for specific shader.
     */
    external setAutoFit : t => Js.boolean => unit = "autoFit" [@@bs.set];
  };
  /*
   The BlurXFilter applies a horizontal Gaussian blur to an object.
   */
  module BlurXFilter = {
    /*
     The BlurXFilter applies a horizontal Gaussian blur to an object.
     */
    type t;
    /*
     Sets the strength of both the blur.
     */
    external blur : t => float = "" [@@bs.get];
    /*
     Sets the strength of both the blur.
     */
    external setBlur : t => float => unit = "blur" [@@bs.set];
    /*
     Sets the quality of the blur by modifying the number of passes. More passes means higher
     quaility bluring but the lower the performance.
     */
    external quality : t => float = "" [@@bs.get];
    /*
     Sets the quality of the blur by modifying the number of passes. More passes means higher
     quaility bluring but the lower the performance.
     */
    external setQuality : t => float => unit = "quality" [@@bs.set];
    /*
     The vertex shader.
     */
    external vertexSrc : t => string = "" [@@bs.get];
    /*
     The vertex shader.
     */
    external setVertexSrc : t => string => unit = "vertexSrc" [@@bs.set];
    /*
     The fragment shader.
     */
    external fragmentSrc : t => string = "" [@@bs.get];
    /*
     The fragment shader.
     */
    external setFragmentSrc : t => string => unit = "fragmentSrc" [@@bs.set];
    /*
     An object containing the current values of custom uniforms.
     */
    external uniforms : t => unit /* unknown js type: object */ = "" [@@bs.get];
    /*
     An object containing the current values of custom uniforms.
     */
    external setUniforms : t => unit /* unknown js type: object */ => unit = "uniforms" [@@bs.set];
    /*
     The padding of the filter. Some filters require extra space to breath such as a blur.
     Increasing this will add extra width and height to the bounds of the object that the
     filter is applied to.
     */
    external padding : t => float = "" [@@bs.get];
    /*
     The padding of the filter. Some filters require extra space to breath such as a blur.
     Increasing this will add extra width and height to the bounds of the object that the
     filter is applied to.
     */
    external setPadding : t => float => unit = "padding" [@@bs.set];
    /*
     The resolution of the filter. Setting this to be lower will lower the quality but
     increase the performance of the filter.
     */
    external resolution : t => float = "" [@@bs.get];
    /*
     The resolution of the filter. Setting this to be lower will lower the quality but
     increase the performance of the filter.
     */
    external setResolution : t => float => unit = "resolution" [@@bs.set];
    /*
     If enabled is true the filter is applied, if false it will not.
     */
    external enabled : t => Js.boolean = "" [@@bs.get];
    /*
     If enabled is true the filter is applied, if false it will not.
     */
    external setEnabled : t => Js.boolean => unit = "enabled" [@@bs.set];
    /*
     If enabled, pixi will fit the filter area into boundaries for better performance.
     Switch it off if it does not work for specific shader.
     */
    external autoFit : t => Js.boolean = "" [@@bs.get];
    /*
     If enabled, pixi will fit the filter area into boundaries for better performance.
     Switch it off if it does not work for specific shader.
     */
    external setAutoFit : t => Js.boolean => unit = "autoFit" [@@bs.set];
  };
  /*
   The BlurYFilter applies a horizontal Gaussian blur to an object.
   */
  module BlurYFilter = {
    /*
     The BlurYFilter applies a horizontal Gaussian blur to an object.
     */
    type t;
    /*
     Sets the strength of both the blur.
     */
    external blur : t => float = "" [@@bs.get];
    /*
     Sets the strength of both the blur.
     */
    external setBlur : t => float => unit = "blur" [@@bs.set];
    /*
     Sets the quality of the blur by modifying the number of passes. More passes means higher
     quaility bluring but the lower the performance.
     */
    external quality : t => float = "" [@@bs.get];
    /*
     Sets the quality of the blur by modifying the number of passes. More passes means higher
     quaility bluring but the lower the performance.
     */
    external setQuality : t => float => unit = "quality" [@@bs.set];
    /*
     The vertex shader.
     */
    external vertexSrc : t => string = "" [@@bs.get];
    /*
     The vertex shader.
     */
    external setVertexSrc : t => string => unit = "vertexSrc" [@@bs.set];
    /*
     The fragment shader.
     */
    external fragmentSrc : t => string = "" [@@bs.get];
    /*
     The fragment shader.
     */
    external setFragmentSrc : t => string => unit = "fragmentSrc" [@@bs.set];
    /*
     An object containing the current values of custom uniforms.
     */
    external uniforms : t => unit /* unknown js type: object */ = "" [@@bs.get];
    /*
     An object containing the current values of custom uniforms.
     */
    external setUniforms : t => unit /* unknown js type: object */ => unit = "uniforms" [@@bs.set];
    /*
     The padding of the filter. Some filters require extra space to breath such as a blur.
     Increasing this will add extra width and height to the bounds of the object that the
     filter is applied to.
     */
    external padding : t => float = "" [@@bs.get];
    /*
     The padding of the filter. Some filters require extra space to breath such as a blur.
     Increasing this will add extra width and height to the bounds of the object that the
     filter is applied to.
     */
    external setPadding : t => float => unit = "padding" [@@bs.set];
    /*
     The resolution of the filter. Setting this to be lower will lower the quality but
     increase the performance of the filter.
     */
    external resolution : t => float = "" [@@bs.get];
    /*
     The resolution of the filter. Setting this to be lower will lower the quality but
     increase the performance of the filter.
     */
    external setResolution : t => float => unit = "resolution" [@@bs.set];
    /*
     If enabled is true the filter is applied, if false it will not.
     */
    external enabled : t => Js.boolean = "" [@@bs.get];
    /*
     If enabled is true the filter is applied, if false it will not.
     */
    external setEnabled : t => Js.boolean => unit = "enabled" [@@bs.set];
    /*
     If enabled, pixi will fit the filter area into boundaries for better performance.
     Switch it off if it does not work for specific shader.
     */
    external autoFit : t => Js.boolean = "" [@@bs.get];
    /*
     If enabled, pixi will fit the filter area into boundaries for better performance.
     Switch it off if it does not work for specific shader.
     */
    external setAutoFit : t => Js.boolean => unit = "autoFit" [@@bs.set];
  };
  /*
   The ColorMatrixFilter class lets you apply a 5x4 matrix transformation on the RGBA
   color and alpha values of every pixel on your displayObject to produce a result
   with a new set of RGBA color and alpha values. It's pretty powerful!

   <pre class="prettyprint source lang-js"><code> let colorMatrix = new PIXI.ColorMatrixFilter();
    container.filters = [colorMatrix];
    colorMatrix.contrast(2);</code></pre>
   */
  module ColorMatrixFilter = {
    /*
     The ColorMatrixFilter class lets you apply a 5x4 matrix transformation on the RGBA
     color and alpha values of every pixel on your displayObject to produce a result
     with a new set of RGBA color and alpha values. It's pretty powerful!

     <pre class="prettyprint source lang-js"><code> let colorMatrix = new PIXI.ColorMatrixFilter();
      container.filters = [colorMatrix];
      colorMatrix.contrast(2);</code></pre>
     */
    type t;
    /*
     The matrix of the color matrix filter
     */
    external matrix : t => array float = "" [@@bs.get];
    /*
     The matrix of the color matrix filter
     */
    external setMatrix : t => array float => unit = "matrix" [@@bs.set];
    /*
     The opacity value to use when mixing the original and resultant colors.

     When the value is 0, the original color is used without modification.
     When the value is 1, the result color is used.
     When in the range (0, 1) the color is interpolated between the original and result by this amount.
     */
    external alpha : t => float = "" [@@bs.get];
    /*
     The opacity value to use when mixing the original and resultant colors.

     When the value is 0, the original color is used without modification.
     When the value is 1, the result color is used.
     When in the range (0, 1) the color is interpolated between the original and result by this amount.
     */
    external setAlpha : t => float => unit = "alpha" [@@bs.set];
    /*
     The vertex shader.
     */
    external vertexSrc : t => string = "" [@@bs.get];
    /*
     The vertex shader.
     */
    external setVertexSrc : t => string => unit = "vertexSrc" [@@bs.set];
    /*
     The fragment shader.
     */
    external fragmentSrc : t => string = "" [@@bs.get];
    /*
     The fragment shader.
     */
    external setFragmentSrc : t => string => unit = "fragmentSrc" [@@bs.set];
    /*
     An object containing the current values of custom uniforms.
     */
    external uniforms : t => unit /* unknown js type: object */ = "" [@@bs.get];
    /*
     An object containing the current values of custom uniforms.
     */
    external setUniforms : t => unit /* unknown js type: object */ => unit = "uniforms" [@@bs.set];
    /*
     The padding of the filter. Some filters require extra space to breath such as a blur.
     Increasing this will add extra width and height to the bounds of the object that the
     filter is applied to.
     */
    external padding : t => float = "" [@@bs.get];
    /*
     The padding of the filter. Some filters require extra space to breath such as a blur.
     Increasing this will add extra width and height to the bounds of the object that the
     filter is applied to.
     */
    external setPadding : t => float => unit = "padding" [@@bs.set];
    /*
     The resolution of the filter. Setting this to be lower will lower the quality but
     increase the performance of the filter.
     */
    external resolution : t => float = "" [@@bs.get];
    /*
     The resolution of the filter. Setting this to be lower will lower the quality but
     increase the performance of the filter.
     */
    external setResolution : t => float => unit = "resolution" [@@bs.set];
    /*
     If enabled is true the filter is applied, if false it will not.
     */
    external enabled : t => Js.boolean = "" [@@bs.get];
    /*
     If enabled is true the filter is applied, if false it will not.
     */
    external setEnabled : t => Js.boolean => unit = "enabled" [@@bs.set];
    /*
     If enabled, pixi will fit the filter area into boundaries for better performance.
     Switch it off if it does not work for specific shader.
     */
    external autoFit : t => Js.boolean = "" [@@bs.get];
    /*
     If enabled, pixi will fit the filter area into boundaries for better performance.
     Switch it off if it does not work for specific shader.
     */
    external setAutoFit : t => Js.boolean => unit = "autoFit" [@@bs.set];
  };
  /*
   The DisplacementFilter class uses the pixel values from the specified texture
   (called the displacement map) to perform a displacement of an object. You can
   use this filter to apply all manor of crazy warping effects. Currently the r
   property of the texture is used to offset the x and the g property of the texture
   is used to offset the y.
   */
  module DisplacementFilter = {
    /*
     The DisplacementFilter class uses the pixel values from the specified texture
     (called the displacement map) to perform a displacement of an object. You can
     use this filter to apply all manor of crazy warping effects. Currently the r
     property of the texture is used to offset the x and the g property of the texture
     is used to offset the y.
     */
    type t;
    /*
     The texture used for the displacement map. Must be power of 2 sized texture.
     */
    external map : t => Texture.t = "" [@@bs.get];
    /*
     The texture used for the displacement map. Must be power of 2 sized texture.
     */
    external setMap : t => Texture.t => unit = "map" [@@bs.set];
    /*
     The vertex shader.
     */
    external vertexSrc : t => string = "" [@@bs.get];
    /*
     The vertex shader.
     */
    external setVertexSrc : t => string => unit = "vertexSrc" [@@bs.set];
    /*
     The fragment shader.
     */
    external fragmentSrc : t => string = "" [@@bs.get];
    /*
     The fragment shader.
     */
    external setFragmentSrc : t => string => unit = "fragmentSrc" [@@bs.set];
    /*
     An object containing the current values of custom uniforms.
     */
    external uniforms : t => unit /* unknown js type: object */ = "" [@@bs.get];
    /*
     An object containing the current values of custom uniforms.
     */
    external setUniforms : t => unit /* unknown js type: object */ => unit = "uniforms" [@@bs.set];
    /*
     The padding of the filter. Some filters require extra space to breath such as a blur.
     Increasing this will add extra width and height to the bounds of the object that the
     filter is applied to.
     */
    external padding : t => float = "" [@@bs.get];
    /*
     The padding of the filter. Some filters require extra space to breath such as a blur.
     Increasing this will add extra width and height to the bounds of the object that the
     filter is applied to.
     */
    external setPadding : t => float => unit = "padding" [@@bs.set];
    /*
     The resolution of the filter. Setting this to be lower will lower the quality but
     increase the performance of the filter.
     */
    external resolution : t => float = "" [@@bs.get];
    /*
     The resolution of the filter. Setting this to be lower will lower the quality but
     increase the performance of the filter.
     */
    external setResolution : t => float => unit = "resolution" [@@bs.set];
    /*
     If enabled is true the filter is applied, if false it will not.
     */
    external enabled : t => Js.boolean = "" [@@bs.get];
    /*
     If enabled is true the filter is applied, if false it will not.
     */
    external setEnabled : t => Js.boolean => unit = "enabled" [@@bs.set];
    /*
     If enabled, pixi will fit the filter area into boundaries for better performance.
     Switch it off if it does not work for specific shader.
     */
    external autoFit : t => Js.boolean = "" [@@bs.get];
    /*
     If enabled, pixi will fit the filter area into boundaries for better performance.
     Switch it off if it does not work for specific shader.
     */
    external setAutoFit : t => Js.boolean => unit = "autoFit" [@@bs.set];
  };
  /*
   Basic FXAA implementation based on the code on geeks3d.com with the
   modification that the texture2DLod stuff was removed since it's
   unsupported by WebGL.
   */
  module FXAAFilter = {
    /*
     Basic FXAA implementation based on the code on geeks3d.com with the
     modification that the texture2DLod stuff was removed since it's
     unsupported by WebGL.
     */
    type t;
    /*
     The vertex shader.
     */
    external vertexSrc : t => string = "" [@@bs.get];
    /*
     The vertex shader.
     */
    external setVertexSrc : t => string => unit = "vertexSrc" [@@bs.set];
    /*
     The fragment shader.
     */
    external fragmentSrc : t => string = "" [@@bs.get];
    /*
     The fragment shader.
     */
    external setFragmentSrc : t => string => unit = "fragmentSrc" [@@bs.set];
    /*
     An object containing the current values of custom uniforms.
     */
    external uniforms : t => unit /* unknown js type: object */ = "" [@@bs.get];
    /*
     An object containing the current values of custom uniforms.
     */
    external setUniforms : t => unit /* unknown js type: object */ => unit = "uniforms" [@@bs.set];
    /*
     The padding of the filter. Some filters require extra space to breath such as a blur.
     Increasing this will add extra width and height to the bounds of the object that the
     filter is applied to.
     */
    external padding : t => float = "" [@@bs.get];
    /*
     The padding of the filter. Some filters require extra space to breath such as a blur.
     Increasing this will add extra width and height to the bounds of the object that the
     filter is applied to.
     */
    external setPadding : t => float => unit = "padding" [@@bs.set];
    /*
     The resolution of the filter. Setting this to be lower will lower the quality but
     increase the performance of the filter.
     */
    external resolution : t => float = "" [@@bs.get];
    /*
     The resolution of the filter. Setting this to be lower will lower the quality but
     increase the performance of the filter.
     */
    external setResolution : t => float => unit = "resolution" [@@bs.set];
    /*
     If enabled is true the filter is applied, if false it will not.
     */
    external enabled : t => Js.boolean = "" [@@bs.get];
    /*
     If enabled is true the filter is applied, if false it will not.
     */
    external setEnabled : t => Js.boolean => unit = "enabled" [@@bs.set];
    /*
     If enabled, pixi will fit the filter area into boundaries for better performance.
     Switch it off if it does not work for specific shader.
     */
    external autoFit : t => Js.boolean = "" [@@bs.get];
    /*
     If enabled, pixi will fit the filter area into boundaries for better performance.
     Switch it off if it does not work for specific shader.
     */
    external setAutoFit : t => Js.boolean => unit = "autoFit" [@@bs.set];
  };
  /*
   A Noise effect filter.
   */
  module NoiseFilter = {
    /*
     A Noise effect filter.
     */
    type t;
    /*
     The amount of noise to apply, this value should be in the range (0, 1].
     */
    external noise : t => float = "" [@@bs.get];
    /*
     The amount of noise to apply, this value should be in the range (0, 1].
     */
    external setNoise : t => float => unit = "noise" [@@bs.set];
    /*
     <p>A seed value to apply to the random noise generation. <code>Math.random()</code> is a good value to use.</p>
     */
    external seed : t => float = "" [@@bs.get];
    /*
     <p>A seed value to apply to the random noise generation. <code>Math.random()</code> is a good value to use.</p>
     */
    external setSeed : t => float => unit = "seed" [@@bs.set];
    /*
     The vertex shader.
     */
    external vertexSrc : t => string = "" [@@bs.get];
    /*
     The vertex shader.
     */
    external setVertexSrc : t => string => unit = "vertexSrc" [@@bs.set];
    /*
     The fragment shader.
     */
    external fragmentSrc : t => string = "" [@@bs.get];
    /*
     The fragment shader.
     */
    external setFragmentSrc : t => string => unit = "fragmentSrc" [@@bs.set];
    /*
     An object containing the current values of custom uniforms.
     */
    external uniforms : t => unit /* unknown js type: object */ = "" [@@bs.get];
    /*
     An object containing the current values of custom uniforms.
     */
    external setUniforms : t => unit /* unknown js type: object */ => unit = "uniforms" [@@bs.set];
    /*
     The padding of the filter. Some filters require extra space to breath such as a blur.
     Increasing this will add extra width and height to the bounds of the object that the
     filter is applied to.
     */
    external padding : t => float = "" [@@bs.get];
    /*
     The padding of the filter. Some filters require extra space to breath such as a blur.
     Increasing this will add extra width and height to the bounds of the object that the
     filter is applied to.
     */
    external setPadding : t => float => unit = "padding" [@@bs.set];
    /*
     The resolution of the filter. Setting this to be lower will lower the quality but
     increase the performance of the filter.
     */
    external resolution : t => float = "" [@@bs.get];
    /*
     The resolution of the filter. Setting this to be lower will lower the quality but
     increase the performance of the filter.
     */
    external setResolution : t => float => unit = "resolution" [@@bs.set];
    /*
     If enabled is true the filter is applied, if false it will not.
     */
    external enabled : t => Js.boolean = "" [@@bs.get];
    /*
     If enabled is true the filter is applied, if false it will not.
     */
    external setEnabled : t => Js.boolean => unit = "enabled" [@@bs.set];
    /*
     If enabled, pixi will fit the filter area into boundaries for better performance.
     Switch it off if it does not work for specific shader.
     */
    external autoFit : t => Js.boolean = "" [@@bs.get];
    /*
     If enabled, pixi will fit the filter area into boundaries for better performance.
     Switch it off if it does not work for specific shader.
     */
    external setAutoFit : t => Js.boolean => unit = "autoFit" [@@bs.set];
  };
  /*
   Does nothing. Very handy.
   */
  module VoidFilter = {
    /*
     Does nothing. Very handy.
     */
    type t;
    /*
     The vertex shader.
     */
    external vertexSrc : t => string = "" [@@bs.get];
    /*
     The vertex shader.
     */
    external setVertexSrc : t => string => unit = "vertexSrc" [@@bs.set];
    /*
     The fragment shader.
     */
    external fragmentSrc : t => string = "" [@@bs.get];
    /*
     The fragment shader.
     */
    external setFragmentSrc : t => string => unit = "fragmentSrc" [@@bs.set];
    /*
     An object containing the current values of custom uniforms.
     */
    external uniforms : t => unit /* unknown js type: object */ = "" [@@bs.get];
    /*
     An object containing the current values of custom uniforms.
     */
    external setUniforms : t => unit /* unknown js type: object */ => unit = "uniforms" [@@bs.set];
    /*
     The padding of the filter. Some filters require extra space to breath such as a blur.
     Increasing this will add extra width and height to the bounds of the object that the
     filter is applied to.
     */
    external padding : t => float = "" [@@bs.get];
    /*
     The padding of the filter. Some filters require extra space to breath such as a blur.
     Increasing this will add extra width and height to the bounds of the object that the
     filter is applied to.
     */
    external setPadding : t => float => unit = "padding" [@@bs.set];
    /*
     The resolution of the filter. Setting this to be lower will lower the quality but
     increase the performance of the filter.
     */
    external resolution : t => float = "" [@@bs.get];
    /*
     The resolution of the filter. Setting this to be lower will lower the quality but
     increase the performance of the filter.
     */
    external setResolution : t => float => unit = "resolution" [@@bs.set];
    /*
     If enabled is true the filter is applied, if false it will not.
     */
    external enabled : t => Js.boolean = "" [@@bs.get];
    /*
     If enabled is true the filter is applied, if false it will not.
     */
    external setEnabled : t => Js.boolean => unit = "enabled" [@@bs.set];
    /*
     If enabled, pixi will fit the filter area into boundaries for better performance.
     Switch it off if it does not work for specific shader.
     */
    external autoFit : t => Js.boolean = "" [@@bs.get];
    /*
     If enabled, pixi will fit the filter area into boundaries for better performance.
     Switch it off if it does not work for specific shader.
     */
    external setAutoFit : t => Js.boolean => unit = "autoFit" [@@bs.set];
  };
};

module Extract = {
  /*
   The extract manager provides functionality to export content from the renderers.

   An instance of this class is automatically created by default, and can be found at renderer.plugins.extract
   */
  module CanvasExtract = {
    /*
     The extract manager provides functionality to export content from the renderers.

     An instance of this class is automatically created by default, and can be found at renderer.plugins.extract
     */
    type t;
  };
  /*
   The extract manager provides functionality to export content from the renderers.

   An instance of this class is automatically created by default, and can be found at renderer.plugins.extract
   */
  module WebGLExtract = {
    /*
     The extract manager provides functionality to export content from the renderers.

     An instance of this class is automatically created by default, and can be found at renderer.plugins.extract
     */
    type t;
  };
};

module CacheData = {
  type t;
};

module Interaction = {
  /*
   Holds all information related to an Interaction event
   */
  module InteractionData = {
    /*
     Holds all information related to an Interaction event
     */
    type t;
    /*
     This point stores the global coords of where the touch/mouse event happened
     */
    external global : t => Point.t = "" [@@bs.get];
    /*
     This point stores the global coords of where the touch/mouse event happened
     */
    external setGlobal : t => Point.t => unit = "global" [@@bs.set];
    /*
     The target DisplayObject that was interacted with
     */
    external target : t => DisplayObject.t = "" [@@bs.get];
    /*
     The target DisplayObject that was interacted with
     */
    external setTarget : t => DisplayObject.t => unit = "target" [@@bs.set];
    /*
     When passed to an event handler, this will be the original DOM Event that was captured
     */
    external originalEvent : t => unit /* unknown js type: MouseEvent|TouchEvent|PointerEvent */ =
      "" [@@bs.get];
    /*
     When passed to an event handler, this will be the original DOM Event that was captured
     */
    external setOriginalEvent :
      t => unit /* unknown js type: MouseEvent|TouchEvent|PointerEvent */ => unit =
      "originalEvent" [@@bs.set];
    /*
     Unique identifier for this interaction
     */
    external identifier : t => float = "" [@@bs.get];
    /*
     Unique identifier for this interaction
     */
    external setIdentifier : t => float => unit = "identifier" [@@bs.set];
    /*
     Indicates whether or not the pointer device that created the event is the primary pointer.
     */
    external isPrimary : t => unit /* unknown js type: Boolean */ = "" [@@bs.get];
    /*
     Indicates whether or not the pointer device that created the event is the primary pointer.
     */
    external setIsPrimary : t => unit /* unknown js type: Boolean */ => unit =
      "isPrimary" [@@bs.set];
    /*
     Indicates which button was pressed on the mouse or pointer device to trigger the event.
     */
    external button : t => float = "" [@@bs.get];
    /*
     Indicates which button was pressed on the mouse or pointer device to trigger the event.
     */
    external setButton : t => float => unit = "button" [@@bs.set];
    /*
     Indicates which buttons are pressed on the mouse or pointer device when the event is triggered.
     */
    external buttons : t => float = "" [@@bs.get];
    /*
     Indicates which buttons are pressed on the mouse or pointer device when the event is triggered.
     */
    external setButtons : t => float => unit = "buttons" [@@bs.set];
    /*
     The width of the pointer's contact along the x-axis, measured in CSS pixels.
     radiusX of TouchEvents will be represented by this value.
     */
    external width : t => float = "" [@@bs.get];
    /*
     The width of the pointer's contact along the x-axis, measured in CSS pixels.
     radiusX of TouchEvents will be represented by this value.
     */
    external setWidth : t => float => unit = "width" [@@bs.set];
    /*
     The height of the pointer's contact along the y-axis, measured in CSS pixels.
     radiusY of TouchEvents will be represented by this value.
     */
    external height : t => float = "" [@@bs.get];
    /*
     The height of the pointer's contact along the y-axis, measured in CSS pixels.
     radiusY of TouchEvents will be represented by this value.
     */
    external setHeight : t => float => unit = "height" [@@bs.set];
    /*
     The angle, in degrees, between the pointer device and the screen.
     */
    external tiltX : t => float = "" [@@bs.get];
    /*
     The angle, in degrees, between the pointer device and the screen.
     */
    external setTiltX : t => float => unit = "tiltX" [@@bs.set];
    /*
     The angle, in degrees, between the pointer device and the screen.
     */
    external tiltY : t => float = "" [@@bs.get];
    /*
     The angle, in degrees, between the pointer device and the screen.
     */
    external setTiltY : t => float => unit = "tiltY" [@@bs.set];
    /*
     The type of pointer that triggered the event.
     */
    external pointerType : t => string = "" [@@bs.get];
    /*
     The type of pointer that triggered the event.
     */
    external setPointerType : t => string => unit = "pointerType" [@@bs.set];
    /*
     Pressure applied by the pointing device during the event. A Touch's force property
     will be represented by this value.
     */
    external pressure : t => float = "" [@@bs.get];
    /*
     Pressure applied by the pointing device during the event. A Touch's force property
     will be represented by this value.
     */
    external setPressure : t => float => unit = "pressure" [@@bs.set];
    /*
     From TouchEvents (not PointerEvents triggered by touches), the rotationAngle of the Touch.
     */
    external rotationAngle : t => float = "" [@@bs.get];
    /*
     From TouchEvents (not PointerEvents triggered by touches), the rotationAngle of the Touch.
     */
    external setRotationAngle : t => float => unit = "rotationAngle" [@@bs.set];
    /*
     Twist of a stylus pointer.
     */
    external twist : t => float = "" [@@bs.get];
    /*
     Twist of a stylus pointer.
     */
    external setTwist : t => float => unit = "twist" [@@bs.set];
    /*
     Barrel pressure on a stylus pointer.
     */
    external tangentialPressure : t => float = "" [@@bs.get];
    /*
     Barrel pressure on a stylus pointer.
     */
    external setTangentialPressure : t => float => unit = "tangentialPressure" [@@bs.set];
    /*
     <p>The unique identifier of the pointer. It will be the same as <code>identifier</code>.</p>
     */
    external pointerId : t => float = "" [@@bs.get];
  };
  /*
   Event class that mimics native DOM events.
   */
  module InteractionEvent = {
    /*
     Event class that mimics native DOM events.
     */
    type t;
    /*
     Whether this event will continue propagating in the tree
     */
    external stopped : t => Js.boolean = "" [@@bs.get];
    /*
     Whether this event will continue propagating in the tree
     */
    external setStopped : t => Js.boolean => unit = "stopped" [@@bs.set];
    /*
     The object which caused this event to be dispatched.
     For listener callback see {@link PIXI.interaction.InteractionEvent.currentTarget}.
     */
    external target : t => DisplayObject.t = "" [@@bs.get];
    /*
     The object which caused this event to be dispatched.
     For listener callback see {@link PIXI.interaction.InteractionEvent.currentTarget}.
     */
    external setTarget : t => DisplayObject.t => unit = "target" [@@bs.set];
    /*
     The object whose event listener’s callback is currently being invoked.
     */
    external currentTarget : t => DisplayObject.t = "" [@@bs.get];
    /*
     The object whose event listener’s callback is currently being invoked.
     */
    external setCurrentTarget : t => DisplayObject.t => unit = "currentTarget" [@@bs.set];
    /*
     Type of the event
     */
    external type_ : t => string = "type" [@@bs.get];
    /*
     Type of the event
     */
    external setType : t => string => unit = "type" [@@bs.set];
    /*
     InteractionData related to this event
     */
    external data : t => Interaction.InteractionData.t = "" [@@bs.get];
    /*
     InteractionData related to this event
     */
    external setData : t => Interaction.InteractionData.t => unit = "data" [@@bs.set];
  };
  /*
   The interaction manager deals with mouse, touch and pointer events. Any DisplayObject can be interactive
   if its interactive parameter is set to true
   This manager also supports multitouch.

   An instance of this class is automatically created by default, and can be found at renderer.plugins.interaction
   */
  module InteractionManager = {
    /*
     The interaction manager deals with mouse, touch and pointer events. Any DisplayObject can be interactive
     if its interactive parameter is set to true
     This manager also supports multitouch.

     An instance of this class is automatically created by default, and can be found at renderer.plugins.interaction
     */
    type t;
    /*
     The renderer this interaction manager works for.
     */
    external renderer : t => SystemRenderer.t = "" [@@bs.get];
    /*
     The renderer this interaction manager works for.
     */
    external setRenderer : t => SystemRenderer.t => unit = "renderer" [@@bs.set];
    /*
     Should default browser actions automatically be prevented.
     Does not apply to pointer events for backwards compatibility
     preventDefault on pointer events stops mouse events from firing
     Thus, for every pointer event, there will always be either a mouse of touch event alongside it.
     */
    external autoPreventDefault : t => Js.boolean = "" [@@bs.get];
    /*
     Should default browser actions automatically be prevented.
     Does not apply to pointer events for backwards compatibility
     preventDefault on pointer events stops mouse events from firing
     Thus, for every pointer event, there will always be either a mouse of touch event alongside it.
     */
    external setAutoPreventDefault : t => Js.boolean => unit = "autoPreventDefault" [@@bs.set];
    /*
     Frequency in milliseconds that the mousemove, moveover &amp; mouseout interaction events will be checked.
     */
    external interactionFrequency : t => float = "" [@@bs.get];
    /*
     Frequency in milliseconds that the mousemove, moveover &amp; mouseout interaction events will be checked.
     */
    external setInteractionFrequency : t => float => unit = "interactionFrequency" [@@bs.set];
    /*
     The mouse data
     */
    external mouse : t => Interaction.InteractionData.t = "" [@@bs.get];
    /*
     The mouse data
     */
    external setMouse : t => Interaction.InteractionData.t => unit = "mouse" [@@bs.set];
    /*
     An event data object to handle all the event tracking/dispatching
     */
    external eventData : t => unit /* unknown js type: object */ = "" [@@bs.get];
    /*
     An event data object to handle all the event tracking/dispatching
     */
    external setEventData : t => unit /* unknown js type: object */ => unit =
      "eventData" [@@bs.set];
    /*
     This property determines if mousemove and touchmove events are fired only when the cursor
     is over the object.
     Setting to true will make things work more in line with how the DOM verison works.
     Setting to false can make things easier for things like dragging
     It is currently set to false as this is how pixi used to work. This will be set to true in
     future versions of pixi.
     */
    external moveWhenInside : t => Js.boolean = "" [@@bs.get];
    /*
     This property determines if mousemove and touchmove events are fired only when the cursor
     is over the object.
     Setting to true will make things work more in line with how the DOM verison works.
     Setting to false can make things easier for things like dragging
     It is currently set to false as this is how pixi used to work. This will be set to true in
     future versions of pixi.
     */
    external setMoveWhenInside : t => Js.boolean => unit = "moveWhenInside" [@@bs.set];
    /*
     Does the device support touch events
     https://www.w3.org/TR/touch-events/
     */
    external supportsTouchEvents : t => Js.boolean = "" [@@bs.get];
    /*
     Does the device support pointer events
     https://www.w3.org/Submission/pointer-events/
     */
    external supportsPointerEvents : t => Js.boolean = "" [@@bs.get];
    /*
     Dictionary of how different cursor modes are handled. Strings are handled as CSS cursor
     values, objects are handled as dictionaries of CSS values for interactionDOMElement,
     and functions are called instead of changing the CSS.
     Default CSS cursor values are provided for 'default' and 'pointer' modes.
     */
    external cursorStyles :
      t => unit /* unknown js type: Object.<string, (string|function()|Object.<string, string>)> */ =
      "" [@@bs.get];
    /*
     Dictionary of how different cursor modes are handled. Strings are handled as CSS cursor
     values, objects are handled as dictionaries of CSS values for interactionDOMElement,
     and functions are called instead of changing the CSS.
     Default CSS cursor values are provided for 'default' and 'pointer' modes.
     */
    external setCursorStyles :
      t =>
      unit /* unknown js type: Object.<string, (string|function()|Object.<string, string>)> */ =>
      unit =
      "cursorStyles" [@@bs.set];
    /*
     The mode of the cursor that is being used.
     The value of this is a key from the cursorStyles dictionary.
     */
    external currentCursorMode : t => string = "" [@@bs.get];
    /*
     The mode of the cursor that is being used.
     The value of this is a key from the cursorStyles dictionary.
     */
    external setCurrentCursorMode : t => string => unit = "currentCursorMode" [@@bs.set];
    /*
     The current resolution / device pixel ratio.
     */
    external resolution : t => float = "" [@@bs.get];
    /*
     The current resolution / device pixel ratio.
     */
    external setResolution : t => float => unit = "resolution" [@@bs.set];
  };
};

module Loaders = {
  module Resource = {
    type t;
  };
  /*
   The new loader, extends Resource Loader by Chad Engler: https://github.com/englercj/resource-loader

   <pre class="prettyprint source lang-js"><code>const loader = PIXI.loader; // pixi exposes a premade instance for you to use.
   //or
   const loader = new PIXI.loaders.Loader(); // you can also create your own if you want

   const sprites = {};

   // Chainable `add` to enqueue a resource
   loader.add('bunny', 'data/bunny.png')
         .add('spaceship', 'assets/spritesheet.json');
   loader.add('scoreFont', 'assets/score.fnt');

   // Chainable `pre` to add a middleware that runs for each resource, *before* loading that resource.
   // This is useful to implement custom caching modules (using filesystem, indexeddb, memory, etc).
   loader.pre(cachingMiddleware);

   // Chainable `use` to add a middleware that runs for each resource, *after* loading that resource.
   // This is useful to implement custom parsing modules (like spritesheet parsers, spine parser, etc).
   loader.use(parsingMiddleware);

   // The `load` method loads the queue of resources, and calls the passed in callback called once all
   // resources have loaded.
   loader.load((loader, resources) => {
       // resources is an object where the key is the name of the resource loaded and the value is the resource object.
       // They have a couple default properties:
       // - `url`: The URL that the resource was loaded from
       // - `error`: The error that happened when trying to load (if any)
       // - `data`: The raw data that was loaded
       // also may contain other properties based on the middleware that runs.
       sprites.bunny = new PIXI.TilingSprite(resources.bunny.texture);
       sprites.spaceship = new PIXI.TilingSprite(resources.spaceship.texture);
       sprites.scoreFont = new PIXI.TilingSprite(resources.scoreFont.texture);
   });

   // throughout the process multiple signals can be dispatched.
   loader.onProgress.add(() => {}); // called once per loaded/errored file
   loader.onError.add(() => {}); // called once per errored file
   loader.onLoad.add(() => {}); // called once per loaded file
   loader.onComplete.add(() => {}); // called once when the queued resources all load.</code></pre>
   */
  module Loader = {
    /*
     The new loader, extends Resource Loader by Chad Engler: https://github.com/englercj/resource-loader

     <pre class="prettyprint source lang-js"><code>const loader = PIXI.loader; // pixi exposes a premade instance for you to use.
     //or
     const loader = new PIXI.loaders.Loader(); // you can also create your own if you want

     const sprites = {};

     // Chainable `add` to enqueue a resource
     loader.add('bunny', 'data/bunny.png')
           .add('spaceship', 'assets/spritesheet.json');
     loader.add('scoreFont', 'assets/score.fnt');

     // Chainable `pre` to add a middleware that runs for each resource, *before* loading that resource.
     // This is useful to implement custom caching modules (using filesystem, indexeddb, memory, etc).
     loader.pre(cachingMiddleware);

     // Chainable `use` to add a middleware that runs for each resource, *after* loading that resource.
     // This is useful to implement custom parsing modules (like spritesheet parsers, spine parser, etc).
     loader.use(parsingMiddleware);

     // The `load` method loads the queue of resources, and calls the passed in callback called once all
     // resources have loaded.
     loader.load((loader, resources) => {
         // resources is an object where the key is the name of the resource loaded and the value is the resource object.
         // They have a couple default properties:
         // - `url`: The URL that the resource was loaded from
         // - `error`: The error that happened when trying to load (if any)
         // - `data`: The raw data that was loaded
         // also may contain other properties based on the middleware that runs.
         sprites.bunny = new PIXI.TilingSprite(resources.bunny.texture);
         sprites.spaceship = new PIXI.TilingSprite(resources.spaceship.texture);
         sprites.scoreFont = new PIXI.TilingSprite(resources.scoreFont.texture);
     });

     // throughout the process multiple signals can be dispatched.
     loader.onProgress.add(() => {}); // called once per loaded/errored file
     loader.onError.add(() => {}); // called once per errored file
     loader.onLoad.add(() => {}); // called once per loaded file
     loader.onComplete.add(() => {}); // called once when the queued resources all load.</code></pre>
     */
    type t;
  };
};

module Mesh = {
  /*
   Base mesh class
   */
  module Mesh = {
    /*
     Base mesh class
     */
    type t;
    /*
     The Uvs of the Mesh
     */
    external uvs : t => unit /* unknown js type: Float32Array */ = "" [@@bs.get];
    /*
     The Uvs of the Mesh
     */
    external setUvs : t => unit /* unknown js type: Float32Array */ => unit = "uvs" [@@bs.set];
    /*
     An array of vertices
     */
    external vertices : t => unit /* unknown js type: Float32Array */ = "" [@@bs.get];
    /*
     An array of vertices
     */
    external setVertices : t => unit /* unknown js type: Float32Array */ => unit =
      "vertices" [@@bs.set];
    /*
     An array containing the indices of the vertices
     */
    external indices : t => unit /* unknown js type: Uint16Array */ = "" [@@bs.get];
    /*
     An array containing the indices of the vertices
     */
    external setIndices : t => unit /* unknown js type: Uint16Array */ => unit =
      "indices" [@@bs.set];
    /*
     Version of mesh uvs are dirty or not
     */
    external dirty : t => float = "" [@@bs.get];
    /*
     Version of mesh uvs are dirty or not
     */
    external setDirty : t => float => unit = "dirty" [@@bs.set];
    /*
     Version of mesh indices
     */
    external indexDirty : t => float = "" [@@bs.get];
    /*
     Version of mesh indices
     */
    external setIndexDirty : t => float => unit = "indexDirty" [@@bs.set];
    /*
     <p>The blend mode to be applied to the sprite. Set to <code>PIXI.BLEND_MODES.NORMAL</code> to remove
     any blend mode.</p>
     */
    external blendMode : t => float = "" [@@bs.get];
    /*
     <p>The blend mode to be applied to the sprite. Set to <code>PIXI.BLEND_MODES.NORMAL</code> to remove
     any blend mode.</p>
     */
    external setBlendMode : t => float => unit = "blendMode" [@@bs.set];
    /*
     Triangles in canvas mode are automatically antialiased, use this value to force triangles
     to overlap a bit with each other.
     */
    external canvasPadding : t => float = "" [@@bs.get];
    /*
     Triangles in canvas mode are automatically antialiased, use this value to force triangles
     to overlap a bit with each other.
     */
    external setCanvasPadding : t => float => unit = "canvasPadding" [@@bs.set];
    /*
     The way the Mesh should be drawn, can be any of the {@link PIXI.mesh.Mesh.DRAW_MODES} consts
     */
    external drawMode : t => float = "" [@@bs.get];
    /*
     The way the Mesh should be drawn, can be any of the {@link PIXI.mesh.Mesh.DRAW_MODES} consts
     */
    external setDrawMode : t => float => unit = "drawMode" [@@bs.set];
    /*
     The default shader that is used if a mesh doesn't have a more specific one.
     */
    external shader : t => Shader.t = "" [@@bs.get];
    /*
     The default shader that is used if a mesh doesn't have a more specific one.
     */
    external setShader : t => Shader.t => unit = "shader" [@@bs.set];
    /*
     The tint applied to the mesh. This is a [r,g,b] value. A value of [1,1,1] will remove any
     tint effect.
     */
    external tintRgb : t => float = "" [@@bs.get];
    /*
     The tint applied to the mesh. This is a [r,g,b] value. A value of [1,1,1] will remove any
     tint effect.
     */
    external setTintRgb : t => float => unit = "tintRgb" [@@bs.set];
    /*
     whether or not upload uvTransform to shader
     if its false, then uvs should be pre-multiplied
     if you change it for generated mesh, please call 'refresh(true)'
     */
    external uploadUvTransform : t => Js.boolean = "" [@@bs.get];
    /*
     whether or not upload uvTransform to shader
     if its false, then uvs should be pre-multiplied
     if you change it for generated mesh, please call 'refresh(true)'
     */
    external setUploadUvTransform : t => Js.boolean => unit = "uploadUvTransform" [@@bs.set];
    /*
     Plugin that is responsible for rendering this element.
     Allows to customize the rendering process without overriding '_renderWebGL' &amp; '_renderCanvas' methods.
     */
    external pluginName : t => string = "" [@@bs.get];
    /*
     Plugin that is responsible for rendering this element.
     Allows to customize the rendering process without overriding '_renderWebGL' &amp; '_renderCanvas' methods.
     */
    external setPluginName : t => string => unit = "pluginName" [@@bs.set];
    /*
     The texture that the mesh uses.
     */
    external texture : t => Texture.t = "" [@@bs.get];
    /*
     The texture that the mesh uses.
     */
    external setTexture : t => Texture.t => unit = "texture" [@@bs.set];
    /*
     The tint applied to the mesh. This is a hex value. A value of 0xFFFFFF will remove any tint effect.
     */
    external tint : t => float = "" [@@bs.get];
    /*
     The tint applied to the mesh. This is a hex value. A value of 0xFFFFFF will remove any tint effect.
     */
    external setTint : t => float => unit = "tint" [@@bs.set];
    /*
     The array of children of this container.
     */
    external children : t => array DisplayObject.t = "" [@@bs.get];
    /*
     The width of the Container, setting this will actually modify the scale to achieve the value set
     */
    external width : t => float = "" [@@bs.get];
    /*
     The width of the Container, setting this will actually modify the scale to achieve the value set
     */
    external setWidth : t => float => unit = "width" [@@bs.set];
    /*
     The height of the Container, setting this will actually modify the scale to achieve the value set
     */
    external height : t => float = "" [@@bs.get];
    /*
     The height of the Container, setting this will actually modify the scale to achieve the value set
     */
    external setHeight : t => float => unit = "height" [@@bs.set];
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
     World transform and local transform of this object.
     This will become read-only later, please do not assign anything there unless you know what are you doing
     */
    external transform : t => TransformBase.t = "" [@@bs.get];
    /*
     World transform and local transform of this object.
     This will become read-only later, please do not assign anything there unless you know what are you doing
     */
    external setTransform : t => TransformBase.t => unit = "transform" [@@bs.set];
    /*
     The opacity of the object.
     */
    external alpha : t => float = "" [@@bs.get];
    /*
     The opacity of the object.
     */
    external setAlpha : t => float => unit = "alpha" [@@bs.set];
    /*
     The visibility of the object. If false the object will not be drawn, and
     the updateTransform function will not be called.

     Only affects recursive calls from parent. You can ask for bounds or call updateTransform manually
     */
    external visible : t => Js.boolean = "" [@@bs.get];
    /*
     The visibility of the object. If false the object will not be drawn, and
     the updateTransform function will not be called.

     Only affects recursive calls from parent. You can ask for bounds or call updateTransform manually
     */
    external setVisible : t => Js.boolean => unit = "visible" [@@bs.set];
    /*
     Can this object be rendered, if false the object will not be drawn but the updateTransform
     methods will still be called.

     Only affects recursive calls from parent. You can ask for bounds manually
     */
    external renderable : t => Js.boolean = "" [@@bs.get];
    /*
     Can this object be rendered, if false the object will not be drawn but the updateTransform
     methods will still be called.

     Only affects recursive calls from parent. You can ask for bounds manually
     */
    external setRenderable : t => Js.boolean => unit = "renderable" [@@bs.set];
    /*
     The display object container that contains this display object.
     */
    external parent : t => Container.t = "" [@@bs.get];
    /*
     The multiplied alpha of the displayObject
     */
    external worldAlpha : t => float = "" [@@bs.get];
    /*
     The area the filter is applied to. This is used as more of an optimisation
     rather than figuring out the dimensions of the displayObject each frame you can set this rectangle

     Also works as an interaction mask
     */
    external filterArea : t => Rectangle.t = "" [@@bs.get];
    /*
     The area the filter is applied to. This is used as more of an optimisation
     rather than figuring out the dimensions of the displayObject each frame you can set this rectangle

     Also works as an interaction mask
     */
    external setFilterArea : t => Rectangle.t => unit = "filterArea" [@@bs.set];
    /*
     The position of the displayObject on the x axis relative to the local coordinates of the parent.
     An alias to position.x
     */
    external x : t => float = "" [@@bs.get];
    /*
     The position of the displayObject on the x axis relative to the local coordinates of the parent.
     An alias to position.x
     */
    external setX : t => float => unit = "x" [@@bs.set];
    /*
     The position of the displayObject on the y axis relative to the local coordinates of the parent.
     An alias to position.y
     */
    external y : t => float = "" [@@bs.get];
    /*
     The position of the displayObject on the y axis relative to the local coordinates of the parent.
     An alias to position.y
     */
    external setY : t => float => unit = "y" [@@bs.set];
    /*
     Current transform of the object based on world (parent) factors
     */
    external worldTransform : t => Matrix.t = "" [@@bs.get];
    /*
     Current transform of the object based on local factors: position, scale, other stuff
     */
    external localTransform : t => Matrix.t = "" [@@bs.get];
    /*
     The coordinate of the object relative to the local coordinates of the parent.
     Assignment by value since pixi-v4.
     */
    external position : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
      "" [@@bs.get];
    /*
     The coordinate of the object relative to the local coordinates of the parent.
     Assignment by value since pixi-v4.
     */
    external setPosition : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
      "position" [@@bs.set];
    /*
     The scale factor of the object.
     Assignment by value since pixi-v4.
     */
    external scale : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
      "" [@@bs.get];
    /*
     The scale factor of the object.
     Assignment by value since pixi-v4.
     */
    external setScale : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
      "scale" [@@bs.set];
    /*
     The pivot point of the displayObject that it rotates around
     Assignment by value since pixi-v4.
     */
    external pivot : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
      "" [@@bs.get];
    /*
     The pivot point of the displayObject that it rotates around
     Assignment by value since pixi-v4.
     */
    external setPivot : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
      "pivot" [@@bs.set];
    /*
     The skew factor for the object in radians.
     Assignment by value since pixi-v4.
     */
    external skew : t => ObservablePoint.t = "" [@@bs.get];
    /*
     The skew factor for the object in radians.
     Assignment by value since pixi-v4.
     */
    external setSkew : t => ObservablePoint.t => unit = "skew" [@@bs.set];
    /*
     The rotation of the object in radians.
     */
    external rotation : t => float = "" [@@bs.get];
    /*
     The rotation of the object in radians.
     */
    external setRotation : t => float => unit = "rotation" [@@bs.set];
    /*
     Indicates if the object is globally visible.
     */
    external worldVisible : t => Js.boolean = "" [@@bs.get];
    /*
     Sets a mask for the displayObject. A mask is an object that limits the visibility of an
     object to the shape of the mask applied to it. In PIXI a regular mask must be a
     PIXI.Graphics or a PIXI.Sprite object. This allows for much faster masking in canvas as it
     utilises shape clipping. To remove a mask, set this property to null.
     */
    external mask : t => unit /* unknown js type: PIXI.Graphics|PIXI.Sprite */ = "" [@@bs.get];
    /*
     Sets a mask for the displayObject. A mask is an object that limits the visibility of an
     object to the shape of the mask applied to it. In PIXI a regular mask must be a
     PIXI.Graphics or a PIXI.Sprite object. This allows for much faster masking in canvas as it
     utilises shape clipping. To remove a mask, set this property to null.
     */
    external setMask : t => unit /* unknown js type: PIXI.Graphics|PIXI.Sprite */ => unit =
      "mask" [@@bs.set];
    /*
     Sets the filters for the displayObject.

     <ul>
     <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
     To remove filters simply set this property to 'null'</li>
     </ul>
     */
    external filters : t => array Filter.t = "" [@@bs.get];
    /*
     Sets the filters for the displayObject.

     <ul>
     <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
     To remove filters simply set this property to 'null'</li>
     </ul>
     */
    external setFilters : t => array Filter.t => unit = "filters" [@@bs.set];
    /*
     Set this to true if you want this display object to be cached as a bitmap.
     This basically takes a snap shot of the display object as it is at that moment. It can
     provide a performance benefit for complex static displayObjects.
     To remove simply set this property to 'false'

     IMPORTANT GOTCHA - make sure that all your textures are preloaded BEFORE setting this property to true
     as it will take a snapshot of what is currently there. If the textures have not loaded then they will not appear.
     */
    external cacheAsBitmap : t => Js.boolean = "" [@@bs.get];
    /*
     Set this to true if you want this display object to be cached as a bitmap.
     This basically takes a snap shot of the display object as it is at that moment. It can
     provide a performance benefit for complex static displayObjects.
     To remove simply set this property to 'false'

     IMPORTANT GOTCHA - make sure that all your textures are preloaded BEFORE setting this property to true
     as it will take a snapshot of what is currently there. If the textures have not loaded then they will not appear.
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
     Interaction shape. Children will be hit first, then this shape will be checked.
     Setting this will cause this shape to be checked in hit tests rather than the displayObject's bounds.
     */
    external hitArea :
      t => unit /* unknown js type: PIXI.Rectangle|PIXI.Circle|PIXI.Ellipse|PIXI.Polygon|PIXI.RoundedRectangle */ =
      "" [@@bs.get];
    /*
     Interaction shape. Children will be hit first, then this shape will be checked.
     Setting this will cause this shape to be checked in hit tests rather than the displayObject's bounds.
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
     This defines what cursor mode is used when the mouse cursor
     is hovered over the displayObject.
     */
    external cursor : t => string = "" [@@bs.get];
    /*
     This defines what cursor mode is used when the mouse cursor
     is hovered over the displayObject.
     */
    external setCursor : t => string => unit = "cursor" [@@bs.set];
  };
  /*
   The NineSlicePlane allows you to stretch a texture using 9-slice scaling. The corners will remain unscaled (useful
   for buttons with rounded corners for example) and the other areas will be scaled horizontally and or vertically

   <pre class="prettyprint source lang-js"><code>let Plane9 = new PIXI.NineSlicePlane(PIXI.Texture.fromImage('BoxWithRoundedCorners.png'), 15, 15, 15, 15);</code></pre><pre>
        A                          B
      +---+----------------------+---+
    C | 1 |          2           | 3 |
      +---+----------------------+---+
      |   |                      |   |
      | 4 |          5           | 6 |
      |   |                      |   |
      +---+----------------------+---+
    D | 7 |          8           | 9 |
      +---+----------------------+---+
    When changing this objects width and/or height:
       areas 1 3 7 and 9 will remain unscaled.
       areas 2 and 8 will be stretched horizontally
       areas 4 and 6 will be stretched vertically
       area 5 will be stretched both horizontally and vertically
   </pre>
   */
  module NineSlicePlane = {
    /*
     The NineSlicePlane allows you to stretch a texture using 9-slice scaling. The corners will remain unscaled (useful
     for buttons with rounded corners for example) and the other areas will be scaled horizontally and or vertically

     <pre class="prettyprint source lang-js"><code>let Plane9 = new PIXI.NineSlicePlane(PIXI.Texture.fromImage('BoxWithRoundedCorners.png'), 15, 15, 15, 15);</code></pre><pre>
          A                          B
        +---+----------------------+---+
      C | 1 |          2           | 3 |
        +---+----------------------+---+
        |   |                      |   |
        | 4 |          5           | 6 |
        |   |                      |   |
        +---+----------------------+---+
      D | 7 |          8           | 9 |
        +---+----------------------+---+
      When changing this objects width and/or height:
         areas 1 3 7 and 9 will remain unscaled.
         areas 2 and 8 will be stretched horizontally
         areas 4 and 6 will be stretched vertically
         area 5 will be stretched both horizontally and vertically
     </pre>
     */
    type t;
    /*
     The width of the NineSlicePlane, setting this will actually modify the vertices and UV's of this plane
     */
    external _width : t => float = "" [@@bs.get];
    /*
     The width of the NineSlicePlane, setting this will actually modify the vertices and UV's of this plane
     */
    external set_width : t => float => unit = "_width" [@@bs.set];
    /*
     The height of the NineSlicePlane, setting this will actually modify the vertices and UV's of this plane
     */
    external _height : t => float = "" [@@bs.get];
    /*
     The height of the NineSlicePlane, setting this will actually modify the vertices and UV's of this plane
     */
    external set_height : t => float => unit = "_height" [@@bs.set];
    /*
     The width of the left column
     */
    external leftWidth : t => float = "" [@@bs.get];
    /*
     The width of the left column
     */
    external setLeftWidth : t => float => unit = "leftWidth" [@@bs.set];
    /*
     The width of the right column
     */
    external rightWidth : t => float = "" [@@bs.get];
    /*
     The width of the right column
     */
    external setRightWidth : t => float => unit = "rightWidth" [@@bs.set];
    /*
     The height of the top row
     */
    external topHeight : t => float = "" [@@bs.get];
    /*
     The height of the top row
     */
    external setTopHeight : t => float => unit = "topHeight" [@@bs.set];
    /*
     The height of the bottom row
     */
    external bottomHeight : t => float = "" [@@bs.get];
    /*
     The height of the bottom row
     */
    external setBottomHeight : t => float => unit = "bottomHeight" [@@bs.set];
    /*
     The width of the NineSlicePlane, setting this will actually modify the vertices and UV's of this plane
     */
    external width : t => float = "" [@@bs.get];
    /*
     The width of the NineSlicePlane, setting this will actually modify the vertices and UV's of this plane
     */
    external setWidth : t => float => unit = "width" [@@bs.set];
    /*
     The height of the NineSlicePlane, setting this will actually modify the vertices and UV's of this plane
     */
    external height : t => float = "" [@@bs.get];
    /*
     The height of the NineSlicePlane, setting this will actually modify the vertices and UV's of this plane
     */
    external setHeight : t => float => unit = "height" [@@bs.set];
    /*
     The Uvs of the Mesh
     */
    external uvs : t => unit /* unknown js type: Float32Array */ = "" [@@bs.get];
    /*
     The Uvs of the Mesh
     */
    external setUvs : t => unit /* unknown js type: Float32Array */ => unit = "uvs" [@@bs.set];
    /*
     An array of vertices
     */
    external vertices : t => unit /* unknown js type: Float32Array */ = "" [@@bs.get];
    /*
     An array of vertices
     */
    external setVertices : t => unit /* unknown js type: Float32Array */ => unit =
      "vertices" [@@bs.set];
    /*
     Version of mesh uvs are dirty or not
     */
    external dirty : t => float = "" [@@bs.get];
    /*
     Version of mesh uvs are dirty or not
     */
    external setDirty : t => float => unit = "dirty" [@@bs.set];
    /*
     Version of mesh indices
     */
    external indexDirty : t => float = "" [@@bs.get];
    /*
     Version of mesh indices
     */
    external setIndexDirty : t => float => unit = "indexDirty" [@@bs.set];
    /*
     <p>The blend mode to be applied to the sprite. Set to <code>PIXI.BLEND_MODES.NORMAL</code> to remove
     any blend mode.</p>
     */
    external blendMode : t => float = "" [@@bs.get];
    /*
     <p>The blend mode to be applied to the sprite. Set to <code>PIXI.BLEND_MODES.NORMAL</code> to remove
     any blend mode.</p>
     */
    external setBlendMode : t => float => unit = "blendMode" [@@bs.set];
    /*
     Triangles in canvas mode are automatically antialiased, use this value to force triangles
     to overlap a bit with each other.
     */
    external canvasPadding : t => float = "" [@@bs.get];
    /*
     Triangles in canvas mode are automatically antialiased, use this value to force triangles
     to overlap a bit with each other.
     */
    external setCanvasPadding : t => float => unit = "canvasPadding" [@@bs.set];
    /*
     The way the Mesh should be drawn, can be any of the {@link PIXI.mesh.Mesh.DRAW_MODES} consts
     */
    external drawMode : t => float = "" [@@bs.get];
    /*
     The way the Mesh should be drawn, can be any of the {@link PIXI.mesh.Mesh.DRAW_MODES} consts
     */
    external setDrawMode : t => float => unit = "drawMode" [@@bs.set];
    /*
     The default shader that is used if a mesh doesn't have a more specific one.
     */
    external shader : t => Shader.t = "" [@@bs.get];
    /*
     The default shader that is used if a mesh doesn't have a more specific one.
     */
    external setShader : t => Shader.t => unit = "shader" [@@bs.set];
    /*
     The tint applied to the mesh. This is a [r,g,b] value. A value of [1,1,1] will remove any
     tint effect.
     */
    external tintRgb : t => float = "" [@@bs.get];
    /*
     The tint applied to the mesh. This is a [r,g,b] value. A value of [1,1,1] will remove any
     tint effect.
     */
    external setTintRgb : t => float => unit = "tintRgb" [@@bs.set];
    /*
     whether or not upload uvTransform to shader
     if its false, then uvs should be pre-multiplied
     if you change it for generated mesh, please call 'refresh(true)'
     */
    external uploadUvTransform : t => Js.boolean = "" [@@bs.get];
    /*
     whether or not upload uvTransform to shader
     if its false, then uvs should be pre-multiplied
     if you change it for generated mesh, please call 'refresh(true)'
     */
    external setUploadUvTransform : t => Js.boolean => unit = "uploadUvTransform" [@@bs.set];
    /*
     Plugin that is responsible for rendering this element.
     Allows to customize the rendering process without overriding '_renderWebGL' &amp; '_renderCanvas' methods.
     */
    external pluginName : t => string = "" [@@bs.get];
    /*
     Plugin that is responsible for rendering this element.
     Allows to customize the rendering process without overriding '_renderWebGL' &amp; '_renderCanvas' methods.
     */
    external setPluginName : t => string => unit = "pluginName" [@@bs.set];
    /*
     The texture that the mesh uses.
     */
    external texture : t => Texture.t = "" [@@bs.get];
    /*
     The texture that the mesh uses.
     */
    external setTexture : t => Texture.t => unit = "texture" [@@bs.set];
    /*
     The tint applied to the mesh. This is a hex value. A value of 0xFFFFFF will remove any tint effect.
     */
    external tint : t => float = "" [@@bs.get];
    /*
     The tint applied to the mesh. This is a hex value. A value of 0xFFFFFF will remove any tint effect.
     */
    external setTint : t => float => unit = "tint" [@@bs.set];
    /*
     The array of children of this container.
     */
    external children : t => array DisplayObject.t = "" [@@bs.get];
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
     World transform and local transform of this object.
     This will become read-only later, please do not assign anything there unless you know what are you doing
     */
    external transform : t => TransformBase.t = "" [@@bs.get];
    /*
     World transform and local transform of this object.
     This will become read-only later, please do not assign anything there unless you know what are you doing
     */
    external setTransform : t => TransformBase.t => unit = "transform" [@@bs.set];
    /*
     The opacity of the object.
     */
    external alpha : t => float = "" [@@bs.get];
    /*
     The opacity of the object.
     */
    external setAlpha : t => float => unit = "alpha" [@@bs.set];
    /*
     The visibility of the object. If false the object will not be drawn, and
     the updateTransform function will not be called.

     Only affects recursive calls from parent. You can ask for bounds or call updateTransform manually
     */
    external visible : t => Js.boolean = "" [@@bs.get];
    /*
     The visibility of the object. If false the object will not be drawn, and
     the updateTransform function will not be called.

     Only affects recursive calls from parent. You can ask for bounds or call updateTransform manually
     */
    external setVisible : t => Js.boolean => unit = "visible" [@@bs.set];
    /*
     Can this object be rendered, if false the object will not be drawn but the updateTransform
     methods will still be called.

     Only affects recursive calls from parent. You can ask for bounds manually
     */
    external renderable : t => Js.boolean = "" [@@bs.get];
    /*
     Can this object be rendered, if false the object will not be drawn but the updateTransform
     methods will still be called.

     Only affects recursive calls from parent. You can ask for bounds manually
     */
    external setRenderable : t => Js.boolean => unit = "renderable" [@@bs.set];
    /*
     The display object container that contains this display object.
     */
    external parent : t => Container.t = "" [@@bs.get];
    /*
     The multiplied alpha of the displayObject
     */
    external worldAlpha : t => float = "" [@@bs.get];
    /*
     The area the filter is applied to. This is used as more of an optimisation
     rather than figuring out the dimensions of the displayObject each frame you can set this rectangle

     Also works as an interaction mask
     */
    external filterArea : t => Rectangle.t = "" [@@bs.get];
    /*
     The area the filter is applied to. This is used as more of an optimisation
     rather than figuring out the dimensions of the displayObject each frame you can set this rectangle

     Also works as an interaction mask
     */
    external setFilterArea : t => Rectangle.t => unit = "filterArea" [@@bs.set];
    /*
     The position of the displayObject on the x axis relative to the local coordinates of the parent.
     An alias to position.x
     */
    external x : t => float = "" [@@bs.get];
    /*
     The position of the displayObject on the x axis relative to the local coordinates of the parent.
     An alias to position.x
     */
    external setX : t => float => unit = "x" [@@bs.set];
    /*
     The position of the displayObject on the y axis relative to the local coordinates of the parent.
     An alias to position.y
     */
    external y : t => float = "" [@@bs.get];
    /*
     The position of the displayObject on the y axis relative to the local coordinates of the parent.
     An alias to position.y
     */
    external setY : t => float => unit = "y" [@@bs.set];
    /*
     Current transform of the object based on world (parent) factors
     */
    external worldTransform : t => Matrix.t = "" [@@bs.get];
    /*
     Current transform of the object based on local factors: position, scale, other stuff
     */
    external localTransform : t => Matrix.t = "" [@@bs.get];
    /*
     The coordinate of the object relative to the local coordinates of the parent.
     Assignment by value since pixi-v4.
     */
    external position : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
      "" [@@bs.get];
    /*
     The coordinate of the object relative to the local coordinates of the parent.
     Assignment by value since pixi-v4.
     */
    external setPosition : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
      "position" [@@bs.set];
    /*
     The scale factor of the object.
     Assignment by value since pixi-v4.
     */
    external scale : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
      "" [@@bs.get];
    /*
     The scale factor of the object.
     Assignment by value since pixi-v4.
     */
    external setScale : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
      "scale" [@@bs.set];
    /*
     The pivot point of the displayObject that it rotates around
     Assignment by value since pixi-v4.
     */
    external pivot : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
      "" [@@bs.get];
    /*
     The pivot point of the displayObject that it rotates around
     Assignment by value since pixi-v4.
     */
    external setPivot : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
      "pivot" [@@bs.set];
    /*
     The skew factor for the object in radians.
     Assignment by value since pixi-v4.
     */
    external skew : t => ObservablePoint.t = "" [@@bs.get];
    /*
     The skew factor for the object in radians.
     Assignment by value since pixi-v4.
     */
    external setSkew : t => ObservablePoint.t => unit = "skew" [@@bs.set];
    /*
     The rotation of the object in radians.
     */
    external rotation : t => float = "" [@@bs.get];
    /*
     The rotation of the object in radians.
     */
    external setRotation : t => float => unit = "rotation" [@@bs.set];
    /*
     Indicates if the object is globally visible.
     */
    external worldVisible : t => Js.boolean = "" [@@bs.get];
    /*
     Sets a mask for the displayObject. A mask is an object that limits the visibility of an
     object to the shape of the mask applied to it. In PIXI a regular mask must be a
     PIXI.Graphics or a PIXI.Sprite object. This allows for much faster masking in canvas as it
     utilises shape clipping. To remove a mask, set this property to null.
     */
    external mask : t => unit /* unknown js type: PIXI.Graphics|PIXI.Sprite */ = "" [@@bs.get];
    /*
     Sets a mask for the displayObject. A mask is an object that limits the visibility of an
     object to the shape of the mask applied to it. In PIXI a regular mask must be a
     PIXI.Graphics or a PIXI.Sprite object. This allows for much faster masking in canvas as it
     utilises shape clipping. To remove a mask, set this property to null.
     */
    external setMask : t => unit /* unknown js type: PIXI.Graphics|PIXI.Sprite */ => unit =
      "mask" [@@bs.set];
    /*
     Sets the filters for the displayObject.

     <ul>
     <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
     To remove filters simply set this property to 'null'</li>
     </ul>
     */
    external filters : t => array Filter.t = "" [@@bs.get];
    /*
     Sets the filters for the displayObject.

     <ul>
     <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
     To remove filters simply set this property to 'null'</li>
     </ul>
     */
    external setFilters : t => array Filter.t => unit = "filters" [@@bs.set];
    /*
     Set this to true if you want this display object to be cached as a bitmap.
     This basically takes a snap shot of the display object as it is at that moment. It can
     provide a performance benefit for complex static displayObjects.
     To remove simply set this property to 'false'

     IMPORTANT GOTCHA - make sure that all your textures are preloaded BEFORE setting this property to true
     as it will take a snapshot of what is currently there. If the textures have not loaded then they will not appear.
     */
    external cacheAsBitmap : t => Js.boolean = "" [@@bs.get];
    /*
     Set this to true if you want this display object to be cached as a bitmap.
     This basically takes a snap shot of the display object as it is at that moment. It can
     provide a performance benefit for complex static displayObjects.
     To remove simply set this property to 'false'

     IMPORTANT GOTCHA - make sure that all your textures are preloaded BEFORE setting this property to true
     as it will take a snapshot of what is currently there. If the textures have not loaded then they will not appear.
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
     Interaction shape. Children will be hit first, then this shape will be checked.
     Setting this will cause this shape to be checked in hit tests rather than the displayObject's bounds.
     */
    external hitArea :
      t => unit /* unknown js type: PIXI.Rectangle|PIXI.Circle|PIXI.Ellipse|PIXI.Polygon|PIXI.RoundedRectangle */ =
      "" [@@bs.get];
    /*
     Interaction shape. Children will be hit first, then this shape will be checked.
     Setting this will cause this shape to be checked in hit tests rather than the displayObject's bounds.
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
     This defines what cursor mode is used when the mouse cursor
     is hovered over the displayObject.
     */
    external cursor : t => string = "" [@@bs.get];
    /*
     This defines what cursor mode is used when the mouse cursor
     is hovered over the displayObject.
     */
    external setCursor : t => string => unit = "cursor" [@@bs.set];
  };
  /*
   The Plane allows you to draw a texture across several points and them manipulate these points

   <pre class="prettyprint source lang-js"><code>for (let i = 0; i &lt; 20; i++) {
       points.push(new PIXI.Point(i * 50, 0));
   };
   let Plane = new PIXI.Plane(PIXI.Texture.fromImage(&quot;snake.png&quot;), points);</code></pre>
   */
  module Plane = {
    /*
     The Plane allows you to draw a texture across several points and them manipulate these points

     <pre class="prettyprint source lang-js"><code>for (let i = 0; i &lt; 20; i++) {
         points.push(new PIXI.Point(i * 50, 0));
     };
     let Plane = new PIXI.Plane(PIXI.Texture.fromImage(&quot;snake.png&quot;), points);</code></pre>
     */
    type t;
    /*
     The Uvs of the Mesh
     */
    external uvs : t => unit /* unknown js type: Float32Array */ = "" [@@bs.get];
    /*
     The Uvs of the Mesh
     */
    external setUvs : t => unit /* unknown js type: Float32Array */ => unit = "uvs" [@@bs.set];
    /*
     An array of vertices
     */
    external vertices : t => unit /* unknown js type: Float32Array */ = "" [@@bs.get];
    /*
     An array of vertices
     */
    external setVertices : t => unit /* unknown js type: Float32Array */ => unit =
      "vertices" [@@bs.set];
    /*
     Version of mesh uvs are dirty or not
     */
    external dirty : t => float = "" [@@bs.get];
    /*
     Version of mesh uvs are dirty or not
     */
    external setDirty : t => float => unit = "dirty" [@@bs.set];
    /*
     Version of mesh indices
     */
    external indexDirty : t => float = "" [@@bs.get];
    /*
     Version of mesh indices
     */
    external setIndexDirty : t => float => unit = "indexDirty" [@@bs.set];
    /*
     <p>The blend mode to be applied to the sprite. Set to <code>PIXI.BLEND_MODES.NORMAL</code> to remove
     any blend mode.</p>
     */
    external blendMode : t => float = "" [@@bs.get];
    /*
     <p>The blend mode to be applied to the sprite. Set to <code>PIXI.BLEND_MODES.NORMAL</code> to remove
     any blend mode.</p>
     */
    external setBlendMode : t => float => unit = "blendMode" [@@bs.set];
    /*
     Triangles in canvas mode are automatically antialiased, use this value to force triangles
     to overlap a bit with each other.
     */
    external canvasPadding : t => float = "" [@@bs.get];
    /*
     Triangles in canvas mode are automatically antialiased, use this value to force triangles
     to overlap a bit with each other.
     */
    external setCanvasPadding : t => float => unit = "canvasPadding" [@@bs.set];
    /*
     The way the Mesh should be drawn, can be any of the {@link PIXI.mesh.Mesh.DRAW_MODES} consts
     */
    external drawMode : t => float = "" [@@bs.get];
    /*
     The way the Mesh should be drawn, can be any of the {@link PIXI.mesh.Mesh.DRAW_MODES} consts
     */
    external setDrawMode : t => float => unit = "drawMode" [@@bs.set];
    /*
     The default shader that is used if a mesh doesn't have a more specific one.
     */
    external shader : t => Shader.t = "" [@@bs.get];
    /*
     The default shader that is used if a mesh doesn't have a more specific one.
     */
    external setShader : t => Shader.t => unit = "shader" [@@bs.set];
    /*
     The tint applied to the mesh. This is a [r,g,b] value. A value of [1,1,1] will remove any
     tint effect.
     */
    external tintRgb : t => float = "" [@@bs.get];
    /*
     The tint applied to the mesh. This is a [r,g,b] value. A value of [1,1,1] will remove any
     tint effect.
     */
    external setTintRgb : t => float => unit = "tintRgb" [@@bs.set];
    /*
     whether or not upload uvTransform to shader
     if its false, then uvs should be pre-multiplied
     if you change it for generated mesh, please call 'refresh(true)'
     */
    external uploadUvTransform : t => Js.boolean = "" [@@bs.get];
    /*
     whether or not upload uvTransform to shader
     if its false, then uvs should be pre-multiplied
     if you change it for generated mesh, please call 'refresh(true)'
     */
    external setUploadUvTransform : t => Js.boolean => unit = "uploadUvTransform" [@@bs.set];
    /*
     Plugin that is responsible for rendering this element.
     Allows to customize the rendering process without overriding '_renderWebGL' &amp; '_renderCanvas' methods.
     */
    external pluginName : t => string = "" [@@bs.get];
    /*
     Plugin that is responsible for rendering this element.
     Allows to customize the rendering process without overriding '_renderWebGL' &amp; '_renderCanvas' methods.
     */
    external setPluginName : t => string => unit = "pluginName" [@@bs.set];
    /*
     The texture that the mesh uses.
     */
    external texture : t => Texture.t = "" [@@bs.get];
    /*
     The texture that the mesh uses.
     */
    external setTexture : t => Texture.t => unit = "texture" [@@bs.set];
    /*
     The tint applied to the mesh. This is a hex value. A value of 0xFFFFFF will remove any tint effect.
     */
    external tint : t => float = "" [@@bs.get];
    /*
     The tint applied to the mesh. This is a hex value. A value of 0xFFFFFF will remove any tint effect.
     */
    external setTint : t => float => unit = "tint" [@@bs.set];
    /*
     The array of children of this container.
     */
    external children : t => array DisplayObject.t = "" [@@bs.get];
    /*
     The width of the Container, setting this will actually modify the scale to achieve the value set
     */
    external width : t => float = "" [@@bs.get];
    /*
     The width of the Container, setting this will actually modify the scale to achieve the value set
     */
    external setWidth : t => float => unit = "width" [@@bs.set];
    /*
     The height of the Container, setting this will actually modify the scale to achieve the value set
     */
    external height : t => float = "" [@@bs.get];
    /*
     The height of the Container, setting this will actually modify the scale to achieve the value set
     */
    external setHeight : t => float => unit = "height" [@@bs.set];
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
     World transform and local transform of this object.
     This will become read-only later, please do not assign anything there unless you know what are you doing
     */
    external transform : t => TransformBase.t = "" [@@bs.get];
    /*
     World transform and local transform of this object.
     This will become read-only later, please do not assign anything there unless you know what are you doing
     */
    external setTransform : t => TransformBase.t => unit = "transform" [@@bs.set];
    /*
     The opacity of the object.
     */
    external alpha : t => float = "" [@@bs.get];
    /*
     The opacity of the object.
     */
    external setAlpha : t => float => unit = "alpha" [@@bs.set];
    /*
     The visibility of the object. If false the object will not be drawn, and
     the updateTransform function will not be called.

     Only affects recursive calls from parent. You can ask for bounds or call updateTransform manually
     */
    external visible : t => Js.boolean = "" [@@bs.get];
    /*
     The visibility of the object. If false the object will not be drawn, and
     the updateTransform function will not be called.

     Only affects recursive calls from parent. You can ask for bounds or call updateTransform manually
     */
    external setVisible : t => Js.boolean => unit = "visible" [@@bs.set];
    /*
     Can this object be rendered, if false the object will not be drawn but the updateTransform
     methods will still be called.

     Only affects recursive calls from parent. You can ask for bounds manually
     */
    external renderable : t => Js.boolean = "" [@@bs.get];
    /*
     Can this object be rendered, if false the object will not be drawn but the updateTransform
     methods will still be called.

     Only affects recursive calls from parent. You can ask for bounds manually
     */
    external setRenderable : t => Js.boolean => unit = "renderable" [@@bs.set];
    /*
     The display object container that contains this display object.
     */
    external parent : t => Container.t = "" [@@bs.get];
    /*
     The multiplied alpha of the displayObject
     */
    external worldAlpha : t => float = "" [@@bs.get];
    /*
     The area the filter is applied to. This is used as more of an optimisation
     rather than figuring out the dimensions of the displayObject each frame you can set this rectangle

     Also works as an interaction mask
     */
    external filterArea : t => Rectangle.t = "" [@@bs.get];
    /*
     The area the filter is applied to. This is used as more of an optimisation
     rather than figuring out the dimensions of the displayObject each frame you can set this rectangle

     Also works as an interaction mask
     */
    external setFilterArea : t => Rectangle.t => unit = "filterArea" [@@bs.set];
    /*
     The position of the displayObject on the x axis relative to the local coordinates of the parent.
     An alias to position.x
     */
    external x : t => float = "" [@@bs.get];
    /*
     The position of the displayObject on the x axis relative to the local coordinates of the parent.
     An alias to position.x
     */
    external setX : t => float => unit = "x" [@@bs.set];
    /*
     The position of the displayObject on the y axis relative to the local coordinates of the parent.
     An alias to position.y
     */
    external y : t => float = "" [@@bs.get];
    /*
     The position of the displayObject on the y axis relative to the local coordinates of the parent.
     An alias to position.y
     */
    external setY : t => float => unit = "y" [@@bs.set];
    /*
     Current transform of the object based on world (parent) factors
     */
    external worldTransform : t => Matrix.t = "" [@@bs.get];
    /*
     Current transform of the object based on local factors: position, scale, other stuff
     */
    external localTransform : t => Matrix.t = "" [@@bs.get];
    /*
     The coordinate of the object relative to the local coordinates of the parent.
     Assignment by value since pixi-v4.
     */
    external position : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
      "" [@@bs.get];
    /*
     The coordinate of the object relative to the local coordinates of the parent.
     Assignment by value since pixi-v4.
     */
    external setPosition : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
      "position" [@@bs.set];
    /*
     The scale factor of the object.
     Assignment by value since pixi-v4.
     */
    external scale : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
      "" [@@bs.get];
    /*
     The scale factor of the object.
     Assignment by value since pixi-v4.
     */
    external setScale : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
      "scale" [@@bs.set];
    /*
     The pivot point of the displayObject that it rotates around
     Assignment by value since pixi-v4.
     */
    external pivot : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
      "" [@@bs.get];
    /*
     The pivot point of the displayObject that it rotates around
     Assignment by value since pixi-v4.
     */
    external setPivot : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
      "pivot" [@@bs.set];
    /*
     The skew factor for the object in radians.
     Assignment by value since pixi-v4.
     */
    external skew : t => ObservablePoint.t = "" [@@bs.get];
    /*
     The skew factor for the object in radians.
     Assignment by value since pixi-v4.
     */
    external setSkew : t => ObservablePoint.t => unit = "skew" [@@bs.set];
    /*
     The rotation of the object in radians.
     */
    external rotation : t => float = "" [@@bs.get];
    /*
     The rotation of the object in radians.
     */
    external setRotation : t => float => unit = "rotation" [@@bs.set];
    /*
     Indicates if the object is globally visible.
     */
    external worldVisible : t => Js.boolean = "" [@@bs.get];
    /*
     Sets a mask for the displayObject. A mask is an object that limits the visibility of an
     object to the shape of the mask applied to it. In PIXI a regular mask must be a
     PIXI.Graphics or a PIXI.Sprite object. This allows for much faster masking in canvas as it
     utilises shape clipping. To remove a mask, set this property to null.
     */
    external mask : t => unit /* unknown js type: PIXI.Graphics|PIXI.Sprite */ = "" [@@bs.get];
    /*
     Sets a mask for the displayObject. A mask is an object that limits the visibility of an
     object to the shape of the mask applied to it. In PIXI a regular mask must be a
     PIXI.Graphics or a PIXI.Sprite object. This allows for much faster masking in canvas as it
     utilises shape clipping. To remove a mask, set this property to null.
     */
    external setMask : t => unit /* unknown js type: PIXI.Graphics|PIXI.Sprite */ => unit =
      "mask" [@@bs.set];
    /*
     Sets the filters for the displayObject.

     <ul>
     <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
     To remove filters simply set this property to 'null'</li>
     </ul>
     */
    external filters : t => array Filter.t = "" [@@bs.get];
    /*
     Sets the filters for the displayObject.

     <ul>
     <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
     To remove filters simply set this property to 'null'</li>
     </ul>
     */
    external setFilters : t => array Filter.t => unit = "filters" [@@bs.set];
    /*
     Set this to true if you want this display object to be cached as a bitmap.
     This basically takes a snap shot of the display object as it is at that moment. It can
     provide a performance benefit for complex static displayObjects.
     To remove simply set this property to 'false'

     IMPORTANT GOTCHA - make sure that all your textures are preloaded BEFORE setting this property to true
     as it will take a snapshot of what is currently there. If the textures have not loaded then they will not appear.
     */
    external cacheAsBitmap : t => Js.boolean = "" [@@bs.get];
    /*
     Set this to true if you want this display object to be cached as a bitmap.
     This basically takes a snap shot of the display object as it is at that moment. It can
     provide a performance benefit for complex static displayObjects.
     To remove simply set this property to 'false'

     IMPORTANT GOTCHA - make sure that all your textures are preloaded BEFORE setting this property to true
     as it will take a snapshot of what is currently there. If the textures have not loaded then they will not appear.
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
     Interaction shape. Children will be hit first, then this shape will be checked.
     Setting this will cause this shape to be checked in hit tests rather than the displayObject's bounds.
     */
    external hitArea :
      t => unit /* unknown js type: PIXI.Rectangle|PIXI.Circle|PIXI.Ellipse|PIXI.Polygon|PIXI.RoundedRectangle */ =
      "" [@@bs.get];
    /*
     Interaction shape. Children will be hit first, then this shape will be checked.
     Setting this will cause this shape to be checked in hit tests rather than the displayObject's bounds.
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
     This defines what cursor mode is used when the mouse cursor
     is hovered over the displayObject.
     */
    external cursor : t => string = "" [@@bs.get];
    /*
     This defines what cursor mode is used when the mouse cursor
     is hovered over the displayObject.
     */
    external setCursor : t => string => unit = "cursor" [@@bs.set];
  };
  /*
   The rope allows you to draw a texture across several points and them manipulate these points

   <pre class="prettyprint source lang-js"><code>for (let i = 0; i &lt; 20; i++) {
       points.push(new PIXI.Point(i * 50, 0));
   };
   let rope = new PIXI.Rope(PIXI.Texture.fromImage(&quot;snake.png&quot;), points);</code></pre>
   */
  module Rope = {
    /*
     The rope allows you to draw a texture across several points and them manipulate these points

     <pre class="prettyprint source lang-js"><code>for (let i = 0; i &lt; 20; i++) {
         points.push(new PIXI.Point(i * 50, 0));
     };
     let rope = new PIXI.Rope(PIXI.Texture.fromImage(&quot;snake.png&quot;), points);</code></pre>
     */
    type t;
    /*
     An array of points that determine the rope
     */
    external points : t => array Point.t = "" [@@bs.get];
    /*
     An array of points that determine the rope
     */
    external setPoints : t => array Point.t => unit = "points" [@@bs.set];
    /*
     An array of vertices used to construct this rope.
     */
    external vertices : t => unit /* unknown js type: Float32Array */ = "" [@@bs.get];
    /*
     An array of vertices used to construct this rope.
     */
    external setVertices : t => unit /* unknown js type: Float32Array */ => unit =
      "vertices" [@@bs.set];
    /*
     The WebGL Uvs of the rope.
     */
    external uvs : t => unit /* unknown js type: Float32Array */ = "" [@@bs.get];
    /*
     The WebGL Uvs of the rope.
     */
    external setUvs : t => unit /* unknown js type: Float32Array */ => unit = "uvs" [@@bs.set];
    /*
     An array containing the color components
     */
    external colors : t => unit /* unknown js type: Float32Array */ = "" [@@bs.get];
    /*
     An array containing the color components
     */
    external setColors : t => unit /* unknown js type: Float32Array */ => unit =
      "colors" [@@bs.set];
    /*
     An array containing the indices of the vertices
     */
    external indices : t => unit /* unknown js type: Uint16Array */ = "" [@@bs.get];
    /*
     An array containing the indices of the vertices
     */
    external setIndices : t => unit /* unknown js type: Uint16Array */ => unit =
      "indices" [@@bs.set];
    /*
     refreshes vertices on every updateTransform
     */
    external autoUpdate : t => Js.boolean = "" [@@bs.get];
    /*
     refreshes vertices on every updateTransform
     */
    external setAutoUpdate : t => Js.boolean => unit = "autoUpdate" [@@bs.set];
    /*
     Version of mesh uvs are dirty or not
     */
    external dirty : t => float = "" [@@bs.get];
    /*
     Version of mesh uvs are dirty or not
     */
    external setDirty : t => float => unit = "dirty" [@@bs.set];
    /*
     Version of mesh indices
     */
    external indexDirty : t => float = "" [@@bs.get];
    /*
     Version of mesh indices
     */
    external setIndexDirty : t => float => unit = "indexDirty" [@@bs.set];
    /*
     <p>The blend mode to be applied to the sprite. Set to <code>PIXI.BLEND_MODES.NORMAL</code> to remove
     any blend mode.</p>
     */
    external blendMode : t => float = "" [@@bs.get];
    /*
     <p>The blend mode to be applied to the sprite. Set to <code>PIXI.BLEND_MODES.NORMAL</code> to remove
     any blend mode.</p>
     */
    external setBlendMode : t => float => unit = "blendMode" [@@bs.set];
    /*
     Triangles in canvas mode are automatically antialiased, use this value to force triangles
     to overlap a bit with each other.
     */
    external canvasPadding : t => float = "" [@@bs.get];
    /*
     Triangles in canvas mode are automatically antialiased, use this value to force triangles
     to overlap a bit with each other.
     */
    external setCanvasPadding : t => float => unit = "canvasPadding" [@@bs.set];
    /*
     The way the Mesh should be drawn, can be any of the {@link PIXI.mesh.Mesh.DRAW_MODES} consts
     */
    external drawMode : t => float = "" [@@bs.get];
    /*
     The way the Mesh should be drawn, can be any of the {@link PIXI.mesh.Mesh.DRAW_MODES} consts
     */
    external setDrawMode : t => float => unit = "drawMode" [@@bs.set];
    /*
     The default shader that is used if a mesh doesn't have a more specific one.
     */
    external shader : t => Shader.t = "" [@@bs.get];
    /*
     The default shader that is used if a mesh doesn't have a more specific one.
     */
    external setShader : t => Shader.t => unit = "shader" [@@bs.set];
    /*
     The tint applied to the mesh. This is a [r,g,b] value. A value of [1,1,1] will remove any
     tint effect.
     */
    external tintRgb : t => float = "" [@@bs.get];
    /*
     The tint applied to the mesh. This is a [r,g,b] value. A value of [1,1,1] will remove any
     tint effect.
     */
    external setTintRgb : t => float => unit = "tintRgb" [@@bs.set];
    /*
     whether or not upload uvTransform to shader
     if its false, then uvs should be pre-multiplied
     if you change it for generated mesh, please call 'refresh(true)'
     */
    external uploadUvTransform : t => Js.boolean = "" [@@bs.get];
    /*
     whether or not upload uvTransform to shader
     if its false, then uvs should be pre-multiplied
     if you change it for generated mesh, please call 'refresh(true)'
     */
    external setUploadUvTransform : t => Js.boolean => unit = "uploadUvTransform" [@@bs.set];
    /*
     Plugin that is responsible for rendering this element.
     Allows to customize the rendering process without overriding '_renderWebGL' &amp; '_renderCanvas' methods.
     */
    external pluginName : t => string = "" [@@bs.get];
    /*
     Plugin that is responsible for rendering this element.
     Allows to customize the rendering process without overriding '_renderWebGL' &amp; '_renderCanvas' methods.
     */
    external setPluginName : t => string => unit = "pluginName" [@@bs.set];
    /*
     The texture that the mesh uses.
     */
    external texture : t => Texture.t = "" [@@bs.get];
    /*
     The texture that the mesh uses.
     */
    external setTexture : t => Texture.t => unit = "texture" [@@bs.set];
    /*
     The tint applied to the mesh. This is a hex value. A value of 0xFFFFFF will remove any tint effect.
     */
    external tint : t => float = "" [@@bs.get];
    /*
     The tint applied to the mesh. This is a hex value. A value of 0xFFFFFF will remove any tint effect.
     */
    external setTint : t => float => unit = "tint" [@@bs.set];
    /*
     The array of children of this container.
     */
    external children : t => array DisplayObject.t = "" [@@bs.get];
    /*
     The width of the Container, setting this will actually modify the scale to achieve the value set
     */
    external width : t => float = "" [@@bs.get];
    /*
     The width of the Container, setting this will actually modify the scale to achieve the value set
     */
    external setWidth : t => float => unit = "width" [@@bs.set];
    /*
     The height of the Container, setting this will actually modify the scale to achieve the value set
     */
    external height : t => float = "" [@@bs.get];
    /*
     The height of the Container, setting this will actually modify the scale to achieve the value set
     */
    external setHeight : t => float => unit = "height" [@@bs.set];
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
     World transform and local transform of this object.
     This will become read-only later, please do not assign anything there unless you know what are you doing
     */
    external transform : t => TransformBase.t = "" [@@bs.get];
    /*
     World transform and local transform of this object.
     This will become read-only later, please do not assign anything there unless you know what are you doing
     */
    external setTransform : t => TransformBase.t => unit = "transform" [@@bs.set];
    /*
     The opacity of the object.
     */
    external alpha : t => float = "" [@@bs.get];
    /*
     The opacity of the object.
     */
    external setAlpha : t => float => unit = "alpha" [@@bs.set];
    /*
     The visibility of the object. If false the object will not be drawn, and
     the updateTransform function will not be called.

     Only affects recursive calls from parent. You can ask for bounds or call updateTransform manually
     */
    external visible : t => Js.boolean = "" [@@bs.get];
    /*
     The visibility of the object. If false the object will not be drawn, and
     the updateTransform function will not be called.

     Only affects recursive calls from parent. You can ask for bounds or call updateTransform manually
     */
    external setVisible : t => Js.boolean => unit = "visible" [@@bs.set];
    /*
     Can this object be rendered, if false the object will not be drawn but the updateTransform
     methods will still be called.

     Only affects recursive calls from parent. You can ask for bounds manually
     */
    external renderable : t => Js.boolean = "" [@@bs.get];
    /*
     Can this object be rendered, if false the object will not be drawn but the updateTransform
     methods will still be called.

     Only affects recursive calls from parent. You can ask for bounds manually
     */
    external setRenderable : t => Js.boolean => unit = "renderable" [@@bs.set];
    /*
     The display object container that contains this display object.
     */
    external parent : t => Container.t = "" [@@bs.get];
    /*
     The multiplied alpha of the displayObject
     */
    external worldAlpha : t => float = "" [@@bs.get];
    /*
     The area the filter is applied to. This is used as more of an optimisation
     rather than figuring out the dimensions of the displayObject each frame you can set this rectangle

     Also works as an interaction mask
     */
    external filterArea : t => Rectangle.t = "" [@@bs.get];
    /*
     The area the filter is applied to. This is used as more of an optimisation
     rather than figuring out the dimensions of the displayObject each frame you can set this rectangle

     Also works as an interaction mask
     */
    external setFilterArea : t => Rectangle.t => unit = "filterArea" [@@bs.set];
    /*
     The position of the displayObject on the x axis relative to the local coordinates of the parent.
     An alias to position.x
     */
    external x : t => float = "" [@@bs.get];
    /*
     The position of the displayObject on the x axis relative to the local coordinates of the parent.
     An alias to position.x
     */
    external setX : t => float => unit = "x" [@@bs.set];
    /*
     The position of the displayObject on the y axis relative to the local coordinates of the parent.
     An alias to position.y
     */
    external y : t => float = "" [@@bs.get];
    /*
     The position of the displayObject on the y axis relative to the local coordinates of the parent.
     An alias to position.y
     */
    external setY : t => float => unit = "y" [@@bs.set];
    /*
     Current transform of the object based on world (parent) factors
     */
    external worldTransform : t => Matrix.t = "" [@@bs.get];
    /*
     Current transform of the object based on local factors: position, scale, other stuff
     */
    external localTransform : t => Matrix.t = "" [@@bs.get];
    /*
     The coordinate of the object relative to the local coordinates of the parent.
     Assignment by value since pixi-v4.
     */
    external position : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
      "" [@@bs.get];
    /*
     The coordinate of the object relative to the local coordinates of the parent.
     Assignment by value since pixi-v4.
     */
    external setPosition : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
      "position" [@@bs.set];
    /*
     The scale factor of the object.
     Assignment by value since pixi-v4.
     */
    external scale : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
      "" [@@bs.get];
    /*
     The scale factor of the object.
     Assignment by value since pixi-v4.
     */
    external setScale : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
      "scale" [@@bs.set];
    /*
     The pivot point of the displayObject that it rotates around
     Assignment by value since pixi-v4.
     */
    external pivot : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
      "" [@@bs.get];
    /*
     The pivot point of the displayObject that it rotates around
     Assignment by value since pixi-v4.
     */
    external setPivot : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
      "pivot" [@@bs.set];
    /*
     The skew factor for the object in radians.
     Assignment by value since pixi-v4.
     */
    external skew : t => ObservablePoint.t = "" [@@bs.get];
    /*
     The skew factor for the object in radians.
     Assignment by value since pixi-v4.
     */
    external setSkew : t => ObservablePoint.t => unit = "skew" [@@bs.set];
    /*
     The rotation of the object in radians.
     */
    external rotation : t => float = "" [@@bs.get];
    /*
     The rotation of the object in radians.
     */
    external setRotation : t => float => unit = "rotation" [@@bs.set];
    /*
     Indicates if the object is globally visible.
     */
    external worldVisible : t => Js.boolean = "" [@@bs.get];
    /*
     Sets a mask for the displayObject. A mask is an object that limits the visibility of an
     object to the shape of the mask applied to it. In PIXI a regular mask must be a
     PIXI.Graphics or a PIXI.Sprite object. This allows for much faster masking in canvas as it
     utilises shape clipping. To remove a mask, set this property to null.
     */
    external mask : t => unit /* unknown js type: PIXI.Graphics|PIXI.Sprite */ = "" [@@bs.get];
    /*
     Sets a mask for the displayObject. A mask is an object that limits the visibility of an
     object to the shape of the mask applied to it. In PIXI a regular mask must be a
     PIXI.Graphics or a PIXI.Sprite object. This allows for much faster masking in canvas as it
     utilises shape clipping. To remove a mask, set this property to null.
     */
    external setMask : t => unit /* unknown js type: PIXI.Graphics|PIXI.Sprite */ => unit =
      "mask" [@@bs.set];
    /*
     Sets the filters for the displayObject.

     <ul>
     <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
     To remove filters simply set this property to 'null'</li>
     </ul>
     */
    external filters : t => array Filter.t = "" [@@bs.get];
    /*
     Sets the filters for the displayObject.

     <ul>
     <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
     To remove filters simply set this property to 'null'</li>
     </ul>
     */
    external setFilters : t => array Filter.t => unit = "filters" [@@bs.set];
    /*
     Set this to true if you want this display object to be cached as a bitmap.
     This basically takes a snap shot of the display object as it is at that moment. It can
     provide a performance benefit for complex static displayObjects.
     To remove simply set this property to 'false'

     IMPORTANT GOTCHA - make sure that all your textures are preloaded BEFORE setting this property to true
     as it will take a snapshot of what is currently there. If the textures have not loaded then they will not appear.
     */
    external cacheAsBitmap : t => Js.boolean = "" [@@bs.get];
    /*
     Set this to true if you want this display object to be cached as a bitmap.
     This basically takes a snap shot of the display object as it is at that moment. It can
     provide a performance benefit for complex static displayObjects.
     To remove simply set this property to 'false'

     IMPORTANT GOTCHA - make sure that all your textures are preloaded BEFORE setting this property to true
     as it will take a snapshot of what is currently there. If the textures have not loaded then they will not appear.
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
     Interaction shape. Children will be hit first, then this shape will be checked.
     Setting this will cause this shape to be checked in hit tests rather than the displayObject's bounds.
     */
    external hitArea :
      t => unit /* unknown js type: PIXI.Rectangle|PIXI.Circle|PIXI.Ellipse|PIXI.Polygon|PIXI.RoundedRectangle */ =
      "" [@@bs.get];
    /*
     Interaction shape. Children will be hit first, then this shape will be checked.
     Setting this will cause this shape to be checked in hit tests rather than the displayObject's bounds.
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
     This defines what cursor mode is used when the mouse cursor
     is hovered over the displayObject.
     */
    external cursor : t => string = "" [@@bs.get];
    /*
     This defines what cursor mode is used when the mouse cursor
     is hovered over the displayObject.
     */
    external setCursor : t => string => unit = "cursor" [@@bs.set];
  };
};

/*
 WebGL renderer plugin for tiling sprites
 */
module MeshRenderer = {
  /*
   WebGL renderer plugin for tiling sprites
   */
  type t;
  /*
   The renderer this manager works for.
   */
  external renderer : t => WebGLRenderer.t = "" [@@bs.get];
  /*
   The renderer this manager works for.
   */
  external setRenderer : t => WebGLRenderer.t => unit = "renderer" [@@bs.set];
};

module Particles = {
  /*
   The ParticleContainer class is a really fast version of the Container built solely for speed,
   so use when you need a lot of sprites or particles. The tradeoff of the ParticleContainer is that advanced
   functionality will not work. ParticleContainer implements only the basic object transform (position, scale, rotation).
   Any other functionality like tinting, masking, etc will not work on sprites in this batch.

   It's extremely easy to use :

   <pre class="prettyprint source lang-js"><code>let container = new ParticleContainer();

   for (let i = 0; i &lt; 100; ++i)
   {
       let sprite = new PIXI.Sprite.fromImage(&quot;myImage.png&quot;);
       container.addChild(sprite);
   }</code></pre>And here you have a hundred sprites that will be renderer at the speed of light.
   */
  module ParticleContainer = {
    /*
     The ParticleContainer class is a really fast version of the Container built solely for speed,
     so use when you need a lot of sprites or particles. The tradeoff of the ParticleContainer is that advanced
     functionality will not work. ParticleContainer implements only the basic object transform (position, scale, rotation).
     Any other functionality like tinting, masking, etc will not work on sprites in this batch.

     It's extremely easy to use :

     <pre class="prettyprint source lang-js"><code>let container = new ParticleContainer();

     for (let i = 0; i &lt; 100; ++i)
     {
         let sprite = new PIXI.Sprite.fromImage(&quot;myImage.png&quot;);
         container.addChild(sprite);
     }</code></pre>And here you have a hundred sprites that will be renderer at the speed of light.
     */
    type t;
    external interactiveChildren : t => Js.boolean = "" [@@bs.get];
    external setInteractiveChildren : t => Js.boolean => unit = "interactiveChildren" [@@bs.set];
    /*
     <p>The blend mode to be applied to the sprite. Apply a value of <code>PIXI.BLEND_MODES.NORMAL</code>
     to reset the blend mode.</p>
     */
    external blendMode : t => float = "" [@@bs.get];
    /*
     <p>The blend mode to be applied to the sprite. Apply a value of <code>PIXI.BLEND_MODES.NORMAL</code>
     to reset the blend mode.</p>
     */
    external setBlendMode : t => float => unit = "blendMode" [@@bs.set];
    /*
     Used for canvas renderering. If true then the elements will be positioned at the
     nearest pixel. This provides a nice speed boost.
     */
    external roundPixels : t => Js.boolean = "" [@@bs.get];
    /*
     Used for canvas renderering. If true then the elements will be positioned at the
     nearest pixel. This provides a nice speed boost.
     */
    external setRoundPixels : t => Js.boolean => unit = "roundPixels" [@@bs.set];
    /*
     The texture used to render the children.
     */
    external baseTexture : t => BaseTexture.t = "" [@@bs.get];
    /*
     The tint applied to the container. This is a hex value.
     A value of 0xFFFFFF will remove any tint effect.

     <ul>
     <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.</li>
     </ul>
     */
    external tint : t => float = "" [@@bs.get];
    /*
     The tint applied to the container. This is a hex value.
     A value of 0xFFFFFF will remove any tint effect.

     <ul>
     <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.</li>
     </ul>
     */
    external setTint : t => float => unit = "tint" [@@bs.set];
    /*
     The array of children of this container.
     */
    external children : t => array DisplayObject.t = "" [@@bs.get];
    /*
     The width of the Container, setting this will actually modify the scale to achieve the value set
     */
    external width : t => float = "" [@@bs.get];
    /*
     The width of the Container, setting this will actually modify the scale to achieve the value set
     */
    external setWidth : t => float => unit = "width" [@@bs.set];
    /*
     The height of the Container, setting this will actually modify the scale to achieve the value set
     */
    external height : t => float = "" [@@bs.get];
    /*
     The height of the Container, setting this will actually modify the scale to achieve the value set
     */
    external setHeight : t => float => unit = "height" [@@bs.set];
    /*
     World transform and local transform of this object.
     This will become read-only later, please do not assign anything there unless you know what are you doing
     */
    external transform : t => TransformBase.t = "" [@@bs.get];
    /*
     World transform and local transform of this object.
     This will become read-only later, please do not assign anything there unless you know what are you doing
     */
    external setTransform : t => TransformBase.t => unit = "transform" [@@bs.set];
    /*
     The opacity of the object.
     */
    external alpha : t => float = "" [@@bs.get];
    /*
     The opacity of the object.
     */
    external setAlpha : t => float => unit = "alpha" [@@bs.set];
    /*
     The visibility of the object. If false the object will not be drawn, and
     the updateTransform function will not be called.

     Only affects recursive calls from parent. You can ask for bounds or call updateTransform manually
     */
    external visible : t => Js.boolean = "" [@@bs.get];
    /*
     The visibility of the object. If false the object will not be drawn, and
     the updateTransform function will not be called.

     Only affects recursive calls from parent. You can ask for bounds or call updateTransform manually
     */
    external setVisible : t => Js.boolean => unit = "visible" [@@bs.set];
    /*
     Can this object be rendered, if false the object will not be drawn but the updateTransform
     methods will still be called.

     Only affects recursive calls from parent. You can ask for bounds manually
     */
    external renderable : t => Js.boolean = "" [@@bs.get];
    /*
     Can this object be rendered, if false the object will not be drawn but the updateTransform
     methods will still be called.

     Only affects recursive calls from parent. You can ask for bounds manually
     */
    external setRenderable : t => Js.boolean => unit = "renderable" [@@bs.set];
    /*
     The display object container that contains this display object.
     */
    external parent : t => Container.t = "" [@@bs.get];
    /*
     The multiplied alpha of the displayObject
     */
    external worldAlpha : t => float = "" [@@bs.get];
    /*
     The area the filter is applied to. This is used as more of an optimisation
     rather than figuring out the dimensions of the displayObject each frame you can set this rectangle

     Also works as an interaction mask
     */
    external filterArea : t => Rectangle.t = "" [@@bs.get];
    /*
     The area the filter is applied to. This is used as more of an optimisation
     rather than figuring out the dimensions of the displayObject each frame you can set this rectangle

     Also works as an interaction mask
     */
    external setFilterArea : t => Rectangle.t => unit = "filterArea" [@@bs.set];
    /*
     The position of the displayObject on the x axis relative to the local coordinates of the parent.
     An alias to position.x
     */
    external x : t => float = "" [@@bs.get];
    /*
     The position of the displayObject on the x axis relative to the local coordinates of the parent.
     An alias to position.x
     */
    external setX : t => float => unit = "x" [@@bs.set];
    /*
     The position of the displayObject on the y axis relative to the local coordinates of the parent.
     An alias to position.y
     */
    external y : t => float = "" [@@bs.get];
    /*
     The position of the displayObject on the y axis relative to the local coordinates of the parent.
     An alias to position.y
     */
    external setY : t => float => unit = "y" [@@bs.set];
    /*
     Current transform of the object based on world (parent) factors
     */
    external worldTransform : t => Matrix.t = "" [@@bs.get];
    /*
     Current transform of the object based on local factors: position, scale, other stuff
     */
    external localTransform : t => Matrix.t = "" [@@bs.get];
    /*
     The coordinate of the object relative to the local coordinates of the parent.
     Assignment by value since pixi-v4.
     */
    external position : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
      "" [@@bs.get];
    /*
     The coordinate of the object relative to the local coordinates of the parent.
     Assignment by value since pixi-v4.
     */
    external setPosition : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
      "position" [@@bs.set];
    /*
     The scale factor of the object.
     Assignment by value since pixi-v4.
     */
    external scale : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
      "" [@@bs.get];
    /*
     The scale factor of the object.
     Assignment by value since pixi-v4.
     */
    external setScale : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
      "scale" [@@bs.set];
    /*
     The pivot point of the displayObject that it rotates around
     Assignment by value since pixi-v4.
     */
    external pivot : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ =
      "" [@@bs.get];
    /*
     The pivot point of the displayObject that it rotates around
     Assignment by value since pixi-v4.
     */
    external setPivot : t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
      "pivot" [@@bs.set];
    /*
     The skew factor for the object in radians.
     Assignment by value since pixi-v4.
     */
    external skew : t => ObservablePoint.t = "" [@@bs.get];
    /*
     The skew factor for the object in radians.
     Assignment by value since pixi-v4.
     */
    external setSkew : t => ObservablePoint.t => unit = "skew" [@@bs.set];
    /*
     The rotation of the object in radians.
     */
    external rotation : t => float = "" [@@bs.get];
    /*
     The rotation of the object in radians.
     */
    external setRotation : t => float => unit = "rotation" [@@bs.set];
    /*
     Indicates if the object is globally visible.
     */
    external worldVisible : t => Js.boolean = "" [@@bs.get];
    /*
     Sets a mask for the displayObject. A mask is an object that limits the visibility of an
     object to the shape of the mask applied to it. In PIXI a regular mask must be a
     PIXI.Graphics or a PIXI.Sprite object. This allows for much faster masking in canvas as it
     utilises shape clipping. To remove a mask, set this property to null.
     */
    external mask : t => unit /* unknown js type: PIXI.Graphics|PIXI.Sprite */ = "" [@@bs.get];
    /*
     Sets a mask for the displayObject. A mask is an object that limits the visibility of an
     object to the shape of the mask applied to it. In PIXI a regular mask must be a
     PIXI.Graphics or a PIXI.Sprite object. This allows for much faster masking in canvas as it
     utilises shape clipping. To remove a mask, set this property to null.
     */
    external setMask : t => unit /* unknown js type: PIXI.Graphics|PIXI.Sprite */ => unit =
      "mask" [@@bs.set];
    /*
     Sets the filters for the displayObject.

     <ul>
     <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
     To remove filters simply set this property to 'null'</li>
     </ul>
     */
    external filters : t => array Filter.t = "" [@@bs.get];
    /*
     Sets the filters for the displayObject.

     <ul>
     <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
     To remove filters simply set this property to 'null'</li>
     </ul>
     */
    external setFilters : t => array Filter.t => unit = "filters" [@@bs.set];
    /*
     Set this to true if you want this display object to be cached as a bitmap.
     This basically takes a snap shot of the display object as it is at that moment. It can
     provide a performance benefit for complex static displayObjects.
     To remove simply set this property to 'false'

     IMPORTANT GOTCHA - make sure that all your textures are preloaded BEFORE setting this property to true
     as it will take a snapshot of what is currently there. If the textures have not loaded then they will not appear.
     */
    external cacheAsBitmap : t => Js.boolean = "" [@@bs.get];
    /*
     Set this to true if you want this display object to be cached as a bitmap.
     This basically takes a snap shot of the display object as it is at that moment. It can
     provide a performance benefit for complex static displayObjects.
     To remove simply set this property to 'false'

     IMPORTANT GOTCHA - make sure that all your textures are preloaded BEFORE setting this property to true
     as it will take a snapshot of what is currently there. If the textures have not loaded then they will not appear.
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
     Interaction shape. Children will be hit first, then this shape will be checked.
     Setting this will cause this shape to be checked in hit tests rather than the displayObject's bounds.
     */
    external hitArea :
      t => unit /* unknown js type: PIXI.Rectangle|PIXI.Circle|PIXI.Ellipse|PIXI.Polygon|PIXI.RoundedRectangle */ =
      "" [@@bs.get];
    /*
     Interaction shape. Children will be hit first, then this shape will be checked.
     Setting this will cause this shape to be checked in hit tests rather than the displayObject's bounds.
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
     This defines what cursor mode is used when the mouse cursor
     is hovered over the displayObject.
     */
    external cursor : t => string = "" [@@bs.get];
    /*
     This defines what cursor mode is used when the mouse cursor
     is hovered over the displayObject.
     */
    external setCursor : t => string => unit = "cursor" [@@bs.set];
  };
};

module ParticleShader = {
  type t;
};

module Prepare = {
  /*
   The prepare manager provides functionality to upload content to the GPU. BasePrepare handles
   basic queuing functionality and is extended by {@link PIXI.prepare.WebGLPrepare} and {@link PIXI.prepare.CanvasPrepare}
   to provide preparation capabilities specific to their respective renderers.
   */
  module BasePrepare = {
    /*
     The prepare manager provides functionality to upload content to the GPU. BasePrepare handles
     basic queuing functionality and is extended by {@link PIXI.prepare.WebGLPrepare} and {@link PIXI.prepare.CanvasPrepare}
     to provide preparation capabilities specific to their respective renderers.
     */
    type t;
    /*
     The limiter to be used to control how quickly items are prepared.
     */
    external limiter :
      t => unit /* unknown js type: PIXI.prepare.CountLimiter|PIXI.prepare.TimeLimiter */ =
      "" [@@bs.get];
    /*
     The limiter to be used to control how quickly items are prepared.
     */
    external setLimiter :
      t => unit /* unknown js type: PIXI.prepare.CountLimiter|PIXI.prepare.TimeLimiter */ => unit =
      "limiter" [@@bs.set];
    /*
     Reference to the renderer.
     */
    external renderer : t => SystemRenderer.t = "" [@@bs.get];
    /*
     Reference to the renderer.
     */
    external setRenderer : t => SystemRenderer.t => unit = "renderer" [@@bs.set];
    /*
     The only real difference between CanvasPrepare and WebGLPrepare is what they pass
     to upload hooks. That different parameter is stored here.
     */
    external uploadHookHelper :
      t => unit /* unknown js type: PIXI.prepare.CanvasPrepare|PIXI.WebGLRenderer */ =
      "" [@@bs.get];
    /*
     The only real difference between CanvasPrepare and WebGLPrepare is what they pass
     to upload hooks. That different parameter is stored here.
     */
    external setUploadHookHelper :
      t => unit /* unknown js type: PIXI.prepare.CanvasPrepare|PIXI.WebGLRenderer */ => unit =
      "uploadHookHelper" [@@bs.set];
  };
  /*
   The prepare manager provides functionality to upload content to the GPU
   This cannot be done directly for Canvas like in WebGL, but the effect can be achieved by drawing
   textures to an offline canvas.
   This draw call will force the texture to be moved onto the GPU.

   An instance of this class is automatically created by default, and can be found at renderer.plugins.prepare
   */
  module CanvasPrepare = {
    /*
     The prepare manager provides functionality to upload content to the GPU
     This cannot be done directly for Canvas like in WebGL, but the effect can be achieved by drawing
     textures to an offline canvas.
     This draw call will force the texture to be moved onto the GPU.

     An instance of this class is automatically created by default, and can be found at renderer.plugins.prepare
     */
    type t;
  };
  /*
   The prepare manager provides functionality to upload content to the GPU.

   An instance of this class is automatically created by default, and can be found at renderer.plugins.prepare
   */
  module WebGLPrepare = {
    /*
     The prepare manager provides functionality to upload content to the GPU.

     An instance of this class is automatically created by default, and can be found at renderer.plugins.prepare
     */
    type t;
  };
};

/*
 CountLimiter limits the number of items handled by a {@link PIXI.prepare.BasePrepare} to a specified
 number of items per frame.
 */
module CountLimiter = {
  /*
   CountLimiter limits the number of items handled by a {@link PIXI.prepare.BasePrepare} to a specified
   number of items per frame.
   */
  type t;
};

/*
 TimeLimiter limits the number of items handled by a {@link PIXI.BasePrepare} to a specified
 number of milliseconds per frame.
 */
module TimeLimiter = {
  /*
   TimeLimiter limits the number of items handled by a {@link PIXI.BasePrepare} to a specified
   number of milliseconds per frame.
   */
  type t;
};
