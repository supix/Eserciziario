#include <iostream>
#include "AlberoBinario.h"

using namespace std;

//Prototipi di funzioni di supporto per la verifica del corretto funzionamento
//dei metodi della classe AlberoBinario.
void stampaMenu();
void Inserisci(AlberoBinario& a);
void Svuota(AlberoBinario& a);
void ContaMinMax(AlberoBinario& a);
void PreOrdine(AlberoBinario& a);
void InOrdine(AlberoBinario& a);
void PostOrdine(AlberoBinario& a);
void Uguali(AlberoBinario& a1, AlberoBinario& a2);

int main() {
  //Istanzio due alberi
  AlberoBinario albero1, albero2;
  //Istanzio un puntatore che, inizialmente, punta al primo albero.
  AlberoBinario* InUso = &albero1;
  char c;
  
  do {
    //Comunico all'utante quale dei due alberi sta utilizzando.
    if (InUso == &albero1)
      cout << "Ora stai lavorando sull'albero 1." << endl;
    else
      cout << "Ora stai lavorando sull'albero 2." << endl;  
    stampaMenu();
      
    cin >> c;
    cin.ignore();

    switch (c) {
      case '1':
        Inserisci(*InUso);
        break;
      case '2':
        Svuota(*InUso);
        break;
      case '3':
        ContaMinMax(*InUso);
        break;
      case '4':
        PreOrdine(*InUso);
        break;
      case '5':
        InOrdine(*InUso);
        break;
      case '6':
        PostOrdine(*InUso);
        break;
      case '7':
        Uguali(albero1, albero2);
        break;
      case 'c': //passo da un albero all'altro
        if (InUso == &albero1)
          InUso = &albero2;
        else
          InUso = &albero1;
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
  cout << "2. Svuota" << endl;
  cout << "3. ContaMinMax" << endl;
  cout << "4. Pre-ordine" << endl;
  cout << "5. InOrdine" << endl;
  cout << "6. Post-Ordine" << endl;
  cout << "7. Uguali" << endl;
  cout << "c. Cambia Albero." << endl;
  cout << "8. Esci" << endl;
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

void ContaMinMax(AlberoBinario& a) {
  int Min, Max;
  
  cout << "Inserisci Min: ";
  cin >> Min;
  cout << "Inserisci Max: ";
  cin >> Max;
  
  cout << "Ci sono " << a.ContaMinMax(Min, Max) << " elementi tra " <<
    Min << " e " << Max << ".\n";
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

void Uguali(AlberoBinario& a1, AlberoBinario& a2) {
  if (a1 == a2)
    cout << "Gli alberi sono uguali.\n";
  else  
    cout << "Gli alberi NON sono uguali.\n";
}  
