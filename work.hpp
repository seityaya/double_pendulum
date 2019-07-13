#ifndef WORK_HPP
#define WORK_HPP

#include "draw.hpp"
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>

namespace Ui {
class Widget;
}

class Widget : public QWidget{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr);
private:
    Ui::Widget *ui;
    QTimer *tmrValue;
    QTimer *tmrDraw;
    QTimer *tmrCore;
    QGraphicsScene *scene;
    QGraphicsScene *track;

private slots:
    void updateValue();
    void updateDraw();
    void updateCore();
    void on_l1_doubleSpinBox_valueChanged(double arg1);
    void on_l2_doubleSpinBox_valueChanged(double arg1);
    void on_m1_doubleSpinBox_valueChanged(double arg1);
    void on_m2_doubleSpinBox_valueChanged(double arg1);
    void on_a1_doubleSpinBox_valueChanged(double arg1);
    void on_a2_doubleSpinBox_valueChanged(double arg1);
    void on_fps_doubleSpinBox_valueChanged(double arg1);
    void on_autor_pushButton_clicked();
    void on_reset_pushButton_clicked();
    void on_save_n_pushButton_clicked();
    void on_save_p_pushButton_clicked();
    void on_random_pushButton_clicked();
    void on_track_pushButton_toggled(bool checked);
    void on_start_pushButton_toggled(bool checked);
    void on_g_doubleSpinBox_valueChanged(double arg1);
    void on_h_doubleSpinBox_valueChanged(double arg1);
    void on_p1_doubleSpinBox_valueChanged(double arg1);
    void on_p2_doubleSpinBox_valueChanged(double arg1);
    void on_save_lineEdit_cursorPositionChanged(int arg1, int arg2);
    void on_checkBox_toggled(bool checked);
};

class Console{
private:
public:
    Console();
    void show();
    int  axec();
};

#endif //WORK_HPP