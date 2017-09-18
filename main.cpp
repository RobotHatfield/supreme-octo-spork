#include "servergui.h"

#include "serverservice.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    //QApplication a(argc, argv);
    ServerService service(argc,argv);
    ServerGui w(&service);
    w.show();

    return service.exec();
}
