/**
 * File: AssetPrice.h
 * Language: C++
 * Author: Alexander D. Mottram
 *
 * AssetPrice defines how a model that simulates an assets price overtime functions.
 *
 * AssetPrice.h inherits from ModelBase.h, though it doesn't implement the RunModelOnce()
 * member function. Instead it separates common factors required for an asset price
 * model and sets the requirement of the AssetPriceData class to write data to.
 */

#ifndef FINTEGRALPROJECT_ASSETPRICE_H
#define FINTEGRALPROJECT_ASSETPRICE_H

#include <cstdlib>
#include "ModelBase.h"
#include "../DataStorage/AssetPriceData.h"

class AssetPrice : public ModelBase{
public:

    /**
     * Create a base class asset price model, cannot be used in place of a ModelBase
     * reference as RunModelOnce() is not implemented.
     *
     * @param TimeSteps_ The total number of time steps that the model will use.
     * @param TimeToMaturity_ The amount of time you wish to model the asset price over.
     * @param StartPrice_ The starting price of the asset at time = 0.
     * @param RiskFreeRate_ The risk free interest rate (such as from a zero coupon bond).
     * @param Volatility_ The volatility of the asset being modelled.
     * @param ResultsRef_ A reference to am AssetPriceData object to save data into.
     */
    AssetPrice(std::size_t TimeSteps_, double TimeToMaturity_, double StartPrice_,
               double RiskFreeRate_, double Volatility_, AssetPriceData& ResultsRef_);

    /**
     * Returns the number of time steps set.
     *
     * @return time steps between zero and time of maturity.
     */
    std::size_t GetTimeSteps() const;

    /**
     * Returns the length of time to model the asset for.
     *
     * @return the length of time of the model.
     */
    double GetTimeToMaturity() const;

    /**
     * Returns the initial starting price of the asset for each run of the model.
     *
     * @return the initial starting price of the model.
     */
    double GetStartPrice() const;

    /**
     * Returns the risk free rate used by the model
     *
     * @return the risk free interest rate.
     */
    double GetRiskFreeRate() const;

    /**
     * Returns the volatility set in the model.
     *
     * @return the volatility.
     */
    double GetVolatility() const;

    /**
     * Passes a reference to the AssetPriceData object for storing results in.
     *
     * @return reference to an AssetPriceData for storing results.
     */
    AssetPriceData& GetResultsRef() const;

    /**
     * Allows the model to write to a new AssetPriceData object.
     *
     * @param NewResultsRef_ A reference to the new AssetPriceData object to write to;
     */
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
