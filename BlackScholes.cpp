#include "BlackScholes.h"
#include <cmath>
#include <numbers>

BlackScholes::BlackScholes(double strike, double spot, double expiry, PayoffType payoffType, double rate, double dividend)
: strike_(strike)
, spot_(spot)
, expiry_(expiry)
, payoffType_(payoffType)
, rate_(rate)
, dividend_(dividend)
{
}



double BlackScholes::operator()(double vol) const
{
    const int phi = static_cast<int>(payoffType_);

    if (expiry_ > 0.0)
    {
        auto [d1, d2] = computeNormArgs(vol);
        auto normCDF = [](double x) { return 0.5 * (1.0 + std::erf(x / std::numbers::sqrt2)); };

        double normD1 = normCDF(phi * d1);
        double normD2 = normCDF(phi * d2);
        double discountFactor = std::exp(-rate_ * expiry_);
        return phi * ((spot_ * std::exp(-dividend_ * expiry_) * normD1) - (strike_ * discountFactor * normD2));
    }
    else
    {
        return std::max(phi * (spot_ - strike_), 0.0);
    }
}



std::pair<double, double> BlackScholes::computeNormArgs(double vol) const
{
    double d1 = (std::log(spot_ / strike_) + (rate_ - dividend_ + 0.5 * vol*vol) * expiry_) / (vol * std::sqrt(expiry_));
    double d2 = d1 - vol * std::sqrt(expiry_);
    return {d1, d2};
}
