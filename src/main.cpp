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
  LZespolona pier;
  statystyka staty;
  double a, b;

  staty.inicjalizuj();

  while (PobierzNastpnePytanie(&BazaT, &WyrZ_PytanieTestowe))
  {
    std::cout << "Podaj wynik operacji:";
    std::cout << WyrZ_PytanieTestowe << endl;
    std::cin >> pier;
    while (std::cin.fail())
    {
      std::cin.clear();
      std::cin.ignore(10000, '\n');
      cerr << "Zly format liczby zespolonej. Podaj inna liczbe:" << endl;
      std::cin >> pier;
    }
    a = pier.im;
    b = pier.re;
    pier = (WyrZ_PytanieTestowe.oblicz(WyrZ_PytanieTestowe));
    if (pier.re == a && pier.im == b) 
    {
      std::cout << "Odpowiedz poprawna" << endl
                << endl;
      ++staty.good; 
    }
    else 
    {
      std::cout << "Zla odpowiedz" << endl
                << "Poprawny wynik to: " << pier << endl
                << endl;
      ++staty.bad;
    }
  }
  std::cout<<"Koniec Testu\n";

  staty.wyswietl();
}

