#include "SphereGeometry.h"
#include "DolfinGui.h"

SphereGeometry::SphereGeometry(DolfinGui *ui)
{
    init(ui);
}
//--------------------------------------------------
void SphereGeometry::init(DolfinGui *ui)
{
    setPointCount(3);
    setRadiusCount(1);
    setCreated(false);
    setGuiWindow(ui);
    setMyType("Sphere");
}
//--------------------------------------------------
void SphereGeometry::setDefaultValues(){
    //Implement later
}
//--------------------------------------------------
QGroupBox *SphereGeometry::createInfoBox()
{
    infoBox = new QGroupBox;
    infoBox->setTitle(tr("Sphere details"));
    infoBox->setObjectName(tr("infoBox"));

    QLabel *center1 = new QLabel(tr("Centre"));
    QLabel *r0 = new QLabel(tr("r:"));
    QLabel *x0 = new QLabel(tr("x:"));
    QLabel *y0 = new QLabel(tr("y:"));
    QLabel *z0 = new QLabel(tr("z:"));

    pointEdit0 = new QLineEdit(infoBox);
    pointEdit1 = new QLineEdit(infoBox);
    pointEdit2 = new QLineEdit(infoBox);
    radiusEdit0 = new QLineEdit(infoBox);

    pointEdit0->setObjectName("pointEdit0");
    pointEdit1->setObjectName("pointEdit1");
    pointEdit2->setObjectName("pointEdit2");
    radiusEdit0->setObjectName("radiusEdit0");

    x0->setBuddy(pointEdit0);
    y0->setBuddy(pointEdit1);
    z0->setBuddy(pointEdit2);
    r0->setBuddy(radiusEdit0);

    updateInfoBox();

    QBoxLayout *topInfoLayout = new QVBoxLayout();

    topInfoLayout->addWidget(center1);
    topInfoLayout->addWidget(x0);
    topInfoLayout->addWidget(pointEdit0);
    topInfoLayout->addWidget(y0);
    topInfoLayout->addWidget(pointEdit1);
    topInfoLayout->addWidget(z0);
    topInfoLayout->addWidget(pointEdit2);
    topInfoLayout->addWidget(r0);
    topInfoLayout->addWidget(radiusEdit0);

    QBoxLayout *sphereInfoLayout = new QHBoxLayout();
    sphereInfoLayout->addLayout(topInfoLayout);

    QPushButton *updateButton = new QPushButton(tr("Update"));
    connect(updateButton, SIGNAL(clicked()), this, SLOT(updateClicked()));

    sphereInfoLayout->addWidget(updateButton);

    infoBox->setLayout(sphereInfoLayout);
    infoBox->setMaximumSize(QSize(200,250));

    return infoBox;
}

void SphereGeometry::updateInfoBox()
{
    pointEdit0->setText("0.0");
    pointEdit1->setText("0.0");
    pointEdit2->setText("-1.0");
    radiusEdit0->setText("0.5");
}

//--------------------------------------------------
void SphereGeometry::updateClicked()
{
    getGuiWindow()->updateSphere(this);
    //getGuiWindow()->sphereSelected = true;
}
