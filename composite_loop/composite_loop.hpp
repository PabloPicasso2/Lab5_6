/**
 * @file composite_loop.hpp
 * @author Pawel Smieja
 * @brief class od control loop composite in a Composite (structural design pattern)
 * @version 0.1
 * @date 2023-06-01
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef COMPOSITE_LOOP_H
#define COMPOSITE_LOOP_H

#include "../compon_loop/compon_loop.hpp"
#include <list>

/**
 * The Composite class represents the complex components that may have children.
 * In "normal" control loop are 3 available components: main control loop object (tree), group of Leaf_ARX objects in pararell (branch), group of Leaf_ARX objects in series (branch).
 * Each group of ARX objects (branches) can have few Leaf_ARX objects (leafs).
 * There is also one PID controller (leaf for tree), that is the first element of the control loop
 *
 * If in storage goes new group (branch), then it should be operated by add_series(), remove_series().
 * It's because main SISO is simulated by simulating groups in series
 * Output can be calculated by simulate() or simulate_series() - it doesn't matter
 */
class Composite_Loop : virtual public Compon_Loop
{
public:
	// add new component
	void add_series(SISO *component) override
	{
		m_children_series.push_back(component);
	}
	void add_pararell(SISO *component) override
	{
		m_children_pararell.push_back(component);
	}
	// remove component
	void remove_series(SISO *component) override { m_children_series.remove(component); }
	void remove_pararell(SISO *component) override { m_children_pararell.remove(component); }

	// get output of the component
	virtual double simulate(double input) override;
	// for siso composite, where leafs are in pararell
	double simulate_pararell(double input) override;
	// for siso composite, where leafs are in series
	double simulate_series(double input) override;

private:
	double m_input, m_out_pararell;

	std::list<SISO *> m_children_pararell;
	std::list<SISO *> m_children_series;
};

#endif