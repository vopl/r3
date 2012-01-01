import QtQuick 1.0
import Client 1.0

Item {
	Text {
		id: label
		color: "blue"
		anchors.centerIn: parent
		text: "sfdg"
		width: 400
	}

	Image {
             id: background
             //anchors.fill: parent
             source: "background.jpg"
             //fillMode: Image.PreserveAspectCrop
         }

	
	function start()
	{
		var ld = "very long";
		//ld = [ld,ld,ld,ld,ld];
		//ld = {a:ld,b:ld};
		//ld = [ld,ld,ld,ld,ld];
		//ld = [ld,ld,ld,ld,ld];
		//ld = [ld,ld,ld,ld,ld];
		//ld = [ld,ld,ld,ld,ld];
		agent.send({cnt:0,ld:ld}, "echo");
		agent.send({cnt:10,ld:ld}, "echo");
		agent.send({cnt:20,ld:ld}, "echo");
		agent.send({cnt:30,ld:ld}, "echo");
		agent.send({cnt:40,ld:ld}, "echo");
		agent.send({cnt:50,ld:ld}, "echo");
		agent.send({cnt:60,ld:ld}, "echo");
		agent.send({cnt:70,ld:ld}, "echo");
		agent.send({cnt:80,ld:ld}, "echo");
		agent.send({cnt:90,ld:ld}, "echo");
		agent.send({cnt:100,ld:ld}, "echo");
		
		console.log("start ping pong")
	}

	property int numChannelsWas:0
	Agent
	{
		id: agent
		property int cnt: 0
		
		function _receive(data, service)
		{
			if(!(cnt % 100))
			{
				label.text=cnt;
			}
			cnt++;
			data.cnt++;
			send(data, "echo");
		}
		onReceive: _receive(data, service)
		
		
		function _channels(numChannels)
		{
			if(!(numChannels%100))
			{
				console.log("----------------- numChannels: "+numChannels);
			}
			if(!numChannelsWas && numChannels)
			{
				start();
			}
			numChannelsWas = numChannels;
		}
		onNumChannelsChanged: _channels(numChannels)
	}
	

	Component.onCompleted: 
	{
		console.log("Component.onCompleted")
		//start();
	}
	Component.onDestruction: console.log("Destruction Beginning!")
}
