#include "appsfuncproplistmodel.h"

AppsFuncPropListModel::AppsFuncPropListModel(QObject *parent, QStringList* Props, QStringList* Funcs) : VirtualListModel(parent)
{
    this->Props = Props;
    this->Funcs = Funcs;
}

int AppsFuncPropListModel::rowCount(const QModelIndex & /*parent*/) const
{
   // qDebug("rowCount %d %d", Props->size() , Funcs->size());
    return (Props->count() + Funcs->count());
}

int AppsFuncPropListModel::columnCount(const QModelIndex & /*parent*/) const
{
    return 1;
}

QString AppsFuncPropListModel::GetData(int index)
{
    if (index <= rowCount() - 1)
    {
        if (index <= Props->count() - 1 && Props->count() > 0)
            return Props->at(index);
        else
        {
            if (Funcs->count() > 0)
              return Funcs->at(index - Props->count());
        }
    }

    return "";
}


QVariant AppsFuncPropListModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole && index.row() <= rowCount() - 1)
    {
        if (index.row() <= Props->count() - 1 && Props->count() > 0)
            return Props->at(index.row());
        else
        {
            if (Funcs->count() > 0)
              return Funcs->at(index.row() - Props->count());
        }
    }
    return QVariant();
}

void AppsFuncPropListModel::DeleteItem(int index)
{
    this->beginRemoveRows(QModelIndex(), index, index);
    if (index <= Props->count() - 1 && Props->count() > 0)
        Props->removeAt(index);
    else
    {
        if (Funcs->count() > 0)
          Funcs->removeAt(index - Props->count());
    }
    this->endRemoveRows();
}

void AppsFuncPropListModel::AddData(QString Text)
{

}

bool AppsFuncPropListModel::setData(int index, QString name)
{
   // AppsList->at(index)->SetName(name);
}


void AppsFuncPropListModel::Refresh()
{

}

void AppsFuncPropListModel::beginInsertRowsWrapper()
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
}

void AppsFuncPropListModel::endInsertRowsWrapper()
{
    endInsertRows();
}
