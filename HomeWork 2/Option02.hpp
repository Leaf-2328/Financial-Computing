//
//  Option02.hpp
//  HomeWork 2
//
//  Created by Yuhang Fan on 2/10/22.
//

#pragma once
namespace fre
{
//pricing European option
double *PriceByCRR(double S0, double U, double D, double R, int N, double K, double (*Payoff)(double z, double K));

//computing call payoff
double CallPayoff(double z, double K);

//computing put payoff
double PutPayoff(double z, double K);

//computing digit call payoff
double DigitCallPayoff(double z, double K);

//computing digit put payoff
double DigitPutPayoff(double z, double K);

//get input data for strike price and steps to expiry
void GetInputData(int &N, double &K);

}
