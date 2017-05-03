#include <iostream>

using namespace std;

const int NMAX = 50;
typedef char Nome[NMAX];
typedef unsigned int Codice; //un partito è per semplicità identificato
                             //da un codice di tipo intero.

struct Oggetto {
  Codice id;
  unsigned int voti;
};

struct Cella;
typedef Cella* PCella;

struct Cella {
  Oggetto elem;
  PCella succ;
};

class Votazioni {
  private:
    PCella first;
    unsigned int numVoti;
    PCella CercaPartito(Codice id) const;
  public:
    Votazioni();
    ~Votazioni();

    unsigned int AggiungiVoto(Codice id);
    void Svuota();
    unsigned int GetVotiPartito(Codice id) const;
    unsigned int GetNumeroVoti() const;
    void GetSituazione() const;
};  

Votazioni::Votazioni(): first(0), numVoti(0) {
}
  
Votazioni::~Votazioni() {
  Svuota();
}
  
PCella Votazioni::CercaPartito(Codice id) const {
//La struttura è gestibile con metodo tabellare: infatti il codice
//partito rappresenta una chiave per la tabella dei voti.
//Questo metodo restituisce il puntatore alla cella avente id pari a quello
//specificato in ingresso, 0 altrimenti.
  PCella p = first;
  bool trovato = false;
  
  while ((p) && !trovato) {
    if (p->elem.id == id)
      trovato = true;
    else
      p = p->succ;
  }  
    
  return p; //se trovato è vero, p punta alla cella ricerc., altrim. p è zero
}  
    
unsigned int Votazioni::AggiungiVoto(Codice id) {
  numVoti++;  //incremento il numero di voti complessivi
  PCella p = CercaPartito(id);
  
  if (p) {
    p->elem.voti++;
    return p->elem.voti;
  } else {
    PCella p = new Cella;
    p->elem.id = id;
    p->elem.voti = 1;
    p->succ = first;
    first = p;
    return 1;
  }   
}
  
void Votazioni::Svuota() {
  while(first) {
    PCella tbd = first;
    first = first->succ;
    delete tbd;
  }  
  numVoti = 0;
}
  
unsigned int Votazioni::GetVotiPartito(Codice id) const {
  PCella p = CercaPartito(id);
  
  if (p) 
    return p->elem.voti;
  else
    return 0;
}
  
unsigned int Votazioni::GetNumeroVoti() const {
  return numVoti;
}
  
void Votazioni::GetSituazione() const {
  PCella p = first;
  
  while (p) {
    cout << "Partito " << p->elem.id << ": voti " << " " << p->elem.voti;
    cout << " (" << (float)p->elem.voti/numVoti*100 << "%)" << endl;
    
    p = p->succ;
  }  
}
  
void AggiungiVoto(Votazioni& v);
void Svuota(Votazioni& v);
void GetVotiPartito(Votazioni& v);
void GetNumeroVoti(Votazioni& v);
void GetSituazione(Votazioni& v);

void stampa_menu() {
  cout << "1: Aggiungi voto.\n";
  cout << "2: Svuota.\n";
  cout << "3: Voti partito.\n";
  cout << "4: Numero voti.\n";
  cout << "5: Situazione.\n";
  cout << "6: Esci.\n";
}

int main()
{
  Votazioni v;
  
  int scelta;
  do {
    stampa_menu();
    cin >> scelta;
    switch (scelta) {
      case 1:
        AggiungiVoto(v);
        break;
      case 2:
        Svuota(v);
        break;
      case 3:
        GetVotiPartito(v);
        break;      
      case 4:
        GetNumeroVoti(v);
        break;      
      case 5:
        GetSituazione(v);
        break;
      case 6:
        break;      
      default:
        cout << "Scelta non valida.\n";
        break;  
    }
  } while (scelta != 6);
  
  return 0;
}

void AggiungiVoto(Votazioni& v) {
  Codice id;
  cout << "Indicare il partito: ";
  cin >> id;
  cout << "Voto Aggiunto. Ora il partito " << id << " ha voti " <<
                                               v.AggiungiVoto(id) << ".\n";
}
  
void Svuota(Votazioni& v) {
  v.Svuota();
  cout << "Struttura svuotata." << endl;
}
  
void GetVotiPartito(Votazioni& v) {
  Codice id;
  cout << "Indicare il partito: ";
  cin >> id;  
  cout << "Il partito " << id << " ha ottenuto voti " <<
                                              v.GetVotiPartito(id) << ".\n";
}  
 
void GetNumeroVoti(Votazioni& v) {
  cout << "I voti complessivi sono: " << v.GetNumeroVoti() << endl;
}
  
void GetSituazione(Votazioni& v) {
  v.GetSituazione();
}
