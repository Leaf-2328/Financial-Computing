//
//  DoubleDigitOpt.cpp
//  Homework 5
//
//  Created by Yuhang Fan on 3/1/22.
//

#include "DoubleDigitOpt.hpp"

namespace fre
{
double DoubleDigitOpt::Payoff(double z) const
{
    if (K1<z && z<K2) return 1.0;
    return 0.0;
}

}
