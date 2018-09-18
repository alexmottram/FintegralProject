//
// Created by alexa on 16/09/2018.
//

#include "DataSet.h"

DataSet::DataSet(std::string DataID_, std::vector<double> Data_) : DataID(DataID_), Data(Data_) {
}

std::string DataSet::GetDataID() const { return DataID; }

std::vector<double> DataSet::GetData() const { return Data; }

