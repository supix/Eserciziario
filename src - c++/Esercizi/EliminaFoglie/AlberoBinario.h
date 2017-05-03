#ifndef _ALBEROBINARIO_H_
#define _ALBEROBINARIO_H_

struct Nodo; //Forward declaration
typedef Nodo* PNodo;
typedef unsigned int TElem; //L'albero contiene interi positivi

class AlberoBinario {
private:
  PNodo root; //radice dell'albero
  unsigned int numelem;
  
  // Metodi ricorsivi di supporto
  void _Inserisci(PNodo& n, const TElem& el);
  void _Svuota(const PNodo& n);
  bool _Cerca(const PNodo& n, const TElem& el) const;
  unsigned int _EliminaFoglie(PNodo& n);
  void _PreOrdine(const PNodo& n) const;
  void _PostOrdine(const PNodo& n) const;
  void _InOrdine(const PNodo& n) const;
  
  inline bool EUnaFoglia(const PNodo& n);
  
  AlberoBinario(const AlberoBinario&); //impedisce la copia mediante costruttore
  void operator=(const AlberoBinario&); //impedisce l'assegnazione
public:
  AlberoBinario(); //costruttore senza parametri
  ~AlberoBinario(); //Distruttore
  
  void Inserisci(const TElem& el);
  void Svuota();
  unsigned int NumElem() const;
  bool Cerca(const TElem& el) const;  
  unsigned int EliminaFoglie();
  void PreOrdine() const;
  void PostOrdine() const;
  void InOrdine() const;
};

#endif /* _ALBEROBINARIO_H_ */
