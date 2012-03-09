/**
  * @name QEvent
  * @constructor
  * @param {QApplication.Type} type
  */
function QEvent(type){return undefined;};

/**
  * @name registerEventType
  * @function
  * @memberOf QEvent
  * @param {Numeric} hint
  * @returns {Numeric}
  */
QEvent.registerEventType = function(hint){return new Numeric();};

/**
  * @default 0
  * @constant
  * @memberOf QEvent
  * @name None
  * @see QEvent#Type
  * @type Number
  */
QEvent.None = 0x0;

/**
  * @default 1
  * @constant
  * @memberOf QEvent
  * @name Timer
  * @see QEvent#Type
  * @type Number
  */
QEvent.Timer = 0x1;

/**
  * @default 2
  * @constant
  * @memberOf QEvent
  * @name MouseButtonPress
  * @see QEvent#Type
  * @type Number
  */
QEvent.MouseButtonPress = 0x2;

/**
  * @default 3
  * @constant
  * @memberOf QEvent
  * @name MouseButtonRelease
  * @see QEvent#Type
  * @type Number
  */
QEvent.MouseButtonRelease = 0x3;

/**
  * @default 4
  * @constant
  * @memberOf QEvent
  * @name MouseButtonDblClick
  * @see QEvent#Type
  * @type Number
  */
QEvent.MouseButtonDblClick = 0x4;

/**
  * @default 5
  * @constant
  * @memberOf QEvent
  * @name MouseMove
  * @see QEvent#Type
  * @type Number
  */
QEvent.MouseMove = 0x5;

/**
  * @default 6
  * @constant
  * @memberOf QEvent
  * @name KeyPress
  * @see QEvent#Type
  * @type Number
  */
QEvent.KeyPress = 0x6;

/**
  * @default 7
  * @constant
  * @memberOf QEvent
  * @name KeyRelease
  * @see QEvent#Type
  * @type Number
  */
QEvent.KeyRelease = 0x7;

/**
  * @default 8
  * @constant
  * @memberOf QEvent
  * @name FocusIn
  * @see QEvent#Type
  * @type Number
  */
QEvent.FocusIn = 0x8;

/**
  * @default 9
  * @constant
  * @memberOf QEvent
  * @name FocusOut
  * @see QEvent#Type
  * @type Number
  */
QEvent.FocusOut = 0x9;

/**
  * @default 10
  * @constant
  * @memberOf QEvent
  * @name Enter
  * @see QEvent#Type
  * @type Number
  */
QEvent.Enter = 0xa;

/**
  * @default 11
  * @constant
  * @memberOf QEvent
  * @name Leave
  * @see QEvent#Type
  * @type Number
  */
QEvent.Leave = 0xb;

/**
  * @default 12
  * @constant
  * @memberOf QEvent
  * @name Paint
  * @see QEvent#Type
  * @type Number
  */
QEvent.Paint = 0xc;

/**
  * @default 13
  * @constant
  * @memberOf QEvent
  * @name Move
  * @see QEvent#Type
  * @type Number
  */
QEvent.Move = 0xd;

/**
  * @default 14
  * @constant
  * @memberOf QEvent
  * @name Resize
  * @see QEvent#Type
  * @type Number
  */
QEvent.Resize = 0xe;

/**
  * @default 15
  * @constant
  * @memberOf QEvent
  * @name Create
  * @see QEvent#Type
  * @type Number
  */
QEvent.Create = 0xf;

/**
  * @default 16
  * @constant
  * @memberOf QEvent
  * @name Destroy
  * @see QEvent#Type
  * @type Number
  */
QEvent.Destroy = 0x10;

/**
  * @default 17
  * @constant
  * @memberOf QEvent
  * @name Show
  * @see QEvent#Type
  * @type Number
  */
QEvent.Show = 0x11;

/**
  * @default 18
  * @constant
  * @memberOf QEvent
  * @name Hide
  * @see QEvent#Type
  * @type Number
  */
QEvent.Hide = 0x12;

/**
  * @default 19
  * @constant
  * @memberOf QEvent
  * @name Close
  * @see QEvent#Type
  * @type Number
  */
QEvent.Close = 0x13;

/**
  * @default 20
  * @constant
  * @memberOf QEvent
  * @name Quit
  * @see QEvent#Type
  * @type Number
  */
QEvent.Quit = 0x14;

/**
  * @default 21
  * @constant
  * @memberOf QEvent
  * @name ParentChange
  * @see QEvent#Type
  * @type Number
  */
QEvent.ParentChange = 0x15;

/**
  * @default 22
  * @constant
  * @memberOf QEvent
  * @name ThreadChange
  * @see QEvent#Type
  * @type Number
  */
QEvent.ThreadChange = 0x16;

/**
  * @default 24
  * @constant
  * @memberOf QEvent
  * @name WindowActivate
  * @see QEvent#Type
  * @type Number
  */
QEvent.WindowActivate = 0x18;

/**
  * @default 25
  * @constant
  * @memberOf QEvent
  * @name WindowDeactivate
  * @see QEvent#Type
  * @type Number
  */
QEvent.WindowDeactivate = 0x19;

/**
  * @default 26
  * @constant
  * @memberOf QEvent
  * @name ShowToParent
  * @see QEvent#Type
  * @type Number
  */
QEvent.ShowToParent = 0x1a;

/**
  * @default 27
  * @constant
  * @memberOf QEvent
  * @name HideToParent
  * @see QEvent#Type
  * @type Number
  */
QEvent.HideToParent = 0x1b;

/**
  * @default 31
  * @constant
  * @memberOf QEvent
  * @name Wheel
  * @see QEvent#Type
  * @type Number
  */
QEvent.Wheel = 0x1f;

/**
  * @default 33
  * @constant
  * @memberOf QEvent
  * @name WindowTitleChange
  * @see QEvent#Type
  * @type Number
  */
QEvent.WindowTitleChange = 0x21;

/**
  * @default 34
  * @constant
  * @memberOf QEvent
  * @name WindowIconChange
  * @see QEvent#Type
  * @type Number
  */
QEvent.WindowIconChange = 0x22;

/**
  * @default 35
  * @constant
  * @memberOf QEvent
  * @name ApplicationWindowIconChange
  * @see QEvent#Type
  * @type Number
  */
QEvent.ApplicationWindowIconChange = 0x23;

/**
  * @default 36
  * @constant
  * @memberOf QEvent
  * @name ApplicationFontChange
  * @see QEvent#Type
  * @type Number
  */
QEvent.ApplicationFontChange = 0x24;

/**
  * @default 37
  * @constant
  * @memberOf QEvent
  * @name ApplicationLayoutDirectionChange
  * @see QEvent#Type
  * @type Number
  */
QEvent.ApplicationLayoutDirectionChange = 0x25;

/**
  * @default 38
  * @constant
  * @memberOf QEvent
  * @name ApplicationPaletteChange
  * @see QEvent#Type
  * @type Number
  */
QEvent.ApplicationPaletteChange = 0x26;

/**
  * @default 39
  * @constant
  * @memberOf QEvent
  * @name PaletteChange
  * @see QEvent#Type
  * @type Number
  */
QEvent.PaletteChange = 0x27;

/**
  * @default 40
  * @constant
  * @memberOf QEvent
  * @name Clipboard
  * @see QEvent#Type
  * @type Number
  */
QEvent.Clipboard = 0x28;

/**
  * @default 42
  * @constant
  * @memberOf QEvent
  * @name Speech
  * @see QEvent#Type
  * @type Number
  */
QEvent.Speech = 0x2a;

/**
  * @default 43
  * @constant
  * @memberOf QEvent
  * @name MetaCall
  * @see QEvent#Type
  * @type Number
  */
QEvent.MetaCall = 0x2b;

/**
  * @default 50
  * @constant
  * @memberOf QEvent
  * @name SockAct
  * @see QEvent#Type
  * @type Number
  */
QEvent.SockAct = 0x32;

/**
  * @default 51
  * @constant
  * @memberOf QEvent
  * @name ShortcutOverride
  * @see QEvent#Type
  * @type Number
  */
QEvent.ShortcutOverride = 0x33;

/**
  * @default 52
  * @constant
  * @memberOf QEvent
  * @name DeferredDelete
  * @see QEvent#Type
  * @type Number
  */
QEvent.DeferredDelete = 0x34;

/**
  * @default 60
  * @constant
  * @memberOf QEvent
  * @name DragEnter
  * @see QEvent#Type
  * @type Number
  */
QEvent.DragEnter = 0x3c;

/**
  * @default 61
  * @constant
  * @memberOf QEvent
  * @name DragMove
  * @see QEvent#Type
  * @type Number
  */
QEvent.DragMove = 0x3d;

/**
  * @default 62
  * @constant
  * @memberOf QEvent
  * @name DragLeave
  * @see QEvent#Type
  * @type Number
  */
QEvent.DragLeave = 0x3e;

/**
  * @default 63
  * @constant
  * @memberOf QEvent
  * @name Drop
  * @see QEvent#Type
  * @type Number
  */
QEvent.Drop = 0x3f;

/**
  * @default 64
  * @constant
  * @memberOf QEvent
  * @name DragResponse
  * @see QEvent#Type
  * @type Number
  */
QEvent.DragResponse = 0x40;

/**
  * @default 68
  * @constant
  * @memberOf QEvent
  * @name ChildAdded
  * @see QEvent#Type
  * @type Number
  */
QEvent.ChildAdded = 0x44;

/**
  * @default 69
  * @constant
  * @memberOf QEvent
  * @name ChildPolished
  * @see QEvent#Type
  * @type Number
  */
QEvent.ChildPolished = 0x45;

/**
  * @default 71
  * @constant
  * @memberOf QEvent
  * @name ChildRemoved
  * @see QEvent#Type
  * @type Number
  */
QEvent.ChildRemoved = 0x47;

/**
  * @default 73
  * @constant
  * @memberOf QEvent
  * @name ShowWindowRequest
  * @see QEvent#Type
  * @type Number
  */
QEvent.ShowWindowRequest = 0x49;

/**
  * @default 74
  * @constant
  * @memberOf QEvent
  * @name PolishRequest
  * @see QEvent#Type
  * @type Number
  */
QEvent.PolishRequest = 0x4a;

/**
  * @default 75
  * @constant
  * @memberOf QEvent
  * @name Polish
  * @see QEvent#Type
  * @type Number
  */
QEvent.Polish = 0x4b;

/**
  * @default 76
  * @constant
  * @memberOf QEvent
  * @name LayoutRequest
  * @see QEvent#Type
  * @type Number
  */
QEvent.LayoutRequest = 0x4c;

/**
  * @default 77
  * @constant
  * @memberOf QEvent
  * @name UpdateRequest
  * @see QEvent#Type
  * @type Number
  */
QEvent.UpdateRequest = 0x4d;

/**
  * @default 78
  * @constant
  * @memberOf QEvent
  * @name UpdateLater
  * @see QEvent#Type
  * @type Number
  */
QEvent.UpdateLater = 0x4e;

/**
  * @default 79
  * @constant
  * @memberOf QEvent
  * @name EmbeddingControl
  * @see QEvent#Type
  * @type Number
  */
QEvent.EmbeddingControl = 0x4f;

/**
  * @default 80
  * @constant
  * @memberOf QEvent
  * @name ActivateControl
  * @see QEvent#Type
  * @type Number
  */
QEvent.ActivateControl = 0x50;

/**
  * @default 81
  * @constant
  * @memberOf QEvent
  * @name DeactivateControl
  * @see QEvent#Type
  * @type Number
  */
QEvent.DeactivateControl = 0x51;

/**
  * @default 82
  * @constant
  * @memberOf QEvent
  * @name ContextMenu
  * @see QEvent#Type
  * @type Number
  */
QEvent.ContextMenu = 0x52;

/**
  * @default 83
  * @constant
  * @memberOf QEvent
  * @name InputMethod
  * @see QEvent#Type
  * @type Number
  */
QEvent.InputMethod = 0x53;

/**
  * @default 86
  * @constant
  * @memberOf QEvent
  * @name AccessibilityPrepare
  * @see QEvent#Type
  * @type Number
  */
QEvent.AccessibilityPrepare = 0x56;

/**
  * @default 87
  * @constant
  * @memberOf QEvent
  * @name TabletMove
  * @see QEvent#Type
  * @type Number
  */
QEvent.TabletMove = 0x57;

/**
  * @default 88
  * @constant
  * @memberOf QEvent
  * @name LocaleChange
  * @see QEvent#Type
  * @type Number
  */
QEvent.LocaleChange = 0x58;

/**
  * @default 89
  * @constant
  * @memberOf QEvent
  * @name LanguageChange
  * @see QEvent#Type
  * @type Number
  */
QEvent.LanguageChange = 0x59;

/**
  * @default 90
  * @constant
  * @memberOf QEvent
  * @name LayoutDirectionChange
  * @see QEvent#Type
  * @type Number
  */
QEvent.LayoutDirectionChange = 0x5a;

/**
  * @default 91
  * @constant
  * @memberOf QEvent
  * @name Style
  * @see QEvent#Type
  * @type Number
  */
QEvent.Style = 0x5b;

/**
  * @default 92
  * @constant
  * @memberOf QEvent
  * @name TabletPress
  * @see QEvent#Type
  * @type Number
  */
QEvent.TabletPress = 0x5c;

/**
  * @default 93
  * @constant
  * @memberOf QEvent
  * @name TabletRelease
  * @see QEvent#Type
  * @type Number
  */
QEvent.TabletRelease = 0x5d;

/**
  * @default 94
  * @constant
  * @memberOf QEvent
  * @name OkRequest
  * @see QEvent#Type
  * @type Number
  */
QEvent.OkRequest = 0x5e;

/**
  * @default 95
  * @constant
  * @memberOf QEvent
  * @name HelpRequest
  * @see QEvent#Type
  * @type Number
  */
QEvent.HelpRequest = 0x5f;

/**
  * @default 96
  * @constant
  * @memberOf QEvent
  * @name IconDrag
  * @see QEvent#Type
  * @type Number
  */
QEvent.IconDrag = 0x60;

/**
  * @default 97
  * @constant
  * @memberOf QEvent
  * @name FontChange
  * @see QEvent#Type
  * @type Number
  */
QEvent.FontChange = 0x61;

/**
  * @default 98
  * @constant
  * @memberOf QEvent
  * @name EnabledChange
  * @see QEvent#Type
  * @type Number
  */
QEvent.EnabledChange = 0x62;

/**
  * @default 99
  * @constant
  * @memberOf QEvent
  * @name ActivationChange
  * @see QEvent#Type
  * @type Number
  */
QEvent.ActivationChange = 0x63;

/**
  * @default 100
  * @constant
  * @memberOf QEvent
  * @name StyleChange
  * @see QEvent#Type
  * @type Number
  */
QEvent.StyleChange = 0x64;

/**
  * @default 101
  * @constant
  * @memberOf QEvent
  * @name IconTextChange
  * @see QEvent#Type
  * @type Number
  */
QEvent.IconTextChange = 0x65;

/**
  * @default 102
  * @constant
  * @memberOf QEvent
  * @name ModifiedChange
  * @see QEvent#Type
  * @type Number
  */
QEvent.ModifiedChange = 0x66;

/**
  * @default 103
  * @constant
  * @memberOf QEvent
  * @name WindowBlocked
  * @see QEvent#Type
  * @type Number
  */
QEvent.WindowBlocked = 0x67;

/**
  * @default 104
  * @constant
  * @memberOf QEvent
  * @name WindowUnblocked
  * @see QEvent#Type
  * @type Number
  */
QEvent.WindowUnblocked = 0x68;

/**
  * @default 105
  * @constant
  * @memberOf QEvent
  * @name WindowStateChange
  * @see QEvent#Type
  * @type Number
  */
QEvent.WindowStateChange = 0x69;

/**
  * @default 109
  * @constant
  * @memberOf QEvent
  * @name MouseTrackingChange
  * @see QEvent#Type
  * @type Number
  */
QEvent.MouseTrackingChange = 0x6d;

/**
  * @default 110
  * @constant
  * @memberOf QEvent
  * @name ToolTip
  * @see QEvent#Type
  * @type Number
  */
QEvent.ToolTip = 0x6e;

/**
  * @default 111
  * @constant
  * @memberOf QEvent
  * @name WhatsThis
  * @see QEvent#Type
  * @type Number
  */
QEvent.WhatsThis = 0x6f;

/**
  * @default 112
  * @constant
  * @memberOf QEvent
  * @name StatusTip
  * @see QEvent#Type
  * @type Number
  */
QEvent.StatusTip = 0x70;

/**
  * @default 113
  * @constant
  * @memberOf QEvent
  * @name ActionChanged
  * @see QEvent#Type
  * @type Number
  */
QEvent.ActionChanged = 0x71;

/**
  * @default 114
  * @constant
  * @memberOf QEvent
  * @name ActionAdded
  * @see QEvent#Type
  * @type Number
  */
QEvent.ActionAdded = 0x72;

/**
  * @default 115
  * @constant
  * @memberOf QEvent
  * @name ActionRemoved
  * @see QEvent#Type
  * @type Number
  */
QEvent.ActionRemoved = 0x73;

/**
  * @default 116
  * @constant
  * @memberOf QEvent
  * @name FileOpen
  * @see QEvent#Type
  * @type Number
  */
QEvent.FileOpen = 0x74;

/**
  * @default 117
  * @constant
  * @memberOf QEvent
  * @name Shortcut
  * @see QEvent#Type
  * @type Number
  */
QEvent.Shortcut = 0x75;

/**
  * @default 118
  * @constant
  * @memberOf QEvent
  * @name WhatsThisClicked
  * @see QEvent#Type
  * @type Number
  */
QEvent.WhatsThisClicked = 0x76;

/**
  * @default 119
  * @constant
  * @memberOf QEvent
  * @name AccessibilityHelp
  * @see QEvent#Type
  * @type Number
  */
QEvent.AccessibilityHelp = 0x77;

/**
  * @default 120
  * @constant
  * @memberOf QEvent
  * @name ToolBarChange
  * @see QEvent#Type
  * @type Number
  */
QEvent.ToolBarChange = 0x78;

/**
  * @default 121
  * @constant
  * @memberOf QEvent
  * @name ApplicationActivate
  * @see QEvent#Type
  * @type Number
  */
QEvent.ApplicationActivate = 0x79;

/**
  * @default 122
  * @constant
  * @memberOf QEvent
  * @name ApplicationDeactivate
  * @see QEvent#Type
  * @type Number
  */
QEvent.ApplicationDeactivate = 0x7a;

/**
  * @default 123
  * @constant
  * @memberOf QEvent
  * @name QueryWhatsThis
  * @see QEvent#Type
  * @type Number
  */
QEvent.QueryWhatsThis = 0x7b;

/**
  * @default 124
  * @constant
  * @memberOf QEvent
  * @name EnterWhatsThisMode
  * @see QEvent#Type
  * @type Number
  */
QEvent.EnterWhatsThisMode = 0x7c;

/**
  * @default 125
  * @constant
  * @memberOf QEvent
  * @name LeaveWhatsThisMode
  * @see QEvent#Type
  * @type Number
  */
QEvent.LeaveWhatsThisMode = 0x7d;

/**
  * @default 126
  * @constant
  * @memberOf QEvent
  * @name ZOrderChange
  * @see QEvent#Type
  * @type Number
  */
QEvent.ZOrderChange = 0x7e;

/**
  * @default 127
  * @constant
  * @memberOf QEvent
  * @name HoverEnter
  * @see QEvent#Type
  * @type Number
  */
QEvent.HoverEnter = 0x7f;

/**
  * @default 128
  * @constant
  * @memberOf QEvent
  * @name HoverLeave
  * @see QEvent#Type
  * @type Number
  */
QEvent.HoverLeave = 0x80;

/**
  * @default 129
  * @constant
  * @memberOf QEvent
  * @name HoverMove
  * @see QEvent#Type
  * @type Number
  */
QEvent.HoverMove = 0x81;

/**
  * @default 130
  * @constant
  * @memberOf QEvent
  * @name AccessibilityDescription
  * @see QEvent#Type
  * @type Number
  */
QEvent.AccessibilityDescription = 0x82;

/**
  * @default 131
  * @constant
  * @memberOf QEvent
  * @name ParentAboutToChange
  * @see QEvent#Type
  * @type Number
  */
QEvent.ParentAboutToChange = 0x83;

/**
  * @default 132
  * @constant
  * @memberOf QEvent
  * @name WinEventAct
  * @see QEvent#Type
  * @type Number
  */
QEvent.WinEventAct = 0x84;

/**
  * @default 152
  * @constant
  * @memberOf QEvent
  * @name AcceptDropsChange
  * @see QEvent#Type
  * @type Number
  */
QEvent.AcceptDropsChange = 0x98;

/**
  * @default 153
  * @constant
  * @memberOf QEvent
  * @name MenubarUpdated
  * @see QEvent#Type
  * @type Number
  */
QEvent.MenubarUpdated = 0x99;

/**
  * @default 154
  * @constant
  * @memberOf QEvent
  * @name ZeroTimerEvent
  * @see QEvent#Type
  * @type Number
  */
QEvent.ZeroTimerEvent = 0x9a;

/**
  * @default 155
  * @constant
  * @memberOf QEvent
  * @name GraphicsSceneMouseMove
  * @see QEvent#Type
  * @type Number
  */
QEvent.GraphicsSceneMouseMove = 0x9b;

/**
  * @default 156
  * @constant
  * @memberOf QEvent
  * @name GraphicsSceneMousePress
  * @see QEvent#Type
  * @type Number
  */
QEvent.GraphicsSceneMousePress = 0x9c;

/**
  * @default 157
  * @constant
  * @memberOf QEvent
  * @name GraphicsSceneMouseRelease
  * @see QEvent#Type
  * @type Number
  */
QEvent.GraphicsSceneMouseRelease = 0x9d;

/**
  * @default 158
  * @constant
  * @memberOf QEvent
  * @name GraphicsSceneMouseDoubleClick
  * @see QEvent#Type
  * @type Number
  */
QEvent.GraphicsSceneMouseDoubleClick = 0x9e;

/**
  * @default 159
  * @constant
  * @memberOf QEvent
  * @name GraphicsSceneContextMenu
  * @see QEvent#Type
  * @type Number
  */
QEvent.GraphicsSceneContextMenu = 0x9f;

/**
  * @default 160
  * @constant
  * @memberOf QEvent
  * @name GraphicsSceneHoverEnter
  * @see QEvent#Type
  * @type Number
  */
QEvent.GraphicsSceneHoverEnter = 0xa0;

/**
  * @default 161
  * @constant
  * @memberOf QEvent
  * @name GraphicsSceneHoverMove
  * @see QEvent#Type
  * @type Number
  */
QEvent.GraphicsSceneHoverMove = 0xa1;

/**
  * @default 162
  * @constant
  * @memberOf QEvent
  * @name GraphicsSceneHoverLeave
  * @see QEvent#Type
  * @type Number
  */
QEvent.GraphicsSceneHoverLeave = 0xa2;

/**
  * @default 163
  * @constant
  * @memberOf QEvent
  * @name GraphicsSceneHelp
  * @see QEvent#Type
  * @type Number
  */
QEvent.GraphicsSceneHelp = 0xa3;

/**
  * @default 164
  * @constant
  * @memberOf QEvent
  * @name GraphicsSceneDragEnter
  * @see QEvent#Type
  * @type Number
  */
QEvent.GraphicsSceneDragEnter = 0xa4;

/**
  * @default 165
  * @constant
  * @memberOf QEvent
  * @name GraphicsSceneDragMove
  * @see QEvent#Type
  * @type Number
  */
QEvent.GraphicsSceneDragMove = 0xa5;

/**
  * @default 166
  * @constant
  * @memberOf QEvent
  * @name GraphicsSceneDragLeave
  * @see QEvent#Type
  * @type Number
  */
QEvent.GraphicsSceneDragLeave = 0xa6;

/**
  * @default 167
  * @constant
  * @memberOf QEvent
  * @name GraphicsSceneDrop
  * @see QEvent#Type
  * @type Number
  */
QEvent.GraphicsSceneDrop = 0xa7;

/**
  * @default 168
  * @constant
  * @memberOf QEvent
  * @name GraphicsSceneWheel
  * @see QEvent#Type
  * @type Number
  */
QEvent.GraphicsSceneWheel = 0xa8;

/**
  * @default 169
  * @constant
  * @memberOf QEvent
  * @name KeyboardLayoutChange
  * @see QEvent#Type
  * @type Number
  */
QEvent.KeyboardLayoutChange = 0xa9;

/**
  * @default 170
  * @constant
  * @memberOf QEvent
  * @name DynamicPropertyChange
  * @see QEvent#Type
  * @type Number
  */
QEvent.DynamicPropertyChange = 0xaa;

/**
  * @default 171
  * @constant
  * @memberOf QEvent
  * @name TabletEnterProximity
  * @see QEvent#Type
  * @type Number
  */
QEvent.TabletEnterProximity = 0xab;

/**
  * @default 172
  * @constant
  * @memberOf QEvent
  * @name TabletLeaveProximity
  * @see QEvent#Type
  * @type Number
  */
QEvent.TabletLeaveProximity = 0xac;

/**
  * @default 173
  * @constant
  * @memberOf QEvent
  * @name NonClientAreaMouseMove
  * @see QEvent#Type
  * @type Number
  */
QEvent.NonClientAreaMouseMove = 0xad;

/**
  * @default 174
  * @constant
  * @memberOf QEvent
  * @name NonClientAreaMouseButtonPress
  * @see QEvent#Type
  * @type Number
  */
QEvent.NonClientAreaMouseButtonPress = 0xae;

/**
  * @default 175
  * @constant
  * @memberOf QEvent
  * @name NonClientAreaMouseButtonRelease
  * @see QEvent#Type
  * @type Number
  */
QEvent.NonClientAreaMouseButtonRelease = 0xaf;

/**
  * @default 176
  * @constant
  * @memberOf QEvent
  * @name NonClientAreaMouseButtonDblClick
  * @see QEvent#Type
  * @type Number
  */
QEvent.NonClientAreaMouseButtonDblClick = 0xb0;

/**
  * @default 177
  * @constant
  * @memberOf QEvent
  * @name MacSizeChange
  * @see QEvent#Type
  * @type Number
  */
QEvent.MacSizeChange = 0xb1;

/**
  * @default 178
  * @constant
  * @memberOf QEvent
  * @name ContentsRectChange
  * @see QEvent#Type
  * @type Number
  */
QEvent.ContentsRectChange = 0xb2;

/**
  * @default 179
  * @constant
  * @memberOf QEvent
  * @name MacGLWindowChange
  * @see QEvent#Type
  * @type Number
  */
QEvent.MacGLWindowChange = 0xb3;

/**
  * @default 180
  * @constant
  * @memberOf QEvent
  * @name FutureCallOut
  * @see QEvent#Type
  * @type Number
  */
QEvent.FutureCallOut = 0xb4;

/**
  * @default 181
  * @constant
  * @memberOf QEvent
  * @name GraphicsSceneResize
  * @see QEvent#Type
  * @type Number
  */
QEvent.GraphicsSceneResize = 0xb5;

/**
  * @default 182
  * @constant
  * @memberOf QEvent
  * @name GraphicsSceneMove
  * @see QEvent#Type
  * @type Number
  */
QEvent.GraphicsSceneMove = 0xb6;

/**
  * @default 183
  * @constant
  * @memberOf QEvent
  * @name CursorChange
  * @see QEvent#Type
  * @type Number
  */
QEvent.CursorChange = 0xb7;

/**
  * @default 184
  * @constant
  * @memberOf QEvent
  * @name ToolTipChange
  * @see QEvent#Type
  * @type Number
  */
QEvent.ToolTipChange = 0xb8;

/**
  * @default 185
  * @constant
  * @memberOf QEvent
  * @name NetworkReplyUpdated
  * @see QEvent#Type
  * @type Number
  */
QEvent.NetworkReplyUpdated = 0xb9;

/**
  * @default 186
  * @constant
  * @memberOf QEvent
  * @name GrabMouse
  * @see QEvent#Type
  * @type Number
  */
QEvent.GrabMouse = 0xba;

/**
  * @default 187
  * @constant
  * @memberOf QEvent
  * @name UngrabMouse
  * @see QEvent#Type
  * @type Number
  */
QEvent.UngrabMouse = 0xbb;

/**
  * @default 188
  * @constant
  * @memberOf QEvent
  * @name GrabKeyboard
  * @see QEvent#Type
  * @type Number
  */
QEvent.GrabKeyboard = 0xbc;

/**
  * @default 189
  * @constant
  * @memberOf QEvent
  * @name UngrabKeyboard
  * @see QEvent#Type
  * @type Number
  */
QEvent.UngrabKeyboard = 0xbd;

/**
  * @default 191
  * @constant
  * @memberOf QEvent
  * @name MacGLClearDrawable
  * @see QEvent#Type
  * @type Number
  */
QEvent.MacGLClearDrawable = 0xbf;

/**
  * @default 192
  * @constant
  * @memberOf QEvent
  * @name StateMachineSignal
  * @see QEvent#Type
  * @type Number
  */
QEvent.StateMachineSignal = 0xc0;

/**
  * @default 193
  * @constant
  * @memberOf QEvent
  * @name StateMachineWrapped
  * @see QEvent#Type
  * @type Number
  */
QEvent.StateMachineWrapped = 0xc1;

/**
  * @default 194
  * @constant
  * @memberOf QEvent
  * @name TouchBegin
  * @see QEvent#Type
  * @type Number
  */
QEvent.TouchBegin = 0xc2;

/**
  * @default 195
  * @constant
  * @memberOf QEvent
  * @name TouchUpdate
  * @see QEvent#Type
  * @type Number
  */
QEvent.TouchUpdate = 0xc3;

/**
  * @default 196
  * @constant
  * @memberOf QEvent
  * @name TouchEnd
  * @see QEvent#Type
  * @type Number
  */
QEvent.TouchEnd = 0xc4;

/**
  * @default 197
  * @constant
  * @memberOf QEvent
  * @name NativeGesture
  * @see QEvent#Type
  * @type Number
  */
QEvent.NativeGesture = 0xc5;

/**
  * @default 198
  * @constant
  * @memberOf QEvent
  * @name Gesture
  * @see QEvent#Type
  * @type Number
  */
QEvent.Gesture = 0xc6;

/**
  * @default 199
  * @constant
  * @memberOf QEvent
  * @name RequestSoftwareInputPanel
  * @see QEvent#Type
  * @type Number
  */
QEvent.RequestSoftwareInputPanel = 0xc7;

/**
  * @default 200
  * @constant
  * @memberOf QEvent
  * @name CloseSoftwareInputPanel
  * @see QEvent#Type
  * @type Number
  */
QEvent.CloseSoftwareInputPanel = 0xc8;

/**
  * @default 201
  * @constant
  * @memberOf QEvent
  * @name UpdateSoftKeys
  * @see QEvent#Type
  * @type Number
  */
QEvent.UpdateSoftKeys = 0xc9;

/**
  * @default 202
  * @constant
  * @memberOf QEvent
  * @name GestureOverride
  * @see QEvent#Type
  * @type Number
  */
QEvent.GestureOverride = 0xca;

/**
  * @default 203
  * @constant
  * @memberOf QEvent
  * @name WinIdChange
  * @see QEvent#Type
  * @type Number
  */
QEvent.WinIdChange = 0xcb;

/**
  * @default 1000
  * @constant
  * @memberOf QEvent
  * @name User
  * @see QEvent#Type
  * @type Number
  */
QEvent.User = 0x3e8;

/**
  * @default 65535
  * @constant
  * @memberOf QEvent
  * @name MaxUser
  * @see QEvent#Type
  * @type Number
  */
QEvent.MaxUser = 0xffff;

/**
  * @constructor 
  * @memberOf QEvent
  * @name Type
  */
QEvent.Type = function(value){;};



/**
  * @name accept
  * @function
  * @memberOf QEvent.prototype
  * @returns {undefined}
  */
QEvent.prototype.accept = function(){return undefined;};

/**
  * @name ignore
  * @function
  * @memberOf QEvent.prototype
  * @returns {undefined}
  */
QEvent.prototype.ignore = function(){return undefined;};

/**
  * @name isAccepted
  * @function
  * @memberOf QEvent.prototype
  * @returns {Boolean}
  */
QEvent.prototype.isAccepted = function(){return new Boolean();};

/**
  * @name setAccepted
  * @function
  * @memberOf QEvent.prototype
  * @param {Boolean} accepted
  * @returns {undefined}
  */
QEvent.prototype.setAccepted = function(accepted){return undefined;};

/**
  * @name spontaneous
  * @function
  * @memberOf QEvent.prototype
  * @returns {Boolean}
  */
QEvent.prototype.spontaneous = function(){return new Boolean();};

/**
  * @name type
  * @function
  * @memberOf QEvent.prototype
  * @returns {QApplication.Type}
  */
QEvent.prototype.type = function(){return new QApplication.Type();};

