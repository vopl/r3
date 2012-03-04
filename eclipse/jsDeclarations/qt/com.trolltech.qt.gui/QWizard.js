/**
  * @name QWizard
  * @constructor
  * @extends QDialog
  * @param {QWidget} parent
  * @param {Qt.WindowFlags} flags
  */
function QWizard(parent, flags){return undefined;};

QWizard.prototype = new QDialog();

/**
  * @default -1
  * @constant
  * @memberOf QWizard
  * @name NoButton
  * @see QWizard#WizardButton
  * @type Number
  */
QWizard.NoButton = 0xffffffff;

/**
  * @default 0x0
  * @constant
  * @memberOf QWizard
  * @name BackButton
  * @see QWizard#WizardButton
  * @type Number
  */
QWizard.BackButton = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QWizard
  * @name NextButton
  * @see QWizard#WizardButton
  * @type Number
  */
QWizard.NextButton = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QWizard
  * @name CommitButton
  * @see QWizard#WizardButton
  * @type Number
  */
QWizard.CommitButton = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QWizard
  * @name FinishButton
  * @see QWizard#WizardButton
  * @type Number
  */
QWizard.FinishButton = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QWizard
  * @name CancelButton
  * @see QWizard#WizardButton
  * @type Number
  */
QWizard.CancelButton = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QWizard
  * @name HelpButton
  * @see QWizard#WizardButton
  * @type Number
  */
QWizard.HelpButton = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf QWizard
  * @name CustomButton1
  * @see QWizard#WizardButton
  * @type Number
  */
QWizard.CustomButton1 = 0x6;

/**
  * @default 0x7
  * @constant
  * @memberOf QWizard
  * @name CustomButton2
  * @see QWizard#WizardButton
  * @type Number
  */
QWizard.CustomButton2 = 0x7;

/**
  * @default 0x8
  * @constant
  * @memberOf QWizard
  * @name CustomButton3
  * @see QWizard#WizardButton
  * @type Number
  */
QWizard.CustomButton3 = 0x8;

/**
  * @default 0x9
  * @constant
  * @memberOf QWizard
  * @name Stretch
  * @see QWizard#WizardButton
  * @type Number
  */
QWizard.Stretch = 0x9;

/**
  * @constructor 
  * @memberOf QWizard
  * @name WizardButton
  */
QWizard.WizardButton = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QWizard
  * @name ClassicStyle
  * @see QWizard#WizardStyle
  * @type Number
  */
QWizard.ClassicStyle = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QWizard
  * @name ModernStyle
  * @see QWizard#WizardStyle
  * @type Number
  */
QWizard.ModernStyle = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QWizard
  * @name MacStyle
  * @see QWizard#WizardStyle
  * @type Number
  */
QWizard.MacStyle = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QWizard
  * @name AeroStyle
  * @see QWizard#WizardStyle
  * @type Number
  */
QWizard.AeroStyle = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QWizard
  * @name NStyles
  * @see QWizard#WizardStyle
  * @type Number
  */
QWizard.NStyles = 0x4;

/**
  * @constructor 
  * @memberOf QWizard
  * @name WizardStyle
  */
QWizard.WizardStyle = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QWizard
  * @name WatermarkPixmap
  * @see QWizard#WizardPixmap
  * @type Number
  */
QWizard.WatermarkPixmap = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QWizard
  * @name LogoPixmap
  * @see QWizard#WizardPixmap
  * @type Number
  */
QWizard.LogoPixmap = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QWizard
  * @name BannerPixmap
  * @see QWizard#WizardPixmap
  * @type Number
  */
QWizard.BannerPixmap = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QWizard
  * @name BackgroundPixmap
  * @see QWizard#WizardPixmap
  * @type Number
  */
QWizard.BackgroundPixmap = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QWizard
  * @name NPixmaps
  * @see QWizard#WizardPixmap
  * @type Number
  */
QWizard.NPixmaps = 0x4;

/**
  * @constructor 
  * @memberOf QWizard
  * @name WizardPixmap
  */
QWizard.WizardPixmap = function(value){;};



/**
  * @default 0x00000001
  * @constant
  * @memberOf QWizard
  * @name IndependentPages
  * @see QWizard#WizardOptions
  * @see QWizard#WizardOption
  * @type Number
  */
QWizard.IndependentPages = 0x1;

/**
  * @default 0x00000002
  * @constant
  * @memberOf QWizard
  * @name IgnoreSubTitles
  * @see QWizard#WizardOptions
  * @see QWizard#WizardOption
  * @type Number
  */
QWizard.IgnoreSubTitles = 0x2;

/**
  * @default 0x00000004
  * @constant
  * @memberOf QWizard
  * @name ExtendedWatermarkPixmap
  * @see QWizard#WizardOptions
  * @see QWizard#WizardOption
  * @type Number
  */
QWizard.ExtendedWatermarkPixmap = 0x4;

/**
  * @default 0x00000008
  * @constant
  * @memberOf QWizard
  * @name NoDefaultButton
  * @see QWizard#WizardOptions
  * @see QWizard#WizardOption
  * @type Number
  */
QWizard.NoDefaultButton = 0x8;

/**
  * @default 0x00000010
  * @constant
  * @memberOf QWizard
  * @name NoBackButtonOnStartPage
  * @see QWizard#WizardOptions
  * @see QWizard#WizardOption
  * @type Number
  */
QWizard.NoBackButtonOnStartPage = 0x10;

/**
  * @default 0x00000020
  * @constant
  * @memberOf QWizard
  * @name NoBackButtonOnLastPage
  * @see QWizard#WizardOptions
  * @see QWizard#WizardOption
  * @type Number
  */
QWizard.NoBackButtonOnLastPage = 0x20;

/**
  * @default 0x00000040
  * @constant
  * @memberOf QWizard
  * @name DisabledBackButtonOnLastPage
  * @see QWizard#WizardOptions
  * @see QWizard#WizardOption
  * @type Number
  */
QWizard.DisabledBackButtonOnLastPage = 0x40;

/**
  * @default 0x00000080
  * @constant
  * @memberOf QWizard
  * @name HaveNextButtonOnLastPage
  * @see QWizard#WizardOptions
  * @see QWizard#WizardOption
  * @type Number
  */
QWizard.HaveNextButtonOnLastPage = 0x80;

/**
  * @default 0x00000100
  * @constant
  * @memberOf QWizard
  * @name HaveFinishButtonOnEarlyPages
  * @see QWizard#WizardOptions
  * @see QWizard#WizardOption
  * @type Number
  */
QWizard.HaveFinishButtonOnEarlyPages = 0x100;

/**
  * @default 0x00000200
  * @constant
  * @memberOf QWizard
  * @name NoCancelButton
  * @see QWizard#WizardOptions
  * @see QWizard#WizardOption
  * @type Number
  */
QWizard.NoCancelButton = 0x200;

/**
  * @default 0x00000400
  * @constant
  * @memberOf QWizard
  * @name CancelButtonOnLeft
  * @see QWizard#WizardOptions
  * @see QWizard#WizardOption
  * @type Number
  */
QWizard.CancelButtonOnLeft = 0x400;

/**
  * @default 0x00000800
  * @constant
  * @memberOf QWizard
  * @name HaveHelpButton
  * @see QWizard#WizardOptions
  * @see QWizard#WizardOption
  * @type Number
  */
QWizard.HaveHelpButton = 0x800;

/**
  * @default 0x00001000
  * @constant
  * @memberOf QWizard
  * @name HelpButtonOnRight
  * @see QWizard#WizardOptions
  * @see QWizard#WizardOption
  * @type Number
  */
QWizard.HelpButtonOnRight = 0x1000;

/**
  * @default 0x00002000
  * @constant
  * @memberOf QWizard
  * @name HaveCustomButton1
  * @see QWizard#WizardOptions
  * @see QWizard#WizardOption
  * @type Number
  */
QWizard.HaveCustomButton1 = 0x2000;

/**
  * @default 0x00004000
  * @constant
  * @memberOf QWizard
  * @name HaveCustomButton2
  * @see QWizard#WizardOptions
  * @see QWizard#WizardOption
  * @type Number
  */
QWizard.HaveCustomButton2 = 0x4000;

/**
  * @default 0x00008000
  * @constant
  * @memberOf QWizard
  * @name HaveCustomButton3
  * @see QWizard#WizardOptions
  * @see QWizard#WizardOption
  * @type Number
  */
QWizard.HaveCustomButton3 = 0x8000;

/**
  * @constructor 
  * @memberOf QWizard
  * @name WizardOption
  */
QWizard.WizardOption = function(value){;};

/**
  * @constructor 
  * @memberOf QWizard
  * @name WizardOptions
  */
QWizard.WizardOptions = function(value1, value2 /*, ...*/){;};


/**
  * @name addPage
  * @function
  * @memberOf QWizard.prototype
  * @param {QWizardPage} page
  * @returns {Numeric}
  */
QWizard.prototype.addPage = function(page){return new Numeric();};

/**
  * @name button
  * @function
  * @memberOf QWizard.prototype
  * @param {QWizard.WizardButton} which
  * @returns {QAbstractButton}
  */
QWizard.prototype.button = function(which){return new QAbstractButton();};

/**
  * @name buttonText
  * @function
  * @memberOf QWizard.prototype
  * @param {QWizard.WizardButton} which
  * @returns {String}
  */
QWizard.prototype.buttonText = function(which){return new String();};

/**
  * @name currentPage
  * @function
  * @memberOf QWizard.prototype
  * @returns {QWizardPage}
  */
QWizard.prototype.currentPage = function(){return new QWizardPage();};

/**
  * @name field
  * @function
  * @memberOf QWizard.prototype
  * @param {String} name
  * @returns {Object}
  */
QWizard.prototype.field = function(name){return new Object();};

/**
  * @name hasVisitedPage
  * @function
  * @memberOf QWizard.prototype
  * @param {Numeric} id
  * @returns {Boolean}
  */
QWizard.prototype.hasVisitedPage = function(id){return new Boolean();};

/**
  * @name nextId
  * @function
  * @memberOf QWizard.prototype
  * @returns {Numeric}
  */
QWizard.prototype.nextId = function(){return new Numeric();};

/**
  * @name page
  * @function
  * @memberOf QWizard.prototype
  * @param {Numeric} id
  * @returns {QWizardPage}
  */
QWizard.prototype.page = function(id){return new QWizardPage();};

/**
  * @name pageIds
  * @function
  * @memberOf QWizard.prototype
  * @returns {Array}
  */
QWizard.prototype.pageIds = function(){return new Array();};

/**
  * @name pixmap
  * @function
  * @memberOf QWizard.prototype
  * @param {QWizard.WizardPixmap} which
  * @returns {QPixmap}
  */
QWizard.prototype.pixmap = function(which){return new QPixmap();};

/**
  * @name removePage
  * @function
  * @memberOf QWizard.prototype
  * @param {Numeric} id
  * @returns {undefined}
  */
QWizard.prototype.removePage = function(id){return undefined;};

/**
  * @name setButton
  * @function
  * @memberOf QWizard.prototype
  * @param {QWizard.WizardButton} which
  * @param {QAbstractButton} button
  * @returns {undefined}
  */
QWizard.prototype.setButton = function(which, button){return undefined;};

/**
  * @name setButtonLayout
  * @function
  * @memberOf QWizard.prototype
  * @param {Array} layout
  * @returns {undefined}
  */
QWizard.prototype.setButtonLayout = function(layout){return undefined;};

/**
  * @name setButtonText
  * @function
  * @memberOf QWizard.prototype
  * @param {QWizard.WizardButton} which
  * @param {String} text
  * @returns {undefined}
  */
QWizard.prototype.setButtonText = function(which, text){return undefined;};

/**
  * @name setField
  * @function
  * @memberOf QWizard.prototype
  * @param {String} name
  * @param {Object} value
  * @returns {undefined}
  */
QWizard.prototype.setField = function(name, value){return undefined;};

/**
  * @name setOption
  * @function
  * @memberOf QWizard.prototype
  * @param {QWizard.WizardOption} option
  * @param {Boolean} on
  * @returns {undefined}
  */
QWizard.prototype.setOption = function(option, on){return undefined;};

/**
  * @name setPage
  * @function
  * @memberOf QWizard.prototype
  * @param {Numeric} id
  * @param {QWizardPage} page
  * @returns {undefined}
  */
QWizard.prototype.setPage = function(id, page){return undefined;};

/**
  * @name setPixmap
  * @function
  * @memberOf QWizard.prototype
  * @param {QWizard.WizardPixmap} which
  * @param {QPixmap} pixmap
  * @returns {undefined}
  */
QWizard.prototype.setPixmap = function(which, pixmap){return undefined;};

/**
  * @name setSideWidget
  * @function
  * @memberOf QWizard.prototype
  * @param {QWidget} widget
  * @returns {undefined}
  */
QWizard.prototype.setSideWidget = function(widget){return undefined;};

/**
  * @name sideWidget
  * @function
  * @memberOf QWizard.prototype
  * @returns {QWidget}
  */
QWizard.prototype.sideWidget = function(){return new QWidget();};

/**
  * @name testOption
  * @function
  * @memberOf QWizard.prototype
  * @param {QWizard.WizardOption} option
  * @returns {Boolean}
  */
QWizard.prototype.testOption = function(option){return new Boolean();};

/**
  * @name validateCurrentPage
  * @function
  * @memberOf QWizard.prototype
  * @returns {Boolean}
  */
QWizard.prototype.validateCurrentPage = function(){return new Boolean();};

/**
  * @name visitedPages
  * @function
  * @memberOf QWizard.prototype
  * @returns {Array}
  */
QWizard.prototype.visitedPages = function(){return new Array();};

/**
  * @name wizardStyle
  * @memberOf QWizard.prototype
  * @type QWizard.WizardStyle
  */
QWizard.prototype.wizardStyle = new QWizard.WizardStyle();

/**
  * @name options
  * @memberOf QWizard.prototype
  * @type QWizard.WizardOptions
  */
QWizard.prototype.options = new QWizard.WizardOptions();

/**
  * @name titleFormat
  * @memberOf QWizard.prototype
  * @type Qt.TextFormat
  */
QWizard.prototype.titleFormat = new Qt.TextFormat();

/**
  * @name subTitleFormat
  * @memberOf QWizard.prototype
  * @type Qt.TextFormat
  */
QWizard.prototype.subTitleFormat = new Qt.TextFormat();

/**
  * @name startId
  * @memberOf QWizard.prototype
  * @type Numeric
  */
QWizard.prototype.startId = new Numeric();

/**
  * @name currentId
  * @memberOf QWizard.prototype
  * @type Numeric
  */
QWizard.prototype.currentId = new Numeric();


