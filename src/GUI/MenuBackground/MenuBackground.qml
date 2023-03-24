import QtQuick 2.15
import QtQuick.Controls 1.4

Rectangle {
	id: root
	color: "transparent"

	/*
	AnimatedImage  {
		source: "dancing-robo.gif"

		anchors.fill: parent
	}
	*/

	Repeater {
		model: 50
		delegate: MenuBackgroundParticle {
			id: particle

			yMax: root.height
			xMax: root.width
		}
	}
}