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

int main() {
  char c;
  int maxocc;
  cout << "Quante occorrenze al massimo per ciascun elemento? ";
  cin >> maxocc;
  AlberoBinario albero(maxocc);
  
  do {
    stampaMenu();
    cin >> c;
    cin.ignore();

    switch (c) {
      case '1':
        Inserisci(albero);
        break;
      case '2':
        Svuota(albero);
        break;
      case '3':
        PreOrdine(albero);
        break;
      case '4':
        InOrdine(albero);
        break;
      case '5':
        PostOrdine(albero);
        break;
      case '6':
        break;  
      default:
        cout << "Scelta non valida.\n";
        break;
    }    
  } while (c != '6');

  return 0;
}

void stampaMenu() {
  cout << endl;
  cout << "1. Inserisci" << endl;
  cout << "2. Svuota" << endl;
  cout << "3. Pre-ordine" << endl;
  cout << "4. InOrdine" << endl;
  cout << "5. Post-Ordine" << endl;
  cout << "6. Esci" << endl;
  cout << endl;
  cout << "Scelta: ";
}

void Inserisci(AlberoBinario& a) {
  int i;
  cout << "Inserisci intero: ";
  cin >> i;
  if (a.Inserisci(i))
    cout << "Elemento inserito.\n";
  else  
    cout << "Elemento non inserito.\n";
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
