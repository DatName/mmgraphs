#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCore/QDateTime>
#include <QtCharts/QDateTimeAxis>
#include <QtCharts/QValueAxis>
#include <QObject>
#include <qcustomplot.h>
#include <datareceiver.h>
#include <datacollector.h>
#include <dataaggregator.h>

QT_CHARTS_USE_NAMESPACE

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    DataReceiver *receiver;
    DataCollector *collector;
    DataAggregator *aggregator;

    Ui::MainWindow* ui;
    QList<QCPGraph*> graphs;
    QVector<QCPGraphData*> data;

public slots:
    void onMouseWheel(QWheelEvent *event);
    void on_add_clicked();
    void xAxisChanged(QCPRange range);
    void updatePlot();
};

#endif // MAINWINDOW_H
