#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include "luaparser.h"
#include "filelistmodel.h"
#include "ListModels\\funcslistmodel.h"
#include "ListModels\\appslistmodel.h"
#include "ListModels\\appsfuncproplistmodel.h"
#include <QRegExp>
#include "contextmenu.h"
#include <Forms\\newfiledialog.h>
#include <Forms\\addeditappearence.h>
#include <Forms\\addeditappprop.h>
#include <Forms\\addeditfunction.h>

class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT
private:
    LuaParser* LP;

    QString DirectoryPath;

    QSortFilterProxyModel*  FuncProxyModel;
    QSortFilterProxyModel*  AppProxyModel;

    FuncsListModel*         FuncListMdl;
    AppsListModel*          AppsListMdl;
    AppsFuncPropListModel*  AppsFuncPropListMdl;
    ListModel*              FileListMdl;

    ContextMenu*            FileListMenu;
    ContextMenu*            LoadFuncMenu;
    ContextMenu*            AppearencesListMenu;
    ContextMenu*            AppearencePropFuncListMenu;

public slots:
    void BuildContextMenus();
    void DeleteFileEvent(QString Path);
    void ShowNewFileDialog();

    void DeleteFunctionEvent(int Index);
    void DeleteAppearenceEvent(int Index);
    void DeleteAppPropEvent(int Index);

    void AddFunctionShowDialog();
    void AddAppearenceShowDialog();
    void AddAppPropShowDialog();

    void EditFunctionEvent(QString Function, int Index, VirtualListModel*);
    void EditAppearenceEvent(QString Appearence, int Index, VirtualListModel*);
    void EditAppPropEvent(QString Prop, int Index, VirtualListModel*);

    void RefreshLuaParser();

private:
    int  AddFunction(QString Function);
    void AddAppearence(QString AppearenceName, QString AppearenceConstructor, int FunctionIndex);
    void AddAppProp(QString Prop, int FunctionIndex, int AppIndex);

    void EditFunction(QString Function, int FuncIndex);
    void EditAppearence(QString AppearenceName, QString AppearenceConstructor, int FuncIndex, int AppIndex);
    void EditAppProp(QString Prop, int FunctionIndex, int AppIndex);

public:
    QString GetDirectoryPath();

public:
    explicit MainWindow(QWidget *parent = 0);
private slots:
    void on_FileListView_clicked(const QModelIndex &index);
    void on_LoadFuncView_clicked(const QModelIndex &index);
    void on_AppearencesListView_clicked(const QModelIndex &index);
    void on_ChooseFolderBtn_clicked();
    void on_FilterFuncComboBox_textChanged(const QString &arg1);
    void on_FilterComboBox_textChanged(const QString &arg1);
    void on_ClearFuncFilterButton_clicked();
    void on_ClearAppFilterButton_clicked();
};

#endif // MAINWINDOW_H
