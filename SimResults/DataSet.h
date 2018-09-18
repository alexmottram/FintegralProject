//
// Created by alexa on 16/09/2018.
//

#ifndef FINTEGRALPROJECT_DATASET_H
#define FINTEGRALPROJECT_DATASET_H

#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

class DataSet {
public:
    DataSet(std::string DataID_, std::vector<double> Data_);

    std::string GetDataID() const;
    std::vector<double> GetData() const;

private:
    std::string DataID;
    std::vector<double> Data;
};


#endif //FINTEGRALPROJECT_DATASET_H
