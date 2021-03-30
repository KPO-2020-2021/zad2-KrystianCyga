#include <iostream>
#include "BazaTestu.hh"
#include "Statystyki.hh"


using namespace std;

int main(int argc, char **argv)
{
  if (argc < 2)
  {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }

  BazaTestu BazaT = {nullptr, 0, 0};

  if (InicjalizujTest(&BazaT, argv[1]) == false)
  {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }

  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  WyrazenieZesp WyrZ_PytanieTestowe;
  LZespolona pier, drug;
  statystyka staty;
  double a, b;

  staty.inicjalizuj();

  while (PobierzNastpnePytanie(&BazaT, &WyrZ_PytanieTestowe))
  {
    cout << "Podaj wynik operacji:";
    cout << WyrZ_PytanieTestowe << endl;
    cin >> pier;
    while (cin.fail())
    {
      std::cin.clear();
      std::cin.ignore(10000, '\n');
      cerr << "Zly format liczby zespolonej. Podaj inna liczbe:" << endl;
      std::cin >> pier;
    }
    a = pier.im; // wprowadzenie czesci rzeczywistej i urojonej liczby od uzytkownika pod zmienne pomocnicze w celu dalszego porownania
    b = pier.re;
    pier = Oblicz(WyrZ_PytanieTestowe); // obliczanie prawdilowego wyniku
    if (pier.re == a && pier.im == b)   // jesli porownanie liczb sie zgadza to odpowiedz dobra
    {
      std::cout << "Odpowiedz poprawna :)" << endl
                << endl;
      ++staty.git; // zliczanie dobrych odpowiedzi
    }
    else // gdy porownanie zle, odpowiedz niepoprawna
    {
      std::cout << "Zla odpowiedz" << endl
                << "Poprawny wynik to: " << pier << endl
                << endl;
      ++staty.bad; // zliczanie zlych odpowiedzi
    }
  }
}

