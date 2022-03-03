//
//  main.cpp
//  Homework 5
//
//  Created by Yuhang Fan on 2/26/22.
//

#include <iostream>
#include <iomanip>
#include "BinomialTreeModel02.hpp"
#include "Option05.hpp"
#include "Strangle.hpp"
#include "Butterfly.hpp"
#include "DoubleDigitOpt.hpp"

using namespace std;
using namespace fre;

int main() {
    int N = 8;
    double U = 1.15125, D = 0.86862, R = 1.00545;
    double S0 = 106.00, K1 = 100, K2 = 110;
    BinomialTreeModel Model(S0, U, D, R);
    
    DoubleDigitOpt doubleDigitOpt(N,K1,K2);
    OptionCalculation doubleDigitOptCalculation(&doubleDigitOpt);
    cout << "European double digit option price = " << fixed << setprecision(2) << doubleDigitOptCalculation.PriceByCRR(Model) << endl;
    
    Strangle strangle(N,K1,K2);
    OptionCalculation strangleCalculation(&strangle);
    cout << "European strangle option price = " << fixed << setprecision(2) << strangleCalculation.PriceByCRR(Model) << endl;
    
    ButterflySpreads butterflyspreads(N,K1,K2);
    OptionCalculation butterflyspreadsCalculation(&butterflyspreads);
    cout << "European butterfly spreads option price = " << fixed << setprecision(2) << butterflyspreadsCalculation.PriceByCRR(Model) << endl;
    
    return 0;
}

/*
 
 European double digit option price = 0.26
 European strangle option price = 28.39
 European butterfly spreads option price = 1.04
 
 */
