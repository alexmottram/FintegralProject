//
// Created by Alex on 14/09/2018.
//

#include "PMSeedGen.h"

const std::size_t A = 16807;
const std::size_t M = 2147483647;
const std::size_t Q = 127773;
const std::size_t R = 2836;

PMSeedGen::PMSeedGen(long Seed_) : Seed(Seed_ ){
    if (Seed == 0){
        Seed = 1;
    }
}

void PMSeedGen::SetSeed(long Seed_) {
    Seed = Seed_;
    if (Seed == 0) {
        Seed = 1;
    }
}

std::size_t PMSeedGen::Max() {
    return M-1;
}

std::size_t PMSeedGen::Min() {
    return 1;
}

long PMSeedGen::GetOneRandomInteger() {
    long k;
    k = Seed/Q;
    Seed = A*(Seed-k*Q)-R*k;

    if(Seed < 0){
        Seed += M;
    }

    return Seed;
}

