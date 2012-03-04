/**
  * @name QAccessible
  * @constructor
  */
function QAccessible(){return undefined;};

/**
  * @name isActive
  * @function
  * @memberOf QAccessible
  * @returns {Boolean}
  */
QAccessible.isActive = function(){return new Boolean();};

/**
  * @name queryAccessibleInterface
  * @function
  * @memberOf QAccessible
  * @param {QObject} arg__1
  * @returns {QAccessibleInterface}
  */
QAccessible.queryAccessibleInterface = function(arg__1){return new QAccessibleInterface();};

/**
  * @name setRootObject
  * @function
  * @memberOf QAccessible
  * @param {QObject} arg__1
  * @returns {undefined}
  */
QAccessible.setRootObject = function(arg__1){return undefined;};

/**
  * @name updateAccessibility
  * @function
  * @memberOf QAccessible
  * @param {QObject} arg__1
  * @param {Numeric} who
  * @param {QAccessible.Event} reason
  * @returns {undefined}
  */
QAccessible.updateAccessibility = function(arg__1, who, reason){return undefined;};

/**
  * @default 0
  * @constant
  * @memberOf QAccessible
  * @name ListSupportedMethods
  * @see QAccessible#Method
  * @type Number
  */
QAccessible.ListSupportedMethods = 0x0;

/**
  * @default 1
  * @constant
  * @memberOf QAccessible
  * @name SetCursorPosition
  * @see QAccessible#Method
  * @type Number
  */
QAccessible.SetCursorPosition = 0x1;

/**
  * @default 2
  * @constant
  * @memberOf QAccessible
  * @name GetCursorPosition
  * @see QAccessible#Method
  * @type Number
  */
QAccessible.GetCursorPosition = 0x2;

/**
  * @default 3
  * @constant
  * @memberOf QAccessible
  * @name ForegroundColor
  * @see QAccessible#Method
  * @type Number
  */
QAccessible.ForegroundColor = 0x3;

/**
  * @default 4
  * @constant
  * @memberOf QAccessible
  * @name BackgroundColor
  * @see QAccessible#Method
  * @type Number
  */
QAccessible.BackgroundColor = 0x4;

/**
  * @constructor 
  * @memberOf QAccessible
  * @name Method
  */
QAccessible.Method = function(value){;};



/**
  * @default 0x00000000
  * @constant
  * @memberOf QAccessible
  * @name NoRole
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.NoRole = 0x0;

/**
  * @default 0x00000001
  * @constant
  * @memberOf QAccessible
  * @name TitleBar
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.TitleBar = 0x1;

/**
  * @default 0x00000002
  * @constant
  * @memberOf QAccessible
  * @name MenuBar
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.MenuBar = 0x2;

/**
  * @default 0x00000003
  * @constant
  * @memberOf QAccessible
  * @name ScrollBar
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.ScrollBar = 0x3;

/**
  * @default 0x00000004
  * @constant
  * @memberOf QAccessible
  * @name Grip
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.Grip = 0x4;

/**
  * @default 0x00000005
  * @constant
  * @memberOf QAccessible
  * @name Sound
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.Sound = 0x5;

/**
  * @default 0x00000006
  * @constant
  * @memberOf QAccessible
  * @name Cursor
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.Cursor = 0x6;

/**
  * @default 0x00000007
  * @constant
  * @memberOf QAccessible
  * @name Caret
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.Caret = 0x7;

/**
  * @default 0x00000008
  * @constant
  * @memberOf QAccessible
  * @name AlertMessage
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.AlertMessage = 0x8;

/**
  * @default 0x00000009
  * @constant
  * @memberOf QAccessible
  * @name Window
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.Window = 0x9;

/**
  * @default 0x0000000A
  * @constant
  * @memberOf QAccessible
  * @name Client
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.Client = 0xa;

/**
  * @default 0x0000000B
  * @constant
  * @memberOf QAccessible
  * @name PopupMenu
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.PopupMenu = 0xb;

/**
  * @default 0x0000000C
  * @constant
  * @memberOf QAccessible
  * @name MenuItem
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.MenuItem = 0xc;

/**
  * @default 0x0000000D
  * @constant
  * @memberOf QAccessible
  * @name ToolTip
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.ToolTip = 0xd;

/**
  * @default 0x0000000E
  * @constant
  * @memberOf QAccessible
  * @name Application
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.Application = 0xe;

/**
  * @default 0x0000000F
  * @constant
  * @memberOf QAccessible
  * @name Document
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.Document = 0xf;

/**
  * @default 0x00000010
  * @constant
  * @memberOf QAccessible
  * @name Pane
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.Pane = 0x10;

/**
  * @default 0x00000011
  * @constant
  * @memberOf QAccessible
  * @name Chart
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.Chart = 0x11;

/**
  * @default 0x00000012
  * @constant
  * @memberOf QAccessible
  * @name Dialog
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.Dialog = 0x12;

/**
  * @default 0x00000013
  * @constant
  * @memberOf QAccessible
  * @name Border
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.Border = 0x13;

/**
  * @default 0x00000014
  * @constant
  * @memberOf QAccessible
  * @name Grouping
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.Grouping = 0x14;

/**
  * @default 0x00000015
  * @constant
  * @memberOf QAccessible
  * @name Separator
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.Separator = 0x15;

/**
  * @default 0x00000016
  * @constant
  * @memberOf QAccessible
  * @name ToolBar
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.ToolBar = 0x16;

/**
  * @default 0x00000017
  * @constant
  * @memberOf QAccessible
  * @name StatusBar
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.StatusBar = 0x17;

/**
  * @default 0x00000018
  * @constant
  * @memberOf QAccessible
  * @name Table
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.Table = 0x18;

/**
  * @default 0x00000019
  * @constant
  * @memberOf QAccessible
  * @name ColumnHeader
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.ColumnHeader = 0x19;

/**
  * @default 0x0000001A
  * @constant
  * @memberOf QAccessible
  * @name RowHeader
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.RowHeader = 0x1a;

/**
  * @default 0x0000001B
  * @constant
  * @memberOf QAccessible
  * @name Column
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.Column = 0x1b;

/**
  * @default 0x0000001C
  * @constant
  * @memberOf QAccessible
  * @name Row
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.Row = 0x1c;

/**
  * @default 0x0000001D
  * @constant
  * @memberOf QAccessible
  * @name Cell
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.Cell = 0x1d;

/**
  * @default 0x0000001E
  * @constant
  * @memberOf QAccessible
  * @name Link
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.Link = 0x1e;

/**
  * @default 0x0000001F
  * @constant
  * @memberOf QAccessible
  * @name HelpBalloon
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.HelpBalloon = 0x1f;

/**
  * @default 0x00000020
  * @constant
  * @memberOf QAccessible
  * @name Assistant
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.Assistant = 0x20;

/**
  * @default 0x00000021
  * @constant
  * @memberOf QAccessible
  * @name List
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.List = 0x21;

/**
  * @default 0x00000022
  * @constant
  * @memberOf QAccessible
  * @name ListItem
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.ListItem = 0x22;

/**
  * @default 0x00000023
  * @constant
  * @memberOf QAccessible
  * @name Tree
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.Tree = 0x23;

/**
  * @default 0x00000024
  * @constant
  * @memberOf QAccessible
  * @name TreeItem
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.TreeItem = 0x24;

/**
  * @default 0x00000025
  * @constant
  * @memberOf QAccessible
  * @name PageTab
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.PageTab = 0x25;

/**
  * @default 0x00000026
  * @constant
  * @memberOf QAccessible
  * @name PropertyPage
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.PropertyPage = 0x26;

/**
  * @default 0x00000027
  * @constant
  * @memberOf QAccessible
  * @name Indicator
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.Indicator = 0x27;

/**
  * @default 0x00000028
  * @constant
  * @memberOf QAccessible
  * @name Graphic
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.Graphic = 0x28;

/**
  * @default 0x00000029
  * @constant
  * @memberOf QAccessible
  * @name StaticText
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.StaticText = 0x29;

/**
  * @default 0x0000002A
  * @constant
  * @memberOf QAccessible
  * @name EditableText
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.EditableText = 0x2a;

/**
  * @default 0x0000002B
  * @constant
  * @memberOf QAccessible
  * @name PushButton
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.PushButton = 0x2b;

/**
  * @default 0x0000002C
  * @constant
  * @memberOf QAccessible
  * @name CheckBox
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.CheckBox = 0x2c;

/**
  * @default 0x0000002D
  * @constant
  * @memberOf QAccessible
  * @name RadioButton
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.RadioButton = 0x2d;

/**
  * @default 0x0000002E
  * @constant
  * @memberOf QAccessible
  * @name ComboBox
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.ComboBox = 0x2e;

/**
  * @default 0x00000030
  * @constant
  * @memberOf QAccessible
  * @name ProgressBar
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.ProgressBar = 0x30;

/**
  * @default 0x00000031
  * @constant
  * @memberOf QAccessible
  * @name Dial
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.Dial = 0x31;

/**
  * @default 0x00000032
  * @constant
  * @memberOf QAccessible
  * @name HotkeyField
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.HotkeyField = 0x32;

/**
  * @default 0x00000033
  * @constant
  * @memberOf QAccessible
  * @name Slider
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.Slider = 0x33;

/**
  * @default 0x00000034
  * @constant
  * @memberOf QAccessible
  * @name SpinBox
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.SpinBox = 0x34;

/**
  * @default 0x00000035
  * @constant
  * @memberOf QAccessible
  * @name Canvas
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.Canvas = 0x35;

/**
  * @default 0x00000036
  * @constant
  * @memberOf QAccessible
  * @name Animation
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.Animation = 0x36;

/**
  * @default 0x00000037
  * @constant
  * @memberOf QAccessible
  * @name Equation
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.Equation = 0x37;

/**
  * @default 0x00000038
  * @constant
  * @memberOf QAccessible
  * @name ButtonDropDown
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.ButtonDropDown = 0x38;

/**
  * @default 0x00000039
  * @constant
  * @memberOf QAccessible
  * @name ButtonMenu
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.ButtonMenu = 0x39;

/**
  * @default 0x0000003A
  * @constant
  * @memberOf QAccessible
  * @name ButtonDropGrid
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.ButtonDropGrid = 0x3a;

/**
  * @default 0x0000003B
  * @constant
  * @memberOf QAccessible
  * @name Whitespace
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.Whitespace = 0x3b;

/**
  * @default 0x0000003C
  * @constant
  * @memberOf QAccessible
  * @name PageTabList
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.PageTabList = 0x3c;

/**
  * @default 0x0000003D
  * @constant
  * @memberOf QAccessible
  * @name Clock
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.Clock = 0x3d;

/**
  * @default 0x0000003E
  * @constant
  * @memberOf QAccessible
  * @name Splitter
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.Splitter = 0x3e;

/**
  * @default 0x0000003F
  * @constant
  * @memberOf QAccessible
  * @name LayeredPane
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.LayeredPane = 0x3f;

/**
  * @default 0x0000ffff
  * @constant
  * @memberOf QAccessible
  * @name UserRole
  * @see QAccessible#Role
  * @type Number
  */
QAccessible.UserRole = 0xffff;

/**
  * @constructor 
  * @memberOf QAccessible
  * @name Role
  */
QAccessible.Role = function(value){;};



/**
  * @default -11
  * @constant
  * @memberOf QAccessible
  * @name AddToSelection
  * @see QAccessible#Action
  * @type Number
  */
QAccessible.AddToSelection = 0xfffffff5;

/**
  * @default -10
  * @constant
  * @memberOf QAccessible
  * @name ExtendSelection
  * @see QAccessible#Action
  * @type Number
  */
QAccessible.ExtendSelection = 0xfffffff6;

/**
  * @default -9
  * @constant
  * @memberOf QAccessible
  * @name RemoveSelection
  * @see QAccessible#Action
  * @type Number
  */
QAccessible.RemoveSelection = 0xfffffff7;

/**
  * @default -8
  * @constant
  * @memberOf QAccessible
  * @name ClearSelection
  * @see QAccessible#Action
  * @type Number
  */
QAccessible.ClearSelection = 0xfffffff8;

/**
  * @default -7
  * @constant
  * @memberOf QAccessible
  * @name Select
  * @see QAccessible#Action
  * @type Number
  */
QAccessible.Select = 0xfffffff9;

/**
  * @default -6
  * @constant
  * @memberOf QAccessible
  * @name Cancel
  * @see QAccessible#Action
  * @type Number
  */
QAccessible.Cancel = 0xfffffffa;

/**
  * @default -5
  * @constant
  * @memberOf QAccessible
  * @name Accept
  * @see QAccessible#Action
  * @type Number
  */
QAccessible.Accept = 0xfffffffb;

/**
  * @default -4
  * @constant
  * @memberOf QAccessible
  * @name Decrease
  * @see QAccessible#Action
  * @type Number
  */
QAccessible.Decrease = 0xfffffffc;

/**
  * @default -3
  * @constant
  * @memberOf QAccessible
  * @name Increase
  * @see QAccessible#Action
  * @type Number
  */
QAccessible.Increase = 0xfffffffd;

/**
  * @default -2
  * @constant
  * @memberOf QAccessible
  * @name SetFocus
  * @see QAccessible#Action
  * @type Number
  */
QAccessible.SetFocus = 0xfffffffe;

/**
  * @default -1
  * @constant
  * @memberOf QAccessible
  * @name Press
  * @see QAccessible#Action
  * @type Number
  */
QAccessible.Press = 0xffffffff;

/**
  * @default 0
  * @constant
  * @memberOf QAccessible
  * @name DefaultAction
  * @see QAccessible#Action
  * @type Number
  */
QAccessible.DefaultAction = 0x0;

/**
  * @constructor 
  * @memberOf QAccessible
  * @name Action
  */
QAccessible.Action = function(value){;};



/**
  * @default 0x0001
  * @constant
  * @memberOf QAccessible
  * @name SoundPlayed
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.SoundPlayed = 0x1;

/**
  * @default 0x0002
  * @constant
  * @memberOf QAccessible
  * @name Alert
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.Alert = 0x2;

/**
  * @default 0x0003
  * @constant
  * @memberOf QAccessible
  * @name ForegroundChanged
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.ForegroundChanged = 0x3;

/**
  * @default 0x0004
  * @constant
  * @memberOf QAccessible
  * @name MenuStart
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.MenuStart = 0x4;

/**
  * @default 0x0005
  * @constant
  * @memberOf QAccessible
  * @name MenuEnd
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.MenuEnd = 0x5;

/**
  * @default 0x0006
  * @constant
  * @memberOf QAccessible
  * @name PopupMenuStart
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.PopupMenuStart = 0x6;

/**
  * @default 0x0007
  * @constant
  * @memberOf QAccessible
  * @name PopupMenuEnd
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.PopupMenuEnd = 0x7;

/**
  * @default 0x000C
  * @constant
  * @memberOf QAccessible
  * @name ContextHelpStart
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.ContextHelpStart = 0xc;

/**
  * @default 0x000D
  * @constant
  * @memberOf QAccessible
  * @name ContextHelpEnd
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.ContextHelpEnd = 0xd;

/**
  * @default 0x000E
  * @constant
  * @memberOf QAccessible
  * @name DragDropStart
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.DragDropStart = 0xe;

/**
  * @default 0x000F
  * @constant
  * @memberOf QAccessible
  * @name DragDropEnd
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.DragDropEnd = 0xf;

/**
  * @default 0x0010
  * @constant
  * @memberOf QAccessible
  * @name DialogStart
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.DialogStart = 0x10;

/**
  * @default 0x0011
  * @constant
  * @memberOf QAccessible
  * @name DialogEnd
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.DialogEnd = 0x11;

/**
  * @default 0x0012
  * @constant
  * @memberOf QAccessible
  * @name ScrollingStart
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.ScrollingStart = 0x12;

/**
  * @default 0x0013
  * @constant
  * @memberOf QAccessible
  * @name ScrollingEnd
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.ScrollingEnd = 0x13;

/**
  * @default 0x0018
  * @constant
  * @memberOf QAccessible
  * @name MenuCommand
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.MenuCommand = 0x18;

/**
  * @default 0x0101
  * @constant
  * @memberOf QAccessible
  * @name ActionChanged
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.ActionChanged = 0x101;

/**
  * @default 0x0102
  * @constant
  * @memberOf QAccessible
  * @name ActiveDescendantChanged
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.ActiveDescendantChanged = 0x102;

/**
  * @default 0x0103
  * @constant
  * @memberOf QAccessible
  * @name AttributeChanged
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.AttributeChanged = 0x103;

/**
  * @default 0x0104
  * @constant
  * @memberOf QAccessible
  * @name DocumentContentChanged
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.DocumentContentChanged = 0x104;

/**
  * @default 0x0105
  * @constant
  * @memberOf QAccessible
  * @name DocumentLoadComplete
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.DocumentLoadComplete = 0x105;

/**
  * @default 0x0106
  * @constant
  * @memberOf QAccessible
  * @name DocumentLoadStopped
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.DocumentLoadStopped = 0x106;

/**
  * @default 0x0107
  * @constant
  * @memberOf QAccessible
  * @name DocumentReload
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.DocumentReload = 0x107;

/**
  * @default 0x0108
  * @constant
  * @memberOf QAccessible
  * @name HyperlinkEndIndexChanged
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.HyperlinkEndIndexChanged = 0x108;

/**
  * @default 0x0109
  * @constant
  * @memberOf QAccessible
  * @name HyperlinkNumberOfAnchorsChanged
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.HyperlinkNumberOfAnchorsChanged = 0x109;

/**
  * @default 0x010A
  * @constant
  * @memberOf QAccessible
  * @name HyperlinkSelectedLinkChanged
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.HyperlinkSelectedLinkChanged = 0x10a;

/**
  * @default 0x010B
  * @constant
  * @memberOf QAccessible
  * @name HypertextLinkActivated
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.HypertextLinkActivated = 0x10b;

/**
  * @default 0x010C
  * @constant
  * @memberOf QAccessible
  * @name HypertextLinkSelected
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.HypertextLinkSelected = 0x10c;

/**
  * @default 0x010D
  * @constant
  * @memberOf QAccessible
  * @name HyperlinkStartIndexChanged
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.HyperlinkStartIndexChanged = 0x10d;

/**
  * @default 0x010E
  * @constant
  * @memberOf QAccessible
  * @name HypertextChanged
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.HypertextChanged = 0x10e;

/**
  * @default 0x010F
  * @constant
  * @memberOf QAccessible
  * @name HypertextNLinksChanged
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.HypertextNLinksChanged = 0x10f;

/**
  * @default 0x0110
  * @constant
  * @memberOf QAccessible
  * @name ObjectAttributeChanged
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.ObjectAttributeChanged = 0x110;

/**
  * @default 0x0111
  * @constant
  * @memberOf QAccessible
  * @name PageChanged
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.PageChanged = 0x111;

/**
  * @default 0x0112
  * @constant
  * @memberOf QAccessible
  * @name SectionChanged
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.SectionChanged = 0x112;

/**
  * @default 0x0113
  * @constant
  * @memberOf QAccessible
  * @name TableCaptionChanged
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.TableCaptionChanged = 0x113;

/**
  * @default 0x0114
  * @constant
  * @memberOf QAccessible
  * @name TableColumnDescriptionChanged
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.TableColumnDescriptionChanged = 0x114;

/**
  * @default 0x0115
  * @constant
  * @memberOf QAccessible
  * @name TableColumnHeaderChanged
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.TableColumnHeaderChanged = 0x115;

/**
  * @default 0x0116
  * @constant
  * @memberOf QAccessible
  * @name TableModelChanged
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.TableModelChanged = 0x116;

/**
  * @default 0x0117
  * @constant
  * @memberOf QAccessible
  * @name TableRowDescriptionChanged
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.TableRowDescriptionChanged = 0x117;

/**
  * @default 0x0118
  * @constant
  * @memberOf QAccessible
  * @name TableRowHeaderChanged
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.TableRowHeaderChanged = 0x118;

/**
  * @default 0x0119
  * @constant
  * @memberOf QAccessible
  * @name TableSummaryChanged
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.TableSummaryChanged = 0x119;

/**
  * @default 0x011A
  * @constant
  * @memberOf QAccessible
  * @name TextAttributeChanged
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.TextAttributeChanged = 0x11a;

/**
  * @default 0x011B
  * @constant
  * @memberOf QAccessible
  * @name TextCaretMoved
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.TextCaretMoved = 0x11b;

/**
  * @default 0x011D
  * @constant
  * @memberOf QAccessible
  * @name TextColumnChanged
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.TextColumnChanged = 0x11d;

/**
  * @default 0x011E
  * @constant
  * @memberOf QAccessible
  * @name TextInserted
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.TextInserted = 0x11e;

/**
  * @default 0x011F
  * @constant
  * @memberOf QAccessible
  * @name TextRemoved
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.TextRemoved = 0x11f;

/**
  * @default 0x0120
  * @constant
  * @memberOf QAccessible
  * @name TextUpdated
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.TextUpdated = 0x120;

/**
  * @default 0x0121
  * @constant
  * @memberOf QAccessible
  * @name TextSelectionChanged
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.TextSelectionChanged = 0x121;

/**
  * @default 0x0122
  * @constant
  * @memberOf QAccessible
  * @name VisibleDataChanged
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.VisibleDataChanged = 0x122;

/**
  * @default 0x8000
  * @constant
  * @memberOf QAccessible
  * @name ObjectCreated
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.ObjectCreated = 0x8000;

/**
  * @default 0x8001
  * @constant
  * @memberOf QAccessible
  * @name ObjectDestroyed
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.ObjectDestroyed = 0x8001;

/**
  * @default 0x8002
  * @constant
  * @memberOf QAccessible
  * @name ObjectShow
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.ObjectShow = 0x8002;

/**
  * @default 0x8003
  * @constant
  * @memberOf QAccessible
  * @name ObjectHide
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.ObjectHide = 0x8003;

/**
  * @default 0x8004
  * @constant
  * @memberOf QAccessible
  * @name ObjectReorder
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.ObjectReorder = 0x8004;

/**
  * @default 0x8005
  * @constant
  * @memberOf QAccessible
  * @name Focus
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.Focus = 0x8005;

/**
  * @default 0x8006
  * @constant
  * @memberOf QAccessible
  * @name Selection
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.Selection = 0x8006;

/**
  * @default 0x8007
  * @constant
  * @memberOf QAccessible
  * @name SelectionAdd
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.SelectionAdd = 0x8007;

/**
  * @default 0x8008
  * @constant
  * @memberOf QAccessible
  * @name SelectionRemove
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.SelectionRemove = 0x8008;

/**
  * @default 0x8009
  * @constant
  * @memberOf QAccessible
  * @name SelectionWithin
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.SelectionWithin = 0x8009;

/**
  * @default 0x800A
  * @constant
  * @memberOf QAccessible
  * @name StateChanged
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.StateChanged = 0x800a;

/**
  * @default 0x800B
  * @constant
  * @memberOf QAccessible
  * @name LocationChanged
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.LocationChanged = 0x800b;

/**
  * @default 0x800C
  * @constant
  * @memberOf QAccessible
  * @name NameChanged
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.NameChanged = 0x800c;

/**
  * @default 0x800D
  * @constant
  * @memberOf QAccessible
  * @name DescriptionChanged
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.DescriptionChanged = 0x800d;

/**
  * @default 0x800E
  * @constant
  * @memberOf QAccessible
  * @name ValueChanged
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.ValueChanged = 0x800e;

/**
  * @default 0x800F
  * @constant
  * @memberOf QAccessible
  * @name ParentChanged
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.ParentChanged = 0x800f;

/**
  * @default 0x80A0
  * @constant
  * @memberOf QAccessible
  * @name HelpChanged
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.HelpChanged = 0x80a0;

/**
  * @default 0x80B0
  * @constant
  * @memberOf QAccessible
  * @name DefaultActionChanged
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.DefaultActionChanged = 0x80b0;

/**
  * @default 0x80C0
  * @constant
  * @memberOf QAccessible
  * @name AcceleratorChanged
  * @see QAccessible#Event
  * @type Number
  */
QAccessible.AcceleratorChanged = 0x80c0;

/**
  * @constructor 
  * @memberOf QAccessible
  * @name Event
  */
QAccessible.Event = function(value){;};



/**
  * @default 0x00000000
  * @constant
  * @memberOf QAccessible
  * @name Unrelated
  * @see QAccessible#Relation
  * @see QAccessible#RelationFlag
  * @type Number
  */
QAccessible.Unrelated = 0x0;

/**
  * @default 0x00000001
  * @constant
  * @memberOf QAccessible
  * @name Self
  * @see QAccessible#Relation
  * @see QAccessible#RelationFlag
  * @type Number
  */
QAccessible.Self = 0x1;

/**
  * @default 0x00000002
  * @constant
  * @memberOf QAccessible
  * @name Ancestor
  * @see QAccessible#Relation
  * @see QAccessible#RelationFlag
  * @type Number
  */
QAccessible.Ancestor = 0x2;

/**
  * @default 0x00000004
  * @constant
  * @memberOf QAccessible
  * @name Child
  * @see QAccessible#Relation
  * @see QAccessible#RelationFlag
  * @type Number
  */
QAccessible.Child = 0x4;

/**
  * @default 0x00000008
  * @constant
  * @memberOf QAccessible
  * @name Descendent
  * @see QAccessible#Relation
  * @see QAccessible#RelationFlag
  * @type Number
  */
QAccessible.Descendent = 0x8;

/**
  * @default 0x00000010
  * @constant
  * @memberOf QAccessible
  * @name Sibling
  * @see QAccessible#Relation
  * @see QAccessible#RelationFlag
  * @type Number
  */
QAccessible.Sibling = 0x10;

/**
  * @default 0x000000ff
  * @constant
  * @memberOf QAccessible
  * @name HierarchyMask
  * @see QAccessible#Relation
  * @see QAccessible#RelationFlag
  * @type Number
  */
QAccessible.HierarchyMask = 0xff;

/**
  * @default 0x00000100
  * @constant
  * @memberOf QAccessible
  * @name Up
  * @see QAccessible#Relation
  * @see QAccessible#RelationFlag
  * @type Number
  */
QAccessible.Up = 0x100;

/**
  * @default 0x00000200
  * @constant
  * @memberOf QAccessible
  * @name Down
  * @see QAccessible#Relation
  * @see QAccessible#RelationFlag
  * @type Number
  */
QAccessible.Down = 0x200;

/**
  * @default 0x00000400
  * @constant
  * @memberOf QAccessible
  * @name Left
  * @see QAccessible#Relation
  * @see QAccessible#RelationFlag
  * @type Number
  */
QAccessible.Left = 0x400;

/**
  * @default 0x00000800
  * @constant
  * @memberOf QAccessible
  * @name Right
  * @see QAccessible#Relation
  * @see QAccessible#RelationFlag
  * @type Number
  */
QAccessible.Right = 0x800;

/**
  * @default 0x00001000
  * @constant
  * @memberOf QAccessible
  * @name Covers
  * @see QAccessible#Relation
  * @see QAccessible#RelationFlag
  * @type Number
  */
QAccessible.Covers = 0x1000;

/**
  * @default 0x00002000
  * @constant
  * @memberOf QAccessible
  * @name Covered
  * @see QAccessible#Relation
  * @see QAccessible#RelationFlag
  * @type Number
  */
QAccessible.Covered = 0x2000;

/**
  * @default 0x0000ff00
  * @constant
  * @memberOf QAccessible
  * @name GeometryMask
  * @see QAccessible#Relation
  * @see QAccessible#RelationFlag
  * @type Number
  */
QAccessible.GeometryMask = 0xff00;

/**
  * @default 0x00010000
  * @constant
  * @memberOf QAccessible
  * @name FocusChild
  * @see QAccessible#Relation
  * @see QAccessible#RelationFlag
  * @type Number
  */
QAccessible.FocusChild = 0x10000;

/**
  * @default 0x00020000
  * @constant
  * @memberOf QAccessible
  * @name Label
  * @see QAccessible#Relation
  * @see QAccessible#RelationFlag
  * @type Number
  */
QAccessible.Label = 0x20000;

/**
  * @default 0x00040000
  * @constant
  * @memberOf QAccessible
  * @name Labelled
  * @see QAccessible#Relation
  * @see QAccessible#RelationFlag
  * @type Number
  */
QAccessible.Labelled = 0x40000;

/**
  * @default 0x00080000
  * @constant
  * @memberOf QAccessible
  * @name Controller
  * @see QAccessible#Relation
  * @see QAccessible#RelationFlag
  * @type Number
  */
QAccessible.Controller = 0x80000;

/**
  * @default 0x00100000
  * @constant
  * @memberOf QAccessible
  * @name Controlled
  * @see QAccessible#Relation
  * @see QAccessible#RelationFlag
  * @type Number
  */
QAccessible.Controlled = 0x100000;

/**
  * @default 0x00ff0000
  * @constant
  * @memberOf QAccessible
  * @name LogicalMask
  * @see QAccessible#Relation
  * @see QAccessible#RelationFlag
  * @type Number
  */
QAccessible.LogicalMask = 0xff0000;

/**
  * @constructor 
  * @memberOf QAccessible
  * @name RelationFlag
  */
QAccessible.RelationFlag = function(value){;};

/**
  * @constructor 
  * @memberOf QAccessible
  * @name Relation
  */
QAccessible.Relation = function(value1, value2 /*, ...*/){;};


/**
  * @default 0x80000000
  * @constant
  * @memberOf QAccessible
  * @name Modal
  * @see QAccessible#State
  * @see QAccessible#StateFlag
  * @type Number
  */
QAccessible.Modal = 0x80000000;

/**
  * @default 0x00000000
  * @constant
  * @memberOf QAccessible
  * @name Normal
  * @see QAccessible#State
  * @see QAccessible#StateFlag
  * @type Number
  */
QAccessible.Normal = 0x0;

/**
  * @default 0x00000001
  * @constant
  * @memberOf QAccessible
  * @name Unavailable
  * @see QAccessible#State
  * @see QAccessible#StateFlag
  * @type Number
  */
QAccessible.Unavailable = 0x1;

/**
  * @default 0x00000002
  * @constant
  * @memberOf QAccessible
  * @name Selected
  * @see QAccessible#State
  * @see QAccessible#StateFlag
  * @type Number
  */
QAccessible.Selected = 0x2;

/**
  * @default 0x00000004
  * @constant
  * @memberOf QAccessible
  * @name Focused
  * @see QAccessible#State
  * @see QAccessible#StateFlag
  * @type Number
  */
QAccessible.Focused = 0x4;

/**
  * @default 0x00000008
  * @constant
  * @memberOf QAccessible
  * @name Pressed
  * @see QAccessible#State
  * @see QAccessible#StateFlag
  * @type Number
  */
QAccessible.Pressed = 0x8;

/**
  * @default 0x00000010
  * @constant
  * @memberOf QAccessible
  * @name Checked
  * @see QAccessible#State
  * @see QAccessible#StateFlag
  * @type Number
  */
QAccessible.Checked = 0x10;

/**
  * @default 0x00000020
  * @constant
  * @memberOf QAccessible
  * @name Mixed
  * @see QAccessible#State
  * @see QAccessible#StateFlag
  * @type Number
  */
QAccessible.Mixed = 0x20;

/**
  * @default 0x00000040
  * @constant
  * @memberOf QAccessible
  * @name ReadOnly
  * @see QAccessible#State
  * @see QAccessible#StateFlag
  * @type Number
  */
QAccessible.ReadOnly = 0x40;

/**
  * @default 0x00000080
  * @constant
  * @memberOf QAccessible
  * @name HotTracked
  * @see QAccessible#State
  * @see QAccessible#StateFlag
  * @type Number
  */
QAccessible.HotTracked = 0x80;

/**
  * @default 0x00000100
  * @constant
  * @memberOf QAccessible
  * @name DefaultButton
  * @see QAccessible#State
  * @see QAccessible#StateFlag
  * @type Number
  */
QAccessible.DefaultButton = 0x100;

/**
  * @default 0x00000200
  * @constant
  * @memberOf QAccessible
  * @name Expanded
  * @see QAccessible#State
  * @see QAccessible#StateFlag
  * @type Number
  */
QAccessible.Expanded = 0x200;

/**
  * @default 0x00000400
  * @constant
  * @memberOf QAccessible
  * @name Collapsed
  * @see QAccessible#State
  * @see QAccessible#StateFlag
  * @type Number
  */
QAccessible.Collapsed = 0x400;

/**
  * @default 0x00000800
  * @constant
  * @memberOf QAccessible
  * @name Busy
  * @see QAccessible#State
  * @see QAccessible#StateFlag
  * @type Number
  */
QAccessible.Busy = 0x800;

/**
  * @default 0x00002000
  * @constant
  * @memberOf QAccessible
  * @name Marqueed
  * @see QAccessible#State
  * @see QAccessible#StateFlag
  * @type Number
  */
QAccessible.Marqueed = 0x2000;

/**
  * @default 0x00004000
  * @constant
  * @memberOf QAccessible
  * @name Animated
  * @see QAccessible#State
  * @see QAccessible#StateFlag
  * @type Number
  */
QAccessible.Animated = 0x4000;

/**
  * @default 0x00008000
  * @constant
  * @memberOf QAccessible
  * @name Invisible
  * @see QAccessible#State
  * @see QAccessible#StateFlag
  * @type Number
  */
QAccessible.Invisible = 0x8000;

/**
  * @default 0x00010000
  * @constant
  * @memberOf QAccessible
  * @name Offscreen
  * @see QAccessible#State
  * @see QAccessible#StateFlag
  * @type Number
  */
QAccessible.Offscreen = 0x10000;

/**
  * @default 0x00020000
  * @constant
  * @memberOf QAccessible
  * @name Sizeable
  * @see QAccessible#State
  * @see QAccessible#StateFlag
  * @type Number
  */
QAccessible.Sizeable = 0x20000;

/**
  * @default 0x00040000
  * @constant
  * @memberOf QAccessible
  * @name Movable
  * @see QAccessible#State
  * @see QAccessible#StateFlag
  * @type Number
  */
QAccessible.Movable = 0x40000;

/**
  * @default 0x00080000
  * @constant
  * @memberOf QAccessible
  * @name SelfVoicing
  * @see QAccessible#State
  * @see QAccessible#StateFlag
  * @type Number
  */
QAccessible.SelfVoicing = 0x80000;

/**
  * @default 0x00100000
  * @constant
  * @memberOf QAccessible
  * @name Focusable
  * @see QAccessible#State
  * @see QAccessible#StateFlag
  * @type Number
  */
QAccessible.Focusable = 0x100000;

/**
  * @default 0x00200000
  * @constant
  * @memberOf QAccessible
  * @name Selectable
  * @see QAccessible#State
  * @see QAccessible#StateFlag
  * @type Number
  */
QAccessible.Selectable = 0x200000;

/**
  * @default 0x00400000
  * @constant
  * @memberOf QAccessible
  * @name Linked
  * @see QAccessible#State
  * @see QAccessible#StateFlag
  * @type Number
  */
QAccessible.Linked = 0x400000;

/**
  * @default 0x00800000
  * @constant
  * @memberOf QAccessible
  * @name Traversed
  * @see QAccessible#State
  * @see QAccessible#StateFlag
  * @type Number
  */
QAccessible.Traversed = 0x800000;

/**
  * @default 0x01000000
  * @constant
  * @memberOf QAccessible
  * @name MultiSelectable
  * @see QAccessible#State
  * @see QAccessible#StateFlag
  * @type Number
  */
QAccessible.MultiSelectable = 0x1000000;

/**
  * @default 0x02000000
  * @constant
  * @memberOf QAccessible
  * @name ExtSelectable
  * @see QAccessible#State
  * @see QAccessible#StateFlag
  * @type Number
  */
QAccessible.ExtSelectable = 0x2000000;

/**
  * @default 0x10000000
  * @constant
  * @memberOf QAccessible
  * @name HasInvokeExtension
  * @see QAccessible#State
  * @see QAccessible#StateFlag
  * @type Number
  */
QAccessible.HasInvokeExtension = 0x10000000;

/**
  * @default 0x20000000
  * @constant
  * @memberOf QAccessible
  * @name Protected
  * @see QAccessible#State
  * @see QAccessible#StateFlag
  * @type Number
  */
QAccessible.Protected = 0x20000000;

/**
  * @default 0x40000000
  * @constant
  * @memberOf QAccessible
  * @name HasPopup
  * @see QAccessible#State
  * @see QAccessible#StateFlag
  * @type Number
  */
QAccessible.HasPopup = 0x40000000;

/**
  * @constructor 
  * @memberOf QAccessible
  * @name StateFlag
  */
QAccessible.StateFlag = function(value){;};

/**
  * @constructor 
  * @memberOf QAccessible
  * @name State
  */
QAccessible.State = function(value1, value2 /*, ...*/){;};


/**
  * @default 0
  * @constant
  * @memberOf QAccessible
  * @name Name
  * @see QAccessible#Text
  * @type Number
  */
QAccessible.Name = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QAccessible
  * @name Description
  * @see QAccessible#Text
  * @type Number
  */
QAccessible.Description = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QAccessible
  * @name Value
  * @see QAccessible#Text
  * @type Number
  */
QAccessible.Value = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QAccessible
  * @name Help
  * @see QAccessible#Text
  * @type Number
  */
QAccessible.Help = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QAccessible
  * @name Accelerator
  * @see QAccessible#Text
  * @type Number
  */
QAccessible.Accelerator = 0x4;

/**
  * @default 0x0000ffff
  * @constant
  * @memberOf QAccessible
  * @name UserText
  * @see QAccessible#Text
  * @type Number
  */
QAccessible.UserText = 0xffff;

/**
  * @constructor 
  * @memberOf QAccessible
  * @name Text
  */
QAccessible.Text = function(value){;};



