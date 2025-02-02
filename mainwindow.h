#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "help.h"

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
    void on_loadData_clicked();
    void on_runStep_clicked();
    void on_runAll_clicked();
    void on_clear_clicked();

    void on_loadFile_clicked();

private:
    Ui::MainWindow *ui;
    Help* help;
};
#endif // MAINWINDOW_H
