#include "newfiledialog.h"

NewFileDialog::NewFileDialog(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
}

void NewFileDialog::SetPath(QString Path)
{
    this->Path = Path;
}

QString NewFileDialog::GetFileName()
{
    return this->FileNameEdit->text();
}

void NewFileDialog::accept()
{
    QString FilePath = Path + "/" + FileNameEdit->text();
    QFile File(FilePath);

    if(!File.open(QIODevice::ReadWrite))
    {
    }
    else
    {
        if (File.isOpen())
        {
            QMessageBox::information(0, "Success", FilePath + " created!");
            emit FileCreated();
            File.close();
        }
    }

    this->done(1);
}

void NewFileDialog::reject()
{

    this->done(0);
}
