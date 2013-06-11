#ifndef APPSLISTMODEL_H
#define APPSLISTMODEL_H

#include <QAbstractTableModel>
#include <QStringList>
#include <QMessageBox>
#include "appearence.h"

class AppsListModel : public QAbstractTableModel
{
    Q_OBJECT
    private:
        QList<Appearence* > AppsList;
        QStringList* List;

    public:
        AppsListModel(QObject *parent, QList<Appearence*> AppsList) : QAbstractTableModel(parent)
        {
            this->AppsList = AppsList;
        }

        int rowCount(const QModelIndex &parent = QModelIndex()) const ;
        int columnCount(const QModelIndex &parent = QModelIndex()) const;
        QString GetData(int index);
        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
};

#endif // APPSLISTMODEL_H
