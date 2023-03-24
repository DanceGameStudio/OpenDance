import QtQuick 2.15
import QtQuick.Controls 1.4

Rectangle {
	id: root
	color: "transparent"

	signal openPlayMenu
	signal openSettingsMenu
	signal openCreditsMenu

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
				topMargin: 50
			}
			
			onClicked: root.openSettingsMenu()
		}
	
		MainMenuButton {
			id: buttonCredits
			text: "CREDITS"

			anchors {
				top: buttonSettings.bottom
				topMargin: 50
			}
			
			onClicked: root.openCreditsMenu()
		}
	}

	
}