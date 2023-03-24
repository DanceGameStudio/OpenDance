import QtQuick 2.15
import Game 1.0

Rectangle {
	id: root
	
	color: "transparent"
	border {
		width: 5
		color: "grey"
	}

	/*
	AnimatedImage  {
		source: "dancing-robo.gif"

		anchors.fill: parent
	}
	*/

	VideoStreamContent {
		anchors {
			fill: parent
			topMargin: root.border.width
			leftMargin: root.border.width
			rightMargin: root.border.width
			bottomMargin: root.border.width
		}
	}
}