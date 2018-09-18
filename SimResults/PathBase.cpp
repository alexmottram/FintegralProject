//
// Created by alexa on 16/09/2018.
//

#include "PathBase.h"

PathBase::PathBase(std::vector<DataSet> Results_) : Results(Results_) {

}

void PathBase::DumpPathToConsole(std::size_t columnWidth_) const {

    if(!Results.empty()) {

        std::cout << std::endl;

        for(size_t j=0; j < Results.size(); j++) {
            std::cout << std::setfill (' ') << std::setw (columnWidth_) <<Results[j].GetDataID() << " ";
        }

        std::cout << std::endl;

        for (std::size_t i=0; i < Results[0].GetData().size(); i++) {


            for(size_t j=0; j < Results.size(); j++) {
                std::cout << std::setfill (' ') << std::setw (columnWidth_) <<Results[j].GetData()[i] << " ";
            }

            std::cout << std::endl;

        }
    }


}

DataSet PathBase::GetDataSetX(std::size_t dataSetX_) const {

    if(dataSetX_ < GetNumberOfDataSets()) {
        return Results[dataSetX_];
    }

    std::cout << "ERROR: Dataset " << dataSetX_ << " is out of bounds. Returning a NULL dataset." << std::endl;

    return DataSet(std::string("NULL"), std::vector<double>());
}

std::size_t PathBase::GetNumberOfDataSets() const { return Results.size(); }
