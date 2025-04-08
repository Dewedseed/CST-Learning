#include "xtask_fac.h"
#include "fftask.h"
#include "log_fac.h"

#include <iostream>
#include <memory>
#include <string>
using namespace std;

std::unique_ptr<XTask> XTaskFactory::Create(int type) {
    LOGDEBUG("Create XTaskFac Type " + to_string(type));
    switch (type) {
        case 0:
            return make_unique<FFTask>();
        default:
            cerr << "XTask type: " << type << " not support!" << endl;
            break;
    }
    return nullptr;
}
