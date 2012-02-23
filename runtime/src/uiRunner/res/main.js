importExtension('qt');
importExtension('qt.core');
importExtension('qt.gui');
importExtension('qt.uitools');
importExtension('qt.sql');



global.uiLoader = include(':/uiLoader.js');
global.network = include(':/network.js');

function onFirstConnect(ec,numChannels)
{
	if(numChannels)
	{
		//log('first connection established');
		//первое соединение установлено, грузить клиентские скрипты
		network.onStateChanged.disconnect(onFirstConnect);
		network.showDialog(false);

		include(QDir.currentPath()+'/../../ui/desktop/main.js');
	}
	else
	{
		//log('first connection NOT established');
		//нет первого соединения, показать диалог
		network.showDialog();
	}
}
network.onStateChanged.connect(onFirstConnect);




QCoreApplication.exec();
