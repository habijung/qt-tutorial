#pragma once

#include "qapplication.h"
#include "qabstractitemdelegate.h"

class Delegate : public QAbstractItemDelegate
{
	Q_OBJECT

public:
	Delegate(QObject* parent = nullptr) : QAbstractItemDelegate(parent)
	{

	}

	void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const override;
	QSize sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const override;
	bool editorEvent(QEvent* event, QAbstractItemModel* model, const QStyleOptionViewItem& option, const QModelIndex& index) override;

private:
	QModelIndex mPressedIndex;
	QModelIndex mHoveredIndex;
};

