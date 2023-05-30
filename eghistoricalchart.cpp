#include "eghistoricalchart.h"
#include "qcustomplot.h"

EgHistoricalChart::EgHistoricalChart(QQuickItem *parent)
    : CustomPlotItem(parent) {

  auto defaultLabelFont = m_CustomPlot->xAxis->labelFont();
  defaultLabelFont.setPointSize(15);
  m_CustomPlot->xAxis->setLabelFont(defaultLabelFont);
  m_CustomPlot->yAxis->setLabelFont(defaultLabelFont);

  auto defaultTickLabelFont = m_CustomPlot->xAxis->tickLabelFont();
  defaultLabelFont.setPointSize(12);
  m_CustomPlot->xAxis->setTickLabelFont(defaultTickLabelFont);
  m_CustomPlot->yAxis->setTickLabelFont(defaultTickLabelFont);

  //  m_CustomPlot->yAxis->setRange(-30.0, 50.0);
  m_CustomPlot->yAxis->setRange(0.0, 0.0);

  m_CustomPlot->xAxis->setLabel("Czas");
  m_CustomPlot->yAxis->setLabel("Temperatura");

  QSharedPointer<QCPAxisTickerDateTime> dateTicker(new QCPAxisTickerDateTime);
  dateTicker->setDateTimeFormat("hh:mm dd/MM/yyyy");
  m_CustomPlot->xAxis->setTicker(dateTicker);

  m_CustomPlot->replot();
}

QColor EgHistoricalChart::backgroundColor() const { return m_backgroundColor; }

void EgHistoricalChart::setBackgroundColor(const QColor &newBackgroundColor) {
  if (m_backgroundColor == newBackgroundColor)
    return;
  m_backgroundColor = newBackgroundColor;
  m_CustomPlot->setBackground(QBrush(m_backgroundColor));
  m_CustomPlot->replot();
  emit backgroundColorChanged();
}

QColor EgHistoricalChart::foregroundColor() const { return m_foregroundColor; }

void EgHistoricalChart::setForegroundColor(const QColor &newForegroundColor) {
  if (m_foregroundColor == newForegroundColor)
    return;
  m_foregroundColor = newForegroundColor;

  m_CustomPlot->xAxis->setLabelColor(m_foregroundColor);
  m_CustomPlot->xAxis->setTickLabelColor(m_foregroundColor);
  m_CustomPlot->xAxis->setSelectedLabelColor(m_foregroundColor);
  m_CustomPlot->xAxis->setSelectedTickLabelColor(m_foregroundColor);
  m_CustomPlot->xAxis2->setLabelColor(m_foregroundColor);
  m_CustomPlot->xAxis2->setTickLabelColor(m_foregroundColor);
  m_CustomPlot->xAxis2->setSelectedLabelColor(m_foregroundColor);
  m_CustomPlot->xAxis2->setSelectedTickLabelColor(m_foregroundColor);
  m_CustomPlot->yAxis->setLabelColor(m_foregroundColor);
  m_CustomPlot->yAxis->setTickLabelColor(m_foregroundColor);
  m_CustomPlot->yAxis->setSelectedLabelColor(m_foregroundColor);
  m_CustomPlot->yAxis->setSelectedTickLabelColor(m_foregroundColor);
  m_CustomPlot->yAxis2->setLabelColor(m_foregroundColor);
  m_CustomPlot->yAxis2->setTickLabelColor(m_foregroundColor);
  m_CustomPlot->yAxis2->setSelectedLabelColor(m_foregroundColor);
  m_CustomPlot->yAxis2->setSelectedTickLabelColor(m_foregroundColor);
  m_CustomPlot->replot();

  emit foregroundColorChanged();
}

void EgHistoricalChart::setChartData(EgHistoricalChartData &newData) {
  m_CustomPlot->clearPlottables();
  m_CustomPlot->yAxis->setRange(0.0, 0.0);

  m_CustomPlot->xAxis->setRange(newData.m_timestampFrom.toTime_t(),
                                newData.m_timestampTo.toTime_t());

  for (auto &serie : newData.m_series) {
    auto *graph = m_CustomPlot->addGraph();

    graph->setPen(QPen(serie.m_color));
    graph->setName(serie.m_name);
    graph->setData(serie.m_x, serie.m_y);
    graph->rescaleAxes(true);
  }

  m_CustomPlot->replot();
}

void EgHistoricalChart::showTestData() {
  EgHistoricalChartData chartData;

  chartData.m_timestampFrom = QDateTime(QDate(2023, 1, 1), QTime(0, 0));
  chartData.m_timestampTo = QDateTime(QDate(2023, 1, 2), QTime(0, 0));

  EgHistoricalChartSeriesData series1;
  series1.m_name = "Fiat";
  series1.m_color = QColorConstants::Yellow;

  series1.m_x = {(double)QDateTime(QDate(2023, 1, 1), QTime(0, 0)).toTime_t(),
                 (double)QDateTime(QDate(2023, 1, 1), QTime(3, 0)).toTime_t(),
                 (double)QDateTime(QDate(2023, 1, 1), QTime(6, 0)).toTime_t(),
                 (double)QDateTime(QDate(2023, 1, 1), QTime(12, 0)).toTime_t(),
                 (double)QDateTime(QDate(2023, 1, 1), QTime(15, 0)).toTime_t(),
                 (double)QDateTime(QDate(2023, 1, 1), QTime(18, 0)).toTime_t()};
  series1.m_y = {-5, -2, -1, 10, 15, 13};

  chartData.m_series.append(series1);

  series1.m_name = "Skoda";
  series1.m_color = QColorConstants::Blue;

  series1.m_x = {(double)QDateTime(QDate(2023, 1, 1), QTime(1, 0)).toTime_t(),
                 (double)QDateTime(QDate(2023, 1, 1), QTime(4, 0)).toTime_t(),
                 (double)QDateTime(QDate(2023, 1, 1), QTime(8, 0)).toTime_t(),
                 (double)QDateTime(QDate(2023, 1, 1), QTime(15, 0)).toTime_t(),
                 (double)QDateTime(QDate(2023, 1, 1), QTime(19, 0)).toTime_t(),
                 (double)QDateTime(QDate(2023, 1, 1), QTime(22, 0)).toTime_t()};
  series1.m_y = {-5, -2, -1, 10, 15, 13};

  chartData.m_series.append(series1);

  setChartData(chartData);
}
