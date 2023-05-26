import QtQuick 2.15
import QtGraphicalEffects 1.15

Item {
    id: rootItem
    property string text
    property color selectedColor
    property color idleColor
    property bool isSelected
    property string iconPath

    width: text.x + text.width + 10

    Image {
        id: image
        height: parent.height / 2
        width: height
        x: (parent.height - height) / 2
        y: x
        source: iconPath
        antialiasing: true
        smooth: true


        ColorOverlay {
            color: isSelected ? selectedColor : idleColor
            id: overlay
            anchors.fill: parent
            source: parent
        }
    }

    Text {
        id: text
        x: image.x + image.width + 5
        height: parent.height
        text: rootItem.text
        color: isSelected ? selectedColor : idleColor
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: parent.height / 3
    }
}
