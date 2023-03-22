import QtQuick 2.15
import QtQuick.Controls 1.4

Rectangle {
	id: root
	
	width: 10 + Math.random()*10
	height: width
	
	property int xMax
	property int yMax

	x: root.xMax*Math.random()
	y: root.yMax*Math.random()

	opacity: .5 + Math.random()*.3
	color: {
		var colors = [
			Qt.rgba(1,0,0),
			Qt.rgba(1,1,0),
			Qt.rgba(1,0,1),
			Qt.rgba(0,1,0),
			Qt.rgba(0,0,1),
		];

		return colors[Math.floor(colors.length*Math.random())]
	}
	
	RotationAnimator {
		loops: Animation.Infinite
        target: root;
        from: 0;
        to: 360;
        duration: 5000 + Math.random()*5000
        running: true
    }

	SequentialAnimation {
		running: false
		id: animationWrap

		NumberAnimation {
			id: animationInit
			target: root
			property: "y"

			to: 0
			duration: 5000*(root.y/root.yMax)
		}
		
		NumberAnimation {
			loops: Animation.Infinite
			target: root
			property: "y"

			from: root.yMax
			to: 0
			duration: 5000
		}
    }
		
	Connections {
		target: root
		function onYChanged() {
			animationInit.from = root.y
			animationWrap.running = true		
			enabled = false
		}
		enabled: true
	}
}