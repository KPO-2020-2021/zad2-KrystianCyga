#include "LZespolona.hh"
#include <cmath>
#include <stdexcept>
#include <cstdlib>
#include <climits>

#define MIN_DIFF 0.00001

/*Funkcja przeciazenia operatora przesuniecia bitowego*/

std::ostream &operator<<(std::ostream &struwyj, LZespolona skl)
{
  struwyj << "(" << skl.re << std::showpos << skl.im << "i"
          << ")" << std::noshowpos;
  return struwyj;
}

std::istream &operator>>(std::istream &struwej, LZespolona &skl)
{
  char naw, lit;
  struwej >> naw;
  if (struwej.fail())
    return struwej;
  if (naw != '(')
  {
    struwej.setstate(std::ios::failbit);
    return struwej;
  }
  struwej >> skl.re;
  if (struwej.fail())
    return struwej;
  struwej >> skl.im;
  if (struwej.fail())
    return struwej;
  struwej >> lit;
  if (struwej.fail())
    return struwej;
  if (lit != 'i')
  {
    struwej.setstate(std::ios::failbit);
    return struwej;
  }
  struwej >> naw;
  if (struwej.fail())
    return struwej;
  if (naw != ')')
  {
    struwej.setstate(std::ios::failbit);
    return struwej;
  }
  return struwej;
}

/*!
 * Realizuje porównanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwsza porównywana liczba zespolona,
 *    Skl2 - druga porównywana liczba zespolona.
 * Zwraca:
 *    True dla równych liczb zespolonych.
 */

bool LZespolona::operator==(LZespolona const &Skl2)
{
  if ((fabs(re - Skl2.re)<= MIN_DIFF) && (fabs(im - Skl2.im) <= MIN_DIFF))
    return true;
  else
    return false;
}

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona LZespolona::operator+(LZespolona const &Skl2)
{
  LZespolona Wynik;

  Wynik.re = re + Skl2.re;
  Wynik.im = im + Skl2.im;
  return Wynik;
}

LZespolona LZespolona::operator+=(LZespolona const &Skl2)
{
  re += Skl2.re;
  im += Skl2.im;
  return (*this);
}

/*!
 * Realizuje odejmowanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik odejmowania,
 *    Skl2 - drugi skladnik odejmowania.
 * Zwraca:
 *    Roznice dwoch skladnikow przekazanych jako parametry.
 */
LZespolona LZespolona::operator-(LZespolona const &Skl2)
{
  LZespolona Wynik;

  Wynik.re = re - Skl2.re;
  Wynik.im = im - Skl2.im;
  return Wynik;
}

/*!
 * Realizuje mnożenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik mnozenia,
 *    Skl2 - drugi skladnik mnozenia.
 * Zwraca:
 *    Iloczyn dwoch skladnikow przekazanych jako parametry.
 */
LZespolona LZespolona::operator*(LZespolona const &Skl2)
{
  LZespolona Wynik;

  Wynik.re = (re * Skl2.re - im * Skl2.im);
  Wynik.im = (im * Skl2.re + re * Skl2.im);
  return Wynik;
}

/*!
 * Realizuje obliczenie modulu liczby.
 * Argumenty:
 *    Skl1 - liczba zespolona,
 * Zwraca:
 *    Modul liczby w postaci double
 */

double LZespolona::operator~()
{
  return sqrt(re * re + im * im);
}

/*!
 * Realizuje sprzezenie liczby.
 * Argumenty:
 *    Skl1 - liczba zespolona,
 * Zwraca:
 *    Sprzezenie liczby w postaci dwoch skladnikow przekazanych jako parametry.
 */
LZespolona LZespolona::operator!()
{
  LZespolona Wynik;

  Wynik.re = re;
  Wynik.im = -im;
  return Wynik;
}

/*!
 * Realizuje dzielenie liczby zespolonej przez druga liczbe zespolona.
 * Argumenty:
 *    Skl1 - dzielona liczba zespolona,
 *    Skl2 - liczba zespolona przez ktora dzielimy.
 * Zwraca:
 *    Wynik dzielenia dwoch skladnikow przekazanych jako parametry.
 */
LZespolona LZespolona::operator/(LZespolona const &Skl2)
{

  LZespolona beka=Skl2,Wynik;
  double modul = (~beka);

  if (modul)
  {
    Wynik.re = (re * Skl2.re + im * Skl2.im) / modul;
    Wynik.im = (-re * Skl2.im + im * Skl2.re) / modul;
  }
  else
  {
    throw "Error";
  }
  return (Wynik);
}

LZespolona LZespolona::operator/=(LZespolona const &Skl2)
{
  LZespolona beka=Skl2;
  double modul = (~beka);

  if (modul)
  {
    re = (re * Skl2.re + im * Skl2.im) / modul;
    re = (-re * Skl2.im + im * Skl2.re) / modul;
  }
  else
  {
    throw "Error";
  }
  return (*this);
}

/*!
 * Realizuje dzielenie liczby zespolonej skalar.
 * Argumenty:
 *    Skl1 - dzielona liczba zespolona,
 *    skalar - liczba typui double.
 * Zwraca:
 *    Wynik dzielenia dwoch skladnikow przekazanych jako parametry.
 */

LZespolona LZespolona::operator/(double skalar)
{

  LZespolona Wynik;
  if (skalar)
  {
    Wynik.re = re / skalar;
    Wynik.im = im / skalar;

    return Wynik;
  }
  else
  {
    throw "Error";
  }
  return (*this);
}

/*funkcja wyswietlajaca liczbe*/

void LZespolona::wyswietl()
{
  std::cout << "(" << re << std::showpos << im << "i"
            << ")" << std::noshowpos;
}

/* funkcja wczytujaca liczbe*/
LZespolona wczytaj()
{
  LZespolona licz;
  char znak;
  std::cin >> znak;
  std::cin >> licz.re;
  std::cin >> znak;
  std::cin >> licz.im;
  if (znak == '-')
    licz.im = licz.im * (-1);
  std::cin >> znak;
  std::cin >> znak;
  return licz;
}

double LZespolona::argument()
{
  double arg;
  if (im > 0 && re == 0)
  {
    arg = M_PI / 2;
  }
  else if (im < 0 && re == 0)
  {
    arg = -M_PI / 2;
  }
  else if (im != 0 && re > 0)
  {
    arg=atan2(im,re);
  }
  else if (im != 0 && re < 0)
  {
    arg=(atan2(im,re)+M_PI);
  }
  else if (im == 0 && re < 0)
  {
    arg=M_PI;
  }
  else if (im == 0 && re > 0)
  {
    arg=0;
  }
  return arg;
}
