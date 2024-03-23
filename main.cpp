#include "MainWindow.h"
#include "Model.h"
#include "Delegate.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("MainWindow");
    w.show();

    QListView view;
    Model model;
    Delegate delegate;
    view.setModel(&model);
    view.setItemDelegate(&delegate);
    view.show();

    return a.exec();
}
