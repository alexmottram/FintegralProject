cmake_minimum_required(VERSION 3.10)
project(FintegralProject)

set(CMAKE_CXX_STANDARD 11)

set(MODELS Models/ModelBase.cpp Models/ModelBase.h
           Models/AssetPrice.cpp Models/AssetPrice.h
           Models/RiskNeutralPrice.cpp Models/RiskNeutralPrice.h)

set(DATASTORAGE DataStorage/InnerDataStorage.cpp DataStorage/InnerDataStorage.h
                DataStorage/PathData.cpp DataStorage/PathData.h
                DataStorage/AssetPriceData.cpp DataStorage/AssetPriceData.h
                DataStorage/CDF.cpp DataStorage/CDF.h)

set(RANDNUMGEN RandNumGen/RandBase.cpp RandNumGen/RandBase.h
               RandNumGen/RandUniform.cpp RandNumGen/RandUniform.h)

add_executable(FintegralProject main.cpp  MonteCarlo.cpp MonteCarlo.h  ProgressBar.cpp ProgressBar.h
                ${MODELS} ${DATASTORAGE} ${RANDNUMGEN})