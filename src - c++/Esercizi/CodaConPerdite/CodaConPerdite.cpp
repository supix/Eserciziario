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

class Coda {
private:
  PRec head;
  PRec tail;
  const unsigned int posti;
  int nelem;
public:
  Coda(unsigned int _posti);
  ~Coda();
  
  bool Push(const TElem& e);
  TElem Top() const;
  TElem Pop();
  TElem Pop(unsigned int n);
  void Svuota();
  unsigned int Count() const;
  bool Empty() const;
};

Coda::Coda(unsigned int _posti): head(0), tail(0), posti(_posti), nelem(0) {
}

Coda::~Coda() {
  Svuota();
}

bool Coda::Push(const TElem& e) {
  if (nelem == posti)
    return false;
    
  //Creo un nuovo elemento nell'heap
  PRec temp = new Record;
  temp->el = e;
  temp->succ = 0;
  
  //se c'è un elemento di coda questo deve puntare al nuovo elemento
  if (tail) 
    tail->succ = temp;
    
  //in ogni caso la coda punterà al nuovo elemento
  tail = temp;
  
  //se la testa non punta ad un elemento, deve puntare al nuovo elemento:
  //la coda, cioè, era vuota al momento dell'inserimento
  if (!head)
    head = temp;  
    
  nelem++;  
  
  return true;
}

TElem Coda::Top() const {
  if (head)
    return head->el;
}

TElem Coda::Pop() {
  if (head) {
    PRec temp = head;
    TElem el_temp = temp->el;
    
    //head passa a puntare all'elemento successivo
    head = head->succ;
    
    //se non punta a niente vuole dire che la coda conteneva un solo elem.
    //anche tail quindi deve puntare a 0
    if (!head)
      tail = 0;
      
    nelem--;  
    delete temp;
    return el_temp;  
  }
}

TElem Coda::Pop(unsigned int n) {
  if (head) {
    TElem el = Pop();
  
    //estrazione dei restanti elementi: si usa il metodo Pop();
    for (int i = 2; (i <= n) && head; i++)
      Pop();
    
    return el;
  }  
}

void Coda::Svuota() {
  while (head != 0) {
    PRec tbd = head;
    head = head->succ;
    delete tbd;
  }
  
  head = tail = 0;
  nelem = 0;
}

unsigned int Coda::Count() const {
  return nelem;
}

bool Coda::Empty() const {
  return (nelem == 0);
}

void stampaMenu();
void Push(Coda& c);
void Top(Coda& c);
void Pop(Coda& c);
void PopMany(Coda& c);
void Svuota(Coda& c);
void Count(Coda& c);
void Empty(Coda& c);

int main()
{
  char c;
  unsigned int i;
  
  cout << "Inserire il numero massimo di elementi in coda: ";
  cin >> i;
  
  Coda coda(i);
  
  do {
    stampaMenu();
    cin >> c;
    cin.ignore();

    switch (c) {
      case '1':
        Push(coda);
        break;
      case '2':
        Top(coda);
        break;
      case '3':
        Pop(coda);
        break;
      case '4':
        PopMany(coda);
        break;        
      case '5':
        Svuota(coda);
        break;
      case '6':
        Count(coda);
        break;
      case '7':
        Empty(coda);
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
  cout << "2. Top" << endl;
  cout << "3. Pop" << endl;
  cout << "4. PopMany" << endl;  
  cout << "5. Svuota" << endl;
  cout << "6. Count" << endl;
  cout << "7. Empty" << endl;
  cout << "8. Esci" << endl;
  cout << endl;
  cout << "Scelta: ";
}

void Push(Coda& c) {
  TElem el;
  cout << "Inserire elemento: ";
  cin >> el;
  if (c.Push(el))
    cout << "Elemento inserito.\n";
  else
    cout << "Elemento NON inserito.\n";
}

void Top(Coda& c) {
  if (!c.Empty())
    cout << "Elemento di testa: " << c.Top() << endl;
  else
    cout << "Coda vuota." << endl;  
}

void Pop(Coda& c) {
  if (!c.Empty())
    cout << "Elemento di testa: " << c.Pop() << endl;
  else
    cout << "Coda vuota." << endl;  
}

void PopMany(Coda& c) {
  int i;
  cout << "Quanti elementi estrarre? ";
  cin >> i;
  
  if (!c.Empty())
    cout << "Elemento di testa: " << c.Pop(i) << endl;
  else
    cout << "Coda vuota." << endl;  
}

void Svuota(Coda& c) {
  c.Svuota();
  cout << "Coda svuotata.\n";
}

void Count(Coda& c) {
  cout << "Numero elementi: " << c.Count() << endl;
}

void Empty(Coda& c) {
  if (c.Empty())
    cout << "True." << endl;
  else
    cout << "False." << endl;  
}
