global.client = new Client();
client.addr = 
{
	host:'localhost',
	service:'29431',
	connect:true,
};
client.connectionInProgress = false;

client.closeSession = function()
{
	if(global.session)
	{
		networkDialog.log('close session');
		global.session.close();
		delete global.session;
	}
	client.updateStatus();
}
client.checkConnection = function()
{
	client.updateStatus();
	
	if(!global.session && client.addr.connect && !client.connectionInProgress)
	{
		networkDialog.log('open session');
		client.connectionInProgress = true;
		client.sessionStart(client.addr.host, client.addr.service);
	}
}
var checkConnectionTimer = new QTimer();
checkConnectionTimer.timeout.connect(client.checkConnection);
checkConnectionTimer.interval = 500;
checkConnectionTimer.start();

client.onSession.connect(function(s, ec){
	client.connectionInProgress = false;
	
    if(ec.fail)
    {
		networkDialog.log(ec);
    }
    
    if(s)
    {
        global.session = s;
		global.session.stateChanged.connect(function(ec, numChannels){
			if(ec.fail)
			{
				networkDialog.log(ec);
			}
			client.updateStatus();
		});
    }
	client.updateStatus();
})

client.updateStatus = function()
{
	if(global.session)
	{
		networkDialog.ui._numChannels.text = global.session.numChannels;
	}
	else
	{
		networkDialog.ui._numChannels.text = 0;
	}
}
global.session = null;


global.mainWindow = uiLoader.load(new QFile(':/mainWindow.ui'));
mainWindow.windowIcon = new QIcon(":/mainWindowIcon.png");

global.networkDialog = uiLoader.load(new QFile(':/networkDialog.ui'), mainWindow);

function cancelAddr()
{
	networkDialog.ui._host.text = client.addr.host;
	networkDialog.ui._service.text = client.addr.service;
	networkDialog.ui._connect.checked = client.addr.connect;
}
cancelAddr();

function applyAddr()
{
	var isChanged = false;
	if(	client.addr.host != networkDialog.ui._host.text ||
		client.addr.service != networkDialog.ui._service.text||
		client.addr.connect != networkDialog.ui._connect.checked)
	{
		isChanged = true;
	}
	
	client.addr.host = networkDialog.ui._host.text;
	client.addr.service = networkDialog.ui._service.text;
	client.addr.connect = networkDialog.ui._connect.checked;
	
	if(isChanged)
	{
		client.closeSession();
	}
}

networkDialog.ui._buttons.button(QDialogButtonBox.Ok).clicked.connect(function(){
	applyAddr();
	networkDialog.visible = false;
});

networkDialog.ui._buttons.button(QDialogButtonBox.Apply).clicked.connect(function(){
	applyAddr();
});

networkDialog.ui._buttons.button(QDialogButtonBox.Cancel).clicked.connect(function(){
	cancelAddr();
	networkDialog.visible = false;
});

networkDialog.log = function(str)
{
	str = (new Date).toLocaleString() + " " + str;
	this.ui._log.appendPlainText(str);
}















mainWindow.ui.actionNetwork.activated.connect(function()
{
    networkDialog.visible = !networkDialog.visible;
});

mainWindow.show();
