#include "appslistmodel.h"

int AppsListModel::rowCount(const QModelIndex & /*parent*/) const
{
    return AppsList.size();
}

int AppsListModel::columnCount(const QModelIndex & /*parent*/) const
{
    return 1;
}

QString AppsListModel::GetData(int index)
{
    return AppsList.at(index)->GetName();
}

QVariant AppsListModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        return AppsList.at(index.row())->GetName();
    }
    return QVariant();
}
