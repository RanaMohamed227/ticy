/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QWidget
{
public:

    void setupUi(QWidget *QWidget)
    {
        if (QWidget->objectName().isEmpty())
            QWidget->setObjectName("QWidget");
        QWidget->resize(800, 600);

        retranslateUi(QWidget);

        QMetaObject::connectSlotsByName(QWidget);
    } // setupUi

    void retranslateUi(QWidget *QWidget)
    {
        QWidget->setWindowTitle(QCoreApplication::translate("QWidget", "Widget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QWidget: public Ui_QWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
