import QtQuick 2.12

    Item {
        id: _itemRoot

        property int size: 100
        property color color: "lightblue"
        property alias text: _caption.text

        signal tuturu();

        height: size
        width: size

        Rectangle {
            anchors.fill: parent
            radius: height / 2
            color: _itemRoot.color
            opacity: _mouseAreaItem.containsPress ? 0.4 : 0.8

            Text {
                id: _caption
                anchors.centerIn: parent
                text: qsTr("Click")
            }

            MouseArea {
                id: _mouseAreaItem
                anchors.fill: parent

                onClicked: _itemRoot.tuturu();
            }
        }
    }
