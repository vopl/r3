/**
  * @name QItemEditorFactory
  * @constructor
  */
function QItemEditorFactory(){return undefined;};

/**
  * @name defaultFactory
  * @function
  * @memberOf QItemEditorFactory
  * @returns {QItemEditorFactory}
  */
QItemEditorFactory.defaultFactory = function(){return new QItemEditorFactory();};

/**
  * @name setDefaultFactory
  * @function
  * @memberOf QItemEditorFactory
  * @param {QItemEditorFactory} factory
  * @returns {undefined}
  */
QItemEditorFactory.setDefaultFactory = function(factory){return undefined;};

/**
  * @name createEditor
  * @function
  * @memberOf QItemEditorFactory.prototype
  * @param {Object} type
  * @param {QWidget} parent
  * @returns {QWidget}
  */
QItemEditorFactory.prototype.createEditor = function(type, parent){return new QWidget();};

/**
  * @name registerEditor
  * @function
  * @memberOf QItemEditorFactory.prototype
  * @param {Object} type
  * @param {QItemEditorCreatorBase} creator
  * @returns {undefined}
  */
QItemEditorFactory.prototype.registerEditor = function(type, creator){return undefined;};

/**
  * @name valuePropertyName
  * @function
  * @memberOf QItemEditorFactory.prototype
  * @param {Object} type
  * @returns {QByteArray}
  */
QItemEditorFactory.prototype.valuePropertyName = function(type){return new QByteArray();};

