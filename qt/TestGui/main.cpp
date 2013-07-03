#include "guiwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QtGui>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    GuiWindow mainWindow;

    mainWindow.show();
    return app.exec();

}
