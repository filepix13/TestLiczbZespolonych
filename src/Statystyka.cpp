#include "Statystyka.hh"
#include <iostream>

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


/*
    Funkcja wyświtla statystykę
    Argumenty:
        stat - statystyka.
    Zwraca:
        brak.
 */
void Wyswietl(Statystyka stat)
{
    double show = 0;

    std::cout << "Ilość dobrych odpowiedzi: " << stat.liczPop << std::endl;
    std::cout << "Ilość błędnych odpowiedzi: " << stat.liczBld << std::endl;
    std::cout << "Wynik procentowy poprawnych odpowiedzi: ";
    show = procent(stat);
    std::cout << show << "%" << std::endl;
}