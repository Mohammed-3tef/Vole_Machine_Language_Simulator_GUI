#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "help.h"
#include "instructions.h"
#include "memory.h"
#include "register.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_help_clicked();
    void on_runStep_clicked();
    void on_runAll_clicked();
    void on_clear_clicked();
    void on_loadFile_clicked();
    void on_loadInput_clicked();

    void displayRegister();
    void displayMemory();

private:
    Ui::MainWindow *ui;
    Help* help;
    Instructions instructions;
    Memory memory;
    Register regist;
};
#endif // MAINWINDOW_H
