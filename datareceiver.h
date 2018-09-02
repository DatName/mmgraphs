#ifndef DATARECEIVER_H
#define DATARECEIVER_H

#include <QRunnable>
#include <QDebug>
#include <ev++.h>
#include <amqpcpp.h>
#include <amqpcpp/libev.h>
#include <amqpcpp/linux_tcp.h>
#include <condition_variable>
#include <cppproto/messages_generic.pb.h>

template<class item>

//https://st.xorian.net/blog/2012/08/go-style-channel-in-c/
class GoChannel {

private:
    std::list<item> queue;
    std::mutex m;
    std::condition_variable cv;
    bool closed;

public:
    GoChannel() : closed(false) { }

    void close() {
        std::unique_lock<std::mutex> lock(m);
        closed = true;
        cv.notify_all();
    }

    bool is_closed() {
        std::unique_lock<std::mutex> lock(m);
        return closed;
    }

    void put(const item &i) {
        std::unique_lock<std::mutex> lock(m);

        if(closed)
            throw std::logic_error("put to closed channel");

        queue.push_back(i);
        cv.notify_one();
    }

    bool get(item &out, bool wait = true) {
        std::unique_lock<std::mutex> lock(m);

        if(wait)
            cv.wait(lock, [&](){ return closed || !queue.empty(); });

        if(queue.empty())
            return false;

        out = queue.front();
        queue.pop_front();
        return true;
    }
};


class DataReceiver : public QRunnable
{
public:
    GoChannel<std::pair<const char*, size_t>> m_chan;

public:
    DataReceiver() {}

    void run();
    void declareExchange(std::string name, AMQP::ExchangeType type);
    void addQueue(std::string exchange, std::string queue, std::string routing_key, int parameters);

private:
    AMQP::Address m_host = AMQP::Address("amqp://donald:tEB8sn2CGQCKkBajaUUbbm8wL@vault.scrutiny.space//");

    ev::default_loop loop;
    AMQP::TcpConnection *connection;
    AMQP::TcpChannel *channel;
};

#endif // DATARECEIVER_H
