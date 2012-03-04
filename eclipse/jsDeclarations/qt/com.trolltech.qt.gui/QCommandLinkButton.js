/**
  * @name QCommandLinkButton
  * @constructor
  * @extends QPushButton
  * @param {QWidget} parent
  */
function QCommandLinkButton(parent){return undefined;};

/**
  * @name QCommandLinkButton^1
  * @constructor
  * @extends QPushButton
  * @param {String} text
  * @param {QWidget} parent
  */
function QCommandLinkButton(text, parent){return undefined;};

/**
  * @name QCommandLinkButton^2
  * @constructor
  * @extends QPushButton
  * @param {String} text
  * @param {String} description
  * @param {QWidget} parent
  */
function QCommandLinkButton(text, description, parent){return undefined;};

QCommandLinkButton.prototype = new QPushButton();

/**
  * @name description
  * @memberOf QCommandLinkButton.prototype
  * @type String
  */
QCommandLinkButton.prototype.description = new String();

/**
  * @name flat
  * @memberOf QCommandLinkButton.prototype
  * @type Boolean
  */
QCommandLinkButton.prototype.flat = new Boolean();


