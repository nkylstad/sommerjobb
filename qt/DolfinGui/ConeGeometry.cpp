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
}
//-------------------------------------------------------------
void ConeGeometry::createInfoBox()
{
    infoBox = new QGroupBox;
    infoBox->setTitle(tr("Cone details"));

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

    QLineEdit *coneEdit0 = new QLineEdit(infoBox);
    QLineEdit *coneEdit1 = new QLineEdit(infoBox);
    QLineEdit *coneEdit2 = new QLineEdit(infoBox);
    QLineEdit *coneEdit3 = new QLineEdit(infoBox);
    QLineEdit *coneEdit4 = new QLineEdit(infoBox);
    QLineEdit *coneEdit5 = new QLineEdit(infoBox);
    QLineEdit *radiusEdit0 = new QLineEdit(infoBox);
    QLineEdit *radiusEdit1 = new QLineEdit(infoBox);

    coneEdit0->setObjectName("coneEdit0");
    coneEdit1->setObjectName("coneEdit1");
    coneEdit2->setObjectName("coneEdit2");
    coneEdit3->setObjectName("coneEdit3");
    coneEdit4->setObjectName("coneEdit4");
    coneEdit5->setObjectName("coneEdit5");
    radiusEdit0->setObjectName("radiusEdit0");
    radiusEdit1->setObjectName("radiusEdit1");

    x0->setBuddy(coneEdit0);
    y0->setBuddy(coneEdit1);
    z0->setBuddy(coneEdit2);
    x1->setBuddy(coneEdit3);
    y1->setBuddy(coneEdit4);
    z1->setBuddy(coneEdit5);
    r0->setBuddy(radiusEdit0);
    r1->setBuddy(radiusEdit1);

    coneEdit0->setText(QString::number(getPoints()[0]));
    coneEdit1->setText("0.0");
    coneEdit2->setText("-1.0");
    coneEdit3->setText("0.0");
    coneEdit4->setText("0.0");
    coneEdit5->setText("1.0");
    radiusEdit0->setText("0.5");
    radiusEdit1->setText("0.5");

    QBoxLayout *topInfoLayout = new QVBoxLayout();
    QBoxLayout *bottomInfoLayout = new QVBoxLayout();

    topInfoLayout->addWidget(center1);
    topInfoLayout->addWidget(x0);
    topInfoLayout->addWidget(coneEdit0);
    topInfoLayout->addWidget(y0);
    topInfoLayout->addWidget(coneEdit1);
    topInfoLayout->addWidget(z0);
    topInfoLayout->addWidget(coneEdit2);
    topInfoLayout->addWidget(r0);
    topInfoLayout->addWidget(radiusEdit0);

    bottomInfoLayout->addWidget(center2);
    bottomInfoLayout->addWidget(x1);
    bottomInfoLayout->addWidget(coneEdit3);
    bottomInfoLayout->addWidget(y1);
    bottomInfoLayout->addWidget(coneEdit4);
    bottomInfoLayout->addWidget(z1);
    bottomInfoLayout->addWidget(coneEdit5);
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
}
//-------------------------------------------------------------
void ConeGeometry::updateClicked()
{
    getGuiWindow()->updateCone(this);
}
