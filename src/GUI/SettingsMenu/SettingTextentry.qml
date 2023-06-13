import QtQuick 2.15
import QtQuick.Controls 1.4

SettingContainer {
	id: root
	
	Rectangle {
		anchors {
			fill: parent
			topMargin: 63 + 10
			leftMargin: 13 + 10
			rightMargin: 13 + 10
			bottomMargin: 13 + 10
		}
		
		color: color_bgTrans
		border {
			width: 3
			color: color_bg
		}

		TextInput {
			id: text
			text: "Text Entry"
		
			anchors.fill: parent

			verticalAlignment: TextInput.AlignVCenter
			horizontalAlignment: TextInput.AlignHCenter

			color: "white"
			font.pointSize: 40
		}
	}
}