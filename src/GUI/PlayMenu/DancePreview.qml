import QtQuick 2.15
import QtQuick.Controls 1.4

Rectangle {
	id: root
	color: "grey"

	width: 300
	height: 100

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