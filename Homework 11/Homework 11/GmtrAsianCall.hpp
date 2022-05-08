//
//  GmtrAsianCall.hpp
//  Homework 11
//
//  Created by Yuhang Fan on 4/4/22.
//

#pragma once
#include "PathDepOption.hpp"
namespace fre {
    class GmtrAsianCall : public PathDepOption
    {
    public:
        GmtrAsianCall(double T_, double K_, int m_) : PathDepOption(T_, K_, m_) {}
        double Payoff(const SamplePath& S) const;
        double PriceByBSFormula(const MCModel& Model);
    };
}
