#include <iostream>
#include "BazaTestu.hh"

using namespace std;

//Wczytuje wyrażenie zespolone i obsługuje błędy
void Wczytaj(LZespolona &LZesp);

int main(int argc, char **argv)
{

  WyrazenieZesp   WyrZ_PytanieTestowe;
  Statystyka stat;
  stat = Utworz();

  
  //Sprawdzamy czy użytkownik wprowadził odpowiedną ilość argumentów przy uruchamianiu programu
  if (argc != 2) {
    cout << endl;
    cerr << "Brak opcji okreslajacej rodzaj testu. Proszę podać tylko jedną nazwę." << endl;
    cerr << "Dopuszczalne nazwy to: latwy, trudny." << endl;
    cout << endl;
    return 1;
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };

  //Próba inicjalizacji podanego testu
  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << "Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }

  cout << endl;
  cout << "Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  //Wykonujemy test dla każego pytania.
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    
    LZespolona b, c;

    cout << "Podaj wynik operacji: ";
    cout << WyrZ_PytanieTestowe; 
    cout << "Twoja odpowiedź: ";
    
    Wczytaj(b);

    c = Oblicz(WyrZ_PytanieTestowe);

    if(b == c)
    {
      cout << "Odpowiedz poprawna" << endl << endl;

      dodajPop(stat);
    }
    
    else
    {
      cout << "Błędna odpowiedź. Poprawnym wynikiem jest: ";
      cout << c;
      cout << endl << endl;

      dodajBld(stat);
    }

  }

  cout << endl;
  cout << "Koniec testu" << endl;
  cout << endl;

  Wyswietl(stat);

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
