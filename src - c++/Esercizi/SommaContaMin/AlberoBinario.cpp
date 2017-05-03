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

AlberoBinario::~AlberoBinario() {
  Svuota();
}

// Metodi privati ricorsivi di supporto

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

TElem AlberoBinario::_Somma(const PNodo& n, TElem min, int& numero) const {
//Questo metodo (ricorsivo) restituisce la somma degli elementi maggiori o
//uguali a min contenuti nell'albero avente radice in n.
//Nel parametro di uscita numero viene inoltre restituito il numero di
//tali elementi.

  numero = 0; //inizializzo il parametro di uscita numero
  TElem sum = 0; //inizializzo l'accumulatore locale somma

  if (n) { //se l'albero è vuoto esco subito
    if (n->el >= min) { //l'elemento nella radice dell'albero deve contribuire alla somma?
      sum = sum + n->el; //aggiungo il suo valore a sum
      numero++; //incremento il numero degli elementi finora trovati
    }

    //ora devo usufruire dello stesso servizio che offro io, ma sui miei
    //sottoalberi sinistro e destro: ricorsione
    int tempNum;
    
    //nel sottoalbero sinistro cerco solo se l'elemento corrente
    //è maggiore o uguale a quello minimo: non ha senso altrimenti.
    if (n->el >= min) { 
      sum = sum + _Somma(n->sin, min, tempNum);
      numero = numero + tempNum;
    }  

    //cerco in ogni caso nel sottoalbero destro
    sum = sum + _Somma(n->des, min, tempNum);
    numero = numero + tempNum;
  }

  return sum;
}

// Metodi pubblici

void AlberoBinario::AggiungiElem(const TElem& el) {
  _AggiungiElem(root, el);
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

TElem AlberoBinario::Somma(TElem min) const {
  int numEl;
  return _Somma(root, min, numEl);
}

int AlberoBinario::NumElem(TElem min) const {
  int numEl;
  _Somma(root, min, numEl);
  
  return numEl;
}

float AlberoBinario::Media() const {
  int numEl;
  TElem sum = _Somma(root, 0, numEl);
  
  return (float)sum/numEl; //casting a float di uno dei due operandi: divisione reale
}
