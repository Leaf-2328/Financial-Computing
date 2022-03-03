//
//  main.cpp
//  Homework 3
//
//  Created by Yuhang Fan on 2/17/22.
//

#include <iostream>
using namespace std;

class DefInt
{
private:
    double a; //lower bound
    double b;  //higher bound
    double (*fp)(double);  //pointer to the function
    
public:
    DefInt(double a_, double b_, double (*fp_)(double))
    {
        a = a_;
        b = b_;
        fp = fp_;
    }
    
    double ByTrapzoid(int N);
    double BySimpson();
};


double DefInt::ByTrapzoid(int N)
{
    double res = fp(a);
    double h = (b-a)/N;
    int k;
    for (k = 1;k <= N-1; k++)
    {
        res += 2*fp(a+k*h);
    }
    res += fp(b);
    res = (h/2)*res;
    
    return res;
}


double DefInt::BySimpson()
{
    return ((b-a)/6)*(fp(a)+4*fp((a+b)/2)+fp(b));  //Formula of Simpson's Rule
}


double f(double x)
{
    return x*x*x - x*x + 1; //f(x) = x^3 - x^2 + 1
}

void test01()
{
    double a = 1.0;
    double b = 2.0;
    DefInt MyInt(a,b,f);
    cout << "f(x) = x*x*x - x*x + 1, a = 1.0 and b = 2.0." << endl;
    
    cout << "The integral result by trapezoidal approximation: " << MyInt.ByTrapzoid(1000) << endl;
    
    cout << "The integral result by Simpson's rule: " << MyInt.BySimpson() << endl;
}


int main() {
    test01();
    return 0;
}

/*
 
 f(x) = x*x*x - x*x + 1, a = 1.0 and b = 2.0.
 The integral result by trapezoidal approximation: 2.41667
 The integral result by Simpson's rule: 2.41667
 
 */
