import QtQuick 2.15
import QtQuick.Controls 2.15

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
		id: dancesList
		model: nameModel
		orientation: ListView.Horizontal
		clip: true

		property DancePreview centerItem;
		onContentXChanged: {
			dancesList.centerItem = itemAt(contentX + width/2,height/2)
		}

		height: 150
		anchors {
			leftMargin: 50
			left: parent.left
			
			rightMargin: anchors.leftMargin
			right: parent.right

			verticalCenter: parent.verticalCenter
		}
		
        NumberAnimation {
			id: anim
			properties: "contentX"
			target: dancesList
			running: false
			from: 100
			duration: 200
		}

		delegate: DancePreview {
			id: prev

			onMoveToMe: {
				anim.from = dancesList.contentX;
				anim.to = prev.x - (dancesList.width/2) + 250;
				anim.start();
			}

			isCenterItem: dancesList.centerItem == prev
		}
		
		Component.onCompleted: {
			dancesList.contentX = dancesList.contentWidth/2 + 250
		}
	}

	StyledButton {
		id: playButton

		text: "Start"
		fontSize: 50

		width: root.width * .2
		height: root.height * .2
		anchors {
			horizontalCenter: root.horizontalCenter
			bottom: parent.bottom
			bottomMargin: 50
		}

		onClicked: root.gameSelected()
	}
}