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

	radius: width/20
	color: color_bgTrans
	border {
		color: color_bg
		width: 3
	}
	
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
			bottomMargin: 13

			left: parent.left
			leftMargin: 10
			right: parent.right
			rightMargin: 10
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
			anchors.fill: parent
		}
	}

	MouseArea {
		id: mouse

		anchors.fill: parent

		cursorShape: Qt.PointingHandCursor
		onClicked: {
			view.setSelected(idx)
		}
	}	
}