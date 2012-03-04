
UiLoader.prototype = new QUiLoader();

///**
// * @constructor
// */
//UiLoader_load_proxyClass = function(){return undefined;};
UiLoader_load_proxyClass.prototype = new Object();

/**
 * 
 * @param {String} src
 * @param {QWidget} parentWidget
 * @returns {UiLoader_load_proxyClass}
 */
UiLoader.prototype.load = function(src, parentWidget){return new UiLoader_load_proxyClass();};

var uiLoader = new UiLoader();