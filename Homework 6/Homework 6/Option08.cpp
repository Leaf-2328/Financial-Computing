//
//  Option08.cpp
//  Homework 6
//
//  Created by Yuhang Fan on 3/20/22.
//

#include "Option08.hpp"
#include "BinomialTreeModel02.hpp"
#include "BinLattice02.hpp"
#include <iostream>
#include <cmath>
using namespace std;

namespace fre
{
Option::~Option(){}
double Call::Payoff(double z) const
{
    if (z > K) return z - K;
    return 0.0;
}
double Put::Payoff(double z) const
{
    if (z < K) return K - z;
    return 0.0;
}

double OptionCalculation::PriceByCRR(const BinomialTreeModel & Model)
{
    double q = Model.RiskNeutProb();
    int N = pOption->GetN();
    vector <double> Price(N+1);
    for (int i = 0; i <= N; i++)
    {
        Price[i] = pOption->Payoff(Model.CalculateAssetPrice(N, i));
    }
    for (int n = N - 1; n>=0;n--)
    {
        for (int i = 0;i <= n; i++)
        {
            Price[i] =(q*Price[i+1]+(1-q)*Price[i])/Model.GetR();
        }
    }
    return Price[0];
}

double OptionCalculation::PriceBySnell(const BinomialTreeModel & Model,
                                         BinLattice<double>&PriceTree, BinLattice<bool>&StoppingTree)
{
    double q = Model.RiskNeutProb();
    int N = pOption->GetN();
    PriceTree.SetN(N);
    StoppingTree.SetN(N);
    double ContVal = 0.0;
    for (int i = 0; i <=N; i++)
    {
        PriceTree.SetNode(N,i,pOption->Payoff(Model.CalculateAssetPrice(N, i)));
        StoppingTree.SetNode(N,i,1);
    }

    for (int n = N - 1; n >= 0; n--)
    {
        for (int i = 0; i <= n; i++)
        {
            ContVal = (q*PriceTree.GetNode(n+1, i+1) + (1-q)*PriceTree.GetNode(n+1, i))/Model.GetR();
            PriceTree.SetNode(n, i, pOption->Payoff(Model.CalculateAssetPrice(n,i)));
            StoppingTree.SetNode(n,i,1);
            if (ContVal > PriceTree.GetNode(n,i))
            {
                PriceTree.SetNode(n, i, ContVal);
                StoppingTree.SetNode(n,i,0);
            }
            else if (PriceTree.GetNode(n, i) == 0.0)
            {
                StoppingTree.SetNode(n,i,0);
            }
        }
    }
    return PriceTree.GetNode(0,0);
}

double OptionCalculation::PriceByCRR(const BinomialTreeModel&Model, BinLattice<double>& PriceTree, BinLattice<double>& XTree, BinLattice<double>& YTree)
{
    double q = Model.RiskNeutProb();
    int N = pOption->GetN();
    PriceTree.SetN(N);
    XTree.SetN(N);
    YTree.SetN(N);
    double r = Model.GetR();
    double deltaVal = 0.0;
    double MoneyMarketP = 0.0;
    double ContVal = 0.0;
    
    for (int i = 0; i <= N; i++)
    {
        PriceTree.SetNode(N,i,pOption->Payoff(Model.CalculateAssetPrice(N, i)));
        XTree.SetNode(N,i,deltaVal);
        YTree.SetNode(N,i,MoneyMarketP);
    }
    
    for (int n = N-1; n >= 0; n--)
    {
        for (int i = 0; i <= n; i++)
        {
            ContVal = (q*PriceTree.GetNode(n+1, i+1) + (1-q)*PriceTree.GetNode(n+1, i))/r;
            PriceTree.SetNode(n, i, ContVal);
            
            deltaVal = (PriceTree.GetNode(n+1, i+1) - PriceTree.GetNode(n+1, i))/(Model.CalculateAssetPrice(n+1, i+1) - Model.CalculateAssetPrice(n+1, i));
            XTree.SetNode(n, i, deltaVal);
            
            MoneyMarketP = (PriceTree.GetNode(n+1, i) - XTree.GetNode(n,i)*Model.CalculateAssetPrice(n+1, i))/pow(r,n+1);
            YTree.SetNode(n, i, MoneyMarketP);
            
            
        }
    }
    return XTree.GetNode(0,0)*Model.CalculateAssetPrice(0, 0) + YTree.GetNode(0,0);
}

}
