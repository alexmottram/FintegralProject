//
// Created by alexa on 17/09/2018.
//

#ifndef FINTEGRALPROJECT_PATHDATA_H
#define FINTEGRALPROJECT_PATHDATA_H


#include <iostream>
#include <vector>
#include <string>
#include <valarray>

class PathData {
public:
    PathData() : Headers(std::valarray<std::string>()), Results(std::valarray<std::valarray<double>>()) {};
    PathData(std::size_t NumberOfVariables_, std::size_t NumberOfResults);
    PathData(std::valarray<std::string> Headers_, std::valarray<std::valarray<double>> Results_);

    std::size_t GetNumberOfVariables() const;
    std::size_t GetNumberOfDataPoints() const;
    std::valarray<std::string> GetHeaders() const;
    std::valarray<double> GetSingleResultX(std::size_t resultX_) const;
    std::valarray<double> GetSingleColumnX(std::size_t columnX_) const;


private:
    std::valarray<std::string> Headers;
    std::valarray<std::valarray<double>> Results;

};


#endif //FINTEGRALPROJECT_PATHDATA_H
