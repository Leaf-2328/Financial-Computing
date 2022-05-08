//
//  main.cpp
//  Homework 11
//
//  Created by Yuhang Fan on 4/4/22.
//

#include <iostream>
#include "PathDepOption.hpp"
#include "GmtrAsianCall.hpp"

using namespace std;
using namespace fre;


int main()
{
    double S0=100.0, r=0.03, sigma=0.2;
    MCModel Model(S0,r,sigma);

    double T =1.0/12.0, K=100.0;
    int m=30;

    ArthmAsianCall Option(T,K,m);
    GmtrAsianCall  CVOption(T,K,m);

    long N=30000;
    double epsilon =0.001;
    Option.PriceByVarRedMC(Model,N,CVOption,epsilon);
    cout << "Arithmetic call price = " << Option.GetPrice() << endl
        << "Error = " << Option.GetPricingError() << endl
        << "Delta = " << Option.GetDelta() << endl << endl;

    Option.PriceByMC(Model,N,epsilon);
    cout << "Price by direct MC = " << Option.GetPrice() << endl
        << "Error = " << Option.GetPricingError() << endl
        << "Delta = " << Option.GetDelta() << endl;

    return 0;
}

/*
 Arithmetic call price = 1.42614
 Error = 0.000139575
 Delta = 0.519876

 Price by direct MC = 1.43537
 Error = 0.0120041
 Delta = 0.530064
 */
