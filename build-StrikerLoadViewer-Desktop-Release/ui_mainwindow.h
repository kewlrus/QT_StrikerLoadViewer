/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed 24. Apr 10:27:05 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QListView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QListView *LoadFuncView;
    QListView *FileListView;
    QListView *AppearencesListView;
    QListView *AppearencePropFuncListView;
    QPushButton *ChooseFolderBtn;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(750, 648);
        MainWindow->setMinimumSize(QSize(750, 648));
        MainWindow->setMaximumSize(QSize(750, 648));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        LoadFuncView = new QListView(centralWidget);
        LoadFuncView->setObjectName(QString::fromUtf8("LoadFuncView"));
        LoadFuncView->setGeometry(QRect(10, 100, 361, 181));
        FileListView = new QListView(centralWidget);
        FileListView->setObjectName(QString::fromUtf8("FileListView"));
        FileListView->setGeometry(QRect(10, 0, 731, 91));
        AppearencesListView = new QListView(centralWidget);
        AppearencesListView->setObjectName(QString::fromUtf8("AppearencesListView"));
        AppearencesListView->setGeometry(QRect(390, 100, 351, 181));
        AppearencePropFuncListView = new QListView(centralWidget);
        AppearencePropFuncListView->setObjectName(QString::fromUtf8("AppearencePropFuncListView"));
        AppearencePropFuncListView->setGeometry(QRect(10, 290, 731, 271));
        AppearencePropFuncListView->setAlternatingRowColors(false);
        AppearencePropFuncListView->setSelectionMode(QAbstractItemView::MultiSelection);
        AppearencePropFuncListView->setMovement(QListView::Static);
        ChooseFolderBtn = new QPushButton(centralWidget);
        ChooseFolderBtn->setObjectName(QString::fromUtf8("ChooseFolderBtn"));
        ChooseFolderBtn->setGeometry(QRect(10, 570, 81, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 750, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        ChooseFolderBtn->setText(QApplication::translate("MainWindow", "Choose Folder", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
