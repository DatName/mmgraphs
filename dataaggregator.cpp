#include "dataaggregator.h"

void DataAggregator::run() {
    QCPGraphData *msg;

    while (this->graphdata->get(msg)) {
        this->x.append(msg);
        emit newValue();

        this->graph->data()->add(*msg);
        this->graph->parentPlot()->replot();
        this->graph->parentPlot()->update();
    }
}
