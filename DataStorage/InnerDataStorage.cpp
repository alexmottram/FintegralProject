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






