#include "servergui.h"

#include "servercontrolpage.h"
#include "serverservice.h"

#include <QDebug>


ServerGui::ServerGui(ServerService *service, QWidget *parent)
    : QMainWindow(parent)
{
    qDebug() << "Server Gui is now being created...";
    scPage = new ServerControlPage(this);
    this->setCentralWidget(scPage);

    makeConnections(service);
    qDebug() << "Server Gui is now created";
}

ServerGui::~ServerGui()
{
    qDebug() << "Server Gui is now being deleted";
}

void ServerGui::makeConnections(ServerService *service)
{
    qDebug() << "Making Connections";
    //connect(this,logMsg(QString),service,SLOT(logAMsg(QString)));
    qDebug() << "Done Making Connections";
}
