/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QWidget
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *QWidget)
    {
        if (QWidget->objectName().isEmpty())
            QWidget->setObjectName("QWidget");
        QWidget->resize(800, 600);
        centralwidget = new QWidget(QWidget);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 490, 221, 81));
        QWidget->setCentralWidget(centralwidget);
        menubar = new QMenuBar(QWidget);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        QWidget->setMenuBar(menubar);
        statusbar = new QStatusBar(QWidget);
        statusbar->setObjectName("statusbar");
        QWidget->setStatusBar(statusbar);

        retranslateUi(QWidget);

        QMetaObject::connectSlotsByName(QWidget);
    } // setupUi

    void retranslateUi(QMainWindow *QWidget)
    {
        QWidget->setWindowTitle(QCoreApplication::translate("QWidget", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("QWidget", "<html><head/><body><p><span style=\" font-size:18pt; text-decoration: underline;\">+ Status</span></p><p><br/></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QWidget: public Ui_QWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
