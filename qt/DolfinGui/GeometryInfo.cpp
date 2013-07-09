#include "GeometryInfo.h"

// Constructor
GeometryInfo::GeometryInfo()
    : QObject()
{
    geometryCount = 0;
}
//-------------------------------------------------------------
int GeometryInfo::getGeometryCount()
{
    return geometryCount;
}
//-------------------------------------------------------------
void GeometryInfo::setGeometryCount(int count)
{
    geometryCount = count;
}
//-------------------------------------------------------------
void GeometryInfo::addedGeometry()
{
    geometryCount += 1;
}
//-------------------------------------------------------------
void GeometryInfo::removedGeometry()
{
    geometryCount -= 1;
}
//-------------------------------------------------------------
void GeometryInfo::addGeometry(Geometry *g){
    geometryList.push_back(g);
    addedGeometry();
}
//-------------------------------------------------------------

void GeometryInfo::removeGeometry(Geometry *g)
{
    //geometryList.remove(g);
    //removedGeometry();
}

//-------------------------------------------------------------
vector<Geometry *> GeometryInfo::getList()
{
    return geometryList;
}
//-------------------------------------------------------------

vector<Geometry *>::iterator GeometryInfo::getIterator()
{
    return geometryListIterator;
}
