#include "funcslistmodel.h"

FuncsListModel::FuncsListModel(QObject *parent, QList<LoadFunction*>* FunctionsList) : VirtualListModel(parent)
{
    this->FunctionsList = FunctionsList;
}

int FuncsListModel::rowCount(const QModelIndex & /*parent*/) const
{
    return FunctionsList->count();
}

int FuncsListModel::columnCount(const QModelIndex & /*parent*/) const
{
    return 1;
}

QString FuncsListModel::GetData(int index)
{
    if (index <= rowCount() - 1)
        return FunctionsList->at(index)->GetName();
    else
        return "";
}

QVariant FuncsListModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole && index.row() <= rowCount() - 1)
    {
        return FunctionsList->at(index.row())->GetName();
    }
    return QVariant();
}

void FuncsListModel::DeleteItem(int index)
{
    this->beginRemoveRows(QModelIndex(), index, index);
    FunctionsList->removeAt(index);
    this->endRemoveRows();
}

void FuncsListModel::AddData(QString Text)
{
    beginInsertRows(QModelIndex(), FunctionsList->count(), FunctionsList->count());
    FunctionsList->append(new LoadFunction(Text));
    endInsertRows();
}

bool FuncsListModel::setData(int index, QString name)
{
    FunctionsList->at(index)->SetName(name);
}

QList<LoadFunction* >* FuncsListModel::GetFunctionsList()
{
    return FunctionsList;
}

QModelIndex FuncsListModel::GetModelIndex(int row)
{
    QModelIndex MIndex = createIndex(row, 0, 0);

    return MIndex;
}

void FuncsListModel::Refresh()
{

}
