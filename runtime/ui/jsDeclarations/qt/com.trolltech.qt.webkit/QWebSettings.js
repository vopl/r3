/**
  * @class QWebSettings from package com.trolltech.qt.webkit
  */
var QWebSettings = {};

/**
  * @name clearIconDatabase
  * @function
  * @memberOf QWebSettings
  * @returns {undefined}
  */
QWebSettings.clearIconDatabase = function(){return undefined;};

/**
  * @name clearMemoryCaches
  * @function
  * @memberOf QWebSettings
  * @returns {undefined}
  */
QWebSettings.clearMemoryCaches = function(){return undefined;};

/**
  * @name enablePersistentStorage
  * @function
  * @memberOf QWebSettings
  * @param {String} path
  * @returns {undefined}
  */
QWebSettings.enablePersistentStorage = function(path){return undefined;};

/**
  * @name globalSettings
  * @function
  * @memberOf QWebSettings
  * @returns {QWebSettings}
  */
QWebSettings.globalSettings = function(){return new QWebSettings();};

/**
  * @name iconDatabasePath
  * @function
  * @memberOf QWebSettings
  * @returns {String}
  */
QWebSettings.iconDatabasePath = function(){return new String();};

/**
  * @name iconForUrl
  * @function
  * @memberOf QWebSettings
  * @param {QUrl} url
  * @returns {QIcon}
  */
QWebSettings.iconForUrl = function(url){return new QIcon();};

/**
  * @name maximumPagesInCache
  * @function
  * @memberOf QWebSettings
  * @returns {Numeric}
  */
QWebSettings.maximumPagesInCache = function(){return new Numeric();};

/**
  * @name offlineStorageDefaultQuota
  * @function
  * @memberOf QWebSettings
  * @returns {Numeric}
  */
QWebSettings.offlineStorageDefaultQuota = function(){return new Numeric();};

/**
  * @name offlineStoragePath
  * @function
  * @memberOf QWebSettings
  * @returns {String}
  */
QWebSettings.offlineStoragePath = function(){return new String();};

/**
  * @name offlineWebApplicationCachePath
  * @function
  * @memberOf QWebSettings
  * @returns {String}
  */
QWebSettings.offlineWebApplicationCachePath = function(){return new String();};

/**
  * @name offlineWebApplicationCacheQuota
  * @function
  * @memberOf QWebSettings
  * @returns {Numeric}
  */
QWebSettings.offlineWebApplicationCacheQuota = function(){return new Numeric();};

/**
  * @name setIconDatabasePath
  * @function
  * @memberOf QWebSettings
  * @param {String} location
  * @returns {undefined}
  */
QWebSettings.setIconDatabasePath = function(location){return undefined;};

/**
  * @name setMaximumPagesInCache
  * @function
  * @memberOf QWebSettings
  * @param {Numeric} pages
  * @returns {undefined}
  */
QWebSettings.setMaximumPagesInCache = function(pages){return undefined;};

/**
  * @name setObjectCacheCapacities
  * @function
  * @memberOf QWebSettings
  * @param {Numeric} cacheMinDeadCapacity
  * @param {Numeric} cacheMaxDead
  * @param {Numeric} totalCapacity
  * @returns {undefined}
  */
QWebSettings.setObjectCacheCapacities = function(cacheMinDeadCapacity, cacheMaxDead, totalCapacity){return undefined;};

/**
  * @name setOfflineStorageDefaultQuota
  * @function
  * @memberOf QWebSettings
  * @param {Numeric} maximumSize
  * @returns {undefined}
  */
QWebSettings.setOfflineStorageDefaultQuota = function(maximumSize){return undefined;};

/**
  * @name setOfflineStoragePath
  * @function
  * @memberOf QWebSettings
  * @param {String} path
  * @returns {undefined}
  */
QWebSettings.setOfflineStoragePath = function(path){return undefined;};

/**
  * @name setOfflineWebApplicationCachePath
  * @function
  * @memberOf QWebSettings
  * @param {String} path
  * @returns {undefined}
  */
QWebSettings.setOfflineWebApplicationCachePath = function(path){return undefined;};

/**
  * @name setOfflineWebApplicationCacheQuota
  * @function
  * @memberOf QWebSettings
  * @param {Numeric} maximumSize
  * @returns {undefined}
  */
QWebSettings.setOfflineWebApplicationCacheQuota = function(maximumSize){return undefined;};

/**
  * @name setWebGraphic
  * @function
  * @memberOf QWebSettings
  * @param {QWebSettings.WebGraphic} type
  * @param {QPixmap} graphic
  * @returns {undefined}
  */
QWebSettings.setWebGraphic = function(type, graphic){return undefined;};

/**
  * @name webGraphic
  * @function
  * @memberOf QWebSettings
  * @param {QWebSettings.WebGraphic} type
  * @returns {QPixmap}
  */
QWebSettings.webGraphic = function(type){return new QPixmap();};

/**
  * @default 0x0
  * @constant
  * @memberOf QWebSettings
  * @name MinimumFontSize
  * @see QWebSettings#FontSize
  * @type Number
  */
QWebSettings.MinimumFontSize = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QWebSettings
  * @name MinimumLogicalFontSize
  * @see QWebSettings#FontSize
  * @type Number
  */
QWebSettings.MinimumLogicalFontSize = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QWebSettings
  * @name DefaultFontSize
  * @see QWebSettings#FontSize
  * @type Number
  */
QWebSettings.DefaultFontSize = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QWebSettings
  * @name DefaultFixedFontSize
  * @see QWebSettings#FontSize
  * @type Number
  */
QWebSettings.DefaultFixedFontSize = 0x3;

/**
  * @constructor 
  * @memberOf QWebSettings
  * @name FontSize
  */
QWebSettings.FontSize = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QWebSettings
  * @name MissingImageGraphic
  * @see QWebSettings#WebGraphic
  * @type Number
  */
QWebSettings.MissingImageGraphic = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QWebSettings
  * @name MissingPluginGraphic
  * @see QWebSettings#WebGraphic
  * @type Number
  */
QWebSettings.MissingPluginGraphic = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QWebSettings
  * @name DefaultFrameIconGraphic
  * @see QWebSettings#WebGraphic
  * @type Number
  */
QWebSettings.DefaultFrameIconGraphic = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QWebSettings
  * @name TextAreaSizeGripCornerGraphic
  * @see QWebSettings#WebGraphic
  * @type Number
  */
QWebSettings.TextAreaSizeGripCornerGraphic = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QWebSettings
  * @name DeleteButtonGraphic
  * @see QWebSettings#WebGraphic
  * @type Number
  */
QWebSettings.DeleteButtonGraphic = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QWebSettings
  * @name InputSpeechButtonGraphic
  * @see QWebSettings#WebGraphic
  * @type Number
  */
QWebSettings.InputSpeechButtonGraphic = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf QWebSettings
  * @name SearchCancelButtonGraphic
  * @see QWebSettings#WebGraphic
  * @type Number
  */
QWebSettings.SearchCancelButtonGraphic = 0x6;

/**
  * @default 0x7
  * @constant
  * @memberOf QWebSettings
  * @name SearchCancelButtonPressedGraphic
  * @see QWebSettings#WebGraphic
  * @type Number
  */
QWebSettings.SearchCancelButtonPressedGraphic = 0x7;

/**
  * @constructor 
  * @memberOf QWebSettings
  * @name WebGraphic
  */
QWebSettings.WebGraphic = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QWebSettings
  * @name StandardFont
  * @see QWebSettings#FontFamily
  * @type Number
  */
QWebSettings.StandardFont = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QWebSettings
  * @name FixedFont
  * @see QWebSettings#FontFamily
  * @type Number
  */
QWebSettings.FixedFont = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QWebSettings
  * @name SerifFont
  * @see QWebSettings#FontFamily
  * @type Number
  */
QWebSettings.SerifFont = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QWebSettings
  * @name SansSerifFont
  * @see QWebSettings#FontFamily
  * @type Number
  */
QWebSettings.SansSerifFont = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QWebSettings
  * @name CursiveFont
  * @see QWebSettings#FontFamily
  * @type Number
  */
QWebSettings.CursiveFont = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QWebSettings
  * @name FantasyFont
  * @see QWebSettings#FontFamily
  * @type Number
  */
QWebSettings.FantasyFont = 0x5;

/**
  * @constructor 
  * @memberOf QWebSettings
  * @name FontFamily
  */
QWebSettings.FontFamily = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QWebSettings
  * @name AutoLoadImages
  * @see QWebSettings#WebAttribute
  * @type Number
  */
QWebSettings.AutoLoadImages = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QWebSettings
  * @name JavascriptEnabled
  * @see QWebSettings#WebAttribute
  * @type Number
  */
QWebSettings.JavascriptEnabled = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QWebSettings
  * @name JavaEnabled
  * @see QWebSettings#WebAttribute
  * @type Number
  */
QWebSettings.JavaEnabled = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QWebSettings
  * @name PluginsEnabled
  * @see QWebSettings#WebAttribute
  * @type Number
  */
QWebSettings.PluginsEnabled = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QWebSettings
  * @name PrivateBrowsingEnabled
  * @see QWebSettings#WebAttribute
  * @type Number
  */
QWebSettings.PrivateBrowsingEnabled = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QWebSettings
  * @name JavascriptCanOpenWindows
  * @see QWebSettings#WebAttribute
  * @type Number
  */
QWebSettings.JavascriptCanOpenWindows = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf QWebSettings
  * @name JavascriptCanAccessClipboard
  * @see QWebSettings#WebAttribute
  * @type Number
  */
QWebSettings.JavascriptCanAccessClipboard = 0x6;

/**
  * @default 0x7
  * @constant
  * @memberOf QWebSettings
  * @name DeveloperExtrasEnabled
  * @see QWebSettings#WebAttribute
  * @type Number
  */
QWebSettings.DeveloperExtrasEnabled = 0x7;

/**
  * @default 0x8
  * @constant
  * @memberOf QWebSettings
  * @name LinksIncludedInFocusChain
  * @see QWebSettings#WebAttribute
  * @type Number
  */
QWebSettings.LinksIncludedInFocusChain = 0x8;

/**
  * @default 0x9
  * @constant
  * @memberOf QWebSettings
  * @name ZoomTextOnly
  * @see QWebSettings#WebAttribute
  * @type Number
  */
QWebSettings.ZoomTextOnly = 0x9;

/**
  * @default 0xa
  * @constant
  * @memberOf QWebSettings
  * @name PrintElementBackgrounds
  * @see QWebSettings#WebAttribute
  * @type Number
  */
QWebSettings.PrintElementBackgrounds = 0xa;

/**
  * @default 0xb
  * @constant
  * @memberOf QWebSettings
  * @name OfflineStorageDatabaseEnabled
  * @see QWebSettings#WebAttribute
  * @type Number
  */
QWebSettings.OfflineStorageDatabaseEnabled = 0xb;

/**
  * @default 0xc
  * @constant
  * @memberOf QWebSettings
  * @name OfflineWebApplicationCacheEnabled
  * @see QWebSettings#WebAttribute
  * @type Number
  */
QWebSettings.OfflineWebApplicationCacheEnabled = 0xc;

/**
  * @default 0xd
  * @constant
  * @memberOf QWebSettings
  * @name LocalStorageEnabled
  * @see QWebSettings#WebAttribute
  * @type Number
  */
QWebSettings.LocalStorageEnabled = 0xd;

/**
  * @default 0xe
  * @constant
  * @memberOf QWebSettings
  * @name LocalContentCanAccessRemoteUrls
  * @see QWebSettings#WebAttribute
  * @type Number
  */
QWebSettings.LocalContentCanAccessRemoteUrls = 0xe;

/**
  * @default 0xf
  * @constant
  * @memberOf QWebSettings
  * @name DnsPrefetchEnabled
  * @see QWebSettings#WebAttribute
  * @type Number
  */
QWebSettings.DnsPrefetchEnabled = 0xf;

/**
  * @default 0x10
  * @constant
  * @memberOf QWebSettings
  * @name XSSAuditingEnabled
  * @see QWebSettings#WebAttribute
  * @type Number
  */
QWebSettings.XSSAuditingEnabled = 0x10;

/**
  * @default 0x11
  * @constant
  * @memberOf QWebSettings
  * @name AcceleratedCompositingEnabled
  * @see QWebSettings#WebAttribute
  * @type Number
  */
QWebSettings.AcceleratedCompositingEnabled = 0x11;

/**
  * @default 0x12
  * @constant
  * @memberOf QWebSettings
  * @name SpatialNavigationEnabled
  * @see QWebSettings#WebAttribute
  * @type Number
  */
QWebSettings.SpatialNavigationEnabled = 0x12;

/**
  * @default 0x13
  * @constant
  * @memberOf QWebSettings
  * @name LocalContentCanAccessFileUrls
  * @see QWebSettings#WebAttribute
  * @type Number
  */
QWebSettings.LocalContentCanAccessFileUrls = 0x13;

/**
  * @default 0x14
  * @constant
  * @memberOf QWebSettings
  * @name TiledBackingStoreEnabled
  * @see QWebSettings#WebAttribute
  * @type Number
  */
QWebSettings.TiledBackingStoreEnabled = 0x14;

/**
  * @default 0x15
  * @constant
  * @memberOf QWebSettings
  * @name FrameFlatteningEnabled
  * @see QWebSettings#WebAttribute
  * @type Number
  */
QWebSettings.FrameFlatteningEnabled = 0x15;

/**
  * @default 0x16
  * @constant
  * @memberOf QWebSettings
  * @name SiteSpecificQuirksEnabled
  * @see QWebSettings#WebAttribute
  * @type Number
  */
QWebSettings.SiteSpecificQuirksEnabled = 0x16;

/**
  * @default 0x17
  * @constant
  * @memberOf QWebSettings
  * @name JavascriptCanCloseWindows
  * @see QWebSettings#WebAttribute
  * @type Number
  */
QWebSettings.JavascriptCanCloseWindows = 0x17;

/**
  * @default 0x18
  * @constant
  * @memberOf QWebSettings
  * @name WebGLEnabled
  * @see QWebSettings#WebAttribute
  * @type Number
  */
QWebSettings.WebGLEnabled = 0x18;

/**
  * @default 0x19
  * @constant
  * @memberOf QWebSettings
  * @name HyperlinkAuditingEnabled
  * @see QWebSettings#WebAttribute
  * @type Number
  */
QWebSettings.HyperlinkAuditingEnabled = 0x19;

/**
  * @constructor 
  * @memberOf QWebSettings
  * @name WebAttribute
  */
QWebSettings.WebAttribute = function(value){;};



/**
  * @name defaultTextEncoding
  * @function
  * @memberOf QWebSettings.prototype
  * @returns {String}
  */
QWebSettings.prototype.defaultTextEncoding = function(){return new String();};

/**
  * @name fontFamily
  * @function
  * @memberOf QWebSettings.prototype
  * @param {QWebSettings.FontFamily} which
  * @returns {String}
  */
QWebSettings.prototype.fontFamily = function(which){return new String();};

/**
  * @name fontSize
  * @function
  * @memberOf QWebSettings.prototype
  * @param {QWebSettings.FontSize} type
  * @returns {Numeric}
  */
QWebSettings.prototype.fontSize = function(type){return new Numeric();};

/**
  * @name localStoragePath
  * @function
  * @memberOf QWebSettings.prototype
  * @returns {String}
  */
QWebSettings.prototype.localStoragePath = function(){return new String();};

/**
  * @name resetAttribute
  * @function
  * @memberOf QWebSettings.prototype
  * @param {QWebSettings.WebAttribute} attr
  * @returns {undefined}
  */
QWebSettings.prototype.resetAttribute = function(attr){return undefined;};

/**
  * @name resetFontFamily
  * @function
  * @memberOf QWebSettings.prototype
  * @param {QWebSettings.FontFamily} which
  * @returns {undefined}
  */
QWebSettings.prototype.resetFontFamily = function(which){return undefined;};

/**
  * @name resetFontSize
  * @function
  * @memberOf QWebSettings.prototype
  * @param {QWebSettings.FontSize} type
  * @returns {undefined}
  */
QWebSettings.prototype.resetFontSize = function(type){return undefined;};

/**
  * @name setAttribute
  * @function
  * @memberOf QWebSettings.prototype
  * @param {QWebSettings.WebAttribute} attr
  * @param {Boolean} on
  * @returns {undefined}
  */
QWebSettings.prototype.setAttribute = function(attr, on){return undefined;};

/**
  * @name setDefaultTextEncoding
  * @function
  * @memberOf QWebSettings.prototype
  * @param {String} encoding
  * @returns {undefined}
  */
QWebSettings.prototype.setDefaultTextEncoding = function(encoding){return undefined;};

/**
  * @name setFontFamily
  * @function
  * @memberOf QWebSettings.prototype
  * @param {QWebSettings.FontFamily} which
  * @param {String} family
  * @returns {undefined}
  */
QWebSettings.prototype.setFontFamily = function(which, family){return undefined;};

/**
  * @name setFontSize
  * @function
  * @memberOf QWebSettings.prototype
  * @param {QWebSettings.FontSize} type
  * @param {Numeric} size
  * @returns {undefined}
  */
QWebSettings.prototype.setFontSize = function(type, size){return undefined;};

/**
  * @name setLocalStoragePath
  * @function
  * @memberOf QWebSettings.prototype
  * @param {String} path
  * @returns {undefined}
  */
QWebSettings.prototype.setLocalStoragePath = function(path){return undefined;};

/**
  * @name setUserStyleSheetUrl
  * @function
  * @memberOf QWebSettings.prototype
  * @param {QUrl} location
  * @returns {undefined}
  */
QWebSettings.prototype.setUserStyleSheetUrl = function(location){return undefined;};

/**
  * @name testAttribute
  * @function
  * @memberOf QWebSettings.prototype
  * @param {QWebSettings.WebAttribute} attr
  * @returns {Boolean}
  */
QWebSettings.prototype.testAttribute = function(attr){return new Boolean();};

/**
  * @name userStyleSheetUrl
  * @function
  * @memberOf QWebSettings.prototype
  * @returns {QUrl}
  */
QWebSettings.prototype.userStyleSheetUrl = function(){return new QUrl();};

