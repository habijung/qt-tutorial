#include "MainWindow.h"
#include "qpushbutton.h"
#include "qmessagebox.h"
#include "qboxlayout.h"

class CentralWidget : public QWidget
{
public:
	CentralWidget(QWidget* parent) : QWidget(parent) {
		// this를 안써주면 직접 해제해야 하므로 써주기
		btn_left = new QPushButton(this);
		btn_right = new QPushButton(this);
	}

	QPushButton* btn_left;
	QPushButton* btn_right;
};

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	// Create button with central widget
	QWidget* widget = new CentralWidget(this);
	QVBoxLayout* main_box = new QVBoxLayout(widget);

	QVBoxLayout* vbox1 = new QVBoxLayout;
	QVBoxLayout* vbox2 = new QVBoxLayout;

	// Create upper box
	QPushButton* btn1 = new QPushButton("Button1");
	QPushButton* btn2 = new QPushButton("Button2");
	QPushButton* btn3 = new QPushButton("Button3");

	QHBoxLayout* hbox = new QHBoxLayout;
	hbox->addWidget(btn1, 0, Qt::AlignLeft);
	hbox->addStretch();
	hbox->addWidget(btn2, 0, Qt::AlignCenter);
	hbox->addStretch();
	hbox->addWidget(btn3, 0, Qt::AlignRight);
	hbox->addStretch();

	vbox1->addLayout(hbox);
	vbox1->addWidget(this->lineEdit);

	// Create lower box
	// Set ComboBox
	for (int i = 0; i < 3; i++)
	{
		this->cbox->addItem(QIcon("./img/clover.png"), "c" + QString::number(i + 1));
	}

	QPushButton* btn_submit = new QPushButton("Submit");

	vbox2->addWidget(this->cbox);
	vbox2->addWidget(btn_submit);
	vbox2->addStretch();

	main_box->addLayout(vbox1);
	main_box->addLayout(vbox2);
	widget->setLayout(main_box);
	setCentralWidget(widget);

	// Button connections
	connect(btn1, SIGNAL(clicked()), this, SLOT(on_clicked()));
	connect(btn2, &QPushButton::clicked, [this]()
		{
			qDebug() << "Button 2 clicked.";
			this->lineEdit->setText("Button 2 clicked.");
		});

	// TODO: PushButton 대신 ComboBox 선택으로 MessageBox 실행하기
	connect(btn_submit, SIGNAL(clicked()), this, SLOT(on_submitButton_clicked()));
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