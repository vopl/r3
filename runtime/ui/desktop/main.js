var f = new QFile('mainWindow.ui');

global.mainWindow = uiLoader.load(f);
mainWindow.windowIcon = new QIcon('mainWindowIcon.png');

mainWindow.ui.actionNetwork.activated.connect(function()
{
   network.showDialog();
});

mainWindow.show();

mainWindow.__proto__.closeEvent = function(evt)
{
	log('mainWindow.closeEvent:', evt.type());

	network.stop();
};
