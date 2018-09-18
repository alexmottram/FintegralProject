//
// Created by alexa on 16/09/2018.
//

#ifndef FINTEGRALPROJECT_PATHBASE_H
#define FINTEGRALPROJECT_PATHBASE_H

#include <vector>
#include <iostream>
#include <iomanip>
#include "DataSet.h"

class PathBase {
public:
    PathBase(std::vector<DataSet> Results_);

    std::size_t GetNumberOfDataSets() const;
    DataSet GetDataSetX(std::size_t dataSetX_) const;

    void DumpPathToConsole(std::size_t columnWidth_) const;

private:
    std::vector<DataSet> Results;
};



#endif //FINTEGRALPROJECT_PATHBASE_H
