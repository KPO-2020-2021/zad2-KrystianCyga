#include "LZespolona.hh"
#include <cmath>
#include <iostream>

#define MIN_DIFF 0.00001

/*Funkcja przeciazenia operatora przesuniecia bitowego*/

std::ostream &operator<<(std::ostream &struwyj, LZespolona skl)
{
  struwyj << "(" << skl.re << std::showpos << skl.im << "i"
          << ")" << std::noshowpos;
  return struwyj;
}

std::istream &operator>>(std::istream struwej, LZespolona &skl)
{
  char naw, lit;
  struwej >> naw;
  if (struwej.fail())
    return struwej;
  if (naw != '(')
  {
    struwej.setstate(ios::failbit);
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
    struwej.setstate(ios::failbit);
    return struwej;
  }
  struwej >> naw;
  if (struwej.fail())
    return struwej;
  if (naw != ')')
  {
    struwej.setstate(ios::failbit);
    return struwej;
  }
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
  if (abs(Skl1.re - Skl2.re) <= MIN_DIFF && abs(Skl1.im - Skl2.im) <= MIN_DIFF)
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
    std::cout << "\nModul liczby Z_2 jest zerem!\nliczb nie mozna podzielić!\n";
    std::cout << "Liczba Z_2: ";
  }
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
  std::cin >> znak;
  std::cin >> znak;
  return licz;
}
