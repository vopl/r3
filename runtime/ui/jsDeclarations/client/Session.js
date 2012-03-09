Session.prototype = new QObject(); 

Session.prototype.client = new Client();

Session.prototype.numChannels = new Number();
Session.prototype.sid = new QUuid(); 

/**
 * @param {Number} numChannels
 */
Session.prototype.balance = function(numChannels){return undefined;};
Session.prototype.close = function(){return undefined;};
Session.prototype.allocAgent = function(){return new Agent();};

/**
 * @signal
 * @param {ErrorCode} errorCode
 * @param {Number} numChannels
 */
Session.prototype.onChanged = function(errorCode, numChannels){return undefined;};