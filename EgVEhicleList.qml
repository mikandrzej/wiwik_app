import QtQuick 2.15
import QtQuick.Dialogs 1.3

Item {
    id: rootItem

    property color selectedVehicleColor: "#622A56"
    property color idleVehicleColor: "transparent"
    property color frameColor: "#F9B3D1"
    property color textColor: "#F9B3D1"

    ListView {
        anchors.fill: parent

        model: myApp.vehicleListModel

        delegate: Rectangle {
            height: 50
            width: rootItem.width
            border.color: frameColor
            id: delegateItem

            color: model.selectedToView ? selectedVehicleColor : idleVehicleColor

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    model.selectedToView = !model.selectedToView
                }
            }

            Rectangle {
                color: model.color
                height: delegateItem.height / 3
                width: height
                y: height
                x: 10
                MouseArea {
                    anchors.fill: parent
                    onClicked: colorDialog.visible = true
                }

                ColorDialog{
                    visible: false
                    id: colorDialog
                    color: model.color
                    onAccepted: {
                        model.color = colorDialog.color
                    }
                }
            }

            Text {
                text: model.name
                font.pixelSize: delegateItem.height / 3
                x: 50
                y: delegateItem.height / 3
                color: textColor
            }

        }
    }
}
