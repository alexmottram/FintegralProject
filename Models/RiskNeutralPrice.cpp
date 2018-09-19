//
// Created by Alex on 18/09/2018.
//

#include "RiskNeutralPrice.h"

RiskNeutralPrice::RiskNeutralPrice(std::size_t TimeSteps_, double TimeToMaturity_, double StartPrice_, double RiskFreeRate_,
                               double Volatility_, AssetPriceData& ResultsRef_, RandBase& RandGen_) :
        AssetPrice(TimeSteps_, TimeToMaturity_, StartPrice_, RiskFreeRate_, Volatility_, ResultsRef_),
        RandGen(RandGen_) {

    RandGen.ResetDimensionality(TimeSteps_);

}

void RiskNeutralPrice::RunModelOnce() {

    double timeDiff = GetTimeToMaturity() / static_cast<double>(GetTimeSteps() - 1);
    double Vol = GetVolatility();
    double adjVol = Vol * sqrt(timeDiff);
    double constTerm = (GetRiskFreeRate() - (0.5 * Vol * Vol)) * timeDiff;

    std::valarray<std::valarray<double>> results(GetTimeSteps());
    std::vector<double> randComponent;
    double time = 0.0;
    double price = GetStartPrice();

    RandGen.GetGaussians(randComponent);

    for (std::size_t i=0; i < GetTimeSteps(); i++) {
        results[i] = std::valarray<double>{time, price};
        time += timeDiff;
        price = price* exp( constTerm + (adjVol * randComponent[i]) );
    }

    GetResultsRef().AddOnePath(results);
}

void RiskNeutralPrice::RunModelOnce(AssetPriceData& ResultsRef_) {

    SetResultsRef(ResultsRef_);
    RunModelOnce();

}