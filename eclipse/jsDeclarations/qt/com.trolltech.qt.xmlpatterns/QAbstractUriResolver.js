/**
  * @name QAbstractUriResolver
  * @constructor
  * @extends QObject
  * @param {QObject} parent
  */
function QAbstractUriResolver(parent){return undefined;};

QAbstractUriResolver.prototype = new QObject();

/**
  * @name resolve
  * @function
  * @memberOf QAbstractUriResolver.prototype
  * @param {QUrl} relative
  * @param {QUrl} baseURI
  * @returns {QUrl}
  */
QAbstractUriResolver.prototype.resolve = function(relative, baseURI){return new QUrl();};

