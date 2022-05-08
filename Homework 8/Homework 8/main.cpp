//
//  main.cpp
//  Homework 8
//
//  Created by Yuhang Fan on 3/25/22.
//

#include <iostream>
#include <iomanip>
#include "Bond.hpp"
#include "Function02.hpp"
#include "NonlinearSolver02.hpp"
using namespace std;
using namespace fre;

int main() {
    double F=100.0;
    double T=3.0;
    double C=1.2;
    double P=98.56;
    
    Intermediary Bond(F,T,C,P);

    double Acc=0.0001;
    double LEnd=0.0;
    double REnd=1.0;
    double Guess=0.2;
    
    // Set target to Bond price at time 0
    double Target = Bond.getPrice();
    NonlinearSolver solver(Target, LEnd, REnd, Acc, Guess);
    
    cout << "Yield by bisection method: " << fixed << setprecision(4)
    << solver.SolveByBisect(&Bond) << endl;
    
    cout << "Yield by Newton-Raphson method: " << fixed << setprecision(4)
    << solver.SolveByNR(&Bond) << endl;
    
    return 0;
}

/*
 Yield by bisection method: 0.0168
 Yield by Newton-Raphson method: 0.0168
 */
