/********************************************************************************
** Form generated from reading UI file 'newfiledialog.ui'
**
** Created: Tue 14. May 13:16:30 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWFILEDIALOG_H
#define UI_NEWFILEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_NewFileDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *FileNameLabel;
    QLineEdit *FileNameEdit;

    void setupUi(QDialog *NewFileDialog)
    {
        if (NewFileDialog->objectName().isEmpty())
            NewFileDialog->setObjectName(QString::fromUtf8("NewFileDialog"));
        NewFileDialog->resize(400, 93);
        buttonBox = new QDialogButtonBox(NewFileDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(50, 50, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        FileNameLabel = new QLabel(NewFileDialog);
        FileNameLabel->setObjectName(QString::fromUtf8("FileNameLabel"));
        FileNameLabel->setGeometry(QRect(10, 10, 81, 16));
        FileNameEdit = new QLineEdit(NewFileDialog);
        FileNameEdit->setObjectName(QString::fromUtf8("FileNameEdit"));
        FileNameEdit->setGeometry(QRect(10, 30, 381, 20));

        retranslateUi(NewFileDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), NewFileDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NewFileDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(NewFileDialog);
    } // setupUi

    void retranslateUi(QDialog *NewFileDialog)
    {
        NewFileDialog->setWindowTitle(QApplication::translate("NewFileDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        FileNameLabel->setText(QApplication::translate("NewFileDialog", "Enter file name", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class NewFileDialog: public Ui_NewFileDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWFILEDIALOG_H
