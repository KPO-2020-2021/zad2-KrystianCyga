#include "Statystyki.hh"
#include <iostream>


/*
Definicje metod dla Statystyki 
*/
void statystyka::wyswietl (){
    std::cout << "Statystyka testu\n";
    std::cout << "Niepoprawne: "<<bad<< std::endl;
    std::cout << "Poprawne: "<<good<< std::endl;
}

void statystyka::addgood (){
    ++good;
}
void statystyka::addbad (){
    ++bad;
}
void statystyka::inicjalizuj (){
    good=0;
    bad=0;
}


