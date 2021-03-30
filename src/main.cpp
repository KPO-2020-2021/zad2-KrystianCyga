#include <iostream>
#include "BazaTestu.hh"
#include "Statystyki.hh"
#include "LZespolona.hh"

using namespace std;




int main(int argc, char **argv)
{
  /*
  statystyka staty,staty1;

  staty.inicjalizuj();
  staty.addgood();
  staty.addbad();
  staty.wyswietl();

  staty1.inicjalizuj();
  staty1.addgood();
  staty1.addbad();
  staty1.wyswietl();
  */


  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }


  
  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  WyrazenieZesp   WyrZ_PytanieTestowe;
  LZespolona pier, drug;
  statystyka staty;
  double a ,b;

  staty.inicjalizuj();
  
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    cout << " Czesc rzeczywista pierwszego argumentu: ";
    cout << WyrZ_PytanieTestowe.Arg1.re << endl;
    cin >> pier;
  }

  
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;

}
