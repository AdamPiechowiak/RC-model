#ifndef STRINGSPLIT_H
#define STRINGSPLIT_H

#include <Arduino.h>
#include <ArduinoJson.h>
#include "AES.h"

class StringSplit {
    public:
        static int liczbaPodstringow(String dane,char delimter);
        static void podzielString(String dane,char delimter, String tab[]);
};

#endif /* STRINGSPLIT_H */