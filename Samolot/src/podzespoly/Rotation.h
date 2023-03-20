#ifndef ROTATION_H
#define ROTATION_H

#include <Wire.h>
#include <Arduino.h>

class Rotation {
    public:

        bool is;

        double x;
        double y;
        double z;

        Rotation();
        void aktualizuj();
        void wyswietl();

};

#endif /* ROTATION_H */