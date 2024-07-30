
#include "clientview.h"

ClientView::ClientView(QObject *parent)
    : QObject{parent}
    , client_view_model{new ClientViewModel{this}}
    , connectedState{false}
{
    //connectedStateChanged
    connect(client_view_model, &ClientViewModel::connectedStateChanged
            , this, &ClientView::connectedStateChanged);

    //errorClient
    connect(client_view_model, &ClientViewModel::errorClient
            , this, &ClientView::errorClient);

    //newClientName
    connect(client_view_model, &ClientViewModel::newClientName
            , this, &ClientView::newClientName);

    //sendMsgToGUI
    connect(client_view_model, &ClientViewModel::sendMsgToGUI
            , this, &ClientView::sendMsgToGUI);
}

void ClientView::connectingToServer(  const QString &strHost
                                    , const QString &port
                                    , const QString client_name) const
{
    client_view_model->connectingToServer(strHost, port, client_name);
}

void ClientView::disconnectingFromServer() const
{
    client_view_model->disconnectingFromServer();
}

QString ClientView::getCurrentDateTime() const
{
    return QString{ QDate::currentDate().toString()
                   + "   " + QTime::currentTime().toString()};
}

bool ClientView::sendMessageToServer(QString msg) const
{
    return client_view_model->sendMessageToServer(msg);
}

bool ClientView::getconnectedState() const
{
    return client_view_model->getConnectedState();
}

