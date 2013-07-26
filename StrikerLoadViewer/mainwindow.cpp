#include "mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    LoadFuncMenu = NULL;
    AppearencesListMenu = NULL;
    AppearencePropFuncListMenu = NULL;
    FileListMenu = NULL;

    LP = NULL;

    setupUi(this);

    QFile File("settings.ini");

    if(!File.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0, "error", File.errorString() + " " + "settings.ini");
     //   close();
    }
    else
    {
        QTextStream in(&File);
        DirectoryPath = in.readLine();

        QDir Directory(DirectoryPath);

        if (Directory.exists() && DirectoryPath.size() > 0)
        {
            LP = new LuaParser(Directory, this->LoadFuncView, this->FileListView, this->AppearencesListView, this->AppearencePropFuncListView);
            connect(LP, SIGNAL(ListModelsChanged()), this, SLOT(BuildContextMenus()));
            BuildContextMenus();
        }
        else
        {
            QMessageBox::information(0, "error", "No such directory: " + DirectoryPath + "!");
           // close();
        }
    }
    File.close();
}

QString MainWindow::GetDirectoryPath() { return DirectoryPath; }

void MainWindow::RefreshLuaParser()
{
    LP->ScanDirectory();
}

void MainWindow::ShowNewFileDialog()
{
    NewFileDialog dialog;

    connect(&dialog, SIGNAL(FileCreated()), this, SLOT(RefreshLuaParser()));

    dialog.SetPath(GetDirectoryPath());
    dialog.show();
    dialog.exec();
}

void MainWindow::DeleteFileEvent(QString Path)
{
    QFile File(Path);
    if (File.open(QIODevice::ReadWrite))
    {
        File.remove();
        RefreshLuaParser();
    }
}

void MainWindow::DeleteFunctionEvent(int Index)
{
    FuncListMdl = LP->getFuncListModel();
    FuncListMdl->DeleteItem(Index);

    AppearencePropFuncListView->setModel(NULL);
    AppearencesListView->setModel(NULL);

    QItemSelection deselection(FuncListMdl->index(0, 0), FuncListMdl->index(FuncListMdl->rowCount() - 1, 0));
    QItemSelection selection(FuncListMdl->index(0, 0), FuncListMdl->index(0, 0));

    LoadFuncView->selectionModel()->select(deselection, QItemSelectionModel::Deselect);
    LoadFuncView->selectionModel()->select(selection, QItemSelectionModel::Select);
}

void MainWindow::DeleteAppearenceEvent(int Index)
{
    AppsListMdl = LP->getAppsListModel();
    AppsListMdl->DeleteItem(Index);

    QItemSelection deselection(AppsListMdl->index(0, 0), AppsListMdl->index(AppsListMdl->rowCount() - 1, 0));
    QItemSelection selection(AppsListMdl->index(0, 0), AppsListMdl->index(0, 0));

    AppearencesListView->selectionModel()->select(deselection, QItemSelectionModel::Deselect);
    AppearencesListView->selectionModel()->select(selection, QItemSelectionModel::Select);

    AppearencePropFuncListView->setModel(NULL);
}

void MainWindow::DeleteAppPropEvent(int Index)
{
    AppsFuncPropListMdl = LP->getAppsFuncPropListModel();
    AppsFuncPropListMdl->DeleteItem(Index);
}

void MainWindow::AddFunctionShowDialog()
{
    addeditfunction dialog;
    dialog.show();
    if (dialog.exec())
    {
        int newFunctionIndex = AddFunction(dialog.GetFunctionName());

        AppsListMdl = LP->getAppsListModel();
        if (AppsListMdl == NULL)
        {
            AppsListMdl = new AppsListModel(0, FuncListMdl->GetFunctionsList()->at(newFunctionIndex)->GetApps());

            AppearencesListView->setModel(AppsListMdl);
            AppearencesListMenu->SetVirtualListModel((VirtualListModel*)AppsListMdl);
            LP->setAppsListModel(AppsListMdl);
        }
        if (newFunctionIndex == 0)
            LP->setAppsFuncPropListModel(NULL);

        AddAppearence("_G.STATE_IDLE","", newFunctionIndex);

        LP->SelectFunction(newFunctionIndex);
    }
}

void MainWindow::AddAppearenceShowDialog()
{
    AddEditAppearence dialog;
    dialog.show();
    if (dialog.exec())
    {
        AddAppearence(dialog.GetAppName(), dialog.GetAppConstructor(), LoadFuncView->selectionModel()->currentIndex().row());
    }
}

void MainWindow::AddAppPropShowDialog()
{
    AddEditAppProp dialog;
    dialog.show();
    if (dialog.exec())
    {
        int FunctIndex = LoadFuncView->selectionModel()->currentIndex().row();
        int AppIndex = AppearencesListView->selectionModel()->currentIndex().row();
        AddAppProp(dialog.GetPropText(), FunctIndex, AppIndex);
    }
}

void MainWindow::EditFunctionEvent(QString Function, int Index, VirtualListModel* VListModel)
{
    addeditfunction dialog;
    dialog.SetFunctionName(Function);
    dialog.show();
    if (dialog.exec())
    {
        FuncProxyModel = LP->getFuncProxyModel();

        QModelIndex ProxyIndex = FuncProxyModel->index(Index, 0, QModelIndex());
        Index = FuncProxyModel->mapToSource(ProxyIndex).row();

        LP->getFuncListModel()->setData(Index, dialog.GetFunctionName());
    }
}

void MainWindow::EditAppearenceEvent(QString Appearence, int Index, VirtualListModel* VListModel)
{
    AddEditAppearence dialog;
    dialog.SetAppName(Appearence);
    dialog.show();
    if (dialog.exec())
    {
        AppProxyModel = LP->getAppProxyModel();

        QModelIndex AppProxyIndex = AppProxyModel->index(Index, 0, QModelIndex());
        Index = AppProxyModel->mapToSource(AppProxyIndex).row();

        LP->getAppsListModel()->setData(Index, dialog.GetAppName());
    }
}

void MainWindow::EditAppPropEvent(QString Prop, int Index, VirtualListModel* VListModel)
{
    AddEditAppProp dialog;
    dialog.SetPropText(Prop);
    dialog.show();
    if (dialog.exec())
    {
        //int FunctIndex = LoadFuncView->selectionModel()->currentIndex().row();
        //int AppIndex = AppearencesListView->selectionModel()->currentIndex().row();
       // AddAppProp(dialog.GetPropText(), FunctIndex, AppIndex);
    }
}

void EditFunction(QString Function, int FuncIndex)
{

}

void EditAppearence(QString AppearenceName, QString AppearenceConstructor, int FuncIndex, int AppIndex)
{

}

void EditAppProp(QString Prop, int FunctionIndex, int AppIndex)
{

}

int MainWindow::AddFunction(QString Function)
{
    FuncListMdl = LP->getFuncListModel();
    FuncListMdl->AddData(Function);

    int newFunctionIndex = FuncListMdl->rowCount() - 1;

    QItemSelection deselection(FuncListMdl->index(0, 0), FuncListMdl->index(FuncListMdl->rowCount(), 0));
    QItemSelection selection(FuncListMdl->index(newFunctionIndex, 0), FuncListMdl->index(newFunctionIndex, 0));

    LoadFuncView->selectionModel()->select(deselection, QItemSelectionModel::Deselect);
    LoadFuncView->selectionModel()->select(selection, QItemSelectionModel::Select);
    LoadFuncView->selectionModel()->setCurrentIndex(FuncListMdl->GetModelIndex(newFunctionIndex), QItemSelectionModel::Select);

    return newFunctionIndex;
}

void MainWindow::AddAppearence(QString AppearenceName, QString AppearenceConstructor, int FunctionIndex)
{
    FuncListMdl = LP->getFuncListModel();

    QList<LoadFunction* >* FunctionsList = FuncListMdl->GetFunctionsList();

    AppsListMdl = LP->getAppsListModel();

    AppsListMdl->beginInsertRowsWrapper();
    FunctionsList->at(FunctionIndex)->AddAppearence("[" + AppearenceName + "]", AppearenceConstructor);
    AppsListMdl->endInsertRowsWrapper();

    int NewAppIndex = FunctionsList->at(FunctionIndex)->GetApps()->count() - 1;

    LP->SelectAppearence(NewAppIndex);

    AppsFuncPropListMdl = LP->getAppsFuncPropListModel();
    if (AppsFuncPropListMdl == NULL)
    {
        AppsFuncPropListMdl = new AppsFuncPropListModel(0, FunctionsList->at(FunctionIndex)->GetApps()->at(NewAppIndex)->GetProps(), FunctionsList->at(FunctionIndex)->GetApps()->at(NewAppIndex)->GetFuncs());
        AppearencePropFuncListView->setModel(AppsFuncPropListMdl);
        LP->setAppsFuncPropListModel(AppsFuncPropListMdl);
    }

    //Add default prop
    QString PropName = "= cAppearence:new(" + AppearenceName + ", 1000, \"PATH_TO_SKFILE.sk\", false);";
    AddAppProp(PropName, FunctionIndex, NewAppIndex);
}

void MainWindow::AddAppProp(QString PropName, int FunctionIndex, int AppIndex)
{
    FuncListMdl = LP->getFuncListModel();
    QList<LoadFunction* >* FunctionsList = FuncListMdl->GetFunctionsList();
    AppsFuncPropListMdl = LP->getAppsFuncPropListModel();

    AppsFuncPropListMdl->beginInsertRowsWrapper();
    QString AppName = FunctionsList->at(FunctionIndex)->GetApps()->at(AppIndex)->GetName();
    FunctionsList->at(FunctionIndex)->AddAppearenceProp(AppName, PropName);
    AppsFuncPropListMdl->endInsertRowsWrapper();
}

void MainWindow::BuildContextMenus()
{
    FuncListMdl = LP->getFuncListModel();
    AppsListMdl = LP->getAppsListModel();
    AppsFuncPropListMdl = LP->getAppsFuncPropListModel();
    FileListMdl = LP->getFileListModel();

    if (LoadFuncMenu)
        delete LoadFuncMenu;

    LoadFuncMenu = new ContextMenu(LoadFuncView, (VirtualListModel*) FuncListMdl, true);
    LoadFuncMenu->addAction("New Function");
    LoadFuncMenu->addAction("Delete Function");
    LoadFuncMenu->addAction("Edit Function");
    LoadFuncView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(LoadFuncView, SIGNAL(customContextMenuRequested(const QPoint&)),
            LoadFuncMenu, SLOT(ShowContextMenu(QPoint)));

    if (AppearencesListMenu)
        delete AppearencesListMenu;

    AppearencesListMenu = new ContextMenu(AppearencesListView, (VirtualListModel*) AppsListMdl, true);
    AppearencesListMenu->addAction("New Appearence");
    AppearencesListMenu->addAction("Delete Appearence");
    AppearencesListMenu->addAction("Edit Appearence");
    AppearencesListView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(AppearencesListView, SIGNAL(customContextMenuRequested(const QPoint&)),
            AppearencesListMenu, SLOT(ShowContextMenu(QPoint)));

    if (AppearencePropFuncListMenu)
        delete AppearencePropFuncListMenu;

    AppearencePropFuncListMenu = new ContextMenu(AppearencePropFuncListView, (VirtualListModel*) AppsFuncPropListMdl);
    AppearencePropFuncListMenu->addAction("New Property");
    AppearencePropFuncListMenu->addAction("Delete Property");
    AppearencePropFuncListMenu->addAction("Edit Property");
    AppearencePropFuncListView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(AppearencePropFuncListView, SIGNAL(customContextMenuRequested(const QPoint&)),
            AppearencePropFuncListMenu, SLOT(ShowContextMenu(QPoint)));

    if (FileListMenu)
        delete FileListMenu;

    FileListMenu = new ContextMenu(FileListView, (VirtualListModel*) FileListMdl);
    FileListMenu->addAction("New File");
    FileListMenu->addAction("Delete File");
    FileListView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(FileListView, SIGNAL(customContextMenuRequested(const QPoint&)),
            FileListMenu, SLOT(ShowContextMenu(QPoint)));

    connect(FileListMenu, SIGNAL(NewFileActionClicked()),
            this, SLOT(ShowNewFileDialog()));

    connect(FileListMenu, SIGNAL(DeleteFileActionClicked(QString)),
            this, SLOT(DeleteFileEvent(QString)));

    connect(LoadFuncMenu, SIGNAL(DeleteFunctionActionClicked(int)),
            this, SLOT(DeleteFunctionEvent(int)));

    connect(AppearencesListMenu, SIGNAL(DeleteAppearenceActionClicked(int)),
            this, SLOT(DeleteAppearenceEvent(int)));

    connect(AppearencePropFuncListMenu, SIGNAL(DeleteAppPropActionClicked(int)),
            this, SLOT(DeleteAppPropEvent(int)));

    //ADD
    connect(LoadFuncMenu, SIGNAL(AddFunctionActionClicked()),
            this, SLOT(AddFunctionShowDialog()));

    connect(AppearencesListMenu, SIGNAL(AddAppearenceActionClicked()),
            this, SLOT(AddAppearenceShowDialog()));

    connect(AppearencePropFuncListMenu, SIGNAL(AddAppPropActionClicked()),
            this, SLOT(AddAppPropShowDialog()));

    //Edit
    connect(LoadFuncMenu, SIGNAL(EditFunctionActionClicked(QString,int,VirtualListModel*)),
            this, SLOT(EditFunctionEvent(QString,int,VirtualListModel*)));

    connect(AppearencesListMenu, SIGNAL(EditAppearenceActionClicked(QString,int,VirtualListModel*)),
            this, SLOT(EditAppearenceEvent(QString,int,VirtualListModel*)));

    connect(AppearencePropFuncListMenu, SIGNAL(EditAppPropActionClicked(QString,int,VirtualListModel*)),
            this, SLOT(EditAppPropEvent(QString,int,VirtualListModel*)));
}

void MainWindow::on_FileListView_clicked(const QModelIndex &index)
{
    LP->SelectFile(index.row());
    LP->setAppFilter(this->FilterComboBox->currentText());
    LP->setFuncFilter(this->FilterFuncComboBox->currentText());
}

void MainWindow::on_LoadFuncView_clicked(const QModelIndex &index)
{
    LP->SelectFunction(index.row());
    LP->setAppFilter(this->FilterComboBox->currentText());
}

void MainWindow::on_AppearencesListView_clicked(const QModelIndex &index)
{
    LP->SelectAppearence(index.row());
}

void MainWindow::on_ChooseFolderBtn_clicked()
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::Directory);
    dialog.setViewMode(QFileDialog::Detail);

    QStringList Folder;
    if (dialog.exec())
        Folder = dialog.selectedFiles();

    if (Folder.size())
    {
        if (Folder.at(0).size() > 0)
        {
            qDebug("%s folder", Folder.at(0).toAscii().data());
            QFile File("settings.ini");

            if(File.open(QIODevice::WriteOnly))
            {
                QTextStream out(&File);
                out << Folder.at(0) << endl;

                QDir Directory(Folder.at(0));

                if (Directory.exists())
                {
                    if (LP)
                        delete LP;

                    LP = new LuaParser(Directory, this->LoadFuncView, this->FileListView, this->AppearencesListView, this->AppearencePropFuncListView);
                }
            }

            File.close();
        }
    }

}

void MainWindow::on_FilterFuncComboBox_textChanged(const QString &arg1)
{
    LP->setFuncFilter(arg1);
}

void MainWindow::on_FilterComboBox_textChanged(const QString &arg1)
{
    LP->setAppFilter(arg1);
}

void MainWindow::on_ClearFuncFilterButton_clicked()
{
    if (FilterFuncComboBox->findText(FilterFuncComboBox->currentText(),Qt::MatchExactly) == -1)
        FilterFuncComboBox->addItem(FilterFuncComboBox->currentText());

    FilterFuncComboBox->setEditText("");
}

void MainWindow::on_ClearAppFilterButton_clicked()
{
    if (FilterComboBox->findText(FilterComboBox->currentText(),Qt::MatchExactly) == -1)
        FilterComboBox->addItem(FilterComboBox->currentText());

    FilterComboBox->setEditText("");
}
