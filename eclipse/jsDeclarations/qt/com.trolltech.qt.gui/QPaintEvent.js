/**
  * @name QPaintEvent
  * @constructor
  * @extends QEvent
  * @param {QRect} paintRect
  */
function QPaintEvent(paintRect){return undefined;};

/**
  * @name QPaintEvent^1
  * @constructor
  * @extends QEvent
  * @param {QRegion} paintRegion
  */
function QPaintEvent(paintRegion){return undefined;};

QPaintEvent.prototype = new QEvent();

/**
  * @name rect
  * @function
  * @memberOf QPaintEvent.prototype
  * @returns {QRect}
  */
QPaintEvent.prototype.rect = function(){return new QRect();};

/**
  * @name region
  * @function
  * @memberOf QPaintEvent.prototype
  * @returns {QRegion}
  */
QPaintEvent.prototype.region = function(){return new QRegion();};

