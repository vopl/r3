/**
  * @name QErrorMessage
  * @constructor
  * @extends QDialog
  * @param {QWidget} parent
  */
function QErrorMessage(parent){return undefined;};

QErrorMessage.prototype = new QDialog();

/**
  * @name qtHandler
  * @function
  * @memberOf QErrorMessage
  * @returns {QErrorMessage}
  */
QErrorMessage.qtHandler = function(){return new QErrorMessage();};

