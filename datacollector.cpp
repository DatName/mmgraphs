#include "datacollector.h"
#include "cppproto/messages_marketdata.pb.h"
#include "cppproto/messages_indicators.pb.h"
#include "cppproto/marketdata.pb.h"
#include "QMap";

void DataCollector::setConnection(std::pair<const char *, std::pair<int, size_t> > *msg, std::mutex *m, std::condition_variable *cond)
{
    this->message = msg;
    this->mutex = m;
    this->condition = cond;
}

void DataCollector::run()
{
    models::Message msgheader;

    while (true) {
        std::unique_lock<std::mutex> locker(*this->mutex);
        this->condition->wait(locker);

        auto data = this->message->first;
        auto deliveryTag = this->message->second.first;
        auto size = this->message->second.second;

        bool flag = msgheader.ParseFromArray(data, int(size));

        if (!flag) {
            qDebug() << "Failed to parse" << size << " bytes from tag " << deliveryTag;
            continue;
        }

        switch (msgheader.header().type()) {
        case models::BOOK_SNAPSHOT:
            models::OrderBookSnapshot snapshot;
            flag = snapshot.ParseFromArray(data, int(size));

            if (flag) {
                this->onBookSnapshot(snapshot);
            } else {
                qDebug() << "Failed to parse order book snapshot";
            }
            break;
        }
    }
}

void DataCollector::onBookSnapshot(models::OrderBookSnapshot snapshot) {
    std::lock_guard<std::mutex> lock(this->ownMutex);

    QString symbol = QString(snapshot.body().snapshot().symbol().c_str());
    QString exchange = QString(snapshot.body().snapshot().exchange().c_str());

    auto indicators = snapshot.body().indicators();
    auto data = QMap<QString, double>();

    QString instrument = symbol.append("|").append(exchange);

    for (auto it=indicators.begin();it != indicators.end(); it++) {
        QString k = QString(it->first.c_str());
        double v = it->second;
        auto key = QString(instrument).append("-").append(k);
        data[key] = v;
    }

    emit onNewData(data);
}
