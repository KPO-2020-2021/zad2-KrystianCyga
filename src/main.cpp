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

  // Zmienne pomocnicze do głównej pętli 
  WyrazenieZesp WyrZ_PytanieTestowe; 
  LZespolona pier,dobra;
  statystyka staty;
  

  staty.inicjalizuj();

  // Glowna petla programu pobierajaca pytania z bazy
  while (PobierzNastpnePytanie(&BazaT, &WyrZ_PytanieTestowe))
  {
    std::cout << "Podaj wynik operacji:";
    std::cout << WyrZ_PytanieTestowe << endl;   //Wyswietlanie pytania testowego
    std::cin >> pier;                           //Proces pobierania odpowiedzi
    while (std::cin.fail())                     //Zabezpieczenie strumienia danych
    {
      std::cin.clear();
      std::cin.ignore(10000, '\n');
      cerr << "Zly format liczby zespolonej. Podaj inna liczbe:" << endl;
      std::cin >> pier;
    }

    dobra = (WyrZ_PytanieTestowe.oblicz(WyrZ_PytanieTestowe));   // Obliczanie poprawnej odpowiedzi
    if (dobra==pier)                           // Sprawdzenie poprawnosci odpowiedzi
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

  staty.wyswietl();       //Wyswietlenie statystyk koncowych 
}

