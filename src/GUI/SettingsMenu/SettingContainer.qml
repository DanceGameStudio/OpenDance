import QtQuick 2.15
import QtQuick.Controls 1.4

Rectangle {
    id: root

    property alias text: title.text

    color: color_bgTrans
    border {
        width: 3
        color: color_bg
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