//
//  Strangle.cpp
//  Homework 5
//
//  Created by Yuhang Fan on 3/1/22.
//

#include "Strangle.hpp"
#include <iostream>
using namespace std;

namespace fre
{
double Strangle::Payoff(double z) const
{
    if (z <= K1) return K1 - z;
    else if (z >= K1 && z <= K2) return 0.0;
    else return z - K2;
}
}
