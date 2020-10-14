#include "physicspendulum.hpp"

#include <QtGui>
#include <cmath>

PhysicsPendulum::PhysicsPendulum() {
    qsrand(static_cast <uint>(QTime(0,0,0).secsTo(QTime::currentTime())));
    set_define();
}

void PhysicsPendulum::set_save(int x) {
    num_save = correct (x, 0, 9);
    switch (num_save){
    case 0:
        set_define();
        break;
    case 1:
        set_penduli();
        break;
    case 2:
        set_define();
        break;
    case 3:
        set_define();
        break;
    case 4:
        set_define();
        break;
    case 5:
        set_define();
        break;
    case 6:
        set_define();
        break;
    case 7:
        set_define();
        break;
    case 8:
        set_define();
        break;
    case 9:
        set_define();
        break;
    }
}

int PhysicsPendulum::get_save_num() {
    return num_save;
}

void PhysicsPendulum::set_penduli() {
    set_l1(1);
    set_l2(0.1);
    set_m1(1);
    set_m2(0.3);
    set_a1_deg(0);
    set_a2_deg(0);
    set_p1(0);
    set_p2(7);
    set_frame(0);
}

void PhysicsPendulum::set_define() {
    set_l1(VALUE_L1_DEF);
    set_l2(VALUE_L2_DEF);
    set_m1(VALUE_M1_DEF);
    set_m2(VALUE_M2_DEF);
    set_a1_deg(VALUE_A1_DEF);
    set_a2_deg(VALUE_A2_DEF);
    set_p1(0);
    set_p2(0);
    set_fps(VALUE_FPS_DEF);
    set_m1x();
    set_m1y();
    set_m2x();
    set_m2y();
    set_ll();
    set_mm();
    set_g(VALUE_G_DEF);
    set_h(VALUE_H_DEF);
    set_frame(0);
    set_sspoint(false);
}

void PhysicsPendulum::set_value (double l1, double l2, double m1, double m2, double a1, double a2, double p1, double p2,  double g, double h, bool ss) {
    set_l1(l1);
    set_l2(l2);
    set_m1(m1);
    set_m2(m2);
    set_a1_deg(a1);
    set_a2_deg(a2);
    set_p1(p1);
    set_p2(p2);
    set_g(g);
    set_h(h);
    set_sspoint(ss);
}

void PhysicsPendulum::set_reset() {
    set_l1(1);
    set_l2(1);
    set_m1(1);
    set_m2(1);
    set_a1_rad(0);
    set_a2_rad(0);
    set_p1(0);
    set_p2(0);
    set_fps(VALUE_FPS_DEF);
    set_frame(0);
}

void PhysicsPendulum::set_random() {
    set_l1(get_rand(VALUE_L1_MIN, 5));
    set_l2(get_rand(VALUE_L1_MIN, 5));
    set_m1(get_rand(VALUE_M1_MIN, 3));
    set_m2(get_rand(VALUE_M1_MIN, 3));
    set_p1(get_rand(VALUE_P_MIN, 3));
    set_p2(get_rand(VALUE_P_MIN, 3));
    set_a1_deg(get_rand(-180, 180));
    set_a2_deg(get_rand(-180, 180));
    set_frame(0);
}

void PhysicsPendulum::set_ss(bool x) {
    if(x){
        set_sspoint(x);
        set_frame(0);
    }else{
        set_sspoint(x);
    }
}

void PhysicsPendulum::set_sspoint(bool x) {
    sspoint = x;
}

bool PhysicsPendulum::get_sspoint() {
    return sspoint;
}

void PhysicsPendulum::set_output (bool x){
    output = x;
}

bool PhysicsPendulum::get_output (){
    return output;
}

void PhysicsPendulum::set_g(double x) {
    g = x;
}

double PhysicsPendulum::get_g() {
    return g;
}

void PhysicsPendulum::set_h(double x) {
    h = x;
}

double PhysicsPendulum::get_h() {
    return h;
}

void PhysicsPendulum::set_p1(double x) {
    p1 = x;
}

double PhysicsPendulum::get_p1() {
    return p1;
}

void PhysicsPendulum::set_p2(double x) {
    p2 = x;
}

double PhysicsPendulum::get_p2() {
    return p2;
}

void PhysicsPendulum::set_l1(double x) {
    l1 = correct(x, VALUE_L1_MIN, VALUE_L1_MAX);
}

double PhysicsPendulum::get_l1() {
    return l1;
}

void PhysicsPendulum::set_l2(double x) {
    l2 = correct(x, VALUE_L2_MIN, VALUE_L2_MAX);
}

double PhysicsPendulum::get_l2() {
    return l2;
}

void PhysicsPendulum::set_m1(double x) {
    m1 = correct(x, VALUE_M1_MIN, VALUE_M1_MAX);
}

double PhysicsPendulum::get_m1() {
    return m1;
}

void PhysicsPendulum::set_m2(double x) {
    m2 = correct(x, VALUE_M2_MIN, VALUE_M2_MAX);
}

double PhysicsPendulum::get_m2() {
    return m2;
}

double PhysicsPendulum::get_Ek() {
    return Ek;
}

double PhysicsPendulum::get_Ep() {
    return Ep;
}

double PhysicsPendulum::get_Es() {
    return Es;
}
void PhysicsPendulum::set_Ek(double x) {
    Ek = x;
}

void PhysicsPendulum::set_Ep(double x) {
    Ep = x;
}

void PhysicsPendulum::set_Es(double x) {
    Es = x;
}


void PhysicsPendulum::set_ll(double x) {
    ll = x;
    l2 = 1;
    l1 = l2 / ll;
}

void PhysicsPendulum::set_ll()
{
    ll = l2 / l1;
}

double PhysicsPendulum::get_ll() {
    set_ll();
    return ll;
}

void PhysicsPendulum::set_mm() {
    mm = m2 / m1;
}

void PhysicsPendulum::set_mm(double x) {
    mm = x;
    m2 = 1;
    m1 = m2 / mm;
}

double PhysicsPendulum::get_mm() {
    set_mm();
    return mm;
}

void   PhysicsPendulum::set_pp (){
    pp = p2 / p1;
}
void   PhysicsPendulum::set_pp (double x){
    pp = x;
    p2 = 1;
    p1 = p2 / pp;
}
double PhysicsPendulum::get_pp (){
    set_pp();
    return pp;
}

void PhysicsPendulum::set_fps(double x) {
    if (compare(x, -1)) {
        fps = VALUE_FPS_MAX;
    } else if (compare(x, VALUE_FPS_MAX + 1)) {
        fps = 0;
    } else {
        fps = x;
    }
}

double PhysicsPendulum::get_fps() {
    return fps;
}

int PhysicsPendulum::get_fps_msec() {
    if (compare(get_fps(), 0)){
        return 1000000;
    }else{
        return static_cast<int>
                ((get_fps()*(VALUE_FPS_MSEC_MIN - VALUE_FPS_MSEC_MAX)-
                  1*(VALUE_FPS_MSEC_MIN+VALUE_FPS_MSEC_MAX)+
                  VALUE_FPS_MSEC_MAX*(VALUE_FPS_MAX+1))/(VALUE_FPS_MAX-1));
    }
}

void PhysicsPendulum::set_a1_rad(double x) {
    a1 = x;
}

double PhysicsPendulum::get_a1_rad() {
    return a1;
}

void PhysicsPendulum::set_a1_deg(double x) {
    a1 = deg2rad(x);
}

double PhysicsPendulum::get_a1_deg() {
    return deg2deg(rad2deg(a1));
}

void PhysicsPendulum::set_a2_rad(double x) {
    a2 = x;
}

double PhysicsPendulum::get_a2_rad() {
    return a2;
}

void PhysicsPendulum::set_a2_deg(double x) {
    a2 = deg2rad(x);
}

double PhysicsPendulum::get_a2_deg() {
    return deg2deg(rad2deg(a2));
}

void PhysicsPendulum::set_m1xy(double x, double y) {
    m1x = x;
    m1y = y;
    l1 = pow((x*x+y*y), (1./2.));
    a1 = atan2(y, x);
}

void PhysicsPendulum::set_m1x() {
    m1x = l1 * sin(get_a1_rad());
}

double PhysicsPendulum::get_m1x() {
    set_m1x();
    return m1x;
}

void PhysicsPendulum::set_m1y() {
    m1y = l1 * cos(get_a1_rad());
}

double PhysicsPendulum::get_m1y() {
    set_m1y();
    return m1y;
}

void PhysicsPendulum::set_m2xy(double x, double y) {
    m2x = x;
    m2y = y;
    l2 = pow((x*x+y*y), (1./2.));
    a2 = atan2(y, x);
}

void PhysicsPendulum::set_m2x() {
    m2x = get_m1x() + l2 * sin(get_a2_rad());
}

double PhysicsPendulum::get_m2x() {
    set_m2x();
    return m2x;
}

void PhysicsPendulum::set_m2y() {
    m2y = get_m1y() + l2 * cos(get_a2_rad());
}

double PhysicsPendulum::get_m2y() {
    set_m2y();
    return  m2y;
}

void   PhysicsPendulum::set_frame (double x) {
    frame = x;
}

double PhysicsPendulum::get_frame () {
    return frame;
}

void PhysicsPendulum::set_fraadd(double x) {
    set_frame(get_frame() + x);
}

void PhysicsPendulum::set_fraadd() {
    set_frame(get_frame() + VALUE_FRAADD);
}

double PhysicsPendulum::get_fraadd() {
    set_fraadd();
    return get_frame();
}

double PhysicsPendulum::get_rand(double min, double max) {
    double k = static_cast<double>(qrand()) / RAND_MAX;
    return min + k * (max - min);
}

bool PhysicsPendulum::compare(double x, double y, double e) {
    return abs(x - y) < pow(10, -e);
}

double PhysicsPendulum::deg2rad(double x) {
    return (x * M_PI) / (180);
}

double PhysicsPendulum::rad2deg(double x) {
    return (x * 180) / (M_PI);
}

double PhysicsPendulum::deg2deg(double x) {
    if(x > 180) {
        return - 180 + (x - 180);
    }else if (x < -180) {
        return  180 + (x + 180);
    }else {
        return x;
    }
}

double PhysicsPendulum::correct(double x, double min, double max) {
    if (x < min) {
        return min;
    } else if (x > max) {
        return max;
    } else {
        return x;
    }
}

int PhysicsPendulum::correct(int x, int min, int max) {
    if (x < min) {
        return min;
    } else if (x > max) {
        return max;
    } else {
        return x;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///  BEG  PhysicsPendulum_Single
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void PhysicsPendulum::pendulum_single_i(){
    if (get_sspoint() == true) {
        set_fraadd();
        //calculations
        {
            at = -sa1*cos(pow(g/l1, 0.5)+(t*sa1));
            t+=h;
        }
        m2 = 0;
        l2 = 0;
        a2 = 0;
        p2 = 0;
        a1 = at;
        p1 = sp1;
    }
    Ep = m1*g*-cos(a1)*l1; // + m1*g*l1;
    Ek = m1*g*-cos(sa1)*l1 - Ep; // + m1*g*l1;
    Es = Ek + Ep;
}

void PhysicsPendulum::pendulum_single_p(){
    if (get_sspoint() == true) {
        set_fraadd();
        //calculations
        {

        }
        m2 = 0;
        l2 = 0;
        a2 = 0;
        p2 = 0;
        a1 = at;
        p1 = sp1;
    }
    Ep = 0;
    Ek = 0;
    Es = Ek + Ep;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///  END  PhysicsPendulum_Single
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///  BEG  PhysicsPendulum_Double
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double PhysicsPendulum::get_T1_p_double(double a1, double a2, double p1, double p2, double l1, double l2, double m1, double m2, double g){
    return  m1 /2 * l1 * l1 * get_aa1_p_double(a1, a2, p1, p2, l1, l2, m1, m2, g) * get_aa1_p_double(a1, a2, p1, p2, l1, l2, m1, m2, g);
}

double PhysicsPendulum::get_T2_p_double(double a1, double a2, double p1, double p2, double l1, double l2, double m1, double m2, double g){
    return  m2 /2 *
            (l1 * l1 * get_aa1_p_double(a1, a2, p1, p2, l1, l2, m1, m2, g) * get_aa1_p_double(a1, a2,  p1, p2, l1, l2, m1, m2, g) +
             l2 * l2 * get_aa2_p_double(a1, a2, p1, p2, l1, l2, m1, m2, g) * get_aa2_p_double(a1, a2,  p1, p2, l1, l2, m1, m2, g) +
             2 * l1 * l2 * get_aa1_p_double(a1, a2, p1, p2, l1, l2, m1, m2, g) * get_aa2_p_double(a1, a2,  p1, p2, l1, l2, m1, m2, g) * cos(a1 - a2));
}

double PhysicsPendulum::get_V1_p_double(double a1, double a2, double p1, double p2, double l1, double l2, double m1, double m2, double g){
    Q_UNUSED(a1);Q_UNUSED(a2);Q_UNUSED(p1);Q_UNUSED(p2);Q_UNUSED(l1);Q_UNUSED(l2);Q_UNUSED(m1);Q_UNUSED(m2);Q_UNUSED(g);
    return  m1*g*-cos(a1)*l1; // + m1*g*l1;
}

double PhysicsPendulum::get_V2_p_double(double a1, double a2, double p1, double p2, double l1, double l2, double m1, double m2, double g){
    Q_UNUSED(a1);Q_UNUSED(a2);Q_UNUSED(p1);Q_UNUSED(p2);Q_UNUSED(l1);Q_UNUSED(l2);Q_UNUSED(m1);Q_UNUSED(m2);Q_UNUSED(g);
    return  -m2*g*(l1*cos(a1)+l2*cos(a2)); // + m2*g*(l1+l2);
}

double PhysicsPendulum::get_A1_p_double(double a1, double a2, double p1, double p2, double l1, double l2, double m1, double m2, double g){
    Q_UNUSED(a1);Q_UNUSED(a2);Q_UNUSED(p1);Q_UNUSED(p2);Q_UNUSED(l1);Q_UNUSED(l2);Q_UNUSED(m1);Q_UNUSED(m2);Q_UNUSED(g);
    return   ((p1*p2*sin(a1-a2))/(l1*l2*(m1+m2*sin(a1-a2)*sin(a1-a2)))) ;
}

double PhysicsPendulum::get_A2_p_double(double a1, double a2, double p1, double p2, double l1, double l2, double m1, double m2, double g){
    Q_UNUSED(a1);Q_UNUSED(a2);Q_UNUSED(p1);Q_UNUSED(p2);Q_UNUSED(l1);Q_UNUSED(l2);Q_UNUSED(m1);Q_UNUSED(m2);Q_UNUSED(g);
    return (((p1*p1*m2*l2*l2 - 2*p1*p2*m2*l1*l2*cos(a1-a2)+p2*p2*(m1+m2)*l1*l1)*sin(2*(a1-a2)))
            / (2*l1*l1*l2*l2*pow((m1+m2*sin(a1-a2)*sin(a1-a2)),2)));
}

double PhysicsPendulum::get_aa1_p_double(double a1, double a2, double p1, double p2, double l1, double l2, double m1, double m2, double g){
    Q_UNUSED(a1);Q_UNUSED(a2);Q_UNUSED(p1);Q_UNUSED(p2);Q_UNUSED(l1);Q_UNUSED(l2);Q_UNUSED(m1);Q_UNUSED(m2);Q_UNUSED(g);
    return (p1*l2-p2*l1*cos(a1-a2))/(l1*l1*l2*(m1+m2*sin(a1-a2)*sin(a1-a2)));
}

double PhysicsPendulum::get_aa2_p_double(double a1, double a2, double p1, double p2, double l1, double l2, double m1, double m2, double g){
    Q_UNUSED(a1);Q_UNUSED(a2);Q_UNUSED(p1);Q_UNUSED(p2);Q_UNUSED(l1);Q_UNUSED(l2);Q_UNUSED(m1);Q_UNUSED(m2);Q_UNUSED(g);
    return (p2*(m1+m2)*l1-p1*m2*l2*cos(a1-a2))/(m2*l1*l2*l2*(m1+m2*sin(a1-a2)*sin(a1-a2)));
}

double PhysicsPendulum::get_pp1_p_double(double a1, double a2, double p1, double p2, double l1, double l2, double m1, double m2, double g){
    return (-(m1+m2)*g*l1*sin(a1) - get_A1_p_double(a1, a2,  p1,  p2, l1, l2, m1, m2, g) + get_A2_p_double(a1, a2,  p1,  p2, l1, l2, m1, m2, g));
}

double PhysicsPendulum::get_pp2_p_double(double a1, double a2, double p1, double p2, double l1, double l2, double m1, double m2, double g){
    return (-m2*g*l2*sin(a2)) + get_A1_p_double(a1, a2,  p1,  p2, l1, l2, m1, m2, g) + get_A2_p_double(a1, a2,  p1,  p2, l1, l2, m1, m2, g);
}

void PhysicsPendulum::RyKy_p_double(double a1, double a2, double p1, double p2, double l1, double l2, double m1, double m2, double g, double h, double &new_a1, double &new_a2, double &new_p1, double &new_p2){
    double aa1[5], aa2[5], pp1[5], pp2[5];

    aa1[1] = h * get_aa1_p_double(a1, a2, p1, p2, l1, l2, m1, m2, g);
    aa2[1] = h * get_aa2_p_double(a1, a2, p1, p2, l1, l2, m1, m2, g);
    pp1[1] = h * get_pp1_p_double(a1, a2, p1, p2, l1, l2, m1, m2, g);
    pp2[1] = h * get_pp2_p_double(a1, a2, p1, p2, l1, l2, m1, m2, g);

    aa1[2] = h * get_aa1_p_double(a1 + aa1[1]/2, a2 + aa2[1]/2,  p1 + pp1[1]/2,  p2 + pp2[1]/2, l1, l2, m1, m2, g);
    aa2[2] = h * get_aa2_p_double(a1 + aa1[1]/2, a2 + aa2[1]/2,  p1 + pp1[1]/2,  p2 + pp2[1]/2, l1, l2, m1, m2, g);
    pp1[2] = h * get_pp1_p_double(a1 + aa1[1]/2, a2 + aa2[1]/2,  p1 + pp1[1]/2,  p2 + pp2[1]/2, l1, l2, m1, m2, g);
    pp2[2] = h * get_pp2_p_double(a1 + aa1[1]/2, a2 + aa2[1]/2,  p1 + pp1[1]/2,  p2 + pp2[1]/2, l1, l2, m1, m2, g);

    aa1[3] = h * get_aa1_p_double(a1 + aa1[2]/2, a2 + aa2[2]/2,  p1 + pp1[2]/2,  p2 + pp2[2]/2, l1, l2, m1, m2, g);
    aa2[3] = h * get_aa2_p_double(a1 + aa1[2]/2, a2 + aa2[2]/2,  p1 + pp1[2]/2,  p2 + pp2[2]/2, l1, l2, m1, m2, g);
    pp1[3] = h * get_pp1_p_double(a1 + aa1[2]/2, a2 + aa2[2]/2,  p1 + pp1[2]/2,  p2 + pp2[2]/2, l1, l2, m1, m2, g);
    pp2[3] = h * get_pp2_p_double(a1 + aa1[2]/2, a2 + aa2[2]/2,  p1 + pp1[2]/2,  p2 + pp2[2]/2, l1, l2, m1, m2, g);

    aa1[4] = h * get_aa1_p_double(a1 + aa1[3], a2 + aa2[3],  p1 + pp1[3],  p2 + pp2[3], l1, l2, m1, m2, g);
    aa2[4] = h * get_aa2_p_double(a1 + aa1[3], a2 + aa2[3],  p1 + pp1[3],  p2 + pp2[3], l1, l2, m1, m2, g);
    pp1[4] = h * get_pp1_p_double(a1 + aa1[3], a2 + aa2[3],  p1 + pp1[3],  p2 + pp2[3], l1, l2, m1, m2, g);
    pp2[4] = h * get_pp2_p_double(a1 + aa1[3], a2 + aa2[3],  p1 + pp1[3],  p2 + pp2[3], l1, l2, m1, m2, g);

    aa1[0] = a1 + (aa1[1] + 2*aa1[2] + 2*aa1[3] + aa1[4])/6;
    aa2[0] = a2 + (aa2[1] + 2*aa2[2] + 2*aa2[3] + aa2[4])/6;
    pp1[0] = p1 + (pp1[1] + 2*pp1[2] + 2*pp1[3] + pp1[4])/6;
    pp2[0] = p2 + (pp2[1] + 2*pp2[2] + 2*pp2[3] + pp2[4])/6;

    new_a1 = aa1[0];
    new_a2 = aa2[0];
    new_p1 = pp1[0];
    new_p2 = pp2[0];
}

void PhysicsPendulum::pendulum_double_p(){
    if (get_sspoint() == true) {
        //calculations
        set_fraadd();
        RyKy_p_double(sa1, sa2, sp1, sp2, sl1, sl2, sm1, sm2, sg, h, sa1, sa2, sp1, sp2);
        a1 = sa1;
        a2 = sa2;
        p1 = sp1;
        p2 = sp2;
    }
    Ek = get_T1_p_double(a1, a2, p1, p2, l1, l2, m1, m2, g) + get_T2_p_double(a1, a2, p1, p2, l1, l2, m1, m2, g);
    Ep = get_V1_p_double(a1, a2, p1, p2, l1, l2, m1, m2, g) + get_V2_p_double(a1, a2, p1, p2, l1, l2, m1, m2, g);
    Es = get_Ek() + get_Ep();

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

double PhysicsPendulum::get_ww1_w_double(double a1, double a2, double e1, double e2, double l1, double l2, double m1, double m2, double g){
    double sind = sin(a2-a1);
    double cosd = cos(a2-a1);
    double M = m1+m2;
    return (m2*l1*e1*e1*sind*cosd+m2*g*sin(a2)*cosd+m2*l2*e2*e2*sind-M*g*sin(a1))
            / (M*l1-m2*l1*cosd*cosd);
}

double PhysicsPendulum::get_ww2_w_double(double a1, double a2, double e1, double e2, double l1, double l2, double m1, double m2, double g){
    double sind = sin(a2-a1);
    double cosd = cos(a2-a1);
    double M = m1+m2;
    return (-m2*l1*e2*e2*sind*cosd+M*(g*sin(a1)*cosd-l1*e1*e1*sind-g*sin(a2)))
            / (M*l2-m2*l2*cosd*cosd);
}

void PhysicsPendulum::RyKy_w_double(double a1, double a2, double w1, double w2, double l1, double l2, double m1, double m2, double g, double h, double &new_a1, double &new_a2, double &new_w1, double &new_w2){
    double aa1[5], aa2[5], ww1[5], ww2[5];

    aa1[1] = h * w1;
    aa2[1] = h * w2;
    ww1[1] = h * get_pp1_p_double(a1, a2, w1, w2, l1, l2, m1, m2, g);
    ww2[1] = h * get_pp2_p_double(a1, a2, w1, w2, l1, l2, m1, m2, g);

    aa1[2] = h * (w1 + w1 * h/2);
    aa2[2] = h * (w2 + w2 * h/2);
    ww1[2] = h * get_ww1_w_double(a1 + aa1[1]/2, a2 + aa2[1]/2,  w1 + ww1[1]/2,  w2 + ww2[1]/2, l1, l2, m1, m2, g);
    ww2[2] = h * get_ww2_w_double(a1 + aa1[1]/2, a2 + aa2[1]/2,  w1 + ww1[1]/2,  w2 + ww2[1]/2, l1, l2, m1, m2, g);

    aa1[3] = h * (w1 + w1 * h/2);
    aa2[3] = h * (w2 + w2 * h/2);
    ww1[3] = h * get_ww1_w_double(a1 + aa1[2]/2, a2 + aa2[2]/2,  w1 + ww1[2]/2,  w2 + ww2[2]/2, l1, l2, m1, m2, g);
    ww2[3] = h * get_ww2_w_double(a1 + aa1[2]/2, a2 + aa2[2]/2,  w1 + ww1[2]/2,  w2 + ww2[2]/2, l1, l2, m1, m2, g);

    aa1[4] = h * (w1 + w1 * h/2);
    aa2[4] = h * (w2 + w2 * h/2);
    ww1[4] = h * get_ww1_w_double(a1 + aa1[3], a2 + aa2[3],  w1 + ww1[3],  w2 + ww2[3], l1, l2, m1, m2, g);
    ww2[4] = h * get_ww2_w_double(a1 + aa1[3], a2 + aa2[3],  w1 + ww1[3],  w2 + ww2[3], l1, l2, m1, m2, g);

    aa1[0] = a1 + (aa1[1] + 2*aa1[2] + 2*aa1[3] + aa1[4])/6;
    aa2[0] = a2 + (aa2[1] + 2*aa2[2] + 2*aa2[3] + aa2[4])/6;
    ww1[0] = w1 + (ww1[1] + 2*ww1[2] + 2*ww1[3] + ww1[4])/6;
    ww2[0] = w2 + (ww2[1] + 2*ww2[2] + 2*ww2[3] + ww2[4])/6;

    new_a1 = aa1[0];
    new_a2 = aa2[0];
    new_w1 = ww1[0];
    new_w2 = ww2[0];
}

void PhysicsPendulum::pendulum_double_w(){
    if (get_sspoint() == true) {
        set_fraadd();
        //calculations
        RyKy_w_double(sa1, sa2, sp1, sp2, sl1, sl2, sm1, sm2, sg, h, sa1, sa2, sp1, sp2);
        a1 = sa1;
        a2 = sa2;
        p1 = sp1;
        p2 = sp2;
    }
    Ek = (m1*p1*p1)/2+ (m2*p2*p2)/2;
    Ep = m1*g*-m1y+m2*g*-m2y + (l1+l2)*m2*g + l1*m1*g;
    Es = Ek + Ep;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///  END  PhysicsPendulum_Double
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PhysicsPendulum::save_calcul( ) {
    sl1 = get_l1();
    sl2 = get_l2();
    sm1 = get_m1();
    sm2 = get_m2();
    sa1 = get_a1_rad();
    sa2 = get_a2_rad();
    sp1 = get_p1();
    sp2 = get_p2();
    sg =  get_g();
    sh =  get_h();
}

void PhysicsPendulum::physicspendulum_run(){
    if (compare(l2, 0) || compare(m2, 0)){
        pendulum_single_i();
        //pendulum_single_p();
    }else{
        pendulum_double_p();
        //pendulum_double_w();

        //qDebug() << sa1 <<"\t"<< sa2 <<"\t"<< sp1 <<"\t"<< sp2 <<"   *   "<< Ep << "+" << Ek << "=" << Es;
    }
}
