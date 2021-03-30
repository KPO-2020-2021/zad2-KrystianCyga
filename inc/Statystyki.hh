#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH

#include "LZespolona.hh"
#include "WyrazenieZesp.hh"

struct statystyka
{
    int good;
    int bad;
};

void wyswietl(statystyka &);
void addgood(statystyka &);
void addbad(statystyka &);
void inicjalizuj(statystyka &);

#endif
