#include <iostream>

using namespace std;

const int MAX_CHARS = 20;
typedef int Matricola;
typedef char Nome[30];

struct Prenotazione {
  Matricola mat;
  Nome nom;
};

class ListaPrenotazioni {
private:
  Prenotazione* pv; //puntatore a vettore prenotaz. dinamicam. allocato 
  int posti; //numero di posti disponibili
  int nelem; //riempimento del vettore
  
  int Ricerca(Matricola m) const;
public:
  ListaPrenotazioni(int n);
  ~ListaPrenotazioni();

  bool Prenota(Matricola m, Nome n);
  bool EliminaPrenotazione(Matricola m);
  int GetPostiDisponibili() const;
  bool EsistePrenotazione(Matricola m) const;
  void Svuota();
  void Stampa();
};

ListaPrenotazioni::ListaPrenotazioni(int n): posti(n), nelem(0) {
  pv = new Prenotazione[posti];
}

ListaPrenotazioni::~ListaPrenotazioni() {
  delete[] pv;
}

int ListaPrenotazioni::Ricerca(Matricola m) const {
  for (int i = 0; i < nelem; i++)
    if (pv[i].mat == m)
      return i;
      
  return -1;    
}

bool ListaPrenotazioni::Prenota(Matricola m, Nome n) {
  if ((GetPostiDisponibili() > 0) && (!EsistePrenotazione(m))) {
    pv[nelem].mat = m;
    strcpy(pv[nelem].nom, n);
    
    nelem++;
    return true;
  }
  
  return false;
}

bool ListaPrenotazioni::EliminaPrenotazione(Matricola m) {
  int i = Ricerca(m);
  
  if (i >= 0) {
    for (int j = i; j < nelem - 1; j++)
      pv[j] = pv[j+1];
      
    nelem--;
    
    return true;
  }
  
  return false;
}

int ListaPrenotazioni::GetPostiDisponibili() const {
  return posti - nelem;
}

bool ListaPrenotazioni::EsistePrenotazione(Matricola m) const {
  return (Ricerca(m) >= 0);
}

void ListaPrenotazioni::Svuota() {
  nelem = 0;
}

void ListaPrenotazioni::Stampa() {
  for (int i = 0; i < nelem; i++)
    cout << pv[i].mat << ": " << pv[i].nom << endl;
    
  cout << endl;  
}

void stampa_menu() {
  cout << "1: Prenota.\n";
  cout << "2: Elimina prenotazione.\n";
  cout << "3: Posti disponibili.\n";
  cout << "4: Esiste Prenotazione.\n";
  cout << "5: Svuota.\n";
  cout << "6: Stampa.\n";
  cout << "7: Esci.\n";
}

void Prenota(ListaPrenotazioni& l);
void Elimina(ListaPrenotazioni& l);
void GetPostiDisponibili(ListaPrenotazioni& l);
void EsistePrenotazione(ListaPrenotazioni& l);
void Svuota(ListaPrenotazioni& l);
void Stampa(ListaPrenotazioni& l);

int main()
{
  int n;
  cout << "Inserire il numero di posti disponibili: ";
  cin >> n;
  
  ListaPrenotazioni l(n);
  
  int scelta;
  do {
    stampa_menu();
    cin >> scelta;
    switch (scelta) {
      case 1:
        Prenota(l);
        break;
      case 2:
        Elimina(l);
        break;
      case 3:
        GetPostiDisponibili(l);
        break;      
      case 4:
        EsistePrenotazione(l);
        break;
      case 5:
        Svuota(l);
        break;
      case 6:
        Stampa(l);
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

void Prenota(ListaPrenotazioni& l) {
  Matricola m;
  Nome n;
  
  cout << "Inserisci Matricola: ";
  cin >> m;
  cout << "Inserisci nome: ";
  cin >> n;
  
  if (l.Prenota(m, n))
    cout << "Prenotazione effettuata.\n";
  else  
    cout << "Prenotazione non effettuata.\n";
}

void Elimina(ListaPrenotazioni& l) {
  Matricola m;
  
  cout << "Inserisci Matricola: ";
  cin >> m;
  
  if (l.EliminaPrenotazione(m))
    cout << "Prenotazione eliminata.\n";
  else  
    cout << "Prenotazione non eliminata.\n";
}

void GetPostiDisponibili(ListaPrenotazioni& l) {
  cout << "I posti disponibili sono: ";
  cout << l.GetPostiDisponibili() << endl;
}

void EsistePrenotazione(ListaPrenotazioni& l) {
  Matricola m;
  
  cout << "Inserisci Matricola: ";
  cin >> m;
  
  if (l.EsistePrenotazione(m))
    cout << "Prenotazione esistente.\n";
  else  
    cout << "Prenotazione non esistente.\n";
}

void Svuota(ListaPrenotazioni& l) {
  l.Svuota();
  cout << "Lista svuotata.\n";
}

void Stampa(ListaPrenotazioni& l) {
  l.Stampa();
}
