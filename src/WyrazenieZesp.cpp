#include "WyrazenieZesp.hh"

std::ostream &operator<<(std::ostream &struwyj, WyrazenieZesp wyr1)
{
    struwyj<< wyr1.Arg1 << wyr1.dajsymbol(wyr1.Op) << wyr1.Arg2;
    return struwyj;
}

std::istream &operator>>(std::istream &struwej, WyrazenieZesp &wyr1)
{
    char znak, ilit;
    struwej >> wyr1.Arg1;
    struwej >> znak;
    wyr1.Op = (wyr1.wczytajoper(znak));
    struwej >> wyr1.Arg2;
    return struwej;
}

Operator WyrazenieZesp::wczytajoper(char znak)
{
    Operator oper;
    switch (znak)
    {
    case '-':
        oper = Op_Odejmij;
        break;
    case '+':
        oper = Op_Dodaj;
        break;
    case '*':
        oper = Op_Mnoz;
        break;
    case '/':
        oper = Op_Dziel;
        break;
    }
    return oper;
}
Operator WyrazenieZesp::wczytajoper()
{
    Operator oper;
    char symbol;
    std::cin>> symbol;
    switch (symbol)
    {
    case '-':
        oper = Op_Odejmij;
        break;
    case '+':
        oper = Op_Dodaj;
        break;
    case '*':
        oper = Op_Mnoz;
        break;
    case '/':
        oper = Op_Dziel;
        break;
    }
    return oper;
}

char WyrazenieZesp::dajsymbol(Operator oper)
{
    char znak;
    switch (oper)
    {
    case Op_Mnoz:
        znak = '*';
        break;
    case Op_Dziel:
        znak = '/';
        break;

    case Op_Dodaj:
        znak = '+';
        break;
    case Op_Odejmij:
        znak = '-';
        break;
    }
    return znak;
}

LZespolona WyrazenieZesp::oblicz(WyrazenieZesp wyr1)
{
    LZespolona pier;
    switch (Op)
    {
    case Op_Dodaj:
        return operator+(Arg1, Arg2);
        break;
    case Op_Odejmij:
        return operator-(Arg1, Arg2);
        break;
    case Op_Dziel:
        return operator/(Arg1, Arg2);
        break;
    case Op_Mnoz:
        return operator*(Arg1, Arg2);
        break;
    }
    return pier;
}
void WyrazenieZesp::wyswietloper(Operator oper)
{
    switch (oper)
    {
    case Op_Dodaj:
        std::cout << "+";
        break;
    case Op_Odejmij:
        std::cout << "-";
        break;
    case Op_Dziel:
        std::cout << "/";
        break;
    case Op_Mnoz:
        std::cout << "*";
        break;
    }
}

void WyrazenieZesp::wyswietlwyraz(WyrazenieZesp wyr1)
{
    wyswietl(Arg1);
    wyswietloper(Op);
    wyswietl(Arg2);
    std::cout << "\n";
}

WyrazenieZesp WyrazenieZesp::wczytajwyrazenie()
{
    LZespolona pier, drug;
    WyrazenieZesp wyr1;
    pier = wczytaj();
    Operator oper = WyrazenieZesp::wczytajoper();
    drug = wczytaj();
    Arg1 = pier;
    Op = oper;
    Arg2 = drug;
    return wyr1;
}