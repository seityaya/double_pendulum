#include "draw.hpp"
#include "work.hpp"
#include "physicspendulum.hpp"

#include <QApplication>

PhysicsPendulum GP;
DrawPendulum GD;

int main(int argc, char *argv[])
{
    //GUI
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();

//        //CONSOL
//        Console c;
//        c.show();
//        return c.axec();
}
