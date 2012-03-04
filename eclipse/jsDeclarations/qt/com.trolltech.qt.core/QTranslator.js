/**
  * @name QTranslator
  * @constructor
  * @extends QObject
  * @param {QObject} parent
  */
function QTranslator(parent){return undefined;};

QTranslator.prototype = new QObject();

/**
  * @name isEmpty
  * @function
  * @memberOf QTranslator.prototype
  * @returns {Boolean}
  */
QTranslator.prototype.isEmpty = function(){return new Boolean();};

/**
  * @name load
  * @function
  * @memberOf QTranslator.prototype
  * @param {QLocale} locale
  * @param {String} filename
  * @param {String} prefix
  * @param {String} directory
  * @param {String} suffix
  * @returns {Boolean}
  */
QTranslator.prototype.load = function(locale, filename, prefix, directory, suffix){return new Boolean();};

/**
  * @name translate
  * @function
  * @memberOf QTranslator.prototype
  * @param {String} context
  * @param {String} sourceText
  * @param {String} disambiguation
  * @returns {String}
  */
QTranslator.prototype.translate = function(context, sourceText, disambiguation){return new String();};

