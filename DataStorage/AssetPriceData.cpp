//
// Created by alexa on 17/09/2018.
//


#include "AssetPriceData.h"

void AssetPriceData::AddOnePath(std::valarray<std::valarray<double>> results_) {
    InnerDataStorage::AddOnePath(PathData(std::valarray<std::string>{"Time","Price"},results_));
}

void AssetPriceData::PrintPricesToCSV(const char *filename_) const {

    auto t1a = std::chrono::high_resolution_clock::now();


    if(GetNumberOfPaths()>0) {

        FILE *dataFile;
        dataFile = fopen(filename_, "w");

        std::valarray<double> priceResults(GetNumberOfPaths());
        std::stringstream stringBuffer;
        std::size_t numberOfPaths = GetNumberOfPaths();

        stringBuffer << GetPathX(0).GetHeaders()[0] << ", ";
        for (std::size_t i=0; i < numberOfPaths; i++) {
            stringBuffer << GetPathX(i).GetHeaders()[1] << " Path " << i << ", ";
        }

        stringBuffer << "\n";

        std::valarray<double> time = GetPathX(0).GetSingleColumnX(0);
        std::size_t numberOfDataPoints = GetPathX(0).GetNumberOfDataPoints();

        std::stringstream MessageSS;
        MessageSS << "Writing results to file with name: " << filename_ << " .";

        ProgressBar csvProgress(numberOfDataPoints, MessageSS.str());

        for (std::size_t j=0; j < numberOfDataPoints; j++) {

            csvProgress.Refresh(j);

            stringBuffer << time[j] << ", ";

            priceResults = GetCrossSection(1,j);

            std::chrono::high_resolution_clock::time_point t3a = std::chrono::high_resolution_clock::now();
            /// This loop here is currently the limiting factor in writing the data to CSV
            for (std::size_t i=0; i < numberOfPaths; i++) {
                stringBuffer << priceResults[i] << ", ";
            }

            stringBuffer << "\n";
        }

        fprintf(dataFile,stringBuffer.str().c_str());
        fclose(dataFile);
    }

    auto t1b = std::chrono::high_resolution_clock::now();
    double timer1 = std::chrono::duration_cast<std::chrono::milliseconds>(t1b-t1a).count();

    std::cout << "Saving the data using stringstream to CSV completed in " << timer1 << " milliseconds." << std::endl;

}

double AssetPriceData::MeanEndPrice() const {

    double mean = 0.0;



    if (GetNumberOfPaths() > 0) {

        std::valarray<double> allFinalPrices = GetCrossSection(1,GetPathX(0).GetNumberOfDataPoints()-1);

        for (auto finalPrice : allFinalPrices) {
            mean += finalPrice;
        }

        mean = mean/GetNumberOfPaths();

    } else {
        std::cout << "ERROR: No paths available to calculate the end price mean." << std::endl;
    }

    return mean;
}

double AssetPriceData::VarianceEndPrice() const{

    double mean = this->MeanEndPrice();
    double variance = 0.0;

    if (GetNumberOfPaths() > 0) {

        std::valarray<double> allFinalPrices = GetCrossSection(1,GetPathX(0).GetNumberOfDataPoints()-1);

        for (auto finalPrice : allFinalPrices) {
            double linearDiff = finalPrice - mean;
            variance += linearDiff * linearDiff;
        }

        variance = variance/GetNumberOfPaths();

    } else {
        std::cout << "ERROR: No paths available to calculate the end price variance." << std::endl;
    }

    return variance;
}

double AssetPriceData::StdDevEndPrice() const {

    double mean = this->MeanEndPrice();
    double variance = 0.0;
    double stdDev = 0.0;

    if (GetNumberOfPaths() > 0) {

        std::valarray<double> allFinalPrices = GetCrossSection(1,GetPathX(0).GetNumberOfDataPoints()-1);

        for (auto finalPrice : allFinalPrices) {
            double linearDiff = finalPrice - mean;
            variance += linearDiff * linearDiff;
        }

        stdDev = sqrt(variance/GetNumberOfPaths());

    } else {
        std::cout << "ERROR: No paths available to calculate the end price variance." << std::endl;
    }

    return stdDev;
}

CDF AssetPriceData::GetCDFofXatY(std::size_t variableX_, std::size_t resultY_) const {

    if(GetNumberOfPaths() > 0) {

        if(variableX_ < GetPathX(0).GetNumberOfVariables() && resultY_ < GetPathX(0).GetNumberOfDataPoints()) {

            std::valarray<double> tmpVector = GetCrossSection(variableX_, resultY_);
            std::valarray<std::valarray<double>> tmpCDF(tmpVector.size());

            std::sort(std::begin(tmpVector), std::end(tmpVector));


            for (size_t i=0; i < tmpVector.size(); i++) {
                double percentile = (static_cast<double>(i) + 1.0)/ static_cast<double>(tmpVector.size());
                tmpCDF[i] = std::valarray<double>{tmpVector[i],percentile};
            }

            return CDF(tmpCDF);
        }

    }

    return CDF();
}
