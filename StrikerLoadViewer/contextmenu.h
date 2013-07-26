#ifndef CONTEXTMENU_H
#define CONTEXTMENU_H

#include <QMenu>
#include <QListView>
#include <QMessageBox>
#include <QMouseEvent>
#include <QFile>
#include <listmodels\\virtuallistmodel.h>
#include <QSortFilterProxyModel>

class ContextMenu : public QMenu
{
    Q_OBJECT
private:
    QListView*          ListView;
    VirtualListModel*   VListModel;
    QString             SelectedString;
    int                 SelectedIndex;

    bool                UsedProxy;

private:
    void mousePressEvent(QMouseEvent *);

signals:
    void NewFileActionClicked();
    void DeleteFileActionClicked(QString Path);

    void AddFunctionActionClicked();
    void DeleteFunctionActionClicked(int FunctionIndex);
    void EditFunctionActionClicked(QString Function, int FunctionIndex, VirtualListModel* VListModel);

    void AddAppearenceActionClicked();
    void DeleteAppearenceActionClicked(int AppearenceIndex);
    void EditAppearenceActionClicked(QString App, int AppearenceIndex, VirtualListModel* VListModel);

    void AddAppPropActionClicked();
    void DeleteAppPropActionClicked(int PropIndex);
    void EditAppPropActionClicked(QString Prop, int PropIndex, VirtualListModel* VListModel);

public:
    ContextMenu(QListView *ListView, VirtualListModel* VListModel, bool UsedProxy = false);

    void SetVirtualListModel(VirtualListModel* VListModel);

public slots:
    void ShowContextMenu(const QPoint& pos);
};

#endif // CONTEXTMENU_H
