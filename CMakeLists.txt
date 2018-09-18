cmake_minimum_required(VERSION 3.10)
project(FintegralProject)

set(CMAKE_CXX_STANDARD 11)

add_executable(FintegralProject main.cpp RandNumGen/RandBase.cpp RandNumGen/RandBase.h RandNumGen/RandUniform.cpp RandNumGen/RandUniform.h RandNumGen/PMSeedGen.cpp RandNumGen/PMSeedGen.h SimResults/DataSet.cpp SimResults/DataSet.h SimResults/ResultsHeaderBase.cpp SimResults/ResultsHeaderBase.h SimResults/PathBase.cpp SimResults/PathBase.h MonteCarlo.cpp MonteCarlo.h Models/ModelBase.cpp Models/ModelBase.h Models/AssetPrice.cpp Models/AssetPrice.h Models/LogNormalPrice.cpp Models/LogNormalPrice.h DataStorage/InnerDataStorage.cpp DataStorage/InnerDataStorage.h DataStorage/PathData.cpp DataStorage/PathData.h DataStorage/AssetPriceData.cpp DataStorage/AssetPriceData.h)