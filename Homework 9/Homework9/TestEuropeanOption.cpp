// TestEuropeanOption.cpp
// Test program for the exact solutions of European options.
// (C) Datasim Component Technology BV 2003-2006
//

#include "EuropeanOption.hpp"
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    // Call option on a stock
    EuropeanOption callOption;
    cout << callOption.GetOptType() << " option on a stock: " << callOption.Price() << endl;

    // Put option on a stock
    //  Calculate the price of a three-month European put option on a non-dividend-paying stock with a strike price of $50 when the current stock price is $50, the risk-free interest rate is 10% per annum, and the volatility is 30% per annum.
    double T = 0.25, K = 50.0, U = 50.0, r = 0.10, sig = 0.30;
    
    char OptionType = 'P';
    EuropeanOption putOption(r,sig,K,T,U,OptionType);
    cout << putOption.GetOptType() << " option on a stock: " << putOption.Price() << endl;

    // Put option with a dividend of $1.50 is expected in two months
    double DPV = 1.5*exp(-r*2/12); // Present Value of dividend payment
    double U_ = U-DPV; // New price with present Value of dividend payment subtracted
    putOption.SetU(U_);
    cout << putOption.GetOptType() << " option with dividend: " << putOption.Price() << endl;
    
    return 0;
}

/*
 Call option on a stock: 2.13293
 Put option on a stock: 2.37561
 Put option with dividend: 3.03039
 */
