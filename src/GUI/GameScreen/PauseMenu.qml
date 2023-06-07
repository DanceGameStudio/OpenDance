import QtQuick 2.15
import QtQuick.Controls 1.4

Rectangle {
	id: root
	color: Qt.rgba(0,0,0,.75)

	anchors.fill: parent

	signal quitGame
	signal openSettings

	Item {
		width: sizes_titleWidth
		height: parent.height*.75

		anchors {
			verticalCenter: parent.verticalCenter
			horizontalCenter: parent.horizontalCenter
		}

		MenuTitle {
			text: "Pause"
			anchors {
				topMargin: 0
			}
		}
		
		Item {
			width: sizes_titleWidth/2
			height: (3*100 - 50)
			anchors {
				verticalCenter: parent.verticalCenter
				horizontalCenter: parent.horizontalCenter
			}
			
			StyledButton {
				id: btnResume
				height: 50
				anchors {
					top: parent.top
					left: parent.left
					right: parent.right
				}
				onClicked: {
					c_gameInterface.set_game_status(gamestatus_running);
					root.visible = false
				}
				text: "Resume"
				fontSize: 20
			}
			
			StyledButton {
				id: btnSettigs
				height: 50
				anchors {
					top: btnResume.bottom
					topMargin: 50
					left: parent.left
					right: parent.right
				}
				onClicked: root.openSettings()
				text: "Settings"
				fontSize: 20
			}

			StyledButton {
				id: btnQuit
				height: 50
				anchors {
					top: btnSettigs.bottom
					topMargin: 50
					left: parent.left
					right: parent.right
				}
				onClicked: {
					c_gameInterface.set_game_status(gamestatus_stopped);
					root.quitGame();
				}
				text: "Quit"
				fontSize: 20
			}
		}
	}
}