/**
  * @class QApplication from package com.trolltech.qt.gui
  * @extends QCoreApplication
  */
var QApplication = {};

QApplication.prototype = new QCoreApplication();

/**
  * @name activeModalWidget
  * @function
  * @memberOf QApplication
  * @returns {QWidget}
  */
QApplication.activeModalWidget = function(){return new QWidget();};

/**
  * @name activePopupWidget
  * @function
  * @memberOf QApplication
  * @returns {QWidget}
  */
QApplication.activePopupWidget = function(){return new QWidget();};

/**
  * @name activeWindow
  * @function
  * @memberOf QApplication
  * @returns {QWidget}
  */
QApplication.activeWindow = function(){return new QWidget();};

/**
  * @name alert
  * @function
  * @memberOf QApplication
  * @param {QWidget} widget
  * @param {Numeric} duration
  * @returns {undefined}
  */
QApplication.alert = function(widget, duration){return undefined;};

/**
  * @name allWidgets
  * @function
  * @memberOf QApplication
  * @returns {Array}
  */
QApplication.allWidgets = function(){return new Array();};

/**
  * @name beep
  * @function
  * @memberOf QApplication
  * @returns {undefined}
  */
QApplication.beep = function(){return undefined;};

/**
  * @name changeOverrideCursor
  * @function
  * @memberOf QApplication
  * @param {QCursor} arg__1
  * @returns {undefined}
  */
QApplication.changeOverrideCursor = function(arg__1){return undefined;};

/**
  * @name clipboard
  * @function
  * @memberOf QApplication
  * @returns {QClipboard}
  */
QApplication.clipboard = function(){return new QClipboard();};

/**
  * @name colorSpec
  * @function
  * @memberOf QApplication
  * @returns {Numeric}
  */
QApplication.colorSpec = function(){return new Numeric();};

/**
  * @name desktop
  * @function
  * @memberOf QApplication
  * @returns {QDesktopWidget}
  */
QApplication.desktop = function(){return new QDesktopWidget();};

/**
  * @name desktopSettingsAware
  * @function
  * @memberOf QApplication
  * @returns {Boolean}
  */
QApplication.desktopSettingsAware = function(){return new Boolean();};

/**
  * @name focusWidget
  * @function
  * @memberOf QApplication
  * @returns {QWidget}
  */
QApplication.focusWidget = function(){return new QWidget();};

/**
  * @name font
  * @function
  * @memberOf QApplication
  * @returns {QFont}
  */
QApplication.font = function(){return new QFont();};

/**
  * @name isEffectEnabled
  * @function
  * @memberOf QApplication
  * @param {Qt.UIEffect} arg__1
  * @returns {Boolean}
  */
QApplication.isEffectEnabled = function(arg__1){return new Boolean();};

/**
  * @name isLeftToRight
  * @function
  * @memberOf QApplication
  * @returns {Boolean}
  */
QApplication.isLeftToRight = function(){return new Boolean();};

/**
  * @name isRightToLeft
  * @function
  * @memberOf QApplication
  * @returns {Boolean}
  */
QApplication.isRightToLeft = function(){return new Boolean();};

/**
  * @name keyboardInputDirection
  * @function
  * @memberOf QApplication
  * @returns {QTextFormat.LayoutDirection}
  */
QApplication.keyboardInputDirection = function(){return new QTextFormat.LayoutDirection();};

/**
  * @name keyboardInputLocale
  * @function
  * @memberOf QApplication
  * @returns {QLocale}
  */
QApplication.keyboardInputLocale = function(){return new QLocale();};

/**
  * @name keyboardModifiers
  * @function
  * @memberOf QApplication
  * @returns {Qt.KeyboardModifiers}
  */
QApplication.keyboardModifiers = function(){return new Qt.KeyboardModifiers();};

/**
  * @name mouseButtons
  * @function
  * @memberOf QApplication
  * @returns {Qt.MouseButtons}
  */
QApplication.mouseButtons = function(){return new Qt.MouseButtons();};

/**
  * @name overrideCursor_private
  * @function
  * @memberOf QApplication
  * @returns {QCursor}
  */
QApplication.overrideCursor_private = function(){return new QCursor();};

/**
  * @name palette
  * @function
  * @memberOf QApplication
  * @returns {QPalette}
  */
QApplication.palette = function(){return new QPalette();};

/**
  * @name queryKeyboardModifiers
  * @function
  * @memberOf QApplication
  * @returns {Qt.KeyboardModifiers}
  */
QApplication.queryKeyboardModifiers = function(){return new Qt.KeyboardModifiers();};

/**
  * @name restoreOverrideCursor
  * @function
  * @memberOf QApplication
  * @returns {undefined}
  */
QApplication.restoreOverrideCursor = function(){return undefined;};

/**
  * @name setActiveWindow
  * @function
  * @memberOf QApplication
  * @param {QWidget} act
  * @returns {undefined}
  */
QApplication.setActiveWindow = function(act){return undefined;};

/**
  * @name setColorSpec
  * @function
  * @memberOf QApplication
  * @param {Numeric} arg__1
  * @returns {undefined}
  */
QApplication.setColorSpec = function(arg__1){return undefined;};

/**
  * @name setDesktopSettingsAware
  * @function
  * @memberOf QApplication
  * @param {Boolean} arg__1
  * @returns {undefined}
  */
QApplication.setDesktopSettingsAware = function(arg__1){return undefined;};

/**
  * @name setEffectEnabled
  * @function
  * @memberOf QApplication
  * @param {Qt.UIEffect} arg__1
  * @param {Boolean} enable
  * @returns {undefined}
  */
QApplication.setEffectEnabled = function(arg__1, enable){return undefined;};

/**
  * @name setFont
  * @function
  * @memberOf QApplication
  * @param {QFont} arg__1
  * @param {String} className
  * @returns {undefined}
  */
QApplication.setFont = function(arg__1, className){return undefined;};

/**
  * @name setGraphicsSystem
  * @function
  * @memberOf QApplication
  * @param {String} arg__1
  * @returns {undefined}
  */
QApplication.setGraphicsSystem = function(arg__1){return undefined;};

/**
  * @name setOverrideCursor
  * @function
  * @memberOf QApplication
  * @param {QCursor} arg__1
  * @returns {undefined}
  */
QApplication.setOverrideCursor = function(arg__1){return undefined;};

/**
  * @name setPalette
  * @function
  * @memberOf QApplication
  * @param {QPalette} arg__1
  * @param {String} className
  * @returns {undefined}
  */
QApplication.setPalette = function(arg__1, className){return undefined;};

/**
  * @name setStyle
  * @function
  * @memberOf QApplication
  * @param {QStyle} arg__1
  * @returns {undefined}
  */
QApplication.setStyle = function(arg__1){return undefined;};

/**
  * @name style
  * @function
  * @memberOf QApplication
  * @returns {QStyle}
  */
QApplication.style = function(){return new QStyle();};

/**
  * @name syncX
  * @function
  * @memberOf QApplication
  * @returns {undefined}
  */
QApplication.syncX = function(){return undefined;};

/**
  * @name topLevelAt
  * @function
  * @memberOf QApplication
  * @param {QPoint} p
  * @returns {QWidget}
  */
QApplication.topLevelAt = function(p){return new QWidget();};

/**
  * @name topLevelWidgets
  * @function
  * @memberOf QApplication
  * @returns {Array}
  */
QApplication.topLevelWidgets = function(){return new Array();};

/**
  * @name type
  * @function
  * @memberOf QApplication
  * @returns {QApplication.Type}
  */
QApplication.type = function(){return new QApplication.Type();};

/**
  * @name widgetAt
  * @function
  * @memberOf QApplication
  * @param {QPoint} p
  * @returns {QWidget}
  */
QApplication.widgetAt = function(p){return new QWidget();};

/**
  * @default 0x0
  * @constant
  * @memberOf QApplication
  * @name Tty
  * @see QApplication#Type
  * @type Number
  */
QApplication.Tty = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QApplication
  * @name GuiClient
  * @see QApplication#Type
  * @type Number
  */
QApplication.GuiClient = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QApplication
  * @name GuiServer
  * @see QApplication#Type
  * @type Number
  */
QApplication.GuiServer = 0x2;

/**
  * @constructor 
  * @memberOf QApplication
  * @name Type
  */
QApplication.Type = function(value){;};



/**
  * @default 0
  * @constant
  * @memberOf QApplication
  * @name NormalColor
  * @see QApplication#ColorSpec
  * @type Number
  */
QApplication.NormalColor = 0x0;

/**
  * @default 1
  * @constant
  * @memberOf QApplication
  * @name CustomColor
  * @see QApplication#ColorSpec
  * @type Number
  */
QApplication.CustomColor = 0x1;

/**
  * @default 2
  * @constant
  * @memberOf QApplication
  * @name ManyColor
  * @see QApplication#ColorSpec
  * @type Number
  */
QApplication.ManyColor = 0x2;

/**
  * @constructor 
  * @memberOf QApplication
  * @name ColorSpec
  */
QApplication.ColorSpec = function(value){;};



/**
  * @name inputContext
  * @function
  * @memberOf QApplication.prototype
  * @returns {QInputContext}
  */
QApplication.prototype.inputContext = function(){return new QInputContext();};

/**
  * @name isSessionRestored
  * @function
  * @memberOf QApplication.prototype
  * @returns {Boolean}
  */
QApplication.prototype.isSessionRestored = function(){return new Boolean();};

/**
  * @name sessionId
  * @function
  * @memberOf QApplication.prototype
  * @returns {String}
  */
QApplication.prototype.sessionId = function(){return new String();};

/**
  * @name sessionKey
  * @function
  * @memberOf QApplication.prototype
  * @returns {String}
  */
QApplication.prototype.sessionKey = function(){return new String();};

/**
  * @name setInputContext
  * @function
  * @memberOf QApplication.prototype
  * @param {QInputContext} arg__1
  * @returns {undefined}
  */
QApplication.prototype.setInputContext = function(arg__1){return undefined;};

/**
  * @name layoutDirection
  * @memberOf QApplication.prototype
  * @type QTextFormat.LayoutDirection
  */
QApplication.prototype.layoutDirection = new QTextFormat.LayoutDirection();

/**
  * @name windowIcon
  * @memberOf QApplication.prototype
  * @type QIcon
  */
QApplication.prototype.windowIcon = new QIcon();

/**
  * @name cursorFlashTime
  * @memberOf QApplication.prototype
  * @type Numeric
  */
QApplication.prototype.cursorFlashTime = new Numeric();

/**
  * @name doubleClickInterval
  * @memberOf QApplication.prototype
  * @type Numeric
  */
QApplication.prototype.doubleClickInterval = new Numeric();

/**
  * @name keyboardInputInterval
  * @memberOf QApplication.prototype
  * @type Numeric
  */
QApplication.prototype.keyboardInputInterval = new Numeric();

/**
  * @name wheelScrollLines
  * @memberOf QApplication.prototype
  * @type Numeric
  */
QApplication.prototype.wheelScrollLines = new Numeric();

/**
  * @name globalStrut
  * @memberOf QApplication.prototype
  * @type QSize
  */
QApplication.prototype.globalStrut = new QSize();

/**
  * @name startDragTime
  * @memberOf QApplication.prototype
  * @type Numeric
  */
QApplication.prototype.startDragTime = new Numeric();

/**
  * @name startDragDistance
  * @memberOf QApplication.prototype
  * @type Numeric
  */
QApplication.prototype.startDragDistance = new Numeric();

/**
  * @name quitOnLastWindowClosed
  * @memberOf QApplication.prototype
  * @type Boolean
  */
QApplication.prototype.quitOnLastWindowClosed = new Boolean();

/**
  * @name styleSheet
  * @memberOf QApplication.prototype
  * @type String
  */
QApplication.prototype.styleSheet = new String();

/**
  * @name autoSipEnabled
  * @memberOf QApplication.prototype
  * @type Boolean
  */
QApplication.prototype.autoSipEnabled = new Boolean();


