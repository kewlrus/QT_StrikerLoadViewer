#ifndef FUNCSLISTMODEL_H
#define FUNCSLISTMODEL_H

#include <QAbstractTableModel>
#include <QStringList>
#include <QMessageBox>
#include "loadfunction.h"
#include "virtuallistmodel.h"

class FuncsListModel : public VirtualListModel
{
    Q_OBJECT
    private:
        QList<LoadFunction* >* FunctionsList;

    public:
        FuncsListModel(QObject *parent, QList<LoadFunction*>* FunctionsList);
        int         rowCount(const QModelIndex &parent = QModelIndex()) const ;
        int         columnCount(const QModelIndex &parent = QModelIndex()) const;
        QString     GetData(int index);
        QVariant    data(const QModelIndex &index, int role = Qt::DisplayRole) const;

        bool        setData(int index, QString name);

        void        Refresh();
        void        DeleteItem(int index);
        void        AddData(QString Text);

        QList<LoadFunction* >* GetFunctionsList();


        QModelIndex GetModelIndex(int row = 0);

        };

#endif // FUNCSLISTMODEL_H
