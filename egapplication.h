#ifndef APPLICATION_H
#define APPLICATION_H

#include "egvehiclelistmodel.h"

#include <QObject>

class EgApplication : public QObject {
  Q_OBJECT
public:
  explicit EgApplication(QObject *parent = nullptr);

    EgVehicleListModel *vehicleListModel() const;

signals:

private:
    EgVehicleListModel *m_vehicleListModel;
    Q_PROPERTY(EgVehicleListModel *vehicleListModel READ vehicleListModel CONSTANT)
};

#endif // APPLICATION_H
