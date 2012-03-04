

Network.prototype = new Object();

Network.prototype.stop = function(){return undefined;};
	
/**
 * @param {Boolean} show
 */
Network.prototype.showDialog = function(show){return undefined;};
	
/**
 * @signal
 * @param {ErrorCode} errorCode
 * @param {Number} numChannels
 */
Network.prototype.onStateChanged = function(errorCode, numChannels){return undefined;};

Network.prototype.allocAgent = function(){return new Agent();};




var network = new Network();
