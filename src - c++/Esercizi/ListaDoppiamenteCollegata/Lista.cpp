#include <iostream>

using namespace std;

struct Record;
typedef Record* PRec;
typedef int TElem;

struct Record {
  TElem el;
  PRec prec;
  PRec succ;
};

class Lista {
private:
  PRec first;
  PRec last;
  unsigned int nelem;
  
  Lista(const Lista&); //inibisce la copia mediante costruttore
  void operator= (const Lista&); //inibisce l'assegnazione
public:
  Lista();
  ~Lista();

  void Inserisci(TElem el);
  void Svuota();
  void StampaDiretta() const;
  void StampaInversa() const;
  void StampaAlternata() const;
  unsigned int Count() const;
};

Lista::Lista(): first(0), last(0), nelem(0) {
}

Lista::~Lista() {
  Svuota();
}

void Lista::Inserisci(TElem el) {
  //Inserimento in coda
  PRec p = new Record;
  p->el = el;
  p->succ = 0;
  p->prec = last;
  if (last)
    last->succ = p;
  last = p;
  
  if (!first)
    first = p;

  nelem++;
}

void Lista::Svuota() {
  PRec tbd; //to be deleted
  while (first != 0) {
    tbd = first;
    first = first->succ;
    delete tbd;
  }
  nelem = 0;
  last = 0;
}

void Lista::StampaDiretta() const {
  PRec p = first;
  while (p != 0) {
    cout << p->el << " ";
    p = p->succ;
  }  
}

void Lista::StampaInversa() const {
  PRec p = last;
  while (p != 0) {
    cout << p->el << " ";
    p = p->prec;
  }  
}

void Lista::StampaAlternata() const {
  PRec p = first;
  PRec q = last;
  bool done = false;
  
  while ((p) && !done) {
    cout << p->el << " ";
    if (q != p)
      cout << q->el << " ";
      
    //se p e q sono sovrapposti oppure sono consecutivi
    //abbiamo terminato
    if ((p == q) || (p->succ == q))
      done = true;

    p = p->succ;
    q = q->prec;
  }  
}

unsigned int Lista::Count() const {
  return nelem;
}  

void stampa_menu() {
  cout << "1: Inserisci.\n";
  cout << "2: Svuota.\n";
  cout << "3: Stampa Diretta.\n";
  cout << "4: Stampa Inversa.\n";
  cout << "5: Stampa Alternata.\n";
  cout << "6: Count.\n";
  cout << "7: Esci.\n";
}

void Inserisci(Lista& l);
void Svuota(Lista& l);
void StampaDiretta(Lista& l);
void StampaInversa(Lista& l);
void StampaAlternata(Lista& l);
void Count(Lista& l);

int main()
{
  Lista l;
  
  int scelta;
  do {
    stampa_menu();
    cin >> scelta;
    switch (scelta) {
      case 1:
        Inserisci(l);
        break;
      case 2:
        Svuota(l);
        break;
      case 3:
        StampaDiretta(l);
        break;      
      case 4:
        StampaInversa(l);
        break;      
      case 5:
        StampaAlternata(l);
        break;    
      case 6:
        Count(l);
        break;
      case 7:
        break;
      default:
        cout << "Scelta non valida.\n";
        break;  
    }
  } while (scelta != 7);
  
  return 0;
}

void Inserisci(Lista& l) {
  TElem el;
  cout << "Inserisci valore elemento: ";
  cin >> el;
  l.Inserisci(el);
}

void Svuota(Lista& l) {
  l.Svuota();
  cout << "Lista svuotata.\n";
}

void StampaDiretta(Lista& l) {
  cout << "Stampa Diretta: ";
  l.StampaDiretta();
  cout << endl;
}

void StampaInversa(Lista& l) {
  cout << "Stampa Inversa: ";
  l.StampaInversa();
  cout << endl;
}

void StampaAlternata(Lista& l) {
  cout << "Stampa Alternata: ";
  l.StampaAlternata();
  cout << endl;
}
void Count(Lista& l) {
  cout << "Il numero di elementi contenuti nella lista e': "
                                                 << l.Count() << endl;
}
