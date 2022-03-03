//
//  BinomialTreeModel.hpp
//  HomeWork 1
//
//  Created by Yuhang Fan on 2/3/22.
//

#pragma once
namespace fre
{
double RiskNeutProb(double U, double D, double R);

double CalculateAssetPrice(double S0, double U, double D, int n, int i);

int GetinputData(double& S0, double& U, double& D, double& R);

int ValidateInputData(const double& S0, const double& U, const double& D, const double& R);
}



