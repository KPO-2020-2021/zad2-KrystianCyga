#include "Statystyki.hh"
#include <iostream>

void wyswietl (statystyka& staty){
    std::cout << "Statystyka testu\n";
    std::cout << "Niepoprawne: "<<staty.bad<< std::endl;
    std::cout << "Poprawne: "<<staty.good<< std::endl;
}

void addgood (statystyka& staty){
    ++staty.good;
}
void addbad (statystyka& staty){
    ++staty.bad;
}
void inicjalizuj (statystyka& staty){
    staty.good=0;
    staty.bad=0;
}


