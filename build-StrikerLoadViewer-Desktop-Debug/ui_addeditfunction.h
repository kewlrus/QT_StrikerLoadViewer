/********************************************************************************
** Form generated from reading UI file 'addeditfunction.ui'
**
** Created: Tue 14. May 13:16:30 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDEDITFUNCTION_H
#define UI_ADDEDITFUNCTION_H

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

class Ui_addeditfunction
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *FunctionNameEdit;
    QLabel *label;

    void setupUi(QDialog *addeditfunction)
    {
        if (addeditfunction->objectName().isEmpty())
            addeditfunction->setObjectName(QString::fromUtf8("addeditfunction"));
        addeditfunction->resize(400, 95);
        buttonBox = new QDialogButtonBox(addeditfunction);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(50, 60, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        FunctionNameEdit = new QLineEdit(addeditfunction);
        FunctionNameEdit->setObjectName(QString::fromUtf8("FunctionNameEdit"));
        FunctionNameEdit->setGeometry(QRect(10, 30, 381, 20));
        label = new QLabel(addeditfunction);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 101, 16));

        retranslateUi(addeditfunction);
        QObject::connect(buttonBox, SIGNAL(accepted()), addeditfunction, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), addeditfunction, SLOT(reject()));

        QMetaObject::connectSlotsByName(addeditfunction);
    } // setupUi

    void retranslateUi(QDialog *addeditfunction)
    {
        addeditfunction->setWindowTitle(QApplication::translate("addeditfunction", "Dialog", 0, QApplication::UnicodeUTF8));
        FunctionNameEdit->setText(QApplication::translate("addeditfunction", "function Load:Name(Actor)", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("addeditfunction", "Function name:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class addeditfunction: public Ui_addeditfunction {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDEDITFUNCTION_H
