#include <iostream>
#include "lista.h"

using namespace std;

struct Record {
  TElem el;
  PRec succ; 
};

Lista::Lista(): first(0), count(0) {
}

Lista::Lista(const Lista& l): first(0), count(l.count) {
  //Se provo a copiare su me stesso, o se la lista
  //l è vuota non esegue alcuna operazione.
  if ((this != &l) && l.first) {
    first = new Record;
    first->el = l.first->el;
    
    PRec lp = l.first;
    PRec p = first;
    while (lp->succ) {
      p->succ = new Record;

      p = p->succ;
      lp = lp->succ;

      p->el = lp->el;      
    }
    p->succ = 0; //imposta a 0 il succ dell'ultimo elemento della lista
  }
}

Lista::~Lista() {
//Il distruttore ha il compito di svuotare la lista deallocando le strutture
//precedentemente allocate con new nel metodo Inserisci(). In caso contrario
//si incorrerebbe in una perdita della relativa memoria (memory-leak).
  Svuota(); //E' sufficiente invocare il metodo Svuota().
}

void Lista::Inserisci(const TElem& el) { //Inserimento in testa.
  PRec p = new Record;
  p->el = el;
  p->succ = first;
  first = p;  

  count++;
}

int Lista::NumeroElementi() const {
  return count;
}

void Lista::Svuota() {
  PRec tbd; //tbd = to be deleted
  while (first) {
    tbd = first;
    first = first->succ;
    delete tbd;
  }
  
  count = 0;
}

void Lista::Elimina(const TElem& el) {
//Questo metodo elimina solo la eventuale prima occorrenza
//dell'elemento specificato.
  if (first) {  // la lista non è vuota
    if (first->el == el) { //l'elemento da eliminare è in testa
      PRec tbd = first;
      first = first->succ;
      delete tbd;
      count --;
    }
    else { //l'elemento da eliminare non è in testa
      PRec p = first;
      bool trovato = false;
      while ((p->succ) && (!trovato)) {
        //l'elemento successivo a quello puntato da p deve essere eliminato
        if (p->succ->el == el) {
          PRec tbd = p->succ;
          p->succ = tbd->succ; //scollega l'elemento tbd...
          delete tbd; //...e lo elimina
          
          trovato = true;
          count --;
        } else
          p = p->succ;
      }
    }
  } 
}

void Lista::Stampa() const {
  PRec p = first;
  
  while (p) {
    cout << p->el << " ";
    p = p->succ;
  }
}

bool Lista::Ricerca(const TElem& el) const {
  PRec p = first;
  bool trovato = false;
  
  while ((p) && (!trovato)) {
    if (p->el == el)
      trovato = true;
    else
      p = p->succ;  
  }
  
  return trovato;
}
