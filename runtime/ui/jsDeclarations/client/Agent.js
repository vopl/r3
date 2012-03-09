Agent.prototype = new QObject();

Agent.prototype.session = new Session();

Agent.prototype.service = new String();

///**
// * @param {Object} data
// * @returns {undefined}
// */
//Agent.prototype.send = function(data){return undefined;};

/**
 * @param {Object} data
 * @param {String} service
 * @returns {undefined}
 */
Agent.prototype.send = function(data, service){return undefined;};

/**
 * @signal
 * @param {ErrorCode} errorCode
 * @param {Object} data
 * @param {String} service
 * @returns {undefined}
 */
Agent.prototype.onSendComplete = function(errorCode, data, service){return undefined;};

/**
 * @signal
 * @param {Object} data
 * @param {String} service
 * @returns {undefined}
 */
Agent.prototype.onReceive = function(data, service){return undefined;};

