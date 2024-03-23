#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"
#include "qlineedit.h"
#include "qcombobox.h"

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

private slots:
	void on_clicked();
	void on_submitButton_clicked();
};
