#include "MainWindow.h"
#include "qpushbutton.h"
#include "qmessagebox.h"
#include "qboxlayout.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    // Create button with central widget
    QWidget* widget = new QWidget;
    QVBoxLayout* vlay = new QVBoxLayout(widget);
    QPushButton* btn = new QPushButton;

    btn->setText("Button");
    vlay->addWidget(btn);
    widget->setLayout(vlay);
    setCentralWidget(widget);
}

MainWindow::~MainWindow()
{}
