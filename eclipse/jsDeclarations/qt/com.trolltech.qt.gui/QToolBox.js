/**
  * @name QToolBox
  * @constructor
  * @extends QFrame
  * @param {QWidget} parent
  * @param {Qt.WindowFlags} f
  */
function QToolBox(parent, f){return undefined;};

QToolBox.prototype = new QFrame();

/**
  * @name addItem
  * @function
  * @memberOf QToolBox.prototype
  * @param {QWidget} widget
  * @param {QIcon} icon
  * @param {String} text
  * @returns {Numeric}
  */
QToolBox.prototype.addItem = function(widget, icon, text){return new Numeric();};

/**
  * @name currentWidget
  * @function
  * @memberOf QToolBox.prototype
  * @returns {QWidget}
  */
QToolBox.prototype.currentWidget = function(){return new QWidget();};

/**
  * @name indexOf
  * @function
  * @memberOf QToolBox.prototype
  * @param {QWidget} widget
  * @returns {Numeric}
  */
QToolBox.prototype.indexOf = function(widget){return new Numeric();};

/**
  * @name insertItem
  * @function
  * @memberOf QToolBox.prototype
  * @param {Numeric} index
  * @param {QWidget} widget
  * @param {QIcon} icon
  * @param {String} text
  * @returns {Numeric}
  */
QToolBox.prototype.insertItem = function(index, widget, icon, text){return new Numeric();};

/**
  * @name isItemEnabled
  * @function
  * @memberOf QToolBox.prototype
  * @param {Numeric} index
  * @returns {Boolean}
  */
QToolBox.prototype.isItemEnabled = function(index){return new Boolean();};

/**
  * @name itemIcon
  * @function
  * @memberOf QToolBox.prototype
  * @param {Numeric} index
  * @returns {QIcon}
  */
QToolBox.prototype.itemIcon = function(index){return new QIcon();};

/**
  * @name itemText
  * @function
  * @memberOf QToolBox.prototype
  * @param {Numeric} index
  * @returns {String}
  */
QToolBox.prototype.itemText = function(index){return new String();};

/**
  * @name itemToolTip
  * @function
  * @memberOf QToolBox.prototype
  * @param {Numeric} index
  * @returns {String}
  */
QToolBox.prototype.itemToolTip = function(index){return new String();};

/**
  * @name removeItem
  * @function
  * @memberOf QToolBox.prototype
  * @param {Numeric} index
  * @returns {undefined}
  */
QToolBox.prototype.removeItem = function(index){return undefined;};

/**
  * @name setItemEnabled
  * @function
  * @memberOf QToolBox.prototype
  * @param {Numeric} index
  * @param {Boolean} enabled
  * @returns {undefined}
  */
QToolBox.prototype.setItemEnabled = function(index, enabled){return undefined;};

/**
  * @name setItemIcon
  * @function
  * @memberOf QToolBox.prototype
  * @param {Numeric} index
  * @param {QIcon} icon
  * @returns {undefined}
  */
QToolBox.prototype.setItemIcon = function(index, icon){return undefined;};

/**
  * @name setItemText
  * @function
  * @memberOf QToolBox.prototype
  * @param {Numeric} index
  * @param {String} text
  * @returns {undefined}
  */
QToolBox.prototype.setItemText = function(index, text){return undefined;};

/**
  * @name setItemToolTip
  * @function
  * @memberOf QToolBox.prototype
  * @param {Numeric} index
  * @param {String} toolTip
  * @returns {undefined}
  */
QToolBox.prototype.setItemToolTip = function(index, toolTip){return undefined;};

/**
  * @name widget
  * @function
  * @memberOf QToolBox.prototype
  * @param {Numeric} index
  * @returns {QWidget}
  */
QToolBox.prototype.widget = function(index){return new QWidget();};

/**
  * @name currentIndex
  * @memberOf QToolBox.prototype
  * @type Numeric
  */
QToolBox.prototype.currentIndex = new Numeric();

/**
  * @name count
  * @memberOf QToolBox.prototype
  * @type Numeric
  */
QToolBox.prototype.count = new Numeric();


