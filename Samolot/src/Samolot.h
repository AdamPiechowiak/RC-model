#ifndef SAMOLOT_H
#define SAMOLOT_H

#include <Arduino.h>
#include <ArduinoJson.h>
#include "podzespoly/Serwo.h"
#include "podzespoly/Position.h"
#include "podzespoly/Rotation.h"
#include "podzespoly/Direction.h"


#define PINSILNIK 25
#define PINLOTKAL 33
#define PINLOTKAP 32
#define PINSTERW 26
#define PINSTERK 27


class Samolot {
    private:
        
        Serwo silnik;
        Serwo sSterK;
        Serwo sSterW;
        Serwo sLotkaP;
        Serwo sLotkaL;

    protected:

        static Samolot* s;
        

        Samolot();

    public:

        Samolot(Samolot &other) = delete;
        void operator=(const Samolot &) = delete;

        int moc;
        int sterKierunku;
        int sterWysoosci;
        int lotki;
        bool silnikON;
        Position position;
        Rotation rotation;
        Direction direction;
        
        static Samolot *GetInstance();
        //static String deszyfrowanie(char message[512],int len);
        void pokarzDane();
        void pobierzDane();
        void wlaczSilnik();
        void wylaczSilnik();
};

#endif /* SAMOLOT_H */