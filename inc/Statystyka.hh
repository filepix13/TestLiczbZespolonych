#pragma once


/*
 * Modeluje wygląd statystyki.
 */
struct Statystyka
{
    int liczBld;        //Liczba błędnych odpowiedzi.
    int liczPop;        //Liczba poprawnych odpowiedzi.
};


//Inicjuje statystykę.
Statystyka Utworz();

//Dodaje błędną odpowiedź do statystyki.
void dodajBld(Statystyka& stat);

//Dodaje poprawną odpowiedź do statystyki.
void dodajPop(Statystyka& stat);

//Oblicza procentowa ilość poprawnych odpowiedzi.
double procent(Statystyka stat);
