//
//  Option.cpp
//  HomeWork 1
//
//  Created by Yuhang Fan on 2/3/22.
//

#include "Option.hpp"
#include "BinomialTreeModel.hpp"
#include <iostream>
#include <cmath>
using namespace std;
namespace fre
{
double PriceByCRR(double S0, double U, double D, double R, int N, double K)
{
    double q = RiskNeutProb(U, D, R);
    double Price[N+1];
    
    for (int i = 0; i < sizeof(Price)/sizeof(Price[0]); i++)
    {
        Price[i] = 0.0;
    }
    
    for (int i = 0; i <= N; i++)
    {
        Price[i] = CallPayoff(CalculateAssetPrice(S0, U, D, N, i),K);
    }
    
    for (int n = N-1; n >= 0; n--)
    {
        for (int i = 0; i <= n; i ++)
        {
            Price[i] = (q*Price[i+1] + (1-q)*Price[i])/R;
        }
    }
    
    return Price[0];
}

double CallPayoff(double z, double K)
{
    if (z>K) return z-K;
    return 0.0;
}

double HW1Factorial(int n)
{
    int res = 1.0;
    for (int i = 1; i <= n; i ++)
    {
        res = res * i;
    }
    return res;
}

double HW1PriceByCRR(double S0, double U, double D, double R, int N, double K)
{
    double q = RiskNeutProb(U, D, R);
    double Price = 0.0;
    
    double FactorialN = HW1Factorial(N);
    for (int i = 0; i <= N; i++)
    {
        Price = Price + FactorialN/(HW1Factorial(i)*HW1Factorial(N-i))*pow(q,i)*pow(1-q,N-i)*CallPayoff(CalculateAssetPrice(S0, U, D, N, i),K);
    }
    Price = Price/pow(R,N);
    return Price;
}

}
