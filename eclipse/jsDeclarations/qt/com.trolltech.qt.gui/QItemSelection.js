/**
  * @name QItemSelection
  * @constructor
  */
function QItemSelection(){return undefined;};

/**
  * @name QItemSelection^1
  * @constructor
  * @param {QModelIndex} topLeft
  * @param {QModelIndex} bottomRight
  */
function QItemSelection(topLeft, bottomRight){return undefined;};

/**
  * @name fromVector
  * @function
  * @memberOf QItemSelection
  * @param {Array} vector
  * @returns {Array}
  */
QItemSelection.fromVector = function(vector){return new Array();};

/**
  * @name split
  * @function
  * @memberOf QItemSelection
  * @param {QItemSelectionRange} range
  * @param {QItemSelectionRange} other
  * @param {QItemSelection} result
  * @returns {undefined}
  */
QItemSelection.split = function(range, other, result){return undefined;};

/**
  * @name append
  * @function
  * @memberOf QItemSelection.prototype
  * @param {QItemSelectionRange} t
  * @returns {undefined}
  */
QItemSelection.prototype.append = function(t){return undefined;};

/**
  * @name at
  * @function
  * @memberOf QItemSelection.prototype
  * @param {Numeric} i
  * @returns {QItemSelectionRange}
  */
QItemSelection.prototype.at = function(i){return new QItemSelectionRange();};

/**
  * @name back
  * @function
  * @memberOf QItemSelection.prototype
  * @returns {QItemSelectionRange}
  */
QItemSelection.prototype.back = function(){return new QItemSelectionRange();};

/**
  * @name clear
  * @function
  * @memberOf QItemSelection.prototype
  * @returns {undefined}
  */
QItemSelection.prototype.clear = function(){return undefined;};

/**
  * @name contains
  * @function
  * @memberOf QItemSelection.prototype
  * @param {QModelIndex} index
  * @returns {Boolean}
  */
QItemSelection.prototype.contains = function(index){return new Boolean();};

/**
  * @name count
  * @function
  * @memberOf QItemSelection.prototype
  * @returns {Numeric}
  */
QItemSelection.prototype.count = function(){return new Numeric();};

/**
  * @name detachShared
  * @function
  * @memberOf QItemSelection.prototype
  * @returns {undefined}
  */
QItemSelection.prototype.detachShared = function(){return undefined;};

/**
  * @name empty
  * @function
  * @memberOf QItemSelection.prototype
  * @returns {Boolean}
  */
QItemSelection.prototype.empty = function(){return new Boolean();};

/**
  * @name endsWith
  * @function
  * @memberOf QItemSelection.prototype
  * @param {QItemSelectionRange} t
  * @returns {Boolean}
  */
QItemSelection.prototype.endsWith = function(t){return new Boolean();};

/**
  * @name first
  * @function
  * @memberOf QItemSelection.prototype
  * @returns {QItemSelectionRange}
  */
QItemSelection.prototype.first = function(){return new QItemSelectionRange();};

/**
  * @name front
  * @function
  * @memberOf QItemSelection.prototype
  * @returns {QItemSelectionRange}
  */
QItemSelection.prototype.front = function(){return new QItemSelectionRange();};

/**
  * @name indexOf
  * @function
  * @memberOf QItemSelection.prototype
  * @param {QItemSelectionRange} t
  * @param {Numeric} from
  * @returns {Numeric}
  */
QItemSelection.prototype.indexOf = function(t, from){return new Numeric();};

/**
  * @name indexes
  * @function
  * @memberOf QItemSelection.prototype
  * @returns {Array}
  */
QItemSelection.prototype.indexes = function(){return new Array();};

/**
  * @name isEmpty
  * @function
  * @memberOf QItemSelection.prototype
  * @returns {Boolean}
  */
QItemSelection.prototype.isEmpty = function(){return new Boolean();};

/**
  * @name isSharedWith
  * @function
  * @memberOf QItemSelection.prototype
  * @param {Array} other
  * @returns {Boolean}
  */
QItemSelection.prototype.isSharedWith = function(other){return new Boolean();};

/**
  * @name last
  * @function
  * @memberOf QItemSelection.prototype
  * @returns {QItemSelectionRange}
  */
QItemSelection.prototype.last = function(){return new QItemSelectionRange();};

/**
  * @name lastIndexOf
  * @function
  * @memberOf QItemSelection.prototype
  * @param {QItemSelectionRange} t
  * @param {Numeric} from
  * @returns {Numeric}
  */
QItemSelection.prototype.lastIndexOf = function(t, from){return new Numeric();};

/**
  * @name length
  * @function
  * @memberOf QItemSelection.prototype
  * @returns {Numeric}
  */
QItemSelection.prototype.length = function(){return new Numeric();};

/**
  * @name merge
  * @function
  * @memberOf QItemSelection.prototype
  * @param {QItemSelection} other
  * @param {QItemSelectionModel.SelectionFlags} command
  * @returns {undefined}
  */
QItemSelection.prototype.merge = function(other, command){return undefined;};

/**
  * @name mid
  * @function
  * @memberOf QItemSelection.prototype
  * @param {Numeric} pos
  * @param {Numeric} length
  * @returns {Array}
  */
QItemSelection.prototype.mid = function(pos, length){return new Array();};

/**
  * @name move
  * @function
  * @memberOf QItemSelection.prototype
  * @param {Numeric} from
  * @param {Numeric} to
  * @returns {undefined}
  */
QItemSelection.prototype.move = function(from, to){return undefined;};

/**
  * @name operator_equal
  * @function
  * @memberOf QItemSelection.prototype
  * @param {Array} l
  * @returns {Boolean}
  */
QItemSelection.prototype.operator_equal = function(l){return new Boolean();};

/**
  * @name pop_back
  * @function
  * @memberOf QItemSelection.prototype
  * @returns {undefined}
  */
QItemSelection.prototype.pop_back = function(){return undefined;};

/**
  * @name pop_front
  * @function
  * @memberOf QItemSelection.prototype
  * @returns {undefined}
  */
QItemSelection.prototype.pop_front = function(){return undefined;};

/**
  * @name prepend
  * @function
  * @memberOf QItemSelection.prototype
  * @param {QItemSelectionRange} t
  * @returns {undefined}
  */
QItemSelection.prototype.prepend = function(t){return undefined;};

/**
  * @name push_back
  * @function
  * @memberOf QItemSelection.prototype
  * @param {QItemSelectionRange} t
  * @returns {undefined}
  */
QItemSelection.prototype.push_back = function(t){return undefined;};

/**
  * @name push_front
  * @function
  * @memberOf QItemSelection.prototype
  * @param {QItemSelectionRange} t
  * @returns {undefined}
  */
QItemSelection.prototype.push_front = function(t){return undefined;};

/**
  * @name removeAll
  * @function
  * @memberOf QItemSelection.prototype
  * @param {QItemSelectionRange} t
  * @returns {Numeric}
  */
QItemSelection.prototype.removeAll = function(t){return new Numeric();};

/**
  * @name removeAt
  * @function
  * @memberOf QItemSelection.prototype
  * @param {Numeric} i
  * @returns {undefined}
  */
QItemSelection.prototype.removeAt = function(i){return undefined;};

/**
  * @name removeFirst
  * @function
  * @memberOf QItemSelection.prototype
  * @returns {undefined}
  */
QItemSelection.prototype.removeFirst = function(){return undefined;};

/**
  * @name removeLast
  * @function
  * @memberOf QItemSelection.prototype
  * @returns {undefined}
  */
QItemSelection.prototype.removeLast = function(){return undefined;};

/**
  * @name removeOne
  * @function
  * @memberOf QItemSelection.prototype
  * @param {QItemSelectionRange} t
  * @returns {Boolean}
  */
QItemSelection.prototype.removeOne = function(t){return new Boolean();};

/**
  * @name replace
  * @function
  * @memberOf QItemSelection.prototype
  * @param {Numeric} i
  * @param {QItemSelectionRange} t
  * @returns {undefined}
  */
QItemSelection.prototype.replace = function(i, t){return undefined;};

/**
  * @name reserve
  * @function
  * @memberOf QItemSelection.prototype
  * @param {Numeric} size
  * @returns {undefined}
  */
QItemSelection.prototype.reserve = function(size){return undefined;};

/**
  * @name select
  * @function
  * @memberOf QItemSelection.prototype
  * @param {QModelIndex} topLeft
  * @param {QModelIndex} bottomRight
  * @returns {undefined}
  */
QItemSelection.prototype.select = function(topLeft, bottomRight){return undefined;};

/**
  * @name setSharable
  * @function
  * @memberOf QItemSelection.prototype
  * @param {Boolean} sharable
  * @returns {undefined}
  */
QItemSelection.prototype.setSharable = function(sharable){return undefined;};

/**
  * @name size
  * @function
  * @memberOf QItemSelection.prototype
  * @returns {Numeric}
  */
QItemSelection.prototype.size = function(){return new Numeric();};

/**
  * @name startsWith
  * @function
  * @memberOf QItemSelection.prototype
  * @param {QItemSelectionRange} t
  * @returns {Boolean}
  */
QItemSelection.prototype.startsWith = function(t){return new Boolean();};

/**
  * @name swap
  * @function
  * @memberOf QItemSelection.prototype
  * @param {Array} other
  * @returns {undefined}
  */
QItemSelection.prototype.swap = function(other){return undefined;};

/**
  * @name takeAt
  * @function
  * @memberOf QItemSelection.prototype
  * @param {Numeric} i
  * @returns {QItemSelectionRange}
  */
QItemSelection.prototype.takeAt = function(i){return new QItemSelectionRange();};

/**
  * @name takeFirst
  * @function
  * @memberOf QItemSelection.prototype
  * @returns {QItemSelectionRange}
  */
QItemSelection.prototype.takeFirst = function(){return new QItemSelectionRange();};

/**
  * @name takeLast
  * @function
  * @memberOf QItemSelection.prototype
  * @returns {QItemSelectionRange}
  */
QItemSelection.prototype.takeLast = function(){return new QItemSelectionRange();};

/**
  * @name toVector
  * @function
  * @memberOf QItemSelection.prototype
  * @returns {Array}
  */
QItemSelection.prototype.toVector = function(){return new Array();};

/**
  * @name value
  * @function
  * @memberOf QItemSelection.prototype
  * @param {Numeric} i
  * @returns {QItemSelectionRange}
  */
QItemSelection.prototype.value = function(i){return new QItemSelectionRange();};

