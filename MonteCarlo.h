/**
 * File: MonteCarlo.h
 * Language: C++
 * Author: Alexander D. Mottram
 *
 * MonteCarlo takes in a reference to a model and runs it a set number of times.
 *
 * MonteCarlo accepts a reference to anything that inherits off class ModelBase
 * and runs that model for a set number of paths. Storing of data for the resulting
 * paths is handled by the model itself. The only other functionality offered
 * by MonteCarlo is a timer that stores the length of time required to run the full
 * set of paths and a progress bar for longer simulations.
 */

#ifndef FINTEGRALPROJECT_MONTECARLO_H
#define FINTEGRALPROJECT_MONTECARLO_H

#include <cstdlib>
#include <chrono>
#include <string>
#include "Models/ModelBase.h"
#include "ProgressBar.h"

class MonteCarlo {
public:
    /**
     * Constructor for a MonteCarlo object, note that the simulation wont run
     * until the Run() command is used on the object.
     *
     * @param Model_ The model to run, the MonteCarlo class doesn't require the
     *               model to have a stochastic term to leave it as flexible as
     *               possible.
     * @param Number0fPaths_ The number of times to run the model.
     */
    MonteCarlo(ModelBase& Model_, std::size_t Number0fPaths_);

    /**
     * Runs the model referenced  to by "Model" for a number of pathways stored
     * in the "NumberPaths" member. Times the process using chrono and inputs it
     * into the class member "Timer".
     */
    void Run();

    /**
     * Returns the last run time as a double in milliseconds.
     *
     * @return run time of last Monte Carlo simulation in milliseconds.
     *         Will return 0.0 if the simulation hasn't been run yet.
     */
    double GetTimeOfLastRun() const;

    /**
     * Prints the last run time in milliseconds to the console, printing
     * 0 if the simulation hasn't yet been run.
     */
    void DumpTimerToConsole() const;

private:
    std::size_t NumberPaths;
    ModelBase& Model;
    double Timer =0.0; // in milliseconds

};


#endif //FINTEGRALPROJECT_MONTECARLO_H
