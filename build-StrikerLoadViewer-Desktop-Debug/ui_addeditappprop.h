/********************************************************************************
** Form generated from reading UI file 'addeditappprop.ui'
**
** Created: Tue 14. May 13:16:30 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDEDITAPPPROP_H
#define UI_ADDEDITAPPPROP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_AddEditAppProp
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QTextEdit *PropTextEdit;

    void setupUi(QDialog *AddEditAppProp)
    {
        if (AddEditAppProp->objectName().isEmpty())
            AddEditAppProp->setObjectName(QString::fromUtf8("AddEditAppProp"));
        AddEditAppProp->resize(400, 300);
        buttonBox = new QDialogButtonBox(AddEditAppProp);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(50, 110, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(AddEditAppProp);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 101, 16));
        PropTextEdit = new QTextEdit(AddEditAppProp);
        PropTextEdit->setObjectName(QString::fromUtf8("PropTextEdit"));
        PropTextEdit->setGeometry(QRect(10, 30, 381, 71));

        retranslateUi(AddEditAppProp);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddEditAppProp, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddEditAppProp, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddEditAppProp);
    } // setupUi

    void retranslateUi(QDialog *AddEditAppProp)
    {
        AddEditAppProp->setWindowTitle(QApplication::translate("AddEditAppProp", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AddEditAppProp", "Prop name:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AddEditAppProp: public Ui_AddEditAppProp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDEDITAPPPROP_H
