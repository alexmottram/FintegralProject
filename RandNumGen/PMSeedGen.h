//
// Created by Alex on 14/09/2018.
//

#ifndef FINTEGRALPROJECT_PMSEEDGEN_H
#define FINTEGRALPROJECT_PMSEEDGEN_H

#include <cstdlib>

class PMSeedGen {
public:
    PMSeedGen(long Seed_ = 1);

    long GetOneRandomInteger();
    void SetSeed(long Seed_);

    static std::size_t Max();
    static std::size_t Min();

private:
    long Seed;
};


#endif //FINTEGRALPROJECT_PMSEEDGEN_H
