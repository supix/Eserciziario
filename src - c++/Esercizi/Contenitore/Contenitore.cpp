#include <iostream>

using namespace std;

const int NMAX = 50;
typedef char Nome[NMAX];
typedef int Peso; //si tratti il peso come valore intero (p.es. grammi)

struct Oggetto {
  Nome n;
  Peso p;
};

struct Cella;
typedef Cella* PCella;

struct Cella {
  Oggetto elem;
  PCella succ;
};

class Contenitore {
  private:
    PCella first;
    Peso capacita;
    Peso somma_pesi;
    unsigned int nelem;
  public:
    Contenitore(Peso max);
    ~Contenitore();
    
    bool Inserisci(char* n, Peso p);
    void Svuota();
    Peso PesoComplessivo() const;
    Peso PesoResiduo() const;
    unsigned int NumElem() const;
    void Stampa() const;
};  

Contenitore::Contenitore(Peso max): first(0), capacita(max),
                                                 somma_pesi(0), nelem(0) {
}
  
Contenitore::~Contenitore() {
  Svuota();
}
  
bool Contenitore::Inserisci(char* n, Peso p) {
  if (p <= capacita - somma_pesi) {
    PCella c = new Cella;
    strcpy(c->elem.n, n);
    c->elem.p = p;
    c->succ = first;
    first = c;
    
    somma_pesi = somma_pesi + p; //il contenitore è ora più pesante di p...
    nelem++; //...e c'è un elemento in più.
    
    return true;
  }  
  
  return false;
}
  
void Contenitore::Svuota() {
  while (first) {
    PCella tbd = first;
    first = first->succ;
    delete tbd;
  }
  
  somma_pesi = 0;
  nelem = 0;
}
  
Peso Contenitore::PesoComplessivo() const {
  return somma_pesi;
}
  
Peso Contenitore::PesoResiduo() const {
  return capacita - somma_pesi;
}
  
unsigned int Contenitore::NumElem() const {
  return nelem;
}
  
void Contenitore::Stampa() const {
  PCella p = first;
  while (p) {
    cout << p->elem.n << ", " << p->elem.p << endl;
    p = p->succ;
  }  
}
  
void Inserisci(Contenitore& c);
void Svuota(Contenitore& c);
void PesoComplessivo(Contenitore& c);
void PesoResiduo(Contenitore& c);
void NumeroElementi(Contenitore& c);
void Stampa(Contenitore& c);

void stampa_menu() {
  cout << "1: Inserisci.\n";
  cout << "2: Svuota.\n";
  cout << "3: Peso Complessivo.\n";
  cout << "4: Peso Residuo.\n";
  cout << "5: Numero Elementi.\n";
  cout << "6: Stampa.\n";
  cout << "7: Esci.\n";
}

int main()
{
  Peso p;
  cout << "Inserisci peso MAX contenitore: ";
  cin >> p;
  Contenitore c(p);
  
  int scelta;
  do {
    stampa_menu();
    cin >> scelta;
    switch (scelta) {
      case 1:
        Inserisci(c);
        break;
      case 2:
        Svuota(c);
        break;
      case 3:
        PesoComplessivo(c);
        break;      
      case 4:
        PesoResiduo(c);
        break;      
      case 5:
        NumeroElementi(c);
        break;
      case 6:
        Stampa(c);
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

void Inserisci(Contenitore& c) {
  char n[NMAX];
  Peso p;
  
  cout << "Inserisci nome elemento: ";
  cin >> n;
  cout << "Inserisci peso elemento: ";
  cin >> p;
  if (c.Inserisci(n, p))
    cout << "Elemento inserito.\n";
  else
    cout << "Elemento NON inserito.\n";
}

void Svuota(Contenitore& c) {
  c.Svuota();
  cout << "Contenitore svuotato.\n";
}

void PesoComplessivo(Contenitore& c) {
  cout << "Il peso complessivo e': " << c.PesoComplessivo() << endl;
}

void PesoResiduo(Contenitore& c) {
  cout << "Il peso residuo e': " << c.PesoResiduo() << endl;
}

void NumeroElementi(Contenitore& c) {
  cout << "N. Elem: " << c.NumElem() << endl;
}

void Stampa(Contenitore& c) {
  cout << "Il contenuto del contenitore e':\n";
  c.Stampa();
  cout << endl;
}
