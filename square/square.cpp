/**
 * @file square.cpp
 * @author Pawel Smieja
 * @brief 
 * @version 0.1
 * @date 2023-05-31
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "square.hpp"

/**
 * @brief return value - initial input decorated by square generator
 * 
 * @return double 
 */
double Dec_square::simulate()
{
    // end of previous period is beginning of next period
    if (m_time == m_period)
        m_time = 0.0;

    // calculate square output
    if (m_time < m_period / 2.0)
        output = -m_amplitude;
    else
        output = m_amplitude;

    // next call of simulate() will be for the next sample
    m_time += 1;

    // square generator + initial input
    return output + m_generator->simulate();
}
