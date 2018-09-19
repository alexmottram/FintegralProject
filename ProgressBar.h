/**
 * File: ProgressBar.h
 * Language: C++
 * Author: Alexander D. Mottram
 *
 * Small tool to track progress through a loop with a known number of iterations.
 *
 * ProgressBar is a class that can be created to track progress through
 * a for loop printing the current position to the console as percentage of
 * the expected number of iterations.
 */

#ifndef FINTEGRALPROJECT_PROGRESSBAR_H
#define FINTEGRALPROJECT_PROGRESSBAR_H

#include <cstdlib>
#include <iostream>
#include <string>

class ProgressBar {
public:

    /**
     * Standard constructor for ProgressBar, also prints out a message to
     * the console as part of construction.
     *
     * @param LoopSize_ The expected number of iterations in the for loop.
     * @param Message_  A string containing the message that should be printed
     *                  to console at the time of construction
     */
    ProgressBar(std::size_t LoopSize_, std::string Message_);

    /**
     * Refreshs a ProgressBar object by entering the current loop iteration.
     *
     * @param LoopIteration_ The current iteration number of the loop being tracked.
     */
    void Refresh(std::size_t LoopIteration_);


private:
    std::size_t LoopSize;
};


#endif //FINTEGRALPROJECT_PROGRESSBAR_H
