/**
  * @name QGLShader
  * @constructor
  * @extends QObject
  * @param {QGLShader.ShaderType} type
  * @param {QObject} parent
  */
function QGLShader(type, parent){return undefined;};

/**
  * @name QGLShader^1
  * @constructor
  * @extends QObject
  * @param {QGLShader.ShaderType} type
  * @param {QGLContext} context
  * @param {QObject} parent
  */
function QGLShader(type, context, parent){return undefined;};

QGLShader.prototype = new QObject();

/**
  * @name hasOpenGLShaders
  * @function
  * @memberOf QGLShader
  * @param {QGLShader.ShaderType} type
  * @param {QGLContext} context
  * @returns {Boolean}
  */
QGLShader.hasOpenGLShaders = function(type, context){return new Boolean();};

/**
  * @default 0x0001
  * @constant
  * @memberOf QGLShader
  * @name Vertex
  * @see QGLShader#ShaderType
  * @see QGLShader#ShaderTypeBit
  * @type Number
  */
QGLShader.Vertex = 0x1;

/**
  * @default 0x0002
  * @constant
  * @memberOf QGLShader
  * @name Fragment
  * @see QGLShader#ShaderType
  * @see QGLShader#ShaderTypeBit
  * @type Number
  */
QGLShader.Fragment = 0x2;

/**
  * @default 0x0004
  * @constant
  * @memberOf QGLShader
  * @name Geometry
  * @see QGLShader#ShaderType
  * @see QGLShader#ShaderTypeBit
  * @type Number
  */
QGLShader.Geometry = 0x4;

/**
  * @constructor 
  * @memberOf QGLShader
  * @name ShaderTypeBit
  */
QGLShader.ShaderTypeBit = function(value){;};

/**
  * @constructor 
  * @memberOf QGLShader
  * @name ShaderType
  */
QGLShader.ShaderType = function(value1, value2 /*, ...*/){;};


/**
  * @name compileSourceCode
  * @function
  * @memberOf QGLShader.prototype
  * @param {QByteArray} source
  * @returns {Boolean}
  */
QGLShader.prototype.compileSourceCode = function(source){return new Boolean();};

/**
  * @name compileSourceFile
  * @function
  * @memberOf QGLShader.prototype
  * @param {String} fileName
  * @returns {Boolean}
  */
QGLShader.prototype.compileSourceFile = function(fileName){return new Boolean();};

/**
  * @name isCompiled
  * @function
  * @memberOf QGLShader.prototype
  * @returns {Boolean}
  */
QGLShader.prototype.isCompiled = function(){return new Boolean();};

/**
  * @name log
  * @function
  * @memberOf QGLShader.prototype
  * @returns {String}
  */
QGLShader.prototype.log = function(){return new String();};

/**
  * @name shaderType
  * @function
  * @memberOf QGLShader.prototype
  * @returns {QGLShader.ShaderType}
  */
QGLShader.prototype.shaderType = function(){return new QGLShader.ShaderType();};

/**
  * @name sourceCode
  * @function
  * @memberOf QGLShader.prototype
  * @returns {QByteArray}
  */
QGLShader.prototype.sourceCode = function(){return new QByteArray();};

