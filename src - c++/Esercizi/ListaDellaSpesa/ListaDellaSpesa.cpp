#include <iostream>

using namespace std;

const int MAX_CHARS = 20;
typedef char Nome[MAX_CHARS];
typedef float Quantita;

struct Articolo {
  Nome n;
  Quantita q;
};

struct Record;
typedef Record* PRec;
struct Record {
  Articolo art;
  PRec succ;
};

class ListaDellaSpesa {
private:
  PRec first;
  bool Ricerca(const Nome n, PRec& p) const;
  bool _Elimina(PRec& p, const Nome n);
  bool StringheUguali(const char* s1, const char* s2) const {
    return (strcmp(s1, s2) == 0);
  }
  
  //inibisce la copia mediante costruttore
  ListaDellaSpesa(const ListaDellaSpesa&) {};
  //inibisce la copia mediante assegnazione
  void operator= (const ListaDellaSpesa&) {};
public:
  ListaDellaSpesa();
  ~ListaDellaSpesa();
  
  Quantita Aggiungi(const Nome n, Quantita q);
  bool Elimina(const Nome n);
  Quantita GetQuantita(const Nome n) const;
  void Svuota();
  void Stampa() const;
};

ListaDellaSpesa::ListaDellaSpesa(): first(0) {
}

ListaDellaSpesa::~ListaDellaSpesa() {
  Svuota();
}
  
bool ListaDellaSpesa::Ricerca(const Nome n, PRec& p) const {
//Questo metodo cerca l'articolo avente il nome specificato e restituisce:
//  - true o false, a seconda che l'articolo sia stato trovato o meno;
//  - il puntatore all'ultimo record visitato.
  if (first) {
    p = first;
    if (StringheUguali(p->art.n, n))
      return true;
    else {
      while (p->succ) {
        p = p->succ;
        if (StringheUguali(p->art.n, n))
          return true;
      }
    }
  }
  
  return false;
}

bool ListaDellaSpesa::_Elimina(PRec& p, const Nome n) {
//metodo ricorsivo di eliminazione di un elemento dalla lista
  if (p) {
    if (StringheUguali(p->art.n, n)) {
      PRec tbd = p;
      p = tbd->succ;
      delete tbd;
      return true;
    }
    else
      return _Elimina(p->succ, n);
  }

  return false;  
}

Quantita ListaDellaSpesa::Aggiungi(const Nome n, Quantita q) {
  if (!first) {
    first = new Record;
    first->succ = 0;
    strcpy(first->art.n, n);
    first->art.q = q;
    return q;
  }
  else {
    PRec p;
    
    if (Ricerca(n, p)) { //esiste nella lista un elemento avente il nome n?
      //trovato => ora p punta all'elemento avente nome n
      p->art.q += q;
    }
    else {  
      //non trovato => ora p punta all'ultimo elemento della lista
      p->succ = new Record;
      p = p->succ;
      strcpy(p->art.n, n);
      p->art.q = q;
      p->succ = 0;
    }
  
    return p->art.q;
  }  
}

bool ListaDellaSpesa::Elimina(const Nome n) {
  return _Elimina(first, n);
}

Quantita ListaDellaSpesa::GetQuantita(const Nome n) const {
  PRec p;
  if (Ricerca(n, p))
    return p->art.q;
  else
    return 0;  
}

void ListaDellaSpesa::Svuota() {
  if (first) {
    PRec tbd = first;
    PRec p;
    
    while (tbd) {
      p = tbd->succ;
      delete tbd;
      tbd = p;
    }
  }
  first = 0;
}

void ListaDellaSpesa::Stampa() const {
  PRec p = first;
  while (p) {
    cout << p->art.n << ": " << p->art.q << endl;
    p = p->succ;
  }
}

void stampa_menu() {
  cout << "1: Aggiungi articolo.\n";
  cout << "2: Elimina articolo.\n";
  cout << "3: Quantita' articolo.\n";
  cout << "4: Svuota lista.\n";
  cout << "5: Stampa lista.\n";
  cout << "6: Esegui test veloce.\n";
  cout << "7: Esci.\n";
}

void Aggiungi(ListaDellaSpesa& l);
void Elimina(ListaDellaSpesa& l);
void GetQuantita(ListaDellaSpesa& l);
void Svuota(ListaDellaSpesa& l);
void Stampa(ListaDellaSpesa& l);
void TestVeloce(ListaDellaSpesa& l);

int main()
{
  ListaDellaSpesa l;
  
  int scelta;
  do {
    stampa_menu();
    cin >> scelta;
    switch (scelta) {
      case 1:
        Aggiungi(l);
        break;
      case 2:
        Elimina(l);
        break;
      case 3:
        GetQuantita(l);
        break;      
      case 4:
        Svuota(l);
        break;
      case 5:
        Stampa(l);
        break;
      case 6:
        TestVeloce(l);
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

void Aggiungi(ListaDellaSpesa& l) {
  Nome n;
  Quantita q, qq;
  cout << "Nome articolo: ";
  cin >> n;
  cout << "Quantita': ";
  cin >> q;
  qq = l.Aggiungi(n, q);
  cout << "Ora la quantita' e' " << qq << endl;
}

void Elimina(ListaDellaSpesa& l) {
  Nome n;
  cout << "Nome articolo: ";
  cin >> n;
  
  if (l.Elimina(n))
    cout << "Articolo eliminato." << endl;
  else
    cout << "Articolo non eliminato." << endl;
}

void GetQuantita(ListaDellaSpesa& l) {
  Nome n;
  Quantita q;
  cout << "Nome articolo: ";
  cin >> n;
  q = l.GetQuantita(n);
  cout << "La quantita' e' " << q << endl;
}

void Svuota(ListaDellaSpesa& l) {
  l.Svuota();
  cout << "Lista svuotata." << endl;
}

void Stampa(ListaDellaSpesa& l) {
  cout << "Lista:" << endl;
  l.Stampa();
}

void TestVeloce(ListaDellaSpesa& l) {
  l.Svuota();
  l.Aggiungi("Pane", 1);
  l.Aggiungi("Latte", 1.5);
  l.Aggiungi("Zucchero", 1);
  l.Aggiungi("Prosciutto", 0.3);
  l.Stampa();
  cout << "Latte: " << l.Aggiungi("Latte", 0.5) << endl;
  l.Elimina("Pane");
  l.Elimina("Zucchero");
  l.Elimina("Prosciutto");
  cout << "Latte: " << l.Aggiungi("Latte", 0.5) << endl;
  l.Svuota();
  l.Stampa();
}
