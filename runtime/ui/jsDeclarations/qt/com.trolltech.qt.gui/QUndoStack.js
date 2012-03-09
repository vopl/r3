/**
  * @name QUndoStack
  * @constructor
  * @extends QObject
  * @param {QObject} parent
  */
function QUndoStack(parent){return undefined;};

QUndoStack.prototype = new QObject();

/**
  * @name beginMacro
  * @function
  * @memberOf QUndoStack.prototype
  * @param {String} text
  * @returns {undefined}
  */
QUndoStack.prototype.beginMacro = function(text){return undefined;};

/**
  * @name canRedo
  * @function
  * @memberOf QUndoStack.prototype
  * @returns {Boolean}
  */
QUndoStack.prototype.canRedo = function(){return new Boolean();};

/**
  * @name canUndo
  * @function
  * @memberOf QUndoStack.prototype
  * @returns {Boolean}
  */
QUndoStack.prototype.canUndo = function(){return new Boolean();};

/**
  * @name cleanIndex
  * @function
  * @memberOf QUndoStack.prototype
  * @returns {Numeric}
  */
QUndoStack.prototype.cleanIndex = function(){return new Numeric();};

/**
  * @name clear
  * @function
  * @memberOf QUndoStack.prototype
  * @returns {undefined}
  */
QUndoStack.prototype.clear = function(){return undefined;};

/**
  * @name command
  * @function
  * @memberOf QUndoStack.prototype
  * @param {Numeric} index
  * @returns {QUndoCommand}
  */
QUndoStack.prototype.command = function(index){return new QUndoCommand();};

/**
  * @name count
  * @function
  * @memberOf QUndoStack.prototype
  * @returns {Numeric}
  */
QUndoStack.prototype.count = function(){return new Numeric();};

/**
  * @name createRedoAction
  * @function
  * @memberOf QUndoStack.prototype
  * @param {QObject} parent
  * @param {String} prefix
  * @returns {QAction}
  */
QUndoStack.prototype.createRedoAction = function(parent, prefix){return new QAction();};

/**
  * @name createUndoAction
  * @function
  * @memberOf QUndoStack.prototype
  * @param {QObject} parent
  * @param {String} prefix
  * @returns {QAction}
  */
QUndoStack.prototype.createUndoAction = function(parent, prefix){return new QAction();};

/**
  * @name endMacro
  * @function
  * @memberOf QUndoStack.prototype
  * @returns {undefined}
  */
QUndoStack.prototype.endMacro = function(){return undefined;};

/**
  * @name index
  * @function
  * @memberOf QUndoStack.prototype
  * @returns {Numeric}
  */
QUndoStack.prototype.index = function(){return new Numeric();};

/**
  * @name isClean
  * @function
  * @memberOf QUndoStack.prototype
  * @returns {Boolean}
  */
QUndoStack.prototype.isClean = function(){return new Boolean();};

/**
  * @name push
  * @function
  * @memberOf QUndoStack.prototype
  * @param {QUndoCommand} cmd
  * @returns {undefined}
  */
QUndoStack.prototype.push = function(cmd){return undefined;};

/**
  * @name redoText
  * @function
  * @memberOf QUndoStack.prototype
  * @returns {String}
  */
QUndoStack.prototype.redoText = function(){return new String();};

/**
  * @name text
  * @function
  * @memberOf QUndoStack.prototype
  * @param {Numeric} idx
  * @returns {String}
  */
QUndoStack.prototype.text = function(idx){return new String();};

/**
  * @name undoText
  * @function
  * @memberOf QUndoStack.prototype
  * @returns {String}
  */
QUndoStack.prototype.undoText = function(){return new String();};

/**
  * @name active
  * @memberOf QUndoStack.prototype
  * @type Boolean
  */
QUndoStack.prototype.active = new Boolean();

/**
  * @name undoLimit
  * @memberOf QUndoStack.prototype
  * @type Numeric
  */
QUndoStack.prototype.undoLimit = new Numeric();


