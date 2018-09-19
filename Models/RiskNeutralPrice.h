/**
 * File: AssetPrice.h
 * Language: C++
 * Author: Alexander D. Mottram
 *
 * RiskNeutralPrice is an asset price model based on the Black-Scholes-Merton model.
 *
 * RiskNeutralPrice inherits from AssetPrice and hence also ModelBase. It implements
 * the RunModelOnce() pure virtual function from model base and hence can be referred
 * to by any function that requires a reference to ModelBase. RiskNeutralPrice calculates
 * a timeseries of price data using the equation below which it writes to an AssetPriceData
 * object.
 *
 * Equation: S_{t+1} = S_{t} * exp( ((r-0.5*vol*vol)*timeDiff) + (sqrt(timeDiff)*vol*N(0,1)) )
 *
 * Symbols:
 * S_{t+1} = Spot price at time (t + timeDiff)
 * r = risk free rate
 * vol = volatility
 * timeDiff = the time step between subsequent measurements of spot price;
 * N(0,1) = gaussian with mean = 0, and standard deviation = 1 *
 */

#ifndef FINTEGRALPROJECT_RISKNEUTRALLOGNORMPRICE_H
#define FINTEGRALPROJECT_RISKNEUTRALLOGNORMPRICE_H

#include "AssetPrice.h"
#include "../RandNumGen/RandBase.h"

class RiskNeutralPrice : public AssetPrice {
public:
    /**
     * Constructor for RiskNeutralPrice asset price model.
     *
     * @param TimeSteps_ The total number of time steps that the model will use.
     * @param TimeToMaturity_ The amount of time you wish to model the asset price over.
     * @param StartPrice_ The starting price of the asset at time = 0.
     * @param RiskFreeRate_ The risk free interest rate (such as from a zero coupon bond).
     * @param Volatility_ The volatility of the asset being modelled.
     * @param ResultsRef_ A reference to am AssetPriceData object to save data into.
     * @param RandGen_ A random number generator that can produce a gaussian that is a
     *                 RandBase object, or a derived class.
     */
    RiskNeutralPrice(std::size_t TimeSteps_, double TimeToMaturity_, double StartPrice_, double RiskFreeRate_,
    double Volatility_, AssetPriceData& Results_, RandBase& RandGen_ );

    /**
     * Runs the model using the parameters defined in the upper AssetPrice object
     * and RandGen for any random values. Results of the single run are written to
     * the AssetPriceData object referred to by ResultRef in the AssetPrice.
     */
    void RunModelOnce();

    /**
     * Points the ResultRef in the above AssetPrice object to a new AssetPriceData object
     * then runs the simulation.
     *
     * @param Results_ A reference to an AssetPriceData object.
     */
    void RunModelOnce(AssetPriceData& Results_);

private:
    RandBase& RandGen;

};


#endif //FINTEGRALPROJECT_RISKNEUTRALLOGNORMPRICE_H
