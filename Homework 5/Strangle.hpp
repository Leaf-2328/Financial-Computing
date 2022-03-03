//
//  Strangle.hpp
//  Homework 5
//
//  Created by Yuhang Fan on 3/1/22.
//

#pragma once
#include "Option05.hpp"

namespace fre
{
class Strangle:public EurOption
{
private:
    double K1, K2;
public:
    Strangle(int N_, int K1_, int K2_):EurOption(N_),K1(K1_),K2(K2_){}
    ~Strangle(){};
    double Payoff(double z) const;
};
}
