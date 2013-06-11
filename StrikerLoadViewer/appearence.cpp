#include "appearence.h"

Appearence::Appearence(QString AppearenceName, QString AppearenceConstructor)
{
    this->AppearenceConstructor = AppearenceConstructor;
    this->AppearenceName = AppearenceName;

    this->Props = new QStringList();
    this->Funcs = new QStringList();
}


void Appearence::AddProp(QString Prop)
{
    (*Props) << Prop;
   // qDebug("PropsCount %d", Props->size());
}

void Appearence::AddFunc(QString Func)
{
    (*Funcs) << Func;
   // qDebug("FuncsCount %d", Funcs->size());
}


QString Appearence::GetName(void)
{
    return AppearenceName;
}

QStringList* Appearence::GetProps(void)
{
    return Props;
}

QStringList* Appearence::GetFuncs(void)
{
    return Funcs;
}
