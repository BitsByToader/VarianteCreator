#include <QCoreApplication>
#include <QDebug>

#include "worker.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    Worker worker;

    return a.exec();
}
