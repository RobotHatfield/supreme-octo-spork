#include "servercore.h"

#include <QDebug>
#include <QDateTime>

ServerCore::ServerCore(int argc, char **argv) : QApplication(argc, argv)
{
    qDebug() << "Initialization of the Server Application Core has begun...";

    // TODO Log time for debugging so that metrics can be applied to the load process
    QDateTime *debugTimer = new QDateTime();

    //Using the method .toString() takes away the weird QT text that gets added to the time string
    qDebug() << "Application execution has begun running at: " << debugTimer->currentDateTimeUtc().toString();
}

ServerCore::~ServerCore()
{
    qDebug() << "Server Application Core is now being deleted...";
}

void ServerCore::logMsg()
{
    qDebug() << "Logging Message";
}
