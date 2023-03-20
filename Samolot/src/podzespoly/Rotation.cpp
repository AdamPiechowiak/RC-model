#include "Rotation.h"

#define ADDRESS 0x53

Rotation::Rotation()
{
    Wire.begin( 21, 22 );

    
    Wire.beginTransmission(ADDRESS);
    int error = Wire.endTransmission();
    
    if (error == 0)
    {
      this->is=true;

        //ustawienie trybu pomiaru
        Wire.beginTransmission(ADDRESS);
        Wire.write(0x2D);
        Wire.write(0x8);
        Wire.endTransmission();

        delay(10);
        //poprawka oś x
        Wire.beginTransmission(ADDRESS);
        Wire.write(0x1E);
        Wire.write(-3);
        Wire.endTransmission();

        delay(10);
        //poprawka oś y
        Wire.beginTransmission(ADDRESS);
        Wire.write(0x1F);
        Wire.write(-1);
        Wire.endTransmission();
        
        delay(10);
        //poprawka oś z
        Wire.beginTransmission(ADDRESS);
        Wire.write(0x20);
        Wire.write(-7);
        Wire.endTransmission();
        delay(10);
    }
    else
    {
      this->is=false;
    }



    
}

void Rotation::aktualizuj()
{
    if(this->is)
    {
        Wire.beginTransmission(ADDRESS);
        Wire.write(0x32);
        Wire.endTransmission(false);

        Wire.requestFrom(ADDRESS, 6);

        if(Wire.available())
        {
            short int x,y,z;
            x = (Wire.read() | Wire.read()<<8);
            this->x = double(x)/256;
            y = (Wire.read() | Wire.read()<<8);
            this->y = double(y)/256;
            z = (Wire.read() | Wire.read()<<8);
            this->z = double(z)/256;
        }
    }



    
}

void Rotation::wyswietl()
{
    if(this->is)
    {
    Serial.print("rotacja x: ");
    Serial.println(this->x);
    Serial.print("rotacja y: ");
    Serial.println(this->y);
    Serial.print("rotacja z: ");
    Serial.println(this->z);
    }
    else
    {
    Serial.println("nie podłączono czujnika");
    }
    
}