//
//  Bond.hpp
//  Homework 8
//
//  Created by Yuhang Fan on 3/26/22.
//

# pragma once
#include "NonlinearSolver02.hpp"
namespace fre{
class Bond
{
private:
    double F;
    double T;
    double C;
public:
    Bond(double F_,double T_, double C_):F(F_),T(T_),C(C_){}
    double BondPrice(double yield); // Calculate Bond Price based on yield
    double CalculateDeriv(double yield);
};

class Intermediary: public Bond, public Function
{
private:
    double P; // Bond price at time 0
public:
    Intermediary(double F_,double T_, double C_, double P_):Bond(F_,T_, C_),P(P_){}
    double getPrice(){return P;} // Function to get bond price
    double Value(double yield);
    double Deriv(double yield);
};
}

