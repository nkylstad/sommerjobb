#include "CubeGeometry.h"
#include "DolfinGui.h"

CubeGeometry::CubeGeometry(DolfinGui *ui)
{
    init(ui);
}
//----------------------------------------------------------------------------
void CubeGeometry::init(DolfinGui *ui)
{
    setPointCount(6);
    setRadiusCount(0);
    setDefaultValues();
    setCreated(false);
    setGuiWindow(ui);
    setMyType("Cube");

    for (int i=0; i<6; ++i){
        std::cout << i << ": " << getPoints()[i] << std::endl;
    }
}

void CubeGeometry::setDefaultValues()
{
    setPoints(new double[6]);
    getPoints()[0] = 0;
    getPoints()[1] = 0;
    getPoints()[2] = 0;
    getPoints()[3] = 1;
    getPoints()[4] = 1;
    getPoints()[5] = 1;
}

//----------------------------------------------------------------------------
QGroupBox *CubeGeometry::createInfoBox()
{
    infoBox = new QGroupBox;
    infoBox->setTitle(tr("Cube details"));
    infoBox->setObjectName(tr("infoBox"));

    QLabel *corner1 = new QLabel(tr("Corner 1"));
    QLabel *corner2 = new QLabel(tr("Corner 2"));
    QLabel *x0 = new QLabel(tr("x:"));
    QLabel *x1 = new QLabel(tr("x:"));
    QLabel *y0 = new QLabel(tr("y:"));
    QLabel *y1 = new QLabel(tr("y:"));
    QLabel *z0 = new QLabel(tr("z:"));
    QLabel *z1 = new QLabel(tr("z:"));

    pointEdit0 = new QLineEdit(infoBox);
    pointEdit1 = new QLineEdit(infoBox);
    pointEdit2 = new QLineEdit(infoBox);
    pointEdit3 = new QLineEdit(infoBox);
    pointEdit4 = new QLineEdit(infoBox);
    pointEdit5 = new QLineEdit(infoBox);

    pointEdit0->setObjectName("pointEdit0");
    pointEdit1->setObjectName("pointEdit1");
    pointEdit2->setObjectName("pointEdit2");
    pointEdit3->setObjectName("pointEdit3");
    pointEdit4->setObjectName("pointEdit4");
    pointEdit5->setObjectName("pointEdit5");

    x0->setBuddy(pointEdit0);
    y0->setBuddy(pointEdit1);
    z0->setBuddy(pointEdit2);
    x1->setBuddy(pointEdit3);
    y1->setBuddy(pointEdit4);
    z1->setBuddy(pointEdit5);

    updateInfoBox();


    QBoxLayout *topInfoLayout = new QHBoxLayout();
    QBoxLayout *bottomInfoLayout = new QHBoxLayout();

    topInfoLayout->addWidget(x0);
    topInfoLayout->addWidget(pointEdit0);
    topInfoLayout->addWidget(y0);
    topInfoLayout->addWidget(pointEdit1);
    topInfoLayout->addWidget(z0);
    topInfoLayout->addWidget(pointEdit2);

    bottomInfoLayout->addWidget(x1);
    bottomInfoLayout->addWidget(pointEdit3);
    bottomInfoLayout->addWidget(y1);
    bottomInfoLayout->addWidget(pointEdit4);
    bottomInfoLayout->addWidget(z1);
    bottomInfoLayout->addWidget(pointEdit5);

    QBoxLayout *cubeInfoLayout = new QVBoxLayout();
    cubeInfoLayout->addWidget(corner1);
    cubeInfoLayout->addLayout(topInfoLayout);
    cubeInfoLayout->addWidget(corner2);
    cubeInfoLayout->addLayout(bottomInfoLayout);

    QPushButton *updateButton = new QPushButton(tr("Update"));

    connect(updateButton, SIGNAL(clicked()), this, SLOT(updateClicked()));

    cubeInfoLayout->addWidget(updateButton);

    infoBox->setLayout(cubeInfoLayout);
    infoBox->setMaximumSize(QSize(200,200));

    return infoBox;
}

void CubeGeometry::updateInfoBox()
{
    pointEdit0->setText(QString::number(getPoints()[0]));
    pointEdit1->setText(QString::number(getPoints()[1]));
    pointEdit2->setText(QString::number(getPoints()[2]));
    pointEdit3->setText(QString::number(getPoints()[3]));
    pointEdit4->setText(QString::number(getPoints()[4]));
    pointEdit5->setText(QString::number(getPoints()[5]));
}

//----------------------------------------------------------------------------
void CubeGeometry::updateClicked()
{
    getGuiWindow()->updateGeometry(this);
}
