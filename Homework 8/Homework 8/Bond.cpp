//
//  Bond.cpp
//  Homework 8
//
//  Created by Yuhang Fan on 3/26/22.
//

#include "Bond.hpp"
#include <cmath>
namespace fre
{
double Bond::BondPrice(double yield)
{
    double Price = 0.0;
    for (int i = 1; i <=T; i++)
    {
        Price += C*exp(-yield*i);
    }
    Price += F*exp(-yield*T);
    
    return Price;
}

double Bond::CalculateDeriv(double yield)
{
    double DeriveValue =0.0;
    for (int i = 1; i<= T; i++)
    {
        DeriveValue += -i*C*exp(-yield*i);
    }
    DeriveValue += -T*F*exp(-yield*T);
    
    return DeriveValue;
}

double Intermediary::Value(double yield)
{
    return BondPrice(yield);
}

double Intermediary::Deriv(double yield)
{
    return CalculateDeriv(yield);
}

}
