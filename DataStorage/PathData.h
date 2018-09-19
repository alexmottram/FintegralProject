/**
 * File: PathData.h
 * Language: C++
 * Author: Alexander D. Mottram
 *
 * Stores valarrays of doubles with corresponding headers.
 *
 * PathData class provides a generic method for storing data of
 * the form of multiple valarrays of doubles, each with their own
 * header to describe the corresponding data. Made to be extended
 * for specific use dependent on the application. Results consists
 * of an "outer valarray" containing multiple "inner valarrays" of
 * doubles.
 *
 * Visual aid:                               Col 0      Col 1      Col 2   ...
 * Outer valarray[i] Header valarray[i]: {Header[0], Header[1], Header[2], ...}
 * Row 0    Outer[0] = Inner valarray[i] { Inner[0],  Inner[1],  Inner[2], ...}
 * Row 1    Outer[1] = Inner valarray[i] { Inner[0],  Inner[1],  Inner[2], ...}
 * Row 2    Outer[2] = Inner valarray[i] { Inner[0],  Inner[1],  Inner[2], ...}
 *          ........
 *
 * Requirements:
 * 1) The inner data must be of the same format for all single results
 * 2) The inner data must be of type double
 * 3) The header must be applicable to all inner data
 * 4) The data is stored with the primary key being the number
 *    of the point and the secondary key being the variable. *
 */


#ifndef FINTEGRALPROJECT_PATHDATA_H
#define FINTEGRALPROJECT_PATHDATA_H

#include <iostream>
#include <vector>
#include <string>
#include <valarray>

class PathData {
public:

    /**
     * Empty constructor for a PathData object.
     *
     * @return PathData object: Header  -> empty valarray of strings
     *                          Results -> outer valarray of empty inner valarrays of type double
     */
    PathData() : Headers(std::valarray<std::string>()), Results(std::valarray<std::valarray<double>>()) {};

     /**
      * Size constructor for a PathData object.
      *
      * @param NumberOfVariables_ The number of variables that will be stored in the
      *                           header and the inner Results valarray.
      * @param NumberOfResults_ The number of valarry doubles stored in the outer valarray.
      *
      * @return PathData object: Header  -> empty valarray of strings
      *                          Results -> valarray of empty valarrays of type double
      */
    PathData(std::size_t NumberOfVariables_, std::size_t NumberOfResults_);

    /**
     * Data constructor for a PathData object.
     *
     * @param Headers_ Strings containing the description of each value in the inner valarray.
     * @param Results_ A two layered valarray consisting of multiple sets of inner data results
     *                 in the larger outer data valarray.
     *
     * @return PathData object: Header  -> filled valarray of strings
     *                          Results -> valarray of filled valarrays of type double
     */
    PathData(std::valarray<std::string> Headers_, std::valarray<std::valarray<double>> Results_);

    /**
     * Gets the size of the header/the size of the inner valarray
     *
     * @return size of the header, returns 0 if empty.
     */
    std::size_t GetNumberOfVariables() const;

    /**
     * Gets the size of the outer valarray which is the number of datapoints.
     *
     * @return size of outer valarray storing data, returns 0 if empty.
     */
    std::size_t GetNumberOfDataPoints() const;

    /**
     * Gets the valarray containing strings of the headers.
     *
     * @return valarry of strings containing headers for the data.
     */
    std::valarray<std::string> GetHeaders() const;

    /**
     * Returns a valarray of the inner data of the resultX_, if resultX_ is
     * out of bounds it returns an empty valarray.
     *
     * @param resultX_ The point in the outer valarray to draw from.
     *
     * @return single inner valarray positioned at index resultX_ in the outter
     *         array or an empty valarray if resultX_ is out of bounds.
     */
    std::valarray<double> GetSingleResultX(std::size_t resultX_) const;

    /**
     * Returns a valarray the same length as the number of data points by
     * selecting the variable "columnX_" from each of the inner valarrays.
     *
     * @param columnX_ The variable to select from each inner valarray.
     *
     * @return a valarray of doubles created from each valarray, returns
     *         empty valarray if columnX_ is out of bounds.
     */
    std::valarray<double> GetSingleColumnX(std::size_t columnX_) const;


private:
    std::valarray<std::string> Headers;
    std::valarray<std::valarray<double>> Results;

};


#endif //FINTEGRALPROJECT_PATHDATA_H
