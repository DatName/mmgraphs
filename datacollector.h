#ifndef DATACOLLECTOR_H
#define DATACOLLECTOR_H

#include <QObject>
#include <qcustomplot.h>
#include <cppproto/messages_marketdata.pb.h>

class DataCollector : public QThread
{
    Q_OBJECT
public:
    explicit DataCollector(QObject *parent = nullptr) {}
    void setConnection(std::pair<const char*, std::pair<int, size_t>> *msg, std::mutex *m, std::condition_variable *cond);
    void run();

public:
    std::pair<const char*, std::pair<int, size_t>> *message;
    std::mutex *mutex;
    std::condition_variable *condition;
    std::mutex ownMutex;

public:
    void onBookSnapshot(models::OrderBookSnapshot snapshot);

signals:
    void onNewData(QMap<QString, double> data);

public slots:
};

#endif // DATACOLLECTOR_H
