//
// Created by alexa on 16/09/2018.
//

#ifndef FINTEGRALPROJECT_LOGNORMALPRICE_H
#define FINTEGRALPROJECT_LOGNORMALPRICE_H

#include <vector>
#include "AssetPrice.h"
#include "../RandNumGen/RandBase.h"

class LogNormalPrice : public AssetPrice {
public:

    LogNormalPrice(std::size_t TimeSteps_, double TimeToMaturity_, double StartPrice_, double RiskFreeRate_,
                   double Volatility_, AssetPriceData& Results_, RandBase& RandGen_ );

    void RunModelOnce();
    void RunModelOnce(AssetPriceData& Results_);

private:
    RandBase& RandGen;

};


#endif //FINTEGRALPROJECT_LOGNORMALPRICE_H
