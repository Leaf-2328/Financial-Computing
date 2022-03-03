//
//  Option.hpp
//  HomeWork 1
//
//  Created by Yuhang Fan on 2/3/22.
//

#pragma once
namespace fre
{
//pricing European option
double PriceByCRR(double S0, double U, double D, double R, int N, double K);

//computing call payoff
double CallPayoff(double z, double K);

//HW1 calculating European option using CRR formula
double HW1Factorial(int n);
double HW1PriceByCRR(double S0, double U, double D, double R, int N, double K);

}
