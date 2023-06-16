/**
 * @file comp_concrete.hpp
 * @author Pawel Smieja
 * @brief class of concrete component (basic input) for generator decorator
 * @version 0.1
 * @date 2023-05-31
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef COMP_CONCRETE_H
#define COMP_CONCRETE_H

#include "../gen/gen.hpp"

class Comp_Concrete: public Comp_Gen
{
public:
    Comp_Concrete(double value) : m_value(value) {}
    ~Comp_Concrete() = default;

    double simulate() override { return m_value; }

private:
    double m_value;
};

#endif