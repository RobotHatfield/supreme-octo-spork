#include "tcpconnection.h"

#include <QDebug>

TcpConnection::TcpConnection(QObject *parent) : QObject(parent)
{
    qDebug() << this << "has been created";
}

TcpConnection::~TcpConnection()
{
    qDebug() << this << "has been destroyed";
}

void TcpConnection::setSocket(QTcpSocket *socket)
{
    m_socket = socket;
    connect(m_socket,&QTcpSocket::connected, this, &TcpConnection::connected);
    connect(m_socket,&QTcpSocket::disconnected, this, &TcpConnection::disconnected);
    connect(m_socket,&QTcpSocket::readyRead, this, &TcpConnection::readyRead);
    connect(m_socket,&QTcpSocket::bytesWritten, this, &TcpConnection::bytesWritten);
    connect(m_socket,&QTcpSocket::stateChanged, this, &TcpConnection::stateChanged);
    connect(m_socket,static_cast<void (QTcpSocket::*)(QAbstractSocket::SocketError)>(&QTcpSocket::error), this, &TcpConnection::error);
}

QTcpSocket *TcpConnection::getSocket()
{
    if(!sender()) return 0;
    return static_cast<QTcpSocket*>(sender());
}

void TcpConnection::connected()
{
    if(!sender()) return;
    qDebug() << this << " connected to " << sender();
}

void TcpConnection::disconnected()
{
    if(!sender()) return;
    qDebug() << this << " disconneceted from " << getSocket();
}

void TcpConnection::readyRead()
{
    if(!sender()) return;
    qDebug() << this << " readyRead " << getSocket();
}

void TcpConnection::bytesWritten(qint64 bytes)
{
    if(!sender()) return;
    qDebug() << this << " bytes written by socket " << getSocket() << "number of bytes = " << bytes;
}

void TcpConnection::stateChanged(QAbstractSocket::SocketState socketState)
{
    if(!sender()) return;
    qDebug() << this << " state changed " << getSocket() << " state = " << socketState;
}

void TcpConnection::error(QAbstractSocket::SocketError socketError)
{
    if(!sender()) return;
    qDebug() << this << " error " << getSocket() << " error = " << socketError;
}
