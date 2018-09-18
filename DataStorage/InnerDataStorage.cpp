//
// Created by alexa on 17/09/2018.
//

#include "InnerDataStorage.h"

/// Work on the initialization of all the data storage components
InnerDataStorage::InnerDataStorage(std::size_t NumberOfPaths_, std::size_t NumberOfVariables_,
                                   std::size_t NumberOfResults) :
        PathResults(std::vector<PathData>()) {

}

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

std::valarray<double> InnerDataStorage::GetCrossSection(std::size_t resultX_, std::size_t rowY_) const {

    std::valarray<double> crossSection(GetNumberOfPaths());

    if(GetNumberOfPaths() > 0) {
        if(rowY_ < PathResults[0].GetNumberOfDataPoints() && resultX_ < PathResults[0].GetNumberOfVariables()) {

            for (std::size_t i=0; i < GetNumberOfPaths(); i++) {

                crossSection[i] = PathResults[i].GetSingleResultX(rowY_)[resultX_];

            }
        }
    }


    return crossSection;
}






