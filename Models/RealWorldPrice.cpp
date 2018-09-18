//
// Created by alexa on 16/09/2018.
//

#include "RealWorldPrice.h"

RealWorldPrice::RealWorldPrice(std::size_t TimeSteps_, double TimeToMaturity_, double StartPrice_, double RiskFreeRate_,
                               double Volatility_, AssetPriceData& ResultsRef_, RandBase& RandGen_) :
        AssetPrice(TimeSteps_, TimeToMaturity_, StartPrice_, RiskFreeRate_, Volatility_, ResultsRef_),
        RandGen(RandGen_) {

    RandGen.ResetDimensionality(TimeSteps_);

}

void RealWorldPrice::RunModelOnce() {

    double timeDiff = GetTimeToMaturity() / static_cast<double>(GetTimeSteps() - 1);
    double adjVol = GetVolatility() * sqrt(timeDiff);
    double adjRFR = GetRiskFreeRate() * timeDiff;

    std::valarray<std::valarray<double>> results(GetTimeSteps());
    std::vector<double> randComponent;
    double time = 0.0;
    double price = GetStartPrice();

    RandGen.GetGaussians(randComponent);

    for (std::size_t i=0; i < GetTimeSteps(); i++) {
        /// Check the equation for change in price
        results[i] = std::valarray<double>{time, price};
        time += timeDiff;
        price = price* exp( adjRFR + (adjVol * randComponent[i]) );
    }

    GetResultsRef().AddOnePath(results);
}

void RealWorldPrice::RunModelOnce(AssetPriceData& ResultsRef_) {

    SetResultsRef(ResultsRef_);
    RunModelOnce();

}