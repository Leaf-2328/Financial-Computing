//
//  Function02.cpp
//  Homework 8
//
//  Created by Yuhang Fan on 3/26/22.
//

#include "Function02.hpp"

namespace fre {
    double F1::Value(double x) { return x * x - 2; }
    double F1::Deriv(double x) { return 2 * x; }

    double F2::Value(double x) { return x * x - a; }
    double F2::Deriv(double x) { return 2 * x; }
}
