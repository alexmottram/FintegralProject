cmake_minimum_required(VERSION 3.10)
project(FintegralProject)

set(CMAKE_CXX_STANDARD 11)

add_executable(FintegralProject main.cpp RandNumGen/RandBase.cpp RandNumGen/RandBase.h RandNumGen/RandUniform.cpp RandNumGen/RandUniform.h RandNumGen/PMSeedGen.cpp RandNumGen/PMSeedGen.h  MonteCarlo.cpp MonteCarlo.h Models/ModelBase.cpp Models/ModelBase.h Models/AssetPrice.cpp Models/AssetPrice.h Models/RealWorldPrice.cpp Models/RealWorldPrice.h DataStorage/InnerDataStorage.cpp DataStorage/InnerDataStorage.h DataStorage/PathData.cpp DataStorage/PathData.h DataStorage/AssetPriceData.cpp DataStorage/AssetPriceData.h ProgressBar.cpp ProgressBar.h Models/RiskNeutralPrice.cpp Models/RiskNeutralPrice.h DataStorage/CDF.cpp DataStorage/CDF.h)