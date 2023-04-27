import QtQuick 2.15
import QtQuick.Controls 1.4
import QtMultimedia 5.15

Rectangle {
	id: root

	signal clicked
	property alias text: label.text
	property alias fontSize: label.font.pixelSize

	opacity: mouse.containsMouse ? (mouse.containsPress ? .9 : 1) : .7
	radius: width/20
	color: Qt.rgba(.2, .2, .2, .9)

	border {
		color: Qt.rgba(.8, .8, .8, 1)
		width: 3
	}
	
    SoundEffect {
        id: soundClick
        source: "ui-click.mp3"
    }
    SoundEffect {
        id: soundHover
        source: "ui-hover.mp3"
    }

	Text {
		id: label
		color: "white"

		anchors {
			verticalCenter: root.verticalCenter
			horizontalCenter: root.horizontalCenter
		}
	}

	MouseArea {
		id: mouse
		hoverEnabled: true
		anchors.fill: root
		onClicked: { soundClick.play(); root.clicked() }
		cursorShape: Qt.PointingHandCursor
	}
}