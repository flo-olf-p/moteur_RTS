/********************************************************************************
** Form generated from reading UI file 'RTS_Engine.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RTS_ENGINE_H
#define UI_RTS_ENGINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "QtWidgetsDebugMenu.h"
#include "QtWidgetsSimulation.h"

QT_BEGIN_NAMESPACE

class Ui_RTS_EngineClass
{
public:
    QWidget *centralWidget;
    QtWidgetsSimulation *widget;
    QtWidgetsDebugMenu *widget_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *RTS_EngineClass)
    {
        if (RTS_EngineClass->objectName().isEmpty())
            RTS_EngineClass->setObjectName("RTS_EngineClass");
        RTS_EngineClass->resize(1300, 1000);
        centralWidget = new QWidget(RTS_EngineClass);
        centralWidget->setObjectName("centralWidget");
        widget = new QtWidgetsSimulation(centralWidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 1000, 1000));
        widget_2 = new QtWidgetsDebugMenu(centralWidget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(1000, 0, 300, 1000));
        RTS_EngineClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(RTS_EngineClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1300, 21));
        RTS_EngineClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(RTS_EngineClass);
        mainToolBar->setObjectName("mainToolBar");
        RTS_EngineClass->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(RTS_EngineClass);
        statusBar->setObjectName("statusBar");
        RTS_EngineClass->setStatusBar(statusBar);

        retranslateUi(RTS_EngineClass);

        QMetaObject::connectSlotsByName(RTS_EngineClass);
    } // setupUi

    void retranslateUi(QMainWindow *RTS_EngineClass)
    {
        RTS_EngineClass->setWindowTitle(QCoreApplication::translate("RTS_EngineClass", "RTS_Engine", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RTS_EngineClass: public Ui_RTS_EngineClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RTS_ENGINE_H
