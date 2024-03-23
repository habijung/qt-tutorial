#include "MainWindow.h"
#include "qpushbutton.h"
#include "qmessagebox.h"
#include "qboxlayout.h"

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	// Create button with central widget
	QWidget* widget = new QWidget;
	QVBoxLayout* vbox = new QVBoxLayout(widget);
	QHBoxLayout* hbox = new QHBoxLayout(widget);

	widget->setLayout(vbox);
	setCentralWidget(widget);

	// Create buttons
	QPushButton* btn1 = new QPushButton("Button1");
	QPushButton* btn2 = new QPushButton("Button2");
	vbox->addWidget(btn1);
	vbox->addWidget(btn2);
	vbox->addWidget(this->lineEdit);
	vbox->addStretch();

	// Set ComboBox
	for (int i = 0; i < 3; i++)
	{
		this->cbox->addItem(QIcon("./img/clover.png"), "c" + QString::number(i + 1));
	}

	QPushButton* btn3 = new QPushButton("Submit");

	vbox->addWidget(this->cbox);
	vbox->addWidget(btn3);
	vbox->addStretch();

	// QHBoxLayout test
	QPushButton* hbtn1 = new QPushButton("H Button 1");
	QPushButton* hbtn2 = new QPushButton("H Button 2");
	hbox->addWidget(hbtn1);
	hbox->addWidget(hbtn2);
	vbox->addLayout(hbox);

	// Button connect
	connect(btn1, SIGNAL(clicked()), this, SLOT(on_clicked()));
	connect(btn2, &QPushButton::clicked, [this]()
		{
			qDebug() << "Button 2 clicked.";
			this->lineEdit->setText("Button 2 clicked.");
		});

	// TODO: PushButton 대신 ComboBox 선택으로 MessageBox 실행하기
	connect(btn3, SIGNAL(clicked()), this, SLOT(on_submitButton_clicked()));
}

MainWindow::~MainWindow()
{}

void MainWindow::on_clicked()
{
	qDebug() << "Button 1 clicked.";
	this->lineEdit->setText("Button 1 clicked.");
}

void MainWindow::on_submitButton_clicked()
{
	qDebug() << "Submit: " << QString(this->cbox->currentText());
	QMessageBox::information(this, "Submit", this->cbox->currentText());
}