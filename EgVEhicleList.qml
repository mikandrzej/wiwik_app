import QtQuick 2.15

Item {
    id: rootItem
    ListView {
        anchors.fill: parent
        model: [
            {id: 0, name: "Payday", plateNo: "PRA2931",  selectedToView: false, color: "#F0C97A"},
            {id: 1, name: "Gandalf",   plateNo: "WMA7230",   selectedToView: false, color: "#6DF7F7"},
            {id: 2, name: "Devil",  plateNo: "KDA5860",  selectedToView: true, color: "#6EE0C0"},
            {id: 3, name: "Clueless",  plateNo: "ZGY5439",  selectedToView: true, color: "#6DF7A9"},
            {id: 4, name: "Tone Zone",  plateNo: "CMG9372",  selectedToView: true, color: "#68ED7C"},
            {id: 5, name: "Chicle",  plateNo: "ZDR5633",  selectedToView: true, color: "#ED816D"},
            {id: 6, name: "Baby Grand",  plateNo: "FSW0791",  selectedToView: true, color: "#B070FA"},
            {id: 7, name: "Scar Face",  plateNo: "WD49039",  selectedToView: true, color: "#72D3E0"},
        ]

        delegate: Rectangle {
            height: 50
            width: rootItem.width
            border.color: "#202020"
            id: delegateItem

            color: modelData.selectedToView ? "white" : "#D0D0D0"

            Rectangle {
                color: modelData.color
                height: delegateItem.height / 3
                width: height
                y: height
                x: 10
            }

            Text {
                text: modelData.name
                font.pixelSize: delegateItem.height / 3
                x: 50
                y: delegateItem.height / 3
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    console.log("vehicle " + modelData.name + " clicked")
                }
            }
        }
    }
}
