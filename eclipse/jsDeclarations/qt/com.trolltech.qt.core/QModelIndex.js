/**
  * @name QModelIndex
  * @constructor
  */
function QModelIndex(){return undefined;};

/**
  * @name QModelIndex^1
  * @constructor
  * @param {QModelIndex} other
  */
function QModelIndex(other){return undefined;};

/**
  * @name child
  * @function
  * @memberOf QModelIndex.prototype
  * @param {Numeric} row
  * @param {Numeric} column
  * @returns {QModelIndex}
  */
QModelIndex.prototype.child = function(row, column){return new QModelIndex();};

/**
  * @name column
  * @function
  * @memberOf QModelIndex.prototype
  * @returns {Numeric}
  */
QModelIndex.prototype.column = function(){return new Numeric();};

/**
  * @name data
  * @function
  * @memberOf QModelIndex.prototype
  * @param {Numeric} role
  * @returns {Object}
  */
QModelIndex.prototype.data = function(role){return new Object();};

/**
  * @name flags
  * @function
  * @memberOf QModelIndex.prototype
  * @returns {Qt.ItemFlags}
  */
QModelIndex.prototype.flags = function(){return new Qt.ItemFlags();};

/**
  * @name internalId
  * @function
  * @memberOf QModelIndex.prototype
  * @returns {Numeric}
  */
QModelIndex.prototype.internalId = function(){return new Numeric();};

/**
  * @name internalPointer
  * @function
  * @memberOf QModelIndex.prototype
  * @returns {undefined}
  */
QModelIndex.prototype.internalPointer = function(){return undefined;};

/**
  * @name isValid
  * @function
  * @memberOf QModelIndex.prototype
  * @returns {Boolean}
  */
QModelIndex.prototype.isValid = function(){return new Boolean();};

/**
  * @name model
  * @function
  * @memberOf QModelIndex.prototype
  * @returns {QAbstractItemModel}
  */
QModelIndex.prototype.model = function(){return new QAbstractItemModel();};

/**
  * @name operator_equal
  * @function
  * @memberOf QModelIndex.prototype
  * @param {QModelIndex} other
  * @returns {Boolean}
  */
QModelIndex.prototype.operator_equal = function(other){return new Boolean();};

/**
  * @name operator_less
  * @function
  * @memberOf QModelIndex.prototype
  * @param {QModelIndex} other
  * @returns {Boolean}
  */
QModelIndex.prototype.operator_less = function(other){return new Boolean();};

/**
  * @name parent
  * @function
  * @memberOf QModelIndex.prototype
  * @returns {QModelIndex}
  */
QModelIndex.prototype.parent = function(){return new QModelIndex();};

/**
  * @name row
  * @function
  * @memberOf QModelIndex.prototype
  * @returns {Numeric}
  */
QModelIndex.prototype.row = function(){return new Numeric();};

/**
  * @name sibling
  * @function
  * @memberOf QModelIndex.prototype
  * @param {Numeric} row
  * @param {Numeric} column
  * @returns {QModelIndex}
  */
QModelIndex.prototype.sibling = function(row, column){return new QModelIndex();};

