/**
  * @name QItemDelegate
  * @constructor
  * @extends QAbstractItemDelegate
  * @param {QObject} parent
  */
function QItemDelegate(parent){return undefined;};

QItemDelegate.prototype = new QAbstractItemDelegate();

/**
  * @name itemEditorFactory
  * @function
  * @memberOf QItemDelegate.prototype
  * @returns {QItemEditorFactory}
  */
QItemDelegate.prototype.itemEditorFactory = function(){return new QItemEditorFactory();};

/**
  * @name setItemEditorFactory
  * @function
  * @memberOf QItemDelegate.prototype
  * @param {QItemEditorFactory} factory
  * @returns {undefined}
  */
QItemDelegate.prototype.setItemEditorFactory = function(factory){return undefined;};

/**
  * @name clipping
  * @memberOf QItemDelegate.prototype
  * @type Boolean
  */
QItemDelegate.prototype.clipping = new Boolean();


