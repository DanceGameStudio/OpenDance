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
            name: "Munir Zohbi"
            role: "Backend"
        }
        
        ListElement {
            name: "Leon Theodoridis"
            role: "Backend"
        }
        
        ListElement {
            name: "Tim Skripalle"
            role: ""
        }
        
        ListElement {
            name: "Jonas Christoph"
            role: ""
        }
        
        ListElement {
            name: "Ben Stiebeiner"
            role: "Frontend"
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

        interactive: false

        model: model
        delegate: Rectangle {
		    color: color_bgTrans
		    border {
                width: 3
		        color: color_bg
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
                text: name // + ": " + role
            }
        }
    }
	
	BackButton {}
}