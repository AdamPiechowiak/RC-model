#include "UDPMessengerService.h"

UDPMessengerService::UDPMessengerService() {
}

UDPMessengerService::UDPMessengerService(WiFiUDP u) {
  udp = u;
}

String UDPMessengerService::pobierzKomende()
{
    
    int packetSize = udp.parsePacket();
    if(packetSize >0)
    {
        //Serial.println(packetSize);
        char incomingPacket[512];
        int len = udp.read(incomingPacket, 512);
        if (len > 0) {
        incomingPacket[len] = 0;
        }
        //Serial.println(incomingPacket);
        return incomingPacket;
    }
    return "";
}
