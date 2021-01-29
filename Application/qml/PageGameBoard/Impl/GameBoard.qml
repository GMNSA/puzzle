import QtQuick 2.12
import QtQuick.Controls 2.5
import ModelGameBoard 1.0
import "qrc:/javascript/Utils.js" as Utils


Page {
    id: _root

    visible: false

    property real sizeWidth: parent.width / 2
    property real sizeHeight: parent.height / 2

    GridView {
        id: _gridView

        anchors.fill: parent
        cellHeight: parent.height / _model.dimention
        cellWidth: parent.width / _model.dimention

        model: GameBoardModel {
            id: _model
        }

        delegate: Item {
            id: _background

            width: _gridView.cellWidth
            height: _gridView.cellHeight

            Rectangle {
                anchors.fill: parent
                anchors.margins: 3
                color: "transparent"

                Image {
                    id: _name
                    anchors.fill: parent
                    source: Utils.getPathForTile(display);
                }

                // Text {
                //     anchors.fill: parent
                //     text: "" + display
                // }

                MouseArea {
                    anchors.fill: parent
                    onPressed: {
                        console.log("index: " + display )
                        _model.move(display);
                    }
                }
            }
        }
    }
}
