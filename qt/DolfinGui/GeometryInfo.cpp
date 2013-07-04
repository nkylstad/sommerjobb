#include "GeometryInfo.h"

// Constructor
GeometryInfo::GeometryInfo(int count)
    : QObject()
{
    dataCount = count;
}
//------------------------------------------------------------
int GeometryInfo::getDataCount()
{
    return dataCount;
}
//------------------------------------------------------------
void GeometryInfo::setDataList(double *list)
{
    dataList = list;
}
