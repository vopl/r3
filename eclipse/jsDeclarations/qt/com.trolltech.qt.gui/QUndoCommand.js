/**
  * @name QUndoCommand
  * @constructor
  * @param {QUndoCommand} parent
  */
function QUndoCommand(parent){return undefined;};

/**
  * @name QUndoCommand^1
  * @constructor
  * @param {String} text
  * @param {QUndoCommand} parent
  */
function QUndoCommand(text, parent){return undefined;};

/**
  * @name actionText
  * @function
  * @memberOf QUndoCommand.prototype
  * @returns {String}
  */
QUndoCommand.prototype.actionText = function(){return new String();};

/**
  * @name child
  * @function
  * @memberOf QUndoCommand.prototype
  * @param {Numeric} index
  * @returns {QUndoCommand}
  */
QUndoCommand.prototype.child = function(index){return new QUndoCommand();};

/**
  * @name childCount
  * @function
  * @memberOf QUndoCommand.prototype
  * @returns {Numeric}
  */
QUndoCommand.prototype.childCount = function(){return new Numeric();};

/**
  * @name id
  * @function
  * @memberOf QUndoCommand.prototype
  * @returns {Numeric}
  */
QUndoCommand.prototype.id = function(){return new Numeric();};

/**
  * @name mergeWith
  * @function
  * @memberOf QUndoCommand.prototype
  * @param {QUndoCommand} other
  * @returns {Boolean}
  */
QUndoCommand.prototype.mergeWith = function(other){return new Boolean();};

/**
  * @name redo
  * @function
  * @memberOf QUndoCommand.prototype
  * @returns {undefined}
  */
QUndoCommand.prototype.redo = function(){return undefined;};

/**
  * @name setText
  * @function
  * @memberOf QUndoCommand.prototype
  * @param {String} text
  * @returns {undefined}
  */
QUndoCommand.prototype.setText = function(text){return undefined;};

/**
  * @name text
  * @function
  * @memberOf QUndoCommand.prototype
  * @returns {String}
  */
QUndoCommand.prototype.text = function(){return new String();};

/**
  * @name undo
  * @function
  * @memberOf QUndoCommand.prototype
  * @returns {undefined}
  */
QUndoCommand.prototype.undo = function(){return undefined;};

