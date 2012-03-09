/**
  * @namespace QSsl from package com.trolltech.qt.network
  */
var QSsl = {};

/**
  * @default 0x0
  * @constant
  * @memberOf QSsl
  * @name PrivateKey
  * @see QSsl#KeyType
  * @type Number
  */
QSsl.PrivateKey = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QSsl
  * @name PublicKey
  * @see QSsl#KeyType
  * @type Number
  */
QSsl.PublicKey = 0x1;

/**
  * @constructor 
  * @memberOf QSsl
  * @name KeyType
  */
QSsl.KeyType = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QSsl
  * @name Rsa
  * @see QSsl#KeyAlgorithm
  * @type Number
  */
QSsl.Rsa = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QSsl
  * @name Dsa
  * @see QSsl#KeyAlgorithm
  * @type Number
  */
QSsl.Dsa = 0x1;

/**
  * @constructor 
  * @memberOf QSsl
  * @name KeyAlgorithm
  */
QSsl.KeyAlgorithm = function(value){;};



/**
  * @default -1
  * @constant
  * @memberOf QSsl
  * @name UnknownProtocol
  * @see QSsl#SslProtocol
  * @type Number
  */
QSsl.UnknownProtocol = 0xffffffff;

/**
  * @default 0x0
  * @constant
  * @memberOf QSsl
  * @name SslV3
  * @see QSsl#SslProtocol
  * @type Number
  */
QSsl.SslV3 = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QSsl
  * @name SslV2
  * @see QSsl#SslProtocol
  * @type Number
  */
QSsl.SslV2 = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QSsl
  * @name TlsV1
  * @see QSsl#SslProtocol
  * @type Number
  */
QSsl.TlsV1 = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QSsl
  * @name AnyProtocol
  * @see QSsl#SslProtocol
  * @type Number
  */
QSsl.AnyProtocol = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QSsl
  * @name TlsV1SslV3
  * @see QSsl#SslProtocol
  * @type Number
  */
QSsl.TlsV1SslV3 = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QSsl
  * @name SecureProtocols
  * @see QSsl#SslProtocol
  * @type Number
  */
QSsl.SecureProtocols = 0x5;

/**
  * @constructor 
  * @memberOf QSsl
  * @name SslProtocol
  */
QSsl.SslProtocol = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QSsl
  * @name EmailEntry
  * @see QSsl#AlternateNameEntryType
  * @type Number
  */
QSsl.EmailEntry = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QSsl
  * @name DnsEntry
  * @see QSsl#AlternateNameEntryType
  * @type Number
  */
QSsl.DnsEntry = 0x1;

/**
  * @constructor 
  * @memberOf QSsl
  * @name AlternateNameEntryType
  */
QSsl.AlternateNameEntryType = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QSsl
  * @name Pem
  * @see QSsl#EncodingFormat
  * @type Number
  */
QSsl.Pem = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QSsl
  * @name Der
  * @see QSsl#EncodingFormat
  * @type Number
  */
QSsl.Der = 0x1;

/**
  * @constructor 
  * @memberOf QSsl
  * @name EncodingFormat
  */
QSsl.EncodingFormat = function(value){;};



