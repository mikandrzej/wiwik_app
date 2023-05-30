import QtQuick 2.15
import EgChart 1.0

Item {
    EgHistoricalChart {
        id: customPlot
        anchors.fill: parent
        foregroundColor: defaultTextColor
        backgroundColor: defaultBackgroundColor

        Component.onCompleted: showTestData()
    }
}
