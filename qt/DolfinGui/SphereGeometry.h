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

    virtual void createInfoBox();
};


#endif // SPHEREGEOMETRY_H
