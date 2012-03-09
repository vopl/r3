/**
  * @name QSqlIndex
  * @constructor
  * @extends QSqlRecord
  * @param {QSqlIndex} other
  */
function QSqlIndex(other){return undefined;};

/**
  * @name QSqlIndex^1
  * @constructor
  * @extends QSqlRecord
  * @param {String} cursorName
  * @param {String} name
  */
function QSqlIndex(cursorName, name){return undefined;};

QSqlIndex.prototype = new QSqlRecord();

/**
  * @name append
  * @function
  * @memberOf QSqlIndex.prototype
  * @param {QSqlField} field
  * @param {Boolean} desc
  * @returns {undefined}
  */
QSqlIndex.prototype.append = function(field, desc){return undefined;};

/**
  * @name cursorName
  * @function
  * @memberOf QSqlIndex.prototype
  * @returns {String}
  */
QSqlIndex.prototype.cursorName = function(){return new String();};

/**
  * @name isDescending
  * @function
  * @memberOf QSqlIndex.prototype
  * @param {Numeric} i
  * @returns {Boolean}
  */
QSqlIndex.prototype.isDescending = function(i){return new Boolean();};

/**
  * @name name
  * @function
  * @memberOf QSqlIndex.prototype
  * @returns {String}
  */
QSqlIndex.prototype.name = function(){return new String();};

/**
  * @name setCursorName
  * @function
  * @memberOf QSqlIndex.prototype
  * @param {String} cursorName
  * @returns {undefined}
  */
QSqlIndex.prototype.setCursorName = function(cursorName){return undefined;};

/**
  * @name setDescending
  * @function
  * @memberOf QSqlIndex.prototype
  * @param {Numeric} i
  * @param {Boolean} desc
  * @returns {undefined}
  */
QSqlIndex.prototype.setDescending = function(i, desc){return undefined;};

/**
  * @name setName
  * @function
  * @memberOf QSqlIndex.prototype
  * @param {String} name
  * @returns {undefined}
  */
QSqlIndex.prototype.setName = function(name){return undefined;};

