#ifndef SERVERSERVICE_H
#define SERVERSERVICE_H

#include "servercore.h"

class ServerService : public ServerCore
{
public:
    ServerService(int argc,char ** argv);
    ~ServerService();

public slots:
    void logAMsg(QString msg);
};

#endif // SERVERSERVICE_H
