/**
  * @name QStyledItemDelegate
  * @constructor
  * @extends QAbstractItemDelegate
  * @param {QObject} parent
  */
function QStyledItemDelegate(parent){return undefined;};

QStyledItemDelegate.prototype = new QAbstractItemDelegate();

/**
  * @name displayText
  * @function
  * @memberOf QStyledItemDelegate.prototype
  * @param {Object} value
  * @param {QLocale} locale
  * @returns {String}
  */
QStyledItemDelegate.prototype.displayText = function(value, locale){return new String();};

/**
  * @name itemEditorFactory
  * @function
  * @memberOf QStyledItemDelegate.prototype
  * @returns {QItemEditorFactory}
  */
QStyledItemDelegate.prototype.itemEditorFactory = function(){return new QItemEditorFactory();};

/**
  * @name setItemEditorFactory
  * @function
  * @memberOf QStyledItemDelegate.prototype
  * @param {QItemEditorFactory} factory
  * @returns {undefined}
  */
QStyledItemDelegate.prototype.setItemEditorFactory = function(factory){return undefined;};

