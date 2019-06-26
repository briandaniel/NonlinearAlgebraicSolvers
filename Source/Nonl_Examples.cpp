/*
 * Nonl_Examples.cpp
 *
 *  Created on: Nov 28, 2018
 *      Author: brian
 */


#include "Nonl_Examples.hpp"


void testNewtonsMethod()
{

	// Object
	// ExponentialFunction Fobj;
	PowerFunction Fobj;

	// Vector of optization variables
	int Nparam = 5;
	vector <double> X(Nparam,2);
	X[0] = 1;

	// Algorithm
	NewtonsMethod newt;
	newt.setFobjPtr(Fobj);

	// void setParams( double xTolIn, double fTolIn, double dXJacobianIn, int maxIterIn, int verboseIn )
	newt.setParams(1e-7,1e-7,1e-7,10,2);

	newt.findZero(X);

	cout << "Optimization used " << Fobj.getEvals() << " function evaluations." << endl;

}
