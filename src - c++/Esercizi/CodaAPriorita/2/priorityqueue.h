#include "coda.h"

class PriorityQueue {
private:
  Coda coda_l;
  Coda coda_h;
  
  PriorityQueue(const PriorityQueue& c); //inibisce la copia...
  PriorityQueue& operator=(const PriorityQueue& c); //..e l'assegnazione
public:
  PriorityQueue();

  void PushLow(const TElem& e);
  void PushHigh(const TElem& e);
  TElem Pop();
  void Clear();
  bool Empty() const;
};
