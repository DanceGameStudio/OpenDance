import QtQuick 2.15
import QtQuick.Controls 1.4

Rectangle {
	id: root
	color: "transparent"
    
	MenuTitle {
		text: "Credits"
	}

	ListModel {
        id: model
        ListElement {
            name: "Munir Z."
            role: "Hurensohn"
        }
        
        ListElement {
            name: "Leon T."
            role: "Schnacker"
        }
        
        ListElement {
            name: "Tim S."
            role: "Brillenschlange"
        }
        
        ListElement {
            name: "Jonas C."
            role: "Rentner"
        }
        
        ListElement {
            name: "Ben S."
            role: "Geiler Typ"
        }
    }

    ListView {
        id: list
        anchors {
            verticalCenter: root.verticalCenter
            horizontalCenter: root.horizontalCenter
        }
        spacing: 25
        width: root.width*.5
        height: root.height*.5

        model: model
        delegate: Rectangle {
		    color: Qt.rgba(.2, .2, .2, .9)
		    border {
                width: 3
		        color: Qt.rgba(.8, .8, .8, 1)
            }
            
            width: list.width
            height: root.height*.1

            Text {
                anchors {
                    verticalCenter: parent.verticalCenter
                    horizontalCenter: parent.horizontalCenter
                }
                font {
                    pixelSize: 40
                }
                color: "white"
                text: name + ": " + role
            }
        }
    }
	
	BackButton {}
}