#include <iostream>
#include "AlberoBinario.h"

using namespace std;

//Prototipi di funzioni di supporto per la verifica del corretto funzionamento
//dei metodi della classe AlberoBinario.
void stampaMenu();
void Inserisci(AlberoBinario& a);
void Svuota(AlberoBinario& a);
void Cerca(AlberoBinario& a);
void ContaNodi(AlberoBinario& a);
void NumeroElementi(AlberoBinario& a);
void PreOrdine(AlberoBinario& a);
void InOrdine(AlberoBinario& a);
void PostOrdine(AlberoBinario& a);

int main() {
  AlberoBinario albero;
  char c;
  
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
        Cerca(albero);
        break;
      case '4':
        ContaNodi(albero);
        break;
      case '5':
        NumeroElementi(albero);
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
  cout << "2. Svuota" << endl;
  cout << "3. Cerca" << endl;
  cout << "4. Conta Nodi" << endl;
  cout << "5. Numero Elementi" << endl;
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
  a.Inserisci(i);
  cout << "Elemento inserito.\n";
}

void Svuota(AlberoBinario& a) {
  cout << "Svuotamento albero." << endl;
  a.Svuota();
}

void Cerca(AlberoBinario& a) {
  int i;

  cout << "Inserisci intero: ";
  cin >> i;

  if (a.Cerca(i)) 
    cout << "Elemento trovato.\n";
  else  
    cout << "Elemento NON trovato.\n";
}

void ContaNodi(AlberoBinario& a) {
  unsigned int num0, num1, num2;
  
  a.ContaNodi(num0, num1, num2);
  cout << "Nodi con 0 figli: " << num0 <<endl;
  cout << "Nodi con 1 figlio: " << num1 <<endl;
  cout << "Nodi con 2 figli: " << num2 <<endl;
}  

void NumeroElementi(AlberoBinario& a) {
  cout << "Il numero di elementi e': " << a.NumElem() << endl;
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
