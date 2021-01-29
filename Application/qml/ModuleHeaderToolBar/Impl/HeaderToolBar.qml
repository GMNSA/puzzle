import QtQuick.Controls 2.5

ToolBar {
    id: _root
    contentHeight: toolButton.implicitHeight


    ToolButton {
        id: toolButton
        text: _stackView.depth > 1 ? "\u25C0" : "\u2630"
        font.pixelSize: Qt.application.font.pixelSize * 1.6
        onClicked: {
            console.log("TEST")
            if (_stackView.depth > 1) {
                _stackView.pop()
            } else {
                // drawer.open()
                console.log("OPEN")
            }
        }
    }

    Label {
        // text: stackView.currentItem.title? "" : ""
        text: "Titile"
        anchors.centerIn: parent
    }
}
