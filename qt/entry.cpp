#include <thread>

#include <QApplication>
#include "mainwindow.h"

// second thread that runs the 
void qt_thread() {
    QApplication app();

    MainWindow window;
    window.resize(800, 480);
    window.show();

    return app.exec();    
}
