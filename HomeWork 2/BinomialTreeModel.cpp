//
//  BinomialTreeModel.cpp
//  HomeWork 2
//
//  Created by Yuhang Fan on 2/10/22.
//


#include "BinomialTreeModel.hpp"
#include <iostream>
#include <cmath>
using namespace std;

namespace fre
{
//compute risk_neitral probability
double RiskNeutProb(double U, double D, double R)
{
    return (R-D)/(U-D);
}

//compute the asset price at node n,i
double CalculateAssetPrice(double S0, double U, double D, int n, int i)
{
    return S0*pow(U,i)*pow(D,n-i);
}

int ValidateInputData(const double& S0, const double& U, const double& D, const double& R)
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


//input and display, check model data
int GetInputData(double& S0, double& U, double& D, double& R)
{
    //entering data
    cout << "Enter S0: "; cin >> S0;
    cout << "Enter U: "; cin >> U;
    cout << "Enter D: "; cin >> D;
    cout << "Enter R: "; cin >> R;
    cout << endl;
    
    //Validate data before calculating asset price on the Binomial Tree
    if (ValidateInputData(S0, U, D, R)!= 0)
    {
        return -1;
    };
    
    return 0;
}

}
