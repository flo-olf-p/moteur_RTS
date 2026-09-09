/********************************************************************************
** Form generated from reading UI file 'RTS_Engine.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
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

QT_BEGIN_NAMESPACE

class Ui_RTS_EngineClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *RTS_EngineClass)
    {
        if (RTS_EngineClass->objectName().isEmpty())
            RTS_EngineClass->setObjectName("RTS_EngineClass");
        RTS_EngineClass->resize(600, 400);
        menuBar = new QMenuBar(RTS_EngineClass);
        menuBar->setObjectName("menuBar");
        RTS_EngineClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(RTS_EngineClass);
        mainToolBar->setObjectName("mainToolBar");
        RTS_EngineClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(RTS_EngineClass);
        centralWidget->setObjectName("centralWidget");
        RTS_EngineClass->setCentralWidget(centralWidget);
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
