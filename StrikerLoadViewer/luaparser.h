#ifndef LUAPARSER_H
#define LUAPARSER_H

#include <QDir>
#include <QRegExp>
#include <QFile>
#include <QMessageBox>
#include <QDirIterator>
#include <QStringList>
#include <QTextStream>
#include <QtGui/QListView>
#include "appearence.h"
#include "loadfunction.h"
#include "filelistmodel.h"
#include "ListModels\\funcslistmodel.h"
#include "ListModels\\appslistmodel.h"
#include "ListModels\\appsfuncproplistmodel.h"
#include <listmodels\\virtuallistmodel.h>
#include <QSortFilterProxyModel>
#include <QMenu>

class LuaParser : public QObject
{
Q_OBJECT
private:
    QList<LoadFunction* > FunctionsList;

    QDir Directory;
    QStringList* LuaFiles;

    QListView* LoadFuncView;
    QListView* FileListView;
    QListView* AppearencesListView;
    QListView* AppearencePropFuncListView;

    FuncsListModel*         FuncListMdl;
    AppsListModel*          AppsListMdl;
    AppsFuncPropListModel*  AppsFuncPropListMdl;
    ListModel*              FileListMdl;

    QSortFilterProxyModel*  FuncProxyModel;
    QSortFilterProxyModel*  AppProxyModel;

signals:
    void ListModelsChanged();

public slots:

public:
    void ScanDirectory(void);
    int GetFunctionIndexByName(QString FunctionName);

private:
    bool OpenFile(QFile File);
    void CloseFile(QFile File);

    int GetFuncIndexByName(QString FuncName);

public:
    void ParseFile(QString FilePath);

    void SelectFile(int Index);
    void SelectFunction(int Index);
    void SelectAppearence(int Index);

    LuaParser(QDir Directory, QListView* LoadFuncView, QListView* FileListView, QListView* AppearencesListView, QListView* AppearencePropFuncListView);

    void                        setAppsListModel(AppsListModel* ALM);
    void                        setAppsFuncPropListModel(AppsFuncPropListModel* AFPLM);

    FuncsListModel*             getFuncListModel();
    AppsListModel*              getAppsListModel();
    AppsFuncPropListModel*      getAppsFuncPropListModel();
    ListModel*                  getFileListModel();
public:
    QSortFilterProxyModel*      getFuncProxyModel();
    QSortFilterProxyModel*      getAppProxyModel();

    void                        setFuncFilter(QString Filter);
    void                        setAppFilter(QString Filter);

};

#endif // LUAPARSER_H
