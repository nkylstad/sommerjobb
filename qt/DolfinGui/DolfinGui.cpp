
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
    //PythonQt::init();
}
//----------------------------------------------------------------------------
void DolfinGui::createStartLayout()
{
    // Create plot window and central window
    plotWindow = new QWidget;
    centralWindow = new QWidget;
    setWindowTitle("DOLFIN Window");

    // Set up operator radio buttons
    newButton = new QRadioButton;
    newButton->setText(tr("New"));

    unionButton = new QRadioButton;
    unionButton->setText(tr("Union"));

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

    centralWindow->setLayout(centralLayout);
    setCentralWidget(centralWindow);
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
const boost::shared_ptr<dolfin::CSGGeometry> DolfinGui::generateGeometry(
       Geometry *geometry){
    std::cout <<"In method generateGeometry()" << std::endl;
    if (geometry->getMyType() == "Cube"){
    std::cout <<"Geometry type was cube!" << std::endl;
        return generateCube(geometry->getPoints());
    }
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
    std::cout << "plotGeometry()" << std::endl;
    boost::shared_ptr<CSGGeometry> g3d;
    for (auto geometry : combinedGeometry->getList())
        if (!g3d){
            g3d = geometry->getGeometryPointer();
        } else {
            if ((geometry->getMyOperator()) == "+")
                g3d = g3d + geometry->getGeometryPointer();
        }
        std::cout << "element in list" << std::endl;

    std::cout << "Hello" << std::endl;
    plotter->plot(g3d);
}
//----------------------------------------------------------------------------
void DolfinGui::createGeometry(Geometry *geometry)
{
    if (!(geometry->isCreated())){
        addInfoBox(geometry->createInfoBox());
        geometry->setSelected(true);

        if (newButton->isChecked()){
            combinedGeometry->getList().clear();
            combinedGeometry->setGeometryCount(0);
            geometry->setMyOperator("+");
        } else if (unionButton->isChecked()) {
            geometry->setMyOperator("+");
        } else if (differenceButton->isChecked()) {
            geometry->setMyOperator("-");
        } else if (intersectButton->isChecked()) {
            geometry->setMyOperator("*");
        }

        combinedGeometry->addGeometry(geometry);
        geometry->setMyIndex(combinedGeometry->getGeometryCount() - 1);
        std::cout << "My index: " << cube->getMyIndex() << std::endl;
    }

    geometry->setGeometryPointer(generateGeometry(geometry));

    plotGeometry();
}
//----------------------------------------------------------------------------
void DolfinGui::plotCube()
{
    CubeGeometry *cube = new CubeGeometry(this);
    if (newButton->isChecked()){
        combinedGeometry->getList().clear();
        combinedGeometry->setGeometryCount(0);
        cube->setMyOperator("+");
    } else if (unionButton->isChecked()){
        cube->setMyOperator("+");
    }
    combinedGeometry->addGeometry(cube);
    cube->setMyIndex(combinedGeometry->getGeometryCount() - 1);
    std::cout << "My index: " << cube->getMyIndex() << std::endl;

    for (int i=0; i<6; ++i){
        std::cout << i << ": " << cube->getPoints()[i] << std::endl;
    }

    plotGeometry(cube);
}
//----------------------------------------------------------------------------
void DolfinGui::plotCube(CubeGeometry *cube)
{
    std::cout << "plotCube(cube)" << std::endl;
    if (!(cube->isCreated())){
        double points[6] = {0.0, 0.0, 0.0, 1.0, 1.0, 1.0};
        cube->setPoints(points);
        addInfoBox(cube->createInfoBox());
        cube->setCreated(true);
    }

    cube->setGeometryPointer(generateCube(cube->getPoints()));

    plotGeometry();
}
//----------------------------------------------------------------------------
void DolfinGui::plotCone()
{
    ConeGeometry *cone = new ConeGeometry(this);
    if (newButton->isChecked()){
        combinedGeometry->getList().clear();
        combinedGeometry->setGeometryCount(0);
        cone->setMyOperator("+");
    }
    combinedGeometry->addGeometry(cone);
    cone->setMyIndex(combinedGeometry->getGeometryCount() - 1);
    plotCone(cone);
}
//----------------------------------------------------------------------------
void DolfinGui::plotCone(ConeGeometry *cone)
{


}
//----------------------------------------------------------------------------
void DolfinGui::plotSphere()
{

}
//----------------------------------------------------------------------------
void DolfinGui::plotSphere(SphereGeometry *sphere)
{

}
//----------------------------------------------------------------------------
void DolfinGui::updateGeometry(Geometry *geometry)
{
    // Use python script to obtain values in QLineEdit boxes
    PythonQt::init();
    PythonQtObjectPtr mainModule = PythonQt::self()->getMainModule();
    mainModule.addObject("infoBox", geometry->getInfoBox());
    double *points = new double[geometry->getPointCount()];
    double *radius = new double[geometry->getRadiusCount()];

    std::cout << "Points: " << std::endl;
    for (int i=0; i < geometry->getPointCount(); ++i){
        points[i] = mainModule.evalScript(QString("eval(infoBox.pointEdit%1.text)").arg(i),
                Py_eval_input).toDouble();
        std::cout << i << ": " << points[i] << std::endl;
    }

    if (geometry->getRadiusCount() > 0){
        for (int i=0; i < geometry->getRadiusCount(); ++i){
            radius[i] = mainModule.evalScript(QString("eval(infoBox.radiusEdit%1.text)").arg(i),
                                              Py_eval_input).toDouble();
        }
    }

    geometry->setPoints(points);
    geometry->setRadius(radius);
    geometry->setGeometryPointer(generateGeometry(geometry));

    std::cout << "Point count: " << geometry->getPointCount() << std::endl;
    plotGeometry();
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
    geometryBoxLayout->addWidget(newButton);
    geometryBoxLayout->addWidget(unionButton);
    geometryBoxLayout->addWidget(differenceButton);
    geometryBoxLayout->addWidget(intersectButton);
    differenceButton->setCheckable(false);
    intersectButton->setCheckable(false);
    newButton->setChecked(true);
    geometryOperatorBox->setLayout(geometryBoxLayout);
    geometryOperatorBox->setMaximumHeight(100);

    cubePlot = new QPushButton(tr("Plot cube"));
    cubePlot->setMaximumSize(QSize(100,20));
    connect(cubePlot, SIGNAL(clicked()), this, SLOT(updatePlot()));

    conePlot = new QPushButton(tr("Plot cone"));
    conePlot->setMaximumSize(QSize(100,20));
    conePlot->setEnabled(false);
    //connect(conePlot, SIGNAL(clicked()), this, SLOT(updatePlot());

    spherePlot = new QPushButton(tr("Plot sphere"));
    spherePlot->setMaximumSize(QSize(100,20));
    spherePlot->setEnabled(false);
    //connect(spherePlot, SIGNAL(clicked()), this, SLOT(updatePlot()));

    sublayout2->addWidget(geometryOperatorBox);
    sublayout2->addWidget(cubePlot);
    sublayout2->addWidget(conePlot);
    sublayout2->addWidget(spherePlot);

    formulaBar->setVisible(true);
    //updateButton->setVisible(true);
    // Create a default start geometry for the plotter
    Box *box = new Box(0,0,0,1,1,1);
    boost::shared_ptr<CSGGeometry> g3d = boost::shared_ptr<CSGGeometry>(box);

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
