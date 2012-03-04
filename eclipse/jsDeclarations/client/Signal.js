function Signal()
{
}

Signal.prototype = new QObject();

///**
// * @param {Function} func
// */
//Signal.prototype.connect = function(func){return undefined;};

/**
 * @param {Object} obj
 * @param {Function} func
 */
Signal.prototype.connect = function(obj, func){return undefined;};

///**
// * @name disconnect^1
// * @param {Function} func
// */
//Signal.prototype.disconnect = function(func){return undefined;};

/**
 * @name disconnect^2
 * @param {Object} obj
 * @param {Function} func
 */
Signal.prototype.disconnect = function(obj, func){return undefined;};
