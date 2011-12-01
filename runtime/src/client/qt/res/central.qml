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
	}

	Component.onCompleted: {console.log("Completed Running!"); agent.send(220);}
	Component.onDestruction: console.log("Destruction Beginning!")
}
