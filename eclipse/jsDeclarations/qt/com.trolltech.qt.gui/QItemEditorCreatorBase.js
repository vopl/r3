/**
  * @name QItemEditorCreatorBase
  * @constructor
  */
function QItemEditorCreatorBase(){return undefined;};

/**
  * @name createWidget
  * @function
  * @memberOf QItemEditorCreatorBase.prototype
  * @param {QWidget} parent
  * @returns {QWidget}
  */
QItemEditorCreatorBase.prototype.createWidget = function(parent){return new QWidget();};

/**
  * @name valuePropertyName
  * @function
  * @memberOf QItemEditorCreatorBase.prototype
  * @returns {QByteArray}
  */
QItemEditorCreatorBase.prototype.valuePropertyName = function(){return new QByteArray();};

