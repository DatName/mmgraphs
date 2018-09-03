#include <QCoreApplication>
#include <QStringList>
#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWheelEvent>
#include "datareceiver.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->plot, SIGNAL(mouseWheel(QWheelEvent*)), SLOT(onMouseWheel(QWheelEvent*)));

    ui->plot->setInteraction(QCP::iRangeDrag);
    ui->plot->setInteraction(QCP::iRangeZoom);
    ui->plot->setInteraction(QCP::iSelectPlottables, true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onNewData(QMap<QString, double> new_data) {

    QDateTime t0 = QDateTime::currentDateTime();

    for (auto it = new_data.begin(); it != new_data.end(); it++ ) {
        auto iter = this->graphs.find(it.key());

        if (iter == this->graphs.end())
            continue;

        auto graph = iter.value();

        auto newdata = QCPGraphData(t0.toTime_t(), it.value());

        graph->data()->add(newdata);

        if (graph->data()->size() < 5) {
            graph->keyAxis()->rescale();
            graph->valueAxis()->rescale();
        }
    }

    for (auto it = new_data.begin(); it != new_data.end(); it++) {
        QString qstr = it.key();
        auto found = this->ui->indicatorsList->findItems(qstr, Qt::MatchFlag::MatchExactly);
        if (found.isEmpty()) {
            this->ui->indicatorsList->addItem(qstr);
        }
    }

    this->ui->plot->replot();
    this->ui->plot->update();
}

void MainWindow::onMouseWheel(QWheelEvent *event)
{
    qDebug() << __FUNCTION__ << event << ":" << event->pos() << ":" << event->pos().x() << ":" << event->pos().y() << "delta:" << event->delta();
}

void MainWindow::xAxisChanged(QCPRange range)
{
    for (auto it=this->graphs.begin(); it!=this->graphs.end(); it++){
        (*it)->keyAxis()->setRange(range);
    }
    ui->plot->replot();
}


void MainWindow::on_indicatorsList_itemClicked(QListWidgetItem *item)
{
    auto indicator_name = item->text();

    qDebug() << "context changed" << indicator_name;
    for (auto it=this->graphs.begin(); it != this->graphs.end(); it++){
        if (it.key().compare(indicator_name) == 0) {
            return;
        }
    }

    int graphcount = ui->plot->graphCount();
    QCPGraph *graph;

    if (graphcount > 0) {
        QCPLayoutGrid *subLayout = new QCPLayoutGrid;

        QCPAxisRect *axisRect = new QCPAxisRect(ui->plot);
        subLayout->addElement(0, 0, axisRect);

        ui->plot->plotLayout()->addElement(graphcount, 0, subLayout);
        graph = ui->plot->addGraph(axisRect->axis(QCPAxis::atBottom), axisRect->axis(QCPAxis::atLeft));

    } else {
        graph = ui->plot->addGraph();
    }

    connect(graph->keyAxis(), SIGNAL(rangeChanged(QCPRange)), SLOT(xAxisChanged(QCPRange)));

    graph->setLineStyle(QCPGraph::lsStepRight);
    graph->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle));

    QSharedPointer<QCPAxisTickerDateTime> dateTicker(new QCPAxisTickerDateTime);
    dateTicker->setDateTimeFormat("hh:mm:ss");
    graph->keyAxis()->setTicker(dateTicker);
    dateTicker->setTickStepStrategy(QCPAxisTicker::tssReadability);

    this->graphs[indicator_name] = graph;
}

void MainWindow::on_rescale_clicked()
{
    for (auto it=this->graphs.begin(); it!=this->graphs.end(); it++){
        (*it)->valueAxis()->rescale();
    }
}
