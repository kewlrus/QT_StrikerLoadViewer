#ifndef NEWFILEDIALOG_H
#define NEWFILEDIALOG_H

#include "ui_newfiledialog.h"
#include <QString>
#include <QAbstractButton>
#include <QMessageBox>
#include <QFile>


class NewFileDialog : public QDialog, private Ui::NewFileDialog
{
    Q_OBJECT
private:
    QString Path;

public:
    explicit NewFileDialog(QWidget *parent = 0);

    void SetPath(QString Path);

    QString GetFileName();

public slots:
    void accept();
    void reject();

signals:
    void FileCreated();
};

#endif // NEWFILEDIALOG_H
