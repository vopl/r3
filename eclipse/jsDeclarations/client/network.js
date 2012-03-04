


function Network()
{
	var addr = 
	{
		host:'localhost',
		service:'29431',
		connect:true,
	};
	var connectionInProgress = false;
	var dialog = uiLoader.load(':/networkDialog.ui');
	var client = new Client();
	var session = undefined;

	this.stop = function()
	{
		dialog.visible = false;
		checkConnectionTimer.stop();
		if(session)
		{
			session.close();
			session = undefined;
		}
	}
	
	this.showDialog = function(show)
	{
		if(undefined == show) show = true;
		dialog.visible = show;
	}
	this.onStateChanged = new Signal();

	this.toString = function()
	{
		return "Network";
	};
	
	this.allocAgent = function()
	{
		if(!session)
		{
			throw "unable to allocate agent, connection in down";
		}
		
		return session.allocAgent();
	}
	
	function checkConnection()
	{
		updateStatus();
		
		if(!session && addr.connect && !connectionInProgress)
		{
			log('open session');
			connectionInProgress = true;
			client.sessionStart(addr.host, addr.service);
		}
	}
	
	var network = this;
	client.onSession.connect(function(s, ec)
	{
		connectionInProgress = false;
		
		if(ec.fail)
		{
			log(ec);
		}
		
		if(s)
		{
			session = s;
			session.onStateChanged.connect(function(ec, numChannels)
			{
				if(ec.fail)
				{
					log(ec);
				}
				updateStatus();
				network.onStateChanged(ec, numChannels);
			});

			network.onStateChanged(ec, session.numChannels);
		}
		else
		{
			network.onStateChanged(ec, 0);
		}
		updateStatus();
	})
	
	var checkConnectionTimer = new QTimer();
	checkConnectionTimer.timeout.connect(this, checkConnection);
	checkConnectionTimer.interval = 500;
	checkConnectionTimer.start();
	
	function closeSession()
	{
		if(session)
		{
			log('close session');
			session.close();
			session = undefined;
		}
		updateStatus();
	}
	
	function updateStatus()
	{
		if(session)
		{
			dialog.ui._numChannels.text = session.numChannels;
		}
		else
		{
			dialog.ui._numChannels.text = 0;
		}
	}
	
	
	
	
	
	
	
	function cancelAddr()
	{
		dialog.ui._host.text = addr.host;
		dialog.ui._service.text = addr.service;
		dialog.ui._connect.checked = addr.connect;
	}
	cancelAddr();
	
	function applyAddr()
	{
		var addressChanged = false;
		if(	addr.host != dialog.ui._host.text ||
			addr.service != dialog.ui._service.text)
		{
			addressChanged = true;
		}
		
		var connectChanged = false;
		if(addr.connect != dialog.ui._connect.checked)
		{
			connectChanged = true;
		}
		addr.host = dialog.ui._host.text;
		addr.service = dialog.ui._service.text;
		addr.connect = dialog.ui._connect.checked;
		
		if(addressChanged)
		{
			log('address changed, '+addr.host+':'+addr.service);
		}
		
		if(addressChanged || connectChanged)
		{
			closeSession();
		}
	}
	
	
	dialog.ui._buttons.button(QDialogButtonBox.Ok).clicked.connect(function(){
		applyAddr();
		dialog.visible = false;
	});

	dialog.ui._buttons.button(QDialogButtonBox.Apply).clicked.connect(function(){
		applyAddr();
	});

	dialog.ui._buttons.button(QDialogButtonBox.Cancel).clicked.connect(function(){
		cancelAddr();
		dialog.visible = false;
	});
	dialog.__proto__.closeEvent = function()
	{
		cancelAddr();
	}
	
	
	function log(str)
	{
		str = (new Date).toLocaleString() + " " + str;
		dialog.ui._log.appendPlainText(str);
	}
	
	
	
}



var network = new Network();
network;
