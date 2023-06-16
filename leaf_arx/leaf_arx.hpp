/**
 * @file leaf_arx.hpp
 * @author Pawel Smieja
 * @brief class of an ARX object (leaf) in a Composite (structural design pattern)
 * @version 0.1
 * @date 2023-06-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef LEAF_ARX_H
#define LEAF_ARX_H

#include "../composite_loop/composite_loop.hpp"
#include <vector>
#include <deque>
#include <string>

/**
 * @brief Few Leaf_ARX objects can be grouped in pararell or in series. 
 * All of the ARX groups (composites) make one SISO object, which can be inserted into contorl loop with input generator and PID controller
 */
class Leaf_ARX : public Composite_Loop
{
public:
    using vector = std::vector<double>;
    using state = std::deque<double>;

    /**
     * @brief Construct a new ARX object
     *
     * @param a coef's of A polynomial (denominator)
     * @param b coef's of B polynomial (numerator)
     * @param k delay
     * @param evar white noise variation
     */
    Leaf_ARX(const vector &a, const vector &b, unsigned k = 0, double evar = 0.0);
    ~Leaf_ARX() = default;

    // simulate output of the ARX object
    double simulate(double input) override;
    // save current parameters to a CSV file
    void save(const std::string &path);

private:
    vector m_a, m_b;
    state m_x, m_y;
    double m_evar;
    unsigned m_k, m_x_depth, m_y_depth;

    void create_states();
    void update_state(state &state, double new_state);
};

#endif
