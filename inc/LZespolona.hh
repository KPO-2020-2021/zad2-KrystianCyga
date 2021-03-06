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

double operator ~ ();                    //Modul liczby
LZespolona operator += (LZespolona const &Skl2);     //Dodawanie V2
LZespolona operator /= (LZespolona const &Skl2);     //Dzielenie V2
void wyswietl();
double argument();                                   //wyswietlanie Argumentu
LZespolona operator/ (double skalar);    //Dzielenie przez liczbe
LZespolona operator/(LZespolona const &Skl2);         //Dzielenie  
LZespolona operator!();                          //Sprzezenie liczby
LZespolona wczytaj();
bool  operator == (LZespolona const &Skl2);        //Porownanie
LZespolona operator + (LZespolona const &Skl2);   //Dodawanie
LZespolona operator-(LZespolona const &Skl2);         // Odejmowanie
LZespolona operator*(LZespolona const &Skl2);         //Mnozenie

};


std::ostream& operator << (std::ostream& struwyj,LZespolona skl);
std::istream& operator >> (std::istream& struwej,LZespolona &skl);









     


#endif
