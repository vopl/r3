/**
  * @name QAbstractItemModel
  * @constructor
  * @extends QObject
  * @param {QObject} parent
  */
function QAbstractItemModel(parent){return undefined;};

QAbstractItemModel.prototype = new QObject();

/**
  * @name buddy
  * @function
  * @memberOf QAbstractItemModel.prototype
  * @param {QModelIndex} index
  * @returns {QModelIndex}
  */
QAbstractItemModel.prototype.buddy = function(index){return new QModelIndex();};

/**
  * @name canFetchMore
  * @function
  * @memberOf QAbstractItemModel.prototype
  * @param {QModelIndex} parent
  * @returns {Boolean}
  */
QAbstractItemModel.prototype.canFetchMore = function(parent){return new Boolean();};

/**
  * @name columnCount
  * @function
  * @memberOf QAbstractItemModel.prototype
  * @param {QModelIndex} parent
  * @returns {Numeric}
  */
QAbstractItemModel.prototype.columnCount = function(parent){return new Numeric();};

/**
  * @name data
  * @function
  * @memberOf QAbstractItemModel.prototype
  * @param {QModelIndex} index
  * @param {Numeric} role
  * @returns {Object}
  */
QAbstractItemModel.prototype.data = function(index, role){return new Object();};

/**
  * @name dropMimeData
  * @function
  * @memberOf QAbstractItemModel.prototype
  * @param {QMimeData} data
  * @param {Qt.DropAction} action
  * @param {Numeric} row
  * @param {Numeric} column
  * @param {QModelIndex} parent
  * @returns {Boolean}
  */
QAbstractItemModel.prototype.dropMimeData = function(data, action, row, column, parent){return new Boolean();};

/**
  * @name fetchMore
  * @function
  * @memberOf QAbstractItemModel.prototype
  * @param {QModelIndex} parent
  * @returns {undefined}
  */
QAbstractItemModel.prototype.fetchMore = function(parent){return undefined;};

/**
  * @name flags
  * @function
  * @memberOf QAbstractItemModel.prototype
  * @param {QModelIndex} index
  * @returns {Qt.ItemFlags}
  */
QAbstractItemModel.prototype.flags = function(index){return new Qt.ItemFlags();};

/**
  * @name hasChildren
  * @function
  * @memberOf QAbstractItemModel.prototype
  * @param {QModelIndex} parent
  * @returns {Boolean}
  */
QAbstractItemModel.prototype.hasChildren = function(parent){return new Boolean();};

/**
  * @name hasIndex
  * @function
  * @memberOf QAbstractItemModel.prototype
  * @param {Numeric} row
  * @param {Numeric} column
  * @param {QModelIndex} parent
  * @returns {Boolean}
  */
QAbstractItemModel.prototype.hasIndex = function(row, column, parent){return new Boolean();};

/**
  * @name headerData
  * @function
  * @memberOf QAbstractItemModel.prototype
  * @param {Numeric} section
  * @param {QPrinter.Orientation} orientation
  * @param {Numeric} role
  * @returns {Object}
  */
QAbstractItemModel.prototype.headerData = function(section, orientation, role){return new Object();};

/**
  * @name index
  * @function
  * @memberOf QAbstractItemModel.prototype
  * @param {Numeric} row
  * @param {Numeric} column
  * @param {QModelIndex} parent
  * @returns {QModelIndex}
  */
QAbstractItemModel.prototype.index = function(row, column, parent){return new QModelIndex();};

/**
  * @name insertColumn
  * @function
  * @memberOf QAbstractItemModel.prototype
  * @param {Numeric} column
  * @param {QModelIndex} parent
  * @returns {Boolean}
  */
QAbstractItemModel.prototype.insertColumn = function(column, parent){return new Boolean();};

/**
  * @name insertColumns
  * @function
  * @memberOf QAbstractItemModel.prototype
  * @param {Numeric} column
  * @param {Numeric} count
  * @param {QModelIndex} parent
  * @returns {Boolean}
  */
QAbstractItemModel.prototype.insertColumns = function(column, count, parent){return new Boolean();};

/**
  * @name insertRow
  * @function
  * @memberOf QAbstractItemModel.prototype
  * @param {Numeric} row
  * @param {QModelIndex} parent
  * @returns {Boolean}
  */
QAbstractItemModel.prototype.insertRow = function(row, parent){return new Boolean();};

/**
  * @name insertRows
  * @function
  * @memberOf QAbstractItemModel.prototype
  * @param {Numeric} row
  * @param {Numeric} count
  * @param {QModelIndex} parent
  * @returns {Boolean}
  */
QAbstractItemModel.prototype.insertRows = function(row, count, parent){return new Boolean();};

/**
  * @name itemData
  * @function
  * @memberOf QAbstractItemModel.prototype
  * @param {QModelIndex} index
  * @returns {Object}
  */
QAbstractItemModel.prototype.itemData = function(index){return new Object();};

/**
  * @name match
  * @function
  * @memberOf QAbstractItemModel.prototype
  * @param {QModelIndex} start
  * @param {Numeric} role
  * @param {Object} value
  * @param {Numeric} hits
  * @param {Qt.MatchFlags} flags
  * @returns {Array}
  */
QAbstractItemModel.prototype.match = function(start, role, value, hits, flags){return new Array();};

/**
  * @name mimeData
  * @function
  * @memberOf QAbstractItemModel.prototype
  * @param {Array} indexes
  * @returns {QMimeData}
  */
QAbstractItemModel.prototype.mimeData = function(indexes){return new QMimeData();};

/**
  * @name mimeTypes
  * @function
  * @memberOf QAbstractItemModel.prototype
  * @returns {Array}
  */
QAbstractItemModel.prototype.mimeTypes = function(){return new Array();};

/**
  * @name parent
  * @function
  * @memberOf QAbstractItemModel.prototype
  * @param {QModelIndex} child
  * @returns {QModelIndex}
  */
QAbstractItemModel.prototype.parent = function(child){return new QModelIndex();};

/**
  * @name removeColumn
  * @function
  * @memberOf QAbstractItemModel.prototype
  * @param {Numeric} column
  * @param {QModelIndex} parent
  * @returns {Boolean}
  */
QAbstractItemModel.prototype.removeColumn = function(column, parent){return new Boolean();};

/**
  * @name removeColumns
  * @function
  * @memberOf QAbstractItemModel.prototype
  * @param {Numeric} column
  * @param {Numeric} count
  * @param {QModelIndex} parent
  * @returns {Boolean}
  */
QAbstractItemModel.prototype.removeColumns = function(column, count, parent){return new Boolean();};

/**
  * @name removeRow
  * @function
  * @memberOf QAbstractItemModel.prototype
  * @param {Numeric} row
  * @param {QModelIndex} parent
  * @returns {Boolean}
  */
QAbstractItemModel.prototype.removeRow = function(row, parent){return new Boolean();};

/**
  * @name removeRows
  * @function
  * @memberOf QAbstractItemModel.prototype
  * @param {Numeric} row
  * @param {Numeric} count
  * @param {QModelIndex} parent
  * @returns {Boolean}
  */
QAbstractItemModel.prototype.removeRows = function(row, count, parent){return new Boolean();};

/**
  * @name roleNames
  * @function
  * @memberOf QAbstractItemModel.prototype
  * @returns {Object}
  */
QAbstractItemModel.prototype.roleNames = function(){return new Object();};

/**
  * @name rowCount
  * @function
  * @memberOf QAbstractItemModel.prototype
  * @param {QModelIndex} parent
  * @returns {Numeric}
  */
QAbstractItemModel.prototype.rowCount = function(parent){return new Numeric();};

/**
  * @name setData
  * @function
  * @memberOf QAbstractItemModel.prototype
  * @param {QModelIndex} index
  * @param {Object} value
  * @param {Numeric} role
  * @returns {Boolean}
  */
QAbstractItemModel.prototype.setData = function(index, value, role){return new Boolean();};

/**
  * @name setHeaderData
  * @function
  * @memberOf QAbstractItemModel.prototype
  * @param {Numeric} section
  * @param {QPrinter.Orientation} orientation
  * @param {Object} value
  * @param {Numeric} role
  * @returns {Boolean}
  */
QAbstractItemModel.prototype.setHeaderData = function(section, orientation, value, role){return new Boolean();};

/**
  * @name setItemData
  * @function
  * @memberOf QAbstractItemModel.prototype
  * @param {QModelIndex} index
  * @param {Object} roles
  * @returns {Boolean}
  */
QAbstractItemModel.prototype.setItemData = function(index, roles){return new Boolean();};

/**
  * @name setSupportedDragActions
  * @function
  * @memberOf QAbstractItemModel.prototype
  * @param {Qt.DropActions} arg__1
  * @returns {undefined}
  */
QAbstractItemModel.prototype.setSupportedDragActions = function(arg__1){return undefined;};

/**
  * @name sibling
  * @function
  * @memberOf QAbstractItemModel.prototype
  * @param {Numeric} row
  * @param {Numeric} column
  * @param {QModelIndex} idx
  * @returns {QModelIndex}
  */
QAbstractItemModel.prototype.sibling = function(row, column, idx){return new QModelIndex();};

/**
  * @name sort
  * @function
  * @memberOf QAbstractItemModel.prototype
  * @param {Numeric} column
  * @param {Qt.SortOrder} order
  * @returns {undefined}
  */
QAbstractItemModel.prototype.sort = function(column, order){return undefined;};

/**
  * @name span
  * @function
  * @memberOf QAbstractItemModel.prototype
  * @param {QModelIndex} index
  * @returns {QSize}
  */
QAbstractItemModel.prototype.span = function(index){return new QSize();};

/**
  * @name supportedDragActions
  * @function
  * @memberOf QAbstractItemModel.prototype
  * @returns {Qt.DropActions}
  */
QAbstractItemModel.prototype.supportedDragActions = function(){return new Qt.DropActions();};

/**
  * @name supportedDropActions
  * @function
  * @memberOf QAbstractItemModel.prototype
  * @returns {Qt.DropActions}
  */
QAbstractItemModel.prototype.supportedDropActions = function(){return new Qt.DropActions();};

