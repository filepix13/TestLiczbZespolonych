#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH



#include "LZespolona.hh"
#include <iostream>


/*!
 * Modeluje zbior operatorow arytmetycznych.
 */
enum Operator { Op_Dodaj=1, Op_Odejmij=2, Op_Mnoz=3, Op_Dziel=4 };


/*
 * Modeluje pojecie dwuargumentowego wyrazenia zespolonego
 */
struct WyrazenieZesp {
  LZespolona   Arg1;   // Pierwszy argument wyrazenia arytmetycznego
  Operator     Op;     // Opertor wyrazenia arytmetycznego
  LZespolona   Arg2;   // Drugi argument wyrazenia arytmetycznego
};


//Tworzy liczbę zepoloną
LZespolona Utworz(double re, double im);

//Wczytuje liczbę zespoloną
LZespolona Wczytaj();

/*//Tworzy wyrażenie zespolone
WyrazenieZesp Utworz(double a, double b, Operator o, double c, double d);*/

//Wczytuje liczbę zespoloną
LZespolona Wczytaj();

//Wczytuje wrażenie zespolone
WyrazenieZesp Wczytaj1();

//Wyświetla liczbę zespoloną
void Wyswietl(LZespolona l);

//Wyświetla wyrażenie zespolone
void Wyswietl(WyrazenieZesp  WyrZ);

//Oblicza wyrażenie zespolone
LZespolona Oblicz(WyrazenieZesp  WyrZ);

//Prównuje dwie liczby zespolone
bool Porownaj(LZespolona a, LZespolona b);

#endif
