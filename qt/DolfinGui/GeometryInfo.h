#ifndef GEOMETRYINFO_H
#define GEOMETRYINFO_H

#include <QObject>

class GeometryInfo : public QObject
{
    Q_OBJECT

public:
    GeometryInfo(int count);

    int getDataCount();

    void setDataList(double *list);

    double *dataList;

private:

    int dataCount;

};

class GeometryInfoDecorator : public QObject
{
    Q_OBJECT

public slots:

    GeometryInfo* new_GeometryInfo(int count){ return new GeometryInfo(count); }

    void setDataList(GeometryInfo *info, double *list) { info->setDataList(list); }
};


#endif // GEOMETRYINFO_H
