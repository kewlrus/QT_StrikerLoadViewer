#ifndef APPSFUNCPROPLISTMODEL_H
#define APPSFUNCPROPLISTMODEL_H

#include <QAbstractTableModel>
#include <QStringList>

class AppsFuncPropListModel : public QAbstractTableModel
{
    Q_OBJECT
    private:
        QStringList* Props;
        QStringList* Funcs;

    public:
        AppsFuncPropListModel(QObject *parent, QStringList* Props, QStringList* Funcs);

        int rowCount(const QModelIndex &parent = QModelIndex()) const ;
        int columnCount(const QModelIndex &parent = QModelIndex()) const;
        QString GetData(int index);
        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
};

#endif // APPSFUNCPROPLISTMODEL_H
