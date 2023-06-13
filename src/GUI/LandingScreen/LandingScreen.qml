import QtQuick 2.15
import QtQuick.Controls 1.4

Rectangle {
	id: root
	color: "transparent"
	
	Image {
		anchors {
			horizontalCenter : root.horizontalCenter
			verticalCenter : root.verticalCenter
		}
		
		fillMode: Image.PreserveAspectFit
		source: "logo_no_bg.png"
	}

	Label {
		text: "Open"

		anchors {
			top: root.top
			left: root.left
			leftMargin: 150
			topMargin: 150
		}

		color: "white"
		font.pixelSize: 50
	}

	Label {
		id: textDance
		text: "Dance"

		anchors {
			bottom: root.bottom
			right: root.right
			rightMargin: 150
			bottomMargin: 150
		}

		color: "white"
		font.pixelSize: 50
	}

	Label {
		id: textContinue
		text: qsTr("Click anywhere to continue")
		
		anchors {
			horizontalCenter: root.horizontalCenter
			bottom: root.bottom
			bottomMargin: root.height/4
		}

		opacity: 0
		SequentialAnimation {
			running: true
			PauseAnimation { duration: 1000 }
			
			SequentialAnimation {
				loops: Animation.Infinite;
				NumberAnimation { target: textContinue; property: "opacity"; to: 1; duration: 1000 }
				NumberAnimation { target: textContinue; property: "opacity"; to: 0; duration: 1000 }
			}
		}

		color: "white"
		font.pixelSize: 50
	}

	MouseArea {
		anchors.fill: parent
		onClicked: root.visible = false
	}
}