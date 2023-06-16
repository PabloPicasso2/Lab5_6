/**
 * @file sinus.hpp
 * @author Pawel Smieja
 * @brief class of sinus decorator for input generator
 * @version 0.1
 * @date 2023-05-31
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef DEC_SINUS_H
#define DEC_SINUS_H

#include "../gen/gen.hpp"

class Dec_sinus : public Decorator
{
public:
    Dec_sinus(Comp_Gen *generator, double amplitude, double period)
        : Decorator(generator), m_amplitude(amplitude), m_period(period), m_time(0.0) {}
    double simulate() override;

private:
    double m_amplitude, m_period, m_time, output;
};

#endif