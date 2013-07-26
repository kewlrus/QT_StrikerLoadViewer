#ifndef LOADFUNCTION_H
#define LOADFUNCTION_H
#include "appearence.h"

class LoadFunction
{
private:
    QList<Appearence* > AppearencesList;
    QString FunctionName;
    QStringList* Props;

public:
    LoadFunction(QString FunctionName);
    ~LoadFunction();

    void AddAppearence(QString AppearenceName, QString AppearenceConstructor);
    void AddAppearenceProp(QString AppearenceName, QString Prop);
    void AddAppearenceFunc(QString AppearenceName, QString Func);

    void AddFuncProp(QString Prop);

    QString GetName(void);
    void    SetName(QString Name);


    int GetAppIndexByName(QString AppearenceName);


    QList<Appearence* >* GetApps(void);
};

#endif // LOADFUNCTION_H
