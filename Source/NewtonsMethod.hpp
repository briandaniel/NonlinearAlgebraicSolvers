/*
 * NewtonsMethod.hpp
 *
 *  Created on: Nov 27, 2018
 *      Author: brian
 */

#ifndef NONLINEARSOLVERS_NEWTONSMETHOD_HPP_
#define NONLINEARSOLVERS_NEWTONSMETHOD_HPP_

#include "UtilityFunctions/utilityFunctions.hpp"
#include "Nonl_Algorithm.hpp"

class NewtonsMethod : public NonlAlgorithm {

  private:

	// parameters
	double dXJacobian;
	double xTol;
	double fTol;
	int maxIter;
	int verbose; // verbose output from optimization?


  public:

	void findZero( std::vector <double> & X );

	// set the parameters
	void setParams( double xTolIn, double fTolIn, double dXJacobianIn, int maxIterIn, int verboseIn )
	{
		xTol = xTolIn;
		fTol = fTolIn;
		dXJacobian = dXJacobianIn;
		maxIter = maxIterIn;
		verbose = verboseIn;

	}

    // default constructor/destructor
	NewtonsMethod()
	{
		dXJacobian = 1e-6;
		xTol = 1e-5;
		fTol = 1e-5;
		maxIter = 100;
		verbose = 0;

	}


	~NewtonsMethod(){}


};


#endif /* NONLINEARSOLVERS_NEWTONSMETHOD_HPP_ */
