#include <iostream>
#include <string.h>

using namespace std;

const int NMAX = 50;
typedef char Nome[NMAX];

struct Record;
typedef Record* PRec;

typedef struct {
  Nome n;
  unsigned int punteggio;
} Squadra;

typedef Squadra TElem;

struct Record { //Singolo elemento (cella) della struttura
  TElem el;
  PRec succ;
};

class Classifica {
private:
  PRec first;
  unsigned int nelem;
  
  Classifica(const Classifica&); //inibisce la copia mediante costruttore
  void operator= (const Classifica&); //inibisce l'assegnazione
  
  unsigned int Elimina(const Nome& n);
  void InserimentoOrdinato(const Nome& n, unsigned int punti);
public:
  Classifica();
  ~Classifica();

  unsigned int Aggiungi(const Nome& n, unsigned int punti);
  void Svuota();
  void Stampa() const;
  unsigned int Count() const;
};

Classifica::Classifica(): first(0), nelem(0) {
}

Classifica::~Classifica() {
  Svuota();
}

unsigned int Classifica::Elimina(const Nome& n) {
//Questo metodo elimina dalla struttura un eventuale elem. avente nome pari
//ad n. In caso di esistenza ne restituisce il punteggio, altrimenti
//restituisce 0.
  
  //E' il primo elemento? (Caso particolare)
  if (first && (strcmp(first->el.n, n) == 0)) {
    PRec tbd = first;
    first = first ->succ;
    unsigned int punti = tbd->el.punteggio;
    delete tbd;
    nelem--;
    return punti;
  }
  
  //E' un elemento successivo al primo?
  PRec p = first;
  while (p && p->succ) {
    //controllo se il successivo di p deve essere eliminato
    if (strcmp(p->succ->el.n, n) == 0) {
      PRec tbd = p->succ;
      p->succ = tbd->succ;
      unsigned int punti = tbd->el.punteggio;
      delete tbd;
      nelem--;
      return punti;
    }  

    p = p->succ;
  }  
  
  //Elemento non trovato
  return 0;
}  

void Classifica::InserimentoOrdinato(const Nome& n, unsigned int punti) {
//Questo metodo effettua un inserimento ordinato nella struttura, in base al
//campo punteggio. Si procede attraverso i seguenti passi:
//  - se la lista è vuota si inserisce l'elemento e si esce;
//  - si controlla se inserire in testa: se sì, si inserisce e si esce;
//  - si cerca il punto di inserimento attraverso una visita, si inserisce
//    (eventualmente in coda) e si esce.

  //In ogni caso alloco un nuovo record
  PRec nuovo = new Record;
  strcpy(nuovo->el.n, n);
  nuovo->el.punteggio = punti;
  nelem++;
  
  if (!first) { //Se la lista è vuota
    first = nuovo; //Inserisco alla testa
    nuovo->succ = 0;
  } else {
    //Se il punteggio della nuova squadra è maggiore della testa
    if (punti >= first->el.punteggio) {
      nuovo->succ = first; //Inserisco in testa
      first = nuovo;
    } else { //Devo cercare il punto di inserzione
      PRec p = first;
      while (p && p->succ) {
        //Devo inserire dopo l'elemento puntato da p?
        if (punti >= p->succ->el.punteggio) {
          nuovo->succ = p->succ;
          p->succ = nuovo;
          return;
        }
        
        p = p->succ;
      }
      
      //Se sono qui, non ho ancora inserito: inserim. in coda, alla quale punta p
      p->succ = nuovo;
      nuovo->succ = 0;
    }  
  }  
}
  
unsigned int Classifica::Aggiungi(const Nome& n, unsigned int punti) {
  unsigned int p = Elimina(n); //Elimina dalla lista l'elemento (se esiste)
  
  InserimentoOrdinato(n, punti + p); //Lo (re)inserisce al posto giusto
  
  return punti + p; //Restituisce il giusto punteggio
}
  
void Classifica::Svuota() {
  while (first) {
    PRec tbd = first;
    first = first->succ;
    delete tbd;
  }
  nelem = 0;
}
  
void Classifica::Stampa() const {
  PRec p = first;
  while (p) {
    cout << p->el.n << ": " << p->el.punteggio << endl;
    p = p->succ;
  }
}
  
unsigned int Classifica::Count() const {
  return nelem;
}
  
void stampa_menu() {
  cout << "1: Inserisci.\n";
  cout << "2: Svuota.\n";
  cout << "3: Stampa.\n";
  cout << "4: Count.\n";
  cout << "5: Esci.\n";
}

void Aggiungi(Classifica& l);
void Svuota(Classifica& l);
void Stampa(Classifica& l);
void Count(Classifica& l);

int main()
{
  Classifica l;
  
  int scelta;
  do {
    stampa_menu();
    cin >> scelta;
    switch (scelta) {
      case 1:
        Aggiungi(l);
        break;
      case 2:
        Svuota(l);
        break;
      case 3:
        Stampa(l);
        break;      
      case 4:
        Count(l);
        break;      
      case 5:
        break;
      default:
        cout << "Scelta non valida.\n";
        break;  
    }
  } while (scelta != 5);
  
  return 0;
}

void Aggiungi(Classifica& l) {
  Nome n;
  unsigned int punti;
  cout << "Inserisci nome: ";
  cin >> n;
  cout << "Inserisci punti: ";
  cin >> punti;
  cout << "La squadra " << n << " ora ha punti: " << l.Aggiungi(n, punti) << ".\n";
}

void Svuota(Classifica& l) {
  l.Svuota();
  cout << "Classifica svuotata.\n";
}

void Stampa(Classifica& l) {
  l.Stampa();
  cout << endl;
}

void Count(Classifica& l) {
  cout << "Il numero di elementi e': " << l.Count() << endl;
}

