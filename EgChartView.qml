import QtQuick 2.15
import CustomPlot 1.0

Item {
    CustomPlotItem {
        id: customPlot
        anchors.fill: parent

        Component.onCompleted: initCustomPlot()
    }
}
