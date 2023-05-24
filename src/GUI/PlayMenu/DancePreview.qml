import QtQuick 2.15
import QtQuick.Controls 1.4
import QtMultimedia 5.15


// https://www.codecguide.com/download_kl.htm

Rectangle {
	id: root
	width: sizes_danceWidth
	height: sizes_danceHeight
	//opacity: PathView.opacity
	scale: PathView.scale

	/*
	color: Qt.rgba(.2, .2, .2, .9)
	border {
		width: 2
		color: Qt.rgba(.8, .8, .8, 1)
	}
	*/
	color: "transparent"
	
	property int idx: 0
	property bool isSelected: false

	onIsSelectedChanged: {
		if (isSelected) {
			player.play();
		} else {
			player.pause();
		}
	}
	
	Text {
		anchors {
			horizontalCenter: parent.horizontalCenter
			top: parent.top
			topMargin: 5
		}
		font.pixelSize: 20
		color: "white"
		text: model.name
		horizontalAlignment: Text.AlignHCenter
		verticalAlignment: Text.AlignVCenter
	}

	Rectangle {
		id: rect

		color: "transparent"

		anchors {
			top: parent.top
			topMargin: 35
			bottom: parent.bottom
			bottomMargin: 5
			left: parent.left
			right: parent.right
		}

		MediaPlayer {
			id: player
			source: model.video
			autoPlay: false
			loops: MediaPlayer.Infinite
		}

		VideoOutput {
			id: videoOutput
			source: player
			//anchors.fill: parent
			anchors {
				left: parent.left
				right: parent.right
				top: parent.top
				bottom: parent.bottom
			}
		}
	}

	MouseArea {
		id: mouse

		anchors.fill: parent

		cursorShape: Qt.PointingHandCursorShape
		onClicked: {
			view.setSelected(idx)
		}
	}	
}