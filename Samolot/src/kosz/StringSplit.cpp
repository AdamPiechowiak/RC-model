#include "StringSplit.h"

int StringSplit::liczbaPodstringow(String dane,char delimter)
{
    int l = 0;
    for(int i =0;i<dane.length();i++)
    {
        if(dane[i]==delimter)
        {
            l++;
        }
    }
    return l+1;
}

void StringSplit::podzielString(String dane,char delimter, String tab[])
{
    int j=0;
    for(int i =0;i<dane.length();i++)
    {
        if(dane[i]==delimter)
        {
            //Serial.println(tab[j]);
            j++;
        }
        else
        {
            tab[j]=tab[j]+dane[i];
        }
    }
}
