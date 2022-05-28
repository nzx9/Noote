#ifndef NOOTE_H
#define NOOTE_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Noote; }
QT_END_NAMESPACE

class Noote : public QMainWindow
{
    Q_OBJECT

public:
    Noote(QWidget *parent = nullptr);
    ~Noote();



private slots:
    void on_actionNew_triggered();
    void on_actionOpen_triggered();

    void on_actionSave_as_triggered();

    void on_actionSave_triggered();

    void on_actionExit_triggered();

    void on_actionCopy_triggered();

    void on_actionCut_triggered();

    void on_actionPaste_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

private:
    Ui::Noote *ui;

    QString currFile  = nullptr;


};
#endif // NOOTE_H
