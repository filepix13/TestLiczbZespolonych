#include "Statystyka.hh"


/*
    Funkcja ta inicjuje statystykę.
    Argumenty:
        Brak.
    Zwraca:
        Funkcja zwraca wyzerowaną statystykę.
 */
Statystyka Utworz()
{
    Statystyka stat;

    stat.liczBld = 0;
    stat.liczPop = 0;

    return stat;
}


/*
    Funkcja dodaje błędną odpowiedź do statystyki.
    Argumenty:
        stat - statystyka.
    Zwraca:
        Funkcja zwraca statystykę z zwiększoną ilością odpowiedzi błędnych.
 */
void dodajBld(Statystyka& stat)
{
    stat.liczBld++;
}


/*
    Funkcja dodaje poprawną odpowiedź do statystyki.
    Argumenty:
        stat - statystyka.
    Zwraca:
        Funkcja zwraca statystykę z zwiększoną ilością odpowiedzi poprawnych.
 */
void dodajPop(Statystyka& stat)
{
    stat.liczPop++;
}


/*
    Funkcja oblicza procentową ilość poprawnych odpowiedzi w statystyce.
    Argumenty:
        stat - statystyka.
    Zwraca:
        Funkcja zwraca procentową ilość poprawnych odpowiedzi w statystyce.
 */
double procent(Statystyka stat)
{
    double show;
    
    show = ((double)stat.liczPop/(stat.liczPop+stat.liczBld))*100;

    return show;
}