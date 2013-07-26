#ifndef ADDEDITFUNCTION_H
#define ADDEDITFUNCTION_H

#include "ui_addeditfunction.h"

class addeditfunction : public QDialog, private Ui::addeditfunction
{
    Q_OBJECT
    
public:
    explicit addeditfunction(QWidget *parent = 0);
    QString GetFunctionName();
    void SetFunctionName(QString FuncName);

public slots:
    void accept();
    void reject();
};

#endif // ADDEDITFUNCTION_H
