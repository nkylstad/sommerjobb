
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
    cubeSelected = false;
    coneSelected = false;
    sphereSelected = false;
    updateRequested = false;
    combinedGeometry = new GeometryInfo();
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
const boost::shared_ptr<dolfin::CSGGeometry> DolfinGui::generateCube(double *points,
                                                                     double *radius)
{
    // Use CSG primitive Box
    Box *box = new Box(points[0],points[1],points[2],
            points[3],points[4],points[5]);
    return boost::shared_ptr<CSGGeometry>(box);
}
//----------------------------------------------------------------------------
const boost::shared_ptr<CSGGeometry> DolfinGui::generateCone(double *points,
                                                             double *radius)
{
    // Use CSG primitive Cone
    Cone *cone = new Cone(Point(points[0],points[1],points[2]),
            Point(points[3],points[4],points[5]), radius[0], radius[1]);
    return boost::shared_ptr<CSGGeometry>(cone);
}
//----------------------------------------------------------------------------
const boost::shared_ptr<CSGGeometry> DolfinGui::generateSphere(double *points,
                                                               double *radius)
{
    // Use CSG primitive Sphere
    Sphere *sphere = new Sphere(Point(points[0], points[1], points[2]),
            radius[0]);
    return boost::shared_ptr<CSGGeometry>(sphere);
}
//----------------------------------------------------------------------------
void DolfinGui::addInfoBox(QGroupBox *box)
{
    infoLayout->addWidget(box);
    centralLayout->update();
}
//----------------------------------------------------------------------------
void DolfinGui::plotGeometry()
{
    if (!updateRequested) {
        for (auto geometry : combinedGeometry->getList())
            g3d = g3d + geometry->getGeometryPointer();
    } else {

    //g3d = g3d + (* combinedGeometry->getList().begin())->getGeometryPointer();
    plotter->plot(g3d);
    updateRequested = false;
}
//----------------------------------------------------------------------------
void DolfinGui::plotCube()
{
    CubeGeometry *cube = new CubeGeometry(this);
    plotCube(cube);
}
//----------------------------------------------------------------------------
void DolfinGui::plotCube(CubeGeometry *cube)
{
    if (!(cube->isCreated())) {
        // Create default cube
        //double points[6] = {0,0,0,1,1,1};
        //cube->setPoints(points);
        cube->getPoints()[0] = 0;
        cube->getPoints()[1] = 0;
        cube->getPoints()[2] = 0;
        cube->getPoints()[3] = 1;
        cube->getPoints()[4] = 1;
        cube->getPoints()[5] = 1;
        cube->createInfoBox();
        addInfoBox(cube->getInfoBox());
        cube->setCreated(true);
    }
    cube->setGeometryPointer(generateCube(cube->getPoints()));
    combinedGeometry->addGeometry(cube);

    //g3d = cube->getGeometryPointer();
    updatePlotWindow();
    plotGeometry();
    //plotter->plot(g3d);
}
//----------------------------------------------------------------------------
void DolfinGui::plotCone()
{
    ConeGeometry *cone = new ConeGeometry(this);
    plotCone(cone);
}
//----------------------------------------------------------------------------
void DolfinGui::plotCone(ConeGeometry *cone)
{
    if (!cone->isCreated()){
        std::cout << "Creating new cone" << std::endl;
        double points[6] = {0, 0, -1, 0, 0, 1};
        double radius[2] = {0.5, 0.5};
        cone->setPoints(points);
        cone->setRadius(radius);
        cone->createInfoBox();
        addInfoBox(cone->getInfoBox());
        cone->setCreated(true);
    }
    cone->setGeometryPointer(generateCone(cone->getPoints(), cone->getRadius()));
    //g3d = generateCone(cone->getPoints(), cone->getRadius());
    updatePlotWindow();
    plotter->plot(generateCone(cone->getPoints(), cone->getRadius()));

}
//----------------------------------------------------------------------------
void DolfinGui::plotSphere()
{
    SphereGeometry *sphere = new SphereGeometry(this);
    plotSphere(sphere);
}
//----------------------------------------------------------------------------
void DolfinGui::plotSphere(SphereGeometry *sphere)
{
    if (!sphere->isCreated()){
        int p = sphere->getPointCount();
        int r = sphere->getRadiusCount();
        double points[3] = {0.0, 0.0, 0.0};
        double radius[1] = {0.5};
        sphere->setPoints(points);
        sphere->setRadius(radius);
        sphere->createInfoBox();
        addInfoBox(sphere->getInfoBox());
        sphere->setCreated(true);
    }

    sphere->setGeometryPointer(generateSphere(sphere->getPoints(), sphere->getRadius()));
    g3d = generateSphere(sphere->getPoints(), sphere->getRadius());
    plotter->plot(g3d);
}
//----------------------------------------------------------------------------
void DolfinGui::updateCube(CubeGeometry *cube)
{
    // Set up arrays to hold information about corner points
    //GeometryInfo *cubeInfo = new GeometryInfo(6);
    //double dataList[cube->getPointCount()];
    //cube->setPoints(dataList);

    updateRequested = true;
    std::cout << "In method updateCube(): \n";
    std::cout << "-------- HELLO!!! --------" << std::endl;
    //for (int i=0; i<6; ++i)
    //    std::cout << cube->getPoints()[i] << " " << std::endl;

    // Use python script to obtain new values for corner points
    PythonQtObjectPtr mainModule = PythonQt::self()->getMainModule();
    mainModule.addObject("cubeInfoBox", cube->getInfoBox());
    for (int i=0; i<cube->getPointCount(); ++i){
        cube->getPoints()[i] = mainModule.evalScript(QString("eval(cubeInfoBox.cubeEdit%1.text)").arg(i),
                                            Py_eval_input).toDouble();

    }
    plotCube(cube);
    cubeSelected = false;
}
//----------------------------------------------------------------------------
void DolfinGui::updateCone(ConeGeometry *cone){

    std::cout << "In method updateCone(): \n";
    std::cout << "-------- HELLO!!! --------" << std::endl;

    for (int i=0; i<6; ++i)
        std::cout << cone->getPoints()[i] << " " << std::endl;

    // Use python script to obtain values for corner points
    PythonQtObjectPtr mainModule = PythonQt::self()->getMainModule();
    mainModule.addObject("coneInfoBox", cone->getInfoBox());
    for (int i=0; i<cone->getPointCount(); ++i)
        cone->getPoints()[i] = mainModule.evalScript(QString("eval(coneInfoBox.coneEdit%1.text)").arg(i),
                                            Py_eval_input).toDouble();

    // Use python script to obtain values for radius
    for (int i=0; i<cone->getRadiusCount(); ++i)
        cone->getRadius()[i] = mainModule.evalScript(QString("eval(coneInfoBox.radiusEdit%1.text)").arg(i),
                                            Py_eval_input).toDouble();

    plotCone(cone);
    std::cout << "Ferdig" << std::endl;
    //coneSelected = false;
}
//----------------------------------------------------------------------------
void DolfinGui::updateSphere(SphereGeometry *sphere){

    std::cout << "In method updateSphere(): \n";
    std::cout << "-------- HELLO!!! --------" << std::endl;

    // Use python script to obtain values for corner points
    PythonQtObjectPtr mainModule = PythonQt::self()->getMainModule();
    mainModule.addObject("sphereInfoBox", sphere->getInfoBox());
    for (int i=0; i<sphere->getPointCount(); ++i)
        sphere->getPoints()[i] = mainModule.evalScript(QString("eval(sphereInfoBox.sphereEdit%1.text)").arg(i),
                                            Py_eval_input).toDouble();

    // Use python script to obtain values for radius
    for (int i=0; i<sphere->getRadiusCount(); ++i)
        sphere->getRadius()[i] = mainModule.evalScript(QString("eval(sphereInfoBox.radiusEdit%1.text)").arg(i),
                                            Py_eval_input).toDouble();

    plotSphere(sphere);
    sphereSelected = false;
}
//----------------------------------------------------------------------------
void DolfinGui::updatePlot()
{
    std::cout << "In method updatePlot(): \n";
    std::cout << "-------- HELLO!!! --------" << std::endl;
    if (cubeSelected){
        std::cout << "Cube is selected\n";
        //updateCube();
    } else if (coneSelected){
        std::cout << "Cone is selected\n";
        //updateCone();
    } else if (sphereSelected){
        std::cout << "Sphere is selected\n";
        //updateSphere();
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
    g3d = boost::shared_ptr<CSGGeometry>(box);

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
