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

bool operator==(LZespolona Skl1, LZespolona Skl2)
{
  if (((sqrt((Skl1.re - Skl2.re) * (Skl1.re - Skl2.re)) <= MIN_DIFF) && ((sqrt((Skl1.im - Skl2.im) * (Skl1.im - Skl2.im)) <= MIN_DIFF))))
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
LZespolona operator+(LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}

LZespolona operator+=(LZespolona Skl1, LZespolona Skl2)
{
  Skl1.re += Skl2.re;
  Skl1.im += Skl2.im;
  return Skl1;
}

/*!
 * Realizuje odejmowanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik odejmowania,
 *    Skl2 - drugi skladnik odejmowania.
 * Zwraca:
 *    Roznice dwoch skladnikow przekazanych jako parametry.
 */
LZespolona operator-(LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
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
LZespolona operator*(LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik.re = (Skl1.re * Skl2.re - Skl1.im * Skl2.im);
  Wynik.im = (Skl1.im * Skl2.re + Skl1.re * Skl2.im);
  return Wynik;
}

/*!
 * Realizuje obliczenie modulu liczby.
 * Argumenty:
 *    Skl1 - liczba zespolona,
 * Zwraca:
 *    Modul liczby w postaci double
 */

double operator~(LZespolona Skl1)
{
  double Wynik;
  Wynik = sqrt(Skl1.re * Skl1.re + Skl1.im * Skl1.im);
  return Wynik;
}

/*!
 * Realizuje sprzezenie liczby.
 * Argumenty:
 *    Skl1 - liczba zespolona,
 * Zwraca:
 *    Sprzezenie liczby w postaci dwoch skladnikow przekazanych jako parametry.
 */
LZespolona operator!(LZespolona Skl1)
{
  LZespolona Wynik;

  Wynik.re = Skl1.re;
  Wynik.im = -Skl1.im;
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
LZespolona operator/(LZespolona Skl1, LZespolona Skl2)
{

  LZespolona Wynik;
  double modul = (~Skl2);

  if (modul)
  {
    Wynik.re = (Skl1.re * Skl2.re + Skl1.im * Skl2.im) / modul;
    Wynik.im = (-Skl1.re * Skl2.im + Skl1.im * Skl2.re) / modul;

    return Wynik;
  }
  else
  {
    throw "Error";
  }
  return Skl1;
}

LZespolona operator/=(LZespolona Skl1, LZespolona Skl2)
{
  double modul = (~Skl2);

  if (modul)
  {
    Skl1.re = (Skl1.re * Skl2.re + Skl1.im * Skl2.im) / modul;
    Skl1.re = (-Skl1.re * Skl2.im + Skl1.im * Skl2.re) / modul;
  }
  else
  {
    throw "Error";
  }
  return Skl1;
}

/*!
 * Realizuje dzielenie liczby zespolonej skalar.
 * Argumenty:
 *    Skl1 - dzielona liczba zespolona,
 *    skalar - liczba typui double.
 * Zwraca:
 *    Wynik dzielenia dwoch skladnikow przekazanych jako parametry.
 */

LZespolona operator/(LZespolona Skl1, double skalar)
{

  LZespolona Wynik;
  if (skalar)
  {
    Wynik.re = Skl1.re / skalar;
    Wynik.im = Skl1.im / skalar;

    return Wynik;
  }
  else
  {
    throw "Error";
  }
  return Skl1;
}

/*funkcja wyswietlajaca liczbe*/

void wyswietl(LZespolona licz)
{
  std::cout << "(" << licz.re << std::showpos << licz.im << "i"
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

double argument(LZespolona Skl1)
{
  double arg;
  if (Skl1.im == 0 && Skl1.re != 0)
  {
    arg = 0;
  }
  else if (Skl1.im > 0 && Skl1.re == 0)
  {
    arg = M_PI / 2;
  }
  else if (Skl1.im < 0 && Skl1.re == 0)
  {
    arg = -M_PI / 2;
  }
  else if (Skl1.im != 0 && Skl1.re > 0)
  {
    arg=atan2(Skl1.im,Skl1.re);
  }
  else if (Skl1.im != 0 && Skl1.re < 0)
  {
    arg=(atan2(Skl1.im,Skl1.re)+M_PI);
  }
  return arg;
}
