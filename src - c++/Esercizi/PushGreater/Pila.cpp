#include <iostream>
#include <stdlib.h>

using namespace std;

typedef int TElem;

struct Record;
typedef Record* PRec;
typedef struct Record {
  TElem el;
  PRec succ;
};  

class Pila {
private:
  PRec top;
  int nelem;
public:
  Pila(unsigned int p = 0);
  ~Pila();
  
  void Push(const TElem& e);
  bool PushGreater(const TElem& e);
  TElem Top() const;
  TElem Pop();
  void Svuota();
  unsigned int Count() const;
  bool Empty() const;
};

Pila::Pila(): top(0), nelem(0) {
}

Pila::~Pila() {
  Svuota();
}
  
void Pila::Push(const TElem& e) {
  PRec p = new Record;
  p->el = e;
  p->succ = top;
  top = p;
  nelem++;
}

bool Pila::PushGreater(const TElem& e) {
  if (Empty() || (e > Top())) {
    Push(e);
    return true;
  } else
    return false;  
}

TElem Pila::Top() const {
  if (top)
    return top->el;
    
  //questo metodo restit. un valore non specif. nel caso la pila sia vuota
}

TElem Pila::Pop() {
  if (top) {
    TElem e = top->el; //memorizza il valore di testa per restit. alla fine

    //memorizza il puntatore alla testa: essa dovrà essere cancellata
    PRec p = top;
    top = top->succ; //porta la testa al successivo
    delete p; //elimina la vecchia testa
    
    nelem--;   
    return e;
  }
  
  //questo metodo restit. un valore non specif. nel caso la pila sia vuota
}

void Pila::Svuota() {
  while (top) {
    PRec p = top;
    top = top->succ;
    delete p;
  }
  nelem = 0;
}

unsigned int Pila::Count() const {
  return nelem;
}

bool Pila::Empty() const {
  return (nelem == 0);
}

void stampaMenu();
void Push(Pila& p);
void PushGreater(Pila& p);
void Top(Pila& p);
void Pop(Pila& p);
void Svuota(Pila& p);
void Count(Pila& p);
void Empty(Pila& p);

int main()
{
  char c;
  Pila pila;
  
  do {
    stampaMenu();
    cin >> c;
    cin.ignore();

    switch (c) {
      case '1':
        Push(pila);
        break;
      case '2':
        PushGreater(pila);
        break;
      case '3':
        Top(pila);
        break;
      case '4':
        Pop(pila);
        break;
      case '5':
        Svuota(pila);
        break;
      case '6':
        Count(pila);
        break;
      case '7':
        Empty(pila);
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
  cout << "1. Push" << endl;
  cout << "2. PushGreater" << endl;
  cout << "3. Top" << endl;
  cout << "4. Pop" << endl;
  cout << "5. Svuota" << endl;
  cout << "6. Count" << endl;
  cout << "7. Empty" << endl;
  cout << "8. Esci" << endl;
  cout << endl;
  cout << "Scelta: ";
}

void Push(Pila& p) {
  TElem el;
  cout << "Inserire elemento: ";
  cin >> el;
  p.Push(el);
}

void PushGreater(Pila& p) {
  TElem el;
  cout << "Inserire elemento: ";
  cin >> el;
  if (p.PushGreater(el))
    cout << "Elemento inserito.\n";
  else
    cout << "Elemento non inserito.\n";
}

void Top(Pila& p) {
  if (!p.Empty())
    cout << "Elemento di testa: " << p.Top() << endl;
  else
    cout << "Pila vuota." << endl;  
}

void Pop(Pila& p) {
  if (!p.Empty())
    cout << "Elemento di testa: " << p.Pop() << endl;
  else
    cout << "Pila vuota." << endl;  
}

void Svuota(Pila& p) {
  p.Svuota();
  cout << "Pila svuotata.\n";
}

void Count(Pila& p) {
  cout << "Numero elementi: " << p.Count() << endl;
}

void Empty(Pila& p) {
  if (p.Empty())
    cout << "True." << endl;
  else
    cout << "False." << endl;  
}
