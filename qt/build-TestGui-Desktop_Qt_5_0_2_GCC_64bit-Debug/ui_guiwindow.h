/********************************************************************************
** Form generated from reading UI file 'guiwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUIWINDOW_H
#define UI_GUIWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GuiWindow
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GuiWindow)
    {
        if (GuiWindow->objectName().isEmpty())
            GuiWindow->setObjectName(QStringLiteral("GuiWindow"));
        GuiWindow->resize(400, 300);
        menuBar = new QMenuBar(GuiWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        GuiWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GuiWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        GuiWindow->addToolBar(mainToolBar);
        centralWidget = new QWidget(GuiWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        GuiWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(GuiWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        GuiWindow->setStatusBar(statusBar);

        retranslateUi(GuiWindow);

        QMetaObject::connectSlotsByName(GuiWindow);
    } // setupUi

    void retranslateUi(QMainWindow *GuiWindow)
    {
        GuiWindow->setWindowTitle(QApplication::translate("GuiWindow", "GuiWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class GuiWindow: public Ui_GuiWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIWINDOW_H
