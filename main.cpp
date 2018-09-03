#include "mainwindow.h"
#include <QApplication>
#include "datareceiver.h"
#include "datacollector.h"
#include "QObject"
#include "qmetatype.h"

#include "cppproto/messages_generic.pb.h"

typedef QMap<QString, double> Message;

int main(int argc, char *argv[])
{

    qRegisterMetaType<Message>();

    QApplication a(argc, argv);
    MainWindow w;

    std::pair<const char*, std::pair<int, size_t>> msg;
    std::condition_variable condition;
    std::mutex m;

    RabbitMQReceiver receiver = RabbitMQReceiver(&msg, &m, &condition);
    std::string address = "amqp://donald:tEB8sn2CGQCKkBajaUUbbm8wL@vault.scrutiny.space//";
    std::thread t(&RabbitMQReceiver::run, ref(receiver), address);
    t.detach();

    DataCollector *collector = new DataCollector();
    collector->setConnection(&msg, &m, &condition);
    collector->start();

    QObject::connect(collector, SIGNAL(onNewData(QMap<QString, double>)), &w, SLOT(onNewData(QMap<QString, double>)));

    w.show();
    return  a.exec();
}
