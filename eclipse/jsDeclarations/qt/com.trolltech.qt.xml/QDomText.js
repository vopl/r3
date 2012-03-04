/**
  * @name QDomText
  * @constructor
  * @extends QDomCharacterData
  */
function QDomText(){return undefined;};

/**
  * @name QDomText^1
  * @constructor
  * @extends QDomCharacterData
  * @param {QDomText} x
  */
function QDomText(x){return undefined;};

QDomText.prototype = new QDomCharacterData();

/**
  * @name splitText
  * @function
  * @memberOf QDomText.prototype
  * @param {Numeric} offset
  * @returns {QDomText}
  */
QDomText.prototype.splitText = function(offset){return new QDomText();};

