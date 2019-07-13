#ifndef DRAW_HPP
#define DRAW_HPP

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QTimer>

#define DRAW_P 2
#define DRAW_L_MIN 0
#define DRAW_L_MAX 115
#define DRAW_M_MIN 0
#define DRAW_M_MAX 30
#define DRAW_BORDER 0
#define VALUE_TRACK false

class DrawPendulum
{
private:
    QGraphicsScene *p;
    QGraphicsScene *m1;
    QGraphicsScene *m2;
    QGraphicsScene *l1;
    QGraphicsScene *l2;
    QGraphicsScene *cl;

    bool treck;
public:
    DrawPendulum();
    void draw_paint();
    void draw_clear();
    void draw_p();
    void draw_m1();
    void draw_m2();
    void draw_l1();
    void draw_l2();
    void draw_tr();
    void draw_cl();

    int  get_m1x();
    int  get_m1y();
    int  get_m2x();
    int  get_m2y();
    int  get_m1();
    int  get_m2();
    int  get_p();
    void set_track(bool x);
    bool get_track();
};

#endif // DRAW_HPP
