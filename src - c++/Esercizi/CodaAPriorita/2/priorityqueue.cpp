#include "priorityqueue.h"

void PriorityQueue::PushLow(const TElem& e) {
  coda_l.Push(e);
}

void PriorityQueue::PushHigh(const TElem& e) {
  coda_h.Push(e);
}

TElem PriorityQueue::Pop() {
  if (!coda_h.Empty())
    return coda_h.Pop();
  else  
    return coda_l.Pop();
}

void PriorityQueue::Clear() {
  coda_h.Svuota();
  coda_l.Svuota();
}

bool PriorityQueue::Empty() const {
  return (coda_h.Empty() && coda_l.Empty());
}

