#include "MainWindow.h"
#include "qpushbutton.h"
#include "qmessagebox.h"
#include "qboxlayout.h"
#include "qpainter.h"
#include "qevent.h"
#include "qdialog.h"
#include "qlistwidget.h"


class CustomDialog : public QDialog
{
public:
	CustomDialog(QWidget* parent) : QDialog(parent) {
		/*
		lineEdit = new QLineEdit(this);

		QPushButton* btn_left = new QPushButton("OK", this);
		QPushButton* btn_right = new QPushButton("Cancel", this);
		connect(btn_left, SIGNAL(clicked()), this, SLOT(accept()));
		connect(btn_right, SIGNAL(clicked()), this, SLOT(reject()));

		QVBoxLayout* vbox = new QVBoxLayout(this);
		vbox->addWidget(lineEdit);
		vbox->addWidget(btn_left);
		vbox->addWidget(btn_right);
		*/

		listWidget = new QListWidget(this);
		QString string = "1, 2, 3, 4";
		QStringList items = string.split(",");
		QStringListIterator iter(items);

		while (iter.hasNext()) {
			listWidget->addItem("Item " + iter.next().trimmed());
		}
	}

private:
	QLineEdit* lineEdit;
	QListWidget* listWidget;
	QStringList* stringList;
};


class CentralWidget : public QWidget
{
public:
	CentralWidget(QWidget* parent) : QWidget(parent) {
		// this를 안써주면 직접 해제해야 하므로 써주기
		btn_left = new QPushButton(this);
		btn_right = new QPushButton(this);
	}

	// Event Override
	void resizeEvent(QResizeEvent* event) override {
		// 생성한 버튼을 윈도우 수평 좌우 + 수직 가운데로 배치하기
		btn_left->move(0, (height() - btn_left->height()) / 2);
		btn_right->move(width() - btn_right->width(), (height() - btn_right->height()) / 2);
	}

	void paintEvent(QPaintEvent* event) override {
		QPainter painter(this);
		painter.setBrush(QBrush(Qt::BDiagPattern));
		painter.drawRect(rect());
	}

	void mousePressEvent(QMouseEvent* event) {
		if (event->button() == Qt::LeftButton) {
			qDebug() << "\nLeft button clicked.\n";
			QMessageBox msgBox;
			msgBox.setText("Left button clicked");
			msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Close);
			msgBox.setDefaultButton(QMessageBox::Ok);
			int ret = msgBox.exec();
		}
		else if (event->button() == Qt::RightButton) {
			qDebug() << "\nRight button clicked.\n";

			CustomDialog* dialog = new CustomDialog(this);
			// Modeless: 제어권을 독점하지 않아서 다른 작업이 가능함
			//dialog->show();
			//dialog->raise();
			//dialog->activateWindow();

			// Modal: 제어권을 가져가서 해당 창이 종료되기 전에 다른 작업 불가능
			dialog->resize(100, 100);
			dialog->exec();
		}
		else if (event->button() == Qt::MiddleButton) {
			qDebug() << "\nMiddle button clicked.\n";
			QMessageBox::information(this, "Title", "Middle button clicked.");
		}
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