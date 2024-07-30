
#ifndef CLIENTVIEWMODEL_H
#define CLIENTVIEWMODEL_H

#include <QObject>

#include "clientmodel.h"

class ClientViewModel : public QObject
{
    Q_OBJECT

private:
    ClientModel *client_model;
public:
    explicit ClientViewModel(QObject *parent = nullptr);

    void connectingToServer(  const QString &strHost
                            , const QString &port
                            , const QString client_name) const;
    void disconnectingFromServer() const;
    bool getConnectedState() const;
    bool sendMessageToServer(QString msg) const;

signals:
    void connectedStateChanged(bool);
    void errorClient(QString);
    void newClientName(QString);
    void sendMsgToGUI(QString);
};

#endif // CLIENTVIEWMODEL_H
