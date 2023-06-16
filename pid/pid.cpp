/**
 * @file pid.cpp
 * @author Pawel Smieja
 * @brief 
 * @version 0.1
 * @date 2023-05-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "pid.hpp"
#include <cmath>

/**
 * @brief Construct a new PID::PID object
 *
 * @param min minimum controller output
 * @param max maximum controller output
 * @param dt time step
 * @param kp proportional coef
 * @param ki integral coef
 * @param kd derivative coef
 */
PID::PID(double min, double max, double dt, double kp, double ki, double kd)
{
    m_dt = dt;
    m_Kp = kp;
    m_Ki = ki;
    m_Kd = kd;
    m_min = min;
    m_max = max;
    // sum of previous and current integrals
    integral_temp = 0.0;
    // previous error
    prev_error = 0.0;
}

// calculate error
double PID::calc_error(double pv, double set_point)
{
    double error = set_point - pv;
    return error;
}

// calculate proportional term
double PID::calc_prop(double error)
{
    double prop = m_Kp * error;
    return prop;
}

// calculate integral term
double PID::calc_integr(double error)
{
    // calculate sum of previous and current integrals
    integral_temp += error * m_dt;
    // calculate integral term
    double integr = m_Ki * integral_temp;
    return integr;
}

// calculate derivative term
double PID::calc_deriv(double error)
{
    double deriv = m_Kd * ((error - prev_error) / m_dt);
    // Save error to previous error
    prev_error = error;

    return deriv;
}

// update setpoint
void PID::set_setPoint(double sp)
{
    set_point = sp;
}

// calculate controller output
double PID::simulate(double pv)
{
    // calculate error
    double error = calc_error(pv, set_point);
    // calculate PID terms
    double prop = calc_prop(error);
    double integr = calc_integr(error);
    double deriv = calc_deriv(error);
    // Calculate controller output
    double output = prop + integr + deriv;

    // Restrict to max/min
    if (output > m_max)
        output = m_max;
    else if (output < m_min)
        output = m_min;

    return output;
}
