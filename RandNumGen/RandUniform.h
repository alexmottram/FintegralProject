//
// Created by Alex on 14/09/2018.
//

#ifndef FINTEGRALPROJECT_RANDUNIFORM_H
#define FINTEGRALPROJECT_RANDUNIFORM_H

#include <random>
#include <cstdlib>
#include "RandBase.h"
#include "PMSeedGen.h"

// Include note about how we are working over a closed interval between 0 and 1 (non inclusive)
class RandUniform : public RandBase {
public:
    RandUniform(std::size_t Dimensionality_, std::size_t Seed_ = 1);

    virtual RandBase* clone() const;
    virtual void GetUniforms(std::vector<double>& variates);
    virtual void Skip(std::size_t numberOfPaths_);
    virtual void SetSeed(std::size_t Seed_);
    virtual void Reset();

    virtual void ResetDimensionality(std::size_t NewDimensionality_);

private:
    // PMSeedGen InnerGenerator;
    std::default_random_engine InnerGenerator;
    std::size_t InitialSeed;
    std::uniform_real_distribution<double> Distribution;

};


#endif //FINTEGRALPROJECT_RANDUNIFORM_H
