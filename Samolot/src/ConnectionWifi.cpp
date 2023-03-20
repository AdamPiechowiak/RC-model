#include "ConnectionWifi.h"

void ConnectionWifi::scan()
{
    Serial.println("scan start");

    // WiFi.scanNetworks will return the number of networks found
    int n = WiFi.scanNetworks();
    Serial.println("scan done");
    if (n == 0) {
        Serial.println("no networks found");
    } else {
        Serial.print(n);
        Serial.println(" networks found");
        for (int i = 0; i < n; ++i) {
            // Print SSID and RSSI for each network found
            Serial.print(i + 1);
            Serial.print(": ");
            Serial.print(WiFi.SSID(i));
            Serial.print(" (");
            Serial.print(WiFi.RSSI(i));
            Serial.print(") ");
            switch(WiFi.encryptionType(i))
            {
                case WIFI_AUTH_OPEN:
                     Serial.println("OPEN");
                    break;
                case WIFI_AUTH_WEP:
                     Serial.println("WEP");
                    break;
                case WIFI_AUTH_WPA_PSK:
                     Serial.println("WPA_PSK");
                    break;
                case WIFI_AUTH_WPA2_PSK:
                     Serial.println("WPA2_PSK");
                    break;
                case WIFI_AUTH_WPA_WPA2_PSK:
                     Serial.println("WPA_WPA2_PSK");
                    break;
                case WIFI_AUTH_WPA2_ENTERPRISE:
                     Serial.println("WPA2_ENTERPRISE");
                    break;
                default:
                     Serial.println("Nieznane");
                    break;
            }
            //Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" Bez hasła":" Z hasłem");
            delay(10);
        }
    }
    Serial.println("");
}

void ConnectionWifi::connect()//const char* ssid,const char* password)
{
    String ssid[2]= {"moja_siec","router1"};
    String password[2] = {"kijanka1","Domino119M"};
    WiFi.disconnect();
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    Serial.println("Connecting to WiFi ..");
    while(WiFi.status() != WL_CONNECTED)
    {
        for(int i=0; i<2; i++)
        {
            Serial.println("Connecting to "+ssid[i]);
            WiFi.begin((const char *)ssid[i].c_str(), (const char *)password[i].c_str());
            delay(2000);
            if(WiFi.status() == WL_CONNECTED) {
                break;
            }
        }
    }
    
    PrzesylDanych::adres = "http://192.168.0.106:4444";

    Serial.println(WiFi.status());
    Serial.println(WiFi.localIP());
}

void ConnectionWifi::createNetwork()
{
    IPAddress local_IP(192,168,0,1);
    IPAddress gateway(192,168,0,2);
    IPAddress subnet(255,255,255,0);

    String ssid = "nielot";
    String password = "Kaszanka3";
    WiFi.disconnect();
    WiFi.mode(WIFI_AP);
    //WiFi.softAPConfig(local_IP, gateway, subnet);
    WiFi.softAP((const char *)ssid.c_str(), (const char *)password.c_str());

    
    PrzesylDanych::adres = "http://192.168.4.2:4444";

    Serial.println(WiFi.status());
    Serial.println(WiFi.localIP());
}