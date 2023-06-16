/**
 * @file composite_loop.cpp
 * @author Pawel Smieja
 * @brief class of control loop composite in a Composite (structural design pattern).
 * @version 0.1
 * @date 2023-06-01
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "composite_loop.hpp"
#include <iostream>

double Composite_Loop::simulate(double input)
{
    double out_pararell = simulate_pararell(input);
    // std::cout << "out_pararell = " << out_pararell << "\n";
    double out_series = simulate_series(out_pararell);
    // std::cout << "out_series = " << out_series << "\n";

    return out_series;
}

double Composite_Loop::simulate_pararell(double input)
{
    // if there are no m_children_pararell, then input of simulate_pararell is copied to output
    double output = input;
    double xx = 0.0;
    for (SISO *component : m_children_pararell)
    {
        // PID output comes to every SISO_pararell input
        output += component->simulate(input);
    }
    return output;
}

double Composite_Loop::simulate_series(double input)
{
    // output of the SISO_pararell is an input for first SISO_series object
    double output = input;
    for (SISO *component : m_children_series)
    {
        // output of previous SISO_series is an input for next SISO_series
        output = component->simulate(output);
    }
    return output;
}