#include <iostream>

#include "RandNumGen/RandBase.h"
#include "RandNumGen/RandUniform.h"

int main() {

    std::cout << "Hello, World!" << std::endl;

    RandUniform generator(10,1);

    std::vector<double> randomResults;
    std::vector<double> gaussianResults;

    int extreme = 6;
    std::vector<double> extremeResults;

    generator.GetUniforms(randomResults);
    generator.GetGaussians(gaussianResults);

    for (std::size_t i; i < randomResults.size(); i++) {
        std::cout << randomResults[i] << "  " << gaussianResults[i] << std::endl;

        if( gaussianResults[i] > extreme || gaussianResults[i] < - extreme) {
            extremeResults.push_back(gaussianResults[i]);
        }
    }

    std::cout << "Second set:" << std::endl;

    std::vector<double> randomResults2;
    std::vector<double> gaussianResults2;

    generator.GetUniforms(randomResults2);
    generator.GetGaussians(gaussianResults2);

    for (std::size_t i; i < randomResults2.size(); i++) {
        std::cout << randomResults2[i] << "  " << gaussianResults2[i] << std::endl;
    }


    return 0;
}