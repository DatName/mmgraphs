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
    Ui::MainWindow* ui;
    QMap<QString, QCPGraph*> graphs;

public slots:
    void onMouseWheel(QWheelEvent *event);
    void xAxisChanged(QCPRange range);
    void onNewData(QMap<QString, double> data);

private slots:
    void on_indicatorsList_itemClicked(QListWidgetItem *item);
    void on_rescale_clicked();
};

#endif // MAINWINDOW_H
