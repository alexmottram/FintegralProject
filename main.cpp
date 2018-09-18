#include <iostream>
#include "RandNumGen/RandBase.h"
#include "RandNumGen/RandUniform.h"
#include "Models/LogNormalPrice.h"
#include "DataStorage/AssetPriceData.h"
#include "MonteCarlo.h"

int main() {
    RandUniform generator(10,1);
    AssetPriceData resultsHeader(100,2,101);
    LogNormalPrice pricingModel(1001, 4.0, 100, 0.02, 0.4, resultsHeader,generator);

    MonteCarlo MonteCarloSim1(pricingModel, 1000);
    MonteCarloSim1.Run();
    MonteCarloSim1.DumpTimerToConsole();
    resultsHeader.BufferedPrintPricesToCSV("test_file2.csv");

    std::cout << "The mean end price is " << resultsHeader.MeanEndPrice() << " the variance is "
              << resultsHeader.VarianceEndPrice() << " and the standard deviation is " << resultsHeader.StdDevEndPrice()
              << " ." << std::endl;

//    for (std::size_t i=1; i < resultsHeader.GetNumberOfPaths()+4; i++) {
//        resultsHeader.DumpPathXToConsole(i,14);
//    }

    return 0;
}