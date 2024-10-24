#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle("Romulus");

    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QGridLayout *layout = new QGridLayout();
    centralWidget->setLayout(layout);


    // layout
    QSplitter *splitter = new QSplitter();
    // place holder for the waterfall plot
    QLabel *waterfall = new QLabel("Waterfall");
    waterfall->setAlignment(Qt::AlignCenter);
    waterfall->setText("waterfall stuff here");
    // place holder for the spectrum plot
    QLabel *spectrum = new QLabel("Spectrum");
    spectrum->setText("spectrum stuff here");
    spectrum->setAlignment(Qt::AlignCenter);

    splitter->addWidget(waterfall);
    splitter->addWidget(spectrum);

    layout->addWidget(splitter, 0, 0, -1, -1);
}
