#include "egdataprovider.h"
#include "egvehiclelistmodel.h"

#include <QJsonArray>
#include <QJsonDocument>
#include <QNetworkReply>
#include <QUrlQuery>

EgDataProvider::EgDataProvider(QObject *parent) : QObject{parent} {}

void EgDataProvider::requestVehicleList() {
  // utwórz zapytanie

  QUrl url("http://127.0.0.1:5000/api/getVehiclesData");
  QNetworkRequest request(url);

  // wyślij żądanie HTTP get
  QNetworkReply *reply = m_netAccMgr.get(request);

  // ustawić funkcję (lambda), która zwrócone dane przeparsuje i zawoła metodę
  // "onReady"
  connect(reply, &QNetworkReply::finished, reply, [reply, this]() {
    auto replyData = reply->readAll();

    qDebug() << "Dane z odpowiedzi: " << replyData;

    QJsonDocument jsonDoc = QJsonDocument::fromJson(replyData);
    if (!jsonDoc.isNull()) {
      if (jsonDoc.isArray()) {
        auto vehArray = jsonDoc.array();
        QList<EgVehicleListModelData> vehList;
        foreach (auto veh, vehArray) {
          EgVehicleListModelData vehModelData;
          vehModelData.id = veh["id"].toString().toInt();
          vehModelData.name = veh["name"].toString();
          vehModelData.plateNo = veh["regNo"].toString();
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

  QUrl url("http://127.0.0.1:5000/api/getChartData");
  QUrlQuery query;
  query.addQueryItem("dateFrom",
                     data.m_timestampFrom.toString("yyyy-MM-ddThh:mm:ssZ"));
  query.addQueryItem("dateTo",
                     data.m_timestampTo.toString("yyyy-MM-ddThh:mm:ssZ"));
  foreach (auto vehId, data.m_vehicles) {
    query.addQueryItem("vehicles", QString::number(vehId));
  }
  url.setQuery(query);

  QNetworkRequest request(url);

  // wyślij żądanie HTTP get
  QNetworkReply *reply = m_netAccMgr.get(request);

  // ustawić funkcję (lambda), która zwrócone dane przeparsuje i zawoła metodę
  // "onReady"
  connect(reply, &QNetworkReply::finished, reply,
          [reply, this]() { qDebug() << reply->readAll(); });
}
