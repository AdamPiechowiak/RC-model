#include <Arduino.h>
#include <HTTPClient.h>
#include <Wire.h>
#include "ConnectionWifi.h"
#include "PrzesylDanych.h"
#include "podzespoly/Scanner.h"
#include <WiFi.h>



int bezPolaczenia = 0;

void setup() {
  Serial.begin(115200);
  
    int RXD2 =16;
    int TXD2 =17;
  Serial2.begin(9600,SERIAL_8N1, RXD2, TXD2);
  Serial.println("start");
  //ConnectionWifi::scan();
  //ConnectionWifi::connect();
  ConnectionWifi::createNetwork();


  Serial.println("Setup done");
  
}

void loop() {
  
  int m = millis();
  int m2;
  int m3;
  int m4;
  //Serial.println(WiFi.SSID());
  //Serial.println(WiFi.RSSI());
  //PrzesylDanych::wyslijGPSWszystko();
  //PrzesylDanych::wyslijDaneSieci();
  if(PrzesylDanych::sprawdzPolaczenie())
  {
    bezPolaczenia = 0;
  //m2 = millis();
  //Serial.println("czas sprawdzenia polaczenia");
  //Serial.println(m2-m);
    Serial.println("jest polaczenie z kontrolerem");
    //wysłanie danych
    //Serial.println("wysylanie danych");
    //PrzesylDanych::wyslijGPS();
  //m3 = millis();
  //Serial.println("czas wyslania danych");
  //Serial.println(m3-m2);
    //pobranie danych
    Serial.println("odbieranie danych");
    PrzesylDanych::odbierzDane();
  //m4 = millis();
  //Serial.println("czas odbioru danych");
  //Serial.println(m4-m3);

  }
  else{
    if(bezPolaczenia>2)
    {
      Samolot* sam = Samolot::GetInstance();
      sam->wylaczSilnik();
    }
    Serial.println("nie ma polaczenia z kontrolerem");
    bezPolaczenia++;
  }
  //Serial.println("czas jesnej petli");
  //Serial.println(m4-m);
  //delay(2000);
  
  /*

  HTTPClient http;

      String serverPath = "http://192.168.0.106:4444";
      
      // Your Domain name with URL path or IP address with path
      http.begin(serverPath.c_str());
      
      // Send HTTP GET request
      int httpResponseCode = http.GET();
      
      if (httpResponseCode>0) {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
        String payload = http.getString();
        
        Serial.println(payload);
      }
      else {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
      }
      // Free resources
      http.end();
      Serial.println("aaa");
  
  Samolot* sam = Samolot::GetInstance();
  
  sam->position.aktualizuj();
  sam->position.wyswietl();
  //sam->rotation.aktualizuj();
  //sam->rotation.wyswietl();
  //sam->direction.aktualizuj();
  //sam->direction.wyswietl();
  int packetSize = udp.parsePacket();
    if(packetSize >0)
    {
        char incomingPacket[512];
        int len = udp.read(incomingPacket, 512);

        if (len > 0) {
          incomingPacket[len] = 0;
        }
        String m = PrzesylDanych::deszyfrowanie(incomingPacket,len);

       PrzesylDanych::odbierzDane(m);
    }*/
  //delay(2000);
}
