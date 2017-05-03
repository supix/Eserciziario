void Lista::MinMax(TElem& min, TElem& max) const {
  if (first) {
    min = first->el;
    max = first->el;
    PRec p = first->succ;
    
    while (p) {
      if (p->el < min)
        min = p->el;
      if (p->el > max)
        max = p->el;     
      p = p->succ;
    }
  }
}
