/**
 * @file gen.hpp
 * @author Pawel Smieja
 * @brief 
 * @version 0.1
 * @date 2023-05-31
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef GEN_H
#define GEN_H

/**
 * @brief class of generator decorator component
 * 
 */
class Comp_Gen
{
public:
    virtual ~Comp_Gen() = default;
    virtual double simulate() = 0;
};

/**
 * @brief class of generator basic-decorator
 * 
 */
class Decorator : public Comp_Gen
{
public:
    Decorator(Comp_Gen *generator) : m_generator(generator) {}
    ~Decorator() = default;

    double simulate() override
    {
        return m_generator->simulate();
    }

protected:
    Comp_Gen *m_generator;
};

#endif
