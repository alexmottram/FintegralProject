//
// Created by Alex on 18/09/2018.
//

#include "ProgressBar.h"

ProgressBar::ProgressBar(std::size_t LoopSize_, std::string Message_) : LoopSize(LoopSize_) {

    std::cout << Message_ << std::endl;
}

void ProgressBar::Refresh(std::size_t LoopIteration_) {
    double progress = static_cast<double>(LoopIteration_)/ static_cast<double>(LoopSize);
    int barWidth = 70;
    std::cout << "[";
    int pos = barWidth * progress;
    for (int j = 0; j < barWidth; ++j) {
        if (j < pos) std::cout << "=";
        else if (j == pos) std::cout << ">";
        else std::cout << " ";

    }
    std::cout << "] " << int(progress * 100.0) << " %\r";
    std::cout.flush();
}
