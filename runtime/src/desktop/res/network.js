
function Network()
{
	var addr = 
	{
		host:'localhost',
		service:'29431',
		connect:true,
	};
	var connectionInProgress = false;
	var dialog = uiLoader.load(new QFile(':/networkDialog.ui'), this);
	var client = new Client();
	
	this.onStateChanged = new Signal();

	this.toString = function()
	{
		return "Network";
	};
	
	function checkConnection()
	{
		print(this, ".", 'checkConnection');
	}
	var checkConnectionTimer = new QTimer();
	checkConnectionTimer.timeout.connect(this, checkConnection);
	checkConnectionTimer.interval = 500;
	checkConnectionTimer.start();
	
}



var network = new Network();
network;
