#include "Delegate.h"


void Delegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
	QStyleOptionButton buttonOption;
	buttonOption.rect = option.rect;
	buttonOption.text = index.data(Qt::DisplayRole).toString();
	buttonOption.state = QStyle::State_Enabled;

	if (mPressedIndex == index)
	{
		buttonOption.state |= QStyle::State_Sunken;
	}
	else if (mHoveredIndex == index)
	{
		buttonOption.state |= QStyle::State_MouseOver;
	}

	QApplication::style()->drawControl(QStyle::CE_PushButton, &buttonOption, painter);
}

QSize Delegate::sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const
{
	Q_UNUSED(option);
	QString text = index.data(Qt::DisplayRole).toString();
	QFontMetrics metrics(QApplication::font());
	QSize baseSize = metrics.size(Qt::TextSingleLine, text);

	const int padding = 20;
	return QSize(baseSize.width(), baseSize.height() + padding);
}

bool Delegate::editorEvent(QEvent* event, QAbstractItemModel* model, const QStyleOptionViewItem& option, const QModelIndex& index)
{
	return true;
}