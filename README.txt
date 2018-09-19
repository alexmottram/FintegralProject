
   N.B. To use the query in the attached excel sheet to plot the paths
   you must print out only 100 paths into a file called "test_file1.csv"
   in the cmake-build-debug directory.

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