/**
  * @name QTreeWidget
  * @constructor
  * @extends QTreeView
  * @param {QWidget} parent
  */
function QTreeWidget(parent){return undefined;};

QTreeWidget.prototype = new QTreeView();

/**
  * @name addTopLevelItem
  * @function
  * @memberOf QTreeWidget.prototype
  * @param {QTreeWidgetItem} item
  * @returns {undefined}
  */
QTreeWidget.prototype.addTopLevelItem = function(item){return undefined;};

/**
  * @name addTopLevelItems
  * @function
  * @memberOf QTreeWidget.prototype
  * @param {Array} items
  * @returns {undefined}
  */
QTreeWidget.prototype.addTopLevelItems = function(items){return undefined;};

/**
  * @name closePersistentEditor
  * @function
  * @memberOf QTreeWidget.prototype
  * @param {QTreeWidgetItem} item
  * @param {Numeric} column
  * @returns {undefined}
  */
QTreeWidget.prototype.closePersistentEditor = function(item, column){return undefined;};

/**
  * @name currentColumn
  * @function
  * @memberOf QTreeWidget.prototype
  * @returns {Numeric}
  */
QTreeWidget.prototype.currentColumn = function(){return new Numeric();};

/**
  * @name currentItem
  * @function
  * @memberOf QTreeWidget.prototype
  * @returns {QTreeWidgetItem}
  */
QTreeWidget.prototype.currentItem = function(){return new QTreeWidgetItem();};

/**
  * @name editItem
  * @function
  * @memberOf QTreeWidget.prototype
  * @param {QTreeWidgetItem} item
  * @param {Numeric} column
  * @returns {undefined}
  */
QTreeWidget.prototype.editItem = function(item, column){return undefined;};

/**
  * @name findItems
  * @function
  * @memberOf QTreeWidget.prototype
  * @param {String} text
  * @param {Qt.MatchFlags} flags
  * @param {Numeric} column
  * @returns {Array}
  */
QTreeWidget.prototype.findItems = function(text, flags, column){return new Array();};

/**
  * @name headerItem
  * @function
  * @memberOf QTreeWidget.prototype
  * @returns {QTreeWidgetItem}
  */
QTreeWidget.prototype.headerItem = function(){return new QTreeWidgetItem();};

/**
  * @name indexOfTopLevelItem
  * @function
  * @memberOf QTreeWidget.prototype
  * @param {QTreeWidgetItem} item
  * @returns {Numeric}
  */
QTreeWidget.prototype.indexOfTopLevelItem = function(item){return new Numeric();};

/**
  * @name insertTopLevelItem
  * @function
  * @memberOf QTreeWidget.prototype
  * @param {Numeric} index
  * @param {QTreeWidgetItem} item
  * @returns {undefined}
  */
QTreeWidget.prototype.insertTopLevelItem = function(index, item){return undefined;};

/**
  * @name insertTopLevelItems
  * @function
  * @memberOf QTreeWidget.prototype
  * @param {Numeric} index
  * @param {Array} items
  * @returns {undefined}
  */
QTreeWidget.prototype.insertTopLevelItems = function(index, items){return undefined;};

/**
  * @name invisibleRootItem
  * @function
  * @memberOf QTreeWidget.prototype
  * @returns {QTreeWidgetItem}
  */
QTreeWidget.prototype.invisibleRootItem = function(){return new QTreeWidgetItem();};

/**
  * @name isFirstItemColumnSpanned
  * @function
  * @memberOf QTreeWidget.prototype
  * @param {QTreeWidgetItem} item
  * @returns {Boolean}
  */
QTreeWidget.prototype.isFirstItemColumnSpanned = function(item){return new Boolean();};

/**
  * @name itemAbove
  * @function
  * @memberOf QTreeWidget.prototype
  * @param {QTreeWidgetItem} item
  * @returns {QTreeWidgetItem}
  */
QTreeWidget.prototype.itemAbove = function(item){return new QTreeWidgetItem();};

/**
  * @name itemAt
  * @function
  * @memberOf QTreeWidget.prototype
  * @param {QPoint} p
  * @returns {QTreeWidgetItem}
  */
QTreeWidget.prototype.itemAt = function(p){return new QTreeWidgetItem();};

/**
  * @name itemBelow
  * @function
  * @memberOf QTreeWidget.prototype
  * @param {QTreeWidgetItem} item
  * @returns {QTreeWidgetItem}
  */
QTreeWidget.prototype.itemBelow = function(item){return new QTreeWidgetItem();};

/**
  * @name itemWidget
  * @function
  * @memberOf QTreeWidget.prototype
  * @param {QTreeWidgetItem} item
  * @param {Numeric} column
  * @returns {QWidget}
  */
QTreeWidget.prototype.itemWidget = function(item, column){return new QWidget();};

/**
  * @name openPersistentEditor
  * @function
  * @memberOf QTreeWidget.prototype
  * @param {QTreeWidgetItem} item
  * @param {Numeric} column
  * @returns {undefined}
  */
QTreeWidget.prototype.openPersistentEditor = function(item, column){return undefined;};

/**
  * @name removeItemWidget
  * @function
  * @memberOf QTreeWidget.prototype
  * @param {QTreeWidgetItem} item
  * @param {Numeric} column
  * @returns {undefined}
  */
QTreeWidget.prototype.removeItemWidget = function(item, column){return undefined;};

/**
  * @name selectedItems
  * @function
  * @memberOf QTreeWidget.prototype
  * @returns {Array}
  */
QTreeWidget.prototype.selectedItems = function(){return new Array();};

/**
  * @name setCurrentItem
  * @function
  * @memberOf QTreeWidget.prototype
  * @param {QTreeWidgetItem} item
  * @returns {undefined}
  */
QTreeWidget.prototype.setCurrentItem = function(item){return undefined;};

/**
  * @name setFirstItemColumnSpanned
  * @function
  * @memberOf QTreeWidget.prototype
  * @param {QTreeWidgetItem} item
  * @param {Boolean} span
  * @returns {undefined}
  */
QTreeWidget.prototype.setFirstItemColumnSpanned = function(item, span){return undefined;};

/**
  * @name setHeaderItem
  * @function
  * @memberOf QTreeWidget.prototype
  * @param {QTreeWidgetItem} item
  * @returns {undefined}
  */
QTreeWidget.prototype.setHeaderItem = function(item){return undefined;};

/**
  * @name setHeaderLabel
  * @function
  * @memberOf QTreeWidget.prototype
  * @param {String} label
  * @returns {undefined}
  */
QTreeWidget.prototype.setHeaderLabel = function(label){return undefined;};

/**
  * @name setHeaderLabels
  * @function
  * @memberOf QTreeWidget.prototype
  * @param {Array} labels
  * @returns {undefined}
  */
QTreeWidget.prototype.setHeaderLabels = function(labels){return undefined;};

/**
  * @name setItemWidget
  * @function
  * @memberOf QTreeWidget.prototype
  * @param {QTreeWidgetItem} item
  * @param {Numeric} column
  * @param {QWidget} widget
  * @returns {undefined}
  */
QTreeWidget.prototype.setItemWidget = function(item, column, widget){return undefined;};

/**
  * @name sortColumn
  * @function
  * @memberOf QTreeWidget.prototype
  * @returns {Numeric}
  */
QTreeWidget.prototype.sortColumn = function(){return new Numeric();};

/**
  * @name sortItems
  * @function
  * @memberOf QTreeWidget.prototype
  * @param {Numeric} column
  * @param {Qt.SortOrder} order
  * @returns {undefined}
  */
QTreeWidget.prototype.sortItems = function(column, order){return undefined;};

/**
  * @name takeTopLevelItem
  * @function
  * @memberOf QTreeWidget.prototype
  * @param {Numeric} index
  * @returns {QTreeWidgetItem}
  */
QTreeWidget.prototype.takeTopLevelItem = function(index){return new QTreeWidgetItem();};

/**
  * @name topLevelItem
  * @function
  * @memberOf QTreeWidget.prototype
  * @param {Numeric} index
  * @returns {QTreeWidgetItem}
  */
QTreeWidget.prototype.topLevelItem = function(index){return new QTreeWidgetItem();};

/**
  * @name visualItemRect
  * @function
  * @memberOf QTreeWidget.prototype
  * @param {QTreeWidgetItem} item
  * @returns {QRect}
  */
QTreeWidget.prototype.visualItemRect = function(item){return new QRect();};

/**
  * @name columnCount
  * @memberOf QTreeWidget.prototype
  * @type Numeric
  */
QTreeWidget.prototype.columnCount = new Numeric();

/**
  * @name topLevelItemCount
  * @memberOf QTreeWidget.prototype
  * @type Numeric
  */
QTreeWidget.prototype.topLevelItemCount = new Numeric();


