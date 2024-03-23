#include "MainWindow.h"
#include "qpushbutton.h"
#include "qmessagebox.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    // Create button with central widget
    QPushButton* btn = new QPushButton;
    btn->setText("Button");
    setCentralWidget(btn);
}

MainWindow::~MainWindow()
{}
