/**
  * @name QSyntaxHighlighter
  * @constructor
  * @extends QObject
  * @param {QObject} parent
  */
function QSyntaxHighlighter(parent){return undefined;};

/**
  * @name QSyntaxHighlighter^1
  * @constructor
  * @extends QObject
  * @param {QTextDocument} parent
  */
function QSyntaxHighlighter(parent){return undefined;};

/**
  * @name QSyntaxHighlighter^2
  * @constructor
  * @extends QObject
  * @param {QTextEdit} parent
  */
function QSyntaxHighlighter(parent){return undefined;};

QSyntaxHighlighter.prototype = new QObject();

/**
  * @name document
  * @function
  * @memberOf QSyntaxHighlighter.prototype
  * @returns {QTextDocument}
  */
QSyntaxHighlighter.prototype.document = function(){return new QTextDocument();};

/**
  * @name setDocument
  * @function
  * @memberOf QSyntaxHighlighter.prototype
  * @param {QTextDocument} doc
  * @returns {undefined}
  */
QSyntaxHighlighter.prototype.setDocument = function(doc){return undefined;};

