
// var res = include("P:/projects/r3/repo/runtime/Debug/client/test.js");
// print("from main2: ", script.filePath, ", ", res);


importExtension('qt');
importExtension('qt.core');
importExtension('qt.gui');
importExtension('qt.uitools');
importExtension('qt.sql');

var prot = {a:1};


global.uiLoader = include(':/uiLoader.js');

var network = include(':/network.js');

network.onStateChanged.connect(function(ec,numChannels){
	print('network state changed: ', ec, ", ", numChannels);
})


global.mainWindow = uiLoader.load(new QFile(':/mainWindow.ui'));
mainWindow.windowIcon = new QIcon(":/mainWindowIcon.png");

mainWindow.ui.actionNetwork.activated.connect(function()
{
   network.showDialog();
});

mainWindow.show();

mainWindow.closeEvent = function(evt)
{
	print('mainWindow.closeEvent');
};

QCoreApplication.exec();
