//
// Created by alexa on 17/09/2018.
//

#include "InnerDataStorage.h"

void InnerDataStorage::AddOnePath(PathData currentPath_) {

    PathResults.push_back(currentPath_);
}


std::size_t InnerDataStorage::GetNumberOfPaths() const { return PathResults.size(); }

std::vector<PathData> InnerDataStorage::GetPathResults() const { return PathResults; }

PathData InnerDataStorage::GetPathX(std::size_t pathX_) const {

    if(pathX_ < GetNumberOfPaths()) {
        return PathResults[pathX_];
    }

    return PathData();
}

std::valarray<double> InnerDataStorage::GetCrossSection(std::size_t variableX_, std::size_t resultY_) const {

    std::valarray<double> crossSection(GetNumberOfPaths());

    if(GetNumberOfPaths() > 0) {

        if(resultY_ < PathResults[0].GetNumberOfDataPoints() && variableX_ < PathResults[0].GetNumberOfVariables()) {

            for (std::size_t i=0; i < GetNumberOfPaths(); i++) {

                crossSection[i] = PathResults[i].GetSingleResultX(resultY_)[variableX_];

            }
        }
    }

    return crossSection;
}

CDF InnerDataStorage::GetCDFofXatY(std::size_t variableX_, std::size_t resultY_) const {

    if(GetNumberOfPaths() > 0) {

        if(variableX_ < GetPathX(0).GetNumberOfVariables() && resultY_ < GetPathX(0).GetNumberOfDataPoints()) {

            std::valarray<double> tmpVector = GetCrossSection(variableX_, resultY_);
            std::valarray<std::valarray<double>> tmpCDF(tmpVector.size());

            std::sort(std::begin(tmpVector), std::end(tmpVector));


            for (size_t i=0; i < tmpVector.size(); i++) {
                double percentile = (static_cast<double>(i) + 1.0)/ static_cast<double>(tmpVector.size());
                tmpCDF[i] = std::valarray<double>{tmpVector[i],percentile};
            }

            return CDF(tmpCDF);
        }

    }

    return CDF();
}






