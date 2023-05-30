import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Styles 1.4

ApplicationWindow {
    property color defaultTextColor: "#F9B3D1"
    property color defaultBackgroundColor: "#140B1F"

    width: 1200
    height: 800
    visible: true
    title: qsTr("Hello World")
    id: rootItem

    color: defaultBackgroundColor

    menuBar:
        EgMenu {
        width: parent.width
        height: 50

        id: menuItem
        selectedItem: "Live View"
        items: [
            {text: "Live View", color: "#F7D4FF", colorSelected: "#F3BBFF", iconPath: "qrc:/icons/satellite-dish-solid.svg"},
            {text: "History", color: "#D4DDFF", colorSelected: "#BBC9FF", iconPath: "qrc:/icons/clock-rotate-left-solid.svg"},
            {text: "Custom", color: "#D4F6FF", colorSelected: "#BBF0FF", iconPath: "qrc:/icons/intercom.svg"}
        ]
    }

    Item {
        anchors.fill: parent
//        transform: Scale {
//            xScale: 0.5 // Scale the width by a factor of 1.5
//            yScale: 0.5 // Scale the height by a factor of 0.8
//        }

//        ColumnLayout {
//        }

        RowLayout {
            anchors.fill: parent
//            Rectangle {
//                Layout.fillHeight: true
//                Layout.minimumWidth: 100
//                EgMenu {
//                    id: menuItem
//                    anchors.fill: parent
//                    selectedItem: "Live View"
//                    items: [
//                        {text: "Live View", color: "#F7D4FF", colorSelected: "#F3BBFF"},
//                        {text: "History", color: "#D4DDFF", colorSelected: "#BBC9FF"},
//                        {text: "Custom", color: "#D4F6FF", colorSelected: "#BBF0FF"}
//                    ]
//                }
//            }
            Rectangle {
                Layout.preferredWidth: 2
                Layout.fillHeight: true
                color: "black"
            }

            Item {
                Layout.fillHeight: true
                Layout.fillWidth: true

                EgLiveView {
                    anchors.fill: parent
                    visible: menuItem.selectedItem === "Live View"
                }
                EgHistory {
                    anchors.fill: parent
                    visible: menuItem.selectedItem === "History"
                }
            }
        }
    }
}
