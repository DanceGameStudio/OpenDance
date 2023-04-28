import QtQuick 2.15
import QtQuick.Controls 1.4
import QtQuick.Shapes 1.4

Shape {
	id: root

	//property string text;
	property alias text: label.text;

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
		PathLine { x: root.width; y: 0 }
		PathLine { x: root.width-50; y: root.height }
		PathLine { x: 0; y: root.height }
		PathLine { x: 50; y: 0 }
	}

	Label {
		id: label

		color: "white"
		font {
			pixelSize: 30
		}

		anchors {
			verticalCenter: root.verticalCenter
			horizontalCenter: root.horizontalCenter
		}
	}
}