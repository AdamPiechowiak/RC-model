#ifndef UDPMESSENGERSERVICE_H
#define UDPMESSENGERSERVICE_H

#include <WiFiUdp.h>
#include <WiFi.h>

class UDPMessengerService {
  private:
    WiFiUDP udp;

  public:
    UDPMessengerService();
    UDPMessengerService(WiFiUDP u);

    String pobierzKomende();
};

#endif /* UDPMESSENGERSERVICE_H */