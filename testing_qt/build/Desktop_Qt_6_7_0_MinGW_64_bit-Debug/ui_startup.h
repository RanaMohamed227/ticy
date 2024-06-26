/********************************************************************************
** Form generated from reading UI file 'startup.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTUP_H
#define UI_STARTUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_startup
{
public:
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEdit_username;
    QLabel *label_2;
    QLineEdit *lineEdit_password;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QPushButton *pushButton_2;

    void setupUi(QWidget *startup)
    {
        if (startup->objectName().isEmpty())
            startup->setObjectName("startup");
        startup->resize(617, 355);
        groupBox = new QGroupBox(startup);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(20, 20, 571, 311));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(230, 160, 111, 29));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(30, 80, 521, 71));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEdit_username = new QLineEdit(layoutWidget);
        lineEdit_username->setObjectName("lineEdit_username");
        lineEdit_username->setEnabled(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_username);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        lineEdit_password = new QLineEdit(layoutWidget);
        lineEdit_password->setObjectName("lineEdit_password");
        lineEdit_password->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_password);

        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(40, 250, 258, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName("label_3");

        horizontalLayout->addWidget(label_3);

        pushButton_2 = new QPushButton(layoutWidget1);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout->addWidget(pushButton_2);


        retranslateUi(startup);

        QMetaObject::connectSlotsByName(startup);
    } // setupUi

    void retranslateUi(QWidget *startup)
    {
        startup->setWindowTitle(QCoreApplication::translate("startup", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("startup", "Sign Up", nullptr));
        pushButton->setText(QCoreApplication::translate("startup", "Sign Up", nullptr));
        label->setText(QCoreApplication::translate("startup", "Email", nullptr));
        label_2->setText(QCoreApplication::translate("startup", "Password", nullptr));
        label_3->setText(QCoreApplication::translate("startup", "Already have an account?", nullptr));
        pushButton_2->setText(QCoreApplication::translate("startup", "Log In", nullptr));
    } // retranslateUi

};

namespace Ui {
    class startup: public Ui_startup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTUP_H
