/**
  * @name QWizardPage
  * @constructor
  * @extends QWidget
  * @param {QWidget} parent
  */
function QWizardPage(parent){return undefined;};

QWizardPage.prototype = new QWidget();

/**
  * @name buttonText
  * @function
  * @memberOf QWizardPage.prototype
  * @param {QWizard.WizardButton} which
  * @returns {String}
  */
QWizardPage.prototype.buttonText = function(which){return new String();};

/**
  * @name cleanupPage
  * @function
  * @memberOf QWizardPage.prototype
  * @returns {undefined}
  */
QWizardPage.prototype.cleanupPage = function(){return undefined;};

/**
  * @name initializePage
  * @function
  * @memberOf QWizardPage.prototype
  * @returns {undefined}
  */
QWizardPage.prototype.initializePage = function(){return undefined;};

/**
  * @name isCommitPage
  * @function
  * @memberOf QWizardPage.prototype
  * @returns {Boolean}
  */
QWizardPage.prototype.isCommitPage = function(){return new Boolean();};

/**
  * @name isComplete
  * @function
  * @memberOf QWizardPage.prototype
  * @returns {Boolean}
  */
QWizardPage.prototype.isComplete = function(){return new Boolean();};

/**
  * @name isFinalPage
  * @function
  * @memberOf QWizardPage.prototype
  * @returns {Boolean}
  */
QWizardPage.prototype.isFinalPage = function(){return new Boolean();};

/**
  * @name nextId
  * @function
  * @memberOf QWizardPage.prototype
  * @returns {Numeric}
  */
QWizardPage.prototype.nextId = function(){return new Numeric();};

/**
  * @name pixmap
  * @function
  * @memberOf QWizardPage.prototype
  * @param {QWizard.WizardPixmap} which
  * @returns {QPixmap}
  */
QWizardPage.prototype.pixmap = function(which){return new QPixmap();};

/**
  * @name setButtonText
  * @function
  * @memberOf QWizardPage.prototype
  * @param {QWizard.WizardButton} which
  * @param {String} text
  * @returns {undefined}
  */
QWizardPage.prototype.setButtonText = function(which, text){return undefined;};

/**
  * @name setCommitPage
  * @function
  * @memberOf QWizardPage.prototype
  * @param {Boolean} commitPage
  * @returns {undefined}
  */
QWizardPage.prototype.setCommitPage = function(commitPage){return undefined;};

/**
  * @name setFinalPage
  * @function
  * @memberOf QWizardPage.prototype
  * @param {Boolean} finalPage
  * @returns {undefined}
  */
QWizardPage.prototype.setFinalPage = function(finalPage){return undefined;};

/**
  * @name setPixmap
  * @function
  * @memberOf QWizardPage.prototype
  * @param {QWizard.WizardPixmap} which
  * @param {QPixmap} pixmap
  * @returns {undefined}
  */
QWizardPage.prototype.setPixmap = function(which, pixmap){return undefined;};

/**
  * @name validatePage
  * @function
  * @memberOf QWizardPage.prototype
  * @returns {Boolean}
  */
QWizardPage.prototype.validatePage = function(){return new Boolean();};

/**
  * @name title
  * @memberOf QWizardPage.prototype
  * @type String
  */
QWizardPage.prototype.title = new String();

/**
  * @name subTitle
  * @memberOf QWizardPage.prototype
  * @type String
  */
QWizardPage.prototype.subTitle = new String();


