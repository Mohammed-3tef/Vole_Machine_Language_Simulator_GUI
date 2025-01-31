/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QFrame *VMLS;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QFrame *Register;
    QFrame *Memory;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1157, 872);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        VMLS = new QFrame(centralwidget);
        VMLS->setObjectName("VMLS");
        VMLS->setMaximumSize(QSize(16777215, 200));
        VMLS->setFrameShape(QFrame::Shape::StyledPanel);
        VMLS->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout_2 = new QGridLayout(VMLS);
        gridLayout_2->setObjectName("gridLayout_2");
        label = new QLabel(VMLS);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(30);
        font.setBold(true);
        font.setItalic(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);


        gridLayout->addWidget(VMLS, 0, 0, 1, 4);

        Register = new QFrame(centralwidget);
        Register->setObjectName("Register");
        Register->setFrameShape(QFrame::Shape::StyledPanel);
        Register->setFrameShadow(QFrame::Shadow::Raised);

        gridLayout->addWidget(Register, 1, 0, 1, 1);

        Memory = new QFrame(centralwidget);
        Memory->setObjectName("Memory");
        Memory->setFrameShape(QFrame::Shape::StyledPanel);
        Memory->setFrameShadow(QFrame::Shadow::Raised);

        gridLayout->addWidget(Memory, 1, 1, 1, 3);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Vole Machine Language Simulator", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
