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
}
//--------------------------------------------------
void SphereGeometry::createInfoBox()
{
    infoBox = new QGroupBox;
    infoBox->setTitle(tr("Sphere details"));

    QLabel *center1 = new QLabel(tr("Centre"));
    QLabel *r0 = new QLabel(tr("r:"));
    QLabel *x0 = new QLabel(tr("x:"));
    QLabel *y0 = new QLabel(tr("y:"));
    QLabel *z0 = new QLabel(tr("z:"));

    QLineEdit *sphereEdit0 = new QLineEdit(infoBox);
    QLineEdit *sphereEdit1 = new QLineEdit(infoBox);
    QLineEdit *sphereEdit2 = new QLineEdit(infoBox);
    QLineEdit *radiusEdit0 = new QLineEdit(infoBox);

    sphereEdit0->setObjectName("sphereEdit0");
    sphereEdit1->setObjectName("sphereEdit1");
    sphereEdit2->setObjectName("sphereEdit2");
    radiusEdit0->setObjectName("radiusEdit0");

    x0->setBuddy(sphereEdit0);
    y0->setBuddy(sphereEdit1);
    z0->setBuddy(sphereEdit2);
    r0->setBuddy(radiusEdit0);

    sphereEdit0->setText("0.0");
    sphereEdit1->setText("0.0");
    sphereEdit2->setText("-1.0");
    radiusEdit0->setText("0.5");

    QBoxLayout *topInfoLayout = new QVBoxLayout();

    topInfoLayout->addWidget(center1);
    topInfoLayout->addWidget(x0);
    topInfoLayout->addWidget(sphereEdit0);
    topInfoLayout->addWidget(y0);
    topInfoLayout->addWidget(sphereEdit1);
    topInfoLayout->addWidget(z0);
    topInfoLayout->addWidget(sphereEdit2);
    topInfoLayout->addWidget(r0);
    topInfoLayout->addWidget(radiusEdit0);

    QBoxLayout *sphereInfoLayout = new QHBoxLayout();
    sphereInfoLayout->addLayout(topInfoLayout);

    QPushButton *updateButton = new QPushButton(tr("Update"));
    connect(updateButton, SIGNAL(clicked()), this, SLOT(updateClicked()));

    sphereInfoLayout->addWidget(updateButton);

    infoBox->setLayout(sphereInfoLayout);
    infoBox->setMaximumSize(QSize(200,250));
}
//--------------------------------------------------
void SphereGeometry::updateClicked()
{
    getGuiWindow()->updateSphere(this);
    //getGuiWindow()->sphereSelected = true;
}
