import QtQuick 2.15
import QtQuick.Controls 1.4

Rectangle {
    id: root

    property alias text: title.text

    color: Qt.rgba(.2, .2, .2, .9)
    border {
        width: 3
        color: Qt.rgba(.8, .8, .8, 1)
    }

    Text {
        id: title
        anchors {
            top: root.top
            topMargin: 10
            horizontalCenter: parent.horizontalCenter
        }
        font {
            pixelSize: 40
        }
        color: "white"
    }
}