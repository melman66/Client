
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QIcon>

#include "clientview.h"
#include "config.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine_client;
    const QUrl url_client(u"qrc:/Client/GUI/ClientWindow.qml"_qs);
    QObject::connect(&engine_client, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine_client.load(url_client);

    qmlRegisterType<ClientView>("Client", 1, 0, "ClientView");

    app.setWindowIcon(QIcon(ICON_SOURCE));

    return app.exec();
}
