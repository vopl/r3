/**
  * @name QListWidget
  * @constructor
  * @extends QListView
  * @param {QWidget} parent
  */
function QListWidget(parent){return undefined;};

QListWidget.prototype = new QListView();

/**
  * @name addItem
  * @function
  * @memberOf QListWidget.prototype
  * @param {QListWidgetItem} item
  * @returns {undefined}
  */
QListWidget.prototype.addItem = function(item){return undefined;};

/**
  * @name addItems
  * @function
  * @memberOf QListWidget.prototype
  * @param {Array} labels
  * @returns {undefined}
  */
QListWidget.prototype.addItems = function(labels){return undefined;};

/**
  * @name closePersistentEditor
  * @function
  * @memberOf QListWidget.prototype
  * @param {QListWidgetItem} item
  * @returns {undefined}
  */
QListWidget.prototype.closePersistentEditor = function(item){return undefined;};

/**
  * @name currentItem
  * @function
  * @memberOf QListWidget.prototype
  * @returns {QListWidgetItem}
  */
QListWidget.prototype.currentItem = function(){return new QListWidgetItem();};

/**
  * @name editItem
  * @function
  * @memberOf QListWidget.prototype
  * @param {QListWidgetItem} item
  * @returns {undefined}
  */
QListWidget.prototype.editItem = function(item){return undefined;};

/**
  * @name findItems
  * @function
  * @memberOf QListWidget.prototype
  * @param {String} text
  * @param {Qt.MatchFlags} flags
  * @returns {Array}
  */
QListWidget.prototype.findItems = function(text, flags){return new Array();};

/**
  * @name insertItem
  * @function
  * @memberOf QListWidget.prototype
  * @param {Numeric} row
  * @param {QListWidgetItem} item
  * @returns {undefined}
  */
QListWidget.prototype.insertItem = function(row, item){return undefined;};

/**
  * @name insertItems
  * @function
  * @memberOf QListWidget.prototype
  * @param {Numeric} row
  * @param {Array} labels
  * @returns {undefined}
  */
QListWidget.prototype.insertItems = function(row, labels){return undefined;};

/**
  * @name item
  * @function
  * @memberOf QListWidget.prototype
  * @param {Numeric} row
  * @returns {QListWidgetItem}
  */
QListWidget.prototype.item = function(row){return new QListWidgetItem();};

/**
  * @name itemAt
  * @function
  * @memberOf QListWidget.prototype
  * @param {QPoint} p
  * @returns {QListWidgetItem}
  */
QListWidget.prototype.itemAt = function(p){return new QListWidgetItem();};

/**
  * @name itemWidget
  * @function
  * @memberOf QListWidget.prototype
  * @param {QListWidgetItem} item
  * @returns {QWidget}
  */
QListWidget.prototype.itemWidget = function(item){return new QWidget();};

/**
  * @name openPersistentEditor
  * @function
  * @memberOf QListWidget.prototype
  * @param {QListWidgetItem} item
  * @returns {undefined}
  */
QListWidget.prototype.openPersistentEditor = function(item){return undefined;};

/**
  * @name removeItemWidget
  * @function
  * @memberOf QListWidget.prototype
  * @param {QListWidgetItem} item
  * @returns {undefined}
  */
QListWidget.prototype.removeItemWidget = function(item){return undefined;};

/**
  * @name row
  * @function
  * @memberOf QListWidget.prototype
  * @param {QListWidgetItem} item
  * @returns {Numeric}
  */
QListWidget.prototype.row = function(item){return new Numeric();};

/**
  * @name selectedItems
  * @function
  * @memberOf QListWidget.prototype
  * @returns {Array}
  */
QListWidget.prototype.selectedItems = function(){return new Array();};

/**
  * @name setCurrentItem
  * @function
  * @memberOf QListWidget.prototype
  * @param {QListWidgetItem} item
  * @returns {undefined}
  */
QListWidget.prototype.setCurrentItem = function(item){return undefined;};

/**
  * @name setItemWidget
  * @function
  * @memberOf QListWidget.prototype
  * @param {QListWidgetItem} item
  * @param {QWidget} widget
  * @returns {undefined}
  */
QListWidget.prototype.setItemWidget = function(item, widget){return undefined;};

/**
  * @name sortItems
  * @function
  * @memberOf QListWidget.prototype
  * @param {Qt.SortOrder} order
  * @returns {undefined}
  */
QListWidget.prototype.sortItems = function(order){return undefined;};

/**
  * @name takeItem
  * @function
  * @memberOf QListWidget.prototype
  * @param {Numeric} row
  * @returns {QListWidgetItem}
  */
QListWidget.prototype.takeItem = function(row){return new QListWidgetItem();};

/**
  * @name visualItemRect
  * @function
  * @memberOf QListWidget.prototype
  * @param {QListWidgetItem} item
  * @returns {QRect}
  */
QListWidget.prototype.visualItemRect = function(item){return new QRect();};

/**
  * @name count
  * @memberOf QListWidget.prototype
  * @type Numeric
  */
QListWidget.prototype.count = new Numeric();

/**
  * @name currentRow
  * @memberOf QListWidget.prototype
  * @type Numeric
  */
QListWidget.prototype.currentRow = new Numeric();

/**
  * @name sortingEnabled
  * @memberOf QListWidget.prototype
  * @type Boolean
  */
QListWidget.prototype.sortingEnabled = new Boolean();


