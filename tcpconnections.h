#ifndef TCPCONNECTIONS_H
#define TCPCONNECTIONS_H

#include <QObject>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
class QThread;
class QReadWriteLock;
class TcpConnection;
QT_END_NAMESPACE

class TcpConnections : public QObject
{
    Q_OBJECT
public:
    explicit TcpConnections(QObject *parent = nullptr);
    ~TcpConnections();

    virtual int count();

protected:
    QMap<QTcpSocket*, TcpConnection*> m_connections;
    void removeSocket(QTcpSocket *socket);

signals:
    void quitting();
    void finished();

protected slots:
    void disconnected();
    void error(QAbstractSocket::SocketError socketError);

public slots:
    void start();
    void quit();
    void accept(qintptr handle, TcpConnection *connection);
};

#endif // TCPCONNECTIONS_H
