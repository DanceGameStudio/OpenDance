import QtQuick 2.15
import QtQuick.Controls 2.15

Rectangle {
	id: root
	color: "transparent"
	
	MenuTitle {
		text: "Select Dance"
	}

	signal gameSelected
	property int sizes_danceWidth: 220
	property int sizes_danceHeight: sizes_danceWidth*(9/16) + 35
	property string video: ""
	
    PathView {
		id: dancesView
		height: 300
		anchors {
			leftMargin: 0
			left: parent.left
			
			rightMargin: anchors.leftMargin
			right: parent.right

			verticalCenter: parent.verticalCenter
		}

        model: c_dancesModel

        delegate: DancePreview {
			property PathView view: dancesView
			idx: index
			isSelected: dancesView.currentIndex == idx-2

			onIsSelectedChanged: {
				if (isSelected) {
					root.video = model.video
				}
			}
		}
        path: Path {
            startX: -sizes_danceWidth/2; startY: 150
			
			PathPercent { value: 0 }

            PathAttribute { name: "scale"; value: 1 }
			PathLine { x: dancesView.width/2; y: sizes_danceHeight/2*1.5 }
			PathPercent { value: 4/2/dancesView.count }
			
            PathAttribute { name: "scale"; value: 1.5 }
			PathLine { x: dancesView.width + sizes_danceWidth/2; y: sizes_danceHeight }
			PathPercent { value: 4/dancesView.count }
						
			PathLine { x: dancesView.width + sizes_danceWidth; y: sizes_danceHeight }
			PathPercent { value: 1 }
		}

		function setSelected(idx) {
			dancesView.currentIndex = idx - 2
		}

		MouseArea {
			anchors.fill: parent
			hoverEnabled: true
			onWheel: {
				wheel.accepted = true;
				if (wheel.angleDelta.y > 0) {
					dancesView.decrementCurrentIndex();
				} else {
					dancesView.incrementCurrentIndex();
				}
			}
		}
    }
	
	BackButton {
		id: btnBack
	}

	StyledButton {
		id: playButton

		text: "Play"
		fontSize: 50

		width: root.width * .2
		height: root.height * .1
		anchors {
			//top: dancesView.bottom
			//topMargin: 50
			bottom: btnBack.bottom
			horizontalCenter: parent.horizontalCenter
		}

		onClicked: {
			root.gameSelected()
			c_gameInterface.set_videoPath(root.video)
			console.log(root.video)
		}
	}
}