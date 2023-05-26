#ifndef EGHISTORICALCHART_H
#define EGHISTORICALCHART_H

#include "qmlplot.h"

#include <QObject>

class EgHistoricalChart : public CustomPlotItem {
  Q_OBJECT
public:
  EgHistoricalChart(QQuickItem *parent = 0) : CustomPlotItem(parent){};
};

#endif // EGHISTORICALCHART_H
