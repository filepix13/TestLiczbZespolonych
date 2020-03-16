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

/*WyrazenieZesp Utworz(WyrazenieZesp zesp)
{
    WyrazenieZesp w;
    w.Arg1 = zesp.Arg1
    w.Arg2 = zesp.Arg2;
    w.Op = o;
    
    return w;
}*/


/*
    Funkcja ta wczytuję liczbę zespoloną ze standardowego wejścia.
    Argumenty:
        Brak.
    Zwraca:
        Funkcja zwraca liczbę zespoloną. Ponadto sprawdza czy liczba wprowadzana w poprawny sposób.
        Jeżeli nie to zezwala na dwie ponowne próby.
 */
LZespolona Wczytaj()
{   
    LZespolona l;
    char znak;


    std::cout << "Twoja odpowiedź: ";
    std::cin >> znak >> l.re >> l.im >> znak >> znak;
    
    for(int i = 0; i < 2; i++)
    {   
        if(std::cin.fail())     //Sprawdzamy czy użytkownik poprawnie wprowadził zmienną
        {
            std::cin.clear();               //Czyścimy i ignorujemy bufor
            std::cin.ignore(1000,'\n');
            std::cerr << "Blad zapisu liczby zespolonej. Sprobuj jeszcze raz." << std::endl << std::endl;
            std::cout << "Twoja odpowiedź: ";
            std::cin >> znak >> l.re >> l.im >> znak >> znak;

            if(i==1)       //Czyścimy i ignorujemy bufor przy drugim podejciu 
            {
                std::cin.clear();
                std::cin.ignore(1000,'\n');
            }
        }
    }
    return l;
}


/*
    Funkcja ta wczytuję wyrażenie zespolone ze standardowego wejścia.
    Argumenty:
        Brak.
    Zwraca:
        Funkcja zwraca wyrażenie zespolone.
 */
WyrazenieZesp Wczytaj1()
{
    WyrazenieZesp w;
    char oper;

    w.Arg1 = Wczytaj();
    std::cin >> oper;
    w.Arg2 = Wczytaj();

    if(oper == '+')         //Sprawdzamy jaki jest operator w wyrażeniu
        w.Op = Op_Dodaj;
    if(oper == '-')
        w.Op = Op_Odejmij;
    if(oper == '*')
        w.Op = Op_Mnoz;
    if(oper == '/')
        w.Op = Op_Dziel;

    return w;
}


/*
    Funkcja ta wyświetla liczbę zespoloną na standardowe wyjście.
    Argumenty:
        l - liczba zespolona, którą będziemy wyświetlać.
    Zwraca:
        Brak.
 */
void Wyswietl(LZespolona l)
{
    std::cout << "(" << l.re << std::showpos << l.im << std::noshowpos << "i)" << std::endl;
}


/*
    Funkcja ta wyświetla wyrażenie zespolone na standardowe wyjście.
    Argumenty:
        WyrZ - wyrażenie zespolone, które będziemy wyświetlać.
    Zwraca:
        Brak.
 */
void Wyswietl(WyrazenieZesp  WyrZ)
{
    std::cout << "(" << WyrZ.Arg1.re << std::showpos << WyrZ.Arg1.im << std::noshowpos << "i) ";
    if(WyrZ.Op == 1)
        std::cout << "+";
    if(WyrZ.Op == 2)
        std::cout << "-";
    if(WyrZ.Op == 3)
        std::cout << "*";
    if(WyrZ.Op == 4)
        std::cout << "/";
    std::cout << " (" << WyrZ.Arg2.re << std::showpos << WyrZ.Arg2.im << std::noshowpos << "i)" << std::endl;
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
    if(WyrZ.Op == 1)
    {
        return WyrZ.Arg1 + WyrZ.Arg2;
    }
    else if(WyrZ.Op == 2)
    {
        return WyrZ.Arg1 - WyrZ.Arg2;
    }
    else if(WyrZ.Op == 3)
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
