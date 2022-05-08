//
//  PathDepOption.hpp
//  Homework 10
//
//  Created by Yuhang Fan on 4/3/22.
//

#pragma once
#include "MCModel.hpp"
namespace fre {
    class PathDepOption
    {
    protected:
        double Price, PricingError, delta, gamma;
        int m;
        double K;
        double T;
    public:
        PathDepOption(double T_, double K_, int m_) :Price(0.0), PricingError(0.0),delta(0.0),gamma(0.0),T(T_), K(K_), m(m_)
        {}
        virtual ~PathDepOption() {}
        virtual double Payoff(const SamplePath& S) const = 0; // Cannot change protected data, cannot change samplepath
        double PriceByMC(const MCModel& Model, long N, double epsilon); // Cannot change Model
        double PriceByVarRedMC(const MCModel& Model, long N, PathDepOption& CVOption, double epsilon);
        virtual double PriceByBSFormula(const MCModel& Model) { return 0.0; } //  Can I change this to pure virtual?
        double GetT() { return T; }
        double GetPrice() { return Price; }
        double GetPricingError() { return PricingError; }
        double GetDelta() { return delta; }
        double GetGamma() { return gamma;}
    };

    class DifferenceOfOptions : public PathDepOption
    {
    private:
        PathDepOption* Ptr1; //Arthmetic
        PathDepOption* Ptr2; // Geometic
        // Base class pointer --> polymorphism
    public:
        DifferenceOfOptions(double T_, double K_, int m_, PathDepOption* Ptr1_, PathDepOption* Ptr2_) :
        PathDepOption(T_, K_, m_), Ptr1(Ptr1_), Ptr2(Ptr2_){ }
    double Payoff(const SamplePath& S) const
        {
            return Ptr1->Payoff(S) - Ptr2->Payoff(S);
        }
    };

    class ArthmAsianCall : public PathDepOption
    {
    public:
        ArthmAsianCall(double T_, double K_, int m_) :PathDepOption(T_, K_, m_) {}
        double Payoff(const SamplePath& S) const; // have to include const, because it is overwriting (have to be the same as base class function)
        
    };
}
