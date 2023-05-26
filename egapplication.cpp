#include "egapplication.h"

EgApplication::EgApplication(QObject *parent) : QObject{parent} {
  m_vehicleListModel = new EgVehicleListModel(this);
}

EgVehicleListModel *EgApplication::vehicleListModel() const {
  return m_vehicleListModel;
}
