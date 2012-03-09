/**
  * @class QTextObject from package com.trolltech.qt.gui
  * @extends QObject
  */
var QTextObject = {};

QTextObject.prototype = new QObject();

/**
  * @name document
  * @function
  * @memberOf QTextObject.prototype
  * @returns {QTextDocument}
  */
QTextObject.prototype.document = function(){return new QTextDocument();};

/**
  * @name format
  * @function
  * @memberOf QTextObject.prototype
  * @returns {QTextFormat}
  */
QTextObject.prototype.format = function(){return new QTextFormat();};

/**
  * @name formatIndex
  * @function
  * @memberOf QTextObject.prototype
  * @returns {Numeric}
  */
QTextObject.prototype.formatIndex = function(){return new Numeric();};

/**
  * @name objectIndex
  * @function
  * @memberOf QTextObject.prototype
  * @returns {Numeric}
  */
QTextObject.prototype.objectIndex = function(){return new Numeric();};

