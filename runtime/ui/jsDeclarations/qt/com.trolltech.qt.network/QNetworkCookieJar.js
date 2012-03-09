/**
  * @name QNetworkCookieJar
  * @constructor
  * @extends QObject
  * @param {QObject} parent
  */
function QNetworkCookieJar(parent){return undefined;};

QNetworkCookieJar.prototype = new QObject();

/**
  * @name cookiesForUrl
  * @function
  * @memberOf QNetworkCookieJar.prototype
  * @param {QUrl} url
  * @returns {Array}
  */
QNetworkCookieJar.prototype.cookiesForUrl = function(url){return new Array();};

/**
  * @name setCookiesFromUrl
  * @function
  * @memberOf QNetworkCookieJar.prototype
  * @param {Array} cookieList
  * @param {QUrl} url
  * @returns {Boolean}
  */
QNetworkCookieJar.prototype.setCookiesFromUrl = function(cookieList, url){return new Boolean();};

