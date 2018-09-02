#include <QCoreApplication>
#include <QStringList>
#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWheelEvent>
#include "datareceiver.h"
#include <datacollector.h>

using namespace models;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->plot, SIGNAL(mouseWheel(QWheelEvent*)), SLOT(onMouseWheel(QWheelEvent*)));

    ui->plot->setInteraction(QCP::iRangeDrag);
    ui->plot->setInteraction(QCP::iRangeZoom);
    ui->plot->setInteraction(QCP::iSelectPlottables, true);

    auto graph = ui->plot->addGraph();
//    graph->setLineStyle(QCPGraph::lsNone);
    graph->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle));

    connect(graph->keyAxis(), SIGNAL(rangeChanged(QCPRange)), SLOT(xAxisChanged(QCPRange)));

    QSharedPointer<QCPAxisTickerDateTime> dateTicker(new QCPAxisTickerDateTime);
    dateTicker->setDateTimeFormat("d. MMMM\nyyyy");
    graph->keyAxis()->setTicker(dateTicker);

    auto *receiver = new DataReceiver();
    this->collector = new DataCollector(&receiver->m_chan);
    this->collector->start();

    QObject::connect(this->collector, SIGNAL(newData()),
            this, SLOT(updatePlot()));

    QThreadPool *threadPool = QThreadPool::globalInstance();
    threadPool->start(receiver);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updatePlot() {

//    qDebug() << "updating graph" << this->collector->data.length();

    auto *graph = this->ui->plot->graph(0);

    graph->keyAxis()->setRange(this->collector->data.first().key,
                               this->collector->data.last().key);

    this->ui->plot->graph(0)->data()->add(this->collector->data.last());

    graph->valueAxis()->rescale();
    this->ui->plot->replot();
    this->ui->plot->update();
}

void MainWindow::onMouseWheel(QWheelEvent *event)
{
    qDebug() << __FUNCTION__ << event << ":" << event->pos() << ":" << event->pos().x() << ":" << event->pos().y() << "delta:" << event->delta();
}

void MainWindow::on_add_clicked()
{
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

    double cumsum = 0.0;
    double fmax = 0.0;
    double fmin = 0.0;
    double r = 0.0;

    QDateTime t0 = QDateTime::currentDateTime();

    QVector<QCPGraphData> x;

    for (int j = 0; j < 1000; j++) {
        r = (static_cast <double> (rand()) / static_cast <double> (RAND_MAX) - 0.5)/2.0;
        cumsum += r;

        if (cumsum > fmax) {
            fmax = cumsum;
        }

        if (cumsum < fmin) {
            fmin = cumsum;
        }

        t0 = t0.addDays(1);
        QCPGraphData *newx = new QCPGraphData(t0.toTime_t(), cumsum);
        x.append(*newx);
    }

    graph->keyAxis()->setRange(x.first().key, x.last().key);
    graph->valueAxis()->setRange(fmin, fmax);

    graph->data()->set(x);

    QSharedPointer<QCPAxisTickerDateTime> dateTicker(new QCPAxisTickerDateTime);
    dateTicker->setDateTimeFormat("d. MMMM\nyyyy");
    graph->keyAxis()->setTicker(dateTicker);

    this->graphs.append(graph);

    ui->plot->replot();
    ui->plot->update();
}

void MainWindow::xAxisChanged(QCPRange range)
{
    QList<QCPGraph*>::iterator it;
    for (it=this->graphs.begin(); it!=this->graphs.end(); it++){
        (*it)->keyAxis()->setRange(range);
    }
    ui->plot->replot();
}
