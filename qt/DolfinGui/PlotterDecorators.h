#ifndef PLOTTERDECORATORS_H
#define PLOTTERDECORATORS_H


public slots:

    Plotter *new_Plotter(const boost::shared_ptr<dolfin::Variable> obj, QWidget *parent = 0)
    { return new Plotter(obj, parent); }

    void plot(Plotter *p, const boost::shared_ptr<dolfin::Variable> obj)
    { p->plot(obj); }

#endif // PLOTTERDECORATORS_H
