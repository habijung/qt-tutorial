#pragma once

#include "qlistview.h"
#include "qabstractitemmodel.h"


class Model : public QAbstractListModel
{
	Q_OBJECT

public:
	Model(QObject* parent = nullptr) : QAbstractListModel(parent)
	{
		qDebug() << "Create custom model.";
		items << "1" << "2" << "3";
	}

	int rowCount(const QModelIndex& parent = QModelIndex()) const override;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

private:
	QStringList items;
};
