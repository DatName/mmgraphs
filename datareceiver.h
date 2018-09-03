#ifndef DATARECEIVER_H
#define DATARECEIVER_H

#include <amqpcpp.h>
#include <amqpcpp/libev.h>
#include <amqpcpp/linux_tcp.h>
#include <condition_variable>

using namespace std;

class RabbitMQReceiver
{
public:
    RabbitMQReceiver(std::pair<const char*, std::pair<int, size_t>> *msg, std::mutex *m, std::condition_variable *cond) {
        message = msg;
        mutex = m;
        condition = cond;
    }

    ~RabbitMQReceiver() {}
public:
    std::pair<const char*, std::pair<int, size_t>> *message;
    std::mutex *mutex;
    std::condition_variable *condition;

public:
    void run(std::string address);
    void declareExchange(std::string name, AMQP::ExchangeType type);
    void addQueue(std::string exchange, std::string queue, std::string routing_key, int parameters);

private:
    AMQP::TcpConnection *connection;
    AMQP::TcpChannel *channel;
};

#endif // DATARECEIVER_H
