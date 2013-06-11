#ifndef APPEARENCE_H
#define APPEARENCE_H
#include <QList>
#include <QString>
#include <QStringList>
#include <QMessageBox>

class Appearence
{
private:
    QStringList* Props;
    QStringList* Funcs;

    QString AppearenceName;
    QString AppearenceConstructor;

public:
    Appearence(QString AppearenceName, QString AppearenceConstructor);

    void AddProp(QString Prop);
    void AddFunc(QString Func);

    QStringList* GetProps(void);
    QStringList* GetFuncs(void);

    QString GetName(void);
};

#endif // APPEARENCE_H
