/**
  * @name QWebPage
  * @constructor
  * @extends QObject
  * @param {QObject} parent
  */
function QWebPage(parent){return undefined;};

QWebPage.prototype = new QObject();

/**
  * @default 0x0
  * @constant
  * @memberOf QWebPage
  * @name QtNetwork
  * @see QWebPage#ErrorDomain
  * @type Number
  */
QWebPage.QtNetwork = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QWebPage
  * @name Http
  * @see QWebPage#ErrorDomain
  * @type Number
  */
QWebPage.Http = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QWebPage
  * @name WebKit
  * @see QWebPage#ErrorDomain
  * @type Number
  */
QWebPage.WebKit = 0x2;

/**
  * @constructor 
  * @memberOf QWebPage
  * @name ErrorDomain
  */
QWebPage.ErrorDomain = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QWebPage
  * @name NavigationTypeLinkClicked
  * @see QWebPage#NavigationType
  * @type Number
  */
QWebPage.NavigationTypeLinkClicked = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QWebPage
  * @name NavigationTypeFormSubmitted
  * @see QWebPage#NavigationType
  * @type Number
  */
QWebPage.NavigationTypeFormSubmitted = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QWebPage
  * @name NavigationTypeBackOrForward
  * @see QWebPage#NavigationType
  * @type Number
  */
QWebPage.NavigationTypeBackOrForward = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QWebPage
  * @name NavigationTypeReload
  * @see QWebPage#NavigationType
  * @type Number
  */
QWebPage.NavigationTypeReload = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QWebPage
  * @name NavigationTypeFormResubmitted
  * @see QWebPage#NavigationType
  * @type Number
  */
QWebPage.NavigationTypeFormResubmitted = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QWebPage
  * @name NavigationTypeOther
  * @see QWebPage#NavigationType
  * @type Number
  */
QWebPage.NavigationTypeOther = 0x5;

/**
  * @constructor 
  * @memberOf QWebPage
  * @name NavigationType
  */
QWebPage.NavigationType = function(value){;};



/**
  * @default -1
  * @constant
  * @memberOf QWebPage
  * @name NoWebAction
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.NoWebAction = 0xffffffff;

/**
  * @default 0x0
  * @constant
  * @memberOf QWebPage
  * @name OpenLink
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.OpenLink = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QWebPage
  * @name OpenLinkInNewWindow
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.OpenLinkInNewWindow = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QWebPage
  * @name OpenFrameInNewWindow
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.OpenFrameInNewWindow = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QWebPage
  * @name DownloadLinkToDisk
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.DownloadLinkToDisk = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QWebPage
  * @name CopyLinkToClipboard
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.CopyLinkToClipboard = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QWebPage
  * @name OpenImageInNewWindow
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.OpenImageInNewWindow = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf QWebPage
  * @name DownloadImageToDisk
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.DownloadImageToDisk = 0x6;

/**
  * @default 0x7
  * @constant
  * @memberOf QWebPage
  * @name CopyImageToClipboard
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.CopyImageToClipboard = 0x7;

/**
  * @default 0x8
  * @constant
  * @memberOf QWebPage
  * @name Back
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.Back = 0x8;

/**
  * @default 0x9
  * @constant
  * @memberOf QWebPage
  * @name Forward
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.Forward = 0x9;

/**
  * @default 0xa
  * @constant
  * @memberOf QWebPage
  * @name Stop
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.Stop = 0xa;

/**
  * @default 0xb
  * @constant
  * @memberOf QWebPage
  * @name Reload
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.Reload = 0xb;

/**
  * @default 0xc
  * @constant
  * @memberOf QWebPage
  * @name Cut
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.Cut = 0xc;

/**
  * @default 0xd
  * @constant
  * @memberOf QWebPage
  * @name Copy
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.Copy = 0xd;

/**
  * @default 0xe
  * @constant
  * @memberOf QWebPage
  * @name Paste
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.Paste = 0xe;

/**
  * @default 0xf
  * @constant
  * @memberOf QWebPage
  * @name Undo
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.Undo = 0xf;

/**
  * @default 0x10
  * @constant
  * @memberOf QWebPage
  * @name Redo
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.Redo = 0x10;

/**
  * @default 0x11
  * @constant
  * @memberOf QWebPage
  * @name MoveToNextChar
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.MoveToNextChar = 0x11;

/**
  * @default 0x12
  * @constant
  * @memberOf QWebPage
  * @name MoveToPreviousChar
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.MoveToPreviousChar = 0x12;

/**
  * @default 0x13
  * @constant
  * @memberOf QWebPage
  * @name MoveToNextWord
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.MoveToNextWord = 0x13;

/**
  * @default 0x14
  * @constant
  * @memberOf QWebPage
  * @name MoveToPreviousWord
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.MoveToPreviousWord = 0x14;

/**
  * @default 0x15
  * @constant
  * @memberOf QWebPage
  * @name MoveToNextLine
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.MoveToNextLine = 0x15;

/**
  * @default 0x16
  * @constant
  * @memberOf QWebPage
  * @name MoveToPreviousLine
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.MoveToPreviousLine = 0x16;

/**
  * @default 0x17
  * @constant
  * @memberOf QWebPage
  * @name MoveToStartOfLine
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.MoveToStartOfLine = 0x17;

/**
  * @default 0x18
  * @constant
  * @memberOf QWebPage
  * @name MoveToEndOfLine
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.MoveToEndOfLine = 0x18;

/**
  * @default 0x19
  * @constant
  * @memberOf QWebPage
  * @name MoveToStartOfBlock
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.MoveToStartOfBlock = 0x19;

/**
  * @default 0x1a
  * @constant
  * @memberOf QWebPage
  * @name MoveToEndOfBlock
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.MoveToEndOfBlock = 0x1a;

/**
  * @default 0x1b
  * @constant
  * @memberOf QWebPage
  * @name MoveToStartOfDocument
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.MoveToStartOfDocument = 0x1b;

/**
  * @default 0x1c
  * @constant
  * @memberOf QWebPage
  * @name MoveToEndOfDocument
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.MoveToEndOfDocument = 0x1c;

/**
  * @default 0x1d
  * @constant
  * @memberOf QWebPage
  * @name SelectNextChar
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.SelectNextChar = 0x1d;

/**
  * @default 0x1e
  * @constant
  * @memberOf QWebPage
  * @name SelectPreviousChar
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.SelectPreviousChar = 0x1e;

/**
  * @default 0x1f
  * @constant
  * @memberOf QWebPage
  * @name SelectNextWord
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.SelectNextWord = 0x1f;

/**
  * @default 0x20
  * @constant
  * @memberOf QWebPage
  * @name SelectPreviousWord
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.SelectPreviousWord = 0x20;

/**
  * @default 0x21
  * @constant
  * @memberOf QWebPage
  * @name SelectNextLine
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.SelectNextLine = 0x21;

/**
  * @default 0x22
  * @constant
  * @memberOf QWebPage
  * @name SelectPreviousLine
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.SelectPreviousLine = 0x22;

/**
  * @default 0x23
  * @constant
  * @memberOf QWebPage
  * @name SelectStartOfLine
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.SelectStartOfLine = 0x23;

/**
  * @default 0x24
  * @constant
  * @memberOf QWebPage
  * @name SelectEndOfLine
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.SelectEndOfLine = 0x24;

/**
  * @default 0x25
  * @constant
  * @memberOf QWebPage
  * @name SelectStartOfBlock
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.SelectStartOfBlock = 0x25;

/**
  * @default 0x26
  * @constant
  * @memberOf QWebPage
  * @name SelectEndOfBlock
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.SelectEndOfBlock = 0x26;

/**
  * @default 0x27
  * @constant
  * @memberOf QWebPage
  * @name SelectStartOfDocument
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.SelectStartOfDocument = 0x27;

/**
  * @default 0x28
  * @constant
  * @memberOf QWebPage
  * @name SelectEndOfDocument
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.SelectEndOfDocument = 0x28;

/**
  * @default 0x29
  * @constant
  * @memberOf QWebPage
  * @name DeleteStartOfWord
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.DeleteStartOfWord = 0x29;

/**
  * @default 0x2a
  * @constant
  * @memberOf QWebPage
  * @name DeleteEndOfWord
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.DeleteEndOfWord = 0x2a;

/**
  * @default 0x2b
  * @constant
  * @memberOf QWebPage
  * @name SetTextDirectionDefault
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.SetTextDirectionDefault = 0x2b;

/**
  * @default 0x2c
  * @constant
  * @memberOf QWebPage
  * @name SetTextDirectionLeftToRight
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.SetTextDirectionLeftToRight = 0x2c;

/**
  * @default 0x2d
  * @constant
  * @memberOf QWebPage
  * @name SetTextDirectionRightToLeft
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.SetTextDirectionRightToLeft = 0x2d;

/**
  * @default 0x2e
  * @constant
  * @memberOf QWebPage
  * @name ToggleBold
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.ToggleBold = 0x2e;

/**
  * @default 0x2f
  * @constant
  * @memberOf QWebPage
  * @name ToggleItalic
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.ToggleItalic = 0x2f;

/**
  * @default 0x30
  * @constant
  * @memberOf QWebPage
  * @name ToggleUnderline
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.ToggleUnderline = 0x30;

/**
  * @default 0x31
  * @constant
  * @memberOf QWebPage
  * @name InspectElement
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.InspectElement = 0x31;

/**
  * @default 0x32
  * @constant
  * @memberOf QWebPage
  * @name InsertParagraphSeparator
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.InsertParagraphSeparator = 0x32;

/**
  * @default 0x33
  * @constant
  * @memberOf QWebPage
  * @name InsertLineSeparator
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.InsertLineSeparator = 0x33;

/**
  * @default 0x34
  * @constant
  * @memberOf QWebPage
  * @name SelectAll
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.SelectAll = 0x34;

/**
  * @default 0x35
  * @constant
  * @memberOf QWebPage
  * @name ReloadAndBypassCache
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.ReloadAndBypassCache = 0x35;

/**
  * @default 0x36
  * @constant
  * @memberOf QWebPage
  * @name PasteAndMatchStyle
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.PasteAndMatchStyle = 0x36;

/**
  * @default 0x37
  * @constant
  * @memberOf QWebPage
  * @name RemoveFormat
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.RemoveFormat = 0x37;

/**
  * @default 0x38
  * @constant
  * @memberOf QWebPage
  * @name ToggleStrikethrough
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.ToggleStrikethrough = 0x38;

/**
  * @default 0x39
  * @constant
  * @memberOf QWebPage
  * @name ToggleSubscript
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.ToggleSubscript = 0x39;

/**
  * @default 0x3a
  * @constant
  * @memberOf QWebPage
  * @name ToggleSuperscript
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.ToggleSuperscript = 0x3a;

/**
  * @default 0x3b
  * @constant
  * @memberOf QWebPage
  * @name InsertUnorderedList
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.InsertUnorderedList = 0x3b;

/**
  * @default 0x3c
  * @constant
  * @memberOf QWebPage
  * @name InsertOrderedList
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.InsertOrderedList = 0x3c;

/**
  * @default 0x3d
  * @constant
  * @memberOf QWebPage
  * @name Indent
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.Indent = 0x3d;

/**
  * @default 0x3e
  * @constant
  * @memberOf QWebPage
  * @name Outdent
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.Outdent = 0x3e;

/**
  * @default 0x3f
  * @constant
  * @memberOf QWebPage
  * @name AlignCenter
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.AlignCenter = 0x3f;

/**
  * @default 0x40
  * @constant
  * @memberOf QWebPage
  * @name AlignJustified
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.AlignJustified = 0x40;

/**
  * @default 0x41
  * @constant
  * @memberOf QWebPage
  * @name AlignLeft
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.AlignLeft = 0x41;

/**
  * @default 0x42
  * @constant
  * @memberOf QWebPage
  * @name AlignRight
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.AlignRight = 0x42;

/**
  * @default 0x43
  * @constant
  * @memberOf QWebPage
  * @name StopScheduledPageRefresh
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.StopScheduledPageRefresh = 0x43;

/**
  * @default 0x44
  * @constant
  * @memberOf QWebPage
  * @name CopyImageUrlToClipboard
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.CopyImageUrlToClipboard = 0x44;

/**
  * @default 0x45
  * @constant
  * @memberOf QWebPage
  * @name WebActionCount
  * @see QWebPage#WebAction
  * @type Number
  */
QWebPage.WebActionCount = 0x45;

/**
  * @constructor 
  * @memberOf QWebPage
  * @name WebAction
  */
QWebPage.WebAction = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QWebPage
  * @name WebBrowserWindow
  * @see QWebPage#WebWindowType
  * @type Number
  */
QWebPage.WebBrowserWindow = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QWebPage
  * @name WebModalDialog
  * @see QWebPage#WebWindowType
  * @type Number
  */
QWebPage.WebModalDialog = 0x1;

/**
  * @constructor 
  * @memberOf QWebPage
  * @name WebWindowType
  */
QWebPage.WebWindowType = function(value){;};



/**
  * @default 1
  * @constant
  * @memberOf QWebPage
  * @name FindBackward
  * @see QWebPage#FindFlags
  * @see QWebPage#FindFlag
  * @type Number
  */
QWebPage.FindBackward = 0x1;

/**
  * @default 2
  * @constant
  * @memberOf QWebPage
  * @name FindCaseSensitively
  * @see QWebPage#FindFlags
  * @see QWebPage#FindFlag
  * @type Number
  */
QWebPage.FindCaseSensitively = 0x2;

/**
  * @default 4
  * @constant
  * @memberOf QWebPage
  * @name FindWrapsAroundDocument
  * @see QWebPage#FindFlags
  * @see QWebPage#FindFlag
  * @type Number
  */
QWebPage.FindWrapsAroundDocument = 0x4;

/**
  * @default 8
  * @constant
  * @memberOf QWebPage
  * @name HighlightAllOccurrences
  * @see QWebPage#FindFlags
  * @see QWebPage#FindFlag
  * @type Number
  */
QWebPage.HighlightAllOccurrences = 0x8;

/**
  * @constructor 
  * @memberOf QWebPage
  * @name FindFlag
  */
QWebPage.FindFlag = function(value){;};

/**
  * @constructor 
  * @memberOf QWebPage
  * @name FindFlags
  */
QWebPage.FindFlags = function(value1, value2 /*, ...*/){;};


/**
  * @default 0x0
  * @constant
  * @memberOf QWebPage
  * @name ChooseMultipleFilesExtension
  * @see QWebPage#Extension
  * @type Number
  */
QWebPage.ChooseMultipleFilesExtension = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QWebPage
  * @name ErrorPageExtension
  * @see QWebPage#Extension
  * @type Number
  */
QWebPage.ErrorPageExtension = 0x1;

/**
  * @constructor 
  * @memberOf QWebPage
  * @name Extension
  */
QWebPage.Extension = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QWebPage
  * @name DontDelegateLinks
  * @see QWebPage#LinkDelegationPolicy
  * @type Number
  */
QWebPage.DontDelegateLinks = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QWebPage
  * @name DelegateExternalLinks
  * @see QWebPage#LinkDelegationPolicy
  * @type Number
  */
QWebPage.DelegateExternalLinks = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QWebPage
  * @name DelegateAllLinks
  * @see QWebPage#LinkDelegationPolicy
  * @type Number
  */
QWebPage.DelegateAllLinks = 0x2;

/**
  * @constructor 
  * @memberOf QWebPage
  * @name LinkDelegationPolicy
  */
QWebPage.LinkDelegationPolicy = function(value){;};



/**
  * @name action
  * @function
  * @memberOf QWebPage.prototype
  * @param {QWebPage.WebAction} action
  * @returns {QAction}
  */
QWebPage.prototype.action = function(action){return new QAction();};

/**
  * @name bytesReceived
  * @function
  * @memberOf QWebPage.prototype
  * @returns {Numeric}
  */
QWebPage.prototype.bytesReceived = function(){return new Numeric();};

/**
  * @name createStandardContextMenu
  * @function
  * @memberOf QWebPage.prototype
  * @returns {QMenu}
  */
QWebPage.prototype.createStandardContextMenu = function(){return new QMenu();};

/**
  * @name currentFrame
  * @function
  * @memberOf QWebPage.prototype
  * @returns {QWebFrame}
  */
QWebPage.prototype.currentFrame = function(){return new QWebFrame();};

/**
  * @name extension
  * @function
  * @memberOf QWebPage.prototype
  * @param {QWebPluginFactory.Extension} extension
  * @param {QWebPage_ExtensionOption} option
  * @param {QWebPage_ExtensionReturn} output
  * @returns {Boolean}
  */
QWebPage.prototype.extension = function(extension, option, output){return new Boolean();};

/**
  * @name findText
  * @function
  * @memberOf QWebPage.prototype
  * @param {String} subString
  * @param {QWebPage.FindFlags} options
  * @returns {Boolean}
  */
QWebPage.prototype.findText = function(subString, options){return new Boolean();};

/**
  * @name focusNextPrevChild
  * @function
  * @memberOf QWebPage.prototype
  * @param {Boolean} next
  * @returns {Boolean}
  */
QWebPage.prototype.focusNextPrevChild = function(next){return new Boolean();};

/**
  * @name frameAt
  * @function
  * @memberOf QWebPage.prototype
  * @param {QPoint} pos
  * @returns {QWebFrame}
  */
QWebPage.prototype.frameAt = function(pos){return new QWebFrame();};

/**
  * @name history
  * @function
  * @memberOf QWebPage.prototype
  * @returns {Object}
  */
QWebPage.prototype.history = function(){return new Object();};

/**
  * @name inputMethodQuery
  * @function
  * @memberOf QWebPage.prototype
  * @param {Qt.InputMethodQuery} property
  * @returns {Object}
  */
QWebPage.prototype.inputMethodQuery = function(property){return new Object();};

/**
  * @name mainFrame
  * @function
  * @memberOf QWebPage.prototype
  * @returns {QWebFrame}
  */
QWebPage.prototype.mainFrame = function(){return new QWebFrame();};

/**
  * @name networkAccessManager
  * @function
  * @memberOf QWebPage.prototype
  * @returns {QNetworkAccessManager}
  */
QWebPage.prototype.networkAccessManager = function(){return new QNetworkAccessManager();};

/**
  * @name pluginFactory
  * @function
  * @memberOf QWebPage.prototype
  * @returns {QWebPluginFactory}
  */
QWebPage.prototype.pluginFactory = function(){return new QWebPluginFactory();};

/**
  * @name setActualVisibleContentRect
  * @function
  * @memberOf QWebPage.prototype
  * @param {QRect} rect
  * @returns {undefined}
  */
QWebPage.prototype.setActualVisibleContentRect = function(rect){return undefined;};

/**
  * @name setNetworkAccessManager
  * @function
  * @memberOf QWebPage.prototype
  * @param {QNetworkAccessManager} manager
  * @returns {undefined}
  */
QWebPage.prototype.setNetworkAccessManager = function(manager){return undefined;};

/**
  * @name setPluginFactory
  * @function
  * @memberOf QWebPage.prototype
  * @param {QWebPluginFactory} factory
  * @returns {undefined}
  */
QWebPage.prototype.setPluginFactory = function(factory){return undefined;};

/**
  * @name setView
  * @function
  * @memberOf QWebPage.prototype
  * @param {QWidget} view
  * @returns {undefined}
  */
QWebPage.prototype.setView = function(view){return undefined;};

/**
  * @name settings
  * @function
  * @memberOf QWebPage.prototype
  * @returns {QWebSettings}
  */
QWebPage.prototype.settings = function(){return new QWebSettings();};

/**
  * @name supportedContentTypes
  * @function
  * @memberOf QWebPage.prototype
  * @returns {Array}
  */
QWebPage.prototype.supportedContentTypes = function(){return new Array();};

/**
  * @name supportsContentType
  * @function
  * @memberOf QWebPage.prototype
  * @param {String} mimeType
  * @returns {Boolean}
  */
QWebPage.prototype.supportsContentType = function(mimeType){return new Boolean();};

/**
  * @name supportsExtension
  * @function
  * @memberOf QWebPage.prototype
  * @param {QWebPluginFactory.Extension} extension
  * @returns {Boolean}
  */
QWebPage.prototype.supportsExtension = function(extension){return new Boolean();};

/**
  * @name swallowContextMenuEvent
  * @function
  * @memberOf QWebPage.prototype
  * @param {QContextMenuEvent} event
  * @returns {Boolean}
  */
QWebPage.prototype.swallowContextMenuEvent = function(event){return new Boolean();};

/**
  * @name totalBytes
  * @function
  * @memberOf QWebPage.prototype
  * @returns {Numeric}
  */
QWebPage.prototype.totalBytes = function(){return new Numeric();};

/**
  * @name triggerAction
  * @function
  * @memberOf QWebPage.prototype
  * @param {QWebPage.WebAction} action
  * @param {Boolean} checked
  * @returns {undefined}
  */
QWebPage.prototype.triggerAction = function(action, checked){return undefined;};

/**
  * @name undoStack
  * @function
  * @memberOf QWebPage.prototype
  * @returns {QUndoStack}
  */
QWebPage.prototype.undoStack = function(){return new QUndoStack();};

/**
  * @name updatePositionDependentActions
  * @function
  * @memberOf QWebPage.prototype
  * @param {QPoint} pos
  * @returns {undefined}
  */
QWebPage.prototype.updatePositionDependentActions = function(pos){return undefined;};

/**
  * @name view
  * @function
  * @memberOf QWebPage.prototype
  * @returns {QWidget}
  */
QWebPage.prototype.view = function(){return new QWidget();};

/**
  * @name modified
  * @memberOf QWebPage.prototype
  * @type Boolean
  */
QWebPage.prototype.modified = new Boolean();

/**
  * @name selectedText
  * @memberOf QWebPage.prototype
  * @type String
  */
QWebPage.prototype.selectedText = new String();

/**
  * @name selectedHtml
  * @memberOf QWebPage.prototype
  * @type String
  */
QWebPage.prototype.selectedHtml = new String();

/**
  * @name hasSelection
  * @memberOf QWebPage.prototype
  * @type Boolean
  */
QWebPage.prototype.hasSelection = new Boolean();

/**
  * @name viewportSize
  * @memberOf QWebPage.prototype
  * @type QSize
  */
QWebPage.prototype.viewportSize = new QSize();

/**
  * @name preferredContentsSize
  * @memberOf QWebPage.prototype
  * @type QSize
  */
QWebPage.prototype.preferredContentsSize = new QSize();

/**
  * @name forwardUnsupportedContent
  * @memberOf QWebPage.prototype
  * @type Boolean
  */
QWebPage.prototype.forwardUnsupportedContent = new Boolean();

/**
  * @name linkDelegationPolicy
  * @memberOf QWebPage.prototype
  * @type QWebPage.LinkDelegationPolicy
  */
QWebPage.prototype.linkDelegationPolicy = new QWebPage.LinkDelegationPolicy();

/**
  * @name palette
  * @memberOf QWebPage.prototype
  * @type QPalette
  */
QWebPage.prototype.palette = new QPalette();

/**
  * @name contentEditable
  * @memberOf QWebPage.prototype
  * @type Boolean
  */
QWebPage.prototype.contentEditable = new Boolean();


