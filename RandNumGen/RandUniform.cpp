//
// Created by Alex on 14/09/2018.
//

#include "RandUniform.h"

RandUniform::RandUniform(std::size_t Dimensionality_, size_t Seed_)
        : RandBase(Dimensionality_), InnerGenerator(Seed_), InitialSeed(Seed_),
          Distribution(std::uniform_real_distribution<double>(0.0,1.0)) {

}

RandBase* RandUniform::clone() const {

    return new RandUniform(*this);
}

void RandUniform::GetUniforms(std::vector<double> &variates) {


    for (size_t i = 0; i < GetDimensionality(); i++) {

        double x = Distribution(InnerGenerator);

        while (x==0.0 || x==1.0) {
            x = Distribution(InnerGenerator);
        }
        variates.push_back(x);
    }
}

void RandUniform::Skip(std::size_t numberOfPaths_) {

    std::vector<double> tmp;

    for (size_t i = 0; i < numberOfPaths_; i++) {
        GetUniforms(tmp);
    }
}

void RandUniform::SetSeed(std::size_t Seed_) {
    InitialSeed = Seed_;
    InnerGenerator = std::default_random_engine(Seed_);
}

void RandUniform::Reset() {
    InnerGenerator = std::default_random_engine(InitialSeed);
}

void RandUniform::ResetDimensionality(std::size_t NewDimensionality_) {
    RandBase::ResetDimensionality(NewDimensionality_);
    InnerGenerator = std::default_random_engine(InitialSeed);
}