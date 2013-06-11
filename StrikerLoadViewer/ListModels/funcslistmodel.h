#ifndef FUNCSLISTMODEL_H
#define FUNCSLISTMODEL_H

#include <QAbstractTableModel>
#include <QStringList>
#include <QMessageBox>
#include "loadfunction.h"

class FuncsListModel : public QAbstractTableModel
{
    Q_OBJECT
    private:
        QList<LoadFunction* > FunctionsList;
        QStringList* List;

    public:
        FuncsListModel(QObject *parent, QList<LoadFunction*> FunctionsList);
        int rowCount(const QModelIndex &parent = QModelIndex()) const ;
        int columnCount(const QModelIndex &parent = QModelIndex()) const;
        QString GetData(int index);
        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
};

#endif // FUNCSLISTMODEL_H
