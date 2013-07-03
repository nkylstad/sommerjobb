
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

}
//----------------------------------------------------------------------------
void DolfinGui::createStartLayout()
{
    plotWindow = new QWidget;
    window = new QWidget;
    setWindowTitle("DOLFIN Window");

    // Create bottom row of labels/buttons
    pixel_x_label = new CoordLabel("Pixel: (%d,%d)");
    cell_label    = new CoordLabel("Cell: %d");
    world_x_label = new CoordLabel("Coordinate: (%.2f,%.2f,%.2f)");
    toggle        = new QPushButton("Toggle mesh");

    unionButton = new QRadioButton;
    unionButton->setText("Union");

    differenceButton = new QRadioButton;
    differenceButton->setText(tr("Difference"));

    intersectButton = new QRadioButton;
    intersectButton->setText(tr("Intersection"));

    sublayout1 = new QHBoxLayout();
    sublayout1->addWidget(pixel_x_label);
    sublayout1->addWidget(cell_label);
    sublayout1->addWidget(world_x_label);
    sublayout1->addWidget(toggle);

    geometryOperatorBox = new QGroupBox;
    geometryOperatorBox->setObjectName("geometryOperatorBox");
    //geometryOperatorBox->setTitle(tr("Operators"));

    PythonQt::init();
    PythonQtObjectPtr mainModule = PythonQt::self()->getMainModule();
    mainModule.addObject("geometryOperatorBox", geometryOperatorBox);

    geometryBoxLayout = new QVBoxLayout();
    geometryBoxLayout->addWidget(unionButton);
    geometryBoxLayout->addWidget(differenceButton);
    geometryBoxLayout->addWidget(intersectButton);
    unionButton->setChecked(true);
    geometryOperatorBox->setLayout(geometryBoxLayout);
    geometryOperatorBox->setMaximumHeight(100);

    formulaBar = new QLineEdit;
    formulaBar->setText(tr("Type here..."));
    formulaBar->setObjectName("formulaBar");
    //formulaBar->grabKeyboard();
    updateButton = new QPushButton(tr("Update"));
    updateButton->setObjectName("updateButton");

    mainModule.addObject("formulaBar", formulaBar);
    mainModule.addObject("updateButton", updateButton);

    connect(formulaBar, SIGNAL(returnPressed()), updateButton, SIGNAL(clicked()));

    //mainModule.evalFile(":testing.py");

    formulaLayout = new QHBoxLayout();
    formulaLayout->addWidget(formulaBar);
    formulaLayout->addWidget(updateButton);

    // Create central plot layout (the plot window above the row of labels/buttons)
    plotLayout = new QVBoxLayout();
    plotLayout->addLayout(formulaLayout);
    plotLayout->addLayout(sublayout1);
    plotLayout->addWidget(plotWindow);

    cubePlot = new QPushButton(tr("Plot cube"));
    cubePlot->setMaximumSize(QSize(100,20));
    connect(cubePlot, SIGNAL(clicked()), this, SLOT(plotCube()));

    conePlot = new QPushButton(tr("Plot cone"));
    conePlot->setMaximumSize(QSize(100,20));
    connect(conePlot, SIGNAL(clicked()), this, SLOT(plotCone()));

    spherePlot = new QPushButton(tr("Plot sphere"));
    spherePlot->setMaximumSize(QSize(100,20));
    connect(spherePlot, SIGNAL(clicked()), this, SLOT(plotSphere()));

    sublayout2 = new QVBoxLayout();
    sublayout2->addWidget(geometryOperatorBox);
    sublayout2->addWidget(cubePlot);
    sublayout2->addWidget(conePlot);
    sublayout2->addWidget(spherePlot);

    centralLayout = new QHBoxLayout();
    centralLayout->addLayout(sublayout2);
    centralLayout->addLayout(plotLayout);

    window->setLayout(centralLayout);
    setCentralWidget(window);
    setMinimumSize(QSize(700,500));
}
//----------------------------------------------------------------------------
void DolfinGui::plotCube()
{
    // Create default cube:
    Box *box = new Box(0, 0, 0, 1, 1, 1);
    Cone *cone = new Cone(Point(0, 0, -1), Point(0, 0, 1), .5, .5);
    const boost::shared_ptr<CSGGeometry> g3d = boost::shared_ptr<CSGGeometry>(box);
    const boost::shared_ptr<CSGGeometry> newG3d = g3d + boost::shared_ptr<CSGGeometry>(cone);
    // Create plotter object:
    plotter = new Plotter(newG3d);
    updatePlot();
    plotter->plot(newG3d);
}
//----------------------------------------------------------------------------
void DolfinGui::updateCube(double x0, double x1, double x2,
                         double y0, double y1, double y2)
{
    Box *box = new Box(x0,x1,x2,y0,y1,y2);
    const boost::shared_ptr<CSGGeometry> g3d = boost::shared_ptr<CSGGeometry>(box);
    plotter->update();
    updatePlot();
    plotter->plot(g3d);
}
//----------------------------------------------------------------------------
void DolfinGui::plotCone()
{
    // Define default cone
    Cone *cone = new Cone(Point(0, 0, -1), Point(0, 0, 1), .1, .5);
    const boost::shared_ptr<CSGGeometry> g3d = boost::shared_ptr<CSGGeometry>(cone);
    plotter = new Plotter(g3d, this);
    updatePlot();
    plotter->plot();
    plotWindow->show();
}
//----------------------------------------------------------------------------
void DolfinGui::plotSphere()
{
    // Define default sphere
    Sphere *sphere = new Sphere(Point(0, 0, 0), 0.3);
    const boost::shared_ptr<CSGGeometry> g3d = boost::shared_ptr<CSGGeometry>(sphere);
    plotter = new Plotter(g3d, this);
    updatePlot();
    plotter->plot();
}
//----------------------------------------------------------------------------
void DolfinGui::updatePlot()
{
    plotLayout->removeWidget(plotWindow);
    plotWindow = plotter->get_widget();

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
void DolfinGui::createActions()
{
    domainAction = new QAction(tr("&Domain"), this);
    domainAction->setIcon(QIcon(":/images/domain.png"));
    domainAction->setStatusTip(tr("Create/edit domains"));
    //connect(domainAction, SIGNAL(triggered()), this, SLOT(domainEditor()));

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



DolfinGui::~DolfinGui()
{
    delete ui;
}
