#include "noote.h"
#include "./ui_noote.h"

Noote::Noote(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Noote)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

Noote::~Noote()
{
    delete ui;
}


void Noote::on_actionNew_triggered(){
    currFile.clear();
    ui->textEdit->setText(QString());
}



void Noote::on_actionOpen_triggered()
{
    QString _file = QFileDialog::getOpenFileName(this, "Select the file");
    QFile file(_file);
    currFile = _file;
    if(!file.open(QIODevice::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "Warning", "File can't open. \nReason: " + file.errorString());
    }
//    setWindowTitle("Noote :: " + _file);
    QTextStream input(&file);
    QString file_data = input.readAll();
    ui->textEdit->setText(file_data);
    file.close();
}


void Noote::on_actionSave_as_triggered()
{
    QString _file = QFileDialog::getSaveFileName(this, "Save file as");
    QFile file(_file);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "Warning", "File can't save. \nReason: " + file.errorString());
        return;
    }
    currFile = _file;
    QTextStream output(&file);
    QString file_data = ui->textEdit->toPlainText();
    output << file_data;
    file.close();
}


void Noote::on_actionSave_triggered()
{
    if(currFile == nullptr){
        Noote::on_actionSave_as_triggered();
        return;
    }
    QFile file(currFile);
    if(!file.open(QFile::ReadWrite | QFile::Text)){
        QMessageBox::warning(this, "Warning", "File can't save. \nReason: " + file.errorString());
        return;
    }
    QTextStream output(&file);
    QString file_data = ui->textEdit->toPlainText();
    output << file_data;
    file.close();
}


void Noote::on_actionExit_triggered()
{

    QApplication::quit();
}


void Noote::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}



void Noote::on_actionCut_triggered()
{
    ui->textEdit->cut();
}


void Noote::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}


void Noote::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}


void Noote::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

