import QtQuick 2.15

Item {
    id: rootItem
    property var items: []
    property string selectedItem: ""

    ListView {
        orientation: ListView.Horizontal
        anchors.fill: parent
        model: items
        delegate:
            EgMenuItem {

            height: parent.height
            text: modelData.text
            selectedColor: "#F9B3D1"
            idleColor: "#C62E65"
            isSelected: modelData.text === selectedItem
            iconPath: modelData.iconPath
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    selectedItem = modelData.text
                }
            }
        }
    }
}
