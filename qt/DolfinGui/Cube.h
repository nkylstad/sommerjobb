#ifndef CUBE_H
#define CUBE_H

#include "Geometry.h"

class Cube : public Geometry
{
    // Should something be here?

public:
    Cube();

    virtual ~Cube() {}

    virtual void init();
    /*

    virtual void setPoints(double *points);

    virtual void setRadius(double *radius);

    virtual void setPointCount(int pCount);

    virtual void setRadiusCount(int rCount);

    //virtual int getPointCount();

    //virtual int getRadiusCount();

    virtual double* getPoints();

    virtual double* getRadius();
    */

};

#endif // CUBE_H
