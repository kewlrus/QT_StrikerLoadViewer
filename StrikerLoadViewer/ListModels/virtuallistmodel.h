#ifndef VIRTUALLISTMODEL_H
#define VIRTUALLISTMODEL_H

#include <QAbstractTableModel>
#include <QStringList>

class VirtualListModel : public QAbstractTableModel
{
    Q_OBJECT
    public:
        VirtualListModel(QObject *parent = 0);
        virtual   void      AddData(QString Text)   = 0;
        virtual   QString   GetData(int index)      = 0;
        virtual   void      DeleteItem(int index)   = 0;
        virtual   void      Refresh()               = 0;

    signals:

    public slots:
    
};

#endif // VIRTUALLISTMODEL_H
