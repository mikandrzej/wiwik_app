import QtQuick 2.15

Item {
    id: rootItem
    property var items: []
    property string selectedItem: ""

    ListView {
        anchors.fill: parent
        model: items
        delegate:
            EgMenuItem {
            height: 50
            width: rootItem.width
            text: modelData.text
            color: modelData.text === selectedItem ? modelData.colorSelected : modelData.color

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    selectedItem = modelData.text
                }
            }
        }
    }
}
