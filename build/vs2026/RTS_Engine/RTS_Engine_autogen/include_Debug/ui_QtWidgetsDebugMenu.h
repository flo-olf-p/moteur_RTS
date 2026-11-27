/********************************************************************************
** Form generated from reading UI file 'QtWidgetsDebugMenu.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTWIDGETSDEBUGMENU_H
#define UI_QTWIDGETSDEBUGMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtWidgetsDebugMenuClass
{
public:
    QScrollBar *verticalScrollBar;
    QSpinBox *SizeCase;
    QPushButton *Update;

    void setupUi(QWidget *QtWidgetsDebugMenuClass)
    {
        if (QtWidgetsDebugMenuClass->objectName().isEmpty())
            QtWidgetsDebugMenuClass->setObjectName("QtWidgetsDebugMenuClass");
        QtWidgetsDebugMenuClass->resize(300, 1000);
        verticalScrollBar = new QScrollBar(QtWidgetsDebugMenuClass);
        verticalScrollBar->setObjectName("verticalScrollBar");
        verticalScrollBar->setGeometry(QRect(280, 9, 20, 991));
        verticalScrollBar->setOrientation(Qt::Orientation::Vertical);
        SizeCase = new QSpinBox(QtWidgetsDebugMenuClass);
        SizeCase->setObjectName("SizeCase");
        SizeCase->setGeometry(QRect(80, 170, 91, 22));
        Update = new QPushButton(QtWidgetsDebugMenuClass);
        Update->setObjectName("Update");
        Update->setGeometry(QRect(90, 240, 80, 24));

        retranslateUi(QtWidgetsDebugMenuClass);

        QMetaObject::connectSlotsByName(QtWidgetsDebugMenuClass);
    } // setupUi

    void retranslateUi(QWidget *QtWidgetsDebugMenuClass)
    {
        QtWidgetsDebugMenuClass->setWindowTitle(QCoreApplication::translate("QtWidgetsDebugMenuClass", "QtWidgetsDebugMenu", nullptr));
        Update->setText(QCoreApplication::translate("QtWidgetsDebugMenuClass", "Update", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtWidgetsDebugMenuClass: public Ui_QtWidgetsDebugMenuClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTWIDGETSDEBUGMENU_H
