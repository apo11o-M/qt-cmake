#pragma once

#include "QtWidgets/QMainWindow"
#include "QtWidgets/QWidget"
#include "QtWidgets/QLayout"
#include "QtWidgets/QVBoxLayout"
#include "QtWidgets/QGridLayout"
#include "QtWidgets/QSplitter"
#include "QtWidgets/QLabel"
#include "QtWidgets/QProgressBar"

#include "QtWidgets/QPushButton"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private:
    QWidget *centralWidget;
};
