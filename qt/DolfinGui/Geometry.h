#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <QObject>
#include <QtGui>
#include <iostream>
#include "CoordLabel.h"
#include "BoundaryMeshFunction.h"
#include "Plotter.h"
#include <boost/shared_ptr.hpp>
#include <boost/ptr_container/ptr_list.hpp>

class DolfinGui;

class Geometry : public QObject
{
    Q_OBJECT

public:

    virtual ~Geometry() {}

    void setPoints(double *points) {
        pointList = points;
    }

    void setRadius(double *radius) {
        radiusList = radius;
    }

    void setPointCount(int pCount) {
        pointCount = pCount;
    }

    void setRadiusCount(int rCount) {
        radiusCount = rCount;
    }

    int getPointCount() {
        return pointCount;
    }

    int getRadiusCount() {
        return radiusCount;
    }

    double* getPoints() {
        return pointList;
    }

    double* getRadius() {
        return radiusList;
    }

    void setGeometryPointer(boost::shared_ptr<dolfin::CSGGeometry> geometry) {
        geometryPointer = geometry;
    }

    const boost::shared_ptr<dolfin::CSGGeometry> getGeometryPointer(){
        return geometryPointer;
    }

    bool isCreated() {
        return created;
    }

    void setCreated(bool c) {
        created = c;
    }

    bool getSelected() {
        return selected;
    }

    void setSelected(bool isSelected) {
        selected = isSelected;
    }

    QGroupBox* getInfoBox() {
        return infoBox;
    }

    void setInfoBox(QGroupBox *box) {
        infoBox = box;
    }

    int operator==(const Geometry &rhs) const {
        if (this->geometryPointer != rhs.geometryPointer) return 0;
        return 1;
    }

    void setGuiWindow(DolfinGui *ui){
        guiWindow = ui;
    }

    DolfinGui* getGuiWindow(){
        return guiWindow;
    }

    // To be implemented in each geometry
    virtual void init(DolfinGui *ui) = 0;

    virtual void createInfoBox() = 0;

    QGroupBox *infoBox;


public slots:

    virtual void updateClicked() = 0;


private:

    int pointCount;  // number of points defined in geometry
    int radiusCount;  // number of radius values defined in geometry

    double *pointList;
    double *radiusList;

    boost::shared_ptr<dolfin::CSGGeometry> geometryPointer;

    DolfinGui *guiWindow;

    bool created;
    bool selected;

};


#endif // GEOMETRY_H
