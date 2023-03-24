import QtQuick 2.15
import QtQuick.Controls 1.4

Rectangle {
	id: root
	color: "transparent"

	signal gameSelected

	ListModel {
		id: nameModel
		ListElement { name: "1" }
		ListElement { name: "2" }
		ListElement { name: "3" }
		ListElement { name: "4" }
		ListElement { name: "5" }
		ListElement { name: "6" }
		ListElement { name: "7" }
		ListElement { name: "8" }
		ListElement { name: "9" }
		ListElement { name: "10" }
		ListElement { name: "11" }
		ListElement { name: "12" }
		ListElement { name: "13" }
		ListElement { name: "14" }
		ListElement { name: "15" }
	}

	ListView {
		model: nameModel
		layoutDirection: Qt.LeftRoRight
		orientation: ListView.Horizontal
		clip: true

		height: 100
		anchors {
			leftMargin: 50
			left: parent.left
			
			rightMargin: anchors.leftMargin
			right: parent.right

			verticalCenter: parent.verticalCenter
		}

		delegate: DancePreview {
		}
	}

	/*
	StyledButton {
		id: playButton

		text: "Play"

		width: 300
		height: 200
		anchors {
			horizontalCenter: root.horizontalCenter
			verticalCenter: root.verticalCenter
		}

		onClicked: root.gameSelected()
	}
	*/
}