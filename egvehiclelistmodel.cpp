#include "egvehiclelistmodel.h"

EgVehicleListModel::EgVehicleListModel(QObject *parent)
    : QAbstractListModel{parent} {}

int EgVehicleListModel::rowCount(const QModelIndex &parent) const {
  if (parent.isValid()) {
    return 0;
  }

  return m_data.count();
}

QVariant EgVehicleListModel::data(const QModelIndex &index, int role) const {
  if (!index.isValid()) {
    return QVariant();
  }
  if (index.column() > 0) {
    return QVariant();
  }
  if (index.row() >= m_data.count()) {
    return QVariant();
  }

  switch (role) {
  case IdRole:
    return m_data[index.row()].id;
  case NameRole:
    return m_data[index.row()].name;
  case PlateNoRole:
    return m_data[index.row()].plateNo;
  case SelectedToViewRole:
    return m_data[index.row()].selectedToView;
  case ColorRole:
    return m_data[index.row()].color;
  }

  return QVariant();
}

bool EgVehicleListModel::setData(const QModelIndex &index,
                                 const QVariant &value, int role) {
  if (!index.isValid()) {
    return false;
  }
  if (index.column() > 0) {
    return false;
  }
  if (index.row() >= m_data.count()) {
    return false;
  }

  switch (role) {
    //  case IdRole:
    //  case NameRole:
    //  case PlateNoRole:
  case SelectedToViewRole:
    m_data[index.row()].selectedToView = value.toBool();
    emit dataChanged(index, index, {role});
    return true;
  case ColorRole:
    m_data[index.row()].color = value.value<QColor>();
    emit dataChanged(index, index, {role});
    return true;
  }

  return false;
}

QHash<int, QByteArray> EgVehicleListModel::roleNames() const {
  static const QHash<int, QByteArray> roles = {
      {IdRole, "id"},
      {NameRole, "name"},
      {PlateNoRole, "plateNo"},
      {SelectedToViewRole, "selectedToView"},
      {ColorRole, "color"}};

  return roles;
}

void EgVehicleListModel::overrideData(QList<EgVehicleListModelData> &newData) {
  beginResetModel();
  m_data = newData;
  endResetModel();
}

QList<int> EgVehicleListModel::getSelectedVehicleList() {
  QList<int> retval;
  foreach (auto veh, m_data) {
    if (veh.selectedToView) {
      retval.append(veh.id);
    }
  }

  return retval;
}
