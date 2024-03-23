#include "MainWindow.h"
#include "Model.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("MainWindow");
    w.show();

    QListView view;
    Model model;
    view.setModel(&model);
    view.show();

    return a.exec();
}
