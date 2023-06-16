/**
 * @file sinus.cpp
 * @author Pawel Smieja
 * @brief
 * @version 0.1
 * @date 2023-05-31
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <cmath>
#include "sinus.hpp"

/**
 * @brief return value - initial input decorated by sinus generator
 *
 * @return double
 */
double Dec_sinus::simulate()
{
    // end of previous period is beginning of next period
    if (m_time == m_period)
        m_time = 0.0;

    // calculate sinus output
    output = m_amplitude * sin(2 * 3.14159 * m_time / m_period);

    // next call of simulate() will be for the next sample
    m_time += 1;

    // sinus generator + initial input
    return output + m_generator->simulate();
}