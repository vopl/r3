
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
	
	if(numChannels)
	{
		var agent = network.allocAgent();
		agent.onSendComplete.connect(function(ec, data, service){
			//print('onSendComplete: ', data);
		});
		agent.onReceive.connect(function(data, service){
			//print('onReceive: ', data);
			agent.send(data, "echo");
		});
		agent.send("data", "echo");
	}
})


global.mainWindow = uiLoader.load(new QFile(':/mainWindow.ui'));
mainWindow.windowIcon = new QIcon(":/mainWindowIcon.png");

mainWindow.ui.actionNetwork.activated.connect(function()
{
   network.showDialog();
});

mainWindow.show();

mainWindow.__proto__.closeEvent = function(evt)
{
	print('mainWindow.closeEvent: ',evt.type());

	network.stop();
};

QCoreApplication.exec();
