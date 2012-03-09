/**
  * @name QDataWidgetMapper
  * @constructor
  * @extends QObject
  * @param {QObject} parent
  */
function QDataWidgetMapper(parent){return undefined;};

QDataWidgetMapper.prototype = new QObject();

/**
  * @default 0x0
  * @constant
  * @memberOf QDataWidgetMapper
  * @name AutoSubmit
  * @see QDataWidgetMapper#SubmitPolicy
  * @type Number
  */
QDataWidgetMapper.AutoSubmit = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QDataWidgetMapper
  * @name ManualSubmit
  * @see QDataWidgetMapper#SubmitPolicy
  * @type Number
  */
QDataWidgetMapper.ManualSubmit = 0x1;

/**
  * @constructor 
  * @memberOf QDataWidgetMapper
  * @name SubmitPolicy
  */
QDataWidgetMapper.SubmitPolicy = function(value){;};



/**
  * @name addMapping
  * @function
  * @memberOf QDataWidgetMapper.prototype
  * @param {QWidget} widget
  * @param {Numeric} section
  * @returns {undefined}
  */
QDataWidgetMapper.prototype.addMapping = function(widget, section){return undefined;};

/**
  * @name clearMapping
  * @function
  * @memberOf QDataWidgetMapper.prototype
  * @returns {undefined}
  */
QDataWidgetMapper.prototype.clearMapping = function(){return undefined;};

/**
  * @name itemDelegate
  * @function
  * @memberOf QDataWidgetMapper.prototype
  * @returns {QAbstractItemDelegate}
  */
QDataWidgetMapper.prototype.itemDelegate = function(){return new QAbstractItemDelegate();};

/**
  * @name mappedPropertyName
  * @function
  * @memberOf QDataWidgetMapper.prototype
  * @param {QWidget} widget
  * @returns {QByteArray}
  */
QDataWidgetMapper.prototype.mappedPropertyName = function(widget){return new QByteArray();};

/**
  * @name mappedSection
  * @function
  * @memberOf QDataWidgetMapper.prototype
  * @param {QWidget} widget
  * @returns {Numeric}
  */
QDataWidgetMapper.prototype.mappedSection = function(widget){return new Numeric();};

/**
  * @name mappedWidgetAt
  * @function
  * @memberOf QDataWidgetMapper.prototype
  * @param {Numeric} section
  * @returns {QWidget}
  */
QDataWidgetMapper.prototype.mappedWidgetAt = function(section){return new QWidget();};

/**
  * @name model
  * @function
  * @memberOf QDataWidgetMapper.prototype
  * @returns {QAbstractItemModel}
  */
QDataWidgetMapper.prototype.model = function(){return new QAbstractItemModel();};

/**
  * @name removeMapping
  * @function
  * @memberOf QDataWidgetMapper.prototype
  * @param {QWidget} widget
  * @returns {undefined}
  */
QDataWidgetMapper.prototype.removeMapping = function(widget){return undefined;};

/**
  * @name rootIndex
  * @function
  * @memberOf QDataWidgetMapper.prototype
  * @returns {QModelIndex}
  */
QDataWidgetMapper.prototype.rootIndex = function(){return new QModelIndex();};

/**
  * @name setItemDelegate
  * @function
  * @memberOf QDataWidgetMapper.prototype
  * @param {QAbstractItemDelegate} delegate
  * @returns {undefined}
  */
QDataWidgetMapper.prototype.setItemDelegate = function(delegate){return undefined;};

/**
  * @name setModel
  * @function
  * @memberOf QDataWidgetMapper.prototype
  * @param {QAbstractItemModel} model
  * @returns {undefined}
  */
QDataWidgetMapper.prototype.setModel = function(model){return undefined;};

/**
  * @name setRootIndex
  * @function
  * @memberOf QDataWidgetMapper.prototype
  * @param {QModelIndex} index
  * @returns {undefined}
  */
QDataWidgetMapper.prototype.setRootIndex = function(index){return undefined;};

/**
  * @name currentIndex
  * @memberOf QDataWidgetMapper.prototype
  * @type Numeric
  */
QDataWidgetMapper.prototype.currentIndex = new Numeric();

/**
  * @name orientation
  * @memberOf QDataWidgetMapper.prototype
  * @type QPrinter.Orientation
  */
QDataWidgetMapper.prototype.orientation = new QPrinter.Orientation();

/**
  * @name submitPolicy
  * @memberOf QDataWidgetMapper.prototype
  * @type QDataWidgetMapper.SubmitPolicy
  */
QDataWidgetMapper.prototype.submitPolicy = new QDataWidgetMapper.SubmitPolicy();


