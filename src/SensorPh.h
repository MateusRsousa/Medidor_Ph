#ifndef SENSORPH_H
#define SENSORPH_H

#include <LiquidCrystal_I2C.h>
#include "Sensor.h"

class SensorPh: public Sensor {
private:

    float Ph;
    
public:
    
    SensorPh();
    float getValue()override;
    
};

#endif
