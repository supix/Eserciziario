#include <iostream>

using namespace std;

const int NMAX = 50;
typedef char Nome[NMAX]; //Nome Persona

struct persona;
typedef struct Persona{
  Nome n;
  bool maschio;
  Persona* coniuge;
};

typedef Persona TElem;

struct Record;
typedef Record* PRec;
struct Record { //Singolo elemento (cella) della struttura
  TElem el;
  PRec succ;
};

class AgenziaMatrimoniale {
private:
  PRec first;
    
  AgenziaMatrimoniale(const AgenziaMatrimoniale&); //inibisce la copia da costr.
  void operator= (const AgenziaMatrimoniale&); //inibisce l'assegnazione
  
  PRec Cerca(Nome n) const;
public:
  AgenziaMatrimoniale();
  ~AgenziaMatrimoniale();

  bool AggiungiPersona(Nome n, bool sesso);
  bool Sposa(Nome n1, Nome n2);
  bool Coniugato(Nome n, bool& coniugato) const;
  unsigned int NumeroSposi() const;
  unsigned int NumeroCoppie() const;
  void Svuota();
  void Stampa() const;
};

AgenziaMatrimoniale::AgenziaMatrimoniale(): first(0) {
}

AgenziaMatrimoniale::~AgenziaMatrimoniale() {
  Svuota();
}

PRec AgenziaMatrimoniale::Cerca(Nome n) const {
//Cerca nella lista la persona avente il nome specificato
//Restituisce il puntatore alla corrispondente cella se esiste, 0 altrim.
  PRec p = first;
  while (p) {
    if (strcmp(p->el.n, n) == 0)
      return p;
    p = p->succ;
  }
  
  return 0;  
}  

bool AgenziaMatrimoniale::AggiungiPersona(Nome n, bool maschio) {
  if (Cerca(n))
    return false;
  
  //Inserimento in testa
  PRec p = new Record;
  strcpy(p->el.n, n);
  p->el.maschio = maschio;
  p->el.coniuge = 0;
  p->succ = first;
  first = p;
  
  return true;
}
  
bool AgenziaMatrimoniale::Sposa(Nome n1, Nome n2) {
  PRec p1 = Cerca(n1);
  //se il primo nome non è stato trovato restituisce false
  if (!p1)
    return false;

  PRec p2 = Cerca(n2);
  //se il secondo nome non è stato trovato restituisce false
  if (!p2) 
    return false;  

  //se i due nomi sono uguali restituisce false
  if (p1 == p2)
    return false;

  //se il sesso è uguale restituisce false
  if (p1->el.maschio == p2->el.maschio)
    return false; 

  //se una delle due persone è già sposata restituisce false
  if (p1->el.coniuge || p2->el.coniuge)
    return false;

  p1->el.coniuge = &p2->el;
  p2->el.coniuge = &p1->el;
  
  return true;
}
  
bool AgenziaMatrimoniale::Coniugato(Nome n, bool& coniugato) const {
  PRec p = Cerca(n);
  
  if (!p)
    return false;
    
  coniugato = (p->el.coniuge != 0);
  return true;
}
  
unsigned int AgenziaMatrimoniale::NumeroSposi() const {
  unsigned int count = 0;
  PRec p = first;
  
  while (p) {
    if (p->el.coniuge != 0)
      count++;
    p = p->succ;
  }
  
  return count;
}
  
unsigned int AgenziaMatrimoniale::NumeroCoppie() const {
  return NumeroSposi() / 2;
}
  
void AgenziaMatrimoniale::Svuota() {
  while (first) {
    PRec tbd = first;
    first = first->succ;
    delete tbd;
  }
}
  
void AgenziaMatrimoniale::Stampa() const {
  PRec p = first;
  while (p) {
    cout << p->el.n << " (";
    if (p->el.maschio)
      cout << 'M';
    else
      cout << 'F';
    cout << ");";
    
    if (p->el.coniuge)
      cout << " coniuge: " << p->el.coniuge->n << ".";
    
    cout << endl;
    
    p = p->succ;
  }    
}  
  
void stampa_menu() {
  cout << "1: AggiungiPersona.\n";
  cout << "2: Sposa.\n";
  cout << "3: Coniugato.\n";
  cout << "4: NumeroSposi.\n";
  cout << "5: NumeroCoppie.\n";
  cout << "6: Svuota.\n";
  cout << "7: Stampa.\n";
  cout << "8: Esci.\n";
}

void AggiungiPersona(AgenziaMatrimoniale& am);
void Sposa(AgenziaMatrimoniale& am);
void Coniugato(AgenziaMatrimoniale& am);
void NumeroSposi(AgenziaMatrimoniale& am);
void NumeroCoppie(AgenziaMatrimoniale& am);
void Svuota(AgenziaMatrimoniale& am);
void Stampa(AgenziaMatrimoniale& am);

int main()
{
  AgenziaMatrimoniale am;
  
  int scelta;
  do {
    stampa_menu();
    cin >> scelta;
    switch (scelta) {
      case 1:
        AggiungiPersona(am);
        break;
      case 2:
        Sposa(am);
        break;
      case 3:
        Coniugato(am);
        break;      
      case 4:
        NumeroSposi(am);
        break;      
      case 5:
        NumeroCoppie(am);
        break;      
      case 6:
        Svuota(am);
        break;      
      case 7:
        Stampa(am);
        break;      
      case 8:
        break;
      default:
        cout << "Scelta non valida.\n";
        break;  
    }
  } while (scelta != 8);
  
  return 0;
}

void AggiungiPersona(AgenziaMatrimoniale& am) {
  Nome n;
  cout << "Specificare il nome: ";
  cin >> n;
  char sesso;
  do {
    cout << "Specificare il sesso (M, F): ";
    cin >> sesso;
  } while ((sesso != 'M') && (sesso != 'm') && (sesso != 'F')
                                               && (sesso != 'f'));
  
  bool maschio = (sesso == 'M' || sesso == 'm');

  if (am.AggiungiPersona(n, maschio))
    cout << "Persona aggiunta.\n";
  else
    cout << "Persona non aggiunta.\n";
}

void Sposa(AgenziaMatrimoniale& am) {
  Nome n1, n2;
  cout << "Inserire primo nome: ";
  cin >> n1;
  cout << "Inserire secondo nome: ";
  cin >> n2;
  
  if (am.Sposa(n1, n2))
    cout << "Matrimonio registrato.\n";
  else
    cout << "Matrimonio non registrato.\n";
}
  
void Coniugato(AgenziaMatrimoniale& am) {
  Nome n;
  bool coniugato;
  cout << "Inserisci il nome: ";
  cin >> n;
  if (!am.Coniugato(n, coniugato))
    cout << "Persona non esistente.\n";
  else
    if (coniugato)
      cout << n << " ha coniuge.\n";
    else
      cout << n << " non ha coniuge.\n";
}

void NumeroSposi(AgenziaMatrimoniale& am) {
  cout << "Il numero sposi è pari a " << am.NumeroSposi() << endl;
}
  
void NumeroCoppie(AgenziaMatrimoniale& am) {
  cout << "Il numero coppie è pari a " << am.NumeroCoppie() << endl;
}
  
void Svuota(AgenziaMatrimoniale& am) {
  am.Svuota();
  cout << "AgenziaMatrimoniale svuotata.\n";
}

void Stampa(AgenziaMatrimoniale& am) {
  am.Stampa();
  cout << endl;
}

