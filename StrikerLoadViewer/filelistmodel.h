#ifndef FILELISTMODEL_H
#define FILELISTMODEL_H

#include <QAbstractTableModel>
#include <QStringList>
#include <QMessageBox>
#include "ListModels\\virtuallistmodel.h"

class ListModel : public VirtualListModel
{
    Q_OBJECT
    private:
        QStringList* List;

    public:
        ListModel(QObject *parent, QStringList* LuaFiles);
        int         rowCount(const QModelIndex &parent = QModelIndex()) const ;
        int         columnCount(const QModelIndex &parent = QModelIndex()) const;
        QString     GetData(int index);
        QVariant    data(const QModelIndex &index, int role = Qt::DisplayRole) const;

        void        currentChanged(const QModelIndex & current, const QModelIndex & previous);

        void        Refresh();

        void        DeleteItem(int index);

        void        AddData(QString Text);
};

#endif // FILELISTMODEL_H
