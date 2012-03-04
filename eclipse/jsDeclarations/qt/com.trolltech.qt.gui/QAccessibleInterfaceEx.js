/**
  * @name QAccessibleInterfaceEx
  * @constructor
  * @extends QAccessibleInterface
  */
function QAccessibleInterfaceEx(){return undefined;};

QAccessibleInterfaceEx.prototype = new QAccessibleInterface();

/**
  * @name invokeMethodEx
  * @function
  * @memberOf QAccessibleInterfaceEx.prototype
  * @param {QAccessible.Method} method
  * @param {Numeric} child
  * @param {Array} params
  * @returns {Object}
  */
QAccessibleInterfaceEx.prototype.invokeMethodEx = function(method, child, params){return new Object();};

/**
  * @name virtual_hook
  * @function
  * @memberOf QAccessibleInterfaceEx.prototype
  * @param {Object} data
  * @returns {Object}
  */
QAccessibleInterfaceEx.prototype.virtual_hook = function(data){return new Object();};

