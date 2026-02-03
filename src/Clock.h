#ifndef CLOCK_H
#define CLOCK_H

#include <ctime>
#include <sys/time.h>
#include <Arduino.h>

class Clock {

    public:
        
        void init();
        void setDateTime(int year, int month, int day, int hour, int minute, int second);
        String getDateTime(); // Obtém a data e hora formatadas como string
    
        
 };
    
    #endif
    