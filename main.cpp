/**
 * @file main.cpp
 * @author Pawel Smieja
 * @brief program for testing simulation closed control loop for: generator - PID controller - SISO composite
 * @version 0.1
 * @date 2023-05-31
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "compon_loop/compon_loop.hpp"
#include "composite_loop/composite_loop.hpp"
#include "pi/pi.hpp"
#include "pd/pd.hpp"
#include "pid/pid.hpp"
#include "leaf_arx/leaf_arx.hpp"
#include "comp_concrete/comp_concrete.hpp"
#include "square/square.hpp"
#include "sinus/sinus.hpp"
#include "triangle/triangle.hpp"
#include <iostream>
#include <iomanip>

int main()
{
    // output of the loop simulation
    double out_loop = 0.0, set_point = 0.0;

    // create main loop - COMPOSITE
    Compon_Loop *loop1 = new Composite_Loop;

    // create COMPOSITEs - SISO, pararell and series
    Compon_Loop *siso1 = new Composite_Loop;
    Compon_Loop *siso_p = new Composite_Loop;
    Compon_Loop *siso_s = new Composite_Loop;


    // create LEAFs
    PID *pid1 = new PID(-5.0, 5.0, 0.1, 0.1, 0.0);
    Leaf_ARX *arx1 = new Leaf_ARX({1.1, 0.8}, {1.3}, 0, 0);
    Leaf_ARX *arx2 = new Leaf_ARX({1.1, 0.7}, {1.3}, 0, 0);
    Leaf_ARX *arx3 = new Leaf_ARX({2.1, 1.2}, {1.3}, 1, 0);

    // add LEAFs to COMPOSITEs
    loop1->add_series(pid1);
    siso_p->add_pararell(arx1);
    siso_p->add_pararell(arx2);
    siso_s->add_series(arx3);

    // add COMPOSITEs to main COMPOSITE (branches to tree)
    siso1->add_series(siso_p);
    siso1->add_series(siso_s);
    loop1->add_series(siso1);


    // new input generator
    Comp_Gen *generator = new Comp_Concrete(2.0);
    // parameters for decorator
    double period1 = 12.0, amplitude1 = 1.0;
    // decorating separately
    //Comp_Gen *generator1 = new Dec_square(generator, amplitude1, period1);
    Comp_Gen *generator1 = new Dec_sinus(generator, amplitude1, period1);

    // set SetPoint for PID controller
    pid1->set_setPoint(generator1->simulate());
    std::cout << "Symulacja petli\n\n";


    // view loop output for x periods of generator
    for (int i = 0; i < period1; ++i)
    {
        set_point = generator1->simulate();
        std::cout << "Set point = " << set_point << "\n";
        pid1->set_setPoint(set_point);
        // argument of loop->simulate(double) is previous output of the loop
        out_loop = loop1->simulate(out_loop);
        std::cout << "out_loop = " << out_loop << "\n\n";
    }


    // get memory back
    delete arx1;
    delete arx2;
    delete arx3;
    delete siso_p;
    delete siso_s;
    delete siso1;
    delete loop1;
    delete pid1;

    delete generator;
    delete generator1;

    std::cin.get();
}