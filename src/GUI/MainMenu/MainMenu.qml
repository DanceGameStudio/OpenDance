import QtQuick 2.15
import QtQuick.Controls 1.4

Rectangle {
	id: root
	color: "transparent"

	signal openPlayMenu
	signal openSettingsMenu
	signal openCreditsMenu

	property int sizes_buttonWidth: root.width*.3
	property int sizes_buttonHeight: root.height*.1
	property int sizes_buttonFont: (root.height + root.width)*.015

	Item {
		width: childrenRect.width
		height: childrenRect.height

		anchors {
			horizontalCenter: root.horizontalCenter
			verticalCenter: root.verticalCenter
		}

		MainMenuButton {
			id: buttonPlay
			text: "PLAY"

			anchors {
				top: parent.top
			}

			onClicked: root.openPlayMenu()
		}
	
		MainMenuButton {
			id: buttonSettings
			text: "SETTINGS"
			
			anchors {
				top: buttonPlay.bottom
				topMargin: sizes_spacing
			}
			
			onClicked: root.openSettingsMenu()
		}
	
		MainMenuButton {
			id: buttonCredits
			text: "CREDITS"

			anchors {
				top: buttonSettings.bottom
				topMargin: sizes_spacing
			}
			
			onClicked: root.openCreditsMenu()
		}
	}	
}