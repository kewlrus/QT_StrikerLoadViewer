#include "funcslistmodel.h"

FuncsListModel::FuncsListModel(QObject *parent, QList<LoadFunction*> FunctionsList) : QAbstractTableModel(parent)
{
    this->FunctionsList = FunctionsList;
}

int FuncsListModel::rowCount(const QModelIndex & /*parent*/) const
{
    return FunctionsList.size();
}

int FuncsListModel::columnCount(const QModelIndex & /*parent*/) const
{
    return 1;
}

QString FuncsListModel::GetData(int index)
{
    return FunctionsList.at(index)->GetName();
}

QVariant FuncsListModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        return FunctionsList.at(index.row())->GetName();
    }
    return QVariant();
}
