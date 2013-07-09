/********************************************************************************
** Form generated from reading UI file 'dolfingui.ui'
**
** Created: Mon Jul 8 08:38:46 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOLFINGUI_H
#define UI_DOLFINGUI_H

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

class Ui_DolfinGui
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DolfinGui)
    {
        if (DolfinGui->objectName().isEmpty())
            DolfinGui->setObjectName(QString::fromUtf8("DolfinGui"));
        DolfinGui->resize(400, 300);
        menuBar = new QMenuBar(DolfinGui);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        DolfinGui->setMenuBar(menuBar);
        mainToolBar = new QToolBar(DolfinGui);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        DolfinGui->addToolBar(mainToolBar);
        centralWidget = new QWidget(DolfinGui);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        DolfinGui->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(DolfinGui);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        DolfinGui->setStatusBar(statusBar);

        retranslateUi(DolfinGui);

        QMetaObject::connectSlotsByName(DolfinGui);
    } // setupUi

    void retranslateUi(QMainWindow *DolfinGui)
    {
        DolfinGui->setWindowTitle(QApplication::translate("DolfinGui", "DolfinGui", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DolfinGui: public Ui_DolfinGui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOLFINGUI_H
