#include "mainthread.h"

MainThread::MainThread(unsigned short Port) {
    server=new Server(Port);
    connect(this,SIGNAL(RemoveClient(QString)),server,SLOT(RemoveClient(QString)));
}

void MainThread::run() {
    while (1) {
        char tmp[20];
        QString n(fgets(tmp,17,stdin));
        n=n.left(n.length()-1);
        emit RemoveClient(n);
    }
}