/**
  * @name QInputContextFactory
  * @constructor
  */
function QInputContextFactory(){return undefined;};

/**
  * @name create
  * @function
  * @memberOf QInputContextFactory
  * @param {String} key
  * @param {QObject} parent
  * @returns {QInputContext}
  */
QInputContextFactory.create = function(key, parent){return new QInputContext();};

/**
  * @name description
  * @function
  * @memberOf QInputContextFactory
  * @param {String} key
  * @returns {String}
  */
QInputContextFactory.description = function(key){return new String();};

/**
  * @name displayName
  * @function
  * @memberOf QInputContextFactory
  * @param {String} key
  * @returns {String}
  */
QInputContextFactory.displayName = function(key){return new String();};

/**
  * @name keys
  * @function
  * @memberOf QInputContextFactory
  * @returns {Array}
  */
QInputContextFactory.keys = function(){return new Array();};

/**
  * @name languages
  * @function
  * @memberOf QInputContextFactory
  * @param {String} key
  * @returns {Array}
  */
QInputContextFactory.languages = function(key){return new Array();};

