#ifndef _ALBEROBINARIO_H_
#define _ALBEROBINARIO_H_

struct Nodo; //Forward declaration
typedef Nodo* PNodo;
typedef int TElem; //L'albero contiene interi

class AlberoBinario {
private:
  PNodo root; //radice dell'albero
  
  // Metodi ricorsivi di supporto
  void _CopiaAlbero(PNodo& dest, const PNodo& source);
  void _Svuota(const PNodo& n);
  void _AggiungiElem(PNodo& n, const TElem& el);
  void _Sostituisce(PNodo& n, PNodo& p);
  bool _InAlb(const PNodo& n, const TElem& el) const;
  void _Elimina(PNodo& n, const TElem& el);
  void _PreOrdine(const PNodo& n) const;
  void _PostOrdine(const PNodo& n) const;
  void _InOrdine(const PNodo& n) const;
  
  //operatore di assegnazione privato: inibisce l'assegnazione 
  //che provocherebbe una copia superficiale
  AlberoBinario& operator=(const AlberoBinario&);
public:
  AlberoBinario(); //costruttore senza parametri
  AlberoBinario(const AlberoBinario& a); //costruttore di copia
  ~AlberoBinario(); //Distruttore
  
  void AggiungiElem(const TElem& el);
  bool InAlb(const TElem& el) const;
  void Elimina(const TElem& el);
  void Svuota();
  void PreOrdine() const;
  void PostOrdine() const;
  void InOrdine() const;
};

#endif /* _ALBEROBINARIO_H_ */
