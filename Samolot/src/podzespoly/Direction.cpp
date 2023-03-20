#include "Direction.h"


#define ADDRESS 0x1E

Direction::Direction()
{
    Wire.begin( 21, 22 );

    
    Wire.beginTransmission(ADDRESS);
    int error = Wire.endTransmission();
    
    if (error == 0)
    {
      this->is=true;

      Wire.beginTransmission(ADDRESS);
      Wire.write(0x00);
      Wire.write(0x50);
      Wire.endTransmission();

      Wire.beginTransmission(ADDRESS);
      Wire.write(0x01);
      Wire.write(0x20);
      Wire.endTransmission();

      
      Wire.beginTransmission(ADDRESS);
      Wire.write(0x02);
      Wire.write(0x00);
      Wire.endTransmission();
    }
    else
    {
      this->is=false;
    }

}

void Direction::aktualizuj()
{
  if(this->is)
  {
    Wire.beginTransmission(ADDRESS);
    Wire.write(0x03);
    Wire.endTransmission(false);

    Wire.requestFrom(ADDRESS, 6);

      if(Wire.available())
      {
          //Serial.println(Wire.read());
          
          int x,y,z;
          x = (Wire.read() | Wire.read()<<8);
          this->x = double(x)*0.92;
          y = (Wire.read() | Wire.read()<<8);
          this->y = double(y)*0.92;
          z = (Wire.read() | Wire.read()<<8);
          this->z = double(z)*0.92;
      }
    Wire.endTransmission();
  }
    
}


void Direction::wyswietl()
{
  if(this->is)
  {
    int MilliGauss_OnThe_XAxis = this->x;
  float heading = atan2(this->y, this->x);
  
  float declinationAngle = 0.0457;
  heading += declinationAngle;
  
  // Correct for when signs are reversed.
  if(heading < 0)
    heading += 2*PI;
    
  // Check for wrap due to addition of declination.
  if(heading > 2*PI)
    heading -= 2*PI;
   
  // Convert radians to degrees for readability.
  float headingDegrees = heading * 180/M_PI; 

    Serial.print("heading: ");
    Serial.println(heading);
    Serial.print("headingDegrees: ");
    Serial.println(headingDegrees);
    


    Serial.print("kierunek x: ");
    Serial.println(this->x);
    Serial.print("kierunek y: ");
    Serial.println(this->y);
    Serial.print("kierunek z: ");
    Serial.println(this->z);
    Serial.println();
    }
    else
    {
    Serial.println("nie podłączono czujnika");
    }
    
    
}