/**
 * File: InnerDataStorage.h
 * Language: C++
 * Author: Alexander D. Mottram
 *
 * Stores data from multiple paths produced during a monte carlo simulation.
 *
 * InnerDataStorage is a generic base class that can store data that follows
 * the requirements of the PathData class. Data is added to initialised objects
 * by adding a single path of data back at a time. Access is provided by returning
 * all the path data, a single path result or a cross-section of the data in single
 * path.
 *
 */

#ifndef FINTEGRALPROJECT_INNERDATASTORAGE_H
#define FINTEGRALPROJECT_INNERDATASTORAGE_H

#include <cstdlib>
#include <vector>
#include <valarray>
#include "PathData.h"

class InnerDataStorage {
public:

    /**
     * Empty constructor for InnerDataStorage.
     *
     * @return InnerDataStorage object: PathResults -> empty vector of PathData
     */
    InnerDataStorage() : PathResults(std::vector<PathData>()){};

    /**
     * Function used to add one path of data into the inner data structure. Can
     * be overwritten by subclasses that have a model specific method for entering
     * data.
     *
     * @param currentPath_ The PathData entry to add to the inner data structure.
     */
    void AddOnePath(PathData currentPath_);

    /**
     * Function to get a single variables from a single row for all Paths within
     * InnerDataStorage. Example use, to get the final price of an asset for all
     * the Paths prdocued by a monte carlo simulation
     *
     * @param variableX_ The variable to retrieve from each path.
     * @param resultY_ The specific result to extract the variable from for each path.
     *
     * @return a valarray of doubles containing only the selected variable
     *         from resultY_. If there are no paths, or either variableX_ or resultY_
     *         or out of range it returns an empty valarray of doubles.
     */
    std::valarray<double> GetCrossSection(std::size_t variableX_, std::size_t resultY_) const;

    /**
     * Gets the number of paths saved in the InnerDataStorage object but doesn't
     * guarantee that the paths all have fully filled out data.
     *
     * @return the number of filled Paths within the PathResults vector, returning
     *         0 if empty.
     */
    std::size_t GetNumberOfPaths() const;

    /**
     * Gets all data stored within the InnerDataStorage.
     *
     * @return all the PathResults.
     */
    std::vector<PathData> GetPathResults() const;

    /**
     * Returns a single path specified by pathX_.
     *
     * @param pathX_ the index of the path to return.
     *
     * @return PathData specified by pathX_. If pathX_ is out of bounds returns an
     *         empty PathData object.
     */
    PathData GetPathX(std::size_t pathX_) const;

private:
    std::vector<PathData> PathResults;
};


#endif //FINTEGRALPROJECT_INNERDATASTORAGE_H
