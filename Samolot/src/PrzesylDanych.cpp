#include "PrzesylDanych.h"

String PrzesylDanych::adres = "";

int PrzesylDanych::sprawdzPolaczenie()
{
  
    int ret=0;

    HTTPClient http;
    http.setConnectTimeout(1000);

    String serverPath = adres+"/connection";
      
    // Your Domain name with URL path or IP address with path
    http.begin(serverPath.c_str());

    // Specify content-type header
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");

    int httpResponseCode = http.GET();
      
      if (httpResponseCode>0) {
        String payload = http.getString();
        if(payload == "ok")
        {
          ret = 1;
        }
      }
      // Free resources
      http.end();

      return ret;
}

void PrzesylDanych::odbierzDane()
{
    

    HTTPClient http;
    //http.setConnectTimeout(2000);

    String serverPath = adres+"/";
      
    // Your Domain name with URL path or IP address with path
    http.begin(serverPath.c_str());

    // Specify content-type header
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    
    int httpResponseCode = http.GET();
    

      if (httpResponseCode>0) {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
        String payload = http.getString();
        
        Serial.println(payload);

        if(payload!="")
        {
          DynamicJsonDocument doc(1024);
          deserializeJson(doc, payload);

          Samolot* sam = Samolot::GetInstance();
          
          if(doc["s"]=="Y")
          {
              sam->wlaczSilnik();
          }

          if(doc["m"]!=nullptr)
          {
              sam->moc = doc["m"];
          }

          if(doc["sk"]!=nullptr)
          {
              sam->sterKierunku = doc["sk"];
          }

          if(doc["sw"]!=nullptr)
          {
              sam->sterWysoosci = doc["sw"];
          }

          if(doc["l"]!=nullptr)
          {
              sam->lotki = doc["l"];
          }
          
          
          sam->pobierzDane();
          //sam->pokarzDane();
          //sam->rotation.wyswietl();
          
        }
        else
        {
          
          Serial.println("Brak zmian z kontrlera");
        }

      }
      else {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
      }
      // Free resources
      http.end();



    
   
}

String PrzesylDanych::deszyfrowanie(String message,int len)
{
    AES aes = AES();

    const unsigned char bkey[32] = { 43, 254, 249, 173, 103, 64, 133, 151, 177, 92, 35, 190, 170, 118, 110, 80, 134, 185, 232, 27, 105, 15, 207, 180, 225, 114, 37, 168, 205, 189, 226, 210 };
    const unsigned char biv[16] = { 207, 101, 235, 121, 143, 208, 82, 189, 217, 132, 4, 233, 176, 218, 139, 6 };
    
    unsigned char *w = aes.DecryptCBC((const unsigned char *)message.c_str(),len,bkey,biv);
    String r;
    int n = w[0]+w[1]+w[2]+w[3];
    /*Serial.println(w[0]);
    Serial.println(w[1]);
    Serial.println(w[2]);
    Serial.println(w[3]);*/
    for(int i = 14;i<n+14;i++)
    {
        r+=(char)w[i];
    }
    //Serial.println();
    return r;
}

void PrzesylDanych::wyslijGPS()
{
    
  int m1 = millis();
    Samolot* sam = Samolot::GetInstance();
    
    sam->position.aktualizuj();
  int m2 = millis();
  Serial.println("aktualizacja danych");
  Serial.println(m2-m1);
    sam->position.wyswietl();

    HTTPClient http;

    String serverPath = adres+"/gps";
      
    // Your Domain name with URL path or IP address with path
    http.begin(serverPath.c_str());

    // Specify content-type header
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");

    //plain text
    http.addHeader("Content-Type", "text/plain");
    if(sam->position.aktualne)
    {
      http.addHeader("ok", "true");
      http.addHeader("lat", String(sam->position.latitude,8));
      http.addHeader("lon", String(sam->position.longitude,8));
      http.addHeader("alt", String(sam->position.altitude,2));
    }
    else
    {
      http.addHeader("ok", "false");
    }
    int httpResponseCode = http.POST("Hello, World!");

    // Data to send with HTTP POST
    //String httpRequestData = "lat=tPmAT5Ab3j7F9";

    // Send HTTP POST request
    //int httpResponseCode = http.POST(httpRequestData);

    // Send HTTP GET request
    //int httpResponseCode = http.GET();
      
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
      
}

void PrzesylDanych::wyslijGPSWszystko()
{
    
    Samolot* sam = Samolot::GetInstance();
    

    HTTPClient http;

    String serverPath = adres+"/gpsfull";
      
    // Your Domain name with URL path or IP address with path
    http.begin(serverPath.c_str());

    // Specify content-type header
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");

    //plain text
    http.addHeader("Content-Type", "text/plain");
    http.addHeader("full", String(sam->position.wszystko()));
    int httpResponseCode = http.POST("Hello, World!");

    // Data to send with HTTP POST
    //String httpRequestData = "lat=tPmAT5Ab3j7F9";

    // Send HTTP POST request
    //int httpResponseCode = http.POST(httpRequestData);

    // Send HTTP GET request
    //int httpResponseCode = http.GET();
      
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
}


void PrzesylDanych::wyslijDaneSieci()
{
    

    HTTPClient http;

    String serverPath = adres+"/siec";
      
    // Your Domain name with URL path or IP address with path
    http.begin(serverPath.c_str());

    // Specify content-type header
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");

    //plain text
    http.addHeader("Content-Type", "text/plain");
    http.addHeader("ssid", WiFi.SSID());
    http.addHeader("rssi", String(WiFi.RSSI()));
    int httpResponseCode = http.POST("Hello, World!");

    // Data to send with HTTP POST
    //String httpRequestData = "lat=tPmAT5Ab3j7F9";

    // Send HTTP POST request
    //int httpResponseCode = http.POST(httpRequestData);

    // Send HTTP GET request
    //int httpResponseCode = http.GET();
      
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
}
