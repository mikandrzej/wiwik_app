import QtQuick 2.15

Item {
    id: rootItem
    property string text
    property color color

    Rectangle {
        color: rootItem.color
        anchors.fill: parent
        Text {
            anchors.fill: parent
            text: rootItem.text
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: rootItem.height / 3
        }
    }

}
