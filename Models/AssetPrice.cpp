//
// Created by alexa on 16/09/2018.
//

#include "AssetPrice.h"

AssetPrice::AssetPrice(std::size_t TimeSteps_, double TimeToMaturity_, double StartPrice_, double RiskFreeRate_,
                       double Volatility_, AssetPriceData& ResultsRef_) :
        TimeSteps(TimeSteps_), TimeToMaturity(TimeToMaturity_), StartPrice(StartPrice_), RiskFreeRate(RiskFreeRate_),
        Volatility(Volatility_), ResultRef(ResultsRef_) {

}

std::size_t AssetPrice::GetTimeSteps() const { return TimeSteps; }
double AssetPrice::GetTimeToMaturity() const { return TimeToMaturity; }
double AssetPrice::GetStartPrice() const { return StartPrice; }
double AssetPrice::GetRiskFreeRate() const { return RiskFreeRate; }
double AssetPrice::GetVolatility() const { return Volatility; }
AssetPriceData& AssetPrice::GetResultsRef() const { return ResultRef; }


void AssetPrice::SetResultsRef(AssetPriceData& NewResultsRef_) {
    ResultRef = NewResultsRef_;

}

