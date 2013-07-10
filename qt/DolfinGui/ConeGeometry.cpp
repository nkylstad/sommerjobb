#include "ConeGeometry.h"
#include "DolfinGui.h"

ConeGeometry::ConeGeometry(DolfinGui *ui)
{
    init(ui);
}
//-------------------------------------------------------------
void ConeGeometry::init(DolfinGui *ui)
{
    setPointCount(6);
    setRadiusCount(2);
    setCreated(false);
    setGuiWindow(ui);
    setPoints(new double[getPointCount()]);
    setPoints(new double[getRadiusCount()]);
    setMyType("Cone");
}
//-------------------------------------------------------------
void ConeGeometry::setDefaultValues(){
    //Implement later
}
//-------------------------------------------------------------
QGroupBox *ConeGeometry::createInfoBox()
{
    infoBox = new QGroupBox;
    infoBox->setTitle(tr("Cone details"));
    infoBox->setObjectName(tr("infoBox"));

    QLabel *center1 = new QLabel(tr("Centre 1"));
    QLabel *center2 = new QLabel(tr("Centre 2"));
    QLabel *r0 = new QLabel(tr("r:"));
    QLabel *r1 = new QLabel(tr("r:"));
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
    radiusEdit0 = new QLineEdit(infoBox);
    radiusEdit1 = new QLineEdit(infoBox);

    pointEdit0->setObjectName("pointEdit0");
    pointEdit1->setObjectName("pointEdit1");
    pointEdit2->setObjectName("pointEdit2");
    pointEdit3->setObjectName("pointEdit3");
    pointEdit4->setObjectName("pointEdit4");
    pointEdit5->setObjectName("pointEdit5");
    radiusEdit0->setObjectName("radiusEdit0");
    radiusEdit1->setObjectName("radiusEdit1");

    x0->setBuddy(pointEdit0);
    y0->setBuddy(pointEdit1);
    z0->setBuddy(pointEdit2);
    x1->setBuddy(pointEdit3);
    y1->setBuddy(pointEdit4);
    z1->setBuddy(pointEdit5);
    r0->setBuddy(radiusEdit0);
    r1->setBuddy(radiusEdit1);



    QBoxLayout *topInfoLayout = new QVBoxLayout();
    QBoxLayout *bottomInfoLayout = new QVBoxLayout();

    topInfoLayout->addWidget(center1);
    topInfoLayout->addWidget(x0);
    topInfoLayout->addWidget(pointEdit0);
    topInfoLayout->addWidget(y0);
    topInfoLayout->addWidget(pointEdit1);
    topInfoLayout->addWidget(z0);
    topInfoLayout->addWidget(pointEdit2);
    topInfoLayout->addWidget(r0);
    topInfoLayout->addWidget(radiusEdit0);

    bottomInfoLayout->addWidget(center2);
    bottomInfoLayout->addWidget(x1);
    bottomInfoLayout->addWidget(pointEdit3);
    bottomInfoLayout->addWidget(y1);
    bottomInfoLayout->addWidget(pointEdit4);
    bottomInfoLayout->addWidget(z1);
    bottomInfoLayout->addWidget(pointEdit5);
    bottomInfoLayout->addWidget(r1);
    bottomInfoLayout->addWidget(radiusEdit1);

    QBoxLayout *coneInfoLayout = new QHBoxLayout();
    coneInfoLayout->addLayout(topInfoLayout);
    coneInfoLayout->addLayout(bottomInfoLayout);

    QPushButton *updateButton = new QPushButton(tr("Update"));
    connect(updateButton, SIGNAL(clicked()), this, SLOT(updateClicked()));

    coneInfoLayout->addWidget(updateButton);

    infoBox->setLayout(coneInfoLayout);
    infoBox->setMaximumSize(QSize(200,250));

    return infoBox;
}

void ConeGeometry::updateInfoBox()
{
    pointEdit0->setText(QString::number(getPoints()[0]));
    pointEdit1->setText("0.0");
    pointEdit2->setText("-1.0");
    pointEdit3->setText("0.0");
    pointEdit4->setText("0.0");
    pointEdit5->setText("1.0");
    radiusEdit0->setText("0.5");
    radiusEdit1->setText("0.5");
}

//-------------------------------------------------------------
void ConeGeometry::updateClicked()
{
    getGuiWindow()->updateCone(this);
}
