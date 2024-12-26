#include <iostream>
#include <format>
#include "BlackScholes.h"

int main(int argc, char* argv[])
{
    double strike = 95.0;
    double spot = 100.0;
    double expiry = 0.25;
    BlackScholes::PayoffType payoffType = BlackScholes::PayoffType::Call;
    double rate = 0.05;
    double dividend = 0.07;

    BlackScholes bs(strike, spot, expiry, payoffType, rate, dividend);
    double vol = 0.2;
    double optionValue = bs(vol);
    std::cout << std::format("Option value: {0}\n", optionValue);

    double currentMarketPrice = 6.2;
    double volGuess1 = 0.1;
    double volGuess2 = 0.15;
    double tol = 1e-6;
    unsigned int maxIter = 1000;
    double impliedVol = bs.impliedVol(bs, currentMarketPrice, volGuess1, volGuess2, tol, maxIter);
    if (!std::isnan(impliedVol))
    {
        std::cout << std::format("Call ITM, time to expiration = {}, ", expiry);
        std::cout << std::format("Implied volatility: {0}\n", impliedVol);
        
        optionValue = bs(impliedVol);
        std::cout << std::format("Value of option at implied vol = {}, ", optionValue);
        std::cout << std::format("Market option price: {0}\n", currentMarketPrice);
    }
    else
    {
        std::cout << "No convergence to implied volatility\n";
    }
    return 0;
}