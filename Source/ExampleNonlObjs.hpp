/*
 * ExampleNonlObj.hpp
 *
 *  Created on: Nov 27, 2018
 *      Author: brian
 */

#ifndef NONLINEARSOLVERS_EXAMPLENONLOBJ_HPP_
#define NONLINEARSOLVERS_EXAMPLENONLOBJ_HPP_

#include <cmath>
#include "Nonl_Objective.hpp"



class PowerFunction : public NonlObjective {

  private:
	int evals;

  public:

	// main function (instantiated from virtual objective)
	void Feval(  vector <double> & X, vector <double> & F   )
	{
		evals++;


		for(int i = 0; i < X.size(); i++)
		{
			F[i] = -10;
			for(int j = 0; j < X.size(); j++)
			{
				F[i] = F[i] + X[i]*pow(X[j],i);
			}
		}
	}

	PowerFunction(){
		evals = 0;
	}

	double getEvals(){	return evals; }

};



class ExponentialFunction : public NonlObjective {

  private:
	int evals;

  public:

	// main function (instantiated from virtual objective)
	void Feval(  vector <double> & X, vector <double> & F   )
	{
		evals++;

		for(int i = 0; i < X.size(); i++)
		{
			F[i] = exp(X[i]) - 5;
		}
	}

	ExponentialFunction(){
		evals = 0;
	}

	double getEvals(){	return evals; }

};


#endif /* NONLINEARSOLVERS_EXAMPLENONLOBJ_HPP_ */
