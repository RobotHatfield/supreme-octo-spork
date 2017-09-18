#include "serverservice.h"

#include <QDebug>

ServerService::ServerService(int argc, char **argv) : ServerCore(argc, argv)
{
    qDebug() << "Server Services are now being created";
}

ServerService::~ServerService()
{
    qDebug() << "Server Services are now being deleted";
}

void ServerService::logAMsg(QString msg)
{
    //
}
