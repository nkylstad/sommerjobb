#ifndef CUBE_H
#define CUBE_H

#include "Geometry.h"



class CubeGeometry : public Geometry
{
public:

    explicit CubeGeometry(DolfinGui *ui);

    //void DolfinGui::updatePlot();

    virtual ~CubeGeometry() {}

    virtual void init(DolfinGui *ui);

    virtual void updateClicked();

    virtual void createInfoBox();


//private:



};

#endif // CUBE_H
