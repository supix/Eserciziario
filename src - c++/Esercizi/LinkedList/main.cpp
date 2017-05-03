#include <iostream>
#include <stdlib.h>

#include "lista.h"

using namespace std;

//Prototipi di funzioni di supporto per la verifica del
//corretto funzionamento dei metodi della classe Lista.
void stampaMenu();
void Inserisci(Lista& l);
void Ricerca(Lista& l);
void Elimina(Lista& l);
void Svuota(Lista& l);
void NumeroElementi(Lista& l);
void Stampa(Lista& l);
void CopiaLista(Lista& l);

int main()
{
  char c;
  Lista lista;
  
  do {
    stampaMenu();
    cin >> c;

    switch (c) {
      case '1':
        Inserisci(lista);
        break;
      case '2':
        Ricerca(lista);
        break;  
      case '3':
        Elimina(lista);
        break;
      case '4':
        Svuota(lista);
        break;
      case '5':
        Stampa(lista);
        break;
      case '6':
        NumeroElementi(lista);
        break;
      case '7':
        CopiaLista(lista);
        break;  
      case '8':
        break;
      default:
        cout << "Scelta non valida.\n";
        break;
    }    
  } while (c != '8');

  return 0;
}

void stampaMenu() {
  cout << endl;
  cout << "1. Inserisci" << endl;
  cout << "2. Ricerca" << endl;
  cout << "3. Elimina" << endl;
  cout << "4. Svuota" << endl;
  cout << "5. Stampa" << endl;
  cout << "6. Numero Elementi" << endl;
  cout << "7. Copia" << endl;
  cout << "8. Esci" << endl;
  cout << endl;
  cout << "Scelta: ";
}

void Inserisci(Lista& l) {
  int i;
  cout << "Inserisci intero: ";
  cin >> i;
  l.Inserisci(i);
}

void Ricerca(Lista& l) {
  int i;
  cout << "Inserisci intero: ";
  cin >> i;
  if (l.Ricerca(i))
    cout << "Trovato.\n";
  else  
    cout << "Non trovato.\n";
}

void Elimina(Lista& l) {
  int i;
  cout << "Inserisci intero: ";
  cin >> i;
  l.Elimina(i);
}

void Svuota(Lista& l) {
  cout << "Svuotamento lista." << endl;
  l.Svuota();
}

void Stampa(Lista& l) {
  cout << "Stampa:\n";
  l.Stampa();
  cout << endl;
}

void NumeroElementi(Lista& l) {
  cout << "Numero Elementi: " << l.NumeroElementi() << endl;
}

void CopiaLista(Lista& l) {
  Lista lcopia(l);
  
  cout << "La lista copiata contiene: ";
  lcopia.Stampa();
  cout << endl;
}
