#pragma once
#include <utility>

class BlackScholes
{
public:
    enum class PayoffType
    {
        Call = 1,
        Put = -1
    };

    BlackScholes(double strike, double spot, double expiry, PayoffType payoffType, double rate, double dividend = 0.0);
    ~BlackScholes() = default;

    double operator()(double vol) const;

private:
    std::pair<double, double> computeNormArgs(double vol) const;

    double strike_;
    double spot_;
    double expiry_;
    PayoffType payoffType_;
    double rate_;
    double dividend_;
};