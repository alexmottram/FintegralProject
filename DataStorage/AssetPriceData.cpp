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
        std::cout << "ERROR: No paths available to calculate the end price standard deviation." << std::endl;
    }

    return stdDev;
}

double AssetPriceData::ValueAtRiskAtTimeX(double risk_, size_t resultX_) const {

    double value = 0.0;

    if( risk_ > 0 && risk_ < 1) {

        if(GetNumberOfPaths() > 0) {

            CDF priceCDF = GetCDFofXatY(1,resultX_);
            value = GetPathX(0).GetSingleResultX(0)[1] - priceCDF.GetFloorInverseCDF(risk_);

        } else {
            std::cout << "ERROR: No paths available to calculate the end price variance." << std::endl;
        }
    } else {
        std::cout << "ERROR: The value of risk entered should be between 0 & 1 excluding those values, returning 0.0"
                  << std::endl;
    }


    return value;
}

double AssetPriceData::ValueAtRisk(double risk_, size_t resultX_) const {

    double value = 0.0;
    std::size_t stopPoint = resultX_;

    if( risk_ > 0 && risk_ < 1) {

        if(GetNumberOfPaths()>0) {

            if(resultX_ > GetPathX(0).GetNumberOfDataPoints()) {
                std::cout << "ERROR: Time selected is outside bounds, using full data set instead." << std::endl;
                stopPoint = GetPathX(0).GetNumberOfDataPoints();
            }

            for (std::size_t i=0; i < stopPoint; i++) {

                double tempValue = ValueAtRiskAtTimeX(risk_,i);
                if(tempValue > value) {
                    value = tempValue;
                }
            }

        } else {
            std::cout << "ERROR: No paths available to calculate the value at risk, returning 0.0." << std::endl;
        }

    } else {
        std::cout << "ERROR: The value of risk entered should be between 0 & 1 excluding those values, returning 0.0"
                  << std::endl;
    }
    return value;
}

double AssetPriceData::ValueAtRisk(double risk_) const {
    return ValueAtRisk(risk_,GetPathX(0).GetNumberOfDataPoints());
}
