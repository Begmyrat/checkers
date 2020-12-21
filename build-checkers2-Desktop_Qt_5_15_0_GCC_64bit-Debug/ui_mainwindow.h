/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
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
    QPushButton *pushButton_File;
    QPushButton *pushButton_Edit;
    QPushButton *pushButton_Game;
    QPushButton *pushButton_Help;
    QPushButton *pushButton_NewGame;
    QPushButton *pushButton_Left;
    QPushButton *pushButton_Left_2;
    QPushButton *pushButton_Left_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(578, 465);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton_File = new QPushButton(centralwidget);
        pushButton_File->setObjectName(QStringLiteral("pushButton_File"));
        pushButton_File->setGeometry(QRect(10, 0, 80, 32));
        pushButton_File->setAutoFillBackground(false);
        pushButton_File->setStyleSheet(QLatin1String("background-color : rgba(0, 122, 255, 128);\n"
"border-radius : 10px;\n"
"color : rgb(255, 255, 255);"));
        pushButton_Edit = new QPushButton(centralwidget);
        pushButton_Edit->setObjectName(QStringLiteral("pushButton_Edit"));
        pushButton_Edit->setGeometry(QRect(90, 0, 80, 32));
        pushButton_Edit->setStyleSheet(QLatin1String("background-color : rgba(0, 122, 255, 128);\n"
"border-radius : 10px;\n"
"color : rgb(255, 255, 255);"));
        pushButton_Game = new QPushButton(centralwidget);
        pushButton_Game->setObjectName(QStringLiteral("pushButton_Game"));
        pushButton_Game->setGeometry(QRect(170, 0, 80, 32));
        pushButton_Game->setStyleSheet(QLatin1String("background-color : rgba(0, 122, 255, 128);\n"
"border-radius : 10px;\n"
"color : rgb(255, 255, 255);"));
        pushButton_Help = new QPushButton(centralwidget);
        pushButton_Help->setObjectName(QStringLiteral("pushButton_Help"));
        pushButton_Help->setGeometry(QRect(250, 0, 80, 32));
        pushButton_Help->setStyleSheet(QLatin1String("background-color : rgba(0, 122, 255, 128);\n"
"border-radius : 10px;\n"
"color : rgb(255, 255, 255);"));
        pushButton_NewGame = new QPushButton(centralwidget);
        pushButton_NewGame->setObjectName(QStringLiteral("pushButton_NewGame"));
        pushButton_NewGame->setGeometry(QRect(410, 50, 161, 41));
        pushButton_NewGame->setStyleSheet(QLatin1String("background-color : rgba(0, 122, 255, 128);\n"
"border-radius : 10px;\n"
"color : rgb(255, 255, 255);"));
        pushButton_Left = new QPushButton(centralwidget);
        pushButton_Left->setObjectName(QStringLiteral("pushButton_Left"));
        pushButton_Left->setGeometry(QRect(410, 90, 61, 41));
        pushButton_Left->setStyleSheet(QLatin1String("background-color : rgba(0, 122, 255, 128);\n"
"border-radius : 10px;\n"
"color : rgb(255, 255, 255);"));
        pushButton_Left_2 = new QPushButton(centralwidget);
        pushButton_Left_2->setObjectName(QStringLiteral("pushButton_Left_2"));
        pushButton_Left_2->setGeometry(QRect(470, 90, 41, 41));
        pushButton_Left_2->setStyleSheet(QLatin1String("background-color : rgba(0, 122, 255, 128);\n"
"border-radius : 10px;\n"
"color : rgb(255, 255, 255);"));
        pushButton_Left_3 = new QPushButton(centralwidget);
        pushButton_Left_3->setObjectName(QStringLiteral("pushButton_Left_3"));
        pushButton_Left_3->setGeometry(QRect(510, 90, 61, 41));
        pushButton_Left_3->setStyleSheet(QLatin1String("background-color : rgba(0, 122, 255, 128);\n"
"border-radius : 10px;\n"
"color : rgb(255, 255, 255);"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 578, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        pushButton_File->setText(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        pushButton_Edit->setText(QApplication::translate("MainWindow", "Edit", Q_NULLPTR));
        pushButton_Game->setText(QApplication::translate("MainWindow", "Game", Q_NULLPTR));
        pushButton_Help->setText(QApplication::translate("MainWindow", "Help", Q_NULLPTR));
        pushButton_NewGame->setText(QApplication::translate("MainWindow", "New Game", Q_NULLPTR));
        pushButton_Left->setText(QApplication::translate("MainWindow", "Left", Q_NULLPTR));
        pushButton_Left_2->setText(QApplication::translate("MainWindow", "Up", Q_NULLPTR));
        pushButton_Left_3->setText(QApplication::translate("MainWindow", "Right", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
