#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "instructions.h"

#include <bits/stdc++.h>
#include <ctime>
#include <QEventLoop>
#include <QTimer>
#include <QFileDialog>
#include <QMessageBox>

using namespace std;

int number = 0;
int rr = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , help(nullptr)
{
    ui->setupUi(this);
    ui->runAll->setEnabled(false);
    ui->runStep->setEnabled(false);
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

void delay(int milliseconds) {
    QEventLoop loop;
    QTimer::singleShot(milliseconds, &loop, &QEventLoop::quit);
    loop.exec(); // Start the event loop and wait
}

void MainWindow::on_loadInput_clicked()
{
    // Check validity of instructions
    if (!ui->inputInstructions->toPlainText().isEmpty()) {
        vector<string> inst;
        QString file = ui->inputInstructions->toPlainText();
        string fileContent = file.toStdString();

        for (int i = 0; i < int(fileContent.size()); ++i) {
            fileContent[i] = toupper(fileContent[i]);
        }

        // Remove spaces and newlines from the fileContent in a single pass
        fileContent.erase(remove_if(fileContent.begin(), fileContent.end(),
                                    [](char c) { return c == ' ' || c == '\n'; }),
                          fileContent.end());

        // Put every 4 characters in an index in the vector
        for (int i = 0; i < int(fileContent.size()); i += 4) {
            inst.push_back(fileContent.substr(i, 4));
        }

        // Filter out invalid instructions
        vector<string> validInst;
        for (int i = 0; i < int(inst.size()); ++i) {
            bool valid = true;
            for (int j = 0; j < 4; ++j) {
                // Check the validity of each character in each instruction
                if (inst[i][j] < 48 || (inst[i][j] > 57 && inst[i][j] < 65) ||
                    (inst[i][j] > 70 && inst[i][j] < 97) || inst[i][j] > 102) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                validInst.push_back(inst[i]);
            }
        }

        // Set the valid instructions
        instructions.setInstructions(validInst);
        memory.setInstructions(validInst);

        // Clear and disable UI elements
        ui->inputInstructions->clear();
        ui->inputInstructions->setEnabled(false);
        ui->loadInput->setEnabled(false);
        ui->loadFile->setEnabled(false);
        ui->runAll->setEnabled(true);
        ui->runStep->setEnabled(true);
    }
}


void MainWindow::on_loadFile_clicked()
{
    // get the file
    QString fileName = QFileDialog::getOpenFileName(
        this,
        tr("Open File"),
        "C://",
        "Text File (*.txt)"
        );

    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            QString qfile = in.readAll(); // Read entire file into a QString
            vector<string> inst;
            string fileContent = qfile.toStdString();

            for (int i = 0; i < int(fileContent.size()); ++i) {
                fileContent[i] = toupper(fileContent[i]);
            }

            // Remove spaces and newlines from the fileContent in a single pass
            fileContent.erase(remove_if(fileContent.begin(), fileContent.end(),
                                        [](char c) { return c == ' ' || c == '\n'; }),
                              fileContent.end());

            // Put every 4 characters in an index in the vector
            for (int i = 0; i < int(fileContent.size()); i += 4) {
                inst.push_back(fileContent.substr(i, 4));
            }

            // Filter out invalid instructions
            vector<string> validInst;
            for (int i = 0; i < int(inst.size()); ++i) {
                bool valid = true;
                for (int j = 0; j < 4; ++j) {
                    // Check the validity of each character in each instruction
                    if (inst[i][j] < 48 || (inst[i][j] > 57 && inst[i][j] < 65) ||
                        (inst[i][j] > 70 && inst[i][j] < 97) || inst[i][j] > 102) {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    validInst.push_back(inst[i]);
                }
            }

            // Set the valid instructions
            instructions.setInstructions(validInst);
            memory.setInstructions(validInst);


            file.close();
        } else {
            QMessageBox::warning(this, tr("Error"), tr("Could not open file"));
        }
    }

    ui->inputInstructions->clear();
    ui->inputInstructions->setEnabled(false);
    ui->loadInput->setEnabled(false);
    ui->loadFile->setEnabled(false);
    ui->runAll->setEnabled(true);
    ui->runStep->setEnabled(true);
}

void MainWindow::on_runStep_clicked()
{
    ui->runStep->setEnabled(false);
    ui->runAll->setEnabled(false);

    rr = 0;
    int counter = memory.getCounter();
    bool flag = instructions.getHalted();

    while (counter <= 255 && !flag) {
        string instruction = memory.getInstruction();
        if (instruction == "0000") {
            ui->currentInstruction->setText("C000 (Stop)");
            break;
        }

        QString displayInst = "";
        for (char c : instruction) {
            displayInst += QChar(std::toupper(c));
        }
        if (displayInst == "4040") {displayInst = "C000 (Stop)";}
        ui->currentInstruction->setText(displayInst);

        string num = instruction.substr(0, 1);
        string address1 = instruction.substr(1, 1);
        string address2 = instruction.substr(2, 1);
        string address3 = instruction.substr(3, 1);
        string address4 = instruction.substr(2, 2);
        bool ff = false;
        int X, XY;

        if (num == "1") {
            instructions.loadFromMemoryToRegister(address4, address1, regist, memory);
        } else if (num == "2") {
            instructions.loadToRegister(address1, address4, regist);
        } else if (num == "3") {
            instructions.store(address1, address4, regist, memory);
            if (address4 == "00") {                 // Display what shows on screen
                std::string hex = memory.getMemory(0);
                ui->outputScreen->setText(QString::fromStdString(hex));
            }
        } else if (num == "4") {
            instructions.move(address2, address3, regist);
        } else if (num == "5") {
            instructions.addingTwoComplement(address1, address2, address3, regist);
        } else if (num == "6") {
            instructions.addingFloatingNumber(address1, address2, address3, regist);
        } else if (num == "7") {
            instructions.orBitwiseOperation(address1, address2, address3, regist);
        } else if (num == "8") {
            instructions.andBitwiseOperation(address1, address2, address3, regist);
        } else if (num == "9") {
            instructions.exclusiveOr(address1, address2, address3, regist);
        } else if (num == "A" || num == "a") {
            X = stoi(address4, nullptr, 16);
            instructions.rotateRight(address1, X, regist);
        } else if (num == "B" || num == "b") {
            XY = stoi(address4, nullptr, 16);
            counter = instructions.conditionalJump(address1, XY, regist, memory, counter, ff);
            if (ff) counter -= 2;
        } else if (num == "C" || num == "c") {
            instructions.halt();
        } else if (num == "D" || num == "d") {
            XY = stoi(address4, nullptr, 16);
            counter = instructions.conditionalJumpGreater(address1, XY, regist, memory, counter, ff);
            if (ff) counter -= 2;
        }
        memory.setCounter(counter + 2);
        counter = memory.getCounter();
        flag = instructions.getHalted();

        displayMemory();
        displayRegister();
        delay(1000);
    }
}

void MainWindow::on_runAll_clicked(){
    rr = 0;
    int counter = memory.getCounter();
    bool flag = instructions.getHalted();

    int maxIterations = 1000;
    int iterationCount = 0;

    while (counter <= 255 && !flag) {
        if (++iterationCount > maxIterations) {
            break;
        }

        string instruction = memory.getInstruction();
        if (instruction.empty() || instruction.length() != 4) {
            break;
        }

        string num = instruction.substr(0, 1);
        string address1 = instruction.substr(1, 1);
        string address2 = instruction.substr(2, 1);
        string address3 = instruction.substr(3, 1);
        string address4 = instruction.substr(2, 2);
        bool ff = false;
        int X, XY;

        if (num == "1") {
            instructions.loadFromMemoryToRegister(address4, address1, regist, memory);
        } else if (num == "2") {
            instructions.loadToRegister(address1, address4, regist);
        } else if (num == "3") {
            instructions.store(address1, address4, regist, memory);
            if (address4 == "00") {                 // Display what shows on screen
                std::string hex = memory.getMemory(0);
                ui->outputScreen->setText(QString::fromStdString(hex));
            }
        } else if (num == "4") {
            instructions.move(address2, address3, regist);
        } else if (num == "5") {
            instructions.addingTwoComplement(address1, address2, address3, regist);
        } else if (num == "6") {
            instructions.addingFloatingNumber(address1, address2, address3, regist);
        } else if (num == "7") {
            instructions.orBitwiseOperation(address1, address2, address3, regist);
        } else if (num == "8") {
            instructions.andBitwiseOperation(address1, address2, address3, regist);
        } else if (num == "9") {
            instructions.exclusiveOr(address1, address2, address3, regist);
        } else if (num == "A" || num == "a") {
            X = stoi(address4, nullptr, 16);
            instructions.rotateRight(address1, X, regist);
        } else if (num == "B" || num == "b") {
            XY = stoi(address4, nullptr, 16);
            counter = instructions.conditionalJump(address1, XY, regist, memory, counter, ff);
            if (ff) counter -= 2;
        } else if (num == "C" || num == "c") {
            instructions.halt();
            break;
        } else if (num == "D" || num == "d") {
            XY = stoi(address4, nullptr, 16);
            counter = instructions.conditionalJumpGreater(address1, XY, regist, memory, counter, ff);
            if (ff) counter -= 2;
        } else {
            break;
        }

        memory.setCounter(counter + 2);
        counter = memory.getCounter();
        flag = instructions.getHalted();
    }

    displayMemory();
    displayRegister();
    ui->runStep->setEnabled(false);
    ui->runAll->setEnabled(false);
}


void MainWindow::on_clear_clicked()
{
    Memory newMemory;
    Register newRegist;
    Instructions newInstructions;
    instructions = newInstructions;
    memory = newMemory;
    regist = newRegist;
    ui->runStep->setEnabled(false);
    ui->runAll->setEnabled(false);
    ui->inputInstructions->setEnabled(true);
    ui->loadInput->setEnabled(true);
    ui->loadFile->setEnabled(true);
    ui->outputScreen->setText("");
    ui->currentInstruction->setText("");
    number = 0;
    rr = 0;

    for (int i = 0; i < 256; i++) {
        QString labelName = QString("x%1").arg(i, 2, 16, QChar('0')).toLower();
        QLabel* label = findChild<QLabel*>(labelName);
        if (label) {
            label->setText("00");
        }
    }

    ui->r0->setText("00");
    ui->r1->setText("00");
    ui->r2->setText("00");
    ui->r3->setText("00");
    ui->r4->setText("00");
    ui->r5->setText("00");
    ui->r6->setText("00");
    ui->r7->setText("00");
    ui->r8->setText("00");
    ui->r9->setText("00");
    ui->ra->setText("00");
    ui->rb->setText("00");
    ui->rc->setText("00");
    ui->rd->setText("00");
    ui->re->setText("00");
    ui->rf->setText("00");
}

void MainWindow::displayMemory(){
    for (int i = 0; i < 256; i++) {
        QString labelName = QString("x%1").arg(i, 2, 16, QChar('0')).toLower();
        QLabel* label = findChild<QLabel*>(labelName);
        if (label) {
            label->setText(QString::fromStdString(memory.getMemory(i)));
        }
    }
}
void MainWindow::displayRegister(){
    ui->r0->setText(QString::fromStdString(regist.getRegister("0")));
    ui->r1->setText(QString::fromStdString(regist.getRegister("1")));
    ui->r2->setText(QString::fromStdString(regist.getRegister("2")));
    ui->r3->setText(QString::fromStdString(regist.getRegister("3")));
    ui->r4->setText(QString::fromStdString(regist.getRegister("4")));
    ui->r5->setText(QString::fromStdString(regist.getRegister("5")));
    ui->r6->setText(QString::fromStdString(regist.getRegister("6")));
    ui->r7->setText(QString::fromStdString(regist.getRegister("7")));
    ui->r8->setText(QString::fromStdString(regist.getRegister("8")));
    ui->r9->setText(QString::fromStdString(regist.getRegister("9")));
    ui->ra->setText(QString::fromStdString(regist.getRegister("a")));
    ui->rb->setText(QString::fromStdString(regist.getRegister("b")));
    ui->rc->setText(QString::fromStdString(regist.getRegister("c")));
    ui->rd->setText(QString::fromStdString(regist.getRegister("d")));
    ui->re->setText(QString::fromStdString(regist.getRegister("e")));
    ui->rf->setText(QString::fromStdString(regist.getRegister("f")));
}
