/**
  * @name QFileOpenEvent
  * @constructor
  * @extends QEvent
  * @param {String} file
  */
function QFileOpenEvent(file){return undefined;};

/**
  * @name QFileOpenEvent^1
  * @constructor
  * @extends QEvent
  * @param {QUrl} url
  */
function QFileOpenEvent(url){return undefined;};

QFileOpenEvent.prototype = new QEvent();

/**
  * @name file
  * @function
  * @memberOf QFileOpenEvent.prototype
  * @returns {String}
  */
QFileOpenEvent.prototype.file = function(){return new String();};

/**
  * @name url
  * @function
  * @memberOf QFileOpenEvent.prototype
  * @returns {QUrl}
  */
QFileOpenEvent.prototype.url = function(){return new QUrl();};

