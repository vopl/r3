/**
  * @name QLocale
  * @constructor
  */
function QLocale(){return undefined;};

/**
  * @name QLocale^1
  * @constructor
  * @param {QLocale.Language} language
  * @param {QLocale.Country} country
  */
function QLocale(language, country){return undefined;};

/**
  * @name QLocale^2
  * @constructor
  * @param {QLocale} other
  */
function QLocale(other){return undefined;};

/**
  * @name QLocale^3
  * @constructor
  * @param {String} name
  */
function QLocale(name){return undefined;};

/**
  * @name c
  * @function
  * @memberOf QLocale
  * @returns {QLocale}
  */
QLocale.c = function(){return new QLocale();};

/**
  * @name countriesForLanguage
  * @function
  * @memberOf QLocale
  * @param {QLocale.Language} lang
  * @returns {Array}
  */
QLocale.countriesForLanguage = function(lang){return new Array();};

/**
  * @name countryToString
  * @function
  * @memberOf QLocale
  * @param {QLocale.Country} country
  * @returns {String}
  */
QLocale.countryToString = function(country){return new String();};

/**
  * @name languageToString
  * @function
  * @memberOf QLocale
  * @param {QLocale.Language} language
  * @returns {String}
  */
QLocale.languageToString = function(language){return new String();};

/**
  * @name setDefault
  * @function
  * @memberOf QLocale
  * @param {QLocale} locale
  * @returns {undefined}
  */
QLocale.setDefault = function(locale){return undefined;};

/**
  * @name system
  * @function
  * @memberOf QLocale
  * @returns {QLocale}
  */
QLocale.system = function(){return new QLocale();};

/**
  * @default 0x0
  * @constant
  * @memberOf QLocale
  * @name MetricSystem
  * @see QLocale#MeasurementSystem
  * @type Number
  */
QLocale.MetricSystem = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QLocale
  * @name ImperialSystem
  * @see QLocale#MeasurementSystem
  * @type Number
  */
QLocale.ImperialSystem = 0x1;

/**
  * @constructor 
  * @memberOf QLocale
  * @name MeasurementSystem
  */
QLocale.MeasurementSystem = function(value){;};



/**
  * @default 0x01
  * @constant
  * @memberOf QLocale
  * @name OmitGroupSeparator
  * @see QLocale#NumberOptions
  * @see QLocale#NumberOption
  * @type Number
  */
QLocale.OmitGroupSeparator = 0x1;

/**
  * @default 0x02
  * @constant
  * @memberOf QLocale
  * @name RejectGroupSeparator
  * @see QLocale#NumberOptions
  * @see QLocale#NumberOption
  * @type Number
  */
QLocale.RejectGroupSeparator = 0x2;

/**
  * @constructor 
  * @memberOf QLocale
  * @name NumberOption
  */
QLocale.NumberOption = function(value){;};

/**
  * @constructor 
  * @memberOf QLocale
  * @name NumberOptions
  */
QLocale.NumberOptions = function(value1, value2 /*, ...*/){;};


/**
  * @default 0x0
  * @constant
  * @memberOf QLocale
  * @name LongFormat
  * @see QLocale#FormatType
  * @type Number
  */
QLocale.LongFormat = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QLocale
  * @name ShortFormat
  * @see QLocale#FormatType
  * @type Number
  */
QLocale.ShortFormat = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QLocale
  * @name NarrowFormat
  * @see QLocale#FormatType
  * @type Number
  */
QLocale.NarrowFormat = 0x2;

/**
  * @constructor 
  * @memberOf QLocale
  * @name FormatType
  */
QLocale.FormatType = function(value){;};



/**
  * @default 0
  * @constant
  * @memberOf QLocale
  * @name AnyCountry
  * @see QLocale#Country
  * @type Number
  */
QLocale.AnyCountry = 0x0;

/**
  * @default 1
  * @constant
  * @memberOf QLocale
  * @name Afghanistan
  * @see QLocale#Country
  * @type Number
  */
QLocale.Afghanistan = 0x1;

/**
  * @default 2
  * @constant
  * @memberOf QLocale
  * @name Albania
  * @see QLocale#Country
  * @type Number
  */
QLocale.Albania = 0x2;

/**
  * @default 3
  * @constant
  * @memberOf QLocale
  * @name Algeria
  * @see QLocale#Country
  * @type Number
  */
QLocale.Algeria = 0x3;

/**
  * @default 4
  * @constant
  * @memberOf QLocale
  * @name AmericanSamoa
  * @see QLocale#Country
  * @type Number
  */
QLocale.AmericanSamoa = 0x4;

/**
  * @default 5
  * @constant
  * @memberOf QLocale
  * @name Andorra
  * @see QLocale#Country
  * @type Number
  */
QLocale.Andorra = 0x5;

/**
  * @default 6
  * @constant
  * @memberOf QLocale
  * @name Angola
  * @see QLocale#Country
  * @type Number
  */
QLocale.Angola = 0x6;

/**
  * @default 7
  * @constant
  * @memberOf QLocale
  * @name Anguilla
  * @see QLocale#Country
  * @type Number
  */
QLocale.Anguilla = 0x7;

/**
  * @default 8
  * @constant
  * @memberOf QLocale
  * @name Antarctica
  * @see QLocale#Country
  * @type Number
  */
QLocale.Antarctica = 0x8;

/**
  * @default 9
  * @constant
  * @memberOf QLocale
  * @name AntiguaAndBarbuda
  * @see QLocale#Country
  * @type Number
  */
QLocale.AntiguaAndBarbuda = 0x9;

/**
  * @default 10
  * @constant
  * @memberOf QLocale
  * @name Argentina
  * @see QLocale#Country
  * @type Number
  */
QLocale.Argentina = 0xa;

/**
  * @default 11
  * @constant
  * @memberOf QLocale
  * @name Armenia
  * @see QLocale#Country
  * @type Number
  */
QLocale.Armenia = 0xb;

/**
  * @default 12
  * @constant
  * @memberOf QLocale
  * @name Aruba
  * @see QLocale#Country
  * @type Number
  */
QLocale.Aruba = 0xc;

/**
  * @default 13
  * @constant
  * @memberOf QLocale
  * @name Australia
  * @see QLocale#Country
  * @type Number
  */
QLocale.Australia = 0xd;

/**
  * @default 14
  * @constant
  * @memberOf QLocale
  * @name Austria
  * @see QLocale#Country
  * @type Number
  */
QLocale.Austria = 0xe;

/**
  * @default 15
  * @constant
  * @memberOf QLocale
  * @name Azerbaijan
  * @see QLocale#Country
  * @type Number
  */
QLocale.Azerbaijan = 0xf;

/**
  * @default 16
  * @constant
  * @memberOf QLocale
  * @name Bahamas
  * @see QLocale#Country
  * @type Number
  */
QLocale.Bahamas = 0x10;

/**
  * @default 17
  * @constant
  * @memberOf QLocale
  * @name Bahrain
  * @see QLocale#Country
  * @type Number
  */
QLocale.Bahrain = 0x11;

/**
  * @default 18
  * @constant
  * @memberOf QLocale
  * @name Bangladesh
  * @see QLocale#Country
  * @type Number
  */
QLocale.Bangladesh = 0x12;

/**
  * @default 19
  * @constant
  * @memberOf QLocale
  * @name Barbados
  * @see QLocale#Country
  * @type Number
  */
QLocale.Barbados = 0x13;

/**
  * @default 20
  * @constant
  * @memberOf QLocale
  * @name Belarus
  * @see QLocale#Country
  * @type Number
  */
QLocale.Belarus = 0x14;

/**
  * @default 21
  * @constant
  * @memberOf QLocale
  * @name Belgium
  * @see QLocale#Country
  * @type Number
  */
QLocale.Belgium = 0x15;

/**
  * @default 22
  * @constant
  * @memberOf QLocale
  * @name Belize
  * @see QLocale#Country
  * @type Number
  */
QLocale.Belize = 0x16;

/**
  * @default 23
  * @constant
  * @memberOf QLocale
  * @name Benin
  * @see QLocale#Country
  * @type Number
  */
QLocale.Benin = 0x17;

/**
  * @default 24
  * @constant
  * @memberOf QLocale
  * @name Bermuda
  * @see QLocale#Country
  * @type Number
  */
QLocale.Bermuda = 0x18;

/**
  * @default 25
  * @constant
  * @memberOf QLocale
  * @name Bhutan
  * @see QLocale#Country
  * @type Number
  */
QLocale.Bhutan = 0x19;

/**
  * @default 26
  * @constant
  * @memberOf QLocale
  * @name Bolivia
  * @see QLocale#Country
  * @type Number
  */
QLocale.Bolivia = 0x1a;

/**
  * @default 27
  * @constant
  * @memberOf QLocale
  * @name BosniaAndHerzegowina
  * @see QLocale#Country
  * @type Number
  */
QLocale.BosniaAndHerzegowina = 0x1b;

/**
  * @default 28
  * @constant
  * @memberOf QLocale
  * @name Botswana
  * @see QLocale#Country
  * @type Number
  */
QLocale.Botswana = 0x1c;

/**
  * @default 29
  * @constant
  * @memberOf QLocale
  * @name BouvetIsland
  * @see QLocale#Country
  * @type Number
  */
QLocale.BouvetIsland = 0x1d;

/**
  * @default 30
  * @constant
  * @memberOf QLocale
  * @name Brazil
  * @see QLocale#Country
  * @type Number
  */
QLocale.Brazil = 0x1e;

/**
  * @default 31
  * @constant
  * @memberOf QLocale
  * @name BritishIndianOceanTerritory
  * @see QLocale#Country
  * @type Number
  */
QLocale.BritishIndianOceanTerritory = 0x1f;

/**
  * @default 32
  * @constant
  * @memberOf QLocale
  * @name BruneiDarussalam
  * @see QLocale#Country
  * @type Number
  */
QLocale.BruneiDarussalam = 0x20;

/**
  * @default 33
  * @constant
  * @memberOf QLocale
  * @name Bulgaria
  * @see QLocale#Country
  * @type Number
  */
QLocale.Bulgaria = 0x21;

/**
  * @default 34
  * @constant
  * @memberOf QLocale
  * @name BurkinaFaso
  * @see QLocale#Country
  * @type Number
  */
QLocale.BurkinaFaso = 0x22;

/**
  * @default 35
  * @constant
  * @memberOf QLocale
  * @name Burundi
  * @see QLocale#Country
  * @type Number
  */
QLocale.Burundi = 0x23;

/**
  * @default 36
  * @constant
  * @memberOf QLocale
  * @name Cambodia
  * @see QLocale#Country
  * @type Number
  */
QLocale.Cambodia = 0x24;

/**
  * @default 37
  * @constant
  * @memberOf QLocale
  * @name Cameroon
  * @see QLocale#Country
  * @type Number
  */
QLocale.Cameroon = 0x25;

/**
  * @default 38
  * @constant
  * @memberOf QLocale
  * @name Canada
  * @see QLocale#Country
  * @type Number
  */
QLocale.Canada = 0x26;

/**
  * @default 39
  * @constant
  * @memberOf QLocale
  * @name CapeVerde
  * @see QLocale#Country
  * @type Number
  */
QLocale.CapeVerde = 0x27;

/**
  * @default 40
  * @constant
  * @memberOf QLocale
  * @name CaymanIslands
  * @see QLocale#Country
  * @type Number
  */
QLocale.CaymanIslands = 0x28;

/**
  * @default 41
  * @constant
  * @memberOf QLocale
  * @name CentralAfricanRepublic
  * @see QLocale#Country
  * @type Number
  */
QLocale.CentralAfricanRepublic = 0x29;

/**
  * @default 42
  * @constant
  * @memberOf QLocale
  * @name Chad
  * @see QLocale#Country
  * @type Number
  */
QLocale.Chad = 0x2a;

/**
  * @default 43
  * @constant
  * @memberOf QLocale
  * @name Chile
  * @see QLocale#Country
  * @type Number
  */
QLocale.Chile = 0x2b;

/**
  * @default 44
  * @constant
  * @memberOf QLocale
  * @name China
  * @see QLocale#Country
  * @type Number
  */
QLocale.China = 0x2c;

/**
  * @default 45
  * @constant
  * @memberOf QLocale
  * @name ChristmasIsland
  * @see QLocale#Country
  * @type Number
  */
QLocale.ChristmasIsland = 0x2d;

/**
  * @default 46
  * @constant
  * @memberOf QLocale
  * @name CocosIslands
  * @see QLocale#Country
  * @type Number
  */
QLocale.CocosIslands = 0x2e;

/**
  * @default 47
  * @constant
  * @memberOf QLocale
  * @name Colombia
  * @see QLocale#Country
  * @type Number
  */
QLocale.Colombia = 0x2f;

/**
  * @default 48
  * @constant
  * @memberOf QLocale
  * @name Comoros
  * @see QLocale#Country
  * @type Number
  */
QLocale.Comoros = 0x30;

/**
  * @default 49
  * @constant
  * @memberOf QLocale
  * @name DemocraticRepublicOfCongo
  * @see QLocale#Country
  * @type Number
  */
QLocale.DemocraticRepublicOfCongo = 0x31;

/**
  * @default 50
  * @constant
  * @memberOf QLocale
  * @name PeoplesRepublicOfCongo
  * @see QLocale#Country
  * @type Number
  */
QLocale.PeoplesRepublicOfCongo = 0x32;

/**
  * @default 51
  * @constant
  * @memberOf QLocale
  * @name CookIslands
  * @see QLocale#Country
  * @type Number
  */
QLocale.CookIslands = 0x33;

/**
  * @default 52
  * @constant
  * @memberOf QLocale
  * @name CostaRica
  * @see QLocale#Country
  * @type Number
  */
QLocale.CostaRica = 0x34;

/**
  * @default 53
  * @constant
  * @memberOf QLocale
  * @name IvoryCoast
  * @see QLocale#Country
  * @type Number
  */
QLocale.IvoryCoast = 0x35;

/**
  * @default 54
  * @constant
  * @memberOf QLocale
  * @name Croatia
  * @see QLocale#Country
  * @type Number
  */
QLocale.Croatia = 0x36;

/**
  * @default 55
  * @constant
  * @memberOf QLocale
  * @name Cuba
  * @see QLocale#Country
  * @type Number
  */
QLocale.Cuba = 0x37;

/**
  * @default 56
  * @constant
  * @memberOf QLocale
  * @name Cyprus
  * @see QLocale#Country
  * @type Number
  */
QLocale.Cyprus = 0x38;

/**
  * @default 57
  * @constant
  * @memberOf QLocale
  * @name CzechRepublic
  * @see QLocale#Country
  * @type Number
  */
QLocale.CzechRepublic = 0x39;

/**
  * @default 58
  * @constant
  * @memberOf QLocale
  * @name Denmark
  * @see QLocale#Country
  * @type Number
  */
QLocale.Denmark = 0x3a;

/**
  * @default 59
  * @constant
  * @memberOf QLocale
  * @name Djibouti
  * @see QLocale#Country
  * @type Number
  */
QLocale.Djibouti = 0x3b;

/**
  * @default 60
  * @constant
  * @memberOf QLocale
  * @name Dominica
  * @see QLocale#Country
  * @type Number
  */
QLocale.Dominica = 0x3c;

/**
  * @default 61
  * @constant
  * @memberOf QLocale
  * @name DominicanRepublic
  * @see QLocale#Country
  * @type Number
  */
QLocale.DominicanRepublic = 0x3d;

/**
  * @default 62
  * @constant
  * @memberOf QLocale
  * @name EastTimor
  * @see QLocale#Country
  * @type Number
  */
QLocale.EastTimor = 0x3e;

/**
  * @default 63
  * @constant
  * @memberOf QLocale
  * @name Ecuador
  * @see QLocale#Country
  * @type Number
  */
QLocale.Ecuador = 0x3f;

/**
  * @default 64
  * @constant
  * @memberOf QLocale
  * @name Egypt
  * @see QLocale#Country
  * @type Number
  */
QLocale.Egypt = 0x40;

/**
  * @default 65
  * @constant
  * @memberOf QLocale
  * @name ElSalvador
  * @see QLocale#Country
  * @type Number
  */
QLocale.ElSalvador = 0x41;

/**
  * @default 66
  * @constant
  * @memberOf QLocale
  * @name EquatorialGuinea
  * @see QLocale#Country
  * @type Number
  */
QLocale.EquatorialGuinea = 0x42;

/**
  * @default 67
  * @constant
  * @memberOf QLocale
  * @name Eritrea
  * @see QLocale#Country
  * @type Number
  */
QLocale.Eritrea = 0x43;

/**
  * @default 68
  * @constant
  * @memberOf QLocale
  * @name Estonia
  * @see QLocale#Country
  * @type Number
  */
QLocale.Estonia = 0x44;

/**
  * @default 69
  * @constant
  * @memberOf QLocale
  * @name Ethiopia
  * @see QLocale#Country
  * @type Number
  */
QLocale.Ethiopia = 0x45;

/**
  * @default 70
  * @constant
  * @memberOf QLocale
  * @name FalklandIslands
  * @see QLocale#Country
  * @type Number
  */
QLocale.FalklandIslands = 0x46;

/**
  * @default 71
  * @constant
  * @memberOf QLocale
  * @name FaroeIslands
  * @see QLocale#Country
  * @type Number
  */
QLocale.FaroeIslands = 0x47;

/**
  * @default 72
  * @constant
  * @memberOf QLocale
  * @name FijiCountry
  * @see QLocale#Country
  * @type Number
  */
QLocale.FijiCountry = 0x48;

/**
  * @default 73
  * @constant
  * @memberOf QLocale
  * @name Finland
  * @see QLocale#Country
  * @type Number
  */
QLocale.Finland = 0x49;

/**
  * @default 74
  * @constant
  * @memberOf QLocale
  * @name France
  * @see QLocale#Country
  * @type Number
  */
QLocale.France = 0x4a;

/**
  * @default 75
  * @constant
  * @memberOf QLocale
  * @name MetropolitanFrance
  * @see QLocale#Country
  * @type Number
  */
QLocale.MetropolitanFrance = 0x4b;

/**
  * @default 76
  * @constant
  * @memberOf QLocale
  * @name FrenchGuiana
  * @see QLocale#Country
  * @type Number
  */
QLocale.FrenchGuiana = 0x4c;

/**
  * @default 77
  * @constant
  * @memberOf QLocale
  * @name FrenchPolynesia
  * @see QLocale#Country
  * @type Number
  */
QLocale.FrenchPolynesia = 0x4d;

/**
  * @default 78
  * @constant
  * @memberOf QLocale
  * @name FrenchSouthernTerritories
  * @see QLocale#Country
  * @type Number
  */
QLocale.FrenchSouthernTerritories = 0x4e;

/**
  * @default 79
  * @constant
  * @memberOf QLocale
  * @name Gabon
  * @see QLocale#Country
  * @type Number
  */
QLocale.Gabon = 0x4f;

/**
  * @default 80
  * @constant
  * @memberOf QLocale
  * @name Gambia
  * @see QLocale#Country
  * @type Number
  */
QLocale.Gambia = 0x50;

/**
  * @default 81
  * @constant
  * @memberOf QLocale
  * @name Georgia
  * @see QLocale#Country
  * @type Number
  */
QLocale.Georgia = 0x51;

/**
  * @default 82
  * @constant
  * @memberOf QLocale
  * @name Germany
  * @see QLocale#Country
  * @type Number
  */
QLocale.Germany = 0x52;

/**
  * @default 83
  * @constant
  * @memberOf QLocale
  * @name Ghana
  * @see QLocale#Country
  * @type Number
  */
QLocale.Ghana = 0x53;

/**
  * @default 84
  * @constant
  * @memberOf QLocale
  * @name Gibraltar
  * @see QLocale#Country
  * @type Number
  */
QLocale.Gibraltar = 0x54;

/**
  * @default 85
  * @constant
  * @memberOf QLocale
  * @name Greece
  * @see QLocale#Country
  * @type Number
  */
QLocale.Greece = 0x55;

/**
  * @default 86
  * @constant
  * @memberOf QLocale
  * @name Greenland
  * @see QLocale#Country
  * @type Number
  */
QLocale.Greenland = 0x56;

/**
  * @default 87
  * @constant
  * @memberOf QLocale
  * @name Grenada
  * @see QLocale#Country
  * @type Number
  */
QLocale.Grenada = 0x57;

/**
  * @default 88
  * @constant
  * @memberOf QLocale
  * @name Guadeloupe
  * @see QLocale#Country
  * @type Number
  */
QLocale.Guadeloupe = 0x58;

/**
  * @default 89
  * @constant
  * @memberOf QLocale
  * @name Guam
  * @see QLocale#Country
  * @type Number
  */
QLocale.Guam = 0x59;

/**
  * @default 90
  * @constant
  * @memberOf QLocale
  * @name Guatemala
  * @see QLocale#Country
  * @type Number
  */
QLocale.Guatemala = 0x5a;

/**
  * @default 91
  * @constant
  * @memberOf QLocale
  * @name Guinea
  * @see QLocale#Country
  * @type Number
  */
QLocale.Guinea = 0x5b;

/**
  * @default 92
  * @constant
  * @memberOf QLocale
  * @name GuineaBissau
  * @see QLocale#Country
  * @type Number
  */
QLocale.GuineaBissau = 0x5c;

/**
  * @default 93
  * @constant
  * @memberOf QLocale
  * @name Guyana
  * @see QLocale#Country
  * @type Number
  */
QLocale.Guyana = 0x5d;

/**
  * @default 94
  * @constant
  * @memberOf QLocale
  * @name Haiti
  * @see QLocale#Country
  * @type Number
  */
QLocale.Haiti = 0x5e;

/**
  * @default 95
  * @constant
  * @memberOf QLocale
  * @name HeardAndMcDonaldIslands
  * @see QLocale#Country
  * @type Number
  */
QLocale.HeardAndMcDonaldIslands = 0x5f;

/**
  * @default 96
  * @constant
  * @memberOf QLocale
  * @name Honduras
  * @see QLocale#Country
  * @type Number
  */
QLocale.Honduras = 0x60;

/**
  * @default 97
  * @constant
  * @memberOf QLocale
  * @name HongKong
  * @see QLocale#Country
  * @type Number
  */
QLocale.HongKong = 0x61;

/**
  * @default 98
  * @constant
  * @memberOf QLocale
  * @name Hungary
  * @see QLocale#Country
  * @type Number
  */
QLocale.Hungary = 0x62;

/**
  * @default 99
  * @constant
  * @memberOf QLocale
  * @name Iceland
  * @see QLocale#Country
  * @type Number
  */
QLocale.Iceland = 0x63;

/**
  * @default 100
  * @constant
  * @memberOf QLocale
  * @name India
  * @see QLocale#Country
  * @type Number
  */
QLocale.India = 0x64;

/**
  * @default 101
  * @constant
  * @memberOf QLocale
  * @name Indonesia
  * @see QLocale#Country
  * @type Number
  */
QLocale.Indonesia = 0x65;

/**
  * @default 102
  * @constant
  * @memberOf QLocale
  * @name Iran
  * @see QLocale#Country
  * @type Number
  */
QLocale.Iran = 0x66;

/**
  * @default 103
  * @constant
  * @memberOf QLocale
  * @name Iraq
  * @see QLocale#Country
  * @type Number
  */
QLocale.Iraq = 0x67;

/**
  * @default 104
  * @constant
  * @memberOf QLocale
  * @name Ireland
  * @see QLocale#Country
  * @type Number
  */
QLocale.Ireland = 0x68;

/**
  * @default 105
  * @constant
  * @memberOf QLocale
  * @name Israel
  * @see QLocale#Country
  * @type Number
  */
QLocale.Israel = 0x69;

/**
  * @default 106
  * @constant
  * @memberOf QLocale
  * @name Italy
  * @see QLocale#Country
  * @type Number
  */
QLocale.Italy = 0x6a;

/**
  * @default 107
  * @constant
  * @memberOf QLocale
  * @name Jamaica
  * @see QLocale#Country
  * @type Number
  */
QLocale.Jamaica = 0x6b;

/**
  * @default 108
  * @constant
  * @memberOf QLocale
  * @name Japan
  * @see QLocale#Country
  * @type Number
  */
QLocale.Japan = 0x6c;

/**
  * @default 109
  * @constant
  * @memberOf QLocale
  * @name Jordan
  * @see QLocale#Country
  * @type Number
  */
QLocale.Jordan = 0x6d;

/**
  * @default 110
  * @constant
  * @memberOf QLocale
  * @name Kazakhstan
  * @see QLocale#Country
  * @type Number
  */
QLocale.Kazakhstan = 0x6e;

/**
  * @default 111
  * @constant
  * @memberOf QLocale
  * @name Kenya
  * @see QLocale#Country
  * @type Number
  */
QLocale.Kenya = 0x6f;

/**
  * @default 112
  * @constant
  * @memberOf QLocale
  * @name Kiribati
  * @see QLocale#Country
  * @type Number
  */
QLocale.Kiribati = 0x70;

/**
  * @default 113
  * @constant
  * @memberOf QLocale
  * @name DemocraticRepublicOfKorea
  * @see QLocale#Country
  * @type Number
  */
QLocale.DemocraticRepublicOfKorea = 0x71;

/**
  * @default 114
  * @constant
  * @memberOf QLocale
  * @name RepublicOfKorea
  * @see QLocale#Country
  * @type Number
  */
QLocale.RepublicOfKorea = 0x72;

/**
  * @default 115
  * @constant
  * @memberOf QLocale
  * @name Kuwait
  * @see QLocale#Country
  * @type Number
  */
QLocale.Kuwait = 0x73;

/**
  * @default 116
  * @constant
  * @memberOf QLocale
  * @name Kyrgyzstan
  * @see QLocale#Country
  * @type Number
  */
QLocale.Kyrgyzstan = 0x74;

/**
  * @default 117
  * @constant
  * @memberOf QLocale
  * @name Lao
  * @see QLocale#Country
  * @type Number
  */
QLocale.Lao = 0x75;

/**
  * @default 118
  * @constant
  * @memberOf QLocale
  * @name Latvia
  * @see QLocale#Country
  * @type Number
  */
QLocale.Latvia = 0x76;

/**
  * @default 119
  * @constant
  * @memberOf QLocale
  * @name Lebanon
  * @see QLocale#Country
  * @type Number
  */
QLocale.Lebanon = 0x77;

/**
  * @default 120
  * @constant
  * @memberOf QLocale
  * @name Lesotho
  * @see QLocale#Country
  * @type Number
  */
QLocale.Lesotho = 0x78;

/**
  * @default 121
  * @constant
  * @memberOf QLocale
  * @name Liberia
  * @see QLocale#Country
  * @type Number
  */
QLocale.Liberia = 0x79;

/**
  * @default 122
  * @constant
  * @memberOf QLocale
  * @name LibyanArabJamahiriya
  * @see QLocale#Country
  * @type Number
  */
QLocale.LibyanArabJamahiriya = 0x7a;

/**
  * @default 123
  * @constant
  * @memberOf QLocale
  * @name Liechtenstein
  * @see QLocale#Country
  * @type Number
  */
QLocale.Liechtenstein = 0x7b;

/**
  * @default 124
  * @constant
  * @memberOf QLocale
  * @name Lithuania
  * @see QLocale#Country
  * @type Number
  */
QLocale.Lithuania = 0x7c;

/**
  * @default 125
  * @constant
  * @memberOf QLocale
  * @name Luxembourg
  * @see QLocale#Country
  * @type Number
  */
QLocale.Luxembourg = 0x7d;

/**
  * @default 126
  * @constant
  * @memberOf QLocale
  * @name Macau
  * @see QLocale#Country
  * @type Number
  */
QLocale.Macau = 0x7e;

/**
  * @default 127
  * @constant
  * @memberOf QLocale
  * @name Macedonia
  * @see QLocale#Country
  * @type Number
  */
QLocale.Macedonia = 0x7f;

/**
  * @default 128
  * @constant
  * @memberOf QLocale
  * @name Madagascar
  * @see QLocale#Country
  * @type Number
  */
QLocale.Madagascar = 0x80;

/**
  * @default 129
  * @constant
  * @memberOf QLocale
  * @name Malawi
  * @see QLocale#Country
  * @type Number
  */
QLocale.Malawi = 0x81;

/**
  * @default 130
  * @constant
  * @memberOf QLocale
  * @name Malaysia
  * @see QLocale#Country
  * @type Number
  */
QLocale.Malaysia = 0x82;

/**
  * @default 131
  * @constant
  * @memberOf QLocale
  * @name Maldives
  * @see QLocale#Country
  * @type Number
  */
QLocale.Maldives = 0x83;

/**
  * @default 132
  * @constant
  * @memberOf QLocale
  * @name Mali
  * @see QLocale#Country
  * @type Number
  */
QLocale.Mali = 0x84;

/**
  * @default 133
  * @constant
  * @memberOf QLocale
  * @name Malta
  * @see QLocale#Country
  * @type Number
  */
QLocale.Malta = 0x85;

/**
  * @default 134
  * @constant
  * @memberOf QLocale
  * @name MarshallIslands
  * @see QLocale#Country
  * @type Number
  */
QLocale.MarshallIslands = 0x86;

/**
  * @default 135
  * @constant
  * @memberOf QLocale
  * @name Martinique
  * @see QLocale#Country
  * @type Number
  */
QLocale.Martinique = 0x87;

/**
  * @default 136
  * @constant
  * @memberOf QLocale
  * @name Mauritania
  * @see QLocale#Country
  * @type Number
  */
QLocale.Mauritania = 0x88;

/**
  * @default 137
  * @constant
  * @memberOf QLocale
  * @name Mauritius
  * @see QLocale#Country
  * @type Number
  */
QLocale.Mauritius = 0x89;

/**
  * @default 138
  * @constant
  * @memberOf QLocale
  * @name Mayotte
  * @see QLocale#Country
  * @type Number
  */
QLocale.Mayotte = 0x8a;

/**
  * @default 139
  * @constant
  * @memberOf QLocale
  * @name Mexico
  * @see QLocale#Country
  * @type Number
  */
QLocale.Mexico = 0x8b;

/**
  * @default 140
  * @constant
  * @memberOf QLocale
  * @name Micronesia
  * @see QLocale#Country
  * @type Number
  */
QLocale.Micronesia = 0x8c;

/**
  * @default 141
  * @constant
  * @memberOf QLocale
  * @name Moldova
  * @see QLocale#Country
  * @type Number
  */
QLocale.Moldova = 0x8d;

/**
  * @default 142
  * @constant
  * @memberOf QLocale
  * @name Monaco
  * @see QLocale#Country
  * @type Number
  */
QLocale.Monaco = 0x8e;

/**
  * @default 143
  * @constant
  * @memberOf QLocale
  * @name Mongolia
  * @see QLocale#Country
  * @type Number
  */
QLocale.Mongolia = 0x8f;

/**
  * @default 144
  * @constant
  * @memberOf QLocale
  * @name Montserrat
  * @see QLocale#Country
  * @type Number
  */
QLocale.Montserrat = 0x90;

/**
  * @default 145
  * @constant
  * @memberOf QLocale
  * @name Morocco
  * @see QLocale#Country
  * @type Number
  */
QLocale.Morocco = 0x91;

/**
  * @default 146
  * @constant
  * @memberOf QLocale
  * @name Mozambique
  * @see QLocale#Country
  * @type Number
  */
QLocale.Mozambique = 0x92;

/**
  * @default 147
  * @constant
  * @memberOf QLocale
  * @name Myanmar
  * @see QLocale#Country
  * @type Number
  */
QLocale.Myanmar = 0x93;

/**
  * @default 148
  * @constant
  * @memberOf QLocale
  * @name Namibia
  * @see QLocale#Country
  * @type Number
  */
QLocale.Namibia = 0x94;

/**
  * @default 149
  * @constant
  * @memberOf QLocale
  * @name NauruCountry
  * @see QLocale#Country
  * @type Number
  */
QLocale.NauruCountry = 0x95;

/**
  * @default 150
  * @constant
  * @memberOf QLocale
  * @name Nepal
  * @see QLocale#Country
  * @type Number
  */
QLocale.Nepal = 0x96;

/**
  * @default 151
  * @constant
  * @memberOf QLocale
  * @name Netherlands
  * @see QLocale#Country
  * @type Number
  */
QLocale.Netherlands = 0x97;

/**
  * @default 152
  * @constant
  * @memberOf QLocale
  * @name NetherlandsAntilles
  * @see QLocale#Country
  * @type Number
  */
QLocale.NetherlandsAntilles = 0x98;

/**
  * @default 153
  * @constant
  * @memberOf QLocale
  * @name NewCaledonia
  * @see QLocale#Country
  * @type Number
  */
QLocale.NewCaledonia = 0x99;

/**
  * @default 154
  * @constant
  * @memberOf QLocale
  * @name NewZealand
  * @see QLocale#Country
  * @type Number
  */
QLocale.NewZealand = 0x9a;

/**
  * @default 155
  * @constant
  * @memberOf QLocale
  * @name Nicaragua
  * @see QLocale#Country
  * @type Number
  */
QLocale.Nicaragua = 0x9b;

/**
  * @default 156
  * @constant
  * @memberOf QLocale
  * @name Niger
  * @see QLocale#Country
  * @type Number
  */
QLocale.Niger = 0x9c;

/**
  * @default 157
  * @constant
  * @memberOf QLocale
  * @name Nigeria
  * @see QLocale#Country
  * @type Number
  */
QLocale.Nigeria = 0x9d;

/**
  * @default 158
  * @constant
  * @memberOf QLocale
  * @name Niue
  * @see QLocale#Country
  * @type Number
  */
QLocale.Niue = 0x9e;

/**
  * @default 159
  * @constant
  * @memberOf QLocale
  * @name NorfolkIsland
  * @see QLocale#Country
  * @type Number
  */
QLocale.NorfolkIsland = 0x9f;

/**
  * @default 160
  * @constant
  * @memberOf QLocale
  * @name NorthernMarianaIslands
  * @see QLocale#Country
  * @type Number
  */
QLocale.NorthernMarianaIslands = 0xa0;

/**
  * @default 161
  * @constant
  * @memberOf QLocale
  * @name Norway
  * @see QLocale#Country
  * @type Number
  */
QLocale.Norway = 0xa1;

/**
  * @default 162
  * @constant
  * @memberOf QLocale
  * @name Oman
  * @see QLocale#Country
  * @type Number
  */
QLocale.Oman = 0xa2;

/**
  * @default 163
  * @constant
  * @memberOf QLocale
  * @name Pakistan
  * @see QLocale#Country
  * @type Number
  */
QLocale.Pakistan = 0xa3;

/**
  * @default 164
  * @constant
  * @memberOf QLocale
  * @name Palau
  * @see QLocale#Country
  * @type Number
  */
QLocale.Palau = 0xa4;

/**
  * @default 165
  * @constant
  * @memberOf QLocale
  * @name PalestinianTerritory
  * @see QLocale#Country
  * @type Number
  */
QLocale.PalestinianTerritory = 0xa5;

/**
  * @default 166
  * @constant
  * @memberOf QLocale
  * @name Panama
  * @see QLocale#Country
  * @type Number
  */
QLocale.Panama = 0xa6;

/**
  * @default 167
  * @constant
  * @memberOf QLocale
  * @name PapuaNewGuinea
  * @see QLocale#Country
  * @type Number
  */
QLocale.PapuaNewGuinea = 0xa7;

/**
  * @default 168
  * @constant
  * @memberOf QLocale
  * @name Paraguay
  * @see QLocale#Country
  * @type Number
  */
QLocale.Paraguay = 0xa8;

/**
  * @default 169
  * @constant
  * @memberOf QLocale
  * @name Peru
  * @see QLocale#Country
  * @type Number
  */
QLocale.Peru = 0xa9;

/**
  * @default 170
  * @constant
  * @memberOf QLocale
  * @name Philippines
  * @see QLocale#Country
  * @type Number
  */
QLocale.Philippines = 0xaa;

/**
  * @default 171
  * @constant
  * @memberOf QLocale
  * @name Pitcairn
  * @see QLocale#Country
  * @type Number
  */
QLocale.Pitcairn = 0xab;

/**
  * @default 172
  * @constant
  * @memberOf QLocale
  * @name Poland
  * @see QLocale#Country
  * @type Number
  */
QLocale.Poland = 0xac;

/**
  * @default 173
  * @constant
  * @memberOf QLocale
  * @name Portugal
  * @see QLocale#Country
  * @type Number
  */
QLocale.Portugal = 0xad;

/**
  * @default 174
  * @constant
  * @memberOf QLocale
  * @name PuertoRico
  * @see QLocale#Country
  * @type Number
  */
QLocale.PuertoRico = 0xae;

/**
  * @default 175
  * @constant
  * @memberOf QLocale
  * @name Qatar
  * @see QLocale#Country
  * @type Number
  */
QLocale.Qatar = 0xaf;

/**
  * @default 176
  * @constant
  * @memberOf QLocale
  * @name Reunion
  * @see QLocale#Country
  * @type Number
  */
QLocale.Reunion = 0xb0;

/**
  * @default 177
  * @constant
  * @memberOf QLocale
  * @name Romania
  * @see QLocale#Country
  * @type Number
  */
QLocale.Romania = 0xb1;

/**
  * @default 178
  * @constant
  * @memberOf QLocale
  * @name RussianFederation
  * @see QLocale#Country
  * @type Number
  */
QLocale.RussianFederation = 0xb2;

/**
  * @default 179
  * @constant
  * @memberOf QLocale
  * @name Rwanda
  * @see QLocale#Country
  * @type Number
  */
QLocale.Rwanda = 0xb3;

/**
  * @default 180
  * @constant
  * @memberOf QLocale
  * @name SaintKittsAndNevis
  * @see QLocale#Country
  * @type Number
  */
QLocale.SaintKittsAndNevis = 0xb4;

/**
  * @default 181
  * @constant
  * @memberOf QLocale
  * @name StLucia
  * @see QLocale#Country
  * @type Number
  */
QLocale.StLucia = 0xb5;

/**
  * @default 182
  * @constant
  * @memberOf QLocale
  * @name StVincentAndTheGrenadines
  * @see QLocale#Country
  * @type Number
  */
QLocale.StVincentAndTheGrenadines = 0xb6;

/**
  * @default 183
  * @constant
  * @memberOf QLocale
  * @name Samoa
  * @see QLocale#Country
  * @type Number
  */
QLocale.Samoa = 0xb7;

/**
  * @default 184
  * @constant
  * @memberOf QLocale
  * @name SanMarino
  * @see QLocale#Country
  * @type Number
  */
QLocale.SanMarino = 0xb8;

/**
  * @default 185
  * @constant
  * @memberOf QLocale
  * @name SaoTomeAndPrincipe
  * @see QLocale#Country
  * @type Number
  */
QLocale.SaoTomeAndPrincipe = 0xb9;

/**
  * @default 186
  * @constant
  * @memberOf QLocale
  * @name SaudiArabia
  * @see QLocale#Country
  * @type Number
  */
QLocale.SaudiArabia = 0xba;

/**
  * @default 187
  * @constant
  * @memberOf QLocale
  * @name Senegal
  * @see QLocale#Country
  * @type Number
  */
QLocale.Senegal = 0xbb;

/**
  * @default 188
  * @constant
  * @memberOf QLocale
  * @name Seychelles
  * @see QLocale#Country
  * @type Number
  */
QLocale.Seychelles = 0xbc;

/**
  * @default 189
  * @constant
  * @memberOf QLocale
  * @name SierraLeone
  * @see QLocale#Country
  * @type Number
  */
QLocale.SierraLeone = 0xbd;

/**
  * @default 190
  * @constant
  * @memberOf QLocale
  * @name Singapore
  * @see QLocale#Country
  * @type Number
  */
QLocale.Singapore = 0xbe;

/**
  * @default 191
  * @constant
  * @memberOf QLocale
  * @name Slovakia
  * @see QLocale#Country
  * @type Number
  */
QLocale.Slovakia = 0xbf;

/**
  * @default 192
  * @constant
  * @memberOf QLocale
  * @name Slovenia
  * @see QLocale#Country
  * @type Number
  */
QLocale.Slovenia = 0xc0;

/**
  * @default 193
  * @constant
  * @memberOf QLocale
  * @name SolomonIslands
  * @see QLocale#Country
  * @type Number
  */
QLocale.SolomonIslands = 0xc1;

/**
  * @default 194
  * @constant
  * @memberOf QLocale
  * @name Somalia
  * @see QLocale#Country
  * @type Number
  */
QLocale.Somalia = 0xc2;

/**
  * @default 195
  * @constant
  * @memberOf QLocale
  * @name SouthAfrica
  * @see QLocale#Country
  * @type Number
  */
QLocale.SouthAfrica = 0xc3;

/**
  * @default 196
  * @constant
  * @memberOf QLocale
  * @name SouthGeorgiaAndTheSouthSandwichIslands
  * @see QLocale#Country
  * @type Number
  */
QLocale.SouthGeorgiaAndTheSouthSandwichIslands = 0xc4;

/**
  * @default 197
  * @constant
  * @memberOf QLocale
  * @name Spain
  * @see QLocale#Country
  * @type Number
  */
QLocale.Spain = 0xc5;

/**
  * @default 198
  * @constant
  * @memberOf QLocale
  * @name SriLanka
  * @see QLocale#Country
  * @type Number
  */
QLocale.SriLanka = 0xc6;

/**
  * @default 199
  * @constant
  * @memberOf QLocale
  * @name StHelena
  * @see QLocale#Country
  * @type Number
  */
QLocale.StHelena = 0xc7;

/**
  * @default 200
  * @constant
  * @memberOf QLocale
  * @name StPierreAndMiquelon
  * @see QLocale#Country
  * @type Number
  */
QLocale.StPierreAndMiquelon = 0xc8;

/**
  * @default 201
  * @constant
  * @memberOf QLocale
  * @name Sudan
  * @see QLocale#Country
  * @type Number
  */
QLocale.Sudan = 0xc9;

/**
  * @default 202
  * @constant
  * @memberOf QLocale
  * @name Suriname
  * @see QLocale#Country
  * @type Number
  */
QLocale.Suriname = 0xca;

/**
  * @default 203
  * @constant
  * @memberOf QLocale
  * @name SvalbardAndJanMayenIslands
  * @see QLocale#Country
  * @type Number
  */
QLocale.SvalbardAndJanMayenIslands = 0xcb;

/**
  * @default 204
  * @constant
  * @memberOf QLocale
  * @name Swaziland
  * @see QLocale#Country
  * @type Number
  */
QLocale.Swaziland = 0xcc;

/**
  * @default 205
  * @constant
  * @memberOf QLocale
  * @name Sweden
  * @see QLocale#Country
  * @type Number
  */
QLocale.Sweden = 0xcd;

/**
  * @default 206
  * @constant
  * @memberOf QLocale
  * @name Switzerland
  * @see QLocale#Country
  * @type Number
  */
QLocale.Switzerland = 0xce;

/**
  * @default 207
  * @constant
  * @memberOf QLocale
  * @name SyrianArabRepublic
  * @see QLocale#Country
  * @type Number
  */
QLocale.SyrianArabRepublic = 0xcf;

/**
  * @default 208
  * @constant
  * @memberOf QLocale
  * @name Taiwan
  * @see QLocale#Country
  * @type Number
  */
QLocale.Taiwan = 0xd0;

/**
  * @default 209
  * @constant
  * @memberOf QLocale
  * @name Tajikistan
  * @see QLocale#Country
  * @type Number
  */
QLocale.Tajikistan = 0xd1;

/**
  * @default 210
  * @constant
  * @memberOf QLocale
  * @name Tanzania
  * @see QLocale#Country
  * @type Number
  */
QLocale.Tanzania = 0xd2;

/**
  * @default 211
  * @constant
  * @memberOf QLocale
  * @name Thailand
  * @see QLocale#Country
  * @type Number
  */
QLocale.Thailand = 0xd3;

/**
  * @default 212
  * @constant
  * @memberOf QLocale
  * @name Togo
  * @see QLocale#Country
  * @type Number
  */
QLocale.Togo = 0xd4;

/**
  * @default 213
  * @constant
  * @memberOf QLocale
  * @name Tokelau
  * @see QLocale#Country
  * @type Number
  */
QLocale.Tokelau = 0xd5;

/**
  * @default 214
  * @constant
  * @memberOf QLocale
  * @name TongaCountry
  * @see QLocale#Country
  * @type Number
  */
QLocale.TongaCountry = 0xd6;

/**
  * @default 215
  * @constant
  * @memberOf QLocale
  * @name TrinidadAndTobago
  * @see QLocale#Country
  * @type Number
  */
QLocale.TrinidadAndTobago = 0xd7;

/**
  * @default 216
  * @constant
  * @memberOf QLocale
  * @name Tunisia
  * @see QLocale#Country
  * @type Number
  */
QLocale.Tunisia = 0xd8;

/**
  * @default 217
  * @constant
  * @memberOf QLocale
  * @name Turkey
  * @see QLocale#Country
  * @type Number
  */
QLocale.Turkey = 0xd9;

/**
  * @default 218
  * @constant
  * @memberOf QLocale
  * @name Turkmenistan
  * @see QLocale#Country
  * @type Number
  */
QLocale.Turkmenistan = 0xda;

/**
  * @default 219
  * @constant
  * @memberOf QLocale
  * @name TurksAndCaicosIslands
  * @see QLocale#Country
  * @type Number
  */
QLocale.TurksAndCaicosIslands = 0xdb;

/**
  * @default 220
  * @constant
  * @memberOf QLocale
  * @name Tuvalu
  * @see QLocale#Country
  * @type Number
  */
QLocale.Tuvalu = 0xdc;

/**
  * @default 221
  * @constant
  * @memberOf QLocale
  * @name Uganda
  * @see QLocale#Country
  * @type Number
  */
QLocale.Uganda = 0xdd;

/**
  * @default 222
  * @constant
  * @memberOf QLocale
  * @name Ukraine
  * @see QLocale#Country
  * @type Number
  */
QLocale.Ukraine = 0xde;

/**
  * @default 223
  * @constant
  * @memberOf QLocale
  * @name UnitedArabEmirates
  * @see QLocale#Country
  * @type Number
  */
QLocale.UnitedArabEmirates = 0xdf;

/**
  * @default 224
  * @constant
  * @memberOf QLocale
  * @name UnitedKingdom
  * @see QLocale#Country
  * @type Number
  */
QLocale.UnitedKingdom = 0xe0;

/**
  * @default 225
  * @constant
  * @memberOf QLocale
  * @name UnitedStates
  * @see QLocale#Country
  * @type Number
  */
QLocale.UnitedStates = 0xe1;

/**
  * @default 226
  * @constant
  * @memberOf QLocale
  * @name UnitedStatesMinorOutlyingIslands
  * @see QLocale#Country
  * @type Number
  */
QLocale.UnitedStatesMinorOutlyingIslands = 0xe2;

/**
  * @default 227
  * @constant
  * @memberOf QLocale
  * @name Uruguay
  * @see QLocale#Country
  * @type Number
  */
QLocale.Uruguay = 0xe3;

/**
  * @default 228
  * @constant
  * @memberOf QLocale
  * @name Uzbekistan
  * @see QLocale#Country
  * @type Number
  */
QLocale.Uzbekistan = 0xe4;

/**
  * @default 229
  * @constant
  * @memberOf QLocale
  * @name Vanuatu
  * @see QLocale#Country
  * @type Number
  */
QLocale.Vanuatu = 0xe5;

/**
  * @default 230
  * @constant
  * @memberOf QLocale
  * @name VaticanCityState
  * @see QLocale#Country
  * @type Number
  */
QLocale.VaticanCityState = 0xe6;

/**
  * @default 231
  * @constant
  * @memberOf QLocale
  * @name Venezuela
  * @see QLocale#Country
  * @type Number
  */
QLocale.Venezuela = 0xe7;

/**
  * @default 232
  * @constant
  * @memberOf QLocale
  * @name VietNam
  * @see QLocale#Country
  * @type Number
  */
QLocale.VietNam = 0xe8;

/**
  * @default 233
  * @constant
  * @memberOf QLocale
  * @name BritishVirginIslands
  * @see QLocale#Country
  * @type Number
  */
QLocale.BritishVirginIslands = 0xe9;

/**
  * @default 234
  * @constant
  * @memberOf QLocale
  * @name USVirginIslands
  * @see QLocale#Country
  * @type Number
  */
QLocale.USVirginIslands = 0xea;

/**
  * @default 235
  * @constant
  * @memberOf QLocale
  * @name WallisAndFutunaIslands
  * @see QLocale#Country
  * @type Number
  */
QLocale.WallisAndFutunaIslands = 0xeb;

/**
  * @default 236
  * @constant
  * @memberOf QLocale
  * @name WesternSahara
  * @see QLocale#Country
  * @type Number
  */
QLocale.WesternSahara = 0xec;

/**
  * @default 237
  * @constant
  * @memberOf QLocale
  * @name Yemen
  * @see QLocale#Country
  * @type Number
  */
QLocale.Yemen = 0xed;

/**
  * @default 238
  * @constant
  * @memberOf QLocale
  * @name Yugoslavia
  * @see QLocale#Country
  * @type Number
  */
QLocale.Yugoslavia = 0xee;

/**
  * @default 239
  * @constant
  * @memberOf QLocale
  * @name Zambia
  * @see QLocale#Country
  * @type Number
  */
QLocale.Zambia = 0xef;

/**
  * @default 240
  * @constant
  * @memberOf QLocale
  * @name Zimbabwe
  * @see QLocale#Country
  * @type Number
  */
QLocale.Zimbabwe = 0xf0;

/**
  * @default 241
  * @constant
  * @memberOf QLocale
  * @name SerbiaAndMontenegro
  * @see QLocale#Country
  * @type Number
  */
QLocale.SerbiaAndMontenegro = 0xf1;

/**
  * @default 242
  * @constant
  * @memberOf QLocale
  * @name Montenegro
  * @see QLocale#Country
  * @type Number
  */
QLocale.Montenegro = 0xf2;

/**
  * @default 243
  * @constant
  * @memberOf QLocale
  * @name Serbia
  * @see QLocale#Country
  * @type Number
  */
QLocale.Serbia = 0xf3;

/**
  * @default 244
  * @constant
  * @memberOf QLocale
  * @name SaintBarthelemy
  * @see QLocale#Country
  * @type Number
  */
QLocale.SaintBarthelemy = 0xf4;

/**
  * @default 245
  * @constant
  * @memberOf QLocale
  * @name SaintMartin
  * @see QLocale#Country
  * @type Number
  */
QLocale.SaintMartin = 0xf5;

/**
  * @default 246
  * @constant
  * @memberOf QLocale
  * @name LatinAmericaAndTheCaribbean
  * @see QLocale#Country
  * @type Number
  */
QLocale.LatinAmericaAndTheCaribbean = 0xf6;

/**
  * @constructor 
  * @memberOf QLocale
  * @name Country
  */
QLocale.Country = function(value){;};



/**
  * @default 0
  * @constant
  * @memberOf QLocale
  * @name AnyLanguage
  * @see QLocale#Language
  * @type Number
  */
QLocale.AnyLanguage = 0x0;

/**
  * @default 1
  * @constant
  * @memberOf QLocale
  * @name C
  * @see QLocale#Language
  * @type Number
  */
QLocale.C = 0x1;

/**
  * @default 2
  * @constant
  * @memberOf QLocale
  * @name Abkhazian
  * @see QLocale#Language
  * @type Number
  */
QLocale.Abkhazian = 0x2;

/**
  * @default 3
  * @constant
  * @memberOf QLocale
  * @name Afan
  * @see QLocale#Language
  * @type Number
  */
QLocale.Afan = 0x3;

/**
  * @default 4
  * @constant
  * @memberOf QLocale
  * @name Afar
  * @see QLocale#Language
  * @type Number
  */
QLocale.Afar = 0x4;

/**
  * @default 5
  * @constant
  * @memberOf QLocale
  * @name Afrikaans
  * @see QLocale#Language
  * @type Number
  */
QLocale.Afrikaans = 0x5;

/**
  * @default 6
  * @constant
  * @memberOf QLocale
  * @name Albanian
  * @see QLocale#Language
  * @type Number
  */
QLocale.Albanian = 0x6;

/**
  * @default 7
  * @constant
  * @memberOf QLocale
  * @name Amharic
  * @see QLocale#Language
  * @type Number
  */
QLocale.Amharic = 0x7;

/**
  * @default 8
  * @constant
  * @memberOf QLocale
  * @name Arabic
  * @see QLocale#Language
  * @type Number
  */
QLocale.Arabic = 0x8;

/**
  * @default 9
  * @constant
  * @memberOf QLocale
  * @name Armenian
  * @see QLocale#Language
  * @type Number
  */
QLocale.Armenian = 0x9;

/**
  * @default 10
  * @constant
  * @memberOf QLocale
  * @name Assamese
  * @see QLocale#Language
  * @type Number
  */
QLocale.Assamese = 0xa;

/**
  * @default 11
  * @constant
  * @memberOf QLocale
  * @name Aymara
  * @see QLocale#Language
  * @type Number
  */
QLocale.Aymara = 0xb;

/**
  * @default 12
  * @constant
  * @memberOf QLocale
  * @name Azerbaijani
  * @see QLocale#Language
  * @type Number
  */
QLocale.Azerbaijani = 0xc;

/**
  * @default 13
  * @constant
  * @memberOf QLocale
  * @name Bashkir
  * @see QLocale#Language
  * @type Number
  */
QLocale.Bashkir = 0xd;

/**
  * @default 14
  * @constant
  * @memberOf QLocale
  * @name Basque
  * @see QLocale#Language
  * @type Number
  */
QLocale.Basque = 0xe;

/**
  * @default 15
  * @constant
  * @memberOf QLocale
  * @name Bengali
  * @see QLocale#Language
  * @type Number
  */
QLocale.Bengali = 0xf;

/**
  * @default 16
  * @constant
  * @memberOf QLocale
  * @name Bhutani
  * @see QLocale#Language
  * @type Number
  */
QLocale.Bhutani = 0x10;

/**
  * @default 17
  * @constant
  * @memberOf QLocale
  * @name Bihari
  * @see QLocale#Language
  * @type Number
  */
QLocale.Bihari = 0x11;

/**
  * @default 18
  * @constant
  * @memberOf QLocale
  * @name Bislama
  * @see QLocale#Language
  * @type Number
  */
QLocale.Bislama = 0x12;

/**
  * @default 19
  * @constant
  * @memberOf QLocale
  * @name Breton
  * @see QLocale#Language
  * @type Number
  */
QLocale.Breton = 0x13;

/**
  * @default 20
  * @constant
  * @memberOf QLocale
  * @name Bulgarian
  * @see QLocale#Language
  * @type Number
  */
QLocale.Bulgarian = 0x14;

/**
  * @default 21
  * @constant
  * @memberOf QLocale
  * @name Burmese
  * @see QLocale#Language
  * @type Number
  */
QLocale.Burmese = 0x15;

/**
  * @default 22
  * @constant
  * @memberOf QLocale
  * @name Byelorussian
  * @see QLocale#Language
  * @type Number
  */
QLocale.Byelorussian = 0x16;

/**
  * @default 23
  * @constant
  * @memberOf QLocale
  * @name Cambodian
  * @see QLocale#Language
  * @type Number
  */
QLocale.Cambodian = 0x17;

/**
  * @default 24
  * @constant
  * @memberOf QLocale
  * @name Catalan
  * @see QLocale#Language
  * @type Number
  */
QLocale.Catalan = 0x18;

/**
  * @default 25
  * @constant
  * @memberOf QLocale
  * @name Chinese
  * @see QLocale#Language
  * @type Number
  */
QLocale.Chinese = 0x19;

/**
  * @default 26
  * @constant
  * @memberOf QLocale
  * @name Corsican
  * @see QLocale#Language
  * @type Number
  */
QLocale.Corsican = 0x1a;

/**
  * @default 27
  * @constant
  * @memberOf QLocale
  * @name Croatian
  * @see QLocale#Language
  * @type Number
  */
QLocale.Croatian = 0x1b;

/**
  * @default 28
  * @constant
  * @memberOf QLocale
  * @name Czech
  * @see QLocale#Language
  * @type Number
  */
QLocale.Czech = 0x1c;

/**
  * @default 29
  * @constant
  * @memberOf QLocale
  * @name Danish
  * @see QLocale#Language
  * @type Number
  */
QLocale.Danish = 0x1d;

/**
  * @default 30
  * @constant
  * @memberOf QLocale
  * @name Dutch
  * @see QLocale#Language
  * @type Number
  */
QLocale.Dutch = 0x1e;

/**
  * @default 31
  * @constant
  * @memberOf QLocale
  * @name English
  * @see QLocale#Language
  * @type Number
  */
QLocale.English = 0x1f;

/**
  * @default 32
  * @constant
  * @memberOf QLocale
  * @name Esperanto
  * @see QLocale#Language
  * @type Number
  */
QLocale.Esperanto = 0x20;

/**
  * @default 33
  * @constant
  * @memberOf QLocale
  * @name Estonian
  * @see QLocale#Language
  * @type Number
  */
QLocale.Estonian = 0x21;

/**
  * @default 34
  * @constant
  * @memberOf QLocale
  * @name Faroese
  * @see QLocale#Language
  * @type Number
  */
QLocale.Faroese = 0x22;

/**
  * @default 35
  * @constant
  * @memberOf QLocale
  * @name FijiLanguage
  * @see QLocale#Language
  * @type Number
  */
QLocale.FijiLanguage = 0x23;

/**
  * @default 36
  * @constant
  * @memberOf QLocale
  * @name Finnish
  * @see QLocale#Language
  * @type Number
  */
QLocale.Finnish = 0x24;

/**
  * @default 37
  * @constant
  * @memberOf QLocale
  * @name French
  * @see QLocale#Language
  * @type Number
  */
QLocale.French = 0x25;

/**
  * @default 38
  * @constant
  * @memberOf QLocale
  * @name Frisian
  * @see QLocale#Language
  * @type Number
  */
QLocale.Frisian = 0x26;

/**
  * @default 39
  * @constant
  * @memberOf QLocale
  * @name Gaelic
  * @see QLocale#Language
  * @type Number
  */
QLocale.Gaelic = 0x27;

/**
  * @default 40
  * @constant
  * @memberOf QLocale
  * @name Galician
  * @see QLocale#Language
  * @type Number
  */
QLocale.Galician = 0x28;

/**
  * @default 41
  * @constant
  * @memberOf QLocale
  * @name Georgian
  * @see QLocale#Language
  * @type Number
  */
QLocale.Georgian = 0x29;

/**
  * @default 42
  * @constant
  * @memberOf QLocale
  * @name German
  * @see QLocale#Language
  * @type Number
  */
QLocale.German = 0x2a;

/**
  * @default 43
  * @constant
  * @memberOf QLocale
  * @name Greek
  * @see QLocale#Language
  * @type Number
  */
QLocale.Greek = 0x2b;

/**
  * @default 44
  * @constant
  * @memberOf QLocale
  * @name Greenlandic
  * @see QLocale#Language
  * @type Number
  */
QLocale.Greenlandic = 0x2c;

/**
  * @default 45
  * @constant
  * @memberOf QLocale
  * @name Guarani
  * @see QLocale#Language
  * @type Number
  */
QLocale.Guarani = 0x2d;

/**
  * @default 46
  * @constant
  * @memberOf QLocale
  * @name Gujarati
  * @see QLocale#Language
  * @type Number
  */
QLocale.Gujarati = 0x2e;

/**
  * @default 47
  * @constant
  * @memberOf QLocale
  * @name Hausa
  * @see QLocale#Language
  * @type Number
  */
QLocale.Hausa = 0x2f;

/**
  * @default 48
  * @constant
  * @memberOf QLocale
  * @name Hebrew
  * @see QLocale#Language
  * @type Number
  */
QLocale.Hebrew = 0x30;

/**
  * @default 49
  * @constant
  * @memberOf QLocale
  * @name Hindi
  * @see QLocale#Language
  * @type Number
  */
QLocale.Hindi = 0x31;

/**
  * @default 50
  * @constant
  * @memberOf QLocale
  * @name Hungarian
  * @see QLocale#Language
  * @type Number
  */
QLocale.Hungarian = 0x32;

/**
  * @default 51
  * @constant
  * @memberOf QLocale
  * @name Icelandic
  * @see QLocale#Language
  * @type Number
  */
QLocale.Icelandic = 0x33;

/**
  * @default 52
  * @constant
  * @memberOf QLocale
  * @name Indonesian
  * @see QLocale#Language
  * @type Number
  */
QLocale.Indonesian = 0x34;

/**
  * @default 53
  * @constant
  * @memberOf QLocale
  * @name Interlingua
  * @see QLocale#Language
  * @type Number
  */
QLocale.Interlingua = 0x35;

/**
  * @default 54
  * @constant
  * @memberOf QLocale
  * @name Interlingue
  * @see QLocale#Language
  * @type Number
  */
QLocale.Interlingue = 0x36;

/**
  * @default 55
  * @constant
  * @memberOf QLocale
  * @name Inuktitut
  * @see QLocale#Language
  * @type Number
  */
QLocale.Inuktitut = 0x37;

/**
  * @default 56
  * @constant
  * @memberOf QLocale
  * @name Inupiak
  * @see QLocale#Language
  * @type Number
  */
QLocale.Inupiak = 0x38;

/**
  * @default 57
  * @constant
  * @memberOf QLocale
  * @name Irish
  * @see QLocale#Language
  * @type Number
  */
QLocale.Irish = 0x39;

/**
  * @default 58
  * @constant
  * @memberOf QLocale
  * @name Italian
  * @see QLocale#Language
  * @type Number
  */
QLocale.Italian = 0x3a;

/**
  * @default 59
  * @constant
  * @memberOf QLocale
  * @name Japanese
  * @see QLocale#Language
  * @type Number
  */
QLocale.Japanese = 0x3b;

/**
  * @default 60
  * @constant
  * @memberOf QLocale
  * @name Javanese
  * @see QLocale#Language
  * @type Number
  */
QLocale.Javanese = 0x3c;

/**
  * @default 61
  * @constant
  * @memberOf QLocale
  * @name Kannada
  * @see QLocale#Language
  * @type Number
  */
QLocale.Kannada = 0x3d;

/**
  * @default 62
  * @constant
  * @memberOf QLocale
  * @name Kashmiri
  * @see QLocale#Language
  * @type Number
  */
QLocale.Kashmiri = 0x3e;

/**
  * @default 63
  * @constant
  * @memberOf QLocale
  * @name Kazakh
  * @see QLocale#Language
  * @type Number
  */
QLocale.Kazakh = 0x3f;

/**
  * @default 64
  * @constant
  * @memberOf QLocale
  * @name Kinyarwanda
  * @see QLocale#Language
  * @type Number
  */
QLocale.Kinyarwanda = 0x40;

/**
  * @default 65
  * @constant
  * @memberOf QLocale
  * @name Kirghiz
  * @see QLocale#Language
  * @type Number
  */
QLocale.Kirghiz = 0x41;

/**
  * @default 66
  * @constant
  * @memberOf QLocale
  * @name Korean
  * @see QLocale#Language
  * @type Number
  */
QLocale.Korean = 0x42;

/**
  * @default 67
  * @constant
  * @memberOf QLocale
  * @name Kurdish
  * @see QLocale#Language
  * @type Number
  */
QLocale.Kurdish = 0x43;

/**
  * @default 68
  * @constant
  * @memberOf QLocale
  * @name Kurundi
  * @see QLocale#Language
  * @type Number
  */
QLocale.Kurundi = 0x44;

/**
  * @default 69
  * @constant
  * @memberOf QLocale
  * @name Laothian
  * @see QLocale#Language
  * @type Number
  */
QLocale.Laothian = 0x45;

/**
  * @default 70
  * @constant
  * @memberOf QLocale
  * @name Latin
  * @see QLocale#Language
  * @type Number
  */
QLocale.Latin = 0x46;

/**
  * @default 71
  * @constant
  * @memberOf QLocale
  * @name Latvian
  * @see QLocale#Language
  * @type Number
  */
QLocale.Latvian = 0x47;

/**
  * @default 72
  * @constant
  * @memberOf QLocale
  * @name Lingala
  * @see QLocale#Language
  * @type Number
  */
QLocale.Lingala = 0x48;

/**
  * @default 73
  * @constant
  * @memberOf QLocale
  * @name Lithuanian
  * @see QLocale#Language
  * @type Number
  */
QLocale.Lithuanian = 0x49;

/**
  * @default 74
  * @constant
  * @memberOf QLocale
  * @name Macedonian
  * @see QLocale#Language
  * @type Number
  */
QLocale.Macedonian = 0x4a;

/**
  * @default 75
  * @constant
  * @memberOf QLocale
  * @name Malagasy
  * @see QLocale#Language
  * @type Number
  */
QLocale.Malagasy = 0x4b;

/**
  * @default 76
  * @constant
  * @memberOf QLocale
  * @name Malay
  * @see QLocale#Language
  * @type Number
  */
QLocale.Malay = 0x4c;

/**
  * @default 77
  * @constant
  * @memberOf QLocale
  * @name Malayalam
  * @see QLocale#Language
  * @type Number
  */
QLocale.Malayalam = 0x4d;

/**
  * @default 78
  * @constant
  * @memberOf QLocale
  * @name Maltese
  * @see QLocale#Language
  * @type Number
  */
QLocale.Maltese = 0x4e;

/**
  * @default 79
  * @constant
  * @memberOf QLocale
  * @name Maori
  * @see QLocale#Language
  * @type Number
  */
QLocale.Maori = 0x4f;

/**
  * @default 80
  * @constant
  * @memberOf QLocale
  * @name Marathi
  * @see QLocale#Language
  * @type Number
  */
QLocale.Marathi = 0x50;

/**
  * @default 81
  * @constant
  * @memberOf QLocale
  * @name Moldavian
  * @see QLocale#Language
  * @type Number
  */
QLocale.Moldavian = 0x51;

/**
  * @default 82
  * @constant
  * @memberOf QLocale
  * @name Mongolian
  * @see QLocale#Language
  * @type Number
  */
QLocale.Mongolian = 0x52;

/**
  * @default 83
  * @constant
  * @memberOf QLocale
  * @name NauruLanguage
  * @see QLocale#Language
  * @type Number
  */
QLocale.NauruLanguage = 0x53;

/**
  * @default 84
  * @constant
  * @memberOf QLocale
  * @name Nepali
  * @see QLocale#Language
  * @type Number
  */
QLocale.Nepali = 0x54;

/**
  * @default 85
  * @constant
  * @memberOf QLocale
  * @name Norwegian
  * @see QLocale#Language
  * @type Number
  */
QLocale.Norwegian = 0x55;

/**
  * @default 86
  * @constant
  * @memberOf QLocale
  * @name Occitan
  * @see QLocale#Language
  * @type Number
  */
QLocale.Occitan = 0x56;

/**
  * @default 87
  * @constant
  * @memberOf QLocale
  * @name Oriya
  * @see QLocale#Language
  * @type Number
  */
QLocale.Oriya = 0x57;

/**
  * @default 88
  * @constant
  * @memberOf QLocale
  * @name Pashto
  * @see QLocale#Language
  * @type Number
  */
QLocale.Pashto = 0x58;

/**
  * @default 89
  * @constant
  * @memberOf QLocale
  * @name Persian
  * @see QLocale#Language
  * @type Number
  */
QLocale.Persian = 0x59;

/**
  * @default 90
  * @constant
  * @memberOf QLocale
  * @name Polish
  * @see QLocale#Language
  * @type Number
  */
QLocale.Polish = 0x5a;

/**
  * @default 91
  * @constant
  * @memberOf QLocale
  * @name Portuguese
  * @see QLocale#Language
  * @type Number
  */
QLocale.Portuguese = 0x5b;

/**
  * @default 92
  * @constant
  * @memberOf QLocale
  * @name Punjabi
  * @see QLocale#Language
  * @type Number
  */
QLocale.Punjabi = 0x5c;

/**
  * @default 93
  * @constant
  * @memberOf QLocale
  * @name Quechua
  * @see QLocale#Language
  * @type Number
  */
QLocale.Quechua = 0x5d;

/**
  * @default 94
  * @constant
  * @memberOf QLocale
  * @name RhaetoRomance
  * @see QLocale#Language
  * @type Number
  */
QLocale.RhaetoRomance = 0x5e;

/**
  * @default 95
  * @constant
  * @memberOf QLocale
  * @name Romanian
  * @see QLocale#Language
  * @type Number
  */
QLocale.Romanian = 0x5f;

/**
  * @default 96
  * @constant
  * @memberOf QLocale
  * @name Russian
  * @see QLocale#Language
  * @type Number
  */
QLocale.Russian = 0x60;

/**
  * @default 97
  * @constant
  * @memberOf QLocale
  * @name Samoan
  * @see QLocale#Language
  * @type Number
  */
QLocale.Samoan = 0x61;

/**
  * @default 98
  * @constant
  * @memberOf QLocale
  * @name Sangho
  * @see QLocale#Language
  * @type Number
  */
QLocale.Sangho = 0x62;

/**
  * @default 99
  * @constant
  * @memberOf QLocale
  * @name Sanskrit
  * @see QLocale#Language
  * @type Number
  */
QLocale.Sanskrit = 0x63;

/**
  * @default 100
  * @constant
  * @memberOf QLocale
  * @name Serbian
  * @see QLocale#Language
  * @type Number
  */
QLocale.Serbian = 0x64;

/**
  * @default 101
  * @constant
  * @memberOf QLocale
  * @name SerboCroatian
  * @see QLocale#Language
  * @type Number
  */
QLocale.SerboCroatian = 0x65;

/**
  * @default 102
  * @constant
  * @memberOf QLocale
  * @name Sesotho
  * @see QLocale#Language
  * @type Number
  */
QLocale.Sesotho = 0x66;

/**
  * @default 103
  * @constant
  * @memberOf QLocale
  * @name Setswana
  * @see QLocale#Language
  * @type Number
  */
QLocale.Setswana = 0x67;

/**
  * @default 104
  * @constant
  * @memberOf QLocale
  * @name Shona
  * @see QLocale#Language
  * @type Number
  */
QLocale.Shona = 0x68;

/**
  * @default 105
  * @constant
  * @memberOf QLocale
  * @name Sindhi
  * @see QLocale#Language
  * @type Number
  */
QLocale.Sindhi = 0x69;

/**
  * @default 106
  * @constant
  * @memberOf QLocale
  * @name Singhalese
  * @see QLocale#Language
  * @type Number
  */
QLocale.Singhalese = 0x6a;

/**
  * @default 107
  * @constant
  * @memberOf QLocale
  * @name Siswati
  * @see QLocale#Language
  * @type Number
  */
QLocale.Siswati = 0x6b;

/**
  * @default 108
  * @constant
  * @memberOf QLocale
  * @name Slovak
  * @see QLocale#Language
  * @type Number
  */
QLocale.Slovak = 0x6c;

/**
  * @default 109
  * @constant
  * @memberOf QLocale
  * @name Slovenian
  * @see QLocale#Language
  * @type Number
  */
QLocale.Slovenian = 0x6d;

/**
  * @default 110
  * @constant
  * @memberOf QLocale
  * @name Somali
  * @see QLocale#Language
  * @type Number
  */
QLocale.Somali = 0x6e;

/**
  * @default 111
  * @constant
  * @memberOf QLocale
  * @name Spanish
  * @see QLocale#Language
  * @type Number
  */
QLocale.Spanish = 0x6f;

/**
  * @default 112
  * @constant
  * @memberOf QLocale
  * @name Sundanese
  * @see QLocale#Language
  * @type Number
  */
QLocale.Sundanese = 0x70;

/**
  * @default 113
  * @constant
  * @memberOf QLocale
  * @name Swahili
  * @see QLocale#Language
  * @type Number
  */
QLocale.Swahili = 0x71;

/**
  * @default 114
  * @constant
  * @memberOf QLocale
  * @name Swedish
  * @see QLocale#Language
  * @type Number
  */
QLocale.Swedish = 0x72;

/**
  * @default 115
  * @constant
  * @memberOf QLocale
  * @name Tagalog
  * @see QLocale#Language
  * @type Number
  */
QLocale.Tagalog = 0x73;

/**
  * @default 116
  * @constant
  * @memberOf QLocale
  * @name Tajik
  * @see QLocale#Language
  * @type Number
  */
QLocale.Tajik = 0x74;

/**
  * @default 117
  * @constant
  * @memberOf QLocale
  * @name Tamil
  * @see QLocale#Language
  * @type Number
  */
QLocale.Tamil = 0x75;

/**
  * @default 118
  * @constant
  * @memberOf QLocale
  * @name Tatar
  * @see QLocale#Language
  * @type Number
  */
QLocale.Tatar = 0x76;

/**
  * @default 119
  * @constant
  * @memberOf QLocale
  * @name Telugu
  * @see QLocale#Language
  * @type Number
  */
QLocale.Telugu = 0x77;

/**
  * @default 120
  * @constant
  * @memberOf QLocale
  * @name Thai
  * @see QLocale#Language
  * @type Number
  */
QLocale.Thai = 0x78;

/**
  * @default 121
  * @constant
  * @memberOf QLocale
  * @name Tibetan
  * @see QLocale#Language
  * @type Number
  */
QLocale.Tibetan = 0x79;

/**
  * @default 122
  * @constant
  * @memberOf QLocale
  * @name Tigrinya
  * @see QLocale#Language
  * @type Number
  */
QLocale.Tigrinya = 0x7a;

/**
  * @default 123
  * @constant
  * @memberOf QLocale
  * @name TongaLanguage
  * @see QLocale#Language
  * @type Number
  */
QLocale.TongaLanguage = 0x7b;

/**
  * @default 124
  * @constant
  * @memberOf QLocale
  * @name Tsonga
  * @see QLocale#Language
  * @type Number
  */
QLocale.Tsonga = 0x7c;

/**
  * @default 125
  * @constant
  * @memberOf QLocale
  * @name Turkish
  * @see QLocale#Language
  * @type Number
  */
QLocale.Turkish = 0x7d;

/**
  * @default 126
  * @constant
  * @memberOf QLocale
  * @name Turkmen
  * @see QLocale#Language
  * @type Number
  */
QLocale.Turkmen = 0x7e;

/**
  * @default 127
  * @constant
  * @memberOf QLocale
  * @name Twi
  * @see QLocale#Language
  * @type Number
  */
QLocale.Twi = 0x7f;

/**
  * @default 128
  * @constant
  * @memberOf QLocale
  * @name Uigur
  * @see QLocale#Language
  * @type Number
  */
QLocale.Uigur = 0x80;

/**
  * @default 129
  * @constant
  * @memberOf QLocale
  * @name Ukrainian
  * @see QLocale#Language
  * @type Number
  */
QLocale.Ukrainian = 0x81;

/**
  * @default 130
  * @constant
  * @memberOf QLocale
  * @name Urdu
  * @see QLocale#Language
  * @type Number
  */
QLocale.Urdu = 0x82;

/**
  * @default 131
  * @constant
  * @memberOf QLocale
  * @name Uzbek
  * @see QLocale#Language
  * @type Number
  */
QLocale.Uzbek = 0x83;

/**
  * @default 132
  * @constant
  * @memberOf QLocale
  * @name Vietnamese
  * @see QLocale#Language
  * @type Number
  */
QLocale.Vietnamese = 0x84;

/**
  * @default 133
  * @constant
  * @memberOf QLocale
  * @name Volapuk
  * @see QLocale#Language
  * @type Number
  */
QLocale.Volapuk = 0x85;

/**
  * @default 134
  * @constant
  * @memberOf QLocale
  * @name Welsh
  * @see QLocale#Language
  * @type Number
  */
QLocale.Welsh = 0x86;

/**
  * @default 135
  * @constant
  * @memberOf QLocale
  * @name Wolof
  * @see QLocale#Language
  * @type Number
  */
QLocale.Wolof = 0x87;

/**
  * @default 136
  * @constant
  * @memberOf QLocale
  * @name Xhosa
  * @see QLocale#Language
  * @type Number
  */
QLocale.Xhosa = 0x88;

/**
  * @default 137
  * @constant
  * @memberOf QLocale
  * @name Yiddish
  * @see QLocale#Language
  * @type Number
  */
QLocale.Yiddish = 0x89;

/**
  * @default 138
  * @constant
  * @memberOf QLocale
  * @name Yoruba
  * @see QLocale#Language
  * @type Number
  */
QLocale.Yoruba = 0x8a;

/**
  * @default 139
  * @constant
  * @memberOf QLocale
  * @name Zhuang
  * @see QLocale#Language
  * @type Number
  */
QLocale.Zhuang = 0x8b;

/**
  * @default 140
  * @constant
  * @memberOf QLocale
  * @name Zulu
  * @see QLocale#Language
  * @type Number
  */
QLocale.Zulu = 0x8c;

/**
  * @default 141
  * @constant
  * @memberOf QLocale
  * @name Nynorsk
  * @see QLocale#Language
  * @type Number
  */
QLocale.Nynorsk = 0x8d;

/**
  * @default 142
  * @constant
  * @memberOf QLocale
  * @name Bosnian
  * @see QLocale#Language
  * @type Number
  */
QLocale.Bosnian = 0x8e;

/**
  * @default 143
  * @constant
  * @memberOf QLocale
  * @name Divehi
  * @see QLocale#Language
  * @type Number
  */
QLocale.Divehi = 0x8f;

/**
  * @default 144
  * @constant
  * @memberOf QLocale
  * @name Manx
  * @see QLocale#Language
  * @type Number
  */
QLocale.Manx = 0x90;

/**
  * @default 145
  * @constant
  * @memberOf QLocale
  * @name Cornish
  * @see QLocale#Language
  * @type Number
  */
QLocale.Cornish = 0x91;

/**
  * @default 146
  * @constant
  * @memberOf QLocale
  * @name Akan
  * @see QLocale#Language
  * @type Number
  */
QLocale.Akan = 0x92;

/**
  * @default 147
  * @constant
  * @memberOf QLocale
  * @name Konkani
  * @see QLocale#Language
  * @type Number
  */
QLocale.Konkani = 0x93;

/**
  * @default 148
  * @constant
  * @memberOf QLocale
  * @name Ga
  * @see QLocale#Language
  * @type Number
  */
QLocale.Ga = 0x94;

/**
  * @default 149
  * @constant
  * @memberOf QLocale
  * @name Igbo
  * @see QLocale#Language
  * @type Number
  */
QLocale.Igbo = 0x95;

/**
  * @default 150
  * @constant
  * @memberOf QLocale
  * @name Kamba
  * @see QLocale#Language
  * @type Number
  */
QLocale.Kamba = 0x96;

/**
  * @default 151
  * @constant
  * @memberOf QLocale
  * @name Syriac
  * @see QLocale#Language
  * @type Number
  */
QLocale.Syriac = 0x97;

/**
  * @default 152
  * @constant
  * @memberOf QLocale
  * @name Blin
  * @see QLocale#Language
  * @type Number
  */
QLocale.Blin = 0x98;

/**
  * @default 153
  * @constant
  * @memberOf QLocale
  * @name Geez
  * @see QLocale#Language
  * @type Number
  */
QLocale.Geez = 0x99;

/**
  * @default 154
  * @constant
  * @memberOf QLocale
  * @name Koro
  * @see QLocale#Language
  * @type Number
  */
QLocale.Koro = 0x9a;

/**
  * @default 155
  * @constant
  * @memberOf QLocale
  * @name Sidamo
  * @see QLocale#Language
  * @type Number
  */
QLocale.Sidamo = 0x9b;

/**
  * @default 156
  * @constant
  * @memberOf QLocale
  * @name Atsam
  * @see QLocale#Language
  * @type Number
  */
QLocale.Atsam = 0x9c;

/**
  * @default 157
  * @constant
  * @memberOf QLocale
  * @name Tigre
  * @see QLocale#Language
  * @type Number
  */
QLocale.Tigre = 0x9d;

/**
  * @default 158
  * @constant
  * @memberOf QLocale
  * @name Jju
  * @see QLocale#Language
  * @type Number
  */
QLocale.Jju = 0x9e;

/**
  * @default 159
  * @constant
  * @memberOf QLocale
  * @name Friulian
  * @see QLocale#Language
  * @type Number
  */
QLocale.Friulian = 0x9f;

/**
  * @default 160
  * @constant
  * @memberOf QLocale
  * @name Venda
  * @see QLocale#Language
  * @type Number
  */
QLocale.Venda = 0xa0;

/**
  * @default 161
  * @constant
  * @memberOf QLocale
  * @name Ewe
  * @see QLocale#Language
  * @type Number
  */
QLocale.Ewe = 0xa1;

/**
  * @default 162
  * @constant
  * @memberOf QLocale
  * @name Walamo
  * @see QLocale#Language
  * @type Number
  */
QLocale.Walamo = 0xa2;

/**
  * @default 163
  * @constant
  * @memberOf QLocale
  * @name Hawaiian
  * @see QLocale#Language
  * @type Number
  */
QLocale.Hawaiian = 0xa3;

/**
  * @default 164
  * @constant
  * @memberOf QLocale
  * @name Tyap
  * @see QLocale#Language
  * @type Number
  */
QLocale.Tyap = 0xa4;

/**
  * @default 165
  * @constant
  * @memberOf QLocale
  * @name Chewa
  * @see QLocale#Language
  * @type Number
  */
QLocale.Chewa = 0xa5;

/**
  * @default 166
  * @constant
  * @memberOf QLocale
  * @name Filipino
  * @see QLocale#Language
  * @type Number
  */
QLocale.Filipino = 0xa6;

/**
  * @default 167
  * @constant
  * @memberOf QLocale
  * @name SwissGerman
  * @see QLocale#Language
  * @type Number
  */
QLocale.SwissGerman = 0xa7;

/**
  * @default 168
  * @constant
  * @memberOf QLocale
  * @name SichuanYi
  * @see QLocale#Language
  * @type Number
  */
QLocale.SichuanYi = 0xa8;

/**
  * @default 169
  * @constant
  * @memberOf QLocale
  * @name Kpelle
  * @see QLocale#Language
  * @type Number
  */
QLocale.Kpelle = 0xa9;

/**
  * @default 170
  * @constant
  * @memberOf QLocale
  * @name LowGerman
  * @see QLocale#Language
  * @type Number
  */
QLocale.LowGerman = 0xaa;

/**
  * @default 171
  * @constant
  * @memberOf QLocale
  * @name SouthNdebele
  * @see QLocale#Language
  * @type Number
  */
QLocale.SouthNdebele = 0xab;

/**
  * @default 172
  * @constant
  * @memberOf QLocale
  * @name NorthernSotho
  * @see QLocale#Language
  * @type Number
  */
QLocale.NorthernSotho = 0xac;

/**
  * @default 173
  * @constant
  * @memberOf QLocale
  * @name NorthernSami
  * @see QLocale#Language
  * @type Number
  */
QLocale.NorthernSami = 0xad;

/**
  * @default 174
  * @constant
  * @memberOf QLocale
  * @name Taroko
  * @see QLocale#Language
  * @type Number
  */
QLocale.Taroko = 0xae;

/**
  * @default 175
  * @constant
  * @memberOf QLocale
  * @name Gusii
  * @see QLocale#Language
  * @type Number
  */
QLocale.Gusii = 0xaf;

/**
  * @default 176
  * @constant
  * @memberOf QLocale
  * @name Taita
  * @see QLocale#Language
  * @type Number
  */
QLocale.Taita = 0xb0;

/**
  * @default 177
  * @constant
  * @memberOf QLocale
  * @name Fulah
  * @see QLocale#Language
  * @type Number
  */
QLocale.Fulah = 0xb1;

/**
  * @default 178
  * @constant
  * @memberOf QLocale
  * @name Kikuyu
  * @see QLocale#Language
  * @type Number
  */
QLocale.Kikuyu = 0xb2;

/**
  * @default 179
  * @constant
  * @memberOf QLocale
  * @name Samburu
  * @see QLocale#Language
  * @type Number
  */
QLocale.Samburu = 0xb3;

/**
  * @default 180
  * @constant
  * @memberOf QLocale
  * @name Sena
  * @see QLocale#Language
  * @type Number
  */
QLocale.Sena = 0xb4;

/**
  * @default 181
  * @constant
  * @memberOf QLocale
  * @name NorthNdebele
  * @see QLocale#Language
  * @type Number
  */
QLocale.NorthNdebele = 0xb5;

/**
  * @default 182
  * @constant
  * @memberOf QLocale
  * @name Rombo
  * @see QLocale#Language
  * @type Number
  */
QLocale.Rombo = 0xb6;

/**
  * @default 183
  * @constant
  * @memberOf QLocale
  * @name Tachelhit
  * @see QLocale#Language
  * @type Number
  */
QLocale.Tachelhit = 0xb7;

/**
  * @default 184
  * @constant
  * @memberOf QLocale
  * @name Kabyle
  * @see QLocale#Language
  * @type Number
  */
QLocale.Kabyle = 0xb8;

/**
  * @default 185
  * @constant
  * @memberOf QLocale
  * @name Nyankole
  * @see QLocale#Language
  * @type Number
  */
QLocale.Nyankole = 0xb9;

/**
  * @default 186
  * @constant
  * @memberOf QLocale
  * @name Bena
  * @see QLocale#Language
  * @type Number
  */
QLocale.Bena = 0xba;

/**
  * @default 187
  * @constant
  * @memberOf QLocale
  * @name Vunjo
  * @see QLocale#Language
  * @type Number
  */
QLocale.Vunjo = 0xbb;

/**
  * @default 188
  * @constant
  * @memberOf QLocale
  * @name Bambara
  * @see QLocale#Language
  * @type Number
  */
QLocale.Bambara = 0xbc;

/**
  * @default 189
  * @constant
  * @memberOf QLocale
  * @name Embu
  * @see QLocale#Language
  * @type Number
  */
QLocale.Embu = 0xbd;

/**
  * @default 190
  * @constant
  * @memberOf QLocale
  * @name Cherokee
  * @see QLocale#Language
  * @type Number
  */
QLocale.Cherokee = 0xbe;

/**
  * @default 191
  * @constant
  * @memberOf QLocale
  * @name Morisyen
  * @see QLocale#Language
  * @type Number
  */
QLocale.Morisyen = 0xbf;

/**
  * @default 192
  * @constant
  * @memberOf QLocale
  * @name Makonde
  * @see QLocale#Language
  * @type Number
  */
QLocale.Makonde = 0xc0;

/**
  * @default 193
  * @constant
  * @memberOf QLocale
  * @name Langi
  * @see QLocale#Language
  * @type Number
  */
QLocale.Langi = 0xc1;

/**
  * @default 194
  * @constant
  * @memberOf QLocale
  * @name Ganda
  * @see QLocale#Language
  * @type Number
  */
QLocale.Ganda = 0xc2;

/**
  * @default 195
  * @constant
  * @memberOf QLocale
  * @name Bemba
  * @see QLocale#Language
  * @type Number
  */
QLocale.Bemba = 0xc3;

/**
  * @default 196
  * @constant
  * @memberOf QLocale
  * @name Kabuverdianu
  * @see QLocale#Language
  * @type Number
  */
QLocale.Kabuverdianu = 0xc4;

/**
  * @default 197
  * @constant
  * @memberOf QLocale
  * @name Meru
  * @see QLocale#Language
  * @type Number
  */
QLocale.Meru = 0xc5;

/**
  * @default 198
  * @constant
  * @memberOf QLocale
  * @name Kalenjin
  * @see QLocale#Language
  * @type Number
  */
QLocale.Kalenjin = 0xc6;

/**
  * @default 199
  * @constant
  * @memberOf QLocale
  * @name Nama
  * @see QLocale#Language
  * @type Number
  */
QLocale.Nama = 0xc7;

/**
  * @default 200
  * @constant
  * @memberOf QLocale
  * @name Machame
  * @see QLocale#Language
  * @type Number
  */
QLocale.Machame = 0xc8;

/**
  * @default 201
  * @constant
  * @memberOf QLocale
  * @name Colognian
  * @see QLocale#Language
  * @type Number
  */
QLocale.Colognian = 0xc9;

/**
  * @default 202
  * @constant
  * @memberOf QLocale
  * @name Masai
  * @see QLocale#Language
  * @type Number
  */
QLocale.Masai = 0xca;

/**
  * @default 203
  * @constant
  * @memberOf QLocale
  * @name Soga
  * @see QLocale#Language
  * @type Number
  */
QLocale.Soga = 0xcb;

/**
  * @default 204
  * @constant
  * @memberOf QLocale
  * @name Luyia
  * @see QLocale#Language
  * @type Number
  */
QLocale.Luyia = 0xcc;

/**
  * @default 205
  * @constant
  * @memberOf QLocale
  * @name Asu
  * @see QLocale#Language
  * @type Number
  */
QLocale.Asu = 0xcd;

/**
  * @default 206
  * @constant
  * @memberOf QLocale
  * @name Teso
  * @see QLocale#Language
  * @type Number
  */
QLocale.Teso = 0xce;

/**
  * @default 207
  * @constant
  * @memberOf QLocale
  * @name Saho
  * @see QLocale#Language
  * @type Number
  */
QLocale.Saho = 0xcf;

/**
  * @default 208
  * @constant
  * @memberOf QLocale
  * @name KoyraChiini
  * @see QLocale#Language
  * @type Number
  */
QLocale.KoyraChiini = 0xd0;

/**
  * @default 209
  * @constant
  * @memberOf QLocale
  * @name Rwa
  * @see QLocale#Language
  * @type Number
  */
QLocale.Rwa = 0xd1;

/**
  * @default 210
  * @constant
  * @memberOf QLocale
  * @name Luo
  * @see QLocale#Language
  * @type Number
  */
QLocale.Luo = 0xd2;

/**
  * @default 211
  * @constant
  * @memberOf QLocale
  * @name Chiga
  * @see QLocale#Language
  * @type Number
  */
QLocale.Chiga = 0xd3;

/**
  * @default 212
  * @constant
  * @memberOf QLocale
  * @name CentralMoroccoTamazight
  * @see QLocale#Language
  * @type Number
  */
QLocale.CentralMoroccoTamazight = 0xd4;

/**
  * @default 213
  * @constant
  * @memberOf QLocale
  * @name KoyraboroSenni
  * @see QLocale#Language
  * @type Number
  */
QLocale.KoyraboroSenni = 0xd5;

/**
  * @default 214
  * @constant
  * @memberOf QLocale
  * @name Shambala
  * @see QLocale#Language
  * @type Number
  */
QLocale.Shambala = 0xd6;

/**
  * @constructor 
  * @memberOf QLocale
  * @name Language
  */
QLocale.Language = function(value){;};



/**
  * @name amText
  * @function
  * @memberOf QLocale.prototype
  * @returns {String}
  */
QLocale.prototype.amText = function(){return new String();};

/**
  * @name bcp47Name
  * @function
  * @memberOf QLocale.prototype
  * @returns {String}
  */
QLocale.prototype.bcp47Name = function(){return new String();};

/**
  * @name country
  * @function
  * @memberOf QLocale.prototype
  * @returns {QLocale.Country}
  */
QLocale.prototype.country = function(){return new QLocale.Country();};

/**
  * @name createSeparatedList
  * @function
  * @memberOf QLocale.prototype
  * @param {Array} strl
  * @returns {String}
  */
QLocale.prototype.createSeparatedList = function(strl){return new String();};

/**
  * @name dateFormat
  * @function
  * @memberOf QLocale.prototype
  * @param {QLocale.FormatType} format
  * @returns {String}
  */
QLocale.prototype.dateFormat = function(format){return new String();};

/**
  * @name dateTimeFormat
  * @function
  * @memberOf QLocale.prototype
  * @param {QLocale.FormatType} format
  * @returns {String}
  */
QLocale.prototype.dateTimeFormat = function(format){return new String();};

/**
  * @name dayName
  * @function
  * @memberOf QLocale.prototype
  * @param {Numeric} arg__1
  * @param {QLocale.FormatType} format
  * @returns {String}
  */
QLocale.prototype.dayName = function(arg__1, format){return new String();};

/**
  * @name decimalPoint
  * @function
  * @memberOf QLocale.prototype
  * @returns {String}
  */
QLocale.prototype.decimalPoint = function(){return new String();};

/**
  * @name exponential
  * @function
  * @memberOf QLocale.prototype
  * @returns {String}
  */
QLocale.prototype.exponential = function(){return new String();};

/**
  * @name firstDayOfWeek
  * @function
  * @memberOf QLocale.prototype
  * @returns {Qt.DayOfWeek}
  */
QLocale.prototype.firstDayOfWeek = function(){return new Qt.DayOfWeek();};

/**
  * @name groupSeparator
  * @function
  * @memberOf QLocale.prototype
  * @returns {String}
  */
QLocale.prototype.groupSeparator = function(){return new String();};

/**
  * @name language
  * @function
  * @memberOf QLocale.prototype
  * @returns {QLocale.Language}
  */
QLocale.prototype.language = function(){return new QLocale.Language();};

/**
  * @name measurementSystem
  * @function
  * @memberOf QLocale.prototype
  * @returns {QLocale.MeasurementSystem}
  */
QLocale.prototype.measurementSystem = function(){return new QLocale.MeasurementSystem();};

/**
  * @name monthName
  * @function
  * @memberOf QLocale.prototype
  * @param {Numeric} arg__1
  * @param {QLocale.FormatType} format
  * @returns {String}
  */
QLocale.prototype.monthName = function(arg__1, format){return new String();};

/**
  * @name name
  * @function
  * @memberOf QLocale.prototype
  * @returns {String}
  */
QLocale.prototype.name = function(){return new String();};

/**
  * @name nativeCountryName
  * @function
  * @memberOf QLocale.prototype
  * @returns {String}
  */
QLocale.prototype.nativeCountryName = function(){return new String();};

/**
  * @name nativeLanguageName
  * @function
  * @memberOf QLocale.prototype
  * @returns {String}
  */
QLocale.prototype.nativeLanguageName = function(){return new String();};

/**
  * @name negativeSign
  * @function
  * @memberOf QLocale.prototype
  * @returns {String}
  */
QLocale.prototype.negativeSign = function(){return new String();};

/**
  * @name numberOptions
  * @function
  * @memberOf QLocale.prototype
  * @returns {QLocale.NumberOptions}
  */
QLocale.prototype.numberOptions = function(){return new QLocale.NumberOptions();};

/**
  * @name operator_equal
  * @function
  * @memberOf QLocale.prototype
  * @param {QLocale} other
  * @returns {Boolean}
  */
QLocale.prototype.operator_equal = function(other){return new Boolean();};

/**
  * @name percent
  * @function
  * @memberOf QLocale.prototype
  * @returns {String}
  */
QLocale.prototype.percent = function(){return new String();};

/**
  * @name pmText
  * @function
  * @memberOf QLocale.prototype
  * @returns {String}
  */
QLocale.prototype.pmText = function(){return new String();};

/**
  * @name positiveSign
  * @function
  * @memberOf QLocale.prototype
  * @returns {String}
  */
QLocale.prototype.positiveSign = function(){return new String();};

/**
  * @name readFrom
  * @function
  * @memberOf QLocale.prototype
  * @param {QDataStream} arg__1
  * @returns {undefined}
  */
QLocale.prototype.readFrom = function(arg__1){return undefined;};

/**
  * @name setNumberOptions
  * @function
  * @memberOf QLocale.prototype
  * @param {QLocale.NumberOptions} options
  * @returns {undefined}
  */
QLocale.prototype.setNumberOptions = function(options){return undefined;};

/**
  * @name standaloneDayName
  * @function
  * @memberOf QLocale.prototype
  * @param {Numeric} arg__1
  * @param {QLocale.FormatType} format
  * @returns {String}
  */
QLocale.prototype.standaloneDayName = function(arg__1, format){return new String();};

/**
  * @name standaloneMonthName
  * @function
  * @memberOf QLocale.prototype
  * @param {Numeric} arg__1
  * @param {QLocale.FormatType} format
  * @returns {String}
  */
QLocale.prototype.standaloneMonthName = function(arg__1, format){return new String();};

/**
  * @name textDirection
  * @function
  * @memberOf QLocale.prototype
  * @returns {QTextFormat.LayoutDirection}
  */
QLocale.prototype.textDirection = function(){return new QTextFormat.LayoutDirection();};

/**
  * @name timeFormat
  * @function
  * @memberOf QLocale.prototype
  * @param {QLocale.FormatType} format
  * @returns {String}
  */
QLocale.prototype.timeFormat = function(format){return new String();};

/**
  * @name toCurrencyString
  * @function
  * @memberOf QLocale.prototype
  * @param {Numeric} arg__1
  * @param {String} symbol
  * @returns {String}
  */
QLocale.prototype.toCurrencyString = function(arg__1, symbol){return new String();};

/**
  * @name toDate
  * @function
  * @memberOf QLocale.prototype
  * @param {String} string
  * @param {QLocale.FormatType} arg__2
  * @returns {QDate}
  */
QLocale.prototype.toDate = function(string, arg__2){return new QDate();};

/**
  * @name toDateTime
  * @function
  * @memberOf QLocale.prototype
  * @param {String} string
  * @param {QLocale.FormatType} format
  * @returns {QDateTime}
  */
QLocale.prototype.toDateTime = function(string, format){return new QDateTime();};

/**
  * @name toDouble
  * @function
  * @memberOf QLocale.prototype
  * @param {String} s
  * @param {Boolean} ok
  * @returns {Numeric}
  */
QLocale.prototype.toDouble = function(s, ok){return new Numeric();};

/**
  * @name toFloat
  * @function
  * @memberOf QLocale.prototype
  * @param {String} s
  * @param {Boolean} ok
  * @returns {Numeric}
  */
QLocale.prototype.toFloat = function(s, ok){return new Numeric();};

/**
  * @name toInt
  * @function
  * @memberOf QLocale.prototype
  * @param {String} s
  * @param {Boolean} ok
  * @param {Numeric} base
  * @returns {Numeric}
  */
QLocale.prototype.toInt = function(s, ok, base){return new Numeric();};

/**
  * @name toLongLong
  * @function
  * @memberOf QLocale.prototype
  * @param {String} s
  * @param {Boolean} ok
  * @param {Numeric} base
  * @returns {Numeric}
  */
QLocale.prototype.toLongLong = function(s, ok, base){return new Numeric();};

/**
  * @name toLower
  * @function
  * @memberOf QLocale.prototype
  * @param {String} str
  * @returns {String}
  */
QLocale.prototype.toLower = function(str){return new String();};

/**
  * @name toShort
  * @function
  * @memberOf QLocale.prototype
  * @param {String} s
  * @param {Boolean} ok
  * @param {Numeric} base
  * @returns {Numeric}
  */
QLocale.prototype.toShort = function(s, ok, base){return new Numeric();};

/**
  * @name toString
  * @function
  * @memberOf QLocale.prototype
  * @param {QDate} date
  * @param {QLocale.FormatType} format
  * @returns {String}
  */
QLocale.prototype.toString = function(date, format){return new String();};

/**
  * @name toTime
  * @function
  * @memberOf QLocale.prototype
  * @param {String} string
  * @param {QLocale.FormatType} arg__2
  * @returns {QTime}
  */
QLocale.prototype.toTime = function(string, arg__2){return new QTime();};

/**
  * @name toUShort
  * @function
  * @memberOf QLocale.prototype
  * @param {String} s
  * @param {Boolean} ok
  * @param {Numeric} base
  * @returns {Numeric}
  */
QLocale.prototype.toUShort = function(s, ok, base){return new Numeric();};

/**
  * @name toUpper
  * @function
  * @memberOf QLocale.prototype
  * @param {String} str
  * @returns {String}
  */
QLocale.prototype.toUpper = function(str){return new String();};

/**
  * @name uiLanguages
  * @function
  * @memberOf QLocale.prototype
  * @returns {Array}
  */
QLocale.prototype.uiLanguages = function(){return new Array();};

/**
  * @name weekdays
  * @function
  * @memberOf QLocale.prototype
  * @returns {Array}
  */
QLocale.prototype.weekdays = function(){return new Array();};

/**
  * @name writeTo
  * @function
  * @memberOf QLocale.prototype
  * @param {QDataStream} arg__1
  * @returns {undefined}
  */
QLocale.prototype.writeTo = function(arg__1){return undefined;};

/**
  * @name zeroDigit
  * @function
  * @memberOf QLocale.prototype
  * @returns {String}
  */
QLocale.prototype.zeroDigit = function(){return new String();};

