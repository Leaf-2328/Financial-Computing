//
//  main.cpp
//  Homework 7
//
//  Created by Yuhang Fan on 3/20/22.
//

#include <iostream>
#include <cmath>
#include "BinomialTreeModel.hpp"
#include "Option.hpp"


using namespace fre;
using namespace std;

int main() {
    double S0=106.0;
    double r=0.058;
    double sigma=0.46;
    double T=(double)9/12;
    double K=100.0;
    int N=8;
    
    double h = T/N;
    double U = exp(sigma*sqrt(h));
    double D = 1/U;
    double R = exp(r*h);
    
    cout << setiosflags(ios::fixed) << setprecision(5);
    
    cout << "S0 = " << S0 << endl << "r = " << r << endl;
    cout << "sigma = " << sigma << endl << "T = " << T << endl;
    cout << "K = " << K << endl << "N = " << N << endl << endl;
    cout << "U = " << U << endl;
    cout << "D = " << D << endl;
    cout << "R = " << R << endl << endl;
    
    BinomialTreeModel Model(S0, U, D, R);
    Call call(N, K);
    OptionCalculation callCalculation(&call);
    BinLattice<double> callPriceTree;

    cout << "American call option price = "
    << fixed << setprecision(3) << callCalculation.PriceBySnell(Model,callPriceTree) << endl;
    return 0;
}

/*
 S0 = 106.00000
 r = 0.05800
 sigma = 0.46000
 T = 0.75000
 K = 100.00000
 N = 8

 U = 1.15125
 D = 0.86862
 R = 1.00545

 American call option price = 21.682
 */
