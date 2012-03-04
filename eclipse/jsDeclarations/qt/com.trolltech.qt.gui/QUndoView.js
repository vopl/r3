/**
  * @name QUndoView
  * @constructor
  * @extends QListView
  * @param {QUndoGroup} group
  * @param {QWidget} parent
  */
function QUndoView(group, parent){return undefined;};

/**
  * @name QUndoView^1
  * @constructor
  * @extends QListView
  * @param {QUndoStack} stack
  * @param {QWidget} parent
  */
function QUndoView(stack, parent){return undefined;};

/**
  * @name QUndoView^2
  * @constructor
  * @extends QListView
  * @param {QWidget} parent
  */
function QUndoView(parent){return undefined;};

QUndoView.prototype = new QListView();

/**
  * @name group
  * @function
  * @memberOf QUndoView.prototype
  * @returns {QUndoGroup}
  */
QUndoView.prototype.group = function(){return new QUndoGroup();};

/**
  * @name stack
  * @function
  * @memberOf QUndoView.prototype
  * @returns {QUndoStack}
  */
QUndoView.prototype.stack = function(){return new QUndoStack();};

/**
  * @name emptyLabel
  * @memberOf QUndoView.prototype
  * @type String
  */
QUndoView.prototype.emptyLabel = new String();

/**
  * @name cleanIcon
  * @memberOf QUndoView.prototype
  * @type QIcon
  */
QUndoView.prototype.cleanIcon = new QIcon();


