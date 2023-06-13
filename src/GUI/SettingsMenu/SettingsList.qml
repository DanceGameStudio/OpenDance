import QtQuick 2.15
import QtQuick.Controls 1.4

Rectangle {
    id: root
    color: "transparent"


    ListModel {
        id: fruitModel

        ListElement {
            name: "Camera Source"
            type: "combox"
            value: 1
            //values: ["Camera 1", "Camera 2"]
        }

        ListElement {
            name: "Difficulty"
            type: "combox"
            value: 1
            //values: ["Easy","Normal","Hard"]
        }

        ListElement {
            name: "Playback Speed"
            type: "slider"
            min: 0.1
            def: 1.0
            value: 1.0
            max: 2.0
        }

        ListElement {
            name: "Name"
            type: "textentry"
            value: "Ben"
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
                visible: model.type == "combox"

                width: view.cellWidth - 50
                height: view.cellHeight - 50
                x: 25
                y: 0
            }

            
            SettingSlider {
                text: name
                visible: model.type == "slider"

                width: view.cellWidth - 50
                height: view.cellHeight - 50
                x: 25
                y: 0
            }

            
            SettingTextentry {
                text: name
                visible: model.type == "textentry"

                width: view.cellWidth - 50
                height: view.cellHeight - 50
                x: 25
                y: 0
            }
        }
    }
}