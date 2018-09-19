/**
 * File: AssetPriceData.h
 * Language: C++
 * Author: Alexander D. Mottram
 *
 * Data storage specifically for use with AssetPrice models.
 *
 * AssetPriceData is a subclass of InnerDataStorage.h designed specifically
 * to be used in conjunction with any AssetPrice.h model. The PathData used
 * consists of {"Time","Price"} of the asset. The class includes various
 * methods that include a print to csv function and various statistical and
 * financial functions.
 */

#ifndef FINTEGRALPROJECT_ASSETPRICEDATA_H
#define FINTEGRALPROJECT_ASSETPRICEDATA_H

#include <fstream>
#include <cmath>
#include <chrono>
#include <sstream>
#include <algorithm>
#include "InnerDataStorage.h"
#include "CDF.h"
#include "../ProgressBar.h"

class AssetPriceData : public InnerDataStorage {
public:

    /**
     * Empty constructor for AssetPriceData.
     *
     * @return AssetPriceData object: InnderDataStorage -> empty vector of PathData
     */
    AssetPriceData() : InnerDataStorage() {}

    /**
     * Overloads InnerDataStorage AddOnePath(PathData currentPath_) used to write
     * a valarray of {Time,Price} data into a PathData using the InnerDataStorages
     * base AddOnePath function.
     *
     * @param results_ A valarray of two doubles of {Time,Price}.
     */
    void AddOnePath(std::valarray<std::valarray<double>> results_);

    /**
     * Prints one column of the time data from PathResult[0] followed
     * by all the price values, a single path per column, for all paths to
     * a file in the build directory. File includes a single header line.
     *
     * @param filename_ Name of the file to write too, creates file if it
     *                  doesn't exist. Will require file format (.csv).
     */
    void PrintPricesToCSV(const char *filename_) const;

    /**
     * Returns the final price of the asset averaged over all the paths.
     *
     * @return mean final price of the asset. Returns 0 and error message
     *         if there is no PathData in the objects InnerDataStorage.
     */
    double MeanEndPrice() const;

    /**
     * Returns the variance of the final price for all the PathData gathered.
     *
     * @return variance of final price of the asset. Returns 0 and error message
     *         if there is no PathData in the objects InnerDataStorage.
     */
    double VarianceEndPrice() const;

    /**
     * Returns the standard deviation of the final price for all the PathData gathered.
     *
     * @return standard deviation of final price of the asset. Returns 0 and error message
     *         if there is no PathData in the objects InnerDataStorage.
     */
    double StdDevEndPrice() const;

    /**
     * Returns the value at risk at a SPECIFIED TIME point. The value at risk
     * is the maximum possible loss that could occur given that prices with
     * probability lower than the set risk_ level are ignored.
     *
     * @param risk_ The probability below which events are ignored.
     * @param resultX_ The time point (result or row within the PathData) to
     *                 calculate the value at risk for.
     * @return maximum possible loss at a specified time(where loss is a positive value)
     *         that can occur giving that prices that occur at that time are have a greater
     *         probability than the risk parameter.
     */
    double ValueAtRiskAtTimeX(double risk_, size_t resultX_) const;

    /**
     * Returns the value at risk BEFORE AND INCLUDING THE SPECIFIED TIME point.
     * Function calls ValueAtRiskAtTimeX() to handle the calculations.
     *
     * @param risk_ The probability below which events are ignored.
     * @param resultX_ The time point (result or row within the PathData) to
     *                 calculate maximum returned value of ValueAtRiskAtTimeX
     *                 up to.
     * @return maximum possible loss before and including the specified time
     *         (where loss is a positive value) that can occur giving that prices
     *         that occur at that time are have a greater probability than the
     *         risk parameter.
     */
    double ValueAtRisk(double risk_, size_t resultX_) const;

    /**
     * Returns the value at risk for the WHOLE TIME RANGE.
     * Function calls ValueAtRisk() to handle the calculation.
     *
     * @param risk_ The probability below which events are ignored.
     * @return maximum possible loss for the whole time range (where loss is
     *         a positive value) that can occur giving that prices that occur
     *         at that time are have a greater probability than the risk parameter.
     */
    double ValueAtRisk(double risk_) const;

};


#endif //FINTEGRALPROJECT_ASSETPRICEDATA_H
