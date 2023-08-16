#include "egapplication.h"

EgApplication::EgApplication(QObject *parent) : QObject{parent} {
  m_vehicleListModel = new EgVehicleListModel(this);

  m_dataProvider.setOnVehicleListReady(
      [this](QList<EgVehicleListModelData> &data) {
        m_vehicleListModel->overrideData(data);
      });

  m_dataProvider.setOnChartDataReady([this](EgHistoricalChartData &data) {
    for (auto &serie : data.m_series) {
      serie.m_color = m_vehicleListModel->getVehicleColor(serie.m_vehicleId);
    }
    m_historicalChartView->setChartData(data);
  });

  m_dataProvider.requestVehicleList();
}

EgVehicleListModel *EgApplication::vehicleListModel() const {
  return m_vehicleListModel;
}

QDateTime EgApplication::timestampFrom() const { return m_timestampFrom; }

void EgApplication::setTimestampFrom(const QDateTime &newTimestampFrom) {
  if (m_timestampFrom == newTimestampFrom)
    return;
  m_timestampFrom = newTimestampFrom;
  emit timestampFromChanged();
}

QDateTime EgApplication::timestampTo() const { return m_timestampTo; }

void EgApplication::setTimestampTo(const QDateTime &newTimestampTo) {
  if (m_timestampTo == newTimestampTo)
    return;
  m_timestampTo = newTimestampTo;
  emit timestampToChanged();
}

void EgApplication::getChartData() {
  EgDataProviderVehicleListData requestData{
      m_vehicleListModel->getSelectedVehicleList(), m_timestampFrom,
      m_timestampTo};
  m_dataProvider.requestVehiclesTemperatureData(requestData);
}

void EgApplication::setHistoricalChartView(
    EgHistoricalChart *newHistoricalChartView) {
  m_historicalChartView = newHistoricalChartView;
}
