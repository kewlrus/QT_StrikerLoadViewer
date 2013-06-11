#include "luaparser.h"
LuaParser::LuaParser(QDir Directory, QListView *LoadFuncView, QListView *FileListView, QListView* AppearencesListView, QListView* AppearencePropFuncListView)
{
    this->LoadFuncView = LoadFuncView;
    this->FileListView = FileListView;
    this->AppearencesListView = AppearencesListView;
    this->AppearencePropFuncListView = AppearencePropFuncListView;
    this->Directory = Directory;

    LuaFiles = new QStringList();
    ScanDirectory();
}

bool LuaParser::OpenFile(QFile File)
{
    if(!File.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0, "error", File.errorString());
        return false;
    };

    return true;
}

void LuaParser::CloseFile(QFile File)
{
    File.close();
}

int LuaParser::GetFuncIndexByName(QString FuncName)
{
    for (int i = 0; i < FunctionsList.size(); ++i)
    {
        if (FunctionsList.at(i)->GetName() == FuncName)
            return i;
    }

    return -1;
}

void LuaParser::ParseFile(QString FilePath)
{
    QFile File(FilePath);

    if(!File.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0, "error", File.errorString());
    }
    else
    {
        FunctionsList.clear();

        QTextStream in(&File);

        QRegExp REFindFunction("function.+Load");
        QRegExp REFindAppearenceCreate("Actor.Appearences(\\[.+\\]\\[.+\\]).+\\=.+(Appearence:new\\(.+\\))");

        while(!in.atEnd())
        {
            QString line = in.readLine();

            if (REFindFunction.indexIn(line) >= 0)
            {
                LoadFunction* LF = new LoadFunction(line);
                FunctionsList.append(LF);
            }

            if (REFindAppearenceCreate.indexIn(line) >= 0)
            {
              //  qDebug("AddAppearence %s, %s",REFindAppearenceCreate.cap(1).toAscii().data(),REFindAppearenceCreate.cap(2).toAscii().data());
                FunctionsList.at(FunctionsList.count() - 1)->AddAppearence(REFindAppearenceCreate.cap(1), REFindAppearenceCreate.cap(2));
            }
        }
        File.close();
        File.open(QIODevice::ReadOnly);
        QTextStream in2(&File);
        QString FuncName;

        while(!in2.atEnd())
        {
            QString line = in2.readLine();
            line = line.trimmed();

            QString AppName;

            QRegExp REFindAppearenceProp("Actor.Appearences(\\[.+\\]\\[.+\\]).?([.=].+)");
            QRegExp REFindAppearenceFunc("Actor.Appearences(\\[.+\\]\\[.+\\])(\\:.+)");
            QRegExp REFindAppearenceCallbacks("Actor.AppearenceCallbacks(\\[.+\\])(.+)");
            QRegExp REFindAppearenceComments("--");
            QRegExp REFindAppearenceCommentsBegin("^--");

            if (REFindFunction.indexIn(line) >= 0)
            {
                FuncName = line;
                continue;
               // qDebug("Func %s",FuncName.toAscii().data());
            }


            if (REFindAppearenceProp.indexIn(line) >= 0 && REFindAppearenceCommentsBegin.indexIn(line) < 0)
            {
                AppName = REFindAppearenceProp.cap(1);
                int FuncIndex = GetFuncIndexByName(FuncName);
               // qDebug("FuncIndex = %d",FuncIndex);
              //  qDebug("AppName %s",AppName.toAscii().data());
                if (FuncIndex >= 0)
                    FunctionsList.at(FuncIndex)->AddAppearenceProp(AppName, REFindAppearenceProp.cap(2));
            }
            else
            {
                if (REFindAppearenceFunc.indexIn(line) >= 0 && REFindAppearenceCommentsBegin.indexIn(line) < 0)
                {
                   AppName = REFindAppearenceFunc.cap(1);
                   int FuncIndex = GetFuncIndexByName(FuncName);
                //  qDebug("FuncIndex = %d",FuncIndex);
                //  qDebug("AppName %s",AppName.toAscii().data());
                   if (FuncIndex >= 0)
                       FunctionsList.at(FuncIndex)->AddAppearenceFunc(AppName, REFindAppearenceFunc.cap(2));
                }
                else
                {
                   /* if (REFindAppearenceCallbacks.indexIn(line) >= 0)
                    {
                       AppName = REFindAppearenceCallbacks.cap(1);
                       int FuncIndex = GetFuncIndexByName(FuncName);
                       if (FuncIndex >= 0)
                           FunctionsList.at(FuncIndex)->AddAppearenceFunc(AppName, REFindAppearenceCallbacks.cap(2));
                    }

                    else
                    {*/
                    if (REFindAppearenceComments.indexIn(line) < 0 && line.trimmed().size() > 0 && line.trimmed() != "end;")
                    {
                        int FuncIndex = GetFuncIndexByName(FuncName);
                        if (FuncIndex >= 0)
                        {
                            FunctionsList.at(FuncIndex)->AddFuncProp(line);
                         //   qDebug("AddFuncProp %s",line.toAscii().data());
                        }
                    }
                 //   }
                }

            }

        }

        FuncsListModel* FuncListMdl = new FuncsListModel(0, FunctionsList);
        LoadFuncView->setModel(FuncListMdl);

        QItemSelection selection(FuncListMdl->index(0,0), FuncListMdl->index(0,0));
        LoadFuncView->selectionModel()->select(selection, QItemSelectionModel::Select);

        AppsListModel* AppsListMdl = new AppsListModel(0, FunctionsList.at(0)->GetApps());
        AppearencesListView->setModel(AppsListMdl);

        AppsFuncPropListModel* AppsFuncPropListMdl = new AppsFuncPropListModel(0, FunctionsList.at(0)->GetApps().at(0)->GetProps(), FunctionsList.at(0)->GetApps().at(0)->GetFuncs());
        AppearencePropFuncListView->setModel(AppsFuncPropListMdl);

        File.close();
    }

};

void LuaParser::ScanDirectory(void)
{
    QDirIterator iterator(Directory.path(), QDirIterator::Subdirectories);

    while (iterator.hasNext())
    {
      iterator.next();
      if (!iterator.fileInfo().isDir())
      {
         QString filename = iterator.fileName();
         if (filename.endsWith(".lua"))
         {
             (*LuaFiles) << iterator.filePath();
         }
      }
    }

    ListModel* FileListMdl = new ListModel(0, LuaFiles);
    FileListView->setModel(FileListMdl);
};


void LuaParser::SelectFile(int Index)
{
    if (Index >= 0 && Index < (*LuaFiles).size())
        ParseFile((*LuaFiles).at(Index));
}

void LuaParser::SelectFunction(int Index)
{
    if (Index >= 0 && Index < FunctionsList.size())
    {
        AppsListModel* AppsListMdl = new AppsListModel(0, FunctionsList.at(Index)->GetApps());
        AppearencesListView->setModel(AppsListMdl);
        QItemSelection selection(AppsListMdl->index(0,0), AppsListMdl->index(0,0));
        AppearencesListView->selectionModel()->select(selection, QItemSelectionModel::Select);
        SelectAppearence(0);
    }
}

void LuaParser::SelectAppearence(int Index)
{
    int SelFunction = LoadFuncView->selectionModel()->selectedIndexes().at(0).row();
    if (Index >= 0 && Index < FunctionsList.at(SelFunction)->GetApps().size() && SelFunction >= 0 && SelFunction < FunctionsList.size())
    {
        AppsFuncPropListModel* AppsFuncPropListMdl = new AppsFuncPropListModel(0, FunctionsList.at(SelFunction)->GetApps().at(Index)->GetProps(), FunctionsList.at(SelFunction)->GetApps().at(Index)->GetFuncs());
        AppearencePropFuncListView->setModel(AppsFuncPropListMdl);
    }
}

