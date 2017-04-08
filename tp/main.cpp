
#include <QApplication>

#include "Calculatrice.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Calculatrice calc;
#if defined(Q_OS_SYMBIAN)
    calc.showMaximized();
#else
    calc.show();
#endif
    return app.exec();
}


