#include "work.hpp"
#include "draw.hpp"
#include "ui_window.h"
#include "physicspendulum.hpp"

#include <stdio.h>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QtGui>
#include <QTimer>
#include <QTextEdit>
#include <QDebug>
#include <QWidget>
#include <QMessageBox>
#include <QString>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <typeinfo>

extern PhysicsPendulum GP;
extern DrawPendulum GD;

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);
    this->resize(920, 695);
    this->setFixedSize(920, 695);
    this->setWindowIcon(QIcon(":physicspendulum.svg"));

    tmrValue = new QTimer(this);
    tmrDraw = new QTimer(this);
    tmrCore = new QTimer(this);

    tmrValue->setInterval(VALUE_TIME_UPDATE);
    connect(tmrValue, SIGNAL(timeout()), this, SLOT(updateValue()));
    tmrValue->start();

    tmrCore->setInterval(GP.get_fps_msec());
    connect(tmrCore, SIGNAL(timeout()), this, SLOT(updateDraw()));
    connect(tmrCore, SIGNAL(timeout()), this, SLOT(updateCore()));
    tmrCore->start();

    track = new QGraphicsScene(this);
    scene = new QGraphicsScene(this);

    ui->graphicsView->setScene(track);
    ui->graphicsView->setScene(scene);

    track->setBackgroundBrush(QBrush(QColor(1,  1,  1, 0)));
    scene->setBackgroundBrush(QBrush(QColor(1,  1,  1, 0)));

    track->setSceneRect(-249, -249, 498, 498);
    scene->setSceneRect(-249, -249, 498, 498);

    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void Widget::updateValue(){
    ui->l1_doubleSpinBox->setValue(GP.get_l1());
    ui->l2_doubleSpinBox->setValue(GP.get_l2());
    ui->m1_doubleSpinBox->setValue(GP.get_m1());
    ui->m2_doubleSpinBox->setValue(GP.get_m2());
    ui->a1_doubleSpinBox->setValue(GP.get_a1_deg());
    ui->a2_doubleSpinBox->setValue(GP.get_a2_deg());
    ui->p1_doubleSpinBox->setValue(GP.get_p1());
    ui->p2_doubleSpinBox->setValue(GP.get_p2());
    ui->fps_doubleSpinBox->setValue(GP.get_fps());
    ui->g_doubleSpinBox->setValue(GP.get_g());
    ui->h_doubleSpinBox->setValue(GP.get_h());

    ui->save_lineEdit->setText(QString::number(GP.get_save_num()));
    ui->Es_lineEdit->setText(QString("%1").arg(GP.get_Es(), 0, 'f', 5));
    ui->Ek_lineEdit->setText(QString("%1").arg(GP.get_Ek(), 0, 'f', 5));
    ui->Ep_lineEdit->setText(QString("%1").arg(GP.get_Ep(), 0, 'f', 5));
    ui->ll_lineEdit->setText(QString("%1").arg(GP.get_ll(), 0, 'f', 5));
    ui->mm_lineEdit->setText(QString("%1").arg(GP.get_mm(), 0, 'f', 5));
    ui->pp_lineEdit->setText(QString("%1").arg(GP.get_pp(), 0, 'f', 5));
    ui->m1xy_lineEdit->setText(QString("%1%2 %3%4").arg(GP.get_m1x() >= 0 ? "+" : "").arg(GP.get_m1x(), 0, 'f', 2).arg(-GP.get_m1y() >= 0 ? "+" : "").arg(-GP.get_m1y(), 0, 'f', 2, '+'));
    ui->m2xy_lineEdit->setText(QString("%1%2 %3%4").arg(GP.get_m2x() >= 0 ? "+" : "").arg(GP.get_m2x(), 0, 'f', 2).arg(-GP.get_m2y() >= 0 ? "+" : "").arg(-GP.get_m2y(), 0, 'f', 2, '+'));
    ui->frame_lineEdit->setText(QString::number(GP.get_frame()));
}

void Widget::updateDraw(){
    scene->clear();
    scene->addEllipse(-GD.get_p()/2, -GD.get_p()/2, GD.get_p(), GD.get_p());
    scene->addLine(0, 0, static_cast<int>(GD.get_m1x()),static_cast<int>(GD.get_m1y()),QPen(QColor(23,  63,   95)));
    scene->addLine(static_cast<int>(GD.get_m1x()), static_cast<int>(GD.get_m1y()), static_cast<int>(GD.get_m2x()), static_cast<int>(GD.get_m2y()),QPen(QColor(224, 178,  12)));
    scene->addEllipse(static_cast<int>(GD.get_m1x()-GD.get_m1()/2), static_cast<int>(GD.get_m1y()-GD.get_m1()/2), GD.get_m1(), GD.get_m1(), QPen(QColor(32,  99,  155)), QBrush(QColor(32,  99,  155)));
    scene->addEllipse(static_cast<int>(GD.get_m2x()-GD.get_m2()/2), static_cast<int>(GD.get_m2y()-GD.get_m2()/2), GD.get_m2(), GD.get_m2(), QPen(QColor(245, 207,  68)), QBrush(QColor(245, 207,  68)));

    if (GD.get_track() == false) { track->clear(); }
    track->addEllipse(static_cast<int>(GD.get_m2x()-1), static_cast<int>(GD.get_m2y()-1), 2, 2, QPen(QColor(245, 0, 0)), QBrush(QColor(245, 0, 0)));

    if (GP.get_sspoint() && GP.get_output()){
        char mas[300];
        sprintf(mas, "F:%5.0f | l:%.2f %.2f m:%.2f %.2f a:% 4.2f % 4.2f p:% 4.2f % 4.2f | E:% 4.2f + % 4.2f = % 4.2f | g:% 3.2f h:% 1.4f",
                GP.get_frame(),
                GP.get_l1(), GP.get_l2(),
                GP.get_m1(), GP.get_m2(),
                GP.get_a1_deg(), GP.get_a2_deg(),
                GP.get_p1(), GP.get_p2(),
                GP.get_Ep(), GP.get_Ek(), GP.get_Es(),
                GP.get_g(), GP.get_h());

        ui->textEdit->append(QString(mas));

    }
}

void Widget::updateCore(){
    GP.physicspendulum_run();
}

void Widget::on_l1_doubleSpinBox_valueChanged(double arg1)                    { GP.set_l1(arg1);         updateValue();updateDraw();    }
void Widget::on_l2_doubleSpinBox_valueChanged(double arg1)                    { GP.set_l2(arg1);         updateValue();updateDraw();    }
void Widget::on_m1_doubleSpinBox_valueChanged(double arg1)                    { GP.set_m1(arg1);         updateValue();updateDraw();    }
void Widget::on_m2_doubleSpinBox_valueChanged(double arg1)                    { GP.set_m2(arg1);         updateValue();updateDraw();    }
void Widget::on_a1_doubleSpinBox_valueChanged(double arg1)                    { GP.set_a1_deg(arg1);     updateValue();updateDraw();    }
void Widget::on_a2_doubleSpinBox_valueChanged(double arg1)                    { GP.set_a2_deg(arg1);     updateValue();updateDraw();    }
void Widget::on_p1_doubleSpinBox_valueChanged(double arg1)                    { GP.set_p1(arg1);         updateValue();updateDraw();    }
void Widget::on_p2_doubleSpinBox_valueChanged(double arg1)                    { GP.set_p2(arg1);         updateValue();updateDraw();    }
void Widget::on_g_doubleSpinBox_valueChanged(double arg1)                     { GP.set_g(arg1);          updateValue();updateDraw();    }
void Widget::on_fps_doubleSpinBox_valueChanged(double arg1)                   { GP.set_fps(arg1);        updateValue();updateDraw(); tmrCore->setInterval(GP.get_fps_msec());   }
void Widget::on_h_doubleSpinBox_valueChanged(double arg1)                     { GP.set_h(arg1);          updateValue();updateDraw();    }
void Widget::on_track_pushButton_toggled(bool checked)                        { GD.set_track(checked);   updateValue();updateDraw();  ui->track_pushButton->setDown(GD.get_track());    }
void Widget::on_start_pushButton_toggled(bool checked)                        { GP.set_ss(checked);      updateValue();updateDraw(); GP.save_calcul(); ui->start_pushButton->setDown(GP.get_sspoint()); }
void Widget::on_reset_pushButton_clicked()                                    { GP.set_reset();          updateValue();updateDraw(); ui->textEdit->setText(" ");  track->clear(); }
void Widget::on_save_n_pushButton_clicked()                                   { GP.set_save(GP.get_save_num()-1);  updateValue();updateDraw();    }
void Widget::on_save_lineEdit_cursorPositionChanged(int arg1, int arg2)       { GP.set_save(GP.get_save_num()+0);  updateValue();updateDraw();    Q_UNUSED(arg1);  Q_UNUSED(arg2); }
void Widget::on_save_p_pushButton_clicked()                                   { GP.set_save(GP.get_save_num()+1);  updateValue();updateDraw();    }
void Widget::on_random_pushButton_clicked()                                   { GP.set_random();                   updateValue();updateDraw();    }
void Widget::on_autor_pushButton_clicked()                                    { QMessageBox::information(this, "Autor/Автор", " Terlekchi Seityagiya Amedovich \n Терлекчи Сеитягия Амедович \n 17-30 / 06 / 2019 \n seityaya@ukr.net");}
void Widget::on_log_pushButton_toggled(bool checked)                                { GP.set_output(checked);                                  }


Console::Console(){}

void Console::show(){
    double l1 = 1;
    double l2 = 1;
    double m1 = 1;
    double m2 = 1;
    double a1 = 45;
    double a2 = 45;
    double p1 = 0;
    double p2 = 0;
    double g  = 9.8;
    double h  = 0.0001;
    bool ss = 1;
    GP.set_value(l1, l2, m1, m2, a1, a2, p1, p2, g, h, ss);
    GP.save_calcul();
    while(1){
    GP.physicspendulum_run();
    }
}

int Console::axec()  { return 0; }
