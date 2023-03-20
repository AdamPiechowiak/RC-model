#ifndef DIRECTION_H
#define DIRECTION_H

//HMC5883L

#include <Arduino.h>
#include <Wire.h>

class Direction {
    public:

        bool is;

        double x;
        double y;
        double z;
        

        Direction();
        void aktualizuj();
        void wyswietl();

};

#endif /* DIRECTION_H */