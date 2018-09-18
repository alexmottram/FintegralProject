//
// Created by Alex on 14/09/2018.
//

#ifndef FINTEGRALPROJECT_RANDOMBASE_H
#define FINTEGRALPROJECT_RANDOMBASE_H


#include <vector>
#include <cmath>

class RandBase {
public:
    RandBase(std::size_t Dimensionality_);
    virtual ~RandBase() {}
    virtual RandBase* clone() const =0;

    std::size_t GetDimensionality() const;

    // Pure virtual functions required by inheriting classes
    virtual void GetUniforms(std::vector<double>& variates) =0;
    virtual void Skip(std::size_t numberOfPaths_) =0;
    virtual void SetSeed(std::size_t Seed) =0;
    virtual void Reset() =0;

    // Virtual functions available for overwrite by inheriting classes
    virtual void GetGaussians(std::vector<double>& variates);
    virtual void ResetDimensionality(std::size_t NewDimensionality_);

private:
    std::size_t Dimensionality;
};

#endif //FINTEGRALPROJECT_RANDOMMAIN_H
