/**
  * @name QFormLayout
  * @constructor
  * @extends QLayout
  * @param {QWidget} parent
  */
function QFormLayout(parent){return undefined;};

QFormLayout.prototype = new QLayout();

/**
  * @default 0x0
  * @constant
  * @memberOf QFormLayout
  * @name FieldsStayAtSizeHint
  * @see QFormLayout#FieldGrowthPolicy
  * @type Number
  */
QFormLayout.FieldsStayAtSizeHint = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QFormLayout
  * @name ExpandingFieldsGrow
  * @see QFormLayout#FieldGrowthPolicy
  * @type Number
  */
QFormLayout.ExpandingFieldsGrow = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QFormLayout
  * @name AllNonFixedFieldsGrow
  * @see QFormLayout#FieldGrowthPolicy
  * @type Number
  */
QFormLayout.AllNonFixedFieldsGrow = 0x2;

/**
  * @constructor 
  * @memberOf QFormLayout
  * @name FieldGrowthPolicy
  */
QFormLayout.FieldGrowthPolicy = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QFormLayout
  * @name DontWrapRows
  * @see QFormLayout#RowWrapPolicy
  * @type Number
  */
QFormLayout.DontWrapRows = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QFormLayout
  * @name WrapLongRows
  * @see QFormLayout#RowWrapPolicy
  * @type Number
  */
QFormLayout.WrapLongRows = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QFormLayout
  * @name WrapAllRows
  * @see QFormLayout#RowWrapPolicy
  * @type Number
  */
QFormLayout.WrapAllRows = 0x2;

/**
  * @constructor 
  * @memberOf QFormLayout
  * @name RowWrapPolicy
  */
QFormLayout.RowWrapPolicy = function(value){;};



/**
  * @default 0
  * @constant
  * @memberOf QFormLayout
  * @name LabelRole
  * @see QFormLayout#ItemRole
  * @type Number
  */
QFormLayout.LabelRole = 0x0;

/**
  * @default 1
  * @constant
  * @memberOf QFormLayout
  * @name FieldRole
  * @see QFormLayout#ItemRole
  * @type Number
  */
QFormLayout.FieldRole = 0x1;

/**
  * @default 2
  * @constant
  * @memberOf QFormLayout
  * @name SpanningRole
  * @see QFormLayout#ItemRole
  * @type Number
  */
QFormLayout.SpanningRole = 0x2;

/**
  * @constructor 
  * @memberOf QFormLayout
  * @name ItemRole
  */
QFormLayout.ItemRole = function(value){;};



/**
  * @name addRow
  * @function
  * @memberOf QFormLayout.prototype
  * @param {QLayout} layout
  * @returns {undefined}
  */
QFormLayout.prototype.addRow = function(layout){return undefined;};

/**
  * @name getItemPosition
  * @function
  * @memberOf QFormLayout.prototype
  * @param {Numeric} index
  * @param {Numeric} rowPtr
  * @param {QFormLayout.ItemRole} rolePtr
  * @returns {undefined}
  */
QFormLayout.prototype.getItemPosition = function(index, rowPtr, rolePtr){return undefined;};

/**
  * @name getLayoutPosition
  * @function
  * @memberOf QFormLayout.prototype
  * @param {QLayout} layout
  * @param {Numeric} rowPtr
  * @param {QFormLayout.ItemRole} rolePtr
  * @returns {undefined}
  */
QFormLayout.prototype.getLayoutPosition = function(layout, rowPtr, rolePtr){return undefined;};

/**
  * @name getWidgetPosition
  * @function
  * @memberOf QFormLayout.prototype
  * @param {QWidget} widget
  * @param {Numeric} rowPtr
  * @param {QFormLayout.ItemRole} rolePtr
  * @returns {undefined}
  */
QFormLayout.prototype.getWidgetPosition = function(widget, rowPtr, rolePtr){return undefined;};

/**
  * @name insertRow
  * @function
  * @memberOf QFormLayout.prototype
  * @param {Numeric} row
  * @param {QLayout} layout
  * @returns {undefined}
  */
QFormLayout.prototype.insertRow = function(row, layout){return undefined;};

/**
  * @name itemAt
  * @function
  * @memberOf QFormLayout.prototype
  * @param {Numeric} row
  * @param {QFormLayout.ItemRole} role
  * @returns {QLayoutItem}
  */
QFormLayout.prototype.itemAt = function(row, role){return new QLayoutItem();};

/**
  * @name labelForField
  * @function
  * @memberOf QFormLayout.prototype
  * @param {QLayout} field
  * @returns {QWidget}
  */
QFormLayout.prototype.labelForField = function(field){return new QWidget();};

/**
  * @name rowCount
  * @function
  * @memberOf QFormLayout.prototype
  * @returns {Numeric}
  */
QFormLayout.prototype.rowCount = function(){return new Numeric();};

/**
  * @name setItem_private
  * @function
  * @memberOf QFormLayout.prototype
  * @param {Numeric} row
  * @param {QFormLayout.ItemRole} role
  * @param {QLayoutItem} item
  * @returns {undefined}
  */
QFormLayout.prototype.setItem_private = function(row, role, item){return undefined;};

/**
  * @name setLayout
  * @function
  * @memberOf QFormLayout.prototype
  * @param {Numeric} row
  * @param {QFormLayout.ItemRole} role
  * @param {QLayout} layout
  * @returns {undefined}
  */
QFormLayout.prototype.setLayout = function(row, role, layout){return undefined;};

/**
  * @name setSpacing
  * @function
  * @memberOf QFormLayout.prototype
  * @param {Numeric} arg__1
  * @returns {undefined}
  */
QFormLayout.prototype.setSpacing = function(arg__1){return undefined;};

/**
  * @name setWidget
  * @function
  * @memberOf QFormLayout.prototype
  * @param {Numeric} row
  * @param {QFormLayout.ItemRole} role
  * @param {QWidget} widget
  * @returns {undefined}
  */
QFormLayout.prototype.setWidget = function(row, role, widget){return undefined;};

/**
  * @name spacing
  * @function
  * @memberOf QFormLayout.prototype
  * @returns {Numeric}
  */
QFormLayout.prototype.spacing = function(){return new Numeric();};

/**
  * @name fieldGrowthPolicy
  * @memberOf QFormLayout.prototype
  * @type QFormLayout.FieldGrowthPolicy
  */
QFormLayout.prototype.fieldGrowthPolicy = new QFormLayout.FieldGrowthPolicy();

/**
  * @name rowWrapPolicy
  * @memberOf QFormLayout.prototype
  * @type QFormLayout.RowWrapPolicy
  */
QFormLayout.prototype.rowWrapPolicy = new QFormLayout.RowWrapPolicy();

/**
  * @name labelAlignment
  * @memberOf QFormLayout.prototype
  * @type Qt.Alignment
  */
QFormLayout.prototype.labelAlignment = new Qt.Alignment();

/**
  * @name formAlignment
  * @memberOf QFormLayout.prototype
  * @type Qt.Alignment
  */
QFormLayout.prototype.formAlignment = new Qt.Alignment();

/**
  * @name horizontalSpacing
  * @memberOf QFormLayout.prototype
  * @type Numeric
  */
QFormLayout.prototype.horizontalSpacing = new Numeric();

/**
  * @name verticalSpacing
  * @memberOf QFormLayout.prototype
  * @type Numeric
  */
QFormLayout.prototype.verticalSpacing = new Numeric();


