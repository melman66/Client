
#include "clientmodel.h"

ClientModel::ClientModel(QObject *parent)
    : QObject{parent}
    , client_socket{nullptr}
    , next_block_size{0}
{}

void ClientModel::connectingToServer(  const QString &strHost
                                     , const QString &port
                                     , const QString name)
{
    client_socket = new QTcpSocket{this};

    quint16 temp_port = port.toUInt();
    client_name = name;

    connect(client_socket, &QTcpSocket::connected
            , this, &ClientModel::slotConnected);
    connect(client_socket, &QTcpSocket::readyRead
            , this, &ClientModel::slotReadyRead);
    connect(client_socket, &QTcpSocket::errorOccurred
            , this, &ClientModel::slotError);

    client_socket->connectToHost(strHost, temp_port);
}

void ClientModel::disconnectingFromServer()
{
    client_socket->disconnectFromHost();
    client_socket->disconnect();

    if(client_socket->state() == QAbstractSocket::UnconnectedState)
        emit connectedStateChanged(false);

    client_socket->deleteLater();
}

bool ClientModel::getConnectedState() const
{
    if(!client_socket)
        return false;

    if(client_socket->state() == QAbstractSocket::ConnectedState)
        return true;
    else
        return false;
}

QTcpSocket* ClientModel::getSocket() const
{
    return client_socket;
}

bool ClientModel::sendMessageToServer(QString msg)
{
    QByteArray arrDataBlock;
    QDataStream out(&arrDataBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_6);

    out << quint16(0)
        << msg;

    out.device()->seek(0);
    out << quint16(arrDataBlock.size() - sizeof(quint8));

    client_socket->write(arrDataBlock);

    return true;
}

//SLOTS
void ClientModel::slotConnected()
{
    sendMessageToServer(client_name);

    emit sendMsgToGUI("Client is connected to the server.");

    emit connectedStateChanged(true);
}

void ClientModel::slotError(QAbstractSocket::SocketError err)
{
    QString strError =
        "!!! Client Error! " + (err == QAbstractSocket::HostNotFoundError ?
                         "The host was not found.":
                         err == QAbstractSocket::RemoteHostClosedError ?
                         "The remote host is closed.":
                         err == QAbstractSocket::ConnectionRefusedError ?
                         "The connection was refused." :
                         QString(client_socket->errorString())
                     );

    client_socket->disconnectFromHost();
    client_socket->disconnect();

    emit errorClient(strError);
}

void ClientModel::slotReadyRead()
{
    QDataStream in(client_socket);
    in.setVersion(QDataStream::Qt_6_6);

    QString msg;

    forever{
        if(!next_block_size){
            if(client_socket->bytesAvailable() < sizeof(quint16))
                break;
            in >> next_block_size;
        }
        in >> msg;
        next_block_size = 0;
    }

    //checking client's name
    if(!name_approved){
        if (msg != client_name){
            client_name = msg;
            emit sendMsgToGUI(QString{ "Your name is occuped. Your new name on server: " + msg});
            emit newClientName(client_name);
        }
        name_approved = true;
    }
    else
        emit sendMsgToGUI(QString{
              QDate::currentDate().toString() + "   "
            + QTime::currentTime().toString() + "\n"
            + "server:\n" + msg});
}


