#include "datacollector.h"
#include <QCoreApplication>
#include <time.h>
#include <ctime>
#include <stdio.h>
#include "cppproto/messages_generic.pb.h"
#include "cppproto/messages_marketdata.pb.h"
#include "cppproto/marketdata.pb.h"
#include "qcustomplot.h"

using namespace std;
using namespace models;
using namespace QCP;

void DataCollector::run() {
    std::pair<const char*, size_t> message;
    models::OrderBookSnapshot orderbook;

    while (this->chan->get(message)) {

        bool flag = orderbook.ParseFromArray(message.first, static_cast<int>(message.second));

        if (!flag) {
//            qDebug() << "error parsing order book from string" << orderbook.body().DebugString().c_str();
            continue;
        }

        auto snapshot = orderbook.body().snapshot();
        std::string symbol = snapshot.symbol().c_str();
        std::string exchange = snapshot.exchange().c_str();

        if (symbol.compare("ETH/BTC") != 0) {
            continue;
        }

        qDebug() << exchange.c_str();

        if (exchange.compare("OKEX") != 0) {
            continue;
        }

        const time_t t = orderbook.header().timestamp()/1000;

        auto bids = &snapshot.bids();
        auto asks = &snapshot.asks();

        if ((snapshot.asks_size() == 0) || (snapshot.bids_size() == 0)) {
            continue;
        }

        auto b = bids->at(0).price();
        auto a = asks->at(0).price();
        QCPGraphData *newx = new QCPGraphData(t, (b+a)/2.0);

//        qDebug() << "emitting signal";
        this->data.append(*newx);

        emit newData();
    }
}
