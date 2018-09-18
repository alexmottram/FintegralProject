//
// Created by alexa on 17/09/2018.
//

#ifndef FINTEGRALPROJECT_ASSETPRICEDATA_H
#define FINTEGRALPROJECT_ASSETPRICEDATA_H

#include <fstream>
#include <cmath>
#include <chrono>
#include <sstream>
#include "InnerDataStorage.h"

class AssetPriceData : public InnerDataStorage {
public:
    AssetPriceData() : InnerDataStorage() {}
    AssetPriceData(std::size_t NumberOfPaths_, std::size_t NumberOfVariables_, std::size_t NumberOfResults);

    virtual void AddOnePath(std::valarray<std::valarray<double>> results_);

    void PrintPricesToCSV(std::string filename_) const;
    void BufferedPrintPricesToCSV(const char *filename_) const;

    double MeanEndPrice() const;
    double VarianceEndPrice() const;
    double StdDevEndPrice() const;
};


#endif //FINTEGRALPROJECT_ASSETPRICEDATA_H
