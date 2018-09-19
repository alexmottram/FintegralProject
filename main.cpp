/**
 * Project: FintegralProject
 *
 * File: main.cpp
 *
 * This project aims to provide base classes for a Monte Carlo simulation,
 * models to go into the Monte Carlo simulation, and a Data Storage system
 * for saving the path data produced during each run within the Monte Carlo
 * simulation.
 *
 *
 * MonteCarlo.h:
 *  The Monte Carlo simulation takes in a reference to a ModelBase object
 *  and runs the model in the object a set amount of times.
 *
 * ProgressBar.h
 *  A small class to create a progress bar for long loops.
 *
 ***************************** Files in Models *********************************
 * ModelBase.h:
 *  A base class for all models to ensure they have a run model output for
 *  the MonteCarlo class.
 *
 * AssetPrice.h:
 *  Inherits from ModelBase and implements the requirements for an asset price
 *  model, but does not include an implementation of how to calculate the asset
 *  price.
 *
 * RiskNeutralPrice.h:
 *  Inherits from AssetPrice and includes the equation to calculate subsequent
 *  prices of an asset given random movement as described by Black-Scholes-Merton.
 *
 *************************** Files in DataStorage ******************************
 *
 * PathData.h:
 *  A base class that can hold a 2D array of data including headers.
 *
 * InnerDataStorage.h:
 *  A base class that can hold a vector of PathData, including tools to manipulate
 *  it in set ways.
 *
 * AssetPriceData.h:
 *  A subclass of InnerDataStorage used to store data from an AssetPrice.h model
 *  with certain statistical functions included including:
 *      + End Price Mean/Variance/Standard Deviation
 *      + Value at Risk
 *      + Print to CSV all price paths
 *
 * CDF.h:
 *  A subclass of PathData used to store cumulative distribution functions and
 *  can return the lowest nearest value for a set probability (useful for value
 *  at risk calculations).
 *
  *************************** Files in RandNumGen ******************************
 *
 * RandBase.h:
 *  A base class for random number generators that provides both uniform and
 *  gaussian outputs. Derived classes must be able to produce a uniformly
 *  distributed random variables, but gaussians can be calculated from the uniform
 *  distribution
 *
 * RandUniform.h
 *  A subclass of RandBase that uses the standard library <random> to write
 *  a series of pseudo random numbers passed into its GetUniform or GetGaussian
 *  functions.
 *
 */

#include <iostream>
#include "RandNumGen/RandUniform.h"
#include "Models/RiskNeutralPrice.h"
#include "DataStorage/AssetPriceData.h"
#include "DataStorage/CDF.h"
#include "MonteCarlo.h"

int main() {

    /// Here is a sample of how the project can run
    RandUniform generator(10,1); // creates random generator used by RiskNeutralPrice
    AssetPriceData results; // creates an object to store results from an asset price model
    RiskNeutralPrice pricingModel(1001, 4.0, 100, 0.1, 0.3, results,generator); // creates a RiskNeutralPrice model

    MonteCarlo MonteCarloSim1(pricingModel, 100); /// Set paths to 100 to use MonteCarloSimPlot.xlsx
    MonteCarloSim1.Run();
    MonteCarloSim1.DumpTimerToConsole();

    /// The excel file "MonteCarloSimPlot.xlsx" contains a query to the file "test_file1.csv".
    /// This query will only function if the number of paths in the montecarlo sim = 100;
    results.PrintPricesToCSV("test_file1.csv");

    std::cout << "The mean end price is " << results.MeanEndPrice() << " the variance is "
              << results.VarianceEndPrice() << " and the standard deviation is "
              << results.StdDevEndPrice() << " ." << std::endl;

    std::cout << "The value at 5% risk at result 50 is "
              << results.ValueAtRiskAtTimeX(0.05,49) // result 50 is index 49
              << " while the value at 5% risk up to result 50 is "
              << results.ValueAtRisk(0.05,50)
              << std::endl;

    std::cout << "Finally value at 5% risk for whole time series is: "
              << results.ValueAtRisk(0.05) << "."
              << std::endl;



    return 0;
}