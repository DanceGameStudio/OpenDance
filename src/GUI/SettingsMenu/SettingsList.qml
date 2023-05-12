import QtQuick 2.15
import QtQuick.Controls 1.4

Rectangle {
    id: root
    color: "transparent"

    ListModel {
        id: fruitModel

        ListElement {
            name: "Apple"
            cost: 2.45
        }
        ListElement {
            name: "Orange"
            cost: 3.25
        }
        ListElement {
            name: "Banana"
            cost: 1.95
        }
    }

    GridView {
        id: view

        anchors.fill: parent
        model: fruitModel
        clip: true

        cellWidth: width/2
        cellHeight: 250

        delegate: Item {
            width: view.cellWidth
            height: view.cellHeight

            SettingCombox {
                text: name

                width: view.cellWidth - 50
                height: view.cellHeight - 50
                x: 25
                y: 0

            }
        }
    }
}