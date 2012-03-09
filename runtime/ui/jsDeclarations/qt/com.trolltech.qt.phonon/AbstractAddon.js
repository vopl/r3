/**
  * @name AbstractAddon
  * @constructor
  */
function AbstractAddon(){return undefined;};

/**
  * @default 0x0
  * @constant
  * @memberOf AbstractAddon
  * @name availableSubtitles
  * @see AbstractAddon#SubtitleCommand
  * @type Number
  */
AbstractAddon.availableSubtitles = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf AbstractAddon
  * @name currentSubtitle
  * @see AbstractAddon#SubtitleCommand
  * @type Number
  */
AbstractAddon.currentSubtitle = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf AbstractAddon
  * @name setCurrentSubtitle
  * @see AbstractAddon#SubtitleCommand
  * @type Number
  */
AbstractAddon.setCurrentSubtitle = 0x2;

/**
  * @constructor 
  * @memberOf AbstractAddon
  * @name SubtitleCommand
  */
AbstractAddon.SubtitleCommand = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf AbstractAddon
  * @name availableTitles
  * @see AbstractAddon#TitleCommand
  * @type Number
  */
AbstractAddon.availableTitles = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf AbstractAddon
  * @name title
  * @see AbstractAddon#TitleCommand
  * @type Number
  */
AbstractAddon.title = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf AbstractAddon
  * @name setTitle
  * @see AbstractAddon#TitleCommand
  * @type Number
  */
AbstractAddon.setTitle = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf AbstractAddon
  * @name autoplayTitles
  * @see AbstractAddon#TitleCommand
  * @type Number
  */
AbstractAddon.autoplayTitles = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf AbstractAddon
  * @name setAutoplayTitles
  * @see AbstractAddon#TitleCommand
  * @type Number
  */
AbstractAddon.setAutoplayTitles = 0x4;

/**
  * @constructor 
  * @memberOf AbstractAddon
  * @name TitleCommand
  */
AbstractAddon.TitleCommand = function(value){;};



/**
  * @default 1
  * @constant
  * @memberOf AbstractAddon
  * @name NavigationInterface
  * @see AbstractAddon#Interface
  * @type Number
  */
AbstractAddon.NavigationInterface = 0x1;

/**
  * @default 2
  * @constant
  * @memberOf AbstractAddon
  * @name ChapterInterface
  * @see AbstractAddon#Interface
  * @type Number
  */
AbstractAddon.ChapterInterface = 0x2;

/**
  * @default 3
  * @constant
  * @memberOf AbstractAddon
  * @name AngleInterface
  * @see AbstractAddon#Interface
  * @type Number
  */
AbstractAddon.AngleInterface = 0x3;

/**
  * @default 4
  * @constant
  * @memberOf AbstractAddon
  * @name TitleInterface
  * @see AbstractAddon#Interface
  * @type Number
  */
AbstractAddon.TitleInterface = 0x4;

/**
  * @default 5
  * @constant
  * @memberOf AbstractAddon
  * @name SubtitleInterface
  * @see AbstractAddon#Interface
  * @type Number
  */
AbstractAddon.SubtitleInterface = 0x5;

/**
  * @default 6
  * @constant
  * @memberOf AbstractAddon
  * @name AudioChannelInterface
  * @see AbstractAddon#Interface
  * @type Number
  */
AbstractAddon.AudioChannelInterface = 0x6;

/**
  * @constructor 
  * @memberOf AbstractAddon
  * @name Interface
  */
AbstractAddon.Interface = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf AbstractAddon
  * @name availableAudioChannels
  * @see AbstractAddon#AudioChannelCommand
  * @type Number
  */
AbstractAddon.availableAudioChannels = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf AbstractAddon
  * @name currentAudioChannel
  * @see AbstractAddon#AudioChannelCommand
  * @type Number
  */
AbstractAddon.currentAudioChannel = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf AbstractAddon
  * @name setCurrentAudioChannel
  * @see AbstractAddon#AudioChannelCommand
  * @type Number
  */
AbstractAddon.setCurrentAudioChannel = 0x2;

/**
  * @constructor 
  * @memberOf AbstractAddon
  * @name AudioChannelCommand
  */
AbstractAddon.AudioChannelCommand = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf AbstractAddon
  * @name availableChapters
  * @see AbstractAddon#ChapterCommand
  * @type Number
  */
AbstractAddon.availableChapters = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf AbstractAddon
  * @name chapter
  * @see AbstractAddon#ChapterCommand
  * @type Number
  */
AbstractAddon.chapter = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf AbstractAddon
  * @name setChapter
  * @see AbstractAddon#ChapterCommand
  * @type Number
  */
AbstractAddon.setChapter = 0x2;

/**
  * @constructor 
  * @memberOf AbstractAddon
  * @name ChapterCommand
  */
AbstractAddon.ChapterCommand = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf AbstractAddon
  * @name Menu1Button
  * @see AbstractAddon#NavigationCommand
  * @type Number
  */
AbstractAddon.Menu1Button = 0x0;

/**
  * @constructor 
  * @memberOf AbstractAddon
  * @name NavigationCommand
  */
AbstractAddon.NavigationCommand = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf AbstractAddon
  * @name availableAngles
  * @see AbstractAddon#AngleCommand
  * @type Number
  */
AbstractAddon.availableAngles = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf AbstractAddon
  * @name angle
  * @see AbstractAddon#AngleCommand
  * @type Number
  */
AbstractAddon.angle = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf AbstractAddon
  * @name setAngle
  * @see AbstractAddon#AngleCommand
  * @type Number
  */
AbstractAddon.setAngle = 0x2;

/**
  * @constructor 
  * @memberOf AbstractAddon
  * @name AngleCommand
  */
AbstractAddon.AngleCommand = function(value){;};



/**
  * @name hasInterface
  * @function
  * @memberOf AbstractAddon.prototype
  * @param {AbstractAddon.Interface} iface
  * @returns {Boolean}
  */
AbstractAddon.prototype.hasInterface = function(iface){return new Boolean();};

/**
  * @name interfaceCall
  * @function
  * @memberOf AbstractAddon.prototype
  * @param {AbstractAddon.Interface} iface
  * @param {Numeric} command
  * @param {Array} arguments
  * @returns {Object}
  */
AbstractAddon.prototype.interfaceCall = function(iface, command, arguments){return new Object();};

