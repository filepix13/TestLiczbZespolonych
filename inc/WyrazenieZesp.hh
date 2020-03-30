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


//Wyświetla wyrażenie zespolone
std::ostream &operator <<(std::ostream &StrWy, WyrazenieZesp &WyrZ);

//Wczytuje wrażenie zespolone
std::istream &operator >>(std::istream& StrmWe,WyrazenieZesp &WyrZ);

//Oblicza wyrażenie zespolone
LZespolona Oblicz(WyrazenieZesp  WyrZ);



#endif
