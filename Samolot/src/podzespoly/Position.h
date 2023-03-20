#ifndef POSITION_H
#define POSITION_H

#include <Arduino.h>
#include <TinyGPS++.h>

class Position {
    public:

        double latitude;
        double longitude;
        double altitude;

        bool aktualne;
        
        Position();
        void aktualizuj();
        void wyswietl();
        String wszystko();

};

#endif /* POSITION_H */