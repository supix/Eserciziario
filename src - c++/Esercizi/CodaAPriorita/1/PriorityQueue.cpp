#include "PriorityQueue.h"

typedef struct Record {
  TElem el;
  PRec succ;
};  

PriorityQueue::PriorityQueue(): head(0), tail(0), tail_h(0) {}

PriorityQueue::~PriorityQueue() {
  Clear();
}

void PriorityQueue::Push(const TElem& e) { //classico Push in coda
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
  //la struttura, cioè, era vuota al momento dell'inserimento
  if (!head)
    head = temp;  
}

void PriorityQueue::PushLow(const TElem& e) {
  Push(e); //si riduce ad un classico inserimento in coda
}

void PriorityQueue::PushHigh(const TElem& e) {
  if (!tail_h) {
    
    //non ci sono elementi ad alta priorità: aggiunta in testa
    if (!head) //la coda è vuota?
      Push(e); //inserisco con Push()
    else {
      PRec temp = new Record;
      temp->el = e;
      temp->succ = head;
      head = temp;
    }  
    
    tail_h = head; //l'elemento inserito è in testa: tail_h deve puntarvi
    
  } else {    
    //inserisco
    PRec temp = new Record;
    temp->el = e;
    temp->succ = tail_h->succ;
    tail_h->succ = temp;
    
    tail_h = temp; //aggiorno il puntatore tail_h
    
    //aggiorno tail se l'elemento aggiunto è in ultima posizione
    if (!tail_h->succ)
      tail = tail_h;
  }
}  

TElem PriorityQueue::Pop() {
  if (head) {
    PRec temp = head;
    TElem el_temp = temp->el;
    
    if (head == tail_h) //ho prelevato l'unico elemento a priorità alta?
      tail_h = 0;       //allora non ce ne sono più
    
    //head passa a puntare all'elemento successivo
    head = head->succ;
    
    //se non punta a niente vuole dire che la coda conteneva un solo elem.
    //anche tail quindi deve puntare a 0
    if (!head) {
      tail = 0;
      tail_h = 0;
    }  
      
    delete temp;
    
    return el_temp;  
  }
}

void PriorityQueue::Clear() {
  while (head != 0) {
    PRec tbd = head;
    head = head->succ;
    delete tbd;
  }
  
  head = tail = tail_h = 0;
}

bool PriorityQueue::Empty() const {
  return !head;
}
