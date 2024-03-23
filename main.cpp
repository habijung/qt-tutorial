#include "MainWindow.h"
#include "Model.h"
#include "Delegate.h"
#include <QtWidgets/QApplication>
#include <QObject>

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
	w.setWindowTitle("MainWindow");
	w.show();

	QListView view;
	Model model;
	Delegate delegate;

	QObject::connect(&delegate, &Delegate::ButtonClicked, [](QModelIndex index) {
		qDebug() << index.row();
		});

	view.setModel(&model);
	view.setItemDelegate(&delegate);
	view.show();

	return a.exec();
}
