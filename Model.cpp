#include "Model.h"


int Model::rowCount(const QModelIndex& parent) const
{
	Q_UNUSED(parent);
	return items.count();
}

QVariant Model::data(const QModelIndex& index, int role) const
{
	QVariant ret;

	if (index.isValid() && role == Qt::DisplayRole)
	{
		return items[index.row()];
	}

	return ret;
}
