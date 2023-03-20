#ifndef CONNECTIONWIFI_H
#define CONNECTIONWIFI_H

#include <WiFi.h>
#include <Arduino.h>
#include "PrzesylDanych.h"

// ConnectionWifi.h

class ConnectionWifi
{
 public:

     //scan and display Networks
    static void scan();
    
     //connect to Network
    static void connect();
    
     //connect to Network
    static void createNetwork();

};


#endif /* CONNECTIONWIFI_H */

