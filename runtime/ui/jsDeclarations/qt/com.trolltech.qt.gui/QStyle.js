/**
  * @name QStyle
  * @constructor
  * @extends QObject
  */
function QStyle(){return undefined;};

QStyle.prototype = new QObject();

/**
  * @name alignedRect
  * @function
  * @memberOf QStyle
  * @param {QTextFormat.LayoutDirection} direction
  * @param {Qt.Alignment} alignment
  * @param {QSize} size
  * @param {QRect} rectangle
  * @returns {QRect}
  */
QStyle.alignedRect = function(direction, alignment, size, rectangle){return new QRect();};

/**
  * @name sliderPositionFromValue
  * @function
  * @memberOf QStyle
  * @param {Numeric} min
  * @param {Numeric} max
  * @param {Numeric} val
  * @param {Numeric} space
  * @param {Boolean} upsideDown
  * @returns {Numeric}
  */
QStyle.sliderPositionFromValue = function(min, max, val, space, upsideDown){return new Numeric();};

/**
  * @name sliderValueFromPosition
  * @function
  * @memberOf QStyle
  * @param {Numeric} min
  * @param {Numeric} max
  * @param {Numeric} pos
  * @param {Numeric} space
  * @param {Boolean} upsideDown
  * @returns {Numeric}
  */
QStyle.sliderValueFromPosition = function(min, max, pos, space, upsideDown){return new Numeric();};

/**
  * @name visualAlignment
  * @function
  * @memberOf QStyle
  * @param {QTextFormat.LayoutDirection} direction
  * @param {Qt.Alignment} alignment
  * @returns {Qt.Alignment}
  */
QStyle.visualAlignment = function(direction, alignment){return new Qt.Alignment();};

/**
  * @name visualPos
  * @function
  * @memberOf QStyle
  * @param {QTextFormat.LayoutDirection} direction
  * @param {QRect} boundingRect
  * @param {QPoint} logicalPos
  * @returns {QPoint}
  */
QStyle.visualPos = function(direction, boundingRect, logicalPos){return new QPoint();};

/**
  * @name visualRect
  * @function
  * @memberOf QStyle
  * @param {QTextFormat.LayoutDirection} direction
  * @param {QRect} boundingRect
  * @param {QRect} logicalRect
  * @returns {QRect}
  */
QStyle.visualRect = function(direction, boundingRect, logicalRect){return new QRect();};

/**
  * @default 0xf0000000
  * @constant
  * @memberOf QStyle
  * @name PM_CustomBase
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_CustomBase = 0xf0000000;

/**
  * @default 0x0
  * @constant
  * @memberOf QStyle
  * @name PM_ButtonMargin
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_ButtonMargin = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QStyle
  * @name PM_ButtonDefaultIndicator
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_ButtonDefaultIndicator = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QStyle
  * @name PM_MenuButtonIndicator
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_MenuButtonIndicator = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QStyle
  * @name PM_ButtonShiftHorizontal
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_ButtonShiftHorizontal = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QStyle
  * @name PM_ButtonShiftVertical
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_ButtonShiftVertical = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QStyle
  * @name PM_DefaultFrameWidth
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_DefaultFrameWidth = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf QStyle
  * @name PM_SpinBoxFrameWidth
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_SpinBoxFrameWidth = 0x6;

/**
  * @default 0x7
  * @constant
  * @memberOf QStyle
  * @name PM_ComboBoxFrameWidth
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_ComboBoxFrameWidth = 0x7;

/**
  * @default 0x8
  * @constant
  * @memberOf QStyle
  * @name PM_MaximumDragDistance
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_MaximumDragDistance = 0x8;

/**
  * @default 0x9
  * @constant
  * @memberOf QStyle
  * @name PM_ScrollBarExtent
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_ScrollBarExtent = 0x9;

/**
  * @default 0xa
  * @constant
  * @memberOf QStyle
  * @name PM_ScrollBarSliderMin
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_ScrollBarSliderMin = 0xa;

/**
  * @default 0xb
  * @constant
  * @memberOf QStyle
  * @name PM_SliderThickness
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_SliderThickness = 0xb;

/**
  * @default 0xc
  * @constant
  * @memberOf QStyle
  * @name PM_SliderControlThickness
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_SliderControlThickness = 0xc;

/**
  * @default 0xd
  * @constant
  * @memberOf QStyle
  * @name PM_SliderLength
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_SliderLength = 0xd;

/**
  * @default 0xe
  * @constant
  * @memberOf QStyle
  * @name PM_SliderTickmarkOffset
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_SliderTickmarkOffset = 0xe;

/**
  * @default 0xf
  * @constant
  * @memberOf QStyle
  * @name PM_SliderSpaceAvailable
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_SliderSpaceAvailable = 0xf;

/**
  * @default 0x10
  * @constant
  * @memberOf QStyle
  * @name PM_DockWidgetSeparatorExtent
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_DockWidgetSeparatorExtent = 0x10;

/**
  * @default 0x11
  * @constant
  * @memberOf QStyle
  * @name PM_DockWidgetHandleExtent
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_DockWidgetHandleExtent = 0x11;

/**
  * @default 0x12
  * @constant
  * @memberOf QStyle
  * @name PM_DockWidgetFrameWidth
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_DockWidgetFrameWidth = 0x12;

/**
  * @default 0x13
  * @constant
  * @memberOf QStyle
  * @name PM_TabBarTabOverlap
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_TabBarTabOverlap = 0x13;

/**
  * @default 0x14
  * @constant
  * @memberOf QStyle
  * @name PM_TabBarTabHSpace
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_TabBarTabHSpace = 0x14;

/**
  * @default 0x15
  * @constant
  * @memberOf QStyle
  * @name PM_TabBarTabVSpace
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_TabBarTabVSpace = 0x15;

/**
  * @default 0x16
  * @constant
  * @memberOf QStyle
  * @name PM_TabBarBaseHeight
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_TabBarBaseHeight = 0x16;

/**
  * @default 0x17
  * @constant
  * @memberOf QStyle
  * @name PM_TabBarBaseOverlap
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_TabBarBaseOverlap = 0x17;

/**
  * @default 0x18
  * @constant
  * @memberOf QStyle
  * @name PM_ProgressBarChunkWidth
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_ProgressBarChunkWidth = 0x18;

/**
  * @default 0x19
  * @constant
  * @memberOf QStyle
  * @name PM_SplitterWidth
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_SplitterWidth = 0x19;

/**
  * @default 0x1a
  * @constant
  * @memberOf QStyle
  * @name PM_TitleBarHeight
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_TitleBarHeight = 0x1a;

/**
  * @default 0x1b
  * @constant
  * @memberOf QStyle
  * @name PM_MenuScrollerHeight
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_MenuScrollerHeight = 0x1b;

/**
  * @default 0x1c
  * @constant
  * @memberOf QStyle
  * @name PM_MenuHMargin
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_MenuHMargin = 0x1c;

/**
  * @default 0x1d
  * @constant
  * @memberOf QStyle
  * @name PM_MenuVMargin
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_MenuVMargin = 0x1d;

/**
  * @default 0x1e
  * @constant
  * @memberOf QStyle
  * @name PM_MenuPanelWidth
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_MenuPanelWidth = 0x1e;

/**
  * @default 0x1f
  * @constant
  * @memberOf QStyle
  * @name PM_MenuTearoffHeight
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_MenuTearoffHeight = 0x1f;

/**
  * @default 0x20
  * @constant
  * @memberOf QStyle
  * @name PM_MenuDesktopFrameWidth
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_MenuDesktopFrameWidth = 0x20;

/**
  * @default 0x21
  * @constant
  * @memberOf QStyle
  * @name PM_MenuBarPanelWidth
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_MenuBarPanelWidth = 0x21;

/**
  * @default 0x22
  * @constant
  * @memberOf QStyle
  * @name PM_MenuBarItemSpacing
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_MenuBarItemSpacing = 0x22;

/**
  * @default 0x23
  * @constant
  * @memberOf QStyle
  * @name PM_MenuBarVMargin
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_MenuBarVMargin = 0x23;

/**
  * @default 0x24
  * @constant
  * @memberOf QStyle
  * @name PM_MenuBarHMargin
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_MenuBarHMargin = 0x24;

/**
  * @default 0x25
  * @constant
  * @memberOf QStyle
  * @name PM_IndicatorWidth
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_IndicatorWidth = 0x25;

/**
  * @default 0x26
  * @constant
  * @memberOf QStyle
  * @name PM_IndicatorHeight
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_IndicatorHeight = 0x26;

/**
  * @default 0x27
  * @constant
  * @memberOf QStyle
  * @name PM_ExclusiveIndicatorWidth
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_ExclusiveIndicatorWidth = 0x27;

/**
  * @default 0x28
  * @constant
  * @memberOf QStyle
  * @name PM_ExclusiveIndicatorHeight
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_ExclusiveIndicatorHeight = 0x28;

/**
  * @default 0x29
  * @constant
  * @memberOf QStyle
  * @name PM_CheckListButtonSize
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_CheckListButtonSize = 0x29;

/**
  * @default 0x2a
  * @constant
  * @memberOf QStyle
  * @name PM_CheckListControllerSize
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_CheckListControllerSize = 0x2a;

/**
  * @default 0x2b
  * @constant
  * @memberOf QStyle
  * @name PM_DialogButtonsSeparator
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_DialogButtonsSeparator = 0x2b;

/**
  * @default 0x2c
  * @constant
  * @memberOf QStyle
  * @name PM_DialogButtonsButtonWidth
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_DialogButtonsButtonWidth = 0x2c;

/**
  * @default 0x2d
  * @constant
  * @memberOf QStyle
  * @name PM_DialogButtonsButtonHeight
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_DialogButtonsButtonHeight = 0x2d;

/**
  * @default 0x2e
  * @constant
  * @memberOf QStyle
  * @name PM_MdiSubWindowFrameWidth
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_MdiSubWindowFrameWidth = 0x2e;

/**
  * @default 0x2f
  * @constant
  * @memberOf QStyle
  * @name PM_MdiSubWindowMinimizedWidth
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_MdiSubWindowMinimizedWidth = 0x2f;

/**
  * @default 0x30
  * @constant
  * @memberOf QStyle
  * @name PM_HeaderMargin
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_HeaderMargin = 0x30;

/**
  * @default 0x31
  * @constant
  * @memberOf QStyle
  * @name PM_HeaderMarkSize
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_HeaderMarkSize = 0x31;

/**
  * @default 0x32
  * @constant
  * @memberOf QStyle
  * @name PM_HeaderGripMargin
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_HeaderGripMargin = 0x32;

/**
  * @default 0x33
  * @constant
  * @memberOf QStyle
  * @name PM_TabBarTabShiftHorizontal
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_TabBarTabShiftHorizontal = 0x33;

/**
  * @default 0x34
  * @constant
  * @memberOf QStyle
  * @name PM_TabBarTabShiftVertical
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_TabBarTabShiftVertical = 0x34;

/**
  * @default 0x35
  * @constant
  * @memberOf QStyle
  * @name PM_TabBarScrollButtonWidth
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_TabBarScrollButtonWidth = 0x35;

/**
  * @default 0x36
  * @constant
  * @memberOf QStyle
  * @name PM_ToolBarFrameWidth
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_ToolBarFrameWidth = 0x36;

/**
  * @default 0x37
  * @constant
  * @memberOf QStyle
  * @name PM_ToolBarHandleExtent
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_ToolBarHandleExtent = 0x37;

/**
  * @default 0x38
  * @constant
  * @memberOf QStyle
  * @name PM_ToolBarItemSpacing
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_ToolBarItemSpacing = 0x38;

/**
  * @default 0x39
  * @constant
  * @memberOf QStyle
  * @name PM_ToolBarItemMargin
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_ToolBarItemMargin = 0x39;

/**
  * @default 0x3a
  * @constant
  * @memberOf QStyle
  * @name PM_ToolBarSeparatorExtent
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_ToolBarSeparatorExtent = 0x3a;

/**
  * @default 0x3b
  * @constant
  * @memberOf QStyle
  * @name PM_ToolBarExtensionExtent
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_ToolBarExtensionExtent = 0x3b;

/**
  * @default 0x3c
  * @constant
  * @memberOf QStyle
  * @name PM_SpinBoxSliderHeight
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_SpinBoxSliderHeight = 0x3c;

/**
  * @default 0x3d
  * @constant
  * @memberOf QStyle
  * @name PM_DefaultTopLevelMargin
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_DefaultTopLevelMargin = 0x3d;

/**
  * @default 0x3e
  * @constant
  * @memberOf QStyle
  * @name PM_DefaultChildMargin
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_DefaultChildMargin = 0x3e;

/**
  * @default 0x3f
  * @constant
  * @memberOf QStyle
  * @name PM_DefaultLayoutSpacing
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_DefaultLayoutSpacing = 0x3f;

/**
  * @default 0x40
  * @constant
  * @memberOf QStyle
  * @name PM_ToolBarIconSize
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_ToolBarIconSize = 0x40;

/**
  * @default 0x41
  * @constant
  * @memberOf QStyle
  * @name PM_ListViewIconSize
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_ListViewIconSize = 0x41;

/**
  * @default 0x42
  * @constant
  * @memberOf QStyle
  * @name PM_IconViewIconSize
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_IconViewIconSize = 0x42;

/**
  * @default 0x43
  * @constant
  * @memberOf QStyle
  * @name PM_SmallIconSize
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_SmallIconSize = 0x43;

/**
  * @default 0x44
  * @constant
  * @memberOf QStyle
  * @name PM_LargeIconSize
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_LargeIconSize = 0x44;

/**
  * @default 0x45
  * @constant
  * @memberOf QStyle
  * @name PM_FocusFrameVMargin
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_FocusFrameVMargin = 0x45;

/**
  * @default 0x46
  * @constant
  * @memberOf QStyle
  * @name PM_FocusFrameHMargin
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_FocusFrameHMargin = 0x46;

/**
  * @default 0x47
  * @constant
  * @memberOf QStyle
  * @name PM_ToolTipLabelFrameWidth
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_ToolTipLabelFrameWidth = 0x47;

/**
  * @default 0x48
  * @constant
  * @memberOf QStyle
  * @name PM_CheckBoxLabelSpacing
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_CheckBoxLabelSpacing = 0x48;

/**
  * @default 0x49
  * @constant
  * @memberOf QStyle
  * @name PM_TabBarIconSize
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_TabBarIconSize = 0x49;

/**
  * @default 0x4a
  * @constant
  * @memberOf QStyle
  * @name PM_SizeGripSize
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_SizeGripSize = 0x4a;

/**
  * @default 0x4b
  * @constant
  * @memberOf QStyle
  * @name PM_DockWidgetTitleMargin
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_DockWidgetTitleMargin = 0x4b;

/**
  * @default 0x4c
  * @constant
  * @memberOf QStyle
  * @name PM_MessageBoxIconSize
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_MessageBoxIconSize = 0x4c;

/**
  * @default 0x4d
  * @constant
  * @memberOf QStyle
  * @name PM_ButtonIconSize
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_ButtonIconSize = 0x4d;

/**
  * @default 0x4e
  * @constant
  * @memberOf QStyle
  * @name PM_DockWidgetTitleBarButtonMargin
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_DockWidgetTitleBarButtonMargin = 0x4e;

/**
  * @default 0x4f
  * @constant
  * @memberOf QStyle
  * @name PM_RadioButtonLabelSpacing
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_RadioButtonLabelSpacing = 0x4f;

/**
  * @default 0x50
  * @constant
  * @memberOf QStyle
  * @name PM_LayoutLeftMargin
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_LayoutLeftMargin = 0x50;

/**
  * @default 0x51
  * @constant
  * @memberOf QStyle
  * @name PM_LayoutTopMargin
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_LayoutTopMargin = 0x51;

/**
  * @default 0x52
  * @constant
  * @memberOf QStyle
  * @name PM_LayoutRightMargin
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_LayoutRightMargin = 0x52;

/**
  * @default 0x53
  * @constant
  * @memberOf QStyle
  * @name PM_LayoutBottomMargin
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_LayoutBottomMargin = 0x53;

/**
  * @default 0x54
  * @constant
  * @memberOf QStyle
  * @name PM_LayoutHorizontalSpacing
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_LayoutHorizontalSpacing = 0x54;

/**
  * @default 0x55
  * @constant
  * @memberOf QStyle
  * @name PM_LayoutVerticalSpacing
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_LayoutVerticalSpacing = 0x55;

/**
  * @default 0x56
  * @constant
  * @memberOf QStyle
  * @name PM_TabBar_ScrollButtonOverlap
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_TabBar_ScrollButtonOverlap = 0x56;

/**
  * @default 0x57
  * @constant
  * @memberOf QStyle
  * @name PM_TextCursorWidth
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_TextCursorWidth = 0x57;

/**
  * @default 0x58
  * @constant
  * @memberOf QStyle
  * @name PM_TabCloseIndicatorWidth
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_TabCloseIndicatorWidth = 0x58;

/**
  * @default 0x59
  * @constant
  * @memberOf QStyle
  * @name PM_TabCloseIndicatorHeight
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_TabCloseIndicatorHeight = 0x59;

/**
  * @default 0x5a
  * @constant
  * @memberOf QStyle
  * @name PM_ScrollView_ScrollBarSpacing
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_ScrollView_ScrollBarSpacing = 0x5a;

/**
  * @default 0x5b
  * @constant
  * @memberOf QStyle
  * @name PM_SubMenuOverlap
  * @see QStyle#PixelMetric
  * @type Number
  */
QStyle.PM_SubMenuOverlap = 0x5b;

/**
  * @constructor 
  * @memberOf QStyle
  * @name PixelMetric
  */
QStyle.PixelMetric = function(value){;};



/**
  * @default 0xf0000000
  * @constant
  * @memberOf QStyle
  * @name SC_CustomBase
  * @see QStyle#SubControls
  * @see QStyle#SubControl
  * @type Number
  */
QStyle.SC_CustomBase = 0xf0000000;

/**
  * @default 0xffffffff
  * @constant
  * @memberOf QStyle
  * @name SC_All
  * @see QStyle#SubControls
  * @see QStyle#SubControl
  * @type Number
  */
QStyle.SC_All = 0xffffffff;

/**
  * @default 0x00000000
  * @constant
  * @memberOf QStyle
  * @name SC_None
  * @see QStyle#SubControls
  * @see QStyle#SubControl
  * @type Number
  */
QStyle.SC_None = 0x0;

/**
  * @default 0x00000001
  * @constant
  * @memberOf QStyle
  * @name SC_ScrollBarAddLine
  * @see QStyle#SubControls
  * @see QStyle#SubControl
  * @type Number
  */
QStyle.SC_ScrollBarAddLine = 0x1;

/**
  * @default 0x00000002
  * @constant
  * @memberOf QStyle
  * @name SC_ScrollBarSubLine
  * @see QStyle#SubControls
  * @see QStyle#SubControl
  * @type Number
  */
QStyle.SC_ScrollBarSubLine = 0x2;

/**
  * @default 0x00000004
  * @constant
  * @memberOf QStyle
  * @name SC_ScrollBarAddPage
  * @see QStyle#SubControls
  * @see QStyle#SubControl
  * @type Number
  */
QStyle.SC_ScrollBarAddPage = 0x4;

/**
  * @default 0x00000008
  * @constant
  * @memberOf QStyle
  * @name SC_ScrollBarSubPage
  * @see QStyle#SubControls
  * @see QStyle#SubControl
  * @type Number
  */
QStyle.SC_ScrollBarSubPage = 0x8;

/**
  * @default 0x00000010
  * @constant
  * @memberOf QStyle
  * @name SC_ScrollBarFirst
  * @see QStyle#SubControls
  * @see QStyle#SubControl
  * @type Number
  */
QStyle.SC_ScrollBarFirst = 0x10;

/**
  * @default 0x00000020
  * @constant
  * @memberOf QStyle
  * @name SC_ScrollBarLast
  * @see QStyle#SubControls
  * @see QStyle#SubControl
  * @type Number
  */
QStyle.SC_ScrollBarLast = 0x20;

/**
  * @default 0x00000040
  * @constant
  * @memberOf QStyle
  * @name SC_ScrollBarSlider
  * @see QStyle#SubControls
  * @see QStyle#SubControl
  * @type Number
  */
QStyle.SC_ScrollBarSlider = 0x40;

/**
  * @default 0x00000080
  * @constant
  * @memberOf QStyle
  * @name SC_ScrollBarGroove
  * @see QStyle#SubControls
  * @see QStyle#SubControl
  * @type Number
  */
QStyle.SC_ScrollBarGroove = 0x80;

/**
  * @default 0x00000100
  * @constant
  * @memberOf QStyle
  * @name SC_TitleBarLabel
  * @see QStyle#SubControls
  * @see QStyle#SubControl
  * @type Number
  */
QStyle.SC_TitleBarLabel = 0x100;

/**
  * @constructor 
  * @memberOf QStyle
  * @name SubControl
  */
QStyle.SubControl = function(value){;};

/**
  * @constructor 
  * @memberOf QStyle
  * @name SubControls
  */
QStyle.SubControls = function(value1, value2 /*, ...*/){;};


/**
  * @default 0xf0000000
  * @constant
  * @memberOf QStyle
  * @name SP_CustomBase
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_CustomBase = 0xf0000000;

/**
  * @default 0x0
  * @constant
  * @memberOf QStyle
  * @name SP_TitleBarMenuButton
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_TitleBarMenuButton = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QStyle
  * @name SP_TitleBarMinButton
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_TitleBarMinButton = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QStyle
  * @name SP_TitleBarMaxButton
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_TitleBarMaxButton = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QStyle
  * @name SP_TitleBarCloseButton
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_TitleBarCloseButton = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QStyle
  * @name SP_TitleBarNormalButton
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_TitleBarNormalButton = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QStyle
  * @name SP_TitleBarShadeButton
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_TitleBarShadeButton = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf QStyle
  * @name SP_TitleBarUnshadeButton
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_TitleBarUnshadeButton = 0x6;

/**
  * @default 0x7
  * @constant
  * @memberOf QStyle
  * @name SP_TitleBarContextHelpButton
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_TitleBarContextHelpButton = 0x7;

/**
  * @default 0x8
  * @constant
  * @memberOf QStyle
  * @name SP_DockWidgetCloseButton
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_DockWidgetCloseButton = 0x8;

/**
  * @default 0x9
  * @constant
  * @memberOf QStyle
  * @name SP_MessageBoxInformation
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_MessageBoxInformation = 0x9;

/**
  * @default 0xa
  * @constant
  * @memberOf QStyle
  * @name SP_MessageBoxWarning
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_MessageBoxWarning = 0xa;

/**
  * @default 0xb
  * @constant
  * @memberOf QStyle
  * @name SP_MessageBoxCritical
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_MessageBoxCritical = 0xb;

/**
  * @default 0xc
  * @constant
  * @memberOf QStyle
  * @name SP_MessageBoxQuestion
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_MessageBoxQuestion = 0xc;

/**
  * @default 0xd
  * @constant
  * @memberOf QStyle
  * @name SP_DesktopIcon
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_DesktopIcon = 0xd;

/**
  * @default 0xe
  * @constant
  * @memberOf QStyle
  * @name SP_TrashIcon
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_TrashIcon = 0xe;

/**
  * @default 0xf
  * @constant
  * @memberOf QStyle
  * @name SP_ComputerIcon
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_ComputerIcon = 0xf;

/**
  * @default 0x10
  * @constant
  * @memberOf QStyle
  * @name SP_DriveFDIcon
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_DriveFDIcon = 0x10;

/**
  * @default 0x11
  * @constant
  * @memberOf QStyle
  * @name SP_DriveHDIcon
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_DriveHDIcon = 0x11;

/**
  * @default 0x12
  * @constant
  * @memberOf QStyle
  * @name SP_DriveCDIcon
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_DriveCDIcon = 0x12;

/**
  * @default 0x13
  * @constant
  * @memberOf QStyle
  * @name SP_DriveDVDIcon
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_DriveDVDIcon = 0x13;

/**
  * @default 0x14
  * @constant
  * @memberOf QStyle
  * @name SP_DriveNetIcon
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_DriveNetIcon = 0x14;

/**
  * @default 0x15
  * @constant
  * @memberOf QStyle
  * @name SP_DirOpenIcon
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_DirOpenIcon = 0x15;

/**
  * @default 0x16
  * @constant
  * @memberOf QStyle
  * @name SP_DirClosedIcon
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_DirClosedIcon = 0x16;

/**
  * @default 0x17
  * @constant
  * @memberOf QStyle
  * @name SP_DirLinkIcon
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_DirLinkIcon = 0x17;

/**
  * @default 0x18
  * @constant
  * @memberOf QStyle
  * @name SP_FileIcon
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_FileIcon = 0x18;

/**
  * @default 0x19
  * @constant
  * @memberOf QStyle
  * @name SP_FileLinkIcon
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_FileLinkIcon = 0x19;

/**
  * @default 0x1a
  * @constant
  * @memberOf QStyle
  * @name SP_ToolBarHorizontalExtensionButton
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_ToolBarHorizontalExtensionButton = 0x1a;

/**
  * @default 0x1b
  * @constant
  * @memberOf QStyle
  * @name SP_ToolBarVerticalExtensionButton
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_ToolBarVerticalExtensionButton = 0x1b;

/**
  * @default 0x1c
  * @constant
  * @memberOf QStyle
  * @name SP_FileDialogStart
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_FileDialogStart = 0x1c;

/**
  * @default 0x1d
  * @constant
  * @memberOf QStyle
  * @name SP_FileDialogEnd
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_FileDialogEnd = 0x1d;

/**
  * @default 0x1e
  * @constant
  * @memberOf QStyle
  * @name SP_FileDialogToParent
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_FileDialogToParent = 0x1e;

/**
  * @default 0x1f
  * @constant
  * @memberOf QStyle
  * @name SP_FileDialogNewFolder
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_FileDialogNewFolder = 0x1f;

/**
  * @default 0x20
  * @constant
  * @memberOf QStyle
  * @name SP_FileDialogDetailedView
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_FileDialogDetailedView = 0x20;

/**
  * @default 0x21
  * @constant
  * @memberOf QStyle
  * @name SP_FileDialogInfoView
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_FileDialogInfoView = 0x21;

/**
  * @default 0x22
  * @constant
  * @memberOf QStyle
  * @name SP_FileDialogContentsView
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_FileDialogContentsView = 0x22;

/**
  * @default 0x23
  * @constant
  * @memberOf QStyle
  * @name SP_FileDialogListView
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_FileDialogListView = 0x23;

/**
  * @default 0x24
  * @constant
  * @memberOf QStyle
  * @name SP_FileDialogBack
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_FileDialogBack = 0x24;

/**
  * @default 0x25
  * @constant
  * @memberOf QStyle
  * @name SP_DirIcon
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_DirIcon = 0x25;

/**
  * @default 0x26
  * @constant
  * @memberOf QStyle
  * @name SP_DialogOkButton
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_DialogOkButton = 0x26;

/**
  * @default 0x27
  * @constant
  * @memberOf QStyle
  * @name SP_DialogCancelButton
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_DialogCancelButton = 0x27;

/**
  * @default 0x28
  * @constant
  * @memberOf QStyle
  * @name SP_DialogHelpButton
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_DialogHelpButton = 0x28;

/**
  * @default 0x29
  * @constant
  * @memberOf QStyle
  * @name SP_DialogOpenButton
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_DialogOpenButton = 0x29;

/**
  * @default 0x2a
  * @constant
  * @memberOf QStyle
  * @name SP_DialogSaveButton
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_DialogSaveButton = 0x2a;

/**
  * @default 0x2b
  * @constant
  * @memberOf QStyle
  * @name SP_DialogCloseButton
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_DialogCloseButton = 0x2b;

/**
  * @default 0x2c
  * @constant
  * @memberOf QStyle
  * @name SP_DialogApplyButton
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_DialogApplyButton = 0x2c;

/**
  * @default 0x2d
  * @constant
  * @memberOf QStyle
  * @name SP_DialogResetButton
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_DialogResetButton = 0x2d;

/**
  * @default 0x2e
  * @constant
  * @memberOf QStyle
  * @name SP_DialogDiscardButton
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_DialogDiscardButton = 0x2e;

/**
  * @default 0x2f
  * @constant
  * @memberOf QStyle
  * @name SP_DialogYesButton
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_DialogYesButton = 0x2f;

/**
  * @default 0x30
  * @constant
  * @memberOf QStyle
  * @name SP_DialogNoButton
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_DialogNoButton = 0x30;

/**
  * @default 0x31
  * @constant
  * @memberOf QStyle
  * @name SP_ArrowUp
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_ArrowUp = 0x31;

/**
  * @default 0x32
  * @constant
  * @memberOf QStyle
  * @name SP_ArrowDown
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_ArrowDown = 0x32;

/**
  * @default 0x33
  * @constant
  * @memberOf QStyle
  * @name SP_ArrowLeft
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_ArrowLeft = 0x33;

/**
  * @default 0x34
  * @constant
  * @memberOf QStyle
  * @name SP_ArrowRight
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_ArrowRight = 0x34;

/**
  * @default 0x35
  * @constant
  * @memberOf QStyle
  * @name SP_ArrowBack
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_ArrowBack = 0x35;

/**
  * @default 0x36
  * @constant
  * @memberOf QStyle
  * @name SP_ArrowForward
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_ArrowForward = 0x36;

/**
  * @default 0x37
  * @constant
  * @memberOf QStyle
  * @name SP_DirHomeIcon
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_DirHomeIcon = 0x37;

/**
  * @default 0x38
  * @constant
  * @memberOf QStyle
  * @name SP_CommandLink
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_CommandLink = 0x38;

/**
  * @default 0x39
  * @constant
  * @memberOf QStyle
  * @name SP_VistaShield
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_VistaShield = 0x39;

/**
  * @default 0x3a
  * @constant
  * @memberOf QStyle
  * @name SP_BrowserReload
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_BrowserReload = 0x3a;

/**
  * @default 0x3b
  * @constant
  * @memberOf QStyle
  * @name SP_BrowserStop
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_BrowserStop = 0x3b;

/**
  * @default 0x3c
  * @constant
  * @memberOf QStyle
  * @name SP_MediaPlay
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_MediaPlay = 0x3c;

/**
  * @default 0x3d
  * @constant
  * @memberOf QStyle
  * @name SP_MediaStop
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_MediaStop = 0x3d;

/**
  * @default 0x3e
  * @constant
  * @memberOf QStyle
  * @name SP_MediaPause
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_MediaPause = 0x3e;

/**
  * @default 0x3f
  * @constant
  * @memberOf QStyle
  * @name SP_MediaSkipForward
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_MediaSkipForward = 0x3f;

/**
  * @default 0x40
  * @constant
  * @memberOf QStyle
  * @name SP_MediaSkipBackward
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_MediaSkipBackward = 0x40;

/**
  * @default 0x41
  * @constant
  * @memberOf QStyle
  * @name SP_MediaSeekForward
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_MediaSeekForward = 0x41;

/**
  * @default 0x42
  * @constant
  * @memberOf QStyle
  * @name SP_MediaSeekBackward
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_MediaSeekBackward = 0x42;

/**
  * @default 0x43
  * @constant
  * @memberOf QStyle
  * @name SP_MediaVolume
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_MediaVolume = 0x43;

/**
  * @default 0x44
  * @constant
  * @memberOf QStyle
  * @name SP_MediaVolumeMuted
  * @see QStyle#StandardPixmap
  * @type Number
  */
QStyle.SP_MediaVolumeMuted = 0x44;

/**
  * @constructor 
  * @memberOf QStyle
  * @name StandardPixmap
  */
QStyle.StandardPixmap = function(value){;};



/**
  * @default 0xf0000000
  * @constant
  * @memberOf QStyle
  * @name SH_CustomBase
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_CustomBase = 0xf0000000;

/**
  * @default 0x0
  * @constant
  * @memberOf QStyle
  * @name SH_EtchDisabledText
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_EtchDisabledText = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QStyle
  * @name SH_DitherDisabledText
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_DitherDisabledText = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QStyle
  * @name SH_ScrollBar_MiddleClickAbsolutePosition
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_ScrollBar_MiddleClickAbsolutePosition = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QStyle
  * @name SH_ScrollBar_ScrollWhenPointerLeavesControl
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_ScrollBar_ScrollWhenPointerLeavesControl = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QStyle
  * @name SH_TabBar_SelectMouseType
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_TabBar_SelectMouseType = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QStyle
  * @name SH_TabBar_Alignment
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_TabBar_Alignment = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf QStyle
  * @name SH_Header_ArrowAlignment
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_Header_ArrowAlignment = 0x6;

/**
  * @default 0x7
  * @constant
  * @memberOf QStyle
  * @name SH_Slider_SnapToValue
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_Slider_SnapToValue = 0x7;

/**
  * @default 0x8
  * @constant
  * @memberOf QStyle
  * @name SH_Slider_SloppyKeyEvents
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_Slider_SloppyKeyEvents = 0x8;

/**
  * @default 0x9
  * @constant
  * @memberOf QStyle
  * @name SH_ProgressDialog_CenterCancelButton
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_ProgressDialog_CenterCancelButton = 0x9;

/**
  * @default 0xa
  * @constant
  * @memberOf QStyle
  * @name SH_ProgressDialog_TextLabelAlignment
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_ProgressDialog_TextLabelAlignment = 0xa;

/**
  * @default 0xb
  * @constant
  * @memberOf QStyle
  * @name SH_PrintDialog_RightAlignButtons
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_PrintDialog_RightAlignButtons = 0xb;

/**
  * @default 0xc
  * @constant
  * @memberOf QStyle
  * @name SH_MainWindow_SpaceBelowMenuBar
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_MainWindow_SpaceBelowMenuBar = 0xc;

/**
  * @default 0xd
  * @constant
  * @memberOf QStyle
  * @name SH_FontDialog_SelectAssociatedText
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_FontDialog_SelectAssociatedText = 0xd;

/**
  * @default 0xe
  * @constant
  * @memberOf QStyle
  * @name SH_Menu_AllowActiveAndDisabled
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_Menu_AllowActiveAndDisabled = 0xe;

/**
  * @default 0xf
  * @constant
  * @memberOf QStyle
  * @name SH_Menu_SpaceActivatesItem
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_Menu_SpaceActivatesItem = 0xf;

/**
  * @default 0x10
  * @constant
  * @memberOf QStyle
  * @name SH_Menu_SubMenuPopupDelay
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_Menu_SubMenuPopupDelay = 0x10;

/**
  * @default 0x11
  * @constant
  * @memberOf QStyle
  * @name SH_ScrollView_FrameOnlyAroundContents
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_ScrollView_FrameOnlyAroundContents = 0x11;

/**
  * @default 0x12
  * @constant
  * @memberOf QStyle
  * @name SH_MenuBar_AltKeyNavigation
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_MenuBar_AltKeyNavigation = 0x12;

/**
  * @default 0x13
  * @constant
  * @memberOf QStyle
  * @name SH_ComboBox_ListMouseTracking
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_ComboBox_ListMouseTracking = 0x13;

/**
  * @default 0x14
  * @constant
  * @memberOf QStyle
  * @name SH_Menu_MouseTracking
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_Menu_MouseTracking = 0x14;

/**
  * @default 0x15
  * @constant
  * @memberOf QStyle
  * @name SH_MenuBar_MouseTracking
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_MenuBar_MouseTracking = 0x15;

/**
  * @default 0x16
  * @constant
  * @memberOf QStyle
  * @name SH_ItemView_ChangeHighlightOnFocus
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_ItemView_ChangeHighlightOnFocus = 0x16;

/**
  * @default 0x17
  * @constant
  * @memberOf QStyle
  * @name SH_Widget_ShareActivation
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_Widget_ShareActivation = 0x17;

/**
  * @default 0x18
  * @constant
  * @memberOf QStyle
  * @name SH_Workspace_FillSpaceOnMaximize
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_Workspace_FillSpaceOnMaximize = 0x18;

/**
  * @default 0x19
  * @constant
  * @memberOf QStyle
  * @name SH_ComboBox_Popup
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_ComboBox_Popup = 0x19;

/**
  * @default 0x1a
  * @constant
  * @memberOf QStyle
  * @name SH_TitleBar_NoBorder
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_TitleBar_NoBorder = 0x1a;

/**
  * @default 0x1b
  * @constant
  * @memberOf QStyle
  * @name SH_Slider_StopMouseOverSlider
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_Slider_StopMouseOverSlider = 0x1b;

/**
  * @default 0x1c
  * @constant
  * @memberOf QStyle
  * @name SH_BlinkCursorWhenTextSelected
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_BlinkCursorWhenTextSelected = 0x1c;

/**
  * @default 0x1d
  * @constant
  * @memberOf QStyle
  * @name SH_RichText_FullWidthSelection
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_RichText_FullWidthSelection = 0x1d;

/**
  * @default 0x1e
  * @constant
  * @memberOf QStyle
  * @name SH_Menu_Scrollable
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_Menu_Scrollable = 0x1e;

/**
  * @default 0x1f
  * @constant
  * @memberOf QStyle
  * @name SH_GroupBox_TextLabelVerticalAlignment
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_GroupBox_TextLabelVerticalAlignment = 0x1f;

/**
  * @default 0x20
  * @constant
  * @memberOf QStyle
  * @name SH_GroupBox_TextLabelColor
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_GroupBox_TextLabelColor = 0x20;

/**
  * @default 0x21
  * @constant
  * @memberOf QStyle
  * @name SH_Menu_SloppySubMenus
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_Menu_SloppySubMenus = 0x21;

/**
  * @default 0x22
  * @constant
  * @memberOf QStyle
  * @name SH_Table_GridLineColor
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_Table_GridLineColor = 0x22;

/**
  * @default 0x23
  * @constant
  * @memberOf QStyle
  * @name SH_LineEdit_PasswordCharacter
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_LineEdit_PasswordCharacter = 0x23;

/**
  * @default 0x24
  * @constant
  * @memberOf QStyle
  * @name SH_DialogButtons_DefaultButton
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_DialogButtons_DefaultButton = 0x24;

/**
  * @default 0x25
  * @constant
  * @memberOf QStyle
  * @name SH_ToolBox_SelectedPageTitleBold
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_ToolBox_SelectedPageTitleBold = 0x25;

/**
  * @default 0x26
  * @constant
  * @memberOf QStyle
  * @name SH_TabBar_PreferNoArrows
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_TabBar_PreferNoArrows = 0x26;

/**
  * @default 0x27
  * @constant
  * @memberOf QStyle
  * @name SH_ScrollBar_LeftClickAbsolutePosition
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_ScrollBar_LeftClickAbsolutePosition = 0x27;

/**
  * @default 0x28
  * @constant
  * @memberOf QStyle
  * @name SH_Q3ListViewExpand_SelectMouseType
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_Q3ListViewExpand_SelectMouseType = 0x28;

/**
  * @default 0x29
  * @constant
  * @memberOf QStyle
  * @name SH_UnderlineShortcut
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_UnderlineShortcut = 0x29;

/**
  * @default 0x2a
  * @constant
  * @memberOf QStyle
  * @name SH_SpinBox_AnimateButton
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_SpinBox_AnimateButton = 0x2a;

/**
  * @default 0x2b
  * @constant
  * @memberOf QStyle
  * @name SH_SpinBox_KeyPressAutoRepeatRate
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_SpinBox_KeyPressAutoRepeatRate = 0x2b;

/**
  * @default 0x2c
  * @constant
  * @memberOf QStyle
  * @name SH_SpinBox_ClickAutoRepeatRate
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_SpinBox_ClickAutoRepeatRate = 0x2c;

/**
  * @default 0x2d
  * @constant
  * @memberOf QStyle
  * @name SH_Menu_FillScreenWithScroll
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_Menu_FillScreenWithScroll = 0x2d;

/**
  * @default 0x2e
  * @constant
  * @memberOf QStyle
  * @name SH_ToolTipLabel_Opacity
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_ToolTipLabel_Opacity = 0x2e;

/**
  * @default 0x2f
  * @constant
  * @memberOf QStyle
  * @name SH_DrawMenuBarSeparator
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_DrawMenuBarSeparator = 0x2f;

/**
  * @default 0x30
  * @constant
  * @memberOf QStyle
  * @name SH_TitleBar_ModifyNotification
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_TitleBar_ModifyNotification = 0x30;

/**
  * @default 0x31
  * @constant
  * @memberOf QStyle
  * @name SH_Button_FocusPolicy
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_Button_FocusPolicy = 0x31;

/**
  * @default 0x32
  * @constant
  * @memberOf QStyle
  * @name SH_MenuBar_DismissOnSecondClick
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_MenuBar_DismissOnSecondClick = 0x32;

/**
  * @default 0x33
  * @constant
  * @memberOf QStyle
  * @name SH_MessageBox_UseBorderForButtonSpacing
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_MessageBox_UseBorderForButtonSpacing = 0x33;

/**
  * @default 0x34
  * @constant
  * @memberOf QStyle
  * @name SH_TitleBar_AutoRaise
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_TitleBar_AutoRaise = 0x34;

/**
  * @default 0x35
  * @constant
  * @memberOf QStyle
  * @name SH_ToolButton_PopupDelay
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_ToolButton_PopupDelay = 0x35;

/**
  * @default 0x36
  * @constant
  * @memberOf QStyle
  * @name SH_FocusFrame_Mask
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_FocusFrame_Mask = 0x36;

/**
  * @default 0x37
  * @constant
  * @memberOf QStyle
  * @name SH_RubberBand_Mask
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_RubberBand_Mask = 0x37;

/**
  * @default 0x38
  * @constant
  * @memberOf QStyle
  * @name SH_WindowFrame_Mask
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_WindowFrame_Mask = 0x38;

/**
  * @default 0x39
  * @constant
  * @memberOf QStyle
  * @name SH_SpinControls_DisableOnBounds
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_SpinControls_DisableOnBounds = 0x39;

/**
  * @default 0x3a
  * @constant
  * @memberOf QStyle
  * @name SH_Dial_BackgroundRole
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_Dial_BackgroundRole = 0x3a;

/**
  * @default 0x3b
  * @constant
  * @memberOf QStyle
  * @name SH_ComboBox_LayoutDirection
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_ComboBox_LayoutDirection = 0x3b;

/**
  * @default 0x3c
  * @constant
  * @memberOf QStyle
  * @name SH_ItemView_EllipsisLocation
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_ItemView_EllipsisLocation = 0x3c;

/**
  * @default 0x3d
  * @constant
  * @memberOf QStyle
  * @name SH_ItemView_ShowDecorationSelected
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_ItemView_ShowDecorationSelected = 0x3d;

/**
  * @default 0x3e
  * @constant
  * @memberOf QStyle
  * @name SH_ItemView_ActivateItemOnSingleClick
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_ItemView_ActivateItemOnSingleClick = 0x3e;

/**
  * @default 0x3f
  * @constant
  * @memberOf QStyle
  * @name SH_ScrollBar_ContextMenu
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_ScrollBar_ContextMenu = 0x3f;

/**
  * @default 0x40
  * @constant
  * @memberOf QStyle
  * @name SH_ScrollBar_RollBetweenButtons
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_ScrollBar_RollBetweenButtons = 0x40;

/**
  * @default 0x41
  * @constant
  * @memberOf QStyle
  * @name SH_Slider_AbsoluteSetButtons
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_Slider_AbsoluteSetButtons = 0x41;

/**
  * @default 0x42
  * @constant
  * @memberOf QStyle
  * @name SH_Slider_PageSetButtons
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_Slider_PageSetButtons = 0x42;

/**
  * @default 0x43
  * @constant
  * @memberOf QStyle
  * @name SH_Menu_KeyboardSearch
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_Menu_KeyboardSearch = 0x43;

/**
  * @default 0x44
  * @constant
  * @memberOf QStyle
  * @name SH_TabBar_ElideMode
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_TabBar_ElideMode = 0x44;

/**
  * @default 0x45
  * @constant
  * @memberOf QStyle
  * @name SH_DialogButtonLayout
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_DialogButtonLayout = 0x45;

/**
  * @default 0x46
  * @constant
  * @memberOf QStyle
  * @name SH_ComboBox_PopupFrameStyle
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_ComboBox_PopupFrameStyle = 0x46;

/**
  * @default 0x47
  * @constant
  * @memberOf QStyle
  * @name SH_MessageBox_TextInteractionFlags
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_MessageBox_TextInteractionFlags = 0x47;

/**
  * @default 0x48
  * @constant
  * @memberOf QStyle
  * @name SH_DialogButtonBox_ButtonsHaveIcons
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_DialogButtonBox_ButtonsHaveIcons = 0x48;

/**
  * @default 0x49
  * @constant
  * @memberOf QStyle
  * @name SH_SpellCheckUnderlineStyle
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_SpellCheckUnderlineStyle = 0x49;

/**
  * @default 0x4a
  * @constant
  * @memberOf QStyle
  * @name SH_MessageBox_CenterButtons
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_MessageBox_CenterButtons = 0x4a;

/**
  * @default 0x4b
  * @constant
  * @memberOf QStyle
  * @name SH_Menu_SelectionWrap
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_Menu_SelectionWrap = 0x4b;

/**
  * @default 0x4c
  * @constant
  * @memberOf QStyle
  * @name SH_ItemView_MovementWithoutUpdatingSelection
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_ItemView_MovementWithoutUpdatingSelection = 0x4c;

/**
  * @default 0x4d
  * @constant
  * @memberOf QStyle
  * @name SH_ToolTip_Mask
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_ToolTip_Mask = 0x4d;

/**
  * @default 0x4e
  * @constant
  * @memberOf QStyle
  * @name SH_FocusFrame_AboveWidget
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_FocusFrame_AboveWidget = 0x4e;

/**
  * @default 0x4f
  * @constant
  * @memberOf QStyle
  * @name SH_TextControl_FocusIndicatorTextCharFormat
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_TextControl_FocusIndicatorTextCharFormat = 0x4f;

/**
  * @default 0x50
  * @constant
  * @memberOf QStyle
  * @name SH_WizardStyle
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_WizardStyle = 0x50;

/**
  * @default 0x51
  * @constant
  * @memberOf QStyle
  * @name SH_ItemView_ArrowKeysNavigateIntoChildren
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_ItemView_ArrowKeysNavigateIntoChildren = 0x51;

/**
  * @default 0x52
  * @constant
  * @memberOf QStyle
  * @name SH_Menu_Mask
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_Menu_Mask = 0x52;

/**
  * @default 0x53
  * @constant
  * @memberOf QStyle
  * @name SH_Menu_FlashTriggeredItem
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_Menu_FlashTriggeredItem = 0x53;

/**
  * @default 0x54
  * @constant
  * @memberOf QStyle
  * @name SH_Menu_FadeOutOnHide
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_Menu_FadeOutOnHide = 0x54;

/**
  * @default 0x55
  * @constant
  * @memberOf QStyle
  * @name SH_SpinBox_ClickAutoRepeatThreshold
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_SpinBox_ClickAutoRepeatThreshold = 0x55;

/**
  * @default 0x56
  * @constant
  * @memberOf QStyle
  * @name SH_ItemView_PaintAlternatingRowColorsForEmptyArea
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_ItemView_PaintAlternatingRowColorsForEmptyArea = 0x56;

/**
  * @default 0x57
  * @constant
  * @memberOf QStyle
  * @name SH_FormLayoutWrapPolicy
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_FormLayoutWrapPolicy = 0x57;

/**
  * @default 0x58
  * @constant
  * @memberOf QStyle
  * @name SH_TabWidget_DefaultTabPosition
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_TabWidget_DefaultTabPosition = 0x58;

/**
  * @default 0x59
  * @constant
  * @memberOf QStyle
  * @name SH_ToolBar_Movable
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_ToolBar_Movable = 0x59;

/**
  * @default 0x5a
  * @constant
  * @memberOf QStyle
  * @name SH_FormLayoutFieldGrowthPolicy
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_FormLayoutFieldGrowthPolicy = 0x5a;

/**
  * @default 0x5b
  * @constant
  * @memberOf QStyle
  * @name SH_FormLayoutFormAlignment
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_FormLayoutFormAlignment = 0x5b;

/**
  * @default 0x5c
  * @constant
  * @memberOf QStyle
  * @name SH_FormLayoutLabelAlignment
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_FormLayoutLabelAlignment = 0x5c;

/**
  * @default 0x5d
  * @constant
  * @memberOf QStyle
  * @name SH_ItemView_DrawDelegateFrame
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_ItemView_DrawDelegateFrame = 0x5d;

/**
  * @default 0x5e
  * @constant
  * @memberOf QStyle
  * @name SH_TabBar_CloseButtonPosition
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_TabBar_CloseButtonPosition = 0x5e;

/**
  * @default 0x5f
  * @constant
  * @memberOf QStyle
  * @name SH_DockWidget_ButtonsHaveFrame
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_DockWidget_ButtonsHaveFrame = 0x5f;

/**
  * @default 0x60
  * @constant
  * @memberOf QStyle
  * @name SH_ToolButtonStyle
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_ToolButtonStyle = 0x60;

/**
  * @default 0x61
  * @constant
  * @memberOf QStyle
  * @name SH_RequestSoftwareInputPanel
  * @see QStyle#StyleHint
  * @type Number
  */
QStyle.SH_RequestSoftwareInputPanel = 0x61;

/**
  * @constructor 
  * @memberOf QStyle
  * @name StyleHint
  */
QStyle.StyleHint = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QStyle
  * @name PE_Q3CheckListController
  * @see QStyle#PrimitiveElement
  * @type Number
  */
QStyle.PE_Q3CheckListController = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QStyle
  * @name PE_Q3CheckListExclusiveIndicator
  * @see QStyle#PrimitiveElement
  * @type Number
  */
QStyle.PE_Q3CheckListExclusiveIndicator = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QStyle
  * @name PE_Q3CheckListIndicator
  * @see QStyle#PrimitiveElement
  * @type Number
  */
QStyle.PE_Q3CheckListIndicator = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QStyle
  * @name PE_Q3DockWindowSeparator
  * @see QStyle#PrimitiveElement
  * @type Number
  */
QStyle.PE_Q3DockWindowSeparator = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QStyle
  * @name PE_Q3Separator
  * @see QStyle#PrimitiveElement
  * @type Number
  */
QStyle.PE_Q3Separator = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QStyle
  * @name PE_Frame
  * @see QStyle#PrimitiveElement
  * @type Number
  */
QStyle.PE_Frame = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf QStyle
  * @name PE_FrameDefaultButton
  * @see QStyle#PrimitiveElement
  * @type Number
  */
QStyle.PE_FrameDefaultButton = 0x6;

/**
  * @default 0x7
  * @constant
  * @memberOf QStyle
  * @name PE_FrameDockWidget
  * @see QStyle#PrimitiveElement
  * @type Number
  */
QStyle.PE_FrameDockWidget = 0x7;

/**
  * @default 0x8
  * @constant
  * @memberOf QStyle
  * @name PE_FrameFocusRect
  * @see QStyle#PrimitiveElement
  * @type Number
  */
QStyle.PE_FrameFocusRect = 0x8;

/**
  * @default 0x9
  * @constant
  * @memberOf QStyle
  * @name PE_FrameGroupBox
  * @see QStyle#PrimitiveElement
  * @type Number
  */
QStyle.PE_FrameGroupBox = 0x9;

/**
  * @default 0xa
  * @constant
  * @memberOf QStyle
  * @name PE_FrameLineEdit
  * @see QStyle#PrimitiveElement
  * @type Number
  */
QStyle.PE_FrameLineEdit = 0xa;

/**
  * @default 0xb
  * @constant
  * @memberOf QStyle
  * @name PE_FrameMenu
  * @see QStyle#PrimitiveElement
  * @type Number
  */
QStyle.PE_FrameMenu = 0xb;

/**
  * @default 0xc
  * @constant
  * @memberOf QStyle
  * @name PE_FrameStatusBar
  * @see QStyle#PrimitiveElement
  * @type Number
  */
QStyle.PE_FrameStatusBar = 0xc;

/**
  * @default 0xd
  * @constant
  * @memberOf QStyle
  * @name PE_FrameTabWidget
  * @see QStyle#PrimitiveElement
  * @type Number
  */
QStyle.PE_FrameTabWidget = 0xd;

/**
  * @default 0xe
  * @constant
  * @memberOf QStyle
  * @name PE_FrameWindow
  * @see QStyle#PrimitiveElement
  * @type Number
  */
QStyle.PE_FrameWindow = 0xe;

/**
  * @default 0xf
  * @constant
  * @memberOf QStyle
  * @name PE_FrameButtonBevel
  * @see QStyle#PrimitiveElement
  * @type Number
  */
QStyle.PE_FrameButtonBevel = 0xf;

/**
  * @default 0x10
  * @constant
  * @memberOf QStyle
  * @name PE_FrameButtonTool
  * @see QStyle#PrimitiveElement
  * @type Number
  */
QStyle.PE_FrameButtonTool = 0x10;

/**
  * @default 0x11
  * @constant
  * @memberOf QStyle
  * @name PE_FrameTabBarBase
  * @see QStyle#PrimitiveElement
  * @type Number
  */
QStyle.PE_FrameTabBarBase = 0x11;

/**
  * @default 0x12
  * @constant
  * @memberOf QStyle
  * @name PE_PanelButtonCommand
  * @see QStyle#PrimitiveElement
  * @type Number
  */
QStyle.PE_PanelButtonCommand = 0x12;

/**
  * @default 0x13
  * @constant
  * @memberOf QStyle
  * @name PE_PanelButtonBevel
  * @see QStyle#PrimitiveElement
  * @type Number
  */
QStyle.PE_PanelButtonBevel = 0x13;

/**
  * @default 0x14
  * @constant
  * @memberOf QStyle
  * @name PE_PanelButtonTool
  * @see QStyle#PrimitiveElement
  * @type Number
  */
QStyle.PE_PanelButtonTool = 0x14;

/**
  * @default 0x15
  * @constant
  * @memberOf QStyle
  * @name PE_PanelMenuBar
  * @see QStyle#PrimitiveElement
  * @type Number
  */
QStyle.PE_PanelMenuBar = 0x15;

/**
  * @default 0x16
  * @constant
  * @memberOf QStyle
  * @name PE_PanelToolBar
  * @see QStyle#PrimitiveElement
  * @type Number
  */
QStyle.PE_PanelToolBar = 0x16;

/**
  * @default 0x17
  * @constant
  * @memberOf QStyle
  * @name PE_PanelLineEdit
  * @see QStyle#PrimitiveElement
  * @type Number
  */
QStyle.PE_PanelLineEdit = 0x17;

/**
  * @default 0x18
  * @constant
  * @memberOf QStyle
  * @name PE_IndicatorArrowDown
  * @see QStyle#PrimitiveElement
  * @type Number
  */
QStyle.PE_IndicatorArrowDown = 0x18;

/**
  * @default 0x19
  * @constant
  * @memberOf QStyle
  * @name PE_IndicatorArrowLeft
  * @see QStyle#PrimitiveElement
  * @type Number
  */
QStyle.PE_IndicatorArrowLeft = 0x19;

/**
  * @default 0x1a
  * @constant
  * @memberOf QStyle
  * @name PE_IndicatorArrowRight
  * @see QStyle#PrimitiveElement
  * @type Number
  */
QStyle.PE_IndicatorArrowRight = 0x1a;

/**
  * @default 0x1b
  * @constant
  * @memberOf QStyle
  * @name PE_IndicatorArrowUp
  * @see QStyle#PrimitiveElement
  * @type Number
  */
QStyle.PE_IndicatorArrowUp = 0x1b;

/**
  * @default 0x1c
  * @constant
  * @memberOf QStyle
  * @name PE_IndicatorBranch
  * @see QStyle#PrimitiveElement
  * @type Number
  */
QStyle.PE_IndicatorBranch = 0x1c;

/**
  * @default 0x1d
  * @constant
  * @memberOf QStyle
  * @name PE_IndicatorButtonDropDown
  * @see QStyle#PrimitiveElement
  * @type Number
  */
QStyle.PE_IndicatorButtonDropDown = 0x1d;

/**
  * @default 0x1e
  * @constant
  * @memberOf QStyle
  * @name PE_IndicatorViewItemCheck
  * @see QStyle#PrimitiveElement
  * @type Number
  */
QStyle.PE_IndicatorViewItemCheck = 0x1e;

/**
  * @default 0x1f
  * @constant
  * @memberOf QStyle
  * @name PE_IndicatorCheckBox
  * @see QStyle#PrimitiveElement
  * @type Number
  */
QStyle.PE_IndicatorCheckBox = 0x1f;

/**
  * @default 0x20
  * @constant
  * @memberOf QStyle
  * @name PE_IndicatorDockWidgetResizeHandle
  * @see QStyle#PrimitiveElement
  * @type Number
  */
QStyle.PE_IndicatorDockWidgetResizeHandle = 0x20;

/**
  * @default 0x21
  * @constant
  * @memberOf QStyle
  * @name PE_IndicatorHeaderArrow
  * @see QStyle#PrimitiveElement
  * @type Number
  */
QStyle.PE_IndicatorHeaderArrow = 0x21;

/**
  * @default 0x22
  * @constant
  * @memberOf QStyle
  * @name PE_IndicatorMenuCheckMark
  * @see QStyle#PrimitiveElement
  * @type Number
  */
QStyle.PE_IndicatorMenuCheckMark = 0x22;

/**
  * @default 0x23
  * @constant
  * @memberOf QStyle
  * @name PE_IndicatorProgressChunk
  * @see QStyle#PrimitiveElement
  * @type Number
  */
QStyle.PE_IndicatorProgressChunk = 0x23;

/**
  * @default 0x24
  * @constant
  * @memberOf QStyle
  * @name PE_IndicatorRadioButton
  * @see QStyle#PrimitiveElement
  * @type Number
  */
QStyle.PE_IndicatorRadioButton = 0x24;

/**
  * @default 0x25
  * @constant
  * @memberOf QStyle
  * @name PE_IndicatorSpinDown
  * @see QStyle#PrimitiveElement
  * @type Number
  */
QStyle.PE_IndicatorSpinDown = 0x25;

/**
  * @default 0x26
  * @constant
  * @memberOf QStyle
  * @name PE_IndicatorSpinMinus
  * @see QStyle#PrimitiveElement
  * @type Number
  */
QStyle.PE_IndicatorSpinMinus = 0x26;

/**
  * @default 0x27
  * @constant
  * @memberOf QStyle
  * @name PE_IndicatorSpinPlus
  * @see QStyle#PrimitiveElement
  * @type Number
  */
QStyle.PE_IndicatorSpinPlus = 0x27;

/**
  * @default 0x28
  * @constant
  * @memberOf QStyle
  * @name PE_IndicatorSpinUp
  * @see QStyle#PrimitiveElement
  * @type Number
  */
QStyle.PE_IndicatorSpinUp = 0x28;

/**
  * @default 0x29
  * @constant
  * @memberOf QStyle
  * @name PE_IndicatorToolBarHandle
  * @see QStyle#PrimitiveElement
  * @type Number
  */
QStyle.PE_IndicatorToolBarHandle = 0x29;

/**
  * @default 0x2a
  * @constant
  * @memberOf QStyle
  * @name PE_IndicatorToolBarSeparator
  * @see QStyle#PrimitiveElement
  * @type Number
  */
QStyle.PE_IndicatorToolBarSeparator = 0x2a;

/**
  * @default 0x2b
  * @constant
  * @memberOf QStyle
  * @name PE_PanelTipLabel
  * @see QStyle#PrimitiveElement
  * @type Number
  */
QStyle.PE_PanelTipLabel = 0x2b;

/**
  * @default 0x2c
  * @constant
  * @memberOf QStyle
  * @name PE_IndicatorTabTear
  * @see QStyle#PrimitiveElement
  * @type Number
  */
QStyle.PE_IndicatorTabTear = 0x2c;

/**
  * @default 0x2d
  * @constant
  * @memberOf QStyle
  * @name PE_PanelScrollAreaCorner
  * @see QStyle#PrimitiveElement
  * @type Number
  */
QStyle.PE_PanelScrollAreaCorner = 0x2d;

/**
  * @default 0x2e
  * @constant
  * @memberOf QStyle
  * @name PE_Widget
  * @see QStyle#PrimitiveElement
  * @type Number
  */
QStyle.PE_Widget = 0x2e;

/**
  * @default 0x2f
  * @constant
  * @memberOf QStyle
  * @name PE_IndicatorColumnViewArrow
  * @see QStyle#PrimitiveElement
  * @type Number
  */
QStyle.PE_IndicatorColumnViewArrow = 0x2f;

/**
  * @default 0x30
  * @constant
  * @memberOf QStyle
  * @name PE_IndicatorItemViewItemDrop
  * @see QStyle#PrimitiveElement
  * @type Number
  */
QStyle.PE_IndicatorItemViewItemDrop = 0x30;

/**
  * @default 0x31
  * @constant
  * @memberOf QStyle
  * @name PE_PanelItemViewItem
  * @see QStyle#PrimitiveElement
  * @type Number
  */
QStyle.PE_PanelItemViewItem = 0x31;

/**
  * @default 0x32
  * @constant
  * @memberOf QStyle
  * @name PE_PanelItemViewRow
  * @see QStyle#PrimitiveElement
  * @type Number
  */
QStyle.PE_PanelItemViewRow = 0x32;

/**
  * @default 0x33
  * @constant
  * @memberOf QStyle
  * @name PE_PanelStatusBar
  * @see QStyle#PrimitiveElement
  * @type Number
  */
QStyle.PE_PanelStatusBar = 0x33;

/**
  * @default 0x34
  * @constant
  * @memberOf QStyle
  * @name PE_IndicatorTabClose
  * @see QStyle#PrimitiveElement
  * @type Number
  */
QStyle.PE_IndicatorTabClose = 0x34;

/**
  * @default 0x35
  * @constant
  * @memberOf QStyle
  * @name PE_PanelMenu
  * @see QStyle#PrimitiveElement
  * @type Number
  */
QStyle.PE_PanelMenu = 0x35;

/**
  * @default 0xf000000
  * @constant
  * @memberOf QStyle
  * @name PE_CustomBase
  * @see QStyle#PrimitiveElement
  * @type Number
  */
QStyle.PE_CustomBase = 0xf000000;

/**
  * @constructor 
  * @memberOf QStyle
  * @name PrimitiveElement
  */
QStyle.PrimitiveElement = function(value){;};



/**
  * @default 0xf0000000
  * @constant
  * @memberOf QStyle
  * @name CE_CustomBase
  * @see QStyle#ControlElement
  * @type Number
  */
QStyle.CE_CustomBase = 0xf0000000;

/**
  * @default 0x0
  * @constant
  * @memberOf QStyle
  * @name CE_PushButton
  * @see QStyle#ControlElement
  * @type Number
  */
QStyle.CE_PushButton = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QStyle
  * @name CE_PushButtonBevel
  * @see QStyle#ControlElement
  * @type Number
  */
QStyle.CE_PushButtonBevel = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QStyle
  * @name CE_PushButtonLabel
  * @see QStyle#ControlElement
  * @type Number
  */
QStyle.CE_PushButtonLabel = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QStyle
  * @name CE_CheckBox
  * @see QStyle#ControlElement
  * @type Number
  */
QStyle.CE_CheckBox = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QStyle
  * @name CE_CheckBoxLabel
  * @see QStyle#ControlElement
  * @type Number
  */
QStyle.CE_CheckBoxLabel = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QStyle
  * @name CE_RadioButton
  * @see QStyle#ControlElement
  * @type Number
  */
QStyle.CE_RadioButton = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf QStyle
  * @name CE_RadioButtonLabel
  * @see QStyle#ControlElement
  * @type Number
  */
QStyle.CE_RadioButtonLabel = 0x6;

/**
  * @default 0x7
  * @constant
  * @memberOf QStyle
  * @name CE_TabBarTab
  * @see QStyle#ControlElement
  * @type Number
  */
QStyle.CE_TabBarTab = 0x7;

/**
  * @default 0x8
  * @constant
  * @memberOf QStyle
  * @name CE_TabBarTabShape
  * @see QStyle#ControlElement
  * @type Number
  */
QStyle.CE_TabBarTabShape = 0x8;

/**
  * @default 0x9
  * @constant
  * @memberOf QStyle
  * @name CE_TabBarTabLabel
  * @see QStyle#ControlElement
  * @type Number
  */
QStyle.CE_TabBarTabLabel = 0x9;

/**
  * @default 0xa
  * @constant
  * @memberOf QStyle
  * @name CE_ProgressBar
  * @see QStyle#ControlElement
  * @type Number
  */
QStyle.CE_ProgressBar = 0xa;

/**
  * @default 0xb
  * @constant
  * @memberOf QStyle
  * @name CE_ProgressBarGroove
  * @see QStyle#ControlElement
  * @type Number
  */
QStyle.CE_ProgressBarGroove = 0xb;

/**
  * @default 0xc
  * @constant
  * @memberOf QStyle
  * @name CE_ProgressBarContents
  * @see QStyle#ControlElement
  * @type Number
  */
QStyle.CE_ProgressBarContents = 0xc;

/**
  * @default 0xd
  * @constant
  * @memberOf QStyle
  * @name CE_ProgressBarLabel
  * @see QStyle#ControlElement
  * @type Number
  */
QStyle.CE_ProgressBarLabel = 0xd;

/**
  * @default 0xe
  * @constant
  * @memberOf QStyle
  * @name CE_MenuItem
  * @see QStyle#ControlElement
  * @type Number
  */
QStyle.CE_MenuItem = 0xe;

/**
  * @default 0xf
  * @constant
  * @memberOf QStyle
  * @name CE_MenuScroller
  * @see QStyle#ControlElement
  * @type Number
  */
QStyle.CE_MenuScroller = 0xf;

/**
  * @default 0x10
  * @constant
  * @memberOf QStyle
  * @name CE_MenuVMargin
  * @see QStyle#ControlElement
  * @type Number
  */
QStyle.CE_MenuVMargin = 0x10;

/**
  * @default 0x11
  * @constant
  * @memberOf QStyle
  * @name CE_MenuHMargin
  * @see QStyle#ControlElement
  * @type Number
  */
QStyle.CE_MenuHMargin = 0x11;

/**
  * @default 0x12
  * @constant
  * @memberOf QStyle
  * @name CE_MenuTearoff
  * @see QStyle#ControlElement
  * @type Number
  */
QStyle.CE_MenuTearoff = 0x12;

/**
  * @default 0x13
  * @constant
  * @memberOf QStyle
  * @name CE_MenuEmptyArea
  * @see QStyle#ControlElement
  * @type Number
  */
QStyle.CE_MenuEmptyArea = 0x13;

/**
  * @default 0x14
  * @constant
  * @memberOf QStyle
  * @name CE_MenuBarItem
  * @see QStyle#ControlElement
  * @type Number
  */
QStyle.CE_MenuBarItem = 0x14;

/**
  * @default 0x15
  * @constant
  * @memberOf QStyle
  * @name CE_MenuBarEmptyArea
  * @see QStyle#ControlElement
  * @type Number
  */
QStyle.CE_MenuBarEmptyArea = 0x15;

/**
  * @default 0x16
  * @constant
  * @memberOf QStyle
  * @name CE_ToolButtonLabel
  * @see QStyle#ControlElement
  * @type Number
  */
QStyle.CE_ToolButtonLabel = 0x16;

/**
  * @default 0x17
  * @constant
  * @memberOf QStyle
  * @name CE_Header
  * @see QStyle#ControlElement
  * @type Number
  */
QStyle.CE_Header = 0x17;

/**
  * @default 0x18
  * @constant
  * @memberOf QStyle
  * @name CE_HeaderSection
  * @see QStyle#ControlElement
  * @type Number
  */
QStyle.CE_HeaderSection = 0x18;

/**
  * @default 0x19
  * @constant
  * @memberOf QStyle
  * @name CE_HeaderLabel
  * @see QStyle#ControlElement
  * @type Number
  */
QStyle.CE_HeaderLabel = 0x19;

/**
  * @default 0x1a
  * @constant
  * @memberOf QStyle
  * @name CE_Q3DockWindowEmptyArea
  * @see QStyle#ControlElement
  * @type Number
  */
QStyle.CE_Q3DockWindowEmptyArea = 0x1a;

/**
  * @default 0x1b
  * @constant
  * @memberOf QStyle
  * @name CE_ToolBoxTab
  * @see QStyle#ControlElement
  * @type Number
  */
QStyle.CE_ToolBoxTab = 0x1b;

/**
  * @default 0x1c
  * @constant
  * @memberOf QStyle
  * @name CE_SizeGrip
  * @see QStyle#ControlElement
  * @type Number
  */
QStyle.CE_SizeGrip = 0x1c;

/**
  * @default 0x1d
  * @constant
  * @memberOf QStyle
  * @name CE_Splitter
  * @see QStyle#ControlElement
  * @type Number
  */
QStyle.CE_Splitter = 0x1d;

/**
  * @default 0x1e
  * @constant
  * @memberOf QStyle
  * @name CE_RubberBand
  * @see QStyle#ControlElement
  * @type Number
  */
QStyle.CE_RubberBand = 0x1e;

/**
  * @default 0x1f
  * @constant
  * @memberOf QStyle
  * @name CE_DockWidgetTitle
  * @see QStyle#ControlElement
  * @type Number
  */
QStyle.CE_DockWidgetTitle = 0x1f;

/**
  * @default 0x20
  * @constant
  * @memberOf QStyle
  * @name CE_ScrollBarAddLine
  * @see QStyle#ControlElement
  * @type Number
  */
QStyle.CE_ScrollBarAddLine = 0x20;

/**
  * @default 0x21
  * @constant
  * @memberOf QStyle
  * @name CE_ScrollBarSubLine
  * @see QStyle#ControlElement
  * @type Number
  */
QStyle.CE_ScrollBarSubLine = 0x21;

/**
  * @default 0x22
  * @constant
  * @memberOf QStyle
  * @name CE_ScrollBarAddPage
  * @see QStyle#ControlElement
  * @type Number
  */
QStyle.CE_ScrollBarAddPage = 0x22;

/**
  * @default 0x23
  * @constant
  * @memberOf QStyle
  * @name CE_ScrollBarSubPage
  * @see QStyle#ControlElement
  * @type Number
  */
QStyle.CE_ScrollBarSubPage = 0x23;

/**
  * @default 0x24
  * @constant
  * @memberOf QStyle
  * @name CE_ScrollBarSlider
  * @see QStyle#ControlElement
  * @type Number
  */
QStyle.CE_ScrollBarSlider = 0x24;

/**
  * @default 0x25
  * @constant
  * @memberOf QStyle
  * @name CE_ScrollBarFirst
  * @see QStyle#ControlElement
  * @type Number
  */
QStyle.CE_ScrollBarFirst = 0x25;

/**
  * @default 0x26
  * @constant
  * @memberOf QStyle
  * @name CE_ScrollBarLast
  * @see QStyle#ControlElement
  * @type Number
  */
QStyle.CE_ScrollBarLast = 0x26;

/**
  * @default 0x27
  * @constant
  * @memberOf QStyle
  * @name CE_FocusFrame
  * @see QStyle#ControlElement
  * @type Number
  */
QStyle.CE_FocusFrame = 0x27;

/**
  * @default 0x28
  * @constant
  * @memberOf QStyle
  * @name CE_ComboBoxLabel
  * @see QStyle#ControlElement
  * @type Number
  */
QStyle.CE_ComboBoxLabel = 0x28;

/**
  * @default 0x29
  * @constant
  * @memberOf QStyle
  * @name CE_ToolBar
  * @see QStyle#ControlElement
  * @type Number
  */
QStyle.CE_ToolBar = 0x29;

/**
  * @default 0x2a
  * @constant
  * @memberOf QStyle
  * @name CE_ToolBoxTabShape
  * @see QStyle#ControlElement
  * @type Number
  */
QStyle.CE_ToolBoxTabShape = 0x2a;

/**
  * @default 0x2b
  * @constant
  * @memberOf QStyle
  * @name CE_ToolBoxTabLabel
  * @see QStyle#ControlElement
  * @type Number
  */
QStyle.CE_ToolBoxTabLabel = 0x2b;

/**
  * @default 0x2c
  * @constant
  * @memberOf QStyle
  * @name CE_HeaderEmptyArea
  * @see QStyle#ControlElement
  * @type Number
  */
QStyle.CE_HeaderEmptyArea = 0x2c;

/**
  * @default 0x2d
  * @constant
  * @memberOf QStyle
  * @name CE_ColumnViewGrip
  * @see QStyle#ControlElement
  * @type Number
  */
QStyle.CE_ColumnViewGrip = 0x2d;

/**
  * @default 0x2e
  * @constant
  * @memberOf QStyle
  * @name CE_ItemViewItem
  * @see QStyle#ControlElement
  * @type Number
  */
QStyle.CE_ItemViewItem = 0x2e;

/**
  * @default 0x2f
  * @constant
  * @memberOf QStyle
  * @name CE_ShapedFrame
  * @see QStyle#ControlElement
  * @type Number
  */
QStyle.CE_ShapedFrame = 0x2f;

/**
  * @constructor 
  * @memberOf QStyle
  * @name ControlElement
  */
QStyle.ControlElement = function(value){;};



/**
  * @default 0xf0000000
  * @constant
  * @memberOf QStyle
  * @name CT_CustomBase
  * @see QStyle#ContentsType
  * @type Number
  */
QStyle.CT_CustomBase = 0xf0000000;

/**
  * @default 0x0
  * @constant
  * @memberOf QStyle
  * @name CT_PushButton
  * @see QStyle#ContentsType
  * @type Number
  */
QStyle.CT_PushButton = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QStyle
  * @name CT_CheckBox
  * @see QStyle#ContentsType
  * @type Number
  */
QStyle.CT_CheckBox = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QStyle
  * @name CT_RadioButton
  * @see QStyle#ContentsType
  * @type Number
  */
QStyle.CT_RadioButton = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QStyle
  * @name CT_ToolButton
  * @see QStyle#ContentsType
  * @type Number
  */
QStyle.CT_ToolButton = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QStyle
  * @name CT_ComboBox
  * @see QStyle#ContentsType
  * @type Number
  */
QStyle.CT_ComboBox = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QStyle
  * @name CT_Splitter
  * @see QStyle#ContentsType
  * @type Number
  */
QStyle.CT_Splitter = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf QStyle
  * @name CT_Q3DockWindow
  * @see QStyle#ContentsType
  * @type Number
  */
QStyle.CT_Q3DockWindow = 0x6;

/**
  * @default 0x7
  * @constant
  * @memberOf QStyle
  * @name CT_ProgressBar
  * @see QStyle#ContentsType
  * @type Number
  */
QStyle.CT_ProgressBar = 0x7;

/**
  * @default 0x8
  * @constant
  * @memberOf QStyle
  * @name CT_MenuItem
  * @see QStyle#ContentsType
  * @type Number
  */
QStyle.CT_MenuItem = 0x8;

/**
  * @default 0x9
  * @constant
  * @memberOf QStyle
  * @name CT_MenuBarItem
  * @see QStyle#ContentsType
  * @type Number
  */
QStyle.CT_MenuBarItem = 0x9;

/**
  * @default 0xa
  * @constant
  * @memberOf QStyle
  * @name CT_MenuBar
  * @see QStyle#ContentsType
  * @type Number
  */
QStyle.CT_MenuBar = 0xa;

/**
  * @default 0xb
  * @constant
  * @memberOf QStyle
  * @name CT_Menu
  * @see QStyle#ContentsType
  * @type Number
  */
QStyle.CT_Menu = 0xb;

/**
  * @default 0xc
  * @constant
  * @memberOf QStyle
  * @name CT_TabBarTab
  * @see QStyle#ContentsType
  * @type Number
  */
QStyle.CT_TabBarTab = 0xc;

/**
  * @default 0xd
  * @constant
  * @memberOf QStyle
  * @name CT_Slider
  * @see QStyle#ContentsType
  * @type Number
  */
QStyle.CT_Slider = 0xd;

/**
  * @default 0xe
  * @constant
  * @memberOf QStyle
  * @name CT_ScrollBar
  * @see QStyle#ContentsType
  * @type Number
  */
QStyle.CT_ScrollBar = 0xe;

/**
  * @default 0xf
  * @constant
  * @memberOf QStyle
  * @name CT_Q3Header
  * @see QStyle#ContentsType
  * @type Number
  */
QStyle.CT_Q3Header = 0xf;

/**
  * @default 0x10
  * @constant
  * @memberOf QStyle
  * @name CT_LineEdit
  * @see QStyle#ContentsType
  * @type Number
  */
QStyle.CT_LineEdit = 0x10;

/**
  * @default 0x11
  * @constant
  * @memberOf QStyle
  * @name CT_SpinBox
  * @see QStyle#ContentsType
  * @type Number
  */
QStyle.CT_SpinBox = 0x11;

/**
  * @default 0x12
  * @constant
  * @memberOf QStyle
  * @name CT_SizeGrip
  * @see QStyle#ContentsType
  * @type Number
  */
QStyle.CT_SizeGrip = 0x12;

/**
  * @default 0x13
  * @constant
  * @memberOf QStyle
  * @name CT_TabWidget
  * @see QStyle#ContentsType
  * @type Number
  */
QStyle.CT_TabWidget = 0x13;

/**
  * @default 0x14
  * @constant
  * @memberOf QStyle
  * @name CT_DialogButtons
  * @see QStyle#ContentsType
  * @type Number
  */
QStyle.CT_DialogButtons = 0x14;

/**
  * @default 0x15
  * @constant
  * @memberOf QStyle
  * @name CT_HeaderSection
  * @see QStyle#ContentsType
  * @type Number
  */
QStyle.CT_HeaderSection = 0x15;

/**
  * @default 0x16
  * @constant
  * @memberOf QStyle
  * @name CT_GroupBox
  * @see QStyle#ContentsType
  * @type Number
  */
QStyle.CT_GroupBox = 0x16;

/**
  * @default 0x17
  * @constant
  * @memberOf QStyle
  * @name CT_MdiControls
  * @see QStyle#ContentsType
  * @type Number
  */
QStyle.CT_MdiControls = 0x17;

/**
  * @default 0x18
  * @constant
  * @memberOf QStyle
  * @name CT_ItemViewItem
  * @see QStyle#ContentsType
  * @type Number
  */
QStyle.CT_ItemViewItem = 0x18;

/**
  * @constructor 
  * @memberOf QStyle
  * @name ContentsType
  */
QStyle.ContentsType = function(value){;};



/**
  * @default 0x00000000
  * @constant
  * @memberOf QStyle
  * @name State_None
  * @see QStyle#State
  * @see QStyle#StateFlag
  * @type Number
  */
QStyle.State_None = 0x0;

/**
  * @default 0x00000001
  * @constant
  * @memberOf QStyle
  * @name State_Enabled
  * @see QStyle#State
  * @see QStyle#StateFlag
  * @type Number
  */
QStyle.State_Enabled = 0x1;

/**
  * @default 0x00000002
  * @constant
  * @memberOf QStyle
  * @name State_Raised
  * @see QStyle#State
  * @see QStyle#StateFlag
  * @type Number
  */
QStyle.State_Raised = 0x2;

/**
  * @default 0x00000004
  * @constant
  * @memberOf QStyle
  * @name State_Sunken
  * @see QStyle#State
  * @see QStyle#StateFlag
  * @type Number
  */
QStyle.State_Sunken = 0x4;

/**
  * @default 0x00000008
  * @constant
  * @memberOf QStyle
  * @name State_Off
  * @see QStyle#State
  * @see QStyle#StateFlag
  * @type Number
  */
QStyle.State_Off = 0x8;

/**
  * @default 0x00000010
  * @constant
  * @memberOf QStyle
  * @name State_NoChange
  * @see QStyle#State
  * @see QStyle#StateFlag
  * @type Number
  */
QStyle.State_NoChange = 0x10;

/**
  * @default 0x00000020
  * @constant
  * @memberOf QStyle
  * @name State_On
  * @see QStyle#State
  * @see QStyle#StateFlag
  * @type Number
  */
QStyle.State_On = 0x20;

/**
  * @default 0x00000040
  * @constant
  * @memberOf QStyle
  * @name State_DownArrow
  * @see QStyle#State
  * @see QStyle#StateFlag
  * @type Number
  */
QStyle.State_DownArrow = 0x40;

/**
  * @default 0x00000080
  * @constant
  * @memberOf QStyle
  * @name State_Horizontal
  * @see QStyle#State
  * @see QStyle#StateFlag
  * @type Number
  */
QStyle.State_Horizontal = 0x80;

/**
  * @default 0x00000100
  * @constant
  * @memberOf QStyle
  * @name State_HasFocus
  * @see QStyle#State
  * @see QStyle#StateFlag
  * @type Number
  */
QStyle.State_HasFocus = 0x100;

/**
  * @default 0x00000200
  * @constant
  * @memberOf QStyle
  * @name State_Top
  * @see QStyle#State
  * @see QStyle#StateFlag
  * @type Number
  */
QStyle.State_Top = 0x200;

/**
  * @default 0x00000400
  * @constant
  * @memberOf QStyle
  * @name State_Bottom
  * @see QStyle#State
  * @see QStyle#StateFlag
  * @type Number
  */
QStyle.State_Bottom = 0x400;

/**
  * @default 0x00000800
  * @constant
  * @memberOf QStyle
  * @name State_FocusAtBorder
  * @see QStyle#State
  * @see QStyle#StateFlag
  * @type Number
  */
QStyle.State_FocusAtBorder = 0x800;

/**
  * @default 0x00001000
  * @constant
  * @memberOf QStyle
  * @name State_AutoRaise
  * @see QStyle#State
  * @see QStyle#StateFlag
  * @type Number
  */
QStyle.State_AutoRaise = 0x1000;

/**
  * @default 0x00002000
  * @constant
  * @memberOf QStyle
  * @name State_MouseOver
  * @see QStyle#State
  * @see QStyle#StateFlag
  * @type Number
  */
QStyle.State_MouseOver = 0x2000;

/**
  * @default 0x00004000
  * @constant
  * @memberOf QStyle
  * @name State_UpArrow
  * @see QStyle#State
  * @see QStyle#StateFlag
  * @type Number
  */
QStyle.State_UpArrow = 0x4000;

/**
  * @default 0x00008000
  * @constant
  * @memberOf QStyle
  * @name State_Selected
  * @see QStyle#State
  * @see QStyle#StateFlag
  * @type Number
  */
QStyle.State_Selected = 0x8000;

/**
  * @default 0x00010000
  * @constant
  * @memberOf QStyle
  * @name State_Active
  * @see QStyle#State
  * @see QStyle#StateFlag
  * @type Number
  */
QStyle.State_Active = 0x10000;

/**
  * @default 0x00020000
  * @constant
  * @memberOf QStyle
  * @name State_Window
  * @see QStyle#State
  * @see QStyle#StateFlag
  * @type Number
  */
QStyle.State_Window = 0x20000;

/**
  * @default 0x00040000
  * @constant
  * @memberOf QStyle
  * @name State_Open
  * @see QStyle#State
  * @see QStyle#StateFlag
  * @type Number
  */
QStyle.State_Open = 0x40000;

/**
  * @default 0x00080000
  * @constant
  * @memberOf QStyle
  * @name State_Children
  * @see QStyle#State
  * @see QStyle#StateFlag
  * @type Number
  */
QStyle.State_Children = 0x80000;

/**
  * @default 0x00100000
  * @constant
  * @memberOf QStyle
  * @name State_Item
  * @see QStyle#State
  * @see QStyle#StateFlag
  * @type Number
  */
QStyle.State_Item = 0x100000;

/**
  * @default 0x00200000
  * @constant
  * @memberOf QStyle
  * @name State_Sibling
  * @see QStyle#State
  * @see QStyle#StateFlag
  * @type Number
  */
QStyle.State_Sibling = 0x200000;

/**
  * @default 0x00400000
  * @constant
  * @memberOf QStyle
  * @name State_Editing
  * @see QStyle#State
  * @see QStyle#StateFlag
  * @type Number
  */
QStyle.State_Editing = 0x400000;

/**
  * @default 0x00800000
  * @constant
  * @memberOf QStyle
  * @name State_KeyboardFocusChange
  * @see QStyle#State
  * @see QStyle#StateFlag
  * @type Number
  */
QStyle.State_KeyboardFocusChange = 0x800000;

/**
  * @default 0x02000000
  * @constant
  * @memberOf QStyle
  * @name State_ReadOnly
  * @see QStyle#State
  * @see QStyle#StateFlag
  * @type Number
  */
QStyle.State_ReadOnly = 0x2000000;

/**
  * @default 0x04000000
  * @constant
  * @memberOf QStyle
  * @name State_Small
  * @see QStyle#State
  * @see QStyle#StateFlag
  * @type Number
  */
QStyle.State_Small = 0x4000000;

/**
  * @default 0x08000000
  * @constant
  * @memberOf QStyle
  * @name State_Mini
  * @see QStyle#State
  * @see QStyle#StateFlag
  * @type Number
  */
QStyle.State_Mini = 0x8000000;

/**
  * @constructor 
  * @memberOf QStyle
  * @name StateFlag
  */
QStyle.StateFlag = function(value){;};

/**
  * @constructor 
  * @memberOf QStyle
  * @name State
  */
QStyle.State = function(value1, value2 /*, ...*/){;};


/**
  * @default 0xf0000000
  * @constant
  * @memberOf QStyle
  * @name CC_CustomBase
  * @see QStyle#ComplexControl
  * @type Number
  */
QStyle.CC_CustomBase = 0xf0000000;

/**
  * @default 0x0
  * @constant
  * @memberOf QStyle
  * @name CC_SpinBox
  * @see QStyle#ComplexControl
  * @type Number
  */
QStyle.CC_SpinBox = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QStyle
  * @name CC_ComboBox
  * @see QStyle#ComplexControl
  * @type Number
  */
QStyle.CC_ComboBox = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QStyle
  * @name CC_ScrollBar
  * @see QStyle#ComplexControl
  * @type Number
  */
QStyle.CC_ScrollBar = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QStyle
  * @name CC_Slider
  * @see QStyle#ComplexControl
  * @type Number
  */
QStyle.CC_Slider = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QStyle
  * @name CC_ToolButton
  * @see QStyle#ComplexControl
  * @type Number
  */
QStyle.CC_ToolButton = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QStyle
  * @name CC_TitleBar
  * @see QStyle#ComplexControl
  * @type Number
  */
QStyle.CC_TitleBar = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf QStyle
  * @name CC_Q3ListView
  * @see QStyle#ComplexControl
  * @type Number
  */
QStyle.CC_Q3ListView = 0x6;

/**
  * @default 0x7
  * @constant
  * @memberOf QStyle
  * @name CC_Dial
  * @see QStyle#ComplexControl
  * @type Number
  */
QStyle.CC_Dial = 0x7;

/**
  * @default 0x8
  * @constant
  * @memberOf QStyle
  * @name CC_GroupBox
  * @see QStyle#ComplexControl
  * @type Number
  */
QStyle.CC_GroupBox = 0x8;

/**
  * @default 0x9
  * @constant
  * @memberOf QStyle
  * @name CC_MdiControls
  * @see QStyle#ComplexControl
  * @type Number
  */
QStyle.CC_MdiControls = 0x9;

/**
  * @constructor 
  * @memberOf QStyle
  * @name ComplexControl
  */
QStyle.ComplexControl = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QStyle
  * @name RSIP_OnMouseClickAndAlreadyFocused
  * @see QStyle#RequestSoftwareInputPanel
  * @type Number
  */
QStyle.RSIP_OnMouseClickAndAlreadyFocused = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QStyle
  * @name RSIP_OnMouseClick
  * @see QStyle#RequestSoftwareInputPanel
  * @type Number
  */
QStyle.RSIP_OnMouseClick = 0x1;

/**
  * @constructor 
  * @memberOf QStyle
  * @name RequestSoftwareInputPanel
  */
QStyle.RequestSoftwareInputPanel = function(value){;};



/**
  * @default 0xf0000000
  * @constant
  * @memberOf QStyle
  * @name SE_CustomBase
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_CustomBase = 0xf0000000;

/**
  * @default 0x0
  * @constant
  * @memberOf QStyle
  * @name SE_PushButtonContents
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_PushButtonContents = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QStyle
  * @name SE_PushButtonFocusRect
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_PushButtonFocusRect = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QStyle
  * @name SE_CheckBoxIndicator
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_CheckBoxIndicator = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QStyle
  * @name SE_CheckBoxContents
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_CheckBoxContents = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QStyle
  * @name SE_CheckBoxFocusRect
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_CheckBoxFocusRect = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QStyle
  * @name SE_CheckBoxClickRect
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_CheckBoxClickRect = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf QStyle
  * @name SE_RadioButtonIndicator
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_RadioButtonIndicator = 0x6;

/**
  * @default 0x7
  * @constant
  * @memberOf QStyle
  * @name SE_RadioButtonContents
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_RadioButtonContents = 0x7;

/**
  * @default 0x8
  * @constant
  * @memberOf QStyle
  * @name SE_RadioButtonFocusRect
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_RadioButtonFocusRect = 0x8;

/**
  * @default 0x9
  * @constant
  * @memberOf QStyle
  * @name SE_RadioButtonClickRect
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_RadioButtonClickRect = 0x9;

/**
  * @default 0xa
  * @constant
  * @memberOf QStyle
  * @name SE_ComboBoxFocusRect
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_ComboBoxFocusRect = 0xa;

/**
  * @default 0xb
  * @constant
  * @memberOf QStyle
  * @name SE_SliderFocusRect
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_SliderFocusRect = 0xb;

/**
  * @default 0xc
  * @constant
  * @memberOf QStyle
  * @name SE_Q3DockWindowHandleRect
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_Q3DockWindowHandleRect = 0xc;

/**
  * @default 0xd
  * @constant
  * @memberOf QStyle
  * @name SE_ProgressBarGroove
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_ProgressBarGroove = 0xd;

/**
  * @default 0xe
  * @constant
  * @memberOf QStyle
  * @name SE_ProgressBarContents
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_ProgressBarContents = 0xe;

/**
  * @default 0xf
  * @constant
  * @memberOf QStyle
  * @name SE_ProgressBarLabel
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_ProgressBarLabel = 0xf;

/**
  * @default 0x10
  * @constant
  * @memberOf QStyle
  * @name SE_DialogButtonAccept
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_DialogButtonAccept = 0x10;

/**
  * @default 0x11
  * @constant
  * @memberOf QStyle
  * @name SE_DialogButtonReject
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_DialogButtonReject = 0x11;

/**
  * @default 0x12
  * @constant
  * @memberOf QStyle
  * @name SE_DialogButtonApply
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_DialogButtonApply = 0x12;

/**
  * @default 0x13
  * @constant
  * @memberOf QStyle
  * @name SE_DialogButtonHelp
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_DialogButtonHelp = 0x13;

/**
  * @default 0x14
  * @constant
  * @memberOf QStyle
  * @name SE_DialogButtonAll
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_DialogButtonAll = 0x14;

/**
  * @default 0x15
  * @constant
  * @memberOf QStyle
  * @name SE_DialogButtonAbort
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_DialogButtonAbort = 0x15;

/**
  * @default 0x16
  * @constant
  * @memberOf QStyle
  * @name SE_DialogButtonIgnore
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_DialogButtonIgnore = 0x16;

/**
  * @default 0x17
  * @constant
  * @memberOf QStyle
  * @name SE_DialogButtonRetry
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_DialogButtonRetry = 0x17;

/**
  * @default 0x18
  * @constant
  * @memberOf QStyle
  * @name SE_DialogButtonCustom
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_DialogButtonCustom = 0x18;

/**
  * @default 0x19
  * @constant
  * @memberOf QStyle
  * @name SE_ToolBoxTabContents
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_ToolBoxTabContents = 0x19;

/**
  * @default 0x1a
  * @constant
  * @memberOf QStyle
  * @name SE_HeaderLabel
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_HeaderLabel = 0x1a;

/**
  * @default 0x1b
  * @constant
  * @memberOf QStyle
  * @name SE_HeaderArrow
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_HeaderArrow = 0x1b;

/**
  * @default 0x1c
  * @constant
  * @memberOf QStyle
  * @name SE_TabWidgetTabBar
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_TabWidgetTabBar = 0x1c;

/**
  * @default 0x1d
  * @constant
  * @memberOf QStyle
  * @name SE_TabWidgetTabPane
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_TabWidgetTabPane = 0x1d;

/**
  * @default 0x1e
  * @constant
  * @memberOf QStyle
  * @name SE_TabWidgetTabContents
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_TabWidgetTabContents = 0x1e;

/**
  * @default 0x1f
  * @constant
  * @memberOf QStyle
  * @name SE_TabWidgetLeftCorner
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_TabWidgetLeftCorner = 0x1f;

/**
  * @default 0x20
  * @constant
  * @memberOf QStyle
  * @name SE_TabWidgetRightCorner
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_TabWidgetRightCorner = 0x20;

/**
  * @default 0x21
  * @constant
  * @memberOf QStyle
  * @name SE_ViewItemCheckIndicator
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_ViewItemCheckIndicator = 0x21;

/**
  * @default 0x22
  * @constant
  * @memberOf QStyle
  * @name SE_TabBarTearIndicator
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_TabBarTearIndicator = 0x22;

/**
  * @default 0x23
  * @constant
  * @memberOf QStyle
  * @name SE_TreeViewDisclosureItem
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_TreeViewDisclosureItem = 0x23;

/**
  * @default 0x24
  * @constant
  * @memberOf QStyle
  * @name SE_LineEditContents
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_LineEditContents = 0x24;

/**
  * @default 0x25
  * @constant
  * @memberOf QStyle
  * @name SE_FrameContents
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_FrameContents = 0x25;

/**
  * @default 0x26
  * @constant
  * @memberOf QStyle
  * @name SE_DockWidgetCloseButton
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_DockWidgetCloseButton = 0x26;

/**
  * @default 0x27
  * @constant
  * @memberOf QStyle
  * @name SE_DockWidgetFloatButton
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_DockWidgetFloatButton = 0x27;

/**
  * @default 0x28
  * @constant
  * @memberOf QStyle
  * @name SE_DockWidgetTitleBarText
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_DockWidgetTitleBarText = 0x28;

/**
  * @default 0x29
  * @constant
  * @memberOf QStyle
  * @name SE_DockWidgetIcon
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_DockWidgetIcon = 0x29;

/**
  * @default 0x2a
  * @constant
  * @memberOf QStyle
  * @name SE_CheckBoxLayoutItem
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_CheckBoxLayoutItem = 0x2a;

/**
  * @default 0x2b
  * @constant
  * @memberOf QStyle
  * @name SE_ComboBoxLayoutItem
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_ComboBoxLayoutItem = 0x2b;

/**
  * @default 0x2c
  * @constant
  * @memberOf QStyle
  * @name SE_DateTimeEditLayoutItem
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_DateTimeEditLayoutItem = 0x2c;

/**
  * @default 0x2d
  * @constant
  * @memberOf QStyle
  * @name SE_DialogButtonBoxLayoutItem
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_DialogButtonBoxLayoutItem = 0x2d;

/**
  * @default 0x2e
  * @constant
  * @memberOf QStyle
  * @name SE_LabelLayoutItem
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_LabelLayoutItem = 0x2e;

/**
  * @default 0x2f
  * @constant
  * @memberOf QStyle
  * @name SE_ProgressBarLayoutItem
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_ProgressBarLayoutItem = 0x2f;

/**
  * @default 0x30
  * @constant
  * @memberOf QStyle
  * @name SE_PushButtonLayoutItem
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_PushButtonLayoutItem = 0x30;

/**
  * @default 0x31
  * @constant
  * @memberOf QStyle
  * @name SE_RadioButtonLayoutItem
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_RadioButtonLayoutItem = 0x31;

/**
  * @default 0x32
  * @constant
  * @memberOf QStyle
  * @name SE_SliderLayoutItem
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_SliderLayoutItem = 0x32;

/**
  * @default 0x33
  * @constant
  * @memberOf QStyle
  * @name SE_SpinBoxLayoutItem
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_SpinBoxLayoutItem = 0x33;

/**
  * @default 0x34
  * @constant
  * @memberOf QStyle
  * @name SE_ToolButtonLayoutItem
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_ToolButtonLayoutItem = 0x34;

/**
  * @default 0x35
  * @constant
  * @memberOf QStyle
  * @name SE_FrameLayoutItem
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_FrameLayoutItem = 0x35;

/**
  * @default 0x36
  * @constant
  * @memberOf QStyle
  * @name SE_GroupBoxLayoutItem
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_GroupBoxLayoutItem = 0x36;

/**
  * @default 0x37
  * @constant
  * @memberOf QStyle
  * @name SE_TabWidgetLayoutItem
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_TabWidgetLayoutItem = 0x37;

/**
  * @default 0x38
  * @constant
  * @memberOf QStyle
  * @name SE_ItemViewItemDecoration
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_ItemViewItemDecoration = 0x38;

/**
  * @default 0x39
  * @constant
  * @memberOf QStyle
  * @name SE_ItemViewItemText
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_ItemViewItemText = 0x39;

/**
  * @default 0x3a
  * @constant
  * @memberOf QStyle
  * @name SE_ItemViewItemFocusRect
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_ItemViewItemFocusRect = 0x3a;

/**
  * @default 0x3b
  * @constant
  * @memberOf QStyle
  * @name SE_TabBarTabLeftButton
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_TabBarTabLeftButton = 0x3b;

/**
  * @default 0x3c
  * @constant
  * @memberOf QStyle
  * @name SE_TabBarTabRightButton
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_TabBarTabRightButton = 0x3c;

/**
  * @default 0x3d
  * @constant
  * @memberOf QStyle
  * @name SE_TabBarTabText
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_TabBarTabText = 0x3d;

/**
  * @default 0x3e
  * @constant
  * @memberOf QStyle
  * @name SE_ShapedFrameContents
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_ShapedFrameContents = 0x3e;

/**
  * @default 0x3f
  * @constant
  * @memberOf QStyle
  * @name SE_ToolBarHandle
  * @see QStyle#SubElement
  * @type Number
  */
QStyle.SE_ToolBarHandle = 0x3f;

/**
  * @constructor 
  * @memberOf QStyle
  * @name SubElement
  */
QStyle.SubElement = function(value){;};



/**
  * @name combinedLayoutSpacing
  * @function
  * @memberOf QStyle.prototype
  * @param {QSizePolicy.ControlTypes} controls1
  * @param {QSizePolicy.ControlTypes} controls2
  * @param {QPrinter.Orientation} orientation
  * @param {QStyleOption} option
  * @param {QWidget} widget
  * @returns {Numeric}
  */
QStyle.prototype.combinedLayoutSpacing = function(controls1, controls2, orientation, option, widget){return new Numeric();};

/**
  * @name drawComplexControl
  * @function
  * @memberOf QStyle.prototype
  * @param {QStyle.ComplexControl} cc
  * @param {QStyleOptionComplex} opt
  * @param {QPainter} p
  * @param {QWidget} widget
  * @returns {undefined}
  */
QStyle.prototype.drawComplexControl = function(cc, opt, p, widget){return undefined;};

/**
  * @name drawControl
  * @function
  * @memberOf QStyle.prototype
  * @param {QStyle.ControlElement} element
  * @param {QStyleOption} opt
  * @param {QPainter} p
  * @param {QWidget} w
  * @returns {undefined}
  */
QStyle.prototype.drawControl = function(element, opt, p, w){return undefined;};

/**
  * @name drawItemPixmap
  * @function
  * @memberOf QStyle.prototype
  * @param {QPainter} painter
  * @param {QRect} rect
  * @param {Numeric} alignment
  * @param {QPixmap} pixmap
  * @returns {undefined}
  */
QStyle.prototype.drawItemPixmap = function(painter, rect, alignment, pixmap){return undefined;};

/**
  * @name drawItemText
  * @function
  * @memberOf QStyle.prototype
  * @param {QPainter} painter
  * @param {QRect} rect
  * @param {Numeric} flags
  * @param {QPalette} pal
  * @param {Boolean} enabled
  * @param {String} text
  * @param {QPalette.ColorRole} textRole
  * @returns {undefined}
  */
QStyle.prototype.drawItemText = function(painter, rect, flags, pal, enabled, text, textRole){return undefined;};

/**
  * @name drawPrimitive
  * @function
  * @memberOf QStyle.prototype
  * @param {QStyle.PrimitiveElement} pe
  * @param {QStyleOption} opt
  * @param {QPainter} p
  * @param {QWidget} w
  * @returns {undefined}
  */
QStyle.prototype.drawPrimitive = function(pe, opt, p, w){return undefined;};

/**
  * @name generatedIconPixmap
  * @function
  * @memberOf QStyle.prototype
  * @param {QLCDNumber.Mode} iconMode
  * @param {QPixmap} pixmap
  * @param {QStyleOption} opt
  * @returns {QPixmap}
  */
QStyle.prototype.generatedIconPixmap = function(iconMode, pixmap, opt){return new QPixmap();};

/**
  * @name hitTestComplexControl
  * @function
  * @memberOf QStyle.prototype
  * @param {QStyle.ComplexControl} cc
  * @param {QStyleOptionComplex} opt
  * @param {QPoint} pt
  * @param {QWidget} widget
  * @returns {QStyle.SubControl}
  */
QStyle.prototype.hitTestComplexControl = function(cc, opt, pt, widget){return new QStyle.SubControl();};

/**
  * @name itemPixmapRect
  * @function
  * @memberOf QStyle.prototype
  * @param {QRect} r
  * @param {Numeric} flags
  * @param {QPixmap} pixmap
  * @returns {QRect}
  */
QStyle.prototype.itemPixmapRect = function(r, flags, pixmap){return new QRect();};

/**
  * @name layoutSpacing
  * @function
  * @memberOf QStyle.prototype
  * @param {QSizePolicy.ControlType} control1
  * @param {QSizePolicy.ControlType} control2
  * @param {QPrinter.Orientation} orientation
  * @param {QStyleOption} option
  * @param {QWidget} widget
  * @returns {Numeric}
  */
QStyle.prototype.layoutSpacing = function(control1, control2, orientation, option, widget){return new Numeric();};

/**
  * @name pixelMetric
  * @function
  * @memberOf QStyle.prototype
  * @param {QStyle.PixelMetric} metric
  * @param {QStyleOption} option
  * @param {QWidget} widget
  * @returns {Numeric}
  */
QStyle.prototype.pixelMetric = function(metric, option, widget){return new Numeric();};

/**
  * @name polish
  * @function
  * @memberOf QStyle.prototype
  * @param {QApplication} arg__1
  * @returns {undefined}
  */
QStyle.prototype.polish = function(arg__1){return undefined;};

/**
  * @name proxy
  * @function
  * @memberOf QStyle.prototype
  * @returns {QStyle}
  */
QStyle.prototype.proxy = function(){return new QStyle();};

/**
  * @name sizeFromContents
  * @function
  * @memberOf QStyle.prototype
  * @param {QStyle.ContentsType} ct
  * @param {QStyleOption} opt
  * @param {QSize} contentsSize
  * @param {QWidget} w
  * @returns {QSize}
  */
QStyle.prototype.sizeFromContents = function(ct, opt, contentsSize, w){return new QSize();};

/**
  * @name standardIcon
  * @function
  * @memberOf QStyle.prototype
  * @param {QStyle.StandardPixmap} standardIcon
  * @param {QStyleOption} option
  * @param {QWidget} widget
  * @returns {QIcon}
  */
QStyle.prototype.standardIcon = function(standardIcon, option, widget){return new QIcon();};

/**
  * @name standardPalette
  * @function
  * @memberOf QStyle.prototype
  * @returns {QPalette}
  */
QStyle.prototype.standardPalette = function(){return new QPalette();};

/**
  * @name standardPixmap
  * @function
  * @memberOf QStyle.prototype
  * @param {QStyle.StandardPixmap} standardPixmap
  * @param {QStyleOption} opt
  * @param {QWidget} widget
  * @returns {QPixmap}
  */
QStyle.prototype.standardPixmap = function(standardPixmap, opt, widget){return new QPixmap();};

/**
  * @name styleHint
  * @function
  * @memberOf QStyle.prototype
  * @param {QStyle.StyleHint} stylehint
  * @param {QStyleOption} opt
  * @param {QWidget} widget
  * @param {QStyleHintReturn} returnData
  * @returns {Numeric}
  */
QStyle.prototype.styleHint = function(stylehint, opt, widget, returnData){return new Numeric();};

/**
  * @name subControlRect
  * @function
  * @memberOf QStyle.prototype
  * @param {QStyle.ComplexControl} cc
  * @param {QStyleOptionComplex} opt
  * @param {QStyle.SubControl} sc
  * @param {QWidget} widget
  * @returns {QRect}
  */
QStyle.prototype.subControlRect = function(cc, opt, sc, widget){return new QRect();};

/**
  * @name subElementRect
  * @function
  * @memberOf QStyle.prototype
  * @param {QStyle.SubElement} subElement
  * @param {QStyleOption} option
  * @param {QWidget} widget
  * @returns {QRect}
  */
QStyle.prototype.subElementRect = function(subElement, option, widget){return new QRect();};

/**
  * @name unpolish
  * @function
  * @memberOf QStyle.prototype
  * @param {QApplication} arg__1
  * @returns {undefined}
  */
QStyle.prototype.unpolish = function(arg__1){return undefined;};

