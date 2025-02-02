#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "instructions.h"

#include <bits/stdc++.h>
using namespace std;

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

void MainWindow::on_loadInput_clicked()
{
    if (!ui->inputInstructions->toPlainText().isEmpty()){
        vector<string> inst;
        QString file = ui->inputInstructions->toPlainText();
        string fileContent = file.toStdString();;

        for (int i = 0; i < int(fileContent.size()); ++i) {                  // remove spaces and end lines from the file.
            fileContent.erase(remove(fileContent.begin(), fileContent.end(), '\n'), fileContent.end());
            fileContent.erase(remove(fileContent.begin(), fileContent.end(), ' '), fileContent.end());
        }
        for (int i = 0; i < int(fileContent.size()); i += 4) {               // put every 4 characters in an index in the vector.
            inst.push_back(fileContent.substr(i, 4));
        }
        for (int i = 0; i < int(inst.size()); ++i) {
            for (int j = 0; j < 4; ++j) {                               // check the validity of each char in each index.
                if (inst[i][j] < 48 || (inst[i][j] > 57 && inst[i][j] < 65) ||
                    (inst[i][j] > 70 && inst[i][j] < 97) || inst[i][j] > 102) {
                    inst.erase(inst.begin() + i);
                    i--;
                    break;
                }
            }
        }
        instructions.getInstructions() = inst;
        ui->inputInstructions->clear();
    }
}

void MainWindow::on_loadFile_clicked()
{

}

void MainWindow::on_runStep_clicked()
{
    machine.runStepByStep(memory,regist,instructions);
}

void MainWindow::on_runAll_clicked()
{
    machine.runAll(memory,regist,instructions);
}

void MainWindow::on_clear_clicked()
{
    Machine newMachine;
    Memory newMemory;
    Register newRegist;
    Instructions newInstructions;
    instructions = newInstructions;
    machine = newMachine;
    memory = newMemory;
    regist = newRegist;
}
