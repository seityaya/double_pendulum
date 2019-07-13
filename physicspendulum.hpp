#ifndef VALUE_HPP
#define VALUE_HPP

#define VALUE_G_DEF 9.81
#define VALUE_H_DEF 0.001

#define VALUE_M1_MIN 0.1
#define VALUE_M1_MAX 1.0

#define VALUE_L1_MIN 0.1
#define VALUE_L1_MAX 1.0

#define VALUE_M2_MIN 0.0
#define VALUE_M2_MAX 1.0

#define VALUE_L2_MIN 0.0
#define VALUE_L2_MAX 1.0

#define VALUE_P_MIN 0.0

#define VALUE_L1_DEF 1.0
#define VALUE_L2_DEF 1.0
#define VALUE_M1_DEF 1.0
#define VALUE_M2_DEF 1.0
#define VALUE_A1_DEF 110
#define VALUE_A2_DEF 110

#define VALUE_FPS_DEF 100
#define VALUE_FPS_MAX 100
#define VALUE_FPS_MSEC_MIN 1
#define VALUE_FPS_MSEC_MAX 100
#define VALUE_TIME_UPDATE 50

#define VALUE_FRAADD 1
#define VALUE_EPS 4


class PhysicsPendulum{
private:
    double l1, l2, m1, m2, ll, mm, pp, a1, a2, Ek, Ep, Es, g, h, m1x, m1y, m2x, m2y, treck, fps, frame, p1, p2, t, at;
    double sa1, sa2, sp1, sp2, sm1, sm2, sl1, sl2, sg, sh;
    int  num_save;
    bool sspoint, output;

public:
    //конструктор
    PhysicsPendulum ();

    //вспомогательные
    bool   compare (double x, double y, double e = VALUE_EPS);
    double get_rand (double min, double max);
    double deg2deg (double x);
    double rad2deg (double x);
    double deg2rad (double x);
    double correct (double x, double min, double max);
    int    correct (int x, int min, int max);

    //группы
    void   save_calcul();
    void   set_value (double l1, double l2, double m1, double m2, double a1, double a2, double p1, double p2, double g, double h, double ss);
    void   set_save(int x);
    int    get_save_num();
    void   set_ss (bool x);
    void   set_stop (bool x);
    void   set_define ();
    void   set_reset ();
    void   set_random ();
    void   set_penduli();
    void print_value();

    //переменные
    void   set_l1 (double x);
    double get_l1 ();
    void   set_l2 (double x);
    double get_l2 ();

    void   set_m1 (double x);
    double get_m1 ();
    void   set_m2 (double x);
    double get_m2 ();

    void   set_ll (double x);
    void   set_ll ();
    double get_ll ();

    void   set_mm (double x);
    void   set_mm ();
    double get_mm ();

    void   set_pp (double x);
    void   set_pp ();
    double get_pp ();

    void   set_a1_deg(double x);
    void   set_a1_rad(double x);
    double get_a1_deg ();
    double get_a1_rad ();

    void   set_a2_deg(double x);
    void   set_a2_rad(double x);
    double get_a2_deg ();
    double get_a2_rad ();


    void   set_p1(double x);
    double get_p1();
    void   set_p2(double x);
    double get_p2();

    //переменные
    void   set_Ek (double x);
    double get_Ek ();
    void   set_Ep (double x);
    double get_Ep ();
    void   set_Es (double x);
    double get_Es ();

    void   set_m1xy(double x, double y);
    void   set_m1x ();
    double get_m1x ();
    void   set_m1y ();
    double get_m1y ();

    void   set_m2xy(double x, double y);
    void   set_m2x ();
    double get_m2x ();
    void   set_m2y ();
    double get_m2y ();

    void   set_track (double x);
    double get_track ();

    void   set_fps (double x);
    double get_fps ();
    int    get_fps_msec ();

    void   set_frame (double x);
    double get_frame ();

    void   set_fraadd (double x);
    void   set_fraadd ();
    double get_fraadd ();

    void   set_g (double x);
    double get_g ();

    void   set_sspoint (bool x);
    bool   get_sspoint ();

    void   set_output (bool x);
    bool   get_output ();

    void   set_h(double x);
    double get_h();

    //////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////
<<<<<<< HEAD:physicspendulum.hpp
    void   physicspendulum_run();
=======
    void   main_run();

>>>>>>> master:value.hpp
private:
    void pendulum_single_i();

    void pendulum_single_p();

    void pendulum_double_p();
    void RyKy_p_double(double a1, double a2, double p1, double p2, double l1, double l2, double m1, double m2, double g, double h, double &now_a1, double &now_a2, double &now_p1, double &now_p2);
    double get_aa1_p_double(double a1, double a2, double p1, double p2, double l1, double l2, double m1, double m2, double g);
    double get_aa2_p_double(double a1, double a2, double p1, double p2, double l1, double l2, double m1, double m2, double g);
    double get_pp1_p_double(double a1, double a2, double p1, double p2, double l1, double l2, double m1, double m2, double g);
    double get_pp2_p_double(double a1, double a2, double p1, double p2, double l1, double l2, double m1, double m2, double g);
    double get_T1_p_double(double a1, double a2, double p1, double p2, double l1, double l2, double m1, double m2, double g);
    double get_T2_p_double(double a1, double a2, double p1, double p2, double l1, double l2, double m1, double m2, double g);
    double get_V1_p_double(double a1, double a2, double p1, double p2, double l1, double l2, double m1, double m2, double g);
    double get_V2_p_double(double a1, double a2, double p1, double p2, double l1, double l2, double m1, double m2, double g);
    double get_A1_p_double(double a1, double a2, double p1, double p2, double l1, double l2, double m1, double m2, double g);
    double get_A2_p_double(double a1, double a2, double p1, double p2, double l1, double l2, double m1, double m2, double g);

    void pendulum_double_w();
    void RyKy_w_double(double a1, double a2, double w1, double w2, double l1, double l2, double m1, double m2, double g, double h, double &new_a1, double &new_a2, double &new_w1, double &new_w2);
    double get_ww1_w_double(double a1, double a2, double e1, double e2, double l1, double l2, double m1, double m2, double g);
    double get_ww2_w_double(double a1, double a2, double e1, double e2, double l1, double l2, double m1, double m2, double g);
    void circle();
};
#endif // VALUE_HPP
