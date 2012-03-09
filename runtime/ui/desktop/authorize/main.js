var w = uiLoader.load('main.ui');

var agent = network.allocAgent();
agent.service = "authorize";

agent.onReceive.connect(function(data){
	tlog('receive,',dumps(data));
});

agent.onSendComplete.connect(function(ec){
	tlog('sendComplete,',dumps(ec));
});

w.ui.buttonBox.button(QDialogButtonBox.Ok).clicked.connect(function(){
	agent.send({
		login:w.ui.login.text,
		password:w.ui.password.text
	});
});

w.ui.buttonBox.button(QDialogButtonBox.Cancel).clicked.connect(function(){
	w.ui.login.text = "";
	w.ui.password.text = "";

});

w;