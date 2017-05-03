TElem Lista::Somma() const {
  PRec p = first;
  TElem somma = 0;
  while (p) {
    somma = somma + p->el;
    p=p->succ;
  }
  
  return somma;
}
