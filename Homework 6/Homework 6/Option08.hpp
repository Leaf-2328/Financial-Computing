//
//  Option08.hpp
//  Homework 6
//
//  Created by Yuhang Fan on 3/20/22.
//

#pragma once
#include "BinomialTreeModel02.hpp"
#include "BinLattice02.hpp"

namespace fre
{
class Option
{
private:
    Option():N(0){}
    Option(const Option &option):N(option.N){}
protected:
    int N;
public:
    Option(int N_):N(N_){}
    int GetN() const { return N;}
    virtual double Payoff(double z) const = 0;
    virtual ~Option() = 0;
};

class Call: public Option
{
private:
    double K;
public:
    Call(int N_, double K_):Option(N_),K(K_){}
    ~Call(){}
    double Payoff(double z) const;
};

class Put: public Option
{
private:
    double K;
public:
    Put (int N_, double K_):Option(N_),K(K_){}
    ~Put(){}
    double Payoff (double z) const;
};

class OptionCalculation
{
private:
    Option* pOption;
    OptionCalculation():pOption(0){}
    OptionCalculation(const OptionCalculation& optionCalculation):
    pOption(optionCalculation.pOption){}
public:
    OptionCalculation(Option *pOption_):pOption(pOption_){}
    ~OptionCalculation(){}
    double PriceByCRR(const BinomialTreeModel& Model);
    double PriceBySnell(const BinomialTreeModel&Model,
                        BinLattice<double>&PriceTree,
                        BinLattice<bool>&StoppingTree);
    //Homework 6 PriceByCRR
    double PriceByCRR(const BinomialTreeModel&Model, BinLattice<double>& PriceTree, BinLattice<double>& XTree, BinLattice<double>& YTree);
};

}
