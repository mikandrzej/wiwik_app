import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Item {
    id: rootItem

    RowLayout {
        x: 5
        y: 5
        width: 150
        height: 25
        Text {
            y: 5
            Layout.preferredWidth: 20
            text: "<b>Od</b>"
            horizontalAlignment: Text.AlignRight
        }
        TextField {
            Layout.fillWidth: true
            Layout.fillHeight: true
            text: "2023-05-17"
            selectByMouse: true
        }
    }

    RowLayout {
        x: 170
        y: 5
        width: 150
        height: 25
        Text {
            y: 5
            Layout.preferredWidth: 20
            text: "<b>Do</b>"
            horizontalAlignment: Text.AlignRight
        }
        TextField {
            Layout.fillWidth: true
            Layout.fillHeight: true
            text: "2023-05-18"
            selectByMouse: true
        }
    }

    Button {
        x: 330
        text: "Pobierz dane"
    }

}
