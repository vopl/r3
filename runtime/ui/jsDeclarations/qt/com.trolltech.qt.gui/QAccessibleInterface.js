/**
  * @name QAccessibleInterface
  * @constructor
  * @extends QAccessible
  */
function QAccessibleInterface(){return undefined;};

QAccessibleInterface.prototype = new QAccessible();

/**
  * @name actionText
  * @function
  * @memberOf QAccessibleInterface.prototype
  * @param {Numeric} action
  * @param {QIODevice.Text} t
  * @param {Numeric} child
  * @returns {String}
  */
QAccessibleInterface.prototype.actionText = function(action, t, child){return new String();};

/**
  * @name childAt
  * @function
  * @memberOf QAccessibleInterface.prototype
  * @param {Numeric} x
  * @param {Numeric} y
  * @returns {Numeric}
  */
QAccessibleInterface.prototype.childAt = function(x, y){return new Numeric();};

/**
  * @name childCount
  * @function
  * @memberOf QAccessibleInterface.prototype
  * @returns {Numeric}
  */
QAccessibleInterface.prototype.childCount = function(){return new Numeric();};

/**
  * @name doAction
  * @function
  * @memberOf QAccessibleInterface.prototype
  * @param {Numeric} action
  * @param {Numeric} child
  * @param {Array} params
  * @returns {Boolean}
  */
QAccessibleInterface.prototype.doAction = function(action, child, params){return new Boolean();};

/**
  * @name indexOfChild
  * @function
  * @memberOf QAccessibleInterface.prototype
  * @param {QAccessibleInterface} arg__1
  * @returns {Numeric}
  */
QAccessibleInterface.prototype.indexOfChild = function(arg__1){return new Numeric();};

/**
  * @name invokeMethod
  * @function
  * @memberOf QAccessibleInterface.prototype
  * @param {QAccessible.Method} method
  * @param {Numeric} child
  * @param {Array} params
  * @returns {Object}
  */
QAccessibleInterface.prototype.invokeMethod = function(method, child, params){return new Object();};

/**
  * @name isValid
  * @function
  * @memberOf QAccessibleInterface.prototype
  * @returns {Boolean}
  */
QAccessibleInterface.prototype.isValid = function(){return new Boolean();};

/**
  * @name navigate
  * @function
  * @memberOf QAccessibleInterface.prototype
  * @param {QAccessible.RelationFlag} relation
  * @param {Numeric} index
  * @param {QAccessibleInterface} iface
  * @returns {Numeric}
  */
QAccessibleInterface.prototype.navigate = function(relation, index, iface){return new Numeric();};

/**
  * @name object
  * @function
  * @memberOf QAccessibleInterface.prototype
  * @returns {QObject}
  */
QAccessibleInterface.prototype.object = function(){return new QObject();};

/**
  * @name rect
  * @function
  * @memberOf QAccessibleInterface.prototype
  * @param {Numeric} child
  * @returns {QRect}
  */
QAccessibleInterface.prototype.rect = function(child){return new QRect();};

/**
  * @name relationTo
  * @function
  * @memberOf QAccessibleInterface.prototype
  * @param {Numeric} child
  * @param {QAccessibleInterface} other
  * @param {Numeric} otherChild
  * @returns {QAccessible.Relation}
  */
QAccessibleInterface.prototype.relationTo = function(child, other, otherChild){return new QAccessible.Relation();};

/**
  * @name role
  * @function
  * @memberOf QAccessibleInterface.prototype
  * @param {Numeric} child
  * @returns {QAccessible.Role}
  */
QAccessibleInterface.prototype.role = function(child){return new QAccessible.Role();};

/**
  * @name setText
  * @function
  * @memberOf QAccessibleInterface.prototype
  * @param {QIODevice.Text} t
  * @param {Numeric} child
  * @param {String} text
  * @returns {undefined}
  */
QAccessibleInterface.prototype.setText = function(t, child, text){return undefined;};

/**
  * @name state
  * @function
  * @memberOf QAccessibleInterface.prototype
  * @param {Numeric} child
  * @returns {QTimeLine.State}
  */
QAccessibleInterface.prototype.state = function(child){return new QTimeLine.State();};

/**
  * @name supportedMethods
  * @function
  * @memberOf QAccessibleInterface.prototype
  * @returns {Array}
  */
QAccessibleInterface.prototype.supportedMethods = function(){return new Array();};

/**
  * @name text
  * @function
  * @memberOf QAccessibleInterface.prototype
  * @param {QIODevice.Text} t
  * @param {Numeric} child
  * @returns {String}
  */
QAccessibleInterface.prototype.text = function(t, child){return new String();};

/**
  * @name userActionCount
  * @function
  * @memberOf QAccessibleInterface.prototype
  * @param {Numeric} child
  * @returns {Numeric}
  */
QAccessibleInterface.prototype.userActionCount = function(child){return new Numeric();};

