/**
 * @file triangle.hpp
 * @author Pawel Smieja
 * @brief class of triangle decorator for input generator
 * @version 0.1
 * @date 2023-05-31
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef DEC_TRIANGLE_H
#define DEC_TRIANGLE_H

#include "../gen/gen.hpp"

class Dec_triangle : public Decorator
{
public:
    Dec_triangle(Comp_Gen *generator, double amplitude, double period)
        : Decorator(generator), m_amplitude(amplitude), m_period(period), m_time(0.0), output(0.0), prev_output(-m_amplitude) {}
    double simulate() override;

private:
    double m_amplitude, m_period, m_time, output, prev_output;
};

#endif