//
// Created by alexa on 17/09/2018.
//

#ifndef FINTEGRALPROJECT_INNERDATASTORAGE_H
#define FINTEGRALPROJECT_INNERDATASTORAGE_H

#include <cstdlib>
#include <vector>
#include <valarray>
#include "PathData.h"

class InnerDataStorage {
public:
    InnerDataStorage() : PathResults(std::vector<PathData>()){};
    InnerDataStorage(std::size_t NumberOfPaths_, std::size_t NumberOfVariables_, std::size_t NumberOfResults);

    virtual void AddOnePath(PathData currentPath_);


    std::valarray<double> GetCrossSection(std::size_t resultX_, std::size_t rowY_) const;
    std::size_t GetNumberOfPaths() const;
    std::vector<PathData> GetPathResults() const;
    PathData GetPathX(std::size_t pathX_) const;

private:
    std::vector<PathData> PathResults;
};


#endif //FINTEGRALPROJECT_INNERDATASTORAGE_H
