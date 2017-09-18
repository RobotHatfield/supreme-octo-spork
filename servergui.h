#ifndef SERVERGUI_H
#define SERVERGUI_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
class ServerService;
class ServerControlPage;
QT_END_NAMESPACE

class ServerGui : public QMainWindow
{
    Q_OBJECT

public:
    ServerGui(ServerService *service, QWidget *parent = 0);
    ~ServerGui();

    ServerControlPage *scPage;

signals:
    void logMsg(QString *msg);

private:
    void makeConnections(ServerService *service);
};

#endif // SERVERGUI_H
