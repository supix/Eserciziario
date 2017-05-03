#ifndef _ALBEROBINARIO_H_
#define _ALBEROBINARIO_H_

struct Nodo; //Forward declaration
typedef Nodo* PNodo;
typedef unsigned int TElem; //L'albero contiene interi positivi

class AlberoBinario {
private:
  PNodo root; //radice dell'albero
  
  // Metodi ricorsivi di supporto
  void _Svuota(const PNodo& n);
  void _AggiungiElem(PNodo& n, const TElem& el);
  void _PreOrdine(const PNodo& n) const;
  void _PostOrdine(const PNodo& n) const;
  void _InOrdine(const PNodo& n) const;
  
  TElem _Somma(const PNodo& n, TElem min, int& numero) const;
public:
  AlberoBinario(); //costruttore senza parametri
  ~AlberoBinario(); //Distruttore
  
  void AggiungiElem(const TElem& el);
  void Svuota();
  void PreOrdine() const;
  void PostOrdine() const;
  void InOrdine() const;
  
  TElem Somma(TElem min) const;
  int NumElem(TElem min) const;
  float Media() const;
};

#endif /* _ALBEROBINARIO_H_ */
