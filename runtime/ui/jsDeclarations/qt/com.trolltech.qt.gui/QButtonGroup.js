/**
  * @name QButtonGroup
  * @constructor
  * @extends QObject
  * @param {QObject} parent
  */
function QButtonGroup(parent){return undefined;};

QButtonGroup.prototype = new QObject();

/**
  * @name addButton
  * @function
  * @memberOf QButtonGroup.prototype
  * @param {QAbstractButton} arg__1
  * @returns {undefined}
  */
QButtonGroup.prototype.addButton = function(arg__1){return undefined;};

/**
  * @name button
  * @function
  * @memberOf QButtonGroup.prototype
  * @param {Numeric} id
  * @returns {QAbstractButton}
  */
QButtonGroup.prototype.button = function(id){return new QAbstractButton();};

/**
  * @name buttons
  * @function
  * @memberOf QButtonGroup.prototype
  * @returns {Array}
  */
QButtonGroup.prototype.buttons = function(){return new Array();};

/**
  * @name checkedButton
  * @function
  * @memberOf QButtonGroup.prototype
  * @returns {QAbstractButton}
  */
QButtonGroup.prototype.checkedButton = function(){return new QAbstractButton();};

/**
  * @name checkedId
  * @function
  * @memberOf QButtonGroup.prototype
  * @returns {Numeric}
  */
QButtonGroup.prototype.checkedId = function(){return new Numeric();};

/**
  * @name id
  * @function
  * @memberOf QButtonGroup.prototype
  * @param {QAbstractButton} button
  * @returns {Numeric}
  */
QButtonGroup.prototype.id = function(button){return new Numeric();};

/**
  * @name removeButton
  * @function
  * @memberOf QButtonGroup.prototype
  * @param {QAbstractButton} arg__1
  * @returns {undefined}
  */
QButtonGroup.prototype.removeButton = function(arg__1){return undefined;};

/**
  * @name setId
  * @function
  * @memberOf QButtonGroup.prototype
  * @param {QAbstractButton} button
  * @param {Numeric} id
  * @returns {undefined}
  */
QButtonGroup.prototype.setId = function(button, id){return undefined;};

/**
  * @name exclusive
  * @memberOf QButtonGroup.prototype
  * @type Boolean
  */
QButtonGroup.prototype.exclusive = new Boolean();


