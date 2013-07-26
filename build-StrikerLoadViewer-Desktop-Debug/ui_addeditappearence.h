/********************************************************************************
** Form generated from reading UI file 'addeditappearence.ui'
**
** Created: Tue 14. May 13:16:30 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDEDITAPPEARENCE_H
#define UI_ADDEDITAPPEARENCE_H

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

class Ui_AddEditAppearence
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *AppNameEdit;
    QLineEdit *AppConstructorEdit;
    QLabel *label_2;

    void setupUi(QDialog *AddEditAppearence)
    {
        if (AddEditAppearence->objectName().isEmpty())
            AddEditAppearence->setObjectName(QString::fromUtf8("AddEditAppearence"));
        AddEditAppearence->resize(400, 157);
        buttonBox = new QDialogButtonBox(AddEditAppearence);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(50, 120, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(AddEditAppearence);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 101, 16));
        AppNameEdit = new QLineEdit(AddEditAppearence);
        AppNameEdit->setObjectName(QString::fromUtf8("AppNameEdit"));
        AppNameEdit->setGeometry(QRect(10, 30, 381, 20));
        AppConstructorEdit = new QLineEdit(AddEditAppearence);
        AppConstructorEdit->setObjectName(QString::fromUtf8("AppConstructorEdit"));
        AppConstructorEdit->setGeometry(QRect(10, 90, 381, 20));
        label_2 = new QLabel(AddEditAppearence);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 60, 381, 16));

        retranslateUi(AddEditAppearence);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddEditAppearence, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddEditAppearence, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddEditAppearence);
    } // setupUi

    void retranslateUi(QDialog *AddEditAppearence)
    {
        AddEditAppearence->setWindowTitle(QApplication::translate("AddEditAppearence", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AddEditAppearence", "Appearence name:", 0, QApplication::UnicodeUTF8));
        AppNameEdit->setText(QApplication::translate("AddEditAppearence", "_G.STATE_CUSTOM", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AddEditAppearence", "Appearence constructor (not necessary):", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AddEditAppearence: public Ui_AddEditAppearence {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDEDITAPPEARENCE_H
