/**
  * @name QActionGroup
  * @constructor
  * @extends QObject
  * @param {QObject} parent
  */
function QActionGroup(parent){return undefined;};

QActionGroup.prototype = new QObject();

/**
  * @name actions
  * @function
  * @memberOf QActionGroup.prototype
  * @returns {Array}
  */
QActionGroup.prototype.actions = function(){return new Array();};

/**
  * @name addAction
  * @function
  * @memberOf QActionGroup.prototype
  * @param {QAction} a
  * @returns {QAction}
  */
QActionGroup.prototype.addAction = function(a){return new QAction();};

/**
  * @name checkedAction
  * @function
  * @memberOf QActionGroup.prototype
  * @returns {QAction}
  */
QActionGroup.prototype.checkedAction = function(){return new QAction();};

/**
  * @name removeAction
  * @function
  * @memberOf QActionGroup.prototype
  * @param {QAction} a
  * @returns {undefined}
  */
QActionGroup.prototype.removeAction = function(a){return undefined;};

/**
  * @name exclusive
  * @memberOf QActionGroup.prototype
  * @type Boolean
  */
QActionGroup.prototype.exclusive = new Boolean();

/**
  * @name enabled
  * @memberOf QActionGroup.prototype
  * @type Boolean
  */
QActionGroup.prototype.enabled = new Boolean();

/**
  * @name visible
  * @memberOf QActionGroup.prototype
  * @type Boolean
  */
QActionGroup.prototype.visible = new Boolean();


