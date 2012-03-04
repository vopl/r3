/**
  * @namespace Phonon from package com.trolltech.qt.phonon
  */
var Phonon = {};

/**
  * @name categoryToString
  * @function
  * @memberOf Phonon
  * @param {Phonon.Category} c
  * @returns {String}
  */
Phonon.categoryToString = function(c){return new String();};

/**
  * @name createPath
  * @function
  * @memberOf Phonon
  * @param {MediaNode} source
  * @param {MediaNode} sink
  * @returns {Path}
  */
Phonon.createPath = function(source, sink){return new Path();};

/**
  * @name createPlayer
  * @function
  * @memberOf Phonon
  * @param {Phonon.Category} category
  * @param {MediaSource} source
  * @returns {MediaObject}
  */
Phonon.createPlayer = function(category, source){return new MediaObject();};

/**
  * @name phononVersion
  * @function
  * @memberOf Phonon
  * @returns {String}
  */
Phonon.phononVersion = function(){return new String();};

/**
  * @name qHash
  * @function
  * @memberOf Phonon
  * @param {EffectParameter} param
  * @returns {Numeric}
  */
Phonon.qHash = function(param){return new Numeric();};

/**
  * @default -1
  * @constant
  * @memberOf Phonon
  * @name NoDisc
  * @see Phonon#DiscType
  * @type Number
  */
Phonon.NoDisc = 0xffffffff;

/**
  * @default 0
  * @constant
  * @memberOf Phonon
  * @name Cd
  * @see Phonon#DiscType
  * @type Number
  */
Phonon.Cd = 0x0;

/**
  * @default 1
  * @constant
  * @memberOf Phonon
  * @name Dvd
  * @see Phonon#DiscType
  * @type Number
  */
Phonon.Dvd = 0x1;

/**
  * @default 2
  * @constant
  * @memberOf Phonon
  * @name Vcd
  * @see Phonon#DiscType
  * @type Number
  */
Phonon.Vcd = 0x2;

/**
  * @constructor 
  * @memberOf Phonon
  * @name DiscType
  */
Phonon.DiscType = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf Phonon
  * @name ArtistMetaData
  * @see Phonon#MetaData
  * @type Number
  */
Phonon.ArtistMetaData = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf Phonon
  * @name AlbumMetaData
  * @see Phonon#MetaData
  * @type Number
  */
Phonon.AlbumMetaData = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf Phonon
  * @name TitleMetaData
  * @see Phonon#MetaData
  * @type Number
  */
Phonon.TitleMetaData = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf Phonon
  * @name DateMetaData
  * @see Phonon#MetaData
  * @type Number
  */
Phonon.DateMetaData = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf Phonon
  * @name GenreMetaData
  * @see Phonon#MetaData
  * @type Number
  */
Phonon.GenreMetaData = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf Phonon
  * @name TracknumberMetaData
  * @see Phonon#MetaData
  * @type Number
  */
Phonon.TracknumberMetaData = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf Phonon
  * @name DescriptionMetaData
  * @see Phonon#MetaData
  * @type Number
  */
Phonon.DescriptionMetaData = 0x6;

/**
  * @default 0x7
  * @constant
  * @memberOf Phonon
  * @name MusicBrainzDiscIdMetaData
  * @see Phonon#MetaData
  * @type Number
  */
Phonon.MusicBrainzDiscIdMetaData = 0x7;

/**
  * @constructor 
  * @memberOf Phonon
  * @name MetaData
  */
Phonon.MetaData = function(value){;};



/**
  * @default -1
  * @constant
  * @memberOf Phonon
  * @name NoCategory
  * @see Phonon#Category
  * @type Number
  */
Phonon.NoCategory = 0xffffffff;

/**
  * @default 0
  * @constant
  * @memberOf Phonon
  * @name NotificationCategory
  * @see Phonon#Category
  * @type Number
  */
Phonon.NotificationCategory = 0x0;

/**
  * @default 1
  * @constant
  * @memberOf Phonon
  * @name MusicCategory
  * @see Phonon#Category
  * @type Number
  */
Phonon.MusicCategory = 0x1;

/**
  * @default 2
  * @constant
  * @memberOf Phonon
  * @name VideoCategory
  * @see Phonon#Category
  * @type Number
  */
Phonon.VideoCategory = 0x2;

/**
  * @default 3
  * @constant
  * @memberOf Phonon
  * @name CommunicationCategory
  * @see Phonon#Category
  * @type Number
  */
Phonon.CommunicationCategory = 0x3;

/**
  * @default 4
  * @constant
  * @memberOf Phonon
  * @name GameCategory
  * @see Phonon#Category
  * @type Number
  */
Phonon.GameCategory = 0x4;

/**
  * @default 5
  * @constant
  * @memberOf Phonon
  * @name AccessibilityCategory
  * @see Phonon#Category
  * @type Number
  */
Phonon.AccessibilityCategory = 0x5;

/**
  * @constructor 
  * @memberOf Phonon
  * @name Category
  */
Phonon.Category = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf Phonon
  * @name AudioOutputDeviceType
  * @see Phonon#ObjectDescriptionType
  * @type Number
  */
Phonon.AudioOutputDeviceType = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf Phonon
  * @name EffectType
  * @see Phonon#ObjectDescriptionType
  * @type Number
  */
Phonon.EffectType = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf Phonon
  * @name AudioChannelType
  * @see Phonon#ObjectDescriptionType
  * @type Number
  */
Phonon.AudioChannelType = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf Phonon
  * @name SubtitleType
  * @see Phonon#ObjectDescriptionType
  * @type Number
  */
Phonon.SubtitleType = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf Phonon
  * @name AudioCaptureDeviceType
  * @see Phonon#ObjectDescriptionType
  * @type Number
  */
Phonon.AudioCaptureDeviceType = 0x4;

/**
  * @constructor 
  * @memberOf Phonon
  * @name ObjectDescriptionType
  */
Phonon.ObjectDescriptionType = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf Phonon
  * @name LoadingState
  * @see Phonon#State
  * @type Number
  */
Phonon.LoadingState = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf Phonon
  * @name StoppedState
  * @see Phonon#State
  * @type Number
  */
Phonon.StoppedState = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf Phonon
  * @name PlayingState
  * @see Phonon#State
  * @type Number
  */
Phonon.PlayingState = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf Phonon
  * @name BufferingState
  * @see Phonon#State
  * @type Number
  */
Phonon.BufferingState = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf Phonon
  * @name PausedState
  * @see Phonon#State
  * @type Number
  */
Phonon.PausedState = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf Phonon
  * @name ErrorState
  * @see Phonon#State
  * @type Number
  */
Phonon.ErrorState = 0x5;

/**
  * @constructor 
  * @memberOf Phonon
  * @name State
  */
Phonon.State = function(value){;};



/**
  * @default 0
  * @constant
  * @memberOf Phonon
  * @name NoError
  * @see Phonon#ErrorType
  * @type Number
  */
Phonon.NoError = 0x0;

/**
  * @default 1
  * @constant
  * @memberOf Phonon
  * @name NormalError
  * @see Phonon#ErrorType
  * @type Number
  */
Phonon.NormalError = 0x1;

/**
  * @default 2
  * @constant
  * @memberOf Phonon
  * @name FatalError
  * @see Phonon#ErrorType
  * @type Number
  */
Phonon.FatalError = 0x2;

/**
  * @constructor 
  * @memberOf Phonon
  * @name ErrorType
  */
Phonon.ErrorType = function(value){;};



