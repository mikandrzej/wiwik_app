#ifndef EGDATAPROVIDER_H
#define EGDATAPROVIDER_H

#include "eghistoricalchart.h"
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

  void setOnChartDataReady(const std::function<void (EgHistoricalChartData &)> &newOnChartDataReady);

  signals:

private:
  QNetworkAccessManager m_netAccMgr;
  std::function<void(QList<EgVehicleListModelData> &)> m_onVehicleListReady;
  std::function<void(EgHistoricalChartData &)> m_onChartDataReady;
};

#endif // EGDATAPROVIDER_H
