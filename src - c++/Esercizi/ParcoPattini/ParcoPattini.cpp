#include <iostream>

using namespace std;

typedef unsigned int Taglia;

struct Pattini {
  Taglia taglia;
  unsigned int totali;
  unsigned int disponibili;
};

struct Record;
typedef Record* PRec;
typedef struct Record {
  Pattini pattini;
  PRec succ;
};
  
class ParcoPattini {
private:
  PRec first;
  unsigned int tot;
  PRec GetRecordByTaglia(Taglia t) const;
  
  ParcoPattini(const ParcoPattini&); //inibisce la copia mediatne costr.
  ParcoPattini& operator=(const ParcoPattini&); //inibisce l'assegnazione
public:
  ParcoPattini();
  ~ParcoPattini();
  void AggiungiPattini(Taglia t);
  void Svuota();
  unsigned int NumeroTotPattini() const;
  bool Fitta(Taglia t);
  unsigned int Disponibilita(Taglia t) const;
  unsigned int NumeroPattini(Taglia t) const;
  bool Restituzione(Taglia t);
  void Stampa() const;
};  

ParcoPattini::ParcoPattini(): first(0), tot(0) {}

ParcoPattini::~ParcoPattini() {
  Svuota();
}

PRec ParcoPattini::GetRecordByTaglia(Taglia t) const {
//Questo metodo permette la gestione della lista come tabella.
//Restituisce il punt. alla cella contenente i pattini della taglia richiesta,
//oppure 0 se tale cella non è nella lista.

  PRec p = first;
  
  while (p) {
    if (p->pattini.taglia == t) //trovato?
      return p; //restituisce il puntatore alla cella della lista
    else
      p = p->succ; //altrimenti avanza di una cella
  }
  
  return 0; //non trovato.
}  

void ParcoPattini::AggiungiPattini(Taglia t) {
  PRec p = GetRecordByTaglia(t);
  
  if (p) {
    p->pattini.totali++;
    p->pattini.disponibili++;
  }
  else {
    PRec p = new Record;
    p->pattini.taglia = t;
    p->pattini.totali = 1;
    p->pattini.disponibili = 1;
    p->succ = first;
    first = p;
  }    
  
  tot++;
}
  
void ParcoPattini::Svuota() {
  while (first) {
    PRec tbd = first;
    first = first->succ;
    delete tbd;
  }  
  
  tot = 0;
}
  
unsigned int ParcoPattini::NumeroTotPattini() const {
  return tot;
}
  
bool ParcoPattini::Fitta(Taglia t) {
  PRec p = GetRecordByTaglia(t);
  
  //ci sono pattini della taglia specificata, e se sì, ce ne sono di disp.?
  if (p && (p->pattini.disponibili > 0)) {
    p->pattini.disponibili--; //decrementa la disponibilità
    return true;
  }
  else
    return false;
}
  
unsigned int ParcoPattini::Disponibilita(Taglia t) const {
  PRec p = GetRecordByTaglia(t);
  
  if (p)
    return p->pattini.disponibili;
  else
    return 0;  
}
  
unsigned int ParcoPattini::NumeroPattini(Taglia t) const {
  PRec p = GetRecordByTaglia(t);
  
  if (p)
    return p->pattini.totali;
  else
    return 0;  
}
  
bool ParcoPattini::Restituzione(Taglia t) {
  PRec p = GetRecordByTaglia(t);
  
  //ci sono pattini della taglia specif., e se sì, ce ne sono di fittati?
  if (p && (p->pattini.disponibili < p->pattini.totali)) {
    p->pattini.disponibili++;
    return true;
  }    
  else
    return false;  
}
  
void ParcoPattini::Stampa() const {
  PRec p = first;
  
  while (p) {
    cout << "Taglia " << p->pattini.taglia << ": ";
    cout << "Totale: " << p->pattini.totali << " ";
    cout << "Fittati: " << p->pattini.totali - p->pattini.disponibili
                                                               << ".\n";
    p = p->succ;
  }  
}

void AggiungiPattini(ParcoPattini& p);
void Svuota(ParcoPattini& p);
void NumeroTotPattini(ParcoPattini& p);
void Fitta(ParcoPattini& p);
void Disponibilita(ParcoPattini& p);
void NumeroPattini(ParcoPattini& p);
void Restituzione(ParcoPattini& p);
void Stampa(ParcoPattini& p);

void stampa_menu() {
  cout << "\n";
  cout << "1: AggiungiPattini.\n";
  cout << "2: Svuota.\n";
  cout << "3: NumeroTotPattini.\n";
  cout << "4: Fitta.\n";
  cout << "5: Disponibilita.\n";
  cout << "6: NumeroPattini.\n";
  cout << "7: Restituzione.\n";
  cout << "8: Stampa.\n";
  cout << "9: Esci.\n";
  cout << "Scelta: ";
}

int main()
{
  ParcoPattini parco;
  
  int scelta;
  do {
    stampa_menu();
    cin >> scelta;
    switch (scelta) {
      case 1:
        AggiungiPattini(parco);
        break;
      case 2:
        Svuota(parco);
        break;
      case 3:
        NumeroTotPattini(parco);
        break;      
      case 4:
        Fitta(parco);
        break;      
      case 5:
        Disponibilita(parco);
        break;
      case 6:
        NumeroPattini(parco);
        break;      
      case 7:
        Restituzione(parco);
        break;      
      case 8:
        Stampa(parco);
        break;      
      case 9:
        break;    
      default:
        cout << "Scelta non valida.\n";
        break;  
    }
  } while (scelta != 9);
  
  return 0;
}

void AggiungiPattini(ParcoPattini& p) {
  Taglia t;
  
  cout << "Inserire la taglia: ";
  cin >> t;
  p.AggiungiPattini(t);
  cout << "Pattini aggiunti al parco.\n";
}
  
void Svuota(ParcoPattini& p) {
  p.Svuota();
  cout << "Parco svuotato.\n";
}
  
void NumeroTotPattini(ParcoPattini& p) {
  cout << "Il parco pattini contiene " << p.NumeroTotPattini()
                                              << " paia di pattini in totale.\n";
}
  
void Fitta(ParcoPattini& p) {
  Taglia t;
  
  cout << "Inserire la taglia: ";
  cin >> t;
  if (p.Fitta(t))
    cout << "Pattini fittati.\n";
  else
    cout << "Pattini non disponibili.\n";
}
  
void Disponibilita(ParcoPattini& p) {
  Taglia t;
  
  cout << "Inserire la taglia: ";
  cin >> t;
  cout << "Disponibilita' taglia " << t << ": " << p.Disponibilita(t)
                                                               << endl;
}
  
void NumeroPattini(ParcoPattini& p) {
  Taglia t;
  
  cout << "Inserire la taglia: ";
  cin >> t;
  cout << "Il parco contiene " << p.NumeroPattini(t) <<
                           " paia di pattini di taglia " << t << ".\n";
}
  
void Restituzione(ParcoPattini& p) {
  Taglia t;
  
  cout << "Inserire la taglia: ";
  cin >> t;
  if (p.Restituzione(t))
    cout << "Pattini restituiti.\n";
  else
    cout << "Errore. Pattini non fittati.\n";
}
  
void Stampa(ParcoPattini& p) {
  p.Stampa();
}
