/**
 * File: CDF.h
 * Language: C++
 * Author: Alexander D. Mottram
 *
 * Stores data for cumulative probability distributions.
 *
 * CDF inherits off PathData, specifying 2 variables only. The
 * first column is "Variable" and the second is the corresponding
 * cumulative distribution function (CDF). Provides functions to
 * calculate the inverse CDF for a set probability.
 *
 * Visual aid: Data is considered to be a 2D array with 2 columns
 * consisting of the defined variables, and rows being the inner
 * valarrays.
 */

#ifndef FINTEGRALPROJECT_CDF_H
#define FINTEGRALPROJECT_CDF_H

#include <valarray>
#include <string>
#include "PathData.h"

class CDF : public PathData{
public:

    /**
     * Empty constructor for a CDF object.
     *
     * @return PathData object: Header  -> valarray of 2 strings "Variable" & "CDF"
     *                          Results -> outer valarray of empty inner valarrays of type double
     */
    CDF();

    /**
     * Size constructor for a CDF object.
     *
     * @param the number of results that will be input into the CDF object.
     *
     * @return PathData object: Header  -> valarray of 2 strings "Variable" & "CDF"
     *                          Results -> outer valarray of length set by input parameter
     *                                     consisting of empty inner valarrays of type double
     */
    CDF(std::size_t NumberOfResults_);

    /**
     * Data constructor for a CDF object.
     *
     * @param results in the form of a outer valarray containing inner valarrays of 2 doubles.
     *
     * @return PathData object: Header  -> valarray of 2 strings "Variable" & "CDF"
     *                          Results -> outer valarray of length set by the input results,
     *                                     note that if the inner array is larger than 2 doubles
     *                                     it will still accept it, but will be inaccessible by
     *                                     other functions of PathData and CDF which use the header
     *                                     to calcualte the maximum size of the inner valarray
     */
    CDF(std::valarray<std::valarray<double>> Results_);

    /**
     * Returns the nearest value for the random variable value BELOW the entered percentile.
     * NOTE: Although it says percentile, enter the parameter as a fraction.
     *
     * @param percentile_ The percentile (in fraction form) to find the nearest lower
     *                    CDF point. Must be greater than 0 and less than 1.
     *
     * @return the value for the random variable for which the CDF is lower than but
     *         closest to the percentile entered. In case of an error it will return 0.0.
     */
    double GetFloorInverseCDF(double percentile_) const; // although labelled percentile use fraction
};


#endif //FINTEGRALPROJECT_CDF_H
