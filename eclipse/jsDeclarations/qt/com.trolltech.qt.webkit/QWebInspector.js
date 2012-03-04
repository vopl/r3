/**
  * @name QWebInspector
  * @constructor
  * @extends QWidget
  * @param {QWidget} parent
  */
function QWebInspector(parent){return undefined;};

QWebInspector.prototype = new QWidget();

/**
  * @name page
  * @function
  * @memberOf QWebInspector.prototype
  * @returns {QWebPage}
  */
QWebInspector.prototype.page = function(){return new QWebPage();};

/**
  * @name setPage
  * @function
  * @memberOf QWebInspector.prototype
  * @param {QWebPage} page
  * @returns {undefined}
  */
QWebInspector.prototype.setPage = function(page){return undefined;};

/**
  * @name sizeHint
  * @function
  * @memberOf QWebInspector.prototype
  * @returns {QSize}
  */
QWebInspector.prototype.sizeHint = function(){return new QSize();};

