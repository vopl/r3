/**
  * @name QUndoGroup
  * @constructor
  * @extends QObject
  * @param {QObject} parent
  */
function QUndoGroup(parent){return undefined;};

QUndoGroup.prototype = new QObject();

/**
  * @name activeStack
  * @function
  * @memberOf QUndoGroup.prototype
  * @returns {QUndoStack}
  */
QUndoGroup.prototype.activeStack = function(){return new QUndoStack();};

/**
  * @name addStack
  * @function
  * @memberOf QUndoGroup.prototype
  * @param {QUndoStack} stack
  * @returns {undefined}
  */
QUndoGroup.prototype.addStack = function(stack){return undefined;};

/**
  * @name canRedo
  * @function
  * @memberOf QUndoGroup.prototype
  * @returns {Boolean}
  */
QUndoGroup.prototype.canRedo = function(){return new Boolean();};

/**
  * @name canUndo
  * @function
  * @memberOf QUndoGroup.prototype
  * @returns {Boolean}
  */
QUndoGroup.prototype.canUndo = function(){return new Boolean();};

/**
  * @name createRedoAction
  * @function
  * @memberOf QUndoGroup.prototype
  * @param {QObject} parent
  * @param {String} prefix
  * @returns {QAction}
  */
QUndoGroup.prototype.createRedoAction = function(parent, prefix){return new QAction();};

/**
  * @name createUndoAction
  * @function
  * @memberOf QUndoGroup.prototype
  * @param {QObject} parent
  * @param {String} prefix
  * @returns {QAction}
  */
QUndoGroup.prototype.createUndoAction = function(parent, prefix){return new QAction();};

/**
  * @name isClean
  * @function
  * @memberOf QUndoGroup.prototype
  * @returns {Boolean}
  */
QUndoGroup.prototype.isClean = function(){return new Boolean();};

/**
  * @name redoText
  * @function
  * @memberOf QUndoGroup.prototype
  * @returns {String}
  */
QUndoGroup.prototype.redoText = function(){return new String();};

/**
  * @name removeStack
  * @function
  * @memberOf QUndoGroup.prototype
  * @param {QUndoStack} stack
  * @returns {undefined}
  */
QUndoGroup.prototype.removeStack = function(stack){return undefined;};

/**
  * @name stacks
  * @function
  * @memberOf QUndoGroup.prototype
  * @returns {Array}
  */
QUndoGroup.prototype.stacks = function(){return new Array();};

/**
  * @name undoText
  * @function
  * @memberOf QUndoGroup.prototype
  * @returns {String}
  */
QUndoGroup.prototype.undoText = function(){return new String();};

