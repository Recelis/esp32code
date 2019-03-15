#ifndef __errors_h_
#define __errors_h_

#include "sensors.h"

#define ERROR_LOW 1
#define NO_ERROR 0

class Errors {
    public:
        Errors();
        ~Errors(){};
        int returnError();
        void printError();
    private:
        int error;
        int debounceCount;
};

#endif
