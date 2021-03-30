#ifndef STATYSTYKI_HH
#define STATYSTYKI_HH
#include <iostream>

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
