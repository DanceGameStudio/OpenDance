import QtQuick 2.15
import QtQuick.Controls 1.4

Rectangle {
	id: root
	width: sizes_danceWidth
	height: sizes_danceHeight
	//opacity: PathView.opacity
	scale: PathView.scale
	
	property int idx: 0
	property bool isSelected: false

	color: "transparent"

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
			view.setSelected(idx)
		}
	}
	
}