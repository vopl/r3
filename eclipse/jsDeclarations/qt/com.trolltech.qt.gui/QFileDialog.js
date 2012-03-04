/**
  * @name QFileDialog
  * @constructor
  * @extends QDialog
  * @param {QWidget} parent
  * @param {Qt.WindowFlags} f
  */
function QFileDialog(parent, f){return undefined;};

/**
  * @name QFileDialog^1
  * @constructor
  * @extends QDialog
  * @param {QWidget} parent
  * @param {String} caption
  * @param {String} directory
  * @param {String} filter
  */
function QFileDialog(parent, caption, directory, filter){return undefined;};

QFileDialog.prototype = new QDialog();

/**
  * @name getExistingDirectory
  * @function
  * @memberOf QFileDialog
  * @param {QWidget} parent
  * @param {String} caption
  * @param {String} dir
  * @param {QFileDialog.Options} options
  * @returns {String}
  */
QFileDialog.getExistingDirectory = function(parent, caption, dir, options){return new String();};

/**
  * @name getOpenFileName
  * @function
  * @memberOf QFileDialog
  * @param {QWidget} parent
  * @param {String} caption
  * @param {String} dir
  * @param {String} filter
  * @param {String} selectedFilter
  * @param {QFileDialog.Options} options
  * @returns {String}
  */
QFileDialog.getOpenFileName = function(parent, caption, dir, filter, selectedFilter, options){return new String();};

/**
  * @name getOpenFileNames
  * @function
  * @memberOf QFileDialog
  * @param {QWidget} parent
  * @param {String} caption
  * @param {String} dir
  * @param {String} filter
  * @param {String} selectedFilter
  * @param {QFileDialog.Options} options
  * @returns {Array}
  */
QFileDialog.getOpenFileNames = function(parent, caption, dir, filter, selectedFilter, options){return new Array();};

/**
  * @name getSaveFileName
  * @function
  * @memberOf QFileDialog
  * @param {QWidget} parent
  * @param {String} caption
  * @param {String} dir
  * @param {String} filter
  * @param {String} selectedFilter
  * @param {QFileDialog.Options} options
  * @returns {String}
  */
QFileDialog.getSaveFileName = function(parent, caption, dir, filter, selectedFilter, options){return new String();};

/**
  * @default 0x0
  * @constant
  * @memberOf QFileDialog
  * @name AnyFile
  * @see QFileDialog#FileMode
  * @type Number
  */
QFileDialog.AnyFile = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QFileDialog
  * @name ExistingFile
  * @see QFileDialog#FileMode
  * @type Number
  */
QFileDialog.ExistingFile = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QFileDialog
  * @name Directory
  * @see QFileDialog#FileMode
  * @type Number
  */
QFileDialog.Directory = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QFileDialog
  * @name ExistingFiles
  * @see QFileDialog#FileMode
  * @type Number
  */
QFileDialog.ExistingFiles = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QFileDialog
  * @name DirectoryOnly
  * @see QFileDialog#FileMode
  * @type Number
  */
QFileDialog.DirectoryOnly = 0x4;

/**
  * @constructor 
  * @memberOf QFileDialog
  * @name FileMode
  */
QFileDialog.FileMode = function(value){;};



/**
  * @default 0x00000001
  * @constant
  * @memberOf QFileDialog
  * @name ShowDirsOnly
  * @see QFileDialog#Options
  * @see QFileDialog#Option
  * @type Number
  */
QFileDialog.ShowDirsOnly = 0x1;

/**
  * @default 0x00000002
  * @constant
  * @memberOf QFileDialog
  * @name DontResolveSymlinks
  * @see QFileDialog#Options
  * @see QFileDialog#Option
  * @type Number
  */
QFileDialog.DontResolveSymlinks = 0x2;

/**
  * @default 0x00000004
  * @constant
  * @memberOf QFileDialog
  * @name DontConfirmOverwrite
  * @see QFileDialog#Options
  * @see QFileDialog#Option
  * @type Number
  */
QFileDialog.DontConfirmOverwrite = 0x4;

/**
  * @default 0x00000008
  * @constant
  * @memberOf QFileDialog
  * @name DontUseSheet
  * @see QFileDialog#Options
  * @see QFileDialog#Option
  * @type Number
  */
QFileDialog.DontUseSheet = 0x8;

/**
  * @default 0x00000010
  * @constant
  * @memberOf QFileDialog
  * @name DontUseNativeDialog
  * @see QFileDialog#Options
  * @see QFileDialog#Option
  * @type Number
  */
QFileDialog.DontUseNativeDialog = 0x10;

/**
  * @default 0x00000020
  * @constant
  * @memberOf QFileDialog
  * @name ReadOnly
  * @see QFileDialog#Options
  * @see QFileDialog#Option
  * @type Number
  */
QFileDialog.ReadOnly = 0x20;

/**
  * @default 0x00000040
  * @constant
  * @memberOf QFileDialog
  * @name HideNameFilterDetails
  * @see QFileDialog#Options
  * @see QFileDialog#Option
  * @type Number
  */
QFileDialog.HideNameFilterDetails = 0x40;

/**
  * @constructor 
  * @memberOf QFileDialog
  * @name Option
  */
QFileDialog.Option = function(value){;};

/**
  * @constructor 
  * @memberOf QFileDialog
  * @name Options
  */
QFileDialog.Options = function(value1, value2 /*, ...*/){;};


/**
  * @default 0x0
  * @constant
  * @memberOf QFileDialog
  * @name LookIn
  * @see QFileDialog#DialogLabel
  * @type Number
  */
QFileDialog.LookIn = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QFileDialog
  * @name FileName
  * @see QFileDialog#DialogLabel
  * @type Number
  */
QFileDialog.FileName = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QFileDialog
  * @name FileType
  * @see QFileDialog#DialogLabel
  * @type Number
  */
QFileDialog.FileType = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QFileDialog
  * @name Accept
  * @see QFileDialog#DialogLabel
  * @type Number
  */
QFileDialog.Accept = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QFileDialog
  * @name Reject
  * @see QFileDialog#DialogLabel
  * @type Number
  */
QFileDialog.Reject = 0x4;

/**
  * @constructor 
  * @memberOf QFileDialog
  * @name DialogLabel
  */
QFileDialog.DialogLabel = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QFileDialog
  * @name Detail
  * @see QFileDialog#ViewMode
  * @type Number
  */
QFileDialog.Detail = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QFileDialog
  * @name List
  * @see QFileDialog#ViewMode
  * @type Number
  */
QFileDialog.List = 0x1;

/**
  * @constructor 
  * @memberOf QFileDialog
  * @name ViewMode
  */
QFileDialog.ViewMode = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QFileDialog
  * @name AcceptOpen
  * @see QFileDialog#AcceptMode
  * @type Number
  */
QFileDialog.AcceptOpen = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QFileDialog
  * @name AcceptSave
  * @see QFileDialog#AcceptMode
  * @type Number
  */
QFileDialog.AcceptSave = 0x1;

/**
  * @constructor 
  * @memberOf QFileDialog
  * @name AcceptMode
  */
QFileDialog.AcceptMode = function(value){;};



/**
  * @name directory
  * @function
  * @memberOf QFileDialog.prototype
  * @returns {QDir}
  */
QFileDialog.prototype.directory = function(){return new QDir();};

/**
  * @name filter
  * @function
  * @memberOf QFileDialog.prototype
  * @returns {QDir.Filters}
  */
QFileDialog.prototype.filter = function(){return new QDir.Filters();};

/**
  * @name filters
  * @function
  * @memberOf QFileDialog.prototype
  * @returns {Array}
  */
QFileDialog.prototype.filters = function(){return new Array();};

/**
  * @name history
  * @function
  * @memberOf QFileDialog.prototype
  * @returns {Array}
  */
QFileDialog.prototype.history = function(){return new Array();};

/**
  * @name iconProvider
  * @function
  * @memberOf QFileDialog.prototype
  * @returns {QFileIconProvider}
  */
QFileDialog.prototype.iconProvider = function(){return new QFileIconProvider();};

/**
  * @name isNameFilterDetailsVisible
  * @function
  * @memberOf QFileDialog.prototype
  * @returns {Boolean}
  */
QFileDialog.prototype.isNameFilterDetailsVisible = function(){return new Boolean();};

/**
  * @name itemDelegate
  * @function
  * @memberOf QFileDialog.prototype
  * @returns {QAbstractItemDelegate}
  */
QFileDialog.prototype.itemDelegate = function(){return new QAbstractItemDelegate();};

/**
  * @name labelText
  * @function
  * @memberOf QFileDialog.prototype
  * @param {QFileDialog.DialogLabel} label
  * @returns {String}
  */
QFileDialog.prototype.labelText = function(label){return new String();};

/**
  * @name nameFilters
  * @function
  * @memberOf QFileDialog.prototype
  * @returns {Array}
  */
QFileDialog.prototype.nameFilters = function(){return new Array();};

/**
  * @name open
  * @function
  * @memberOf QFileDialog.prototype
  * @param {QObject} receiver
  * @param {String} member
  * @returns {undefined}
  */
QFileDialog.prototype.open = function(receiver, member){return undefined;};

/**
  * @name proxyModel
  * @function
  * @memberOf QFileDialog.prototype
  * @returns {Object}
  */
QFileDialog.prototype.proxyModel = function(){return new Object();};

/**
  * @name restoreState
  * @function
  * @memberOf QFileDialog.prototype
  * @param {QByteArray} state
  * @returns {Boolean}
  */
QFileDialog.prototype.restoreState = function(state){return new Boolean();};

/**
  * @name saveState
  * @function
  * @memberOf QFileDialog.prototype
  * @returns {QByteArray}
  */
QFileDialog.prototype.saveState = function(){return new QByteArray();};

/**
  * @name selectFile
  * @function
  * @memberOf QFileDialog.prototype
  * @param {String} filename
  * @returns {undefined}
  */
QFileDialog.prototype.selectFile = function(filename){return undefined;};

/**
  * @name selectFilter
  * @function
  * @memberOf QFileDialog.prototype
  * @param {String} filter
  * @returns {undefined}
  */
QFileDialog.prototype.selectFilter = function(filter){return undefined;};

/**
  * @name selectNameFilter
  * @function
  * @memberOf QFileDialog.prototype
  * @param {String} filter
  * @returns {undefined}
  */
QFileDialog.prototype.selectNameFilter = function(filter){return undefined;};

/**
  * @name selectedFiles
  * @function
  * @memberOf QFileDialog.prototype
  * @returns {Array}
  */
QFileDialog.prototype.selectedFiles = function(){return new Array();};

/**
  * @name selectedFilter
  * @function
  * @memberOf QFileDialog.prototype
  * @returns {String}
  */
QFileDialog.prototype.selectedFilter = function(){return new String();};

/**
  * @name selectedNameFilter
  * @function
  * @memberOf QFileDialog.prototype
  * @returns {String}
  */
QFileDialog.prototype.selectedNameFilter = function(){return new String();};

/**
  * @name setDirectory
  * @function
  * @memberOf QFileDialog.prototype
  * @param {QDir} directory
  * @returns {undefined}
  */
QFileDialog.prototype.setDirectory = function(directory){return undefined;};

/**
  * @name setFilter
  * @function
  * @memberOf QFileDialog.prototype
  * @param {QDir.Filters} filters
  * @returns {undefined}
  */
QFileDialog.prototype.setFilter = function(filters){return undefined;};

/**
  * @name setFilters
  * @function
  * @memberOf QFileDialog.prototype
  * @param {Array} filters
  * @returns {undefined}
  */
QFileDialog.prototype.setFilters = function(filters){return undefined;};

/**
  * @name setHistory
  * @function
  * @memberOf QFileDialog.prototype
  * @param {Array} paths
  * @returns {undefined}
  */
QFileDialog.prototype.setHistory = function(paths){return undefined;};

/**
  * @name setIconProvider
  * @function
  * @memberOf QFileDialog.prototype
  * @param {QFileIconProvider} provider
  * @returns {undefined}
  */
QFileDialog.prototype.setIconProvider = function(provider){return undefined;};

/**
  * @name setItemDelegate
  * @function
  * @memberOf QFileDialog.prototype
  * @param {QAbstractItemDelegate} delegate
  * @returns {undefined}
  */
QFileDialog.prototype.setItemDelegate = function(delegate){return undefined;};

/**
  * @name setLabelText
  * @function
  * @memberOf QFileDialog.prototype
  * @param {QFileDialog.DialogLabel} label
  * @param {String} text
  * @returns {undefined}
  */
QFileDialog.prototype.setLabelText = function(label, text){return undefined;};

/**
  * @name setNameFilter
  * @function
  * @memberOf QFileDialog.prototype
  * @param {String} filter
  * @returns {undefined}
  */
QFileDialog.prototype.setNameFilter = function(filter){return undefined;};

/**
  * @name setNameFilterDetailsVisible
  * @function
  * @memberOf QFileDialog.prototype
  * @param {Boolean} enabled
  * @returns {undefined}
  */
QFileDialog.prototype.setNameFilterDetailsVisible = function(enabled){return undefined;};

/**
  * @name setNameFilters
  * @function
  * @memberOf QFileDialog.prototype
  * @param {Array} filters
  * @returns {undefined}
  */
QFileDialog.prototype.setNameFilters = function(filters){return undefined;};

/**
  * @name setOption
  * @function
  * @memberOf QFileDialog.prototype
  * @param {QFileDialog.Option} option
  * @param {Boolean} on
  * @returns {undefined}
  */
QFileDialog.prototype.setOption = function(option, on){return undefined;};

/**
  * @name setProxyModel
  * @function
  * @memberOf QFileDialog.prototype
  * @param {Object} model
  * @returns {undefined}
  */
QFileDialog.prototype.setProxyModel = function(model){return undefined;};

/**
  * @name setSidebarUrls
  * @function
  * @memberOf QFileDialog.prototype
  * @param {Array} urls
  * @returns {undefined}
  */
QFileDialog.prototype.setSidebarUrls = function(urls){return undefined;};

/**
  * @name sidebarUrls
  * @function
  * @memberOf QFileDialog.prototype
  * @returns {Array}
  */
QFileDialog.prototype.sidebarUrls = function(){return new Array();};

/**
  * @name testOption
  * @function
  * @memberOf QFileDialog.prototype
  * @param {QFileDialog.Option} option
  * @returns {Boolean}
  */
QFileDialog.prototype.testOption = function(option){return new Boolean();};

/**
  * @name viewMode
  * @memberOf QFileDialog.prototype
  * @type QListView.ViewMode
  */
QFileDialog.prototype.viewMode = new QListView.ViewMode();

/**
  * @name fileMode
  * @memberOf QFileDialog.prototype
  * @type QFileDialog.FileMode
  */
QFileDialog.prototype.fileMode = new QFileDialog.FileMode();

/**
  * @name acceptMode
  * @memberOf QFileDialog.prototype
  * @type QFileDialog.AcceptMode
  */
QFileDialog.prototype.acceptMode = new QFileDialog.AcceptMode();

/**
  * @name readOnly
  * @memberOf QFileDialog.prototype
  * @type Boolean
  */
QFileDialog.prototype.readOnly = new Boolean();

/**
  * @name resolveSymlinks
  * @memberOf QFileDialog.prototype
  * @type Boolean
  */
QFileDialog.prototype.resolveSymlinks = new Boolean();

/**
  * @name confirmOverwrite
  * @memberOf QFileDialog.prototype
  * @type Boolean
  */
QFileDialog.prototype.confirmOverwrite = new Boolean();

/**
  * @name defaultSuffix
  * @memberOf QFileDialog.prototype
  * @type String
  */
QFileDialog.prototype.defaultSuffix = new String();

/**
  * @name nameFilterDetailsVisible
  * @memberOf QFileDialog.prototype
  * @type Boolean
  */
QFileDialog.prototype.nameFilterDetailsVisible = new Boolean();

/**
  * @name options
  * @memberOf QFileDialog.prototype
  * @type QFileDialog.Options
  */
QFileDialog.prototype.options = new QFileDialog.Options();


