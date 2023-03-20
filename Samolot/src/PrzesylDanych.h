#ifndef PRZESYLDANYCH_H
#define PRZESYLDANYCH_H

#include <Arduino.h>
#include <ArduinoJson.h>
#include <HTTPClient.h>
#include <WiFi.h>
#include "AES.h"
#include "Samolot.h"
#include "podzespoly/Scanner.h"
#include "podzespoly/Position.h"


class PrzesylDanych {
    public:
        static String deszyfrowanie(String message,int len);
        static void odbierzDane();
        static void wyslijGPS();
        static void wyslijDaneSieci();
        static void wyslijGPSWszystko();
        static int sprawdzPolaczenie();

        static String adres;
};

#endif /* PRZESYLDANYCH_H */