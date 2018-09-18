//
// Created by alexa on 16/09/2018.
//

#include "ResultsHeaderBase.h"

void ResultsHeaderBase::AddOnePath(PathBase Path_) {
    AllPaths.push_back(Path_);
}

void ResultsHeaderBase::DumpPathXToConsole(std::size_t x_, std::size_t columnWidth_) const {

    AllPaths[x_].DumpPathToConsole(columnWidth_);

}

std::size_t ResultsHeaderBase::GetNumberOfPaths() const {
    return AllPaths.size();
}

PathBase ResultsHeaderBase::GetPathx(std::size_t pathX_) const {

    if(pathX_ <= GetNumberOfPaths()) {
        return AllPaths[pathX_];
    }

    std::cout << "ERROR: Pathway " << pathX_ << " out of bounds. Returning empty path." << std::endl;

    return PathBase(std::vector<DataSet>());
}

void ResultsHeaderBase::PrintAllToCSV(std::string filename_, size_t commonDataSet_, size_t varDataSet_) const {

    if(!AllPaths.empty()) {
        std::ofstream CSVfile;
        CSVfile.open (filename_);
        std:size_t varColumns = GetNumberOfPaths() ;

        CSVfile << AllPaths[0].GetDataSetX(commonDataSet_).GetDataID() << ", ";
        for (std::size_t i=0; i < GetNumberOfPaths(); i++) {
            CSVfile << AllPaths[i].GetDataSetX(varDataSet_).GetDataID() << " Path " << i << ", ";
        }

        CSVfile << "\n";

        for (std::size_t j=0; j < AllPaths[0].GetDataSetX(commonDataSet_).GetData().size(); j++) {

            CSVfile << AllPaths[0].GetDataSetX(commonDataSet_).GetData()[j] << ", ";

            for (std::size_t i=0; i < GetNumberOfPaths(); i++) {
                CSVfile << AllPaths[i].GetDataSetX(varDataSet_).GetData()[j] << ", ";
            }

            CSVfile << "\n";
        }
    }
}
