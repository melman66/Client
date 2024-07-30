
#ifndef CLIENTVIEW_H
#define CLIENTVIEW_H

#include <QObject>
#include <QDebug>
#include <QtQml>

#include "clientviewmodel.h"

class ClientView : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(bool connectedState
                   READ getconnectedState
                       NOTIFY connectedStateChanged)

private:
    ClientViewModel *client_view_model;

    bool connectedState;

public:
    explicit ClientView(QObject *parent = nullptr);

    Q_INVOKABLE void    connectingToServer(  const QString &strHost
                                        , const QString &port
                                        , const QString client_name) const;
    Q_INVOKABLE void    disconnectingFromServer() const;
    Q_INVOKABLE QString getCurrentDateTime() const;
    Q_INVOKABLE bool    sendMessageToServer(QString msg) const;

    bool getconnectedState() const;

signals:
    void connectedStateChanged(bool);
    void errorClient(QString);
    void sendMsgToGUI(QString);
    void newClientName(QString);
    void messageSended(QString);
};

#endif // CLIENTVIEW_H
