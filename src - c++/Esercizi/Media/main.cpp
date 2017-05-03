#include <iostream>
#include "AlberoBinario.h"

using namespace std;

//Prototipi di funzioni di supporto per la verifica del corretto funzionamento
//dei metodi della classe AlberoBinario.
void stampaMenu();
void Inserisci(AlberoBinario& a);
void Svuota(AlberoBinario& a);
void PreOrdine(AlberoBinario& a);
void InOrdine(AlberoBinario& a);
void PostOrdine(AlberoBinario& a);

void Somma(AlberoBinario& a);
void Numero(AlberoBinario& a);
void Media(AlberoBinario& a);

int main() {
  char c;
  AlberoBinario albero;
  
  do {
    stampaMenu();
    cin >> c;
    cin.ignore();

    switch (c) {
      case '1':
        Inserisci(albero);
        break;
      case '2':
        Somma(albero);
        break;
      case '3':
        Numero(albero);
        break;
      case '4':
        Media(albero);
        break;
      case '5':
        Svuota(albero);
        break;
      case '6':
        PreOrdine(albero);
        break;
      case '7':
        InOrdine(albero);
        break;
      case '8':
        PostOrdine(albero);
        break;
      case '9':
        break;  
      default:
        cout << "Scelta non valida.\n";
        break;
    }    
  } while (c != '9');

  return 0;
}

void stampaMenu() {
  cout << endl;
  cout << "1. Inserisci" << endl;
  cout << "2. Somma" << endl;
  cout << "3. Numero Elementi" << endl;
  cout << "4. Media" << endl;
  cout << "5. Svuota" << endl;
  cout << "6. Pre-ordine" << endl;
  cout << "7. InOrdine" << endl;
  cout << "8. Post-Ordine" << endl;
  cout << "9. Esci" << endl;
  cout << endl;
  cout << "Scelta: ";
}

void Inserisci(AlberoBinario& a) {
  int i;
  cout << "Inserisci intero: ";
  cin >> i;
  a.AggiungiElem(i);
}

void Svuota(AlberoBinario& a) {
  cout << "Svuotamento albero." << endl;
  a.Svuota();
}

void PreOrdine(AlberoBinario& a) {
  cout << "Stampa in pre-ordine:\n";
  a.PreOrdine();
  cout << endl;  
}

void InOrdine(AlberoBinario& a) {
  cout << "Stampa in ordine:\n";
  a.InOrdine();
  cout << endl;  
}

void PostOrdine(AlberoBinario& a) {
  cout << "Stampa in post-ordine:\n";
  a.PostOrdine();
  cout << endl;
}

void Somma(AlberoBinario& a) {
  cout << "Inserisci il minimo: ";
  TElem min;
  cin >> min;
  
  TElem sum = a.Somma(min);
  cout << "La somma degli elementi >= " << min << " e': " << sum << endl;
}

void Numero(AlberoBinario& a) {
  cout << "Inserisci il minimo: ";
  TElem min;
  cin >> min;
  
  TElem num = a.NumElem(min);
  cout << "La somma degli elementi >= " << min << " e': " << num << endl;
}

void Media(AlberoBinario& a) {
  cout << "La media degli elementi dell'albero e': " << a.Media() << endl;
}

