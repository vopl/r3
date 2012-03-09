/**
  * @name QSplashScreen
  * @constructor
  * @extends QWidget
  * @param {QWidget} parent
  * @param {QPixmap} pixmap
  * @param {Qt.WindowFlags} f
  */
function QSplashScreen(parent, pixmap, f){return undefined;};

/**
  * @name QSplashScreen^1
  * @constructor
  * @extends QWidget
  * @param {QPixmap} pixmap
  * @param {Qt.WindowFlags} f
  */
function QSplashScreen(pixmap, f){return undefined;};

QSplashScreen.prototype = new QWidget();

/**
  * @name finish
  * @function
  * @memberOf QSplashScreen.prototype
  * @param {QWidget} w
  * @returns {undefined}
  */
QSplashScreen.prototype.finish = function(w){return undefined;};

/**
  * @name pixmap
  * @function
  * @memberOf QSplashScreen.prototype
  * @returns {QPixmap}
  */
QSplashScreen.prototype.pixmap = function(){return new QPixmap();};

/**
  * @name setPixmap
  * @function
  * @memberOf QSplashScreen.prototype
  * @param {QPixmap} pixmap
  * @returns {undefined}
  */
QSplashScreen.prototype.setPixmap = function(pixmap){return undefined;};

