#include <iostream>

using namespace std;

const int NMAX = 100; //numero max di elementi della lista
typedef int TElem;

class Lista {
private:
  TElem v[NMAX];
  int nelem;
public:
  Lista();
  ~Lista();

  void InserisciInCoda(TElem el);
  void Svuota();
  void Stampa() const;
  int Count() const;
};

Lista::Lista(): nelem(0) {
}

Lista::~Lista() {
  //Qui non è necessaria alcuna operazione
  //Il distruttore poteva anche essere omesso del tutto.
}

void Lista::InserisciInCoda(TElem el) {
  if (nelem < NMAX) {
    v[nelem] = el;
    nelem++;
  }  
}

void Lista::Svuota() {
  nelem = 0;
}

void Lista::Stampa() const {
  for (int i = 0; i < nelem; i++)
    cout << v[i] << " ";
  cout << endl;  
}

int Lista::Count() const {
  return nelem; 
}

void stampa_menu() {
  cout << "1: InserisciInCoda.\n";
  cout << "2: Svuota.\n";
  cout << "3: Stampa.\n";
  cout << "4: Count.\n";
  cout << "5: Esci.\n";
}

void InserisciInCoda(Lista& l);
void Svuota(Lista& l);
void Stampa(Lista& l);
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
        InserisciInCoda(l);
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

void InserisciInCoda(Lista& l) {
  TElem el;
  cout << "Inserisci valore elemento: ";
  cin >> el;
  l.InserisciInCoda(el);
}

void Svuota(Lista& l) {
  l.Svuota();
  cout << "Lista svuotata.\n";
}

void Stampa(Lista& l) {
  cout << "Il contenuto della lista e': ";
  l.Stampa();
  cout << endl;
}

void Count(Lista& l) {
  cout << "N. Elem: " << l.Count() << endl;
}
