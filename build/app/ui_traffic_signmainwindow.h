/********************************************************************************
** Form generated from reading UI file 'traffic_signmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAFFIC_SIGNMAINWINDOW_H
#define UI_TRAFFIC_SIGNMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Traffic_signMainWindow
{
public:
    QWidget *centralWidget;
    QLabel *VideoLabel;
    QLabel *SignLabel;
    QPushButton *VideoButton;
    QPushButton *ExitButton;
    QTextBrowser *textBrowser;
    QPushButton *RunButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Traffic_signMainWindow)
    {
        if (Traffic_signMainWindow->objectName().isEmpty())
            Traffic_signMainWindow->setObjectName(QString::fromUtf8("Traffic_signMainWindow"));
        Traffic_signMainWindow->resize(901, 584);
        centralWidget = new QWidget(Traffic_signMainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        VideoLabel = new QLabel(centralWidget);
        VideoLabel->setObjectName(QString::fromUtf8("VideoLabel"));
        VideoLabel->setGeometry(QRect(10, 20, 640, 480));
        SignLabel = new QLabel(centralWidget);
        SignLabel->setObjectName(QString::fromUtf8("SignLabel"));
        SignLabel->setGeometry(QRect(700, 30, 151, 111));
        VideoButton = new QPushButton(centralWidget);
        VideoButton->setObjectName(QString::fromUtf8("VideoButton"));
        VideoButton->setGeometry(QRect(660, 440, 99, 27));
        ExitButton = new QPushButton(centralWidget);
        ExitButton->setObjectName(QString::fromUtf8("ExitButton"));
        ExitButton->setGeometry(QRect(780, 440, 99, 27));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(690, 180, 161, 81));
        RunButton = new QPushButton(centralWidget);
        RunButton->setObjectName(QString::fromUtf8("RunButton"));
        RunButton->setGeometry(QRect(720, 380, 99, 27));
        Traffic_signMainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Traffic_signMainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 901, 25));
        Traffic_signMainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Traffic_signMainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Traffic_signMainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Traffic_signMainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Traffic_signMainWindow->setStatusBar(statusBar);

        retranslateUi(Traffic_signMainWindow);

        QMetaObject::connectSlotsByName(Traffic_signMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *Traffic_signMainWindow)
    {
        Traffic_signMainWindow->setWindowTitle(QApplication::translate("Traffic_signMainWindow", "Traffic_signMainWindow", 0, QApplication::UnicodeUTF8));
        VideoLabel->setText(QApplication::translate("Traffic_signMainWindow", "Video", 0, QApplication::UnicodeUTF8));
        SignLabel->setText(QApplication::translate("Traffic_signMainWindow", "Sign", 0, QApplication::UnicodeUTF8));
        VideoButton->setText(QApplication::translate("Traffic_signMainWindow", "Video", 0, QApplication::UnicodeUTF8));
        ExitButton->setText(QApplication::translate("Traffic_signMainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        RunButton->setText(QApplication::translate("Traffic_signMainWindow", "Run", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Traffic_signMainWindow: public Ui_Traffic_signMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAFFIC_SIGNMAINWINDOW_H
