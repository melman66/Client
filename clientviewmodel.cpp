
#include "clientviewmodel.h"

ClientViewModel::ClientViewModel(QObject *parent)
    : QObject{parent}
    , client_model{new ClientModel{this}}
{
    //connectedStateChanged
    connect(client_model, &ClientModel::connectedStateChanged
            , this, &ClientViewModel::connectedStateChanged);

    //errorCLient
    connect(client_model, &ClientModel::errorClient
            , this, &ClientViewModel::errorClient);

    //newClientName
    connect(client_model, &ClientModel::newClientName
            , this, &ClientViewModel::newClientName);

    //sendMsgToGUI
    connect(client_model, &ClientModel::sendMsgToGUI
            , this, &ClientViewModel::sendMsgToGUI);
}

void ClientViewModel::connectingToServer(  const QString &strHost
                                         , const QString &port
                                         , const QString client_name) const
{
    client_model->connectingToServer(strHost, port, client_name);
}

void ClientViewModel::disconnectingFromServer() const
{
    client_model->disconnectingFromServer();
}

bool ClientViewModel::getConnectedState() const
{
    return client_model->getConnectedState();
}

bool ClientViewModel::sendMessageToServer(QString msg) const
{
    return client_model->sendMessageToServer(msg);
}
