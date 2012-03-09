function Client()
{
	return undefined;
}

Client.prototype = new QObject();


/**
 * @param {String} host
 * @param {String} service
 * @returns {undefined}
 */
Client.prototype.sessionStart = function(host, service){return undefined;};

/**
 * @signal
 * @param {Session} session
 * @param {ErrorCode} errorCode
 * @returns {undefined}
 */
Client.prototype.onSession = function(session, errorCode){return undefined;};
