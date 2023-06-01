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
		
		Item {
			id: scoreContianer
			width: 150
			height: 50			
			anchors {
				left: streamBig.left
				leftMargin: -(container.width - streamBig.width)/3

				top: streamBig.top
				topMargin: -(container.height - streamBig.height)/3
			}

			Rectangle {
				id: score

				width: 150
				height: 50

				anchors {
					verticalCenter: parent.verticalCenter
					horizontalCenter: parent.horizontalCenter
				}

				SequentialAnimation {
					id: scoreAnim
					running: false
				
					ParallelAnimation {
						NumberAnimation { target: score; property: "width"; to: 175; duration: 30 }
						NumberAnimation { target: score; property: "height"; to: 75; duration: 30 }
					}
				
					ParallelAnimation {
						NumberAnimation { target: score; property: "width"; to: 150; duration: 30 }
						NumberAnimation { target: score; property: "height"; to: 50; duration: 30 }
					}
				}

				color: color_bgTrans
				border {
					width: 5
					color: "grey"
				}

				Text {
					id: scoreText
					color: "white"
					text: "0"
					font.pointSize: parent.width/8
					anchors {
						verticalCenter: parent.verticalCenter
						horizontalCenter: parent.horizontalCenter
					}
				}
				
				Timer {
					interval: 1; running: true; repeat: true
					onTriggered: {
						let newScore = c_gameInterface.get_score();
						if (scoreText.text == newScore) { return; }

						console.log("CHANGE!")
						scoreText.text = newScore;
						scoreAnim.restart()
					}
				}

			}
		}
	}

	/*
	StyledButton {
		text: "HIT!"
		width: 200
		height: 200
		x: parent.width-200
		y: parent.height-200

		onClicked: {
			scoreAnim.restart()
		}
	}
	*/

	PauseMenu {
		id: pauseMenu
		visible: false

		onQuitGame: root.quitGame()
		onOpenSettings: root.openSettings()
	}
}