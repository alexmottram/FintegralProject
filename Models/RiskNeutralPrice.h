//
// Created by Alex on 18/09/2018.
//

#ifndef FINTEGRALPROJECT_RISKNEUTRALLOGNORMPRICE_H
#define FINTEGRALPROJECT_RISKNEUTRALLOGNORMPRICE_H

#include "AssetPrice.h"
#include "../RandNumGen/RandBase.h"

class RiskNeutralPrice : public AssetPrice {
public:

    RiskNeutralPrice(std::size_t TimeSteps_, double TimeToMaturity_, double StartPrice_, double RiskFreeRate_,
    double Volatility_, AssetPriceData& Results_, RandBase& RandGen_ );

    void RunModelOnce();
    void RunModelOnce(AssetPriceData& Results_);

private:
    RandBase& RandGen;

};


#endif //FINTEGRALPROJECT_RISKNEUTRALLOGNORMPRICE_H
