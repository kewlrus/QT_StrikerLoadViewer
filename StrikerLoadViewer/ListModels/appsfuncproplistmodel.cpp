#include "appsfuncproplistmodel.h"

AppsFuncPropListModel::AppsFuncPropListModel(QObject *parent, QStringList* Props, QStringList* Funcs) : QAbstractTableModel(parent)
{
    this->Props = Props;
    this->Funcs = Funcs;
}

int AppsFuncPropListModel::rowCount(const QModelIndex & /*parent*/) const
{
   // qDebug("rowCount %d %d", Props->size() , Funcs->size());
    return (Props->size() + Funcs->size());
}

int AppsFuncPropListModel::columnCount(const QModelIndex & /*parent*/) const
{
    return 1;
}

QString AppsFuncPropListModel::GetData(int index)
{
    return Props->at(index);
}

QVariant AppsFuncPropListModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
      //  qDebug("AppsFuncPropListModel");
     //   return 123;
        if (index.row() <= Props->size() - 1 && Props->size() > 0)
            return Props->at(index.row());
        else
        {
            if (Funcs->size() > 0)
              return Funcs->at(index.row() - Props->size());
        }

       // return AppsList.at(index.row())->GetName();
    }
    return QVariant();
}
