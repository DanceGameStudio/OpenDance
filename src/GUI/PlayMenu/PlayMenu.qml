import QtQuick 2.15
import QtQuick.Controls 2.15

Rectangle {
	id: root
	color: "transparent"
	
	MenuTitle {
		text: "Select Dance"
	}

	signal gameSelected

	ListModel {
		id: nameModel
		ListElement { name: "1" }
		ListElement { name: "2" }
		ListElement { name: "3" }
		ListElement { name: "4" }
		ListElement { name: "5" }
		ListElement { name: "6" }
		/*
		ListElement { name: "7" }
		ListElement { name: "8" }
		ListElement { name: "9" }
		ListElement { name: "10" }
		ListElement { name: "11" }
		ListElement { name: "12" }
		ListElement { name: "13" }
		ListElement { name: "14" }
		ListElement { name: "15" }
		*/
	}
	
	property int sizes_danceHeight: 100
	property int sizes_danceWidth: 400
	
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

		Component.onCompleted: {
			console.log(c_dancesModel, c_dancesModel.count)
		}
        model: c_dancesModel

        delegate: DancePreview {
			property PathView view: dancesView
			idx: index
			isSelected: dancesView.currentIndex == idx-2
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
    }
	
	StyledButton {
		id: playButton

		text: "Play"
		fontSize: 50

		width: root.width * .2
		height: root.height * .1
		anchors {
			top: dancesView.bottom
			topMargin: 50
			horizontalCenter: parent.horizontalCenter
		}

		onClicked: root.gameSelected()
	}

	BackButton {}
}