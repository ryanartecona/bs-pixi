module type TYPES = {
  type accessibilityManager;
  type application;
  type shader;
  type bounds;
  type container;
  type displayObject;
  type transform;
  type transformBase;
  type transformStatic;
  type graphics;
  type graphicsData;
  type graphicsRenderer;
  type primitiveShader;
  type groupD8;
  type matrix;
  type observablePoint;
  type point;
  type circle;
  type ellipse;
  type polygon;
  type rectangle;
  type roundedRectangle;
  type systemRenderer;
  type canvasRenderer;
  type canvasMaskManager;
  type canvasRenderTarget;
  type textureGarbageCollector;
  type textureManager;
  type webGLRenderer;
  type webGLState;
  type filter;
  type spriteMaskFilter;
  type blendModeManager;
  type filterManager;
  type maskManager;
  type stencilManager;
  type webGLManager;
  type objectRenderer;
  type quad;
  type renderTarget;
  type sprite;
  type canvasTinter;
  type buffer;
  type text;
  type textMetrics;
  type fontMetrics;
  type textStyle;
  type baseRenderTexture;
  type baseTexture;
  type renderTexture;
  type spritesheet;
  type texture;
  type videoBaseTexture;
  type ticker;
  type eventEmitter;
  type canvasExtract;
  type webGLExtract;
  type animatedSprite;
  type bitmapText;
  type textureTransform;
  type tilingSprite;
  type tilingSpriteRenderer;
  type blurFilter;
  type blurXFilter;
  type blurYFilter;
  type colorMatrixFilter;
  type displacementFilter;
  type fxaaFilter;
  type noiseFilter;
  type voidFilter;
  type interactionData;
  type interactionEvent;
  type interactionManager;
  type resource;
  type loader;
  type mesh;
  type nineSlicePlane;
  type plane;
  type rope;
  type meshRenderer;
  type particleContainer;
  type particleShader;
  type basePrepare;
  type canvasPrepare;
  type countLimiter;
  type timeLimiter;
  type webGLPrepare;
};

module Impl (T: TYPES) => {
  module Accessibility = {
    module AccessibilityManager = {
      /*
       The Accessibility manager recreates the ability to tab and have content read by screen
       readers. This is very important as it can possibly help people with disabilities access pixi
       content.

       Much like interaction any DisplayObject can be made accessible. This manager will map the
       events as if the mouse was being used, minimizing the effort required to implement.

       An instance of this class is automatically created by default, and can be found at renderer.plugins.accessibility
       */
      type t = T.accessibilityManager;
      external create :
        renderer::unit /* unknown js type: PIXI.CanvasRenderer|PIXI.WebGLRenderer */ => unit => t =
        "AccessibilityManager"
        [@@bs.new] [@@bs.scope "accessibility"] [@@bs.module ("pixi.js", "PIXI")];
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
      external renderer : t => T.systemRenderer = "" [@@bs.get];
      /*
       The renderer this accessibility manager works for.
       */
      external setRenderer : t => T.systemRenderer => unit = "renderer" [@@bs.set];
      /*
       Creates the touch hooks.
       */
      external createTouchHook : unit = "" [@@bs.send.pipe : t];
      /*
       TODO: docs.
       */
      external capHitArea : hitArea::T.rectangle => unit = "" [@@bs.send.pipe : t];
      /*
       Destroys the accessibility manager
       */
      external destroy : unit = "" [@@bs.send.pipe : t];
    };
  };
  module Application = {
    /*
     Convenience class to create a new PIXI application.
     This class automatically creates the renderer, ticker
     and root container.
     */
    type t = T.application;
    type createOptions;
    /*
     The optional renderer parameters
     */
    external mkCreateOptions :
      width::float? =>
      height::float? =>
      view::Dom.element? =>
      transparent::Js.boolean? =>
      antialias::Js.boolean? =>
      preserveDrawingBuffer::Js.boolean? =>
      resolution::float? =>
      forceCanvas::Js.boolean? =>
      backgroundColor::float? =>
      clearBeforeRender::Js.boolean? =>
      roundPixels::Js.boolean? =>
      forceFXAA::Js.boolean? =>
      legacy::Js.boolean? =>
      sharedTicker::Js.boolean? =>
      sharedLoader::Js.boolean? =>
      unit =>
      createOptions =
      "" [@@bs.obj];
    external create : options::createOptions? => unit => t =
      "Application" [@@bs.new] [@@bs.module ("pixi.js", "PIXI")];
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
    external stage : t => T.container = "" [@@bs.get];
    /*
     The root display container that's rendered.
     */
    external setStage : t => T.container => unit = "stage" [@@bs.set];
    /*
     Ticker for doing render updates.
     */
    external ticker : t => T.ticker = "" [@@bs.get];
    /*
     Ticker for doing render updates.
     */
    external setTicker : t => T.ticker => unit = "ticker" [@@bs.set];
    /*
     Reference to the renderer's canvas element.
     */
    external view : t => Dom.element = "" [@@bs.get];
    /*
     Reference to the renderer's screen rectangle. Its safe to use as filterArea or hitArea for whole screen
     */
    external screen : t => T.rectangle = "" [@@bs.get];
    /*
     Loader instance to help with asset loading.
     */
    external loader : t => T.loader = "" [@@bs.get];
    /*
     Loader instance to help with asset loading.
     */
    external setLoader : t => T.loader => unit = "loader" [@@bs.set];
    /*
     Render the current stage.
     */
    external render : unit = "" [@@bs.send.pipe : t];
    /*
     Convenience method for stopping the render.
     */
    external stop : unit = "" [@@bs.send.pipe : t];
    /*
     Convenience method for starting the render.
     */
    external start : unit = "" [@@bs.send.pipe : t];
    /*
     Destroy and don't use after this.
     */
    external destroy : removeView::unit /* unknown js type: Boolean */? => unit =
      "" [@@bs.send.pipe : t];
  };
  module Shader = {
    /*
     Wrapper class, webGL Shader for Pixi.
     Adds precision string if vertexSrc or fragmentSrc have no mention of it.
     */
    type t = T.shader;
    external create :
      gl::ReasonJs.Gl.glT => vertexSrc::array string => fragmentSrc::array string => unit => t =
      "Shader" [@@bs.new] [@@bs.module ("pixi.js", "PIXI")];
  };
  module Bounds = {
    /*
     'Builder' pattern for bounds rectangles
     Axis-Aligned Bounding Box
     It is not a shape! Its mutable thing, no 'EMPTY' or that kind of problems
     */
    type t = T.bounds;
    external create : unit => t = "Bounds" [@@bs.new] [@@bs.module ("pixi.js", "PIXI")];
    external minX : t => float = "" [@@bs.get];
    external setMinX : t => float => unit = "minX" [@@bs.set];
    external minY : t => float = "" [@@bs.get];
    external setMinY : t => float => unit = "minY" [@@bs.set];
    external maxX : t => float = "" [@@bs.get];
    external setMaxX : t => float => unit = "maxX" [@@bs.set];
    external maxY : t => float = "" [@@bs.get];
    external setMaxY : t => float => unit = "maxY" [@@bs.set];
    /*
     Checks if bounds are empty.
     */
    external isEmpty : Js.boolean = "" [@@bs.send.pipe : t];
    /*
     Clears the bounds and resets.
     */
    external clear : unit = "" [@@bs.send.pipe : t];
    /*
     Can return Rectangle.EMPTY constant, either construct new rectangle, either use your rectangle
     It is not guaranteed that it will return tempRect
     */
    external getRectangle : rect::T.rectangle => T.rectangle = "" [@@bs.send.pipe : t];
    /*
     This function should be inlined when its possible.
     */
    external addPoint : point::T.point => unit = "" [@@bs.send.pipe : t];
    /*
     Adds a quad, not transformed
     */
    external addQuad : vertices::Js_typed_array.Float32Array.t => unit = "" [@@bs.send.pipe : t];
    /*
     Adds sprite frame, transformed.
     */
    external addFrame :
      transform::T.transformBase => x0::float => y0::float => x1::float => y1::float => unit =
      "" [@@bs.send.pipe : t];
    /*
     Add an array of vertices
     */
    external addVertices :
      transform::T.transformBase =>
      vertices::Js_typed_array.Float32Array.t =>
      beginOffset::float =>
      endOffset::float =>
      unit =
      "" [@@bs.send.pipe : t];
    /*
     Adds other Bounds
     */
    external addBounds : bounds::T.bounds => unit = "" [@@bs.send.pipe : t];
    /*
     Adds other Bounds, masked with Bounds
     */
    external addBoundsMask : bounds::T.bounds => mask::T.bounds => unit = "" [@@bs.send.pipe : t];
    /*
     Adds other Bounds, masked with Rectangle
     */
    external addBoundsArea : bounds::T.bounds => area::T.rectangle => unit =
      "" [@@bs.send.pipe : t];
  };
  module Container = {
    /*
     A Container represents a collection of display objects.
     It is the base class of all display objects that act as a container for other objects.

     <pre class="prettyprint source lang-js"><code>let container = new PIXI.Container();
     container.addChild(sprite);</code></pre>
     */
    type t = T.container;
    external create : unit => t = "Container" [@@bs.new] [@@bs.module ("pixi.js", "PIXI")];
    /*
     The array of children of this container.
     */
    external children : t => array T.displayObject = "" [@@bs.get];
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
    external transform : t => T.transformBase = "" [@@bs.get];
    /*
     World transform and local transform of this object.
     This will become read-only later, please do not assign anything there unless you know what are you doing
     */
    external setTransform : t => T.transformBase => unit = "transform" [@@bs.set];
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
    external parent : t => T.container = "" [@@bs.get];
    /*
     The multiplied alpha of the displayObject
     */
    external worldAlpha : t => float = "" [@@bs.get];
    /*
     The area the filter is applied to. This is used as more of an optimisation
     rather than figuring out the dimensions of the displayObject each frame you can set this rectangle

     Also works as an interaction mask
     */
    external filterArea : t => T.rectangle = "" [@@bs.get];
    /*
     The area the filter is applied to. This is used as more of an optimisation
     rather than figuring out the dimensions of the displayObject each frame you can set this rectangle

     Also works as an interaction mask
     */
    external setFilterArea : t => T.rectangle => unit = "filterArea" [@@bs.set];
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
    external worldTransform : t => T.matrix = "" [@@bs.get];
    /*
     Current transform of the object based on local factors: position, scale, other stuff
     */
    external localTransform : t => T.matrix = "" [@@bs.get];
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
    external skew : t => T.observablePoint = "" [@@bs.get];
    /*
     The skew factor for the object in radians.
     Assignment by value since pixi-v4.
     */
    external setSkew : t => T.observablePoint => unit = "skew" [@@bs.set];
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
    external filters : t => array T.filter = "" [@@bs.get];
    /*
     Sets the filters for the displayObject.

     <ul>
     <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
     To remove filters simply set this property to 'null'</li>
     </ul>
     */
    external setFilters : t => array T.filter => unit = "filters" [@@bs.set];
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
    /*
     Adds one or more children to the container.

     <p>Multiple items can be added like so: <code>myContainer.addChild(thingOne, thingTwo, thingThree)</code></p>
     */
    external addChild : child::T.displayObject => T.displayObject = "" [@@bs.send.pipe : t];
    /*
     Adds a child to the container at a specified index. If the index is out of bounds an error will be thrown
     */
    external addChildAt : child::T.displayObject => index::float => T.displayObject =
      "" [@@bs.send.pipe : t];
    /*
     Swaps the position of 2 Display Objects within this container.
     */
    external swapChildren : child::T.displayObject => child2::T.displayObject => unit =
      "" [@@bs.send.pipe : t];
    /*
     Returns the index position of a child DisplayObject instance
     */
    external getChildIndex : child::T.displayObject => float = "" [@@bs.send.pipe : t];
    /*
     Changes the position of an existing child in the display object container
     */
    external setChildIndex : child::T.displayObject => index::float => unit =
      "" [@@bs.send.pipe : t];
    /*
     Returns the child at the specified index
     */
    external getChildAt : index::float => T.displayObject = "" [@@bs.send.pipe : t];
    /*
     Removes one or more children from the container.
     */
    external removeChild : child::T.displayObject => T.displayObject = "" [@@bs.send.pipe : t];
    /*
     Removes a child from the specified index position.
     */
    external removeChildAt : index::float => T.displayObject = "" [@@bs.send.pipe : t];
    /*
     Removes all children from this container that are within the begin and end indexes.
     */
    external removeChildren : beginIndex::float? => endIndex::float? => array T.displayObject =
      "" [@@bs.send.pipe : t];
    /*
     Updates the transform on all children of this container for rendering
     */
    external updateTransform : unit = "" [@@bs.send.pipe : t];
    /*
     Recalculates the bounds of the container.
     */
    external calculateBounds : unit = "" [@@bs.send.pipe : t];
    /*
     Recalculates the bounds of the object. Override this to
     calculate the bounds of the specific object (not including children).
     */
    external _calculateBounds : unit = "" [@@bs.send.pipe : t];
    /*
     Renders the object using the WebGL renderer
     */
    external renderWebGL : renderer::T.webGLRenderer => unit = "" [@@bs.send.pipe : t];
    /*
     Renders the object using the Canvas renderer
     */
    external renderCanvas : renderer::T.canvasRenderer => unit = "" [@@bs.send.pipe : t];
    /*
     <p>Removes all internal references and listeners as well as removes children from the display list.
     Do not use a Container after calling <code>destroy</code>.</p>
     */
    external destroy : options::unit /* unknown js type: object|boolean */? => unit =
      "" [@@bs.send.pipe : t];
    /*
     Returns the display object in the container
     */
    external getChildByName : name::string => T.displayObject = "" [@@bs.send.pipe : t];
    /*
     recursively updates transform of all objects from the root to this one
     internal function for toLocal()
     */
    external _recursivePostUpdateTransform : unit = "" [@@bs.send.pipe : t];
    /*
     Retrieves the bounds of the displayObject as a rectangle object.
     */
    external getBounds : skipUpdate::Js.boolean => rect::T.rectangle => T.rectangle =
      "" [@@bs.send.pipe : t];
    /*
     Retrieves the local bounds of the displayObject as a rectangle object
     */
    external getLocalBounds : rect::T.rectangle? => T.rectangle = "" [@@bs.send.pipe : t];
    /*
     Calculates the global position of the display object
     */
    external toGlobal : position::T.point => point::T.point? => skipUpdate::Js.boolean? => T.point =
      "" [@@bs.send.pipe : t];
    /*
     Calculates the local position of the display object relative to another point
     */
    external toLocal :
      position::T.point =>
      from::T.displayObject? =>
      point::T.point? =>
      skipUpdate::Js.boolean? =>
      T.point =
      "" [@@bs.send.pipe : t];
    /*
     Set the parent Container of this DisplayObject
     */
    external setParent : container::T.container => T.container = "" [@@bs.send.pipe : t];
    /*
     Convenience function to set the position, scale, skew and pivot at once.
     */
    external setTransform :
      x::float? =>
      y::float? =>
      scaleX::float? =>
      scaleY::float? =>
      rotation::float? =>
      skewX::float? =>
      skewY::float? =>
      pivotX::float? =>
      pivotY::float? =>
      T.displayObject =
      "" [@@bs.send.pipe : t];
  };
  module DisplayObject = {
    /*
     The base class for all objects that are rendered on the screen.
     This is an abstract class and should not be used on its own rather it should be extended.
     */
    type t = T.displayObject;
    external create : unit => t = "DisplayObject" [@@bs.new] [@@bs.module ("pixi.js", "PIXI")];
    /*
     World transform and local transform of this object.
     This will become read-only later, please do not assign anything there unless you know what are you doing
     */
    external transform : t => T.transformBase = "" [@@bs.get];
    /*
     World transform and local transform of this object.
     This will become read-only later, please do not assign anything there unless you know what are you doing
     */
    external setTransform : t => T.transformBase => unit = "transform" [@@bs.set];
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
    external parent : t => T.container = "" [@@bs.get];
    /*
     The multiplied alpha of the displayObject
     */
    external worldAlpha : t => float = "" [@@bs.get];
    /*
     The area the filter is applied to. This is used as more of an optimisation
     rather than figuring out the dimensions of the displayObject each frame you can set this rectangle

     Also works as an interaction mask
     */
    external filterArea : t => T.rectangle = "" [@@bs.get];
    /*
     The area the filter is applied to. This is used as more of an optimisation
     rather than figuring out the dimensions of the displayObject each frame you can set this rectangle

     Also works as an interaction mask
     */
    external setFilterArea : t => T.rectangle => unit = "filterArea" [@@bs.set];
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
    external worldTransform : t => T.matrix = "" [@@bs.get];
    /*
     Current transform of the object based on local factors: position, scale, other stuff
     */
    external localTransform : t => T.matrix = "" [@@bs.get];
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
    external skew : t => T.observablePoint = "" [@@bs.get];
    /*
     The skew factor for the object in radians.
     Assignment by value since pixi-v4.
     */
    external setSkew : t => T.observablePoint => unit = "skew" [@@bs.set];
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
    external filters : t => array T.filter = "" [@@bs.get];
    /*
     Sets the filters for the displayObject.

     <ul>
     <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
     To remove filters simply set this property to 'null'</li>
     </ul>
     */
    external setFilters : t => array T.filter => unit = "filters" [@@bs.set];
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
    /*
     Updates the object transform for rendering

     TODO - Optimization pass!
     */
    external updateTransform : unit = "" [@@bs.send.pipe : t];
    /*
     recursively updates transform of all objects from the root to this one
     internal function for toLocal()
     */
    external _recursivePostUpdateTransform : unit = "" [@@bs.send.pipe : t];
    /*
     Retrieves the bounds of the displayObject as a rectangle object.
     */
    external getBounds : skipUpdate::Js.boolean => rect::T.rectangle => T.rectangle =
      "" [@@bs.send.pipe : t];
    /*
     Retrieves the local bounds of the displayObject as a rectangle object
     */
    external getLocalBounds : rect::T.rectangle? => T.rectangle = "" [@@bs.send.pipe : t];
    /*
     Calculates the global position of the display object
     */
    external toGlobal : position::T.point => point::T.point? => skipUpdate::Js.boolean? => T.point =
      "" [@@bs.send.pipe : t];
    /*
     Calculates the local position of the display object relative to another point
     */
    external toLocal :
      position::T.point =>
      from::T.displayObject? =>
      point::T.point? =>
      skipUpdate::Js.boolean? =>
      T.point =
      "" [@@bs.send.pipe : t];
    /*
     Renders the object using the WebGL renderer
     */
    external renderWebGL : renderer::T.webGLRenderer => unit = "" [@@bs.send.pipe : t];
    /*
     Renders the object using the Canvas renderer
     */
    external renderCanvas : renderer::T.canvasRenderer => unit = "" [@@bs.send.pipe : t];
    /*
     Set the parent Container of this DisplayObject
     */
    external setParent : container::T.container => T.container = "" [@@bs.send.pipe : t];
    /*
     Convenience function to set the position, scale, skew and pivot at once.
     */
    external setTransform :
      x::float? =>
      y::float? =>
      scaleX::float? =>
      scaleY::float? =>
      rotation::float? =>
      skewX::float? =>
      skewY::float? =>
      pivotX::float? =>
      pivotY::float? =>
      T.displayObject =
      "" [@@bs.send.pipe : t];
    /*
     <p>Base destroy method for generic display objects. This will automatically
     remove the display object from its parent Container as well as remove
     all current event listeners and internal references. Do not use a DisplayObject
     after calling <code>destroy</code>.</p>
     */
    external destroy : unit = "" [@@bs.send.pipe : t];
    /*
     Returns the global position of the displayObject. Does not depend on object scale, rotation and pivot.
     */
    external getGlobalPosition : point::T.point => skipUpdate::Js.boolean => T.point =
      "" [@@bs.send.pipe : t];
  };
  module Transform = {
    /*
     Generic class to deal with traditional 2D matrix transforms
     local transformation is calculated from position,scale,skew and rotation
     */
    type t = T.transform;
    external create : unit => t = "Transform" [@@bs.new] [@@bs.module ("pixi.js", "PIXI")];
    /*
     The coordinate of the object relative to the local coordinates of the parent.
     */
    external position : t => T.point = "" [@@bs.get];
    /*
     The coordinate of the object relative to the local coordinates of the parent.
     */
    external setPosition : t => T.point => unit = "position" [@@bs.set];
    /*
     The scale factor of the object.
     */
    external scale : t => T.point = "" [@@bs.get];
    /*
     The scale factor of the object.
     */
    external setScale : t => T.point => unit = "scale" [@@bs.set];
    /*
     The skew amount, on the x and y axis.
     */
    external skew : t => T.observablePoint = "" [@@bs.get];
    /*
     The skew amount, on the x and y axis.
     */
    external setSkew : t => T.observablePoint => unit = "skew" [@@bs.set];
    /*
     The pivot point of the displayObject that it rotates around
     */
    external pivot : t => T.point = "" [@@bs.get];
    /*
     The pivot point of the displayObject that it rotates around
     */
    external setPivot : t => T.point => unit = "pivot" [@@bs.set];
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
    external worldTransform : t => T.matrix = "" [@@bs.get];
    /*
     The global matrix transform. It can be swapped temporarily by some functions like getLocalBounds()
     */
    external setWorldTransform : t => T.matrix => unit = "worldTransform" [@@bs.set];
    /*
     The local matrix transform
     */
    external localTransform : t => T.matrix = "" [@@bs.get];
    /*
     The local matrix transform
     */
    external setLocalTransform : t => T.matrix => unit = "localTransform" [@@bs.set];
    /*
     Updates only local matrix
     */
    external updateLocalTransform : unit = "" [@@bs.send.pipe : t];
    /*
     Updates the values of the object and applies the parent's transform.
     */
    external updateTransform : parentTransform::T.transform => unit = "" [@@bs.send.pipe : t];
    /*
     Decomposes a matrix and sets the transforms properties based on it.
     */
    external setFromMatrix : matrix::T.matrix => unit = "" [@@bs.send.pipe : t];
  };
  module TransformBase = {
    /*
     Generic class to deal with traditional 2D matrix transforms
     */
    type t = T.transformBase;
    external create : unit => t = "TransformBase" [@@bs.new] [@@bs.module ("pixi.js", "PIXI")];
    /*
     The global matrix transform. It can be swapped temporarily by some functions like getLocalBounds()
     */
    external worldTransform : t => T.matrix = "" [@@bs.get];
    /*
     The global matrix transform. It can be swapped temporarily by some functions like getLocalBounds()
     */
    external setWorldTransform : t => T.matrix => unit = "worldTransform" [@@bs.set];
    /*
     The local matrix transform
     */
    external localTransform : t => T.matrix = "" [@@bs.get];
    /*
     The local matrix transform
     */
    external setLocalTransform : t => T.matrix => unit = "localTransform" [@@bs.set];
    /*
     TransformBase does not have decomposition, so this function wont do anything
     */
    external updateLocalTransform : unit = "" [@@bs.send.pipe : t];
    /*
     Updates the values of the object and applies the parent's transform.
     */
    external updateTransform : parentTransform::T.transformBase => unit = "" [@@bs.send.pipe : t];
  };
  module TransformStatic = {
    /*
     Transform that takes care about its versions
     */
    type t = T.transformStatic;
    external create : unit => t = "TransformStatic" [@@bs.new] [@@bs.module ("pixi.js", "PIXI")];
    /*
     The coordinate of the object relative to the local coordinates of the parent.
     */
    external position : t => T.observablePoint = "" [@@bs.get];
    /*
     The coordinate of the object relative to the local coordinates of the parent.
     */
    external setPosition : t => T.observablePoint => unit = "position" [@@bs.set];
    /*
     The scale factor of the object.
     */
    external scale : t => T.observablePoint = "" [@@bs.get];
    /*
     The scale factor of the object.
     */
    external setScale : t => T.observablePoint => unit = "scale" [@@bs.set];
    /*
     The pivot point of the displayObject that it rotates around
     */
    external pivot : t => T.observablePoint = "" [@@bs.get];
    /*
     The pivot point of the displayObject that it rotates around
     */
    external setPivot : t => T.observablePoint => unit = "pivot" [@@bs.set];
    /*
     The skew amount, on the x and y axis.
     */
    external skew : t => T.observablePoint = "" [@@bs.get];
    /*
     The skew amount, on the x and y axis.
     */
    external setSkew : t => T.observablePoint => unit = "skew" [@@bs.set];
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
    external worldTransform : t => T.matrix = "" [@@bs.get];
    /*
     The global matrix transform. It can be swapped temporarily by some functions like getLocalBounds()
     */
    external setWorldTransform : t => T.matrix => unit = "worldTransform" [@@bs.set];
    /*
     The local matrix transform
     */
    external localTransform : t => T.matrix = "" [@@bs.get];
    /*
     The local matrix transform
     */
    external setLocalTransform : t => T.matrix => unit = "localTransform" [@@bs.set];
    /*
     Updates only local matrix
     */
    external updateLocalTransform : unit = "" [@@bs.send.pipe : t];
    /*
     Updates the values of the object and applies the parent's transform.
     */
    external updateTransform : parentTransform::T.transform => unit = "" [@@bs.send.pipe : t];
    /*
     Decomposes a matrix and sets the transforms properties based on it.
     */
    external setFromMatrix : matrix::T.matrix => unit = "" [@@bs.send.pipe : t];
  };
  module Graphics = {
    /*
     The Graphics class contains methods used to draw primitive shapes such as lines, circles and
     rectangles to the display, and to color and fill them.
     */
    type t = T.graphics;
    external create : nativeLines::Js.boolean? => unit => t =
      "Graphics" [@@bs.new] [@@bs.module ("pixi.js", "PIXI")];
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
    external children : t => array T.displayObject = "" [@@bs.get];
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
    external transform : t => T.transformBase = "" [@@bs.get];
    /*
     World transform and local transform of this object.
     This will become read-only later, please do not assign anything there unless you know what are you doing
     */
    external setTransform : t => T.transformBase => unit = "transform" [@@bs.set];
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
    external parent : t => T.container = "" [@@bs.get];
    /*
     The multiplied alpha of the displayObject
     */
    external worldAlpha : t => float = "" [@@bs.get];
    /*
     The area the filter is applied to. This is used as more of an optimisation
     rather than figuring out the dimensions of the displayObject each frame you can set this rectangle

     Also works as an interaction mask
     */
    external filterArea : t => T.rectangle = "" [@@bs.get];
    /*
     The area the filter is applied to. This is used as more of an optimisation
     rather than figuring out the dimensions of the displayObject each frame you can set this rectangle

     Also works as an interaction mask
     */
    external setFilterArea : t => T.rectangle => unit = "filterArea" [@@bs.set];
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
    external worldTransform : t => T.matrix = "" [@@bs.get];
    /*
     Current transform of the object based on local factors: position, scale, other stuff
     */
    external localTransform : t => T.matrix = "" [@@bs.get];
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
    external skew : t => T.observablePoint = "" [@@bs.get];
    /*
     The skew factor for the object in radians.
     Assignment by value since pixi-v4.
     */
    external setSkew : t => T.observablePoint => unit = "skew" [@@bs.set];
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
    external filters : t => array T.filter = "" [@@bs.get];
    /*
     Sets the filters for the displayObject.

     <ul>
     <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
     To remove filters simply set this property to 'null'</li>
     </ul>
     */
    external setFilters : t => array T.filter => unit = "filters" [@@bs.set];
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
    /*
     Creates a new Graphics object with the same values as this one.
     Note that the only the properties of the object are cloned, not its transform (position,scale,etc)
     */
    external clone : T.graphics = "" [@@bs.send.pipe : t];
    /*
     Specifies the line style used for subsequent calls to Graphics methods such as the lineTo()
     method or the drawCircle() method.
     */
    external lineStyle : lineWidth::float? => color::float? => alpha::float? => T.graphics =
      "" [@@bs.send.pipe : t];
    /*
     Moves the current drawing position to x, y.
     */
    external moveTo : x::float => y::float => T.graphics = "" [@@bs.send.pipe : t];
    /*
     Draws a line using the current line style from the current drawing position to (x, y);
     The current drawing position is then set to (x, y).
     */
    external lineTo : x::float => y::float => T.graphics = "" [@@bs.send.pipe : t];
    /*
     Calculate the points for a quadratic bezier curve and then draws it.
     Based on: https://stackoverflow.com/questions/785097/how-do-i-implement-a-bezier-curve-in-c
     */
    external quadraticCurveTo : cpX::float => cpY::float => toX::float => toY::float => T.graphics =
      "" [@@bs.send.pipe : t];
    /*
     Calculate the points for a bezier curve and then draws it.
     */
    external bezierCurveTo :
      cpX::float =>
      cpY::float =>
      cpX2::float =>
      cpY2::float =>
      toX::float =>
      toY::float =>
      T.graphics =
      "" [@@bs.send.pipe : t];
    /*
     The arcTo() method creates an arc/curve between two tangents on the canvas.

     &quot;borrowed&quot; from https://code.google.com/p/fxcanvas/ - thanks google!
     */
    external arcTo :
      x1::float => y1::float => x2::float => y2::float => radius::float => T.graphics =
      "" [@@bs.send.pipe : t];
    /*
     The arc method creates an arc/curve (used to create circles, or parts of circles).
     */
    external arc :
      cx::float =>
      cy::float =>
      radius::float =>
      startAngle::float =>
      endAngle::float =>
      anticlockwise::Js.boolean? =>
      T.graphics =
      "" [@@bs.send.pipe : t];
    /*
     Specifies a simple one-color fill that subsequent calls to other Graphics methods
     (such as lineTo() or drawCircle()) use when drawing.
     */
    external beginFill : color::float? => alpha::float? => T.graphics = "" [@@bs.send.pipe : t];
    /*
     Applies a fill to the lines and shapes that were added since the last call to the beginFill() method.
     */
    external endFill : T.graphics = "" [@@bs.send.pipe : t];
    external drawRect : x::float => y::float => width::float => height::float => T.graphics =
      "" [@@bs.send.pipe : t];
    external drawRoundedRect :
      x::float => y::float => width::float => height::float => radius::float => T.graphics =
      "" [@@bs.send.pipe : t];
    /*
     Draws a circle.
     */
    external drawCircle : x::float => y::float => radius::float => T.graphics =
      "" [@@bs.send.pipe : t];
    /*
     Draws an ellipse.
     */
    external drawEllipse : x::float => y::float => width::float => height::float => T.graphics =
      "" [@@bs.send.pipe : t];
    /*
     Draws a polygon using the given path.
     */
    external drawPolygon :
      path::unit /* unknown js type: Array.<number>|Array.<PIXI.Point> */ => T.graphics =
      "" [@@bs.send.pipe : t];
    /*
     Clears the graphics that were drawn to this Graphics object, and resets fill and line style settings.
     */
    external clear : T.graphics = "" [@@bs.send.pipe : t];
    /*
     True if graphics consists of one rectangle, and thus, can be drawn like a Sprite and
     masked with gl.scissor.
     */
    external isFastRect : Js.boolean = "" [@@bs.send.pipe : t];
    /*
     Tests if a point is inside this graphics object
     */
    external containsPoint : point::T.point => Js.boolean = "" [@@bs.send.pipe : t];
    /*
     Update the bounds of the object
     */
    external updateLocalBounds : unit = "" [@@bs.send.pipe : t];
    /*
     Draws the given shape to this Graphics object. Can be any of Circle, Rectangle, Ellipse, Line or Polygon.
     */
    external drawShape :
      shape::
        unit /* unknown js type: PIXI.Circle|PIXI.Ellipse|PIXI.Polygon|PIXI.Rectangle|PIXI.RoundedRectangle */ =>
      T.graphicsData =
      "" [@@bs.send.pipe : t];
    /*
     Generates a canvas texture.
     */
    external generateCanvasTexture : scaleMode::float => resolution::float => T.texture =
      "" [@@bs.send.pipe : t];
    /*
     Closes the current path.
     */
    external closePath : T.graphics = "" [@@bs.send.pipe : t];
    /*
     Adds a hole in the current path.
     */
    external addHole : T.graphics = "" [@@bs.send.pipe : t];
    /*
     Destroys the Graphics object.
     */
    external destroy : options::unit /* unknown js type: object|boolean */? => unit =
      "" [@@bs.send.pipe : t];
    /*
     Adds one or more children to the container.

     <p>Multiple items can be added like so: <code>myContainer.addChild(thingOne, thingTwo, thingThree)</code></p>
     */
    external addChild : child::T.displayObject => T.displayObject = "" [@@bs.send.pipe : t];
    /*
     Adds a child to the container at a specified index. If the index is out of bounds an error will be thrown
     */
    external addChildAt : child::T.displayObject => index::float => T.displayObject =
      "" [@@bs.send.pipe : t];
    /*
     Swaps the position of 2 Display Objects within this container.
     */
    external swapChildren : child::T.displayObject => child2::T.displayObject => unit =
      "" [@@bs.send.pipe : t];
    /*
     Returns the index position of a child DisplayObject instance
     */
    external getChildIndex : child::T.displayObject => float = "" [@@bs.send.pipe : t];
    /*
     Changes the position of an existing child in the display object container
     */
    external setChildIndex : child::T.displayObject => index::float => unit =
      "" [@@bs.send.pipe : t];
    /*
     Returns the child at the specified index
     */
    external getChildAt : index::float => T.displayObject = "" [@@bs.send.pipe : t];
    /*
     Removes one or more children from the container.
     */
    external removeChild : child::T.displayObject => T.displayObject = "" [@@bs.send.pipe : t];
    /*
     Removes a child from the specified index position.
     */
    external removeChildAt : index::float => T.displayObject = "" [@@bs.send.pipe : t];
    /*
     Removes all children from this container that are within the begin and end indexes.
     */
    external removeChildren : beginIndex::float? => endIndex::float? => array T.displayObject =
      "" [@@bs.send.pipe : t];
    /*
     Updates the transform on all children of this container for rendering
     */
    external updateTransform : unit = "" [@@bs.send.pipe : t];
    /*
     Recalculates the bounds of the container.
     */
    external calculateBounds : unit = "" [@@bs.send.pipe : t];
    /*
     Renders the object using the WebGL renderer
     */
    external renderWebGL : renderer::T.webGLRenderer => unit = "" [@@bs.send.pipe : t];
    /*
     Renders the object using the Canvas renderer
     */
    external renderCanvas : renderer::T.canvasRenderer => unit = "" [@@bs.send.pipe : t];
    /*
     recursively updates transform of all objects from the root to this one
     internal function for toLocal()
     */
    external _recursivePostUpdateTransform : unit = "" [@@bs.send.pipe : t];
    /*
     Retrieves the bounds of the displayObject as a rectangle object.
     */
    external getBounds : skipUpdate::Js.boolean => rect::T.rectangle => T.rectangle =
      "" [@@bs.send.pipe : t];
    /*
     Retrieves the local bounds of the displayObject as a rectangle object
     */
    external getLocalBounds : rect::T.rectangle? => T.rectangle = "" [@@bs.send.pipe : t];
    /*
     Calculates the global position of the display object
     */
    external toGlobal : position::T.point => point::T.point? => skipUpdate::Js.boolean? => T.point =
      "" [@@bs.send.pipe : t];
    /*
     Calculates the local position of the display object relative to another point
     */
    external toLocal :
      position::T.point =>
      from::T.displayObject? =>
      point::T.point? =>
      skipUpdate::Js.boolean? =>
      T.point =
      "" [@@bs.send.pipe : t];
    /*
     Set the parent Container of this DisplayObject
     */
    external setParent : container::T.container => T.container = "" [@@bs.send.pipe : t];
    /*
     Convenience function to set the position, scale, skew and pivot at once.
     */
    external setTransform :
      x::float? =>
      y::float? =>
      scaleX::float? =>
      scaleY::float? =>
      rotation::float? =>
      skewX::float? =>
      skewY::float? =>
      pivotX::float? =>
      pivotY::float? =>
      T.displayObject =
      "" [@@bs.send.pipe : t];
  };
  module GraphicsData = {
    /*
     A GraphicsData object.
     */
    type t = T.graphicsData;
    external create :
      lineWidth::float =>
      lineColor::float =>
      lineAlpha::float =>
      fillColor::float =>
      fillAlpha::float =>
      fill::Js.boolean =>
      nativeLines::Js.boolean =>
      shape::unit /* unknown js type: PIXI.Circle|PIXI.Rectangle|PIXI.Ellipse|PIXI.Polygon */ =>
      unit =>
      t =
      "GraphicsData" [@@bs.new] [@@bs.module ("pixi.js", "PIXI")];
    /*
     Creates a new GraphicsData object with the same values as this one.
     */
    external clone : T.graphicsData = "" [@@bs.send.pipe : t];
    /*
     Adds a hole to the shape.
     */
    external addHole : shape::unit /* unknown js type: PIXI.Rectangle|PIXI.Circle */ => unit =
      "" [@@bs.send.pipe : t];
    /*
     Destroys the Graphics data.
     */
    external destroy : unit = "" [@@bs.send.pipe : t];
  };
  module GraphicsRenderer = {
    /*
     Renders the graphics object.
     */
    type t = T.graphicsRenderer;
    external create : renderer::T.webGLRenderer => unit => t =
      "GraphicsRenderer" [@@bs.new] [@@bs.module ("pixi.js", "PIXI")];
    /*
     The renderer this manager works for.
     */
    external renderer : t => T.webGLRenderer = "" [@@bs.get];
    /*
     The renderer this manager works for.
     */
    external setRenderer : t => T.webGLRenderer => unit = "renderer" [@@bs.set];
    /*
     Destroys this renderer.
     */
    external destroy : unit = "" [@@bs.send.pipe : t];
    /*
     Renders a graphics object.
     */
    external render : graphics::T.graphics => unit = "" [@@bs.send.pipe : t];
    /*
     Starts the renderer and sets the shader
     */
    external start : unit = "" [@@bs.send.pipe : t];
    /*
     Stops the renderer
     */
    external stop : unit = "" [@@bs.send.pipe : t];
    /*
     Stub method for rendering content and emptying the current batch.
     */
    external flush : unit = "" [@@bs.send.pipe : t];
  };
  module PrimitiveShader = {
    /*
     This shader is used to draw simple primitive shapes for {@link PIXI.Graphics}.
     */
    type t = T.primitiveShader;
    external create : gl::ReasonJs.Gl.glT => unit => t =
      "PrimitiveShader" [@@bs.new] [@@bs.module ("pixi.js", "PIXI")];
  };
  module GroupD8 = {
    type t = T.groupD8;
    external create : unit => t = "GroupD8" [@@bs.new] [@@bs.module ("pixi.js", "PIXI")];
  };
  module Matrix = {
    /*
     The pixi Matrix class as an object, which makes it a lot faster,
     here is a representation of it :
     | a | b | tx|
     | c | d | ty|
     | 0 | 0 | 1 |
     */
    type t = T.matrix;
    external create :
      a::float? => b::float? => c::float? => d::float? => tx::float? => ty::float? => unit => t =
      "Matrix" [@@bs.new] [@@bs.module ("pixi.js", "PIXI")];
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
    /*
     Creates a Matrix object based on the given array. The Element to Matrix mapping order is as follows:

     a = array[0]
     b = array[1]
     c = array[3]
     d = array[4]
     tx = array[2]
     ty = array[5]
     */
    external fromArray : array::array float => unit = "" [@@bs.send.pipe : t];
    /*
     sets the matrix properties
     */
    external set :
      a::float => b::float => c::float => d::float => tx::float => ty::float => T.matrix =
      "" [@@bs.send.pipe : t];
    /*
     Creates an array from the current Matrix object.
     */
    external toArray : transpose::Js.boolean => out::Js_typed_array.Float32Array.t? => array float =
      "" [@@bs.send.pipe : t];
    /*
     Get a new position with the current transformation applied.
     Can be used to go from a child's coordinate space to the world coordinate space. (e.g. rendering)
     */
    external apply : pos::T.point => newPos::T.point? => T.point = "" [@@bs.send.pipe : t];
    /*
     Get a new position with the inverse of the current transformation applied.
     Can be used to go from the world coordinate space to a child's coordinate space. (e.g. input)
     */
    external applyInverse : pos::T.point => newPos::T.point? => T.point = "" [@@bs.send.pipe : t];
    /*
     Translates the matrix on the x and y.
     */
    external translate : x::float => y::float => T.matrix = "" [@@bs.send.pipe : t];
    /*
     Applies a scale transformation to the matrix.
     */
    external scale : x::float => y::float => T.matrix = "" [@@bs.send.pipe : t];
    /*
     Applies a rotation transformation to the matrix.
     */
    external rotate : angle::float => T.matrix = "" [@@bs.send.pipe : t];
    /*
     Appends the given Matrix to this Matrix.
     */
    external append : matrix::T.matrix => T.matrix = "" [@@bs.send.pipe : t];
    /*
     Sets the matrix based on all the available properties
     */
    external setTransform :
      x::float =>
      y::float =>
      pivotX::float =>
      pivotY::float =>
      scaleX::float =>
      scaleY::float =>
      rotation::float =>
      skewX::float =>
      skewY::float =>
      T.matrix =
      "" [@@bs.send.pipe : t];
    /*
     Prepends the given Matrix to this Matrix.
     */
    external prepend : matrix::T.matrix => T.matrix = "" [@@bs.send.pipe : t];
    /*
     Decomposes the matrix (x, y, scaleX, scaleY, and rotation) and sets the properties on to a transform.
     */
    external decompose :
      transform::unit /* unknown js type: PIXI.Transform|PIXI.TransformStatic */ => unit /* unknown js type: PIXI.Transform|PIXI.TransformStatic */ =
      "" [@@bs.send.pipe : t];
    /*
     Inverts this matrix
     */
    external invert : T.matrix = "" [@@bs.send.pipe : t];
    /*
     Resets this Matix to an identity (default) matrix.
     */
    external identity : T.matrix = "" [@@bs.send.pipe : t];
    /*
     Creates a new Matrix object with the same values as this one.
     */
    external clone : T.matrix = "" [@@bs.send.pipe : t];
    /*
     Changes the values of the given matrix to be the same as the ones in this matrix
     */
    external copy : matrix::T.matrix => T.matrix = "" [@@bs.send.pipe : t];
  };
  module ObservablePoint = {
    /*
     The Point object represents a location in a two-dimensional coordinate system, where x represents
     the horizontal axis and y represents the vertical axis.
     An observable point is a point that triggers a callback when the point's position is changed.
     */
    type t = T.observablePoint;
    external create :
      cb::unit /* unknown js type: function */ =>
      scope::unit /* unknown js type: object */ =>
      x::float? =>
      y::float? =>
      unit =>
      t =
      "ObservablePoint" [@@bs.new] [@@bs.module ("pixi.js", "PIXI")];
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
    /*
     Sets the point to a new x and y position.
     If y is omitted, both x and y will be set to x.
     */
    external set : x::float? => y::float? => unit = "" [@@bs.send.pipe : t];
    /*
     Copies the data from another point
     */
    external copy : point::unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
      "" [@@bs.send.pipe : t];
  };
  module Point = {
    /*
     The Point object represents a location in a two-dimensional coordinate system, where x represents
     the horizontal axis and y represents the vertical axis.
     */
    type t = T.point;
    external create : x::float? => y::float? => unit => t =
      "Point" [@@bs.new] [@@bs.module ("pixi.js", "PIXI")];
    external x : t => float = "" [@@bs.get];
    external setX : t => float => unit = "x" [@@bs.set];
    external y : t => float = "" [@@bs.get];
    external setY : t => float => unit = "y" [@@bs.set];
    /*
     Creates a clone of this point
     */
    external clone : T.point = "" [@@bs.send.pipe : t];
    /*
     Copies x and y from the given point
     */
    external copy : p::T.point => unit = "" [@@bs.send.pipe : t];
    /*
     Returns true if the given point is equal to this point
     */
    external equals : p::T.point => Js.boolean = "" [@@bs.send.pipe : t];
    /*
     Sets the point to a new x and y position.
     If y is omitted, both x and y will be set to x.
     */
    external set : x::float? => y::float? => unit = "" [@@bs.send.pipe : t];
  };
  module Circle = {
    /*
     The Circle object can be used to specify a hit area for displayObjects
     */
    type t = T.circle;
    external create : x::float? => y::float? => radius::float? => unit => t =
      "Circle" [@@bs.new] [@@bs.module ("pixi.js", "PIXI")];
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
    /*
     Creates a clone of this Circle instance
     */
    external clone : T.circle = "" [@@bs.send.pipe : t];
    /*
     Checks whether the x and y coordinates given are contained within this circle
     */
    external contains : x::float => y::float => Js.boolean = "" [@@bs.send.pipe : t];
    /*
     Returns the framing rectangle of the circle as a Rectangle object
     */
    external getBounds : T.rectangle = "" [@@bs.send.pipe : t];
  };
  module Ellipse = {
    /*
     The Ellipse object can be used to specify a hit area for displayObjects
     */
    type t = T.ellipse;
    external create : x::float? => y::float? => width::float? => height::float? => unit => t =
      "Ellipse" [@@bs.new] [@@bs.module ("pixi.js", "PIXI")];
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
     Creates a clone of this Ellipse instance
     */
    external clone : T.ellipse = "" [@@bs.send.pipe : t];
    /*
     Checks whether the x and y coordinates given are contained within this ellipse
     */
    external contains : x::float => y::float => Js.boolean = "" [@@bs.send.pipe : t];
    /*
     Returns the framing rectangle of the ellipse as a Rectangle object
     */
    external getBounds : T.rectangle = "" [@@bs.send.pipe : t];
  };
  module Polygon = {
    type t = T.polygon;
    external create :
      points::unit /* unknown js type: Array.<PIXI.Point>|Array.<number> */ => unit => t =
      "Polygon" [@@bs.new] [@@bs.module ("pixi.js", "PIXI")];
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
    /*
     Creates a clone of this polygon
     */
    external clone : T.polygon = "" [@@bs.send.pipe : t];
    /*
     Closes the polygon, adding points if necessary.
     */
    external close : unit = "" [@@bs.send.pipe : t];
    /*
     Checks whether the x and y coordinates passed to this function are contained within this polygon
     */
    external contains : x::float => y::float => Js.boolean = "" [@@bs.send.pipe : t];
  };
  module Rectangle = {
    /*
     Rectangle object is an area defined by its position, as indicated by its top-left corner
     point (x, y) and by its width and its height.
     */
    type t = T.rectangle;
    external create : x::float? => y::float? => width::float? => height::float? => unit => t =
      "Rectangle" [@@bs.new] [@@bs.module ("pixi.js", "PIXI")];
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
    /*
     Creates a clone of this Rectangle
     */
    external clone : T.rectangle = "" [@@bs.send.pipe : t];
    /*
     Copies another rectangle to this one.
     */
    external copy : rectangle::T.rectangle => T.rectangle = "" [@@bs.send.pipe : t];
    /*
     Checks whether the x and y coordinates given are contained within this Rectangle
     */
    external contains : x::float => y::float => Js.boolean = "" [@@bs.send.pipe : t];
    /*
     Pads the rectangle making it grow in all directions.
     */
    external pad : paddingX::float => paddingY::float => unit = "" [@@bs.send.pipe : t];
    /*
     Fits this rectangle around the passed one.
     */
    external fit : rectangle::T.rectangle => unit = "" [@@bs.send.pipe : t];
    /*
     Enlarges this rectangle to include the passed rectangle.
     */
    external enlarge : rectangle::T.rectangle => unit = "" [@@bs.send.pipe : t];
  };
  module RoundedRectangle = {
    /*
     The Rounded Rectangle object is an area that has nice rounded corners, as indicated by its
     top-left corner point (x, y) and by its width and its height and its radius.
     */
    type t = T.roundedRectangle;
    external create :
      x::float? => y::float? => width::float? => height::float? => radius::float? => unit => t =
      "RoundedRectangle" [@@bs.new] [@@bs.module ("pixi.js", "PIXI")];
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
    /*
     Creates a clone of this Rounded Rectangle
     */
    external clone : T.roundedRectangle = "" [@@bs.send.pipe : t];
    /*
     Checks whether the x and y coordinates given are contained within this Rounded Rectangle
     */
    external contains : x::float => y::float => Js.boolean = "" [@@bs.send.pipe : t];
  };
  module SystemRenderer = {
    /*
     The SystemRenderer is the base for a Pixi Renderer. It is extended by the {@link PIXI.CanvasRenderer}
     and {@link PIXI.WebGLRenderer} which can be used for rendering a Pixi scene.
     */
    type t = T.systemRenderer;
    type createOptions;
    /*
     The optional renderer parameters
     */
    external mkCreateOptions :
      width::float? =>
      height::float? =>
      view::Dom.element? =>
      transparent::Js.boolean? =>
      autoResize::Js.boolean? =>
      antialias::Js.boolean? =>
      resolution::float? =>
      preserveDrawingBuffer::Js.boolean? =>
      clearBeforeRender::Js.boolean? =>
      backgroundColor::float? =>
      roundPixels::Js.boolean? =>
      unit =>
      createOptions =
      "" [@@bs.obj];
    external create : system::string => options::createOptions? => unit => t =
      "SystemRenderer" [@@bs.new] [@@bs.module ("pixi.js", "PIXI")];
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
    external screen : t => T.rectangle = "" [@@bs.get];
    /*
     Measurements of the screen. (0, 0, screenWidth, screenHeight)

     Its safe to use as filterArea or hitArea for whole stage
     */
    external setScreen : t => T.rectangle => unit = "screen" [@@bs.set];
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
    external setPreserveDrawingBuffer : t => Js.boolean => unit =
      "preserveDrawingBuffer" [@@bs.set];
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
    /*
     Resizes the screen and canvas to the specified width and height
     Canvas dimensions are multiplied by resolution
     */
    external resize : screenWidth::float => screenHeight::float => unit = "" [@@bs.send.pipe : t];
    /*
     Useful function that returns a texture of the display object that can then be used to create sprites
     This can be quite useful if your displayObject is complicated and needs to be reused multiple times.
     */
    external generateTexture :
      displayObject::T.displayObject => scaleMode::float => resolution::float => T.texture =
      "" [@@bs.send.pipe : t];
    /*
     Removes everything from the renderer and optionally removes the Canvas DOM element.
     */
    external destroy : removeView::Js.boolean? => unit = "" [@@bs.send.pipe : t];
  };
  module CanvasRenderer = {
    /*
     The CanvasRenderer draws the scene and all its content onto a 2d canvas. This renderer should
     be used for browsers that do not support WebGL. Don't forget to add the CanvasRenderer.view to
     your DOM or you will not see anything :)
     */
    type t = T.canvasRenderer;
    type createOptions;
    /*
     The optional renderer parameters
     */
    external mkCreateOptions :
      width::float? =>
      height::float? =>
      view::Dom.element? =>
      transparent::Js.boolean? =>
      autoResize::Js.boolean? =>
      antialias::Js.boolean? =>
      resolution::float? =>
      preserveDrawingBuffer::Js.boolean? =>
      clearBeforeRender::Js.boolean? =>
      backgroundColor::float? =>
      roundPixels::Js.boolean? =>
      unit =>
      createOptions =
      "" [@@bs.obj];
    external create : options::createOptions? => unit => t =
      "CanvasRenderer" [@@bs.new] [@@bs.module ("pixi.js", "PIXI")];
    /*
     The root canvas 2d context that everything is drawn with.
     */
    external rootContext : t => unit /* unknown js type: CanvasRenderingContext2D */ =
      "" [@@bs.get];
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
    external maskManager : t => T.canvasMaskManager = "" [@@bs.get];
    /*
     Instance of a CanvasMaskManager, handles masking when using the canvas renderer.
     */
    external setMaskManager : t => T.canvasMaskManager => unit = "maskManager" [@@bs.set];
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
    external extract : t => T.canvasExtract = "" [@@bs.get];
    /*
     Collection of methods for extracting data (image, pixels, etc.) from a display object or render texture
     */
    external setExtract : t => T.canvasExtract => unit = "extract" [@@bs.set];
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
    external screen : t => T.rectangle = "" [@@bs.get];
    /*
     Measurements of the screen. (0, 0, screenWidth, screenHeight)

     Its safe to use as filterArea or hitArea for whole stage
     */
    external setScreen : t => T.rectangle => unit = "screen" [@@bs.set];
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
    external setPreserveDrawingBuffer : t => Js.boolean => unit =
      "preserveDrawingBuffer" [@@bs.set];
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
    /*
     Renders the object to this canvas view
     */
    external render :
      displayObject::T.displayObject =>
      renderTexture::T.renderTexture? =>
      clear::Js.boolean? =>
      transform::T.transform? =>
      skipUpdateTransform::Js.boolean? =>
      unit =
      "" [@@bs.send.pipe : t];
    /*
     Clear the canvas of renderer.
     */
    external clear : clearColor::string? => unit = "" [@@bs.send.pipe : t];
    /*
     Sets the blend mode of the renderer.
     */
    external setBlendMode : blendMode::float => unit = "" [@@bs.send.pipe : t];
    /*
     Removes everything from the renderer and optionally removes the Canvas DOM element.
     */
    external destroy : removeView::Js.boolean? => unit = "" [@@bs.send.pipe : t];
    /*
     Resizes the canvas view to the specified width and height.
     */
    external resize : screenWidth::float => screenHeight::float => unit = "" [@@bs.send.pipe : t];
    /*
     Adds a plugin to the renderer.
     */
    external registerPlugin :
      pluginName::string => ctor::unit /* unknown js type: function */ => unit =
      "" [@@bs.send.pipe : t];
    /*
     Useful function that returns a texture of the display object that can then be used to create sprites
     This can be quite useful if your displayObject is complicated and needs to be reused multiple times.
     */
    external generateTexture :
      displayObject::T.displayObject => scaleMode::float => resolution::float => T.texture =
      "" [@@bs.send.pipe : t];
  };
  module CanvasMaskManager = {
    /*
     A set of functions used to handle masking.
     */
    type t = T.canvasMaskManager;
    external create : renderer::T.canvasRenderer => unit => t =
      "CanvasMaskManager" [@@bs.new] [@@bs.module ("pixi.js", "PIXI")];
    /*
     This method adds it to the current stack of masks.
     */
    external pushMask : maskData::unit /* unknown js type: object */ => unit =
      "" [@@bs.send.pipe : t];
    /*
     Renders a PIXI.Graphics shape.
     */
    external renderGraphicsShape : graphics::T.graphics => unit = "" [@@bs.send.pipe : t];
    /*
     Restores the current drawing context to the state it was before the mask was applied.
     */
    external popMask : renderer::T.canvasRenderer => unit = "" [@@bs.send.pipe : t];
    /*
     Destroys this canvas mask manager.
     */
    external destroy : unit = "" [@@bs.send.pipe : t];
  };
  module CanvasRenderTarget = {
    /*
     Creates a Canvas element of the given size.
     */
    type t = T.canvasRenderTarget;
    external create : width::float => height::float => resolution::float? => unit => t =
      "CanvasRenderTarget" [@@bs.new] [@@bs.module ("pixi.js", "PIXI")];
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
    /*
     Resizes the canvas to the specified width and height.
     */
    external resize : width::float => height::float => unit = "" [@@bs.send.pipe : t];
    /*
     Destroys this canvas.
     */
    external destroy : unit = "" [@@bs.send.pipe : t];
  };
  module TextureGarbageCollector = {
    /*
     TextureGarbageCollector. This class manages the GPU and ensures that it does not get clogged
     up with textures that are no longer being used.
     */
    type t = T.textureGarbageCollector;
    external create : renderer::T.webGLRenderer => unit => t =
      "TextureGarbageCollector" [@@bs.new] [@@bs.module ("pixi.js", "PIXI")];
    /*
     Checks to see when the last time a texture was used
     if the texture has not been used for a specified amount of time it will be removed from the GPU
     */
    external update : unit = "" [@@bs.send.pipe : t];
    /*
     Checks to see when the last time a texture was used
     if the texture has not been used for a specified amount of time it will be removed from the GPU
     */
    external run : unit = "" [@@bs.send.pipe : t];
    /*
     Removes all the textures within the specified displayObject and its children from the GPU
     */
    external unload : displayObject::T.displayObject => unit = "" [@@bs.send.pipe : t];
  };
  module TextureManager = {
    /*
     Helper class to create a webGL Texture
     */
    type t = T.textureManager;
    external create : renderer::T.webGLRenderer => unit => t =
      "TextureManager" [@@bs.new] [@@bs.module ("pixi.js", "PIXI")];
    /*
     A reference to the current renderer
     */
    external renderer : t => T.webGLRenderer = "" [@@bs.get];
    /*
     A reference to the current renderer
     */
    external setRenderer : t => T.webGLRenderer => unit = "renderer" [@@bs.set];
    /*
     The current WebGL rendering context
     */
    external gl : t => ReasonJs.Gl.glT = "" [@@bs.get];
    /*
     The current WebGL rendering context
     */
    external setGl : t => ReasonJs.Gl.glT => unit = "gl" [@@bs.set];
    /*
     Binds a texture.
     */
    external bindTexture : unit = "" [@@bs.send.pipe : t];
    /*
     Gets a texture.
     */
    external getTexture : unit = "" [@@bs.send.pipe : t];
    /*
     Updates and/or Creates a WebGL texture for the renderer's context.
     */
    external updateTexture :
      texture::unit /* unknown js type: PIXI.BaseTexture|PIXI.Texture */ => location::float => unit /* unknown js type: GLTexture */ =
      "" [@@bs.send.pipe : t];
    /*
     Deletes the texture from WebGL
     */
    external destroyTexture :
      texture::unit /* unknown js type: PIXI.BaseTexture|PIXI.Texture */ =>
      skipRemove::Js.boolean? =>
      unit =
      "" [@@bs.send.pipe : t];
    /*
     Deletes all the textures from WebGL
     */
    external removeAll : unit = "" [@@bs.send.pipe : t];
    /*
     Destroys this manager and removes all its textures
     */
    external destroy : unit = "" [@@bs.send.pipe : t];
  };
  module WebGLRenderer = {
    /*
     The WebGLRenderer draws the scene and all its content onto a webGL enabled canvas. This renderer
     should be used for browsers that support webGL. This Render works by automatically managing webGLBatchs.
     So no need for Sprite Batches or Sprite Clouds.
     Don't forget to add the view to your DOM or you will not see anything :)
     */
    type t = T.webGLRenderer;
    type createOptions;
    /*
     The optional renderer parameters
     */
    external mkCreateOptions :
      width::float? =>
      height::float? =>
      view::Dom.element? =>
      transparent::Js.boolean? =>
      autoResize::Js.boolean? =>
      antialias::Js.boolean? =>
      forceFXAA::Js.boolean? =>
      resolution::float? =>
      clearBeforeRender::Js.boolean? =>
      preserveDrawingBuffer::Js.boolean? =>
      roundPixels::Js.boolean? =>
      backgroundColor::float? =>
      legacy::Js.boolean? =>
      unit =>
      createOptions =
      "" [@@bs.obj];
    external create : options::createOptions? => unit => t =
      "WebGLRenderer" [@@bs.new] [@@bs.module ("pixi.js", "PIXI")];
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
    external maskManager : t => T.maskManager = "" [@@bs.get];
    /*
     Manages the masks using the stencil buffer.
     */
    external setMaskManager : t => T.maskManager => unit = "maskManager" [@@bs.set];
    /*
     Manages the stencil buffer.
     */
    external stencilManager : t => T.stencilManager = "" [@@bs.get];
    /*
     Manages the stencil buffer.
     */
    external setStencilManager : t => T.stencilManager => unit = "stencilManager" [@@bs.set];
    /*
     An empty renderer.
     */
    external emptyRenderer : t => T.objectRenderer = "" [@@bs.get];
    /*
     An empty renderer.
     */
    external setEmptyRenderer : t => T.objectRenderer => unit = "emptyRenderer" [@@bs.set];
    /*
     The currently active ObjectRenderer.
     */
    external currentRenderer : t => T.objectRenderer = "" [@@bs.get];
    /*
     The currently active ObjectRenderer.
     */
    external setCurrentRenderer : t => T.objectRenderer => unit = "currentRenderer" [@@bs.set];
    /*
     The currently active ObjectRenderer.
     */
    external state : t => T.webGLState = "" [@@bs.get];
    /*
     The currently active ObjectRenderer.
     */
    external setState : t => T.webGLState => unit = "state" [@@bs.set];
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
    external _activeShader : t => T.shader = "" [@@bs.get];
    /*
     Holds the current shader
     */
    external set_activeShader : t => T.shader => unit = "_activeShader" [@@bs.set];
    /*
     Holds the current render target
     */
    external _activeRenderTarget : t => T.renderTarget = "" [@@bs.get];
    /*
     Holds the current render target
     */
    external set_activeRenderTarget : t => T.renderTarget => unit =
      "_activeRenderTarget" [@@bs.set];
    /*
     Manages the filters.
     */
    external filterManager : t => T.filterManager = "" [@@bs.get];
    /*
     Manages the filters.
     */
    external setFilterManager : t => T.filterManager => unit = "filterManager" [@@bs.set];
    /*
     Collection of installed plugins. These are included by default in PIXI, but can be excluded
     by creating a custom build. Consult the README for more information about creating custom
     builds and excluding plugins.
     */
    external plugins : t => unit /* unknown js type: object */ = "" [@@bs.get];
    /*
     Collection of methods for extracting data (image, pixels, etc.) from a display object or render texture
     */
    external extract : t => T.webGLExtract = "" [@@bs.get];
    /*
     Collection of methods for extracting data (image, pixels, etc.) from a display object or render texture
     */
    external setExtract : t => T.webGLExtract => unit = "extract" [@@bs.set];
    /*
     The supplied constructor options.
     */
    external options : t => unit /* unknown js type: Object */ = "" [@@bs.get];
    /*
     Measurements of the screen. (0, 0, screenWidth, screenHeight)

     Its safe to use as filterArea or hitArea for whole stage
     */
    external screen : t => T.rectangle = "" [@@bs.get];
    /*
     Measurements of the screen. (0, 0, screenWidth, screenHeight)

     Its safe to use as filterArea or hitArea for whole stage
     */
    external setScreen : t => T.rectangle => unit = "screen" [@@bs.set];
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
    external setPreserveDrawingBuffer : t => Js.boolean => unit =
      "preserveDrawingBuffer" [@@bs.set];
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
    /*
     Renders the object to its webGL view
     */
    external render :
      displayObject::T.displayObject =>
      renderTexture::T.renderTexture =>
      clear::Js.boolean? =>
      transform::T.transform? =>
      skipUpdateTransform::Js.boolean? =>
      unit =
      "" [@@bs.send.pipe : t];
    /*
     Changes the current renderer to the one given in parameter
     */
    external setObjectRenderer : objectRenderer::T.objectRenderer => unit =
      "" [@@bs.send.pipe : t];
    /*
     This should be called if you wish to do some custom rendering
     It will basically render anything that may be batched up such as sprites
     */
    external flush : unit = "" [@@bs.send.pipe : t];
    /*
     Resizes the webGL view to the specified width and height.
     */
    external resize : screenWidth::float => screenHeight::float => unit = "" [@@bs.send.pipe : t];
    /*
     Resizes the webGL view to the specified width and height.
     */
    external setBlendMode : blendMode::float => unit = "" [@@bs.send.pipe : t];
    /*
     Erases the active render target and fills the drawing area with a colour
     */
    external clear : clearColor::float? => unit = "" [@@bs.send.pipe : t];
    /*
     Sets the transform of the active render target to the given matrix
     */
    external setTransform : matrix::T.matrix => unit = "" [@@bs.send.pipe : t];
    /*
     Erases the render texture and fills the drawing area with a colour
     */
    external clearRenderTexture :
      renderTexture::T.renderTexture => clearColor::float? => T.webGLRenderer =
      "" [@@bs.send.pipe : t];
    /*
     Binds a render texture for rendering
     */
    external bindRenderTexture :
      renderTexture::T.renderTexture => transform::T.transform => T.webGLRenderer =
      "" [@@bs.send.pipe : t];
    /*
     Changes the current render target to the one given in parameter
     */
    external bindRenderTarget : renderTarget::T.renderTarget => T.webGLRenderer =
      "" [@@bs.send.pipe : t];
    /*
     Changes the current shader to the one given in parameter
     */
    external bindShader : shader::T.shader => autoProject::Js.boolean? => T.webGLRenderer =
      "" [@@bs.send.pipe : t];
    /*
     Binds the texture. This will return the location of the bound texture.
     It may not be the same as the one you pass in. This is due to optimisation that prevents
     needless binding of textures. For example if the texture is already bound it will return the
     current location of the texture instead of the one provided. To bypass this use force location
     */
    external bindTexture :
      texture::T.texture => location::float => forceLocation::Js.boolean => float =
      "" [@@bs.send.pipe : t];
    /*
     unbinds the texture ...
     */
    external unbindTexture : texture::T.texture => T.webGLRenderer = "" [@@bs.send.pipe : t];
    /*
     Creates a new VAO from this renderer's context and state.
     */
    external createVao : unit /* unknown js type: VertexArrayObject */ = "" [@@bs.send.pipe : t];
    /*
     Changes the current Vao to the one given in parameter
     */
    external bindVao : vao::unit /* unknown js type: PIXI.VertexArrayObject */ => T.webGLRenderer =
      "" [@@bs.send.pipe : t];
    /*
     Resets the WebGL state so you can render things however you fancy!
     */
    external reset : T.webGLRenderer = "" [@@bs.send.pipe : t];
    /*
     Removes everything from the renderer (event listeners, spritebatch, etc...)
     */
    external destroy : removeView::Js.boolean? => unit = "" [@@bs.send.pipe : t];
    /*
     Adds a plugin to the renderer.
     */
    external registerPlugin :
      pluginName::string => ctor::unit /* unknown js type: function */ => unit =
      "" [@@bs.send.pipe : t];
    /*
     Useful function that returns a texture of the display object that can then be used to create sprites
     This can be quite useful if your displayObject is complicated and needs to be reused multiple times.
     */
    external generateTexture :
      displayObject::T.displayObject => scaleMode::float => resolution::float => T.texture =
      "" [@@bs.send.pipe : t];
  };
  module WebGLState = {
    /*
     A WebGL state machines
     */
    type t = T.webGLState;
    external create : gl::ReasonJs.Gl.glT => unit => t =
      "WebGLState" [@@bs.new] [@@bs.module ("pixi.js", "PIXI")];
    /*
     The current active state
     */
    external activeState : t => Js_typed_array.Uint8Array.t = "" [@@bs.get];
    /*
     The current active state
     */
    external setActiveState : t => Js_typed_array.Uint8Array.t => unit = "activeState" [@@bs.set];
    /*
     The default state
     */
    external defaultState : t => Js_typed_array.Uint8Array.t = "" [@@bs.get];
    /*
     The default state
     */
    external setDefaultState : t => Js_typed_array.Uint8Array.t => unit =
      "defaultState" [@@bs.set];
    /*
     The current WebGL rendering context
     */
    external gl : t => ReasonJs.Gl.glT = "" [@@bs.get];
    /*
     The current WebGL rendering context
     */
    external setGl : t => ReasonJs.Gl.glT => unit = "gl" [@@bs.set];
    /*
     Pushes a new active state
     */
    external push : unit = "" [@@bs.send.pipe : t];
    /*
     Pops a state out
     */
    external pop : unit = "" [@@bs.send.pipe : t];
    /*
     Sets the current state
     */
    external setState : state::unit /* unknown js type: * */ => unit = "" [@@bs.send.pipe : t];
    /*
     Enables or disabled blending.
     */
    external setBlend : value::Js.boolean => unit = "" [@@bs.send.pipe : t];
    /*
     Sets the blend mode.
     */
    external setBlendMode : value::float => unit = "" [@@bs.send.pipe : t];
    /*
     Sets whether to enable or disable depth test.
     */
    external setDepthTest : value::Js.boolean => unit = "" [@@bs.send.pipe : t];
    /*
     Sets whether to enable or disable cull face.
     */
    external setCullFace : value::Js.boolean => unit = "" [@@bs.send.pipe : t];
    /*
     Sets the gl front face.
     */
    external setFrontFace : value::Js.boolean => unit = "" [@@bs.send.pipe : t];
    /*
     Disables all the vaos in use
     */
    external resetAttributes : unit = "" [@@bs.send.pipe : t];
    /*
     Resets all the logic and disables the vaos
     */
    external resetToDefault : unit = "" [@@bs.send.pipe : t];
  };
  module Filter = {
    type t = T.filter;
    external create :
      vertexSrc::string? =>
      fragmentSrc::string? =>
      uniforms::unit /* unknown js type: object */? =>
      unit =>
      t =
      "Filter" [@@bs.new] [@@bs.module ("pixi.js", "PIXI")];
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
    /*
     Applies the filter
     */
    external apply :
      filterManager::T.filterManager =>
      input::T.renderTarget =>
      output::T.renderTarget =>
      clear::Js.boolean =>
      currentState::unit /* unknown js type: object */? =>
      unit =
      "" [@@bs.send.pipe : t];
  };
  module SpriteMaskFilter = {
    /*
     The SpriteMaskFilter class
     */
    type t = T.spriteMaskFilter;
    external create : sprite::T.sprite => unit => t =
      "SpriteMaskFilter" [@@bs.new] [@@bs.module ("pixi.js", "PIXI")];
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
    /*
     Applies the filter
     */
    external apply :
      filterManager::T.filterManager => input::T.renderTarget => output::T.renderTarget => unit =
      "" [@@bs.send.pipe : t];
  };
  module BlendModeManager = {
    type t = T.blendModeManager;
    external create : renderer::T.webGLRenderer => unit => t =
      "BlendModeManager" [@@bs.new] [@@bs.module ("pixi.js", "PIXI")];
    external currentBlendMode : t => float = "" [@@bs.get];
    external setCurrentBlendMode : t => float => unit = "currentBlendMode" [@@bs.set];
    /*
     The renderer this manager works for.
     */
    external renderer : t => T.webGLRenderer = "" [@@bs.get];
    /*
     The renderer this manager works for.
     */
    external setRenderer : t => T.webGLRenderer => unit = "renderer" [@@bs.set];
    /*
     Sets-up the given blendMode from WebGL's point of view.
     */
    external setBlendMode : blendMode::float => Js.boolean = "" [@@bs.send.pipe : t];
    /*
     Generic method called when there is a WebGL context change.
     */
    external onContextChange : unit = "" [@@bs.send.pipe : t];
    /*
     Generic destroy methods to be overridden by the subclass
     */
    external destroy : unit = "" [@@bs.send.pipe : t];
  };
  module FilterManager = {
    type t = T.filterManager;
    external create : renderer::T.webGLRenderer => unit => t =
      "FilterManager" [@@bs.new] [@@bs.module ("pixi.js", "PIXI")];
    /*
     The renderer this manager works for.
     */
    external renderer : t => T.webGLRenderer = "" [@@bs.get];
    /*
     The renderer this manager works for.
     */
    external setRenderer : t => T.webGLRenderer => unit = "renderer" [@@bs.set];
    /*
     Adds a new filter to the manager.
     */
    external pushFilter : target::T.displayObject => filters::array T.filter => unit =
      "" [@@bs.send.pipe : t];
    /*
     Pops off the filter and applies it.
     */
    external popFilter : unit = "" [@@bs.send.pipe : t];
    /*
     Draws a filter.
     */
    external applyFilter :
      filter::T.filter =>
      input::T.renderTarget =>
      output::T.renderTarget =>
      clear::Js.boolean =>
      unit =
      "" [@@bs.send.pipe : t];
    /*
     Uploads the uniforms of the filter.
     */
    external syncUniforms :
      shader::unit /* unknown js type: GLShader */ => filter::T.filter => unit =
      "" [@@bs.send.pipe : t];
    /*
     Gets a render target from the pool, or creates a new one.
     */
    external getRenderTarget : clear::Js.boolean => resolution::float => T.renderTarget =
      "" [@@bs.send.pipe : t];
    /*
     Returns a render target to the pool.
     */
    external returnRenderTarget : renderTarget::T.renderTarget => unit = "" [@@bs.send.pipe : t];
    /*
     Calculates the mapped matrix.

     TODO playing around here.. this is temporary - (will end up in the shader)
     this returns a matrix that will normalise map filter cords in the filter to screen space
     */
    external calculateScreenSpaceMatrix : outputMatrix::T.matrix => T.matrix =
      "" [@@bs.send.pipe : t];
    /*
     Multiply vTextureCoord to this matrix to achieve (0,0,1,1) for filterArea
     */
    external calculateNormalizedScreenSpaceMatrix : outputMatrix::T.matrix => T.matrix =
      "" [@@bs.send.pipe : t];
    /*
     This will map the filter coord so that a texture can be used based on the transform of a sprite
     */
    external calculateSpriteMatrix : outputMatrix::T.matrix => sprite::T.sprite => T.matrix =
      "" [@@bs.send.pipe : t];
    /*
     Destroys this Filter Manager.
     */
    external destroy : unit = "" [@@bs.send.pipe : t];
    /*
     Empties the texture pool.
     */
    external emptyPool : unit = "" [@@bs.send.pipe : t];
    /*
     Frees a render target back into the pool.
     */
    external freePotRenderTarget : renderTarget::T.renderTarget => unit = "" [@@bs.send.pipe : t];
    /*
     Generic method called when there is a WebGL context change.
     */
    external onContextChange : unit = "" [@@bs.send.pipe : t];
  };
  module MaskManager = {
    type t = T.maskManager;
    external create : renderer::T.webGLRenderer => unit => t =
      "MaskManager" [@@bs.new] [@@bs.module ("pixi.js", "PIXI")];
    /*
     The renderer this manager works for.
     */
    external renderer : t => T.webGLRenderer = "" [@@bs.get];
    /*
     The renderer this manager works for.
     */
    external setRenderer : t => T.webGLRenderer => unit = "renderer" [@@bs.set];
    /*
     Applies the Mask and adds it to the current filter stack.
     */
    external pushMask :
      target::T.displayObject =>
      maskData::unit /* unknown js type: PIXI.Sprite|PIXI.Graphics */ =>
      unit =
      "" [@@bs.send.pipe : t];
    /*
     Removes the last mask from the mask stack and doesn't return it.
     */
    external popMask :
      target::T.displayObject =>
      maskData::unit /* unknown js type: PIXI.Sprite|PIXI.Graphics */ =>
      unit =
      "" [@@bs.send.pipe : t];
    /*
     Applies the Mask and adds it to the current filter stack.
     */
    external pushSpriteMask : target::T.renderTarget => maskData::T.sprite => unit =
      "" [@@bs.send.pipe : t];
    /*
     Removes the last filter from the filter stack and doesn't return it.
     */
    external popSpriteMask : unit = "" [@@bs.send.pipe : t];
    /*
     Applies the Mask and adds it to the current filter stack.
     */
    external pushStencilMask :
      maskData::unit /* unknown js type: PIXI.Sprite|PIXI.Graphics */ => unit =
      "" [@@bs.send.pipe : t];
    /*
     Removes the last filter from the filter stack and doesn't return it.
     */
    external popStencilMask : unit = "" [@@bs.send.pipe : t];
    external pushScissorMask : target::T.displayObject => maskData::T.graphics => unit =
      "" [@@bs.send.pipe : t];
    external popScissorMask : unit = "" [@@bs.send.pipe : t];
    /*
     Generic method called when there is a WebGL context change.
     */
    external onContextChange : unit = "" [@@bs.send.pipe : t];
    /*
     Generic destroy methods to be overridden by the subclass
     */
    external destroy : unit = "" [@@bs.send.pipe : t];
  };
  module StencilManager = {
    type t = T.stencilManager;
    external create : renderer::T.webGLRenderer => unit => t =
      "StencilManager" [@@bs.new] [@@bs.module ("pixi.js", "PIXI")];
    /*
     The renderer this manager works for.
     */
    external renderer : t => T.webGLRenderer = "" [@@bs.get];
    /*
     The renderer this manager works for.
     */
    external setRenderer : t => T.webGLRenderer => unit = "renderer" [@@bs.set];
    /*
     Changes the mask stack that is used by this manager.
     */
    external setMaskStack : stencilMaskStack::array T.graphics => unit = "" [@@bs.send.pipe : t];
    /*
     Applies the Mask and adds it to the current filter stack. @alvin
     */
    external pushStencil : graphics::T.graphics => unit = "" [@@bs.send.pipe : t];
    /*
     TODO @alvin
     */
    external popStencil : unit = "" [@@bs.send.pipe : t];
    /*
     Destroys the mask stack.
     */
    external destroy : unit = "" [@@bs.send.pipe : t];
    /*
     Generic method called when there is a WebGL context change.
     */
    external onContextChange : unit = "" [@@bs.send.pipe : t];
  };
  module WebGLManager = {
    type t = T.webGLManager;
    external create : renderer::T.webGLRenderer => unit => t =
      "WebGLManager" [@@bs.new] [@@bs.module ("pixi.js", "PIXI")];
    /*
     The renderer this manager works for.
     */
    external renderer : t => T.webGLRenderer = "" [@@bs.get];
    /*
     The renderer this manager works for.
     */
    external setRenderer : t => T.webGLRenderer => unit = "renderer" [@@bs.set];
    /*
     Generic method called when there is a WebGL context change.
     */
    external onContextChange : unit = "" [@@bs.send.pipe : t];
    /*
     Generic destroy methods to be overridden by the subclass
     */
    external destroy : unit = "" [@@bs.send.pipe : t];
  };
  module ObjectRenderer = {
    /*
     Base for a common object renderer that can be used as a system renderer plugin.
     */
    type t = T.objectRenderer;
    external create : unit => t = "ObjectRenderer" [@@bs.new] [@@bs.module ("pixi.js", "PIXI")];
    /*
     The renderer this manager works for.
     */
    external renderer : t => T.webGLRenderer = "" [@@bs.get];
    /*
     The renderer this manager works for.
     */
    external setRenderer : t => T.webGLRenderer => unit = "renderer" [@@bs.set];
    /*
     Starts the renderer and sets the shader
     */
    external start : unit = "" [@@bs.send.pipe : t];
    /*
     Stops the renderer
     */
    external stop : unit = "" [@@bs.send.pipe : t];
    /*
     Stub method for rendering content and emptying the current batch.
     */
    external flush : unit = "" [@@bs.send.pipe : t];
    /*
     Renders an object
     */
    external render : object::T.displayObject => unit = "" [@@bs.send.pipe : t];
    /*
     Generic method called when there is a WebGL context change.
     */
    external onContextChange : unit = "" [@@bs.send.pipe : t];
    /*
     Generic destroy methods to be overridden by the subclass
     */
    external destroy : unit = "" [@@bs.send.pipe : t];
  };
  module Quad = {
    /*
     Helper class to create a quad
     */
    type t = T.quad;
    external create : gl::ReasonJs.Gl.glT => state::unit /* unknown js type: object */ => unit => t =
      "Quad" [@@bs.new] [@@bs.module ("pixi.js", "PIXI")];
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
    external vertices : t => Js_typed_array.Float32Array.t = "" [@@bs.get];
    /*
     An array of vertices
     */
    external setVertices : t => Js_typed_array.Float32Array.t => unit = "vertices" [@@bs.set];
    /*
     The Uvs of the quad
     */
    external uvs : t => Js_typed_array.Float32Array.t = "" [@@bs.get];
    /*
     The Uvs of the quad
     */
    external setUvs : t => Js_typed_array.Float32Array.t => unit = "uvs" [@@bs.set];
    /*
     An array containing the indices of the vertices
     */
    external indices : t => Js_typed_array.Uint16Array.t = "" [@@bs.get];
    /*
     An array containing the indices of the vertices
     */
    external setIndices : t => Js_typed_array.Uint16Array.t => unit = "indices" [@@bs.set];
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
    /*
     Initialises the vaos and uses the shader.
     */
    external initVao : shader::T.shader => unit = "" [@@bs.send.pipe : t];
    /*
     Maps two Rectangle to the quad.
     */
    external map : targetTextureFrame::T.rectangle => destinationFrame::T.rectangle => T.quad =
      "" [@@bs.send.pipe : t];
    /*
     Binds the buffer and uploads the data
     */
    external upload : T.quad = "" [@@bs.send.pipe : t];
    /*
     Removes this quad from WebGL
     */
    external destroy : unit = "" [@@bs.send.pipe : t];
  };
  module RenderTarget = {
    type t = T.renderTarget;
    external create :
      gl::ReasonJs.Gl.glT =>
      width::float? =>
      height::float? =>
      scaleMode::float? =>
      resolution::float? =>
      root::Js.boolean? =>
      unit =>
      t =
      "RenderTarget" [@@bs.new] [@@bs.module ("pixi.js", "PIXI")];
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
    external size : t => T.rectangle = "" [@@bs.get];
    /*
     The size of the object as a rectangle
     */
    external setSize : t => T.rectangle => unit = "size" [@@bs.set];
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
    external projectionMatrix : t => T.matrix = "" [@@bs.get];
    /*
     The projection matrix
     */
    external setProjectionMatrix : t => T.matrix => unit = "projectionMatrix" [@@bs.set];
    /*
     The object's transform
     */
    external transform : t => T.matrix = "" [@@bs.get];
    /*
     The object's transform
     */
    external setTransform : t => T.matrix => unit = "transform" [@@bs.set];
    /*
     The frame.
     */
    external frame : t => T.rectangle = "" [@@bs.get];
    /*
     The frame.
     */
    external setFrame : t => T.rectangle => unit = "frame" [@@bs.set];
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
    external stencilMaskStack : t => array T.graphics = "" [@@bs.get];
    /*
     The data structure for the stencil masks
     */
    external setStencilMaskStack : t => array T.graphics => unit = "stencilMaskStack" [@@bs.set];
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
    /*
     Clears the filter texture.
     */
    external clear : clearColor::array float? => unit = "" [@@bs.send.pipe : t];
    /*
     Binds the stencil buffer.
     */
    external attachStencilBuffer : unit = "" [@@bs.send.pipe : t];
    /*
     Sets the frame of the render target.
     */
    external setFrame : destinationFrame::T.rectangle => sourceFrame::T.rectangle => unit =
      "" [@@bs.send.pipe : t];
    /*
     Binds the buffers and initialises the viewport.
     */
    external activate : unit = "" [@@bs.send.pipe : t];
    /*
     Updates the projection matrix based on a projection frame (which is a rectangle)
     */
    external calculateProjection :
      destinationFrame::T.rectangle => sourceFrame::T.rectangle => unit =
      "" [@@bs.send.pipe : t];
    /*
     Resizes the texture to the specified width and height
     */
    external resize : width::float => height::float => unit = "" [@@bs.send.pipe : t];
    /*
     Destroys the render target.
     */
    external destroy : unit = "" [@@bs.send.pipe : t];
  };
  module Sprite = {
    /*
     The Sprite object is the base for all textured objects that are rendered to the screen

     A sprite can be created directly from an image like this:

     <pre class="prettyprint source lang-js"><code>let sprite = new PIXI.Sprite.fromImage('assets/image.png');</code></pre>
     */
    type t = T.sprite;
    external create : texture::T.texture => unit => t =
      "Sprite" [@@bs.new] [@@bs.module ("pixi.js", "PIXI")];
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
    external anchor : t => T.observablePoint = "" [@@bs.get];
    /*
     The anchor sets the origin point of the texture.
     The default is 0,0 this means the texture's origin is the top left
     Setting the anchor to 0.5,0.5 means the texture's origin is centered
     Setting the anchor to 1,1 would mean the texture's origin point will be the bottom right corner
     */
    external setAnchor : t => T.observablePoint => unit = "anchor" [@@bs.set];
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
    external texture : t => T.texture = "" [@@bs.get];
    /*
     The texture that the sprite is using
     */
    external setTexture : t => T.texture => unit = "texture" [@@bs.set];
    /*
     The array of children of this container.
     */
    external children : t => array T.displayObject = "" [@@bs.get];
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
    external transform : t => T.transformBase = "" [@@bs.get];
    /*
     World transform and local transform of this object.
     This will become read-only later, please do not assign anything there unless you know what are you doing
     */
    external setTransform : t => T.transformBase => unit = "transform" [@@bs.set];
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
    external parent : t => T.container = "" [@@bs.get];
    /*
     The multiplied alpha of the displayObject
     */
    external worldAlpha : t => float = "" [@@bs.get];
    /*
     The area the filter is applied to. This is used as more of an optimisation
     rather than figuring out the dimensions of the displayObject each frame you can set this rectangle

     Also works as an interaction mask
     */
    external filterArea : t => T.rectangle = "" [@@bs.get];
    /*
     The area the filter is applied to. This is used as more of an optimisation
     rather than figuring out the dimensions of the displayObject each frame you can set this rectangle

     Also works as an interaction mask
     */
    external setFilterArea : t => T.rectangle => unit = "filterArea" [@@bs.set];
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
    external worldTransform : t => T.matrix = "" [@@bs.get];
    /*
     Current transform of the object based on local factors: position, scale, other stuff
     */
    external localTransform : t => T.matrix = "" [@@bs.get];
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
    external skew : t => T.observablePoint = "" [@@bs.get];
    /*
     The skew factor for the object in radians.
     Assignment by value since pixi-v4.
     */
    external setSkew : t => T.observablePoint => unit = "skew" [@@bs.set];
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
    external filters : t => array T.filter = "" [@@bs.get];
    /*
     Sets the filters for the displayObject.

     <ul>
     <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
     To remove filters simply set this property to 'null'</li>
     </ul>
     */
    external setFilters : t => array T.filter => unit = "filters" [@@bs.set];
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
    /*
     calculates worldTransform * vertices, store it in vertexData
     */
    external calculateVertices : unit = "" [@@bs.send.pipe : t];
    /*
     calculates worldTransform * vertices for a non texture with a trim. store it in vertexTrimmedData
     This is used to ensure that the true width and height of a trimmed texture is respected
     */
    external calculateTrimmedVertices : unit = "" [@@bs.send.pipe : t];
    /*
     Gets the local bounds of the sprite object.
     */
    external getLocalBounds : rect::T.rectangle => T.rectangle = "" [@@bs.send.pipe : t];
    /*
     Tests if a point is inside this sprite
     */
    external containsPoint : point::T.point => Js.boolean = "" [@@bs.send.pipe : t];
    /*
     Destroys this sprite and optionally its texture and children
     */
    external destroy : options::unit /* unknown js type: object|boolean */? => unit =
      "" [@@bs.send.pipe : t];
    /*
     Adds one or more children to the container.

     <p>Multiple items can be added like so: <code>myContainer.addChild(thingOne, thingTwo, thingThree)</code></p>
     */
    external addChild : child::T.displayObject => T.displayObject = "" [@@bs.send.pipe : t];
    /*
     Adds a child to the container at a specified index. If the index is out of bounds an error will be thrown
     */
    external addChildAt : child::T.displayObject => index::float => T.displayObject =
      "" [@@bs.send.pipe : t];
    /*
     Swaps the position of 2 Display Objects within this container.
     */
    external swapChildren : child::T.displayObject => child2::T.displayObject => unit =
      "" [@@bs.send.pipe : t];
    /*
     Returns the index position of a child DisplayObject instance
     */
    external getChildIndex : child::T.displayObject => float = "" [@@bs.send.pipe : t];
    /*
     Changes the position of an existing child in the display object container
     */
    external setChildIndex : child::T.displayObject => index::float => unit =
      "" [@@bs.send.pipe : t];
    /*
     Returns the child at the specified index
     */
    external getChildAt : index::float => T.displayObject = "" [@@bs.send.pipe : t];
    /*
     Removes one or more children from the container.
     */
    external removeChild : child::T.displayObject => T.displayObject = "" [@@bs.send.pipe : t];
    /*
     Removes a child from the specified index position.
     */
    external removeChildAt : index::float => T.displayObject = "" [@@bs.send.pipe : t];
    /*
     Removes all children from this container that are within the begin and end indexes.
     */
    external removeChildren : beginIndex::float? => endIndex::float? => array T.displayObject =
      "" [@@bs.send.pipe : t];
    /*
     Updates the transform on all children of this container for rendering
     */
    external updateTransform : unit = "" [@@bs.send.pipe : t];
    /*
     Recalculates the bounds of the container.
     */
    external calculateBounds : unit = "" [@@bs.send.pipe : t];
    /*
     Renders the object using the WebGL renderer
     */
    external renderWebGL : renderer::T.webGLRenderer => unit = "" [@@bs.send.pipe : t];
    /*
     Renders the object using the Canvas renderer
     */
    external renderCanvas : renderer::T.canvasRenderer => unit = "" [@@bs.send.pipe : t];
    /*
     recursively updates transform of all objects from the root to this one
     internal function for toLocal()
     */
    external _recursivePostUpdateTransform : unit = "" [@@bs.send.pipe : t];
    /*
     Retrieves the bounds of the displayObject as a rectangle object.
     */
    external getBounds : skipUpdate::Js.boolean => rect::T.rectangle => T.rectangle =
      "" [@@bs.send.pipe : t];
    /*
     Calculates the global position of the display object
     */
    external toGlobal : position::T.point => point::T.point? => skipUpdate::Js.boolean? => T.point =
      "" [@@bs.send.pipe : t];
    /*
     Calculates the local position of the display object relative to another point
     */
    external toLocal :
      position::T.point =>
      from::T.displayObject? =>
      point::T.point? =>
      skipUpdate::Js.boolean? =>
      T.point =
      "" [@@bs.send.pipe : t];
    /*
     Set the parent Container of this DisplayObject
     */
    external setParent : container::T.container => T.container = "" [@@bs.send.pipe : t];
    /*
     Convenience function to set the position, scale, skew and pivot at once.
     */
    external setTransform :
      x::float? =>
      y::float? =>
      scaleX::float? =>
      scaleY::float? =>
      rotation::float? =>
      skewX::float? =>
      skewY::float? =>
      pivotX::float? =>
      pivotY::float? =>
      T.displayObject =
      "" [@@bs.send.pipe : t];
  };
  module CanvasTinter = {
    type t = T.canvasTinter;
    external create : unit => t = "CanvasTinter" [@@bs.new] [@@bs.module ("pixi.js", "PIXI")];
  };
  module Buffer = {
    type t = T.buffer;
    external create : size::float => unit => t =
      "Buffer" [@@bs.new] [@@bs.module ("pixi.js", "PIXI")];
    /*
     View on the vertices as a Float32Array for positions
     */
    external float32View : t => Js_typed_array.Float32Array.t = "" [@@bs.get];
    /*
     View on the vertices as a Float32Array for positions
     */
    external setFloat32View : t => Js_typed_array.Float32Array.t => unit =
      "float32View" [@@bs.set];
    /*
     View on the vertices as a Uint32Array for uvs
     */
    external uint32View : t => Js_typed_array.Float32Array.t = "" [@@bs.get];
    /*
     View on the vertices as a Uint32Array for uvs
     */
    external setUint32View : t => Js_typed_array.Float32Array.t => unit = "uint32View" [@@bs.set];
    /*
     Destroys the buffer.
     */
    external destroy : unit = "" [@@bs.send.pipe : t];
  };
  module Text = {
    /*
     A Text Object will create a line or multiple lines of text. To split a line you can use '\n' in your text string,
     or add a wordWrap property set to true and and wordWrapWidth property with a value in the style object.

     A Text can be created directly from a string and a style object

     <pre class="prettyprint source lang-js"><code>let text = new PIXI.Text('This is a pixi text',{fontFamily : 'Arial', fontSize: 24, fill : 0xff1010, align : 'center'});</code></pre>
     */
    type t = T.text;
    external create :
      text::string =>
      style::unit /* unknown js type: object|PIXI.TextStyle */? =>
      canvas::Dom.element? =>
      unit =>
      t =
      "Text" [@@bs.new] [@@bs.module ("pixi.js", "PIXI")];
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
    external anchor : t => T.observablePoint = "" [@@bs.get];
    /*
     The anchor sets the origin point of the texture.
     The default is 0,0 this means the texture's origin is the top left
     Setting the anchor to 0.5,0.5 means the texture's origin is centered
     Setting the anchor to 1,1 would mean the texture's origin point will be the bottom right corner
     */
    external setAnchor : t => T.observablePoint => unit = "anchor" [@@bs.set];
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
    external texture : t => T.texture = "" [@@bs.get];
    /*
     The texture that the sprite is using
     */
    external setTexture : t => T.texture => unit = "texture" [@@bs.set];
    /*
     The array of children of this container.
     */
    external children : t => array T.displayObject = "" [@@bs.get];
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
    external transform : t => T.transformBase = "" [@@bs.get];
    /*
     World transform and local transform of this object.
     This will become read-only later, please do not assign anything there unless you know what are you doing
     */
    external setTransform : t => T.transformBase => unit = "transform" [@@bs.set];
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
    external parent : t => T.container = "" [@@bs.get];
    /*
     The multiplied alpha of the displayObject
     */
    external worldAlpha : t => float = "" [@@bs.get];
    /*
     The area the filter is applied to. This is used as more of an optimisation
     rather than figuring out the dimensions of the displayObject each frame you can set this rectangle

     Also works as an interaction mask
     */
    external filterArea : t => T.rectangle = "" [@@bs.get];
    /*
     The area the filter is applied to. This is used as more of an optimisation
     rather than figuring out the dimensions of the displayObject each frame you can set this rectangle

     Also works as an interaction mask
     */
    external setFilterArea : t => T.rectangle => unit = "filterArea" [@@bs.set];
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
    external worldTransform : t => T.matrix = "" [@@bs.get];
    /*
     Current transform of the object based on local factors: position, scale, other stuff
     */
    external localTransform : t => T.matrix = "" [@@bs.get];
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
    external skew : t => T.observablePoint = "" [@@bs.get];
    /*
     The skew factor for the object in radians.
     Assignment by value since pixi-v4.
     */
    external setSkew : t => T.observablePoint => unit = "skew" [@@bs.set];
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
    external filters : t => array T.filter = "" [@@bs.get];
    /*
     Sets the filters for the displayObject.

     <ul>
     <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
     To remove filters simply set this property to 'null'</li>
     </ul>
     */
    external setFilters : t => array T.filter => unit = "filters" [@@bs.set];
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
    /*
     Renders the object using the WebGL renderer
     */
    external renderWebGL : renderer::T.webGLRenderer => unit = "" [@@bs.send.pipe : t];
    /*
     Gets the local bounds of the text object.
     */
    external getLocalBounds : rect::T.rectangle => T.rectangle = "" [@@bs.send.pipe : t];
    /*
     calculates the bounds of the Text as a rectangle. The bounds calculation takes the worldTransform into account.
     */
    external _calculateBounds : unit = "" [@@bs.send.pipe : t];
    /*
     Destroys this text object.
     Note* Unlike a Sprite, a Text object will automatically destroy its baseTexture and texture as
     the majority of the time the texture will not be shared with any other Sprites.
     */
    external destroy : options::unit /* unknown js type: object|boolean */? => unit =
      "" [@@bs.send.pipe : t];
    /*
     calculates worldTransform * vertices, store it in vertexData
     */
    external calculateVertices : unit = "" [@@bs.send.pipe : t];
    /*
     calculates worldTransform * vertices for a non texture with a trim. store it in vertexTrimmedData
     This is used to ensure that the true width and height of a trimmed texture is respected
     */
    external calculateTrimmedVertices : unit = "" [@@bs.send.pipe : t];
    /*
     Tests if a point is inside this sprite
     */
    external containsPoint : point::T.point => Js.boolean = "" [@@bs.send.pipe : t];
    /*
     Adds one or more children to the container.

     <p>Multiple items can be added like so: <code>myContainer.addChild(thingOne, thingTwo, thingThree)</code></p>
     */
    external addChild : child::T.displayObject => T.displayObject = "" [@@bs.send.pipe : t];
    /*
     Adds a child to the container at a specified index. If the index is out of bounds an error will be thrown
     */
    external addChildAt : child::T.displayObject => index::float => T.displayObject =
      "" [@@bs.send.pipe : t];
    /*
     Swaps the position of 2 Display Objects within this container.
     */
    external swapChildren : child::T.displayObject => child2::T.displayObject => unit =
      "" [@@bs.send.pipe : t];
    /*
     Returns the index position of a child DisplayObject instance
     */
    external getChildIndex : child::T.displayObject => float = "" [@@bs.send.pipe : t];
    /*
     Changes the position of an existing child in the display object container
     */
    external setChildIndex : child::T.displayObject => index::float => unit =
      "" [@@bs.send.pipe : t];
    /*
     Returns the child at the specified index
     */
    external getChildAt : index::float => T.displayObject = "" [@@bs.send.pipe : t];
    /*
     Removes one or more children from the container.
     */
    external removeChild : child::T.displayObject => T.displayObject = "" [@@bs.send.pipe : t];
    /*
     Removes a child from the specified index position.
     */
    external removeChildAt : index::float => T.displayObject = "" [@@bs.send.pipe : t];
    /*
     Removes all children from this container that are within the begin and end indexes.
     */
    external removeChildren : beginIndex::float? => endIndex::float? => array T.displayObject =
      "" [@@bs.send.pipe : t];
    /*
     Updates the transform on all children of this container for rendering
     */
    external updateTransform : unit = "" [@@bs.send.pipe : t];
    /*
     Recalculates the bounds of the container.
     */
    external calculateBounds : unit = "" [@@bs.send.pipe : t];
    /*
     Renders the object using the Canvas renderer
     */
    external renderCanvas : renderer::T.canvasRenderer => unit = "" [@@bs.send.pipe : t];
    /*
     recursively updates transform of all objects from the root to this one
     internal function for toLocal()
     */
    external _recursivePostUpdateTransform : unit = "" [@@bs.send.pipe : t];
    /*
     Retrieves the bounds of the displayObject as a rectangle object.
     */
    external getBounds : skipUpdate::Js.boolean => rect::T.rectangle => T.rectangle =
      "" [@@bs.send.pipe : t];
    /*
     Calculates the global position of the display object
     */
    external toGlobal : position::T.point => point::T.point? => skipUpdate::Js.boolean? => T.point =
      "" [@@bs.send.pipe : t];
    /*
     Calculates the local position of the display object relative to another point
     */
    external toLocal :
      position::T.point =>
      from::T.displayObject? =>
      point::T.point? =>
      skipUpdate::Js.boolean? =>
      T.point =
      "" [@@bs.send.pipe : t];
    /*
     Set the parent Container of this DisplayObject
     */
    external setParent : container::T.container => T.container = "" [@@bs.send.pipe : t];
    /*
     Convenience function to set the position, scale, skew and pivot at once.
     */
    external setTransform :
      x::float? =>
      y::float? =>
      scaleX::float? =>
      scaleY::float? =>
      rotation::float? =>
      skewX::float? =>
      skewY::float? =>
      pivotX::float? =>
      pivotY::float? =>
      T.displayObject =
      "" [@@bs.send.pipe : t];
  };
  module TextMetrics = {
    /*
     The TextMetrics object represents the measurement of a block of text with a specified style.
     */
    type t = T.textMetrics;
    external create :
      text::string =>
      style::T.textStyle =>
      width::float =>
      height::float =>
      lines::unit /* unknown js type: array */ =>
      lineWidths::unit /* unknown js type: array */ =>
      lineHeight::float =>
      maxLineWidth::float =>
      fontProperties::unit /* unknown js type: Object */ =>
      unit =>
      t =
      "TextMetrics" [@@bs.new] [@@bs.module ("pixi.js", "PIXI")];
    module FontMetrics = {
      type t = T.fontMetrics;
    };
  };
  module TextStyle = {
    /*
     A TextStyle Object decorates a Text Object. It can be shared between
     multiple Text objects. Changing the style will update all text objects using it.
     */
    type t = T.textStyle;
    type createStyle;
    /*
     The style parameters
     */
    external mkCreateStyle :
      align::string? =>
      breakWords::Js.boolean? =>
      dropShadow::Js.boolean? =>
      dropShadowAlpha::float? =>
      dropShadowAngle::float? =>
      dropShadowBlur::float? =>
      dropShadowColor::string? =>
      dropShadowDistance::float? =>
      fill::
        unit /* unknown js type: string|Array.<string>|number|Array.<number>|CanvasGradient|CanvasPattern */? =>
      fillGradientType::float? =>
      fillGradientStops::array float? =>
      fontFamily::array string? =>
      fontSize::unit /* unknown js type: number|string */? =>
      fontStyle::string? =>
      fontVariant::string? =>
      fontWeight::string? =>
      letterSpacing::float? =>
      lineHeight::float? =>
      lineJoin::string? =>
      miterLimit::float? =>
      padding::float? =>
      stroke::unit /* unknown js type: string|number */? =>
      strokeThickness::float? =>
      trim::Js.boolean? =>
      textBaseline::string? =>
      wordWrap::Js.boolean? =>
      wordWrapWidth::float? =>
      unit =>
      createStyle =
      "" [@@bs.obj];
    external create : style::createStyle? => unit => t =
      "TextStyle" [@@bs.new] [@@bs.module ("pixi.js", "PIXI")];
    /*
     Creates a new TextStyle object with the same values as this one.
     Note that the only the properties of the object are cloned.
     */
    external clone : T.textStyle = "" [@@bs.send.pipe : t];
    /*
     Resets all properties to the defaults specified in TextStyle.prototype._default
     */
    external reset : unit = "" [@@bs.send.pipe : t];
    /*
     <p>Generates a font style string to use for <code>TextMetrics.measureFont()</code>.</p>
     */
    external toFontString : string = "" [@@bs.send.pipe : t];
  };
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
    type t = T.baseRenderTexture;
    external create :
      width::float? => height::float? => scaleMode::float? => resolution::float? => unit => t =
      "BaseRenderTexture" [@@bs.new] [@@bs.module ("pixi.js", "PIXI")];
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
    /*
     Resizes the BaseRenderTexture.
     */
    external resize : width::float => height::float => unit = "" [@@bs.send.pipe : t];
    /*
     Destroys this texture
     */
    external destroy : unit = "" [@@bs.send.pipe : t];
    /*
     Updates the texture on all the webgl renderers, this also assumes the src has changed.
     */
    external update : unit = "" [@@bs.send.pipe : t];
    /*
     Update dimensions from real values
     */
    external _updateDimensions : unit = "" [@@bs.send.pipe : t];
    /*
     Load a source.

     <p>If the source is not-immediately-available, such as an image that needs to be
     downloaded, then the 'loaded' or 'error' event will be dispatched in the future
     and <code>hasLoaded</code> will remain false after this call.</p>
     <p>The logic state after calling <code>loadSource</code> directly or indirectly (eg. <code>fromImage</code>, <code>new BaseTexture</code>) is:</p>
     <pre class="prettyprint source"><code>if (texture.hasLoaded) {
        // texture ready for use
     } else if (texture.isLoading) {
        // listen to 'loaded' and/or 'error' events on texture
     } else {
        // not loading, not going to load UNLESS the source is reloaded
        // (it may still make sense to listen to the events)
     }</code></pre>
     */
    external loadSource :
      source::unit /* unknown js type: HTMLImageElement|HTMLCanvasElement */ => unit =
      "" [@@bs.send.pipe : t];
    /*
     Updates type of the source image.
     */
    external _updateImageType : unit = "" [@@bs.send.pipe : t];
    /*
     <p>Checks if <code>source</code> is an SVG image and whether it's loaded via a URL or a data URI. Then calls
     <code>_loadSvgSourceUsingDataUri</code> or <code>_loadSvgSourceUsingXhr</code>.</p>
     */
    external _loadSvgSource : unit = "" [@@bs.send.pipe : t];
    /*
     <p>Reads an SVG string from data URI and then calls <code>_loadSvgSourceUsingString</code>.</p>
     */
    external _loadSvgSourceUsingDataUri : dataUri::string => unit = "" [@@bs.send.pipe : t];
    /*
     <p>Loads an SVG string from <code>imageUrl</code> using XHR and then calls <code>_loadSvgSourceUsingString</code>.</p>
     */
    external _loadSvgSourceUsingXhr : unit = "" [@@bs.send.pipe : t];
    /*
     <p>Loads texture using an SVG string. The original SVG Image is stored as <code>origSource</code> and the
     created canvas is the new <code>source</code>. The SVG is scaled using <code>sourceScale</code>. Called by
     <code>_loadSvgSourceUsingXhr</code> or <code>_loadSvgSourceUsingDataUri</code>.</p>
     */
    external _loadSvgSourceUsingString : svgString::string => unit = "" [@@bs.send.pipe : t];
    /*
     Frees the texture from WebGL memory without destroying this texture object.
     This means you can still use the texture later which will upload it to GPU
     memory again.
     */
    external dispose : unit = "" [@@bs.send.pipe : t];
    /*
     Changes the source image of the texture.
     The original source must be an Image element.
     */
    external updateSourceImage : newSrc::string => unit = "" [@@bs.send.pipe : t];
  };
  module BaseTexture = {
    /*
     A texture stores the information that represents an image. All textures have a base texture.
     */
    type t = T.baseTexture;
    external create :
      source::unit /* unknown js type: HTMLImageElement|HTMLCanvasElement */? =>
      scaleMode::float? =>
      resolution::float? =>
      unit =>
      t =
      "BaseTexture" [@@bs.new] [@@bs.module ("pixi.js", "PIXI")];
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
    /*
     Updates the texture on all the webgl renderers, this also assumes the src has changed.
     */
    external update : unit = "" [@@bs.send.pipe : t];
    /*
     Update dimensions from real values
     */
    external _updateDimensions : unit = "" [@@bs.send.pipe : t];
    /*
     Load a source.

     <p>If the source is not-immediately-available, such as an image that needs to be
     downloaded, then the 'loaded' or 'error' event will be dispatched in the future
     and <code>hasLoaded</code> will remain false after this call.</p>
     <p>The logic state after calling <code>loadSource</code> directly or indirectly (eg. <code>fromImage</code>, <code>new BaseTexture</code>) is:</p>
     <pre class="prettyprint source"><code>if (texture.hasLoaded) {
        // texture ready for use
     } else if (texture.isLoading) {
        // listen to 'loaded' and/or 'error' events on texture
     } else {
        // not loading, not going to load UNLESS the source is reloaded
        // (it may still make sense to listen to the events)
     }</code></pre>
     */
    external loadSource :
      source::unit /* unknown js type: HTMLImageElement|HTMLCanvasElement */ => unit =
      "" [@@bs.send.pipe : t];
    /*
     Updates type of the source image.
     */
    external _updateImageType : unit = "" [@@bs.send.pipe : t];
    /*
     <p>Checks if <code>source</code> is an SVG image and whether it's loaded via a URL or a data URI. Then calls
     <code>_loadSvgSourceUsingDataUri</code> or <code>_loadSvgSourceUsingXhr</code>.</p>
     */
    external _loadSvgSource : unit = "" [@@bs.send.pipe : t];
    /*
     <p>Reads an SVG string from data URI and then calls <code>_loadSvgSourceUsingString</code>.</p>
     */
    external _loadSvgSourceUsingDataUri : dataUri::string => unit = "" [@@bs.send.pipe : t];
    /*
     <p>Loads an SVG string from <code>imageUrl</code> using XHR and then calls <code>_loadSvgSourceUsingString</code>.</p>
     */
    external _loadSvgSourceUsingXhr : unit = "" [@@bs.send.pipe : t];
    /*
     <p>Loads texture using an SVG string. The original SVG Image is stored as <code>origSource</code> and the
     created canvas is the new <code>source</code>. The SVG is scaled using <code>sourceScale</code>. Called by
     <code>_loadSvgSourceUsingXhr</code> or <code>_loadSvgSourceUsingDataUri</code>.</p>
     */
    external _loadSvgSourceUsingString : svgString::string => unit = "" [@@bs.send.pipe : t];
    /*
     Destroys this base texture
     */
    external destroy : unit = "" [@@bs.send.pipe : t];
    /*
     Frees the texture from WebGL memory without destroying this texture object.
     This means you can still use the texture later which will upload it to GPU
     memory again.
     */
    external dispose : unit = "" [@@bs.send.pipe : t];
    /*
     Changes the source image of the texture.
     The original source must be an Image element.
     */
    external updateSourceImage : newSrc::string => unit = "" [@@bs.send.pipe : t];
  };
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
    type t = T.renderTexture;
    external create : baseRenderTexture::T.baseRenderTexture => frame::T.rectangle? => unit => t =
      "RenderTexture" [@@bs.new] [@@bs.module ("pixi.js", "PIXI")];
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
    external baseTexture : t => T.baseTexture = "" [@@bs.get];
    /*
     The base texture that this texture uses.
     */
    external setBaseTexture : t => T.baseTexture => unit = "baseTexture" [@@bs.set];
    /*
     This is the area of the BaseTexture image to actually copy to the Canvas / WebGL when rendering,
     irrespective of the actual frame size or placement (which can be influenced by trimmed texture atlases)
     */
    external _frame : t => T.rectangle = "" [@@bs.get];
    /*
     This is the area of the BaseTexture image to actually copy to the Canvas / WebGL when rendering,
     irrespective of the actual frame size or placement (which can be influenced by trimmed texture atlases)
     */
    external set_frame : t => T.rectangle => unit = "_frame" [@@bs.set];
    /*
     This is the trimmed area of original texture, before it was put in atlas
     */
    external trim : t => T.rectangle = "" [@@bs.get];
    /*
     This is the trimmed area of original texture, before it was put in atlas
     */
    external setTrim : t => T.rectangle => unit = "trim" [@@bs.set];
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
    external orig : t => T.rectangle = "" [@@bs.get];
    /*
     This is the area of original texture, before it was put in atlas
     */
    external setOrig : t => T.rectangle => unit = "orig" [@@bs.set];
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
    external frame : t => T.rectangle = "" [@@bs.get];
    /*
     The frame specifies the region of the base texture that this texture uses.
     */
    external setFrame : t => T.rectangle => unit = "frame" [@@bs.set];
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
    /*
     Resizes the RenderTexture.
     */
    external resize : width::float => height::float => doNotResizeBaseTexture::Js.boolean => unit =
      "" [@@bs.send.pipe : t];
    /*
     Updates this texture on the gpu.
     */
    external update : unit = "" [@@bs.send.pipe : t];
    /*
     Destroys this texture
     */
    external destroy : destroyBase::Js.boolean? => unit = "" [@@bs.send.pipe : t];
    /*
     Creates a new texture object that acts the same as this one.
     */
    external clone : T.texture = "" [@@bs.send.pipe : t];
    /*
     Updates the internal WebGL UV cache.
     */
    external _updateUvs : unit = "" [@@bs.send.pipe : t];
  };
  module Spritesheet = {
    /*
     Utility class for maintaining reference to a collection
     of Textures on a single Spritesheet.
     */
    type t = T.spritesheet;
    external create :
      baseTexture::T.baseTexture =>
      data::unit /* unknown js type: Object */ =>
      resolutionFilename::string? =>
      unit =>
      t =
      "Spritesheet" [@@bs.new] [@@bs.module ("pixi.js", "PIXI")];
    /*
     Reference to ths source texture
     */
    external baseTexture : t => T.baseTexture = "" [@@bs.get];
    /*
     Reference to ths source texture
     */
    external setBaseTexture : t => T.baseTexture => unit = "baseTexture" [@@bs.set];
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
    /*
     Parser spritesheet from loaded data. This is done asynchronously
     to prevent creating too many Texture within a single process.
     */
    external parse : callback::unit /* unknown js type: function */ => unit =
      "" [@@bs.send.pipe : t];
    /*
     Destroy Spritesheet and don't use after this.
     */
    external destroy : destroyBase::Js.boolean? => unit = "" [@@bs.send.pipe : t];
  };
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
    type t = T.texture;
    external create :
      baseTexture::T.baseTexture =>
      frame::T.rectangle? =>
      orig::T.rectangle? =>
      trim::T.rectangle? =>
      rotate::float? =>
      unit =>
      t =
      "Texture" [@@bs.new] [@@bs.module ("pixi.js", "PIXI")];
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
    external baseTexture : t => T.baseTexture = "" [@@bs.get];
    /*
     The base texture that this texture uses.
     */
    external setBaseTexture : t => T.baseTexture => unit = "baseTexture" [@@bs.set];
    /*
     This is the area of the BaseTexture image to actually copy to the Canvas / WebGL when rendering,
     irrespective of the actual frame size or placement (which can be influenced by trimmed texture atlases)
     */
    external _frame : t => T.rectangle = "" [@@bs.get];
    /*
     This is the area of the BaseTexture image to actually copy to the Canvas / WebGL when rendering,
     irrespective of the actual frame size or placement (which can be influenced by trimmed texture atlases)
     */
    external set_frame : t => T.rectangle => unit = "_frame" [@@bs.set];
    /*
     This is the trimmed area of original texture, before it was put in atlas
     */
    external trim : t => T.rectangle = "" [@@bs.get];
    /*
     This is the trimmed area of original texture, before it was put in atlas
     */
    external setTrim : t => T.rectangle => unit = "trim" [@@bs.set];
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
    external orig : t => T.rectangle = "" [@@bs.get];
    /*
     This is the area of original texture, before it was put in atlas
     */
    external setOrig : t => T.rectangle => unit = "orig" [@@bs.set];
    /*
     Extra field for extra plugins. May contain clamp settings and some matrices
     */
    external transform : t => unit /* unknown js type: Object */ = "" [@@bs.get];
    /*
     Extra field for extra plugins. May contain clamp settings and some matrices
     */
    external setTransform : t => unit /* unknown js type: Object */ => unit =
      "transform" [@@bs.set];
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
    external frame : t => T.rectangle = "" [@@bs.get];
    /*
     The frame specifies the region of the base texture that this texture uses.
     */
    external setFrame : t => T.rectangle => unit = "frame" [@@bs.set];
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
    /*
     Updates this texture on the gpu.
     */
    external update : unit = "" [@@bs.send.pipe : t];
    /*
     Destroys this texture
     */
    external destroy : destroyBase::Js.boolean? => unit = "" [@@bs.send.pipe : t];
    /*
     Creates a new texture object that acts the same as this one.
     */
    external clone : T.texture = "" [@@bs.send.pipe : t];
    /*
     Updates the internal WebGL UV cache.
     */
    external _updateUvs : unit = "" [@@bs.send.pipe : t];
  };
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
    type t = T.videoBaseTexture;
    external create :
      source::unit /* unknown js type: HTMLVideoElement */ => scaleMode::float? => unit => t =
      "VideoBaseTexture" [@@bs.new] [@@bs.module ("pixi.js", "PIXI")];
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
    /*
     Destroys this texture
     */
    external destroy : unit = "" [@@bs.send.pipe : t];
    /*
     Updates the texture on all the webgl renderers, this also assumes the src has changed.
     */
    external update : unit = "" [@@bs.send.pipe : t];
    /*
     Update dimensions from real values
     */
    external _updateDimensions : unit = "" [@@bs.send.pipe : t];
    /*
     Load a source.

     <p>If the source is not-immediately-available, such as an image that needs to be
     downloaded, then the 'loaded' or 'error' event will be dispatched in the future
     and <code>hasLoaded</code> will remain false after this call.</p>
     <p>The logic state after calling <code>loadSource</code> directly or indirectly (eg. <code>fromImage</code>, <code>new BaseTexture</code>) is:</p>
     <pre class="prettyprint source"><code>if (texture.hasLoaded) {
        // texture ready for use
     } else if (texture.isLoading) {
        // listen to 'loaded' and/or 'error' events on texture
     } else {
        // not loading, not going to load UNLESS the source is reloaded
        // (it may still make sense to listen to the events)
     }</code></pre>
     */
    external loadSource :
      source::unit /* unknown js type: HTMLImageElement|HTMLCanvasElement */ => unit =
      "" [@@bs.send.pipe : t];
    /*
     Updates type of the source image.
     */
    external _updateImageType : unit = "" [@@bs.send.pipe : t];
    /*
     <p>Checks if <code>source</code> is an SVG image and whether it's loaded via a URL or a data URI. Then calls
     <code>_loadSvgSourceUsingDataUri</code> or <code>_loadSvgSourceUsingXhr</code>.</p>
     */
    external _loadSvgSource : unit = "" [@@bs.send.pipe : t];
    /*
     <p>Reads an SVG string from data URI and then calls <code>_loadSvgSourceUsingString</code>.</p>
     */
    external _loadSvgSourceUsingDataUri : dataUri::string => unit = "" [@@bs.send.pipe : t];
    /*
     <p>Loads an SVG string from <code>imageUrl</code> using XHR and then calls <code>_loadSvgSourceUsingString</code>.</p>
     */
    external _loadSvgSourceUsingXhr : unit = "" [@@bs.send.pipe : t];
    /*
     <p>Loads texture using an SVG string. The original SVG Image is stored as <code>origSource</code> and the
     created canvas is the new <code>source</code>. The SVG is scaled using <code>sourceScale</code>. Called by
     <code>_loadSvgSourceUsingXhr</code> or <code>_loadSvgSourceUsingDataUri</code>.</p>
     */
    external _loadSvgSourceUsingString : svgString::string => unit = "" [@@bs.send.pipe : t];
    /*
     Frees the texture from WebGL memory without destroying this texture object.
     This means you can still use the texture later which will upload it to GPU
     memory again.
     */
    external dispose : unit = "" [@@bs.send.pipe : t];
    /*
     Changes the source image of the texture.
     The original source must be an Image element.
     */
    external updateSourceImage : newSrc::string => unit = "" [@@bs.send.pipe : t];
  };
  module Ticker = {
    module Ticker = {
      /*
       A Ticker class that runs an update loop that other objects listen to.
       This class is composed around listeners
       meant for execution on the next requested animation frame.
       Animation frames are requested only when necessary,
       e.g. When the ticker is started and the emitter has listeners.
       */
      type t = T.ticker;
      external create : unit => t =
        "Ticker" [@@bs.new] [@@bs.scope "ticker"] [@@bs.module ("pixi.js", "PIXI")];
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
      /*
       Register a handler for tick events. Calls continuously unless
       it is removed or the ticker is stopped.
       */
      external add :
        fn::unit /* unknown js type: function */ =>
        context::unit /* unknown js type: function */? =>
        priority::float? =>
        T.ticker =
        "" [@@bs.send.pipe : t];
      /*
       Add a handler for the tick event which is only execute once.
       */
      external addOnce :
        fn::unit /* unknown js type: function */ =>
        context::unit /* unknown js type: function */? =>
        priority::float? =>
        T.ticker =
        "" [@@bs.send.pipe : t];
      /*
       Removes any handlers matching the function and context parameters.
       If no handlers are left after removing, then it cancels the animation frame.
       */
      external remove :
        fn::unit /* unknown js type: function */ =>
        context::unit /* unknown js type: function */? =>
        T.ticker =
        "" [@@bs.send.pipe : t];
      /*
       Starts the ticker. If the ticker has listeners
       a new animation frame is requested at this point.
       */
      external start : unit = "" [@@bs.send.pipe : t];
      /*
       Stops the ticker. If the ticker has requested
       an animation frame it is canceled at this point.
       */
      external stop : unit = "" [@@bs.send.pipe : t];
      /*
       Destroy the ticker and don't use after this. Calling
       this method removes all references to internal events.
       */
      external destroy : unit = "" [@@bs.send.pipe : t];
      /*
       Triggers an update. An update entails setting the
       current {@link PIXI.ticker.Ticker#elapsedMS},
       the current {@link PIXI.ticker.Ticker#deltaTime},
       invoking all listeners with current deltaTime,
       and then finally setting {@link PIXI.ticker.Ticker#lastTime}
       with the value of currentTime that was provided.
       This method will be called automatically by animation
       frame callbacks if the ticker instance has been started
       and listeners are added.
       */
      external update : currentTime::float? => unit = "" [@@bs.send.pipe : t];
    };
  };
  module Utils = {
    module EventEmitter = {
      type t = T.eventEmitter;
      external create : unit => t =
        "EventEmitter" [@@bs.new] [@@bs.scope "utils"] [@@bs.module ("pixi.js", "PIXI")];
    };
  };
  module Extract = {
    module CanvasExtract = {
      /*
       The extract manager provides functionality to export content from the renderers.

       An instance of this class is automatically created by default, and can be found at renderer.plugins.extract
       */
      type t = T.canvasExtract;
      external create : renderer::T.canvasRenderer => unit => t =
        "CanvasExtract" [@@bs.new] [@@bs.scope "extract"] [@@bs.module ("pixi.js", "PIXI")];
      /*
       Will return a HTML Image of the target
       */
      external image :
        target::unit /* unknown js type: PIXI.DisplayObject|PIXI.RenderTexture */ => unit /* unknown js type: HTMLImageElement */ =
        "" [@@bs.send.pipe : t];
      /*
       <p>Will return a a base64 encoded string of this target. It works by calling
        <code>CanvasExtract.getCanvas</code> and then running toDataURL on that.</p>
       */
      external base64 :
        target::unit /* unknown js type: PIXI.DisplayObject|PIXI.RenderTexture */ => string =
        "" [@@bs.send.pipe : t];
      /*
       Creates a Canvas element, renders this target to it and then returns it.
       */
      external canvas :
        target::unit /* unknown js type: PIXI.DisplayObject|PIXI.RenderTexture */ => Dom.element =
        "" [@@bs.send.pipe : t];
      /*
       Will return a one-dimensional array containing the pixel data of the entire texture in RGBA
       order, with integer values between 0 and 255 (included).
       */
      external pixels :
        target::unit /* unknown js type: PIXI.DisplayObject|PIXI.RenderTexture */ => unit /* unknown js type: Uint8ClampedArray */ =
        "" [@@bs.send.pipe : t];
      /*
       Destroys the extract
       */
      external destroy : unit = "" [@@bs.send.pipe : t];
    };
    module WebGLExtract = {
      /*
       The extract manager provides functionality to export content from the renderers.

       An instance of this class is automatically created by default, and can be found at renderer.plugins.extract
       */
      type t = T.webGLExtract;
      external create : renderer::T.webGLRenderer => unit => t =
        "WebGLExtract" [@@bs.new] [@@bs.scope "extract"] [@@bs.module ("pixi.js", "PIXI")];
      /*
       Will return a HTML Image of the target
       */
      external image :
        target::unit /* unknown js type: PIXI.DisplayObject|PIXI.RenderTexture */ => unit /* unknown js type: HTMLImageElement */ =
        "" [@@bs.send.pipe : t];
      /*
       <p>Will return a a base64 encoded string of this target. It works by calling
        <code>WebGLExtract.getCanvas</code> and then running toDataURL on that.</p>
       */
      external base64 :
        target::unit /* unknown js type: PIXI.DisplayObject|PIXI.RenderTexture */ => string =
        "" [@@bs.send.pipe : t];
      /*
       Creates a Canvas element, renders this target to it and then returns it.
       */
      external canvas :
        target::unit /* unknown js type: PIXI.DisplayObject|PIXI.RenderTexture */ => Dom.element =
        "" [@@bs.send.pipe : t];
      /*
       Will return a one-dimensional array containing the pixel data of the entire texture in RGBA
       order, with integer values between 0 and 255 (included).
       */
      external pixels :
        target::unit /* unknown js type: PIXI.DisplayObject|PIXI.RenderTexture */ => unit /* unknown js type: Uint8ClampedArray */ =
        "" [@@bs.send.pipe : t];
      /*
       Destroys the extract
       */
      external destroy : unit = "" [@@bs.send.pipe : t];
    };
  };
  module Extras = {
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
      type t = T.animatedSprite;
      external create :
        textures::unit /* unknown js type: Array.<PIXI.Texture>|Array.<FrameObject> */ =>
        autoUpdate::Js.boolean? =>
        unit =>
        t =
        "AnimatedSprite" [@@bs.new] [@@bs.scope "extras"] [@@bs.module ("pixi.js", "PIXI")];
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
      external textures : t => array T.texture = "" [@@bs.get];
      /*
       The array of textures used for this AnimatedSprite
       */
      external setTextures : t => array T.texture => unit = "textures" [@@bs.set];
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
      external anchor : t => T.observablePoint = "" [@@bs.get];
      /*
       The anchor sets the origin point of the texture.
       The default is 0,0 this means the texture's origin is the top left
       Setting the anchor to 0.5,0.5 means the texture's origin is centered
       Setting the anchor to 1,1 would mean the texture's origin point will be the bottom right corner
       */
      external setAnchor : t => T.observablePoint => unit = "anchor" [@@bs.set];
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
      external texture : t => T.texture = "" [@@bs.get];
      /*
       The texture that the sprite is using
       */
      external setTexture : t => T.texture => unit = "texture" [@@bs.set];
      /*
       The array of children of this container.
       */
      external children : t => array T.displayObject = "" [@@bs.get];
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
      external transform : t => T.transformBase = "" [@@bs.get];
      /*
       World transform and local transform of this object.
       This will become read-only later, please do not assign anything there unless you know what are you doing
       */
      external setTransform : t => T.transformBase => unit = "transform" [@@bs.set];
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
      external parent : t => T.container = "" [@@bs.get];
      /*
       The multiplied alpha of the displayObject
       */
      external worldAlpha : t => float = "" [@@bs.get];
      /*
       The area the filter is applied to. This is used as more of an optimisation
       rather than figuring out the dimensions of the displayObject each frame you can set this rectangle

       Also works as an interaction mask
       */
      external filterArea : t => T.rectangle = "" [@@bs.get];
      /*
       The area the filter is applied to. This is used as more of an optimisation
       rather than figuring out the dimensions of the displayObject each frame you can set this rectangle

       Also works as an interaction mask
       */
      external setFilterArea : t => T.rectangle => unit = "filterArea" [@@bs.set];
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
      external worldTransform : t => T.matrix = "" [@@bs.get];
      /*
       Current transform of the object based on local factors: position, scale, other stuff
       */
      external localTransform : t => T.matrix = "" [@@bs.get];
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
      external setPosition :
        t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
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
      external skew : t => T.observablePoint = "" [@@bs.get];
      /*
       The skew factor for the object in radians.
       Assignment by value since pixi-v4.
       */
      external setSkew : t => T.observablePoint => unit = "skew" [@@bs.set];
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
      external filters : t => array T.filter = "" [@@bs.get];
      /*
       Sets the filters for the displayObject.

       <ul>
       <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
       To remove filters simply set this property to 'null'</li>
       </ul>
       */
      external setFilters : t => array T.filter => unit = "filters" [@@bs.set];
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
      /*
       Stops the AnimatedSprite
       */
      external stop : unit = "" [@@bs.send.pipe : t];
      /*
       Plays the AnimatedSprite
       */
      external play : unit = "" [@@bs.send.pipe : t];
      /*
       Stops the AnimatedSprite and goes to a specific frame
       */
      external gotoAndStop : frameNumber::float => unit = "" [@@bs.send.pipe : t];
      /*
       Goes to a specific frame and begins playing the AnimatedSprite
       */
      external gotoAndPlay : frameNumber::float => unit = "" [@@bs.send.pipe : t];
      /*
       Stops the AnimatedSprite and destroys it
       */
      external destroy : options::unit /* unknown js type: object|boolean */? => unit =
        "" [@@bs.send.pipe : t];
      /*
       calculates worldTransform * vertices, store it in vertexData
       */
      external calculateVertices : unit = "" [@@bs.send.pipe : t];
      /*
       calculates worldTransform * vertices for a non texture with a trim. store it in vertexTrimmedData
       This is used to ensure that the true width and height of a trimmed texture is respected
       */
      external calculateTrimmedVertices : unit = "" [@@bs.send.pipe : t];
      /*
       Gets the local bounds of the sprite object.
       */
      external getLocalBounds : rect::T.rectangle => T.rectangle = "" [@@bs.send.pipe : t];
      /*
       Tests if a point is inside this sprite
       */
      external containsPoint : point::T.point => Js.boolean = "" [@@bs.send.pipe : t];
      /*
       Adds one or more children to the container.

       <p>Multiple items can be added like so: <code>myContainer.addChild(thingOne, thingTwo, thingThree)</code></p>
       */
      external addChild : child::T.displayObject => T.displayObject = "" [@@bs.send.pipe : t];
      /*
       Adds a child to the container at a specified index. If the index is out of bounds an error will be thrown
       */
      external addChildAt : child::T.displayObject => index::float => T.displayObject =
        "" [@@bs.send.pipe : t];
      /*
       Swaps the position of 2 Display Objects within this container.
       */
      external swapChildren : child::T.displayObject => child2::T.displayObject => unit =
        "" [@@bs.send.pipe : t];
      /*
       Returns the index position of a child DisplayObject instance
       */
      external getChildIndex : child::T.displayObject => float = "" [@@bs.send.pipe : t];
      /*
       Changes the position of an existing child in the display object container
       */
      external setChildIndex : child::T.displayObject => index::float => unit =
        "" [@@bs.send.pipe : t];
      /*
       Returns the child at the specified index
       */
      external getChildAt : index::float => T.displayObject = "" [@@bs.send.pipe : t];
      /*
       Removes one or more children from the container.
       */
      external removeChild : child::T.displayObject => T.displayObject = "" [@@bs.send.pipe : t];
      /*
       Removes a child from the specified index position.
       */
      external removeChildAt : index::float => T.displayObject = "" [@@bs.send.pipe : t];
      /*
       Removes all children from this container that are within the begin and end indexes.
       */
      external removeChildren : beginIndex::float? => endIndex::float? => array T.displayObject =
        "" [@@bs.send.pipe : t];
      /*
       Updates the transform on all children of this container for rendering
       */
      external updateTransform : unit = "" [@@bs.send.pipe : t];
      /*
       Recalculates the bounds of the container.
       */
      external calculateBounds : unit = "" [@@bs.send.pipe : t];
      /*
       Renders the object using the WebGL renderer
       */
      external renderWebGL : renderer::T.webGLRenderer => unit = "" [@@bs.send.pipe : t];
      /*
       Renders the object using the Canvas renderer
       */
      external renderCanvas : renderer::T.canvasRenderer => unit = "" [@@bs.send.pipe : t];
      /*
       recursively updates transform of all objects from the root to this one
       internal function for toLocal()
       */
      external _recursivePostUpdateTransform : unit = "" [@@bs.send.pipe : t];
      /*
       Retrieves the bounds of the displayObject as a rectangle object.
       */
      external getBounds : skipUpdate::Js.boolean => rect::T.rectangle => T.rectangle =
        "" [@@bs.send.pipe : t];
      /*
       Calculates the global position of the display object
       */
      external toGlobal :
        position::T.point => point::T.point? => skipUpdate::Js.boolean? => T.point =
        "" [@@bs.send.pipe : t];
      /*
       Calculates the local position of the display object relative to another point
       */
      external toLocal :
        position::T.point =>
        from::T.displayObject? =>
        point::T.point? =>
        skipUpdate::Js.boolean? =>
        T.point =
        "" [@@bs.send.pipe : t];
      /*
       Set the parent Container of this DisplayObject
       */
      external setParent : container::T.container => T.container = "" [@@bs.send.pipe : t];
      /*
       Convenience function to set the position, scale, skew and pivot at once.
       */
      external setTransform :
        x::float? =>
        y::float? =>
        scaleX::float? =>
        scaleY::float? =>
        rotation::float? =>
        skewX::float? =>
        skewY::float? =>
        pivotX::float? =>
        pivotY::float? =>
        T.displayObject =
        "" [@@bs.send.pipe : t];
    };
    module BitmapText = {
      /*
       A BitmapText object will create a line or multiple lines of text using bitmap font. To
       split a line you can use '\n', '\r' or '\r\n' in your string. You can generate the fnt files using:

       A BitmapText can only be created when the font is loaded

       <pre class="prettyprint source lang-js"><code>// in this case the font is in a file called 'desyrel.fnt'
       let bitmapText = new PIXI.extras.BitmapText(&quot;text using a fancy font!&quot;, {font: &quot;35px Desyrel&quot;, align: &quot;right&quot;});</code></pre>http://www.angelcode.com/products/bmfont/ for windows or
       http://www.bmglyph.com/ for mac.
       */
      type t = T.bitmapText;
      type createStyle;
      /*
       The style parameters
       */
      external mkCreateStyle :
        font::unit /* unknown js type: string|object */ =>
        font::string? =>
        font::float? =>
        align::string? =>
        tint::float? =>
        unit =>
        createStyle =
        "" [@@bs.obj];
      external create : text::string => style::createStyle => unit => t =
        "BitmapText" [@@bs.new] [@@bs.scope "extras"] [@@bs.module ("pixi.js", "PIXI")];
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
      external setFont : t => unit /* unknown js type: string|object */ => unit =
        "font" [@@bs.set];
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
      external children : t => array T.displayObject = "" [@@bs.get];
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
      external transform : t => T.transformBase = "" [@@bs.get];
      /*
       World transform and local transform of this object.
       This will become read-only later, please do not assign anything there unless you know what are you doing
       */
      external setTransform : t => T.transformBase => unit = "transform" [@@bs.set];
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
      external parent : t => T.container = "" [@@bs.get];
      /*
       The multiplied alpha of the displayObject
       */
      external worldAlpha : t => float = "" [@@bs.get];
      /*
       The area the filter is applied to. This is used as more of an optimisation
       rather than figuring out the dimensions of the displayObject each frame you can set this rectangle

       Also works as an interaction mask
       */
      external filterArea : t => T.rectangle = "" [@@bs.get];
      /*
       The area the filter is applied to. This is used as more of an optimisation
       rather than figuring out the dimensions of the displayObject each frame you can set this rectangle

       Also works as an interaction mask
       */
      external setFilterArea : t => T.rectangle => unit = "filterArea" [@@bs.set];
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
      external worldTransform : t => T.matrix = "" [@@bs.get];
      /*
       Current transform of the object based on local factors: position, scale, other stuff
       */
      external localTransform : t => T.matrix = "" [@@bs.get];
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
      external setPosition :
        t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
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
      external skew : t => T.observablePoint = "" [@@bs.get];
      /*
       The skew factor for the object in radians.
       Assignment by value since pixi-v4.
       */
      external setSkew : t => T.observablePoint => unit = "skew" [@@bs.set];
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
      external filters : t => array T.filter = "" [@@bs.get];
      /*
       Sets the filters for the displayObject.

       <ul>
       <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
       To remove filters simply set this property to 'null'</li>
       </ul>
       */
      external setFilters : t => array T.filter => unit = "filters" [@@bs.set];
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
      /*
       Validates text before calling parent's getLocalBounds
       */
      external getLocalBounds : T.rectangle = "" [@@bs.send.pipe : t];
      /*
       Adds one or more children to the container.

       <p>Multiple items can be added like so: <code>myContainer.addChild(thingOne, thingTwo, thingThree)</code></p>
       */
      external addChild : child::T.displayObject => T.displayObject = "" [@@bs.send.pipe : t];
      /*
       Adds a child to the container at a specified index. If the index is out of bounds an error will be thrown
       */
      external addChildAt : child::T.displayObject => index::float => T.displayObject =
        "" [@@bs.send.pipe : t];
      /*
       Swaps the position of 2 Display Objects within this container.
       */
      external swapChildren : child::T.displayObject => child2::T.displayObject => unit =
        "" [@@bs.send.pipe : t];
      /*
       Returns the index position of a child DisplayObject instance
       */
      external getChildIndex : child::T.displayObject => float = "" [@@bs.send.pipe : t];
      /*
       Changes the position of an existing child in the display object container
       */
      external setChildIndex : child::T.displayObject => index::float => unit =
        "" [@@bs.send.pipe : t];
      /*
       Returns the child at the specified index
       */
      external getChildAt : index::float => T.displayObject = "" [@@bs.send.pipe : t];
      /*
       Removes one or more children from the container.
       */
      external removeChild : child::T.displayObject => T.displayObject = "" [@@bs.send.pipe : t];
      /*
       Removes a child from the specified index position.
       */
      external removeChildAt : index::float => T.displayObject = "" [@@bs.send.pipe : t];
      /*
       Removes all children from this container that are within the begin and end indexes.
       */
      external removeChildren : beginIndex::float? => endIndex::float? => array T.displayObject =
        "" [@@bs.send.pipe : t];
      /*
       Recalculates the bounds of the container.
       */
      external calculateBounds : unit = "" [@@bs.send.pipe : t];
      /*
       Recalculates the bounds of the object. Override this to
       calculate the bounds of the specific object (not including children).
       */
      external _calculateBounds : unit = "" [@@bs.send.pipe : t];
      /*
       Renders the object using the WebGL renderer
       */
      external renderWebGL : renderer::T.webGLRenderer => unit = "" [@@bs.send.pipe : t];
      /*
       Renders the object using the Canvas renderer
       */
      external renderCanvas : renderer::T.canvasRenderer => unit = "" [@@bs.send.pipe : t];
      /*
       <p>Removes all internal references and listeners as well as removes children from the display list.
       Do not use a Container after calling <code>destroy</code>.</p>
       */
      external destroy : options::unit /* unknown js type: object|boolean */? => unit =
        "" [@@bs.send.pipe : t];
      /*
       recursively updates transform of all objects from the root to this one
       internal function for toLocal()
       */
      external _recursivePostUpdateTransform : unit = "" [@@bs.send.pipe : t];
      /*
       Retrieves the bounds of the displayObject as a rectangle object.
       */
      external getBounds : skipUpdate::Js.boolean => rect::T.rectangle => T.rectangle =
        "" [@@bs.send.pipe : t];
      /*
       Calculates the global position of the display object
       */
      external toGlobal :
        position::T.point => point::T.point? => skipUpdate::Js.boolean? => T.point =
        "" [@@bs.send.pipe : t];
      /*
       Calculates the local position of the display object relative to another point
       */
      external toLocal :
        position::T.point =>
        from::T.displayObject? =>
        point::T.point? =>
        skipUpdate::Js.boolean? =>
        T.point =
        "" [@@bs.send.pipe : t];
      /*
       Set the parent Container of this DisplayObject
       */
      external setParent : container::T.container => T.container = "" [@@bs.send.pipe : t];
      /*
       Convenience function to set the position, scale, skew and pivot at once.
       */
      external setTransform :
        x::float? =>
        y::float? =>
        scaleX::float? =>
        scaleY::float? =>
        rotation::float? =>
        skewX::float? =>
        skewY::float? =>
        pivotX::float? =>
        pivotY::float? =>
        T.displayObject =
        "" [@@bs.send.pipe : t];
    };
    module TextureTransform = {
      /*
       class controls uv transform and frame clamp for texture
       */
      type t = T.textureTransform;
      external create : texture::T.texture => clampMargin::float? => unit => t =
        "TextureTransform" [@@bs.new] [@@bs.scope "extras"] [@@bs.module ("pixi.js", "PIXI")];
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
      external texture : t => T.texture = "" [@@bs.get];
      /*
       texture property
       */
      external setTexture : t => T.texture => unit = "texture" [@@bs.set];
      /*
       Multiplies uvs array to transform
       */
      external multiplyUvs :
        uvs::Js_typed_array.Float32Array.t =>
        out::Js_typed_array.Float32Array.t? =>
        Js_typed_array.Float32Array.t =
        "" [@@bs.send.pipe : t];
      /*
       updates matrices if texture was changed
       */
      external update : forceUpdate::Js.boolean => Js.boolean = "" [@@bs.send.pipe : t];
    };
    module TilingSprite = {
      /*
       A tiling sprite is a fast way of rendering a tiling image
       */
      type t = T.tilingSprite;
      external create : texture::T.texture => width::float? => height::float? => unit => t =
        "TilingSprite" [@@bs.new] [@@bs.scope "extras"] [@@bs.module ("pixi.js", "PIXI")];
      /*
       Tile transform
       */
      external tileTransform : t => T.transformStatic = "" [@@bs.get];
      /*
       Tile transform
       */
      external setTileTransform : t => T.transformStatic => unit = "tileTransform" [@@bs.set];
      /*
       transform that is applied to UV to get the texture coords
       */
      external uvTransform : t => T.textureTransform = "" [@@bs.get];
      /*
       transform that is applied to UV to get the texture coords
       */
      external setUvTransform : t => T.textureTransform => unit = "uvTransform" [@@bs.set];
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
      external tileScale : t => T.observablePoint = "" [@@bs.get];
      /*
       The scaling of the image that is being tiled
       */
      external setTileScale : t => T.observablePoint => unit = "tileScale" [@@bs.set];
      /*
       The offset of the image that is being tiled
       */
      external tilePosition : t => T.observablePoint = "" [@@bs.get];
      /*
       The offset of the image that is being tiled
       */
      external setTilePosition : t => T.observablePoint => unit = "tilePosition" [@@bs.set];
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
      external anchor : t => T.observablePoint = "" [@@bs.get];
      /*
       The anchor sets the origin point of the texture.
       The default is 0,0 this means the texture's origin is the top left
       Setting the anchor to 0.5,0.5 means the texture's origin is centered
       Setting the anchor to 1,1 would mean the texture's origin point will be the bottom right corner
       */
      external setAnchor : t => T.observablePoint => unit = "anchor" [@@bs.set];
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
      external texture : t => T.texture = "" [@@bs.get];
      /*
       The texture that the sprite is using
       */
      external setTexture : t => T.texture => unit = "texture" [@@bs.set];
      /*
       The array of children of this container.
       */
      external children : t => array T.displayObject = "" [@@bs.get];
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
      external transform : t => T.transformBase = "" [@@bs.get];
      /*
       World transform and local transform of this object.
       This will become read-only later, please do not assign anything there unless you know what are you doing
       */
      external setTransform : t => T.transformBase => unit = "transform" [@@bs.set];
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
      external parent : t => T.container = "" [@@bs.get];
      /*
       The multiplied alpha of the displayObject
       */
      external worldAlpha : t => float = "" [@@bs.get];
      /*
       The area the filter is applied to. This is used as more of an optimisation
       rather than figuring out the dimensions of the displayObject each frame you can set this rectangle

       Also works as an interaction mask
       */
      external filterArea : t => T.rectangle = "" [@@bs.get];
      /*
       The area the filter is applied to. This is used as more of an optimisation
       rather than figuring out the dimensions of the displayObject each frame you can set this rectangle

       Also works as an interaction mask
       */
      external setFilterArea : t => T.rectangle => unit = "filterArea" [@@bs.set];
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
      external worldTransform : t => T.matrix = "" [@@bs.get];
      /*
       Current transform of the object based on local factors: position, scale, other stuff
       */
      external localTransform : t => T.matrix = "" [@@bs.get];
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
      external setPosition :
        t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
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
      external skew : t => T.observablePoint = "" [@@bs.get];
      /*
       The skew factor for the object in radians.
       Assignment by value since pixi-v4.
       */
      external setSkew : t => T.observablePoint => unit = "skew" [@@bs.set];
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
      external filters : t => array T.filter = "" [@@bs.get];
      /*
       Sets the filters for the displayObject.

       <ul>
       <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
       To remove filters simply set this property to 'null'</li>
       </ul>
       */
      external setFilters : t => array T.filter => unit = "filters" [@@bs.set];
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
      /*
       Gets the local bounds of the sprite object.
       */
      external getLocalBounds : rect::T.rectangle => T.rectangle = "" [@@bs.send.pipe : t];
      /*
       Checks if a point is inside this tiling sprite.
       */
      external containsPoint : point::T.point => Js.boolean = "" [@@bs.send.pipe : t];
      /*
       Destroys this sprite and optionally its texture and children
       */
      external destroy : options::unit /* unknown js type: object|boolean */? => unit =
        "" [@@bs.send.pipe : t];
      /*
       calculates worldTransform * vertices, store it in vertexData
       */
      external calculateVertices : unit = "" [@@bs.send.pipe : t];
      /*
       calculates worldTransform * vertices for a non texture with a trim. store it in vertexTrimmedData
       This is used to ensure that the true width and height of a trimmed texture is respected
       */
      external calculateTrimmedVertices : unit = "" [@@bs.send.pipe : t];
      /*
       Adds one or more children to the container.

       <p>Multiple items can be added like so: <code>myContainer.addChild(thingOne, thingTwo, thingThree)</code></p>
       */
      external addChild : child::T.displayObject => T.displayObject = "" [@@bs.send.pipe : t];
      /*
       Adds a child to the container at a specified index. If the index is out of bounds an error will be thrown
       */
      external addChildAt : child::T.displayObject => index::float => T.displayObject =
        "" [@@bs.send.pipe : t];
      /*
       Swaps the position of 2 Display Objects within this container.
       */
      external swapChildren : child::T.displayObject => child2::T.displayObject => unit =
        "" [@@bs.send.pipe : t];
      /*
       Returns the index position of a child DisplayObject instance
       */
      external getChildIndex : child::T.displayObject => float = "" [@@bs.send.pipe : t];
      /*
       Changes the position of an existing child in the display object container
       */
      external setChildIndex : child::T.displayObject => index::float => unit =
        "" [@@bs.send.pipe : t];
      /*
       Returns the child at the specified index
       */
      external getChildAt : index::float => T.displayObject = "" [@@bs.send.pipe : t];
      /*
       Removes one or more children from the container.
       */
      external removeChild : child::T.displayObject => T.displayObject = "" [@@bs.send.pipe : t];
      /*
       Removes a child from the specified index position.
       */
      external removeChildAt : index::float => T.displayObject = "" [@@bs.send.pipe : t];
      /*
       Removes all children from this container that are within the begin and end indexes.
       */
      external removeChildren : beginIndex::float? => endIndex::float? => array T.displayObject =
        "" [@@bs.send.pipe : t];
      /*
       Updates the transform on all children of this container for rendering
       */
      external updateTransform : unit = "" [@@bs.send.pipe : t];
      /*
       Recalculates the bounds of the container.
       */
      external calculateBounds : unit = "" [@@bs.send.pipe : t];
      /*
       Renders the object using the WebGL renderer
       */
      external renderWebGL : renderer::T.webGLRenderer => unit = "" [@@bs.send.pipe : t];
      /*
       Renders the object using the Canvas renderer
       */
      external renderCanvas : renderer::T.canvasRenderer => unit = "" [@@bs.send.pipe : t];
      /*
       recursively updates transform of all objects from the root to this one
       internal function for toLocal()
       */
      external _recursivePostUpdateTransform : unit = "" [@@bs.send.pipe : t];
      /*
       Retrieves the bounds of the displayObject as a rectangle object.
       */
      external getBounds : skipUpdate::Js.boolean => rect::T.rectangle => T.rectangle =
        "" [@@bs.send.pipe : t];
      /*
       Calculates the global position of the display object
       */
      external toGlobal :
        position::T.point => point::T.point? => skipUpdate::Js.boolean? => T.point =
        "" [@@bs.send.pipe : t];
      /*
       Calculates the local position of the display object relative to another point
       */
      external toLocal :
        position::T.point =>
        from::T.displayObject? =>
        point::T.point? =>
        skipUpdate::Js.boolean? =>
        T.point =
        "" [@@bs.send.pipe : t];
      /*
       Set the parent Container of this DisplayObject
       */
      external setParent : container::T.container => T.container = "" [@@bs.send.pipe : t];
      /*
       Convenience function to set the position, scale, skew and pivot at once.
       */
      external setTransform :
        x::float? =>
        y::float? =>
        scaleX::float? =>
        scaleY::float? =>
        rotation::float? =>
        skewX::float? =>
        skewY::float? =>
        pivotX::float? =>
        pivotY::float? =>
        T.displayObject =
        "" [@@bs.send.pipe : t];
    };
    module TilingSpriteRenderer = {
      /*
       WebGL renderer plugin for tiling sprites
       */
      type t = T.tilingSpriteRenderer;
      external create : renderer::T.webGLRenderer => unit => t =
        "TilingSpriteRenderer" [@@bs.new] [@@bs.scope "extras"] [@@bs.module ("pixi.js", "PIXI")];
      /*
       The renderer this manager works for.
       */
      external renderer : t => T.webGLRenderer = "" [@@bs.get];
      /*
       The renderer this manager works for.
       */
      external setRenderer : t => T.webGLRenderer => unit = "renderer" [@@bs.set];
      external render : ts::T.tilingSprite => unit = "" [@@bs.send.pipe : t];
      /*
       Starts the renderer and sets the shader
       */
      external start : unit = "" [@@bs.send.pipe : t];
      /*
       Stops the renderer
       */
      external stop : unit = "" [@@bs.send.pipe : t];
      /*
       Stub method for rendering content and emptying the current batch.
       */
      external flush : unit = "" [@@bs.send.pipe : t];
      /*
       Generic destroy methods to be overridden by the subclass
       */
      external destroy : unit = "" [@@bs.send.pipe : t];
    };
  };
  module Filters = {
    module BlurFilter = {
      /*
       The BlurFilter applies a Gaussian blur to an object.
       The strength of the blur can be set for x- and y-axis separately.
       */
      type t = T.blurFilter;
      external create :
        strength::float => quality::float => resolution::float => kernelSize::float? => unit => t =
        "BlurFilter" [@@bs.new] [@@bs.scope "filters"] [@@bs.module ("pixi.js", "PIXI")];
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
      external setUniforms : t => unit /* unknown js type: object */ => unit =
        "uniforms" [@@bs.set];
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
      /*
       Applies the filter.
       */
      external apply :
        filterManager::T.filterManager => input::T.renderTarget => output::T.renderTarget => unit =
        "" [@@bs.send.pipe : t];
    };
    module BlurXFilter = {
      /*
       The BlurXFilter applies a horizontal Gaussian blur to an object.
       */
      type t = T.blurXFilter;
      external create :
        strength::float => quality::float => resolution::float => kernelSize::float? => unit => t =
        "BlurXFilter" [@@bs.new] [@@bs.scope "filters"] [@@bs.module ("pixi.js", "PIXI")];
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
      external setUniforms : t => unit /* unknown js type: object */ => unit =
        "uniforms" [@@bs.set];
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
      /*
       Applies the filter.
       */
      external apply :
        filterManager::T.filterManager =>
        input::T.renderTarget =>
        output::T.renderTarget =>
        clear::Js.boolean =>
        unit =
        "" [@@bs.send.pipe : t];
    };
    module BlurYFilter = {
      /*
       The BlurYFilter applies a horizontal Gaussian blur to an object.
       */
      type t = T.blurYFilter;
      external create :
        strength::float => quality::float => resolution::float => kernelSize::float? => unit => t =
        "BlurYFilter" [@@bs.new] [@@bs.scope "filters"] [@@bs.module ("pixi.js", "PIXI")];
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
      external setUniforms : t => unit /* unknown js type: object */ => unit =
        "uniforms" [@@bs.set];
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
      /*
       Applies the filter.
       */
      external apply :
        filterManager::T.filterManager =>
        input::T.renderTarget =>
        output::T.renderTarget =>
        clear::Js.boolean =>
        unit =
        "" [@@bs.send.pipe : t];
    };
    module ColorMatrixFilter = {
      /*
       The ColorMatrixFilter class lets you apply a 5x4 matrix transformation on the RGBA
       color and alpha values of every pixel on your displayObject to produce a result
       with a new set of RGBA color and alpha values. It's pretty powerful!

       <pre class="prettyprint source lang-js"><code> let colorMatrix = new PIXI.ColorMatrixFilter();
        container.filters = [colorMatrix];
        colorMatrix.contrast(2);</code></pre>
       */
      type t = T.colorMatrixFilter;
      external create : unit => t =
        "ColorMatrixFilter" [@@bs.new] [@@bs.scope "filters"] [@@bs.module ("pixi.js", "PIXI")];
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
      external setUniforms : t => unit /* unknown js type: object */ => unit =
        "uniforms" [@@bs.set];
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
      /*
       Transforms current matrix and set the new one
       */
      external _loadMatrix : matrix::array float => multiply::Js.boolean => unit =
        "" [@@bs.send.pipe : t];
      /*
       Adjusts brightness
       */
      external brightness : b::float => multiply::Js.boolean => unit = "" [@@bs.send.pipe : t];
      /*
       Set the matrices in grey scales
       */
      external greyscale : scale::float => multiply::Js.boolean => unit = "" [@@bs.send.pipe : t];
      /*
       Set the black and white matrice.
       */
      external blackAndWhite : multiply::Js.boolean => unit = "" [@@bs.send.pipe : t];
      /*
       Set the hue property of the color
       */
      external hue : rotation::float => multiply::Js.boolean => unit = "" [@@bs.send.pipe : t];
      /*
       Set the contrast matrix, increase the separation between dark and bright
       Increase contrast : shadows darker and highlights brighter
       Decrease contrast : bring the shadows up and the highlights down
       */
      external contrast : amount::float => multiply::Js.boolean => unit = "" [@@bs.send.pipe : t];
      /*
       Set the saturation matrix, increase the separation between colors
       Increase saturation : increase contrast, brightness, and sharpness
       */
      external saturate : amount::float => multiply::Js.boolean => unit = "" [@@bs.send.pipe : t];
      /*
       Desaturate image (remove color)

       Call the saturate function
       */
      external desaturate : unit = "" [@@bs.send.pipe : t];
      /*
       Negative image (inverse of classic rgb matrix)
       */
      external negative : multiply::Js.boolean => unit = "" [@@bs.send.pipe : t];
      /*
       Sepia image
       */
      external sepia : multiply::Js.boolean => unit = "" [@@bs.send.pipe : t];
      /*
       Color motion picture process invented in 1916 (thanks Dominic Szablewski)
       */
      external technicolor : multiply::Js.boolean => unit = "" [@@bs.send.pipe : t];
      /*
       Polaroid filter
       */
      external polaroid : multiply::Js.boolean => unit = "" [@@bs.send.pipe : t];
      /*
       Filter who transforms : Red -&gt; Blue and Blue -&gt; Red
       */
      external toBGR : multiply::Js.boolean => unit = "" [@@bs.send.pipe : t];
      /*
       Color reversal film introduced by Eastman Kodak in 1935. (thanks Dominic Szablewski)
       */
      external kodachrome : multiply::Js.boolean => unit = "" [@@bs.send.pipe : t];
      /*
       Brown delicious browni filter (thanks Dominic Szablewski)
       */
      external browni : multiply::Js.boolean => unit = "" [@@bs.send.pipe : t];
      /*
       Vintage filter (thanks Dominic Szablewski)
       */
      external vintage : multiply::Js.boolean => unit = "" [@@bs.send.pipe : t];
      /*
       We don't know exactly what it does, kind of gradient map, but funny to play with!
       */
      external colorTone :
        desaturation::float =>
        toned::float =>
        lightColor::string =>
        darkColor::string =>
        multiply::Js.boolean =>
        unit =
        "" [@@bs.send.pipe : t];
      /*
       Night effect
       */
      external night : intensity::float => multiply::Js.boolean => unit = "" [@@bs.send.pipe : t];
      /*
       Predator effect

       Erase the current matrix by setting a new indepent one
       */
      external predator : amount::float => multiply::Js.boolean => unit = "" [@@bs.send.pipe : t];
      /*
       LSD effect

       Multiply the current matrix
       */
      external lsd : multiply::Js.boolean => unit = "" [@@bs.send.pipe : t];
      /*
       Erase the current matrix by setting the default one
       */
      external reset : unit = "" [@@bs.send.pipe : t];
      /*
       Applies the filter
       */
      external apply :
        filterManager::T.filterManager =>
        input::T.renderTarget =>
        output::T.renderTarget =>
        clear::Js.boolean =>
        currentState::unit /* unknown js type: object */? =>
        unit =
        "" [@@bs.send.pipe : t];
    };
    module DisplacementFilter = {
      /*
       The DisplacementFilter class uses the pixel values from the specified texture
       (called the displacement map) to perform a displacement of an object. You can
       use this filter to apply all manor of crazy warping effects. Currently the r
       property of the texture is used to offset the x and the g property of the texture
       is used to offset the y.
       */
      type t = T.displacementFilter;
      external create : sprite::T.sprite => scale::float => unit => t =
        "DisplacementFilter" [@@bs.new] [@@bs.scope "filters"] [@@bs.module ("pixi.js", "PIXI")];
      /*
       The texture used for the displacement map. Must be power of 2 sized texture.
       */
      external map : t => T.texture = "" [@@bs.get];
      /*
       The texture used for the displacement map. Must be power of 2 sized texture.
       */
      external setMap : t => T.texture => unit = "map" [@@bs.set];
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
      external setUniforms : t => unit /* unknown js type: object */ => unit =
        "uniforms" [@@bs.set];
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
      /*
       Applies the filter.
       */
      external apply :
        filterManager::T.filterManager => input::T.renderTarget => output::T.renderTarget => unit =
        "" [@@bs.send.pipe : t];
    };
    module FXAAFilter = {
      /*
       Basic FXAA implementation based on the code on geeks3d.com with the
       modification that the texture2DLod stuff was removed since it's
       unsupported by WebGL.
       */
      type t = T.fxaaFilter;
      external create : unit => t =
        "FXAAFilter" [@@bs.new] [@@bs.scope "filters"] [@@bs.module ("pixi.js", "PIXI")];
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
      external setUniforms : t => unit /* unknown js type: object */ => unit =
        "uniforms" [@@bs.set];
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
      /*
       Applies the filter
       */
      external apply :
        filterManager::T.filterManager =>
        input::T.renderTarget =>
        output::T.renderTarget =>
        clear::Js.boolean =>
        currentState::unit /* unknown js type: object */? =>
        unit =
        "" [@@bs.send.pipe : t];
    };
    module NoiseFilter = {
      /*
       A Noise effect filter.
       */
      type t = T.noiseFilter;
      external create : noise::float => seed::float => unit => t =
        "NoiseFilter" [@@bs.new] [@@bs.scope "filters"] [@@bs.module ("pixi.js", "PIXI")];
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
      external setUniforms : t => unit /* unknown js type: object */ => unit =
        "uniforms" [@@bs.set];
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
      /*
       Applies the filter
       */
      external apply :
        filterManager::T.filterManager =>
        input::T.renderTarget =>
        output::T.renderTarget =>
        clear::Js.boolean =>
        currentState::unit /* unknown js type: object */? =>
        unit =
        "" [@@bs.send.pipe : t];
    };
    module VoidFilter = {
      /*
       Does nothing. Very handy.
       */
      type t = T.voidFilter;
      external create : unit => t =
        "VoidFilter" [@@bs.new] [@@bs.scope "filters"] [@@bs.module ("pixi.js", "PIXI")];
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
      external setUniforms : t => unit /* unknown js type: object */ => unit =
        "uniforms" [@@bs.set];
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
      /*
       Applies the filter
       */
      external apply :
        filterManager::T.filterManager =>
        input::T.renderTarget =>
        output::T.renderTarget =>
        clear::Js.boolean =>
        currentState::unit /* unknown js type: object */? =>
        unit =
        "" [@@bs.send.pipe : t];
    };
  };
  module Interaction = {
    module InteractionData = {
      /*
       Holds all information related to an Interaction event
       */
      type t = T.interactionData;
      external create : unit => t =
        "InteractionData" [@@bs.new] [@@bs.scope "interaction"] [@@bs.module ("pixi.js", "PIXI")];
      /*
       This point stores the global coords of where the touch/mouse event happened
       */
      external global : t => T.point = "" [@@bs.get];
      /*
       This point stores the global coords of where the touch/mouse event happened
       */
      external setGlobal : t => T.point => unit = "global" [@@bs.set];
      /*
       The target DisplayObject that was interacted with
       */
      external target : t => T.displayObject = "" [@@bs.get];
      /*
       The target DisplayObject that was interacted with
       */
      external setTarget : t => T.displayObject => unit = "target" [@@bs.set];
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
      /*
       This will return the local coordinates of the specified displayObject for this InteractionData
       */
      external getLocalPosition :
        displayObject::T.displayObject => point::T.point? => globalPos::T.point? => T.point =
        "" [@@bs.send.pipe : t];
    };
    module InteractionEvent = {
      /*
       Event class that mimics native DOM events.
       */
      type t = T.interactionEvent;
      external create : unit => t =
        "InteractionEvent" [@@bs.new] [@@bs.scope "interaction"] [@@bs.module ("pixi.js", "PIXI")];
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
      external target : t => T.displayObject = "" [@@bs.get];
      /*
       The object which caused this event to be dispatched.
       For listener callback see {@link PIXI.interaction.InteractionEvent.currentTarget}.
       */
      external setTarget : t => T.displayObject => unit = "target" [@@bs.set];
      /*
       The object whose event listener’s callback is currently being invoked.
       */
      external currentTarget : t => T.displayObject = "" [@@bs.get];
      /*
       The object whose event listener’s callback is currently being invoked.
       */
      external setCurrentTarget : t => T.displayObject => unit = "currentTarget" [@@bs.set];
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
      external data : t => T.interactionData = "" [@@bs.get];
      /*
       InteractionData related to this event
       */
      external setData : t => T.interactionData => unit = "data" [@@bs.set];
      /*
       Prevents event from reaching any objects other than the current object.
       */
      external stopPropagation : unit = "" [@@bs.send.pipe : t];
    };
    module InteractionManager = {
      /*
       The interaction manager deals with mouse, touch and pointer events. Any DisplayObject can be interactive
       if its interactive parameter is set to true
       This manager also supports multitouch.

       An instance of this class is automatically created by default, and can be found at renderer.plugins.interaction
       */
      type t = T.interactionManager;
      type createOptions;
      /*
       The options for the manager.
       */
      external mkCreateOptions :
        autoPreventDefault::Js.boolean? => interactionFrequency::float? => unit => createOptions =
        "" [@@bs.obj];
      external create :
        renderer::unit /* unknown js type: PIXI.CanvasRenderer|PIXI.WebGLRenderer */ =>
        options::createOptions? =>
        unit =>
        t =
        "InteractionManager"
        [@@bs.new] [@@bs.scope "interaction"] [@@bs.module ("pixi.js", "PIXI")];
      /*
       The renderer this interaction manager works for.
       */
      external renderer : t => T.systemRenderer = "" [@@bs.get];
      /*
       The renderer this interaction manager works for.
       */
      external setRenderer : t => T.systemRenderer => unit = "renderer" [@@bs.set];
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
      external mouse : t => T.interactionData = "" [@@bs.get];
      /*
       The mouse data
       */
      external setMouse : t => T.interactionData => unit = "mouse" [@@bs.set];
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
      /*
       Hit tests a point against the display tree, returning the first interactive object that is hit.
       */
      external hitTest : globalPoint::T.point => root::T.container? => T.displayObject =
        "" [@@bs.send.pipe : t];
      /*
       Updates the state of interactive objects.
       Invoked by a throttled ticker update from {@link PIXI.ticker.shared}.
       */
      external update : deltaTime::float => unit = "" [@@bs.send.pipe : t];
      /*
       Sets the current cursor mode, handling any callbacks or CSS style changes.
       */
      external setCursorMode : mode::string => unit = "" [@@bs.send.pipe : t];
      /*
       Maps x and y coords from a DOM object and maps them correctly to the pixi view. The
       resulting value is stored in the point. This takes into account the fact that the DOM
       element could be scaled and positioned anywhere on the screen.
       */
      external mapPositionToPoint : point::T.point => x::float => y::float => unit =
        "" [@@bs.send.pipe : t];
      /*
       Destroys the interaction manager
       */
      external destroy : unit = "" [@@bs.send.pipe : t];
    };
  };
  module Loaders = {
    module Resource = {
      type t = T.resource;
      external create : unit => t =
        "Resource" [@@bs.new] [@@bs.scope "loaders"] [@@bs.module ("pixi.js", "PIXI")];
    };
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
      type t = T.loader;
      external create : baseUrl::string? => concurrency::float? => unit => t =
        "Loader" [@@bs.new] [@@bs.scope "loaders"] [@@bs.module ("pixi.js", "PIXI")];
      /*
       Destroy the loader, removes references.
       */
      external destroy : unit = "" [@@bs.send.pipe : t];
    };
  };
  module Mesh = {
    module Mesh = {
      /*
       Base mesh class
       */
      type t = T.mesh;
      external create :
        texture::T.texture =>
        vertices::Js_typed_array.Float32Array.t? =>
        uvs::Js_typed_array.Float32Array.t? =>
        indices::Js_typed_array.Uint16Array.t? =>
        drawMode::float? =>
        unit =>
        t =
        "Mesh" [@@bs.new] [@@bs.scope "mesh"] [@@bs.module ("pixi.js", "PIXI")];
      /*
       The Uvs of the Mesh
       */
      external uvs : t => Js_typed_array.Float32Array.t = "" [@@bs.get];
      /*
       The Uvs of the Mesh
       */
      external setUvs : t => Js_typed_array.Float32Array.t => unit = "uvs" [@@bs.set];
      /*
       An array of vertices
       */
      external vertices : t => Js_typed_array.Float32Array.t = "" [@@bs.get];
      /*
       An array of vertices
       */
      external setVertices : t => Js_typed_array.Float32Array.t => unit = "vertices" [@@bs.set];
      /*
       An array containing the indices of the vertices
       */
      external indices : t => Js_typed_array.Uint16Array.t = "" [@@bs.get];
      /*
       An array containing the indices of the vertices
       */
      external setIndices : t => Js_typed_array.Uint16Array.t => unit = "indices" [@@bs.set];
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
      external shader : t => T.shader = "" [@@bs.get];
      /*
       The default shader that is used if a mesh doesn't have a more specific one.
       */
      external setShader : t => T.shader => unit = "shader" [@@bs.set];
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
      external texture : t => T.texture = "" [@@bs.get];
      /*
       The texture that the mesh uses.
       */
      external setTexture : t => T.texture => unit = "texture" [@@bs.set];
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
      external children : t => array T.displayObject = "" [@@bs.get];
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
      external transform : t => T.transformBase = "" [@@bs.get];
      /*
       World transform and local transform of this object.
       This will become read-only later, please do not assign anything there unless you know what are you doing
       */
      external setTransform : t => T.transformBase => unit = "transform" [@@bs.set];
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
      external parent : t => T.container = "" [@@bs.get];
      /*
       The multiplied alpha of the displayObject
       */
      external worldAlpha : t => float = "" [@@bs.get];
      /*
       The area the filter is applied to. This is used as more of an optimisation
       rather than figuring out the dimensions of the displayObject each frame you can set this rectangle

       Also works as an interaction mask
       */
      external filterArea : t => T.rectangle = "" [@@bs.get];
      /*
       The area the filter is applied to. This is used as more of an optimisation
       rather than figuring out the dimensions of the displayObject each frame you can set this rectangle

       Also works as an interaction mask
       */
      external setFilterArea : t => T.rectangle => unit = "filterArea" [@@bs.set];
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
      external worldTransform : t => T.matrix = "" [@@bs.get];
      /*
       Current transform of the object based on local factors: position, scale, other stuff
       */
      external localTransform : t => T.matrix = "" [@@bs.get];
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
      external setPosition :
        t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
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
      external skew : t => T.observablePoint = "" [@@bs.get];
      /*
       The skew factor for the object in radians.
       Assignment by value since pixi-v4.
       */
      external setSkew : t => T.observablePoint => unit = "skew" [@@bs.set];
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
      external filters : t => array T.filter = "" [@@bs.get];
      /*
       Sets the filters for the displayObject.

       <ul>
       <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
       To remove filters simply set this property to 'null'</li>
       </ul>
       */
      external setFilters : t => array T.filter => unit = "filters" [@@bs.set];
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
      /*
       multiplies uvs only if uploadUvTransform is false
       call it after you change uvs manually
       make sure that texture is valid
       */
      external multiplyUvs : unit = "" [@@bs.send.pipe : t];
      /*
       Refreshes uvs for generated meshes (rope, plane)
       sometimes refreshes vertices too
       */
      external refresh : forceUpdate::Js.boolean? => unit = "" [@@bs.send.pipe : t];
      /*
       re-calculates mesh coords
       */
      external _refresh : unit = "" [@@bs.send.pipe : t];
      /*
       Returns the bounds of the mesh as a rectangle. The bounds calculation takes the worldTransform into account.
       */
      external _calculateBounds : unit = "" [@@bs.send.pipe : t];
      /*
       Tests if a point is inside this mesh. Works only for TRIANGLE_MESH
       */
      external containsPoint : point::T.point => Js.boolean = "" [@@bs.send.pipe : t];
      /*
       Adds one or more children to the container.

       <p>Multiple items can be added like so: <code>myContainer.addChild(thingOne, thingTwo, thingThree)</code></p>
       */
      external addChild : child::T.displayObject => T.displayObject = "" [@@bs.send.pipe : t];
      /*
       Adds a child to the container at a specified index. If the index is out of bounds an error will be thrown
       */
      external addChildAt : child::T.displayObject => index::float => T.displayObject =
        "" [@@bs.send.pipe : t];
      /*
       Swaps the position of 2 Display Objects within this container.
       */
      external swapChildren : child::T.displayObject => child2::T.displayObject => unit =
        "" [@@bs.send.pipe : t];
      /*
       Returns the index position of a child DisplayObject instance
       */
      external getChildIndex : child::T.displayObject => float = "" [@@bs.send.pipe : t];
      /*
       Changes the position of an existing child in the display object container
       */
      external setChildIndex : child::T.displayObject => index::float => unit =
        "" [@@bs.send.pipe : t];
      /*
       Returns the child at the specified index
       */
      external getChildAt : index::float => T.displayObject = "" [@@bs.send.pipe : t];
      /*
       Removes one or more children from the container.
       */
      external removeChild : child::T.displayObject => T.displayObject = "" [@@bs.send.pipe : t];
      /*
       Removes a child from the specified index position.
       */
      external removeChildAt : index::float => T.displayObject = "" [@@bs.send.pipe : t];
      /*
       Removes all children from this container that are within the begin and end indexes.
       */
      external removeChildren : beginIndex::float? => endIndex::float? => array T.displayObject =
        "" [@@bs.send.pipe : t];
      /*
       Updates the transform on all children of this container for rendering
       */
      external updateTransform : unit = "" [@@bs.send.pipe : t];
      /*
       Recalculates the bounds of the container.
       */
      external calculateBounds : unit = "" [@@bs.send.pipe : t];
      /*
       Renders the object using the WebGL renderer
       */
      external renderWebGL : renderer::T.webGLRenderer => unit = "" [@@bs.send.pipe : t];
      /*
       Renders the object using the Canvas renderer
       */
      external renderCanvas : renderer::T.canvasRenderer => unit = "" [@@bs.send.pipe : t];
      /*
       <p>Removes all internal references and listeners as well as removes children from the display list.
       Do not use a Container after calling <code>destroy</code>.</p>
       */
      external destroy : options::unit /* unknown js type: object|boolean */? => unit =
        "" [@@bs.send.pipe : t];
      /*
       recursively updates transform of all objects from the root to this one
       internal function for toLocal()
       */
      external _recursivePostUpdateTransform : unit = "" [@@bs.send.pipe : t];
      /*
       Retrieves the bounds of the displayObject as a rectangle object.
       */
      external getBounds : skipUpdate::Js.boolean => rect::T.rectangle => T.rectangle =
        "" [@@bs.send.pipe : t];
      /*
       Retrieves the local bounds of the displayObject as a rectangle object
       */
      external getLocalBounds : rect::T.rectangle? => T.rectangle = "" [@@bs.send.pipe : t];
      /*
       Calculates the global position of the display object
       */
      external toGlobal :
        position::T.point => point::T.point? => skipUpdate::Js.boolean? => T.point =
        "" [@@bs.send.pipe : t];
      /*
       Calculates the local position of the display object relative to another point
       */
      external toLocal :
        position::T.point =>
        from::T.displayObject? =>
        point::T.point? =>
        skipUpdate::Js.boolean? =>
        T.point =
        "" [@@bs.send.pipe : t];
      /*
       Set the parent Container of this DisplayObject
       */
      external setParent : container::T.container => T.container = "" [@@bs.send.pipe : t];
      /*
       Convenience function to set the position, scale, skew and pivot at once.
       */
      external setTransform :
        x::float? =>
        y::float? =>
        scaleX::float? =>
        scaleY::float? =>
        rotation::float? =>
        skewX::float? =>
        skewY::float? =>
        pivotX::float? =>
        pivotY::float? =>
        T.displayObject =
        "" [@@bs.send.pipe : t];
    };
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
      type t = T.nineSlicePlane;
      external create :
        texture::T.texture =>
        leftWidth::unit /* unknown js type: int */? =>
        topHeight::unit /* unknown js type: int */? =>
        rightWidth::unit /* unknown js type: int */? =>
        bottomHeight::unit /* unknown js type: int */? =>
        unit =>
        t =
        "NineSlicePlane" [@@bs.new] [@@bs.scope "mesh"] [@@bs.module ("pixi.js", "PIXI")];
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
      external uvs : t => Js_typed_array.Float32Array.t = "" [@@bs.get];
      /*
       The Uvs of the Mesh
       */
      external setUvs : t => Js_typed_array.Float32Array.t => unit = "uvs" [@@bs.set];
      /*
       An array of vertices
       */
      external vertices : t => Js_typed_array.Float32Array.t = "" [@@bs.get];
      /*
       An array of vertices
       */
      external setVertices : t => Js_typed_array.Float32Array.t => unit = "vertices" [@@bs.set];
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
      external shader : t => T.shader = "" [@@bs.get];
      /*
       The default shader that is used if a mesh doesn't have a more specific one.
       */
      external setShader : t => T.shader => unit = "shader" [@@bs.set];
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
      external texture : t => T.texture = "" [@@bs.get];
      /*
       The texture that the mesh uses.
       */
      external setTexture : t => T.texture => unit = "texture" [@@bs.set];
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
      external children : t => array T.displayObject = "" [@@bs.get];
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
      external transform : t => T.transformBase = "" [@@bs.get];
      /*
       World transform and local transform of this object.
       This will become read-only later, please do not assign anything there unless you know what are you doing
       */
      external setTransform : t => T.transformBase => unit = "transform" [@@bs.set];
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
      external parent : t => T.container = "" [@@bs.get];
      /*
       The multiplied alpha of the displayObject
       */
      external worldAlpha : t => float = "" [@@bs.get];
      /*
       The area the filter is applied to. This is used as more of an optimisation
       rather than figuring out the dimensions of the displayObject each frame you can set this rectangle

       Also works as an interaction mask
       */
      external filterArea : t => T.rectangle = "" [@@bs.get];
      /*
       The area the filter is applied to. This is used as more of an optimisation
       rather than figuring out the dimensions of the displayObject each frame you can set this rectangle

       Also works as an interaction mask
       */
      external setFilterArea : t => T.rectangle => unit = "filterArea" [@@bs.set];
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
      external worldTransform : t => T.matrix = "" [@@bs.get];
      /*
       Current transform of the object based on local factors: position, scale, other stuff
       */
      external localTransform : t => T.matrix = "" [@@bs.get];
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
      external setPosition :
        t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
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
      external skew : t => T.observablePoint = "" [@@bs.get];
      /*
       The skew factor for the object in radians.
       Assignment by value since pixi-v4.
       */
      external setSkew : t => T.observablePoint => unit = "skew" [@@bs.set];
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
      external filters : t => array T.filter = "" [@@bs.get];
      /*
       Sets the filters for the displayObject.

       <ul>
       <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
       To remove filters simply set this property to 'null'</li>
       </ul>
       */
      external setFilters : t => array T.filter => unit = "filters" [@@bs.set];
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
      /*
       Updates the horizontal vertices.
       */
      external updateHorizontalVertices : unit = "" [@@bs.send.pipe : t];
      /*
       Updates the vertical vertices.
       */
      external updateVerticalVertices : unit = "" [@@bs.send.pipe : t];
      /*
       Refreshes NineSlicePlane coords. All of them.
       */
      external _refresh : unit = "" [@@bs.send.pipe : t];
      /*
       multiplies uvs only if uploadUvTransform is false
       call it after you change uvs manually
       make sure that texture is valid
       */
      external multiplyUvs : unit = "" [@@bs.send.pipe : t];
      /*
       Refreshes uvs for generated meshes (rope, plane)
       sometimes refreshes vertices too
       */
      external refresh : forceUpdate::Js.boolean? => unit = "" [@@bs.send.pipe : t];
      /*
       Returns the bounds of the mesh as a rectangle. The bounds calculation takes the worldTransform into account.
       */
      external _calculateBounds : unit = "" [@@bs.send.pipe : t];
      /*
       Tests if a point is inside this mesh. Works only for TRIANGLE_MESH
       */
      external containsPoint : point::T.point => Js.boolean = "" [@@bs.send.pipe : t];
      /*
       Adds one or more children to the container.

       <p>Multiple items can be added like so: <code>myContainer.addChild(thingOne, thingTwo, thingThree)</code></p>
       */
      external addChild : child::T.displayObject => T.displayObject = "" [@@bs.send.pipe : t];
      /*
       Adds a child to the container at a specified index. If the index is out of bounds an error will be thrown
       */
      external addChildAt : child::T.displayObject => index::float => T.displayObject =
        "" [@@bs.send.pipe : t];
      /*
       Swaps the position of 2 Display Objects within this container.
       */
      external swapChildren : child::T.displayObject => child2::T.displayObject => unit =
        "" [@@bs.send.pipe : t];
      /*
       Returns the index position of a child DisplayObject instance
       */
      external getChildIndex : child::T.displayObject => float = "" [@@bs.send.pipe : t];
      /*
       Changes the position of an existing child in the display object container
       */
      external setChildIndex : child::T.displayObject => index::float => unit =
        "" [@@bs.send.pipe : t];
      /*
       Returns the child at the specified index
       */
      external getChildAt : index::float => T.displayObject = "" [@@bs.send.pipe : t];
      /*
       Removes one or more children from the container.
       */
      external removeChild : child::T.displayObject => T.displayObject = "" [@@bs.send.pipe : t];
      /*
       Removes a child from the specified index position.
       */
      external removeChildAt : index::float => T.displayObject = "" [@@bs.send.pipe : t];
      /*
       Removes all children from this container that are within the begin and end indexes.
       */
      external removeChildren : beginIndex::float? => endIndex::float? => array T.displayObject =
        "" [@@bs.send.pipe : t];
      /*
       Updates the transform on all children of this container for rendering
       */
      external updateTransform : unit = "" [@@bs.send.pipe : t];
      /*
       Recalculates the bounds of the container.
       */
      external calculateBounds : unit = "" [@@bs.send.pipe : t];
      /*
       Renders the object using the WebGL renderer
       */
      external renderWebGL : renderer::T.webGLRenderer => unit = "" [@@bs.send.pipe : t];
      /*
       Renders the object using the Canvas renderer
       */
      external renderCanvas : renderer::T.canvasRenderer => unit = "" [@@bs.send.pipe : t];
      /*
       <p>Removes all internal references and listeners as well as removes children from the display list.
       Do not use a Container after calling <code>destroy</code>.</p>
       */
      external destroy : options::unit /* unknown js type: object|boolean */? => unit =
        "" [@@bs.send.pipe : t];
      /*
       recursively updates transform of all objects from the root to this one
       internal function for toLocal()
       */
      external _recursivePostUpdateTransform : unit = "" [@@bs.send.pipe : t];
      /*
       Retrieves the bounds of the displayObject as a rectangle object.
       */
      external getBounds : skipUpdate::Js.boolean => rect::T.rectangle => T.rectangle =
        "" [@@bs.send.pipe : t];
      /*
       Retrieves the local bounds of the displayObject as a rectangle object
       */
      external getLocalBounds : rect::T.rectangle? => T.rectangle = "" [@@bs.send.pipe : t];
      /*
       Calculates the global position of the display object
       */
      external toGlobal :
        position::T.point => point::T.point? => skipUpdate::Js.boolean? => T.point =
        "" [@@bs.send.pipe : t];
      /*
       Calculates the local position of the display object relative to another point
       */
      external toLocal :
        position::T.point =>
        from::T.displayObject? =>
        point::T.point? =>
        skipUpdate::Js.boolean? =>
        T.point =
        "" [@@bs.send.pipe : t];
      /*
       Set the parent Container of this DisplayObject
       */
      external setParent : container::T.container => T.container = "" [@@bs.send.pipe : t];
      /*
       Convenience function to set the position, scale, skew and pivot at once.
       */
      external setTransform :
        x::float? =>
        y::float? =>
        scaleX::float? =>
        scaleY::float? =>
        rotation::float? =>
        skewX::float? =>
        skewY::float? =>
        pivotX::float? =>
        pivotY::float? =>
        T.displayObject =
        "" [@@bs.send.pipe : t];
    };
    module Plane = {
      /*
       The Plane allows you to draw a texture across several points and them manipulate these points

       <pre class="prettyprint source lang-js"><code>for (let i = 0; i &lt; 20; i++) {
           points.push(new PIXI.Point(i * 50, 0));
       };
       let Plane = new PIXI.Plane(PIXI.Texture.fromImage(&quot;snake.png&quot;), points);</code></pre>
       */
      type t = T.plane;
      external create : texture::T.texture => verticesX::float => verticesY::float => unit => t =
        "Plane" [@@bs.new] [@@bs.scope "mesh"] [@@bs.module ("pixi.js", "PIXI")];
      /*
       The Uvs of the Mesh
       */
      external uvs : t => Js_typed_array.Float32Array.t = "" [@@bs.get];
      /*
       The Uvs of the Mesh
       */
      external setUvs : t => Js_typed_array.Float32Array.t => unit = "uvs" [@@bs.set];
      /*
       An array of vertices
       */
      external vertices : t => Js_typed_array.Float32Array.t = "" [@@bs.get];
      /*
       An array of vertices
       */
      external setVertices : t => Js_typed_array.Float32Array.t => unit = "vertices" [@@bs.set];
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
      external shader : t => T.shader = "" [@@bs.get];
      /*
       The default shader that is used if a mesh doesn't have a more specific one.
       */
      external setShader : t => T.shader => unit = "shader" [@@bs.set];
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
      external texture : t => T.texture = "" [@@bs.get];
      /*
       The texture that the mesh uses.
       */
      external setTexture : t => T.texture => unit = "texture" [@@bs.set];
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
      external children : t => array T.displayObject = "" [@@bs.get];
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
      external transform : t => T.transformBase = "" [@@bs.get];
      /*
       World transform and local transform of this object.
       This will become read-only later, please do not assign anything there unless you know what are you doing
       */
      external setTransform : t => T.transformBase => unit = "transform" [@@bs.set];
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
      external parent : t => T.container = "" [@@bs.get];
      /*
       The multiplied alpha of the displayObject
       */
      external worldAlpha : t => float = "" [@@bs.get];
      /*
       The area the filter is applied to. This is used as more of an optimisation
       rather than figuring out the dimensions of the displayObject each frame you can set this rectangle

       Also works as an interaction mask
       */
      external filterArea : t => T.rectangle = "" [@@bs.get];
      /*
       The area the filter is applied to. This is used as more of an optimisation
       rather than figuring out the dimensions of the displayObject each frame you can set this rectangle

       Also works as an interaction mask
       */
      external setFilterArea : t => T.rectangle => unit = "filterArea" [@@bs.set];
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
      external worldTransform : t => T.matrix = "" [@@bs.get];
      /*
       Current transform of the object based on local factors: position, scale, other stuff
       */
      external localTransform : t => T.matrix = "" [@@bs.get];
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
      external setPosition :
        t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
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
      external skew : t => T.observablePoint = "" [@@bs.get];
      /*
       The skew factor for the object in radians.
       Assignment by value since pixi-v4.
       */
      external setSkew : t => T.observablePoint => unit = "skew" [@@bs.set];
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
      external filters : t => array T.filter = "" [@@bs.get];
      /*
       Sets the filters for the displayObject.

       <ul>
       <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
       To remove filters simply set this property to 'null'</li>
       </ul>
       */
      external setFilters : t => array T.filter => unit = "filters" [@@bs.set];
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
      /*
       Refreshes plane coordinates
       */
      external _refresh : unit = "" [@@bs.send.pipe : t];
      /*
       multiplies uvs only if uploadUvTransform is false
       call it after you change uvs manually
       make sure that texture is valid
       */
      external multiplyUvs : unit = "" [@@bs.send.pipe : t];
      /*
       Refreshes uvs for generated meshes (rope, plane)
       sometimes refreshes vertices too
       */
      external refresh : forceUpdate::Js.boolean? => unit = "" [@@bs.send.pipe : t];
      /*
       Returns the bounds of the mesh as a rectangle. The bounds calculation takes the worldTransform into account.
       */
      external _calculateBounds : unit = "" [@@bs.send.pipe : t];
      /*
       Tests if a point is inside this mesh. Works only for TRIANGLE_MESH
       */
      external containsPoint : point::T.point => Js.boolean = "" [@@bs.send.pipe : t];
      /*
       Adds one or more children to the container.

       <p>Multiple items can be added like so: <code>myContainer.addChild(thingOne, thingTwo, thingThree)</code></p>
       */
      external addChild : child::T.displayObject => T.displayObject = "" [@@bs.send.pipe : t];
      /*
       Adds a child to the container at a specified index. If the index is out of bounds an error will be thrown
       */
      external addChildAt : child::T.displayObject => index::float => T.displayObject =
        "" [@@bs.send.pipe : t];
      /*
       Swaps the position of 2 Display Objects within this container.
       */
      external swapChildren : child::T.displayObject => child2::T.displayObject => unit =
        "" [@@bs.send.pipe : t];
      /*
       Returns the index position of a child DisplayObject instance
       */
      external getChildIndex : child::T.displayObject => float = "" [@@bs.send.pipe : t];
      /*
       Changes the position of an existing child in the display object container
       */
      external setChildIndex : child::T.displayObject => index::float => unit =
        "" [@@bs.send.pipe : t];
      /*
       Returns the child at the specified index
       */
      external getChildAt : index::float => T.displayObject = "" [@@bs.send.pipe : t];
      /*
       Removes one or more children from the container.
       */
      external removeChild : child::T.displayObject => T.displayObject = "" [@@bs.send.pipe : t];
      /*
       Removes a child from the specified index position.
       */
      external removeChildAt : index::float => T.displayObject = "" [@@bs.send.pipe : t];
      /*
       Removes all children from this container that are within the begin and end indexes.
       */
      external removeChildren : beginIndex::float? => endIndex::float? => array T.displayObject =
        "" [@@bs.send.pipe : t];
      /*
       Updates the transform on all children of this container for rendering
       */
      external updateTransform : unit = "" [@@bs.send.pipe : t];
      /*
       Recalculates the bounds of the container.
       */
      external calculateBounds : unit = "" [@@bs.send.pipe : t];
      /*
       Renders the object using the WebGL renderer
       */
      external renderWebGL : renderer::T.webGLRenderer => unit = "" [@@bs.send.pipe : t];
      /*
       Renders the object using the Canvas renderer
       */
      external renderCanvas : renderer::T.canvasRenderer => unit = "" [@@bs.send.pipe : t];
      /*
       <p>Removes all internal references and listeners as well as removes children from the display list.
       Do not use a Container after calling <code>destroy</code>.</p>
       */
      external destroy : options::unit /* unknown js type: object|boolean */? => unit =
        "" [@@bs.send.pipe : t];
      /*
       recursively updates transform of all objects from the root to this one
       internal function for toLocal()
       */
      external _recursivePostUpdateTransform : unit = "" [@@bs.send.pipe : t];
      /*
       Retrieves the bounds of the displayObject as a rectangle object.
       */
      external getBounds : skipUpdate::Js.boolean => rect::T.rectangle => T.rectangle =
        "" [@@bs.send.pipe : t];
      /*
       Retrieves the local bounds of the displayObject as a rectangle object
       */
      external getLocalBounds : rect::T.rectangle? => T.rectangle = "" [@@bs.send.pipe : t];
      /*
       Calculates the global position of the display object
       */
      external toGlobal :
        position::T.point => point::T.point? => skipUpdate::Js.boolean? => T.point =
        "" [@@bs.send.pipe : t];
      /*
       Calculates the local position of the display object relative to another point
       */
      external toLocal :
        position::T.point =>
        from::T.displayObject? =>
        point::T.point? =>
        skipUpdate::Js.boolean? =>
        T.point =
        "" [@@bs.send.pipe : t];
      /*
       Set the parent Container of this DisplayObject
       */
      external setParent : container::T.container => T.container = "" [@@bs.send.pipe : t];
      /*
       Convenience function to set the position, scale, skew and pivot at once.
       */
      external setTransform :
        x::float? =>
        y::float? =>
        scaleX::float? =>
        scaleY::float? =>
        rotation::float? =>
        skewX::float? =>
        skewY::float? =>
        pivotX::float? =>
        pivotY::float? =>
        T.displayObject =
        "" [@@bs.send.pipe : t];
    };
    module Rope = {
      /*
       The rope allows you to draw a texture across several points and them manipulate these points

       <pre class="prettyprint source lang-js"><code>for (let i = 0; i &lt; 20; i++) {
           points.push(new PIXI.Point(i * 50, 0));
       };
       let rope = new PIXI.Rope(PIXI.Texture.fromImage(&quot;snake.png&quot;), points);</code></pre>
       */
      type t = T.rope;
      external create : texture::T.texture => points::array T.point => unit => t =
        "Rope" [@@bs.new] [@@bs.scope "mesh"] [@@bs.module ("pixi.js", "PIXI")];
      /*
       An array of points that determine the rope
       */
      external points : t => array T.point = "" [@@bs.get];
      /*
       An array of points that determine the rope
       */
      external setPoints : t => array T.point => unit = "points" [@@bs.set];
      /*
       An array of vertices used to construct this rope.
       */
      external vertices : t => Js_typed_array.Float32Array.t = "" [@@bs.get];
      /*
       An array of vertices used to construct this rope.
       */
      external setVertices : t => Js_typed_array.Float32Array.t => unit = "vertices" [@@bs.set];
      /*
       The WebGL Uvs of the rope.
       */
      external uvs : t => Js_typed_array.Float32Array.t = "" [@@bs.get];
      /*
       The WebGL Uvs of the rope.
       */
      external setUvs : t => Js_typed_array.Float32Array.t => unit = "uvs" [@@bs.set];
      /*
       An array containing the color components
       */
      external colors : t => Js_typed_array.Float32Array.t = "" [@@bs.get];
      /*
       An array containing the color components
       */
      external setColors : t => Js_typed_array.Float32Array.t => unit = "colors" [@@bs.set];
      /*
       An array containing the indices of the vertices
       */
      external indices : t => Js_typed_array.Uint16Array.t = "" [@@bs.get];
      /*
       An array containing the indices of the vertices
       */
      external setIndices : t => Js_typed_array.Uint16Array.t => unit = "indices" [@@bs.set];
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
      external shader : t => T.shader = "" [@@bs.get];
      /*
       The default shader that is used if a mesh doesn't have a more specific one.
       */
      external setShader : t => T.shader => unit = "shader" [@@bs.set];
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
      external texture : t => T.texture = "" [@@bs.get];
      /*
       The texture that the mesh uses.
       */
      external setTexture : t => T.texture => unit = "texture" [@@bs.set];
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
      external children : t => array T.displayObject = "" [@@bs.get];
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
      external transform : t => T.transformBase = "" [@@bs.get];
      /*
       World transform and local transform of this object.
       This will become read-only later, please do not assign anything there unless you know what are you doing
       */
      external setTransform : t => T.transformBase => unit = "transform" [@@bs.set];
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
      external parent : t => T.container = "" [@@bs.get];
      /*
       The multiplied alpha of the displayObject
       */
      external worldAlpha : t => float = "" [@@bs.get];
      /*
       The area the filter is applied to. This is used as more of an optimisation
       rather than figuring out the dimensions of the displayObject each frame you can set this rectangle

       Also works as an interaction mask
       */
      external filterArea : t => T.rectangle = "" [@@bs.get];
      /*
       The area the filter is applied to. This is used as more of an optimisation
       rather than figuring out the dimensions of the displayObject each frame you can set this rectangle

       Also works as an interaction mask
       */
      external setFilterArea : t => T.rectangle => unit = "filterArea" [@@bs.set];
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
      external worldTransform : t => T.matrix = "" [@@bs.get];
      /*
       Current transform of the object based on local factors: position, scale, other stuff
       */
      external localTransform : t => T.matrix = "" [@@bs.get];
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
      external setPosition :
        t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
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
      external skew : t => T.observablePoint = "" [@@bs.get];
      /*
       The skew factor for the object in radians.
       Assignment by value since pixi-v4.
       */
      external setSkew : t => T.observablePoint => unit = "skew" [@@bs.set];
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
      external filters : t => array T.filter = "" [@@bs.get];
      /*
       Sets the filters for the displayObject.

       <ul>
       <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
       To remove filters simply set this property to 'null'</li>
       </ul>
       */
      external setFilters : t => array T.filter => unit = "filters" [@@bs.set];
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
      /*
       Refreshes
       */
      external _refresh : unit = "" [@@bs.send.pipe : t];
      /*
       refreshes vertices of Rope mesh
       */
      external refreshVertices : unit = "" [@@bs.send.pipe : t];
      /*
       multiplies uvs only if uploadUvTransform is false
       call it after you change uvs manually
       make sure that texture is valid
       */
      external multiplyUvs : unit = "" [@@bs.send.pipe : t];
      /*
       Refreshes uvs for generated meshes (rope, plane)
       sometimes refreshes vertices too
       */
      external refresh : forceUpdate::Js.boolean? => unit = "" [@@bs.send.pipe : t];
      /*
       Returns the bounds of the mesh as a rectangle. The bounds calculation takes the worldTransform into account.
       */
      external _calculateBounds : unit = "" [@@bs.send.pipe : t];
      /*
       Tests if a point is inside this mesh. Works only for TRIANGLE_MESH
       */
      external containsPoint : point::T.point => Js.boolean = "" [@@bs.send.pipe : t];
      /*
       Adds one or more children to the container.

       <p>Multiple items can be added like so: <code>myContainer.addChild(thingOne, thingTwo, thingThree)</code></p>
       */
      external addChild : child::T.displayObject => T.displayObject = "" [@@bs.send.pipe : t];
      /*
       Adds a child to the container at a specified index. If the index is out of bounds an error will be thrown
       */
      external addChildAt : child::T.displayObject => index::float => T.displayObject =
        "" [@@bs.send.pipe : t];
      /*
       Swaps the position of 2 Display Objects within this container.
       */
      external swapChildren : child::T.displayObject => child2::T.displayObject => unit =
        "" [@@bs.send.pipe : t];
      /*
       Returns the index position of a child DisplayObject instance
       */
      external getChildIndex : child::T.displayObject => float = "" [@@bs.send.pipe : t];
      /*
       Changes the position of an existing child in the display object container
       */
      external setChildIndex : child::T.displayObject => index::float => unit =
        "" [@@bs.send.pipe : t];
      /*
       Returns the child at the specified index
       */
      external getChildAt : index::float => T.displayObject = "" [@@bs.send.pipe : t];
      /*
       Removes one or more children from the container.
       */
      external removeChild : child::T.displayObject => T.displayObject = "" [@@bs.send.pipe : t];
      /*
       Removes a child from the specified index position.
       */
      external removeChildAt : index::float => T.displayObject = "" [@@bs.send.pipe : t];
      /*
       Removes all children from this container that are within the begin and end indexes.
       */
      external removeChildren : beginIndex::float? => endIndex::float? => array T.displayObject =
        "" [@@bs.send.pipe : t];
      /*
       Recalculates the bounds of the container.
       */
      external calculateBounds : unit = "" [@@bs.send.pipe : t];
      /*
       Renders the object using the WebGL renderer
       */
      external renderWebGL : renderer::T.webGLRenderer => unit = "" [@@bs.send.pipe : t];
      /*
       Renders the object using the Canvas renderer
       */
      external renderCanvas : renderer::T.canvasRenderer => unit = "" [@@bs.send.pipe : t];
      /*
       <p>Removes all internal references and listeners as well as removes children from the display list.
       Do not use a Container after calling <code>destroy</code>.</p>
       */
      external destroy : options::unit /* unknown js type: object|boolean */? => unit =
        "" [@@bs.send.pipe : t];
      /*
       recursively updates transform of all objects from the root to this one
       internal function for toLocal()
       */
      external _recursivePostUpdateTransform : unit = "" [@@bs.send.pipe : t];
      /*
       Retrieves the bounds of the displayObject as a rectangle object.
       */
      external getBounds : skipUpdate::Js.boolean => rect::T.rectangle => T.rectangle =
        "" [@@bs.send.pipe : t];
      /*
       Retrieves the local bounds of the displayObject as a rectangle object
       */
      external getLocalBounds : rect::T.rectangle? => T.rectangle = "" [@@bs.send.pipe : t];
      /*
       Calculates the global position of the display object
       */
      external toGlobal :
        position::T.point => point::T.point? => skipUpdate::Js.boolean? => T.point =
        "" [@@bs.send.pipe : t];
      /*
       Calculates the local position of the display object relative to another point
       */
      external toLocal :
        position::T.point =>
        from::T.displayObject? =>
        point::T.point? =>
        skipUpdate::Js.boolean? =>
        T.point =
        "" [@@bs.send.pipe : t];
      /*
       Set the parent Container of this DisplayObject
       */
      external setParent : container::T.container => T.container = "" [@@bs.send.pipe : t];
      /*
       Convenience function to set the position, scale, skew and pivot at once.
       */
      external setTransform :
        x::float? =>
        y::float? =>
        scaleX::float? =>
        scaleY::float? =>
        rotation::float? =>
        skewX::float? =>
        skewY::float? =>
        pivotX::float? =>
        pivotY::float? =>
        T.displayObject =
        "" [@@bs.send.pipe : t];
    };
  };
  module MeshRenderer = {
    /*
     WebGL renderer plugin for tiling sprites
     */
    type t = T.meshRenderer;
    external create : renderer::T.webGLRenderer => unit => t =
      "MeshRenderer" [@@bs.new] [@@bs.module ("pixi.js", "PIXI")];
    /*
     The renderer this manager works for.
     */
    external renderer : t => T.webGLRenderer = "" [@@bs.get];
    /*
     The renderer this manager works for.
     */
    external setRenderer : t => T.webGLRenderer => unit = "renderer" [@@bs.set];
    /*
     renders mesh
     */
    external render : mesh::T.mesh => unit = "" [@@bs.send.pipe : t];
    /*
     Starts the renderer and sets the shader
     */
    external start : unit = "" [@@bs.send.pipe : t];
    /*
     Stops the renderer
     */
    external stop : unit = "" [@@bs.send.pipe : t];
    /*
     Stub method for rendering content and emptying the current batch.
     */
    external flush : unit = "" [@@bs.send.pipe : t];
    /*
     Generic destroy methods to be overridden by the subclass
     */
    external destroy : unit = "" [@@bs.send.pipe : t];
  };
  module Particles = {
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
      type t = T.particleContainer;
      type createProperties;
      /*
       The properties of children that should be uploaded to the gpu and applied.
       */
      external mkCreateProperties :
        scale::Js.boolean? =>
        position::Js.boolean? =>
        rotation::Js.boolean? =>
        uvs::Js.boolean? =>
        alpha::Js.boolean? =>
        unit =>
        createProperties =
        "" [@@bs.obj];
      external create :
        maxSize::float? => properties::createProperties? => batchSize::float? => unit => t =
        "ParticleContainer" [@@bs.new] [@@bs.scope "particles"] [@@bs.module ("pixi.js", "PIXI")];
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
      external baseTexture : t => T.baseTexture = "" [@@bs.get];
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
      external children : t => array T.displayObject = "" [@@bs.get];
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
      external transform : t => T.transformBase = "" [@@bs.get];
      /*
       World transform and local transform of this object.
       This will become read-only later, please do not assign anything there unless you know what are you doing
       */
      external setTransform : t => T.transformBase => unit = "transform" [@@bs.set];
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
      external parent : t => T.container = "" [@@bs.get];
      /*
       The multiplied alpha of the displayObject
       */
      external worldAlpha : t => float = "" [@@bs.get];
      /*
       The area the filter is applied to. This is used as more of an optimisation
       rather than figuring out the dimensions of the displayObject each frame you can set this rectangle

       Also works as an interaction mask
       */
      external filterArea : t => T.rectangle = "" [@@bs.get];
      /*
       The area the filter is applied to. This is used as more of an optimisation
       rather than figuring out the dimensions of the displayObject each frame you can set this rectangle

       Also works as an interaction mask
       */
      external setFilterArea : t => T.rectangle => unit = "filterArea" [@@bs.set];
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
      external worldTransform : t => T.matrix = "" [@@bs.get];
      /*
       Current transform of the object based on local factors: position, scale, other stuff
       */
      external localTransform : t => T.matrix = "" [@@bs.get];
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
      external setPosition :
        t => unit /* unknown js type: PIXI.Point|PIXI.ObservablePoint */ => unit =
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
      external skew : t => T.observablePoint = "" [@@bs.get];
      /*
       The skew factor for the object in radians.
       Assignment by value since pixi-v4.
       */
      external setSkew : t => T.observablePoint => unit = "skew" [@@bs.set];
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
      external filters : t => array T.filter = "" [@@bs.get];
      /*
       Sets the filters for the displayObject.

       <ul>
       <li>IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
       To remove filters simply set this property to 'null'</li>
       </ul>
       */
      external setFilters : t => array T.filter => unit = "filters" [@@bs.set];
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
      /*
       Sets the private properties array to dynamic / static based on the passed properties object
       */
      external setProperties : properties::unit /* unknown js type: object */ => unit =
        "" [@@bs.send.pipe : t];
      /*
       Destroys the container
       */
      external destroy : options::unit /* unknown js type: object|boolean */? => unit =
        "" [@@bs.send.pipe : t];
      /*
       Adds one or more children to the container.

       <p>Multiple items can be added like so: <code>myContainer.addChild(thingOne, thingTwo, thingThree)</code></p>
       */
      external addChild : child::T.displayObject => T.displayObject = "" [@@bs.send.pipe : t];
      /*
       Adds a child to the container at a specified index. If the index is out of bounds an error will be thrown
       */
      external addChildAt : child::T.displayObject => index::float => T.displayObject =
        "" [@@bs.send.pipe : t];
      /*
       Swaps the position of 2 Display Objects within this container.
       */
      external swapChildren : child::T.displayObject => child2::T.displayObject => unit =
        "" [@@bs.send.pipe : t];
      /*
       Returns the index position of a child DisplayObject instance
       */
      external getChildIndex : child::T.displayObject => float = "" [@@bs.send.pipe : t];
      /*
       Changes the position of an existing child in the display object container
       */
      external setChildIndex : child::T.displayObject => index::float => unit =
        "" [@@bs.send.pipe : t];
      /*
       Returns the child at the specified index
       */
      external getChildAt : index::float => T.displayObject = "" [@@bs.send.pipe : t];
      /*
       Removes one or more children from the container.
       */
      external removeChild : child::T.displayObject => T.displayObject = "" [@@bs.send.pipe : t];
      /*
       Removes a child from the specified index position.
       */
      external removeChildAt : index::float => T.displayObject = "" [@@bs.send.pipe : t];
      /*
       Removes all children from this container that are within the begin and end indexes.
       */
      external removeChildren : beginIndex::float? => endIndex::float? => array T.displayObject =
        "" [@@bs.send.pipe : t];
      /*
       Recalculates the bounds of the container.
       */
      external calculateBounds : unit = "" [@@bs.send.pipe : t];
      /*
       Recalculates the bounds of the object. Override this to
       calculate the bounds of the specific object (not including children).
       */
      external _calculateBounds : unit = "" [@@bs.send.pipe : t];
      /*
       recursively updates transform of all objects from the root to this one
       internal function for toLocal()
       */
      external _recursivePostUpdateTransform : unit = "" [@@bs.send.pipe : t];
      /*
       Retrieves the bounds of the displayObject as a rectangle object.
       */
      external getBounds : skipUpdate::Js.boolean => rect::T.rectangle => T.rectangle =
        "" [@@bs.send.pipe : t];
      /*
       Retrieves the local bounds of the displayObject as a rectangle object
       */
      external getLocalBounds : rect::T.rectangle? => T.rectangle = "" [@@bs.send.pipe : t];
      /*
       Calculates the global position of the display object
       */
      external toGlobal :
        position::T.point => point::T.point? => skipUpdate::Js.boolean? => T.point =
        "" [@@bs.send.pipe : t];
      /*
       Calculates the local position of the display object relative to another point
       */
      external toLocal :
        position::T.point =>
        from::T.displayObject? =>
        point::T.point? =>
        skipUpdate::Js.boolean? =>
        T.point =
        "" [@@bs.send.pipe : t];
      /*
       Set the parent Container of this DisplayObject
       */
      external setParent : container::T.container => T.container = "" [@@bs.send.pipe : t];
      /*
       Convenience function to set the position, scale, skew and pivot at once.
       */
      external setTransform :
        x::float? =>
        y::float? =>
        scaleX::float? =>
        scaleY::float? =>
        rotation::float? =>
        skewX::float? =>
        skewY::float? =>
        pivotX::float? =>
        pivotY::float? =>
        T.displayObject =
        "" [@@bs.send.pipe : t];
    };
  };
  module ParticleShader = {
    type t = T.particleShader;
    external create : gl::T.shader => unit => t =
      "ParticleShader" [@@bs.new] [@@bs.module ("pixi.js", "PIXI")];
  };
  module Prepare = {
    module BasePrepare = {
      /*
       The prepare manager provides functionality to upload content to the GPU. BasePrepare handles
       basic queuing functionality and is extended by {@link PIXI.prepare.WebGLPrepare} and {@link PIXI.prepare.CanvasPrepare}
       to provide preparation capabilities specific to their respective renderers.
       */
      type t = T.basePrepare;
      external create : renderer::T.systemRenderer => unit => t =
        "BasePrepare" [@@bs.new] [@@bs.scope "prepare"] [@@bs.module ("pixi.js", "PIXI")];
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
      external renderer : t => T.systemRenderer = "" [@@bs.get];
      /*
       Reference to the renderer.
       */
      external setRenderer : t => T.systemRenderer => unit = "renderer" [@@bs.set];
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
      /*
       Upload all the textures and graphics to the GPU.
       */
      external upload :
        item::
          unit /* unknown js type: function|PIXI.DisplayObject|PIXI.Container|PIXI.BaseTexture|PIXI.Texture|PIXI.Graphics|PIXI.Text */ =>
        done::unit /* unknown js type: function */? =>
        unit =
        "" [@@bs.send.pipe : t];
      /*
       Adds hooks for finding items.
       */
      external registerFindHook :
        addHook::unit /* unknown js type: function */ => unit /* unknown js type: PIXI.BasePrepare */ =
        "" [@@bs.send.pipe : t];
      /*
       Adds hooks for uploading items.
       */
      external registerUploadHook :
        uploadHook::unit /* unknown js type: function */ => unit /* unknown js type: PIXI.BasePrepare */ =
        "" [@@bs.send.pipe : t];
      /*
       Manually add an item to the uploading queue.
       */
      external add :
        item::unit /* unknown js type: PIXI.DisplayObject|PIXI.Container|PIXI.BaseTexture|PIXI.Texture|PIXI.Graphics|PIXI.Text|* */ => unit /* unknown js type: PIXI.CanvasPrepare */ =
        "" [@@bs.send.pipe : t];
      /*
       Destroys the plugin, don't use after this.
       */
      external destroy : unit = "" [@@bs.send.pipe : t];
    };
    module CanvasPrepare = {
      /*
       The prepare manager provides functionality to upload content to the GPU
       This cannot be done directly for Canvas like in WebGL, but the effect can be achieved by drawing
       textures to an offline canvas.
       This draw call will force the texture to be moved onto the GPU.

       An instance of this class is automatically created by default, and can be found at renderer.plugins.prepare
       */
      type t = T.canvasPrepare;
      external create : renderer::T.canvasRenderer => unit => t =
        "CanvasPrepare" [@@bs.new] [@@bs.scope "prepare"] [@@bs.module ("pixi.js", "PIXI")];
      /*
       Destroys the plugin, don't use after this.
       */
      external destroy : unit = "" [@@bs.send.pipe : t];
      /*
       Upload all the textures and graphics to the GPU.
       */
      external upload :
        item::
          unit /* unknown js type: function|PIXI.DisplayObject|PIXI.Container|PIXI.BaseTexture|PIXI.Texture|PIXI.Graphics|PIXI.Text */ =>
        done::unit /* unknown js type: function */? =>
        unit =
        "" [@@bs.send.pipe : t];
      /*
       Adds hooks for finding items.
       */
      external registerFindHook :
        addHook::unit /* unknown js type: function */ => unit /* unknown js type: PIXI.BasePrepare */ =
        "" [@@bs.send.pipe : t];
      /*
       Adds hooks for uploading items.
       */
      external registerUploadHook :
        uploadHook::unit /* unknown js type: function */ => unit /* unknown js type: PIXI.BasePrepare */ =
        "" [@@bs.send.pipe : t];
      /*
       Manually add an item to the uploading queue.
       */
      external add :
        item::unit /* unknown js type: PIXI.DisplayObject|PIXI.Container|PIXI.BaseTexture|PIXI.Texture|PIXI.Graphics|PIXI.Text|* */ => unit /* unknown js type: PIXI.CanvasPrepare */ =
        "" [@@bs.send.pipe : t];
    };
    module CountLimiter = {
      /*
       CountLimiter limits the number of items handled by a {@link PIXI.prepare.BasePrepare} to a specified
       number of items per frame.
       */
      type t = T.countLimiter;
      external create : maxItemsPerFrame::float => unit => t =
        "CountLimiter" [@@bs.new] [@@bs.scope "prepare"] [@@bs.module ("pixi.js", "PIXI")];
      /*
       Resets any counting properties to start fresh on a new frame.
       */
      external beginFrame : unit = "" [@@bs.send.pipe : t];
      /*
       Checks to see if another item can be uploaded. This should only be called once per item.
       */
      external allowedToUpload : Js.boolean = "" [@@bs.send.pipe : t];
    };
    module WebGLPrepare = {
      /*
       The prepare manager provides functionality to upload content to the GPU.

       An instance of this class is automatically created by default, and can be found at renderer.plugins.prepare
       */
      type t = T.webGLPrepare;
      external create : renderer::T.webGLRenderer => unit => t =
        "WebGLPrepare" [@@bs.new] [@@bs.scope "prepare"] [@@bs.module ("pixi.js", "PIXI")];
      /*
       Upload all the textures and graphics to the GPU.
       */
      external upload :
        item::
          unit /* unknown js type: function|PIXI.DisplayObject|PIXI.Container|PIXI.BaseTexture|PIXI.Texture|PIXI.Graphics|PIXI.Text */ =>
        done::unit /* unknown js type: function */? =>
        unit =
        "" [@@bs.send.pipe : t];
      /*
       Adds hooks for finding items.
       */
      external registerFindHook :
        addHook::unit /* unknown js type: function */ => unit /* unknown js type: PIXI.BasePrepare */ =
        "" [@@bs.send.pipe : t];
      /*
       Adds hooks for uploading items.
       */
      external registerUploadHook :
        uploadHook::unit /* unknown js type: function */ => unit /* unknown js type: PIXI.BasePrepare */ =
        "" [@@bs.send.pipe : t];
      /*
       Manually add an item to the uploading queue.
       */
      external add :
        item::unit /* unknown js type: PIXI.DisplayObject|PIXI.Container|PIXI.BaseTexture|PIXI.Texture|PIXI.Graphics|PIXI.Text|* */ => unit /* unknown js type: PIXI.CanvasPrepare */ =
        "" [@@bs.send.pipe : t];
      /*
       Destroys the plugin, don't use after this.
       */
      external destroy : unit = "" [@@bs.send.pipe : t];
    };
  };
  module TimeLimiter = {
    /*
     TimeLimiter limits the number of items handled by a {@link PIXI.BasePrepare} to a specified
     number of milliseconds per frame.
     */
    type t = T.timeLimiter;
    external create : maxMilliseconds::float => unit => t =
      "TimeLimiter" [@@bs.new] [@@bs.module ("pixi.js", "PIXI")];
    /*
     Resets any counting properties to start fresh on a new frame.
     */
    external beginFrame : unit = "" [@@bs.send.pipe : t];
    /*
     Checks to see if another item can be uploaded. This should only be called once per item.
     */
    external allowedToUpload : Js.boolean = "" [@@bs.send.pipe : t];
  };
};

type accessibilityManager;

type application;

type shader;

type bounds;

type container;

type displayObject;

type transform;

type transformBase;

type transformStatic;

type graphics;

type graphicsData;

type graphicsRenderer;

type primitiveShader;

type groupD8;

type matrix;

type observablePoint;

type point;

type circle;

type ellipse;

type polygon;

type rectangle;

type roundedRectangle;

type systemRenderer;

type canvasRenderer;

type canvasMaskManager;

type canvasRenderTarget;

type textureGarbageCollector;

type textureManager;

type webGLRenderer;

type webGLState;

type filter;

type spriteMaskFilter;

type blendModeManager;

type filterManager;

type maskManager;

type stencilManager;

type webGLManager;

type objectRenderer;

type quad;

type renderTarget;

type sprite;

type canvasTinter;

type buffer;

type text;

type textMetrics;

type fontMetrics;

type textStyle;

type baseRenderTexture;

type baseTexture;

type renderTexture;

type spritesheet;

type texture;

type videoBaseTexture;

type ticker;

type eventEmitter;

type canvasExtract;

type webGLExtract;

type animatedSprite;

type bitmapText;

type textureTransform;

type tilingSprite;

type tilingSpriteRenderer;

type blurFilter;

type blurXFilter;

type blurYFilter;

type colorMatrixFilter;

type displacementFilter;

type fxaaFilter;

type noiseFilter;

type voidFilter;

type interactionData;

type interactionEvent;

type interactionManager;

type resource;

type loader;

type mesh;

type nineSlicePlane;

type plane;

type rope;

type meshRenderer;

type particleContainer;

type particleShader;

type basePrepare;

type canvasPrepare;

type countLimiter;

type timeLimiter;

type webGLPrepare;

include
  Impl {
    type nonrec accessibilityManager = accessibilityManager;
    type nonrec application = application;
    type nonrec shader = shader;
    type nonrec bounds = bounds;
    type nonrec container = container;
    type nonrec displayObject = displayObject;
    type nonrec transform = transform;
    type nonrec transformBase = transformBase;
    type nonrec transformStatic = transformStatic;
    type nonrec graphics = graphics;
    type nonrec graphicsData = graphicsData;
    type nonrec graphicsRenderer = graphicsRenderer;
    type nonrec primitiveShader = primitiveShader;
    type nonrec groupD8 = groupD8;
    type nonrec matrix = matrix;
    type nonrec observablePoint = observablePoint;
    type nonrec point = point;
    type nonrec circle = circle;
    type nonrec ellipse = ellipse;
    type nonrec polygon = polygon;
    type nonrec rectangle = rectangle;
    type nonrec roundedRectangle = roundedRectangle;
    type nonrec systemRenderer = systemRenderer;
    type nonrec canvasRenderer = canvasRenderer;
    type nonrec canvasMaskManager = canvasMaskManager;
    type nonrec canvasRenderTarget = canvasRenderTarget;
    type nonrec textureGarbageCollector = textureGarbageCollector;
    type nonrec textureManager = textureManager;
    type nonrec webGLRenderer = webGLRenderer;
    type nonrec webGLState = webGLState;
    type nonrec filter = filter;
    type nonrec spriteMaskFilter = spriteMaskFilter;
    type nonrec blendModeManager = blendModeManager;
    type nonrec filterManager = filterManager;
    type nonrec maskManager = maskManager;
    type nonrec stencilManager = stencilManager;
    type nonrec webGLManager = webGLManager;
    type nonrec objectRenderer = objectRenderer;
    type nonrec quad = quad;
    type nonrec renderTarget = renderTarget;
    type nonrec sprite = sprite;
    type nonrec canvasTinter = canvasTinter;
    type nonrec buffer = buffer;
    type nonrec text = text;
    type nonrec textMetrics = textMetrics;
    type nonrec fontMetrics = fontMetrics;
    type nonrec textStyle = textStyle;
    type nonrec baseRenderTexture = baseRenderTexture;
    type nonrec baseTexture = baseTexture;
    type nonrec renderTexture = renderTexture;
    type nonrec spritesheet = spritesheet;
    type nonrec texture = texture;
    type nonrec videoBaseTexture = videoBaseTexture;
    type nonrec ticker = ticker;
    type nonrec eventEmitter = eventEmitter;
    type nonrec canvasExtract = canvasExtract;
    type nonrec webGLExtract = webGLExtract;
    type nonrec animatedSprite = animatedSprite;
    type nonrec bitmapText = bitmapText;
    type nonrec textureTransform = textureTransform;
    type nonrec tilingSprite = tilingSprite;
    type nonrec tilingSpriteRenderer = tilingSpriteRenderer;
    type nonrec blurFilter = blurFilter;
    type nonrec blurXFilter = blurXFilter;
    type nonrec blurYFilter = blurYFilter;
    type nonrec colorMatrixFilter = colorMatrixFilter;
    type nonrec displacementFilter = displacementFilter;
    type nonrec fxaaFilter = fxaaFilter;
    type nonrec noiseFilter = noiseFilter;
    type nonrec voidFilter = voidFilter;
    type nonrec interactionData = interactionData;
    type nonrec interactionEvent = interactionEvent;
    type nonrec interactionManager = interactionManager;
    type nonrec resource = resource;
    type nonrec loader = loader;
    type nonrec mesh = mesh;
    type nonrec nineSlicePlane = nineSlicePlane;
    type nonrec plane = plane;
    type nonrec rope = rope;
    type nonrec meshRenderer = meshRenderer;
    type nonrec particleContainer = particleContainer;
    type nonrec particleShader = particleShader;
    type nonrec basePrepare = basePrepare;
    type nonrec canvasPrepare = canvasPrepare;
    type nonrec countLimiter = countLimiter;
    type nonrec timeLimiter = timeLimiter;
    type nonrec webGLPrepare = webGLPrepare;
  };
