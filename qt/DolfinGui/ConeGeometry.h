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
    QLineEdit *radiusEdit0;
    QLineEdit *radiusEdit1;
};

#endif // CONE_H
