/*
 * NewtonsMethod.cpp
 *
 *  Created on: Nov 27, 2018
 *      Author: brian
 */

#include "NewtonsMethod.hpp"


void NewtonsMethod::findZero( std::vector <double> & X  )
{
	int N = X.size();

	vector <double> dX(N,dXJacobian);
	vector <double> XdiffNeg(N,0);
	vector <double> F(N,fTol*2);
	vector < vector<double> > J(N, vector<double>(N));

	if ( verbose > 0 && getProcID() == ROOT_ID)
	{
		cout << "Newtons method iteration starting with " << endl;
		cout << "X = "; print1DVector(X);
	}

	int k = 0;

	// Compute F
	FobjPtr->Feval(X,F);

	while( k < maxIter)
	{


		// Compute approximate jacobian
		FobjPtr->JacobianApproximation(X,dX,J);

		// solves the system Ax = b by lu factorization
		// void luSolve( vector<vector<double>> & A, vector<double> & b, vector<double> & x )
		luSolve( J, F, XdiffNeg );


		if ( verbose > 1 && getProcID() == ROOT_ID)
		{
			cout << endl << "At iter " << k << endl;
			cout << "X = "; print1DVector(X);
			cout << "XdiffNeg = "; print1DVector(XdiffNeg);
			cout << "F = "; print1DVector(F);
			cout << "J = "; print2DVector(J);
		}


		for(int i = 0; i < N; i++)
		{
			X[i] = X[i] - XdiffNeg[i];
		}


		// Compute F
		FobjPtr->Feval(X,F);

		if( absMean( XdiffNeg ) < xTol || absMean(F) < fTol || F[0] != F[0] || isinf(F[0]) )
		{
			break;
		}
		k++;


	}

	if ( verbose > 0 && getProcID() == ROOT_ID)
	{
		cout << "Newtons method iteration finished after " << k << " iterations with " << endl;
		cout << "X = "; print1DVector(X);
		cout << "F = "; print1DVector(F);
	}





}


