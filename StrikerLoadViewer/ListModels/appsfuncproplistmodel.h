#ifndef APPSFUNCPROPLISTMODEL_H
#define APPSFUNCPROPLISTMODEL_H

#include <QAbstractTableModel>
#include <QStringList>
#include "virtuallistmodel.h"

class AppsFuncPropListModel : public VirtualListModel
{
    Q_OBJECT
    private:
        QStringList* Props;
        QStringList* Funcs;

    public:
        AppsFuncPropListModel(QObject *parent, QStringList* Props, QStringList* Funcs);

        int         rowCount(const QModelIndex &parent = QModelIndex()) const ;
        int         columnCount(const QModelIndex &parent = QModelIndex()) const;
        QString     GetData(int index);
        QVariant    data(const QModelIndex &index, int role = Qt::DisplayRole) const;

        void        Refresh();

        void        DeleteItem(int index);

        void        AddData(QString Text);
        bool        setData(int index, QString name);

        void        beginInsertRowsWrapper();
        void        endInsertRowsWrapper();
};

#endif // APPSFUNCPROPLISTMODEL_H
