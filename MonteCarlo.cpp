//
// Created by alexa on 16/09/2018.
//

#include "MonteCarlo.h"

MonteCarlo::MonteCarlo(ModelBase& Model_, std::size_t Number0fPaths_) :
                        Model(Model_), NumberPaths(Number0fPaths_) {

}

void MonteCarlo::Run() {

    auto t1 = std::chrono::high_resolution_clock::now();

    for (size_t i=0; i < NumberPaths; i++ ) {
        Model.RunModelOnce();
    }

    auto t2 = std::chrono::high_resolution_clock::now();
    Timer = std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count();

}

void MonteCarlo::DumpTimerToConsole() const {

    std::cout << "The last monte carlo simulation completed in " << Timer << " milliseconds." << std::endl;

}
