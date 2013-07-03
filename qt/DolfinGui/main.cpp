#include "DolfinGui.h"
//#include <dolfin.h>
#include <QApplication>

using namespace dolfin;

int main(int argc, char *argv[])
{
    if (getenv("DOLFIN_NOPLOT"))
    {
      warning("DOLFIN_NOPLOT is set; not running %s", argv[0]);
      return 0;
    }

    QApplication a(argc, argv);
    DolfinGui w;
    w.show();
    
    return a.exec();
}
