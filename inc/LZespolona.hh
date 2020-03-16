#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include "Statystyka.hh"

/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
};

//Deklaracja funkcji obliczającej sprzeżenie liczby zespolonej
LZespolona Sprzezenie(LZespolona);

//Deklaracja funkcji obliczającej moduł z liczby zespolonej
double Modul2(LZespolona);

//Deklaracja funckji dodającej dwie liczby zespolonej
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);

//Deklaracja funckji odejmującej dwie liczby zespolonej
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2);

//Deklaracja funckji mnożącej dwie liczby zespolonej
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2);

//Deklaracja funckji dzielącej dwie liczby zespolonej
LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2);


#endif
