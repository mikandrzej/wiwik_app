import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 1.4 as OldControls

Item {
    id: rootItem

    Popup {
        id: popupFrom
        modal: true
        visible: false
        OldControls.Calendar {
            selectedDate: myApp.timestampFrom
            onSelectedDateChanged: myApp.timestampFrom = selectedDate
        }
    }

    Text {
        x: 5
        y: 5
        width: 20
        text: "<b>Od:</b>"
        font.pixelSize: 12
        color: defaultTextColor
        horizontalAlignment: Text.AlignRight
    }
    Text {
        x: 30
        y: 5
        width: 150
        color: defaultTextColor
        font.pixelSize: 12
        font.bold: true
        text: myApp.timestampFrom.toLocaleDateString()
        horizontalAlignment: Text.AlignLeft

        MouseArea {
            anchors.fill: parent
            onClicked: popupFrom.open()
        }
    }

    Popup {
        id: popupTo
        modal: true
        visible: false
        OldControls.Calendar {
            id: calendar
            selectedDate: myApp.timestampTo
            onSelectedDateChanged: myApp.timestampTo = selectedDate
        }
    }
    Text {
        x: 205
        y: 5
        width: 20
        color: defaultTextColor
        font.pixelSize: 12
        text: "<b>Do:</b>"
        horizontalAlignment: Text.AlignRight
    }
    Text {
        x: 230
        y: 5
        color: defaultTextColor
        font.pixelSize: 12
        font.bold: true
        text: myApp.timestampTo.toLocaleDateString()
        horizontalAlignment: Text.AlignLeft

        MouseArea {
            anchors.fill: parent
            onClicked: popupTo.open()
        }
    }

    Button {
        y: 25
        x: 5
        text: "Pobierz dane"
        onClicked: myApp.getChartData()
    }

}
