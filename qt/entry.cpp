#include <thread>

#include "QtWidgets/QApplication"
#include "mainwindow.h"

// second thread that runs the qt gui
void qt_thread(int &argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow window;
    window.resize(800, 480);
    window.show();

    app.exec();    
}
