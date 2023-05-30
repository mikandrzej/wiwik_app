#ifndef APPLICATION_H
#define APPLICATION_H

#include "egdataprovider.h"
#include "egvehiclelistmodel.h"

#include <QObject>

class EgApplication : public QObject {
  Q_OBJECT
public:
  explicit EgApplication(QObject *parent = nullptr);

  EgVehicleListModel *vehicleListModel() const;

  QDateTime timestampFrom() const;
  void setTimestampFrom(const QDateTime &newTimestampFrom);

  QDateTime timestampTo() const;
  void setTimestampTo(const QDateTime &newTimestampTo);

  Q_INVOKABLE void getChartData();

signals:

  void timestampFromChanged();
  void timestampToChanged();

private:
  EgVehicleListModel *m_vehicleListModel;
  EgDataProvider m_dataProvider;
  Q_PROPERTY(
      EgVehicleListModel *vehicleListModel READ vehicleListModel CONSTANT)

  QDateTime m_timestampFrom = QDateTime::currentDateTime();
  QDateTime m_timestampTo = QDateTime::currentDateTime();
  Q_PROPERTY(QDateTime timestampFrom READ timestampFrom WRITE setTimestampFrom
                 NOTIFY timestampFromChanged)
  Q_PROPERTY(QDateTime timestampTo READ timestampTo WRITE setTimestampTo NOTIFY
                 timestampToChanged)
};

#endif // APPLICATION_H
