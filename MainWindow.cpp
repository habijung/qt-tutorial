#include "MainWindow.h"
#include "qpushbutton.h"
#include "qmessagebox.h"
#include "qboxlayout.h"
#include "qlineedit.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    // Create button with central widget
    QWidget* widget = new QWidget;
    QVBoxLayout* vbox = new QVBoxLayout(widget);

    // Create buttons
    QPushButton* btn1 = new QPushButton("Button1");
    QPushButton* btn2 = new QPushButton("Button2");

    // Create line edit box
    QLineEdit* lineEdit = new QLineEdit(this);
    
    vbox->addWidget(btn1);
    vbox->addWidget(btn2);
    vbox->addStretch();
    vbox->addWidget(lineEdit);

    widget->setLayout(vbox);
    setCentralWidget(widget);

    // Button connect
    connect(btn1, SIGNAL(clicked()), this, SLOT(on_clicked()));
}

MainWindow::~MainWindow()
{}
