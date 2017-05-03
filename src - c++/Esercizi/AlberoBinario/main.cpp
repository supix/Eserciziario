#include <iostream>
#include "AlberoBinario.h"

using namespace std;

//Prototipi di funzioni di supporto per la verifica del corretto funzion.
//dei metodi della classe AlberoBinario.
void stampaMenu();
void Inserisci(AlberoBinario& a);
void Ricerca(AlberoBinario& a);
void Elimina(AlberoBinario& a);
void Svuota(AlberoBinario& a);
void PreOrdine(AlberoBinario& a);
void InOrdine(AlberoBinario& a);
void PostOrdine(AlberoBinario& a);
void Copia(AlberoBinario& a);

int main() {
  char c;
  AlberoBinario albero;
  
  do {
    stampaMenu();
    cin >> c;

    switch (c) {
      case '1':
        Inserisci(albero);
        break;
      case '2':
        Ricerca(albero);
        break;  
      case '3':
        Elimina(albero);
        break;
      case '4':
        Svuota(albero);
        break;
      case '5':
        PreOrdine(albero);
        break;
      case '6':
        InOrdine(albero);
        break;
      case '7':
        PostOrdine(albero);
        break;
      case '8':
        Copia(albero);
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
  cout << "2. Ricerca" << endl;
  cout << "3. Elimina" << endl;
  cout << "4. Svuota" << endl;
  cout << "5. Pre-ordine" << endl;
  cout << "6. InOrdine" << endl;
  cout << "7. Post-Ordine" << endl;
  cout << "8. Copia albero" << endl;
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

void Ricerca(AlberoBinario& a) {
  int i;
  cout << "Inserisci intero: ";
  cin >> i;
  if (a.InAlb(i))
    cout << "Trovato.\n";
  else  
    cout << "Non trovato.\n";
}

void Elimina(AlberoBinario& a) {
  int i;
  cout << "Inserisci intero: ";
  cin >> i;
  a.Elimina(i);
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

void Copia(AlberoBinario& a) {
  AlberoBinario b(a);
  cout << "La visita in ordine dell'albero copiato e': ";
  b.InOrdine();
  cout << endl;
  
  //al termine di questa funzione, l'istanza di AlberoBinario b viene
  //distrutta e rimossa dallo stack.
}
