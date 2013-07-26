#include "addeditappprop.h"

AddEditAppProp::AddEditAppProp(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
}

void AddEditAppProp::accept()
{

    this->done(1);
}

void AddEditAppProp::reject()
{

    this->done(0);
}

QString AddEditAppProp::GetPropText()
{
    return PropTextEdit->toPlainText();
}

void AddEditAppProp::SetPropText(QString Name)
{
    PropTextEdit->setText(Name);
}
