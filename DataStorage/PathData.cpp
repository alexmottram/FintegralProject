//
// Created by alexa on 17/09/2018.
//

#include "PathData.h"

PathData::PathData(std::size_t NumberOfVariables_, std::size_t NumberOfResults_) :
        Headers(std::valarray<std::string>(NumberOfVariables_)),
        Results(std::valarray<std::valarray<double>>(NumberOfResults_)) {

    for (std::size_t i=0; i < NumberOfResults_; i++) {
        Results[i] = std::valarray<double>(NumberOfVariables_);
    }
}

PathData::PathData(std::valarray<std::string> Headers_, std::valarray<std::valarray<double>> Results_) :
    Headers(Headers_), Results(Results_) {

}


std::size_t PathData::GetNumberOfVariables() const { return Headers.size(); }

std::size_t PathData::GetNumberOfDataPoints() const { return Results.size(); }

std::valarray<std::string> PathData::GetHeaders() const { return Headers; }

std::valarray<double> PathData::GetSingleResultX(std::size_t resultX_) const {

    if(resultX_ < GetNumberOfDataPoints()) {
        return Results[resultX_];
    } else {
        return std::valarray<double>();
    }
}

std::valarray<double> PathData::GetSingleColumnX(size_t columnX_) const {

    std::valarray<double> tmpVector(GetNumberOfDataPoints());

    if(columnX_ < GetNumberOfVariables()) {

        for (std::size_t i=0; i < GetNumberOfDataPoints(); i++) {
            tmpVector[i] = Results[i][columnX_];
        }
    }

    return tmpVector;

}





