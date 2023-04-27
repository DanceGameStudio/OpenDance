import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    id: root

    visible: true
    title: qsTr("OpenDance")
    visibility: Qt.WindowFullScreen
    flags: Qt.FramelessWindowHint | Qt.Window
    color: "black"

    MenuBackground {
        id: menuBackground

        anchors.fill: parent

        visible: !gameScreen.visible
    }

    GameScreen {
        id: gameScreen

        anchors.fill: parent

        visible: false
    }

    MainMenu {
        id: mainMenu

        x: 0
        y: 0
        width: root.width
        height: root.height

        visible: !landingScreen.visible && !playMenu.visible && !settingsMenu.visible && !creditsMenu.visible && !gameScreen.visible
        
        onOpenPlayMenu: playMenu.visible = true
        onOpenSettingsMenu: settingsMenu.visible = true
        onOpenCreditsMenu: creditsMenu.visible = true
    }
    
    PlayMenu {
        id: playMenu
        anchors.fill: parent
        visible: false

        onGameSelected: { playMenu.visible = false; gameScreen.visible = true; }
    }
    
    SettingsMenu {
        id: settingsMenu
        anchors.fill: parent
        visible: false
    }

    CreditsMenu {
        id: creditsMenu
        anchors.fill: parent
        visible: false
    }

    LandingScreen {
        visible: false

        id: landingScreen
        
        x: 0
        y: 0
        width: root.width
        height: root.height
    }
}
