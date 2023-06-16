/**
 * @file triangle.cpp
 * @author Pawel Smieja
 * @brief
 * @version 0.1
 * @date 2023-05-31
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <cmath>
#include "triangle.hpp"

/**
 * @brief return value - initial input decorated by triangle generator
 *
 * @return double
 */
double Dec_triangle::simulate()
{
    // end of previous period is beginning of next period
    if (m_time == m_period)
        m_time = 0.0;

    output = (2 * m_amplitude / 3.14) * asin(sin(2 * 3.14 * m_time / m_period));

    // next call of simulate() will be for the next sample
    m_time += 1;

    // triangle generator + initial input
    return output + m_generator->simulate();
}
