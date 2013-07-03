#ifndef DOLFINGUI_H
#define DOLFINGUI_H

#include <QtGui>
#include "ui_dolfingui.h"
#include "CoordLabel.h"
#include "BoundaryMeshFunction.h"
#include "Plotter.h"
#include <dolfin.h>
#include <PythonQt/PythonQt.h>

namespace Ui {
class DolfinGui;
}

class DolfinGui : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit DolfinGui(QWidget *parent = 0);
    ~DolfinGui();

    
private slots:
    //void sphere();
    //void cube();
    //void cone();
    //void domainEditor();
    //void boundaryEditor();
    //void clear();
    void plotCube();
    void plotSphere();
    void plotCone();
    void updatePlot();

private:
    Ui::DolfinGui *ui;
    void updateCube(double x0, double x1, double x2,
                  double y0, double y1, double y2);
    void createToolBar();
    void createActions();
    void createStartLayout();
    void updateLayout();
    void connectPlotter();

    void plotGeometry(const boost::shared_ptr<dolfin::CSGGeometry> geometry);
    //void createStatusBar();
    //void renderDisplay();

    QWidget *plotWindow;
    QWidget *window;

    QLineEdit *formulaBar;

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
    QBoxLayout *plotLayout;
    QBoxLayout *formulaLayout;
    QBoxLayout *sublayout1;
    QBoxLayout *geometryBoxLayout;
    QBoxLayout *sublayout2;
    QBoxLayout *centralLayout;

    Plotter *plotter;
    QPushButton *cubePlot;
    QPushButton *conePlot;
    QPushButton *spherePlot;
    QPushButton *updateButton;

    CoordLabel *pixel_x_label;
    CoordLabel *cell_label;
    CoordLabel *world_x_label;
    QPushButton *toggle;

    QRadioButton *unionButton;
    QRadioButton *differenceButton;
    QRadioButton *intersectButton;

    QGroupBox *geometryOperatorBox;

    //QSplitter *bottomSplitter;
    QSplitter *mainSplitter;

    QToolBar *toolBar;
    QMenu *fileMenu;

};

#endif // DOLFINGUI_H
