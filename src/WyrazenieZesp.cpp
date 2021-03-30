#include "WyrazenieZesp.hh"

Operator wczytajoper(char znak)
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

char dajsymbol(Operator oper)
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

LZespolona oblicz(WyrazenieZesp wyr1)
{
    LZespolona pier;
    switch (wyr1.Op)
    {
    case Op_Dodaj:
        return operator+(wyr1.Arg1, wyr1.Arg2);
        break;
    case Op_Odejmij:
        return operator-(wyr1.Arg1, wyr1.Arg2);
        break;
    case Op_Dziel:
        return operator/(wyr1.Arg1, wyr1.Arg2);
        break;
    case Op_Mnoz:
        return operator*(wyr1.Arg1, wyr1.Arg2);
        break;
    }
    return pier;
}

void wyswietloper(Operator oper)
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

void wyswietlwyraz(WyrazenieZesp wyr1)
{
    wyswietl(wyr1.Arg1);
    wyswietloper(wyr1.Op);
    wyswietl(wyr1.Arg2);
    std::cout << "\n";
}

WyrazenieZesp wczytajwyrazenie()
{
    LZespolona pier,drug;
    WyrazenieZesp wyr1;
    pier=wczytaj();
    Operator oper = wczytajoper();
    drug=wczytaj();
    wyr1.Arg1=pier;
    wyr1.Op=oper;
    wyr1.Arg2=drug;
    return wyr1;

}