//
// Created by Alex on 18/09/2018.
//

#include "CDF.h"

CDF::CDF() : PathData(std::valarray<std::string> {"Variable","CDF"}, std::valarray<std::valarray<double>>()) {

}

CDF::CDF(std::size_t NumberOfResults_) :
        PathData(std::valarray<std::string> {"Variable","CDF"}, std::valarray<std::valarray<double>>(NumberOfResults_)) {

}

CDF::CDF(std::valarray<std::valarray<double>> Results_)  :
        PathData(std::valarray<std::string> {"Variable","CDF"}, Results_) {

}

double CDF::GetFloorInverseCDF(double percentile_) const {

    if (GetNumberOfDataPoints() > 0) {
        if (percentile_ > 0 && percentile_ < 1) {

            if (percentile_ > GetSingleResultX(0)[1]) {

                for (size_t i=0; i < GetNumberOfDataPoints(); i++) {
                    if (percentile_ <  GetSingleResultX(i)[1]) {
                        return GetSingleResultX(i-1)[0];
                    }
                }

            } else {
                std::cout << "ERROR: The fraction you searched within the CDF is lower than the lowest available value."
                          << std::endl;
            }

        } else {
            std::cout << "ERROR: The fraction you searched within the CDF is out of bounds." << std::endl;
        }
    } else {
        std::cout << "ERROR: CDF not initialised fully." << std::endl;
    }

    return 0.0;
}
