/**
  * @class QAbstractMessageHandler from package com.trolltech.qt.xmlpatterns
  * @extends QObject
  */
var QAbstractMessageHandler = {};

QAbstractMessageHandler.prototype = new QObject();

/**
  * @name message
  * @function
  * @memberOf QAbstractMessageHandler.prototype
  * @param {Global.QtMsgType} type
  * @param {String} description
  * @param {QUrl} identifier
  * @param {QSourceLocation} sourceLocation
  * @returns {undefined}
  */
QAbstractMessageHandler.prototype.message = function(type, description, identifier, sourceLocation){return undefined;};

