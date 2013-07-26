#ifndef ADDEDITAPPEARENCE_H
#define ADDEDITAPPEARENCE_H

#include "ui_addeditappearence.h"

class AddEditAppearence : public QDialog, private Ui::AddEditAppearence
{
    Q_OBJECT
    
public:
    explicit AddEditAppearence(QWidget *parent = 0);

    QString GetAppName();
    QString GetAppConstructor();

    void    SetAppName(QString Name);
    void    SetAppConstructorName(QString Name);

public slots:
    void accept();
    void reject();
};

#endif // ADDEDITAPPEARENCE_H
