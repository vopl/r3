/**
  * @name QWidgetAction
  * @constructor
  * @extends QAction
  * @param {QObject} parent
  */
function QWidgetAction(parent){return undefined;};

QWidgetAction.prototype = new QAction();

/**
  * @name defaultWidget
  * @function
  * @memberOf QWidgetAction.prototype
  * @returns {QWidget}
  */
QWidgetAction.prototype.defaultWidget = function(){return new QWidget();};

/**
  * @name releaseWidget
  * @function
  * @memberOf QWidgetAction.prototype
  * @param {QWidget} widget
  * @returns {undefined}
  */
QWidgetAction.prototype.releaseWidget = function(widget){return undefined;};

/**
  * @name requestWidget
  * @function
  * @memberOf QWidgetAction.prototype
  * @param {QWidget} parent
  * @returns {QWidget}
  */
QWidgetAction.prototype.requestWidget = function(parent){return new QWidget();};

/**
  * @name setDefaultWidget
  * @function
  * @memberOf QWidgetAction.prototype
  * @param {QWidget} w
  * @returns {undefined}
  */
QWidgetAction.prototype.setDefaultWidget = function(w){return undefined;};

