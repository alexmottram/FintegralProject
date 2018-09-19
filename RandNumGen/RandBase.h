/**
 * File: RandBase.h
 * Language: C++
 * Author: Alexander D. Mottram
 *
 * A base class for random number generators.
 *
 * RandBase is a base class for a random number generator heavily based of
 * the class described in "C++ Design Patterns and Derivatives Pricing" by
 * Mark S. Joshi. Can return either a set of N uniformly distributed random
 * numbers, or N normally (Gaussian) distributed random numbers. Subclasses
 * need only provide uniform random values, as GetGaussian is implemented to
 * map a uniform to a Gaussian distribution.
 *
 * Requirements
 * 1) A derived RNG must provide a set of N uniformly distributed random numbers
 * 2) A derived class must be able to reset its seed, reset its results and
 *    skip a certain number of points (mainly useful for psuedo-RNGs)
 */

#ifndef FINTEGRALPROJECT_RANDOMBASE_H
#define FINTEGRALPROJECT_RANDOMBASE_H


#include <vector>
#include <cmath>

class RandBase {
public:

    /**
     * Standard constructor for the base random class.
     *
     * @param Dimensionality_ The number of random numbers that the RNG
     *                        should produce.
     */
    RandBase(std::size_t Dimensionality_);

    /**
     * Returns the number of random points that the RNG should produce.
     *
     * @return Dimensionality, the amount of random numbers to generate.
     */
    std::size_t GetDimensionality() const;

    /**
     * Gets N random numbers that are uniformly distributed, this is a pure
     * virtual function that must be implemented by derived classes.
     *
     * @param variates The uniformly distributed random numbers
     */
    virtual void GetUniforms(std::vector<double>& variates) =0;

    /**
     * Skips a set amount of random numbers, only of use for congruential random
     * number generators, or other pseudo-RNGs.
     *
     * @param numberOfPaths_ The number of random numbers to skip.
     */
    virtual void Skip(std::size_t numberOfPaths_) =0;

    /**
     * Resets the seed for a random number generator.
     *
     * @param Seed The initial seed to reset to.
     */
    virtual void SetSeed(std::size_t Seed) =0;

    /**
     *  Resets the random number generator to its initial state, reseeding
     *  if necessary.
     */
    virtual void Reset() =0;

    // Virtual functions available for overwrite by inheriting classes
    /**
     * If overridden it will follow derived class behaviour, otherwise
     * it will call GetUniforms() and use the Beasley-Springer/Moro approximation
     * for an inverse cumlative normal function to calculate the relative Gaussian
     * random number for each uniform random number.
     *
     * @param variates The amount of random numbers to generate.
     */
    virtual void GetGaussians(std::vector<double>& variates);

    /**
     * Sets a new value for Dimensionality so future calls will return
     * a different amount of random numbers.
     *
     * @param NewDimensionality_ The new amount of random numbers to return.
     */
    virtual void ResetDimensionality(std::size_t NewDimensionality_);

private:
    std::size_t Dimensionality;
};

#endif //FINTEGRALPROJECT_RANDOMMAIN_H
