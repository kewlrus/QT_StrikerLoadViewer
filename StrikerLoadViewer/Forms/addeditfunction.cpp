#include "addeditfunction.h"

addeditfunction::addeditfunction(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
}

void addeditfunction::accept()
{

    this->done(1);
}

void addeditfunction::reject()
{

    this->done(0);
}

QString addeditfunction::GetFunctionName()
{
    return this->FunctionNameEdit->text();
}

void addeditfunction::SetFunctionName(QString FuncName)
{
    FunctionNameEdit->setText(FuncName);
}
