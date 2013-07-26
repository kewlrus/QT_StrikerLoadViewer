#include "addeditappearence.h"

AddEditAppearence::AddEditAppearence(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
}

void AddEditAppearence::accept()
{

    this->done(1);
}

void AddEditAppearence::reject()
{

    this->done(0);
}

QString AddEditAppearence::GetAppName()
{
    return AppNameEdit->text();
}

QString AddEditAppearence::GetAppConstructor()
{
    return AppConstructorEdit->text();
}

void AddEditAppearence::SetAppName(QString Name)
{
    AppNameEdit->setText(Name);
}

void AddEditAppearence::SetAppConstructorName(QString Name)
{
    AppConstructorEdit->setText(Name);
}
