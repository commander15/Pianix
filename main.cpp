#include <QtWidgets/qapplication.h>

#include "mainwindow.h"
#include "device.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    MainWindow win;
    win.show();

    Device device(argc > 1 ? argv[1] : "/dev/ttyACM0");
    device.setBaudRate(9600);
    device.open(QIODevice::ReadOnly);
    QObject::connect(&device, &Device::notePlayRequested, &win, &MainWindow::playNote);
    
    return app.exec();
}
