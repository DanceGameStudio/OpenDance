import QtQuick 2.15
import Game 1.0

Rectangle {
	id: root

	color: color_bgTrans
	border {
		width: 5
		color: color_bg
	}

	property alias content: content

	VideoStreamContent {
		id: content
		anchors {
			fill: parent
			topMargin: root.border.width
			leftMargin: root.border.width
			rightMargin: root.border.width
			bottomMargin: root.border.width
		}
	}
}