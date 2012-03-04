/**
  * @name QDrag
  * @constructor
  * @extends QObject
  * @param {QWidget} dragSource
  */
function QDrag(dragSource){return undefined;};

QDrag.prototype = new QObject();

/**
  * @name exec
  * @function
  * @memberOf QDrag.prototype
  * @param {Qt.DropActions} supportedActions
  * @returns {Qt.DropAction}
  */
QDrag.prototype.exec = function(supportedActions){return new Qt.DropAction();};

/**
  * @name hotSpot
  * @function
  * @memberOf QDrag.prototype
  * @returns {QPoint}
  */
QDrag.prototype.hotSpot = function(){return new QPoint();};

/**
  * @name mimeData
  * @function
  * @memberOf QDrag.prototype
  * @returns {QMimeData}
  */
QDrag.prototype.mimeData = function(){return new QMimeData();};

/**
  * @name pixmap
  * @function
  * @memberOf QDrag.prototype
  * @returns {QPixmap}
  */
QDrag.prototype.pixmap = function(){return new QPixmap();};

/**
  * @name setDragCursor
  * @function
  * @memberOf QDrag.prototype
  * @param {QPixmap} cursor
  * @param {Qt.DropAction} action
  * @returns {undefined}
  */
QDrag.prototype.setDragCursor = function(cursor, action){return undefined;};

/**
  * @name setHotSpot
  * @function
  * @memberOf QDrag.prototype
  * @param {QPoint} hotspot
  * @returns {undefined}
  */
QDrag.prototype.setHotSpot = function(hotspot){return undefined;};

/**
  * @name setMimeData
  * @function
  * @memberOf QDrag.prototype
  * @param {QMimeData} data
  * @returns {undefined}
  */
QDrag.prototype.setMimeData = function(data){return undefined;};

/**
  * @name setPixmap
  * @function
  * @memberOf QDrag.prototype
  * @param {QPixmap} arg__1
  * @returns {undefined}
  */
QDrag.prototype.setPixmap = function(arg__1){return undefined;};

/**
  * @name source
  * @function
  * @memberOf QDrag.prototype
  * @returns {QWidget}
  */
QDrag.prototype.source = function(){return new QWidget();};

/**
  * @name target
  * @function
  * @memberOf QDrag.prototype
  * @returns {QWidget}
  */
QDrag.prototype.target = function(){return new QWidget();};

