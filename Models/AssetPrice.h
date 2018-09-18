//
// Created by alexa on 16/09/2018.
//

#ifndef FINTEGRALPROJECT_ASSETPRICE_H
#define FINTEGRALPROJECT_ASSETPRICE_H

#include <cstdlib>
#include "ModelBase.h"
#include "../DataStorage/AssetPriceData.h"

class AssetPrice : public ModelBase{
public:
    AssetPrice(std::size_t TimeSteps_, double TimeToMaturity_, double StartPrice_,
               double RiskFreeRate_, double Volatility_, AssetPriceData& ResultsRef_);

    std::size_t GetTimeSteps() const;
    double GetTimeToMaturity() const;
    double GetStartPrice() const;
    double GetRiskFreeRate() const;
    double GetVolatility() const;
    AssetPriceData& GetResultsRef() const;

    void SetResultsRef(AssetPriceData& NewResultsRef_);

private:
    std::size_t TimeSteps;
    double TimeToMaturity;

    double StartPrice;
    double RiskFreeRate;
    double Volatility;

    AssetPriceData& ResultRef;
};


#endif //FINTEGRALPROJECT_ASSETPRICE_H
