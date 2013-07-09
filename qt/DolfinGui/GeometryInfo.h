#ifndef GEOMETRYINFO_H
#define GEOMETRYINFO_H

//#include <QObject>
#include "Geometry.h"
#include <vector>
using namespace std;

class GeometryInfo : public QObject
{
    Q_OBJECT

public:
    explicit GeometryInfo();

    int getGeometryCount();

    void setGeometryCount(int count);

    void addedGeometry();

    void removedGeometry();

    void addGeometry(Geometry *g);

    vector<Geometry *> getList();

    vector<Geometry *>::iterator getIterator();

    void removeGeometry(Geometry *g);

private:

    vector<Geometry *> geometryList;
    vector<Geometry *>::iterator geometryListIterator;
    int geometryCount;

};

#endif // GEOMETRYINFO_H
