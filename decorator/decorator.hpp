#ifndef DECORATOR_H
#define DECORATOR_H

//#include "../gen/gen.hpp"

class Decorator : public Comp_Gen
{
public:
    Decorator(Comp_Gen *generator) : m_generator(generator) {}
    ~Decorator() = default;

    double generate() override
    {
        return m_generator->generate();
    }

protected:
    Comp_Gen *m_generator;
};

#endif