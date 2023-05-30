#ifndef EGDATAPROVIDER_H
#define EGDATAPROVIDER_H

#include "egvehiclelistmodel.h"

#include <QNetworkAccessManager>
#include <QObject>

struct EgDataProviderVehicleListData {
  QList<int> m_vehicles;
  QDateTime m_timestampFrom;
  QDateTime m_timestampTo;
};

class EgDataProvider : public QObject {
  Q_OBJECT
public:
  explicit EgDataProvider(QObject *parent = nullptr);

  void requestVehicleList();

  void setOnVehicleListReady(
      const std::function<void(QList<EgVehicleListModelData> &)>
          &newOnVehicleListReady);

  void requestVehiclesTemperatureData(EgDataProviderVehicleListData &data);

signals:

private:
  QNetworkAccessManager m_netAccMgr;
  std::function<void(QList<EgVehicleListModelData> &)> m_onVehicleListReady;
};

#endif // EGDATAPROVIDER_H
