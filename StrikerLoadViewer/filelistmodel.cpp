#include "filelistmodel.h"

ListModel::ListModel(QObject *parent, QStringList* LuaFiles): QAbstractTableModel(parent)
{
    List = LuaFiles;
  //  connect(this,SIGNAL())
}

int ListModel::rowCount(const QModelIndex & /*parent*/) const
{
    return (*List).size();
}

int ListModel::columnCount(const QModelIndex & /*parent*/) const
{
    return 1;
}

QString ListModel::GetData(int index)
{
    return (*List).at(index);
}

QVariant ListModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        return (*List).at(index.row());
    }
    return QVariant();
}

 /*void ListModel::currentChanged(const QModelIndex & current, const QModelIndex & previous)
 {
     //printf("asd");
     QMessageBox::information(0, "error", "asdasd");

 };*/
