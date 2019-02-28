#ifndef __sensors_h_
#define __sensors_h_

#define HIGHPRESSURE_READ 34
#define LOWPRESSURE_READ 35


class Sensors{
    public:
        Sensors();
        ~Sensors(){};
        bool getLowStatus();
        bool getHighStatus();    
};



#endif