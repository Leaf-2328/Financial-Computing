//
//  main.cpp
//  HW1
//
//  Created by Yuhang Fan on 2/3/22.
//

#include "BinomialTreeModel.hpp"
#include "Option.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
using namespace fre;

int main() {
    double u = 1.15125, d = 0.86862, r = 1.00545;
    double s0 = 106.00;
    double k = 100.00;
    const int N = 8;
    
    cout << "u = " << u << ",d = " << d << ",r = " << r << "," << endl;
    cout << "s0 = " << s0 << ",k = " << k << "," << endl;
    cout << "N = " << N << "," << endl << endl;
    
    double optionPrice01 = PriceByCRR(s0, u, d, r, N, k);
    cout << "European call option price = " << fixed << setprecision(2) << optionPrice01 << endl;
    
    double optionPrice02 = HW1PriceByCRR(s0, u, d, r, N, k);
    cout << "Calculate European call option price by HW1 Function: " << fixed << setprecision(2)
         << optionPrice02 << endl << endl;

    return 0;
}

/*
 u = 1.15125,d = 0.86862,r = 1.00545
 s0 = 106,k = 100
 N = 8,

 Europrn call option price = 21.68
 Calculate Europrn call option price by HW1 Function: 21.68

*/
