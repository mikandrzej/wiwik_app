#ifndef EGHISTORICALCHART_H
#define EGHISTORICALCHART_H

#include "qmlplot.h"

#include <QObject>

struct EgHistoricalChartSeriesData {
  QString m_name;
  QColor m_color;
  QVector<double> m_x;
  QVector<double> m_y;
};

struct EgHistoricalChartData {
  QVector<EgHistoricalChartSeriesData> m_series;
  QDateTime m_timestampFrom;
  QDateTime m_timestampTo;
};

class EgHistoricalChart : public CustomPlotItem {
  Q_OBJECT
public:
  EgHistoricalChart(QQuickItem *parent = 0);

  QColor backgroundColor() const;
  void setBackgroundColor(const QColor &newBackgroundColor);

  QColor foregroundColor() const;
  void setForegroundColor(const QColor &newForegroundColor);

  void setChartData(EgHistoricalChartData &newData);

  Q_INVOKABLE void showTestData();

signals:
  void backgroundColorChanged();
  void foregroundColorChanged();

private:
  QColor m_backgroundColor;
  QColor m_foregroundColor;
  Q_PROPERTY(QColor backgroundColor READ backgroundColor WRITE
                 setBackgroundColor NOTIFY backgroundColorChanged)
  Q_PROPERTY(QColor foregroundColor READ foregroundColor WRITE
                 setForegroundColor NOTIFY foregroundColorChanged)
};

#endif // EGHISTORICALCHART_H
