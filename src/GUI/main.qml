import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    
    TestComponent {
        x: 0
        y: 0
    }

    TestComponent {
        x: 300
        y: 0
    }
}
