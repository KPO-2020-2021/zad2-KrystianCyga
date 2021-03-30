#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH

#include "LZespolona.hh"

/*!
 * Modeluje zbior operatorow arytmetycznych.
 */
enum Operator
{
  Op_Dodaj,
  Op_Odejmij,
  Op_Mnoz,
  Op_Dziel
};

/*
 * Modeluje pojecie dwuargumentowego wyrazenia zespolonego
 */
struct WyrazenieZesp
{
  LZespolona Arg1; // Pierwszy argument wyrazenia arytmetycznego
  Operator Op;     // Opertor wyrazenia arytmetycznego
  LZespolona Arg2; // Drugi argument wyrazenia arytmetycznego

  Operator wczytajoper(char znak);
  Operator wczytajoper();
  char dajsymbol(Operator oper);
  LZespolona oblicz(WyrazenieZesp wyr1);
  void wyswietloper(Operator oper);
  void wyswietlwyraz(WyrazenieZesp wyr1);
  WyrazenieZesp wczytajwyrazenie();
};

std::ostream &operator<<(std::ostream &struwyj, WyrazenieZesp wyr1);
std::istream &operator>>(std::istream &struwej, WyrazenieZesp &wyr1);

#endif
