import QtQuick 2.15
import QtQuick.Controls 1.4

Rectangle {
	id: root
	color: "transparent"

	Item {
		id: container
		
		anchors.fill: parent

		VideoStream {
			id: streamBig
			anchors {
				fill: parent
				topMargin: (container.width + container.height)/75
				leftMargin: anchors.topMargin
				rightMargin: anchors.topMargin
				bottomMargin: anchors.topMargin
			}
		}

		VideoStream {
			id: streamSmall

			width: streamBig.width * .3
			height: streamBig.height * .3

			anchors {
				right: streamBig.right
				rightMargin: -(container.width - streamBig.width)/3

				bottom: streamBig.bottom
				bottomMargin: -(container.height - streamBig.height)/3
			}
		}
	}
}