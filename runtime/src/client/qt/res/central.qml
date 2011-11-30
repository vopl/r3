import MyLib 1.0
import QtQuick 1.0

Host {
    width: 300; height: 500
    
    Agent {}

    Rectangle {
        anchors.fill: parent
        objectName: "rect"
    }

    Text { text: "currentDateTime" }
    
	Keys.onPressed:  {
        console.log("move left");
        scale = 0.5;
    }    

    function myFunc()
    {
        console.log("myFunc");
    }

}


