#include "loadfunction.h"

LoadFunction::LoadFunction(QString FunctionName)
{
    this->FunctionName = FunctionName;
    Props = new QStringList();
}

LoadFunction::~LoadFunction()
{
    delete Props;
}


void LoadFunction::AddAppearence(QString AppearenceName, QString AppearenceConstructor)
{
    if (GetAppIndexByName(AppearenceName) == -1)
    {
        Appearence* AP = new Appearence(AppearenceName, AppearenceConstructor);
        AppearencesList.append(AP);
    }
}
void LoadFunction::AddFuncProp(QString Prop)
{
    (*Props) << Prop;
}

void LoadFunction::AddAppearenceProp(QString AppearenceName, QString Prop)
{
//    qDebug("AddAppProp %s prop = %s",AppearenceName.toAscii().data(), Prop.toAscii().data());
    int index = GetAppIndexByName(AppearenceName);
    if (index >= 0)
    {
      //  qDebug("AddAppProp %s prop = %s",AppearenceName.toAscii().data(), Prop.toAscii().data());
        AppearencesList.at(index)->AddProp(Prop);
    }
}

void LoadFunction::AddAppearenceFunc(QString AppearenceName, QString Func)
{
 //   qDebug("AddAppFunc %s func = %s", AppearenceName.toAscii().data(), Func.toAscii().data());
    int index = GetAppIndexByName(AppearenceName);
    if (index >= 0)
    {
       // qDebug("AddAppFunc %s func = %s", AppearenceName.toAscii().data(), Func.toAscii().data());
        AppearencesList.at(index)->AddFunc(Func);
    }
}

int LoadFunction::GetAppIndexByName(QString AppearenceName)
{
    for (int i = 0; i < AppearencesList.size(); ++i)
    {
        if (AppearencesList.at(i)->GetName() == AppearenceName)
            return i;
    }

    return -1;
}

QString LoadFunction::GetName(void)
{
    return FunctionName;
}


QList<Appearence* > LoadFunction::GetApps(void)
{
    return AppearencesList;
}
