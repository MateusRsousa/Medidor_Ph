#ifndef SENSOR_H
#define SENSOR_H

class Sensor {
public:
    virtual float getValue() = 0; 
    virtual ~Sensor() {}          
};

#endif
