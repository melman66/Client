
#ifndef CLIENTMODEL_H
#define CLIENTMODEL_H

#include <QDebug>
#include <QObject>
#include <QTcpSocket>
#include <QTime>
#include <QPair>

class ClientModel : public QObject
{
    Q_OBJECT

private:
    QString     client_name;
    QTcpSocket* client_socket;
    quint16     next_block_size;
    bool        name_approved{false};

public:
    explicit ClientModel(QObject *parent);

    void        connectingToServer(  const QString &strHost
                            , const QString &port
                            , const QString name);
    void        disconnectingFromServer();
    bool        getConnectedState() const;
    QTcpSocket* getSocket() const;
    bool        sendMessageToServer(QString msg);


public slots:
    void slotConnected();
    void slotError(QAbstractSocket::SocketError err);
    void slotReadyRead();

signals:
    void connectedStateChanged(bool);
    void errorClient(QString);
    void newClientName(QString);
    void sendMsgToGUI(QString);
};

#endif // CLIENTMODEL_H
