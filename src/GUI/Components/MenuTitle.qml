import QtQuick 2.15
import QtQuick.Controls 1.4
import QtQuick.Shapes 1.4

Shape {
	id: root

	property alias text: label.text;

	anchors {
		top: parent.top
		topMargin: sizes_spacing
			
		horizontalCenter: parent.horizontalCenter
	}

	width: sizes_titleWidth
	height: sizes_titleHeight

	property int sizes_offset: height/2

	ShapePath {
		fillColor: Qt.rgba(.2, .2, .2, .9)
		strokeWidth: 3
		strokeColor: Qt.rgba(.8, .8, .8, 1)

		startX: sizes_offset; startY: 0
		PathLine { x: root.width; y: 0 }
		PathLine { x: root.width-sizes_offset; y: root.height }
		PathLine { x: 0; y: root.height }
		PathLine { x: sizes_offset; y: 0 }
	}

	Label {
		id: label

		color: "white"
		font {
			pixelSize: root.width*.1
		}

		anchors {
			verticalCenter: root.verticalCenter
			horizontalCenter: root.horizontalCenter
		}
	}
}