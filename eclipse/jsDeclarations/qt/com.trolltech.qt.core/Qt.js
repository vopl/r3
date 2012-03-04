/**
  * @namespace Qt from package com.trolltech.qt.core
  */
var Qt = {};

/**
  * @default 0x0
  * @constant
  * @memberOf Qt
  * @name WidgetShortcut
  * @see Qt#ShortcutContext
  * @type Number
  */
Qt.WidgetShortcut = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf Qt
  * @name WindowShortcut
  * @see Qt#ShortcutContext
  * @type Number
  */
Qt.WindowShortcut = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf Qt
  * @name ApplicationShortcut
  * @see Qt#ShortcutContext
  * @type Number
  */
Qt.ApplicationShortcut = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf Qt
  * @name WidgetWithChildrenShortcut
  * @see Qt#ShortcutContext
  * @type Number
  */
Qt.WidgetWithChildrenShortcut = 0x3;

/**
  * @constructor 
  * @memberOf Qt
  * @name ShortcutContext
  */
Qt.ShortcutContext = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf Qt
  * @name Unchecked
  * @see Qt#CheckState
  * @type Number
  */
Qt.Unchecked = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf Qt
  * @name PartiallyChecked
  * @see Qt#CheckState
  * @type Number
  */
Qt.PartiallyChecked = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf Qt
  * @name Checked
  * @see Qt#CheckState
  * @type Number
  */
Qt.Checked = 0x2;

/**
  * @constructor 
  * @memberOf Qt
  * @name CheckState
  */
Qt.CheckState = function(value){;};



/**
  * @default 0
  * @constant
  * @memberOf Qt
  * @name NoFocus
  * @see Qt#FocusPolicy
  * @type Number
  */
Qt.NoFocus = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf Qt
  * @name TabFocus
  * @see Qt#FocusPolicy
  * @type Number
  */
Qt.TabFocus = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf Qt
  * @name ClickFocus
  * @see Qt#FocusPolicy
  * @type Number
  */
Qt.ClickFocus = 0x2;

/**
  * @default TabFocus|ClickFocus|0x8
  * @constant
  * @memberOf Qt
  * @name StrongFocus
  * @see Qt#FocusPolicy
  * @type Number
  */
Qt.StrongFocus = 0xb;

/**
  * @default StrongFocus|0x4
  * @constant
  * @memberOf Qt
  * @name WheelFocus
  * @see Qt#FocusPolicy
  * @type Number
  */
Qt.WheelFocus = 0xf;

/**
  * @constructor 
  * @memberOf Qt
  * @name FocusPolicy
  */
Qt.FocusPolicy = function(value){;};



/**
  * @default 1
  * @constant
  * @memberOf Qt
  * @name TapGesture
  * @see Qt#GestureType
  * @type Number
  */
Qt.TapGesture = 0x1;

/**
  * @default 2
  * @constant
  * @memberOf Qt
  * @name TapAndHoldGesture
  * @see Qt#GestureType
  * @type Number
  */
Qt.TapAndHoldGesture = 0x2;

/**
  * @default 3
  * @constant
  * @memberOf Qt
  * @name PanGesture
  * @see Qt#GestureType
  * @type Number
  */
Qt.PanGesture = 0x3;

/**
  * @default 4
  * @constant
  * @memberOf Qt
  * @name PinchGesture
  * @see Qt#GestureType
  * @type Number
  */
Qt.PinchGesture = 0x4;

/**
  * @default 5
  * @constant
  * @memberOf Qt
  * @name SwipeGesture
  * @see Qt#GestureType
  * @type Number
  */
Qt.SwipeGesture = 0x5;

/**
  * @default 0x0100
  * @constant
  * @memberOf Qt
  * @name CustomGesture
  * @see Qt#GestureType
  * @type Number
  */
Qt.CustomGesture = 0x100;

/**
  * @default ~0u
  * @constant
  * @memberOf Qt
  * @name LastGestureType
  * @see Qt#GestureType
  * @type Number
  */
Qt.LastGestureType = 0x101;

/**
  * @constructor 
  * @memberOf Qt
  * @name GestureType
  */
Qt.GestureType = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf Qt
  * @name IgnoreAction
  * @see Qt#DropActions
  * @see Qt#DropAction
  * @type Number
  */
Qt.IgnoreAction = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf Qt
  * @name CopyAction
  * @see Qt#DropActions
  * @see Qt#DropAction
  * @type Number
  */
Qt.CopyAction = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf Qt
  * @name MoveAction
  * @see Qt#DropActions
  * @see Qt#DropAction
  * @type Number
  */
Qt.MoveAction = 0x2;

/**
  * @default 0x4
  * @constant
  * @memberOf Qt
  * @name LinkAction
  * @see Qt#DropActions
  * @see Qt#DropAction
  * @type Number
  */
Qt.LinkAction = 0x4;

/**
  * @default 0xff
  * @constant
  * @memberOf Qt
  * @name ActionMask
  * @see Qt#DropActions
  * @see Qt#DropAction
  * @type Number
  */
Qt.ActionMask = 0xff;

/**
  * @default 0x8002
  * @constant
  * @memberOf Qt
  * @name TargetMoveAction
  * @see Qt#DropActions
  * @see Qt#DropAction
  * @type Number
  */
Qt.TargetMoveAction = 0x8002;

/**
  * @constructor 
  * @memberOf Qt
  * @name DropAction
  */
Qt.DropAction = function(value){;};

/**
  * @constructor 
  * @memberOf Qt
  * @name DropActions
  */
Qt.DropActions = function(value1, value2 /*, ...*/){;};


/**
  * @default 0x80000000
  * @constant
  * @memberOf Qt
  * @name WindowSoftkeysRespondHint
  * @see Qt#WindowFlags
  * @see Qt#WindowType
  * @type Number
  */
Qt.WindowSoftkeysRespondHint = 0x80000000;

/**
  * @default 0x00000000
  * @constant
  * @memberOf Qt
  * @name Widget
  * @see Qt#WindowFlags
  * @see Qt#WindowType
  * @type Number
  */
Qt.Widget = 0x0;

/**
  * @default 0x00000001
  * @constant
  * @memberOf Qt
  * @name Window
  * @see Qt#WindowFlags
  * @see Qt#WindowType
  * @type Number
  */
Qt.Window = 0x1;

/**
  * @default 0x00000002|Window
  * @constant
  * @memberOf Qt
  * @name Dialog
  * @see Qt#WindowFlags
  * @see Qt#WindowType
  * @type Number
  */
Qt.Dialog = 0x3;

/**
  * @default 0x00000004|Window
  * @constant
  * @memberOf Qt
  * @name Sheet
  * @see Qt#WindowFlags
  * @see Qt#WindowType
  * @type Number
  */
Qt.Sheet = 0x5;

/**
  * @default 0x00000006|Window
  * @constant
  * @memberOf Qt
  * @name Drawer
  * @see Qt#WindowFlags
  * @see Qt#WindowType
  * @type Number
  */
Qt.Drawer = 0x7;

/**
  * @default 0x00000008|Window
  * @constant
  * @memberOf Qt
  * @name Popup
  * @see Qt#WindowFlags
  * @see Qt#WindowType
  * @type Number
  */
Qt.Popup = 0x9;

/**
  * @default 0x0000000a|Window
  * @constant
  * @memberOf Qt
  * @name Tool
  * @see Qt#WindowFlags
  * @see Qt#WindowType
  * @type Number
  */
Qt.Tool = 0xb;

/**
  * @default 0x0000000c|Window
  * @constant
  * @memberOf Qt
  * @name ToolTip
  * @see Qt#WindowFlags
  * @see Qt#WindowType
  * @type Number
  */
Qt.ToolTip = 0xd;

/**
  * @default 0x0000000e|Window
  * @constant
  * @memberOf Qt
  * @name SplashScreen
  * @see Qt#WindowFlags
  * @see Qt#WindowType
  * @type Number
  */
Qt.SplashScreen = 0xf;

/**
  * @default 0x00000010|Window
  * @constant
  * @memberOf Qt
  * @name Desktop
  * @see Qt#WindowFlags
  * @see Qt#WindowType
  * @type Number
  */
Qt.Desktop = 0x11;

/**
  * @default 0x00000012
  * @constant
  * @memberOf Qt
  * @name SubWindow
  * @see Qt#WindowFlags
  * @see Qt#WindowType
  * @type Number
  */
Qt.SubWindow = 0x12;

/**
  * @default 0x000000ff
  * @constant
  * @memberOf Qt
  * @name WindowType_Mask
  * @see Qt#WindowFlags
  * @see Qt#WindowType
  * @type Number
  */
Qt.WindowType_Mask = 0xff;

/**
  * @default 0x00000100
  * @constant
  * @memberOf Qt
  * @name MSWindowsFixedSizeDialogHint
  * @see Qt#WindowFlags
  * @see Qt#WindowType
  * @type Number
  */
Qt.MSWindowsFixedSizeDialogHint = 0x100;

/**
  * @default 0x00000200
  * @constant
  * @memberOf Qt
  * @name MSWindowsOwnDC
  * @see Qt#WindowFlags
  * @see Qt#WindowType
  * @type Number
  */
Qt.MSWindowsOwnDC = 0x200;

/**
  * @default 0x00000400
  * @constant
  * @memberOf Qt
  * @name X11BypassWindowManagerHint
  * @see Qt#WindowFlags
  * @see Qt#WindowType
  * @type Number
  */
Qt.X11BypassWindowManagerHint = 0x400;

/**
  * @default 0x00000800
  * @constant
  * @memberOf Qt
  * @name FramelessWindowHint
  * @see Qt#WindowFlags
  * @see Qt#WindowType
  * @type Number
  */
Qt.FramelessWindowHint = 0x800;

/**
  * @default 0x00001000
  * @constant
  * @memberOf Qt
  * @name WindowTitleHint
  * @see Qt#WindowFlags
  * @see Qt#WindowType
  * @type Number
  */
Qt.WindowTitleHint = 0x1000;

/**
  * @default 0x00002000
  * @constant
  * @memberOf Qt
  * @name WindowSystemMenuHint
  * @see Qt#WindowFlags
  * @see Qt#WindowType
  * @type Number
  */
Qt.WindowSystemMenuHint = 0x2000;

/**
  * @default 0x00004000
  * @constant
  * @memberOf Qt
  * @name WindowMinimizeButtonHint
  * @see Qt#WindowFlags
  * @see Qt#WindowType
  * @type Number
  */
Qt.WindowMinimizeButtonHint = 0x4000;

/**
  * @default 0x00008000
  * @constant
  * @memberOf Qt
  * @name WindowMaximizeButtonHint
  * @see Qt#WindowFlags
  * @see Qt#WindowType
  * @type Number
  */
Qt.WindowMaximizeButtonHint = 0x8000;

/**
  * @default WindowMinimizeButtonHint|WindowMaximizeButtonHint
  * @constant
  * @memberOf Qt
  * @name WindowMinMaxButtonsHint
  * @see Qt#WindowFlags
  * @see Qt#WindowType
  * @type Number
  */
Qt.WindowMinMaxButtonsHint = 0xc000;

/**
  * @default 0x00010000
  * @constant
  * @memberOf Qt
  * @name WindowContextHelpButtonHint
  * @see Qt#WindowFlags
  * @see Qt#WindowType
  * @type Number
  */
Qt.WindowContextHelpButtonHint = 0x10000;

/**
  * @default 0x00020000
  * @constant
  * @memberOf Qt
  * @name WindowShadeButtonHint
  * @see Qt#WindowFlags
  * @see Qt#WindowType
  * @type Number
  */
Qt.WindowShadeButtonHint = 0x20000;

/**
  * @default 0x00040000
  * @constant
  * @memberOf Qt
  * @name WindowStaysOnTopHint
  * @see Qt#WindowFlags
  * @see Qt#WindowType
  * @type Number
  */
Qt.WindowStaysOnTopHint = 0x40000;

/**
  * @default 0x00080000
  * @constant
  * @memberOf Qt
  * @name WindowOkButtonHint
  * @see Qt#WindowFlags
  * @see Qt#WindowType
  * @type Number
  */
Qt.WindowOkButtonHint = 0x80000;

/**
  * @default 0x00100000
  * @constant
  * @memberOf Qt
  * @name WindowCancelButtonHint
  * @see Qt#WindowFlags
  * @see Qt#WindowType
  * @type Number
  */
Qt.WindowCancelButtonHint = 0x100000;

/**
  * @default 0x02000000
  * @constant
  * @memberOf Qt
  * @name CustomizeWindowHint
  * @see Qt#WindowFlags
  * @see Qt#WindowType
  * @type Number
  */
Qt.CustomizeWindowHint = 0x2000000;

/**
  * @default 0x04000000
  * @constant
  * @memberOf Qt
  * @name WindowStaysOnBottomHint
  * @see Qt#WindowFlags
  * @see Qt#WindowType
  * @type Number
  */
Qt.WindowStaysOnBottomHint = 0x4000000;

/**
  * @default 0x08000000
  * @constant
  * @memberOf Qt
  * @name WindowCloseButtonHint
  * @see Qt#WindowFlags
  * @see Qt#WindowType
  * @type Number
  */
Qt.WindowCloseButtonHint = 0x8000000;

/**
  * @default 0x10000000
  * @constant
  * @memberOf Qt
  * @name MacWindowToolBarButtonHint
  * @see Qt#WindowFlags
  * @see Qt#WindowType
  * @type Number
  */
Qt.MacWindowToolBarButtonHint = 0x10000000;

/**
  * @default 0x20000000
  * @constant
  * @memberOf Qt
  * @name BypassGraphicsProxyWidget
  * @see Qt#WindowFlags
  * @see Qt#WindowType
  * @type Number
  */
Qt.BypassGraphicsProxyWidget = 0x20000000;

/**
  * @default 0x40000000
  * @constant
  * @memberOf Qt
  * @name WindowSoftkeysVisibleHint
  * @see Qt#WindowFlags
  * @see Qt#WindowType
  * @type Number
  */
Qt.WindowSoftkeysVisibleHint = 0x40000000;

/**
  * @constructor 
  * @memberOf Qt
  * @name WindowType
  */
Qt.WindowType = function(value){;};

/**
  * @constructor 
  * @memberOf Qt
  * @name WindowFlags
  */
Qt.WindowFlags = function(value1, value2 /*, ...*/){;};


/**
  * @default 0x0
  * @constant
  * @memberOf Qt
  * @name TextDate
  * @see Qt#DateFormat
  * @type Number
  */
Qt.TextDate = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf Qt
  * @name ISODate
  * @see Qt#DateFormat
  * @type Number
  */
Qt.ISODate = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf Qt
  * @name SystemLocaleDate
  * @see Qt#DateFormat
  * @type Number
  */
Qt.SystemLocaleDate = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf Qt
  * @name LocaleDate
  * @see Qt#DateFormat
  * @type Number
  */
Qt.LocaleDate = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf Qt
  * @name SystemLocaleShortDate
  * @see Qt#DateFormat
  * @type Number
  */
Qt.SystemLocaleShortDate = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf Qt
  * @name SystemLocaleLongDate
  * @see Qt#DateFormat
  * @type Number
  */
Qt.SystemLocaleLongDate = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf Qt
  * @name DefaultLocaleShortDate
  * @see Qt#DateFormat
  * @type Number
  */
Qt.DefaultLocaleShortDate = 0x6;

/**
  * @default 0x7
  * @constant
  * @memberOf Qt
  * @name DefaultLocaleLongDate
  * @see Qt#DateFormat
  * @type Number
  */
Qt.DefaultLocaleLongDate = 0x7;

/**
  * @constructor 
  * @memberOf Qt
  * @name DateFormat
  */
Qt.DateFormat = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf Qt
  * @name PlainText
  * @see Qt#TextFormat
  * @type Number
  */
Qt.PlainText = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf Qt
  * @name RichText
  * @see Qt#TextFormat
  * @type Number
  */
Qt.RichText = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf Qt
  * @name AutoText
  * @see Qt#TextFormat
  * @type Number
  */
Qt.AutoText = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf Qt
  * @name LogText
  * @see Qt#TextFormat
  * @type Number
  */
Qt.LogText = 0x3;

/**
  * @constructor 
  * @memberOf Qt
  * @name TextFormat
  */
Qt.TextFormat = function(value){;};



/**
  * @default 0x00
  * @constant
  * @memberOf Qt
  * @name MiterJoin
  * @see Qt#PenJoinStyle
  * @type Number
  */
Qt.MiterJoin = 0x0;

/**
  * @default 0x40
  * @constant
  * @memberOf Qt
  * @name BevelJoin
  * @see Qt#PenJoinStyle
  * @type Number
  */
Qt.BevelJoin = 0x40;

/**
  * @default 0x80
  * @constant
  * @memberOf Qt
  * @name RoundJoin
  * @see Qt#PenJoinStyle
  * @type Number
  */
Qt.RoundJoin = 0x80;

/**
  * @default 0x100
  * @constant
  * @memberOf Qt
  * @name SvgMiterJoin
  * @see Qt#PenJoinStyle
  * @type Number
  */
Qt.SvgMiterJoin = 0x100;

/**
  * @default 0x1c0
  * @constant
  * @memberOf Qt
  * @name MPenJoinStyle
  * @see Qt#PenJoinStyle
  * @type Number
  */
Qt.MPenJoinStyle = 0x1c0;

/**
  * @constructor 
  * @memberOf Qt
  * @name PenJoinStyle
  */
Qt.PenJoinStyle = function(value){;};



/**
  * @default 0x01
  * @constant
  * @memberOf Qt
  * @name DontStartGestureOnChildren
  * @see Qt#GestureFlags
  * @see Qt#GestureFlag
  * @type Number
  */
Qt.DontStartGestureOnChildren = 0x1;

/**
  * @default 0x02
  * @constant
  * @memberOf Qt
  * @name ReceivePartialGestures
  * @see Qt#GestureFlags
  * @see Qt#GestureFlag
  * @type Number
  */
Qt.ReceivePartialGestures = 0x2;

/**
  * @default 0x04
  * @constant
  * @memberOf Qt
  * @name IgnoredGesturesPropagateToParent
  * @see Qt#GestureFlags
  * @see Qt#GestureFlag
  * @type Number
  */
Qt.IgnoredGesturesPropagateToParent = 0x4;

/**
  * @constructor 
  * @memberOf Qt
  * @name GestureFlag
  */
Qt.GestureFlag = function(value){;};

/**
  * @constructor 
  * @memberOf Qt
  * @name GestureFlags
  */
Qt.GestureFlags = function(value1, value2 /*, ...*/){;};


/**
  * @default 0x0
  * @constant
  * @memberOf Qt
  * @name CaseInsensitive
  * @see Qt#CaseSensitivity
  * @type Number
  */
Qt.CaseInsensitive = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf Qt
  * @name CaseSensitive
  * @see Qt#CaseSensitivity
  * @type Number
  */
Qt.CaseSensitive = 0x1;

/**
  * @constructor 
  * @memberOf Qt
  * @name CaseSensitivity
  */
Qt.CaseSensitivity = function(value){;};



/**
  * @default -1
  * @constant
  * @memberOf Qt
  * @name LowEventPriority
  * @see Qt#EventPriority
  * @type Number
  */
Qt.LowEventPriority = 0xffffffff;

/**
  * @default 0
  * @constant
  * @memberOf Qt
  * @name NormalEventPriority
  * @see Qt#EventPriority
  * @type Number
  */
Qt.NormalEventPriority = 0x0;

/**
  * @default 1
  * @constant
  * @memberOf Qt
  * @name HighEventPriority
  * @see Qt#EventPriority
  * @type Number
  */
Qt.HighEventPriority = 0x1;

/**
  * @constructor 
  * @memberOf Qt
  * @name EventPriority
  */
Qt.EventPriority = function(value){;};



/**
  * @default 0x00000000
  * @constant
  * @memberOf Qt
  * @name AutoColor
  * @see Qt#ImageConversionFlags
  * @see Qt#ImageConversionFlag
  * @type Number
  */
Qt.AutoColor = 0x0;

/**
  * @default 0x00000002
  * @constant
  * @memberOf Qt
  * @name MonoOnly
  * @see Qt#ImageConversionFlags
  * @see Qt#ImageConversionFlag
  * @type Number
  */
Qt.MonoOnly = 0x2;

/**
  * @default 0x00000003
  * @constant
  * @memberOf Qt
  * @name ColorMode_Mask
  * @see Qt#ImageConversionFlags
  * @see Qt#ImageConversionFlag
  * @type Number
  */
Qt.ColorMode_Mask = 0x3;

/**
  * @default 0x00000004
  * @constant
  * @memberOf Qt
  * @name OrderedAlphaDither
  * @see Qt#ImageConversionFlags
  * @see Qt#ImageConversionFlag
  * @type Number
  */
Qt.OrderedAlphaDither = 0x4;

/**
  * @default 0x00000008
  * @constant
  * @memberOf Qt
  * @name DiffuseAlphaDither
  * @see Qt#ImageConversionFlags
  * @see Qt#ImageConversionFlag
  * @type Number
  */
Qt.DiffuseAlphaDither = 0x8;

/**
  * @default 0x0000000c
  * @constant
  * @memberOf Qt
  * @name AlphaDither_Mask
  * @see Qt#ImageConversionFlags
  * @see Qt#ImageConversionFlag
  * @type Number
  */
Qt.AlphaDither_Mask = 0xc;

/**
  * @default 0x00000010
  * @constant
  * @memberOf Qt
  * @name OrderedDither
  * @see Qt#ImageConversionFlags
  * @see Qt#ImageConversionFlag
  * @type Number
  */
Qt.OrderedDither = 0x10;

/**
  * @default 0x00000020
  * @constant
  * @memberOf Qt
  * @name ThresholdDither
  * @see Qt#ImageConversionFlags
  * @see Qt#ImageConversionFlag
  * @type Number
  */
Qt.ThresholdDither = 0x20;

/**
  * @default 0x00000030
  * @constant
  * @memberOf Qt
  * @name Dither_Mask
  * @see Qt#ImageConversionFlags
  * @see Qt#ImageConversionFlag
  * @type Number
  */
Qt.Dither_Mask = 0x30;

/**
  * @default 0x00000040
  * @constant
  * @memberOf Qt
  * @name PreferDither
  * @see Qt#ImageConversionFlags
  * @see Qt#ImageConversionFlag
  * @type Number
  */
Qt.PreferDither = 0x40;

/**
  * @default 0x00000080
  * @constant
  * @memberOf Qt
  * @name AvoidDither
  * @see Qt#ImageConversionFlags
  * @see Qt#ImageConversionFlag
  * @type Number
  */
Qt.AvoidDither = 0x80;

/**
  * @default 0x000000c0
  * @constant
  * @memberOf Qt
  * @name DitherMode_Mask
  * @see Qt#ImageConversionFlags
  * @see Qt#ImageConversionFlag
  * @type Number
  */
Qt.DitherMode_Mask = 0xc0;

/**
  * @default 0x00000100
  * @constant
  * @memberOf Qt
  * @name NoOpaqueDetection
  * @see Qt#ImageConversionFlags
  * @see Qt#ImageConversionFlag
  * @type Number
  */
Qt.NoOpaqueDetection = 0x100;

/**
  * @default 0x00000200
  * @constant
  * @memberOf Qt
  * @name NoFormatConversion
  * @see Qt#ImageConversionFlags
  * @see Qt#ImageConversionFlag
  * @type Number
  */
Qt.NoFormatConversion = 0x200;

/**
  * @constructor 
  * @memberOf Qt
  * @name ImageConversionFlag
  */
Qt.ImageConversionFlag = function(value){;};

/**
  * @constructor 
  * @memberOf Qt
  * @name ImageConversionFlags
  */
Qt.ImageConversionFlags = function(value1, value2 /*, ...*/){;};


/**
  * @default 0x0
  * @constant
  * @memberOf Qt
  * @name NoGesture
  * @see Qt#GestureState
  * @type Number
  */
Qt.NoGesture = 0x0;

/**
  * @default 1
  * @constant
  * @memberOf Qt
  * @name GestureStarted
  * @see Qt#GestureState
  * @type Number
  */
Qt.GestureStarted = 0x1;

/**
  * @default 2
  * @constant
  * @memberOf Qt
  * @name GestureUpdated
  * @see Qt#GestureState
  * @type Number
  */
Qt.GestureUpdated = 0x2;

/**
  * @default 3
  * @constant
  * @memberOf Qt
  * @name GestureFinished
  * @see Qt#GestureState
  * @type Number
  */
Qt.GestureFinished = 0x3;

/**
  * @default 4
  * @constant
  * @memberOf Qt
  * @name GestureCanceled
  * @see Qt#GestureState
  * @type Number
  */
Qt.GestureCanceled = 0x4;

/**
  * @constructor 
  * @memberOf Qt
  * @name GestureState
  */
Qt.GestureState = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf Qt
  * @name TransparentMode
  * @see Qt#BGMode
  * @type Number
  */
Qt.TransparentMode = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf Qt
  * @name OpaqueMode
  * @see Qt#BGMode
  * @type Number
  */
Qt.OpaqueMode = 0x1;

/**
  * @constructor 
  * @memberOf Qt
  * @name BGMode
  */
Qt.BGMode = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf Qt
  * @name AutoConnection
  * @see Qt#ConnectionType
  * @type Number
  */
Qt.AutoConnection = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf Qt
  * @name DirectConnection
  * @see Qt#ConnectionType
  * @type Number
  */
Qt.DirectConnection = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf Qt
  * @name QueuedConnection
  * @see Qt#ConnectionType
  * @type Number
  */
Qt.QueuedConnection = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf Qt
  * @name AutoCompatConnection
  * @see Qt#ConnectionType
  * @type Number
  */
Qt.AutoCompatConnection = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf Qt
  * @name BlockingQueuedConnection
  * @see Qt#ConnectionType
  * @type Number
  */
Qt.BlockingQueuedConnection = 0x4;

/**
  * @default 0x80
  * @constant
  * @memberOf Qt
  * @name UniqueConnection
  * @see Qt#ConnectionType
  * @type Number
  */
Qt.UniqueConnection = 0x80;

/**
  * @constructor 
  * @memberOf Qt
  * @name ConnectionType
  */
Qt.ConnectionType = function(value){;};



/**
  * @default 0
  * @constant
  * @memberOf Qt
  * @name NoToolBarArea
  * @see Qt#ToolBarAreas
  * @see Qt#ToolBarArea
  * @type Number
  */
Qt.NoToolBarArea = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf Qt
  * @name LeftToolBarArea
  * @see Qt#ToolBarAreas
  * @see Qt#ToolBarArea
  * @type Number
  */
Qt.LeftToolBarArea = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf Qt
  * @name RightToolBarArea
  * @see Qt#ToolBarAreas
  * @see Qt#ToolBarArea
  * @type Number
  */
Qt.RightToolBarArea = 0x2;

/**
  * @default 0x4
  * @constant
  * @memberOf Qt
  * @name TopToolBarArea
  * @see Qt#ToolBarAreas
  * @see Qt#ToolBarArea
  * @type Number
  */
Qt.TopToolBarArea = 0x4;

/**
  * @default 0x8
  * @constant
  * @memberOf Qt
  * @name BottomToolBarArea
  * @see Qt#ToolBarAreas
  * @see Qt#ToolBarArea
  * @type Number
  */
Qt.BottomToolBarArea = 0x8;

/**
  * @default 0xf
  * @constant
  * @memberOf Qt
  * @name ToolBarArea_Mask
  * @see Qt#ToolBarAreas
  * @see Qt#ToolBarArea
  * @type Number
  */
Qt.ToolBarArea_Mask = 0xf;

/**
  * @constructor 
  * @memberOf Qt
  * @name ToolBarArea
  */
Qt.ToolBarArea = function(value){;};

/**
  * @constructor 
  * @memberOf Qt
  * @name ToolBarAreas
  */
Qt.ToolBarAreas = function(value1, value2 /*, ...*/){;};


/**
  * @default 0x0
  * @constant
  * @memberOf Qt
  * @name DeviceCoordinates
  * @see Qt#CoordinateSystem
  * @type Number
  */
Qt.DeviceCoordinates = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf Qt
  * @name LogicalCoordinates
  * @see Qt#CoordinateSystem
  * @type Number
  */
Qt.LogicalCoordinates = 0x1;

/**
  * @constructor 
  * @memberOf Qt
  * @name CoordinateSystem
  */
Qt.CoordinateSystem = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf Qt
  * @name AbsoluteSize
  * @see Qt#SizeMode
  * @type Number
  */
Qt.AbsoluteSize = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf Qt
  * @name RelativeSize
  * @see Qt#SizeMode
  * @type Number
  */
Qt.RelativeSize = 0x1;

/**
  * @constructor 
  * @memberOf Qt
  * @name SizeMode
  */
Qt.SizeMode = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf Qt
  * @name MouseFocusReason
  * @see Qt#FocusReason
  * @type Number
  */
Qt.MouseFocusReason = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf Qt
  * @name TabFocusReason
  * @see Qt#FocusReason
  * @type Number
  */
Qt.TabFocusReason = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf Qt
  * @name BacktabFocusReason
  * @see Qt#FocusReason
  * @type Number
  */
Qt.BacktabFocusReason = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf Qt
  * @name ActiveWindowFocusReason
  * @see Qt#FocusReason
  * @type Number
  */
Qt.ActiveWindowFocusReason = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf Qt
  * @name PopupFocusReason
  * @see Qt#FocusReason
  * @type Number
  */
Qt.PopupFocusReason = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf Qt
  * @name ShortcutFocusReason
  * @see Qt#FocusReason
  * @type Number
  */
Qt.ShortcutFocusReason = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf Qt
  * @name MenuBarFocusReason
  * @see Qt#FocusReason
  * @type Number
  */
Qt.MenuBarFocusReason = 0x6;

/**
  * @default 0x7
  * @constant
  * @memberOf Qt
  * @name OtherFocusReason
  * @see Qt#FocusReason
  * @type Number
  */
Qt.OtherFocusReason = 0x7;

/**
  * @default 0x8
  * @constant
  * @memberOf Qt
  * @name NoFocusReason
  * @see Qt#FocusReason
  * @type Number
  */
Qt.NoFocusReason = 0x8;

/**
  * @constructor 
  * @memberOf Qt
  * @name FocusReason
  */
Qt.FocusReason = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf Qt
  * @name StretchTile
  * @see Qt#TileRule
  * @type Number
  */
Qt.StretchTile = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf Qt
  * @name RepeatTile
  * @see Qt#TileRule
  * @type Number
  */
Qt.RepeatTile = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf Qt
  * @name RoundTile
  * @see Qt#TileRule
  * @type Number
  */
Qt.RoundTile = 0x2;

/**
  * @constructor 
  * @memberOf Qt
  * @name TileRule
  */
Qt.TileRule = function(value){;};



/**
  * @default -1
  * @constant
  * @memberOf Qt
  * @name WhiteSpaceModeUndefined
  * @see Qt#WhiteSpaceMode
  * @type Number
  */
Qt.WhiteSpaceModeUndefined = 0xffffffff;

/**
  * @default 0x0
  * @constant
  * @memberOf Qt
  * @name WhiteSpaceNormal
  * @see Qt#WhiteSpaceMode
  * @type Number
  */
Qt.WhiteSpaceNormal = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf Qt
  * @name WhiteSpacePre
  * @see Qt#WhiteSpaceMode
  * @type Number
  */
Qt.WhiteSpacePre = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf Qt
  * @name WhiteSpaceNoWrap
  * @see Qt#WhiteSpaceMode
  * @type Number
  */
Qt.WhiteSpaceNoWrap = 0x2;

/**
  * @constructor 
  * @memberOf Qt
  * @name WhiteSpaceMode
  */
Qt.WhiteSpaceMode = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf Qt
  * @name IgnoreAspectRatio
  * @see Qt#AspectRatioMode
  * @type Number
  */
Qt.IgnoreAspectRatio = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf Qt
  * @name KeepAspectRatio
  * @see Qt#AspectRatioMode
  * @type Number
  */
Qt.KeepAspectRatio = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf Qt
  * @name KeepAspectRatioByExpanding
  * @see Qt#AspectRatioMode
  * @type Number
  */
Qt.KeepAspectRatioByExpanding = 0x2;

/**
  * @constructor 
  * @memberOf Qt
  * @name AspectRatioMode
  */
Qt.AspectRatioMode = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf Qt
  * @name MinimumSize
  * @see Qt#SizeHint
  * @type Number
  */
Qt.MinimumSize = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf Qt
  * @name PreferredSize
  * @see Qt#SizeHint
  * @type Number
  */
Qt.PreferredSize = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf Qt
  * @name MaximumSize
  * @see Qt#SizeHint
  * @type Number
  */
Qt.MaximumSize = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf Qt
  * @name MinimumDescent
  * @see Qt#SizeHint
  * @type Number
  */
Qt.MinimumDescent = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf Qt
  * @name NSizeHints
  * @see Qt#SizeHint
  * @type Number
  */
Qt.NSizeHints = 0x4;

/**
  * @constructor 
  * @memberOf Qt
  * @name SizeHint
  */
Qt.SizeHint = function(value){;};



/**
  * @default 0x0001
  * @constant
  * @memberOf Qt
  * @name AlignLeft
  * @see Qt#Alignment
  * @see Qt#AlignmentFlag
  * @type Number
  */
Qt.AlignLeft = 0x1;

/**
  * @default 0x0002
  * @constant
  * @memberOf Qt
  * @name AlignRight
  * @see Qt#Alignment
  * @see Qt#AlignmentFlag
  * @type Number
  */
Qt.AlignRight = 0x2;

/**
  * @default 0x0004
  * @constant
  * @memberOf Qt
  * @name AlignHCenter
  * @see Qt#Alignment
  * @see Qt#AlignmentFlag
  * @type Number
  */
Qt.AlignHCenter = 0x4;

/**
  * @default 0x0008
  * @constant
  * @memberOf Qt
  * @name AlignJustify
  * @see Qt#Alignment
  * @see Qt#AlignmentFlag
  * @type Number
  */
Qt.AlignJustify = 0x8;

/**
  * @default 0x0010
  * @constant
  * @memberOf Qt
  * @name AlignAbsolute
  * @see Qt#Alignment
  * @see Qt#AlignmentFlag
  * @type Number
  */
Qt.AlignAbsolute = 0x10;

/**
  * @default AlignLeft|AlignRight|AlignHCenter|AlignJustify|AlignAbsolute
  * @constant
  * @memberOf Qt
  * @name AlignHorizontal_Mask
  * @see Qt#Alignment
  * @see Qt#AlignmentFlag
  * @type Number
  */
Qt.AlignHorizontal_Mask = 0x1f;

/**
  * @default 0x0020
  * @constant
  * @memberOf Qt
  * @name AlignTop
  * @see Qt#Alignment
  * @see Qt#AlignmentFlag
  * @type Number
  */
Qt.AlignTop = 0x20;

/**
  * @default 0x0040
  * @constant
  * @memberOf Qt
  * @name AlignBottom
  * @see Qt#Alignment
  * @see Qt#AlignmentFlag
  * @type Number
  */
Qt.AlignBottom = 0x40;

/**
  * @default 0x0080
  * @constant
  * @memberOf Qt
  * @name AlignVCenter
  * @see Qt#Alignment
  * @see Qt#AlignmentFlag
  * @type Number
  */
Qt.AlignVCenter = 0x80;

/**
  * @default AlignVCenter|AlignHCenter
  * @constant
  * @memberOf Qt
  * @name AlignCenter
  * @see Qt#Alignment
  * @see Qt#AlignmentFlag
  * @type Number
  */
Qt.AlignCenter = 0x84;

/**
  * @default AlignTop|AlignBottom|AlignVCenter
  * @constant
  * @memberOf Qt
  * @name AlignVertical_Mask
  * @see Qt#Alignment
  * @see Qt#AlignmentFlag
  * @type Number
  */
Qt.AlignVertical_Mask = 0xe0;

/**
  * @constructor 
  * @memberOf Qt
  * @name AlignmentFlag
  */
Qt.AlignmentFlag = function(value){;};

/**
  * @constructor 
  * @memberOf Qt
  * @name Alignment
  */
Qt.Alignment = function(value1, value2 /*, ...*/){;};


/**
  * @default 0x0
  * @constant
  * @memberOf Qt
  * @name NoContextMenu
  * @see Qt#ContextMenuPolicy
  * @type Number
  */
Qt.NoContextMenu = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf Qt
  * @name DefaultContextMenu
  * @see Qt#ContextMenuPolicy
  * @type Number
  */
Qt.DefaultContextMenu = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf Qt
  * @name ActionsContextMenu
  * @see Qt#ContextMenuPolicy
  * @type Number
  */
Qt.ActionsContextMenu = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf Qt
  * @name CustomContextMenu
  * @see Qt#ContextMenuPolicy
  * @type Number
  */
Qt.CustomContextMenu = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf Qt
  * @name PreventContextMenu
  * @see Qt#ContextMenuPolicy
  * @type Number
  */
Qt.PreventContextMenu = 0x4;

/**
  * @constructor 
  * @memberOf Qt
  * @name ContextMenuPolicy
  */
Qt.ContextMenuPolicy = function(value){;};



/**
  * @default 0
  * @constant
  * @memberOf Qt
  * @name NoDockWidgetArea
  * @see Qt#DockWidgetAreas
  * @see Qt#DockWidgetArea
  * @type Number
  */
Qt.NoDockWidgetArea = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf Qt
  * @name LeftDockWidgetArea
  * @see Qt#DockWidgetAreas
  * @see Qt#DockWidgetArea
  * @type Number
  */
Qt.LeftDockWidgetArea = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf Qt
  * @name RightDockWidgetArea
  * @see Qt#DockWidgetAreas
  * @see Qt#DockWidgetArea
  * @type Number
  */
Qt.RightDockWidgetArea = 0x2;

/**
  * @default 0x4
  * @constant
  * @memberOf Qt
  * @name TopDockWidgetArea
  * @see Qt#DockWidgetAreas
  * @see Qt#DockWidgetArea
  * @type Number
  */
Qt.TopDockWidgetArea = 0x4;

/**
  * @default 0x8
  * @constant
  * @memberOf Qt
  * @name BottomDockWidgetArea
  * @see Qt#DockWidgetAreas
  * @see Qt#DockWidgetArea
  * @type Number
  */
Qt.BottomDockWidgetArea = 0x8;

/**
  * @default 0xf
  * @constant
  * @memberOf Qt
  * @name DockWidgetArea_Mask
  * @see Qt#DockWidgetAreas
  * @see Qt#DockWidgetArea
  * @type Number
  */
Qt.DockWidgetArea_Mask = 0xf;

/**
  * @constructor 
  * @memberOf Qt
  * @name DockWidgetArea
  */
Qt.DockWidgetArea = function(value){;};

/**
  * @constructor 
  * @memberOf Qt
  * @name DockWidgetAreas
  */
Qt.DockWidgetAreas = function(value1, value2 /*, ...*/){;};


/**
  * @default 0x0
  * @constant
  * @memberOf Qt
  * @name UI_General
  * @see Qt#UIEffect
  * @type Number
  */
Qt.UI_General = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf Qt
  * @name UI_AnimateMenu
  * @see Qt#UIEffect
  * @type Number
  */
Qt.UI_AnimateMenu = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf Qt
  * @name UI_FadeMenu
  * @see Qt#UIEffect
  * @type Number
  */
Qt.UI_FadeMenu = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf Qt
  * @name UI_AnimateCombo
  * @see Qt#UIEffect
  * @type Number
  */
Qt.UI_AnimateCombo = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf Qt
  * @name UI_AnimateTooltip
  * @see Qt#UIEffect
  * @type Number
  */
Qt.UI_AnimateTooltip = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf Qt
  * @name UI_FadeTooltip
  * @see Qt#UIEffect
  * @type Number
  */
Qt.UI_FadeTooltip = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf Qt
  * @name UI_AnimateToolBox
  * @see Qt#UIEffect
  * @type Number
  */
Qt.UI_AnimateToolBox = 0x6;

/**
  * @constructor 
  * @memberOf Qt
  * @name UIEffect
  */
Qt.UIEffect = function(value){;};



/**
  * @default 0
  * @constant
  * @memberOf Qt
  * @name AnchorLeft
  * @see Qt#AnchorPoint
  * @type Number
  */
Qt.AnchorLeft = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf Qt
  * @name AnchorHorizontalCenter
  * @see Qt#AnchorPoint
  * @type Number
  */
Qt.AnchorHorizontalCenter = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf Qt
  * @name AnchorRight
  * @see Qt#AnchorPoint
  * @type Number
  */
Qt.AnchorRight = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf Qt
  * @name AnchorTop
  * @see Qt#AnchorPoint
  * @type Number
  */
Qt.AnchorTop = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf Qt
  * @name AnchorVerticalCenter
  * @see Qt#AnchorPoint
  * @type Number
  */
Qt.AnchorVerticalCenter = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf Qt
  * @name AnchorBottom
  * @see Qt#AnchorPoint
  * @type Number
  */
Qt.AnchorBottom = 0x5;

/**
  * @constructor 
  * @memberOf Qt
  * @name AnchorPoint
  */
Qt.AnchorPoint = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf Qt
  * @name color0
  * @see Qt#GlobalColor
  * @type Number
  */
Qt.color0 = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf Qt
  * @name color1
  * @see Qt#GlobalColor
  * @type Number
  */
Qt.color1 = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf Qt
  * @name black
  * @see Qt#GlobalColor
  * @type Number
  */
Qt.black = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf Qt
  * @name white
  * @see Qt#GlobalColor
  * @type Number
  */
Qt.white = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf Qt
  * @name darkGray
  * @see Qt#GlobalColor
  * @type Number
  */
Qt.darkGray = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf Qt
  * @name gray
  * @see Qt#GlobalColor
  * @type Number
  */
Qt.gray = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf Qt
  * @name lightGray
  * @see Qt#GlobalColor
  * @type Number
  */
Qt.lightGray = 0x6;

/**
  * @default 0x7
  * @constant
  * @memberOf Qt
  * @name red
  * @see Qt#GlobalColor
  * @type Number
  */
Qt.red = 0x7;

/**
  * @default 0x8
  * @constant
  * @memberOf Qt
  * @name green
  * @see Qt#GlobalColor
  * @type Number
  */
Qt.green = 0x8;

/**
  * @default 0x9
  * @constant
  * @memberOf Qt
  * @name blue
  * @see Qt#GlobalColor
  * @type Number
  */
Qt.blue = 0x9;

/**
  * @default 0xa
  * @constant
  * @memberOf Qt
  * @name cyan
  * @see Qt#GlobalColor
  * @type Number
  */
Qt.cyan = 0xa;

/**
  * @default 0xb
  * @constant
  * @memberOf Qt
  * @name magenta
  * @see Qt#GlobalColor
  * @type Number
  */
Qt.magenta = 0xb;

/**
  * @default 0xc
  * @constant
  * @memberOf Qt
  * @name yellow
  * @see Qt#GlobalColor
  * @type Number
  */
Qt.yellow = 0xc;

/**
  * @default 0xd
  * @constant
  * @memberOf Qt
  * @name darkRed
  * @see Qt#GlobalColor
  * @type Number
  */
Qt.darkRed = 0xd;

/**
  * @default 0xe
  * @constant
  * @memberOf Qt
  * @name darkGreen
  * @see Qt#GlobalColor
  * @type Number
  */
Qt.darkGreen = 0xe;

/**
  * @default 0xf
  * @constant
  * @memberOf Qt
  * @name darkBlue
  * @see Qt#GlobalColor
  * @type Number
  */
Qt.darkBlue = 0xf;

/**
  * @default 0x10
  * @constant
  * @memberOf Qt
  * @name darkCyan
  * @see Qt#GlobalColor
  * @type Number
  */
Qt.darkCyan = 0x10;

/**
  * @default 0x11
  * @constant
  * @memberOf Qt
  * @name darkMagenta
  * @see Qt#GlobalColor
  * @type Number
  */
Qt.darkMagenta = 0x11;

/**
  * @default 0x12
  * @constant
  * @memberOf Qt
  * @name darkYellow
  * @see Qt#GlobalColor
  * @type Number
  */
Qt.darkYellow = 0x12;

/**
  * @default 0x13
  * @constant
  * @memberOf Qt
  * @name transparent
  * @see Qt#GlobalColor
  * @type Number
  */
Qt.transparent = 0x13;

/**
  * @constructor 
  * @memberOf Qt
  * @name GlobalColor
  */
Qt.GlobalColor = function(value){;};



/**
  * @default 0xfe000000
  * @constant
  * @memberOf Qt
  * @name KeyboardModifierMask
  * @see Qt#KeyboardModifiers
  * @see Qt#KeyboardModifier
  * @type Number
  */
Qt.KeyboardModifierMask = 0xfe000000;

/**
  * @default 0x00000000
  * @constant
  * @memberOf Qt
  * @name NoModifier
  * @see Qt#KeyboardModifiers
  * @see Qt#KeyboardModifier
  * @type Number
  */
Qt.NoModifier = 0x0;

/**
  * @default 0x02000000
  * @constant
  * @memberOf Qt
  * @name ShiftModifier
  * @see Qt#KeyboardModifiers
  * @see Qt#KeyboardModifier
  * @type Number
  */
Qt.ShiftModifier = 0x2000000;

/**
  * @default 0x04000000
  * @constant
  * @memberOf Qt
  * @name ControlModifier
  * @see Qt#KeyboardModifiers
  * @see Qt#KeyboardModifier
  * @type Number
  */
Qt.ControlModifier = 0x4000000;

/**
  * @default 0x08000000
  * @constant
  * @memberOf Qt
  * @name AltModifier
  * @see Qt#KeyboardModifiers
  * @see Qt#KeyboardModifier
  * @type Number
  */
Qt.AltModifier = 0x8000000;

/**
  * @default 0x10000000
  * @constant
  * @memberOf Qt
  * @name MetaModifier
  * @see Qt#KeyboardModifiers
  * @see Qt#KeyboardModifier
  * @type Number
  */
Qt.MetaModifier = 0x10000000;

/**
  * @default 0x20000000
  * @constant
  * @memberOf Qt
  * @name KeypadModifier
  * @see Qt#KeyboardModifiers
  * @see Qt#KeyboardModifier
  * @type Number
  */
Qt.KeypadModifier = 0x20000000;

/**
  * @default 0x40000000
  * @constant
  * @memberOf Qt
  * @name GroupSwitchModifier
  * @see Qt#KeyboardModifiers
  * @see Qt#KeyboardModifier
  * @type Number
  */
Qt.GroupSwitchModifier = 0x40000000;

/**
  * @constructor 
  * @memberOf Qt
  * @name KeyboardModifier
  */
Qt.KeyboardModifier = function(value){;};

/**
  * @constructor 
  * @memberOf Qt
  * @name KeyboardModifiers
  */
Qt.KeyboardModifiers = function(value1, value2 /*, ...*/){;};


/**
  * @default 0x0
  * @constant
  * @memberOf Qt
  * @name NavigationModeNone
  * @see Qt#NavigationMode
  * @type Number
  */
Qt.NavigationModeNone = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf Qt
  * @name NavigationModeKeypadTabOrder
  * @see Qt#NavigationMode
  * @type Number
  */
Qt.NavigationModeKeypadTabOrder = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf Qt
  * @name NavigationModeKeypadDirectional
  * @see Qt#NavigationMode
  * @type Number
  */
Qt.NavigationModeKeypadDirectional = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf Qt
  * @name NavigationModeCursorAuto
  * @see Qt#NavigationMode
  * @type Number
  */
Qt.NavigationModeCursorAuto = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf Qt
  * @name NavigationModeCursorForceVisible
  * @see Qt#NavigationMode
  * @type Number
  */
Qt.NavigationModeCursorForceVisible = 0x4;

/**
  * @constructor 
  * @memberOf Qt
  * @name NavigationMode
  */
Qt.NavigationMode = function(value){;};



/**
  * @default 0
  * @constant
  * @memberOf Qt
  * @name DisplayRole
  * @see Qt#ItemDataRole
  * @type Number
  */
Qt.DisplayRole = 0x0;

/**
  * @default 1
  * @constant
  * @memberOf Qt
  * @name DecorationRole
  * @see Qt#ItemDataRole
  * @type Number
  */
Qt.DecorationRole = 0x1;

/**
  * @default 2
  * @constant
  * @memberOf Qt
  * @name EditRole
  * @see Qt#ItemDataRole
  * @type Number
  */
Qt.EditRole = 0x2;

/**
  * @default 3
  * @constant
  * @memberOf Qt
  * @name ToolTipRole
  * @see Qt#ItemDataRole
  * @type Number
  */
Qt.ToolTipRole = 0x3;

/**
  * @default 4
  * @constant
  * @memberOf Qt
  * @name StatusTipRole
  * @see Qt#ItemDataRole
  * @type Number
  */
Qt.StatusTipRole = 0x4;

/**
  * @default 5
  * @constant
  * @memberOf Qt
  * @name WhatsThisRole
  * @see Qt#ItemDataRole
  * @type Number
  */
Qt.WhatsThisRole = 0x5;

/**
  * @default 6
  * @constant
  * @memberOf Qt
  * @name FontRole
  * @see Qt#ItemDataRole
  * @type Number
  */
Qt.FontRole = 0x6;

/**
  * @default 7
  * @constant
  * @memberOf Qt
  * @name TextAlignmentRole
  * @see Qt#ItemDataRole
  * @type Number
  */
Qt.TextAlignmentRole = 0x7;

/**
  * @default 8
  * @constant
  * @memberOf Qt
  * @name BackgroundColorRole
  * @see Qt#ItemDataRole
  * @type Number
  */
Qt.BackgroundColorRole = 0x8;

/**
  * @default 9
  * @constant
  * @memberOf Qt
  * @name TextColorRole
  * @see Qt#ItemDataRole
  * @type Number
  */
Qt.TextColorRole = 0x9;

/**
  * @default 10
  * @constant
  * @memberOf Qt
  * @name CheckStateRole
  * @see Qt#ItemDataRole
  * @type Number
  */
Qt.CheckStateRole = 0xa;

/**
  * @default 11
  * @constant
  * @memberOf Qt
  * @name AccessibleTextRole
  * @see Qt#ItemDataRole
  * @type Number
  */
Qt.AccessibleTextRole = 0xb;

/**
  * @default 12
  * @constant
  * @memberOf Qt
  * @name AccessibleDescriptionRole
  * @see Qt#ItemDataRole
  * @type Number
  */
Qt.AccessibleDescriptionRole = 0xc;

/**
  * @default 13
  * @constant
  * @memberOf Qt
  * @name SizeHintRole
  * @see Qt#ItemDataRole
  * @type Number
  */
Qt.SizeHintRole = 0xd;

/**
  * @default 14
  * @constant
  * @memberOf Qt
  * @name InitialSortOrderRole
  * @see Qt#ItemDataRole
  * @type Number
  */
Qt.InitialSortOrderRole = 0xe;

/**
  * @default 27
  * @constant
  * @memberOf Qt
  * @name DisplayPropertyRole
  * @see Qt#ItemDataRole
  * @type Number
  */
Qt.DisplayPropertyRole = 0x1b;

/**
  * @default 28
  * @constant
  * @memberOf Qt
  * @name DecorationPropertyRole
  * @see Qt#ItemDataRole
  * @type Number
  */
Qt.DecorationPropertyRole = 0x1c;

/**
  * @default 29
  * @constant
  * @memberOf Qt
  * @name ToolTipPropertyRole
  * @see Qt#ItemDataRole
  * @type Number
  */
Qt.ToolTipPropertyRole = 0x1d;

/**
  * @default 30
  * @constant
  * @memberOf Qt
  * @name StatusTipPropertyRole
  * @see Qt#ItemDataRole
  * @type Number
  */
Qt.StatusTipPropertyRole = 0x1e;

/**
  * @default 31
  * @constant
  * @memberOf Qt
  * @name WhatsThisPropertyRole
  * @see Qt#ItemDataRole
  * @type Number
  */
Qt.WhatsThisPropertyRole = 0x1f;

/**
  * @default 32
  * @constant
  * @memberOf Qt
  * @name UserRole
  * @see Qt#ItemDataRole
  * @type Number
  */
Qt.UserRole = 0x20;

/**
  * @constructor 
  * @memberOf Qt
  * @name ItemDataRole
  */
Qt.ItemDataRole = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf Qt
  * @name ScrollBarAsNeeded
  * @see Qt#ScrollBarPolicy
  * @type Number
  */
Qt.ScrollBarAsNeeded = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf Qt
  * @name ScrollBarAlwaysOff
  * @see Qt#ScrollBarPolicy
  * @type Number
  */
Qt.ScrollBarAlwaysOff = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf Qt
  * @name ScrollBarAlwaysOn
  * @see Qt#ScrollBarPolicy
  * @type Number
  */
Qt.ScrollBarAlwaysOn = 0x2;

/**
  * @constructor 
  * @memberOf Qt
  * @name ScrollBarPolicy
  */
Qt.ScrollBarPolicy = function(value){;};



/**
  * @default 0xffff0000
  * @constant
  * @memberOf Qt
  * @name ImhExclusiveInputMask
  * @see Qt#InputMethodHints
  * @see Qt#InputMethodHint
  * @type Number
  */
Qt.ImhExclusiveInputMask = 0xffff0000;

/**
  * @default 0x0
  * @constant
  * @memberOf Qt
  * @name ImhNone
  * @see Qt#InputMethodHints
  * @see Qt#InputMethodHint
  * @type Number
  */
Qt.ImhNone = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf Qt
  * @name ImhHiddenText
  * @see Qt#InputMethodHints
  * @see Qt#InputMethodHint
  * @type Number
  */
Qt.ImhHiddenText = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf Qt
  * @name ImhNoAutoUppercase
  * @see Qt#InputMethodHints
  * @see Qt#InputMethodHint
  * @type Number
  */
Qt.ImhNoAutoUppercase = 0x2;

/**
  * @default 0x4
  * @constant
  * @memberOf Qt
  * @name ImhPreferNumbers
  * @see Qt#InputMethodHints
  * @see Qt#InputMethodHint
  * @type Number
  */
Qt.ImhPreferNumbers = 0x4;

/**
  * @default 0x8
  * @constant
  * @memberOf Qt
  * @name ImhPreferUppercase
  * @see Qt#InputMethodHints
  * @see Qt#InputMethodHint
  * @type Number
  */
Qt.ImhPreferUppercase = 0x8;

/**
  * @default 0x10
  * @constant
  * @memberOf Qt
  * @name ImhPreferLowercase
  * @see Qt#InputMethodHints
  * @see Qt#InputMethodHint
  * @type Number
  */
Qt.ImhPreferLowercase = 0x10;

/**
  * @default 0x20
  * @constant
  * @memberOf Qt
  * @name ImhNoPredictiveText
  * @see Qt#InputMethodHints
  * @see Qt#InputMethodHint
  * @type Number
  */
Qt.ImhNoPredictiveText = 0x20;

/**
  * @default 0x10000
  * @constant
  * @memberOf Qt
  * @name ImhDigitsOnly
  * @see Qt#InputMethodHints
  * @see Qt#InputMethodHint
  * @type Number
  */
Qt.ImhDigitsOnly = 0x10000;

/**
  * @default 0x20000
  * @constant
  * @memberOf Qt
  * @name ImhFormattedNumbersOnly
  * @see Qt#InputMethodHints
  * @see Qt#InputMethodHint
  * @type Number
  */
Qt.ImhFormattedNumbersOnly = 0x20000;

/**
  * @default 0x40000
  * @constant
  * @memberOf Qt
  * @name ImhUppercaseOnly
  * @see Qt#InputMethodHints
  * @see Qt#InputMethodHint
  * @type Number
  */
Qt.ImhUppercaseOnly = 0x40000;

/**
  * @default 0x80000
  * @constant
  * @memberOf Qt
  * @name ImhLowercaseOnly
  * @see Qt#InputMethodHints
  * @see Qt#InputMethodHint
  * @type Number
  */
Qt.ImhLowercaseOnly = 0x80000;

/**
  * @default 0x100000
  * @constant
  * @memberOf Qt
  * @name ImhDialableCharactersOnly
  * @see Qt#InputMethodHints
  * @see Qt#InputMethodHint
  * @type Number
  */
Qt.ImhDialableCharactersOnly = 0x100000;

/**
  * @default 0x200000
  * @constant
  * @memberOf Qt
  * @name ImhEmailCharactersOnly
  * @see Qt#InputMethodHints
  * @see Qt#InputMethodHint
  * @type Number
  */
Qt.ImhEmailCharactersOnly = 0x200000;

/**
  * @default 0x400000
  * @constant
  * @memberOf Qt
  * @name ImhUrlCharactersOnly
  * @see Qt#InputMethodHints
  * @see Qt#InputMethodHint
  * @type Number
  */
Qt.ImhUrlCharactersOnly = 0x400000;

/**
  * @constructor 
  * @memberOf Qt
  * @name InputMethodHint
  */
Qt.InputMethodHint = function(value){;};

/**
  * @constructor 
  * @memberOf Qt
  * @name InputMethodHints
  */
Qt.InputMethodHints = function(value1, value2 /*, ...*/){;};


/**
  * @default 0x0
  * @constant
  * @memberOf Qt
  * @name AnchorName
  * @see Qt#AnchorAttribute
  * @type Number
  */
Qt.AnchorName = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf Qt
  * @name AnchorHref
  * @see Qt#AnchorAttribute
  * @type Number
  */
Qt.AnchorHref = 0x1;

/**
  * @constructor 
  * @memberOf Qt
  * @name AnchorAttribute
  */
Qt.AnchorAttribute = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf Qt
  * @name NonModal
  * @see Qt#WindowModality
  * @type Number
  */
Qt.NonModal = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf Qt
  * @name WindowModal
  * @see Qt#WindowModality
  * @type Number
  */
Qt.WindowModal = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf Qt
  * @name ApplicationModal
  * @see Qt#WindowModality
  * @type Number
  */
Qt.ApplicationModal = 0x2;

/**
  * @constructor 
  * @memberOf Qt
  * @name WindowModality
  */
Qt.WindowModality = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf Qt
  * @name AscendingOrder
  * @see Qt#SortOrder
  * @type Number
  */
Qt.AscendingOrder = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf Qt
  * @name DescendingOrder
  * @see Qt#SortOrder
  * @type Number
  */
Qt.DescendingOrder = 0x1;

/**
  * @constructor 
  * @memberOf Qt
  * @name SortOrder
  */
Qt.SortOrder = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf Qt
  * @name NoPen
  * @see Qt#PenStyle
  * @type Number
  */
Qt.NoPen = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf Qt
  * @name SolidLine
  * @see Qt#PenStyle
  * @type Number
  */
Qt.SolidLine = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf Qt
  * @name DashLine
  * @see Qt#PenStyle
  * @type Number
  */
Qt.DashLine = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf Qt
  * @name DotLine
  * @see Qt#PenStyle
  * @type Number
  */
Qt.DotLine = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf Qt
  * @name DashDotLine
  * @see Qt#PenStyle
  * @type Number
  */
Qt.DashDotLine = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf Qt
  * @name DashDotDotLine
  * @see Qt#PenStyle
  * @type Number
  */
Qt.DashDotDotLine = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf Qt
  * @name CustomDashLine
  * @see Qt#PenStyle
  * @type Number
  */
Qt.CustomDashLine = 0x6;

/**
  * @default 0x0f
  * @constant
  * @memberOf Qt
  * @name MPenStyle
  * @see Qt#PenStyle
  * @type Number
  */
Qt.MPenStyle = 0xf;

/**
  * @constructor 
  * @memberOf Qt
  * @name PenStyle
  */
Qt.PenStyle = function(value){;};



/**
  * @default 0
  * @constant
  * @memberOf Qt
  * @name NoItemFlags
  * @see Qt#ItemFlags
  * @see Qt#ItemFlag
  * @type Number
  */
Qt.NoItemFlags = 0x0;

/**
  * @default 1
  * @constant
  * @memberOf Qt
  * @name ItemIsSelectable
  * @see Qt#ItemFlags
  * @see Qt#ItemFlag
  * @type Number
  */
Qt.ItemIsSelectable = 0x1;

/**
  * @default 2
  * @constant
  * @memberOf Qt
  * @name ItemIsEditable
  * @see Qt#ItemFlags
  * @see Qt#ItemFlag
  * @type Number
  */
Qt.ItemIsEditable = 0x2;

/**
  * @default 4
  * @constant
  * @memberOf Qt
  * @name ItemIsDragEnabled
  * @see Qt#ItemFlags
  * @see Qt#ItemFlag
  * @type Number
  */
Qt.ItemIsDragEnabled = 0x4;

/**
  * @default 8
  * @constant
  * @memberOf Qt
  * @name ItemIsDropEnabled
  * @see Qt#ItemFlags
  * @see Qt#ItemFlag
  * @type Number
  */
Qt.ItemIsDropEnabled = 0x8;

/**
  * @default 16
  * @constant
  * @memberOf Qt
  * @name ItemIsUserCheckable
  * @see Qt#ItemFlags
  * @see Qt#ItemFlag
  * @type Number
  */
Qt.ItemIsUserCheckable = 0x10;

/**
  * @default 32
  * @constant
  * @memberOf Qt
  * @name ItemIsEnabled
  * @see Qt#ItemFlags
  * @see Qt#ItemFlag
  * @type Number
  */
Qt.ItemIsEnabled = 0x20;

/**
  * @default 64
  * @constant
  * @memberOf Qt
  * @name ItemIsTristate
  * @see Qt#ItemFlags
  * @see Qt#ItemFlag
  * @type Number
  */
Qt.ItemIsTristate = 0x40;

/**
  * @constructor 
  * @memberOf Qt
  * @name ItemFlag
  */
Qt.ItemFlag = function(value){;};

/**
  * @constructor 
  * @memberOf Qt
  * @name ItemFlags
  */
Qt.ItemFlags = function(value1, value2 /*, ...*/){;};


/**
  * @default 0x0
  * @constant
  * @memberOf Qt
  * @name XAxis
  * @see Qt#Axis
  * @type Number
  */
Qt.XAxis = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf Qt
  * @name YAxis
  * @see Qt#Axis
  * @type Number
  */
Qt.YAxis = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf Qt
  * @name ZAxis
  * @see Qt#Axis
  * @type Number
  */
Qt.ZAxis = 0x2;

/**
  * @constructor 
  * @memberOf Qt
  * @name Axis
  */
Qt.Axis = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf Qt
  * @name FastTransformation
  * @see Qt#TransformationMode
  * @type Number
  */
Qt.FastTransformation = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf Qt
  * @name SmoothTransformation
  * @see Qt#TransformationMode
  * @type Number
  */
Qt.SmoothTransformation = 0x1;

/**
  * @constructor 
  * @memberOf Qt
  * @name TransformationMode
  */
Qt.TransformationMode = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf Qt
  * @name NoSection
  * @see Qt#WindowFrameSection
  * @type Number
  */
Qt.NoSection = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf Qt
  * @name LeftSection
  * @see Qt#WindowFrameSection
  * @type Number
  */
Qt.LeftSection = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf Qt
  * @name TopLeftSection
  * @see Qt#WindowFrameSection
  * @type Number
  */
Qt.TopLeftSection = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf Qt
  * @name TopSection
  * @see Qt#WindowFrameSection
  * @type Number
  */
Qt.TopSection = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf Qt
  * @name TopRightSection
  * @see Qt#WindowFrameSection
  * @type Number
  */
Qt.TopRightSection = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf Qt
  * @name RightSection
  * @see Qt#WindowFrameSection
  * @type Number
  */
Qt.RightSection = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf Qt
  * @name BottomRightSection
  * @see Qt#WindowFrameSection
  * @type Number
  */
Qt.BottomRightSection = 0x6;

/**
  * @default 0x7
  * @constant
  * @memberOf Qt
  * @name BottomSection
  * @see Qt#WindowFrameSection
  * @type Number
  */
Qt.BottomSection = 0x7;

/**
  * @default 0x8
  * @constant
  * @memberOf Qt
  * @name BottomLeftSection
  * @see Qt#WindowFrameSection
  * @type Number
  */
Qt.BottomLeftSection = 0x8;

/**
  * @default 0x9
  * @constant
  * @memberOf Qt
  * @name TitleBarArea
  * @see Qt#WindowFrameSection
  * @type Number
  */
Qt.TitleBarArea = 0x9;

/**
  * @constructor 
  * @memberOf Qt
  * @name WindowFrameSection
  */
Qt.WindowFrameSection = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf Qt
  * @name ExactHit
  * @see Qt#HitTestAccuracy
  * @type Number
  */
Qt.ExactHit = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf Qt
  * @name FuzzyHit
  * @see Qt#HitTestAccuracy
  * @type Number
  */
Qt.FuzzyHit = 0x1;

/**
  * @constructor 
  * @memberOf Qt
  * @name HitTestAccuracy
  */
Qt.HitTestAccuracy = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf Qt
  * @name ArrowCursor
  * @see Qt#CursorShape
  * @type Number
  */
Qt.ArrowCursor = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf Qt
  * @name UpArrowCursor
  * @see Qt#CursorShape
  * @type Number
  */
Qt.UpArrowCursor = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf Qt
  * @name CrossCursor
  * @see Qt#CursorShape
  * @type Number
  */
Qt.CrossCursor = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf Qt
  * @name WaitCursor
  * @see Qt#CursorShape
  * @type Number
  */
Qt.WaitCursor = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf Qt
  * @name IBeamCursor
  * @see Qt#CursorShape
  * @type Number
  */
Qt.IBeamCursor = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf Qt
  * @name SizeVerCursor
  * @see Qt#CursorShape
  * @type Number
  */
Qt.SizeVerCursor = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf Qt
  * @name SizeHorCursor
  * @see Qt#CursorShape
  * @type Number
  */
Qt.SizeHorCursor = 0x6;

/**
  * @default 0x7
  * @constant
  * @memberOf Qt
  * @name SizeBDiagCursor
  * @see Qt#CursorShape
  * @type Number
  */
Qt.SizeBDiagCursor = 0x7;

/**
  * @default 0x8
  * @constant
  * @memberOf Qt
  * @name SizeFDiagCursor
  * @see Qt#CursorShape
  * @type Number
  */
Qt.SizeFDiagCursor = 0x8;

/**
  * @default 0x9
  * @constant
  * @memberOf Qt
  * @name SizeAllCursor
  * @see Qt#CursorShape
  * @type Number
  */
Qt.SizeAllCursor = 0x9;

/**
  * @default 0xa
  * @constant
  * @memberOf Qt
  * @name BlankCursor
  * @see Qt#CursorShape
  * @type Number
  */
Qt.BlankCursor = 0xa;

/**
  * @default 0xb
  * @constant
  * @memberOf Qt
  * @name SplitVCursor
  * @see Qt#CursorShape
  * @type Number
  */
Qt.SplitVCursor = 0xb;

/**
  * @default 0xc
  * @constant
  * @memberOf Qt
  * @name SplitHCursor
  * @see Qt#CursorShape
  * @type Number
  */
Qt.SplitHCursor = 0xc;

/**
  * @default 0xd
  * @constant
  * @memberOf Qt
  * @name PointingHandCursor
  * @see Qt#CursorShape
  * @type Number
  */
Qt.PointingHandCursor = 0xd;

/**
  * @default 0xe
  * @constant
  * @memberOf Qt
  * @name ForbiddenCursor
  * @see Qt#CursorShape
  * @type Number
  */
Qt.ForbiddenCursor = 0xe;

/**
  * @default 0xf
  * @constant
  * @memberOf Qt
  * @name WhatsThisCursor
  * @see Qt#CursorShape
  * @type Number
  */
Qt.WhatsThisCursor = 0xf;

/**
  * @default 0x10
  * @constant
  * @memberOf Qt
  * @name BusyCursor
  * @see Qt#CursorShape
  * @type Number
  */
Qt.BusyCursor = 0x10;

/**
  * @default 0x11
  * @constant
  * @memberOf Qt
  * @name OpenHandCursor
  * @see Qt#CursorShape
  * @type Number
  */
Qt.OpenHandCursor = 0x11;

/**
  * @default 0x12
  * @constant
  * @memberOf Qt
  * @name ClosedHandCursor
  * @see Qt#CursorShape
  * @type Number
  */
Qt.ClosedHandCursor = 0x12;

/**
  * @default 0x13
  * @constant
  * @memberOf Qt
  * @name DragCopyCursor
  * @see Qt#CursorShape
  * @type Number
  */
Qt.DragCopyCursor = 0x13;

/**
  * @default 0x14
  * @constant
  * @memberOf Qt
  * @name DragMoveCursor
  * @see Qt#CursorShape
  * @type Number
  */
Qt.DragMoveCursor = 0x14;

/**
  * @default 0x15
  * @constant
  * @memberOf Qt
  * @name DragLinkCursor
  * @see Qt#CursorShape
  * @type Number
  */
Qt.DragLinkCursor = 0x15;

/**
  * @default 24
  * @constant
  * @memberOf Qt
  * @name BitmapCursor
  * @see Qt#CursorShape
  * @type Number
  */
Qt.BitmapCursor = 0x18;

/**
  * @default 25
  * @constant
  * @memberOf Qt
  * @name CustomCursor
  * @see Qt#CursorShape
  * @type Number
  */
Qt.CustomCursor = 0x19;

/**
  * @constructor 
  * @memberOf Qt
  * @name CursorShape
  */
Qt.CursorShape = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf Qt
  * @name ContainsItemShape
  * @see Qt#ItemSelectionMode
  * @type Number
  */
Qt.ContainsItemShape = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf Qt
  * @name IntersectsItemShape
  * @see Qt#ItemSelectionMode
  * @type Number
  */
Qt.IntersectsItemShape = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf Qt
  * @name ContainsItemBoundingRect
  * @see Qt#ItemSelectionMode
  * @type Number
  */
Qt.ContainsItemBoundingRect = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf Qt
  * @name IntersectsItemBoundingRect
  * @see Qt#ItemSelectionMode
  * @type Number
  */
Qt.IntersectsItemBoundingRect = 0x3;

/**
  * @constructor 
  * @memberOf Qt
  * @name ItemSelectionMode
  */
Qt.ItemSelectionMode = function(value){;};



/**
  * @default 0x1
  * @constant
  * @memberOf Qt
  * @name Horizontal
  * @see Qt#Orientations
  * @see Qt#Orientation
  * @type Number
  */
Qt.Horizontal = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf Qt
  * @name Vertical
  * @see Qt#Orientations
  * @see Qt#Orientation
  * @type Number
  */
Qt.Vertical = 0x2;

/**
  * @constructor 
  * @memberOf Qt
  * @name Orientation
  */
Qt.Orientation = function(value){;};

/**
  * @constructor 
  * @memberOf Qt
  * @name Orientations
  */
Qt.Orientations = function(value1, value2 /*, ...*/){;};


/**
  * @default 0x0
  * @constant
  * @memberOf Qt
  * @name ImMicroFocus
  * @see Qt#InputMethodQuery
  * @type Number
  */
Qt.ImMicroFocus = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf Qt
  * @name ImFont
  * @see Qt#InputMethodQuery
  * @type Number
  */
Qt.ImFont = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf Qt
  * @name ImCursorPosition
  * @see Qt#InputMethodQuery
  * @type Number
  */
Qt.ImCursorPosition = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf Qt
  * @name ImSurroundingText
  * @see Qt#InputMethodQuery
  * @type Number
  */
Qt.ImSurroundingText = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf Qt
  * @name ImCurrentSelection
  * @see Qt#InputMethodQuery
  * @type Number
  */
Qt.ImCurrentSelection = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf Qt
  * @name ImMaximumTextLength
  * @see Qt#InputMethodQuery
  * @type Number
  */
Qt.ImMaximumTextLength = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf Qt
  * @name ImAnchorPosition
  * @see Qt#InputMethodQuery
  * @type Number
  */
Qt.ImAnchorPosition = 0x6;

/**
  * @constructor 
  * @memberOf Qt
  * @name InputMethodQuery
  */
Qt.InputMethodQuery = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf Qt
  * @name LocalTime
  * @see Qt#TimeSpec
  * @type Number
  */
Qt.LocalTime = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf Qt
  * @name UTC
  * @see Qt#TimeSpec
  * @type Number
  */
Qt.UTC = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf Qt
  * @name OffsetFromUTC
  * @see Qt#TimeSpec
  * @type Number
  */
Qt.OffsetFromUTC = 0x2;

/**
  * @constructor 
  * @memberOf Qt
  * @name TimeSpec
  */
Qt.TimeSpec = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf Qt
  * @name NoArrow
  * @see Qt#ArrowType
  * @type Number
  */
Qt.NoArrow = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf Qt
  * @name UpArrow
  * @see Qt#ArrowType
  * @type Number
  */
Qt.UpArrow = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf Qt
  * @name DownArrow
  * @see Qt#ArrowType
  * @type Number
  */
Qt.DownArrow = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf Qt
  * @name LeftArrow
  * @see Qt#ArrowType
  * @type Number
  */
Qt.LeftArrow = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf Qt
  * @name RightArrow
  * @see Qt#ArrowType
  * @type Number
  */
Qt.RightArrow = 0x4;

/**
  * @constructor 
  * @memberOf Qt
  * @name ArrowType
  */
Qt.ArrowType = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf Qt
  * @name OddEvenFill
  * @see Qt#FillRule
  * @type Number
  */
Qt.OddEvenFill = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf Qt
  * @name WindingFill
  * @see Qt#FillRule
  * @type Number
  */
Qt.WindingFill = 0x1;

/**
  * @constructor 
  * @memberOf Qt
  * @name FillRule
  */
Qt.FillRule = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf Qt
  * @name MaskInColor
  * @see Qt#MaskMode
  * @type Number
  */
Qt.MaskInColor = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf Qt
  * @name MaskOutColor
  * @see Qt#MaskMode
  * @type Number
  */
Qt.MaskOutColor = 0x1;

/**
  * @constructor 
  * @memberOf Qt
  * @name MaskMode
  */
Qt.MaskMode = function(value){;};



/**
  * @default 0x00000000
  * @constant
  * @memberOf Qt
  * @name WindowNoState
  * @see Qt#WindowStates
  * @see Qt#WindowState
  * @type Number
  */
Qt.WindowNoState = 0x0;

/**
  * @default 0x00000001
  * @constant
  * @memberOf Qt
  * @name WindowMinimized
  * @see Qt#WindowStates
  * @see Qt#WindowState
  * @type Number
  */
Qt.WindowMinimized = 0x1;

/**
  * @default 0x00000002
  * @constant
  * @memberOf Qt
  * @name WindowMaximized
  * @see Qt#WindowStates
  * @see Qt#WindowState
  * @type Number
  */
Qt.WindowMaximized = 0x2;

/**
  * @default 0x00000004
  * @constant
  * @memberOf Qt
  * @name WindowFullScreen
  * @see Qt#WindowStates
  * @see Qt#WindowState
  * @type Number
  */
Qt.WindowFullScreen = 0x4;

/**
  * @default 0x00000008
  * @constant
  * @memberOf Qt
  * @name WindowActive
  * @see Qt#WindowStates
  * @see Qt#WindowState
  * @type Number
  */
Qt.WindowActive = 0x8;

/**
  * @constructor 
  * @memberOf Qt
  * @name WindowState
  */
Qt.WindowState = function(value){;};

/**
  * @constructor 
  * @memberOf Qt
  * @name WindowStates
  */
Qt.WindowStates = function(value1, value2 /*, ...*/){;};


/**
  * @default 4
  * @constant
  * @memberOf Qt
  * @name NToolBarAreas
  * @see Qt#ToolBarAreaSizes
  * @type Number
  */
Qt.NToolBarAreas = 0x4;

/**
  * @constructor 
  * @memberOf Qt
  * @name ToolBarAreaSizes
  */
Qt.ToolBarAreaSizes = function(value){;};



/**
  * @default 0x00000
  * @constant
  * @memberOf Qt
  * @name TopLeftCorner
  * @see Qt#Corner
  * @type Number
  */
Qt.TopLeftCorner = 0x0;

/**
  * @default 0x00001
  * @constant
  * @memberOf Qt
  * @name TopRightCorner
  * @see Qt#Corner
  * @type Number
  */
Qt.TopRightCorner = 0x1;

/**
  * @default 0x00002
  * @constant
  * @memberOf Qt
  * @name BottomLeftCorner
  * @see Qt#Corner
  * @type Number
  */
Qt.BottomLeftCorner = 0x2;

/**
  * @default 0x00003
  * @constant
  * @memberOf Qt
  * @name BottomRightCorner
  * @see Qt#Corner
  * @type Number
  */
Qt.BottomRightCorner = 0x3;

/**
  * @constructor 
  * @memberOf Qt
  * @name Corner
  */
Qt.Corner = function(value){;};



/**
  * @default 1
  * @constant
  * @memberOf Qt
  * @name Monday
  * @see Qt#DayOfWeek
  * @type Number
  */
Qt.Monday = 0x1;

/**
  * @default 2
  * @constant
  * @memberOf Qt
  * @name Tuesday
  * @see Qt#DayOfWeek
  * @type Number
  */
Qt.Tuesday = 0x2;

/**
  * @default 3
  * @constant
  * @memberOf Qt
  * @name Wednesday
  * @see Qt#DayOfWeek
  * @type Number
  */
Qt.Wednesday = 0x3;

/**
  * @default 4
  * @constant
  * @memberOf Qt
  * @name Thursday
  * @see Qt#DayOfWeek
  * @type Number
  */
Qt.Thursday = 0x4;

/**
  * @default 5
  * @constant
  * @memberOf Qt
  * @name Friday
  * @see Qt#DayOfWeek
  * @type Number
  */
Qt.Friday = 0x5;

/**
  * @default 6
  * @constant
  * @memberOf Qt
  * @name Saturday
  * @see Qt#DayOfWeek
  * @type Number
  */
Qt.Saturday = 0x6;

/**
  * @default 7
  * @constant
  * @memberOf Qt
  * @name Sunday
  * @see Qt#DayOfWeek
  * @type Number
  */
Qt.Sunday = 0x7;

/**
  * @constructor 
  * @memberOf Qt
  * @name DayOfWeek
  */
Qt.DayOfWeek = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf Qt
  * @name NoClip
  * @see Qt#ClipOperation
  * @type Number
  */
Qt.NoClip = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf Qt
  * @name ReplaceClip
  * @see Qt#ClipOperation
  * @type Number
  */
Qt.ReplaceClip = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf Qt
  * @name IntersectClip
  * @see Qt#ClipOperation
  * @type Number
  */
Qt.IntersectClip = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf Qt
  * @name UniteClip
  * @see Qt#ClipOperation
  * @type Number
  */
Qt.UniteClip = 0x3;

/**
  * @constructor 
  * @memberOf Qt
  * @name ClipOperation
  */
Qt.ClipOperation = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf Qt
  * @name LeftToRight
  * @see Qt#LayoutDirection
  * @type Number
  */
Qt.LeftToRight = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf Qt
  * @name RightToLeft
  * @see Qt#LayoutDirection
  * @type Number
  */
Qt.RightToLeft = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf Qt
  * @name LayoutDirectionAuto
  * @see Qt#LayoutDirection
  * @type Number
  */
Qt.LayoutDirectionAuto = 0x2;

/**
  * @constructor 
  * @memberOf Qt
  * @name LayoutDirection
  */
Qt.LayoutDirection = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf Qt
  * @name ToolButtonIconOnly
  * @see Qt#ToolButtonStyle
  * @type Number
  */
Qt.ToolButtonIconOnly = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf Qt
  * @name ToolButtonTextOnly
  * @see Qt#ToolButtonStyle
  * @type Number
  */
Qt.ToolButtonTextOnly = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf Qt
  * @name ToolButtonTextBesideIcon
  * @see Qt#ToolButtonStyle
  * @type Number
  */
Qt.ToolButtonTextBesideIcon = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf Qt
  * @name ToolButtonTextUnderIcon
  * @see Qt#ToolButtonStyle
  * @type Number
  */
Qt.ToolButtonTextUnderIcon = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf Qt
  * @name ToolButtonFollowStyle
  * @see Qt#ToolButtonStyle
  * @type Number
  */
Qt.ToolButtonFollowStyle = 0x4;

/**
  * @constructor 
  * @memberOf Qt
  * @name ToolButtonStyle
  */
Qt.ToolButtonStyle = function(value){;};



/**
  * @default 4
  * @constant
  * @memberOf Qt
  * @name NDockWidgetAreas
  * @see Qt#DockWidgetAreaSizes
  * @type Number
  */
Qt.NDockWidgetAreas = 0x4;

/**
  * @constructor 
  * @memberOf Qt
  * @name DockWidgetAreaSizes
  */
Qt.DockWidgetAreaSizes = function(value){;};



/**
  * @default 0x20
  * @constant
  * @memberOf Qt
  * @name Key_Space
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Space = 0x20;

/**
  * @default 0x21
  * @constant
  * @memberOf Qt
  * @name Key_Exclam
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Exclam = 0x21;

/**
  * @default 0x22
  * @constant
  * @memberOf Qt
  * @name Key_QuoteDbl
  * @see Qt#Key
  * @type Number
  */
Qt.Key_QuoteDbl = 0x22;

/**
  * @default 0x23
  * @constant
  * @memberOf Qt
  * @name Key_NumberSign
  * @see Qt#Key
  * @type Number
  */
Qt.Key_NumberSign = 0x23;

/**
  * @default 0x24
  * @constant
  * @memberOf Qt
  * @name Key_Dollar
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Dollar = 0x24;

/**
  * @default 0x25
  * @constant
  * @memberOf Qt
  * @name Key_Percent
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Percent = 0x25;

/**
  * @default 0x26
  * @constant
  * @memberOf Qt
  * @name Key_Ampersand
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Ampersand = 0x26;

/**
  * @default 0x27
  * @constant
  * @memberOf Qt
  * @name Key_Apostrophe
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Apostrophe = 0x27;

/**
  * @default 0x28
  * @constant
  * @memberOf Qt
  * @name Key_ParenLeft
  * @see Qt#Key
  * @type Number
  */
Qt.Key_ParenLeft = 0x28;

/**
  * @default 0x29
  * @constant
  * @memberOf Qt
  * @name Key_ParenRight
  * @see Qt#Key
  * @type Number
  */
Qt.Key_ParenRight = 0x29;

/**
  * @default 0x2a
  * @constant
  * @memberOf Qt
  * @name Key_Asterisk
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Asterisk = 0x2a;

/**
  * @default 0x2b
  * @constant
  * @memberOf Qt
  * @name Key_Plus
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Plus = 0x2b;

/**
  * @default 0x2c
  * @constant
  * @memberOf Qt
  * @name Key_Comma
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Comma = 0x2c;

/**
  * @default 0x2d
  * @constant
  * @memberOf Qt
  * @name Key_Minus
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Minus = 0x2d;

/**
  * @default 0x2e
  * @constant
  * @memberOf Qt
  * @name Key_Period
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Period = 0x2e;

/**
  * @default 0x2f
  * @constant
  * @memberOf Qt
  * @name Key_Slash
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Slash = 0x2f;

/**
  * @default 0x30
  * @constant
  * @memberOf Qt
  * @name Key_0
  * @see Qt#Key
  * @type Number
  */
Qt.Key_0 = 0x30;

/**
  * @default 0x31
  * @constant
  * @memberOf Qt
  * @name Key_1
  * @see Qt#Key
  * @type Number
  */
Qt.Key_1 = 0x31;

/**
  * @default 0x32
  * @constant
  * @memberOf Qt
  * @name Key_2
  * @see Qt#Key
  * @type Number
  */
Qt.Key_2 = 0x32;

/**
  * @default 0x33
  * @constant
  * @memberOf Qt
  * @name Key_3
  * @see Qt#Key
  * @type Number
  */
Qt.Key_3 = 0x33;

/**
  * @default 0x34
  * @constant
  * @memberOf Qt
  * @name Key_4
  * @see Qt#Key
  * @type Number
  */
Qt.Key_4 = 0x34;

/**
  * @default 0x35
  * @constant
  * @memberOf Qt
  * @name Key_5
  * @see Qt#Key
  * @type Number
  */
Qt.Key_5 = 0x35;

/**
  * @default 0x36
  * @constant
  * @memberOf Qt
  * @name Key_6
  * @see Qt#Key
  * @type Number
  */
Qt.Key_6 = 0x36;

/**
  * @default 0x37
  * @constant
  * @memberOf Qt
  * @name Key_7
  * @see Qt#Key
  * @type Number
  */
Qt.Key_7 = 0x37;

/**
  * @default 0x38
  * @constant
  * @memberOf Qt
  * @name Key_8
  * @see Qt#Key
  * @type Number
  */
Qt.Key_8 = 0x38;

/**
  * @default 0x39
  * @constant
  * @memberOf Qt
  * @name Key_9
  * @see Qt#Key
  * @type Number
  */
Qt.Key_9 = 0x39;

/**
  * @default 0x3a
  * @constant
  * @memberOf Qt
  * @name Key_Colon
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Colon = 0x3a;

/**
  * @default 0x3b
  * @constant
  * @memberOf Qt
  * @name Key_Semicolon
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Semicolon = 0x3b;

/**
  * @default 0x3c
  * @constant
  * @memberOf Qt
  * @name Key_Less
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Less = 0x3c;

/**
  * @default 0x3d
  * @constant
  * @memberOf Qt
  * @name Key_Equal
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Equal = 0x3d;

/**
  * @default 0x3e
  * @constant
  * @memberOf Qt
  * @name Key_Greater
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Greater = 0x3e;

/**
  * @default 0x3f
  * @constant
  * @memberOf Qt
  * @name Key_Question
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Question = 0x3f;

/**
  * @default 0x40
  * @constant
  * @memberOf Qt
  * @name Key_At
  * @see Qt#Key
  * @type Number
  */
Qt.Key_At = 0x40;

/**
  * @default 0x41
  * @constant
  * @memberOf Qt
  * @name Key_A
  * @see Qt#Key
  * @type Number
  */
Qt.Key_A = 0x41;

/**
  * @default 0x42
  * @constant
  * @memberOf Qt
  * @name Key_B
  * @see Qt#Key
  * @type Number
  */
Qt.Key_B = 0x42;

/**
  * @default 0x43
  * @constant
  * @memberOf Qt
  * @name Key_C
  * @see Qt#Key
  * @type Number
  */
Qt.Key_C = 0x43;

/**
  * @default 0x44
  * @constant
  * @memberOf Qt
  * @name Key_D
  * @see Qt#Key
  * @type Number
  */
Qt.Key_D = 0x44;

/**
  * @default 0x45
  * @constant
  * @memberOf Qt
  * @name Key_E
  * @see Qt#Key
  * @type Number
  */
Qt.Key_E = 0x45;

/**
  * @default 0x46
  * @constant
  * @memberOf Qt
  * @name Key_F
  * @see Qt#Key
  * @type Number
  */
Qt.Key_F = 0x46;

/**
  * @default 0x47
  * @constant
  * @memberOf Qt
  * @name Key_G
  * @see Qt#Key
  * @type Number
  */
Qt.Key_G = 0x47;

/**
  * @default 0x48
  * @constant
  * @memberOf Qt
  * @name Key_H
  * @see Qt#Key
  * @type Number
  */
Qt.Key_H = 0x48;

/**
  * @default 0x49
  * @constant
  * @memberOf Qt
  * @name Key_I
  * @see Qt#Key
  * @type Number
  */
Qt.Key_I = 0x49;

/**
  * @default 0x4a
  * @constant
  * @memberOf Qt
  * @name Key_J
  * @see Qt#Key
  * @type Number
  */
Qt.Key_J = 0x4a;

/**
  * @default 0x4b
  * @constant
  * @memberOf Qt
  * @name Key_K
  * @see Qt#Key
  * @type Number
  */
Qt.Key_K = 0x4b;

/**
  * @default 0x4c
  * @constant
  * @memberOf Qt
  * @name Key_L
  * @see Qt#Key
  * @type Number
  */
Qt.Key_L = 0x4c;

/**
  * @default 0x4d
  * @constant
  * @memberOf Qt
  * @name Key_M
  * @see Qt#Key
  * @type Number
  */
Qt.Key_M = 0x4d;

/**
  * @default 0x4e
  * @constant
  * @memberOf Qt
  * @name Key_N
  * @see Qt#Key
  * @type Number
  */
Qt.Key_N = 0x4e;

/**
  * @default 0x4f
  * @constant
  * @memberOf Qt
  * @name Key_O
  * @see Qt#Key
  * @type Number
  */
Qt.Key_O = 0x4f;

/**
  * @default 0x50
  * @constant
  * @memberOf Qt
  * @name Key_P
  * @see Qt#Key
  * @type Number
  */
Qt.Key_P = 0x50;

/**
  * @default 0x51
  * @constant
  * @memberOf Qt
  * @name Key_Q
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Q = 0x51;

/**
  * @default 0x52
  * @constant
  * @memberOf Qt
  * @name Key_R
  * @see Qt#Key
  * @type Number
  */
Qt.Key_R = 0x52;

/**
  * @default 0x53
  * @constant
  * @memberOf Qt
  * @name Key_S
  * @see Qt#Key
  * @type Number
  */
Qt.Key_S = 0x53;

/**
  * @default 0x54
  * @constant
  * @memberOf Qt
  * @name Key_T
  * @see Qt#Key
  * @type Number
  */
Qt.Key_T = 0x54;

/**
  * @default 0x55
  * @constant
  * @memberOf Qt
  * @name Key_U
  * @see Qt#Key
  * @type Number
  */
Qt.Key_U = 0x55;

/**
  * @default 0x56
  * @constant
  * @memberOf Qt
  * @name Key_V
  * @see Qt#Key
  * @type Number
  */
Qt.Key_V = 0x56;

/**
  * @default 0x57
  * @constant
  * @memberOf Qt
  * @name Key_W
  * @see Qt#Key
  * @type Number
  */
Qt.Key_W = 0x57;

/**
  * @default 0x58
  * @constant
  * @memberOf Qt
  * @name Key_X
  * @see Qt#Key
  * @type Number
  */
Qt.Key_X = 0x58;

/**
  * @default 0x59
  * @constant
  * @memberOf Qt
  * @name Key_Y
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Y = 0x59;

/**
  * @default 0x5a
  * @constant
  * @memberOf Qt
  * @name Key_Z
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Z = 0x5a;

/**
  * @default 0x5b
  * @constant
  * @memberOf Qt
  * @name Key_BracketLeft
  * @see Qt#Key
  * @type Number
  */
Qt.Key_BracketLeft = 0x5b;

/**
  * @default 0x5c
  * @constant
  * @memberOf Qt
  * @name Key_Backslash
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Backslash = 0x5c;

/**
  * @default 0x5d
  * @constant
  * @memberOf Qt
  * @name Key_BracketRight
  * @see Qt#Key
  * @type Number
  */
Qt.Key_BracketRight = 0x5d;

/**
  * @default 0x5e
  * @constant
  * @memberOf Qt
  * @name Key_AsciiCircum
  * @see Qt#Key
  * @type Number
  */
Qt.Key_AsciiCircum = 0x5e;

/**
  * @default 0x5f
  * @constant
  * @memberOf Qt
  * @name Key_Underscore
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Underscore = 0x5f;

/**
  * @default 0x60
  * @constant
  * @memberOf Qt
  * @name Key_QuoteLeft
  * @see Qt#Key
  * @type Number
  */
Qt.Key_QuoteLeft = 0x60;

/**
  * @default 0x7b
  * @constant
  * @memberOf Qt
  * @name Key_BraceLeft
  * @see Qt#Key
  * @type Number
  */
Qt.Key_BraceLeft = 0x7b;

/**
  * @default 0x7c
  * @constant
  * @memberOf Qt
  * @name Key_Bar
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Bar = 0x7c;

/**
  * @default 0x7d
  * @constant
  * @memberOf Qt
  * @name Key_BraceRight
  * @see Qt#Key
  * @type Number
  */
Qt.Key_BraceRight = 0x7d;

/**
  * @default 0x7e
  * @constant
  * @memberOf Qt
  * @name Key_AsciiTilde
  * @see Qt#Key
  * @type Number
  */
Qt.Key_AsciiTilde = 0x7e;

/**
  * @default 0x0a0
  * @constant
  * @memberOf Qt
  * @name Key_nobreakspace
  * @see Qt#Key
  * @type Number
  */
Qt.Key_nobreakspace = 0xa0;

/**
  * @default 0x0a1
  * @constant
  * @memberOf Qt
  * @name Key_exclamdown
  * @see Qt#Key
  * @type Number
  */
Qt.Key_exclamdown = 0xa1;

/**
  * @default 0x0a2
  * @constant
  * @memberOf Qt
  * @name Key_cent
  * @see Qt#Key
  * @type Number
  */
Qt.Key_cent = 0xa2;

/**
  * @default 0x0a3
  * @constant
  * @memberOf Qt
  * @name Key_sterling
  * @see Qt#Key
  * @type Number
  */
Qt.Key_sterling = 0xa3;

/**
  * @default 0x0a4
  * @constant
  * @memberOf Qt
  * @name Key_currency
  * @see Qt#Key
  * @type Number
  */
Qt.Key_currency = 0xa4;

/**
  * @default 0x0a5
  * @constant
  * @memberOf Qt
  * @name Key_yen
  * @see Qt#Key
  * @type Number
  */
Qt.Key_yen = 0xa5;

/**
  * @default 0x0a6
  * @constant
  * @memberOf Qt
  * @name Key_brokenbar
  * @see Qt#Key
  * @type Number
  */
Qt.Key_brokenbar = 0xa6;

/**
  * @default 0x0a7
  * @constant
  * @memberOf Qt
  * @name Key_section
  * @see Qt#Key
  * @type Number
  */
Qt.Key_section = 0xa7;

/**
  * @default 0x0a8
  * @constant
  * @memberOf Qt
  * @name Key_diaeresis
  * @see Qt#Key
  * @type Number
  */
Qt.Key_diaeresis = 0xa8;

/**
  * @default 0x0a9
  * @constant
  * @memberOf Qt
  * @name Key_copyright
  * @see Qt#Key
  * @type Number
  */
Qt.Key_copyright = 0xa9;

/**
  * @default 0x0aa
  * @constant
  * @memberOf Qt
  * @name Key_ordfeminine
  * @see Qt#Key
  * @type Number
  */
Qt.Key_ordfeminine = 0xaa;

/**
  * @default 0x0ab
  * @constant
  * @memberOf Qt
  * @name Key_guillemotleft
  * @see Qt#Key
  * @type Number
  */
Qt.Key_guillemotleft = 0xab;

/**
  * @default 0x0ac
  * @constant
  * @memberOf Qt
  * @name Key_notsign
  * @see Qt#Key
  * @type Number
  */
Qt.Key_notsign = 0xac;

/**
  * @default 0x0ad
  * @constant
  * @memberOf Qt
  * @name Key_hyphen
  * @see Qt#Key
  * @type Number
  */
Qt.Key_hyphen = 0xad;

/**
  * @default 0x0ae
  * @constant
  * @memberOf Qt
  * @name Key_registered
  * @see Qt#Key
  * @type Number
  */
Qt.Key_registered = 0xae;

/**
  * @default 0x0af
  * @constant
  * @memberOf Qt
  * @name Key_macron
  * @see Qt#Key
  * @type Number
  */
Qt.Key_macron = 0xaf;

/**
  * @default 0x0b0
  * @constant
  * @memberOf Qt
  * @name Key_degree
  * @see Qt#Key
  * @type Number
  */
Qt.Key_degree = 0xb0;

/**
  * @default 0x0b1
  * @constant
  * @memberOf Qt
  * @name Key_plusminus
  * @see Qt#Key
  * @type Number
  */
Qt.Key_plusminus = 0xb1;

/**
  * @default 0x0b2
  * @constant
  * @memberOf Qt
  * @name Key_twosuperior
  * @see Qt#Key
  * @type Number
  */
Qt.Key_twosuperior = 0xb2;

/**
  * @default 0x0b3
  * @constant
  * @memberOf Qt
  * @name Key_threesuperior
  * @see Qt#Key
  * @type Number
  */
Qt.Key_threesuperior = 0xb3;

/**
  * @default 0x0b4
  * @constant
  * @memberOf Qt
  * @name Key_acute
  * @see Qt#Key
  * @type Number
  */
Qt.Key_acute = 0xb4;

/**
  * @default 0x0b5
  * @constant
  * @memberOf Qt
  * @name Key_mu
  * @see Qt#Key
  * @type Number
  */
Qt.Key_mu = 0xb5;

/**
  * @default 0x0b6
  * @constant
  * @memberOf Qt
  * @name Key_paragraph
  * @see Qt#Key
  * @type Number
  */
Qt.Key_paragraph = 0xb6;

/**
  * @default 0x0b7
  * @constant
  * @memberOf Qt
  * @name Key_periodcentered
  * @see Qt#Key
  * @type Number
  */
Qt.Key_periodcentered = 0xb7;

/**
  * @default 0x0b8
  * @constant
  * @memberOf Qt
  * @name Key_cedilla
  * @see Qt#Key
  * @type Number
  */
Qt.Key_cedilla = 0xb8;

/**
  * @default 0x0b9
  * @constant
  * @memberOf Qt
  * @name Key_onesuperior
  * @see Qt#Key
  * @type Number
  */
Qt.Key_onesuperior = 0xb9;

/**
  * @default 0x0ba
  * @constant
  * @memberOf Qt
  * @name Key_masculine
  * @see Qt#Key
  * @type Number
  */
Qt.Key_masculine = 0xba;

/**
  * @default 0x0bb
  * @constant
  * @memberOf Qt
  * @name Key_guillemotright
  * @see Qt#Key
  * @type Number
  */
Qt.Key_guillemotright = 0xbb;

/**
  * @default 0x0bc
  * @constant
  * @memberOf Qt
  * @name Key_onequarter
  * @see Qt#Key
  * @type Number
  */
Qt.Key_onequarter = 0xbc;

/**
  * @default 0x0bd
  * @constant
  * @memberOf Qt
  * @name Key_onehalf
  * @see Qt#Key
  * @type Number
  */
Qt.Key_onehalf = 0xbd;

/**
  * @default 0x0be
  * @constant
  * @memberOf Qt
  * @name Key_threequarters
  * @see Qt#Key
  * @type Number
  */
Qt.Key_threequarters = 0xbe;

/**
  * @default 0x0bf
  * @constant
  * @memberOf Qt
  * @name Key_questiondown
  * @see Qt#Key
  * @type Number
  */
Qt.Key_questiondown = 0xbf;

/**
  * @default 0x0c0
  * @constant
  * @memberOf Qt
  * @name Key_Agrave
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Agrave = 0xc0;

/**
  * @default 0x0c1
  * @constant
  * @memberOf Qt
  * @name Key_Aacute
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Aacute = 0xc1;

/**
  * @default 0x0c2
  * @constant
  * @memberOf Qt
  * @name Key_Acircumflex
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Acircumflex = 0xc2;

/**
  * @default 0x0c3
  * @constant
  * @memberOf Qt
  * @name Key_Atilde
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Atilde = 0xc3;

/**
  * @default 0x0c4
  * @constant
  * @memberOf Qt
  * @name Key_Adiaeresis
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Adiaeresis = 0xc4;

/**
  * @default 0x0c5
  * @constant
  * @memberOf Qt
  * @name Key_Aring
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Aring = 0xc5;

/**
  * @default 0x0c6
  * @constant
  * @memberOf Qt
  * @name Key_AE
  * @see Qt#Key
  * @type Number
  */
Qt.Key_AE = 0xc6;

/**
  * @default 0x0c7
  * @constant
  * @memberOf Qt
  * @name Key_Ccedilla
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Ccedilla = 0xc7;

/**
  * @default 0x0c8
  * @constant
  * @memberOf Qt
  * @name Key_Egrave
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Egrave = 0xc8;

/**
  * @default 0x0c9
  * @constant
  * @memberOf Qt
  * @name Key_Eacute
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Eacute = 0xc9;

/**
  * @default 0x0ca
  * @constant
  * @memberOf Qt
  * @name Key_Ecircumflex
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Ecircumflex = 0xca;

/**
  * @default 0x0cb
  * @constant
  * @memberOf Qt
  * @name Key_Ediaeresis
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Ediaeresis = 0xcb;

/**
  * @default 0x0cc
  * @constant
  * @memberOf Qt
  * @name Key_Igrave
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Igrave = 0xcc;

/**
  * @default 0x0cd
  * @constant
  * @memberOf Qt
  * @name Key_Iacute
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Iacute = 0xcd;

/**
  * @default 0x0ce
  * @constant
  * @memberOf Qt
  * @name Key_Icircumflex
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Icircumflex = 0xce;

/**
  * @default 0x0cf
  * @constant
  * @memberOf Qt
  * @name Key_Idiaeresis
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Idiaeresis = 0xcf;

/**
  * @default 0x0d0
  * @constant
  * @memberOf Qt
  * @name Key_ETH
  * @see Qt#Key
  * @type Number
  */
Qt.Key_ETH = 0xd0;

/**
  * @default 0x0d1
  * @constant
  * @memberOf Qt
  * @name Key_Ntilde
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Ntilde = 0xd1;

/**
  * @default 0x0d2
  * @constant
  * @memberOf Qt
  * @name Key_Ograve
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Ograve = 0xd2;

/**
  * @default 0x0d3
  * @constant
  * @memberOf Qt
  * @name Key_Oacute
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Oacute = 0xd3;

/**
  * @default 0x0d4
  * @constant
  * @memberOf Qt
  * @name Key_Ocircumflex
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Ocircumflex = 0xd4;

/**
  * @default 0x0d5
  * @constant
  * @memberOf Qt
  * @name Key_Otilde
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Otilde = 0xd5;

/**
  * @default 0x0d6
  * @constant
  * @memberOf Qt
  * @name Key_Odiaeresis
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Odiaeresis = 0xd6;

/**
  * @default 0x0d7
  * @constant
  * @memberOf Qt
  * @name Key_multiply
  * @see Qt#Key
  * @type Number
  */
Qt.Key_multiply = 0xd7;

/**
  * @default 0x0d8
  * @constant
  * @memberOf Qt
  * @name Key_Ooblique
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Ooblique = 0xd8;

/**
  * @default 0x0d9
  * @constant
  * @memberOf Qt
  * @name Key_Ugrave
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Ugrave = 0xd9;

/**
  * @default 0x0da
  * @constant
  * @memberOf Qt
  * @name Key_Uacute
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Uacute = 0xda;

/**
  * @default 0x0db
  * @constant
  * @memberOf Qt
  * @name Key_Ucircumflex
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Ucircumflex = 0xdb;

/**
  * @default 0x0dc
  * @constant
  * @memberOf Qt
  * @name Key_Udiaeresis
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Udiaeresis = 0xdc;

/**
  * @default 0x0dd
  * @constant
  * @memberOf Qt
  * @name Key_Yacute
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Yacute = 0xdd;

/**
  * @default 0x0de
  * @constant
  * @memberOf Qt
  * @name Key_THORN
  * @see Qt#Key
  * @type Number
  */
Qt.Key_THORN = 0xde;

/**
  * @default 0x0df
  * @constant
  * @memberOf Qt
  * @name Key_ssharp
  * @see Qt#Key
  * @type Number
  */
Qt.Key_ssharp = 0xdf;

/**
  * @default 0x0f7
  * @constant
  * @memberOf Qt
  * @name Key_division
  * @see Qt#Key
  * @type Number
  */
Qt.Key_division = 0xf7;

/**
  * @default 0x0ff
  * @constant
  * @memberOf Qt
  * @name Key_ydiaeresis
  * @see Qt#Key
  * @type Number
  */
Qt.Key_ydiaeresis = 0xff;

/**
  * @default 0x01000000
  * @constant
  * @memberOf Qt
  * @name Key_Escape
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Escape = 0x1000000;

/**
  * @default 0x01000001
  * @constant
  * @memberOf Qt
  * @name Key_Tab
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Tab = 0x1000001;

/**
  * @default 0x01000002
  * @constant
  * @memberOf Qt
  * @name Key_Backtab
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Backtab = 0x1000002;

/**
  * @default 0x01000003
  * @constant
  * @memberOf Qt
  * @name Key_Backspace
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Backspace = 0x1000003;

/**
  * @default 0x01000004
  * @constant
  * @memberOf Qt
  * @name Key_Return
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Return = 0x1000004;

/**
  * @default 0x01000005
  * @constant
  * @memberOf Qt
  * @name Key_Enter
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Enter = 0x1000005;

/**
  * @default 0x01000006
  * @constant
  * @memberOf Qt
  * @name Key_Insert
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Insert = 0x1000006;

/**
  * @default 0x01000007
  * @constant
  * @memberOf Qt
  * @name Key_Delete
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Delete = 0x1000007;

/**
  * @default 0x01000008
  * @constant
  * @memberOf Qt
  * @name Key_Pause
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Pause = 0x1000008;

/**
  * @default 0x01000009
  * @constant
  * @memberOf Qt
  * @name Key_Print
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Print = 0x1000009;

/**
  * @default 0x0100000a
  * @constant
  * @memberOf Qt
  * @name Key_SysReq
  * @see Qt#Key
  * @type Number
  */
Qt.Key_SysReq = 0x100000a;

/**
  * @default 0x0100000b
  * @constant
  * @memberOf Qt
  * @name Key_Clear
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Clear = 0x100000b;

/**
  * @default 0x01000010
  * @constant
  * @memberOf Qt
  * @name Key_Home
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Home = 0x1000010;

/**
  * @default 0x01000011
  * @constant
  * @memberOf Qt
  * @name Key_End
  * @see Qt#Key
  * @type Number
  */
Qt.Key_End = 0x1000011;

/**
  * @default 0x01000012
  * @constant
  * @memberOf Qt
  * @name Key_Left
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Left = 0x1000012;

/**
  * @default 0x01000013
  * @constant
  * @memberOf Qt
  * @name Key_Up
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Up = 0x1000013;

/**
  * @default 0x01000014
  * @constant
  * @memberOf Qt
  * @name Key_Right
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Right = 0x1000014;

/**
  * @default 0x01000015
  * @constant
  * @memberOf Qt
  * @name Key_Down
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Down = 0x1000015;

/**
  * @default 0x01000016
  * @constant
  * @memberOf Qt
  * @name Key_PageUp
  * @see Qt#Key
  * @type Number
  */
Qt.Key_PageUp = 0x1000016;

/**
  * @default 0x01000017
  * @constant
  * @memberOf Qt
  * @name Key_PageDown
  * @see Qt#Key
  * @type Number
  */
Qt.Key_PageDown = 0x1000017;

/**
  * @default 0x01000020
  * @constant
  * @memberOf Qt
  * @name Key_Shift
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Shift = 0x1000020;

/**
  * @default 0x01000021
  * @constant
  * @memberOf Qt
  * @name Key_Control
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Control = 0x1000021;

/**
  * @default 0x01000022
  * @constant
  * @memberOf Qt
  * @name Key_Meta
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Meta = 0x1000022;

/**
  * @default 0x01000023
  * @constant
  * @memberOf Qt
  * @name Key_Alt
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Alt = 0x1000023;

/**
  * @default 0x01000024
  * @constant
  * @memberOf Qt
  * @name Key_CapsLock
  * @see Qt#Key
  * @type Number
  */
Qt.Key_CapsLock = 0x1000024;

/**
  * @default 0x01000025
  * @constant
  * @memberOf Qt
  * @name Key_NumLock
  * @see Qt#Key
  * @type Number
  */
Qt.Key_NumLock = 0x1000025;

/**
  * @default 0x01000026
  * @constant
  * @memberOf Qt
  * @name Key_ScrollLock
  * @see Qt#Key
  * @type Number
  */
Qt.Key_ScrollLock = 0x1000026;

/**
  * @default 0x01000030
  * @constant
  * @memberOf Qt
  * @name Key_F1
  * @see Qt#Key
  * @type Number
  */
Qt.Key_F1 = 0x1000030;

/**
  * @default 0x01000031
  * @constant
  * @memberOf Qt
  * @name Key_F2
  * @see Qt#Key
  * @type Number
  */
Qt.Key_F2 = 0x1000031;

/**
  * @default 0x01000032
  * @constant
  * @memberOf Qt
  * @name Key_F3
  * @see Qt#Key
  * @type Number
  */
Qt.Key_F3 = 0x1000032;

/**
  * @default 0x01000033
  * @constant
  * @memberOf Qt
  * @name Key_F4
  * @see Qt#Key
  * @type Number
  */
Qt.Key_F4 = 0x1000033;

/**
  * @default 0x01000034
  * @constant
  * @memberOf Qt
  * @name Key_F5
  * @see Qt#Key
  * @type Number
  */
Qt.Key_F5 = 0x1000034;

/**
  * @default 0x01000035
  * @constant
  * @memberOf Qt
  * @name Key_F6
  * @see Qt#Key
  * @type Number
  */
Qt.Key_F6 = 0x1000035;

/**
  * @default 0x01000036
  * @constant
  * @memberOf Qt
  * @name Key_F7
  * @see Qt#Key
  * @type Number
  */
Qt.Key_F7 = 0x1000036;

/**
  * @default 0x01000037
  * @constant
  * @memberOf Qt
  * @name Key_F8
  * @see Qt#Key
  * @type Number
  */
Qt.Key_F8 = 0x1000037;

/**
  * @default 0x01000038
  * @constant
  * @memberOf Qt
  * @name Key_F9
  * @see Qt#Key
  * @type Number
  */
Qt.Key_F9 = 0x1000038;

/**
  * @default 0x01000039
  * @constant
  * @memberOf Qt
  * @name Key_F10
  * @see Qt#Key
  * @type Number
  */
Qt.Key_F10 = 0x1000039;

/**
  * @default 0x0100003a
  * @constant
  * @memberOf Qt
  * @name Key_F11
  * @see Qt#Key
  * @type Number
  */
Qt.Key_F11 = 0x100003a;

/**
  * @default 0x0100003b
  * @constant
  * @memberOf Qt
  * @name Key_F12
  * @see Qt#Key
  * @type Number
  */
Qt.Key_F12 = 0x100003b;

/**
  * @default 0x0100003c
  * @constant
  * @memberOf Qt
  * @name Key_F13
  * @see Qt#Key
  * @type Number
  */
Qt.Key_F13 = 0x100003c;

/**
  * @default 0x0100003d
  * @constant
  * @memberOf Qt
  * @name Key_F14
  * @see Qt#Key
  * @type Number
  */
Qt.Key_F14 = 0x100003d;

/**
  * @default 0x0100003e
  * @constant
  * @memberOf Qt
  * @name Key_F15
  * @see Qt#Key
  * @type Number
  */
Qt.Key_F15 = 0x100003e;

/**
  * @default 0x0100003f
  * @constant
  * @memberOf Qt
  * @name Key_F16
  * @see Qt#Key
  * @type Number
  */
Qt.Key_F16 = 0x100003f;

/**
  * @default 0x01000040
  * @constant
  * @memberOf Qt
  * @name Key_F17
  * @see Qt#Key
  * @type Number
  */
Qt.Key_F17 = 0x1000040;

/**
  * @default 0x01000041
  * @constant
  * @memberOf Qt
  * @name Key_F18
  * @see Qt#Key
  * @type Number
  */
Qt.Key_F18 = 0x1000041;

/**
  * @default 0x01000042
  * @constant
  * @memberOf Qt
  * @name Key_F19
  * @see Qt#Key
  * @type Number
  */
Qt.Key_F19 = 0x1000042;

/**
  * @default 0x01000043
  * @constant
  * @memberOf Qt
  * @name Key_F20
  * @see Qt#Key
  * @type Number
  */
Qt.Key_F20 = 0x1000043;

/**
  * @default 0x01000044
  * @constant
  * @memberOf Qt
  * @name Key_F21
  * @see Qt#Key
  * @type Number
  */
Qt.Key_F21 = 0x1000044;

/**
  * @default 0x01000045
  * @constant
  * @memberOf Qt
  * @name Key_F22
  * @see Qt#Key
  * @type Number
  */
Qt.Key_F22 = 0x1000045;

/**
  * @default 0x01000046
  * @constant
  * @memberOf Qt
  * @name Key_F23
  * @see Qt#Key
  * @type Number
  */
Qt.Key_F23 = 0x1000046;

/**
  * @default 0x01000047
  * @constant
  * @memberOf Qt
  * @name Key_F24
  * @see Qt#Key
  * @type Number
  */
Qt.Key_F24 = 0x1000047;

/**
  * @default 0x01000048
  * @constant
  * @memberOf Qt
  * @name Key_F25
  * @see Qt#Key
  * @type Number
  */
Qt.Key_F25 = 0x1000048;

/**
  * @default 0x01000049
  * @constant
  * @memberOf Qt
  * @name Key_F26
  * @see Qt#Key
  * @type Number
  */
Qt.Key_F26 = 0x1000049;

/**
  * @default 0x0100004a
  * @constant
  * @memberOf Qt
  * @name Key_F27
  * @see Qt#Key
  * @type Number
  */
Qt.Key_F27 = 0x100004a;

/**
  * @default 0x0100004b
  * @constant
  * @memberOf Qt
  * @name Key_F28
  * @see Qt#Key
  * @type Number
  */
Qt.Key_F28 = 0x100004b;

/**
  * @default 0x0100004c
  * @constant
  * @memberOf Qt
  * @name Key_F29
  * @see Qt#Key
  * @type Number
  */
Qt.Key_F29 = 0x100004c;

/**
  * @default 0x0100004d
  * @constant
  * @memberOf Qt
  * @name Key_F30
  * @see Qt#Key
  * @type Number
  */
Qt.Key_F30 = 0x100004d;

/**
  * @default 0x0100004e
  * @constant
  * @memberOf Qt
  * @name Key_F31
  * @see Qt#Key
  * @type Number
  */
Qt.Key_F31 = 0x100004e;

/**
  * @default 0x0100004f
  * @constant
  * @memberOf Qt
  * @name Key_F32
  * @see Qt#Key
  * @type Number
  */
Qt.Key_F32 = 0x100004f;

/**
  * @default 0x01000050
  * @constant
  * @memberOf Qt
  * @name Key_F33
  * @see Qt#Key
  * @type Number
  */
Qt.Key_F33 = 0x1000050;

/**
  * @default 0x01000051
  * @constant
  * @memberOf Qt
  * @name Key_F34
  * @see Qt#Key
  * @type Number
  */
Qt.Key_F34 = 0x1000051;

/**
  * @default 0x01000052
  * @constant
  * @memberOf Qt
  * @name Key_F35
  * @see Qt#Key
  * @type Number
  */
Qt.Key_F35 = 0x1000052;

/**
  * @default 0x01000053
  * @constant
  * @memberOf Qt
  * @name Key_Super_L
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Super_L = 0x1000053;

/**
  * @default 0x01000054
  * @constant
  * @memberOf Qt
  * @name Key_Super_R
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Super_R = 0x1000054;

/**
  * @default 0x01000055
  * @constant
  * @memberOf Qt
  * @name Key_Menu
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Menu = 0x1000055;

/**
  * @default 0x01000056
  * @constant
  * @memberOf Qt
  * @name Key_Hyper_L
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Hyper_L = 0x1000056;

/**
  * @default 0x01000057
  * @constant
  * @memberOf Qt
  * @name Key_Hyper_R
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Hyper_R = 0x1000057;

/**
  * @default 0x01000058
  * @constant
  * @memberOf Qt
  * @name Key_Help
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Help = 0x1000058;

/**
  * @default 0x01000059
  * @constant
  * @memberOf Qt
  * @name Key_Direction_L
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Direction_L = 0x1000059;

/**
  * @default 0x01000060
  * @constant
  * @memberOf Qt
  * @name Key_Direction_R
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Direction_R = 0x1000060;

/**
  * @default 0x01000061
  * @constant
  * @memberOf Qt
  * @name Key_Back
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Back = 0x1000061;

/**
  * @default 0x01000062
  * @constant
  * @memberOf Qt
  * @name Key_Forward
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Forward = 0x1000062;

/**
  * @default 0x01000063
  * @constant
  * @memberOf Qt
  * @name Key_Stop
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Stop = 0x1000063;

/**
  * @default 0x01000064
  * @constant
  * @memberOf Qt
  * @name Key_Refresh
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Refresh = 0x1000064;

/**
  * @default 0x01000070
  * @constant
  * @memberOf Qt
  * @name Key_VolumeDown
  * @see Qt#Key
  * @type Number
  */
Qt.Key_VolumeDown = 0x1000070;

/**
  * @default 0x01000071
  * @constant
  * @memberOf Qt
  * @name Key_VolumeMute
  * @see Qt#Key
  * @type Number
  */
Qt.Key_VolumeMute = 0x1000071;

/**
  * @default 0x01000072
  * @constant
  * @memberOf Qt
  * @name Key_VolumeUp
  * @see Qt#Key
  * @type Number
  */
Qt.Key_VolumeUp = 0x1000072;

/**
  * @default 0x01000073
  * @constant
  * @memberOf Qt
  * @name Key_BassBoost
  * @see Qt#Key
  * @type Number
  */
Qt.Key_BassBoost = 0x1000073;

/**
  * @default 0x01000074
  * @constant
  * @memberOf Qt
  * @name Key_BassUp
  * @see Qt#Key
  * @type Number
  */
Qt.Key_BassUp = 0x1000074;

/**
  * @default 0x01000075
  * @constant
  * @memberOf Qt
  * @name Key_BassDown
  * @see Qt#Key
  * @type Number
  */
Qt.Key_BassDown = 0x1000075;

/**
  * @default 0x01000076
  * @constant
  * @memberOf Qt
  * @name Key_TrebleUp
  * @see Qt#Key
  * @type Number
  */
Qt.Key_TrebleUp = 0x1000076;

/**
  * @default 0x01000077
  * @constant
  * @memberOf Qt
  * @name Key_TrebleDown
  * @see Qt#Key
  * @type Number
  */
Qt.Key_TrebleDown = 0x1000077;

/**
  * @default 0x01000080
  * @constant
  * @memberOf Qt
  * @name Key_MediaPlay
  * @see Qt#Key
  * @type Number
  */
Qt.Key_MediaPlay = 0x1000080;

/**
  * @default 0x01000081
  * @constant
  * @memberOf Qt
  * @name Key_MediaStop
  * @see Qt#Key
  * @type Number
  */
Qt.Key_MediaStop = 0x1000081;

/**
  * @default 0x01000082
  * @constant
  * @memberOf Qt
  * @name Key_MediaPrevious
  * @see Qt#Key
  * @type Number
  */
Qt.Key_MediaPrevious = 0x1000082;

/**
  * @default 0x01000083
  * @constant
  * @memberOf Qt
  * @name Key_MediaNext
  * @see Qt#Key
  * @type Number
  */
Qt.Key_MediaNext = 0x1000083;

/**
  * @default 0x01000084
  * @constant
  * @memberOf Qt
  * @name Key_MediaRecord
  * @see Qt#Key
  * @type Number
  */
Qt.Key_MediaRecord = 0x1000084;

/**
  * @default 0x1000085
  * @constant
  * @memberOf Qt
  * @name Key_MediaPause
  * @see Qt#Key
  * @type Number
  */
Qt.Key_MediaPause = 0x1000085;

/**
  * @default 0x1000086
  * @constant
  * @memberOf Qt
  * @name Key_MediaTogglePlayPause
  * @see Qt#Key
  * @type Number
  */
Qt.Key_MediaTogglePlayPause = 0x1000086;

/**
  * @default 0x01000090
  * @constant
  * @memberOf Qt
  * @name Key_HomePage
  * @see Qt#Key
  * @type Number
  */
Qt.Key_HomePage = 0x1000090;

/**
  * @default 0x01000091
  * @constant
  * @memberOf Qt
  * @name Key_Favorites
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Favorites = 0x1000091;

/**
  * @default 0x01000092
  * @constant
  * @memberOf Qt
  * @name Key_Search
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Search = 0x1000092;

/**
  * @default 0x01000093
  * @constant
  * @memberOf Qt
  * @name Key_Standby
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Standby = 0x1000093;

/**
  * @default 0x01000094
  * @constant
  * @memberOf Qt
  * @name Key_OpenUrl
  * @see Qt#Key
  * @type Number
  */
Qt.Key_OpenUrl = 0x1000094;

/**
  * @default 0x010000a0
  * @constant
  * @memberOf Qt
  * @name Key_LaunchMail
  * @see Qt#Key
  * @type Number
  */
Qt.Key_LaunchMail = 0x10000a0;

/**
  * @default 0x010000a1
  * @constant
  * @memberOf Qt
  * @name Key_LaunchMedia
  * @see Qt#Key
  * @type Number
  */
Qt.Key_LaunchMedia = 0x10000a1;

/**
  * @default 0x010000a2
  * @constant
  * @memberOf Qt
  * @name Key_Launch0
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Launch0 = 0x10000a2;

/**
  * @default 0x010000a3
  * @constant
  * @memberOf Qt
  * @name Key_Launch1
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Launch1 = 0x10000a3;

/**
  * @default 0x010000a4
  * @constant
  * @memberOf Qt
  * @name Key_Launch2
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Launch2 = 0x10000a4;

/**
  * @default 0x010000a5
  * @constant
  * @memberOf Qt
  * @name Key_Launch3
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Launch3 = 0x10000a5;

/**
  * @default 0x010000a6
  * @constant
  * @memberOf Qt
  * @name Key_Launch4
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Launch4 = 0x10000a6;

/**
  * @default 0x010000a7
  * @constant
  * @memberOf Qt
  * @name Key_Launch5
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Launch5 = 0x10000a7;

/**
  * @default 0x010000a8
  * @constant
  * @memberOf Qt
  * @name Key_Launch6
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Launch6 = 0x10000a8;

/**
  * @default 0x010000a9
  * @constant
  * @memberOf Qt
  * @name Key_Launch7
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Launch7 = 0x10000a9;

/**
  * @default 0x010000aa
  * @constant
  * @memberOf Qt
  * @name Key_Launch8
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Launch8 = 0x10000aa;

/**
  * @default 0x010000ab
  * @constant
  * @memberOf Qt
  * @name Key_Launch9
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Launch9 = 0x10000ab;

/**
  * @default 0x010000ac
  * @constant
  * @memberOf Qt
  * @name Key_LaunchA
  * @see Qt#Key
  * @type Number
  */
Qt.Key_LaunchA = 0x10000ac;

/**
  * @default 0x010000ad
  * @constant
  * @memberOf Qt
  * @name Key_LaunchB
  * @see Qt#Key
  * @type Number
  */
Qt.Key_LaunchB = 0x10000ad;

/**
  * @default 0x010000ae
  * @constant
  * @memberOf Qt
  * @name Key_LaunchC
  * @see Qt#Key
  * @type Number
  */
Qt.Key_LaunchC = 0x10000ae;

/**
  * @default 0x010000af
  * @constant
  * @memberOf Qt
  * @name Key_LaunchD
  * @see Qt#Key
  * @type Number
  */
Qt.Key_LaunchD = 0x10000af;

/**
  * @default 0x010000b0
  * @constant
  * @memberOf Qt
  * @name Key_LaunchE
  * @see Qt#Key
  * @type Number
  */
Qt.Key_LaunchE = 0x10000b0;

/**
  * @default 0x010000b1
  * @constant
  * @memberOf Qt
  * @name Key_LaunchF
  * @see Qt#Key
  * @type Number
  */
Qt.Key_LaunchF = 0x10000b1;

/**
  * @default 0x010000b2
  * @constant
  * @memberOf Qt
  * @name Key_MonBrightnessUp
  * @see Qt#Key
  * @type Number
  */
Qt.Key_MonBrightnessUp = 0x10000b2;

/**
  * @default 0x010000b3
  * @constant
  * @memberOf Qt
  * @name Key_MonBrightnessDown
  * @see Qt#Key
  * @type Number
  */
Qt.Key_MonBrightnessDown = 0x10000b3;

/**
  * @default 0x010000b4
  * @constant
  * @memberOf Qt
  * @name Key_KeyboardLightOnOff
  * @see Qt#Key
  * @type Number
  */
Qt.Key_KeyboardLightOnOff = 0x10000b4;

/**
  * @default 0x010000b5
  * @constant
  * @memberOf Qt
  * @name Key_KeyboardBrightnessUp
  * @see Qt#Key
  * @type Number
  */
Qt.Key_KeyboardBrightnessUp = 0x10000b5;

/**
  * @default 0x010000b6
  * @constant
  * @memberOf Qt
  * @name Key_KeyboardBrightnessDown
  * @see Qt#Key
  * @type Number
  */
Qt.Key_KeyboardBrightnessDown = 0x10000b6;

/**
  * @default 0x010000b7
  * @constant
  * @memberOf Qt
  * @name Key_PowerOff
  * @see Qt#Key
  * @type Number
  */
Qt.Key_PowerOff = 0x10000b7;

/**
  * @default 0x010000b8
  * @constant
  * @memberOf Qt
  * @name Key_WakeUp
  * @see Qt#Key
  * @type Number
  */
Qt.Key_WakeUp = 0x10000b8;

/**
  * @default 0x010000b9
  * @constant
  * @memberOf Qt
  * @name Key_Eject
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Eject = 0x10000b9;

/**
  * @default 0x010000ba
  * @constant
  * @memberOf Qt
  * @name Key_ScreenSaver
  * @see Qt#Key
  * @type Number
  */
Qt.Key_ScreenSaver = 0x10000ba;

/**
  * @default 0x010000bb
  * @constant
  * @memberOf Qt
  * @name Key_WWW
  * @see Qt#Key
  * @type Number
  */
Qt.Key_WWW = 0x10000bb;

/**
  * @default 0x010000bc
  * @constant
  * @memberOf Qt
  * @name Key_Memo
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Memo = 0x10000bc;

/**
  * @default 0x010000bd
  * @constant
  * @memberOf Qt
  * @name Key_LightBulb
  * @see Qt#Key
  * @type Number
  */
Qt.Key_LightBulb = 0x10000bd;

/**
  * @default 0x010000be
  * @constant
  * @memberOf Qt
  * @name Key_Shop
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Shop = 0x10000be;

/**
  * @default 0x010000bf
  * @constant
  * @memberOf Qt
  * @name Key_History
  * @see Qt#Key
  * @type Number
  */
Qt.Key_History = 0x10000bf;

/**
  * @default 0x010000c0
  * @constant
  * @memberOf Qt
  * @name Key_AddFavorite
  * @see Qt#Key
  * @type Number
  */
Qt.Key_AddFavorite = 0x10000c0;

/**
  * @default 0x010000c1
  * @constant
  * @memberOf Qt
  * @name Key_HotLinks
  * @see Qt#Key
  * @type Number
  */
Qt.Key_HotLinks = 0x10000c1;

/**
  * @default 0x010000c2
  * @constant
  * @memberOf Qt
  * @name Key_BrightnessAdjust
  * @see Qt#Key
  * @type Number
  */
Qt.Key_BrightnessAdjust = 0x10000c2;

/**
  * @default 0x010000c3
  * @constant
  * @memberOf Qt
  * @name Key_Finance
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Finance = 0x10000c3;

/**
  * @default 0x010000c4
  * @constant
  * @memberOf Qt
  * @name Key_Community
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Community = 0x10000c4;

/**
  * @default 0x010000c5
  * @constant
  * @memberOf Qt
  * @name Key_AudioRewind
  * @see Qt#Key
  * @type Number
  */
Qt.Key_AudioRewind = 0x10000c5;

/**
  * @default 0x010000c6
  * @constant
  * @memberOf Qt
  * @name Key_BackForward
  * @see Qt#Key
  * @type Number
  */
Qt.Key_BackForward = 0x10000c6;

/**
  * @default 0x010000c7
  * @constant
  * @memberOf Qt
  * @name Key_ApplicationLeft
  * @see Qt#Key
  * @type Number
  */
Qt.Key_ApplicationLeft = 0x10000c7;

/**
  * @default 0x010000c8
  * @constant
  * @memberOf Qt
  * @name Key_ApplicationRight
  * @see Qt#Key
  * @type Number
  */
Qt.Key_ApplicationRight = 0x10000c8;

/**
  * @default 0x010000c9
  * @constant
  * @memberOf Qt
  * @name Key_Book
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Book = 0x10000c9;

/**
  * @default 0x010000ca
  * @constant
  * @memberOf Qt
  * @name Key_CD
  * @see Qt#Key
  * @type Number
  */
Qt.Key_CD = 0x10000ca;

/**
  * @default 0x010000cb
  * @constant
  * @memberOf Qt
  * @name Key_Calculator
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Calculator = 0x10000cb;

/**
  * @default 0x010000cc
  * @constant
  * @memberOf Qt
  * @name Key_ToDoList
  * @see Qt#Key
  * @type Number
  */
Qt.Key_ToDoList = 0x10000cc;

/**
  * @default 0x010000cd
  * @constant
  * @memberOf Qt
  * @name Key_ClearGrab
  * @see Qt#Key
  * @type Number
  */
Qt.Key_ClearGrab = 0x10000cd;

/**
  * @default 0x010000ce
  * @constant
  * @memberOf Qt
  * @name Key_Close
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Close = 0x10000ce;

/**
  * @default 0x010000cf
  * @constant
  * @memberOf Qt
  * @name Key_Copy
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Copy = 0x10000cf;

/**
  * @default 0x010000d0
  * @constant
  * @memberOf Qt
  * @name Key_Cut
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Cut = 0x10000d0;

/**
  * @default 0x010000d1
  * @constant
  * @memberOf Qt
  * @name Key_Display
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Display = 0x10000d1;

/**
  * @default 0x010000d2
  * @constant
  * @memberOf Qt
  * @name Key_DOS
  * @see Qt#Key
  * @type Number
  */
Qt.Key_DOS = 0x10000d2;

/**
  * @default 0x010000d3
  * @constant
  * @memberOf Qt
  * @name Key_Documents
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Documents = 0x10000d3;

/**
  * @default 0x010000d4
  * @constant
  * @memberOf Qt
  * @name Key_Excel
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Excel = 0x10000d4;

/**
  * @default 0x010000d5
  * @constant
  * @memberOf Qt
  * @name Key_Explorer
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Explorer = 0x10000d5;

/**
  * @default 0x010000d6
  * @constant
  * @memberOf Qt
  * @name Key_Game
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Game = 0x10000d6;

/**
  * @default 0x010000d7
  * @constant
  * @memberOf Qt
  * @name Key_Go
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Go = 0x10000d7;

/**
  * @default 0x010000d8
  * @constant
  * @memberOf Qt
  * @name Key_iTouch
  * @see Qt#Key
  * @type Number
  */
Qt.Key_iTouch = 0x10000d8;

/**
  * @default 0x010000d9
  * @constant
  * @memberOf Qt
  * @name Key_LogOff
  * @see Qt#Key
  * @type Number
  */
Qt.Key_LogOff = 0x10000d9;

/**
  * @default 0x010000da
  * @constant
  * @memberOf Qt
  * @name Key_Market
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Market = 0x10000da;

/**
  * @default 0x010000db
  * @constant
  * @memberOf Qt
  * @name Key_Meeting
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Meeting = 0x10000db;

/**
  * @default 0x010000dc
  * @constant
  * @memberOf Qt
  * @name Key_MenuKB
  * @see Qt#Key
  * @type Number
  */
Qt.Key_MenuKB = 0x10000dc;

/**
  * @default 0x010000dd
  * @constant
  * @memberOf Qt
  * @name Key_MenuPB
  * @see Qt#Key
  * @type Number
  */
Qt.Key_MenuPB = 0x10000dd;

/**
  * @default 0x010000de
  * @constant
  * @memberOf Qt
  * @name Key_MySites
  * @see Qt#Key
  * @type Number
  */
Qt.Key_MySites = 0x10000de;

/**
  * @default 0x010000df
  * @constant
  * @memberOf Qt
  * @name Key_News
  * @see Qt#Key
  * @type Number
  */
Qt.Key_News = 0x10000df;

/**
  * @default 0x010000e0
  * @constant
  * @memberOf Qt
  * @name Key_OfficeHome
  * @see Qt#Key
  * @type Number
  */
Qt.Key_OfficeHome = 0x10000e0;

/**
  * @default 0x010000e1
  * @constant
  * @memberOf Qt
  * @name Key_Option
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Option = 0x10000e1;

/**
  * @default 0x010000e2
  * @constant
  * @memberOf Qt
  * @name Key_Paste
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Paste = 0x10000e2;

/**
  * @default 0x010000e3
  * @constant
  * @memberOf Qt
  * @name Key_Phone
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Phone = 0x10000e3;

/**
  * @default 0x010000e4
  * @constant
  * @memberOf Qt
  * @name Key_Calendar
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Calendar = 0x10000e4;

/**
  * @default 0x010000e5
  * @constant
  * @memberOf Qt
  * @name Key_Reply
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Reply = 0x10000e5;

/**
  * @default 0x010000e6
  * @constant
  * @memberOf Qt
  * @name Key_Reload
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Reload = 0x10000e6;

/**
  * @default 0x010000e7
  * @constant
  * @memberOf Qt
  * @name Key_RotateWindows
  * @see Qt#Key
  * @type Number
  */
Qt.Key_RotateWindows = 0x10000e7;

/**
  * @default 0x010000e8
  * @constant
  * @memberOf Qt
  * @name Key_RotationPB
  * @see Qt#Key
  * @type Number
  */
Qt.Key_RotationPB = 0x10000e8;

/**
  * @default 0x010000e9
  * @constant
  * @memberOf Qt
  * @name Key_RotationKB
  * @see Qt#Key
  * @type Number
  */
Qt.Key_RotationKB = 0x10000e9;

/**
  * @default 0x010000ea
  * @constant
  * @memberOf Qt
  * @name Key_Save
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Save = 0x10000ea;

/**
  * @default 0x010000eb
  * @constant
  * @memberOf Qt
  * @name Key_Send
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Send = 0x10000eb;

/**
  * @default 0x010000ec
  * @constant
  * @memberOf Qt
  * @name Key_Spell
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Spell = 0x10000ec;

/**
  * @default 0x010000ed
  * @constant
  * @memberOf Qt
  * @name Key_SplitScreen
  * @see Qt#Key
  * @type Number
  */
Qt.Key_SplitScreen = 0x10000ed;

/**
  * @default 0x010000ee
  * @constant
  * @memberOf Qt
  * @name Key_Support
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Support = 0x10000ee;

/**
  * @default 0x010000ef
  * @constant
  * @memberOf Qt
  * @name Key_TaskPane
  * @see Qt#Key
  * @type Number
  */
Qt.Key_TaskPane = 0x10000ef;

/**
  * @default 0x010000f0
  * @constant
  * @memberOf Qt
  * @name Key_Terminal
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Terminal = 0x10000f0;

/**
  * @default 0x010000f1
  * @constant
  * @memberOf Qt
  * @name Key_Tools
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Tools = 0x10000f1;

/**
  * @default 0x010000f2
  * @constant
  * @memberOf Qt
  * @name Key_Travel
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Travel = 0x10000f2;

/**
  * @default 0x010000f3
  * @constant
  * @memberOf Qt
  * @name Key_Video
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Video = 0x10000f3;

/**
  * @default 0x010000f4
  * @constant
  * @memberOf Qt
  * @name Key_Word
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Word = 0x10000f4;

/**
  * @default 0x010000f5
  * @constant
  * @memberOf Qt
  * @name Key_Xfer
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Xfer = 0x10000f5;

/**
  * @default 0x010000f6
  * @constant
  * @memberOf Qt
  * @name Key_ZoomIn
  * @see Qt#Key
  * @type Number
  */
Qt.Key_ZoomIn = 0x10000f6;

/**
  * @default 0x010000f7
  * @constant
  * @memberOf Qt
  * @name Key_ZoomOut
  * @see Qt#Key
  * @type Number
  */
Qt.Key_ZoomOut = 0x10000f7;

/**
  * @default 0x010000f8
  * @constant
  * @memberOf Qt
  * @name Key_Away
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Away = 0x10000f8;

/**
  * @default 0x010000f9
  * @constant
  * @memberOf Qt
  * @name Key_Messenger
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Messenger = 0x10000f9;

/**
  * @default 0x010000fa
  * @constant
  * @memberOf Qt
  * @name Key_WebCam
  * @see Qt#Key
  * @type Number
  */
Qt.Key_WebCam = 0x10000fa;

/**
  * @default 0x010000fb
  * @constant
  * @memberOf Qt
  * @name Key_MailForward
  * @see Qt#Key
  * @type Number
  */
Qt.Key_MailForward = 0x10000fb;

/**
  * @default 0x010000fc
  * @constant
  * @memberOf Qt
  * @name Key_Pictures
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Pictures = 0x10000fc;

/**
  * @default 0x010000fd
  * @constant
  * @memberOf Qt
  * @name Key_Music
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Music = 0x10000fd;

/**
  * @default 0x010000fe
  * @constant
  * @memberOf Qt
  * @name Key_Battery
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Battery = 0x10000fe;

/**
  * @default 0x010000ff
  * @constant
  * @memberOf Qt
  * @name Key_Bluetooth
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Bluetooth = 0x10000ff;

/**
  * @default 0x01000100
  * @constant
  * @memberOf Qt
  * @name Key_WLAN
  * @see Qt#Key
  * @type Number
  */
Qt.Key_WLAN = 0x1000100;

/**
  * @default 0x01000101
  * @constant
  * @memberOf Qt
  * @name Key_UWB
  * @see Qt#Key
  * @type Number
  */
Qt.Key_UWB = 0x1000101;

/**
  * @default 0x01000102
  * @constant
  * @memberOf Qt
  * @name Key_AudioForward
  * @see Qt#Key
  * @type Number
  */
Qt.Key_AudioForward = 0x1000102;

/**
  * @default 0x01000103
  * @constant
  * @memberOf Qt
  * @name Key_AudioRepeat
  * @see Qt#Key
  * @type Number
  */
Qt.Key_AudioRepeat = 0x1000103;

/**
  * @default 0x01000104
  * @constant
  * @memberOf Qt
  * @name Key_AudioRandomPlay
  * @see Qt#Key
  * @type Number
  */
Qt.Key_AudioRandomPlay = 0x1000104;

/**
  * @default 0x01000105
  * @constant
  * @memberOf Qt
  * @name Key_Subtitle
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Subtitle = 0x1000105;

/**
  * @default 0x01000106
  * @constant
  * @memberOf Qt
  * @name Key_AudioCycleTrack
  * @see Qt#Key
  * @type Number
  */
Qt.Key_AudioCycleTrack = 0x1000106;

/**
  * @default 0x01000107
  * @constant
  * @memberOf Qt
  * @name Key_Time
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Time = 0x1000107;

/**
  * @default 0x01000108
  * @constant
  * @memberOf Qt
  * @name Key_Hibernate
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Hibernate = 0x1000108;

/**
  * @default 0x01000109
  * @constant
  * @memberOf Qt
  * @name Key_View
  * @see Qt#Key
  * @type Number
  */
Qt.Key_View = 0x1000109;

/**
  * @default 0x0100010a
  * @constant
  * @memberOf Qt
  * @name Key_TopMenu
  * @see Qt#Key
  * @type Number
  */
Qt.Key_TopMenu = 0x100010a;

/**
  * @default 0x0100010b
  * @constant
  * @memberOf Qt
  * @name Key_PowerDown
  * @see Qt#Key
  * @type Number
  */
Qt.Key_PowerDown = 0x100010b;

/**
  * @default 0x0100010c
  * @constant
  * @memberOf Qt
  * @name Key_Suspend
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Suspend = 0x100010c;

/**
  * @default 0x0100010d
  * @constant
  * @memberOf Qt
  * @name Key_ContrastAdjust
  * @see Qt#Key
  * @type Number
  */
Qt.Key_ContrastAdjust = 0x100010d;

/**
  * @default 0x0100010e
  * @constant
  * @memberOf Qt
  * @name Key_LaunchG
  * @see Qt#Key
  * @type Number
  */
Qt.Key_LaunchG = 0x100010e;

/**
  * @default 0x0100010f
  * @constant
  * @memberOf Qt
  * @name Key_LaunchH
  * @see Qt#Key
  * @type Number
  */
Qt.Key_LaunchH = 0x100010f;

/**
  * @default 0x01001103
  * @constant
  * @memberOf Qt
  * @name Key_AltGr
  * @see Qt#Key
  * @type Number
  */
Qt.Key_AltGr = 0x1001103;

/**
  * @default 0x01001120
  * @constant
  * @memberOf Qt
  * @name Key_Multi_key
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Multi_key = 0x1001120;

/**
  * @default 0x01001121
  * @constant
  * @memberOf Qt
  * @name Key_Kanji
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Kanji = 0x1001121;

/**
  * @default 0x01001122
  * @constant
  * @memberOf Qt
  * @name Key_Muhenkan
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Muhenkan = 0x1001122;

/**
  * @default 0x01001123
  * @constant
  * @memberOf Qt
  * @name Key_Henkan
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Henkan = 0x1001123;

/**
  * @default 0x01001124
  * @constant
  * @memberOf Qt
  * @name Key_Romaji
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Romaji = 0x1001124;

/**
  * @default 0x01001125
  * @constant
  * @memberOf Qt
  * @name Key_Hiragana
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Hiragana = 0x1001125;

/**
  * @default 0x01001126
  * @constant
  * @memberOf Qt
  * @name Key_Katakana
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Katakana = 0x1001126;

/**
  * @default 0x01001127
  * @constant
  * @memberOf Qt
  * @name Key_Hiragana_Katakana
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Hiragana_Katakana = 0x1001127;

/**
  * @default 0x01001128
  * @constant
  * @memberOf Qt
  * @name Key_Zenkaku
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Zenkaku = 0x1001128;

/**
  * @default 0x01001129
  * @constant
  * @memberOf Qt
  * @name Key_Hankaku
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Hankaku = 0x1001129;

/**
  * @default 0x0100112a
  * @constant
  * @memberOf Qt
  * @name Key_Zenkaku_Hankaku
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Zenkaku_Hankaku = 0x100112a;

/**
  * @default 0x0100112b
  * @constant
  * @memberOf Qt
  * @name Key_Touroku
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Touroku = 0x100112b;

/**
  * @default 0x0100112c
  * @constant
  * @memberOf Qt
  * @name Key_Massyo
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Massyo = 0x100112c;

/**
  * @default 0x0100112d
  * @constant
  * @memberOf Qt
  * @name Key_Kana_Lock
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Kana_Lock = 0x100112d;

/**
  * @default 0x0100112e
  * @constant
  * @memberOf Qt
  * @name Key_Kana_Shift
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Kana_Shift = 0x100112e;

/**
  * @default 0x0100112f
  * @constant
  * @memberOf Qt
  * @name Key_Eisu_Shift
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Eisu_Shift = 0x100112f;

/**
  * @default 0x01001130
  * @constant
  * @memberOf Qt
  * @name Key_Eisu_toggle
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Eisu_toggle = 0x1001130;

/**
  * @default 0x01001131
  * @constant
  * @memberOf Qt
  * @name Key_Hangul
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Hangul = 0x1001131;

/**
  * @default 0x01001132
  * @constant
  * @memberOf Qt
  * @name Key_Hangul_Start
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Hangul_Start = 0x1001132;

/**
  * @default 0x01001133
  * @constant
  * @memberOf Qt
  * @name Key_Hangul_End
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Hangul_End = 0x1001133;

/**
  * @default 0x01001134
  * @constant
  * @memberOf Qt
  * @name Key_Hangul_Hanja
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Hangul_Hanja = 0x1001134;

/**
  * @default 0x01001135
  * @constant
  * @memberOf Qt
  * @name Key_Hangul_Jamo
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Hangul_Jamo = 0x1001135;

/**
  * @default 0x01001136
  * @constant
  * @memberOf Qt
  * @name Key_Hangul_Romaja
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Hangul_Romaja = 0x1001136;

/**
  * @default 0x01001137
  * @constant
  * @memberOf Qt
  * @name Key_Codeinput
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Codeinput = 0x1001137;

/**
  * @default 0x01001138
  * @constant
  * @memberOf Qt
  * @name Key_Hangul_Jeonja
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Hangul_Jeonja = 0x1001138;

/**
  * @default 0x01001139
  * @constant
  * @memberOf Qt
  * @name Key_Hangul_Banja
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Hangul_Banja = 0x1001139;

/**
  * @default 0x0100113a
  * @constant
  * @memberOf Qt
  * @name Key_Hangul_PreHanja
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Hangul_PreHanja = 0x100113a;

/**
  * @default 0x0100113b
  * @constant
  * @memberOf Qt
  * @name Key_Hangul_PostHanja
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Hangul_PostHanja = 0x100113b;

/**
  * @default 0x0100113c
  * @constant
  * @memberOf Qt
  * @name Key_SingleCandidate
  * @see Qt#Key
  * @type Number
  */
Qt.Key_SingleCandidate = 0x100113c;

/**
  * @default 0x0100113d
  * @constant
  * @memberOf Qt
  * @name Key_MultipleCandidate
  * @see Qt#Key
  * @type Number
  */
Qt.Key_MultipleCandidate = 0x100113d;

/**
  * @default 0x0100113e
  * @constant
  * @memberOf Qt
  * @name Key_PreviousCandidate
  * @see Qt#Key
  * @type Number
  */
Qt.Key_PreviousCandidate = 0x100113e;

/**
  * @default 0x0100113f
  * @constant
  * @memberOf Qt
  * @name Key_Hangul_Special
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Hangul_Special = 0x100113f;

/**
  * @default 0x0100117e
  * @constant
  * @memberOf Qt
  * @name Key_Mode_switch
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Mode_switch = 0x100117e;

/**
  * @default 0x01001250
  * @constant
  * @memberOf Qt
  * @name Key_Dead_Grave
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Dead_Grave = 0x1001250;

/**
  * @default 0x01001251
  * @constant
  * @memberOf Qt
  * @name Key_Dead_Acute
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Dead_Acute = 0x1001251;

/**
  * @default 0x01001252
  * @constant
  * @memberOf Qt
  * @name Key_Dead_Circumflex
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Dead_Circumflex = 0x1001252;

/**
  * @default 0x01001253
  * @constant
  * @memberOf Qt
  * @name Key_Dead_Tilde
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Dead_Tilde = 0x1001253;

/**
  * @default 0x01001254
  * @constant
  * @memberOf Qt
  * @name Key_Dead_Macron
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Dead_Macron = 0x1001254;

/**
  * @default 0x01001255
  * @constant
  * @memberOf Qt
  * @name Key_Dead_Breve
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Dead_Breve = 0x1001255;

/**
  * @default 0x01001256
  * @constant
  * @memberOf Qt
  * @name Key_Dead_Abovedot
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Dead_Abovedot = 0x1001256;

/**
  * @default 0x01001257
  * @constant
  * @memberOf Qt
  * @name Key_Dead_Diaeresis
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Dead_Diaeresis = 0x1001257;

/**
  * @default 0x01001258
  * @constant
  * @memberOf Qt
  * @name Key_Dead_Abovering
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Dead_Abovering = 0x1001258;

/**
  * @default 0x01001259
  * @constant
  * @memberOf Qt
  * @name Key_Dead_Doubleacute
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Dead_Doubleacute = 0x1001259;

/**
  * @default 0x0100125a
  * @constant
  * @memberOf Qt
  * @name Key_Dead_Caron
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Dead_Caron = 0x100125a;

/**
  * @default 0x0100125b
  * @constant
  * @memberOf Qt
  * @name Key_Dead_Cedilla
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Dead_Cedilla = 0x100125b;

/**
  * @default 0x0100125c
  * @constant
  * @memberOf Qt
  * @name Key_Dead_Ogonek
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Dead_Ogonek = 0x100125c;

/**
  * @default 0x0100125d
  * @constant
  * @memberOf Qt
  * @name Key_Dead_Iota
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Dead_Iota = 0x100125d;

/**
  * @default 0x0100125e
  * @constant
  * @memberOf Qt
  * @name Key_Dead_Voiced_Sound
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Dead_Voiced_Sound = 0x100125e;

/**
  * @default 0x0100125f
  * @constant
  * @memberOf Qt
  * @name Key_Dead_Semivoiced_Sound
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Dead_Semivoiced_Sound = 0x100125f;

/**
  * @default 0x01001260
  * @constant
  * @memberOf Qt
  * @name Key_Dead_Belowdot
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Dead_Belowdot = 0x1001260;

/**
  * @default 0x01001261
  * @constant
  * @memberOf Qt
  * @name Key_Dead_Hook
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Dead_Hook = 0x1001261;

/**
  * @default 0x01001262
  * @constant
  * @memberOf Qt
  * @name Key_Dead_Horn
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Dead_Horn = 0x1001262;

/**
  * @default 0x0100ffff
  * @constant
  * @memberOf Qt
  * @name Key_MediaLast
  * @see Qt#Key
  * @type Number
  */
Qt.Key_MediaLast = 0x100ffff;

/**
  * @default 0x01010000
  * @constant
  * @memberOf Qt
  * @name Key_Select
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Select = 0x1010000;

/**
  * @default 0x01010001
  * @constant
  * @memberOf Qt
  * @name Key_Yes
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Yes = 0x1010001;

/**
  * @default 0x01010002
  * @constant
  * @memberOf Qt
  * @name Key_No
  * @see Qt#Key
  * @type Number
  */
Qt.Key_No = 0x1010002;

/**
  * @default 0x01020001
  * @constant
  * @memberOf Qt
  * @name Key_Cancel
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Cancel = 0x1020001;

/**
  * @default 0x01020002
  * @constant
  * @memberOf Qt
  * @name Key_Printer
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Printer = 0x1020002;

/**
  * @default 0x01020003
  * @constant
  * @memberOf Qt
  * @name Key_Execute
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Execute = 0x1020003;

/**
  * @default 0x01020004
  * @constant
  * @memberOf Qt
  * @name Key_Sleep
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Sleep = 0x1020004;

/**
  * @default 0x01020005
  * @constant
  * @memberOf Qt
  * @name Key_Play
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Play = 0x1020005;

/**
  * @default 0x01020006
  * @constant
  * @memberOf Qt
  * @name Key_Zoom
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Zoom = 0x1020006;

/**
  * @default 0x01100000
  * @constant
  * @memberOf Qt
  * @name Key_Context1
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Context1 = 0x1100000;

/**
  * @default 0x01100001
  * @constant
  * @memberOf Qt
  * @name Key_Context2
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Context2 = 0x1100001;

/**
  * @default 0x01100002
  * @constant
  * @memberOf Qt
  * @name Key_Context3
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Context3 = 0x1100002;

/**
  * @default 0x01100003
  * @constant
  * @memberOf Qt
  * @name Key_Context4
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Context4 = 0x1100003;

/**
  * @default 0x01100004
  * @constant
  * @memberOf Qt
  * @name Key_Call
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Call = 0x1100004;

/**
  * @default 0x01100005
  * @constant
  * @memberOf Qt
  * @name Key_Hangup
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Hangup = 0x1100005;

/**
  * @default 0x01100006
  * @constant
  * @memberOf Qt
  * @name Key_Flip
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Flip = 0x1100006;

/**
  * @default 0x01100007
  * @constant
  * @memberOf Qt
  * @name Key_ToggleCallHangup
  * @see Qt#Key
  * @type Number
  */
Qt.Key_ToggleCallHangup = 0x1100007;

/**
  * @default 0x01100008
  * @constant
  * @memberOf Qt
  * @name Key_VoiceDial
  * @see Qt#Key
  * @type Number
  */
Qt.Key_VoiceDial = 0x1100008;

/**
  * @default 0x01100009
  * @constant
  * @memberOf Qt
  * @name Key_LastNumberRedial
  * @see Qt#Key
  * @type Number
  */
Qt.Key_LastNumberRedial = 0x1100009;

/**
  * @default 0x01100020
  * @constant
  * @memberOf Qt
  * @name Key_Camera
  * @see Qt#Key
  * @type Number
  */
Qt.Key_Camera = 0x1100020;

/**
  * @default 0x01100021
  * @constant
  * @memberOf Qt
  * @name Key_CameraFocus
  * @see Qt#Key
  * @type Number
  */
Qt.Key_CameraFocus = 0x1100021;

/**
  * @default 0x01ffffff
  * @constant
  * @memberOf Qt
  * @name Key_unknown
  * @see Qt#Key
  * @type Number
  */
Qt.Key_unknown = 0x1ffffff;

/**
  * @constructor 
  * @memberOf Qt
  * @name Key
  */
Qt.Key = function(value){;};



/**
  * @default 0
  * @constant
  * @memberOf Qt
  * @name AA_ImmediateWidgetCreation
  * @see Qt#ApplicationAttribute
  * @type Number
  */
Qt.AA_ImmediateWidgetCreation = 0x0;

/**
  * @default 1
  * @constant
  * @memberOf Qt
  * @name AA_MSWindowsUseDirect3DByDefault
  * @see Qt#ApplicationAttribute
  * @type Number
  */
Qt.AA_MSWindowsUseDirect3DByDefault = 0x1;

/**
  * @default 2
  * @constant
  * @memberOf Qt
  * @name AA_DontShowIconsInMenus
  * @see Qt#ApplicationAttribute
  * @type Number
  */
Qt.AA_DontShowIconsInMenus = 0x2;

/**
  * @default 3
  * @constant
  * @memberOf Qt
  * @name AA_NativeWindows
  * @see Qt#ApplicationAttribute
  * @type Number
  */
Qt.AA_NativeWindows = 0x3;

/**
  * @default 4
  * @constant
  * @memberOf Qt
  * @name AA_DontCreateNativeWidgetSiblings
  * @see Qt#ApplicationAttribute
  * @type Number
  */
Qt.AA_DontCreateNativeWidgetSiblings = 0x4;

/**
  * @default 5
  * @constant
  * @memberOf Qt
  * @name AA_MacPluginApplication
  * @see Qt#ApplicationAttribute
  * @type Number
  */
Qt.AA_MacPluginApplication = 0x5;

/**
  * @default 6
  * @constant
  * @memberOf Qt
  * @name AA_DontUseNativeMenuBar
  * @see Qt#ApplicationAttribute
  * @type Number
  */
Qt.AA_DontUseNativeMenuBar = 0x6;

/**
  * @default 7
  * @constant
  * @memberOf Qt
  * @name AA_MacDontSwapCtrlAndMeta
  * @see Qt#ApplicationAttribute
  * @type Number
  */
Qt.AA_MacDontSwapCtrlAndMeta = 0x7;

/**
  * @default 8
  * @constant
  * @memberOf Qt
  * @name AA_S60DontConstructApplicationPanes
  * @see Qt#ApplicationAttribute
  * @type Number
  */
Qt.AA_S60DontConstructApplicationPanes = 0x8;

/**
  * @default 9
  * @constant
  * @memberOf Qt
  * @name AA_S60DisablePartialScreenInputMode
  * @see Qt#ApplicationAttribute
  * @type Number
  */
Qt.AA_S60DisablePartialScreenInputMode = 0x9;

/**
  * @default 10
  * @constant
  * @memberOf Qt
  * @name AA_X11InitThreads
  * @see Qt#ApplicationAttribute
  * @type Number
  */
Qt.AA_X11InitThreads = 0xa;

/**
  * @default 11
  * @constant
  * @memberOf Qt
  * @name AA_CaptureMultimediaKeys
  * @see Qt#ApplicationAttribute
  * @type Number
  */
Qt.AA_CaptureMultimediaKeys = 0xb;

/**
  * @default 0xc
  * @constant
  * @memberOf Qt
  * @name AA_AttributeCount
  * @see Qt#ApplicationAttribute
  * @type Number
  */
Qt.AA_AttributeCount = 0xc;

/**
  * @constructor 
  * @memberOf Qt
  * @name ApplicationAttribute
  */
Qt.ApplicationAttribute = function(value){;};



/**
  * @default 0x0100
  * @constant
  * @memberOf Qt
  * @name TextSingleLine
  * @see Qt#TextFlag
  * @type Number
  */
Qt.TextSingleLine = 0x100;

/**
  * @default 0x0200
  * @constant
  * @memberOf Qt
  * @name TextDontClip
  * @see Qt#TextFlag
  * @type Number
  */
Qt.TextDontClip = 0x200;

/**
  * @default 0x0400
  * @constant
  * @memberOf Qt
  * @name TextExpandTabs
  * @see Qt#TextFlag
  * @type Number
  */
Qt.TextExpandTabs = 0x400;

/**
  * @default 0x0800
  * @constant
  * @memberOf Qt
  * @name TextShowMnemonic
  * @see Qt#TextFlag
  * @type Number
  */
Qt.TextShowMnemonic = 0x800;

/**
  * @default 0x1000
  * @constant
  * @memberOf Qt
  * @name TextWordWrap
  * @see Qt#TextFlag
  * @type Number
  */
Qt.TextWordWrap = 0x1000;

/**
  * @default 0x2000
  * @constant
  * @memberOf Qt
  * @name TextWrapAnywhere
  * @see Qt#TextFlag
  * @type Number
  */
Qt.TextWrapAnywhere = 0x2000;

/**
  * @default 0x4000
  * @constant
  * @memberOf Qt
  * @name TextDontPrint
  * @see Qt#TextFlag
  * @type Number
  */
Qt.TextDontPrint = 0x4000;

/**
  * @default 0x8000
  * @constant
  * @memberOf Qt
  * @name TextHideMnemonic
  * @see Qt#TextFlag
  * @type Number
  */
Qt.TextHideMnemonic = 0x8000;

/**
  * @default 0x10000
  * @constant
  * @memberOf Qt
  * @name TextJustificationForced
  * @see Qt#TextFlag
  * @type Number
  */
Qt.TextJustificationForced = 0x10000;

/**
  * @default 0x20000
  * @constant
  * @memberOf Qt
  * @name TextForceLeftToRight
  * @see Qt#TextFlag
  * @type Number
  */
Qt.TextForceLeftToRight = 0x20000;

/**
  * @default 0x40000
  * @constant
  * @memberOf Qt
  * @name TextForceRightToLeft
  * @see Qt#TextFlag
  * @type Number
  */
Qt.TextForceRightToLeft = 0x40000;

/**
  * @default 0x80000
  * @constant
  * @memberOf Qt
  * @name TextLongestVariant
  * @see Qt#TextFlag
  * @type Number
  */
Qt.TextLongestVariant = 0x80000;

/**
  * @default 0x100000
  * @constant
  * @memberOf Qt
  * @name TextBypassShaping
  * @see Qt#TextFlag
  * @type Number
  */
Qt.TextBypassShaping = 0x100000;

/**
  * @default 0x08000000
  * @constant
  * @memberOf Qt
  * @name TextIncludeTrailingSpaces
  * @see Qt#TextFlag
  * @type Number
  */
Qt.TextIncludeTrailingSpaces = 0x8000000;

/**
  * @constructor 
  * @memberOf Qt
  * @name TextFlag
  */
Qt.TextFlag = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf Qt
  * @name NoBrush
  * @see Qt#BrushStyle
  * @type Number
  */
Qt.NoBrush = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf Qt
  * @name SolidPattern
  * @see Qt#BrushStyle
  * @type Number
  */
Qt.SolidPattern = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf Qt
  * @name Dense1Pattern
  * @see Qt#BrushStyle
  * @type Number
  */
Qt.Dense1Pattern = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf Qt
  * @name Dense2Pattern
  * @see Qt#BrushStyle
  * @type Number
  */
Qt.Dense2Pattern = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf Qt
  * @name Dense3Pattern
  * @see Qt#BrushStyle
  * @type Number
  */
Qt.Dense3Pattern = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf Qt
  * @name Dense4Pattern
  * @see Qt#BrushStyle
  * @type Number
  */
Qt.Dense4Pattern = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf Qt
  * @name Dense5Pattern
  * @see Qt#BrushStyle
  * @type Number
  */
Qt.Dense5Pattern = 0x6;

/**
  * @default 0x7
  * @constant
  * @memberOf Qt
  * @name Dense6Pattern
  * @see Qt#BrushStyle
  * @type Number
  */
Qt.Dense6Pattern = 0x7;

/**
  * @default 0x8
  * @constant
  * @memberOf Qt
  * @name Dense7Pattern
  * @see Qt#BrushStyle
  * @type Number
  */
Qt.Dense7Pattern = 0x8;

/**
  * @default 0x9
  * @constant
  * @memberOf Qt
  * @name HorPattern
  * @see Qt#BrushStyle
  * @type Number
  */
Qt.HorPattern = 0x9;

/**
  * @default 0xa
  * @constant
  * @memberOf Qt
  * @name VerPattern
  * @see Qt#BrushStyle
  * @type Number
  */
Qt.VerPattern = 0xa;

/**
  * @default 0xb
  * @constant
  * @memberOf Qt
  * @name CrossPattern
  * @see Qt#BrushStyle
  * @type Number
  */
Qt.CrossPattern = 0xb;

/**
  * @default 0xc
  * @constant
  * @memberOf Qt
  * @name BDiagPattern
  * @see Qt#BrushStyle
  * @type Number
  */
Qt.BDiagPattern = 0xc;

/**
  * @default 0xd
  * @constant
  * @memberOf Qt
  * @name FDiagPattern
  * @see Qt#BrushStyle
  * @type Number
  */
Qt.FDiagPattern = 0xd;

/**
  * @default 0xe
  * @constant
  * @memberOf Qt
  * @name DiagCrossPattern
  * @see Qt#BrushStyle
  * @type Number
  */
Qt.DiagCrossPattern = 0xe;

/**
  * @default 0xf
  * @constant
  * @memberOf Qt
  * @name LinearGradientPattern
  * @see Qt#BrushStyle
  * @type Number
  */
Qt.LinearGradientPattern = 0xf;

/**
  * @default 0x10
  * @constant
  * @memberOf Qt
  * @name RadialGradientPattern
  * @see Qt#BrushStyle
  * @type Number
  */
Qt.RadialGradientPattern = 0x10;

/**
  * @default 0x11
  * @constant
  * @memberOf Qt
  * @name ConicalGradientPattern
  * @see Qt#BrushStyle
  * @type Number
  */
Qt.ConicalGradientPattern = 0x11;

/**
  * @default 24
  * @constant
  * @memberOf Qt
  * @name TexturePattern
  * @see Qt#BrushStyle
  * @type Number
  */
Qt.TexturePattern = 0x18;

/**
  * @constructor 
  * @memberOf Qt
  * @name BrushStyle
  */
Qt.BrushStyle = function(value){;};



/**
  * @default 0
  * @constant
  * @memberOf Qt
  * @name WA_Disabled
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_Disabled = 0x0;

/**
  * @default 1
  * @constant
  * @memberOf Qt
  * @name WA_UnderMouse
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_UnderMouse = 0x1;

/**
  * @default 2
  * @constant
  * @memberOf Qt
  * @name WA_MouseTracking
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_MouseTracking = 0x2;

/**
  * @default 3
  * @constant
  * @memberOf Qt
  * @name WA_ContentsPropagated
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_ContentsPropagated = 0x3;

/**
  * @default 4
  * @constant
  * @memberOf Qt
  * @name WA_OpaquePaintEvent
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_OpaquePaintEvent = 0x4;

/**
  * @default 5
  * @constant
  * @memberOf Qt
  * @name WA_StaticContents
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_StaticContents = 0x5;

/**
  * @default 7
  * @constant
  * @memberOf Qt
  * @name WA_LaidOut
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_LaidOut = 0x7;

/**
  * @default 8
  * @constant
  * @memberOf Qt
  * @name WA_PaintOnScreen
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_PaintOnScreen = 0x8;

/**
  * @default 9
  * @constant
  * @memberOf Qt
  * @name WA_NoSystemBackground
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_NoSystemBackground = 0x9;

/**
  * @default 10
  * @constant
  * @memberOf Qt
  * @name WA_UpdatesDisabled
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_UpdatesDisabled = 0xa;

/**
  * @default 11
  * @constant
  * @memberOf Qt
  * @name WA_Mapped
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_Mapped = 0xb;

/**
  * @default 12
  * @constant
  * @memberOf Qt
  * @name WA_MacNoClickThrough
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_MacNoClickThrough = 0xc;

/**
  * @default 13
  * @constant
  * @memberOf Qt
  * @name WA_PaintOutsidePaintEvent
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_PaintOutsidePaintEvent = 0xd;

/**
  * @default 14
  * @constant
  * @memberOf Qt
  * @name WA_InputMethodEnabled
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_InputMethodEnabled = 0xe;

/**
  * @default 15
  * @constant
  * @memberOf Qt
  * @name WA_WState_Visible
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_WState_Visible = 0xf;

/**
  * @default 16
  * @constant
  * @memberOf Qt
  * @name WA_WState_Hidden
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_WState_Hidden = 0x10;

/**
  * @default 32
  * @constant
  * @memberOf Qt
  * @name WA_ForceDisabled
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_ForceDisabled = 0x20;

/**
  * @default 33
  * @constant
  * @memberOf Qt
  * @name WA_KeyCompression
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_KeyCompression = 0x21;

/**
  * @default 34
  * @constant
  * @memberOf Qt
  * @name WA_PendingMoveEvent
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_PendingMoveEvent = 0x22;

/**
  * @default 35
  * @constant
  * @memberOf Qt
  * @name WA_PendingResizeEvent
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_PendingResizeEvent = 0x23;

/**
  * @default 36
  * @constant
  * @memberOf Qt
  * @name WA_SetPalette
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_SetPalette = 0x24;

/**
  * @default 37
  * @constant
  * @memberOf Qt
  * @name WA_SetFont
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_SetFont = 0x25;

/**
  * @default 38
  * @constant
  * @memberOf Qt
  * @name WA_SetCursor
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_SetCursor = 0x26;

/**
  * @default 39
  * @constant
  * @memberOf Qt
  * @name WA_NoChildEventsFromChildren
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_NoChildEventsFromChildren = 0x27;

/**
  * @default 41
  * @constant
  * @memberOf Qt
  * @name WA_WindowModified
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_WindowModified = 0x29;

/**
  * @default 42
  * @constant
  * @memberOf Qt
  * @name WA_Resized
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_Resized = 0x2a;

/**
  * @default 43
  * @constant
  * @memberOf Qt
  * @name WA_Moved
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_Moved = 0x2b;

/**
  * @default 44
  * @constant
  * @memberOf Qt
  * @name WA_PendingUpdate
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_PendingUpdate = 0x2c;

/**
  * @default 45
  * @constant
  * @memberOf Qt
  * @name WA_InvalidSize
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_InvalidSize = 0x2d;

/**
  * @default 46
  * @constant
  * @memberOf Qt
  * @name WA_MacBrushedMetal
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_MacBrushedMetal = 0x2e;

/**
  * @default 47
  * @constant
  * @memberOf Qt
  * @name WA_CustomWhatsThis
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_CustomWhatsThis = 0x2f;

/**
  * @default 48
  * @constant
  * @memberOf Qt
  * @name WA_LayoutOnEntireRect
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_LayoutOnEntireRect = 0x30;

/**
  * @default 49
  * @constant
  * @memberOf Qt
  * @name WA_OutsideWSRange
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_OutsideWSRange = 0x31;

/**
  * @default 50
  * @constant
  * @memberOf Qt
  * @name WA_GrabbedShortcut
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_GrabbedShortcut = 0x32;

/**
  * @default 51
  * @constant
  * @memberOf Qt
  * @name WA_TransparentForMouseEvents
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_TransparentForMouseEvents = 0x33;

/**
  * @default 52
  * @constant
  * @memberOf Qt
  * @name WA_PaintUnclipped
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_PaintUnclipped = 0x34;

/**
  * @default 53
  * @constant
  * @memberOf Qt
  * @name WA_SetWindowIcon
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_SetWindowIcon = 0x35;

/**
  * @default 54
  * @constant
  * @memberOf Qt
  * @name WA_NoMouseReplay
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_NoMouseReplay = 0x36;

/**
  * @default 55
  * @constant
  * @memberOf Qt
  * @name WA_DeleteOnClose
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_DeleteOnClose = 0x37;

/**
  * @default 56
  * @constant
  * @memberOf Qt
  * @name WA_RightToLeft
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_RightToLeft = 0x38;

/**
  * @default 57
  * @constant
  * @memberOf Qt
  * @name WA_SetLayoutDirection
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_SetLayoutDirection = 0x39;

/**
  * @default 58
  * @constant
  * @memberOf Qt
  * @name WA_NoChildEventsForParent
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_NoChildEventsForParent = 0x3a;

/**
  * @default 59
  * @constant
  * @memberOf Qt
  * @name WA_ForceUpdatesDisabled
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_ForceUpdatesDisabled = 0x3b;

/**
  * @default 60
  * @constant
  * @memberOf Qt
  * @name WA_WState_Created
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_WState_Created = 0x3c;

/**
  * @default 61
  * @constant
  * @memberOf Qt
  * @name WA_WState_CompressKeys
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_WState_CompressKeys = 0x3d;

/**
  * @default 62
  * @constant
  * @memberOf Qt
  * @name WA_WState_InPaintEvent
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_WState_InPaintEvent = 0x3e;

/**
  * @default 63
  * @constant
  * @memberOf Qt
  * @name WA_WState_Reparented
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_WState_Reparented = 0x3f;

/**
  * @default 64
  * @constant
  * @memberOf Qt
  * @name WA_WState_ConfigPending
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_WState_ConfigPending = 0x40;

/**
  * @default 66
  * @constant
  * @memberOf Qt
  * @name WA_WState_Polished
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_WState_Polished = 0x42;

/**
  * @default 67
  * @constant
  * @memberOf Qt
  * @name WA_WState_DND
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_WState_DND = 0x43;

/**
  * @default 68
  * @constant
  * @memberOf Qt
  * @name WA_WState_OwnSizePolicy
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_WState_OwnSizePolicy = 0x44;

/**
  * @default 69
  * @constant
  * @memberOf Qt
  * @name WA_WState_ExplicitShowHide
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_WState_ExplicitShowHide = 0x45;

/**
  * @default 70
  * @constant
  * @memberOf Qt
  * @name WA_ShowModal
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_ShowModal = 0x46;

/**
  * @default 71
  * @constant
  * @memberOf Qt
  * @name WA_MouseNoMask
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_MouseNoMask = 0x47;

/**
  * @default 72
  * @constant
  * @memberOf Qt
  * @name WA_GroupLeader
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_GroupLeader = 0x48;

/**
  * @default 73
  * @constant
  * @memberOf Qt
  * @name WA_NoMousePropagation
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_NoMousePropagation = 0x49;

/**
  * @default 74
  * @constant
  * @memberOf Qt
  * @name WA_Hover
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_Hover = 0x4a;

/**
  * @default 75
  * @constant
  * @memberOf Qt
  * @name WA_InputMethodTransparent
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_InputMethodTransparent = 0x4b;

/**
  * @default 76
  * @constant
  * @memberOf Qt
  * @name WA_QuitOnClose
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_QuitOnClose = 0x4c;

/**
  * @default 77
  * @constant
  * @memberOf Qt
  * @name WA_KeyboardFocusChange
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_KeyboardFocusChange = 0x4d;

/**
  * @default 78
  * @constant
  * @memberOf Qt
  * @name WA_AcceptDrops
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_AcceptDrops = 0x4e;

/**
  * @default 79
  * @constant
  * @memberOf Qt
  * @name WA_DropSiteRegistered
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_DropSiteRegistered = 0x4f;

/**
  * @default 80
  * @constant
  * @memberOf Qt
  * @name WA_WindowPropagation
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_WindowPropagation = 0x50;

/**
  * @default 81
  * @constant
  * @memberOf Qt
  * @name WA_NoX11EventCompression
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_NoX11EventCompression = 0x51;

/**
  * @default 82
  * @constant
  * @memberOf Qt
  * @name WA_TintedBackground
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_TintedBackground = 0x52;

/**
  * @default 83
  * @constant
  * @memberOf Qt
  * @name WA_X11OpenGLOverlay
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_X11OpenGLOverlay = 0x53;

/**
  * @default 84
  * @constant
  * @memberOf Qt
  * @name WA_AlwaysShowToolTips
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_AlwaysShowToolTips = 0x54;

/**
  * @default 85
  * @constant
  * @memberOf Qt
  * @name WA_MacOpaqueSizeGrip
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_MacOpaqueSizeGrip = 0x55;

/**
  * @default 86
  * @constant
  * @memberOf Qt
  * @name WA_SetStyle
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_SetStyle = 0x56;

/**
  * @default 87
  * @constant
  * @memberOf Qt
  * @name WA_SetLocale
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_SetLocale = 0x57;

/**
  * @default 88
  * @constant
  * @memberOf Qt
  * @name WA_MacShowFocusRect
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_MacShowFocusRect = 0x58;

/**
  * @default 89
  * @constant
  * @memberOf Qt
  * @name WA_MacNormalSize
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_MacNormalSize = 0x59;

/**
  * @default 90
  * @constant
  * @memberOf Qt
  * @name WA_MacSmallSize
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_MacSmallSize = 0x5a;

/**
  * @default 91
  * @constant
  * @memberOf Qt
  * @name WA_MacMiniSize
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_MacMiniSize = 0x5b;

/**
  * @default 92
  * @constant
  * @memberOf Qt
  * @name WA_LayoutUsesWidgetRect
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_LayoutUsesWidgetRect = 0x5c;

/**
  * @default 93
  * @constant
  * @memberOf Qt
  * @name WA_StyledBackground
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_StyledBackground = 0x5d;

/**
  * @default 94
  * @constant
  * @memberOf Qt
  * @name WA_MSWindowsUseDirect3D
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_MSWindowsUseDirect3D = 0x5e;

/**
  * @default 95
  * @constant
  * @memberOf Qt
  * @name WA_CanHostQMdiSubWindowTitleBar
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_CanHostQMdiSubWindowTitleBar = 0x5f;

/**
  * @default 96
  * @constant
  * @memberOf Qt
  * @name WA_MacAlwaysShowToolWindow
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_MacAlwaysShowToolWindow = 0x60;

/**
  * @default 97
  * @constant
  * @memberOf Qt
  * @name WA_StyleSheet
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_StyleSheet = 0x61;

/**
  * @default 98
  * @constant
  * @memberOf Qt
  * @name WA_ShowWithoutActivating
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_ShowWithoutActivating = 0x62;

/**
  * @default 99
  * @constant
  * @memberOf Qt
  * @name WA_X11BypassTransientForHint
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_X11BypassTransientForHint = 0x63;

/**
  * @default 100
  * @constant
  * @memberOf Qt
  * @name WA_NativeWindow
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_NativeWindow = 0x64;

/**
  * @default 101
  * @constant
  * @memberOf Qt
  * @name WA_DontCreateNativeAncestors
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_DontCreateNativeAncestors = 0x65;

/**
  * @default 102
  * @constant
  * @memberOf Qt
  * @name WA_MacVariableSize
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_MacVariableSize = 0x66;

/**
  * @default 103
  * @constant
  * @memberOf Qt
  * @name WA_DontShowOnScreen
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_DontShowOnScreen = 0x67;

/**
  * @default 104
  * @constant
  * @memberOf Qt
  * @name WA_X11NetWmWindowTypeDesktop
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_X11NetWmWindowTypeDesktop = 0x68;

/**
  * @default 105
  * @constant
  * @memberOf Qt
  * @name WA_X11NetWmWindowTypeDock
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_X11NetWmWindowTypeDock = 0x69;

/**
  * @default 106
  * @constant
  * @memberOf Qt
  * @name WA_X11NetWmWindowTypeToolBar
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_X11NetWmWindowTypeToolBar = 0x6a;

/**
  * @default 107
  * @constant
  * @memberOf Qt
  * @name WA_X11NetWmWindowTypeMenu
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_X11NetWmWindowTypeMenu = 0x6b;

/**
  * @default 108
  * @constant
  * @memberOf Qt
  * @name WA_X11NetWmWindowTypeUtility
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_X11NetWmWindowTypeUtility = 0x6c;

/**
  * @default 109
  * @constant
  * @memberOf Qt
  * @name WA_X11NetWmWindowTypeSplash
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_X11NetWmWindowTypeSplash = 0x6d;

/**
  * @default 110
  * @constant
  * @memberOf Qt
  * @name WA_X11NetWmWindowTypeDialog
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_X11NetWmWindowTypeDialog = 0x6e;

/**
  * @default 111
  * @constant
  * @memberOf Qt
  * @name WA_X11NetWmWindowTypeDropDownMenu
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_X11NetWmWindowTypeDropDownMenu = 0x6f;

/**
  * @default 112
  * @constant
  * @memberOf Qt
  * @name WA_X11NetWmWindowTypePopupMenu
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_X11NetWmWindowTypePopupMenu = 0x70;

/**
  * @default 113
  * @constant
  * @memberOf Qt
  * @name WA_X11NetWmWindowTypeToolTip
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_X11NetWmWindowTypeToolTip = 0x71;

/**
  * @default 114
  * @constant
  * @memberOf Qt
  * @name WA_X11NetWmWindowTypeNotification
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_X11NetWmWindowTypeNotification = 0x72;

/**
  * @default 115
  * @constant
  * @memberOf Qt
  * @name WA_X11NetWmWindowTypeCombo
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_X11NetWmWindowTypeCombo = 0x73;

/**
  * @default 116
  * @constant
  * @memberOf Qt
  * @name WA_X11NetWmWindowTypeDND
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_X11NetWmWindowTypeDND = 0x74;

/**
  * @default 117
  * @constant
  * @memberOf Qt
  * @name WA_MacFrameworkScaled
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_MacFrameworkScaled = 0x75;

/**
  * @default 118
  * @constant
  * @memberOf Qt
  * @name WA_SetWindowModality
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_SetWindowModality = 0x76;

/**
  * @default 119
  * @constant
  * @memberOf Qt
  * @name WA_WState_WindowOpacitySet
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_WState_WindowOpacitySet = 0x77;

/**
  * @default 120
  * @constant
  * @memberOf Qt
  * @name WA_TranslucentBackground
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_TranslucentBackground = 0x78;

/**
  * @default 121
  * @constant
  * @memberOf Qt
  * @name WA_AcceptTouchEvents
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_AcceptTouchEvents = 0x79;

/**
  * @default 122
  * @constant
  * @memberOf Qt
  * @name WA_WState_AcceptedTouchBeginEvent
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_WState_AcceptedTouchBeginEvent = 0x7a;

/**
  * @default 123
  * @constant
  * @memberOf Qt
  * @name WA_TouchPadAcceptSingleTouchEvents
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_TouchPadAcceptSingleTouchEvents = 0x7b;

/**
  * @default 124
  * @constant
  * @memberOf Qt
  * @name WA_MergeSoftkeys
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_MergeSoftkeys = 0x7c;

/**
  * @default 125
  * @constant
  * @memberOf Qt
  * @name WA_MergeSoftkeysRecursively
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_MergeSoftkeysRecursively = 0x7d;

/**
  * @default 128
  * @constant
  * @memberOf Qt
  * @name WA_LockPortraitOrientation
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_LockPortraitOrientation = 0x80;

/**
  * @default 129
  * @constant
  * @memberOf Qt
  * @name WA_LockLandscapeOrientation
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_LockLandscapeOrientation = 0x81;

/**
  * @default 130
  * @constant
  * @memberOf Qt
  * @name WA_AutoOrientation
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_AutoOrientation = 0x82;

/**
  * @default 132
  * @constant
  * @memberOf Qt
  * @name WA_X11DoNotAcceptFocus
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_X11DoNotAcceptFocus = 0x84;

/**
  * @default 133
  * @constant
  * @memberOf Qt
  * @name WA_SymbianNoSystemRotation
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_SymbianNoSystemRotation = 0x85;

/**
  * @default 134
  * @constant
  * @memberOf Qt
  * @name WA_MacNoShadow
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_MacNoShadow = 0x86;

/**
  * @default 0x87
  * @constant
  * @memberOf Qt
  * @name WA_AttributeCount
  * @see Qt#WidgetAttribute
  * @type Number
  */
Qt.WA_AttributeCount = 0x87;

/**
  * @constructor 
  * @memberOf Qt
  * @name WidgetAttribute
  */
Qt.WidgetAttribute = function(value){;};



/**
  * @default 0x01
  * @constant
  * @memberOf Qt
  * @name TouchPointPressed
  * @see Qt#TouchPointStates
  * @see Qt#TouchPointState
  * @type Number
  */
Qt.TouchPointPressed = 0x1;

/**
  * @default 0x02
  * @constant
  * @memberOf Qt
  * @name TouchPointMoved
  * @see Qt#TouchPointStates
  * @see Qt#TouchPointState
  * @type Number
  */
Qt.TouchPointMoved = 0x2;

/**
  * @default 0x04
  * @constant
  * @memberOf Qt
  * @name TouchPointStationary
  * @see Qt#TouchPointStates
  * @see Qt#TouchPointState
  * @type Number
  */
Qt.TouchPointStationary = 0x4;

/**
  * @default 0x08
  * @constant
  * @memberOf Qt
  * @name TouchPointReleased
  * @see Qt#TouchPointStates
  * @see Qt#TouchPointState
  * @type Number
  */
Qt.TouchPointReleased = 0x8;

/**
  * @default 0x0f
  * @constant
  * @memberOf Qt
  * @name TouchPointStateMask
  * @see Qt#TouchPointStates
  * @see Qt#TouchPointState
  * @type Number
  */
Qt.TouchPointStateMask = 0xf;

/**
  * @default 0x10
  * @constant
  * @memberOf Qt
  * @name TouchPointPrimary
  * @see Qt#TouchPointStates
  * @see Qt#TouchPointState
  * @type Number
  */
Qt.TouchPointPrimary = 0x10;

/**
  * @constructor 
  * @memberOf Qt
  * @name TouchPointState
  */
Qt.TouchPointState = function(value){;};

/**
  * @constructor 
  * @memberOf Qt
  * @name TouchPointStates
  */
Qt.TouchPointStates = function(value1, value2 /*, ...*/){;};


/**
  * @default 0
  * @constant
  * @memberOf Qt
  * @name NoTextInteraction
  * @see Qt#TextInteractionFlags
  * @see Qt#TextInteractionFlag
  * @type Number
  */
Qt.NoTextInteraction = 0x0;

/**
  * @default 1
  * @constant
  * @memberOf Qt
  * @name TextSelectableByMouse
  * @see Qt#TextInteractionFlags
  * @see Qt#TextInteractionFlag
  * @type Number
  */
Qt.TextSelectableByMouse = 0x1;

/**
  * @default 2
  * @constant
  * @memberOf Qt
  * @name TextSelectableByKeyboard
  * @see Qt#TextInteractionFlags
  * @see Qt#TextInteractionFlag
  * @type Number
  */
Qt.TextSelectableByKeyboard = 0x2;

/**
  * @default 4
  * @constant
  * @memberOf Qt
  * @name LinksAccessibleByMouse
  * @see Qt#TextInteractionFlags
  * @see Qt#TextInteractionFlag
  * @type Number
  */
Qt.LinksAccessibleByMouse = 0x4;

/**
  * @default 8
  * @constant
  * @memberOf Qt
  * @name LinksAccessibleByKeyboard
  * @see Qt#TextInteractionFlags
  * @see Qt#TextInteractionFlag
  * @type Number
  */
Qt.LinksAccessibleByKeyboard = 0x8;

/**
  * @default TextSelectableByMouse|LinksAccessibleByMouse|LinksAccessibleByKeyboard
  * @constant
  * @memberOf Qt
  * @name TextBrowserInteraction
  * @see Qt#TextInteractionFlags
  * @see Qt#TextInteractionFlag
  * @type Number
  */
Qt.TextBrowserInteraction = 0xd;

/**
  * @default 16
  * @constant
  * @memberOf Qt
  * @name TextEditable
  * @see Qt#TextInteractionFlags
  * @see Qt#TextInteractionFlag
  * @type Number
  */
Qt.TextEditable = 0x10;

/**
  * @default TextSelectableByMouse|TextSelectableByKeyboard|TextEditable
  * @constant
  * @memberOf Qt
  * @name TextEditorInteraction
  * @see Qt#TextInteractionFlags
  * @see Qt#TextInteractionFlag
  * @type Number
  */
Qt.TextEditorInteraction = 0x13;

/**
  * @constructor 
  * @memberOf Qt
  * @name TextInteractionFlag
  */
Qt.TextInteractionFlag = function(value){;};

/**
  * @constructor 
  * @memberOf Qt
  * @name TextInteractionFlags
  */
Qt.TextInteractionFlags = function(value1, value2 /*, ...*/){;};


/**
  * @default 0x00000000
  * @constant
  * @memberOf Qt
  * @name NoButton
  * @see Qt#MouseButtons
  * @see Qt#MouseButton
  * @type Number
  */
Qt.NoButton = 0x0;

/**
  * @default 0x00000001
  * @constant
  * @memberOf Qt
  * @name LeftButton
  * @see Qt#MouseButtons
  * @see Qt#MouseButton
  * @type Number
  */
Qt.LeftButton = 0x1;

/**
  * @default 0x00000002
  * @constant
  * @memberOf Qt
  * @name RightButton
  * @see Qt#MouseButtons
  * @see Qt#MouseButton
  * @type Number
  */
Qt.RightButton = 0x2;

/**
  * @default 0x00000004
  * @constant
  * @memberOf Qt
  * @name MidButton
  * @see Qt#MouseButtons
  * @see Qt#MouseButton
  * @type Number
  */
Qt.MidButton = 0x4;

/**
  * @default 0x00000008
  * @constant
  * @memberOf Qt
  * @name XButton1
  * @see Qt#MouseButtons
  * @see Qt#MouseButton
  * @type Number
  */
Qt.XButton1 = 0x8;

/**
  * @default 0x00000010
  * @constant
  * @memberOf Qt
  * @name XButton2
  * @see Qt#MouseButtons
  * @see Qt#MouseButton
  * @type Number
  */
Qt.XButton2 = 0x10;

/**
  * @default 0x000000ff
  * @constant
  * @memberOf Qt
  * @name MouseButtonMask
  * @see Qt#MouseButtons
  * @see Qt#MouseButton
  * @type Number
  */
Qt.MouseButtonMask = 0xff;

/**
  * @constructor 
  * @memberOf Qt
  * @name MouseButton
  */
Qt.MouseButton = function(value){;};

/**
  * @constructor 
  * @memberOf Qt
  * @name MouseButtons
  */
Qt.MouseButtons = function(value1, value2 /*, ...*/){;};


/**
  * @default 0
  * @constant
  * @memberOf Qt
  * @name MatchExactly
  * @see Qt#MatchFlags
  * @see Qt#MatchFlag
  * @type Number
  */
Qt.MatchExactly = 0x0;

/**
  * @default 1
  * @constant
  * @memberOf Qt
  * @name MatchContains
  * @see Qt#MatchFlags
  * @see Qt#MatchFlag
  * @type Number
  */
Qt.MatchContains = 0x1;

/**
  * @default 2
  * @constant
  * @memberOf Qt
  * @name MatchStartsWith
  * @see Qt#MatchFlags
  * @see Qt#MatchFlag
  * @type Number
  */
Qt.MatchStartsWith = 0x2;

/**
  * @default 3
  * @constant
  * @memberOf Qt
  * @name MatchEndsWith
  * @see Qt#MatchFlags
  * @see Qt#MatchFlag
  * @type Number
  */
Qt.MatchEndsWith = 0x3;

/**
  * @default 4
  * @constant
  * @memberOf Qt
  * @name MatchRegExp
  * @see Qt#MatchFlags
  * @see Qt#MatchFlag
  * @type Number
  */
Qt.MatchRegExp = 0x4;

/**
  * @default 5
  * @constant
  * @memberOf Qt
  * @name MatchWildcard
  * @see Qt#MatchFlags
  * @see Qt#MatchFlag
  * @type Number
  */
Qt.MatchWildcard = 0x5;

/**
  * @default 8
  * @constant
  * @memberOf Qt
  * @name MatchFixedString
  * @see Qt#MatchFlags
  * @see Qt#MatchFlag
  * @type Number
  */
Qt.MatchFixedString = 0x8;

/**
  * @default 16
  * @constant
  * @memberOf Qt
  * @name MatchCaseSensitive
  * @see Qt#MatchFlags
  * @see Qt#MatchFlag
  * @type Number
  */
Qt.MatchCaseSensitive = 0x10;

/**
  * @default 32
  * @constant
  * @memberOf Qt
  * @name MatchWrap
  * @see Qt#MatchFlags
  * @see Qt#MatchFlag
  * @type Number
  */
Qt.MatchWrap = 0x20;

/**
  * @default 64
  * @constant
  * @memberOf Qt
  * @name MatchRecursive
  * @see Qt#MatchFlags
  * @see Qt#MatchFlag
  * @type Number
  */
Qt.MatchRecursive = 0x40;

/**
  * @constructor 
  * @memberOf Qt
  * @name MatchFlag
  */
Qt.MatchFlag = function(value){;};

/**
  * @constructor 
  * @memberOf Qt
  * @name MatchFlags
  */
Qt.MatchFlags = function(value1, value2 /*, ...*/){;};


/**
  * @default 0x00
  * @constant
  * @memberOf Qt
  * @name FlatCap
  * @see Qt#PenCapStyle
  * @type Number
  */
Qt.FlatCap = 0x0;

/**
  * @default 0x10
  * @constant
  * @memberOf Qt
  * @name SquareCap
  * @see Qt#PenCapStyle
  * @type Number
  */
Qt.SquareCap = 0x10;

/**
  * @default 0x20
  * @constant
  * @memberOf Qt
  * @name RoundCap
  * @see Qt#PenCapStyle
  * @type Number
  */
Qt.RoundCap = 0x20;

/**
  * @default 0x30
  * @constant
  * @memberOf Qt
  * @name MPenCapStyle
  * @see Qt#PenCapStyle
  * @type Number
  */
Qt.MPenCapStyle = 0x30;

/**
  * @constructor 
  * @memberOf Qt
  * @name PenCapStyle
  */
Qt.PenCapStyle = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf Qt
  * @name ElideLeft
  * @see Qt#TextElideMode
  * @type Number
  */
Qt.ElideLeft = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf Qt
  * @name ElideRight
  * @see Qt#TextElideMode
  * @type Number
  */
Qt.ElideRight = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf Qt
  * @name ElideMiddle
  * @see Qt#TextElideMode
  * @type Number
  */
Qt.ElideMiddle = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf Qt
  * @name ElideNone
  * @see Qt#TextElideMode
  * @type Number
  */
Qt.ElideNone = 0x3;

/**
  * @constructor 
  * @memberOf Qt
  * @name TextElideMode
  */
Qt.TextElideMode = function(value){;};



