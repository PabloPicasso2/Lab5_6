/**
 * @file leaf_arx.cpp
 * @author Pawel Smieja
 * @brief class of a leaf object in a Composite (structural design pattern).
 * @version 0.1
 * @date 2023-06-01
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "leaf_arx.hpp"
#include <numeric>
#include <fstream>

Leaf_ARX::Leaf_ARX(const vector &a, const vector &b, unsigned k, double evar)
{
    m_a = a;
    m_b = b;
    m_k = k;
    m_evar = evar;

    create_states();
}

double Leaf_ARX::simulate(double x)
{
    update_state(m_x, x);

    auto y = std::inner_product(m_x.begin(), m_x.end(), m_b.begin(), 0.0) - std::inner_product(m_y.begin(), m_y.end(), m_a.begin(), 0.0);

    update_state(m_y, y);

    return y;
}

void Leaf_ARX::create_states()
{
    if (m_k)
    {
        auto delay = vector(m_k, 0.0);
        delay.insert(delay.end(), m_b.begin(), m_b.end());
        m_b = delay;
    }

    // size(x) must be eqal to size(B) - the same with size(y)=size(A)
    m_x_depth = m_b.size();
    m_y_depth = m_a.size();
    m_x = state(m_x_depth, 0.0);
    m_y = state(m_y_depth, 0.0);
}

void Leaf_ARX::update_state(state &state, double new_state)
{
    state.pop_back();
    state.push_front(new_state);
}

void Leaf_ARX::save(const std::string &path)
{
    std::ofstream file(path);

    file << "a = ";
    for (const auto &coef : m_a)
    {
        file << coef << "\n";
    }

    file << "b = ";
    for (const auto &coef : m_b)
    {
        file << coef << "\n";
    }

    file << "k = " << m_k << "\n";
    file << "var = " << m_evar << "\n";
}