#ifndef STATYSTYKI_HH
#define STATYSTYKI_HH
#include <iostream>

struct statystyka
{
    int good;
    int bad;

     // Metody struktury statystyka:
    void wyswietl();        // Wyświetlenie            
    void addgood();         //Dodanie dobrej odpowiedzi
    void addbad();          //Dodanie zlej odpowiedzi
    void inicjalizuj();     // Wyzerowanie 
};



#endif
