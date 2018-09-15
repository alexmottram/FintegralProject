cmake_minimum_required(VERSION 3.10)
project(FintegralProject)

set(CMAKE_CXX_STANDARD 11)

add_executable(FintegralProject main.cpp RandNumGen/RandBase.cpp RandNumGen/RandBase.h RandNumGen/RandUniform.cpp RandNumGen/RandUniform.h RandNumGen/PMSeedGen.cpp RandNumGen/PMSeedGen.h)