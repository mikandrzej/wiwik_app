import QtQuick 2.15
import EgChart 1.0

Item {
    EgHistoricalChart {
        objectName: "historicalTemperatureChart"
        id: customPlot
        anchors.fill: parent
        foregroundColor: defaultTextColor
        backgroundColor: defaultBackgroundColor

        Component.onCompleted: {
            myApp.setHistoricalChartView(customPlot)
            showTestData()
        }
    }
}
