//
//  main.cpp
//  Homework 6
//
//  Created by Yuhang Fan on 3/20/22.
//

#include "BinomialTreeModel02.hpp"
#include "Option08.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
using namespace fre;

int main() {
    int N = 8;
    double U = 1.15125, D = 0.86862, R = 1.00545;
    double S0 = 106.00, K = 100.00;
    BinomialTreeModel Model(S0, U, D, R);
    
    ofstream fout;
    fout.open("Results.txt");
    
    Call call(N, K);
    OptionCalculation callCalculation(&call);
    
    BinLattice<double> callPriceTree;
    BinLattice<double> callXTree;
    BinLattice<double> callYTree;
    fout << "European call option price = "
    << fixed << setprecision(3) << callCalculation.PriceByCRR(Model) << endl;
    
    fout << "European call prices by HW6 PriceByCRR:"
    << fixed << setprecision(3) << callCalculation.PriceByCRR(Model, callPriceTree, callXTree, callYTree)
    << endl << endl;
    
    fout << "Stock positions in replicating strategy:" << endl << endl;
    callXTree.Display(fout);
    fout << "Money market account positions in replicating strategy:" << endl << endl;
    callYTree.Display(fout);
    
    Put put(N, K);
    OptionCalculation putCalculation(&put);
    
    BinLattice<double> putPriceTree;
    BinLattice<double> putXTree;
    BinLattice<double> putYTree;
    fout << "European put option price = "
    << fixed << setprecision(3) << putCalculation.PriceByCRR(Model) << endl;
    
    fout << "European put prices by HW6 PriceByCRR:"
    << fixed << setprecision(3) << putCalculation.PriceByCRR(Model, putPriceTree, putXTree, putYTree)
    << endl << endl;
    
    fout << "Stock positions in replicating strategy:" << endl << endl;
    putXTree.Display(fout);
    fout << "Money market account positions in replicating strategy:" << endl << endl;
    putYTree.Display(fout);
    return 0;
}
