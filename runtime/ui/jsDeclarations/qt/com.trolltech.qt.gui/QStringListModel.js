/**
  * @name QStringListModel
  * @constructor
  * @extends QAbstractListModel
  * @param {QObject} parent
  */
function QStringListModel(parent){return undefined;};

/**
  * @name QStringListModel^1
  * @constructor
  * @extends QAbstractListModel
  * @param {Array} strings
  * @param {QObject} parent
  */
function QStringListModel(strings, parent){return undefined;};

QStringListModel.prototype = new QAbstractListModel();

/**
  * @name setStringList
  * @function
  * @memberOf QStringListModel.prototype
  * @param {Array} strings
  * @returns {undefined}
  */
QStringListModel.prototype.setStringList = function(strings){return undefined;};

/**
  * @name stringList
  * @function
  * @memberOf QStringListModel.prototype
  * @returns {Array}
  */
QStringListModel.prototype.stringList = function(){return new Array();};

