import QtQuick 2.12
import QtQuick.Controls 2.5
import ModuleHeaderToolBar.Impl 1.0
import ModuleRoundButton.Impl 1.0
import QtQuick.Layouts 1.3
import PageMainMenu.Impl 1.0
import PageGameBoard.Impl 1.0
import "qrc:/javascript/color_functions.js" as UpdateColor

ApplicationWindow {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Stack")


    header: HeaderToolBar {
    }

    StackView {
        id: _stackView
        initialItem: _mainMenu
        anchors.fill: parent
    }

    // -------------------------------------------------

    MainMenu {
        id: _mainMenu
    }

    GameBoard {
        id: _gameBoard

        visible: false
    }
}
