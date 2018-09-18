//
// Created by alexa on 16/09/2018.
//

#ifndef FINTEGRALPROJECT_RESULTHEADERBASE_H
#define FINTEGRALPROJECT_RESULTHEADERBASE_H

#include <vector>
#include <fstream>
#include "PathBase.h"

class ResultsHeaderBase {
public:
    ResultsHeaderBase() {}

    void AddOnePath(PathBase Path_);
    std::size_t GetNumberOfPaths() const;
    PathBase GetPathx(std::size_t x_) const;

    /// Remove this function, for testing only
    void DumpPathXToConsole(std::size_t pathX_, std::size_t columnWidth_) const;
    // Prints the data set common_ from path 0, then DataSet varDataSet from all paths
    void PrintAllToCSV(std::string filename_, size_t commonDataSet_, size_t varDataSet_) const;

private:
    std::vector<PathBase> AllPaths;
};


#endif //FINTEGRALPROJECT_RESULTHEADERBASE_H
