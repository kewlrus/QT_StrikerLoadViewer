#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include "luaparser.h"

class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT
private:
    LuaParser* LP;

public:
    explicit MainWindow(QWidget *parent = 0);
private slots:
    void on_FileListView_clicked(const QModelIndex &index);
    void on_LoadFuncView_clicked(const QModelIndex &index);
    void on_AppearencesListView_clicked(const QModelIndex &index);
    void on_ChooseFolderBtn_clicked();
};

#endif // MAINWINDOW_H
