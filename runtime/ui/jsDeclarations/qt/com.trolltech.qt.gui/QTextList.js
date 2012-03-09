/**
  * @name QTextList
  * @constructor
  * @extends QTextBlockGroup
  * @param {QTextDocument} doc
  */
function QTextList(doc){return undefined;};

QTextList.prototype = new QTextBlockGroup();

/**
  * @name add
  * @function
  * @memberOf QTextList.prototype
  * @param {QTextBlock} block
  * @returns {undefined}
  */
QTextList.prototype.add = function(block){return undefined;};

/**
  * @name count
  * @function
  * @memberOf QTextList.prototype
  * @returns {Numeric}
  */
QTextList.prototype.count = function(){return new Numeric();};

/**
  * @name item
  * @function
  * @memberOf QTextList.prototype
  * @param {Numeric} i
  * @returns {QTextBlock}
  */
QTextList.prototype.item = function(i){return new QTextBlock();};

/**
  * @name itemNumber
  * @function
  * @memberOf QTextList.prototype
  * @param {QTextBlock} arg__1
  * @returns {Numeric}
  */
QTextList.prototype.itemNumber = function(arg__1){return new Numeric();};

/**
  * @name itemText
  * @function
  * @memberOf QTextList.prototype
  * @param {QTextBlock} arg__1
  * @returns {String}
  */
QTextList.prototype.itemText = function(arg__1){return new String();};

/**
  * @name remove
  * @function
  * @memberOf QTextList.prototype
  * @param {QTextBlock} arg__1
  * @returns {undefined}
  */
QTextList.prototype.remove = function(arg__1){return undefined;};

/**
  * @name removeItem
  * @function
  * @memberOf QTextList.prototype
  * @param {Numeric} i
  * @returns {undefined}
  */
QTextList.prototype.removeItem = function(i){return undefined;};

/**
  * @name setFormat
  * @function
  * @memberOf QTextList.prototype
  * @param {QTextListFormat} format
  * @returns {undefined}
  */
QTextList.prototype.setFormat = function(format){return undefined;};

/**
  * @name textListFormat
  * @function
  * @memberOf QTextList.prototype
  * @returns {QTextListFormat}
  */
QTextList.prototype.textListFormat = function(){return new QTextListFormat();};

