#include "draw.hpp"
#include "work.hpp"
#include "physicspendulum.hpp"

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainter>
#include <QPen>
#include <QDebug>
#include <QStyleOption>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QtGui>
#include <QTimer>
#include <QTextEdit>
#include <QWidget>
#include <QMessageBox>
#include <QString>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>

extern PhysicsPendulum GP;
extern DrawPendulum GD;

DrawPendulum::DrawPendulum(){
    set_track(VALUE_TRACK);
}
void DrawPendulum::draw_paint(){}
void DrawPendulum::draw_clear(){}
void DrawPendulum::draw_p(){}
void DrawPendulum::draw_m1(){}
void DrawPendulum::draw_m2(){}
void DrawPendulum::draw_l1(){}
void DrawPendulum::draw_l2(){}
void DrawPendulum::draw_tr(){}
void DrawPendulum::draw_cl(){}

int DrawPendulum::get_p(){
    return DRAW_P;
}

int DrawPendulum::get_m1x(){
    return (int)((GP.get_m1x()*(DRAW_L_MAX-DRAW_M_MIN))+DRAW_M_MIN);
}
int DrawPendulum::get_m1y(){
    return (int)((GP.get_m1y()*(DRAW_L_MAX-DRAW_M_MIN))+DRAW_M_MIN);
}
int DrawPendulum::get_m2x(){
    return (int)((GP.get_m2x()*(DRAW_L_MAX-DRAW_M_MIN))+DRAW_M_MIN);
}
int DrawPendulum::get_m2y(){
    return (int)((GP.get_m2y()*(DRAW_L_MAX-DRAW_M_MIN))+DRAW_M_MIN);
}
int DrawPendulum::get_m1(){
    return (int)((GP.get_m1()*(DRAW_M_MAX-DRAW_M_MIN))+DRAW_M_MIN);
}
int DrawPendulum::get_m2(){
    return (int)((GP.get_m2()*(DRAW_M_MAX-DRAW_M_MIN))+DRAW_M_MIN);
}
void DrawPendulum::set_track(bool x) {
    treck = x;
}
bool DrawPendulum::get_track() {
    return treck;
}
