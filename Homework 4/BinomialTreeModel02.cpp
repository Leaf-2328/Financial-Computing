//
//  BinomialTreeModel02.cpp
//  Homework 4
//
//  Created by Yuhang Fan on 2/26/22.
//

#include "BinomialTreeModel02.hpp"
#include <iostream>
#include <cmath>
using namespace std;

namespace fre
{
//compute risk_neitral probability
double BinomialTreeModel::RiskNeutProb() const
{
    return (R-D)/(U-D);
}

//compute the asset price at node n,i
double BinomialTreeModel::CalculateAssetPrice(int n, int i) const
{
    return S0*pow(U,i)*pow(D,n-i);
}

void BinomialTreeModel::UpdateBinomialTreeModel(double S0_, double U_, double D_, double R_)
{
    S0 = S0_; U = U_; D = D_; R = R_;
}

//input and display, check model data
int BinomialTreeModel::GetInputData()
{
    //entering data
    cout << "Enter S0: "; cin >> S0;
    cout << "Enter U: "; cin >> U;
    cout << "Enter D: "; cin >> D;
    cout << "Enter R: "; cin >> R;
    cout << endl;
    
    //making sure that 0<S0, -1<D<U, -1<R
    if (S0<=0.0||U<=-1.0||D<=-1.0||R<=0.0||U<=D||R<=-1.0)
    {
        cout << "Illegal data ranges" << endl;
        cout << "Terminating program" << endl;
        return -1;
    }
    
    //checking for arbitrage
    if (R >= U || R <= D)
    {
        cout << "Arbitrage exists";
        cout << "Terminate program" << endl;
        return -1;
    }
    
    cout << "Input data checked" << endl;
    cout << "There is no arbitrage" << endl << endl;
    
    return 0;
}

int BinomialTreeModel::ValidateInputData() const
{
    //Validate data before calculating asset price on the Binomial Tree
    if (S0<=0.0||U<=0.0||D<=0.0||R<=0.0||U<=D)
    {
        cout << "Illegal data ranges" << endl;
        cout << "Terminating program" << endl;
        return -1;
    }
    
    //checking for arbitrage
    if (R >= U || R <= D)
    {
        cout << "Arbitrage exists";
        cout << "Terminate program" << endl;
        return -1;
    }
    
    cout << "Input data checked" << endl;
    cout << "There is no arbitrage" << endl << endl;
    
    return 0;
}

}
