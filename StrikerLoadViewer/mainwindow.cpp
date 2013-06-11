#include "mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
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
        QString DirectoryPath = in.readLine();

        QDir Directory(DirectoryPath);

        if (Directory.exists() && DirectoryPath.size() > 0)
        {
            LP = new LuaParser(Directory, this->LoadFuncView, this->FileListView, this->AppearencesListView, this->AppearencePropFuncListView);
        }
        else
        {
            QMessageBox::information(0, "error", "No such directory: " + DirectoryPath + "!");
           // close();
        }
    }
    File.close();
}

void MainWindow::on_FileListView_clicked(const QModelIndex &index)
{
    LP->SelectFile(index.row());
}

void MainWindow::on_LoadFuncView_clicked(const QModelIndex &index)
{
    LP->SelectFunction(index.row());
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
