#include "coda.h"

typedef struct Record {
  TElem el;
  PRec succ;
};  

Coda::Coda(): head(0), tail(0), nelem(0) {
}

Coda::~Coda() {
  Svuota();
}

void Coda::Push(const TElem& e) {
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
    
    //se non punta a niente vuole dire che la coda conteneva un solo elemento
    //anche tail quindi deve puntare a 0
    if (!head)
      tail = 0;
      
    nelem--;  
    delete temp;
    return el_temp;  
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

int Coda::Count() const {
  return nelem;
}

bool Coda::Empty() const {
  return (nelem == 0);
}
