import QtQuick 2.15
import QtQuick.Layouts 1.15

Item {
    RowLayout {
        anchors.fill: parent

        // lista pojazdow
        EgVEhicleList {
            Layout.minimumWidth: 200
            Layout.fillHeight: true
            clip: true
        }

        // wyswietlanie wykresu
        ColumnLayout {
            Layout.fillWidth: true
            Layout.fillHeight: true

            //EgChartData
            EgChartData {
                Layout.minimumHeight: 100
                Layout.fillWidth: true
            }

            //EgChartView
            EgChartView {
                Layout.fillHeight: true
                Layout.fillWidth: true
            }
        }


    }
}
