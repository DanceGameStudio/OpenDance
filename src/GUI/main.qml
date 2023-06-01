import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    id: root

    visible: true
    title: qsTr("OpenDance")
    visibility: Qt.WindowFullScreen
    //flags: Qt.FramelessWindowHint | Qt.Window
    color: "black"
    
    property color color_bg: Qt.rgba(194/255, 66/255, 245/255, 1)
    property color color_bgTrans: Qt.rgba(194/255, 66/255, 245/255, 100/255)
    
    property int sizes_spacing: root.height*.05
    property int sizes_titleWidth: root.width*.2
    property int sizes_titleHeight: root.height*.1

    MenuBackground {
        id: menuBackground

        anchors.fill: parent

        visible: !gameScreen.visible
    }

    GameScreen {
        id: gameScreen
        visible: true

        anchors.fill: parent

        onOpenSettings: {
            gameScreen.visible = false;
            settingsMenu.visible = true;
        }
        onQuitGame: {
            gameScreen.visible = false;
            playMenu.visible = true;
        }
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
        visible: false

        anchors.fill: parent

        onGameSelected: { playMenu.visible = false; gameScreen.visible = true; }
    }
    
    SettingsMenu {
        id: settingsMenu
        anchors.fill: parent
        visible: false
        
	    onVisibleChanged: {
		    if (!visible) { // if the game is just paused and not stopped, resume to game screen
			    if (c_gameInterface.get_game_status() == 1) {
                    gameScreen.visible = true;
                }
		    }
	    }
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
