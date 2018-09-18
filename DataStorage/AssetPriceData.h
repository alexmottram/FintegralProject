/**
 * File: AssetPriceData.h
 * Language: C++
 * Author: Alexander D. Mottram
 *
 * Data storage specifically for use with AssetPrice models.
 *
 * AssetPriceData is a subclass of InnerDataStorage.h designed specifically
 * to be used in conjunction with any AssetPrice.h model.
 *
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
     */
    AssetPriceData() : InnerDataStorage() {}

    void AddOnePath(std::valarray<std::valarray<double>> results_);

    void PrintPricesToCSV(const char *filename_) const;
    double MeanEndPrice() const;
    double VarianceEndPrice() const;
    double StdDevEndPrice() const;

    CDF GetCDFofXatY(std::size_t variableX_, std::size_t resultY_) const;


};


#endif //FINTEGRALPROJECT_ASSETPRICEDATA_H
