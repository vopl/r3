/**
  * @class QAbstractXmlNodeModel from package com.trolltech.qt.xmlpatterns
  */
var QAbstractXmlNodeModel = {};

/**
  * @default 0x0
  * @constant
  * @memberOf QAbstractXmlNodeModel
  * @name Parent
  * @see QAbstractXmlNodeModel#SimpleAxis
  * @type Number
  */
QAbstractXmlNodeModel.Parent = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QAbstractXmlNodeModel
  * @name FirstChild
  * @see QAbstractXmlNodeModel#SimpleAxis
  * @type Number
  */
QAbstractXmlNodeModel.FirstChild = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QAbstractXmlNodeModel
  * @name PreviousSibling
  * @see QAbstractXmlNodeModel#SimpleAxis
  * @type Number
  */
QAbstractXmlNodeModel.PreviousSibling = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QAbstractXmlNodeModel
  * @name NextSibling
  * @see QAbstractXmlNodeModel#SimpleAxis
  * @type Number
  */
QAbstractXmlNodeModel.NextSibling = 0x3;

/**
  * @constructor 
  * @memberOf QAbstractXmlNodeModel
  * @name SimpleAxis
  */
QAbstractXmlNodeModel.SimpleAxis = function(value){;};



/**
  * @default 0x1
  * @constant
  * @memberOf QAbstractXmlNodeModel
  * @name InheritNamespaces
  * @see QAbstractXmlNodeModel#NodeCopySetting
  * @type Number
  */
QAbstractXmlNodeModel.InheritNamespaces = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QAbstractXmlNodeModel
  * @name PreserveNamespaces
  * @see QAbstractXmlNodeModel#NodeCopySetting
  * @type Number
  */
QAbstractXmlNodeModel.PreserveNamespaces = 0x2;

/**
  * @constructor 
  * @memberOf QAbstractXmlNodeModel
  * @name NodeCopySetting
  */
QAbstractXmlNodeModel.NodeCopySetting = function(value){;};



/**
  * @name baseUri
  * @function
  * @memberOf QAbstractXmlNodeModel.prototype
  * @param {QXmlNodeModelIndex} ni
  * @returns {QUrl}
  */
QAbstractXmlNodeModel.prototype.baseUri = function(ni){return new QUrl();};

/**
  * @name compareOrder
  * @function
  * @memberOf QAbstractXmlNodeModel.prototype
  * @param {QXmlNodeModelIndex} ni1
  * @param {QXmlNodeModelIndex} ni2
  * @returns {QXmlNodeModelIndex.DocumentOrder}
  */
QAbstractXmlNodeModel.prototype.compareOrder = function(ni1, ni2){return new QXmlNodeModelIndex.DocumentOrder();};

/**
  * @name documentUri
  * @function
  * @memberOf QAbstractXmlNodeModel.prototype
  * @param {QXmlNodeModelIndex} ni
  * @returns {QUrl}
  */
QAbstractXmlNodeModel.prototype.documentUri = function(ni){return new QUrl();};

/**
  * @name elementById
  * @function
  * @memberOf QAbstractXmlNodeModel.prototype
  * @param {QXmlName} NCName
  * @returns {QXmlNodeModelIndex}
  */
QAbstractXmlNodeModel.prototype.elementById = function(NCName){return new QXmlNodeModelIndex();};

/**
  * @name kind
  * @function
  * @memberOf QAbstractXmlNodeModel.prototype
  * @param {QXmlNodeModelIndex} ni
  * @returns {QXmlNodeModelIndex.NodeKind}
  */
QAbstractXmlNodeModel.prototype.kind = function(ni){return new QXmlNodeModelIndex.NodeKind();};

/**
  * @name name
  * @function
  * @memberOf QAbstractXmlNodeModel.prototype
  * @param {QXmlNodeModelIndex} ni
  * @returns {QXmlName}
  */
QAbstractXmlNodeModel.prototype.name = function(ni){return new QXmlName();};

/**
  * @name namespaceBindings
  * @function
  * @memberOf QAbstractXmlNodeModel.prototype
  * @param {QXmlNodeModelIndex} n
  * @returns {Array}
  */
QAbstractXmlNodeModel.prototype.namespaceBindings = function(n){return new Array();};

/**
  * @name nodesByIdref
  * @function
  * @memberOf QAbstractXmlNodeModel.prototype
  * @param {QXmlName} NCName
  * @returns {Array}
  */
QAbstractXmlNodeModel.prototype.nodesByIdref = function(NCName){return new Array();};

/**
  * @name root
  * @function
  * @memberOf QAbstractXmlNodeModel.prototype
  * @param {QXmlNodeModelIndex} n
  * @returns {QXmlNodeModelIndex}
  */
QAbstractXmlNodeModel.prototype.root = function(n){return new QXmlNodeModelIndex();};

/**
  * @name sourceLocation
  * @function
  * @memberOf QAbstractXmlNodeModel.prototype
  * @param {QXmlNodeModelIndex} index
  * @returns {QSourceLocation}
  */
QAbstractXmlNodeModel.prototype.sourceLocation = function(index){return new QSourceLocation();};

/**
  * @name stringValue
  * @function
  * @memberOf QAbstractXmlNodeModel.prototype
  * @param {QXmlNodeModelIndex} n
  * @returns {String}
  */
QAbstractXmlNodeModel.prototype.stringValue = function(n){return new String();};

/**
  * @name typedValue
  * @function
  * @memberOf QAbstractXmlNodeModel.prototype
  * @param {QXmlNodeModelIndex} n
  * @returns {Object}
  */
QAbstractXmlNodeModel.prototype.typedValue = function(n){return new Object();};

