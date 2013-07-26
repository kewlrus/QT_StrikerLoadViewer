#include "luaparser.h"
LuaParser::LuaParser(QDir Directory, QListView *LoadFuncView, QListView *FileListView, QListView* AppearencesListView, QListView* AppearencePropFuncListView)
{
    this->LoadFuncView = LoadFuncView;
    this->FileListView = FileListView;
    this->AppearencesListView = AppearencesListView;
    this->AppearencePropFuncListView = AppearencePropFuncListView;
    this->Directory = Directory;

    FuncListMdl = NULL;
    AppsListMdl = NULL;
    AppsFuncPropListMdl = NULL;
    FileListMdl = NULL;

    FuncProxyModel = NULL;
    AppProxyModel = NULL;

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

        if (FuncListMdl)
        {
            delete FuncListMdl;
            FuncListMdl = NULL;
        }

        if (AppsListMdl)
        {
            delete AppsListMdl;
            AppsListMdl = NULL;
        }

        if (AppsFuncPropListMdl)
        {
            delete AppsFuncPropListMdl;
            AppsFuncPropListMdl = NULL;
        }


        FuncListMdl = new FuncsListModel(0, &FunctionsList);

        FuncProxyModel = new QSortFilterProxyModel(this);
        FuncProxyModel->setSourceModel(FuncListMdl);
        LoadFuncView->setModel(FuncProxyModel);

        if (FunctionsList.count() > 0)
        {
            QItemSelection selection(FuncListMdl->index(0,0), FuncListMdl->index(0,0));

            LoadFuncView->selectionModel()->select(selection, QItemSelectionModel::Select);
            LoadFuncView->selectionModel()->setCurrentIndex(FuncListMdl->GetModelIndex(), QItemSelectionModel::Select);
            //
            AppsListMdl = new AppsListModel(0, FunctionsList.at(0)->GetApps());

            AppProxyModel = new QSortFilterProxyModel(this);
            AppProxyModel->setSourceModel(AppsListMdl);
            AppearencesListView->setModel(AppProxyModel);

            QItemSelection selectionApp(AppsListMdl->index(0,0), AppsListMdl->index(0,0));

            AppearencesListView->selectionModel()->select(selectionApp, QItemSelectionModel::Select);
            AppearencesListView->selectionModel()->setCurrentIndex(AppsListMdl->GetModelIndex(), QItemSelectionModel::Select);
            //
            AppsFuncPropListMdl = new AppsFuncPropListModel(0, FunctionsList.at(0)->GetApps()->at(0)->GetProps(), FunctionsList.at(0)->GetApps()->at(0)->GetFuncs());
            AppearencePropFuncListView->setModel(AppsFuncPropListMdl);
        }

        emit ListModelsChanged();

        File.close();
    }

}

void LuaParser::ScanDirectory(void)
{
    QDirIterator iterator(Directory.path(), QDirIterator::Subdirectories);
    LuaFiles->clear();
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

    if (FileListMdl)
        delete FileListMdl;

    FileListMdl = new ListModel(0, LuaFiles);
    FileListView->setModel(FileListMdl);
}

int LuaParser::GetFunctionIndexByName(QString FunctionName)
{
    for (int i = 0; i < FunctionsList.count(); i++)
    {
        if (FunctionsList.at(i)->GetName() == FunctionName)
            return i;
    }

    return -1;
}

void LuaParser::SelectFile(int Index)
{
    if (Index >= 0 && Index < (*LuaFiles).size())
        ParseFile((*LuaFiles).at(Index));
}

void LuaParser::SelectFunction(int Index)
{
    if (Index >= 0 && Index < FunctionsList.size() && FuncProxyModel->rowCount() > 0)
    {
        if (AppsListMdl)
        {
            delete AppsListMdl;
            AppsListMdl = NULL;
        }

        QModelIndex ProxyIndex = FuncProxyModel->index(Index, 0, QModelIndex());
        int IndexSource = FuncProxyModel->mapToSource(ProxyIndex).row();

        if (FunctionsList.at(Index)->GetApps()->size() > 0)
        {
            //Selecting Index Function Programmatically
            QItemSelection FuncSelection(FuncProxyModel->index(Index, 0), FuncProxyModel->index(Index, 0));
            QModelIndex FuncProxyModelIndex = FuncProxyModel->index(Index, 0 , QModelIndex());
            LoadFuncView->selectionModel()->select(FuncSelection, QItemSelectionModel::Select);
            LoadFuncView->selectionModel()->setCurrentIndex(FuncProxyModelIndex, QItemSelectionModel::Select);

            //Setting Appearences Proxy Model
            AppsListMdl = new AppsListModel(0, FunctionsList.at(IndexSource)->GetApps());

            if (AppProxyModel != NULL)
            {
                delete AppProxyModel;
                AppProxyModel = NULL;
            }

            AppProxyModel = new QSortFilterProxyModel(this);
            AppProxyModel->setSourceModel(AppsListMdl);
            AppearencesListView->setModel(AppProxyModel);

            //Selecting Appearences programmatically
          //  QItemSelection selection(AppsListMdl->index(0,0), AppsListMdl->index(0,0));
        //    AppearencesListView->selectionModel()->select(selection, QItemSelectionModel::Select);
        //    AppearencesListView->selectionModel()->setCurrentIndex(AppsListMdl->GetModelIndex(), QItemSelectionModel::Select);

            SelectAppearence(0);
        }
    }
}

void LuaParser::SelectAppearence(int Index)
{
    int SelFunction = LoadFuncView->selectionModel()->selectedIndexes().at(0).row();

    QModelIndex ProxyIndex = FuncProxyModel->index(SelFunction, 0, QModelIndex());
    SelFunction = FuncProxyModel->mapToSource(ProxyIndex).row();
    int SourceAppIndex = 0;

    if (AppProxyModel != NULL)
    {
        QModelIndex AppProxyIndex = AppProxyModel->index(Index, 0, QModelIndex());
        SourceAppIndex = AppProxyModel->mapToSource(AppProxyIndex).row();
    }

  //  QMessageBox::information(0, "error", File.errorString());
    if (SourceAppIndex >= 0 && SelFunction >= 0 && SourceAppIndex < FunctionsList.at(SelFunction)->GetApps()->size() && SelFunction >= 0 && SelFunction < FunctionsList.size())
    {
        //Setting Appereances Properties Model (without proxy)
        if (AppsFuncPropListMdl)
        {
            delete AppsFuncPropListMdl;
            AppsFuncPropListMdl = NULL;
        }

        AppsFuncPropListMdl = new AppsFuncPropListModel(0, FunctionsList.at(SelFunction)->GetApps()->at(SourceAppIndex)->GetProps(), FunctionsList.at(SelFunction)->GetApps()->at(SourceAppIndex)->GetFuncs());
        AppearencePropFuncListView->setModel(AppsFuncPropListMdl);

        //Selecting Appereance programmatically
        QItemSelection deselection(AppProxyModel->index(0, 0), AppProxyModel->index(AppProxyModel->rowCount(), 0));
        QItemSelection selection(AppProxyModel->index(Index, 0), AppProxyModel->index(Index, 0));
        QModelIndex AppProxyModelIndex = AppProxyModel->index(Index, 0 , QModelIndex());

        AppearencesListView->selectionModel()->select(deselection, QItemSelectionModel::Deselect);
        AppearencesListView->selectionModel()->select(selection, QItemSelectionModel::Select);
        AppearencesListView->selectionModel()->setCurrentIndex(AppProxyModelIndex, QItemSelectionModel::Select);

    }
}

void LuaParser::setAppsListModel(AppsListModel* ALM){ AppsListMdl = ALM; }
void LuaParser::setAppsFuncPropListModel(AppsFuncPropListModel* AFPLM) { AppsFuncPropListMdl = AFPLM; }

FuncsListModel* LuaParser::getFuncListModel(){ return FuncListMdl; }
AppsListModel* LuaParser::getAppsListModel(){ return AppsListMdl; }
AppsFuncPropListModel* LuaParser::getAppsFuncPropListModel(){ return AppsFuncPropListMdl; }
ListModel* LuaParser::getFileListModel(){ return FileListMdl; }

QSortFilterProxyModel*  LuaParser::getFuncProxyModel() { return FuncProxyModel; }
QSortFilterProxyModel*  LuaParser::getAppProxyModel() { return AppProxyModel; }

void LuaParser::setFuncFilter(QString Filter)
{
    if (FuncProxyModel != NULL)
    {
        FuncProxyModel->setFilterRegExp(QRegExp(Filter, Qt::CaseInsensitive, QRegExp::FixedString));
        if (FuncProxyModel->rowCount() <= 0)
        {
            if (AppProxyModel != NULL)
            {
                delete AppProxyModel;
                AppProxyModel = NULL;
            }
            AppearencesListView->setModel(NULL);

            if (AppsFuncPropListMdl != NULL)
            {
                delete AppsFuncPropListMdl;
                AppsFuncPropListMdl = NULL;
            }
            AppearencePropFuncListView->setModel(NULL);
        }
    }

    SelectFunction(0);
}

void LuaParser::setAppFilter(QString Filter)
{
    if (AppProxyModel != NULL)
    {
        AppProxyModel->setFilterRegExp(QRegExp(Filter, Qt::CaseInsensitive, QRegExp::FixedString));
        if (AppProxyModel->rowCount() <= 0)
        {
            if (AppsFuncPropListMdl != NULL)
            {
                delete AppsFuncPropListMdl;
                AppsFuncPropListMdl = NULL;
            }
            AppearencePropFuncListView->setModel(NULL);
        }
    }

    SelectAppearence(0);
}
