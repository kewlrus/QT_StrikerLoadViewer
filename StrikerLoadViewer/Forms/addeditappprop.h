#ifndef ADDEDITAPPPROP_H
#define ADDEDITAPPPROP_H

#include "ui_addeditappprop.h"

class AddEditAppProp : public QDialog, private Ui::AddEditAppProp
{
    Q_OBJECT
    
public:
    explicit AddEditAppProp(QWidget *parent = 0);

    QString GetPropText();

    void    SetPropText(QString Name);

public slots:
    void accept();
    void reject();
};

#endif // ADDEDITAPPPROP_H
