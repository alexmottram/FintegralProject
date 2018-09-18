#include <iostream>
#include "RandNumGen/RandBase.h"
#include "RandNumGen/RandUniform.h"
#include "Models/RealWorldPrice.h"
#include "Models/RiskNeutralPrice.h"
#include "DataStorage/AssetPriceData.h"
#include "DataStorage/CDF.h"
#include "MonteCarlo.h"

int main() {
    RandUniform generator(10,1);
    AssetPriceData resultsHeader1;
    AssetPriceData resultsHeader2;
    RiskNeutralPrice pricingModel1(101, 4.0, 100, 0.02, 0.2, resultsHeader1,generator);
    RiskNeutralPrice pricingModel2(101, 4.0, 100, 0.02, 0.2, resultsHeader2,generator);

    MonteCarlo MonteCarloSim1(pricingModel1, 10000);
    MonteCarloSim1.Run();
    MonteCarloSim1.DumpTimerToConsole();
    //resultsHeader1.PrintPricesToCSV("test_file2.csv");

    std::cout << "The mean end price is " << resultsHeader1.MeanEndPrice() << " the variance is "
              << resultsHeader1.VarianceEndPrice() << " and the standard deviation is " << resultsHeader1.StdDevEndPrice()
              << " ." << std::endl;

//    MonteCarlo MonteCarloSim2(pricingModel2, 10000);
//    MonteCarloSim2.Run();
//    MonteCarloSim2.DumpTimerToConsole();
//    resultsHeader2.PrintPricesToCSV("test_file.csv");
//    std::cout << "The mean end price is " << resultsHeader2.MeanEndPrice() << " the variance is "
//              << resultsHeader2.VarianceEndPrice() << " and the standard deviation is " << resultsHeader2.StdDevEndPrice()
//              << " ." << std::endl;


    CDF newCDF = resultsHeader1.GetCDFofXatY(1,100);

    std::cout << newCDF.GetFloorInverseCDF(0.5);

    return 0;
}