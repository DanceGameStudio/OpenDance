import QtQuick 2.15
import QtQuick.Controls 1.4

Rectangle {
	id: root
	color: "transparent"
	
	MenuTitle {
		text: "Settings"
	}
		
	StyledButton {
		id: backButton

		text: "Back"
		fontSize: 25

		width: root.width * .1
		height: root.height * .05
		anchors {
			bottom: parent.bottom
			bottomMargin: 50
			left: parent.left
			leftMargin: 50
		}

		onClicked: root.visible = false
	}

	BackButton {}

}