import QtQuick 2.15
import QtQuick.Controls 1.4

Rectangle {
	id: root
	color: "transparent"
	
    focus: true
	Keys.onEscapePressed: {
		pauseMenu.visible = !pauseMenu.visible
		c_gameInterface.set_game_status(pauseMenu.visible ? 1 : 0);
	}

	signal quitGame
	signal openSettings

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

			Component.onCompleted: {
				c_gameInterface.connectVideo(streamBig.content)
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

			Component.onCompleted: {
				c_gameInterface.connectCamera(streamSmall.content)
			}
		}
	}

	PauseMenu {
		id: pauseMenu
		visible: true

		onQuitGame: root.quitGame()
		onOpenSettings: root.openSettings()
	}
}