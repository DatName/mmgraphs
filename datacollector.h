#ifndef DATACOLLECTOR_H
#define DATACOLLECTOR_H
#include <QThread>
#include "datareceiver.h"
#include <qcustomplot.h>

class DataCollector : public QThread
{
    Q_OBJECT
public:
    DataCollector(GoChannel<std::pair<const char*, size_t>> *msg_channel) {
        chan = msg_channel;
    }

    GoChannel<std::pair<const char*, size_t>> *chan;
    QVector<QCPGraphData> data;
    void run(void);

signals:
    void newData();

};

#endif // DATACOLLECTOR_H
