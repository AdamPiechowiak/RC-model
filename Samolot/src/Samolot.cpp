#include "Samolot.h"



Samolot* Samolot::s = nullptr;

Samolot::Samolot()
{
    this->moc = 0;
    this->sterKierunku = 50;
    this->sterWysoosci = 50;
    this->lotki =50;
    this->silnikON = false;

    
    this->silnik = Serwo(10,60,110);
    this->silnik.attach(PINSILNIK); 
    this->silnik.write(0); 

    this->sSterW = Serwo(10,87,180);//0 gora 180 dol
    this->sSterW.attach(PINSTERW); 
    this->sSterW.write(this->sSterW.center);

    this->sSterK = Serwo(15,93,180);//0 lewo 180 prawo
    this->sSterK.attach(PINSTERK); 
    this->sSterK.write(this->sSterK.center);

    this->sLotkaL = Serwo(55,92,125);//0 DOL 180 GORA
    this->sLotkaL.attach(PINLOTKAL); 
    this->sLotkaL.write(this->sLotkaL.center);

    this->sLotkaP = Serwo(45,78,115);//0 gora 180 dol
    this->sLotkaP.attach(PINLOTKAP); 
    this->sLotkaP.write(this->sLotkaP.center);
}

Samolot *Samolot::GetInstance()
{
    if(s==nullptr)
    {
        s = new Samolot();
    } 

    return s;
}

void Samolot::pokarzDane()
{
    Serial.print("moc: ");
    Serial.println(this->moc);
    Serial.print("ster kierunku: ");
    Serial.println(this->sterKierunku);
    Serial.print("ster wysokości: ");
    Serial.println(this->sterWysoosci);
    Serial.print("lotki: ");
    Serial.println(this->lotki);
    Serial.print("silnik ON/OFF: ");
    if(this->silnikON)
    {
        Serial.println("Y");
    }
    else
    {
        Serial.println("N");
    }
    
    this->position.wyswietl();
    this->rotation.wyswietl();
    this->direction.wyswietl();

   
}

void Samolot::wlaczSilnik()
{
    if(!this->silnikON)
    {
        this->silnikON = true;
        this->silnik.write(0); 
        delay(1000);
        this->silnik.write(this->silnik.max); 
        delay(3000);
        this->silnik.write(this->silnik.min); 
        delay(1000);
        Serial.println("silnik start");
    }
}

void Samolot::wylaczSilnik()
{
    if(this->silnikON)
    {
        this->silnik.write(0); 
        Serial.println("silnik stop");
    }
}

void Samolot::pobierzDane()
{
    //this->direction.aktualizuj();
    //this->position.aktualizuj();
    //this->rotation.aktualizuj();


    if(this->silnikON)
    {
        if(0<=this->moc && 100>=this->moc)
        {
            this->silnik.write(this->silnik.min+this->moc); 
            //Serial.println(this->silnik.min+this->moc);
        }

    }
   
    if(0<=this->sterKierunku && 100>=this->sterKierunku)
    {
        if(this->sterKierunku>50)
        {
            float p = sSterK.max-sSterK.center;
            float r = this->sterKierunku-50;
            int w = int(sSterK.center+(p/50*r));
            this->sSterK.write(w);
            //Serial.println(w);

        }
        else if(this->sterKierunku<50)
        {
            float p = sSterK.center-sSterK.min;
            float r = this->sterKierunku;
            int w = int(sSterK.min+p/50*r);
            this->sSterK.write(w);
            //Serial.println(w);
        }
        else
        {
            this->sSterK.write(this->sSterK.center);
            //Serial.println(this->sSterK.center);
        }

    }

    if(0<=this->sterWysoosci && 100>=this->sterWysoosci)
    {
        if(this->sterWysoosci>50)
        {
            float p = sSterW.max-sSterW.center;
            float r = this->sterWysoosci-50;
            int w = int(sSterW.center+(p/50*r));
            this->sSterW.write(w);
            //Serial.println(w);

        }
        else if(this->sterWysoosci<50)
        {
            float p = sSterW.center-sSterW.min;
            float r = this->sterWysoosci;
            int w = int(sSterW.min+p/50*r);
            this->sSterW.write(w);
            //Serial.println(w);
        }
        else
        {
            this->sSterW.write(this->sSterW.center);
            //Serial.println(this->sSterW.center);
        }
    }

    if(0<=this->lotki && 100>=this->lotki)
    {
        if(this->lotki>50)
        {

            float r = this->lotki-50;

            float pl = sLotkaL.max-sLotkaL.center;
            int wl = int(sLotkaL.center+(pl/50*r));
            this->sLotkaL.write(wl);
            //Serial.println(wl);

            float pp = sLotkaP.max-sLotkaP.center;
            int wp = int(sLotkaP.center+(pp/50*r));
            this->sLotkaP.write(wp);
            //Serial.println(wp);
        }
        else if(this->lotki<50)
        {
            float r = this->lotki;

            float pl = sLotkaL.center-sLotkaL.min;
            int wl = int(sLotkaL.min+pl/50*r);
            this->sLotkaL.write(wl);
            //Serial.println(wl);

            
            float pp = sLotkaP.center-sLotkaP.min;
            int wp = int(sLotkaP.min+pp/50*r);
            this->sLotkaP.write(wp);
            //Serial.println(wp);
        }
        else
        {
            this->sLotkaL.write(this->sLotkaL.center);
            this->sLotkaP.write(this->sLotkaP.center);
            //Serial.println(this->sLotkaL.center);
            //Serial.println(this->sLotkaP.center);
        }
    }

    //Serial.println();
}