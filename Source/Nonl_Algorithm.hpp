/*
 * Nonl_Algorithm.hpp
 *
 *  Created on: Nov 27, 2018
 *      Author: brian
 */

#ifndef NONLINEARSOLVERS_NONL_ALGORITHM_HPP_
#define NONLINEARSOLVERS_NONL_ALGORITHM_HPP_


// Parallel commands
#ifndef ROOT_ID
#define ROOT_ID 0 // id of root process
#endif

// Standard includes
#include <vector>

// local includes
#include "Nonl_Objective.hpp"

class NonlAlgorithm{

  protected:
	// objective class used for objective evaluations
	NonlObjective * FobjPtr;

  public:
	// Pure virtual minimizer
	virtual void findZero( std::vector <double> & X ) = 0;

	// set the objective
	void setFobjPtr( NonlObjective & obj ){ FobjPtr = &obj; }

};



#endif /* NONLINEARSOLVERS_NONL_ALGORITHM_HPP_ */
