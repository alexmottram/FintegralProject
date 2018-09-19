/**
 * File: RandBase.h
 * Language: C++
 * Author: Alexander D. Mottram
 *
 * A uniformly distributed random number generator using <random>.
 *
 * RandBase is a subclass class of RandBase that returns only a uniform distribution
 * of pseudo random number using the stl <random> class as an inner generator. Heavily
 * based off the Random Uniform class described in "C++ Design Patterns and Derivatives
 * Pricing" by Mark S. Joshi.
 */

#ifndef FINTEGRALPROJECT_RANDUNIFORM_H
#define FINTEGRALPROJECT_RANDUNIFORM_H

#include <random>
#include <cstdlib>
#include "RandBase.h"

// Include note about how we are working over a closed interval between 0 and 1 (non inclusive)
class RandUniform : public RandBase {
public:

    /**
     * Standard constructor for a RandUniform object with default seed = 1.
     *
     * @param Dimensionality_ The amount of random numbers to return each time.
     * @param Seed_ The initial starting seed of the psuedo RNG.
     */
    RandUniform(std::size_t Dimensionality_, std::size_t Seed_ = 1);

    /**
     * Writes a series of uniformly distributed (bettwen 0 and 1) random numbers
     * into the vector referenced by variates. Note, that it will never return
     * 0 or 1 themselves to avoid issues when using an inverse cumulative normal
     * distribution.
     *
     * @param variates A reference to the vector to fill with randomly generated numbers.
     */
    virtual void GetUniforms(std::vector<double>& variates);

    /**
     * Implements Skip from RandBase by getting X number of random uniforms using
     * GetUniform().
     *
     * @param numberOfPaths_ The number of random uniform numbers skipped.
     */
    virtual void Skip(std::size_t numberOfPaths_);

    /**
     * Implements SetSeed from RandBase by setting the initial seed of the InnerGenerator
     * and resetting the inner generator to that new seed.
     *
     * @param Seed_ The new seed to set and initialise the inner generator to.
     */
    virtual void SetSeed(std::size_t Seed_);

    /**
     * Resets the inner generator to the seed value in object member "InitialSeed".
     */
    virtual void Reset();

    /**
     * Allows changing of the number of random numbers to return when using GetUniform
     * or GetGaussian functions.
     *
     * @param NewDimensionality_ The new amount of random numbers to return.
     */
    virtual void ResetDimensionality(std::size_t NewDimensionality_);

private:
    std::default_random_engine InnerGenerator;
    std::size_t InitialSeed;
    std::uniform_real_distribution<double> Distribution;

};


#endif //FINTEGRALPROJECT_RANDUNIFORM_H
