/**
 * File: ModelBase.h
 * Language: C++
 * Author: Alexander D. Mottram
 *
 * ModelBase is an interface abstract class defining minimum behaviour for all models.
 *
 * ModelBase is an abstract interface which for use with the MonteCarlo.h
 * class, which allows the MonteCarlo class to accept any "model" subclass
 * that has an implementation of RunModelOnce().
 */

#ifndef FINTEGRALPROJECT_MODELBASE_H
#define FINTEGRALPROJECT_MODELBASE_H

#include "../DataStorage/InnerDataStorage.h"

class ModelBase {
public:

    /**
     * RunModelOnce is a pure virtual function that must be implemented
     * by subclasses to describe how a single run of the model performs.
     */
    virtual void RunModelOnce() =0;

private:

};


#endif //FINTEGRALPROJECT_MODELBASE_H
