
#include "DolfinGui.h"


using namespace dolfin;

DolfinGui::DolfinGui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DolfinGui)
{
    // Set up the main window
    ui->setupUi(this);
    createActions();
    createToolBar();
    createStartLayout();
    domainInitialized = false;
    cubeInfoDisplayed = false;

}
//----------------------------------------------------------------------------
void DolfinGui::createStartLayout()
{
    plotWindow = new QWidget;
    window = new QWidget;
    setWindowTitle("DOLFIN Window");

    PythonQt::init();

    unionButton = new QRadioButton;
    unionButton->setText("Union");

    differenceButton = new QRadioButton;
    differenceButton->setText(tr("Difference"));

    intersectButton = new QRadioButton;
    intersectButton->setText(tr("Intersection"));

    sublayout1 = new QHBoxLayout();

    formulaBar = new QLineEdit;
    formulaBar->setText(tr("Type here..."));
    formulaBar->setObjectName("formulaBar");
    formulaBar->setVisible(false);
    //formulaBar->grabKeyboard();
    //updateButton = new QPushButton(tr("Update"));
    //updateButton->setObjectName("updateButton");
    //updateButton->setVisible(false);

    formulaLayout = new QHBoxLayout();
    formulaLayout->addWidget(formulaBar);
    //formulaLayout->addWidget(updateButton);

    // Create central plot layout (the plot window above the row of labels/buttons)
    plotLayout = new QVBoxLayout();
    plotLayout->addLayout(formulaLayout);
    plotLayout->addLayout(sublayout1);
    plotLayout->addWidget(plotWindow);

    sublayout2 = new QVBoxLayout();
    infoLayout = new QVBoxLayout();

    centralLayout = new QHBoxLayout();
    centralLayout->addLayout(sublayout2);
    centralLayout->addLayout(plotLayout);
    centralLayout->addLayout(infoLayout);

    window->setLayout(centralLayout);
    setCentralWidget(window);
    setMinimumSize(QSize(900,500));
}
//----------------------------------------------------------------------------
const boost::shared_ptr<CSGGeometry> DolfinGui::generateCube(double *points)
{
    Box *box = new Box(points[0],points[1],points[2],
            points[3],points[4],points[5]);
    return boost::shared_ptr<CSGGeometry>(box);
}
//----------------------------------------------------------------------------
const boost::shared_ptr<CSGGeometry> DolfinGui::generateCone(double c00, double c01, double c02,
                             double c10, double c11, double c12, double r0, double r1)
{
    Cone *cone = new Cone(Point(c00,c01,c02), Point(c10,c11,c12), r0, r1);
    return boost::shared_ptr<CSGGeometry>(cone);
}
//----------------------------------------------------------------------------
const boost::shared_ptr<CSGGeometry> DolfinGui::generateSphere(double c0, double c1, double c2,
                                                               double r)
{
    Sphere *sphere = new Sphere(Point(c0, c1, c2), r);
    return boost::shared_ptr<CSGGeometry>(sphere);
}
//----------------------------------------------------------------------------
void DolfinGui::plotCube()
{
    double points[6] = {0,0,0,1,1,1};
    g3d = generateCube(points);
    updatePlotWindow();
    plotter->plot(g3d);

    if (!cubeInfoDisplayed)
        cubeInfoBox = createCubeInfoBox();
        addInfoBox(cubeInfoBox);
        cubeInfoDisplayed = true;
}
//----------------------------------------------------------------------------
void DolfinGui::addInfoBox(QGroupBox *box)
{
    infoLayout->addWidget(box);
    centralLayout->update();
}
//----------------------------------------------------------------------------
QGroupBox* DolfinGui::createCubeInfoBox()
{
    QGroupBox *infoBox = new QGroupBox;
    infoBox->setTitle(tr("Cube details"));

    QLabel *corner1 = new QLabel(tr("First corner coordinates"));
    QLabel *corner2 = new QLabel(tr("Second corner coordinates"));
    QLabel *x0 = new QLabel(tr("x:"));
    QLabel *x1 = new QLabel(tr("x:"));
    QLabel *y0 = new QLabel(tr("y:"));
    QLabel *y1 = new QLabel(tr("y:"));
    QLabel *z0 = new QLabel(tr("z:"));
    QLabel *z1 = new QLabel(tr("z:"));

    QLineEdit *cubeEdit0 = new QLineEdit(infoBox);
    QLineEdit *cubeEdit1 = new QLineEdit(infoBox);
    QLineEdit *cubeEdit2 = new QLineEdit(infoBox);
    QLineEdit *cubeEdit3 = new QLineEdit(infoBox);
    QLineEdit *cubeEdit4 = new QLineEdit(infoBox);
    QLineEdit *cubeEdit5 = new QLineEdit(infoBox);

    cubeEdit0->setObjectName("cubeEdit0");
    cubeEdit1->setObjectName("cubeEdit1");
    cubeEdit2->setObjectName("cubeEdit2");
    cubeEdit3->setObjectName("cubeEdit3");
    cubeEdit4->setObjectName("cubeEdit4");
    cubeEdit5->setObjectName("cubeEdit5");

    x0->setBuddy(cubeEdit0);
    y0->setBuddy(cubeEdit1);
    z0->setBuddy(cubeEdit2);
    x1->setBuddy(cubeEdit3);
    y1->setBuddy(cubeEdit4);
    z1->setBuddy(cubeEdit5);

    cubeEdit0->setText("0.0");
    cubeEdit1->setText("0.0");
    cubeEdit2->setText("0.0");
    cubeEdit3->setText("1.0");
    cubeEdit4->setText("1.0");
    cubeEdit5->setText("1.0");

    QBoxLayout *topInfoLayout = new QHBoxLayout();
    QBoxLayout *bottomInfoLayout = new QHBoxLayout();

    topInfoLayout->addWidget(x0);
    topInfoLayout->addWidget(cubeEdit0);
    topInfoLayout->addWidget(y0);
    topInfoLayout->addWidget(cubeEdit1);
    topInfoLayout->addWidget(z0);
    topInfoLayout->addWidget(cubeEdit2);

    bottomInfoLayout->addWidget(x1);
    bottomInfoLayout->addWidget(cubeEdit3);
    bottomInfoLayout->addWidget(y1);
    bottomInfoLayout->addWidget(cubeEdit4);
    bottomInfoLayout->addWidget(z1);
    bottomInfoLayout->addWidget(cubeEdit5);

    QBoxLayout *cubeInfoLayout = new QVBoxLayout();
    cubeInfoLayout->addWidget(corner1);
    cubeInfoLayout->addLayout(topInfoLayout);
    cubeInfoLayout->addWidget(corner2);
    cubeInfoLayout->addLayout(bottomInfoLayout);

    updateButton = new QPushButton(tr("Update"));
    cubeSelected = true;
    connect(updateButton, SIGNAL(clicked()), this, SLOT(updatePlot()));

    cubeInfoLayout->addWidget(updateButton);

    infoBox->setLayout(cubeInfoLayout);
    infoBox->setMaximumSize(QSize(200,200));

    return infoBox;
}
//----------------------------------------------------------------------------
void DolfinGui::plotCone()
{
    g3d = generateCone(0,0,-1,0,0,1,0.1,0.5);
    updatePlotWindow();
    plotter->plot(g3d);

}
//----------------------------------------------------------------------------
void DolfinGui::plotSphere()
{
    g3d = generateSphere(0,0,0,0.3);
    updatePlotWindow();
    plotter->plot(g3d);
}
//----------------------------------------------------------------------------
void DolfinGui::updateCube()
{
    // Set up arrays to hold information about corner points
    /*GeometryInfo *cubeInfo = new GeometryInfo(6);
    double dataList[cubeInfo->getDataCount()];
    cubeInfo->setDataList(dataList);*/

    Cube *cubeGeometry = new Cube();
    double list[cubeGeometry->getPointCount()];
    cubeGeometry->setPoints(list);

    // Use python script to obtain values for corner points

    PythonQtObjectPtr mainModule = PythonQt::self()->getMainModule();
    //mainModule.addObject("cubeGeometry", cubeGeometry);

    mainModule.addObject("cubeInfoBox", cubeInfoBox);
    for (int i=0; i<cubeGeometry->getPointCount(); ++i)
        cubeGeometry->getPoints()[i] = mainModule.evalScript(QString("eval(cubeInfoBox.cubeEdit%1.text)").arg(i),
                                            Py_eval_input).toDouble();

    g3d = generateCube(cubeGeometry->getPoints());
    updatePlotWindow();
    plotter->plot(g3d);

}
//----------------------------------------------------------------------------
void DolfinGui::updatePlot()
{
    if (cubeSelected){
        updateCube();
    }
}
//----------------------------------------------------------------------------
void DolfinGui::updatePlotWindow()
{
    plotLayout->removeWidget(plotWindow);
    plotWindow = plotter->get_widget();
    //plotWindow->setMinimumSize(QSize(700,300));

    plotLayout->addWidget(plotWindow);
    connectPlotter();

    centralLayout->update();
}
//----------------------------------------------------------------------------
void DolfinGui::connectPlotter()
{

    QObject::connect(plotWindow, SIGNAL(mouseMoved(int,int)),
                     pixel_x_label, SLOT(setNum(int,int)));
    //connect(plotWindow, SIGNAL(mouseClick(int,int)),plotWindow, SLOT(grabKeyboard()));
    QObject::connect(plotter, SIGNAL(cellId(int)),
                     cell_label, SLOT(setNum(int)));
    QObject::connect(plotter, SIGNAL(worldPos(double,double,double)),
                     world_x_label, SLOT(setNum(double,double,double)));
    QObject::connect(toggle, SIGNAL(pressed()),
                     plotter, SLOT(toggleMesh()));

    // Connect the cell-pick signal to the plotted object and renderer
    //QObject::connect(plotter, SIGNAL(cellPicked(int)), &meshfunc, SLOT(toggleCell(int)));
    QObject::connect(plotter, SIGNAL(cellPicked(int)),
                     plotter, SLOT(update()));

}
//----------------------------------------------------------------------------
void DolfinGui::domainEditor()
{
    // Create bottom row of labels/buttons
    pixel_x_label = new CoordLabel("Pixel: (%d,%d)");
    cell_label    = new CoordLabel("Cell: %d");
    world_x_label = new CoordLabel("Coordinate: (%.2f,%.2f,%.2f)");
    toggle        = new QPushButton("Toggle mesh");

    // Add mesh button and labels
    sublayout1->addWidget(pixel_x_label);
    sublayout1->addWidget(cell_label);
    sublayout1->addWidget(world_x_label);
    sublayout1->addWidget(toggle);

    // Add domain layout
    geometryOperatorBox = new QGroupBox;
    geometryOperatorBox->setObjectName("geometryOperatorBox");
    geometryOperatorBox->setTitle(tr("Operators"));

    geometryBoxLayout = new QVBoxLayout();
    geometryBoxLayout->addWidget(unionButton);
    geometryBoxLayout->addWidget(differenceButton);
    geometryBoxLayout->addWidget(intersectButton);
    unionButton->setChecked(true);
    geometryOperatorBox->setLayout(geometryBoxLayout);
    geometryOperatorBox->setMaximumHeight(100);

    cubePlot = new QPushButton(tr("Plot cube"));
    cubePlot->setMaximumSize(QSize(100,20));
    connect(cubePlot, SIGNAL(clicked()), this, SLOT(plotCube()));

    conePlot = new QPushButton(tr("Plot cone"));
    conePlot->setMaximumSize(QSize(100,20));
    connect(conePlot, SIGNAL(clicked()), this, SLOT(plotCone()));

    spherePlot = new QPushButton(tr("Plot sphere"));
    spherePlot->setMaximumSize(QSize(100,20));
    connect(spherePlot, SIGNAL(clicked()), this, SLOT(plotSphere()));

    sublayout2->addWidget(geometryOperatorBox);
    sublayout2->addWidget(cubePlot);
    sublayout2->addWidget(conePlot);
    sublayout2->addWidget(spherePlot);

    formulaBar->setVisible(true);
    //updateButton->setVisible(true);
    // Create a default start geometry for the plotter
    Box *box = new Box(0,0,0,1,1,1);
    const boost::shared_ptr<CSGGeometry> g3d = boost::shared_ptr<CSGGeometry>(box);

    // Create plotter:
    plotter = new Plotter(g3d);
    updatePlotWindow();
    plotter->plot();
    madePlot=false; // set to true when an actual plot is generated.
}
//----------------------------------------------------------------------------
void DolfinGui::createActions()
{
    domainAction = new QAction(tr("&Domain"), this);
    domainAction->setIcon(QIcon(":/images/domain.png"));
    domainAction->setStatusTip(tr("Create/edit domains"));
    connect(domainAction, SIGNAL(triggered()), this, SLOT(domainEditor()));

    boundaryAction = new QAction(tr("Boundary"), this);
    boundaryAction->setIcon(QIcon(":/images/boundary.png"));
    boundaryAction->setStatusTip(tr("Define/mark boundary"));
    //connect(boundaryAction, SIGNAL(triggered()), this, SLOT(boundaryEditor()));

    meshAction = new QAction(tr("Mesh"), this);
    meshAction->setIcon(QIcon(":/images/mesh.png"));
    meshAction->setStatusTip(tr("Create mesh"));

    exitAction = new QAction(tr("Exit"), this);
    exitAction->setIcon(QIcon(":/images/exit.png"));
    exitAction->setStatusTip(tr("Exit the program"));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));
}
//----------------------------------------------------------------------------
void DolfinGui::createToolBar()
{
    toolBar = addToolBar(tr("&Tools"));
    toolBar->addAction(domainAction);
    toolBar->addAction(boundaryAction);
    toolBar->addAction(meshAction);
    toolBar->addSeparator();
    toolBar->addAction(exitAction);
    toolBar->setIconSize(QSize(40,40));
}
//----------------------------------------------------------------------------
DolfinGui::~DolfinGui()
{
    delete ui;
}
