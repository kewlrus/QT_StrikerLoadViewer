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

private:
    void ScanDirectory(void);

    bool OpenFile(QFile File);
    void CloseFile(QFile File);

    int GetFuncIndexByName(QString FuncName);

public:
    void ParseFile(QString FilePath);

    void SelectFile(int Index);
    void SelectFunction(int Index);
    void SelectAppearence(int Index);

    LuaParser(QDir Directory, QListView* LoadFuncView, QListView* FileListView, QListView* AppearencesListView, QListView* AppearencePropFuncListView);
};

#endif // LUAPARSER_H
