#ifndef SERWO_H
#define SERWO_H

#include <Arduino.h>
#include <ESP32Servo.h>


class Serwo : public Servo {
    public:
        
        int max;
        int center;
        int min;

        Serwo();
        Serwo(int min, int center ,int max);

};

#endif /* SERWO_H */