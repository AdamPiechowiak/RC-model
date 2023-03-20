#include "Position.h"

Position::Position()
{
    this->latitude = 0;
    this->longitude = 0;
    this->altitude = 0;
}

void Position::aktualizuj()
{
 
  
  int RXD2 =16;
  int TXD2 =17;

  Serial2.begin(9600,SERIAL_8N1, RXD2, TXD2);

  TinyGPSPlus gps;

  boolean newData = false;
  for (unsigned long start = millis(); millis() - start < 1000;)
  {
    if(Serial2.available()!=0)
      Serial.println(Serial2.available());
      
      while (Serial2.available())
      {
        
    //Serial.print((char)Serial2.read());
        byte b = Serial2.read();
        Serial.print((char)b);
          if (gps.encode(b))
          {
               newData = true;
           }
       }

  }

    //If newData is true
    if(newData == true)
    {
        newData = false;
        if (gps.location.isValid())
        {
            this->aktualne = true;
            this->latitude = gps.location.lat();
            this->longitude = gps.location.lng();
            this->altitude = gps.altitude.meters();
        }
        else
        {
            this->aktualne = false;
        }

        Serial.print(F("Location: ")); 
  if (gps.location.isValid())
  {
    Serial.print(gps.location.lat(), 6);
    Serial.print(F(","));
    Serial.print(gps.location.lng(), 6);
  }
  else
  {
    Serial.print(F("INVALID"));
  }

  Serial.print(F("  Date/Time: "));
  if (gps.date.isValid())
  {
    Serial.print(gps.date.month());
    Serial.print(F("/"));
    Serial.print(gps.date.day());
    Serial.print(F("/"));
    Serial.print(gps.date.year());
  }
  else
  {
    Serial.print(F("INVALID"));
  }

  Serial.print(F(" "));
  if (gps.time.isValid())
  {
    if (gps.time.hour() < 10) Serial.print(F("0"));
    Serial.print(gps.time.hour());
    Serial.print(F(":"));
    if (gps.time.minute() < 10) Serial.print(F("0"));
    Serial.print(gps.time.minute());
    Serial.print(F(":"));
    if (gps.time.second() < 10) Serial.print(F("0"));
    Serial.print(gps.time.second());
    Serial.print(F("."));
    if (gps.time.centisecond() < 10) Serial.print(F("0"));
    Serial.print(gps.time.centisecond());
  }
  else
  {
    Serial.print(F("INVALID"));
  }

  Serial.println();

    }
    else
    {
        this->aktualne = false;
        Serial.println("nie działa");
    }  

}

void Position::wyswietl()
{
    
    Serial.print("szerokość geograficzna: ");
    Serial.println(this->latitude,8);
    Serial.print("długość geograficzna: ");
    Serial.println(this->longitude,8);
    Serial.print("wysokość: ");
    Serial.println(this->altitude);
    if(this->aktualne)
    {
        Serial.println("aktualne");
    }
    else
    {
        Serial.println("nie aktualne");
    }
    
    
}


String Position::wszystko()
{
  
    String dane ="";

    TinyGPSPlus gps;

    
    boolean newData = false;

    while (Serial2.available() > 0)
    {
      //Serial.print(char(Serial2.read()));

      if (gps.encode(Serial2.read()))
            {
                newData = true;
            }
    }

    if(newData == true)
    {

        dane += "Location: ";

        Serial.print(F("Location: ")); 
  if (gps.location.isValid())
  {
    dane += String(gps.location.lat(), 6);
    dane +=",";
    dane += String(gps.location.lng(), 6);
    dane +=",";
    dane += String(gps.altitude.meters(), 2);
    Serial.print(gps.location.lat(), 6);
    Serial.print(F(","));
    Serial.print(gps.location.lng(), 6);
    Serial.print(F(","));
    Serial.print(gps.altitude.meters(), 2);
  }
  else
  {
    dane +="INVALID";
    Serial.print(F("INVALID"));
  }

    dane +="  Date/Time: ";
  Serial.print(F("  Date/Time: "));
  if (gps.date.isValid())
  {
    
    dane +=String(gps.date.day());
    
    dane +="/";
    
    dane +=String(gps.date.month());
    
    dane +="/";
    
    
    dane +=String(gps.date.year());
    Serial.print(gps.date.day());
    Serial.print(F("/"));
    Serial.print(gps.date.month());
    Serial.print(F("/"));
    Serial.print(gps.date.year());
  }
  else
  {
    dane +="INVALID";
    Serial.print(F("INVALID"));
  }

    dane +=" ";
  Serial.print(F(" "));
  if (gps.time.isValid())
  {
    if (gps.time.hour() < 10) Serial.print(F("0"));
    
    dane +=String(gps.time.hour());
    dane +=":";
    Serial.print(gps.time.hour());
    Serial.print(F(":"));
    if (gps.time.minute() < 10) Serial.print(F("0"));
    dane +=String(gps.time.minute());
    dane +=":";
    Serial.print(gps.time.minute());
    Serial.print(F(":"));
    if (gps.time.second() < 10) Serial.print(F("0"));
    dane +=String(gps.time.second());
    dane +=".";
    Serial.print(gps.time.second());
    Serial.print(F("."));
    if (gps.time.centisecond() < 10) Serial.print(F("0"));
    Serial.print(gps.time.centisecond());
    Serial.print(gps.time.centisecond());
  }
  else
  {
    dane +="INVALID";
    Serial.print(F("INVALID"));
  }

    dane +="";
  Serial.println();

    }
    else
    {
        this->aktualne = false;
    dane +="brak danych";
        Serial.println("nie działa");
    }  
  /*
    String dane ="";

    int RXD2 =16;
    int TXD2 =17;

    Serial2.begin(9600,SERIAL_8N1, RXD2, TXD2);

    TinyGPSPlus gps;

    boolean newData = false;
    //for (unsigned long start = millis(); millis() - start < 1000;)
    //{
      

        while (Serial2.available()> 0)
        {
          
          Serial.print(char(Serial2.read()));
            //if (gps.encode(Serial2.read()))
            //{
                //newData = true;
            //}
        }
    //}

    //If newData is true
    if(newData == true)
    {

        dane += "Location: ";

        Serial.print(F("Location: ")); 
  if (gps.location.isValid())
  {
    dane += String(gps.location.lat(), 6);
    dane +=",";
    dane += String(gps.location.lng(), 6);
    dane +=",";
    dane += String(gps.altitude.meters(), 2);
    Serial.print(gps.location.lat(), 6);
    Serial.print(F(","));
    Serial.print(gps.location.lng(), 6);
    Serial.print(F(","));
    Serial.print(gps.altitude.meters(), 2);
  }
  else
  {
    dane +="INVALID";
    Serial.print(F("INVALID"));
  }

    dane +="  Date/Time: ";
  Serial.print(F("  Date/Time: "));
  if (gps.date.isValid())
  {
    
    dane +=String(gps.date.month());
    
    dane +="/";
    
    dane +=String(gps.date.day());
    
    dane +="/";
    
    dane +=String(gps.date.year());
    Serial.print(gps.date.month());
    Serial.print(F("/"));
    Serial.print(gps.date.day());
    Serial.print(F("/"));
    Serial.print(gps.date.year());
  }
  else
  {
    dane +="INVALID";
    Serial.print(F("INVALID"));
  }

    dane +=" ";
  Serial.print(F(" "));
  if (gps.time.isValid())
  {
    if (gps.time.hour() < 10) Serial.print(F("0"));
    
    dane +=String(gps.time.hour());
    dane +=":";
    Serial.print(gps.time.hour());
    Serial.print(F(":"));
    if (gps.time.minute() < 10) Serial.print(F("0"));
    dane +=String(gps.time.minute());
    dane +=":";
    Serial.print(gps.time.minute());
    Serial.print(F(":"));
    if (gps.time.second() < 10) Serial.print(F("0"));
    dane +=String(gps.time.second());
    dane +=".";
    Serial.print(gps.time.second());
    Serial.print(F("."));
    if (gps.time.centisecond() < 10) Serial.print(F("0"));
    Serial.print(gps.time.centisecond());
    Serial.print(gps.time.centisecond());
  }
  else
  {
    dane +="INVALID";
    Serial.print(F("INVALID"));
  }

    dane +="";
  Serial.println();

    }
    else
    {
        this->aktualne = false;
    dane +="brak danych";
        Serial.println("nie działa");
    }  
    */
    return dane;
}