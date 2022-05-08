//
//  Option.cpp
//  Homework 7
//
//  Created by Yuhang Fan on 3/20/22.
//

#include "Option.hpp"
#include "BinomialTreeModel.hpp"
#include <cmath>
using namespace std;
using namespace fre;

namespace fre
{
Option::~Option(){};
double Call::Payoff(double z) const
{
    if (z > K) return z - K;
    return 0.0;
}


double OptionCalculation::PriceBySnell(const BinomialTreeModel & Model,
                                         BinLattice<double>&PriceTree)
{
    double q = Model.RiskNeutProb();
    int N = pOption->GetN();
    PriceTree.SetN(N);
    double ContVal = 0.0;
    for (int i = 0; i <=N; i++)
    {
        PriceTree.SetNode(N,i,pOption->Payoff(Model.CalculateAssetPrice(N, i)));
    }

    for (int n = N - 1; n >= 0; n--)
    {
        for (int i = 0; i <= n; i++)
        {
            ContVal = (q*PriceTree.GetNode(n+1, i+1) + (1-q)*PriceTree.GetNode(n+1, i))/Model.GetR();
            PriceTree.SetNode(n, i, pOption->Payoff(Model.CalculateAssetPrice(n,i)));
            if (ContVal > PriceTree.GetNode(n,i))
            {
                PriceTree.SetNode(n, i, ContVal);
            }
        }
    }
    return PriceTree.GetNode(0,0);
}

}
