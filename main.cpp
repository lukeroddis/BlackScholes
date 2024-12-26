#include <iostream>
#include "BlackScholes.h"

int main(int argc, char* argv[]) {

    BlackScholes bs(100, 100, 1, BlackScholes::PayoffType::Call, 0.05, 0.2);
    double optionValue = bs(0.2);
    std::cout << "Option value: " << optionValue << std::endl;
    return 0;
}