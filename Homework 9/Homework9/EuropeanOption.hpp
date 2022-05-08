// EuropeanOption2.hpp
//
// Class that represents  solutions to European options. This is
// an implementation using basic C++ syntax only. It has been
// written for pedagogical reasons
//
// (C) Datasim Component Technology BV 2003-2006
//

#ifndef EuropeanOption_hpp
#define EuropeanOption_hpp

class EuropeanOption
{
private:
    double r;        // Interest rate
    double sig;        // Volatility
    double K;        // Strike price
    double T;        // Expiry date
    double U;        // Current underlying price (e.g. stock, forward)
    double b;        // Cost of carry
    
    char * optType;
//    string optType;    // Option name (call, put)
    //string unam;    // Name of underlying asset
    
    // Gaussian functions
    double n(double x) const;
    double N(double x) const;
    
public:                // For TEST purposes only

    // 'Kernel' functions for option calculations
    double CallPrice() const;
    double PutPrice() const;
    double CallDelta() const;
    double PutDelta() const;
    double CallGamma() const;
    double PutGamma() const;
    double CallVega() const;
    double PutVega() const;

public:    // Public functions
    // Default call option
    EuropeanOption():r(0.08),sig(0.30),K(65.0),T(0.25),U(60.0),b(r)
    {
        optType = new char {'C'}; //Dynamic Allocation
    }
    
    // Copy constructor
    EuropeanOption(const EuropeanOption& o2):
    r(o2.r),sig(o2.sig),K(o2.K),T(o2.T),U(o2.U),b(o2.b),optType(o2.optType){}
    
    EuropeanOption (char * optType);    // Create option type
    virtual ~EuropeanOption();
    
    // Constructor with parameters
    EuropeanOption(double r_,double sig_,double K_,double T_,double U_,char optType_):
    r(r_),sig(sig_),K(K_),T(T_),U(U_),b(r_)
    {
        optType = new char {optType_}; //Dynamic Allocation
    }

    EuropeanOption& operator = (EuropeanOption& option2);

    // Functions that calculate option price and sensitivities
    double Price() const;
    double Delta() const;

    // Modifier functions
    void toggle();        // Change option type (C/P, P/C)
    
    // Function to get option Type
    const char * GetOptType();
    
    //Change current underlying price
    void SetU(double U_){ U = U_;}


};

#endif
