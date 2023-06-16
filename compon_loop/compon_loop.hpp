/**
 * @file compon_loop.hpp
 * @author Pawel Smieja
 * @brief class of control loop component in a Composite (structural design pattern)
 * @version 0.1
 * @date 2023-06-04
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef COMPON_LOOP_H
#define COMPON_LOOP_H

#include <algorithm>
#include <iostream>
#include "../siso/siso.hpp"

/**
 * The base Component class declares common operations for composites and leafs
 */
class Compon_Loop : public SISO
{
public:
	virtual ~Compon_Loop() = default;
	// add new component
	virtual void add_series(SISO *component) = 0;
	virtual void add_pararell(SISO *component) = 0;
	// remove component
	virtual void remove_series(SISO *component) = 0;
	virtual void remove_pararell(SISO *component) = 0;

	// get output of the component/leaf
	virtual double simulate(double input) = 0;
	// for component, where leafs are in series
	virtual double simulate_series(double input) = 0;
	// for component, where leafs are in pararell
	virtual double simulate_pararell(double input) = 0;
};

#endif
