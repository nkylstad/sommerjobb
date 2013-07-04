#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <QObject>

class Geometry : public QObject
{
    Q_OBJECT

public:

    virtual void setPoints(double *points) {
        pointList = points;
    }

    virtual void setRadius(double *radius) {
        radiusList = radius;
    }

    virtual void setPointCount(int pCount) {
        pointCount = pCount;
    }

    virtual void setRadiusCount(int rCount) {
        radiusCount = rCount;
    }

    virtual int getPointCount() {
        return pointCount;
    }

    virtual int getRadiusCount() {
        return radiusCount;
    }

    virtual double* getPoints() {
        return pointList;
    }

    virtual double* getRadius() {
        return radiusList;
    }

    virtual void init() { };

private:
    int pointCount;  // number of points defined in geometry
    int radiusCount;  // number of radius values defined in geometry

    double *pointList;
    double *radiusList;
};


#endif // GEOMETRY_H
