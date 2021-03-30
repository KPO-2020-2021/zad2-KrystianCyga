#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH

#include "LZespolona.hh"
#include "WyrazenieZesp.hh"


struct statystyka
{
    int good;
    int bad;
    
    void wyswietl();
    void addgood();
    void addbad();
    void inicjalizuj();
};



#endif
