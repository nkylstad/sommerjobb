/********************************************************************************
** Form generated from reading UI file 'guiwindow.ui'
**
** Created: Mon Jun 24 15:50:51 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUIWINDOW_H
#define UI_GUIWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GuiWindow
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GuiWindow)
    {
        if (GuiWindow->objectName().isEmpty())
            GuiWindow->setObjectName(QString::fromUtf8("GuiWindow"));
        GuiWindow->resize(400, 300);
        GuiWindow->setStyleSheet(QString::fromUtf8("#GuiWindow {\n"
"background: QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #eef, stop: 1 #ccf);\n"
"}"));
        centralWidget = new QWidget(GuiWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        GuiWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GuiWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 25));
        GuiWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GuiWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        GuiWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(GuiWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        GuiWindow->setStatusBar(statusBar);

        retranslateUi(GuiWindow);

        QMetaObject::connectSlotsByName(GuiWindow);
    } // setupUi

    void retranslateUi(QMainWindow *GuiWindow)
    {
        GuiWindow->setWindowTitle(QApplication::translate("GuiWindow", "GuiWindow", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GuiWindow: public Ui_GuiWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIWINDOW_H
