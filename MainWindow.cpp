#include "MainWindow.h"
#include "qpushbutton.h"
#include "qmessagebox.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    // QPushButton Example
    QPushButton btn;
    btn.setText("QPushButton");
    btn.setToolTip("A tooltip");
    btn.show();

    // QMessageBox Example
    QMessageBox msg;
    msg.setText("QMessageBox");
    msg.setInformativeText("Any changes?");
    msg.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    msg.setDefaultButton(QMessageBox::Save);
    int ret = msg.exec();
}

MainWindow::~MainWindow()
{}
