#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH



#include "LZespolona.hh"
#include <iostream>


/*!
 * Modeluje zbior operatorow arytmetycznych.
 */
enum Operator {Op_Dodaj = 0, Op_Odejmij, Op_Mnoz, Op_Dziel};


/*
 * Modeluje pojecie dwuargumentowego wyrazenia zespolonego
 */
struct WyrazenieZesp {
  LZespolona   Arg1;   // Pierwszy argument wyrazenia arytmetycznego
  Operator     Op;     // Opertor wyrazenia arytmetycznego
  LZespolona   Arg2;   // Drugi argument wyrazenia arytmetycznego
};



//Wyświetla liczbę zespoloną
std::ostream &operator <<(std::ostream& StrmWy,LZespolona &Lz);

//Wyświetla wyrażenie zespolone
std::ostream &operator <<(std::ostream &StrWy, WyrazenieZesp &WyrZ);

//Wczytuje liczbę zespoloną
std::istream &operator >>(std::istream& StrmWe,LZespolona &Lz);

//Wczytuje wrażenie zespolone
std::istream &operator >>(std::istream& StrmWe,WyrazenieZesp &WyrZ);

//Tworzy liczbę zepoloną
LZespolona Utworz(double re, double im);

//Wczytuje wyrażenie zespolone i obsługuje błędy
void Wczytaj(LZespolona &LZesp);

//Oblicza wyrażenie zespolone
LZespolona Oblicz(WyrazenieZesp  WyrZ);

//Prównuje dwie liczby zespolone
bool Porownaj(LZespolona a, LZespolona b);

#endif
