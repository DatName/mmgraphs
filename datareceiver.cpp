#include "datareceiver.h"
#include "cppproto/messages_generic.pb.h"
#include "cppproto/messages_marketdata.pb.h"
#include "cppproto/marketdata.pb.h"

using namespace models;
using namespace AMQP;

void DataReceiver::run()
{
    AMQP::LibEvHandler handler(this->loop);

    AMQP::TcpConnection connection(&handler, this->m_host);
    this->connection = &connection;

    AMQP::TcpChannel channel(&connection);
    this->channel = &channel;

    this->declareExchange("md_topic", AMQP::topic);
    this->addQueue("md_topic", "", "SS.#", AMQP::exclusive + !AMQP::durable);

    ev_run(this->loop);
}

void DataReceiver::declareExchange(std::string name, AMQP::ExchangeType type = AMQP::topic)
{
    this->channel->declareExchange(name, type).onSuccess([&name]() {
        qDebug() << "Exchange" << &name << "declared";
    }).onError([&name](const char *message) {
        qDebug() << "Exchange error" << &name << ":" << message;
    });

    this->channel->onError([&name](const char *msg) {
        qDebug() << "Error opening channel" << &name << ":" << msg;
    });

    this->channel->onReady([&name]() {
        qDebug() << "Channel" << &name << "ready";
    });
}

//int parameters = AMQP::exclusive + !AMQP::durable
void DataReceiver::addQueue(std::string exchange, std::string queue, std::string routing_key, int parameters)
{
    if (this->channel == nullptr) {
        qDebug() << "NULL PTR!";
    }

    this->channel->declareQueue(parameters)
            .onSuccess([](const std::string &queue, uint32_t messagecount, uint32_t consumercount) {
        qDebug() << "queue declared: " << &queue << ". Messages count:" << messagecount << ". Consumer count:" << consumercount;
    });

    this->channel->bindQueue(exchange, queue, routing_key);

    this->channel->consume(queue)
            .onReceived([this](const AMQP::Message &message, uint64_t deliveryTag, bool redelivered){

        if (!redelivered) {
            this->m_chan.put(std::make_pair(message.body(), message.bodySize()));
        }

        this->channel->ack(deliveryTag);
    });
}
