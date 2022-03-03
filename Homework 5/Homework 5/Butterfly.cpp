//
//  Butterfly.cpp
//  Homework 5
//
//  Created by Yuhang Fan on 3/1/22.
//

#include <iostream>
#include "Butterfly.hpp"
using namespace std;

namespace fre
{
double ButterflySpreads::Payoff(double z) const
{
    if (z > K1 && z <= (K1+K2)/2) return z - K1;
    else if (z > (K1+K2)/2 && z < K2) return K2 - z;
    else return 0.0;
}
}
