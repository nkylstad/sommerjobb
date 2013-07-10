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

    virtual QGroupBox* createInfoBox();

    virtual void updateInfoBox();

    virtual void setDefaultValues();


private:

    QLineEdit *pointEdit0;
    QLineEdit *pointEdit1;
    QLineEdit *pointEdit2;
    QLineEdit *pointEdit3;
    QLineEdit *pointEdit4;
    QLineEdit *pointEdit5;
};

#endif // CUBE_H
