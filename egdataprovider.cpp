#include "egdataprovider.h"
#include "eghistoricalchart.h"
#include "egvehiclelistmodel.h"

#include <QJsonArray>
#include <QJsonDocument>
#include <QNetworkReply>
#include <QUrlQuery>

EgDataProvider::EgDataProvider(QObject *parent) : QObject{parent} {}

void EgDataProvider::requestVehicleList() {
  // utwórz zapytanie

  QUrl url("http://127.0.0.1:5000/api/getVehicles");
  QNetworkRequest request(url);

  // wyślij żądanie HTTP get
  QNetworkReply *reply = m_netAccMgr.get(request);

  // ustawić funkcję (lambda), która zwrócone dane przeparsuje i zawoła metodę
  // "onReady"
  connect(reply, &QNetworkReply::finished, reply, [reply, this]() {
    auto replyData = reply->readAll();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(replyData);
    if (!jsonDoc.isNull()) {
      if (jsonDoc.isArray()) {
        auto vehArray = jsonDoc.array();
        QList<EgVehicleListModelData> vehList;
        foreach (auto veh, vehArray) {
          EgVehicleListModelData vehModelData;
          vehModelData.id = veh["vehicle_id"].toInt();
          vehModelData.name = veh["vehicle_name"].toString();
          vehModelData.plateNo = veh["vehicle_plate"].toString();
          vehList.append(vehModelData);
        }

        if (m_onVehicleListReady != nullptr) {
          m_onVehicleListReady(vehList);
        }
      }
    }
  });
}

void EgDataProvider::setOnVehicleListReady(
    const std::function<void(QList<EgVehicleListModelData> &)>
        &newOnVehicleListReady) {
  m_onVehicleListReady = newOnVehicleListReady;
}

void EgDataProvider::requestVehiclesTemperatureData(
    EgDataProviderVehicleListData &data) {
  // utwórz zapytanie

  QUrl url("http://127.0.0.1:5000/api/getVehicleTempData");
  QUrlQuery query;
  query.addQueryItem("dateFrom",
                     QString::number(data.m_timestampFrom.toSecsSinceEpoch()));
  query.addQueryItem("dateTo",
                     QString::number(data.m_timestampTo.toSecsSinceEpoch()));
  foreach (auto vehId, data.m_vehicles) {
    query.addQueryItem("vehicles", QString::number(vehId));
  }
  url.setQuery(query);

  QNetworkRequest request(url);

  // wyślij żądanie HTTP get
  QNetworkReply *reply = m_netAccMgr.get(request);

  // ustawić funkcję (lambda), która zwrócone dane przeparsuje i zawoła metodę
  // "onReady"
  connect(reply, &QNetworkReply::finished, reply, [reply, data, this]() {
    auto replyData = reply->readAll();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(replyData);

    if (!jsonDoc.isNull()) {
      if (jsonDoc.isArray()) {
        auto pointArray = jsonDoc.array();
        EgHistoricalChartData chartData;

        chartData.m_timestampFrom = data.m_timestampFrom;
        chartData.m_timestampTo = data.m_timestampTo;

        QHash<QString, EgHistoricalChartSeriesData *> name_to_seriesdata_map;
        foreach (auto point, pointArray) {
          auto veh_name = point["vehicle_name"].toString();
          if (!name_to_seriesdata_map.contains(veh_name)) {
            chartData.m_series.append(EgHistoricalChartSeriesData());
            name_to_seriesdata_map[veh_name] =
                &chartData.m_series[chartData.m_series.length() - 1];
            auto *series = name_to_seriesdata_map[veh_name];
            series->m_vehicleName = point["vehicle_name"].toString();
            series->m_vehicleId = point["vehicle_id"].toInt();
          }

          auto *series = name_to_seriesdata_map[veh_name];

          series->m_x.append(point["measure_timestamp"].toInt());
          series->m_y.append(point["measure_value"].toDouble());
        }

        //        QList<EgVehicleListModelData> vehList;
        //        foreach (auto veh, vehArray) {
        //          EgVehicleListModelData vehModelData;
        //          vehModelData.id = veh["id"].toInt();
        //          vehModelData.name = veh["name"].toString();
        //          vehModelData.plateNo = veh["plate_no"].toString();
        //          vehList.append(vehModelData);
        //        }

        if (m_onChartDataReady != nullptr) {
          m_onChartDataReady(chartData);
        }
      }
    }
  });
}

void EgDataProvider::setOnChartDataReady(
    const std::function<void(EgHistoricalChartData &)> &newOnChartDataReady) {
  m_onChartDataReady = newOnChartDataReady;
}
