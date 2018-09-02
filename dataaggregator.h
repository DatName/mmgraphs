#ifndef DATAAGGREGATOR_H
#define DATAAGGREGATOR_H
#include <QRunnable>
#include "datacollector.h"

class DataAggregator : public QObject
{
    Q_OBJECT
public:
    DataAggregator(QCPGraph *graph_inc, GoChannel<QCPGraphData*> *graphdata_inc) {
        graphdata = graphdata_inc;
        graph = graph_inc;
    }

    QCPGraph *graph;
    GoChannel<QCPGraphData*> *graphdata;
    QVector<QCPGraphData*> x;

    void run();
signals:
    void newValue();
};

#endif // DATAAGGREGATOR_H
