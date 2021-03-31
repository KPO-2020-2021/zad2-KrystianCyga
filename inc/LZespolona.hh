#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH


#include <iostream>

/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */

};


std::ostream& operator << (std::ostream& struwyj,LZespolona skl);
std::istream& operator >> (std::istream& struwej,LZespolona &skl);

LZespolona operator /= (LZespolona Skl1, LZespolona Skl2);     //Dzielenie V2
LZespolona operator += (LZespolona Skl1, LZespolona Skl2);     //Dodawanie V2
double arg(LZespolona Skl1);                                   //wyswietlanie Argumentu

void wyswietl(LZespolona licz);
LZespolona wczytaj();
bool  operator == (LZespolona  Skl1,  LZespolona  Skl2);        //Porownanie
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);   //Dodawanie
LZespolona operator-(LZespolona Skl1, LZespolona Skl2);         // Odejmowanie
LZespolona operator*(LZespolona Skl1, LZespolona Skl2);         //Mnozenie
double operator ~ (LZespolona Skl1);                            //Modul liczby
LZespolona operator!(LZespolona Skl1);                          //Sprzezenie liczby
LZespolona operator/(LZespolona Skl1, LZespolona Skl2);         //Dzielenie       
LZespolona operator/ (LZespolona Skl1, double skalar);          //Dzielenie przez liczbe

#endif
