/**
  * @name QColor
  * @constructor
  */
function QColor(){return undefined;};

/**
  * @name QColor^1
  * @constructor
  * @param {Qt.GlobalColor} color
  */
function QColor(color){return undefined;};

/**
  * @name QColor^2
  * @constructor
  * @param {QColor} color
  */
function QColor(color){return undefined;};

/**
  * @name QColor^3
  * @constructor
  * @param {String} name
  */
function QColor(name){return undefined;};

/**
  * @name QColor^4
  * @constructor
  * @param {Numeric} r
  * @param {Numeric} g
  * @param {Numeric} b
  * @param {Numeric} a
  */
function QColor(r, g, b, a){return undefined;};

/**
  * @name QColor^5
  * @constructor
  * @param {Numeric} rgb
  */
function QColor(rgb){return undefined;};

/**
  * @name colorNames
  * @function
  * @memberOf QColor
  * @returns {Array}
  */
QColor.colorNames = function(){return new Array();};

/**
  * @name fromCmyk
  * @function
  * @memberOf QColor
  * @param {Numeric} c
  * @param {Numeric} m
  * @param {Numeric} y
  * @param {Numeric} k
  * @param {Numeric} a
  * @returns {QColor}
  */
QColor.fromCmyk = function(c, m, y, k, a){return new QColor();};

/**
  * @name fromCmykF
  * @function
  * @memberOf QColor
  * @param {Numeric} c
  * @param {Numeric} m
  * @param {Numeric} y
  * @param {Numeric} k
  * @param {Numeric} a
  * @returns {QColor}
  */
QColor.fromCmykF = function(c, m, y, k, a){return new QColor();};

/**
  * @name fromHsl
  * @function
  * @memberOf QColor
  * @param {Numeric} h
  * @param {Numeric} s
  * @param {Numeric} l
  * @param {Numeric} a
  * @returns {QColor}
  */
QColor.fromHsl = function(h, s, l, a){return new QColor();};

/**
  * @name fromHslF
  * @function
  * @memberOf QColor
  * @param {Numeric} h
  * @param {Numeric} s
  * @param {Numeric} l
  * @param {Numeric} a
  * @returns {QColor}
  */
QColor.fromHslF = function(h, s, l, a){return new QColor();};

/**
  * @name fromHsv
  * @function
  * @memberOf QColor
  * @param {Numeric} h
  * @param {Numeric} s
  * @param {Numeric} v
  * @param {Numeric} a
  * @returns {QColor}
  */
QColor.fromHsv = function(h, s, v, a){return new QColor();};

/**
  * @name fromHsvF
  * @function
  * @memberOf QColor
  * @param {Numeric} h
  * @param {Numeric} s
  * @param {Numeric} v
  * @param {Numeric} a
  * @returns {QColor}
  */
QColor.fromHsvF = function(h, s, v, a){return new QColor();};

/**
  * @name fromRgb
  * @function
  * @memberOf QColor
  * @param {Numeric} r
  * @param {Numeric} g
  * @param {Numeric} b
  * @param {Numeric} a
  * @returns {QColor}
  */
QColor.fromRgb = function(r, g, b, a){return new QColor();};

/**
  * @name fromRgbF
  * @function
  * @memberOf QColor
  * @param {Numeric} r
  * @param {Numeric} g
  * @param {Numeric} b
  * @param {Numeric} a
  * @returns {QColor}
  */
QColor.fromRgbF = function(r, g, b, a){return new QColor();};

/**
  * @name fromRgba
  * @function
  * @memberOf QColor
  * @param {Numeric} rgba
  * @returns {QColor}
  */
QColor.fromRgba = function(rgba){return new QColor();};

/**
  * @name isValidColor
  * @function
  * @memberOf QColor
  * @param {String} name
  * @returns {Boolean}
  */
QColor.isValidColor = function(name){return new Boolean();};

/**
  * @default 0x0
  * @constant
  * @memberOf QColor
  * @name Invalid
  * @see QColor#Spec
  * @type Number
  */
QColor.Invalid = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QColor
  * @name Rgb
  * @see QColor#Spec
  * @type Number
  */
QColor.Rgb = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QColor
  * @name Hsv
  * @see QColor#Spec
  * @type Number
  */
QColor.Hsv = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QColor
  * @name Cmyk
  * @see QColor#Spec
  * @type Number
  */
QColor.Cmyk = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QColor
  * @name Hsl
  * @see QColor#Spec
  * @type Number
  */
QColor.Hsl = 0x4;

/**
  * @constructor 
  * @memberOf QColor
  * @name Spec
  */
QColor.Spec = function(value){;};



/**
  * @name alpha
  * @function
  * @memberOf QColor.prototype
  * @returns {Numeric}
  */
QColor.prototype.alpha = function(){return new Numeric();};

/**
  * @name alphaF
  * @function
  * @memberOf QColor.prototype
  * @returns {Numeric}
  */
QColor.prototype.alphaF = function(){return new Numeric();};

/**
  * @name black
  * @function
  * @memberOf QColor.prototype
  * @returns {Numeric}
  */
QColor.prototype.black = function(){return new Numeric();};

/**
  * @name blackF
  * @function
  * @memberOf QColor.prototype
  * @returns {Numeric}
  */
QColor.prototype.blackF = function(){return new Numeric();};

/**
  * @name blue
  * @function
  * @memberOf QColor.prototype
  * @returns {Numeric}
  */
QColor.prototype.blue = function(){return new Numeric();};

/**
  * @name blueF
  * @function
  * @memberOf QColor.prototype
  * @returns {Numeric}
  */
QColor.prototype.blueF = function(){return new Numeric();};

/**
  * @name convertTo
  * @function
  * @memberOf QColor.prototype
  * @param {QColor.Spec} colorSpec
  * @returns {QColor}
  */
QColor.prototype.convertTo = function(colorSpec){return new QColor();};

/**
  * @name cyan
  * @function
  * @memberOf QColor.prototype
  * @returns {Numeric}
  */
QColor.prototype.cyan = function(){return new Numeric();};

/**
  * @name cyanF
  * @function
  * @memberOf QColor.prototype
  * @returns {Numeric}
  */
QColor.prototype.cyanF = function(){return new Numeric();};

/**
  * @name darker
  * @function
  * @memberOf QColor.prototype
  * @param {Numeric} f
  * @returns {QColor}
  */
QColor.prototype.darker = function(f){return new QColor();};

/**
  * @name getHsl
  * @function
  * @memberOf QColor.prototype
  * @param {Numeric} h
  * @param {Numeric} s
  * @param {Numeric} l
  * @param {Numeric} a
  * @returns {undefined}
  */
QColor.prototype.getHsl = function(h, s, l, a){return undefined;};

/**
  * @name getHslF
  * @function
  * @memberOf QColor.prototype
  * @param {Numeric} h
  * @param {Numeric} s
  * @param {Numeric} l
  * @param {Numeric} a
  * @returns {undefined}
  */
QColor.prototype.getHslF = function(h, s, l, a){return undefined;};

/**
  * @name green
  * @function
  * @memberOf QColor.prototype
  * @returns {Numeric}
  */
QColor.prototype.green = function(){return new Numeric();};

/**
  * @name greenF
  * @function
  * @memberOf QColor.prototype
  * @returns {Numeric}
  */
QColor.prototype.greenF = function(){return new Numeric();};

/**
  * @name hslHue
  * @function
  * @memberOf QColor.prototype
  * @returns {Numeric}
  */
QColor.prototype.hslHue = function(){return new Numeric();};

/**
  * @name hslHueF
  * @function
  * @memberOf QColor.prototype
  * @returns {Numeric}
  */
QColor.prototype.hslHueF = function(){return new Numeric();};

/**
  * @name hslSaturation
  * @function
  * @memberOf QColor.prototype
  * @returns {Numeric}
  */
QColor.prototype.hslSaturation = function(){return new Numeric();};

/**
  * @name hslSaturationF
  * @function
  * @memberOf QColor.prototype
  * @returns {Numeric}
  */
QColor.prototype.hslSaturationF = function(){return new Numeric();};

/**
  * @name hsvHue
  * @function
  * @memberOf QColor.prototype
  * @returns {Numeric}
  */
QColor.prototype.hsvHue = function(){return new Numeric();};

/**
  * @name hsvHueF
  * @function
  * @memberOf QColor.prototype
  * @returns {Numeric}
  */
QColor.prototype.hsvHueF = function(){return new Numeric();};

/**
  * @name hsvSaturation
  * @function
  * @memberOf QColor.prototype
  * @returns {Numeric}
  */
QColor.prototype.hsvSaturation = function(){return new Numeric();};

/**
  * @name hsvSaturationF
  * @function
  * @memberOf QColor.prototype
  * @returns {Numeric}
  */
QColor.prototype.hsvSaturationF = function(){return new Numeric();};

/**
  * @name hue
  * @function
  * @memberOf QColor.prototype
  * @returns {Numeric}
  */
QColor.prototype.hue = function(){return new Numeric();};

/**
  * @name hueF
  * @function
  * @memberOf QColor.prototype
  * @returns {Numeric}
  */
QColor.prototype.hueF = function(){return new Numeric();};

/**
  * @name isValid
  * @function
  * @memberOf QColor.prototype
  * @returns {Boolean}
  */
QColor.prototype.isValid = function(){return new Boolean();};

/**
  * @name lighter
  * @function
  * @memberOf QColor.prototype
  * @param {Numeric} f
  * @returns {QColor}
  */
QColor.prototype.lighter = function(f){return new QColor();};

/**
  * @name lightness
  * @function
  * @memberOf QColor.prototype
  * @returns {Numeric}
  */
QColor.prototype.lightness = function(){return new Numeric();};

/**
  * @name lightnessF
  * @function
  * @memberOf QColor.prototype
  * @returns {Numeric}
  */
QColor.prototype.lightnessF = function(){return new Numeric();};

/**
  * @name magenta
  * @function
  * @memberOf QColor.prototype
  * @returns {Numeric}
  */
QColor.prototype.magenta = function(){return new Numeric();};

/**
  * @name magentaF
  * @function
  * @memberOf QColor.prototype
  * @returns {Numeric}
  */
QColor.prototype.magentaF = function(){return new Numeric();};

/**
  * @name name
  * @function
  * @memberOf QColor.prototype
  * @returns {String}
  */
QColor.prototype.name = function(){return new String();};

/**
  * @name operator_equal
  * @function
  * @memberOf QColor.prototype
  * @param {QColor} c
  * @returns {Boolean}
  */
QColor.prototype.operator_equal = function(c){return new Boolean();};

/**
  * @name readFrom
  * @function
  * @memberOf QColor.prototype
  * @param {QDataStream} arg__1
  * @returns {undefined}
  */
QColor.prototype.readFrom = function(arg__1){return undefined;};

/**
  * @name red
  * @function
  * @memberOf QColor.prototype
  * @returns {Numeric}
  */
QColor.prototype.red = function(){return new Numeric();};

/**
  * @name redF
  * @function
  * @memberOf QColor.prototype
  * @returns {Numeric}
  */
QColor.prototype.redF = function(){return new Numeric();};

/**
  * @name rgb
  * @function
  * @memberOf QColor.prototype
  * @returns {Numeric}
  */
QColor.prototype.rgb = function(){return new Numeric();};

/**
  * @name rgba
  * @function
  * @memberOf QColor.prototype
  * @returns {Numeric}
  */
QColor.prototype.rgba = function(){return new Numeric();};

/**
  * @name saturation
  * @function
  * @memberOf QColor.prototype
  * @returns {Numeric}
  */
QColor.prototype.saturation = function(){return new Numeric();};

/**
  * @name saturationF
  * @function
  * @memberOf QColor.prototype
  * @returns {Numeric}
  */
QColor.prototype.saturationF = function(){return new Numeric();};

/**
  * @name setAlpha
  * @function
  * @memberOf QColor.prototype
  * @param {Numeric} alpha
  * @returns {undefined}
  */
QColor.prototype.setAlpha = function(alpha){return undefined;};

/**
  * @name setAlphaF
  * @function
  * @memberOf QColor.prototype
  * @param {Numeric} alpha
  * @returns {undefined}
  */
QColor.prototype.setAlphaF = function(alpha){return undefined;};

/**
  * @name setBlue
  * @function
  * @memberOf QColor.prototype
  * @param {Numeric} blue
  * @returns {undefined}
  */
QColor.prototype.setBlue = function(blue){return undefined;};

/**
  * @name setBlueF
  * @function
  * @memberOf QColor.prototype
  * @param {Numeric} blue
  * @returns {undefined}
  */
QColor.prototype.setBlueF = function(blue){return undefined;};

/**
  * @name setCmyk
  * @function
  * @memberOf QColor.prototype
  * @param {Numeric} c
  * @param {Numeric} m
  * @param {Numeric} y
  * @param {Numeric} k
  * @param {Numeric} a
  * @returns {undefined}
  */
QColor.prototype.setCmyk = function(c, m, y, k, a){return undefined;};

/**
  * @name setCmykF
  * @function
  * @memberOf QColor.prototype
  * @param {Numeric} c
  * @param {Numeric} m
  * @param {Numeric} y
  * @param {Numeric} k
  * @param {Numeric} a
  * @returns {undefined}
  */
QColor.prototype.setCmykF = function(c, m, y, k, a){return undefined;};

/**
  * @name setGreen
  * @function
  * @memberOf QColor.prototype
  * @param {Numeric} green
  * @returns {undefined}
  */
QColor.prototype.setGreen = function(green){return undefined;};

/**
  * @name setGreenF
  * @function
  * @memberOf QColor.prototype
  * @param {Numeric} green
  * @returns {undefined}
  */
QColor.prototype.setGreenF = function(green){return undefined;};

/**
  * @name setHsl
  * @function
  * @memberOf QColor.prototype
  * @param {Numeric} h
  * @param {Numeric} s
  * @param {Numeric} l
  * @param {Numeric} a
  * @returns {undefined}
  */
QColor.prototype.setHsl = function(h, s, l, a){return undefined;};

/**
  * @name setHslF
  * @function
  * @memberOf QColor.prototype
  * @param {Numeric} h
  * @param {Numeric} s
  * @param {Numeric} l
  * @param {Numeric} a
  * @returns {undefined}
  */
QColor.prototype.setHslF = function(h, s, l, a){return undefined;};

/**
  * @name setHsv
  * @function
  * @memberOf QColor.prototype
  * @param {Numeric} h
  * @param {Numeric} s
  * @param {Numeric} v
  * @param {Numeric} a
  * @returns {undefined}
  */
QColor.prototype.setHsv = function(h, s, v, a){return undefined;};

/**
  * @name setHsvF
  * @function
  * @memberOf QColor.prototype
  * @param {Numeric} h
  * @param {Numeric} s
  * @param {Numeric} v
  * @param {Numeric} a
  * @returns {undefined}
  */
QColor.prototype.setHsvF = function(h, s, v, a){return undefined;};

/**
  * @name setNamedColor
  * @function
  * @memberOf QColor.prototype
  * @param {String} name
  * @returns {undefined}
  */
QColor.prototype.setNamedColor = function(name){return undefined;};

/**
  * @name setRed
  * @function
  * @memberOf QColor.prototype
  * @param {Numeric} red
  * @returns {undefined}
  */
QColor.prototype.setRed = function(red){return undefined;};

/**
  * @name setRedF
  * @function
  * @memberOf QColor.prototype
  * @param {Numeric} red
  * @returns {undefined}
  */
QColor.prototype.setRedF = function(red){return undefined;};

/**
  * @name setRgb
  * @function
  * @memberOf QColor.prototype
  * @param {Numeric} r
  * @param {Numeric} g
  * @param {Numeric} b
  * @param {Numeric} a
  * @returns {undefined}
  */
QColor.prototype.setRgb = function(r, g, b, a){return undefined;};

/**
  * @name setRgbF
  * @function
  * @memberOf QColor.prototype
  * @param {Numeric} r
  * @param {Numeric} g
  * @param {Numeric} b
  * @param {Numeric} a
  * @returns {undefined}
  */
QColor.prototype.setRgbF = function(r, g, b, a){return undefined;};

/**
  * @name setRgba
  * @function
  * @memberOf QColor.prototype
  * @param {Numeric} rgba
  * @returns {undefined}
  */
QColor.prototype.setRgba = function(rgba){return undefined;};

/**
  * @name spec
  * @function
  * @memberOf QColor.prototype
  * @returns {QColor.Spec}
  */
QColor.prototype.spec = function(){return new QColor.Spec();};

/**
  * @name toCmyk
  * @function
  * @memberOf QColor.prototype
  * @returns {QColor}
  */
QColor.prototype.toCmyk = function(){return new QColor();};

/**
  * @name toHsl
  * @function
  * @memberOf QColor.prototype
  * @returns {QColor}
  */
QColor.prototype.toHsl = function(){return new QColor();};

/**
  * @name toHsv
  * @function
  * @memberOf QColor.prototype
  * @returns {QColor}
  */
QColor.prototype.toHsv = function(){return new QColor();};

/**
  * @name toRgb
  * @function
  * @memberOf QColor.prototype
  * @returns {QColor}
  */
QColor.prototype.toRgb = function(){return new QColor();};

/**
  * @name value
  * @function
  * @memberOf QColor.prototype
  * @returns {Numeric}
  */
QColor.prototype.value = function(){return new Numeric();};

/**
  * @name valueF
  * @function
  * @memberOf QColor.prototype
  * @returns {Numeric}
  */
QColor.prototype.valueF = function(){return new Numeric();};

/**
  * @name writeTo
  * @function
  * @memberOf QColor.prototype
  * @param {QDataStream} arg__1
  * @returns {undefined}
  */
QColor.prototype.writeTo = function(arg__1){return undefined;};

/**
  * @name yellow
  * @function
  * @memberOf QColor.prototype
  * @returns {Numeric}
  */
QColor.prototype.yellow = function(){return new Numeric();};

/**
  * @name yellowF
  * @function
  * @memberOf QColor.prototype
  * @returns {Numeric}
  */
QColor.prototype.yellowF = function(){return new Numeric();};

