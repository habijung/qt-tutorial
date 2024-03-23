#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"
#include "qlineedit.h"
#include "qcombobox.h"
#include "qtimer.h"
#include "qpushbutton.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget* parent = nullptr);
	~MainWindow();

private:
	Ui::MainWindowClass ui;
	QLineEdit* lineEdit = new QLineEdit;
	QComboBox* cbox = new QComboBox;
	QTimer* timer;
	QPushButton* btnEvent;
	QPushButton* btnControl;

private slots:
	void on_clicked();
	void on_submitButton_clicked();
	void on_timer();
	bool eventFilter(QObject* obj, QEvent* e);
};
