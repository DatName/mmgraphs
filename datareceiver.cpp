#include "datareceiver.h"
#include "ev++.h"
#include "cppproto/messages_generic.pb.h"
#include "cppproto/messages_marketdata.pb.h"
#include "cppproto/marketdata.pb.h"
#include "thread"

using namespace models;
using namespace AMQP;
using namespace std;

void RabbitMQReceiver::run(std::string address)
{
    ev::default_loop loop;
    AMQP::LibEvHandler handler(loop);

    AMQP::Address host(address);

    AMQP::TcpConnection connection(&handler, host);
    this->connection = &connection;

    AMQP::TcpChannel channel(&connection);
    this->channel = &channel;

    this->declareExchange("md_topic", AMQP::topic);
    this->addQueue("md_topic", "", "SS.#", AMQP::exclusive + !AMQP::durable);
    this->addQueue("indicators_topic", "", "", AMQP::exclusive + !AMQP::durable);

    ev_run(loop);
}


void RabbitMQReceiver::declareExchange(std::string name, AMQP::ExchangeType type = AMQP::topic)
{
    this->channel->declareExchange(name, type).onSuccess([&name]() {
        std::cout << "Exchange " << &name << " declared" << endl;
    }).onError([&name](const char *message) {
        std::cout << "Exchange error " << &name << ":" << message << endl;
    });

    this->channel->onError([&name](const char *msg) {
        std::cout << "Error opening channel" << &name << ":" << msg << endl;
    });

    this->channel->onReady([&name]() {
        std::cout << "Channel" << &name << "ready" << endl;
    });
}

//int parameters = AMQP::exclusive + !AMQP::durable
void RabbitMQReceiver::addQueue(std::string exchange, std::string queue, std::string routing_key, int parameters)
{
    this->channel->declareQueue(parameters)
            .onSuccess([](const std::string &queue, uint32_t messagecount, uint32_t consumercount) {
        std::cout << "queue declared: " << &queue << ". Messages count:" << messagecount << ". Consumer count:" << consumercount << endl;
    });

    this->channel->bindQueue(exchange, queue, routing_key);

    this->channel->consume(queue)
            .onReceived([this](const AMQP::Message &message, uint64_t deliveryTag, bool redelivered){

        if (redelivered) {
            return;
        }

        this->mutex->lock();

        size_t sz = message.bodySize();
        char* data = (char*)malloc(sizeof(char)*sz);
        for (size_t j = 0; j < sz; j++)
            data[j] = message.body()[j];

        models::Message headermsg;

        bool flag = headermsg.ParsePartialFromArray(message.body(), int(message.bodySize()));

        if (!flag) {
            std::cout << "faild to parse in consumer" << endl;
            return;
        }

        this->message->first = data;
        this->message->second = std::make_pair(deliveryTag, sz);
        this->channel->ack(deliveryTag);
        this->condition->notify_one();

        this->mutex->unlock();

    });
}
