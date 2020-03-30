#include "WyrazenieZesp.hh"



/*
    Funkcja ta wczytuje wyrażenie zespolone ze strumienia wejściowego.
    Argumenty:
        StrWe - Strumień wejściowy,
        WyrZ - Wyrażenie zespolone.
    Zwraca:
        Funkcja zwraca strumień wejściowy.
 */
std::istream &operator >>(std::istream& StrmWe,WyrazenieZesp &WyrZ)
{
    char oper;

    std::cin >> WyrZ.Arg1;
    std::cin >> oper;
    std::cin >> WyrZ.Arg2;

    switch(oper)
    {
        case '+':
            WyrZ.Op = Op_Dodaj;
            break;
        case '-':
            WyrZ.Op = Op_Odejmij;
            break;
        case '*':
            WyrZ.Op = Op_Mnoz;
            break;
        case '/':
            WyrZ.Op = Op_Dziel;
            break;
        default:
            StrmWe.setstate(std::ios::failbit);
            break;
    }

    return StrmWe;
}


/*
    Funkcja ta wyświetla wyrażenie zespolone na strumień wyjściowy.
    Argumenty:
        StrWy - Strumień wyjściowy,
        WyrZ - wyrażenie zepolone.
    Zwraca:
        Funkcja zwraca strumień wyjściowy.
 */
std::ostream &operator <<(std::ostream &StrWy, WyrazenieZesp &WyrZ)
{   
    StrWy << "(" << WyrZ.Arg1.re << std::showpos << WyrZ.Arg1.im << std::noshowpos << "i) ";

    switch(WyrZ.Op)
    {
        case Op_Dodaj:
            StrWy << '+';
            break;
        case Op_Odejmij:
            StrWy << '-';
            break;
        case Op_Mnoz:
            StrWy << '*';
            break;
        case Op_Dziel:
            StrWy << '/';
            break;
    }

    StrWy << " (" << WyrZ.Arg2.re << std::showpos << WyrZ.Arg2.im << std::noshowpos << "i)" << std::endl;    

    return StrWy;
}


/*
    Funkcja ta oblicza wyrażenie zespolone.
    Argumenty:
        WyrZ - Wyrażenie zepolone, które będziemy obliczać
    Zwraca:
        Funkcja zwraca liczbę zespoloną.
 */
LZespolona Oblicz(WyrazenieZesp  WyrZ)
{
    if(WyrZ.Op == 0)
    {
        return WyrZ.Arg1 + WyrZ.Arg2;
    }
    else if(WyrZ.Op == 1)
    {
        return WyrZ.Arg1 - WyrZ.Arg2;
    }
    else if(WyrZ.Op == 2)
    {
        return WyrZ.Arg1 * WyrZ.Arg2;
    }
    else
    {
        return WyrZ.Arg1 / WyrZ.Arg2;
    }
}
