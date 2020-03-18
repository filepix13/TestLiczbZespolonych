#include "WyrazenieZesp.hh"


/*
    Funkcja ta tworzy liczbę zespoloną z dwóch liczb typu double.
    Argumenty:
        re - część rzeczywista liczby zespolonej,
        im - część urojona liczby zespolonej,
    Zwraca:
        Funkcja zwraca liczbę zespoloną.
 */
LZespolona Utworz(double re, double im)
{
    LZespolona l;

    l.re = re;
    l.im = im;

    return l;
}

/*
    Funkcja ta wczytuje liczbę zespoloną oraz obsługuje błędny zapis.
    Argumenty:
        b - wczytywana liczba zespolona.
    Zwraca:
        Brak.
*/
void Wczytaj(LZespolona &b)
{
    for(int i=0; ; i++)
    {
      std::cin >> b;

      if(std::cin.fail() && i==3)
      {
        std::cin.clear( );
        std::cin.ignore(1000,'\n');
        break;
      }

      else if(std::cin.fail())
      {
        std::cerr << "Blad formatu liczby zespolonej. Spróbuj jeszcze raz." << std::endl << std::endl;
        std::cout << "Twoja odpowiedź: ";
        std::cin.clear( );
        std::cin.ignore(1000,'\n');
        continue;
      }
      break;

    }
}

/*WyrazenieZesp Utworz(WyrazenieZesp zesp)
{
    WyrazenieZesp w;
    w.Arg1 = zesp.Arg1
    w.Arg2 = zesp.Arg2;
    w.Op = o;
    
    return w;
}*/


/*
    Funkcja ta wczytuje liczbę zespoloną ze strumienia wejściowego.
    Argumenty:
        StrWe - Strumień wejściowy,
        Lz - liczba zespolona.
    Zwraca:
        Funkcja zwraca strumień wejściowy.
 */
std::istream &operator >>(std::istream& StrmWe,LZespolona& Lz)
{
    char znak;

    StrmWe >> znak;
    if(znak!='(')
        StrmWe.setstate(std::ios::failbit);

    StrmWe >> Lz.re;
    StrmWe >> Lz.im;
    
    StrmWe >> znak;
    if(znak!='i')
        StrmWe.setstate(std::ios::failbit);
    StrmWe >> znak;
    if(znak!=')')
        StrmWe.setstate(std::ios::failbit);

    return StrmWe;
} 

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
    Funkcja ta wyświetla liczbę zespoloną na strumień wyjściowy.
    Argumenty:
        StrWy - Strumień wyjściowy,
        Lz - liczba zespolona.
    Zwraca:
        Funkcja zwraca strumień wyjściowy.
 */
std::ostream &operator <<(std::ostream& StrmWy,LZespolona &Lz)
{
    return StrmWy << '(' <<Lz.re << std::showpos << Lz.im << std::noshowpos << "i)";
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


/*
    Funkcja ta porównuje dwie liczby zespolone.
    Argumenty:
        a - pierwsza liczba zespolona, którą będziemy porównywać,
        b - druga liczba zespolona, którą będziemy porównywać.
    Zwraca:
        Zwraca prawdę lub fałsz.
*/
bool Porownaj(LZespolona a, LZespolona b)
{
    if(a.re == b.re && a.im == b.im)
    {
        return true;
    }
    else
    {
        return false;
    }
    

}
