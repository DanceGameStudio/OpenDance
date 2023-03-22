import QtQuick 2.15
import QtQuick.Controls 1.4
import QtQuick.Shapes 1.4

Rectangle {
	id: root
	color: "transparent"

	Shape {
		id: shape

		anchors {
			top: parent.top
			topMargin: 50
			
			horizontalCenter: parent.horizontalCenter
		}

		width: 400
		height: 100

		ShapePath {
			fillColor: Qt.rgba(.2, .2, .2, .9)
			strokeWidth: 3
			strokeColor: Qt.rgba(.8, .8, .8, 1)

			startX: 50; startY: 0
			PathLine { x: shape.width; y: 0 }
			PathLine { x: shape.width-50; y: shape.height }
			PathLine { x: 0; y: shape.height }
			PathLine { x: 50; y: 0 }
		}
	}

}