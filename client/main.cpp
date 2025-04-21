#include <QCoreApplication>
#include "myclient.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    qDebug() << "1" << MyClient::getInstance();
    MyClient::getInstance()->connectToServer();
    return a.exec();
}
