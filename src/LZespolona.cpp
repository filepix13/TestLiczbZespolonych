#include "LZespolona.hh"
#include <cmath>


/*!
 * Realizuje sprzężenie liczby zespolonej.
 * Argumenty:
 *    l - liczba zespolona której sprzężenie wykonujemy,
 * Zwraca:
 *    Sprzężoną liczbę zespoloną
 */
LZespolona Sprzezenie(LZespolona l)
{
  LZespolona liczba;

  liczba.re = l.re;
  liczba.im = -l.im;
  
  return liczba;
}


/*!
 * Realizuje obliczenie modułu liczby zespolonej.
 * Argumenty:
 *    l - liczba zespolona, której moduł obliczamy.
 * Zwraca:
 *    Moduł liczby zespolonej.
 */
double Modul2(LZespolona l)
{
  double modul = sqrt(pow(l.re, 2) + pow(l.im, 2));
  return modul;
}

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}


/*!
 * Realizuje odejmnowanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik odejmowania,
 *    Skl2 - drugi skladnik odejmowania.
 * Zwraca:
 *    Różnicę dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}


/*!
 * Realizuje mnożenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik mnożenia,
 *    Skl2 - drugi skladnik mnożenia.
 * Zwraca:
 *    Iloczyn dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re * Skl2.re;
  Wynik.im = Skl1.im * Skl2.im;
  return Wynik;
}


/*!
 * Realizuje dzielenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dzielenia,
 *    Skl2 - drugi skladnik dzielenia.
 * Zwraca:
 *    Iloraz dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  a,Wynik;
  double b;

  a = Sprzezenie(Skl2);
  b = Modul2(Skl2);

  Wynik.re = (Skl1.re*a.re)/b;
  Wynik.im = (Skl1.im*a.im)/b;

  return Wynik;
}
