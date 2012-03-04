/**
  * @name QGraphicsAnchorLayout
  * @constructor
  * @extends QGraphicsLayout
  * @param {QGraphicsLayoutItem} parent
  */
function QGraphicsAnchorLayout(parent){return undefined;};

QGraphicsAnchorLayout.prototype = new QGraphicsLayout();

/**
  * @name addAnchor
  * @function
  * @memberOf QGraphicsAnchorLayout.prototype
  * @param {QGraphicsLayoutItem} firstItem
  * @param {Qt.AnchorPoint} firstEdge
  * @param {QGraphicsLayoutItem} secondItem
  * @param {Qt.AnchorPoint} secondEdge
  * @returns {QGraphicsAnchor}
  */
QGraphicsAnchorLayout.prototype.addAnchor = function(firstItem, firstEdge, secondItem, secondEdge){return new QGraphicsAnchor();};

/**
  * @name addAnchors
  * @function
  * @memberOf QGraphicsAnchorLayout.prototype
  * @param {QGraphicsLayoutItem} firstItem
  * @param {QGraphicsLayoutItem} secondItem
  * @param {Qt.Orientations} orientations
  * @returns {undefined}
  */
QGraphicsAnchorLayout.prototype.addAnchors = function(firstItem, secondItem, orientations){return undefined;};

/**
  * @name addCornerAnchors
  * @function
  * @memberOf QGraphicsAnchorLayout.prototype
  * @param {QGraphicsLayoutItem} firstItem
  * @param {Qt.Corner} firstCorner
  * @param {QGraphicsLayoutItem} secondItem
  * @param {Qt.Corner} secondCorner
  * @returns {undefined}
  */
QGraphicsAnchorLayout.prototype.addCornerAnchors = function(firstItem, firstCorner, secondItem, secondCorner){return undefined;};

/**
  * @name anchor
  * @function
  * @memberOf QGraphicsAnchorLayout.prototype
  * @param {QGraphicsLayoutItem} firstItem
  * @param {Qt.AnchorPoint} firstEdge
  * @param {QGraphicsLayoutItem} secondItem
  * @param {Qt.AnchorPoint} secondEdge
  * @returns {QGraphicsAnchor}
  */
QGraphicsAnchorLayout.prototype.anchor = function(firstItem, firstEdge, secondItem, secondEdge){return new QGraphicsAnchor();};

/**
  * @name horizontalSpacing
  * @function
  * @memberOf QGraphicsAnchorLayout.prototype
  * @returns {Numeric}
  */
QGraphicsAnchorLayout.prototype.horizontalSpacing = function(){return new Numeric();};

/**
  * @name setHorizontalSpacing
  * @function
  * @memberOf QGraphicsAnchorLayout.prototype
  * @param {Numeric} spacing
  * @returns {undefined}
  */
QGraphicsAnchorLayout.prototype.setHorizontalSpacing = function(spacing){return undefined;};

/**
  * @name setSpacing
  * @function
  * @memberOf QGraphicsAnchorLayout.prototype
  * @param {Numeric} spacing
  * @returns {undefined}
  */
QGraphicsAnchorLayout.prototype.setSpacing = function(spacing){return undefined;};

/**
  * @name setVerticalSpacing
  * @function
  * @memberOf QGraphicsAnchorLayout.prototype
  * @param {Numeric} spacing
  * @returns {undefined}
  */
QGraphicsAnchorLayout.prototype.setVerticalSpacing = function(spacing){return undefined;};

/**
  * @name verticalSpacing
  * @function
  * @memberOf QGraphicsAnchorLayout.prototype
  * @returns {Numeric}
  */
QGraphicsAnchorLayout.prototype.verticalSpacing = function(){return new Numeric();};

