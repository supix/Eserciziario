#include <iostream>
#include "AlberoBinario.h"

using namespace std;

struct Nodo { //Struttura Nodo
  TElem el;
  PNodo sin;
  PNodo des;
};  

AlberoBinario::AlberoBinario(): root(0) {
}

AlberoBinario::AlberoBinario(const AlberoBinario& a) {
  if (this != &a) //copia solo da un oggetto differente
    _CopiaAlbero(root, a.root);  
}

AlberoBinario::~AlberoBinario() {
  Svuota();
}

// Metodi privati ricorsivi di supporto

void AlberoBinario::_CopiaAlbero(PNodo& dest, const PNodo& source) {
// Questo metodo ricorsivo accetta in ingresso un puntatore ad un albero
// sorgente (source) e restituisce in uscita un puntatore ad un albero che
// viene costruito ricopiando il primo. 
  if (source) { //se la sorgente non è l'albero vuoto
    dest = new Nodo; //crea un nuovo nodo
    dest->el = source->el; //assegna il contenuto dalla sorgente alla destinaz.

    //Ora bisogna ricreare il sottoalbero sinistro ed il sottoalbero destro
    //del nodo puntato da dest ricopiando i rispett. sottoalberi puntati da
    //source. Riflettendo, l'operazione desiderata è del tutto analoga a quella
    //già invocata a partire dalla radice. E' quindi possibile sfruttare la
    //ricorsione ed invocare lo stesso "servizio" _CopiaAlbero() consid.
    //source->des e source->sin come radici di due distinti alberi.

    _CopiaAlbero(dest->sin, source->sin); //assegna il sottoalbero sinistro
    _CopiaAlbero(dest->des, source->des); //assegna il sottoalbero destro
  } else
    dest = 0;
}

void AlberoBinario::_AggiungiElem(PNodo& n, const TElem& el) {
  if (!n) {
    n = new Nodo; //si crea un nuovo elemento dell'albero...
    n->el = el; //...e lo si inizializza.
    n->sin = 0;
    n->des = 0;
  }
  else
    if (el > n->el)
      _AggiungiElem(n->des, el);
    else  
      _AggiungiElem(n->sin, el);
}

bool AlberoBinario::_InAlb(const PNodo& n, const TElem& el) const {
  if (!n)
    return false;
    
  if (n->el == el) //l'elemento cercato è nella radice?
    return true;
    
  if (el > n->el) //è maggiore del contenuto della radice?
    return _InAlb(n->des, el);  //cerca nel sottoalbero destro
  else
    return _InAlb(n->sin, el); //cerca nel sottoalbero sinistro
}

void AlberoBinario::_Sostituisce(PNodo& n, PNodo& p) {
// Questo metodo ha come parametri di ingresso-uscita:
//   -n: un puntatore alla radice di un albero;
//   -p: un puntatore ad un nodo.
// Il suo effetto è quello di sostituire il nodo puntato da p con il massimo
// elemento dell'albero n. La prima volta questo metodo viene invocato
// (nel metodo elimina) con la sintassi _Sostisuisci(n->sin, n), percui
// si provvede alla sostituzione del nodo n con il massimo del suo
// sottoalbero sinistro.
  PNodo q;
  if (!n->des) {
    q = n;
    n = n->sin;
    q->sin=p->sin;
    q->des=p->des;
    p=q;
  } else
    _Sostituisce(n->des, p);  
}

void AlberoBinario::_Elimina(PNodo& n, const TElem& el) {
  if (n) { // Eliminare da un albero vuoto non produce alcuna operazione
    if (n->el == el) {
      //cancella nodo corrente
      PNodo p = n;
      if (!n->sin) //il ramo sinistro del nodo da eliminare è vuoto? 
        n = n->des; //sostituzione del nodo col suo sottoalbero destro
      else
        if (!n->des) //il ramo destro del nodo da eliminare è vuoto? 
          n = n->sin; //sostituzione del nodo col suo sottoalbero sinistro
        else //il nodo da eliminare ha sia il sottoalbero sx che quello dx?
          _Sostituisce(n->sin, n); //chiamo il "servizio" Sostituisce()
      delete p;    
    } else
      if (el > n->el)
        _Elimina(n->des, el);
      else
        _Elimina(n->sin, el);
  }
}

void AlberoBinario::_Svuota(const PNodo& n) {
  if (n) { // Agisce solo se l'albero esiste
    _Svuota(n->sin);
    _Svuota(n->des);  
    delete n;
  }
}

void AlberoBinario::_PreOrdine(const PNodo& n) const {
  if (n) {
    cout << n->el << " ";
    _PreOrdine(n->sin);
    _PreOrdine(n->des);
  }  
}

void AlberoBinario::_PostOrdine(const PNodo& n) const {
  if (n) {
    _PostOrdine(n->sin);
    _PostOrdine(n->des);
    cout << n->el << " ";
  }  
}

void AlberoBinario::_InOrdine(const PNodo& n) const {
  if (n) {
    _InOrdine(n->sin);
    cout << n->el << " ";
    _InOrdine(n->des);
  }  
}

// Metodi pubblici

void AlberoBinario::AggiungiElem(const TElem& el) {
  _AggiungiElem(root, el);
}

bool AlberoBinario::InAlb(const TElem& el) const {
  return _InAlb(root, el);
}

void AlberoBinario::Elimina(const TElem& el) {
  _Elimina(root, el);
}

void AlberoBinario::Svuota() {
  _Svuota(root);
  root = 0;
}

void AlberoBinario::PreOrdine() const {
  _PreOrdine(root);
}

void AlberoBinario::PostOrdine() const {
  _PostOrdine(root);
}

void AlberoBinario::InOrdine() const {
  _InOrdine(root);
}
