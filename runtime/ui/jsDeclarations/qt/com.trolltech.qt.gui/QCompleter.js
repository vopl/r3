/**
  * @name QCompleter
  * @constructor
  * @extends QObject
  * @param {QAbstractItemModel} model
  * @param {QObject} parent
  */
function QCompleter(model, parent){return undefined;};

/**
  * @name QCompleter^1
  * @constructor
  * @extends QObject
  * @param {QObject} parent
  */
function QCompleter(parent){return undefined;};

/**
  * @name QCompleter^2
  * @constructor
  * @extends QObject
  * @param {Array} completions
  * @param {QObject} parent
  */
function QCompleter(completions, parent){return undefined;};

QCompleter.prototype = new QObject();

/**
  * @default 0
  * @constant
  * @memberOf QCompleter
  * @name UnsortedModel
  * @see QCompleter#ModelSorting
  * @type Number
  */
QCompleter.UnsortedModel = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QCompleter
  * @name CaseSensitivelySortedModel
  * @see QCompleter#ModelSorting
  * @type Number
  */
QCompleter.CaseSensitivelySortedModel = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QCompleter
  * @name CaseInsensitivelySortedModel
  * @see QCompleter#ModelSorting
  * @type Number
  */
QCompleter.CaseInsensitivelySortedModel = 0x2;

/**
  * @constructor 
  * @memberOf QCompleter
  * @name ModelSorting
  */
QCompleter.ModelSorting = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QCompleter
  * @name PopupCompletion
  * @see QCompleter#CompletionMode
  * @type Number
  */
QCompleter.PopupCompletion = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QCompleter
  * @name UnfilteredPopupCompletion
  * @see QCompleter#CompletionMode
  * @type Number
  */
QCompleter.UnfilteredPopupCompletion = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QCompleter
  * @name InlineCompletion
  * @see QCompleter#CompletionMode
  * @type Number
  */
QCompleter.InlineCompletion = 0x2;

/**
  * @constructor 
  * @memberOf QCompleter
  * @name CompletionMode
  */
QCompleter.CompletionMode = function(value){;};



/**
  * @name completionCount
  * @function
  * @memberOf QCompleter.prototype
  * @returns {Numeric}
  */
QCompleter.prototype.completionCount = function(){return new Numeric();};

/**
  * @name completionModel
  * @function
  * @memberOf QCompleter.prototype
  * @returns {QAbstractItemModel}
  */
QCompleter.prototype.completionModel = function(){return new QAbstractItemModel();};

/**
  * @name currentCompletion
  * @function
  * @memberOf QCompleter.prototype
  * @returns {String}
  */
QCompleter.prototype.currentCompletion = function(){return new String();};

/**
  * @name currentIndex
  * @function
  * @memberOf QCompleter.prototype
  * @returns {QModelIndex}
  */
QCompleter.prototype.currentIndex = function(){return new QModelIndex();};

/**
  * @name currentRow
  * @function
  * @memberOf QCompleter.prototype
  * @returns {Numeric}
  */
QCompleter.prototype.currentRow = function(){return new Numeric();};

/**
  * @name model
  * @function
  * @memberOf QCompleter.prototype
  * @returns {QAbstractItemModel}
  */
QCompleter.prototype.model = function(){return new QAbstractItemModel();};

/**
  * @name pathFromIndex
  * @function
  * @memberOf QCompleter.prototype
  * @param {QModelIndex} index
  * @returns {String}
  */
QCompleter.prototype.pathFromIndex = function(index){return new String();};

/**
  * @name popup
  * @function
  * @memberOf QCompleter.prototype
  * @returns {QAbstractItemView}
  */
QCompleter.prototype.popup = function(){return new QAbstractItemView();};

/**
  * @name setCurrentRow
  * @function
  * @memberOf QCompleter.prototype
  * @param {Numeric} row
  * @returns {Boolean}
  */
QCompleter.prototype.setCurrentRow = function(row){return new Boolean();};

/**
  * @name setModel
  * @function
  * @memberOf QCompleter.prototype
  * @param {QAbstractItemModel} c
  * @returns {undefined}
  */
QCompleter.prototype.setModel = function(c){return undefined;};

/**
  * @name setPopup
  * @function
  * @memberOf QCompleter.prototype
  * @param {QAbstractItemView} popup
  * @returns {undefined}
  */
QCompleter.prototype.setPopup = function(popup){return undefined;};

/**
  * @name setWidget
  * @function
  * @memberOf QCompleter.prototype
  * @param {QWidget} widget
  * @returns {undefined}
  */
QCompleter.prototype.setWidget = function(widget){return undefined;};

/**
  * @name splitPath
  * @function
  * @memberOf QCompleter.prototype
  * @param {String} path
  * @returns {Array}
  */
QCompleter.prototype.splitPath = function(path){return new Array();};

/**
  * @name widget
  * @function
  * @memberOf QCompleter.prototype
  * @returns {QWidget}
  */
QCompleter.prototype.widget = function(){return new QWidget();};

/**
  * @name completionPrefix
  * @memberOf QCompleter.prototype
  * @type String
  */
QCompleter.prototype.completionPrefix = new String();

/**
  * @name modelSorting
  * @memberOf QCompleter.prototype
  * @type QCompleter.ModelSorting
  */
QCompleter.prototype.modelSorting = new QCompleter.ModelSorting();

/**
  * @name completionMode
  * @memberOf QCompleter.prototype
  * @type QCompleter.CompletionMode
  */
QCompleter.prototype.completionMode = new QCompleter.CompletionMode();

/**
  * @name completionColumn
  * @memberOf QCompleter.prototype
  * @type Numeric
  */
QCompleter.prototype.completionColumn = new Numeric();

/**
  * @name completionRole
  * @memberOf QCompleter.prototype
  * @type Numeric
  */
QCompleter.prototype.completionRole = new Numeric();

/**
  * @name maxVisibleItems
  * @memberOf QCompleter.prototype
  * @type Numeric
  */
QCompleter.prototype.maxVisibleItems = new Numeric();

/**
  * @name caseSensitivity
  * @memberOf QCompleter.prototype
  * @type Qt.CaseSensitivity
  */
QCompleter.prototype.caseSensitivity = new Qt.CaseSensitivity();

/**
  * @name wrapAround
  * @memberOf QCompleter.prototype
  * @type Boolean
  */
QCompleter.prototype.wrapAround = new Boolean();


