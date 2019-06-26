/*
 * Nonl_Objective.cpp
 *
 *  Created on: Nov 27, 2018
 *      Author: brian
 */

#include "Nonl_Objective.hpp"

void NonlObjective::JacobianApproximation( vector <double> & X, vector <double> & dX, vector< vector<double> > & J )
{

	int N = X.size();

	vector <double> XdX (N,0);

	// create F and FdX of correct size to match data
	vector <double> F(J.size(),0);
	vector <double> FdX(J.size(),0);

	// evaluate at the starting value
	Feval(X,F);

	for(int j = 0; j <  N; j++ )
	{

		for(int k = 0; k < N; k++ )
		{
			XdX[k] = X[k];
		}
		XdX[j] = XdX[j] + dX[j];

		Feval(XdX, FdX);

		for(int i = 0; i < J.size(); i++ )
		{
			J[i][j] = (FdX[i] - F[i])/dX[j];
		}
	}


}



