//////////////////////////////////////////////////////////////////////////
global.mainWindow = uiLoader.load('mainWindow.ui');
mainWindow.windowIcon = new QIcon('mainWindowIcon.png');

mainWindow.ui.actionNetwork.activated.connect(function()
{
   network.showDialog();
});

//////////////////////////////////////////////////////////////////////////
mainWindow.ui.actionFull_screen.triggered.connect(function(fs)
{
    if(fs)
    {
        mainWindow.showFullScreen();
    }
    else
    {
        mainWindow.showNormal();
    }
});

//////////////////////////////////////////////////////////////////////////
mainWindow.__proto__.closeEvent = function(evt)
{
	log('mainWindow.closeEvent:', evt.type());

	network.stop();
};

//////////////////////////////////////////////////////////////////////////
mainWindow.show();
