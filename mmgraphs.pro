#-------------------------------------------------
#
# Project created by QtCreator 2018-09-01T10:52:25
#
#-------------------------------------------------

QT       += core gui network widgets printsupport

TARGET = mmgraphs
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    qcustomplot.cpp \
    rabbitmq.cpp \
    cppproto/marketdata.pb.cc \
    cppproto/messages_broker.pb.cc \
    cppproto/messages_config.pb.cc \
    cppproto/messages_generic.pb.cc \
    cppproto/messages_indicators.pb.cc \
    cppproto/messages_marketdata.pb.cc \
    cppproto/messages_rm.pb.cc \
    cppproto/messages_robot.pb.cc \
    cppproto/order.pb.cc \
    datareceiver.cpp \
    datacollector.cpp

HEADERS += \
        mainwindow.h \
    qcustomplot.h \
    rabbitmq.h \
    cppproto/marketdata.pb.h \
    cppproto/messages_broker.pb.h \
    cppproto/messages_config.pb.h \
    cppproto/messages_generic.pb.h \
    cppproto/messages_indicators.pb.h \
    cppproto/messages_marketdata.pb.h \
    cppproto/messages_rm.pb.h \
    cppproto/messages_robot.pb.h \
    cppproto/order.pb.h \
    datareceiver.h \
    datacollector.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += /usr/include/openssl

# add protobuf (http://beaufour.dk/blog/2008/02/using-pkgconfig.html)
CONFIG += link_pkgconfig
PKGCONFIG += protobuf

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../AMQP-CPP-3.1.0/build/bin/release/ -lamqpcpp
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../AMQP-CPP-3.1.0/build/bin/debug/ -lamqpcpp
else:unix: LIBS += -L$$PWD/../AMQP-CPP-3.1.0/build/bin/ -lamqpcpp

INCLUDEPATH += $$PWD/../AMQP-CPP-3.1.0/include
DEPENDPATH += $$PWD/../AMQP-CPP-3.1.0/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../AMQP-CPP-3.1.0/build/bin/release/libamqpcpp.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../AMQP-CPP-3.1.0/build/bin/debug/libamqpcpp.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../AMQP-CPP-3.1.0/build/bin/release/amqpcpp.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../AMQP-CPP-3.1.0/build/bin/debug/amqpcpp.lib
else:unix: PRE_TARGETDEPS += $$PWD/../AMQP-CPP-3.1.0/build/bin/libamqpcpp.a

LIBS += -lev -ldl
