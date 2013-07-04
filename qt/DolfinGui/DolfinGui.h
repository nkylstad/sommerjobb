#ifndef DOLFINGUI_H
#define DOLFINGUI_H

#include <QtGui>
#include "ui_dolfingui.h"
#include "CoordLabel.h"
#include "BoundaryMeshFunction.h"
#include "Plotter.h"
#include "GeometryInfo.h"
#include "Cube.h"
#include <dolfin.h>
#include <PythonQt/PythonQt.h>
#include <boost/lexical_cast.hpp>
#include <string>

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
    void domainEditor();
    //void boundaryEditor();
    //void clear();
    void plotCube();
    void plotSphere();
    void plotCone();
    void updatePlot();

private:
    Ui::DolfinGui *ui;
    void updateCube();
    void createToolBar();
    void createActions();
    void createStartLayout();
    void connectPlotter();
    void updatePlotWindow();
    void addInfoBox(QGroupBox *box);
    QGroupBox* createCubeInfoBox();

    const boost::shared_ptr<dolfin::CSGGeometry> generateCube(
           double *points);

    const boost::shared_ptr<dolfin::CSGGeometry> generateCone(
            double c00, double c01, double c02,
            double c10, double c11, double c12,
            double r0, double r1);

    const boost::shared_ptr<dolfin::CSGGeometry> generateSphere(
            double c0, double c1, double c2,
            double r);

    void plotGeometry(const boost::shared_ptr<dolfin::CSGGeometry> geometry);
    //void createStatusBar();
    //void renderDisplay();

    boost::shared_ptr<dolfin::CSGGeometry> g3d;

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
    QBoxLayout *infoLayout;

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
    QGroupBox *cubeInfoBox;

    //QSplitter *bottomSplitter;
    QSplitter *mainSplitter;

    QToolBar *toolBar;
    QMenu *fileMenu;

    bool madePlot;
    bool cubeSelected;
    bool domainInitialized;
    bool cubeInfoDisplayed;

};

#endif // DOLFINGUI_H
