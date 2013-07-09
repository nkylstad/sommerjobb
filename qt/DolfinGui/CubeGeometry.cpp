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
    setCreated(false);
    setGuiWindow(ui);
    setPoints(new double[6]);
}
//----------------------------------------------------------------------------
void CubeGeometry::createInfoBox()
{
    infoBox = new QGroupBox;
    infoBox->setTitle(tr("Cube details"));

    QLabel *corner1 = new QLabel(tr("Corner 1"));
    QLabel *corner2 = new QLabel(tr("Corner 2"));
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

    cubeEdit0->setText(QString::number(getPoints()[0]));
    cubeEdit1->setText(QString::number(getPoints()[1]));
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

    QPushButton *updateButton = new QPushButton(tr("Update"));

    connect(updateButton, SIGNAL(clicked()), this, SLOT(updateClicked()));

    cubeInfoLayout->addWidget(updateButton);

    infoBox->setLayout(cubeInfoLayout);
    infoBox->setMaximumSize(QSize(200,200));
}
//----------------------------------------------------------------------------
void CubeGeometry::updateClicked()
{
    getGuiWindow()->updateCube(this);
}
