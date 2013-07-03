#include <QtGui>

#include "guiwindow.h"
#include <vtkDataObjectToTable.h>
#include <vtkElevationFilter.h>
#include <vtkPolyDataMapper.h>
#include <vtkQtTableView.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkSphereSource.h>
#include <vtkCubeSource.h>
#include <vtkConeSource.h>
#include <vtkSmartPointer.h>
#include <QVTKWidget.h>

#define VTK_CREATE(type, name) \
  vtkSmartPointer<type> name = vtkSmartPointer<type>::New()


GuiWindow::GuiWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GuiWindow)
{
    // Set up the main window
    ui->setupUi(this);
    createActions();
    createToolBar();
    createStatusBar();

   // Set up Qt widget for VTK window
    qvtkWidget = new QVTKWidget;
    vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
    qvtkWidget->GetRenderWindow()->AddRenderer(renderer);
    qvtkWidget->GetRenderWindow()->Render(); done.

    // Set up layout
    buttonFrame = new QFrame;
    buttonFrame->setMaximumSize(QSize(200,123456));
    buttonFrame->setFrameStyle(QFrame::Box);
    buttonFrame->setLineWidth(2);

    mainSplitter = new QSplitter(Qt::Horizontal);
    mainSplitter->addWidget(buttonFrame);
    mainSplitter->addWidget(qvtkWidget);

    setCentralWidget(mainSplitter);
    setMinimumSize(QSize(1000,700));
    setWindowIcon(QIcon(":/images/fenics_banner.png"));
  }


void GuiWindow::createActions()
{
    domainAction = new QAction(tr("&Domain"), this);
    domainAction->setIcon(QIcon(":/images/domain.png"));
    domainAction->setStatusTip(tr("Create/edit domains"));
    connect(domainAction, SIGNAL(triggered()), this, SLOT(domainEditor()));

    boundaryAction = new QAction(tr("Boundary"), this);
    boundaryAction->setIcon(QIcon(":/images/boundary.png"));
    boundaryAction->setStatusTip(tr("Define/mark boundary"));
    connect(boundaryAction, SIGNAL(triggered()), this, SLOT(boundaryEditor()));

    meshAction = new QAction(tr("Mesh"), this);
    meshAction->setIcon(QIcon(":/images/mesh.png"));
    meshAction->setStatusTip(tr("Create mesh"));

    exitAction = new QAction(tr("Exit"), this);
    exitAction->setIcon(QIcon(":/images/exit.png"));
    exitAction->setStatusTip(tr("Exit the program"));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));
}



void GuiWindow::createToolBar()
{
    toolBar = addToolBar(tr("&Tools"));
    toolBar->addAction(domainAction);
    toolBar->addAction(boundaryAction);
    toolBar->addAction(meshAction);
    toolBar->addSeparator();
    toolBar->addAction(exitAction);
    toolBar->setIconSize(QSize(40,40));
}


void GuiWindow::createStatusBar()
{
    QMainWindow::statusBar()->showMessage(tr("Welcome!"));
}


void GuiWindow::domainEditor()
{

    // Set up simple geometries using VTK
    sphereButton = new QPushButton;
    sphereButton->setText(tr("Sphere"));
    sphereButton->setMinimumSize(QSize(60,60));
    sphereButton->setStatusTip(tr("Create sphere geometry"));
    connect(sphereButton, SIGNAL(clicked()), this, SLOT(sphere()));

    cubeButton = new QPushButton;
    cubeButton->setText(tr("Cube"));
    cubeButton->setMinimumSize(QSize(60,60));
    cubeButton->setStatusTip(tr("Create cube geometry"));
    connect(cubeButton, SIGNAL(clicked()), this, SLOT(cube()));

    coneButton = new QPushButton;
    coneButton->setText(tr("Cone"));
    coneButton->setMinimumSize(QSize(60,60));
    coneButton->setStatusTip(tr("Create cone geometry"));
    connect(coneButton, SIGNAL(clicked()), this, SLOT(cone()));

    clearButton = new QPushButton;
    clearButton->setText(tr("Clear"));
    clearButton->setMinimumSize(QSize(60,60));
    clearButton->setStatusTip(tr("Clear all geometries"));
    connect(clearButton, SIGNAL(clicked()), this, SLOT(clear()));

    QVBoxLayout *buttonLayout = new QVBoxLayout();
    buttonLayout->addWidget(sphereButton);
    buttonLayout->addWidget(cubeButton);
    buttonLayout->addWidget(coneButton);
    buttonLayout->addWidget(clearButton);

    buttonFrame->setLayout(buttonLayout);
    buttonFrame->show();

}

void GuiWindow::boundaryEditor()
{
    boundaryTypeLayout = new QVBoxLayout();

    boundaryTypeLabel = new QLabel;
    boundaryTypeLabel->setText(tr("Select type of BC"));

    dirichletButton = new QRadioButton;
    dirichletButton->setText(tr("Dirichlet"));

    neumannButton = new QRadioButton;
    neumannButton->setText(tr("Neumann"));

    boundaryTypeLayout->addWidget(boundaryTypeLabel);
    boundaryTypeLayout->addWidget(dirichletButton);
    boundaryTypeLayout->addWidget(neumannButton);
    //boundaryTypeLayout->SetMaximumSize(QSize(200,100));
    boundaryTypeLayout->setAlignment(Qt::AlignTop);
}

void GuiWindow::clear()
{
    vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
    renderer->Clear();
    qvtkWidget->GetRenderWindow()->AddRenderer(renderer);
    qvtkWidget->GetRenderWindow()->Render();

    QMainWindow::statusBar()->showMessage(tr("No geometry selected."));
}


void GuiWindow::sphere()
{

    vtkSmartPointer<vtkSphereSource> sphereSource = vtkSmartPointer<vtkSphereSource>::New();
    sphereSource->SetThetaResolution(30);
    sphereSource->SetPhiResolution(30);
    sphereSource->Update();
    vtkSmartPointer<vtkPolyDataMapper> sphereMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    sphereMapper->SetInputConnection(sphereSource->GetOutputPort());
    vtkSmartPointer<vtkActor> sphereActor = vtkSmartPointer<vtkActor>::New();
    sphereActor->SetMapper(sphereMapper);

    vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
    renderer->AddActor(sphereActor);
    qvtkWidget->GetRenderWindow()->AddRenderer(renderer);
    qvtkWidget->GetRenderWindow()->Render();

    QMainWindow::statusBar()->showMessage(tr("Sphere geometry. Scroll to zoom."));
}

void GuiWindow::cube()
{
    vtkSmartPointer<vtkCubeSource> cubeSource =
        vtkSmartPointer<vtkCubeSource>::New();
    cubeSource->Update();
    vtkSmartPointer<vtkPolyDataMapper> cubeMapper =
        vtkSmartPointer<vtkPolyDataMapper>::New();
    cubeMapper->SetInputConnection(cubeSource->GetOutputPort());
    vtkSmartPointer<vtkActor> cubeActor =
        vtkSmartPointer<vtkActor>::New();
    cubeActor->SetMapper(cubeMapper);

    vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
    renderer->AddActor(cubeActor);
    qvtkWidget->GetRenderWindow()->AddRenderer(renderer);
    qvtkWidget->GetRenderWindow()->Render();

    QMainWindow::statusBar()->showMessage(tr("Cube geometry. Scroll to zoom."));
}


void GuiWindow::cone()
{
    vtkSmartPointer<vtkConeSource> coneSource =
        vtkSmartPointer<vtkConeSource>::New();
    coneSource->SetResolution(30);
    coneSource->Update();
    vtkSmartPointer<vtkPolyDataMapper> coneMapper =
        vtkSmartPointer<vtkPolyDataMapper>::New();
    coneMapper->SetInputConnection(coneSource->GetOutputPort());
    vtkSmartPointer<vtkActor> coneActor =
        vtkSmartPointer<vtkActor>::New();
    coneActor->SetMapper(coneMapper);

    vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
    renderer->AddActor(coneActor);
    qvtkWidget->GetRenderWindow()->AddRenderer(renderer);
    qvtkWidget->GetRenderWindow()->Render();

    QMainWindow::statusBar()->showMessage(tr("Cone geometry. Scroll to zoom."));
}




GuiWindow::~GuiWindow()
{

    delete ui;
    delete qvtkWidget;
}

