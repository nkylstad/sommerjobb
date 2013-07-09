#ifndef CONE_H
#define CONE_H

#include "Geometry.h"

class ConeGeometry : public Geometry
{
public:
    explicit ConeGeometry(DolfinGui *ui);

    virtual ~ConeGeometry() {}

    virtual void init(DolfinGui *ui);

    virtual void updateClicked();

    virtual void createInfoBox();


};

#endif // CONE_H
