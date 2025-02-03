/********************************************************************************
** Form generated from reading UI file 'help.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELP_H
#define UI_HELP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Help
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QGridLayout *gridLayout_2;
    QTextBrowser *textBrowser;
    QPushButton *back;

    void setupUi(QMainWindow *Help)
    {
        if (Help->objectName().isEmpty())
            Help->setObjectName("Help");
        Help->resize(800, 600);
        centralwidget = new QWidget(Help);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setMaximumSize(QSize(16777215, 50));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 780, 538));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents_2);
        gridLayout_2->setObjectName("gridLayout_2");
        textBrowser = new QTextBrowser(scrollAreaWidgetContents_2);
        textBrowser->setObjectName("textBrowser");

        gridLayout_2->addWidget(textBrowser, 0, 0, 1, 1);

        back = new QPushButton(scrollAreaWidgetContents_2);
        back->setObjectName("back");
        back->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        back->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	margin:0% 250%;\n"
"	\n"
"    color: #000; \n"
"    border: 2px solid rgb(0,0,0) ;\n"
"    border-radius: 50px;\n"
"    padding: 5px;\n"
"}\n"
""));

        gridLayout_2->addWidget(back, 1, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents_2);

        gridLayout->addWidget(scrollArea, 1, 0, 1, 1);

        Help->setCentralWidget(centralwidget);

        retranslateUi(Help);

        QMetaObject::connectSlotsByName(Help);
    } // setupUi

    void retranslateUi(QMainWindow *Help)
    {
        Help->setWindowTitle(QCoreApplication::translate("Help", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("Help", "Help", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("Help", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<h1 align=\"center\" style=\" margin-top:18px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:xx-large; font-weight:700;\">Vole Machine Language Simulator </span></h1>\n"
"<h2 align=\"center\" style=\" margin-top:16px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:x-large; font-weight:700;\">How to run </span></h2>\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom"
                        ":12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">first input instructions <br />second click on load data <br />third click on run <br />fourth look at output screen and memory and register </p>\n"
"<h2 align=\"center\" style=\" margin-top:16px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:x-large; font-weight:700;\">Instructions </span></h2></body></html>", nullptr));
        back->setText(QCoreApplication::translate("Help", "I Understood", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Help: public Ui_Help {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELP_H
