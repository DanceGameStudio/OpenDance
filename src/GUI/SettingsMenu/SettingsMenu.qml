import QtQuick 2.15
import QtQuick.Controls 1.4

Rectangle {
	id: root
	color: "transparent"
	
	MenuTitle {
		id: title
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

	SettingsList {
		id: list

		anchors {
			top: title.bottom
			topMargin: 50

			bottom: backButton.top
			bottomMargin: 50

			left: root.left
			leftMargin: 50

			right: root.right
			rightMargin: 50
		}
	}

	BackButton {}
}