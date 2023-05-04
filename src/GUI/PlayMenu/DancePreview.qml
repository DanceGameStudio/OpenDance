import QtQuick 2.15
import QtQuick.Controls 1.4

Rectangle {
	id: root
	width: sizes_danceWidth
	height: sizes_danceHeight
	
	color: "transparent"
	/*
	color: "red"
	border {
		color: "green"
		width: 3
	}
	*/

	signal moveToMe
	property bool isCenterItem
	
	NumberAnimation {
		id: animW
		properties: "width"
		target: rect
		running: false
		duration: 200
	}
	NumberAnimation {
		id: animH
		properties: "height"
		target: rect
		running: false
		duration: 200
	}

	onIsCenterItemChanged: {
		animW.from = rect.width;
		animW.to = isCenterItem ? 500 : 300;
		animW.start();

		animH.from = rect.height;
		animH.to = isCenterItem ? 150 : 100;
		animH.start();
	}

	Rectangle {
		id: rect
		color: "grey"
		width: 300
		height: 100

		anchors {
			verticalCenter: parent.verticalCenter
			horizontalCenter: parent.horizontalCenter
		}
			
		Text {
			anchors.fill: parent
			font.pixelSize: 30
			color: "white"
			text: model.name
			horizontalAlignment: Text.AlignHCenter
			verticalAlignment: Text.AlignVCenter
		}

		border {
			color: "darkgrey"
			width: 5
		}
	}

	MouseArea {
		id: mouse

		anchors.fill: parent

		cursorShape: Qt.PointingHandCursorShape
		onClicked: {
			if (!isCenterItem) {
				moveToMe()
			}
		}
	}
	
}