//
// Created by Alex on 18/09/2018.
//

#ifndef FINTEGRALPROJECT_PROGRESSBAR_H
#define FINTEGRALPROJECT_PROGRESSBAR_H

#include <cstdlib>
#include <iostream>
#include <string>

class ProgressBar {
public:
    ProgressBar(std::size_t LoopSize_, std::string Message_);

    void Refresh(std::size_t LoopIteration_);
    void Reset();
    void ResetLoopSize();


private:
    std::size_t LoopSize;
};


#endif //FINTEGRALPROJECT_PROGRESSBAR_H
