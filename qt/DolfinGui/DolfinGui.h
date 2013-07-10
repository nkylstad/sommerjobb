#ifndef DOLFINGUI_H
#define DOLFINGUI_H

#include "ui_dolfingui.h"
#include "GeometryInfo.h"
#include "CubeGeometry.h"
#include "ConeGeometry.h"
#include "SphereGeometry.h"
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


    void updateCube(CubeGeometry *cube);
    void updateCone(ConeGeometry *cone);
    void updateSphere(SphereGeometry *sphere);
    void updateGeometry(Geometry *geometry);

    bool cubeSelected;
    bool coneSelected;
    bool sphereSelected;
    
private slots:
    //void sphere();
    //void cube();
    //void cone();
    void domainEditor();
    void updatePlot();
    //void boundaryEditor();
    //void clear();
    void plotCube();
    void plotSphere();
    void plotCone();
    //void updateSphere();

private:
    Ui::DolfinGui *ui;
    void plotCube(CubeGeometry *cube);
    void plotCone(ConeGeometry *cone);
    void plotSphere(SphereGeometry *sphere);


    void createToolBar();
    void createActions();
    void createStartLayout();
    void connectPlotter();
    void updatePlotWindow();
    void addInfoBox(QGroupBox *box);
    QGroupBox* createCubeInfoBox();
    QGroupBox* createConeInfoBox();
    QGroupBox* createSphereInfoBox();

    const boost::shared_ptr<dolfin::CSGGeometry> generateGeometry(
           Geometry *geometry);

    const boost::shared_ptr<dolfin::CSGGeometry> generateCube(
           double *points, double *radius=0);

    const boost::shared_ptr<dolfin::CSGGeometry> generateCone(
            double *points, double *radius);

    const boost::shared_ptr<dolfin::CSGGeometry> generateSphere(
            double *points, double *radius);

    void plotGeometry();

    void createGeometry(Geometry *geometry);
    //void createStatusBar();
    //void renderDisplay();


    GeometryInfo *combinedGeometry;

    QWidget *plotWindow;
    QWidget *centralWindow;

    QRadioButton *newButton;
    QRadioButton *unionButton;
    QRadioButton *differenceButton;
    QRadioButton *intersectButton;

    QLineEdit *formulaBar;

    QAction *domainAction;
    QAction *boundaryAction;
    QAction *meshAction;
    QAction *exitAction;

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


    QGroupBox *geometryOperatorBox;
    QGroupBox *cubeInfoBox;
    QGroupBox *coneInfoBox;
    QGroupBox *sphereInfoBox;

    //QSplitter *bottomSplitter;
    QSplitter *mainSplitter;

    QToolBar *toolBar;
    QMenu *fileMenu;

    bool madePlot;

    bool domainInitialized;
    bool updateRequested;

};

#endif // DOLFINGUI_H
