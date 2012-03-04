/**
  * @name QGLShaderProgram
  * @constructor
  * @extends QObject
  * @param {QObject} parent
  */
function QGLShaderProgram(parent){return undefined;};

/**
  * @name QGLShaderProgram^1
  * @constructor
  * @extends QObject
  * @param {QGLContext} context
  * @param {QObject} parent
  */
function QGLShaderProgram(context, parent){return undefined;};

QGLShaderProgram.prototype = new QObject();

/**
  * @name hasOpenGLShaderPrograms
  * @function
  * @memberOf QGLShaderProgram
  * @param {QGLContext} context
  * @returns {Boolean}
  */
QGLShaderProgram.hasOpenGLShaderPrograms = function(context){return new Boolean();};

/**
  * @name addShader
  * @function
  * @memberOf QGLShaderProgram.prototype
  * @param {QGLShader} shader
  * @returns {Boolean}
  */
QGLShaderProgram.prototype.addShader = function(shader){return new Boolean();};

/**
  * @name addShaderFromSourceCode
  * @function
  * @memberOf QGLShaderProgram.prototype
  * @param {QGLShader.ShaderType} type
  * @param {QByteArray} source
  * @returns {Boolean}
  */
QGLShaderProgram.prototype.addShaderFromSourceCode = function(type, source){return new Boolean();};

/**
  * @name addShaderFromSourceFile
  * @function
  * @memberOf QGLShaderProgram.prototype
  * @param {QGLShader.ShaderType} type
  * @param {String} fileName
  * @returns {Boolean}
  */
QGLShaderProgram.prototype.addShaderFromSourceFile = function(type, fileName){return new Boolean();};

/**
  * @name attributeLocation
  * @function
  * @memberOf QGLShaderProgram.prototype
  * @param {QByteArray} name
  * @returns {Numeric}
  */
QGLShaderProgram.prototype.attributeLocation = function(name){return new Numeric();};

/**
  * @name bind
  * @function
  * @memberOf QGLShaderProgram.prototype
  * @returns {Boolean}
  */
QGLShaderProgram.prototype.bind = function(){return new Boolean();};

/**
  * @name bindAttributeLocation
  * @function
  * @memberOf QGLShaderProgram.prototype
  * @param {QByteArray} name
  * @param {Numeric} location
  * @returns {undefined}
  */
QGLShaderProgram.prototype.bindAttributeLocation = function(name, location){return undefined;};

/**
  * @name disableAttributeArray
  * @function
  * @memberOf QGLShaderProgram.prototype
  * @param {String} name
  * @returns {undefined}
  */
QGLShaderProgram.prototype.disableAttributeArray = function(name){return undefined;};

/**
  * @name enableAttributeArray
  * @function
  * @memberOf QGLShaderProgram.prototype
  * @param {String} name
  * @returns {undefined}
  */
QGLShaderProgram.prototype.enableAttributeArray = function(name){return undefined;};

/**
  * @name geometryOutputVertexCount
  * @function
  * @memberOf QGLShaderProgram.prototype
  * @returns {Numeric}
  */
QGLShaderProgram.prototype.geometryOutputVertexCount = function(){return new Numeric();};

/**
  * @name isLinked
  * @function
  * @memberOf QGLShaderProgram.prototype
  * @returns {Boolean}
  */
QGLShaderProgram.prototype.isLinked = function(){return new Boolean();};

/**
  * @name link
  * @function
  * @memberOf QGLShaderProgram.prototype
  * @returns {Boolean}
  */
QGLShaderProgram.prototype.link = function(){return new Boolean();};

/**
  * @name log
  * @function
  * @memberOf QGLShaderProgram.prototype
  * @returns {String}
  */
QGLShaderProgram.prototype.log = function(){return new String();};

/**
  * @name maxGeometryOutputVertices
  * @function
  * @memberOf QGLShaderProgram.prototype
  * @returns {Numeric}
  */
QGLShaderProgram.prototype.maxGeometryOutputVertices = function(){return new Numeric();};

/**
  * @name release
  * @function
  * @memberOf QGLShaderProgram.prototype
  * @returns {undefined}
  */
QGLShaderProgram.prototype.release = function(){return undefined;};

/**
  * @name removeAllShaders
  * @function
  * @memberOf QGLShaderProgram.prototype
  * @returns {undefined}
  */
QGLShaderProgram.prototype.removeAllShaders = function(){return undefined;};

/**
  * @name removeShader
  * @function
  * @memberOf QGLShaderProgram.prototype
  * @param {QGLShader} shader
  * @returns {undefined}
  */
QGLShaderProgram.prototype.removeShader = function(shader){return undefined;};

/**
  * @name setAttributeArray_QVector2D
  * @function
  * @memberOf QGLShaderProgram.prototype
  * @param {String} name
  * @param {QVector2D} values
  * @param {Numeric} stride
  * @returns {undefined}
  */
QGLShaderProgram.prototype.setAttributeArray_QVector2D = function(name, values, stride){return undefined;};

/**
  * @name setAttributeArray_QVector3D
  * @function
  * @memberOf QGLShaderProgram.prototype
  * @param {String} name
  * @param {QVector3D} values
  * @param {Numeric} stride
  * @returns {undefined}
  */
QGLShaderProgram.prototype.setAttributeArray_QVector3D = function(name, values, stride){return undefined;};

/**
  * @name setAttributeArray_QVector4D
  * @function
  * @memberOf QGLShaderProgram.prototype
  * @param {String} name
  * @param {QVector4D} values
  * @param {Numeric} stride
  * @returns {undefined}
  */
QGLShaderProgram.prototype.setAttributeArray_QVector4D = function(name, values, stride){return undefined;};

/**
  * @name setAttributeValue
  * @function
  * @memberOf QGLShaderProgram.prototype
  * @param {String} name
  * @param {QColor} value
  * @returns {undefined}
  */
QGLShaderProgram.prototype.setAttributeValue = function(name, value){return undefined;};

/**
  * @name setGeometryOutputVertexCount
  * @function
  * @memberOf QGLShaderProgram.prototype
  * @param {Numeric} count
  * @returns {undefined}
  */
QGLShaderProgram.prototype.setGeometryOutputVertexCount = function(count){return undefined;};

/**
  * @name setUniformValue
  * @function
  * @memberOf QGLShaderProgram.prototype
  * @param {String} name
  * @param {QColor} color
  * @returns {undefined}
  */
QGLShaderProgram.prototype.setUniformValue = function(name, color){return undefined;};

/**
  * @name setUniformValueArray
  * @function
  * @memberOf QGLShaderProgram.prototype
  * @param {String} name
  * @param {QMatrix3x3} values
  * @param {Numeric} count
  * @returns {undefined}
  */
QGLShaderProgram.prototype.setUniformValueArray = function(name, values, count){return undefined;};

/**
  * @name setUniformValueArray_QVector2D
  * @function
  * @memberOf QGLShaderProgram.prototype
  * @param {String} name
  * @param {QVector2D} values
  * @param {Numeric} count
  * @returns {undefined}
  */
QGLShaderProgram.prototype.setUniformValueArray_QVector2D = function(name, values, count){return undefined;};

/**
  * @name setUniformValueArray_QVector3D
  * @function
  * @memberOf QGLShaderProgram.prototype
  * @param {String} name
  * @param {QVector3D} values
  * @param {Numeric} count
  * @returns {undefined}
  */
QGLShaderProgram.prototype.setUniformValueArray_QVector3D = function(name, values, count){return undefined;};

/**
  * @name setUniformValueArray_QVector4D
  * @function
  * @memberOf QGLShaderProgram.prototype
  * @param {String} name
  * @param {QVector4D} values
  * @param {Numeric} count
  * @returns {undefined}
  */
QGLShaderProgram.prototype.setUniformValueArray_QVector4D = function(name, values, count){return undefined;};

/**
  * @name shaders
  * @function
  * @memberOf QGLShaderProgram.prototype
  * @returns {Array}
  */
QGLShaderProgram.prototype.shaders = function(){return new Array();};

/**
  * @name uniformLocation
  * @function
  * @memberOf QGLShaderProgram.prototype
  * @param {QByteArray} name
  * @returns {Numeric}
  */
QGLShaderProgram.prototype.uniformLocation = function(name){return new Numeric();};

