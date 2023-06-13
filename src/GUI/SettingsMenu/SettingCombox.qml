import QtQuick 2.15
import QtQuick.Controls 1.4

SettingContainer {
	id: root
	
	text: "Combox"
	
	ComboBox {
        currentIndex: 2
        model: ListModel {
            id: cbItems
            ListElement { text: "Option 1"; }
            ListElement { text: "Option 2"; }
            ListElement { text: "Option 3"; }
        }
        width: 200
        
		anchors {
			fill: parent
			topMargin: 63 + 10
			leftMargin: 13 + 10
			rightMargin: 13 + 10
			bottomMargin: 13 + 10
		}
    }
}