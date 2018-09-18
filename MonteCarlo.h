//
// Created by alexa on 16/09/2018.
//

#ifndef FINTEGRALPROJECT_MONTECARLO_H
#define FINTEGRALPROJECT_MONTECARLO_H

#include <cstdlib>
#include <chrono>
#include "Models/ModelBase.h"

class MonteCarlo {
public:
    MonteCarlo(ModelBase& Model_, std::size_t Number0fPaths_);

    void Run();
    void DumpTimerToConsole() const;

private:
    std::size_t NumberPaths;
    ModelBase& Model;
    double Timer =0; // in milliseconds

};


#endif //FINTEGRALPROJECT_MONTECARLO_H
