#ifndef SPHEREGEOMETRY_H
#define SPHEREGEOMETRY_H

#include "Geometry.h"

class SphereGeometry : public Geometry
{
public:

    explicit SphereGeometry(DolfinGui *ui);

    virtual ~SphereGeometry() {}

    virtual void init(DolfinGui *ui);

    virtual void updateClicked();

    virtual QGroupBox* createInfoBox();

    virtual void updateInfoBox();

    virtual void setDefaultValues();

private:

    QLineEdit *pointEdit0;
    QLineEdit *pointEdit1;
    QLineEdit *pointEdit2;
    QLineEdit *radiusEdit0;
};


#endif // SPHEREGEOMETRY_H
