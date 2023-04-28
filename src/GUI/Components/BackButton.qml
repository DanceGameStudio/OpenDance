StyledButton {
	id: root

	property alias menu: root.parent

	text: "Back"
	fontSize: 25

	width: menu.width * .1
	height: menu.height * .05
	anchors {
		bottom: parent.bottom
		bottomMargin: 50
		left: parent.left
		leftMargin: 50
	}

	onClicked: menu.visible = false
}