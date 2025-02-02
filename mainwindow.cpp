#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , help(nullptr)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_help_clicked()
{
    if (!help) {
        help = new Help(this);
    }
    help->show();
}


void MainWindow::on_loadData_clicked()
{

}


void MainWindow::on_runStep_clicked()
{

}


void MainWindow::on_clear_clicked()
{

}


void MainWindow::on_runAll_clicked()
{

}


void MainWindow::on_loadFile_clicked()
{

}

