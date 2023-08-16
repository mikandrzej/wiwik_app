#ifndef EGVEHICLELISTMODEL_H
#define EGVEHICLELISTMODEL_H

#include <QAbstractListModel>
#include <QColor>

struct EgVehicleListModelData {
  int id;
  QString name;
  QString plateNo;
  bool selectedToView;
  QColor color;
};

class EgVehicleListModel : public QAbstractListModel {
  Q_OBJECT

  enum {
    IdRole = Qt::UserRole,
    NameRole,
    PlateNoRole,
    SelectedToViewRole,
    ColorRole
  };

public:
  explicit EgVehicleListModel(QObject *parent = nullptr);

  // QAbstractItemModel interface
public:
  int rowCount(const QModelIndex &parent) const override;
  QVariant data(const QModelIndex &index, int role) const override;
  bool setData(const QModelIndex &index, const QVariant &value,
               int role) override;
  QHash<int, QByteArray> roleNames() const override;

  void overrideData(QList<EgVehicleListModelData> &newData);
  QList<int> getSelectedVehicleList();
  QColor getVehicleColor(int id);

private:
  QList<EgVehicleListModelData> m_data;
};

#endif // EGVEHICLELISTMODEL_H

//{id: 0, name: "Payday", plateNo: "PRA2931",  selectedToView: false, color:
//"#F0C97A"},
