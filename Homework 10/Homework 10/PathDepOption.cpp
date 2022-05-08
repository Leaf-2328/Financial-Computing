//
//  PathDepOption.cpp
//  Homework 10
//
//  Created by Yuhang Fan on 4/3/22.
//

#include "PathDepOption.hpp"
#include <cmath>
#include <vector>

namespace fre {
    void Rescale(SamplePath& S, double x)
    {
        int m = S.size();
        for (int j = 0; j < m; j++) S[j] = x * S[j];
    }

    double PathDepOption::PriceByMC(const MCModel& Model, long N, double epsilon)
    {
        double H = 0.0 , Hsq = 0.0, Heps = 0.0, Hgamma = 0.0;
        SamplePath S(m); // S(m) is empty, we dont have any price
        for (long i = 0; i < N; i++)
        {
            Model.GenerateSamplePath(T, m, S); // Populate a path
            H = (i * H + Payoff(S)) / (i + 1.0); //running average
            
            Hsq = (i * Hsq + pow(Payoff(S), 2.0)) / (i + 1.0);
            Rescale(S, 1.0 + epsilon);
            Heps = (i * Heps + Payoff(S)) / (i + 1.0);
            
            Rescale(S, (1.0-epsilon)/(1.0+epsilon));
            Hgamma = (i*Hgamma + Payoff(S))/(i+1.0); // First shift back Rescale; Then shift left
        }
        Price = exp(-Model.GetR() * T) * H;
        PricingError = exp(-Model.GetR() * T) * sqrt(Hsq - H * H) / sqrt(N - 1.0);
        delta = exp(-Model.GetR() * T) * (Heps - H) / (Model.GetS0() * epsilon);
        gamma = exp(-Model.GetR() * T) * (Heps - 2*H +Hgamma)/pow((Model.GetS0() * epsilon),2);
        return Price;
    }
    

    double ArthmAsianCall::Payoff(const SamplePath& S) const
    {
        double Ave = 0.0;
        for (int k = 0; k < m; k++) Ave = (k * Ave + S[k]) / (k + 1.0);
            if (Ave < K) return 0.0;
        return Ave - K;
    }

    double PathDepOption::PriceByVarRedMC(const MCModel& Model, long N,
    PathDepOption& CVOption, double epsilon)
    {
        DifferenceOfOptions VarRedOpt(T, K, m, this, &CVOption);
        // Ptr1 -- this (current object address) <-- option <-- arithmetic asian call
        // Ptr2 -- address of CV option
        Price = VarRedOpt.PriceByMC(Model, N, epsilon) + CVOption.PriceByBSFormula(Model);
        PricingError = VarRedOpt.PricingError;
        return Price;
    }

}

/*
 Asian Call Price = 1.43107
 Pricing Error = 0.0120662
 delta = 0.528801
 gamma = 0.114276
 */
