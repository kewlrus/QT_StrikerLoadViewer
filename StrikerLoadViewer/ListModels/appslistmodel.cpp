#include "appslistmodel.h"

int AppsListModel::rowCount(const QModelIndex & /*parent*/) const
{
    return AppsList->count();
}

int AppsListModel::columnCount(const QModelIndex & /*parent*/) const
{
    return 1;
}

QString AppsListModel::GetData(int index)
{
    if (index <= rowCount() - 1)
        return AppsList->at(index)->GetName();
    else
        return "";
}

QVariant AppsListModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole && index.row() <= rowCount() - 1)
    {
      // if (AppsList->at(index.row())->GetName() == "[_G.STATE_DEAD][1]")
          return AppsList->at(index.row())->GetName();
    }
    return QVariant();
}

void AppsListModel::DeleteItem(int index)
{
    this->beginRemoveRows(QModelIndex(), index, index);
    AppsList->removeAt(index);
    this->endRemoveRows();
}

void AppsListModel::AddData(QString Text)
{
}

bool AppsListModel::setData(int index, QString name)
{
    AppsList->at(index)->SetName(name);
}

void AppsListModel::Refresh()
{
   /* QModelIndex top = createIndex(AppsList->.count() - 1, 0, 0);
    QModelIndex bottom = createIndex(AppsList->count() - 1, 3, 0);

    emit dataChanged(top, bottom); // emit layoutChanged() if headers changed*/

}

void AppsListModel::beginInsertRowsWrapper()
{
    beginInsertRows(QModelIndex(), AppsList->size(), AppsList->size());

}

void AppsListModel::endInsertRowsWrapper()
{
    endInsertRows();
}

QModelIndex AppsListModel::GetModelIndex(int row)
{
    QModelIndex MIndex = createIndex(row, 0, 0);

    return MIndex;
}
