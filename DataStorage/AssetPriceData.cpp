//
// Created by alexa on 17/09/2018.
//


#include "AssetPriceData.h"

AssetPriceData::AssetPriceData(std::size_t NumberOfPaths_, std::size_t NumberOfVariables_, std::size_t NumberOfResults)
        : InnerDataStorage(NumberOfPaths_, NumberOfVariables_, NumberOfResults) {

}

void AssetPriceData::AddOnePath(std::valarray<std::valarray<double>> results_) {
    InnerDataStorage::AddOnePath(PathData(std::valarray<std::string>{"Time","Price"},results_));
}

void AssetPriceData::PrintPricesToCSV(std::string filename_) const {

    auto t1 = std::chrono::high_resolution_clock::now();

    if(GetNumberOfPaths()>0) {
        std::ofstream CSVfile;
        CSVfile.open (filename_);
        std:size_t varColumns = GetNumberOfPaths() ;

        CSVfile << GetPathX(0).GetHeaders()[0] << ", ";
        for (std::size_t i=0; i < GetNumberOfPaths(); i++) {
            CSVfile << GetPathX(i).GetHeaders()[1] << " Path " << i << ", ";
        }

        CSVfile << "\n";

        for (std::size_t j=0; j < GetPathX(0).GetNumberOfDataPoints(); j++) {

            CSVfile << GetPathX(0).GetSingleResultX(j)[0] << ", ";

            for (std::size_t i=0; i < GetNumberOfPaths(); i++) {
                CSVfile << GetPathX(i).GetSingleResultX(j)[1]<< ", ";
            }

            CSVfile << "\n";
        }

        CSVfile << std::endl;
    }

    auto t2 = std::chrono::high_resolution_clock::now();
    double Timer = std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count();
    std::cout << "Saving the data to CSV completed in " << Timer << " milliseconds." << std::endl;

}

void AssetPriceData::BufferedPrintPricesToCSV(const char *filename_) const {

    auto t1 = std::chrono::high_resolution_clock::now();

    if(GetNumberOfPaths()>0) {
        // std::ofstream CSVfile;
        FILE *dataFile;
        dataFile = fopen(filename_, "w");

        std::valarray<double> priceResults(GetNumberOfPaths());
        std::stringstream stringBuffer;

        stringBuffer << GetPathX(0).GetHeaders()[0] << ", ";
        for (std::size_t i=0; i < GetNumberOfPaths(); i++) {
            stringBuffer << GetPathX(i).GetHeaders()[1] << " Path " << i << ", ";
        }

        stringBuffer << "\n";


        for (std::size_t j=0; j < GetPathX(0).GetNumberOfDataPoints(); j++) {

            stringBuffer << GetPathX(0).GetSingleResultX(j)[0] << ", ";
            priceResults = GetCrossSection(1,j);
            for (auto points : priceResults) {
                stringBuffer << points << ", ";
            }

            stringBuffer << "\n";
        }

        fprintf(dataFile,stringBuffer.str().c_str());
        fclose(dataFile);

        //CSVfile << std::endl;
    }

    auto t2 = std::chrono::high_resolution_clock::now();
    double Timer = std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count();
    std::cout << "Saving the data using buffer to CSV completed in " << Timer << " milliseconds." << std::endl;

}

double AssetPriceData::MeanEndPrice() const {

    double mean = 0.0;

    if (GetNumberOfPaths() > 0) {

        for (auto path : GetPathResults()) {
            mean += path.GetSingleResultX(path.GetNumberOfDataPoints()-1)[1];
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

        for (auto path : GetPathResults()) {
            double linearDiff = path.GetSingleResultX(path.GetNumberOfDataPoints()-1)[1] - mean;
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

        for (auto path : GetPathResults()) {
            double linearDiff = path.GetSingleResultX(path.GetNumberOfDataPoints()-1)[1] - mean;
            variance += linearDiff * linearDiff;
        }

        stdDev = sqrt(variance/GetNumberOfPaths());

    } else {
        std::cout << "ERROR: No paths available to calculate the end price variance." << std::endl;
    }

    return stdDev;
}
