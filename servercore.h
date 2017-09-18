#ifndef SERVERCORE_H
#define SERVERCORE_H

#include <QApplication>

class ServerCore : public QApplication
{
    Q_OBJECT

public:
    ServerCore(int argc, char **argv);
    ~ServerCore();

    virtual void logMsg();
};

#endif // SERVERCORE_H
