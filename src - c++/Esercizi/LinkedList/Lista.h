#ifndef _LISTA_H_
#define _LISTA_H_

struct Record; //forward declaration: utile a dichiarare il tipo PRec
typedef Record* PRec;
typedef int TElem;

class Lista {
private:
  PRec first;
  int count;
  
  Lista& operator=(const Lista&); //non implementato: inibisce l'assegnaz.
public:
  Lista(); //costruttore senza parametri
  Lista(const Lista& l); //costruttore di copia
  ~Lista(); //distruttore

  void Inserisci(const TElem& el); //Inserimento in testa
  int NumeroElementi() const; //Restituisce il num. degli elementi nella lista
  void Svuota(); //Svuota la lista
  void Elimina(const TElem& el); //Elimina un elemento se presente
  void Stampa() const; //Stampa su st. out. tutti gli elementi
  bool Ricerca(const TElem& el) const; //Indica la presenza di un elemento
};

#endif /* _LISTA_H_ */
