/**
  * @name QPersistentModelIndex
  * @constructor
  */
function QPersistentModelIndex(){return undefined;};

/**
  * @name QPersistentModelIndex^1
  * @constructor
  * @param {QModelIndex} index
  */
function QPersistentModelIndex(index){return undefined;};

/**
  * @name QPersistentModelIndex^2
  * @constructor
  * @param {QPersistentModelIndex} other
  */
function QPersistentModelIndex(other){return undefined;};

/**
  * @name child
  * @function
  * @memberOf QPersistentModelIndex.prototype
  * @param {Numeric} row
  * @param {Numeric} column
  * @returns {QModelIndex}
  */
QPersistentModelIndex.prototype.child = function(row, column){return new QModelIndex();};

/**
  * @name column
  * @function
  * @memberOf QPersistentModelIndex.prototype
  * @returns {Numeric}
  */
QPersistentModelIndex.prototype.column = function(){return new Numeric();};

/**
  * @name data
  * @function
  * @memberOf QPersistentModelIndex.prototype
  * @param {Numeric} role
  * @returns {Object}
  */
QPersistentModelIndex.prototype.data = function(role){return new Object();};

/**
  * @name flags
  * @function
  * @memberOf QPersistentModelIndex.prototype
  * @returns {Qt.ItemFlags}
  */
QPersistentModelIndex.prototype.flags = function(){return new Qt.ItemFlags();};

/**
  * @name internalId
  * @function
  * @memberOf QPersistentModelIndex.prototype
  * @returns {Numeric}
  */
QPersistentModelIndex.prototype.internalId = function(){return new Numeric();};

/**
  * @name isValid
  * @function
  * @memberOf QPersistentModelIndex.prototype
  * @returns {Boolean}
  */
QPersistentModelIndex.prototype.isValid = function(){return new Boolean();};

/**
  * @name model
  * @function
  * @memberOf QPersistentModelIndex.prototype
  * @returns {QAbstractItemModel}
  */
QPersistentModelIndex.prototype.model = function(){return new QAbstractItemModel();};

/**
  * @name operator_cast_QModelIndex
  * @function
  * @memberOf QPersistentModelIndex.prototype
  * @returns {QModelIndex}
  */
QPersistentModelIndex.prototype.operator_cast_QModelIndex = function(){return new QModelIndex();};

/**
  * @name operator_equal
  * @function
  * @memberOf QPersistentModelIndex.prototype
  * @param {QModelIndex} other
  * @returns {Boolean}
  */
QPersistentModelIndex.prototype.operator_equal = function(other){return new Boolean();};

/**
  * @name operator_less
  * @function
  * @memberOf QPersistentModelIndex.prototype
  * @param {QPersistentModelIndex} other
  * @returns {Boolean}
  */
QPersistentModelIndex.prototype.operator_less = function(other){return new Boolean();};

/**
  * @name parent
  * @function
  * @memberOf QPersistentModelIndex.prototype
  * @returns {QModelIndex}
  */
QPersistentModelIndex.prototype.parent = function(){return new QModelIndex();};

/**
  * @name row
  * @function
  * @memberOf QPersistentModelIndex.prototype
  * @returns {Numeric}
  */
QPersistentModelIndex.prototype.row = function(){return new Numeric();};

/**
  * @name sibling
  * @function
  * @memberOf QPersistentModelIndex.prototype
  * @param {Numeric} row
  * @param {Numeric} column
  * @returns {QModelIndex}
  */
QPersistentModelIndex.prototype.sibling = function(row, column){return new QModelIndex();};

