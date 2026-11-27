/********************************************************************************
** Form generated from reading UI file 'QtWidgetsSimulation.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTWIDGETSSIMULATION_H
#define UI_QTWIDGETSSIMULATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtWidgetsSimulationClass
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;

    void setupUi(QWidget *QtWidgetsSimulationClass)
    {
        if (QtWidgetsSimulationClass->objectName().isEmpty())
            QtWidgetsSimulationClass->setObjectName("QtWidgetsSimulationClass");
        QtWidgetsSimulationClass->resize(1000, 1000);
        gridLayoutWidget = new QWidget(QtWidgetsSimulationClass);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(9, 9, 981, 871));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(QtWidgetsSimulationClass);

        QMetaObject::connectSlotsByName(QtWidgetsSimulationClass);
    } // setupUi

    void retranslateUi(QWidget *QtWidgetsSimulationClass)
    {
        QtWidgetsSimulationClass->setWindowTitle(QCoreApplication::translate("QtWidgetsSimulationClass", "QtWidgetsSimulation", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtWidgetsSimulationClass: public Ui_QtWidgetsSimulationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTWIDGETSSIMULATION_H
