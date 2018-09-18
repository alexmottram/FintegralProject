//
// Created by alexa on 16/09/2018.
//

#ifndef FINTEGRALPROJECT_MODELBASE_H
#define FINTEGRALPROJECT_MODELBASE_H

#include "../DataStorage/InnerDataStorage.h"

class ModelBase {
public:

    virtual void RunModelOnce() =0;

private:

};


#endif //FINTEGRALPROJECT_MODELBASE_H
