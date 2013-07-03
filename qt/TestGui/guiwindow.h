#ifndef GUIWINDOW_H
#define GUIWINDOW_H

#include <vtkSmartPointer.h>

#include <QMainWindow>
#include <QVTKWidget.h>

#include "ui_guiwindow.h"

#define VTK_CREATE(type, name) \
  vtkSmartPointer<type> name = vtkSmartPointer<type>::New()

namespace Ui {
class GuiWindow;
}

class QPushButton;
class QTextEdit;
class QToolBar;
class QAction;
class QSplitter;
class QFrame;
class QStatusBar;
class QVBoxLayout;
class QRadioButton;
class QLabel;

class GuiWindow : public QMainWindow, private Ui::GuiWindow
{
    Q_OBJECT
    
public:
    explicit GuiWindow(QWidget *parent = 0);
    ~GuiWindow();
    

private slots:
    void sphere();
    void cube();
    void cone();
    void domainEditor();
    void boundaryEditor();
    void clear();

private:
    Ui::GuiWindow *ui;

    void createToolBar();
    void createActions();
    void createStatusBar();
    void renderDisplay();

    QVTKWidget *qvtkWidget;

    QAction *domainAction;
    QAction *boundaryAction;
    QAction *meshAction;
    QAction *exitAction;

    QAction *sphereAction;
    QAction *cubeAction;

    QLabel *boundaryTypeLabel;

    QFrame *buttonFrame;
    QVBoxLayout *boundaryTypeLayout;
    QVBoxLayout *buttonLayout;
    QPushButton *sphereButton;
    QPushButton *cubeButton;
    QPushButton *coneButton;
    QPushButton *squareButton;
    QPushButton *clearButton;

    QRadioButton *dirichletButton;
    QRadioButton *neumannButton;

    QSplitter *bottomSplitter;
    QSplitter *mainSplitter;

    QToolBar *toolBar;
};

#endif // GUIWINDOW_H
