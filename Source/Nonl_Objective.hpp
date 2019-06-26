/*
 * Nonl_Objective.hpp
 *
 *  Created on: Nov 27, 2018
 *      Author: brian
 */

#ifndef NONLINEARSOLVERS_NONL_OBJECTIVE_HPP_
#define NONLINEARSOLVERS_NONL_OBJECTIVE_HPP_


using namespace std;

// Parallel commands
#ifndef ROOT_ID
#define ROOT_ID 0 // id of root process
#endif

// Standard includes
#include <vector>
#include <mpi.h>


// Evaluates to a single double return
class NonlObjective{

  public:
	// Pure virtual objective evaluation
	virtual void  Feval( vector <double> & X, vector <double> & F ) = 0;

	// gradient evaluation
	void JacobianApproximation( vector <double> & X, vector <double> & dX, vector< vector<double> > & J );


};



#endif /* NONLINEARSOLVERS_NONL_OBJECTIVE_HPP_ */
