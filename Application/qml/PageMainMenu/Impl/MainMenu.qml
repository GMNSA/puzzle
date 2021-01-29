import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import ModelGameBoard 1.0

Page {
    id: _root

     GameBoardModel {
         id: _modelGameBoard
     }

    ColumnLayout {
        width: parent.width
        height: parent.height / 2
        Layout.alignment: Qt.AlignCenter
        // anchors.centerIn: parent
        spacing: 10

        Button {
            text: "Continue"
            Layout.preferredWidth: parent.width / 2
            Layout.alignment: Qt.AlignHCenter
            onClicked: {
                if (_modelGameBoard.isGameRun)
                    _stackView.push(_gameBoard)
            }
        }

        Button {
            text: _modelGameBoard.isGameRun ? "reset" : "New Game"
            Layout.preferredWidth: parent.width / 2
            Layout.alignment: Qt.AlignHCenter
            onClicked: {
                _modelGameBoard.startGame();
                _stackView.push(_gameBoard)
            }
        }

        Button {
            text: "Records"
            width: 400
            Layout.preferredWidth: parent.width / 2
            Layout.alignment: Qt.AlignHCenter
            onClicked: {
                // _stackView.push(_records)
            }
        }

        Button {
            text: "About"
            width: 400
            Layout.preferredWidth: parent.width / 2
            Layout.alignment: Qt.AlignHCenter
            onClicked: {
                updateColor();
            }
        }
    }
}
