#include "run/mroot.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MRoot wnd;
    wnd.show();

    return app.exec();
}
