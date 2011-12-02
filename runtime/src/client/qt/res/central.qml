import QtQuick 1.0
import Client 1.0

Item {
    Image
    {
        anchors.horizontalCenter: parent.horizontalCenter
    }

	Agent
	{
		id: agent
		property int i: 220
		
		function trata(data, service)
		{
			if(! (data%1000))
			{
				console.log("receive from "+service+", data: "+data); 
			}
			send(data+1, "echo");
		}
		onReceive: trata(data, service)
	}
	
	//agent.onReceive: {console.log("receive");}

	Component.onCompleted: {console.log("Completed Running!"); agent.send(0, "echo");}
	Component.onDestruction: console.log("Destruction Beginning!")
}
