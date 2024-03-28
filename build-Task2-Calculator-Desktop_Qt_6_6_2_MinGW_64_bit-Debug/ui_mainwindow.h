/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(415, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(100, 110, 171, 31));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        lineEdit->setFont(font);
        lineEdit->setToolTipDuration(-17);
        lineEdit->setCursorPosition(0);
        lineEdit->setAlignment(Qt::AlignCenter);
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(100, 210, 171, 31));
        lineEdit_2->setFont(font);
        lineEdit_2->setToolTipDuration(-17);
        lineEdit_2->setCursorPosition(0);
        lineEdit_2->setAlignment(Qt::AlignCenter);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(80, 40, 201, 51));
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label->setIndent(1);
        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(150, 150, 61, 41));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        lineEdit_3->setFont(font1);
        lineEdit_3->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(140, 270, 80, 24));
        pushButton->setFont(font1);
        pushButton->setAutoRepeatInterval(83);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(18, 360, 371, 20));
        label_2->setFont(font);
        label_2->setContextMenuPolicy(Qt::NoContextMenu);
        label_2->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 415, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter 1st number", nullptr));
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter 2nd number", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "CALCULATOR", nullptr));
        lineEdit_3->setPlaceholderText(QCoreApplication::translate("MainWindow", "Operator", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Result", nullptr));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
