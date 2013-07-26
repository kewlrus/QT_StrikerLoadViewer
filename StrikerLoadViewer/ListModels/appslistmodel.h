#ifndef APPSLISTMODEL_H
#define APPSLISTMODEL_H

#include <QAbstractTableModel>
#include <QStringList>
#include <QMessageBox>
#include "appearence.h"
#include "virtuallistmodel.h"

class AppsListModel : public VirtualListModel
{
    Q_OBJECT
    private:
        QList<Appearence* >* AppsList;
        QStringList* List;

    public:
        AppsListModel(QObject *parent, QList<Appearence*>* AppsList) : VirtualListModel(parent)
        {
            this->AppsList = AppsList;
        }

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

        QModelIndex GetModelIndex(int row = 0);
};

#endif // APPSLISTMODEL_H
